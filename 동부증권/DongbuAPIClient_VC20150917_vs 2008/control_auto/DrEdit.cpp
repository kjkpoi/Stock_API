// DrEdit.cpp : implementation file
//

#include "stdafx.h"
#include "DrEdit.h"

//#include <Imm.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrEdit
#define CLR_DISABLE		RGB(215,216,218)
#define CLR_BORDER		RGB(116,117,117)

CDrEdit::CDrEdit()
{
	m_bRange = FALSE;
	m_bDot = FALSE;
	m_bUseMinus = FALSE;

	m_dMin = 0;
	m_dMax = 100;

	m_nRealLength = 0;
	m_cNegativeSign = '-';
	m_cDecimalPoint = '.';
	m_strPrefix = "";
	m_cGroupSeparator = ',';

	m_nMaxWholeDigits = 9;
	m_nMaxDecimalPlaces = 0;

	m_bAdjustingSeparators = FALSE;
	m_nDigitsInGroup = 3;
	m_bRange = FALSE;

	m_dMaxKillFocus = -1;
	m_dMinKillFocus = -1;
	
	m_bSelectAll = TRUE;
}

CDrEdit::~CDrEdit()
{
}


BEGIN_MESSAGE_MAP(CDrEdit, CEdit)
	//{{AFX_MSG_MAP(CDrEdit)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_WM_SETFOCUS()
	ON_WM_NCPAINT()
	//}}AFX_MSG_MAP
//	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CDrEdit::OnEnKillfocus)
	ON_WM_KILLFOCUS()
	// 20120723 ssj - 서버자동주문 >>
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	// 20120723 ssj - 서버자동주문 <<
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrEdit message handlers

int CDrEdit::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CEdit::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: Add your specialized creation code here
	ModifyStyle(0, WS_BORDER);
	ModifyStyleEx(0, WS_EX_CLIENTEDGE|WS_EX_STATICEDGE);

	return 0;
}

void CDrEdit::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CRect r;
	GetClientRect(&r);
	
	CDC memDC;
    memDC.CreateCompatibleDC(&dc);
	
	CBitmap m_bitmap, *m_pOldBitmap;

    m_bitmap.CreateCompatibleBitmap(&dc, r.Width(), r.Height());
	m_pOldBitmap = memDC.SelectObject(&m_bitmap);

	memDC.FillSolidRect(r, IsWindowEnabled() ? RGB(255,255,255): CLR_DISABLE);

	CEdit::DefWindowProc( WM_PAINT, (WPARAM)memDC.m_hDC, 0 );

	dc.BitBlt(r.left, r.top, r.Width(), r.Height(), &memDC, r.left, r.top, SRCCOPY);

    memDC.SelectObject(m_pOldBitmap);
	m_bitmap.DeleteObject();

	memDC.DeleteDC();
}

void CDrEdit::OnNcPaint() 
{
	// TODO: Add your message handler code here
 	CRect r;
 	GetWindowRect(&r);
	ScreenToClient(&r);

	CDC* dc = GetDC();
	dc->Draw3dRect(r, CLR_BORDER, CLR_BORDER);
	r.DeflateRect(1,1);
	dc->Draw3dRect(r, RGB(255,255,255), RGB(255,255,255));
	r.DeflateRect(1,1);
	dc->Draw3dRect(r, RGB(255,255,255), RGB(255,255,255));
	r.DeflateRect(1,1);
	dc->Draw3dRect(r, RGB(255,255,255), RGB(255,255,255));
	ReleaseDC(dc);
	// Do not call CEdit::OnNcPaint() for painting messages
}

void CDrEdit::OnChar(UINT uChar, UINT nRepCnt, UINT nFlags)
{
	TCHAR c = static_cast<TCHAR>(uChar);

	int nStart, nEnd;
	GetSel(nStart, nEnd);
	CString strText;
	GetWindowText(strText);
	CString strNumericText = GetNumericText(strText);
	int nDecimalPos = strText.Find(m_cDecimalPoint);
	int nNumericDecimalPos = strNumericText.Find(m_cDecimalPoint);
	int nLen = strText.GetLength();
	int nNumericLen = strNumericText.GetLength();
	int nPrefixLen = m_strPrefix.GetLength();
	int nSepCount = GetGroupSeparatorCount(strText);
	bool bNeedAdjustment = false;

	// Check if we're in the prefix's location
	if (nStart < nPrefixLen && _istprint(c))
	{
		TCHAR cPrefix = m_strPrefix[nStart];

		// Check if it's the same character as the prefix.
		if (cPrefix == c /*&& _ShouldEnter(c)*/)
		{
			if (nLen > nStart)
			{
				nEnd = (nEnd == nLen ? nEnd : (nStart + 1));
				SetSel(nStart, nEnd);
				ReplaceSel(CString(c), TRUE);
			}
			else
				CEdit::OnChar(uChar, nRepCnt, nFlags);
		}
		// If it's a part of the number, enter the prefix
		else if ((_istdigit(c) || c == m_cNegativeSign || c == m_cDecimalPoint)/* && _ShouldEnter(c)*/)
		{
			nEnd = (nEnd == nLen ? nEnd : (nPrefixLen));
			SetSel(nStart, nEnd);
			ReplaceSel(m_strPrefix.Mid(nStart), TRUE);

			OnChar(uChar, nRepCnt, nFlags);
		}

		return;
	}

	// Check if it's a negative sign
	if (c == m_cNegativeSign && IsNegativeAllowed())
	{
		// If it's at the beginning, determine if it should overwritten
		if (nStart == nPrefixLen)
		{
			if (!strNumericText.IsEmpty() && strNumericText[0] == m_cNegativeSign/* && _ShouldEnter(c)*/)
			{
				nEnd = (nEnd == nLen ? nEnd : (nStart + 1));
				SetSel(nStart, nEnd);
				ReplaceSel(CString(m_cNegativeSign), TRUE);
				return;
			}
		}
		// If we're not at the beginning, toggle the sign
		else //if (_ShouldEnter(c))
		{
			if (strNumericText[0] == m_cNegativeSign)
			{
				SetSel(nPrefixLen, nPrefixLen + 1);
				ReplaceSel(_T(""), TRUE);
				SetSel(nStart - 1, nEnd - 1);
			}
			else
			{
				SetSel(nPrefixLen, nPrefixLen);
				ReplaceSel(CString(m_cNegativeSign), TRUE);
				SetSel(nStart + 1, nEnd + 1);
			}

			return;
		}
	}

	// Check if it's a decimal point (only one is allowed).
	else if (c == m_cDecimalPoint && m_nMaxDecimalPlaces > 0)
	{
		if (nDecimalPos >= 0)
		{
			// Check if we're replacing the decimal point
			if (nDecimalPos >= nStart && nDecimalPos < nEnd)
				bNeedAdjustment = true;
			else
			{	// Otherwise, put the caret on it
				//if (_ShouldEnter(c))
				SetSel(nDecimalPos + 1, nDecimalPos + 1);
				return;
			}
		}
		else
			bNeedAdjustment = true;
	}

	// Check if it's a digit
	else if (_istdigit(c))
	{
		// Check if we're on the right of the decimal point.
		if (nDecimalPos >= 0 && nDecimalPos < nStart)
		{
			if (strNumericText.Mid(nNumericDecimalPos + 1).GetLength() == m_nMaxDecimalPlaces)
			{
				if (nStart <= nDecimalPos + m_nMaxDecimalPlaces/* && _ShouldEnter(c)*/)
				{
					nEnd = (nEnd == nLen ? nEnd : (nStart + 1));
					SetSel(nStart, nEnd);
					ReplaceSel(CString(c), TRUE);
				}
				return;
			}
		}

		// We're on the left side of the decimal point
		else 
		{
			bool bIsNegative = (!strNumericText.IsEmpty() && strNumericText[0] == m_cNegativeSign);

			// Make sure we can still enter digits.
			if (nStart == m_nMaxWholeDigits + bIsNegative + nSepCount + nPrefixLen)
			{
				if ((m_nRealLength > 0) && m_nMaxDecimalPlaces > 0)
				{
					nEnd = (nEnd == nLen ? nEnd : (nStart + 2));
					SetSel(nStart, nEnd);
					ReplaceSel(CString(m_cDecimalPoint) + c, TRUE);
				}
				return;
			}

			if (strNumericText.Mid(0, nNumericDecimalPos >= 0 ? nNumericDecimalPos : nNumericLen).GetLength() == m_nMaxWholeDigits + bIsNegative)
			{				
				if (strText[nStart] == m_cGroupSeparator)
					nStart++;

				nEnd = (nEnd == nLen ? nEnd : (nStart + 1));
				SetSel(nStart, nEnd);
				ReplaceSel(CString(c), TRUE);
				AdjustWithinRange();
				return;
			}

			bNeedAdjustment = true;
		}
	}

	// Check if it's a non-printable character, such as Backspace or Ctrl+C
	else if (!_istprint(c))
		bNeedAdjustment = true;
	else
		return;


	// 	if (!_ShouldEnter(c))
	// 		return;

	CEdit::OnChar(uChar, nRepCnt, nFlags);

	AdjustWithinRange();
	// If the decimal point was added/removed or a separator needs adding/removing, adjust the text
	if (bNeedAdjustment)
		AdjustSeparators(nSepCount);
}

void CDrEdit::SetEditRange(double dMin, double dMax)
{
	m_bRange = TRUE;
	m_dMin = dMin;
	m_dMax = dMax;
}

CString CDrEdit::GetNumericText(const CString& strText, bool bUseMathSymbols /*= false*/)
{
	CString strNewText;
	bool bIsNegative = false;
	bool bHasDecimalPoint = false;

	for (int iPos = 0, nLen = strText.GetLength(); iPos < nLen; iPos++)
	{
		TCHAR c = strText[iPos];
		if (_istdigit(c))
			strNewText += c;
		else if (c == m_cNegativeSign)
			bIsNegative = true;
		else if (c == m_cDecimalPoint && !bHasDecimalPoint)
		{
			bHasDecimalPoint = true;
			strNewText += '.';//(bUseMathSymbols ? '.' : m_cDecimalPoint);
		}
	}

	// Add the negative sign to the front of the number
	if (bIsNegative)
		strNewText.Insert(0, '-');
	//strNewText.Insert(0, bUseMathSymbols ? '-' : m_cNegativeSign);

	return strNewText;
}

int CDrEdit::GetGroupSeparatorCount(const CString& strText)
{
	int iPos, nSepCount, nLen;
	for (iPos = 0, nSepCount = 0, nLen = strText.GetLength(); iPos < nLen; iPos++)
	{
		if (strText[iPos] == m_cGroupSeparator)
			nSepCount++;
	}

	return nSepCount;
}

BOOL CDrEdit::IsNegativeAllowed()
{
	return m_bUseMinus;
}


void CDrEdit::AdjustSeparators(int nCurrentSeparatorCount)
{
	//	SelectionSaver selection = m_pEdit;
	m_bAdjustingSeparators = TRUE;

	CString strValidText = GetValidText();
	CString strText;
	int nStart, nEnd;
	int nFind;
	UpdateData(TRUE);
	GetWindowText(strText);
	if (strValidText != strText)
	{
		int nLen = strValidText.GetLength();
		
		GetSel(nStart, nEnd);
		nFind = strValidText.Find('.');
		SetWindowText(strValidText);

		if(nFind > -1)
		{				
			if(nFind > m_nMaxWholeDigits)
			{
				SetSel(nFind + 1, nFind + 1);
			}
			else
				SetSel(nFind, nFind);
			
		}
		else		
			SetSel(nLen, nLen);		
	}



	// Adjust the current selection if separators were added/removed
	int nNewSeparatorCount = GetGroupSeparatorCount(strValidText);
	// 	if (nCurrentSeparatorCount != nNewSeparatorCount && selection.GetStart() > m_strPrefix.GetLength())
	// 		selection += (nNewSeparatorCount - nCurrentSeparatorCount);

	m_bAdjustingSeparators = FALSE;
}

CString CDrEdit::GetValidText()
{
	CString strText;
	GetWindowText(strText);
	CString strNewText;
	bool bIsNegative = false;
	int iPos, nDecimalPos, nNewLen, nLen;

	// Remove any invalid characters from the number
	for (iPos = 0, nDecimalPos = -1, nNewLen = 0, nLen = strText.GetLength(); iPos < nLen; iPos++)
	{
		TCHAR c = strText[iPos];

		// Check for a negative sign
		if (c == m_cNegativeSign && IsNegativeAllowed())
			bIsNegative = true;

		// Check for a digit
		else if (_istdigit(c))
		{
			// Make sure it doesn't go beyond the limits
			if (nDecimalPos < 0 && nNewLen == m_nMaxWholeDigits)
				continue;

			if (nDecimalPos >= 0 && nNewLen > nDecimalPos + m_nMaxDecimalPlaces)
				break;

			strNewText += c;
			nNewLen++;
		}
		// Check for a decimal point
		else if (c == m_cDecimalPoint && nDecimalPos < 0)
		{
			if (m_nMaxDecimalPlaces == 0)
				break;

			strNewText += c;
			nDecimalPos = nNewLen;
			nNewLen++;
		}
	}

	// Check if we need to pad the number with zeros after the decimal point
	// 	if (m_nMaxDecimalPlaces > 0 && nNewLen > 0 &&
	// 		((PadWithZerosAfterDecimalWhenTextChanges) ||
	// 		(!m_bAdjustingSeparators && (PadWithZerosAfterDecimalWhenTextIsSet))))
	// 	{
	// 		if (nDecimalPos < 0)
	// 		{
	// 			if (nNewLen == 0 || strNewText == '-')
	// 			{
	// 				strNewText = '0';
	// 				nNewLen = 1;
	// 			}
	// 			strNewText += m_cDecimalPoint;
	// 			nDecimalPos = nNewLen++;
	// 		}
	// 
	// 		InsertZeros(&strNewText, -1, m_nMaxDecimalPlaces - (nNewLen - nDecimalPos - 1));
	// 	}

	// Insert the negative sign if it's there
	if (bIsNegative)
		strNewText.Insert(0, m_cNegativeSign);

	return GetSeparatedText(strNewText);
}

CString CDrEdit::GetSeparatedText(const CString& strText)
{
	CString strNumericText = GetNumericText(strText);
	CString strNewText = strNumericText;

	// Retrieve the number without the decimal point
	int nDecimalPos = strNumericText.Find(m_cDecimalPoint);
	if (nDecimalPos >= 0)
		strNewText = strNewText.Left(nDecimalPos);

	if (m_nDigitsInGroup > 0)
	{
		int nLen = strNewText.GetLength();
		BOOL bIsNegative = (!strNewText.IsEmpty() && strNewText[0] == m_cNegativeSign);

		// Loop in reverse and stick the separator every m_nDigitsInGroup digits.
		for (int iPos = nLen - (m_nDigitsInGroup + 1); iPos >= bIsNegative; iPos -= m_nDigitsInGroup)
			strNewText = strNewText.Left(iPos + 1) + m_cGroupSeparator + strNewText.Mid(iPos + 1);
	}

	// Prepend the prefix, if the number is not empty.
	if (!strNewText.IsEmpty() || nDecimalPos >= 0)
	{
		strNewText = m_strPrefix + strNewText;

		if (nDecimalPos >= 0)
			strNewText += strNumericText.Mid(nDecimalPos);
	}

	return strNewText;
}

void CDrEdit::AdjustWithinRange()
{		
	if(!m_bRange)
		return;

	CString strText;
	CString strFormat, strWindow;
	strFormat.Format("%s%d%s", "%.", m_nMaxDecimalPlaces, "lf");

	GetWindowText(strWindow);
	double dValue = _tcstod(GetNumericText(strWindow), NULL);

	if (dValue < m_dMin)
	{
		strText.Format(strFormat, m_dMin);
		SetWindowText(strText);
	}
	else if (dValue > m_dMax)
	{
		strText.Format(strFormat, m_dMax);
		SetWindowText(strText);
	}
}

void CDrEdit::AdjustWithinRangeKillFocus()
{		
	if(!m_bRange || (m_dMaxKillFocus == -1 || m_dMinKillFocus == -1))
		return;

	CString strText;
	CString strFormat, strWindow;
	strFormat.Format("%s%d%s", "%.", m_nMaxDecimalPlaces, "lf");

	GetWindowText(strWindow);
	double dValue = _tcstod(GetNumericText(strWindow), NULL);

	if (dValue < m_dMinKillFocus)
	{
		strText.Format(strFormat, m_dMinKillFocus);
		SetWindowText(strText);
	}
	else if (dValue > m_dMaxKillFocus)
	{
		strText.Format(strFormat, m_dMaxKillFocus);
		SetWindowText(strText);
	}
}

void CDrEdit::SetUseMinus(BOOL bUse)
{
	m_bUseMinus = bUse;
}

void CDrEdit::SetPlaces(int nIntegerPlaces, int nDecimalPlaces)
{
	m_nMaxWholeDigits = nIntegerPlaces;
	m_nMaxDecimalPlaces = m_nRealLength = nDecimalPlaces;
}

//
//void CDrEdit::SetEngMode(HWND hWnd)
//{
//	HIMC hIMC = ImmGetContext(hWnd);
//	DWORD dwConv, dwSent;
//	DWORD dwTemp;
//
//	ImmGetConversionStatus(hIMC, &dwConv, &dwSent);
//	dwTemp = dwConv & ~IME_CMODE_LANGUAGE;
//	dwTemp |= IME_CMODE_ALPHANUMERIC;
//	dwConv = dwTemp;
//	ImmSetConversionStatus(hIMC, dwConv, dwSent);
//	ImmReleaseContext(hWnd, hIMC);
//}
//
//void CDrEdit::SetHanMode(HWND hWnd)
//{
//	HIMC hIMC = ImmGetContext(hWnd);
//	DWORD dwConv, dwSent;
//	DWORD dwTemp;
//
//	ImmGetConversionStatus(hIMC, &dwConv, &dwSent);
//	dwTemp = dwConv & ~IME_CMODE_LANGUAGE;
//	dwTemp |= IME_CMODE_NATIVE;
//	dwConv = dwTemp;
//	ImmSetConversionStatus(hIMC, dwConv, dwSent);
//	ImmReleaseContext(hWnd, hIMC);
//}

void CDrEdit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	/*if(nChar == 229)
	{
		SetEngMode(m_hWnd);
		return;
	}*/

	CEdit::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CDrEdit::OnSetFocus(CWnd* pOldWnd)
{
	CEdit::OnSetFocus(pOldWnd);
		
	if (m_bSelectAll)
		SetSel(0, -1);
	
	//SetEngMode(m_hWnd);
}


//void CDrEdit::OnEnKillfocus()
//{
//	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//}

void CDrEdit::OnKillFocus(CWnd* pNewWnd)
{
	CEdit::OnKillFocus(pNewWnd);

	if(m_dMaxKillFocus != -1 && m_dMinKillFocus != -1)
		AdjustWithinRangeKillFocus();
}

void CDrEdit::SetEditRangeKillFocus(double dMin, double dMax)
{
	m_bRange = TRUE;
	m_dMinKillFocus = dMin;
	m_dMaxKillFocus = dMax;
}
void CDrEdit::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	if (m_bSelectAll)
		SetSel(0, -1);
	
	CEdit::OnLButtonDown(nFlags, point);
}

void CDrEdit::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	if (m_bSelectAll)
		SetSel(0, -1);

	CEdit::OnLButtonUp(nFlags, point);
}

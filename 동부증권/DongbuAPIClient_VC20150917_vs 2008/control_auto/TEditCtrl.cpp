// TEditCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "TEditCtrl.h"
#include <WINUSER.H>
// 20120723 ssj - 서버자동주문 >>
//.#include "../../../ChartDll/Include_Chart/Dll_Load/IMetaTable.h"
// 20120723 ssj - 서버자동주문 <<
#include <imm.h>
#include "TEditCtrlWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTEditCtrl

/**************************************************************/
/*                                                            */
/*                  TEdit(Dot, Mainers Control                */
/*                                                            */
/*                                                            */
/*                      작성일 : 2004. 11~                    */
/*                  작성자 : 우동우 (두리 정보 통신)          */
/*                                                            */
/**************************************************************/
CTEditCtrl::CTEditCtrl()
{
	m_bAllClear = FALSE;
	m_bIgnoreComma = FALSE;
	m_bTimeType = FALSE;

	m_cNegativeSign = '-';
	m_cDecimalPoint = '.';
	m_strPrefix = "";
	m_cGroupSeparator = ',';
	m_nMaxWholeDigits = 0;
	m_nMaxDecimalPlaces = 0;
	m_bAdjustingSeparators = FALSE;
	m_nDigitsInGroup = 3;
	m_bRange = FALSE;
	m_dMin = 0;
	m_dMax = 100;
	m_bDefReturn = FALSE;
	m_dwarSharedCtrl.RemoveAll();
}

CTEditCtrl::~CTEditCtrl()
{
	m_dwarSharedCtrl.RemoveAll();	
}


BEGIN_MESSAGE_MAP(CTEditCtrl, CEdit)
	//{{AFX_MSG_MAP(CTEditCtrl)
	ON_WM_KILLFOCUS()
	ON_WM_CHAR()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	ON_WM_KEYDOWN()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTEditCtrl message handlers


BOOL CTEditCtrl::Create(const RECT& rect, CWnd* pParentWnd, UINT nID, int nIntegerLength, int nRealLength, BOOL bMinus) 
{
	BOOL bResult = TRUE;

	bResult = CEdit::Create(WS_CHILD | WS_VISIBLE | ES_RIGHT, rect, pParentWnd, nID);

	ModifyStyle(0, WS_BORDER);
	ModifyStyleEx(0, WS_EX_CLIENTEDGE|WS_EX_STATICEDGE);

	m_bUseMinus = bMinus;
	m_nMaxWholeDigits = m_nIntegerLength = nIntegerLength;
	m_nMaxDecimalPlaces = m_nRealLength = nRealLength;
	
	int nMaxLength;
	if (nRealLength > 0)
		nMaxLength = nIntegerLength + nRealLength + 1 + 1;
	else
		nMaxLength = nIntegerLength + 1;
//	LimitText(nMaxLength);

	if(m_nMaxWholeDigits == 0)
		m_nMaxWholeDigits = 9;
		
	return bResult;
}

void CTEditCtrl::SetInit(CString strText)
{
	m_bEscapeKey = FALSE;
	
	m_bDot = FALSE;
	m_bMainers = FALSE;
	m_strEdit.RemoveAll();
	
	m_bFirstInput = TRUE;
	
	if (strText.Find(".", 0) > 0)
		m_bDot = TRUE;
	else
		m_bDot = FALSE;
	
	if (strText.Find("-", 0) > 0)
		m_bMainers = TRUE;
	else
		m_bMainers = FALSE;
	
	for (int nIndex = 0; nIndex < strText.GetLength(); nIndex++)
		m_strEdit.Add(CString(strText[nIndex]));
	
	SetWindowText(strText);
	SetSel(0, strText.GetLength());
	SetFocus();
}

void CTEditCtrl::OnKillFocus(CWnd* pNewWnd) 
{
	PostMessage(WM_CLOSE, 0, 0);
	
	if (!m_bEscapeKey)
	{	

		CString strWindow, strResult, strFormat;
		strFormat.Format("%s%d%s", "%.", m_nMaxDecimalPlaces, "lf");
		GetWindowText(strWindow);

		if(strWindow.IsEmpty())
		{
			CWnd *pWndParent = GetParent();
			pWndParent->SetWindowText(strWindow);		
			return;
		}

		double dValue = _tcstod(GetNumericText(strWindow), NULL);
		strResult.Format(strFormat, dValue);
		
		m_bAllClear = FALSE;
		
		CWnd *pWndParent = GetParent();
		InsertComma(strResult);	
		pWndParent->SetWindowText(strResult);		
		SetTextSharedCtrl(strResult);
	} 
	else 
	{
		
	}
}

BOOL CTEditCtrl::PreTranslateMessage(MSG* pMsg) 
{
	/*
	m_bEscapeKey = FALSE;	

	if (pMsg->wParam == VK_RETURN)
	{		
		if(m_bTimeType)
		{
			SetTimeFormat();
		}
		else
		{
			CString strWindow;
			GetWindowText(strWindow);

			if(strWindow.IsEmpty())
				SetWindowText(strWindow);	
			else
			{
				if(atoi(strWindow) >= INT_MAX)
				{
					MessageBox("입력할 수 있는 최대값은 999,999,999 입니다.");
					strWindow = "999999999";
				}

				InsertComma(strWindow);	
				SetWindowText(strWindow);
			}
		}
		PostMessage(WM_CLOSE, 0, 0);
		if(!m_bDefReturn)
			return TRUE;
	}
	else if (pMsg->wParam == VK_ESCAPE)
	{	
		CString strWindow;
		GetWindowText(strWindow);
		InsertComma(strWindow);
		SetWindowText(strWindow);
		
		PostMessage(WM_CLOSE, 0, 0);
		return m_bEscapeKey = TRUE;
	}
	*/

	return CEdit::PreTranslateMessage(pMsg);
}

void CTEditCtrl::PostNcDestroy() 
{
	CEdit::PostNcDestroy();
}

// void CTEditCtrl::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
// {
// 	int nCount = m_strEdit.GetSize();
// 	
// 	CString strTemp;
// 	if (nCount > 0)
// 		strTemp = m_strEdit.GetAt(nCount - 1);
// 	
// 	if ((nChar == '-') && (m_bMainers == FALSE) && (m_bUseMinus == TRUE))
// 	{
// 		if ((m_bAllClear == FALSE) && (nCount > 0))
// 		{
// 			m_bDot = FALSE;
// 			m_bMainers = FALSE;
// 			m_strEdit.RemoveAll();
// 			m_bAllClear = TRUE;
// 			
// 			CEdit::OnChar(nChar, nRepCnt, nFlags);
// 			m_strEdit.Add((LPCTSTR)&nChar);
// 			m_bMainers = TRUE;
// 		}
// 		else if (nCount == 0)
// 		{
// 			CEdit::OnChar(nChar, nRepCnt, nFlags);
// 			m_strEdit.Add((LPCTSTR)&nChar);
// 			m_bMainers = TRUE;
// 		}
// 	}
// 	else if (nChar == '.') 
// 	{
// 		if ((m_bDot == FALSE) && (nCount > 0))
// 		{
// 			if (strTemp != '-')
// 			{
// 				if (m_bAllClear == FALSE)
// 				{
// 					m_bDot = FALSE;
// 					m_bMainers = FALSE;
// 					m_strEdit.RemoveAll();
// 					m_bAllClear = TRUE;
// 				}
// 				
// 				if (m_nRealLength > 0)
// 				{
// 					CEdit::OnChar(nChar, nRepCnt, nFlags);
// 					m_strEdit.Add((LPCTSTR)&nChar);
// 					m_bDot = TRUE;
// 				}
// 			}
// 		}
// 	}
// 	else if (nChar == VK_BACK)
// 	{
// 		if (nCount > 0)
// 		{
// 			if (strTemp == '-')
// 				m_bMainers = FALSE;
// 			else if (strTemp == '.')
// 				m_bDot = FALSE;
// 			
// 			CEdit::OnChar(nChar, nRepCnt, nFlags);
// 			m_bAllClear = TRUE;
// 			
// 			CString strTemp;
// 			GetWindowText(strTemp);
// 			if (strTemp.IsEmpty() == TRUE)
// 			{
// 				m_bMainers = FALSE;
// 				m_bDot = FALSE;
// 				
// 				m_strEdit.RemoveAll();
// 			}
// 			else
// 				m_strEdit.RemoveAt(nCount - 1, 1);
// 		}
// 		else
// 		{
// 			m_bDot = FALSE;
// 			m_bMainers = FALSE;
// 			m_strEdit.RemoveAll();
// 		}
// 	}
// 	else if(nChar == VK_RETURN)
// 	{
// 		MessageBox("1");
// 	}
// 	else if ((nChar >= '0') && (nChar <= '9'))
// 	{
// 		if (m_bAllClear == FALSE)
// 		{
// 			m_bDot = FALSE;
// 			m_bMainers = FALSE;
// 			m_strEdit.RemoveAll();
// 			m_bAllClear = TRUE;
// 		}
// 
// 		BOOL bAdd = TRUE;
// 		if (m_bDot == TRUE)
// 		{
// 			int nRealCnt = 1;
// 			BOOL bHaveDot = FALSE;
// 			for (int nIndex = 0; nIndex < m_strEdit.GetSize(); nIndex++)
// 			{
// 				if (bHaveDot == TRUE)
// 					nRealCnt++;
// 				else
// 				{
// 					if (m_strEdit.GetAt(nIndex) == ".")
// 						bHaveDot = TRUE;
// 				}
// 			}
// 
// 			if (m_nRealLength < nRealCnt)
// 				bAdd = FALSE;
// 		}
// 		
// 		if (bAdd == TRUE)
// 		{		
// 			CEdit::OnChar(nChar, nRepCnt, nFlags);
// 			m_strEdit.Add((LPCTSTR)&nChar);
// 			
// 		}
// 	}
// }

void CTEditCtrl::ValueWithComma(CString& strData)
{
	for(int nIndex = 3; nIndex < strData.GetLength(); nIndex+=4)
	{		
		if( strData[strData.GetLength() - nIndex - 1] == ',')
			continue;
		strData.Insert(strData.GetLength() - nIndex, ',');
	}
}
/*
LRESULT CTEditCtrl::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	if(message==WM_SETTEXT)
	{
		m_szText = (LPCTSTR)lParam;
//		IDataUtilManager* pMng = (IDataUtilManager*)AfxGetPctrInterface(UUID_IDataUtilManager);
//		m_szText = pMng->GetComma(m_szText);
		m_szText = GetComma(m_szText);
//		CEdit::SetWindowText(m_szText);
		return 1;
	}
	else if(message==WM_GETTEXT)
	{
		return OnGetText(wParam, lParam);
	}

	return CEdit::WindowProc(message, wParam, lParam);
}
*/
LRESULT CTEditCtrl::OnGetText(WPARAM wParam, LPARAM lParam)
{
	int nMaxLen = (int)wParam;
	if (nMaxLen == 0)
		return 0;       // nothing copied
	LPTSTR lpszDest = (LPTSTR)lParam;

	m_szText.Remove(',');

	int nLen = m_szText.GetLength();
	memcpy(lpszDest, (LPCTSTR)m_szText, nLen);

	lpszDest[nLen] = '\0';
	return nLen+1;      // number of bytes copied
}

CString CTEditCtrl::GetComma(LPCSTR pData)
{
	CString szRet=_T("");
	CString szTmp = pData;
	szTmp.TrimLeft();
	szTmp.TrimRight();

	szTmp = GetNumber(szTmp);

	if(szTmp.IsEmpty())	return "" ;
	TCHAR ch=' ';
	if(szTmp[0]=='+' ||szTmp[0]=='-') 
	{
		ch = szTmp[0];
		szTmp = szTmp.Mid(1);
	}

	// 앞의 0 제거
	CString sTemp;
	TCHAR chTemp = '0';
	sTemp = RemoveFront(szTmp, chTemp);
	
	// 소수점 이하 제거
	CString sTemp1;
	int nIndex = sTemp.Find(".");
	if( nIndex >= 0 )
	{
		sTemp1 = sTemp.Mid(nIndex+1);
		szTmp = sTemp.Left(nIndex);
	}
	else
		szTmp = sTemp;		
	//

	// 전부 0일 경우에 0을 추가
	if( szTmp.GetLength() == 0 )
		szTmp = "0";
	
	szTmp.MakeReverse();
	int	nLen = szTmp.GetLength();	
	szRet.Empty();
 	for(int i=0;   i<nLen;   i++) 
	{
		if(i!=0 && !(i%3))	szRet += ',';
		szRet += szTmp[i];
	}
	if(ch=='-') szRet += ch;
	szRet.MakeReverse();	

	// 소수점 이하 다시 붙임
	if( nIndex >= 0 )
	{
		szRet = szRet + "." +sTemp1;
	}

	return szRet;

}

CString  CTEditCtrl::GetNumber( LPCSTR pData )
{
	CString szRet=_T("");
	int nLen = strlen(pData);
	char	ch;

	for(int i=0;  i<nLen ; i++) {
		ch = pData[i];
		if(ch >= '0' && ch <= '9'||ch == '.' || ch == '-' || ch== '+') 
			szRet += ch;
	}
	return szRet;
}

char* CTEditCtrl::RemoveFront(LPCSTR pData, TCHAR ch)
{
	int nLen = strlen(pData);
	int nSameCharCnt = 0;

	for(int i=0;  i<nLen ; i++) 
	{  
		if(pData[i]!=ch) return (char *)&pData[i];
		nSameCharCnt++;
	}

	//같은 길이를 가진 
	if(ch == '0' && nSameCharCnt == nLen)
	{
		return (char*)&pData[nLen-1] ;
	}

	return (char *)pData;
}

void CTEditCtrl::InsertComma(CString & str1)
{
	if(m_bIgnoreComma)
		return;
	
	CString str,strTemp1,strTemp2,strTemp3;
	str = str1;
	str.Remove(',');
	//부호 처리.
	if(str.GetLength() > 0)
	{
		if(str.GetAt(0) == '-' || str.GetAt(0) == '+')
		{
			strTemp1 = str.Left(1);
			str = str.Mid(1);//부호제거한 문자열.
		}
	}

	int pos ;
	int x,y,i;
	//소수점 부분을 제거한다.
	if((pos = str.Find(".")) != -1)
	{
		strTemp3 = str.Mid(pos);//소수점부터 이하값을 가지고 있는 변수.
		str = str.Left(pos);//소수점 위의 내용을 가지고 있다.
	}
	//문자열의 길이를 구한다.
	int nLength = str.GetLength();
	int max;//콤마의 최대갯수

	//정수 3자리 이상의 값일 경우.
	if((x = nLength / 3) > 0)//몫->x
	{
		if((y = nLength % 3) > 0) //정확히 나누어 떨어지지 않을 때.
			max = x;
		else if(y == 0)
			max = x-1;
		
		for(i = 0 ; i < max ; i++)//실제로 콤마를 삽입하는 부분.
		{
			if((pos = str.Find(','))== -1)//콤마가 문자열에 없을 경우.
			{
				str = str.Left(nLength-3)+","+str.Mid(nLength-3);					
			}
			else
			{
				str = str.Left(pos-3)+","+str.Mid(pos-3);					
			}
		}
		str1 = strTemp1 + str + strTemp3;		
	}
}

BOOL CTEditCtrl::SetTimeFormat()
{
	CString strTime;
	GetWindowText(strTime);

	if(strTime.GetLength() == 6)
	{
		BOOL bChk = TRUE;

		if(strTime.GetAt(0) >= '3')
			bChk = FALSE;

		if(strTime.GetAt(0) == '2' && strTime.GetAt(1) >= '4')
			bChk = FALSE;

		if(strTime.GetAt(2) >= '6')
			bChk = FALSE;

		if(strTime.GetAt(5) >= '6')
			bChk = FALSE;

		if(bChk)
		{	
			strTime.Insert(2, _T(':'));
			strTime.Insert(5, _T(':'));

			SetWindowText(strTime);
			m_strBeforeText = strTime;
		}
		else
		{
			SetWindowText(m_strBeforeText);
			CString strErrorMsg;
			strErrorMsg.Format("시간형식이 잘못되었습니다.");
			MessageBox(strErrorMsg, MB_OK);
			SetFocus();
			return FALSE;
		}
	}
	else
	{
		SetWindowText(m_strBeforeText);
		CString strErrorMsg;
		strErrorMsg.Format("시분초 각 두자리씩 숫자로만 표시해주십시요.");
		MessageBox( strErrorMsg, MB_OK);
		SetFocus();
		return FALSE;						
	}

	return TRUE;
}

//EditBox 기능개선~ 


void CTEditCtrl::OnChar(UINT uChar, UINT nRepCnt, UINT nFlags)
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
			{
				CEdit::OnChar(uChar, nRepCnt, nFlags);
				SetTextSharedCtrl();
			}
		}
		// If it's a part of the number, enter the prefix
		else if ((_istdigit(c) || c == m_cNegativeSign || c == m_cDecimalPoint)/* && _ShouldEnter(c)*/)
		{
			nEnd = (nEnd == nLen ? nEnd : (nPrefixLen));
			SetSel(nStart, nEnd);
			ReplaceSel(m_strPrefix.Mid(nStart), TRUE);

			OnChar(uChar, nRepCnt, nFlags);
			SetTextSharedCtrl();
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
				SetTextSharedCtrl();
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
			SetTextSharedCtrl();
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
				SetTextSharedCtrl();
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
				SetTextSharedCtrl();
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
				SetTextSharedCtrl();
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
				SetTextSharedCtrl();
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
	SetTextSharedCtrl();

	AdjustWithinRange();
	// If the decimal point was added/removed or a separator needs adding/removing, adjust the text
	if (bNeedAdjustment)
		AdjustSeparators(nSepCount);
	
}

CString CTEditCtrl::GetNumericText(const CString& strText, bool bUseMathSymbols /*= false*/)
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

int CTEditCtrl::GetGroupSeparatorCount(const CString& strText)
{
	int iPos, nSepCount, nLen;
	for (iPos = 0, nSepCount = 0, nLen = strText.GetLength(); iPos < nLen; iPos++)
	{
		if (strText[iPos] == m_cGroupSeparator)
			nSepCount++;
	}

	return nSepCount;
}

BOOL CTEditCtrl::IsNegativeAllowed()
{
	return m_bUseMinus;
}


void CTEditCtrl::AdjustSeparators(int nCurrentSeparatorCount)
{
//	SelectionSaver selection = m_pEdit;
	m_bAdjustingSeparators = TRUE;

	CString strValidText = GetValidText();
	CString strText;
	GetWindowText(strText);
// 	if (strValidText != strText)
// 	{
// 		int nLen = strValidText.GetLength();		
// 		SetWindowText(strValidText);
// 		SetSel(nLen, nLen);
// 	}
	int nStart, nEnd, nFind;
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

CString CTEditCtrl::GetValidText()
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

CString CTEditCtrl::GetSeparatedText(const CString& strText)
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

void CTEditCtrl::AdjustWithinRange()
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
//
//void CTEditCtrl::SetEngMode(HWND hWnd)
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
//void CTEditCtrl::SetHanMode(HWND hWnd)
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

void CTEditCtrl::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	/*if(nChar == 229)
	{
		SetEngMode(m_hWnd);
		return;
	}*/

	CEdit::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CTEditCtrl::OnSetFocus(CWnd* pOldWnd)
{
	CEdit::OnSetFocus(pOldWnd);

	//SetEngMode(m_hWnd);
}

void CTEditCtrl::SetDefReturn(BOOL bSet)
{
	m_bDefReturn = bSet;
}

void CTEditCtrl::SetTextSharedCtrl(CString strText)
{
	int nIndex;
	for(nIndex = 0; nIndex < m_dwarSharedCtrl.GetSize(); nIndex++)
	{
		HWND hWnd = (HWND)m_dwarSharedCtrl.GetAt(nIndex);
		CTEditCtrlWnd* pWnd = ((CTEditCtrlWnd*)FromHandle(hWnd));
		if(pWnd)
		{
			if(strText.IsEmpty())
				GetWindowText(strText);
			pWnd->SetText(strText);			
			pWnd->AdjustText();			
		}
	}
}
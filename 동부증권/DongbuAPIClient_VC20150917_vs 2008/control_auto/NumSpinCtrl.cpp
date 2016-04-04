// NumSpinCtrl.cpp : implementation file
//
// Damir Valiulin, Rocscience Inc.
//
// See header file for usage.
//

#include "stdafx.h"
#include "NumSpinCtrl.h"
#include <math.h>
#include <locale.h>

#include "../include_auto/globalauto.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define EPS 1.0e-9

/////////////////////////////////////////////////////////////////////////////
// CNumSpinCtrl

CNumSpinCtrl::CNumSpinCtrl()
{
	m_Delta = 1;
	m_MinVal = 0;
	m_MaxVal = 100;
	m_IntRange = 100;

	lconv* pLconv = localeconv ();
	m_DecSymbol = *pLconv->decimal_point;
	m_bTrimTrailingZeros = TRUE;
	SetDecimalPlaces (-1); // simple formatting through "%g"
	SetFormatString (NULL);

	m_bInUp = m_bInDown = FALSE;
	m_bCapture = FALSE;
	m_bUpClick = m_bDownClick = FALSE;	
	m_bNoRemain = FALSE;
}

CNumSpinCtrl::CNumSpinCtrl(CString strImagePath)
{
	m_Delta = 1;
	m_MinVal = 0;
	m_MaxVal = 100;
	m_IntRange = 100;

	lconv* pLconv = localeconv ();
	m_DecSymbol = *pLconv->decimal_point;
	m_bTrimTrailingZeros = TRUE;
	SetDecimalPlaces (-1); // simple formatting through "%g"
	SetFormatString (NULL);

	m_bInUp = m_bInDown = FALSE;
	m_bCapture = FALSE;
	m_bUpClick = m_bDownClick = FALSE;
	m_strImagePath = strImagePath;
	m_bNoRemain = FALSE;
}

CNumSpinCtrl::~CNumSpinCtrl()
{
	m_imgBtnList.DeleteImageList();
}


BEGIN_MESSAGE_MAP(CNumSpinCtrl, CSpinButtonCtrl)
	//{{AFX_MSG_MAP(CNumSpinCtrl)
	ON_NOTIFY_REFLECT_EX(UDN_DELTAPOS, OnDeltapos)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNumSpinCtrl message handlers

void CNumSpinCtrl::SetValueForBuddy (double val)
{
	CWnd* pEdit = GetBuddy();
	if (pEdit)
	{
		if(m_bNoRemain)
			val = val - (int)val % 10;		

		CString str;
		if (m_strFormat.IsEmpty ())
			str = FormatValue (val);
		else
			str.Format (m_strFormat, val);
		
		InsertComma(str);
		pEdit->SetWindowText (str);
	}
}

void CNumSpinCtrl::SetPos(double val)
{
	SetValueForBuddy (val);
	SetIntPos (val);
}

double CNumSpinCtrl::GetPos()
{
	CWnd* pEdit = GetBuddy();
	if (pEdit)
	{
		CString str;
		pEdit->GetWindowText (str);
		str.Remove(',');
		double val = atof (str);
		return val;
	}
	else
	{
		//ASSERT (FALSE); // you didn't set buddy
		return 0.0;
	}
}

void CNumSpinCtrl::SetRangeAndDelta(double lower, double upper, double delta)
{
	m_MinVal = lower;
	m_MaxVal = upper;
	m_Delta = delta;

	ASSERT (m_MaxVal > m_MinVal); // reversed min/max is not implemented, although it's probably easy

	//// avoid division by zero
	if (m_Delta == 0.0 || IsSame(m_Delta, 0))// fabs(m_Delta - 0.0) <= 0.0001)
		return;

	/// Figure out the integer range to use, so that acceleration can work properly
	double range = fabs ((m_MaxVal - m_MinVal) / m_Delta);
	if (range > (double)UD_MAXVAL)
		m_IntRange = UD_MAXVAL;
	else
		m_IntRange = (int) range;
	CSpinButtonCtrl::SetRange32 (0, m_IntRange);

	/// Set integer position
	SetIntPos (GetPos());
}

void CNumSpinCtrl::SetIntPos (double pos)
{
	//// avoid division by zero
	if (m_MaxVal == m_MinVal)
		return;
	
	if (IsSame(m_MaxVal, m_MinVal))
		return;

	int int_pos;
	
	if (pos < m_MinVal)
		int_pos = 0;
	else if (pos > m_MaxVal)
		int_pos = m_IntRange;
	else
	{
		// where in the range is current position?
		double pos_in_range = (pos - m_MinVal) / (m_MaxVal - m_MinVal);
		int_pos = (int)(m_IntRange * pos_in_range + 0.5);
	}
	CSpinButtonCtrl::SetPos (int_pos);
}

void CNumSpinCtrl::GetRangeAndDelta(double& lower, double& upper, double& delta)
{
	lower = m_MinVal;
	upper = m_MaxVal;
	delta = m_Delta;
}

BOOL CNumSpinCtrl::OnDeltapos(NMHDR* pNMHDR, LRESULT* pResult)
{
	NM_UPDOWN* pUD = (NM_UPDOWN*)pNMHDR;
	
	double val = GetPos () + m_Delta * pUD->iDelta;

	const bool can_wrap = (UDS_WRAP & GetStyle());


	if (pUD->iDelta < 0) // spin down
	{
		double abs_eps = fabs(EPS * max (val, m_MinVal));
		if (abs_eps < EPS) abs_eps = EPS;

		if (m_MinVal - val > abs_eps){  //if (val < m_MinVal){		
			if(can_wrap){
				val = m_MaxVal;
			}
			else{
				val = m_MinVal;
			}
		}
	}
	else  // spin up
	{
		double abs_eps = fabs(EPS * max (val, m_MaxVal));
		if (abs_eps < EPS) abs_eps = EPS;
		
		if (val - m_MaxVal > abs_eps){   //if (val > m_MaxVal){		
			if(can_wrap){
				val = m_MinVal;
			}
			else{
				val = m_MaxVal;
			}
		}
	}

	SetValueForBuddy (val);

	*pResult = 0;

	return FALSE; // let parent process this notification too.
}

int CNumSpinCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CSpinButtonCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	InitSpinCtrl();

	return 0;
}


void CNumSpinCtrl::InitSpinCtrl()
{
	ASSERT ((GetStyle () & UDS_SETBUDDYINT) != UDS_SETBUDDYINT); // Otherwise control won't work properly!
	//ModifyStyle (UDS_SETBUDDYINT, UDS_ARROWKEYS);
	SetRangeAndDelta (m_MinVal, m_MaxVal, m_Delta); // set default values

	
	//CString m_strImagePath = "c:\\Hanwha\\svn\\ProjSrc\\WinDebug\\Image";
	if(!m_strImagePath.IsEmpty())
	{
		char szPath[MAX_PATH];
		CBitmap	bitmap;

		if(!m_imgBtnList.m_hImageList)
		{
			m_imgBtnList.Create(17, 20, ILC_COLORDDB/*|ILC_MASK*/, 1, 1);

			sprintf_s(szPath, MAX_PATH, "%s\\Contents\\%s", m_strImagePath, "btn_spin_aroow01_default.bmp");
			bitmap.Attach((HBITMAP)LoadImage(NULL, szPath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE|LR_CREATEDIBSECTION|LR_DEFAULTSIZE));
			m_imgBtnList.Add(&bitmap, RGB(255,0, 255));
			bitmap.DeleteObject();

			sprintf_s(szPath, MAX_PATH, "%s\\Contents\\%s", m_strImagePath, "btn_spin_aroow01_down.bmp");
			bitmap.Attach((HBITMAP)LoadImage(NULL, szPath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE|LR_CREATEDIBSECTION|LR_DEFAULTSIZE));
			m_imgBtnList.Add(&bitmap, RGB(255,0, 255));
			bitmap.DeleteObject();

			sprintf_s(szPath, MAX_PATH, "%s\\Contents\\%s", m_strImagePath, "btn_spin_aroow01_disable.bmp");
			bitmap.Attach((HBITMAP)LoadImage(NULL, szPath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE|LR_CREATEDIBSECTION|LR_DEFAULTSIZE));
			m_imgBtnList.Add(&bitmap, RGB(255,0, 255));
			bitmap.DeleteObject();

			sprintf_s(szPath, MAX_PATH, "%s\\Contents\\%s", m_strImagePath, "btn_spin_aroow02_default.bmp");
			bitmap.Attach((HBITMAP)LoadImage(NULL, szPath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE|LR_CREATEDIBSECTION|LR_DEFAULTSIZE));
			m_imgBtnList.Add(&bitmap, RGB(255,0, 255));
			bitmap.DeleteObject();

			sprintf_s(szPath, MAX_PATH, "%s\\Contents\\%s", m_strImagePath, "btn_spin_aroow02_down.bmp");
			bitmap.Attach((HBITMAP)LoadImage(NULL, szPath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE|LR_CREATEDIBSECTION|LR_DEFAULTSIZE));
			m_imgBtnList.Add(&bitmap, RGB(255,0, 255));
			bitmap.DeleteObject();

			sprintf_s(szPath, MAX_PATH, "%s\\Contents\\%s", m_strImagePath, "btn_spin_aroow02_disable.bmp");
			bitmap.Attach((HBITMAP)LoadImage(NULL, szPath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE|LR_CREATEDIBSECTION|LR_DEFAULTSIZE));
			m_imgBtnList.Add(&bitmap, RGB(255,0, 255));
			bitmap.DeleteObject();

		}

		Invalidate();
	}

}

CString CNumSpinCtrl::FormatValue (double val)
{
	CString str;
	
	if (m_NumDecPlaces == -1) // no precision specified
	{
		str.Format (_T("%g"), val);
		return str;
	}

	CString fstr;

	/// Check which format to use ('e' or 'f')
	bool bExponential;
	fstr.Format (_T("%g"), val);
	if (fstr.Find (_T('e')) != -1)
	{
		fstr.Format (_T("%%.%de"), m_NumDecPlaces);
		bExponential = true;
	}
	else
	{
		fstr.Format (_T("%%.%df"), m_NumDecPlaces);
		bExponential = false;
	}

	/// Output the number with given format
	str.Format (fstr, val);

	/// Check for trailing zeros and remove them
	if (m_bTrimTrailingZeros)
	{
		if (bExponential)
		{
			// separate base and exponent
			CString strBase, strExponent;
			int e_pos = str.Find (_T('e'));
			strBase = str.Left (e_pos);
			strExponent = str.Right (str.GetLength () - e_pos);
			
			if (str.Find (m_DecSymbol) != -1){
				strBase.TrimRight (_T('0'));
				strBase.TrimRight (m_DecSymbol); // if dot is all that's left
			}
			
			str = strBase + strExponent; //reconstruct
		}
		else
		{
			if (str.Find (m_DecSymbol) != -1){
				str.TrimRight (_T('0'));
				str.TrimRight (m_DecSymbol); // if dot is all that's left
			}
		}
	}
	
	return str;
}

void CNumSpinCtrl::SetDecimalPlaces(int number)
{
	m_NumDecPlaces = number;
}

int CNumSpinCtrl::GetDecimalPlaces()
{
	return m_NumDecPlaces;
}

void CNumSpinCtrl::SetFormatString (LPCTSTR lpszFormatString /*= NULL*/)
{
	if (lpszFormatString == NULL)
		m_strFormat.Empty ();
	else
		m_strFormat = lpszFormatString;
}

void CNumSpinCtrl::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CRect rc;
	GetWindowRect(&rc);
	ScreenToClient(&rc);

	int y = rc.CenterPoint().y;
	CRect rcUpper(rc);
	rcUpper.bottom = y;
	CRect rcDown(rc);
	rcDown.top = y;

	if(!m_imgBtnList.m_hImageList) return;
	if(IsWindowEnabled())
	{
		if(m_bInUp)
			m_imgBtnList.Draw(&dc, 1, rcUpper.TopLeft(), ILD_NORMAL);
		else 
			m_imgBtnList.Draw(&dc, 0, rcUpper.TopLeft(), ILD_NORMAL);
	}
	else
		m_imgBtnList.Draw(&dc, 2, rcUpper.TopLeft(), ILD_NORMAL);

	if(IsWindowEnabled())
	{
		if(m_bInDown)
			m_imgBtnList.Draw(&dc, 4, rcDown.TopLeft(), ILD_NORMAL);
		else 
			m_imgBtnList.Draw(&dc, 3, rcDown.TopLeft(), ILD_NORMAL);
	}
	else
		m_imgBtnList.Draw(&dc, 5, rcUpper.TopLeft(), ILD_NORMAL);

	// Do not call CSpinButtonCtrl::OnPaint() for painting messages
}

void CNumSpinCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rc;
	GetWindowRect(&rc);
	ScreenToClient(&rc);

	int y = rc.CenterPoint().y;
	CRect rcUpper(rc);
	rcUpper.bottom = y;
	CRect rcDown(rc);
	rcDown.top = y;

	m_bInUp = m_bInDown = FALSE;

	if(rcUpper.PtInRect(point)) 
	{
		m_bInUp = TRUE;
		m_bUpClick = TRUE;
	}
	else if(rcDown.PtInRect(point))
	{
		m_bInDown = TRUE;
		m_bDownClick = TRUE;
	}

	if(m_bInUp || m_bInDown)
	{
		////TRACEP("4", "SetCapture");
		SetCapture();
		m_bCapture = TRUE;
	}

	CSpinButtonCtrl::OnLButtonDown(nFlags, point);
}

void CNumSpinCtrl::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_bInUp = m_bInDown = FALSE;
	////TRACEP("5", "ReleaseCapture");

	// 20120723 ssj - 서버자동주문 >>
	if (m_bCapture)
	// 20120723 ssj - 서버자동주문 <<
	{
		ReleaseCapture();
		m_bCapture = FALSE;
	}
	m_bUpClick = m_bDownClick = FALSE;
	CSpinButtonCtrl::OnLButtonUp(nFlags, point);
}

void CNumSpinCtrl::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	if(m_bCapture)
	{
		CRect rc;
		GetWindowRect(&rc);
		ScreenToClient(&rc);

		int y = rc.CenterPoint().y;
		CRect rcUpper(rc);
		rcUpper.bottom = y;
		CRect rcDown(rc);
		rcDown.top = y;

		if(m_bUpClick)
		{
			m_bInUp = m_bInDown = FALSE;
			if(rcUpper.PtInRect(point)) 
			{
				m_bInUp = TRUE;
			
			}
			else
			{
				m_bInUp = FALSE;

				// 20120723 ssj - 서버자동주문 >>
				ReleaseCapture();
				m_bCapture = FALSE;
				// 20120723 ssj - 서버자동주문 <<
			}
			//InvalidateRect(rcUpper);
		}
		
		if(m_bDownClick)
		{
			if(rcDown.PtInRect(point))
			{
				m_bInDown = TRUE;
			}
			else
			{
				m_bInDown = FALSE;

				// 20120723 ssj - 서버자동주문 >>
				ReleaseCapture();
				m_bCapture = FALSE;
				// 20120723 ssj - 서버자동주문 <<
			}
		//	InvalidateRect(rcDown);
		}
	}
	
	CSpinButtonCtrl::OnMouseMove(nFlags, point);
}

BOOL CNumSpinCtrl::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}


//
//BOOL CNumSpinCtrl::IsSame(double d1, double d2)
//{
//	if (fabs(d1 - d2) < 0.0001)
//		return TRUE;
//
//	return FALSE;
//}
//
//void CNumSpinCtrl::InsertComma(CString & str1)
//{	
//
//	CString str,strTemp1,strTemp2,strTemp3;
//	str = str1;
//	//부호 처리.
//	if(str.GetLength() > 0)
//	{
//		if(str.GetAt(0) == '-' || str.GetAt(0) == '+')
//		{
//			strTemp1 = str.Left(1);
//			str = str.Mid(1);//부호제거한 문자열.
//		}
//	}
//
//	int pos ;
//	int x,y,i;
//	//소수점 부분을 제거한다.
//	if((pos = str.Find(".")) != -1)
//	{
//		strTemp3 = str.Mid(pos);//소수점부터 이하값을 가지고 있는 변수.
//		str = str.Left(pos);//소수점 위의 내용을 가지고 있다.
//	}
//	//문자열의 길이를 구한다.
//	int nLength = str.GetLength();
//	int max;//콤마의 최대갯수
//
//	//정수 3자리 이상의 값일 경우.
//	if((x = nLength / 3) > 0)//몫->x
//	{
//		if((y = nLength % 3) > 0) //정확히 나누어 떨어지지 않을 때.
//			max = x;
//		else if(y == 0)
//			max = x-1;
//
//		for(i = 0 ; i < max ; i++)//실제로 콤마를 삽입하는 부분.
//		{
//			if((pos = str.Find(','))== -1)//콤마가 문자열에 없을 경우.
//			{
//				str = str.Left(nLength-3)+","+str.Mid(nLength-3);					
//			}
//			else
//			{
//				str = str.Left(pos-3)+","+str.Mid(pos-3);					
//			}
//		}
//		str1 = strTemp1 + str + strTemp3;		
//	}
//}

#if !defined(AFX_TEDITCTRLWND_H__DD33EF1A_0D99_4C14_9E1B_63B7F8A42F16__INCLUDED_)
#define AFX_TEDITCTRLWND_H__DD33EF1A_0D99_4C14_9E1B_63B7F8A42F16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TEdit.h : header file
//

/************************************************************************/
/*																		                                  */
/*	          						Edit Wnd  Control							                */
/*						                                  												*/
/*																		                                  */
/*		      					작성일 : 2004. 11~						                  	*/
/*	        					작성자 : 우동우 (두리 정보 통신)				          */
/*																		                                  */
/************************************************************************/

/////////////////////////////////////////////////////////////////////////////
// CTEditCtrlWnd window

class CTEditCtrl;
class CTEditCtrlWnd : public CWnd
{
	// Construction
public:
	CTEditCtrlWnd();
	virtual ~CTEditCtrlWnd();

	BOOL Create(const RECT& rect, CWnd* pParentWnd, UINT nID, COLORREF clrFace, 
					int nIntegerLength, int nRealLength = 0, BOOL bEnable = TRUE, BOOL bMinus = 1);
	
	void InsertComma(CString & str1);

	void IngnoreComma(BOOL bValue) { m_bIgnoreComma = bValue; }

	BOOL TimeFormat(CString str);
	void SetTimeType(BOOL bTimeType);
	void SetUseMinus(BOOL bUse);
	void SetNumPlaces(int nInterer, int nPoint);
	void SetText(CString str);
	void SetEditFocus();

	void SetDefReturn(BOOL bSet = TRUE);//0000260: [자동주문]기능추가 및 로직변경 검토안
	void SetShareGroup(DWORD dwGroup);
	CWnd* GetInnerEditCtrlHwnd();

	// 20120723 ssj - 서버자동주문 >>
	void	AdjustText();
	// 20120723 ssj - 서버자동주문 <<

private:
	BOOL  m_bUseMinus;
	CFont m_fontDefault;

	COLORREF	m_clrFace;
	COLORREF	m_clrTopLeft;
	COLORREF	m_clrBottomRight;
			
	CTEditCtrl  *m_pEditCtrl;
	BOOL		m_bIgnoreComma;
	BOOL		m_bTimeType;
	BOOL		m_bDefReturn;//0000260: [자동주문]기능추가 및 로직변경 검토안	

protected:
	int m_nIntegerLength, m_nRealLength;
	BOOL m_bEnable;

	CString GetCurrencyText(CString strSource);
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTEditCtrlWnd)
	public:
	
	//}}AFX_VIRTUAL
		
	// Generated message map functions
protected:
	//{{AFX_MSG(CTEditCtrlWnd)
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEDITCTRLWND_H__DD33EF1A_0D99_4C14_9E1B_63B7F8A42F16__INCLUDED_)

#if !defined(AFX_DREDIT_H__5CF7EC3A_4D89_4595_BFF2_31461293D1FC__INCLUDED_)
#define AFX_DREDIT_H__5CF7EC3A_4D89_4595_BFF2_31461293D1FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DrEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDrEdit window

class CDrEdit : public CEdit
{
// Construction
public:
	CDrEdit();

// Attributes
public:
	BOOL m_bRange;
	double	 m_dMax;
	double	 m_dMin;

	double	 m_dMaxKillFocus;
	double	 m_dMinKillFocus;

	// 20120723 ssj - 서버자동주문 >>
	BOOL	m_bSelectAll;
	// 20120723 ssj - 서버자동주문 <<

	BOOL m_bDot;
	BOOL m_bUseMinus;
	//
	TCHAR	m_cNegativeSign, m_cDecimalPoint, m_cGroupSeparator;
	int		m_nMaxWholeDigits, m_nMaxDecimalPlaces, m_nDigitsInGroup, m_nRealLength;
	CString m_strPrefix;
	BOOL	m_bAdjustingSeparators;
	CString GetNumericText(const CString& strText, bool bUseMathSymbols = false);
	int		GetGroupSeparatorCount(const CString& strText);
	BOOL	IsNegativeAllowed();
	void	AdjustSeparators(int nCurrentSeparatorCount);
	CString GetValidText();
	CString GetSeparatedText(const CString& strText);
	void	AdjustWithinRange();
	void	AdjustWithinRangeKillFocus();
	void	SetUseMinus(BOOL bUse);
	void	SetPlaces(int nIntegerPlaces, int nDecimalPlaces);
	//void	SetEngMode(HWND hWnd);
	//void	SetHanMode(HWND hWnd);
	void	SetEditRangeKillFocus(double dMin, double dMax);

// Operations
public:
	void SetEditRange(double dMin, double dMax);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDrEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDrEdit)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnNcPaint();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
//	afx_msg void OnEnKillfocus();
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	// 20120723 ssj - 서버자동주문 >>
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	// 20120723 ssj - 서버자동주문 <<
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DREDIT_H__5CF7EC3A_4D89_4595_BFF2_31461293D1FC__INCLUDED_)

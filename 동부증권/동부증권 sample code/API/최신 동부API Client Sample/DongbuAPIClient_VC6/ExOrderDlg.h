#if !defined(AFX_EXORDERDLG_H__4CC3D2D9_CEEC_417A_8F9F_1CF528A19C95__INCLUDED_)
#define AFX_EXORDERDLG_H__4CC3D2D9_CEEC_417A_8F9F_1CF528A19C95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExOrderDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExOrderDlg dialog

class CExOrderDlg : public CDialog
{
// Construction
public:
	CExOrderDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CExOrderDlg)
	enum { IDD = IDD_DLG_ORDER };
	CListBox	m_lstMsg;
		CComboBox	m_cmbPriceType;
		CString	m_strAcctPwd;
		CString	m_strDate;
		CString	m_strJongmok;
		CString	m_strPrice;
		CString	m_strQty;
	CString	m_strAccount;
	//}}AFX_DATA
	
	int		m_nTRCode ;		
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExOrderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CExOrderDlg)
		virtual BOOL OnInitDialog();
		afx_msg void OnBtnAbleqty();
		afx_msg void OnBtnOrder();
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXORDERDLG_H__4CC3D2D9_CEEC_417A_8F9F_1CF528A19C95__INCLUDED_)

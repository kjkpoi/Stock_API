#if !defined(AFX_EXINQUERYDLG_H__506916BA_4D21_4B05_9275_ACC333DA9900__INCLUDED_)
#define AFX_EXINQUERYDLG_H__506916BA_4D21_4B05_9275_ACC333DA9900__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExInqueryDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExInqueryDlg dialog

class CExInqueryDlg : public CDialog
{
// Construction
public:
	CExInqueryDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CExInqueryDlg)
	enum { IDD = IDD_DLG_QUERY };
	CListBox	m_lstMsg;
		CString		m_strAcctPwd;
		CString		m_strDate;
	CString	m_strAccount;
	//}}AFX_DATA
	
	int			m_nTRCode ;	
	CString		m_szNextKey ;

	CString		GetSelAccount() ;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExInqueryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CExInqueryDlg)
	afx_msg void OnBtnInqury();
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXINQUERYDLG_H__506916BA_4D21_4B05_9275_ACC333DA9900__INCLUDED_)

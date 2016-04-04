#if !defined(AFX_EXOPTDEPOSITDLG_H__F91BDA4C_3D85_445E_B446_14DCEC380C5B__INCLUDED_)
#define AFX_EXOPTDEPOSITDLG_H__F91BDA4C_3D85_445E_B446_14DCEC380C5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExOptDepositDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExOptDepositDlg dialog

class CExOptDepositDlg : public CDialog
{
// Construction
public:
	CExOptDepositDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CExOptDepositDlg)
	enum { IDD = IDD_DLG_OPTIONDEPOSIT };
	CListBox	m_lstMsg;
	CComboBox	m_cmbMonth;
	CComboBox	m_cmbItem;
	CComboBox	m_cmbBaseAsset;
	//}}AFX_DATA

	CString		m_szNextKey;
	void		ParseSubMessage(char *pTRData, int &nOffset, int &nCount) ;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExOptDepositDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CExOptDepositDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnInqury();
	afx_msg void OnSelchangeCmbItem();
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXOPTDEPOSITDLG_H__F91BDA4C_3D85_445E_B446_14DCEC380C5B__INCLUDED_)

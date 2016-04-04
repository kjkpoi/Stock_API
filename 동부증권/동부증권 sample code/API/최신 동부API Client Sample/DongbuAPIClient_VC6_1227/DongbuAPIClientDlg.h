// DongbuAPIClientDlg.h : header file
//

#if !defined(AFX_DONGBUAPICLIENTDLG_H__5BC797B4_BF25_46DA_A6A1_9CD41F62EF0F__INCLUDED_)
#define AFX_DONGBUAPICLIENTDLG_H__5BC797B4_BF25_46DA_A6A1_9CD41F62EF0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDongbuAPIClientDlg dialog

#define SZ_ACCOUNTNO     11

class CDongbuAPIClientDlg : public CDialog
{
// Construction
public:
	CDongbuAPIClientDlg(CWnd* pParent = NULL);	// standard constructor

	HWND	FindDRCM(CString szUserName);		
	BOOL	GetDRCMInfo(CString &szRoot, CString &szExe, CString &szWinName );	
	void    EnableControls(BOOL bConnected);

	void    GetClientIp() ;
	CString SetIp (CString szIP) ;
	void    GetFutureAccList(LPSTR szData, int nLen);

	HWND	ConnectDongbuAPI( BOOL bConnect );
	void    DisconnectedDongbuAPI() ;
	void    OnRealTimeData(PVOID szData, int nLen) ;	
	void	RequestRT(UINT nDlgItemId, CString szTitle, CString szRId, CString szParam);
// Dialog Data
	//{{AFX_DATA(CDongbuAPIClientDlg)
	enum { IDD = IDD_DONGBUAPICLIENT_DIALOG };
		CComboBox	m_cmbAccount;
		CListBox	m_lstMsg;	

		BOOL		m_chkShowLoginDlg;
		BOOL		m_chkMultiConn;

		CString		m_strID;
		CString		m_strPwd;
		CString		m_strCertPwd;	
		CString		m_strNick;
		CString		m_strOptCodes;
		CString		m_strFutCodes;

	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDongbuAPIClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDongbuAPIClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	afx_msg void OnBtnTrTest();
	afx_msg void OnConnectDongbuAPI();
	afx_msg void OnDisconnectDongbuAPI();
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	afx_msg void OnBtnOrder();
	afx_msg void OnBtnJango();	
	afx_msg void OnBtnChegyul();
	afx_msg void OnBtnEval();
	afx_msg void OnBtnFee();
	afx_msg void OnBtnAcclist();
	afx_msg void OnClearList();	
	afx_msg void OnBtnDeposit();
	afx_msg void OnBtnAbleqty();
	afx_msg void OnBtnSc0();
	afx_msg void OnBtnSh0();
	afx_msg void OnBtnOc0();
	afx_msg void OnBtnOh0();
	afx_msg void OnBtnXf2();
	afx_msg void OnBtnXf3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DONGBUAPICLIENTDLG_H__5BC797B4_BF25_46DA_A6A1_9CD41F62EF0F__INCLUDED_)

#pragma once


// CExRealtimeDataDlg ��ȭ �����Դϴ�.

class CExLoginDlg : public CDialog
{
	DECLARE_DYNAMIC(CExLoginDlg)

public:
	CExLoginDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CExLoginDlg();

// ��ȭ ���� �������Դϴ�.
	
	//{{AFX_DATA(CExLoginDlg)
	enum { IDD = IDD_DLG_LOGIN };
	CListBox	m_lstMsg;
	BOOL		m_chkShowLoginDlg;
	BOOL		m_chkMultiConn;
	CString		m_strID;
	CString		m_strPwd;
	CString		m_strCertPwd;	
	CString		m_strNick;	
	//}}AFX_DATA


	BOOL	KillProcess(CString szExe) ;
	HWND	ShellExecuteDRCM( CString szWinName, CString szFileName, CString szUserName,CString szRoot);

	HWND	FindDRCM(CString szUserName);		
	BOOL	GetDRCMInfo(CString &szRoot, CString &szExe, CString &szWinName );	
	
	HWND	ConnectDongbuAPI( BOOL bConnect );	
	void   EnableControls(BOOL bConnected) ;

protected:
	
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:	
	afx_msg void OnBnClickedBtnLogin();
	afx_msg void OnBnClickedBtnLogout();
	
	virtual BOOL OnInitDialog();
	
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
};

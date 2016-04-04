#pragma once


// CExRealtimeDataDlg 대화 상자입니다.

class CExLoginDlg : public CDialog
{
	DECLARE_DYNAMIC(CExLoginDlg)

public:
	CExLoginDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CExLoginDlg();

// 대화 상자 데이터입니다.
	
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
	
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:	
	afx_msg void OnBnClickedBtnLogin();
	afx_msg void OnBnClickedBtnLogout();
	
	virtual BOOL OnInitDialog();
	
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
};

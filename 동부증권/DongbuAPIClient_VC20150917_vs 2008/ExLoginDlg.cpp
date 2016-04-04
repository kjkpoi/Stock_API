// ExLoginDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "DongbuAPIClient_VC.h"
#include "ExLoginDlg.h"
#include "MainFrm.h"

#include <Tlhelp32.h> 

// CExLoginDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CExLoginDlg, CDialog)

CExLoginDlg::CExLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExLoginDlg)	
	m_chkShowLoginDlg = FALSE;
	m_chkMultiConn = FALSE;
	m_strID =  theApp.g_strID;	
	m_strPwd = theApp.g_strPwd ;
	m_strCertPwd = theApp.g_strCertPwd	;
	m_strNick = _T("dongbutest");	
	//}}AFX_DATA_INIT
}

CExLoginDlg::~CExLoginDlg()
{
}

void CExLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExLoginDlg)	
	DDX_Control(pDX, IDC_LIST, m_lstMsg);
	DDX_Check(pDX, IDC_CHK_SHOWLOGIN, m_chkShowLoginDlg);
	DDX_Check(pDX, IDC_CHK_MULTICONN, m_chkMultiConn);
	DDX_Text(pDX, IDC_EDT_ID,		m_strID);
	DDX_Text(pDX, IDC_EDT_PWD,		m_strPwd);
	DDX_Text(pDX, IDC_EDT_CERT_PWD, m_strCertPwd);
	DDX_Text(pDX, IDC_EDT_NICK,		m_strNick);		
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExLoginDlg, CDialog)		

	ON_BN_CLICKED(IDC_BTN_LOGIN, &CExLoginDlg::OnBnClickedBtnLogin)
	ON_BN_CLICKED(IDC_BTN_LOGOUT, &CExLoginDlg::OnBnClickedBtnLogout)

	ON_WM_WINDOWPOSCHANGING()
END_MESSAGE_MAP()




BOOL CExLoginDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	EnableControls(theApp.g_bConnected);

	OnBnClickedBtnLogin();
	return TRUE;  
}

//=======================================================================================
// FUNCTION	:  로그인
//=======================================================================================
void CExLoginDlg::OnBnClickedBtnLogin()
{
	UpdateData(TRUE) ;
	m_lstMsg.ResetContent() ;

	HWND hSocket = NULL ;

	CString szUserName ;

	if ( m_strNick.IsEmpty() )
		szUserName = m_strID ;
	else
		szUserName = m_strNick ;

	theApp.g_hDongbuDRCM  = FindDRCM(szUserName);

	if ( !theApp.g_hDongbuDRCM  ) 		
		return ;

	m_lstMsg.InsertString(0, "동부 DRCM을 찾았습니다" ) ;
	int nRet =(int) ConnectDongbuAPI(TRUE);
	switch(nRet) 
	{
	case DRCM_MSG_LOGINFAIL:		
		m_lstMsg.InsertString(0,  "로그인 실패" ) ;
		break;
	case DRCM_MSG_SOCKETFAIL:
		m_lstMsg.InsertString(0,  "서버 접속 실패" ) ;
		break;

	case DRCM_MSG_RESTART:
		m_lstMsg.InsertString(0,  "재접속하십시오.." ) ;
		//ConnectDRCM(FALSE) ;
		return;

	default:
		hSocket =(HWND) nRet ; 
	}

	if ( hSocket )
	{		
		m_lstMsg.InsertString(0,  "로그인 성공" ) ;		
		EnableControls(TRUE);	

		theApp.g_szId = m_strID ;	
		theApp.g_bConnected = TRUE ;
		EndDialog(IDOK);

	}
	else
	{
		m_lstMsg.InsertString(0, "로그인 실패" ) ;
	}

	UpdateData(FALSE);
}


//=======================================================================================
// FUNCTION	:  로그 아웃
//=======================================================================================
void CExLoginDlg::OnBnClickedBtnLogout()
{
	ConnectDongbuAPI(FALSE);
	EndDialog(IDOK) ;
}


//=======================================================================================
// FUNCTION : DRCM에 접속
// RETURN   : DRDM의 SOCKET HANDLE
//=======================================================================================
HWND CExLoginDlg::ConnectDongbuAPI ( BOOL bConnect )
{	
	UpdateData (TRUE) ;

	ST_DRCM_USER stUserData ;
	memset( &stUserData, 0x00, sizeof(ST_DRCM_USER) );
	
	sprintf_s(stUserData.szUserId,"%s",  m_strID) ;
	sprintf_s(stUserData.szPwd,"%s",	   m_strPwd) ;
	sprintf_s(stUserData.szCertPwd,"%s", m_strCertPwd) ;

	stUserData.bShowLoginDlg =  m_chkShowLoginDlg ;	
	stUserData.hClientWnd = AfxGetMainWnd()->GetSafeHwnd() ; //연결통보를 받고자하는 윈도우 핸들
	
	//send data
	COPYDATASTRUCT cds;
	cds.dwData = (DWORD)(bConnect)?DRCM_CONNECT:DRCM_DISCONNECT;				
	cds.cbData = sizeof(ST_DRCM_USER);		
	cds.lpData = &stUserData;	
	
	return (HWND) ::SendMessage(theApp.g_hDongbuDRCM , WM_COPYDATA, cds.cbData, (LPARAM)&cds);	

}

//=======================================================================================
// FUNCTION	: 동부DRCM의 정보를 레지스트리에서 가져옴
// RETURN	: 
//=======================================================================================
BOOL CExLoginDlg::GetDRCMInfo(CString &szRoot, CString &szExe, CString &szWinName )
{	
	CRegistry registry;
	registry.SetRootKey(HKEY_CURRENT_USER);
	registry.SetKey("Software\\Dongbu Securities\\DongbuDRCM\\PATH", FALSE);
	szRoot = registry.ReadString("Root", "");
	szExe = registry.ReadString("Exe", "");
	szWinName = registry.ReadString("WinName", "");

	if ( szRoot.IsEmpty() || szExe.IsEmpty() || szWinName.IsEmpty())
		return FALSE ;
	else
		return TRUE ;
}



BOOL CExLoginDlg::KillProcess(CString szExe)
{		
	char *szProcess = (LPSTR)(LPCTSTR)szExe ;

	if(szProcess==NULL)
		return FALSE;
	HANDLE   hProcessSnap = NULL; 

	BOOL   bRet      = FALSE; 
	PROCESSENTRY32 pe32      = {0}; 

	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);  
	if (hProcessSnap == INVALID_HANDLE_VALUE) 
		return FALSE; 
	pe32.dwSize = sizeof(PROCESSENTRY32); 
	if (Process32First(hProcessSnap, &pe32)) 
	{ 
		BOOL          bGotModule = FALSE; 
		MODULEENTRY32 me32       = {0};  
		do 
		{ 
			if(::lstrcmpi(pe32.szExeFile, szProcess)==0)
			{
				HANDLE hProcess = NULL;
				DWORD Code = 0;

				hProcess = OpenProcess(PROCESS_ALL_ACCESS,FALSE, pe32.th32ProcessID); 
				GetExitCodeProcess(hProcess, &Code);

				if(TerminateProcess(hProcess, Code))
				{
					WaitForSingleObject(hProcess, 1000);
					bRet = TRUE;
				} 

				CloseHandle(hProcess);
				//	break;
			}
		} 
		while (Process32Next(hProcessSnap, &pe32)); 
	}    
	CloseHandle (hProcessSnap); 

	return bRet;
}

HWND CExLoginDlg::ShellExecuteDRCM( CString szWinName, CString szFileName, CString szUserName,CString szRoot)
{
	HWND hDrcmHandle = NULL;
	HANDLE hSyncEvent = NULL;

	ShellExecute(NULL, "open", szFileName, szUserName, szRoot, SW_SHOWNORMAL);								

	while(1)
	{
		::WaitForSingleObject(hSyncEvent, INFINITE);
		DWORD dwWait = 0;
		do
		{					
			dwWait = ::WaitForSingleObject(hSyncEvent, 3000);
		}
		while(dwWait == WAIT_OBJECT_0);
		// timed out
		hDrcmHandle = ::FindWindow(NULL, szWinName);
		if ( hDrcmHandle != NULL )			
			break;			
	}
	return hDrcmHandle ;

}

//=======================================================================================
// FUNCTION	:  설치되어있는 drcm을 실행하고 핸들값을 가져옴
//=======================================================================================
HWND CExLoginDlg::FindDRCM(CString szUserName)
{			
	BOOL bAlreayRun = FALSE;
	
	CString szRoot, szWinName, szFileName, szTmpWinName ;

	GetDRCMInfo (szRoot, szFileName, szWinName);
	szTmpWinName.Format( "%s[%s]", szWinName, szUserName ) ;

	theApp.g_strRoot = szRoot;

	szRoot = szRoot + "\\Bin";

	HANDLE hSyncEvent=NULL;
	HWND hDrcmHandle = ::FindWindow(NULL, szTmpWinName);	

	if ( (m_chkMultiConn==FALSE) && (hDrcmHandle !=NULL))  
	{
		bAlreayRun = TRUE ;

		CString strMsg ;
		strMsg = "같은ID 사용자가 동부 API에 로그인되어 있습니다." ;
		strMsg += "\n 현재 실행중인 동부API 프로세스를 강제종료하시겠습니까?" ;	

		int nRet = MessageBox (strMsg, "동부DRCM", MB_ICONQUESTION|MB_YESNO) ;
		if ( nRet == IDYES)
		{
			KillProcess(szFileName) ;		
			hDrcmHandle = ShellExecuteDRCM(szWinName, szFileName, szUserName, szRoot);
		}		
		else 
		{
			CString strMsg ;					
			strMsg += "\n 멀티 커넥션 설정 위반으로 동부API를 종료합니다! " ;
			MessageBox (strMsg, "동부DRCM", MB_ICONINFORMATION|MB_OK);
			return NULL;
		}
	}		
	else 
		hDrcmHandle = ShellExecuteDRCM(szWinName, szFileName, szUserName, szRoot);

	if ( !hDrcmHandle )	
		MessageBox ( "동부 API을 찾을 수 없습니다" , "동부 API", MB_ICONINFORMATION|MB_OK) ;

	return hDrcmHandle;
}


//=======================================================================================
// FUNCTION	: UpdateControls
//=======================================================================================
void CExLoginDlg::EnableControls(BOOL bConnected) 
{	
	BOOL bEnable = bConnected ;

	GetDlgItem(IDC_BTN_LOGIN)->EnableWindow(!bEnable) ;
	GetDlgItem(IDC_BTN_LOGOUT)->EnableWindow(bEnable) ;			
}

void CExLoginDlg::OnWindowPosChanging(WINDOWPOS* lpwndpos)
{
	CDialog::OnWindowPosChanging(lpwndpos);

	//// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	//lpwndpos->flags &= ~SWP_SHOWWINDOW ;
}

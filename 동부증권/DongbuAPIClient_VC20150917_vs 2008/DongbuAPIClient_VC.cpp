
// DongbuAPIClient_VC.cpp : 응용 프로그램에 대한 클래스 동작을 정의합니다.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "DongbuAPIClient_VC.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "DongbuAPIClient_VCDoc.h"
#include "DongbuAPIClient_VCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDongbuAPIClient_VCApp

BEGIN_MESSAGE_MAP(CDongbuAPIClient_VCApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CDongbuAPIClient_VCApp::OnAppAbout)
	// 표준 파일을 기초로 하는 문서 명령입니다.
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// 표준 인쇄 설정 명령입니다.
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
	

END_MESSAGE_MAP()


// CDongbuAPIClient_VCApp 생성

CDongbuAPIClient_VCApp::CDongbuAPIClient_VCApp()
{

	COleDateTime tToday = COleDateTime::GetCurrentTime();
	CString strDate = tToday.Format(_T("%Y%m%d"));
	m_bHiColorIcons = TRUE;


	//DRCM 연결상태 
	g_hDongbuDRCM = NULL ;
	g_bConnected  = FALSE ;


	//자주쓰는 계좌등의 정보를 한꺼번에 넣어둠..  위해
	g_strID = _T("kjkpoi");
	g_strPwd = _T("144882a!");
	g_strCertPwd = _T("951235789a!");	
	g_strAccount = _T("10155547001");	
	g_strAcctPwd = _T("9512");		
	g_strJongmok = _T("000030");	
	g_strPrice = _T("");	
	
	g_strDate = _T(strDate) ;
	g_szMyIP = "192.1.1.1"; //각각 pc의 ClientIP

	g_strRoot = "C:\\동부증권\\동부 DRCM";
	
}


BOOL CDongbuAPIClient_VCApp::SendToServerEx(CString strTrCode,BYTE * lpData,long nSize, HWND hSender)
{
	COPYDATASTRUCT cds;
	cds.dwData = (DWORD)DRCM_SENDDATA;			
	cds.cbData = (DWORD)nSize;		
	cds.lpData = lpData;

	BOOL bRet = ::SendMessage(g_hDongbuDRCM, WM_COPYDATA, (WPARAM)hSender, (LPARAM)&cds);
	
	if ( bRet != TRUE )
	{
		AfxMessageBox("DRCM SERVER에 요청 실패!") ;
	}

	return bRet ;
}

//=======================================================================================
// FUNCTION : DRCM에TR 처리 요청
//=======================================================================================
BOOL CDongbuAPIClient_VCApp::SendToServerEx(int nWorkType, CString szTrCode, CString szData, HWND hSender)
{	
	if (szData.IsEmpty())
		return FALSE ;

	CString szSendData ;

	switch ( nWorkType )
	{
	case DRCM_SENDDATA :
		szSendData.Format("%-5s%s", szTrCode, szData );
		break ;
	case DRCM_ADVICE :
	case DRCM_UNADVICE :
		szSendData.Format("%-3s%s", szTrCode, szData );
		break ;
	}

	int nLen = szSendData.GetLength() ;

	COPYDATASTRUCT cds;
	cds.dwData = (DWORD)nWorkType;			
	cds.cbData = (DWORD)nLen;
	cds.lpData = szSendData.GetBuffer(0);

	BOOL bRet = ::SendMessage(g_hDongbuDRCM, WM_COPYDATA, (WPARAM)hSender, (LPARAM)&cds);

	szData.ReleaseBuffer() ;

	if ( bRet != TRUE )
	{
		AfxMessageBox("DRCM SERVER에 요청 실패!") ;
	}

	return bRet ;
}


int CDongbuAPIClient_VCApp::gatoi(LPSTR lpstrSrc, UINT uSize)
{
	char tmp[20];
	memcpy(tmp, lpstrSrc, uSize);
	tmp[uSize] = 0;
	int nRetValue = atoi(tmp);
	return nRetValue;
}

double CDongbuAPIClient_VCApp::gatof(LPSTR lpstrSrc, UINT uSize)
{
	char tmp[20];
	memcpy(tmp, lpstrSrc, uSize);
	tmp[uSize] = 0;
	double nRetValue = atof(tmp);
	return nRetValue;
}

CString CDongbuAPIClient_VCApp::gatosz(LPSTR lpstrSrc, UINT uSize)
{
	CString szRet ;
	char tmp[1024];
	memcpy(tmp, lpstrSrc, uSize);
	tmp[uSize] = 0;

	szRet = tmp ;
	szRet.TrimLeft(); szRet.TrimRight();

	return szRet ;

}


// 유일한 CDongbuAPIClient_VCApp 개체입니다.

CDongbuAPIClient_VCApp theApp;


// CDongbuAPIClient_VCApp 초기화

BOOL CDongbuAPIClient_VCApp::InitInstance()
{
	// 응용 프로그램 매니페스트가 ComCtl32.dll 버전 6 이상을 사용하여 비주얼 스타일을
	// 사용하도록 지정하는 경우, Windows XP 상에서 반드시 InitCommonControlsEx()가 필요합니다. 
	// InitCommonControlsEx()를 사용하지 않으면 창을 만들 수 없습니다.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 응용 프로그램에서 사용할 모든 공용 컨트롤 클래스를 포함하도록
	// 이 항목을 설정하십시오.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	// OLE 라이브러리를 초기화합니다.
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// 표준 초기화
	// 이들 기능을 사용하지 않고 최종 실행 파일의 크기를 줄이려면
	// 아래에서 필요 없는 특정 초기화
	// 루틴을 제거해야 합니다.
	// 해당 설정이 저장된 레지스트리 키를 변경하십시오.
	// TODO: 이 문자열을 회사 또는 조직의 이름과 같은
	// 적절한 내용으로 수정해야 합니다.
	SetRegistryKey(_T("로컬 응용 프로그램 마법사에서 생성된 응용 프로그램"));
	LoadStdProfileSettings(4);  // MRU를 포함하여 표준 INI 파일 옵션을 로드합니다.

	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	//// 응용 프로그램의 문서 템플릿을 등록합니다. 문서 템플릿은
	////  문서, 프레임 창 및 뷰 사이의 연결 역할을 합니다.
	//CMultiDocTemplate* pDocTemplate;
	//pDocTemplate = new CMultiDocTemplate(IDR_DongbuAPIClientTYPE,
	//	RUNTIME_CLASS(CDongbuAPIClient_VCDoc),
	//	RUNTIME_CLASS(CChildFrame), // 사용자 지정 MDI 자식 프레임입니다.
	//	RUNTIME_CLASS(CDongbuAPIClient_VCView));
	//if (!pDocTemplate)
	//	return FALSE;
	//AddDocTemplate(pDocTemplate);

	// 주 MDI 프레임 창을 만듭니다.
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;
	// 접미사가 있을 경우에만 DragAcceptFiles를 호출합니다.
	//  MDI 응용 프로그램에서는 m_pMainWnd를 설정한 후 바로 이러한 호출이 발생해야 합니다.


	// 표준 셸 명령, DDE, 파일 열기에 대한 명령줄을 구문 분석합니다.
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);


	// 명령줄에 지정된 명령을 디스패치합니다.
	// 응용 프로그램이 /RegServer, /Register, /Unregserver 또는 /Unregister로 시작된 경우 FALSE를 반환합니다.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// 주 창이 초기화되었으므로 이를 표시하고 업데이트합니다.
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}



// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// 대화 상자를 실행하기 위한 응용 프로그램 명령입니다.
void CDongbuAPIClient_VCApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CDongbuAPIClient_VCApp 사용자 지정 로드/저장 메서드

void CDongbuAPIClient_VCApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	//GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
}

void CDongbuAPIClient_VCApp::LoadCustomState()
{
}

void CDongbuAPIClient_VCApp::SaveCustomState()
{
}


// CDongbuAPIClient_VCApp 메시지 처리기


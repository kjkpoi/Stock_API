
// DongbuAPIClient_VC.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
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
	// ǥ�� ������ ���ʷ� �ϴ� ���� ����Դϴ�.
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// ǥ�� �μ� ���� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
	

END_MESSAGE_MAP()


// CDongbuAPIClient_VCApp ����

CDongbuAPIClient_VCApp::CDongbuAPIClient_VCApp()
{

	COleDateTime tToday = COleDateTime::GetCurrentTime();
	CString strDate = tToday.Format(_T("%Y%m%d"));
	m_bHiColorIcons = TRUE;


	//DRCM ������� 
	g_hDongbuDRCM = NULL ;
	g_bConnected  = FALSE ;


	//���־��� ���µ��� ������ �Ѳ����� �־��..  ����
	g_strID = _T("kjkpoi");
	g_strPwd = _T("144882a!");
	g_strCertPwd = _T("951235789a!");	
	g_strAccount = _T("10155547001");	
	g_strAcctPwd = _T("9512");		
	g_strJongmok = _T("000030");	
	g_strPrice = _T("");	
	
	g_strDate = _T(strDate) ;
	g_szMyIP = "192.1.1.1"; //���� pc�� ClientIP

	g_strRoot = "C:\\��������\\���� DRCM";
	
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
		AfxMessageBox("DRCM SERVER�� ��û ����!") ;
	}

	return bRet ;
}

//=======================================================================================
// FUNCTION : DRCM��TR ó�� ��û
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
		AfxMessageBox("DRCM SERVER�� ��û ����!") ;
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


// ������ CDongbuAPIClient_VCApp ��ü�Դϴ�.

CDongbuAPIClient_VCApp theApp;


// CDongbuAPIClient_VCApp �ʱ�ȭ

BOOL CDongbuAPIClient_VCApp::InitInstance()
{
	// ���� ���α׷� �Ŵ��佺Ʈ�� ComCtl32.dll ���� 6 �̻��� ����Ͽ� ���־� ��Ÿ����
	// ����ϵ��� �����ϴ� ���, Windows XP �󿡼� �ݵ�� InitCommonControlsEx()�� �ʿ��մϴ�. 
	// InitCommonControlsEx()�� ������� ������ â�� ���� �� �����ϴ�.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ���� ���α׷����� ����� ��� ���� ��Ʈ�� Ŭ������ �����ϵ���
	// �� �׸��� �����Ͻʽÿ�.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	// OLE ���̺귯���� �ʱ�ȭ�մϴ�.
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// ǥ�� �ʱ�ȭ
	// �̵� ����� ������� �ʰ� ���� ���� ������ ũ�⸦ ���̷���
	// �Ʒ����� �ʿ� ���� Ư�� �ʱ�ȭ
	// ��ƾ�� �����ؾ� �մϴ�.
	// �ش� ������ ����� ������Ʈ�� Ű�� �����Ͻʽÿ�.
	// TODO: �� ���ڿ��� ȸ�� �Ǵ� ������ �̸��� ����
	// ������ �������� �����ؾ� �մϴ�.
	SetRegistryKey(_T("���� ���� ���α׷� �����翡�� ������ ���� ���α׷�"));
	LoadStdProfileSettings(4);  // MRU�� �����Ͽ� ǥ�� INI ���� �ɼ��� �ε��մϴ�.

	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	//// ���� ���α׷��� ���� ���ø��� ����մϴ�. ���� ���ø���
	////  ����, ������ â �� �� ������ ���� ������ �մϴ�.
	//CMultiDocTemplate* pDocTemplate;
	//pDocTemplate = new CMultiDocTemplate(IDR_DongbuAPIClientTYPE,
	//	RUNTIME_CLASS(CDongbuAPIClient_VCDoc),
	//	RUNTIME_CLASS(CChildFrame), // ����� ���� MDI �ڽ� �������Դϴ�.
	//	RUNTIME_CLASS(CDongbuAPIClient_VCView));
	//if (!pDocTemplate)
	//	return FALSE;
	//AddDocTemplate(pDocTemplate);

	// �� MDI ������ â�� ����ϴ�.
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;
	// ���̻簡 ���� ��쿡�� DragAcceptFiles�� ȣ���մϴ�.
	//  MDI ���� ���α׷������� m_pMainWnd�� ������ �� �ٷ� �̷��� ȣ���� �߻��ؾ� �մϴ�.


	// ǥ�� �� ���, DDE, ���� ���⿡ ���� ������� ���� �м��մϴ�.
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);


	// ����ٿ� ������ ����� ����ġ�մϴ�.
	// ���� ���α׷��� /RegServer, /Register, /Unregserver �Ǵ� /Unregister�� ���۵� ��� FALSE�� ��ȯ�մϴ�.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// �� â�� �ʱ�ȭ�Ǿ����Ƿ� �̸� ǥ���ϰ� ������Ʈ�մϴ�.
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}



// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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

// ��ȭ ���ڸ� �����ϱ� ���� ���� ���α׷� ����Դϴ�.
void CDongbuAPIClient_VCApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CDongbuAPIClient_VCApp ����� ���� �ε�/���� �޼���

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


// CDongbuAPIClient_VCApp �޽��� ó����


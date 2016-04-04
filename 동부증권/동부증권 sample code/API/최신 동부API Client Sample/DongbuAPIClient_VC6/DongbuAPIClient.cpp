// DongbuAPIClient.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "DongbuAPIClient.h"
#include "DongbuAPIClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDongbuAPIClientApp

BEGIN_MESSAGE_MAP(CDongbuAPIClientApp, CWinApp)
	//{{AFX_MSG_MAP(CDongbuAPIClientApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDongbuAPIClientApp construction

CDongbuAPIClientApp::CDongbuAPIClientApp()
{
	g_hDongbuDRCM = NULL ;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CDongbuAPIClientApp object

CDongbuAPIClientApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CDongbuAPIClientApp initialization

BOOL CDongbuAPIClientApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CDongbuAPIClientDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}


//=======================================================================================
// FUNCTION : DRCM에TR 처리 요청
//=======================================================================================
BOOL CDongbuAPIClientApp::SendToServerEx(int nWorkType, CString szTrCode, CString szData, HWND hSender)
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

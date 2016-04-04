// DongbuAPIClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DongbuAPIClient.h"
#include "DongbuAPIClientDlg.h"


#include "_DrdsIO/DrdsSC0.h"
#include "_DrdsIO/DrdsOC0.h"
#include "_DrdsIO/DrdsSH0.h"
#include "_DrdsIO/DrdsOH0.h"
#include "_DrdsIO/DrdsXF2.h"
#include "_DrdsIO/DrdsXF3.h"

#include "ExInqueryDlg.h"
#include "ExOrderDlg.h"
#include "ExOptDepositDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDongbuAPIClientDlg dialog

CDongbuAPIClientDlg::CDongbuAPIClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDongbuAPIClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDongbuAPIClientDlg)	
	m_strID = _T("");
	m_strPwd = _T("");
	m_strCertPwd = _T("");	
	m_chkShowLoginDlg = TRUE;
	m_chkMultiConn = TRUE;
	m_strNick = _T("dongbutest");
	
	m_strFutCodes = _T("101G3000,101G6000");
	m_strOptCodes = _T("201G1235,301G1227");
	//}}AFX_DATA_INIT
	
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDongbuAPIClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDongbuAPIClientDlg)
	DDX_Control(pDX, IDC_CMB_ACCOUNT, m_cmbAccount);
	DDX_Control(pDX, IDC_LIST, m_lstMsg);
	DDX_Text(pDX, IDC_EDT_ID,		m_strID);
	DDX_Text(pDX, IDC_EDT_PWD,		m_strPwd);
	DDX_Text(pDX, IDC_EDT_CERT_PWD, m_strCertPwd);
	DDX_Text(pDX, IDC_EDT_NICK,		m_strNick);	
	DDX_Text(pDX, IDC_EDT_FUTCODES, m_strFutCodes);
	DDX_Text(pDX, IDC_EDT_OPTCODES, m_strOptCodes);

	DDX_Check(pDX, IDC_CHK_SHOWLOGIN, m_chkShowLoginDlg);
	DDX_Check(pDX, IDC_CHK_MULTICONN, m_chkMultiConn);
	
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDongbuAPIClientDlg, CDialog)
	//{{AFX_MSG_MAP(CDongbuAPIClientDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BTN_RUN,		OnConnectDongbuAPI)
	ON_BN_CLICKED(IDC_BTN_STOP,		OnDisconnectDongbuAPI)
	ON_WM_COPYDATA()
	ON_BN_CLICKED(IDC_BTN_ORDER,	OnBtnOrder)
	ON_BN_CLICKED(IDC_BTN_JANGO,	OnBtnJango)	
	ON_BN_CLICKED(IDC_BTN_CHEGYUL,	OnBtnChegyul)
	ON_BN_CLICKED(IDC_BTN_EVAL,		OnBtnEval)
	ON_BN_CLICKED(IDC_BTN_FEE,		OnBtnFee)
	ON_BN_CLICKED(IDC_BTN_ACCLIST,	OnBtnAcclist)
	ON_BN_CLICKED(IDC_BTN_CLEARLIST,OnClearList)	
	ON_BN_CLICKED(IDC_BTN_DEPOSIT,	OnBtnDeposit)
	ON_BN_CLICKED(IDC_BTN_ABLEQTY,	OnBtnAbleqty)	
	ON_BN_CLICKED(IDC_BTN_SC0, OnBtnSc0)
	ON_BN_CLICKED(IDC_BTN_SH0, OnBtnSh0)
	ON_BN_CLICKED(IDC_BTN_OC0, OnBtnOc0)
	ON_BN_CLICKED(IDC_BTN_OH0, OnBtnOh0)
	ON_BN_CLICKED(IDC_BTN_XF2, OnBtnXf2)
	ON_BN_CLICKED(IDC_BTN_XF3, OnBtnXf3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDongbuAPIClientDlg message handlers

BOOL CDongbuAPIClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	EnableControls(FALSE) ;
			
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDongbuAPIClientDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CDongbuAPIClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDongbuAPIClientDlg::OnClose() 
{
	ConnectDongbuAPI(FALSE);

	CDialog::OnClose();
}

//=======================================================================================
// FUNCTION	: 동부DRCM 접속 
//=======================================================================================
void CDongbuAPIClientDlg::OnConnectDongbuAPI() 
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

		SetDlgItemText(IDC_EDT_ID2, m_strID);
		EnableControls(TRUE);	

		GetClientIp();		
	}
	else
	{
		m_lstMsg.InsertString(0, "로그인 실패" ) ;
	}

	UpdateData(FALSE);
		
}

//=======================================================================================
// FUNCTION	: 동부DRCM 접속 해제
//=======================================================================================
void CDongbuAPIClientDlg::OnDisconnectDongbuAPI() 
{		
	ConnectDongbuAPI(FALSE);		
}

//=======================================================================================
// FUNCTION	: 동부DRCM 접속 해제될때 화면 처리
//=======================================================================================
void CDongbuAPIClientDlg::DisconnectedDongbuAPI() 
{
	if ( theApp.g_hDongbuDRCM )
	{		
		theApp.g_hDongbuDRCM  = NULL ;

		m_cmbAccount.ResetContent();
		EnableControls(FALSE) ;
		

		m_lstMsg.InsertString(0, "동부DRCM 접속 해제" ) ;
	}	
}

//=======================================================================================
// FUNCTION	: UpdateControls
//=======================================================================================
void CDongbuAPIClientDlg::GetClientIp() 
{	
	COPYDATASTRUCT cds;
	cds.dwData = (DWORD)DRCM_CLIENT_IP;			
	cds.cbData = (DWORD)0;			
	::SendMessage(theApp.g_hDongbuDRCM, WM_COPYDATA, (WPARAM)m_hWnd, (LPARAM)&cds);
}

//=======================================================================================
// FUNCTION	: UpdateControls
//=======================================================================================
void CDongbuAPIClientDlg::EnableControls(BOOL bConnected) 
{	
	BOOL bEnable = bConnected ;

	GetDlgItem(IDC_BTN_RUN)->EnableWindow(!bEnable) ;
	GetDlgItem(IDC_BTN_STOP)->EnableWindow(bEnable) ;	
	GetDlgItem(IDC_BTN_ORDER)->EnableWindow(bEnable) ;
	GetDlgItem(IDC_BTN_JANGO)->EnableWindow(bEnable) ;
	
	GetDlgItem(IDC_BTN_CHEGYUL)->EnableWindow(bEnable) ;

	GetDlgItem(IDC_BTN_EVAL)->EnableWindow(bEnable) ;
	GetDlgItem(IDC_BTN_FEE)->EnableWindow(bEnable) ;

	GetDlgItem(IDC_BTN_ACCLIST)->EnableWindow(bEnable) ;
	GetDlgItem(IDC_BTN_ABLEQTY)->EnableWindow(bEnable) ;
	GetDlgItem(IDC_BTN_DEPOSIT)->EnableWindow(bEnable) ;

	GetDlgItem(IDC_BTN_SC0)->EnableWindow(bEnable) ;
	GetDlgItem(IDC_BTN_SH0)->EnableWindow(bEnable) ;
	GetDlgItem(IDC_BTN_OC0)->EnableWindow(bEnable) ;
	GetDlgItem(IDC_BTN_OH0)->EnableWindow(bEnable) ;
	GetDlgItem(IDC_BTN_XF2)->EnableWindow(bEnable) ;
	GetDlgItem(IDC_BTN_XF3)->EnableWindow(bEnable) ;

	if ( !bEnable )
	{
		CButton *pButton = (CButton *)GetDlgItem(IDC_BTN_XF2) ;
		pButton->SetCheck(FALSE);

		pButton = (CButton *)GetDlgItem(IDC_BTN_XF3) ;
		pButton->SetCheck(FALSE);
		pButton = (CButton *)GetDlgItem(IDC_BTN_SC0) ;
		pButton->SetCheck(FALSE);
		pButton = (CButton *)GetDlgItem(IDC_BTN_SH0) ;
		pButton->SetCheck(FALSE);
		pButton = (CButton *)GetDlgItem(IDC_BTN_OC0) ;
		pButton->SetCheck(FALSE);
		pButton = (CButton *)GetDlgItem(IDC_BTN_OH0) ;
		pButton->SetCheck(FALSE);
	}

	UpdateData ( FALSE ) ;
}


//=======================================================================================
// FUNCTION	: 동부DRCM의 정보를 레지스트리에서 가져옴
// RETURN	: 
//=======================================================================================
BOOL CDongbuAPIClientDlg::GetDRCMInfo(CString &szRoot, CString &szExe, CString &szWinName )
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


HWND CDongbuAPIClientDlg::FindDRCM( CString szUserName)
{			
	BOOL bAlreayRun  ;
	bAlreayRun = FALSE;

	CString szRoot, szWinName, szFileName, szTmpWinName ;
	
	GetDRCMInfo (szRoot, szFileName, szWinName);
	szTmpWinName.Format( "%s[%s]", szWinName, szUserName ) ;

	szRoot = szRoot + "\\Bin";
	
	HANDLE hSyncEvent=NULL;
	HWND hDrcmHandle = ::FindWindow(NULL, szTmpWinName);	
	if ( hDrcmHandle == NULL )
	{
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
	}
	else
	{
		if ( m_chkMultiConn == FALSE )
		{
			bAlreayRun = TRUE ;
			hDrcmHandle = NULL ;	
		}
		else
		{
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
		}
	}
	
	if ( hDrcmHandle == NULL )
	{		
		if ( bAlreayRun )
		{
			CString strMsg ;
			strMsg = "이미 같은 ID 가 동부 DRCM에 로그되어 있습니다." ;
			strMsg += "\n 프로그램을 종료합니다! " ;
			MessageBox (strMsg, "동부DRCM", MB_ICONINFORMATION|MB_OK) ;	
		}
		else		
			MessageBox ( "동부 DRCM을 찾을 수 없습니다" , "동부DRCM", MB_ICONINFORMATION|MB_OK) ;
	}

	return hDrcmHandle;
}

//=======================================================================================
// FUNCTION : DRCM에 접속
// RETURN   : DRDM의 SOCKET HANDLE //<=쓸일은 별루 없지만
//=======================================================================================
HWND CDongbuAPIClientDlg::ConnectDongbuAPI ( BOOL bConnect )
{	
	UpdateData (TRUE) ;

	ST_DRCM_USER stUserData ;
	memset( &stUserData, 0x00, sizeof(ST_DRCM_USER) );
	
	sprintf(stUserData.szUserId,"%s",  m_strID) ;
	sprintf(stUserData.szPwd,"%s",	   m_strPwd) ;
	sprintf(stUserData.szCertPwd,"%s", m_strCertPwd) ;
	
	stUserData.bShowLoginDlg =  m_chkShowLoginDlg ;	
	stUserData.hClientWnd = m_hWnd ;

	//send data
	COPYDATASTRUCT cds;
	cds.dwData = (DWORD)(bConnect)?DRCM_CONNECT:DRCM_DISCONNECT;				
	cds.cbData = sizeof(ST_DRCM_USER);		
	cds.lpData = &stUserData;	
	return (HWND)::SendMessage(theApp.g_hDongbuDRCM , WM_COPYDATA, cds.cbData, (LPARAM)&cds);		
}

//=======================================================================================
// FUNCTION : DRCM에서 보내온 WM_COPYDATA 메시지 처리
// RETURN   : 
//=======================================================================================
BOOL CDongbuAPIClientDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
{
	COPYDATASTRUCT* pCDS = pCopyDataStruct ;

	int nDataType = (int)pCDS->dwData ;

	switch (nDataType)
	{
		case DRCM_DISCONNECT : //DRCM 이 종료될때 오는 메시지
			DisconnectedDongbuAPI() ;
			break;

		case DRCM_CLIENT_IP :  //client ip
			{
				CString szIp ;
				szIp.Format("%*.*s", pCDS->cbData, pCDS->cbData, pCDS->lpData );
				theApp.g_szMyIP = SetIp(szIp) ;
			}
			
			OnBtnAcclist();
			break ;

		case DRCM_F_ACCLIST :  //get future account list			
			GetFutureAccList((LPSTR)pCDS->lpData, (int)pCDS->cbData);
			break ;
	
		case DRCM_DRDS_DATA :  //실시간 데이타
			OnRealTimeData(pCDS->lpData, (int)pCDS->cbData ) ;			
			break ;	
	}
		
	return CDialog::OnCopyData(pWnd, pCopyDataStruct);
}


//=======================================================================================
// FUNCTION : 실시간 데이타
// RETURN   : 
//=======================================================================================
void CDongbuAPIClientDlg::OnRealTimeData(PVOID szData, int nLen)
{
	TRACE("OnRealTimeData------------------\n");
	
	DrdsData* pDrdsData = (DrdsData*)szData;
	
	int nDataType = -1 ;
	
	if (memcmp(pDrdsData->Name, R_XF2, 3) == 0 ) 
	{
		nDataType = eXF2 ;
		DRDS_XF2_DATA* pReal = (DRDS_XF2_DATA*)pDrdsData->Data;					
	}
		
	else if (memcmp(pDrdsData->Name, R_XF3, 3) == 0)
	{
		nDataType = eXF3 ;
		DRDS_XF3_DATA* pReal = (DRDS_XF3_DATA*)pDrdsData->Data;		
	}
			
	else if (memcmp(pDrdsData->Name, R_SC0, 3) == 0)	
	{
		nDataType = eSC0 ;
		DRDS_SC0_DATA* pReal = (DRDS_SC0_DATA*)pDrdsData->Data;
	}
	
	else if (memcmp(pDrdsData->Name, R_OC0, 3) == 0)	
	{
		nDataType = eOC0 ;	
		DRDS_OC0_DATA* pReal = (DRDS_OC0_DATA*)pDrdsData->Data;
	}

	//선물 5호가
	else if (memcmp(pDrdsData->Name, R_SH0, 3) == 0)	
	{
		nDataType = eSH0 ;
		DRDS_SH0_DATA* pReal = (DRDS_SH0_DATA*)pDrdsData->Data;
		
	}
	//옵션 5호가
	else if (memcmp(pDrdsData->Name, R_OH0, 3) == 0)	
	{
		nDataType = eOH0 ;
		DRDS_OH0_DATA* pReal = (DRDS_OH0_DATA*)pDrdsData->Data;
	}

	if ( nDataType >= 0 )
	{
		//CString szVal, szKey;
		//szKey.Format("%32.32s", pDrdsData->Key);
		//szVal.Format("%*.*s", pDrdsData->Len, pDrdsData->Len, pDrdsData->Data);
		//m_lstMsg.AddString(szMsg) ;	
	}
	
	CString szText ;
	szText.Format("[%3.3s] Realtime Data received", pDrdsData->Name);
	m_lstMsg.InsertString(0, szText ) ;
}


//=======================================================================================
// FUNCTION : 선물 계좌리스트 
//            GEJA_SIZE : 위임구분(1) + 계좌(11) + 계좌명(20)
//=======================================================================================
#define GEJA_SIZE		32
void CDongbuAPIClientDlg::GetFutureAccList(LPSTR szData, int nLen)
{

	m_cmbAccount.ResetContent();

	CString strData ( szData );

	if ( strData.GetLength() < 3 )
		return ;
	
	int nOffset = 3 ;
	int nCount = atoi ( strData.Left(nOffset) ) ;

	for ( int i =0 ; i < nCount; i++ )
	{
		CString szAcc = strData.Mid( nOffset, GEJA_SIZE ) ;

		CString szGubun = szAcc.Left (1) ;
		CString szAccNo = szAcc.Mid (1, 11) ;
		CString szAccName = szAcc.Right(20) ;
		szAccNo.TrimRight() ;
		szAccName.TrimRight() ;

		CString strText;
		strText.Format("%s[%s]", szAccNo, szAccName) ;
		m_cmbAccount.AddString(strText) ;

		nOffset+= GEJA_SIZE ;
	}

	if (nCount > 0)
		m_cmbAccount.SetCurSel(0);

	m_lstMsg.InsertString(0,"계좌조회>>조회 완료" ) ;	

	UpdateData(FALSE);
}
//=======================================================================================
// FUNCTION : 잔고조회
//=======================================================================================
void CDongbuAPIClientDlg::OnBtnJango() 
{	
	CExInqueryDlg dlgQuery ;	
	dlgQuery.m_nTRCode = atoi(TR_13655);
	dlgQuery.DoModal() ;

}

//=======================================================================================
// FUNCTION : 체결내역조회
//=======================================================================================
void CDongbuAPIClientDlg::OnBtnChegyul() 
{
	CExInqueryDlg dlgQuery ;	
	dlgQuery.m_nTRCode = atoi(TR_13615) ;
	dlgQuery.DoModal() ;

}

//=======================================================================================
// FUNCTION : 평가현황 조회
//=======================================================================================
void CDongbuAPIClientDlg::OnBtnEval() 
{
	CExInqueryDlg dlgQuery ;	
	dlgQuery.m_nTRCode = atoi(TR_15813) ;	
	dlgQuery.DoModal() ;
}

//=======================================================================================
// FUNCTION : 수수료 / 주문가능 금액 조회
//=======================================================================================
void CDongbuAPIClientDlg::OnBtnFee() 
{
	CExInqueryDlg dlgQuery ;	
	dlgQuery.m_nTRCode = atoi(TR_13653) ;
	dlgQuery.DoModal() ;
}


//=======================================================================================
// FUNCTION : 주문내기
//=======================================================================================
void CDongbuAPIClientDlg::OnBtnOrder() 
{	
	CExOrderDlg dlgOrder ;	
	dlgOrder.m_nTRCode = atoi(TR_20000) ;	
	dlgOrder.DoModal() ;	
}

//=======================================================================================
// FUNCTION : 신규/청산 가능수량
//=======================================================================================
void CDongbuAPIClientDlg::OnBtnAbleqty() 
{
	CExOrderDlg dlgOrder ;	
	dlgOrder.m_nTRCode = atoi(TR_14051) ;	
	dlgOrder.DoModal() ;
}

//=======================================================================================
// FUNCTION : 옵션종목별매도증거금
//=======================================================================================
void CDongbuAPIClientDlg::OnBtnDeposit() 
{
	CExOptDepositDlg dlgOptionDeposit;			
	dlgOptionDeposit.DoModal() ;
}

//=======================================================================================
// FUNCTION : 계좌리스트 가져오기
//=======================================================================================
void CDongbuAPIClientDlg::OnBtnAcclist() 
{	
	COPYDATASTRUCT cds;
	cds.dwData = (DWORD)DRCM_F_ACCLIST;			
	cds.cbData = 0 ;
	::SendMessage(theApp.g_hDongbuDRCM, WM_COPYDATA, (WPARAM)m_hWnd, (LPARAM)&cds);		
}


void CDongbuAPIClientDlg::OnBtnSc0() 
{
	RequestRT(IDC_BTN_SC0, "시세", R_SC0,  m_strFutCodes);	
}

void CDongbuAPIClientDlg::OnBtnSh0() 
{
	RequestRT(IDC_BTN_SH0, "호가", R_SH0, m_strFutCodes);		
}

void CDongbuAPIClientDlg::OnBtnOc0() 
{
	RequestRT(IDC_BTN_OC0, "시세", R_OC0, m_strOptCodes);		
}

void CDongbuAPIClientDlg::OnBtnOh0() 
{
	RequestRT(IDC_BTN_OH0, "호가", R_OH0, m_strOptCodes);	
}

void CDongbuAPIClientDlg::OnBtnXf2() 
{	
	RequestRT(IDC_BTN_XF2,"체결", R_XF2 , m_strID);		
}

void CDongbuAPIClientDlg::OnBtnXf3() 
{
	RequestRT(IDC_BTN_XF3, "잔고", R_XF3, m_strID);		
}

void CDongbuAPIClientDlg::RequestRT(UINT nDlgItemId,CString szTitle, CString szRId, CString szParam) 
{
	CString szText ;
	CButton *pButton = (CButton *)GetDlgItem(nDlgItemId) ;
	
	if (pButton->GetCheck())	
	{
		theApp.SendToServerEx (DRCM_ADVICE, szRId, szParam, m_hWnd );
		szText.Format("%s(%s)해제", szTitle, szRId);
	}
	else
	{
		theApp.SendToServerEx (DRCM_UNADVICE, szRId, szParam, m_hWnd );
		szText.Format("%s(%s)등록", szTitle, szRId);		
	}

	pButton->SetWindowText(szText);
}
void CDongbuAPIClientDlg::OnClearList() 
{	
	m_lstMsg.ResetContent() ;
	UpdateData(FALSE) ;
}

CString CDongbuAPIClientDlg::SetIp (CString szIP )
{
	CString strResult ;

	CString tmp;
	int nIndex = szIP.Find(".");
	if (nIndex<0)
	{
		strResult.Empty();
		return strResult;
	}

	tmp.Format("%3.3s", szIP.Left(nIndex));
	szIP = szIP.Mid(nIndex+1);
	strResult += tmp;

	nIndex = szIP.Find(".");
	if (nIndex<0)
	{
		strResult.Empty();
		return strResult;
	}
	tmp.Format("%3.3s", szIP.Left(nIndex));
	strResult += tmp;

	szIP = szIP.Mid(nIndex+1);
	nIndex = szIP.Find(".");
	if (nIndex<0)
	{
		strResult.Empty();
		return strResult;
	}
	tmp.Format("%3.3s", szIP.Left(nIndex));
	strResult += tmp;

	szIP = szIP.Mid(nIndex+1);
	tmp.Format("%3.3s", szIP);
	strResult += tmp;

	strResult.Replace(' ', '0');
	return strResult;
}

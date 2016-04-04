// ExDepositDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "DongbuAPIClient_VC.h"
#include "ExDepositDlg.h"


// CExDepositDlg 대화 상자입니다.

#include "include_cme/TR20112.h"
#include "include_fo/TR15813.h"
#include "include_sk/TR20051.h"

IMPLEMENT_DYNAMIC(CExDepositDlg, CDialog)

CExDepositDlg::CExDepositDlg(CWnd* pParent /*=NULL*/)
: CDialog(CExDepositDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExDepositDlg)
	m_strAccount = theApp.g_strAccount;
	m_strAcctPwd =  theApp.g_strAcctPwd;
	m_strDate = theApp.g_strDate;
	//}}AFX_DATA_INIT
}

CExDepositDlg::~CExDepositDlg()
{
}

void CExDepositDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CExDepositDlg)
	DDX_Control(pDX, IDC_LIST,			m_lstMsg);	
	DDX_Text(pDX, IDC_EDT_ACCOUNT,		m_strAccount);
	DDX_Text(pDX, IDC_EDT_ACCTPWD,		m_strAcctPwd);	
	DDX_Text(pDX, IDC_EDT_DATE,		    m_strDate);	
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExDepositDlg, CDialog)

	ON_WM_COPYDATA()
	ON_BN_CLICKED(IDC_BTN_INQUERY, OnBtnInquery)

END_MESSAGE_MAP()


// CExDepositDlg 메시지 처리기입니다.

BOOL CExDepositDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CExDepositDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
{
	COPYDATASTRUCT* pCDS = pCopyDataStruct ;

	int nDataType = (int)pCDS->dwData ;

	STTRHEADER* prData = (STTRHEADER*)pCDS->lpData;
	char szTrCode[5+1] ={0,} ;
	char szMsg[82+1] ={0,} ;
	CString strMsg  ;


	memcpy(szTrCode, prData->TRCode, 5 ) ;
	memcpy(szMsg, prData->Message, 82) ;

	strMsg = szMsg ;
	strMsg.TrimRight() ;

	if ( strcmp(szTrCode, TR_15813 ) == 0 ) 
	{					
		TR_15813_O* pData = (TR_15813_O*)prData->TRData;
		strMsg= "선옵 예수금 현황 결과>>" + strMsg ;
		m_lstMsg.InsertString( 0, strMsg );
		UpdateData(FALSE) ;
	}

	if ( strcmp(szTrCode, TR_20112 ) == 0 ) 
	{					
		TR_20112_O* pData = (TR_20112_O*)prData->TRData;

		strMsg= "CME선물 예수금 현황 결과>>" + strMsg ;
		m_lstMsg.InsertString( 0, strMsg );
		UpdateData(FALSE) ;
	}

	if ( strcmp(szTrCode, TR_20051 ) == 0 ) 
	{					
		TR_20051_O* pData = (TR_20051_O*)prData->TRData;

		CString szTmp ;
		szTmp.Format("예탁자산총액 = %*.*s", sizeof(pData->dpsast), sizeof(pData->dpsast), pData->dpsast) ;

		m_lstMsg.InsertString( 0, szTmp );
		
		strMsg= "주식 예수금 현황 결과>>"+ strMsg ;
		m_lstMsg.InsertString( 0, strMsg );

		UpdateData(FALSE) ;
	}


	return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
}

void CExDepositDlg::OnBtnInquery()
{
	switch (m_nProduct)
	{	 
	case ID_PRODUCT_FO :
	case ID_PRODUCT_SFO :
		MakePacket_FO();
		break;

	case ID_PRODUCT_CME :
		MakePacket_CME() ;
		break;

	case ID_PRODUCT_SK :
		MakePacket_SK() ;
		break;
	}	
}

//=======================================================================================
// FUNCTION : 동부api에 데이터 요청 (CME선물)
// RETURN   : 
//=======================================================================================
void CExDepositDlg::MakePacket_CME()
{
	UpdateData (TRUE) ;
	
	CString szAccount = m_strAccount ; 	
	CString szPwd = m_strAcctPwd ;
	CString szDate = m_strDate ;
	CString szNextKey;
	CString szInput ;
	
	szAccount.TrimLeft() ;
	szAccount.TrimRight() ;
	szAccount.Remove('-');


	TR_20112_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_20112_I)) ;

	memcpy ( stInput.accno, szAccount, szAccount.GetLength() ) ;
	memcpy ( stInput.pass, szPwd, szPwd.GetLength() ) ;
	//memcpy ( stInput.date, szDate, szDate.GetLength() ) ;		
	memcpy ( stInput.janggubun, "0", 1) ;		//잔고평가구분 #0:기본설정1:이동평균법2:선입선출법 (보통은 '0'을 사용)
	memcpy ( stInput.futuregubun, "1", 1) ;		//선물가격평가구분  #2:전일종가1:당초가
	//memcpy ( stInput.ip_addr, szIP, szIP.GetLength()) ;						
	
	szNextKey.Format("%0*d", sizeof(stInput.nxtKey), 0);
	memcpy ( stInput.nxtKey, szNextKey, szNextKey.GetLength()) ;

	int nLen = sizeof(stInput) ;
	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);
	theApp.SendToServerEx (DRCM_SENDDATA, TR_20112, szInput, m_hWnd);
}

//=======================================================================================
// FUNCTION : 동부api에 데이터 요청 (선물옵션/주식선옵)
// RETURN   : 
//=======================================================================================
void CExDepositDlg::MakePacket_FO()
{
	UpdateData (TRUE) ;

	CString szAccount = m_strAccount ; 	
	CString szPwd = m_strAcctPwd ;
	CString szDate = m_strDate ;
	CString szNextKey;
	CString szInput ;

	szAccount.TrimLeft() ;
	szAccount.TrimRight() ;
	szAccount.Remove('-');


	TR_15813_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_15813_I)) ;

	memcpy ( stInput.accno, szAccount, szAccount.GetLength() ) ;
	memcpy ( stInput.pass, szPwd, szPwd.GetLength() ) ;
	memcpy ( stInput.date, szDate, szDate.GetLength() ) ;		
	memcpy ( stInput.janggubun, "0", 1) ;		//잔고평가구분 #0:기본설정1:이동평균법2:선입선출법 (보통은 '0'을 사용)
	memcpy ( stInput.futuregubun, "1", 1) ;		//선물가격평가구분  #2:전일종가1:당초가
	
	
	szNextKey.Format("%0*d", sizeof(stInput.nxtKey), 0);
	memcpy ( stInput.nxtKey, szNextKey, szNextKey.GetLength()) ;

	int nLen = sizeof(stInput) ;
	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);
	theApp.SendToServerEx (DRCM_SENDDATA, TR_15813, szInput, m_hWnd);		
}


//=======================================================================================
// FUNCTION : 동부api에 데이터 요청 (주식)
// RETURN   : 
//=======================================================================================
void CExDepositDlg::MakePacket_SK()
{
	UpdateData (TRUE) ;

	CString szAccount = m_strAccount ; 	
	CString szPwd = m_strAcctPwd ;
	CString szDate = m_strDate ;
	CString szNextKey;
	CString szInput ;

	szAccount.TrimLeft() ;
	szAccount.TrimRight() ;
	szAccount.Remove('-');


	TR_20051_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_20051_I)) ;

	memcpy ( stInput.geja, szAccount, szAccount.GetLength() ) ;
	memcpy ( stInput.passwd, szPwd, szPwd.GetLength() ) ;	
	
	int nLen = sizeof(stInput) ;
	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);
	theApp.SendToServerEx (DRCM_SENDDATA, TR_20051, szInput, m_hWnd);		
}

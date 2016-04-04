// ExAbleOrderQtyDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "DongbuAPIClient_VC.h"
#include "ExAbleOrderQtyDlg.h"


// CExAbleOrderQtyDlg 대화 상자입니다.

#include "include_fo/TR14051.h"
#include "include_cme/TR26011.h"
#include "include_jfo/TR14055.h"
#include "include_sk/TR10121.h"
#include "include_sk/TR10142.h"

#include "ExJangoDlg.h"


IMPLEMENT_DYNAMIC(CExAbleOrderQtyDlg, CDialog)

CExAbleOrderQtyDlg::CExAbleOrderQtyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExAbleOrderQtyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExAbleOrderQtyDlg)
	m_strAccount = theApp.g_strAccount;
	m_strAcctPwd =  theApp.g_strAcctPwd;
	m_strJongmok =  theApp.g_strJongmok;
	m_strPrice =  theApp.g_strPrice;	
	//}}AFX_DATA_INIT
}

CExAbleOrderQtyDlg::~CExAbleOrderQtyDlg()
{
}

void CExAbleOrderQtyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CExAbleOrderQtyDlg)
	DDX_Control(pDX, IDC_LIST,			m_lstMsg);
	DDX_Control(pDX, IDC_CMB_PRICETYPE, m_cmbPriceType);
	DDX_Control(pDX, IDC_CMB_CREDITGUBUN, m_cmbCreditType);
	
	DDX_Text(pDX, IDC_EDT_ACCOUNT,		m_strAccount);
	DDX_Text(pDX, IDC_EDT_ACCTPWD,		m_strAcctPwd);	
	DDX_Text(pDX, IDC_EDT_JONGMOK,		m_strJongmok);
	DDX_Text(pDX, IDC_EDT_PRICE,		m_strPrice);	
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExAbleOrderQtyDlg, CDialog)

	ON_WM_COPYDATA()
	ON_BN_CLICKED(IDC_BTN_ABLEQTY, OnBtnAbleqty)
	
END_MESSAGE_MAP()


// CExAbleOrderQtyDlg 메시지 처리기입니다.

BOOL CExAbleOrderQtyDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	switch (m_nProduct)
	{
	case ID_PRODUCT_CME :
		//가격타입
		m_cmbPriceType.AddString("00:지정가");
		m_cmbPriceType.AddString("00:지정가(IOC)");
		m_cmbPriceType.AddString("00:지정가(FOK)");
		m_cmbPriceType.SetCurSel(0);
		break;
	default:
		m_cmbPriceType.AddString("00:지정가");
		m_cmbPriceType.AddString("03:시장가");
		m_cmbPriceType.SetCurSel(0);
	}

	// "01":유통융자, "03":자기융자,"07":자기대주 
	m_cmbCreditType.AddString("01:유통융자");
	m_cmbCreditType.AddString("03:자기융자");
	m_cmbCreditType.AddString("07:자기대주");
	m_cmbCreditType.SetCurSel(0);


	CButton *pMesu = (CButton *)(GetDlgItem(IDC_RADIO_MESU));
	pMesu->SetCheck(1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}



BOOL CExAbleOrderQtyDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
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

	if ( strcmp(szTrCode, TR_14051 ) == 0 || strcmp(szTrCode, TR_14055 ) == 0 || strcmp(szTrCode, TR_26011 ) == 0 ) 
	{					
		TR_26011_O* pData = (TR_26011_O*)prData->TRData;	

		CString szTmp ;
		szTmp.Format("신규 가능 수량 %*.*s", sizeof(pData->newqty), sizeof(pData->newqty), pData->newqty ) ;
		m_lstMsg.InsertString( 0, szTmp );

		szTmp.Format("청산 가능 수량 %*.*s" , sizeof(pData->clearqty), sizeof(pData->clearqty), pData->clearqty );
		m_lstMsg.InsertString( 0, szTmp );


		strMsg= "신규/청산 가능수량조회 결과 >>" + strMsg ;
		m_lstMsg.InsertString( 0, strMsg );


		//*********************************
		//화면에 맞게 데이터를 처리
		//*********************************


		UpdateData(FALSE) ;
	}

	if ( strcmp(szTrCode, TR_10121 ) == 0 ) //주식 신규/청산 가능수량
	{					
		CTR_10121_O stQty((TR_10121_O*)prData->TRData) ;

		CString szTmp ;
		szTmp.Format("매도/매수최대가능수량 %s", stQty.pqty ) ;
		m_lstMsg.InsertString( 0, szTmp );

		szTmp.Format("매수적정가능수량   %s" , stQty.maxqty );
		m_lstMsg.InsertString( 0, szTmp );


		strMsg= "주식 신규/청산 가능수량조회 결과 >>" + strMsg ;
		m_lstMsg.InsertString( 0, strMsg );


		//*********************************
		//화면에 맞게 데이터를 처리
		//*********************************

		UpdateData(FALSE) ;
	}
	if ( strcmp(szTrCode, TR_10142 ) == 0 ) //주식 신용 매수 가능수량
	{					
		CTR_10142_O stQty((CTR_10142_O*)prData->TRData) ;

		CString szTmp ;
		szTmp.Format("신용 주문가능금액 %s", stQty.maxprice ) ;
		m_lstMsg.InsertString( 0, szTmp );

		szTmp.Format("신용 매수적정가능수량   %s" , stQty.maxqty );
		m_lstMsg.InsertString( 0, szTmp );


		strMsg= "주식 신용 매수 가능수량조회 결과 >>" + strMsg ;
		m_lstMsg.InsertString( 0, strMsg );


		//*********************************
		//화면에 맞게 데이터를 처리
		//*********************************

		UpdateData(FALSE) ;
	}


	return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
}

void CExAbleOrderQtyDlg::OnBtnAbleqty()
{
	switch (m_nProduct)
	{
		case ID_PRODUCT_FO : //선물옵션		
			MakePacket_FO();
			break;

		case ID_PRODUCT_CME : //CME선물
			MakePacket_CME() ;
			break;

		case ID_PRODUCT_SFO : //주식선물		
			MakePacket_SFO();
			break;

		case ID_PRODUCT_SK : //주식
			{
				CButton *pChkCredit = (CButton *) GetDlgItem(IDC_CHK_CREDITORDER) ;
				BOOL bCheck = pChkCredit->GetCheck() ;
				if ( bCheck ) //신용가능 수량
					MakePacket_SK_Credit();
				else
					MakePacket_SK();
			}
			
			break;
	}	
}


//=======================================================================================
// FUNCTION : 동부api에 데이터 요청 (선물옵션)
// RETURN   : 
//=======================================================================================
void CExAbleOrderQtyDlg::MakePacket_FO()
{
	UpdateData (TRUE) ;

	int nLen = 0 ;
	CString szPwd = m_strAcctPwd ;
	CString szAccount = m_strAccount ; 
	CString szJongmok = m_strJongmok;
	CString szInput ;
	CString szPrice ;	

	long nPrice = int( (atof(m_strPrice)*100) + 0.005 ) ;	
	szPrice.Format("%d", nPrice) ;

	CButton *pMesu = (CButton *)(GetDlgItem(IDC_RADIO_MESU));
	CString szGubun = pMesu->GetCheck() ? "2" :"1";

	CString szPriceType ;	
	m_cmbPriceType.GetLBText(m_cmbPriceType.GetCurSel(), szPriceType);	

	TR_14051_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_14051_I)) ;

	memcpy ( stInput.geja, szAccount, szAccount.GetLength() ) ;
	memcpy ( stInput.passwd, szPwd, szPwd.GetLength() ) ;
	memcpy ( stInput.jcode, m_strJongmok, szJongmok.GetLength() ) ;
	memcpy ( stInput.gb, szGubun, 1 ) ;				//매매구분  1:매도 2:매수
	memcpy ( stInput.price, szPrice, szPrice.GetLength() ) ;
	memcpy ( stInput.ord_type, szPriceType.Left(2), 2 ) ;		//주문유형	
	memcpy ( stInput.zLqdtQtyQryTp, "1", 1 ) ;					//청산수량 조회구분 : 동부는 1
	//memcpy ( stInput.ip, szIP, szIP.GetLength()) ;

	nLen = sizeof(stInput) ;
	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);
	theApp.SendToServerEx(DRCM_SENDDATA, TR_14051, szInput, m_hWnd);
}

//=======================================================================================
// FUNCTION : 동부api에 데이터 요청 (주식선옵)
// RETURN   : 
//=======================================================================================
void CExAbleOrderQtyDlg::MakePacket_SFO()
{
	UpdateData (TRUE) ;

	int nLen = 0 ;
	CString szPwd = m_strAcctPwd ;
	CString szAccount = m_strAccount ; 
	CString szJongmok = m_strJongmok;
	CString szInput ;
	CString szPrice ;	

	long nPrice = atoi(m_strPrice) ;
	szPrice.Format("%d", nPrice) ;

	CButton *pMesu = (CButton *)(GetDlgItem(IDC_RADIO_MESU));
	CString szGubun = pMesu->GetCheck() ? "2" :"1";

	CString szPriceType ;	
	m_cmbPriceType.GetLBText(m_cmbPriceType.GetCurSel(), szPriceType);	
	int nPriceType = atoi(szPriceType.Left(2)) ;	

	TR_14055_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_14055_I)) ;

	memcpy ( stInput.geja, szAccount, szAccount.GetLength() ) ;
	memcpy ( stInput.passwd, szPwd, szPwd.GetLength() ) ;
	memcpy ( stInput.jcode, m_strJongmok, szJongmok.GetLength() ) ;
	memcpy ( stInput.gb, szGubun, 1 ) ;								//매매구분  1:매도 2:매수
	memcpy ( stInput.price, szPrice, szPrice.GetLength() ) ;
	memcpy ( stInput.ord_type, szPriceType.Left(2), 2 ) ;		    //주문유형	
	memcpy ( stInput.zLqdtQtyQryTp, "1", 1 ) ;					    //청산수량 조회구분 : 동부는 1
	//memcpy ( stInput.ip, szIP, szIP.GetLength()) ;

	nLen = sizeof(stInput) ;
	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);
	theApp.SendToServerEx(DRCM_SENDDATA, TR_14055, szInput, m_hWnd);
}

//=======================================================================================
// FUNCTION : 동부api에 데이터 요청 (CME선물)
// RETURN   : 
//=======================================================================================
void CExAbleOrderQtyDlg::MakePacket_CME()
{
	UpdateData (TRUE) ;

	int nLen = 0 ;
	CString szPwd = m_strAcctPwd ;
	CString szAccount = m_strAccount ; 
	CString szJongmok = m_strJongmok;
	CString szInput ;
	CString szPrice ;	
	
	long nPrice = int( (atof(m_strPrice)*100) + 0.005 ) ;
	szPrice.Format("%d", nPrice) ;

	CButton *pMesu = (CButton *)(GetDlgItem(IDC_RADIO_MESU));
	CString szGubun = pMesu->GetCheck() ? "2" :"1";

	CString szPriceType ;	
	m_cmbPriceType.GetLBText(m_cmbPriceType.GetCurSel(), szPriceType);	
	int nPriceType = atoi(szPriceType.Left(2)) ;	

	TR_26011_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_26011_I)) ;

	memcpy ( stInput.geja, szAccount, szAccount.GetLength() ) ;
	memcpy ( stInput.passwd, szPwd, szPwd.GetLength() ) ;
	memcpy ( stInput.jcode, m_strJongmok, szJongmok.GetLength() ) ;
	memcpy ( stInput.gb, szGubun, 1 ) ;								//매매구분  1:매도 2:매수
	memcpy ( stInput.price, szPrice, szPrice.GetLength() ) ;
	memcpy ( stInput.ord_type, szPriceType.Left(2), 2 ) ;			//주문유형	
	//memcpy ( stInput.ip, szIP, szIP.GetLength()) ;

	nLen = sizeof(stInput) ;
	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);
	theApp.SendToServerEx(DRCM_SENDDATA, TR_26011, szInput, m_hWnd);
}


//=======================================================================================
// FUNCTION : 동부api에 데이터 요청 (주식)
// RETURN   : 
//=======================================================================================
void CExAbleOrderQtyDlg::MakePacket_SK()
{
	UpdateData (TRUE) ;

	int nLen = 0 ;
	CString szPwd = m_strAcctPwd ;
	CString szAccount = m_strAccount ; 
	CString szJongmok = m_strJongmok;
	CString szInput ;
	CString szPrice ;	

	long nPrice = atoi(m_strPrice) ;
	szPrice.Format("%d", nPrice) ;

	CButton *pMesu = (CButton *)(GetDlgItem(IDC_RADIO_MESU));
	CString szGubun = pMesu->GetCheck() ? "2" :"1";

	TR10121_I stInput ;
	memset (&stInput, 0x20, sizeof(TR10121_I)) ;

	memcpy ( stInput.gb, szGubun, 1 ) ;								//매매구분  1:매도 2:매수
	memcpy ( stInput.geja, szAccount, szAccount.GetLength() ) ;
	memcpy ( stInput.passwd, szPwd, szPwd.GetLength() ) ;
	memcpy ( stInput.jcode, m_strJongmok, szJongmok.GetLength() ) ;	
	memcpy ( stInput.price, szPrice, szPrice.GetLength() ) ;
	
	nLen = sizeof(stInput) ;
	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);
	theApp.SendToServerEx(DRCM_SENDDATA, TR_10121, szInput, m_hWnd);
}


//=======================================================================================
// FUNCTION : 동부api에 데이터 요청 (주식)
// RETURN   : 신용 매수 주문 가능 수량
//=======================================================================================
void CExAbleOrderQtyDlg::MakePacket_SK_Credit()
{	
	//ipaddr(199.99.9.90->199099009090)

	UpdateData (TRUE) ;

	int nLen = 0 ;
	CString szPwd = m_strAcctPwd ;
	CString szAccount = m_strAccount ; 
	CString szJongmok = m_strJongmok;
	CString szInput ;
	CString szPrice ;	

	CString szCreditType ;	
	m_cmbCreditType.GetLBText(m_cmbCreditType.GetCurSel(), szCreditType);	
	szCreditType = szCreditType.Left(2) ;

	CString szIP = "199099009090000" ;


	TR_10142_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_10142_I)) ;

	
	memcpy ( stInput.acct, szAccount, szAccount.GetLength() ) ;
	memcpy ( stInput.passwd, szPwd, szPwd.GetLength() ) ;
	memcpy ( stInput.sinygb, szCreditType, szCreditType.GetLength() ) ;
	memcpy ( stInput.jcode, m_strJongmok, szJongmok.GetLength() ) ;	
	
	memcpy ( stInput.ipaddr, szIP, szIP.GetLength()) ;

	//가격
	long nPrice = atoi(m_strPrice) ;	
	nLen = sizeof(stInput.price);
	szPrice.Format("%0*I64d", nLen-4, (__int64) nPrice);
	szPrice = "+" + szPrice + ".00";	//반드시 포멧을 맞춰야함.
	memcpy(stInput.price, (LPSTR)(LPCTSTR)szPrice, nLen);

	nLen = sizeof(stInput) ;
	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);
	theApp.SendToServerEx(DRCM_SENDDATA, TR_10142, szInput, m_hWnd);
}



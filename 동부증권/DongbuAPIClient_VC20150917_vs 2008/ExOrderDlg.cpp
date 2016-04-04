// ExOrderDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "DongbuAPIClient_VC.h"
#include "ExOrderDlg.h"


// CExOrderDlg 대화 상자입니다.

#include "include_cme/TR20001.h"
#include "include_fo/TR20030.h"
#include "include_sk/TR20020.h"

#define		DEF_ORDER_MEDO		1
#define		DEF_ORDER_MESU		2
#define		DEF_ORDER_MODIFY	3
#define		DEF_ORDER_CANCEL	4


IMPLEMENT_DYNAMIC(CExOrderDlg, CDialog)


//------------------------------------------------------------------------------------------
// 주문관련 공통 INPUT HEADER & OUTPUT STRUCTURES
//------------------------------------------------------------------------------------------
typedef struct _TRORDER_I
{
	char    incnt    [ 4];      /* 주문 cnt					*/
	char    mapno    [ 5];      /* TR사용하는 Map번호		*/
} TR_ORDER_I;

typedef struct _TRORDER_O
{
	char    outcnt   [ 4];       /* 주문 cnt                */
} TR_ORDER_O;

#define SZ_ORDER_O     sizeof(TR_ORDER_O)

typedef struct _TRORDER_OS
{
	char	clikey   [ 8];      /* 주문 key                  */
	char    juno     [ 9];      /* 주문번호                  */
	char    msgcd    [ 6];      /* 메시지코드                */
	char    msgcm   [100];      /* 처리메시지                */
} TR_ORDER_OS;

#define SZ_ORDER_OS     sizeof(TR_ORDER_OS)


CExOrderDlg::CExOrderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExOrderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExOrderDlg)
	m_strAccount = theApp.g_strAccount;
	m_strAcctPwd =  theApp.g_strAcctPwd;
	m_strJongmok =  theApp.g_strJongmok;
	m_strPrice =  theApp.g_strPrice;		
	m_strQty = _T("1");	
	//}}AFX_DATA_INIT
}

CExOrderDlg::~CExOrderDlg()
{
}

void CExOrderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CExOrderDlg)
	DDX_Control(pDX, IDC_LIST,			m_lstMsg);
	DDX_Control(pDX, IDC_CMB_PRICETYPE, m_cmbPriceType);
	DDX_Text(pDX, IDC_EDT_ACCTPWD,		m_strAcctPwd);	
	DDX_Text(pDX, IDC_EDT_JONGMOK,		m_strJongmok);
	DDX_Text(pDX, IDC_EDT_PRICE,		m_strPrice);
	DDX_Text(pDX, IDC_EDT_QTY,			m_strQty);
	DDX_Text(pDX, IDC_EDT_ACCOUNT,		m_strAccount);
	DDX_Text(pDX, IDC_EDT_ORGNO,		m_strOrgOrderNo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExOrderDlg, CDialog)

	ON_WM_COPYDATA()

	ON_BN_CLICKED(IDC_BTN_MESU,		OnBtnMesu)
	ON_BN_CLICKED(IDC_BTN_MEDO,		OnBtnMedo)
	ON_BN_CLICKED(IDC_BTN_MODIFY,	OnBtnModify)
	ON_BN_CLICKED(IDC_BTN_CANCEL,	OnBtnCancel)
	

END_MESSAGE_MAP()


// CExOrderDlg 메시지 처리기입니다.

BOOL CExOrderDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();


	switch (m_nProduct)
	{
	case ID_PRODUCT_CME :
		//가격타입
		m_cmbPriceType.AddString("00:지정가");
		m_cmbPriceType.AddString("10:지정가(IOC)");
		m_cmbPriceType.AddString("20:지정가(FOK)");
		m_cmbPriceType.SetCurSel(0);
		break;

	case ID_PRODUCT_SK :		
		m_cmbPriceType.AddString("00:지정가");
		m_cmbPriceType.AddString("03:시장가");
		m_cmbPriceType.AddString("05:조건부지정가");
		m_cmbPriceType.AddString("06:최유리지정가");
		m_cmbPriceType.AddString("07:최우선지정가");
		m_cmbPriceType.AddString("10:지정가(IOC)");
		m_cmbPriceType.AddString("13:시장가(IOC)");
		m_cmbPriceType.AddString("16:최유리지정가(IOC)");
		m_cmbPriceType.AddString("20:지정가(FOK)");
		m_cmbPriceType.AddString("23:시장가(FOK)");
		m_cmbPriceType.AddString("26:최유리지정가(FOK)");
		m_cmbPriceType.AddString("61:장전시간외");
		m_cmbPriceType.AddString("81:장후시간외");
		m_cmbPriceType.AddString("09:자사주");

		m_cmbPriceType.SetCurSel(0);
		break;

	default:
		m_cmbPriceType.AddString("00:지정가");
		m_cmbPriceType.AddString("03:시장가");
		m_cmbPriceType.SetCurSel(0);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CExOrderDlg::OnBtnMesu()
{
	MakeOrder(DEF_ORDER_MESU);
}

void CExOrderDlg::OnBtnMedo()
{
	MakeOrder(DEF_ORDER_MEDO);
}

void CExOrderDlg::OnBtnModify()
{
	MakeOrder(DEF_ORDER_MODIFY);
}

void CExOrderDlg::OnBtnCancel()
{
	MakeOrder(DEF_ORDER_CANCEL);
}


void CExOrderDlg::MakeOrder(int nOrdSect) 	
{	
	UpdateData(TRUE);

	long nPrice = 0 ;

	switch (m_nProduct)
	{	
	case ID_PRODUCT_FO :		//선옵	
		nPrice = int( (atof(m_strPrice)*100) + 0.005 ) ;	 //round off error 발생될 수 있음.
		MakePacket(TR_20030, nOrdSect, nPrice);
		break;
	case ID_PRODUCT_SFO :		//주식선옵
		nPrice = atoi(m_strPrice) ;
		MakePacket_SK(TR_20030, nOrdSect, nPrice);
		break;
	case ID_PRODUCT_CME :		//CME선물
		nPrice = int( (atof(m_strPrice)*100) + 0.005 ) ;	 //round off error 발생될 수 있음.	
		MakePacket(TR_20001, nOrdSect, nPrice);
		break;

	case ID_PRODUCT_SK :		//주식
		nPrice = atoi(m_strPrice) ;
		MakePacket_SK(TR_20020, nOrdSect, nPrice);
		break;	
	}	
}

//=======================================================================================
// FUNCTION : 동부api에 주문
//            선옵/CME선물/주식선옵 주문(TR_20001_IS /TR_20030_IS) INPUT I/O가 동일
//=======================================================================================
void CExOrderDlg::MakePacket(CString szTrNo, int nOrdSect, long nPrice) 	
{
	UpdateData (TRUE) ;

	TR_20001_IS tr_input ;

	int nLen = 0 ;

	CString szAccount = m_strAccount ;
	CString szPwd    = m_strAcctPwd ;	 
	CString szJongmok = m_strJongmok;
	CString szInput ;
		
	int nClientKey = 7000;							//임의의 숫자
	int nOrgOrdNo = atoi(m_strOrgOrderNo) ;			//원주문번호
	int nQty = atoi(m_strQty);	

	CString szPriceType ;	
	m_cmbPriceType.GetLBText(m_cmbPriceType.GetCurSel(), szPriceType);	
	int nPriceType = atoi(szPriceType.Left(2)) ;

	//CME선물일경우 정정/취소일경우 지정가만로만 주문 가능
	if ( m_nProduct == ID_PRODUCT_CME)
	{
		if ( nOrdSect == 3 || nOrdSect == 4 )
			nPriceType = 0 ;

		//취소는 전량취소(0)으로만 가능하다
		if ( nOrdSect == 4 )
			nQty = 0;
	}
	
	int nSize = sizeof(TR_20001_IS) ;
	memset(&tr_input, 0x20, sizeof(TR_20001_IS));  //스페이스로 채움

	CString strTemp;

	// 주문 Key			: clikey   [ 8]
	nLen = sizeof(tr_input.clikey);
	strTemp.Format("%0*d", nLen, nClientKey);
	memcpy(tr_input.clikey	, (LPSTR)(LPCTSTR)strTemp, nLen);


	// 주문구분			: gb       [ 1]		1:매도, 2:매수, 3:정정, 4:취소
	nLen = sizeof(tr_input.gb);
	strTemp.Format("%0*d", nLen, nOrdSect);
	memcpy(tr_input.gb	, (LPSTR)(LPCTSTR)strTemp, nLen);

	// 계좌번호			: geja     [11->20]
	nLen = sizeof(tr_input.geja);	
	szAccount.Remove('-'); szAccount.Remove('_'); szAccount.Remove(' ');
	strTemp.Format("%-*.*s", nLen, nLen, szAccount);
	memcpy(tr_input.geja	, (LPSTR)(LPCTSTR)strTemp	, nLen);

	// 비밀번호			: passwd   [ 8]
	nLen = sizeof(tr_input.passwd);
	strTemp.Format("%-*.*s", nLen, nLen, szPwd);
	memcpy(tr_input.passwd	, (LPSTR)(LPCTSTR)strTemp	, nLen);

	// 종목코드			: code     [15]
	nLen = sizeof(tr_input.code);
	strTemp.Format("%-*.*s", nLen, nLen, szJongmok);
	memcpy(tr_input.code	, (LPSTR)(LPCTSTR)strTemp, nLen);

	// 원주문번호		: wonno    [ 7->9]
	nLen = sizeof(tr_input.wonno);
	strTemp.Format("%0*d", nLen, nOrgOrdNo);
	memcpy(tr_input.wonno, (LPSTR)(LPCTSTR)strTemp	, nLen);

	// 주문유형			: jutype   [ 1->2]		00:지정가 03:시장가 05:조건부지정가 06:최유리지정가
	CString strPriceType ;
	nLen = sizeof(tr_input.jutype);	
	strPriceType.Format("%02d", nPriceType);
	memcpy(tr_input.jutype	, (LPSTR)(LPCTSTR)strPriceType, nLen);

	// 주문 가격		: juprc    [10->12]
	if(nPrice <= 0)
	{
		if ( strPriceType == "03" || strPriceType == "06" // 시장가,  최유리 지정가
			|| szJongmok.Left(1) == "4"	// 스프레드
			|| nOrdSect == 4			// 취소주문
			) {}
		else
		{
			AfxMessageBox("주문가격이 올바르지 않습니다!") ;
			return  ;
		}
	}

	nLen = sizeof(tr_input.juprc);

	if(nPrice < 0)
	{
		strTemp.Format("%0*I64d", nLen-1, (__int64)nPrice*(-1));
		strTemp = "-" + strTemp;
	} else
	{
		strTemp.Format("%0*I64d", nLen-1, (__int64)nPrice);
		strTemp = "+" + strTemp;
	}
	memcpy(tr_input.juprc	, (LPSTR)(LPCTSTR)strTemp	, nLen);

	// 주문 수량		: qty      [ 7->15]
	nLen = sizeof(tr_input.qty);	
	strTemp.Format("%0*d", nLen, nQty);
	memcpy(tr_input.qty	, (LPSTR)(LPCTSTR)strTemp	, nLen);

	// 클라이언트 IP	: ip       [12]		(199.99.9.90->199099009090)
	/*nLen = sizeof(tr_input.ip);
	strTemp.Format("%-*.*s", nLen, nLen, "");
	memcpy(tr_input.ip		, (LPSTR)(LPCTSTR)strTemp	, nLen);*/

	nLen = sizeof(TR_20001_IS) ;
	szInput.Format("000100000%-*.*s", nLen , nLen, (LPCTSTR)&tr_input );

	theApp.SendToServerEx (DRCM_SENDDATA, szTrNo, szInput, m_hWnd);		
}


//=======================================================================================
// FUNCTION : 동부api에 주식 주문
//          
//=======================================================================================
void CExOrderDlg::MakePacket_SK(CString szTrNo, int nOrdSect, long nPrice) 	
{
	UpdateData (TRUE) ;

	TR_20020_IS tr_input ;

	int nLen = 0 ;

	CString szAccount = m_strAccount ;
	CString szPwd    = m_strAcctPwd ;	 
	CString szJongmok = m_strJongmok;
	CString szInput ;
		
	int nClientKey = 7000;							//임의의 숫자
	int nOrgOrdNo = atoi(m_strOrgOrderNo) ;			//원주문번호
	int nQty = atoi(m_strQty);	

	CString szPriceType ;	
	m_cmbPriceType.GetLBText(m_cmbPriceType.GetCurSel(), szPriceType);	
	int nPriceType = atoi(szPriceType.Left(2)) ;
	
	int nSize = sizeof(TR_20020_IS) ;
	memset(&tr_input, 0x20, sizeof(TR_20020_IS));  //스페이스로 채움

	CString strTemp;

	// 주문 Key			: clikey   [ 8]
	nLen = sizeof(tr_input.clikey);
	strTemp.Format("%0*d", nLen, nClientKey);
	memcpy(tr_input.clikey	, (LPSTR)(LPCTSTR)strTemp, nLen);


	// 주문구분			: gb       [ 1]		1:매도, 2:매수, 3:정정, 4:취소
	nLen = sizeof(tr_input.gb);
	strTemp.Format("%0*d", nLen, nOrdSect);
	memcpy(tr_input.gb	, (LPSTR)(LPCTSTR)strTemp, nLen);

	// 계좌번호			: geja     [11->20]
	nLen = sizeof(tr_input.geja);	
	szAccount.Remove('-'); szAccount.Remove('_'); szAccount.Remove(' ');
	strTemp.Format("%-*.*s", nLen, nLen, szAccount);
	memcpy(tr_input.geja	, (LPSTR)(LPCTSTR)strTemp	, nLen);

	// 비밀번호			: passwd   [ 8]
	nLen = sizeof(tr_input.passwd);
	strTemp.Format("%-*.*s", nLen, nLen, szPwd);
	memcpy(tr_input.passwd	, (LPSTR)(LPCTSTR)strTemp	, nLen);

	// 종목코드			: code     [15]
	nLen = sizeof(tr_input.code);
	strTemp.Format("%-*.*s", nLen, nLen, szJongmok);
	memcpy(tr_input.code	, (LPSTR)(LPCTSTR)strTemp, nLen);

	// 원주문번호		: wonno    [ 7->9]
	nLen = sizeof(tr_input.wonno);
	strTemp.Format("%0*d", nLen, nOrgOrdNo);
	memcpy(tr_input.wonno, (LPSTR)(LPCTSTR)strTemp	, nLen);

	// 주문유형			: jutype   [ 1->2]		00:지정가 03:시장가 05:조건부지정가 06:최유리지정가
	CString strPriceType ;
	nLen = sizeof(tr_input.jutype);	
	strPriceType.Format("%02d", nPriceType);
	memcpy(tr_input.jutype	, (LPSTR)(LPCTSTR)strPriceType, nLen);

	// 주문 가격		: juprc    [10->12]
	if(nPrice <= 0)
	{
		if ( strPriceType == "03" || strPriceType == "06" // 시장가,  최유리 지정가
			|| strPriceType == "13" || strPriceType == "16" //ioc(시장가,  최유리 지정가)
			|| strPriceType == "23" || strPriceType == "26" //fok(시장가,  최유리 지정가)
			|| szJongmok.Left(1) == "4"	// 스프레드
			|| nOrdSect == 4			// 취소주문
			) {}
		else
		{
			AfxMessageBox("주문가격이 올바르지 않습니다!") ;
			return  ;
		}
	}

	nLen = sizeof(tr_input.juprc);

	if(nPrice < 0)
	{
		strTemp.Format("%0*I64d", nLen-1, (__int64)nPrice*(-1));
		strTemp = "-" + strTemp;
	} else
	{
		strTemp.Format("%0*I64d", nLen-1, (__int64)nPrice);
		strTemp = "+" + strTemp;
	}
	memcpy(tr_input.juprc	, (LPSTR)(LPCTSTR)strTemp	, nLen);

	// 주문 수량		: qty      [ 7->15]
	nLen = sizeof(tr_input.qty);	
	strTemp.Format("%0*d", nLen, nQty);
	memcpy(tr_input.qty	, (LPSTR)(LPCTSTR)strTemp	, nLen);

	//신용구분	
	nLen = sizeof(tr_input.zMgntrnCode);
	strTemp.Format("%0*d", nLen, 0);
	memcpy(tr_input.zMgntrnCode, (LPSTR)(LPCTSTR)strTemp	, nLen);

	//대출일자	
	nLen = sizeof(tr_input.zLoanDt);
	strTemp.Format("%0*d", nLen, 0);
	memcpy(tr_input.zLoanDt, (LPSTR)(LPCTSTR)strTemp	, nLen);


	// 클라이언트 IP	: ip       [12]		(199.99.9.90->199099009090)
	/*nLen = sizeof(tr_input.ip);
	strTemp.Format("%-*.*s", nLen, nLen, "");
	memcpy(tr_input.ip		, (LPSTR)(LPCTSTR)strTemp	, nLen);*/

	nLen = sizeof(TR_20020_IS) ;
	szInput.Format("000100000%-*.*s", nLen , nLen, (LPCTSTR)&tr_input );

	theApp.SendToServerEx (DRCM_SENDDATA, szTrNo, szInput, m_hWnd);		
}

//=======================================================================================
// FUNCTION : 동부apI 로부터 데이터 수신
// RETURN   : 
//=======================================================================================
BOOL CExOrderDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
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

	if ( strcmp(szTrCode, TR_20030 ) == 0      //선옵 주문/주식선옵
	   ||  strcmp(szTrCode, TR_20020 ) == 0    //주식
	   ||  strcmp(szTrCode, TR_20001 ) == 0 )  //CME 주문
	{
		CString szData = (LPCTSTR)prData->TRData ;
		
		TR_ORDER_OS * pTR = (TR_ORDER_OS*)(LPCTSTR)szData.Mid(SZ_ORDER_O);

		//주문시에 입력했던 키값
		int nTrIndex = theApp.gatoi(pTR->clikey, sizeof(pTR->clikey));

		//주문이 성공적으로 이루어지면 주문번호가 0이상이어야함
		int nOrderNo = theApp.gatoi(pTR->juno, sizeof(pTR->juno));

		if ( nOrderNo <= 0) //주문오류 메시지
		{
			strMsg= "주문 결과 >>" + strMsg ;
		}
		else
		{
			//메시지
			strMsg.Format( "%.*s", sizeof(pTR->msgcm), pTR->msgcm ) ;
			strMsg= "주문 결과 >>" + strMsg ;
		}
		

		m_lstMsg.InsertString( 0, strMsg );			
		
		//*********************************
		//화면에 맞게 데이터를 처리
		//*********************************
	}
	
	return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
}

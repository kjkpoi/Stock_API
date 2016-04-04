// ExOrderDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "DongbuAPIClient_VC.h"
#include "ExOrderDlg.h"


// CExOrderDlg ��ȭ �����Դϴ�.

#include "include_cme/TR20001.h"
#include "include_fo/TR20030.h"
#include "include_sk/TR20020.h"

#define		DEF_ORDER_MEDO		1
#define		DEF_ORDER_MESU		2
#define		DEF_ORDER_MODIFY	3
#define		DEF_ORDER_CANCEL	4


IMPLEMENT_DYNAMIC(CExOrderDlg, CDialog)


//------------------------------------------------------------------------------------------
// �ֹ����� ���� INPUT HEADER & OUTPUT STRUCTURES
//------------------------------------------------------------------------------------------
typedef struct _TRORDER_I
{
	char    incnt    [ 4];      /* �ֹ� cnt					*/
	char    mapno    [ 5];      /* TR����ϴ� Map��ȣ		*/
} TR_ORDER_I;

typedef struct _TRORDER_O
{
	char    outcnt   [ 4];       /* �ֹ� cnt                */
} TR_ORDER_O;

#define SZ_ORDER_O     sizeof(TR_ORDER_O)

typedef struct _TRORDER_OS
{
	char	clikey   [ 8];      /* �ֹ� key                  */
	char    juno     [ 9];      /* �ֹ���ȣ                  */
	char    msgcd    [ 6];      /* �޽����ڵ�                */
	char    msgcm   [100];      /* ó���޽���                */
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


// CExOrderDlg �޽��� ó�����Դϴ�.

BOOL CExOrderDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();


	switch (m_nProduct)
	{
	case ID_PRODUCT_CME :
		//����Ÿ��
		m_cmbPriceType.AddString("00:������");
		m_cmbPriceType.AddString("10:������(IOC)");
		m_cmbPriceType.AddString("20:������(FOK)");
		m_cmbPriceType.SetCurSel(0);
		break;

	case ID_PRODUCT_SK :		
		m_cmbPriceType.AddString("00:������");
		m_cmbPriceType.AddString("03:���尡");
		m_cmbPriceType.AddString("05:���Ǻ�������");
		m_cmbPriceType.AddString("06:������������");
		m_cmbPriceType.AddString("07:�ֿ켱������");
		m_cmbPriceType.AddString("10:������(IOC)");
		m_cmbPriceType.AddString("13:���尡(IOC)");
		m_cmbPriceType.AddString("16:������������(IOC)");
		m_cmbPriceType.AddString("20:������(FOK)");
		m_cmbPriceType.AddString("23:���尡(FOK)");
		m_cmbPriceType.AddString("26:������������(FOK)");
		m_cmbPriceType.AddString("61:�����ð���");
		m_cmbPriceType.AddString("81:���Ľð���");
		m_cmbPriceType.AddString("09:�ڻ���");

		m_cmbPriceType.SetCurSel(0);
		break;

	default:
		m_cmbPriceType.AddString("00:������");
		m_cmbPriceType.AddString("03:���尡");
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
	case ID_PRODUCT_FO :		//����	
		nPrice = int( (atof(m_strPrice)*100) + 0.005 ) ;	 //round off error �߻��� �� ����.
		MakePacket(TR_20030, nOrdSect, nPrice);
		break;
	case ID_PRODUCT_SFO :		//�ֽļ���
		nPrice = atoi(m_strPrice) ;
		MakePacket_SK(TR_20030, nOrdSect, nPrice);
		break;
	case ID_PRODUCT_CME :		//CME����
		nPrice = int( (atof(m_strPrice)*100) + 0.005 ) ;	 //round off error �߻��� �� ����.	
		MakePacket(TR_20001, nOrdSect, nPrice);
		break;

	case ID_PRODUCT_SK :		//�ֽ�
		nPrice = atoi(m_strPrice) ;
		MakePacket_SK(TR_20020, nOrdSect, nPrice);
		break;	
	}	
}

//=======================================================================================
// FUNCTION : ����api�� �ֹ�
//            ����/CME����/�ֽļ��� �ֹ�(TR_20001_IS /TR_20030_IS) INPUT I/O�� ����
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
		
	int nClientKey = 7000;							//������ ����
	int nOrgOrdNo = atoi(m_strOrgOrderNo) ;			//���ֹ���ȣ
	int nQty = atoi(m_strQty);	

	CString szPriceType ;	
	m_cmbPriceType.GetLBText(m_cmbPriceType.GetCurSel(), szPriceType);	
	int nPriceType = atoi(szPriceType.Left(2)) ;

	//CME�����ϰ�� ����/����ϰ�� ���������θ� �ֹ� ����
	if ( m_nProduct == ID_PRODUCT_CME)
	{
		if ( nOrdSect == 3 || nOrdSect == 4 )
			nPriceType = 0 ;

		//��Ҵ� �������(0)���θ� �����ϴ�
		if ( nOrdSect == 4 )
			nQty = 0;
	}
	
	int nSize = sizeof(TR_20001_IS) ;
	memset(&tr_input, 0x20, sizeof(TR_20001_IS));  //�����̽��� ä��

	CString strTemp;

	// �ֹ� Key			: clikey   [ 8]
	nLen = sizeof(tr_input.clikey);
	strTemp.Format("%0*d", nLen, nClientKey);
	memcpy(tr_input.clikey	, (LPSTR)(LPCTSTR)strTemp, nLen);


	// �ֹ�����			: gb       [ 1]		1:�ŵ�, 2:�ż�, 3:����, 4:���
	nLen = sizeof(tr_input.gb);
	strTemp.Format("%0*d", nLen, nOrdSect);
	memcpy(tr_input.gb	, (LPSTR)(LPCTSTR)strTemp, nLen);

	// ���¹�ȣ			: geja     [11->20]
	nLen = sizeof(tr_input.geja);	
	szAccount.Remove('-'); szAccount.Remove('_'); szAccount.Remove(' ');
	strTemp.Format("%-*.*s", nLen, nLen, szAccount);
	memcpy(tr_input.geja	, (LPSTR)(LPCTSTR)strTemp	, nLen);

	// ��й�ȣ			: passwd   [ 8]
	nLen = sizeof(tr_input.passwd);
	strTemp.Format("%-*.*s", nLen, nLen, szPwd);
	memcpy(tr_input.passwd	, (LPSTR)(LPCTSTR)strTemp	, nLen);

	// �����ڵ�			: code     [15]
	nLen = sizeof(tr_input.code);
	strTemp.Format("%-*.*s", nLen, nLen, szJongmok);
	memcpy(tr_input.code	, (LPSTR)(LPCTSTR)strTemp, nLen);

	// ���ֹ���ȣ		: wonno    [ 7->9]
	nLen = sizeof(tr_input.wonno);
	strTemp.Format("%0*d", nLen, nOrgOrdNo);
	memcpy(tr_input.wonno, (LPSTR)(LPCTSTR)strTemp	, nLen);

	// �ֹ�����			: jutype   [ 1->2]		00:������ 03:���尡 05:���Ǻ������� 06:������������
	CString strPriceType ;
	nLen = sizeof(tr_input.jutype);	
	strPriceType.Format("%02d", nPriceType);
	memcpy(tr_input.jutype	, (LPSTR)(LPCTSTR)strPriceType, nLen);

	// �ֹ� ����		: juprc    [10->12]
	if(nPrice <= 0)
	{
		if ( strPriceType == "03" || strPriceType == "06" // ���尡,  ������ ������
			|| szJongmok.Left(1) == "4"	// ��������
			|| nOrdSect == 4			// ����ֹ�
			) {}
		else
		{
			AfxMessageBox("�ֹ������� �ùٸ��� �ʽ��ϴ�!") ;
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

	// �ֹ� ����		: qty      [ 7->15]
	nLen = sizeof(tr_input.qty);	
	strTemp.Format("%0*d", nLen, nQty);
	memcpy(tr_input.qty	, (LPSTR)(LPCTSTR)strTemp	, nLen);

	// Ŭ���̾�Ʈ IP	: ip       [12]		(199.99.9.90->199099009090)
	/*nLen = sizeof(tr_input.ip);
	strTemp.Format("%-*.*s", nLen, nLen, "");
	memcpy(tr_input.ip		, (LPSTR)(LPCTSTR)strTemp	, nLen);*/

	nLen = sizeof(TR_20001_IS) ;
	szInput.Format("000100000%-*.*s", nLen , nLen, (LPCTSTR)&tr_input );

	theApp.SendToServerEx (DRCM_SENDDATA, szTrNo, szInput, m_hWnd);		
}


//=======================================================================================
// FUNCTION : ����api�� �ֽ� �ֹ�
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
		
	int nClientKey = 7000;							//������ ����
	int nOrgOrdNo = atoi(m_strOrgOrderNo) ;			//���ֹ���ȣ
	int nQty = atoi(m_strQty);	

	CString szPriceType ;	
	m_cmbPriceType.GetLBText(m_cmbPriceType.GetCurSel(), szPriceType);	
	int nPriceType = atoi(szPriceType.Left(2)) ;
	
	int nSize = sizeof(TR_20020_IS) ;
	memset(&tr_input, 0x20, sizeof(TR_20020_IS));  //�����̽��� ä��

	CString strTemp;

	// �ֹ� Key			: clikey   [ 8]
	nLen = sizeof(tr_input.clikey);
	strTemp.Format("%0*d", nLen, nClientKey);
	memcpy(tr_input.clikey	, (LPSTR)(LPCTSTR)strTemp, nLen);


	// �ֹ�����			: gb       [ 1]		1:�ŵ�, 2:�ż�, 3:����, 4:���
	nLen = sizeof(tr_input.gb);
	strTemp.Format("%0*d", nLen, nOrdSect);
	memcpy(tr_input.gb	, (LPSTR)(LPCTSTR)strTemp, nLen);

	// ���¹�ȣ			: geja     [11->20]
	nLen = sizeof(tr_input.geja);	
	szAccount.Remove('-'); szAccount.Remove('_'); szAccount.Remove(' ');
	strTemp.Format("%-*.*s", nLen, nLen, szAccount);
	memcpy(tr_input.geja	, (LPSTR)(LPCTSTR)strTemp	, nLen);

	// ��й�ȣ			: passwd   [ 8]
	nLen = sizeof(tr_input.passwd);
	strTemp.Format("%-*.*s", nLen, nLen, szPwd);
	memcpy(tr_input.passwd	, (LPSTR)(LPCTSTR)strTemp	, nLen);

	// �����ڵ�			: code     [15]
	nLen = sizeof(tr_input.code);
	strTemp.Format("%-*.*s", nLen, nLen, szJongmok);
	memcpy(tr_input.code	, (LPSTR)(LPCTSTR)strTemp, nLen);

	// ���ֹ���ȣ		: wonno    [ 7->9]
	nLen = sizeof(tr_input.wonno);
	strTemp.Format("%0*d", nLen, nOrgOrdNo);
	memcpy(tr_input.wonno, (LPSTR)(LPCTSTR)strTemp	, nLen);

	// �ֹ�����			: jutype   [ 1->2]		00:������ 03:���尡 05:���Ǻ������� 06:������������
	CString strPriceType ;
	nLen = sizeof(tr_input.jutype);	
	strPriceType.Format("%02d", nPriceType);
	memcpy(tr_input.jutype	, (LPSTR)(LPCTSTR)strPriceType, nLen);

	// �ֹ� ����		: juprc    [10->12]
	if(nPrice <= 0)
	{
		if ( strPriceType == "03" || strPriceType == "06" // ���尡,  ������ ������
			|| strPriceType == "13" || strPriceType == "16" //ioc(���尡,  ������ ������)
			|| strPriceType == "23" || strPriceType == "26" //fok(���尡,  ������ ������)
			|| szJongmok.Left(1) == "4"	// ��������
			|| nOrdSect == 4			// ����ֹ�
			) {}
		else
		{
			AfxMessageBox("�ֹ������� �ùٸ��� �ʽ��ϴ�!") ;
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

	// �ֹ� ����		: qty      [ 7->15]
	nLen = sizeof(tr_input.qty);	
	strTemp.Format("%0*d", nLen, nQty);
	memcpy(tr_input.qty	, (LPSTR)(LPCTSTR)strTemp	, nLen);

	//�ſ뱸��	
	nLen = sizeof(tr_input.zMgntrnCode);
	strTemp.Format("%0*d", nLen, 0);
	memcpy(tr_input.zMgntrnCode, (LPSTR)(LPCTSTR)strTemp	, nLen);

	//��������	
	nLen = sizeof(tr_input.zLoanDt);
	strTemp.Format("%0*d", nLen, 0);
	memcpy(tr_input.zLoanDt, (LPSTR)(LPCTSTR)strTemp	, nLen);


	// Ŭ���̾�Ʈ IP	: ip       [12]		(199.99.9.90->199099009090)
	/*nLen = sizeof(tr_input.ip);
	strTemp.Format("%-*.*s", nLen, nLen, "");
	memcpy(tr_input.ip		, (LPSTR)(LPCTSTR)strTemp	, nLen);*/

	nLen = sizeof(TR_20020_IS) ;
	szInput.Format("000100000%-*.*s", nLen , nLen, (LPCTSTR)&tr_input );

	theApp.SendToServerEx (DRCM_SENDDATA, szTrNo, szInput, m_hWnd);		
}

//=======================================================================================
// FUNCTION : ����apI �κ��� ������ ����
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

	if ( strcmp(szTrCode, TR_20030 ) == 0      //���� �ֹ�/�ֽļ���
	   ||  strcmp(szTrCode, TR_20020 ) == 0    //�ֽ�
	   ||  strcmp(szTrCode, TR_20001 ) == 0 )  //CME �ֹ�
	{
		CString szData = (LPCTSTR)prData->TRData ;
		
		TR_ORDER_OS * pTR = (TR_ORDER_OS*)(LPCTSTR)szData.Mid(SZ_ORDER_O);

		//�ֹ��ÿ� �Է��ߴ� Ű��
		int nTrIndex = theApp.gatoi(pTR->clikey, sizeof(pTR->clikey));

		//�ֹ��� ���������� �̷������ �ֹ���ȣ�� 0�̻��̾����
		int nOrderNo = theApp.gatoi(pTR->juno, sizeof(pTR->juno));

		if ( nOrderNo <= 0) //�ֹ����� �޽���
		{
			strMsg= "�ֹ� ��� >>" + strMsg ;
		}
		else
		{
			//�޽���
			strMsg.Format( "%.*s", sizeof(pTR->msgcm), pTR->msgcm ) ;
			strMsg= "�ֹ� ��� >>" + strMsg ;
		}
		

		m_lstMsg.InsertString( 0, strMsg );			
		
		//*********************************
		//ȭ�鿡 �°� �����͸� ó��
		//*********************************
	}
	
	return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
}

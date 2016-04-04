// ExOrderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dongbuapiclient.h"
#include "ExOrderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExOrderDlg dialog


CExOrderDlg::CExOrderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExOrderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExOrderDlg)
	m_strAcctPwd = _T("");
	m_strJongmok = _T("301G1215");
	m_strPrice = _T("0.88");
	m_strQty = _T("1");
	m_strAccount = _T("");
	//}}AFX_DATA_INIT
}

void CExOrderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExOrderDlg)
	DDX_Control(pDX, IDC_LIST, m_lstMsg);
	DDX_Control(pDX, IDC_CMB_PRICETYPE, m_cmbPriceType);
	DDX_Text(pDX, IDC_EDT_ACCTPWD, m_strAcctPwd);	
	DDX_Text(pDX, IDC_EDT_JONGMOK, m_strJongmok);
	DDX_Text(pDX, IDC_EDT_PRICE, m_strPrice);
	DDX_Text(pDX, IDC_EDT_QTY, m_strQty);
	DDX_Text(pDX, IDC_EDT_ACCOUNT, m_strAccount);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CExOrderDlg, CDialog)
	//{{AFX_MSG_MAP(CExOrderDlg)
		ON_BN_CLICKED(IDC_BTN_ABLEQTY, OnBtnAbleqty)
	ON_BN_CLICKED(IDC_BTN_ORDER, OnBtnOrder)
	ON_WM_COPYDATA()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExOrderDlg message handlers


BOOL CExOrderDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
		
	//����Ÿ��
	m_cmbPriceType.AddString("00:������");
	m_cmbPriceType.AddString("03:���尡");
	m_cmbPriceType.SetCurSel(0);

	CButton *pMesu = (CButton *)(GetDlgItem(IDC_RADIO_MESU));
	pMesu->SetCheck(1);


	CString szText ;
	switch ( m_nTRCode)
	{
	case 14051 : 	
		szText.Format("�ű�/û�갡�� ���� %d]", m_nTRCode) ;
		GetDlgItem(IDC_STATIC_QTY)->ShowWindow(SW_HIDE) ;
		GetDlgItem(IDC_EDT_QTY)->ShowWindow(SW_HIDE) ;	
		GetDlgItem(IDC_BTN_ORDER)->ShowWindow(SW_HIDE) ;
		GetDlgItem(IDC_BTN_ABLEQTY)->ShowWindow(SW_SHOW) ;
		break;
	case 20000 : 
		szText.Format("�ֹ�����[TR Code %d]", m_nTRCode) ;	
		GetDlgItem(IDC_STATIC_QTY)->ShowWindow(SW_SHOW) ;
		GetDlgItem(IDC_EDT_QTY)->ShowWindow(SW_SHOW) ;
		GetDlgItem(IDC_BTN_ORDER)->ShowWindow(SW_SHOW) ;
		GetDlgItem(IDC_BTN_ABLEQTY)->ShowWindow(SW_HIDE) ;
		
		
		break;
	}

	SetWindowText(szText) ;
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CExOrderDlg::OnBtnAbleqty() 
{
	UpdateData (TRUE) ;

	int nLen = 0 ;
	CString szPwd = m_strAcctPwd ;
	CString szAccount = m_strAccount ; 
	CString szJongmok = m_strJongmok;
	CString szInput ;
	CString szPrice ;	
	CString szIP = theApp.g_szMyIP;

	long nPrice = int(atof(m_strPrice) *100.0) ;
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
	memcpy ( stInput.gb, szGubun, 1 ) ;								//�Ÿű���  1:�ŵ� 2:�ż�
	memcpy ( stInput.price, szPrice, szPrice.GetLength() ) ;
	memcpy ( stInput.ord_type, szPriceType.Left(2), 2 ) ;		//�ֹ�����
	memcpy ( stInput.zLqdtQtyQryTp, "1", 1 ) ;					//û����� ��ȸ���� : ���δ� 1	
	memcpy ( stInput.ip, szIP, szIP.GetLength()) ;

	nLen = sizeof(stInput) ;
	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);
	theApp.SendToServerEx(DRCM_SENDDATA, TR_14051, szInput, m_hWnd);	
}

void CExOrderDlg::OnBtnOrder() 	
{
	UpdateData (TRUE) ;

	TR_20000_IS tr_input ;

	int nLen = 0 ;
	CString szPwd = m_strAcctPwd ;
	CString szAccount = m_strAccount ; 
	CString szJongmok = m_strJongmok;
	CString szInput ;
	CString szPrice ;

	CString szIP = theApp.g_szMyIP;
	int nClientKey = 7000;
	int nOrgOrdNo = 0 ; //���ֹ���ȣ
	int nQty = atoi(m_strQty);

	long nPrice = int(atof(m_strPrice) *100.0) ;
	szPrice.Format("%d", nPrice) ;

	CButton *pMesu = (CButton *)(GetDlgItem(IDC_RADIO_MESU));
	CString szGubun = pMesu->GetCheck() ? "2" :"1";
	int nOrdSect = atoi (szGubun) ;
	
	CString szPriceType ;	
	m_cmbPriceType.GetLBText(m_cmbPriceType.GetCurSel(), szPriceType);	
	int nPriceType = atoi(szPriceType) ;
	
	int nSize = sizeof(TR_20000_IS) ;
	memset(&tr_input, 0x20, sizeof(TR_20000_IS));

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
			|| nOrdSect == 4				// ����ֹ�
			) {}
		else
			return  ;
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
	nLen = sizeof(tr_input.ip);
	strTemp.Format("%-*.*s", nLen, nLen, szIP);
	memcpy(tr_input.ip		, (LPSTR)(LPCTSTR)strTemp	, nLen);
	
	nLen = sizeof(TR_20000_IS) ;
	szInput.Format("000100000%-*.*s", nLen , nLen, (LPCTSTR)&tr_input );
	theApp.SendToServerEx (DRCM_SENDDATA, TR_20000, szInput, m_hWnd);		
}

BOOL CExOrderDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
{
	COPYDATASTRUCT* pCDS = pCopyDataStruct ;

	int nDataType = (int)pCDS->dwData ;

	STTRHEADER* prData = (STTRHEADER*)pCDS->lpData;
	char szTrCode[5+1] ={0,} ;
	char szMsg[82+1] ={0,} ;
	CString strMsg  ;

	switch (nDataType)
	{
		case DRCM_DISCONNECT : //DRCM �� ����ɶ� ���� �޽���			
			break;
		case DRCM_CLIENT_IP :  //client ip						
			break ;
		case DRCM_F_ACCLIST :  //get future account list						
			break ;
		case DRCM_DRDS_DATA :  //�ǽð� ����Ÿ			
			break;
		default :						
			memcpy(szTrCode, prData->TRCode, 5 ) ;
			memcpy(szMsg, prData->Message, 82) ;

			strMsg = szMsg ;
			strMsg.TrimRight() ;
			
			if ( strcmp(szTrCode, TR_20000 ) == 0 )
			{	
				CString szData = (LPCTSTR)prData->TRData ;
				
				strMsg= "�ֹ� >>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );			
				UpdateData(FALSE) ;
			}
			else if ( strcmp(szTrCode, TR_14051 ) == 0 ) //�ű�/û�� ���ɼ���
			{					
				TR_14051_O* pData = (TR_14051_O*)prData->TRData;	
				
				strMsg= "�ű�/û�� ���ɼ��� >>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
						
				UpdateData(FALSE) ;
			}
		
			
			break ;	
	}
	return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
}

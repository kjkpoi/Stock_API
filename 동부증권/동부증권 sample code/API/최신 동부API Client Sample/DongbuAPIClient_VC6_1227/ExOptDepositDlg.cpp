// ExOptDepositDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dongbuapiclient.h"
#include "ExOptDepositDlg.h"

#include "DongbuAPIClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExOptDepositDlg dialog

CExOptDepositDlg::CExOptDepositDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExOptDepositDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExOptDepositDlg)
	//}}AFX_DATA_INIT
}

void CExOptDepositDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExOptDepositDlg)
	DDX_Control(pDX, IDC_LIST, m_lstMsg);
	DDX_Control(pDX, IDC_CMB_MONTH, m_cmbMonth);
	DDX_Control(pDX, IDC_CMB_ITEM, m_cmbItem);
	DDX_Control(pDX, IDC_CMB_BASEASSET, m_cmbBaseAsset);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CExOptDepositDlg, CDialog)
	//{{AFX_MSG_MAP(CExOptDepositDlg)	
	ON_BN_CLICKED(IDC_BTN_INQURY, OnBtnInqury)
	ON_CBN_SELCHANGE(IDC_CMB_ITEM, OnSelchangeCmbItem)
	ON_WM_COPYDATA()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExOptDepositDlg message handlers


BOOL CExOptDepositDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_cmbItem.AddString("00전체"    );
    m_cmbItem.AddString("01주가지수");
    m_cmbItem.AddString("02개별주식");
    m_cmbItem.AddString("03가공채권");
    m_cmbItem.AddString("04통화"    );
    m_cmbItem.AddString("05상품"    );
    m_cmbItem.AddString("06금리"    );

	m_cmbBaseAsset.AddString("000전체");

	m_cmbMonth.AddString("0전체    ");
    m_cmbMonth.AddString("1(1월물) ");
    m_cmbMonth.AddString("2(2월물) ");
    m_cmbMonth.AddString("3(3월물) ");
    m_cmbMonth.AddString("4(4월물) ");
    m_cmbMonth.AddString("5(5월물) ");
    m_cmbMonth.AddString("6(6월물) ");
    m_cmbMonth.AddString("7(7월물) ");
    m_cmbMonth.AddString("8(8월물) ");
    m_cmbMonth.AddString("9(9월물) ");
    m_cmbMonth.AddString("A(10월물)");
    m_cmbMonth.AddString("B(11월물)");
    m_cmbMonth.AddString("C(12월물)");
	

	m_cmbItem.SetCurSel(0);
	m_cmbBaseAsset.SetCurSel(0);
	m_cmbMonth.SetCurSel(0);
		
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void CExOptDepositDlg::OnSelchangeCmbItem() 
{
	int nSelIdx = m_cmbItem.GetCurSel();

	m_cmbBaseAsset.ResetContent();
	m_cmbBaseAsset.AddString("000전체");

	if ( nSelIdx ==1 )
	{	
		m_cmbBaseAsset.AddString("501KOSPI200");
		m_cmbBaseAsset.AddString("503STAR30");
	}
	else if ( nSelIdx  > 1 )
	{
		 m_cmbBaseAsset.AddString("510국민은행"     );
		 m_cmbBaseAsset.AddString("511삼성전자"     );
		 m_cmbBaseAsset.AddString("512SK텔레콤"     );
		 m_cmbBaseAsset.AddString("513포항제철"     );
		 m_cmbBaseAsset.AddString("514KT"           );
		 m_cmbBaseAsset.AddString("515한국전력공사" );
		 m_cmbBaseAsset.AddString("516현대자동차"   );
		 m_cmbBaseAsset.AddString("517삼성증권"     );
		 m_cmbBaseAsset.AddString("518신한지주"     );
		 m_cmbBaseAsset.AddString("519기아차"       );
		 m_cmbBaseAsset.AddString("520현대모비스"   );
		 m_cmbBaseAsset.AddString("521삼성물산"     );
		 m_cmbBaseAsset.AddString("522삼성SDI"      );
		 m_cmbBaseAsset.AddString("523삼성전기"     );
		 m_cmbBaseAsset.AddString("524LG전자"       );
		 m_cmbBaseAsset.AddString("525LG화학"       );
		 m_cmbBaseAsset.AddString("526대한항공"     );
		 m_cmbBaseAsset.AddString("527한진해운"     );
		 m_cmbBaseAsset.AddString("528한국가스"     );
		 m_cmbBaseAsset.AddString("529강원랜드"     );
		 m_cmbBaseAsset.AddString("530삼성화재"     );
		 m_cmbBaseAsset.AddString("531CJ"           );
		 m_cmbBaseAsset.AddString("532INI스틸"      );
		 m_cmbBaseAsset.AddString("533SK"           );
		 m_cmbBaseAsset.AddString("534LG"           );
		 m_cmbBaseAsset.AddString("535GS"           );     
		 m_cmbBaseAsset.AddString("536케이티엔지"   );                              
		 m_cmbBaseAsset.AddString("538한국타이어"   );                              
		 m_cmbBaseAsset.AddString("539현대중공업"   );                              
		 m_cmbBaseAsset.AddString("540하나금융지주" ); 
	}
	
	m_cmbBaseAsset.SetCurSel(0);
}

void CExOptDepositDlg::OnBtnInqury() 
{
	UpdateData (TRUE) ;

	int nLen = 0 ;
	CString szItem;
	CString szBaseAsset;
	CString szMonth ;
	CString szInput ;
	CString szIP = theApp.g_szMyIP;
	CString szNextKey = m_szNextKey ; 
	
	m_cmbItem.GetLBText(m_cmbItem.GetCurSel(), szItem);	
	m_cmbBaseAsset.GetLBText(m_cmbMonth.GetCurSel(), szBaseAsset);
	m_cmbMonth.GetLBText(m_cmbMonth.GetCurSel(), szMonth);

	TR_16260_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_16260_I)) ;
	memcpy ( stInput.itemcode, szItem.Left(2), 2) ;
	memcpy ( stInput.baseassetcode, szBaseAsset.Left(3), 3 ) ;
	memcpy ( stInput.month, szMonth.Left(1), 1 ) ;			
	memcpy ( stInput.ip_addr, szIP, szIP.GetLength()) ;	
	
	if (szNextKey.IsEmpty())
		szNextKey.Format("%0*d", sizeof(stInput.nxtKey), 0);
	memcpy ( stInput.nxtKey, szNextKey, szNextKey.GetLength()) ;

	nLen = sizeof(stInput) ;
	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);
	theApp.SendToServerEx (DRCM_SENDDATA, TR_16260, szInput, m_hWnd);	


	if (szNextKey.IsEmpty())
	{
		m_lstMsg.ResetContent() ;
		UpdateData(FALSE) ;
	}
}

BOOL CExOptDepositDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
{
	COPYDATASTRUCT* pCDS = pCopyDataStruct ;

	int nDataType = (int)pCDS->dwData ;
	
	STTRHEADER* prData = (STTRHEADER*)pCDS->lpData;
	char szTrCode[5+1] ={0,} ;
	char szMsg[82+1] ={0,} ;
	CString strMsg  ;

	int nLen = 0;

	switch (nDataType)
	{
		case DRCM_DISCONNECT : //DRCM 이 종료될때 오는 메시지			
			break;
		case DRCM_CLIENT_IP :  //client ip						
			break ;
		case DRCM_F_ACCLIST :  //get future account list						
			break ;
		case DRCM_DRDS_DATA :  //실시간 데이타			
			break;
		default :						
			memcpy(szTrCode, prData->TRCode, 5 ) ;
			memcpy(szMsg, prData->Message, 82) ;
		
			if ( strcmp(szTrCode, TR_16260 ) == 0 )
			{						
				int nSZ_HEADER = 40 ;
				int nOffset = nSZ_HEADER ;
				int nSZ_16260 = sizeof(TR_16260_OS);
				CString szCount, szData, szHeader, szNextFlag, szNextKey ;

				char szTmp[40] = {0x00,};
				memcpy(szTmp, (char*)prData->TRData, nSZ_HEADER-1);
				for ( int i = 0; i < nSZ_HEADER; i++)
				{
					if (szTmp[i] == NULL)
						szTmp[i] = ' ' ;
				}
				szHeader.Format("%*.*s",nSZ_HEADER, nSZ_HEADER, szTmp);
				szNextFlag = szHeader.Mid(szHeader.Find("EN=") + 3, 1) ;
				szNextKey = szHeader.Mid(szHeader.Find("DT=") + 3, 18) ;
				szCount = szHeader.Mid(28,4 ) ;

				 //연속키
				if ( atoi(szNextFlag) == 1) 
				{
					m_szNextKey.Format("%s%s", szNextFlag, szNextKey) ;
				}
				
				//데이터
				for (int i = 0; i < atoi(szCount); i++)
				{
					TR_16260_OS* pData = (TR_16260_OS*)(prData->TRData+nOffset);
													
					szData.Format("%02d : 행사가 %13.13s",i, pData->exeprice );
					m_lstMsg.InsertString( 0, szData );					
					nOffset += nSZ_16260 ;
				}
			}

			strMsg = szMsg ;
			strMsg.TrimRight() ;
			m_lstMsg.InsertString( 0, strMsg );
			
			break ;	
	}
	return CDialog::OnCopyData(pWnd, pCopyDataStruct);
}

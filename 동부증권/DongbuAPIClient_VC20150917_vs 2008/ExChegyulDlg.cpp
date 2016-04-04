// ExChegyulDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "DongbuAPIClient_VC.h"
#include "ExChegyulDlg.h"


// CExChegyulDlg 대화 상자입니다.

#include "include_cme/TR20111.h"
#include "include_cme/DrdsXF5.h"

//#include "include_fo/TR13615.h"
#include "include_fo/TR13616.h"
#include "include_fo/DrdsXF2.h"

#include "include_SK/TR13118.h"
#include "include_SK/DrdsXX1.h"


IMPLEMENT_DYNAMIC(CExChegyulDlg, CDialog)

CExChegyulDlg::CExChegyulDlg(CWnd* pParent /*=NULL*/)
: CDialog(CExChegyulDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExChegyulDlg)
	m_strAccount = theApp.g_strAccount;
	m_strAcctPwd =  theApp.g_strAcctPwd;		
	//}}AFX_DATA_INIT
}

CExChegyulDlg::~CExChegyulDlg()
{
}

void CExChegyulDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CExChegyulDlg)
	DDX_Control(pDX, IDC_LIST,			m_lstMsg);	
	DDX_Text(pDX, IDC_EDT_ACCOUNT,		m_strAccount);
	DDX_Text(pDX, IDC_EDT_ACCTPWD,		m_strAcctPwd);		
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExChegyulDlg, CDialog)

	ON_WM_COPYDATA()
	ON_BN_CLICKED(IDC_BTN_INQUERY, OnBtnInquery)
	ON_BN_CLICKED(IDC_CHK_REALTIME, OnBtnRequestRealtimeData)
	ON_BN_CLICKED(IDC_BTN_INQUERY_NEXT, &CExChegyulDlg::OnBnClickedBtnInqueryNext)
END_MESSAGE_MAP()


// CExChegyulDlg 메시지 처리기입니다.

BOOL CExChegyulDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	SetWindowText("체결 내역 조회") ;

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

//=======================================================================================
// FUNCTION : 실시간 데이터 요청
// RETURN   : 
//=======================================================================================
void CExChegyulDlg::OnBtnRequestRealtimeData()
{
	BOOL bAdvise = ((CButton *)GetDlgItem(IDC_CHK_REALTIME))->GetCheck() ;
	int nAdvise = bAdvise ? DRCM_ADVICE : DRCM_UNADVICE ;

	switch (m_nProduct)
	{
	// 선물옵션	체결	
	case ID_PRODUCT_FO :
		theApp.SendToServerEx (nAdvise, R_XF2, theApp.g_szId, m_hWnd );	
		break;

	case ID_PRODUCT_CME : //CME선물	체결	
		theApp.SendToServerEx (nAdvise, R_XF5, theApp.g_szId, m_hWnd );	
		break;

	// 주식	체결	
	case ID_PRODUCT_SK :
		theApp.SendToServerEx (nAdvise, R_XX1, theApp.g_szId, m_hWnd );	
		break;
	}	
}

//=======================================================================================
// FUNCTION : 다음데이터 조회
// RETURN   : 
//=======================================================================================
void CExChegyulDlg::OnBnClickedBtnInqueryNext()
{
	GetDlgItem(IDC_BTN_INQUERY_NEXT)->EnableWindow(FALSE);

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
// FUNCTION : 조회
// RETURN   : 
//=======================================================================================
void CExChegyulDlg::OnBtnInquery()
{
	GetDlgItem(IDC_BTN_INQUERY_NEXT)->EnableWindow(FALSE);
	m_szNextKey ="";

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
// FUNCTION : 동부api에 데이터 요청(CME선물)
// RETURN   : 
//=======================================================================================
void CExChegyulDlg::MakePacket_CME()
{
	UpdateData (TRUE) ;
	
	CString szAccount = m_strAccount ; 	
	CString szPwd = m_strAcctPwd ;
	CString szInput ;
	
	szAccount.TrimLeft() ;
	szAccount.TrimRight() ;
	szAccount.Remove('-');

	TR_20111_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_20111_I)) ;
	memcpy ( stInput.geja, szAccount, szAccount.GetLength() ) ;
	memcpy ( stInput.passwd, szPwd, szPwd.GetLength() ) ;
	memcpy ( stInput.sort, "2", 1 ) ;	//정순(1) 역순(2)  

	int nLen = sizeof(stInput) ;
	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);				
	
	theApp.SendToServerEx (DRCM_SENDDATA, TR_20111, szInput, m_hWnd);
}

//=======================================================================================
// FUNCTION : 동부api에 데이터 요청 (지수선옵, 주식선옵)
// RETURN   : 연속처리 안됨 
//=======================================================================================
//void CExChegyulDlg::MakePacket_FO()
//{
//	UpdateData (TRUE) ;
//
//	CString szAccount = m_strAccount ; 	
//	CString szPwd = m_strAcctPwd ;
//	CString szInput ;
//
//	szAccount.TrimLeft() ;
//	szAccount.TrimRight() ;
//	szAccount.Remove('-');
//
//	TR_13615_I stInput ;
//	memset (&stInput, 0x20, sizeof(TR_13615_I)) ;
//	memcpy ( stInput.geja, szAccount, szAccount.GetLength() ) ;
//	memcpy ( stInput.passwd, szPwd, szPwd.GetLength() ) ;
//	memcpy ( stInput.sort, "2", 1 ) ;	//정순(1) 역순(2)  
//
//	int nLen = sizeof(stInput) ;
//	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);				
//
//	theApp.SendToServerEx (DRCM_SENDDATA, TR_13615, szInput, m_hWnd);	
//}

//=======================================================================================
// FUNCTION : 동부api에 데이터 요청 (지수선옵, 주식선옵)
// RETURN   : 연속처리 가능한 TR
//=======================================================================================
void CExChegyulDlg::MakePacket_FO()
{
	UpdateData (TRUE) ;

	CString szAccount = m_strAccount ; 	
	CString szPwd = m_strAcctPwd ;
	CString szJongmok ;
	CString szNext ;
	CString szInput ;
	
	szAccount.TrimLeft() ;
	szAccount.TrimRight() ;
	szAccount.Remove('-');

	TR_13616_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_13616_I)) ;
	memcpy ( stInput.geja, szAccount, szAccount.GetLength() ) ;
	memcpy ( stInput.checkgb, "0", 1 ) ;	//조회구분 0:전체, 1:종목 
	//memcpy ( stInput.jgcode, szJongmok, szJongmok.GetLength() ) ; //종목코드 
	
	szNext.Format("%0*d", sizeof(stInput.nxtKey), atoi(m_szNextKey) );
	if ( atoi(m_szNextKey) == 0)	
		stInput.nxtGb[0] = '0';
	else
		stInput.nxtGb[0] = '1';	

	stInput.jugb[0] = '0'; /* 0전체 1매수 2매도                */
	memcpy(stInput.nxtKey, (LPSTR)(LPCTSTR)szNext, szNext.GetLength()) ;
		

	int nLen = sizeof(stInput) ;
	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);				

	theApp.SendToServerEx (DRCM_SENDDATA, TR_13616, szInput, m_hWnd);	


	m_szNextKey = "" ;
}

//=======================================================================================
// FUNCTION : 동부api에 데이터 요청 (주식)
// RETURN   : 
//=======================================================================================
void CExChegyulDlg::MakePacket_SK()
{
	UpdateData (TRUE) ;

	CString szAccount = m_strAccount ; 	
	CString szPwd = m_strAcctPwd ;
	CString szInput ;
	CString szNext ;

	szAccount.TrimLeft() ;
	szAccount.TrimRight() ;
	szAccount.Remove('-');

	TR_13118_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_13118_I)) ;
	memcpy ( stInput.geja, szAccount, szAccount.GetLength() ) ;
	memcpy ( stInput.sgb, "1", 1 ) ;  // 1:주문/체결 2:미체결		
	memcpy ( stInput.sort, "2", 1 ) ; //역순
	szNext.Format("%0*d", sizeof(stInput.next), 0 );
	
	if ( atoi(szNext) == 0)	
	{		
		memcpy ( stInput.ngbn, "0", 1 ) ;	
	}
	else
	{		
		memcpy ( stInput.ngbn, "1", 1 ) ;	
	}

	memcpy ( stInput.next, (LPCTSTR)szNext, szNext.GetLength() ) ;
	
	int nLen = sizeof(stInput) ;
	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);				

	theApp.SendToServerEx (DRCM_SENDDATA, TR_13118, szInput, m_hWnd);	
}


//=======================================================================================
// FUNCTION : 동부apI 로부터 데이터 수신
// RETURN   : 
//=======================================================================================
BOOL CExChegyulDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
{
	COPYDATASTRUCT* pCDS = pCopyDataStruct ;

	int nDataType = (int)pCDS->dwData ;	
	switch (nDataType)
	{	

	case DRCM_DRDS_DATA :  //실시간 데이타
		{
			DrdsData* pDrdsData = (DrdsData*)pCDS->lpData;

			//선옵 체결 실시간데이터
			if (memcmp(pDrdsData->Name, R_XF2, 3) == 0)
			{
				nDataType = eXF2 ;
				DRDS_XF2_DATA* pReal = (DRDS_XF2_DATA*)pDrdsData->Data;	
				//*********************************
				//화면에 맞게 데이터를 처리
				//*********************************
			}
			//CME선물 체결 실시간데이터
			else if (memcmp(pDrdsData->Name, R_XF5, 3) == 0)
			{
				nDataType = eXF5 ;
				DRDS_XF5_DATA* pReal = (DRDS_XF5_DATA*)pDrdsData->Data;	
				//*********************************
				//화면에 맞게 데이터를 처리
				//*********************************
			}

			//주식 체결 실시간데이터
			else if (memcmp(pDrdsData->Name, R_XX1, 3) == 0)
			{
				nDataType = eXX1 ;
				DRDS_XX1_DATA* pReal = (DRDS_XX1_DATA*)pDrdsData->Data;	

				CDRDS_XX1_DATA stRealData ;
				stRealData.Convert(pReal) ;

				CString strMsg ;
				strMsg= "주식 체결 실시간데이터 수신(주문번호) >>" + stRealData.m_szjuno;
				m_lstMsg.InsertString( 0, strMsg );

				//*********************************
				//화면에 맞게 데이터를 처리
				//*********************************
			}
			break ;	
		}			

	default: //조회 데이터
		{
			STTRHEADER* prData = (STTRHEADER*)pCDS->lpData;
			char szTrCode[5+1] ={0,} ;
			char szMsg[82+1] ={0,} ;
			CString strMsg  ;


			memcpy(szTrCode, prData->TRCode, 5 ) ;
			memcpy(szMsg, prData->Message, 82) ;

			strMsg = szMsg ;
			strMsg.TrimRight() ;

			//지수선옵 체결내역
			//	
			//}
			if ( strcmp(szTrCode, TR_13616 ) == 0 ) 
			{
				TR_13616_O* pData = (TR_13616_O*)prData->TRData;

				CTR_13616_O tr_13616_output;
				tr_13616_output.Convert(pData);
				if ( tr_13616_output.m_szNextFlag = "1")	
				{
					m_szNextKey = tr_13616_output.m_szNextVal ;
					GetDlgItem(IDC_BTN_INQUERY_NEXT)->EnableWindow(TRUE) ;
				}
				else
				{
					m_szNextKey = "" ;		
					GetDlgItem(IDC_BTN_INQUERY_NEXT)->EnableWindow(FALSE) ;
				}

				for(int i=0; i < tr_13616_output.m_ngridcnt; i++)
				{
					m_lstMsg.InsertString( 0, pData->grid[i].juno );
					//*********************************
					//화면에 맞게 데이터를 처리
					//*********************************
				}

				strMsg= "선옵 체결조회 결과>>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;
			}

			//CME선물 체결내역
			if ( strcmp(szTrCode, TR_20111 ) == 0 ) 
			{					
				TR_20111_O* pData = (TR_20111_O*)prData->TRData;

				int count = theApp.gatoi( pData->gridcnt, sizeof(pData->gridcnt) ) ;		
				for ( int i =0; i < count; i++)
				{											
				}

				strMsg= "CME선물 체결조회 결과>>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;

				//*********************************
				//화면에 맞게 데이터를 처리
				//*********************************
			}

			//주식 체결 내역
			if ( strcmp(szTrCode, TR_13118 ) == 0 )
			{								
				TR_13118_O* pData = (TR_13118_O*)prData->TRData;
				TR_13118_G* pGR = (TR_13118_G *)(pData->gr_DATA);
				int count = theApp.gatoi( pData->gr_cnt, sizeof(pData->gr_cnt) ) ;

				for ( int i =0; i < count; i++)
				{	
					TR_13118_G* pGridData = (TR_13118_G*)(&pGR[i]);

					//*********************************
					//화면에 맞게 데이터를 처리
					//*********************************
				}
				strMsg= "주식 체결조회 결과>>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;


			}

		}
	}

	return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
}


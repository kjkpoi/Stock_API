// ExJangoDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "DongbuAPIClient_VC.h"
#include "ExJangoDlg.h"


// CExJangoDlg 대화 상자입니다.

#include "include_cme/TR20110.h"
#include "include_fo/TR13655.h"
#include "include_sk/TR13148.h"
#include "include_sk/TR13147.h"

#include "include_cme/DrdsXF6.h"
#include "include_fo/DrdsXF3.h"
#include "include_sk/DrdsXX6.h"
#include "include_sk/DrdsXX9.h"

IMPLEMENT_DYNAMIC(CExJangoDlg, CDialog)

CExJangoDlg::CExJangoDlg(CWnd* pParent /*=NULL*/)
: CDialog(CExJangoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExJangoDlg)
	m_strAccount = theApp.g_strAccount;
	//}}AFX_DATA_INIT
}

CExJangoDlg::~CExJangoDlg()
{
}

void CExJangoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CExJangoDlg)
	DDX_Control(pDX, IDC_LIST,			m_lstMsg);	
	DDX_Text(pDX, IDC_EDT_ACCOUNT,		m_strAccount);	
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExJangoDlg, CDialog)

	ON_WM_COPYDATA()
	ON_BN_CLICKED(IDC_BTN_INQUERY,  OnBtnInquery)
	ON_BN_CLICKED(IDC_CHK_REALTIME, OnBtnRequestRealtimeData)	
END_MESSAGE_MAP()


// CExJangoDlg 메시지 처리기입니다.

BOOL CExJangoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CExJangoDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
{
	COPYDATASTRUCT* pCDS = pCopyDataStruct ;

	int nDataType = (int)pCDS->dwData ;	
	switch (nDataType)
	{	
	case DRCM_DRDS_DATA :  //실시간 데이타
		{
			CString strMsg ;
			DrdsData* pDrdsData = (DrdsData*)pCDS->lpData;

			//선옵 잔고 실시간데이터
			if (memcmp(pDrdsData->Name, R_XF3, 3) == 0)
			{
				nDataType = eXF3 ;
				DRDS_XF3_DATA* pReal = (DRDS_XF3_DATA*)pDrdsData->Data;	

				strMsg.Format("XF3 잔고 실시간 데이터 수신");
				m_lstMsg.InsertString( 0, strMsg );
				//*********************************
				//화면에 맞게 데이터를 처리
				//*********************************
			}
			//CME선물 잔고 실시간데이터
			else if (memcmp(pDrdsData->Name, R_XF6, 3) == 0)
			{
				nDataType = eXF6 ;
				DRDS_XF6_DATA* pReal = (DRDS_XF6_DATA*)pDrdsData->Data;	

				strMsg.Format("XF6 잔고 실시간 데이터 수신");
				m_lstMsg.InsertString( 0, strMsg );
				//*********************************
				//화면에 맞게 데이터를 처리
				//*********************************
				
			}
			//주식 잔고 실시간데이터
			else if (memcmp(pDrdsData->Name, R_XX6, 3) == 0)
			{
				nDataType = eXX6 ;
				DRDS_XX6_DATA* pReal = (DRDS_XX6_DATA*)pDrdsData->Data;	

				CDRDS_XX6_DATA stRealData ;
				stRealData.Convert(pReal) ;

				CString strMsg ;
				strMsg= "주식 잔고 실시간데이터 수신(종목코드) >>" + stRealData.m_szjgcode;
				m_lstMsg.InsertString( 0, strMsg );
				
			}
			//주식 잔고 실시간데이터(신용포함)
			else if (memcmp(pDrdsData->Name, R_XX9, 3) == 0)
			{
				nDataType = eXX9 ;
				DRDS_XX9_DATA* pReal = (DRDS_XX9_DATA*)pDrdsData->Data;	

				CDRDS_XX9_DATA stRealData ;
				stRealData.Convert(pReal) ;

				CString strMsg ;
				strMsg= "주식 잔고 실시간데이터(신용포함) 수신(종목코드) >>" + stRealData.m_szjgcode;
				m_lstMsg.InsertString( 0, strMsg );

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

			//선옵 잔고
			if ( strcmp(szTrCode, TR_13655 ) == 0 ) 
			{					
				TR_13655_O* pData = (TR_13655_O*)prData->TRData;	
				int count = theApp.gatoi( pData->gridcnt, sizeof(pData->gridcnt) ) ;		
				for ( int i =0; i < count; i++)
				{		
					CString szTmp, szJongmok, szQty, szPrice ;

					int nSize = sizeof(TR_13655_G) ;
					szJongmok.Format("%*.*s", sizeof(pData->gr[i].jocode), sizeof(pData->gr[i].jocode), pData->gr[i].jocode) ;
					szQty.Format("%*.*s", sizeof(pData->gr[i].tnonqty), sizeof(pData->gr[i].tnonqty), pData->gr[i].tnonqty) ;
					szPrice.Format("%*.*s", sizeof(pData->gr[i].tnonprc), sizeof(pData->gr[i].tnonprc), pData->gr[i].tnonprc) ;

					szTmp.Format("종목:%s 보유수량:%s 매입단가:%s", szJongmok, szQty, szPrice) ;

					m_lstMsg.InsertString( 0, szTmp );							
				}

				strMsg= "선옵 잔고조회 결과>>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;

				//*********************************
				//화면에 맞게 데이터를 처리
				//*********************************
			}

			//CME 잔고
			else if ( strcmp(szTrCode, TR_20110 ) == 0 ) 
			{					
				TR_20110_O* pData = (TR_20110_O*)prData->TRData;	
				int count = theApp.gatoi( pData->gridcnt, sizeof(pData->gridcnt) ) ;		
				for ( int i =0; i < count; i++)
				{		
					CString szTmp, szJongmok, szQty, szPrice ;

					int nSize = sizeof(TR_20110_G) ;
					szJongmok.Format("%*.*s", sizeof(pData->gr[i].jocode), sizeof(pData->gr[i].jocode), pData->gr[i].jocode) ;
					szQty.Format("%*.*s", sizeof(pData->gr[i].tnonqty), sizeof(pData->gr[i].tnonqty), pData->gr[i].tnonqty) ;
					szPrice.Format("%*.*s", sizeof(pData->gr[i].tnonprc), sizeof(pData->gr[i].tnonprc), pData->gr[i].tnonprc) ;

					szTmp.Format("종목:%s 보유수량:%s 매입단가:%s", szJongmok, szQty, szPrice) ;

					m_lstMsg.InsertString( 0, szTmp );							
				}

				strMsg= "CME 선물 잔고조회 결과>>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;

				//*********************************
				//화면에 맞게 데이터를 처리
				//*********************************
			}

			//주식 잔고
			else if ( strcmp(szTrCode, TR_13148 ) == 0 ) 
			{					
				TR_13148_O* pData = (TR_13148_O*)prData->TRData;					
				int count = theApp.gatoi(pData->gr_bjlen, 4) ;		
				for ( int i =0; i < count; i++)
				{		
					CString szTmp, szJongmok, szQty, szPrice ;

					int nSize = sizeof(TR_13148_G) ;
					szJongmok.Format("%*.*s", sizeof(pData->gr[i].jocode), sizeof(pData->gr[i].jocode), pData->gr[i].jocode) ;
					szQty.Format("%*.*s", sizeof(pData->gr[i].qntybooknon), sizeof(pData->gr[i].qntybooknon), pData->gr[i].qntybooknon) ;
					szPrice.Format("%*.*s", sizeof(pData->gr[i].prcebooknon), sizeof(pData->gr[i].prcebooknon), pData->gr[i].prcebooknon) ;

					szTmp.Format("종목:%s 보유수량:%s 매입단가:%s", szJongmok, szQty, szPrice) ;

					m_lstMsg.InsertString( 0, szTmp );							
				}

				strMsg= "주식 잔고조회 결과>>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;

				//*********************************
				//화면에 맞게 데이터를 처리
				//*********************************
			}

			//주식 잔고2
			else if ( strcmp(szTrCode, TR_13147 ) == 0 ) 
			{					
				TR_13147_O* pData = (TR_13147_O*)prData->TRData;					
				int count = theApp.gatoi(pData->gr_bjlen, 4) ;		
				for ( int i =0; i < count; i++)
				{		
					CString szTmp, szJongmok, szQty, szPrice ;

					int nSize = sizeof(TR_13147_G) ;
					szJongmok.Format("%*.*s", sizeof(pData->gr[i].jocode), sizeof(pData->gr[i].jocode), pData->gr[i].jocode) ;
					szQty.Format("%*.*s", sizeof(pData->gr[i].qntybooknon), sizeof(pData->gr[i].qntybooknon), pData->gr[i].qntybooknon) ;
					szPrice.Format("%*.*s", sizeof(pData->gr[i].prcebooknon), sizeof(pData->gr[i].prcebooknon), pData->gr[i].prcebooknon) ;

					szTmp.Format("종목:%s 보유수량:%s 매입단가:%s", szJongmok, szQty, szPrice) ;

					m_lstMsg.InsertString( 0, szTmp );							
				}

				strMsg= "주식 잔고조회2 결과>>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;

				//*********************************
				//화면에 맞게 데이터를 처리
				//*********************************
			}
		}		
	}

	return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
}

//=======================================================================================
// FUNCTION : 실시간 데이터 요청
// RETURN   : 
//=======================================================================================
void CExJangoDlg::OnBtnRequestRealtimeData()
{
	BOOL bAdvise = ((CButton *)GetDlgItem(IDC_CHK_REALTIME))->GetCheck() ;
	int nAdvise = bAdvise ? DRCM_ADVICE : DRCM_UNADVICE ;

	switch (m_nProduct)
	{
	case ID_PRODUCT_FO :// 선물옵션	잔고
		theApp.SendToServerEx (nAdvise, R_XF3, theApp.g_szId, m_hWnd );	
		break;

	case ID_PRODUCT_CME : //CME선물 잔고
		theApp.SendToServerEx (nAdvise, R_XF6, theApp.g_szId, m_hWnd );	
		break;

	case ID_PRODUCT_SK :// 주식
		theApp.SendToServerEx (nAdvise, R_XX6, theApp.g_szId, m_hWnd );	
		break;
	}	
}

//=======================================================================================
// FUNCTION : 조회
// RETURN   : 
//=======================================================================================
void CExJangoDlg::OnBtnInquery()
{
	switch (m_nProduct)
	{
	case ID_PRODUCT_FO :   // 지수 선물옵션	
	case ID_PRODUCT_SFO :  // 주식 선물옵션
		MakePacket_FO();
		break;

	case ID_PRODUCT_CME : // CME선물	
		MakePacket_CME() ;
		break;

	case ID_PRODUCT_SK : // 주식
		//MakePacket_SK() ;
		MakePacket_SK_Simple() ;
		break;
	}	
}

//=======================================================================================
// FUNCTION : 동부api에 데이터 요청 (CME선물)
// RETURN   : 
//=======================================================================================
void CExJangoDlg::MakePacket_CME()
{
	UpdateData (TRUE) ;

	CString szAccount = m_strAccount ; 	
	CString szInput ;
	
	szAccount.TrimLeft() ;
	szAccount.TrimRight() ;
	szAccount.Remove('-');

	int nLen = sizeof(TR_20110_I) ;
	szInput.Format("%-*.*s", nLen , nLen, szAccount );	
	theApp.SendToServerEx (DRCM_SENDDATA, TR_20110, szInput, m_hWnd);
}

//=======================================================================================
// FUNCTION : 동부api에 데이터 요청 (선물옵션)
// RETURN   : 
//=======================================================================================
void CExJangoDlg::MakePacket_FO()
{	
	UpdateData (TRUE) ;

	int nLen = 0 ;
	
	CString szAccount = m_strAccount ; 
	
	CString szInput ;
	
	szAccount.TrimLeft() ;
	szAccount.TrimRight() ;
	szAccount.Remove('-');

	nLen = sizeof(TR_13655_I) ;
	szInput.Format("%-*.*s", nLen , nLen, szAccount );	
	theApp.SendToServerEx (DRCM_SENDDATA, TR_13655, szInput, m_hWnd);
	
}

//=======================================================================================
// FUNCTION : 동부api에 데이터 요청 (주식)
// RETURN   : 
//=======================================================================================
void CExJangoDlg::MakePacket_SK()
{	
	UpdateData (TRUE) ;

	int nLen = 0 ;

	CString szAccount = m_strAccount ; 
	CString szGubun = "0" ;/* 조회구분 0:잔고 1:평가 2:체결잔고 */
	CString szNext ;

	CString szInput ;

	szAccount.TrimLeft() ;
	szAccount.TrimRight() ;
	szAccount.Remove('-');

	nLen = sizeof(TR_13147_I) ;
	TR_13147_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_13147_I)) ;
	memcpy ( stInput.geja, szAccount, szAccount.GetLength() ) ;
	memcpy ( stInput.gbun, szGubun, 1 ) ;
	memcpy ( stInput.ngbn, "0", 1 ) ;	

	szNext.Format("%0*d", sizeof(stInput.next), 0 );
	memcpy ( stInput.next, (LPCTSTR)szNext, szNext.GetLength() ) ;

	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput );	

	theApp.SendToServerEx (DRCM_SENDDATA, TR_13147, szInput, m_hWnd);
}


//=======================================================================================
// FUNCTION : 동부api에 데이터 요청 (주식)
// RETURN   : 
//=======================================================================================
void CExJangoDlg::MakePacket_SK_Simple()
{	
	UpdateData (TRUE) ;

	int nLen = 0 ;

	CString szAccount = m_strAccount ; 
	CString szGubun = "0" ;/* 조회구분 0:잔고 1:평가 2:체결잔고 */
	CString szNext ;

	CString szInput ;

	szAccount.TrimLeft() ;
	szAccount.TrimRight() ;
	szAccount.Remove('-');

	nLen = sizeof(TR_13148_I) ;
	TR_13148_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_13148_I)) ;
	memcpy ( stInput.geja, szAccount, szAccount.GetLength() ) ;
	memcpy ( stInput.gbun, szGubun, 1 ) ;
	memcpy ( stInput.ngbn, "0", 1 ) ;	

	szNext.Format("%0*d", sizeof(stInput.next), 0 );
	memcpy ( stInput.next, (LPCTSTR)szNext, szNext.GetLength() ) ;

	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput );	

	theApp.SendToServerEx (DRCM_SENDDATA, TR_13148, szInput, m_hWnd);
}



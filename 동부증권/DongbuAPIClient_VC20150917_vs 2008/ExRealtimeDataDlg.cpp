// ExRealtimeDataDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "DongbuAPIClient_VC.h"
#include "ExRealtimeDataDlg.h"


// CExRealtimeDataDlg 대화 상자입니다.

#include "include_cme/TR20110.h"

#include "include_fo/DrdsSC0.h"
#include "include_fo/DrdsOC0.h"
#include "include_fo/DrdsSH0.h"
#include "include_fo/DrdsOH0.h"

#include "include_cme/DrdsMC0.h"
#include "include_cme/DrdsMH0.h"

#include "include_jfo/DrdsJC0.h"
#include "include_jfo/DrdsOPC.h"

#include "include_sk/DrdsX12.h"
#include "include_sk/DrdsS31.h"


IMPLEMENT_DYNAMIC(CExRealtimeDataDlg, CDialog)

CExRealtimeDataDlg::CExRealtimeDataDlg(CWnd* pParent /*=NULL*/)
: CDialog(CExRealtimeDataDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExRealtimeDataDlg)
	//m_strJongmok = _T("101H3000,101H6000");
	m_strJongmok = theApp.g_strJongmok;
	//}}AFX_DATA_INIT
}

CExRealtimeDataDlg::~CExRealtimeDataDlg()
{
}

void CExRealtimeDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CExRealtimeDataDlg)
	
	DDX_Text(pDX, IDC_EDT_JONGMOK,		m_strJongmok);	
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExRealtimeDataDlg, CDialog)

	ON_WM_COPYDATA()

	ON_BN_CLICKED(IDC_CHK_SISE,		OnBtnRequestSise)	
	ON_BN_CLICKED(IDC_CHK_HOGA,		OnBtnRequestHoga)	
END_MESSAGE_MAP()


// CExRealtimeDataDlg 메시지 처리기입니다.

BOOL CExRealtimeDataDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


//=======================================================================================
// FUNCTION : 동부apI 로부터 데이터 수신
// RETURN   : 
//=======================================================================================
BOOL CExRealtimeDataDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
{
	COPYDATASTRUCT* pCDS = pCopyDataStruct ;

	int nDataType = (int)pCDS->dwData ;	
	switch (nDataType)
	{	

		case DRCM_DRDS_DATA :  //실시간 데이타
		{
			DrdsData* pDrdsData = (DrdsData*)pCDS->lpData;

			//선물 시세
			if (memcmp(pDrdsData->Name, R_SC0, 3) == 0)	
			{
				nDataType = eSC0 ;
				DRDS_SC0_DATA* pReal = (DRDS_SC0_DATA*)pDrdsData->Data;
			}
			//선물 호가
			else if (memcmp(pDrdsData->Name, R_SH0, 3) == 0)	
			{
				nDataType = eSH0 ;
				DRDS_SH0_DATA* pReal = (DRDS_SH0_DATA*)pDrdsData->Data;
			}
			//옵션 시세
			else if (memcmp(pDrdsData->Name, R_OC0, 3) == 0)	
			{
				nDataType = eOC0 ;	
				DRDS_OC0_DATA* pReal = (DRDS_OC0_DATA*)pDrdsData->Data;
			}			
			//옵션 호가
			else if (memcmp(pDrdsData->Name, R_OH0, 3) == 0)	
			{
				nDataType = eOH0 ;
				DRDS_OH0_DATA* pReal = (DRDS_OH0_DATA*)pDrdsData->Data;
			}

			//주식선물 시세
			else if (memcmp(pDrdsData->Name, R_JC0, 3) == 0)	
			{	
				DRDS_JC0_DATA* pReal = (DRDS_JC0_DATA*)pDrdsData->Data;
			}			
			//주식선물 호가
			else if (memcmp(pDrdsData->Name, R_JH0, 3) == 0)	
			{	
				DRDS_JH0_DATA* pReal = (DRDS_JH0_DATA*)pDrdsData->Data;
			}

			//주식옵션 시세
			else if (memcmp(pDrdsData->Name, R_OPC, 3) == 0)	
			{	
				DRDS_OPC_DATA* pReal = (DRDS_OPC_DATA*)pDrdsData->Data;
			}
			//주식옵션 호가
			else if (memcmp(pDrdsData->Name, R_OPH, 3) == 0)	
			{		
				DRDS_OPH_DATA* pReal = (DRDS_OPH_DATA*)pDrdsData->Data;
			}
			
			//CME 선물시세
			else if (memcmp(pDrdsData->Name, R_MC0, 3) == 0)	
			{
				nDataType = eMC0 ;
				DRDS_MC0_DATA* pReal = (DRDS_MC0_DATA*)pDrdsData->Data;
			}

			//CME 선물 호가
			else if (memcmp(pDrdsData->Name, R_MH0, 3) == 0)	
			{
				nDataType = eMH0 ;
				DRDS_MH0_DATA* pReal = (DRDS_MH0_DATA*)pDrdsData->Data;
			}


			//주식 시세
			else if (memcmp(pDrdsData->Name, R_S31, 3) == 0)	
			{
				nDataType = eS31 ;

				DRDS_S31_DATA* pReal = (DRDS_S31_DATA*)pDrdsData->Data;	

				CDRDS_S31_DATA stRealData ;
				stRealData.Convert(pReal) ;

				CString strMsg ;
				strMsg= "주식 실시간 시세 데이터 수신(종목코드) >>" + stRealData.m_szcode;

				//*********************************
				//화면에 맞게 데이터를 처리
				//*********************************
				
			}

			//주식 호가
			else if (memcmp(pDrdsData->Name, R_X12, 3) == 0)	
			{
				nDataType = eX12 ;

				DRDS_X12_DATA* pReal = (DRDS_X12_DATA*)pDrdsData->Data;	
			
				//*********************************
				//화면에 맞게 데이터를 처리
				//*********************************
			}
			break ;	
		}			
			
	}

	return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
}

//=======================================================================================
// FUNCTION : 실시간 데이터 요청_ 시세
// RETURN   : 
//=======================================================================================
void CExRealtimeDataDlg::OnBtnRequestSise()
{
	UpdateData(TRUE) ;

	BOOL bAdvise = ((CButton *)GetDlgItem(IDC_CHK_SISE))->GetCheck() ;
	int nAdvise = bAdvise ? DRCM_ADVICE : DRCM_UNADVICE ;

	switch (m_nProduct)
	{
	case ID_PRODUCT_FUT :// 선물
		theApp.SendToServerEx (nAdvise, R_SC0, m_strJongmok, m_hWnd );	
		break;
	case ID_PRODUCT_OPT :// 옵션
		theApp.SendToServerEx (nAdvise, R_OC0, m_strJongmok, m_hWnd );	
		break;

	case ID_PRODUCT_SFUT :// 주식 선물
		theApp.SendToServerEx (nAdvise, R_JC0, m_strJongmok, m_hWnd );	
		break;
	case ID_PRODUCT_SOPT :// 주식 옵션
		theApp.SendToServerEx (nAdvise, R_OPC, m_strJongmok, m_hWnd );	
		break;

	case ID_PRODUCT_CME : //CME선물
		theApp.SendToServerEx (nAdvise, R_MC0, m_strJongmok, m_hWnd );	
		break;

	case ID_PRODUCT_SK : //주식
		theApp.SendToServerEx (nAdvise, R_S31, m_strJongmok, m_hWnd );	
		break;
	}	
}

//=======================================================================================
// FUNCTION : 실시간 데이터 요청 _ 호가
// RETURN   : 
//=======================================================================================
void CExRealtimeDataDlg::OnBtnRequestHoga()
{
	UpdateData(TRUE);
	BOOL bAdvise = ((CButton *)GetDlgItem(IDC_CHK_HOGA))->GetCheck() ;
	int nAdvise = bAdvise ? DRCM_ADVICE : DRCM_UNADVICE ;

	switch (m_nProduct)
	{
	case ID_PRODUCT_FUT :// 선물
		theApp.SendToServerEx (nAdvise, R_SH0, m_strJongmok, m_hWnd );	
		break;
	case ID_PRODUCT_OPT :// 옵션
		theApp.SendToServerEx (nAdvise, R_OH0, m_strJongmok, m_hWnd );	
		break;

	case ID_PRODUCT_SFUT :// 주식 선물
		theApp.SendToServerEx (nAdvise, R_JH0, m_strJongmok, m_hWnd );	
		break;
	case ID_PRODUCT_SOPT :// 주식 옵션
		theApp.SendToServerEx (nAdvise, R_OPH, m_strJongmok, m_hWnd );	
		break;

	case ID_PRODUCT_CME : //CME선물
		theApp.SendToServerEx (nAdvise, R_MH0, m_strJongmok, m_hWnd );	
		break;

	case ID_PRODUCT_SK : //주식
		theApp.SendToServerEx (nAdvise, R_X12, m_strJongmok, m_hWnd );	
		break;
	}	
}

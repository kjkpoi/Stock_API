
// MainFrm.cpp : CMainFrame 클래스의 구현
//

#include "stdafx.h"
#include "DongbuAPIClient_VC.h"

#include "MainFrm.h"

#include "ExLoginDlg.h"
#include "ExOrderDlg.h"
#include "ExAbleOrderQtyDlg.h"
#include "ExJangoDlg.h"
#include "ExChegyulDlg.h"
#include "ExMiChegyulDlg.h"
#include "ExDepositDlg.h"
#include "ExRealtimeDataDlg.h"
#include "SymbolFindDialog.h"

#include "ExSiseDlg.h"
#include "ExHogaDlg.h"
//#include "ExInvestTodayDlg.h"
#include "ExInvestChu.h"

#include "ExSvrAutoOrderDlg.h"

#include "ExTest.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWndEx)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWndEx)
	ON_WM_CREATE()

	ON_COMMAND(IDM_LOGIN,			OnLogin)

	ON_COMMAND(IDM_FO_ACCOUNTLIST,		OnInquryAccountListFO) 
	ON_COMMAND(IDM_SK_ACCOUNTLIST,		OnInquryAccountListSK) 
	

	//지수 선옵
	ON_COMMAND(IDM_FO_ORDER,		OnOrderFO) 
	ON_COMMAND(IDM_FO_ABLEQTY,		OnAbleQtyFO)
	ON_COMMAND(IDM_FO_JANGO,		OnJangoFO) 
	ON_COMMAND(IDM_FO_CHE,			OnChegyulFO)
	ON_COMMAND(IDM_FO_MICHE,		OnMiChegyulFO)
	ON_COMMAND(IDM_FO_DEPOSIT,		OnDepositFO)
	ON_COMMAND(IDM_FUT_SYMBOLFINDER,		OnSymbolFinderFut)
	ON_COMMAND(IDM_OPT_SYMBOLFINDER,		OnSymbolFinderOpt)
	
	ON_COMMAND(IDM_FUT_HOGA,		    OnHogaFut)
	ON_COMMAND(IDM_OPT_HOGA,		    OnHogaOpt)
	

	//CME 선물
	ON_COMMAND(IDM_CME_ORDER,		OnOrderCME)
	ON_COMMAND(IDM_CME_ABLEQTY,		OnAbleQtyCME)
	ON_COMMAND(IDM_CME_JANGO,		OnJangoCME)
	ON_COMMAND(IDM_CME_CHE,			OnChegyulCME)
	ON_COMMAND(IDM_CME_MICHE,		OnMiChegyulCME)
	ON_COMMAND(IDM_CME_DEPOSIT,		OnDepositCME)
	ON_COMMAND(IDM_CME_RT,			OnRealtimeCME)
	ON_COMMAND(IDM_CME_INVESTCHG,	OnInvestChange)
	

	//주식 선옵
	ON_COMMAND(IDM_SFO_ORDER,		OnOrderSFO) 
	ON_COMMAND(IDM_SFO_ABLEQTY,		OnAbleQtySFO)
			
	//주식
	ON_COMMAND(IDM_SK_ORDER,		OnOrderSK) 
	ON_COMMAND(IDM_SK_ABLEQTY,		OnAbleQtySK)
	ON_COMMAND(IDM_SK_JANGO,		OnJangoSK) 
	ON_COMMAND(IDM_SK_CHE,			OnChegyulSK)
	ON_COMMAND(IDM_SK_MICHE,		OnMiChegyulSK)
	ON_COMMAND(IDM_SK_DEPOSIT,		OnDepositSK)
	ON_COMMAND(IDM_SK_INVESTTODAY,	OnInvestToday)
	ON_COMMAND(IDM_SK_INVEST,		OnInvestSK)

	ON_COMMAND(IDM_SK_SVRORDER_SETALL,		OnSvrOrderSetAll)
	ON_COMMAND(IDM_SK_SVRORDER_SET,		    OnSvrOrderSet)
	

	ON_COMMAND(IDM_SK_SISE,		    OnSiseSK)
	ON_COMMAND(IDM_SK_HOGA,		    OnHogaSK)

	ON_COMMAND(IDM_FUT_RT,		OnRealtimeFUT)
	ON_COMMAND(IDM_OPT_RT,		OnRealtimeOPT)
	ON_COMMAND(IDM_SFUT_RT,		OnRealtimeSFUT)
	ON_COMMAND(IDM_SOPT_RT,		OnRealtimeSOPT)
	ON_COMMAND(IDM_SK_RT,		OnRealtimeSK)

	ON_COMMAND(IDM_MY_TEST,		OnMyTest)
	
	
	ON_WM_COPYDATA()
	
	//ON_REGISTERED_MESSAGE(AFX_WM_CREATETOOLBAR, &CMainFrame::OnToolbarCreateNew)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 상태 줄 표시기
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 생성/소멸

CMainFrame::CMainFrame()
{
	// TODO: 여기에 멤버 초기화 코드를 추가합니다.
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	//BOOL bNameValid;

	// 모든 사용자 인터페이스 요소를 그리는 데 사용하는 비주얼 관리자를 설정합니다.
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2005));

	CMDITabInfo mdiTabParams;
	mdiTabParams.m_style = CMFCTabCtrl::STYLE_3D_ONENOTE; // 사용할 수 있는 다른 스타일...
	mdiTabParams.m_bActiveTabCloseButton = TRUE;      // FALSE로 설정하여 탭 영역 오른쪽에 닫기 단추를 배치합니다.
	mdiTabParams.m_bTabIcons = FALSE;    // TRUE로 설정하여 MDI 탭의 문서 아이콘을 활성화합니다.
	mdiTabParams.m_bAutoColor = TRUE;    // FALSE로 설정하여 MDI 탭의 자동 색 지정을 비활성화합니다.
	mdiTabParams.m_bDocumentMenu = TRUE; // 탭 영역의 오른쪽 가장자리에 문서 메뉴를 활성화합니다.
	EnableMDITabbedGroups(TRUE, mdiTabParams);

	if (!m_wndMenuBar.Create(this))
	{
		TRACE0("메뉴 모음을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}

	m_wndMenuBar.SetPaneStyle(m_wndMenuBar.GetPaneStyle() | CBRS_SIZE_DYNAMIC | CBRS_TOOLTIPS | CBRS_FLYBY);


	SetWindowTextEx();

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWndEx::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return TRUE;
}

// CMainFrame 진단

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWndEx::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWndEx::Dump(dc);
}
#endif //_DEBUG



BOOL CMainFrame::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, CCreateContext* pContext) 
{
	// 기본 클래스가 실제 작업을 수행합니다.

	if (!CMDIFrameWndEx::LoadFrame(nIDResource, dwDefaultStyle, pParentWnd, pContext))
	{
		return FALSE;
	}

	return TRUE;
}

void CMainFrame::SetWindowTextEx() 
{
	CString szText = "동부API 예제 프로그램 >> ";

	if ( theApp.g_bConnected )	
		szText += "동부API와 접속중...." ;		
	else
		szText += "동부API와 접속안됨" ;		
			
	
	this->SetWindowText(szText) ;
}

//=======================================================================================
// FUNCTION : DRCM에서 보내온 WM_COPYDATA 메시지 처리
// RETURN   : 
//=======================================================================================
BOOL CMainFrame::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
{
	COPYDATASTRUCT* pCDS = pCopyDataStruct ;

	int nDataType = (int)pCDS->dwData ;

	switch (nDataType)
	{
	case DRCM_DISCONNECT : //DRCM 이 종료될때 오는 메시지

		if ( theApp.g_hDongbuDRCM )
		{		
			theApp.g_hDongbuDRCM  = NULL ;	
			theApp.g_bConnected = FALSE ;
		}
		
		SetWindowTextEx();

		break;	

	case DRCM_F_ACCLIST :  //선옵계좌리스트
	case DRCM_S_ACCLIST :  //주식계좌리스트
		GetAccountList((LPSTR)pCDS->lpData, (int)pCDS->cbData);
		break ;	
	}

	return CMDIFrameWndEx::OnCopyData(pWnd, pCopyDataStruct);
}


//로그인/로그아웃
void CMainFrame::OnLogin() 
{
	CExLoginDlg dlg;
	dlg.DoModal() ;

	SetWindowTextEx();
}

//선옵계좌리스트
void CMainFrame::OnInquryAccountListFO() 
{
	COPYDATASTRUCT cds;	
	cds.dwData = (DWORD)DRCM_F_ACCLIST;			
	cds.cbData = 0 ;
	::SendMessage(theApp.g_hDongbuDRCM, WM_COPYDATA, (WPARAM)m_hWnd, (LPARAM)&cds);			
}
//주식계좌리스트
void CMainFrame::OnInquryAccountListSK() 
{
	COPYDATASTRUCT cds;	
	cds.dwData = (DWORD)DRCM_S_ACCLIST;			
	cds.cbData = 0 ;
	::SendMessage(theApp.g_hDongbuDRCM, WM_COPYDATA, (WPARAM)m_hWnd, (LPARAM)&cds);	

}

//=======================================================================================
// FUNCTION : 선물 계좌리스트 
//            GEJA_SIZE : 위임구분(1) + 계좌(11) + 계좌명(20)
//=======================================================================================
#define GEJA_SIZE		32
void CMainFrame::GetAccountList(LPSTR szData, int nLen)
{
	CString szTotalList ;
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

		szTotalList += strText + " \n";		

		nOffset+= GEJA_SIZE ;
	}	

	AfxMessageBox(szTotalList) ;
}

//선물 종목코드
void CMainFrame::OnSymbolFinderFut() 
{
	CSymbolFindDialog dlg;
	dlg.m_nProduct = ID_PRODUCT_FUT ;
	dlg.DoModal() ;	
}

//옵션 종목코드
void CMainFrame::OnSymbolFinderOpt() 
{
	CSymbolFindDialog dlg;
	dlg.m_nProduct = ID_PRODUCT_OPT ;
	dlg.DoModal() ;	
}

//=======================================================================================
// FUNCTION : 주문예제 화면 열기
//=======================================================================================
void CMainFrame::OpenOrderExDlg(int nProduct) 
{
	CExOrderDlg dlg;
	dlg.m_nProduct = nProduct ;
	dlg.DoModal() ;	
}

//=======================================================================================
// FUNCTION : 체결내역조회 예제 화면 열기
//=======================================================================================
void CMainFrame::OpenChegyulExDlg(int nProduct) 
{
	CExChegyulDlg dlg;
	dlg.m_nProduct = nProduct ;
	dlg.DoModal() ;
}

//=======================================================================================
// FUNCTION : 미체결내역조회 예제 화면 열기
//=======================================================================================
void CMainFrame::OpenMiChegyulExDlg (int nProduct) 
{
	CExMiChegyulDlg dlg;
	dlg.m_nProduct = nProduct ;
	dlg.DoModal() ;
}

//=======================================================================================
// FUNCTION : 잔고조회예제 화면 열기
//=======================================================================================
void CMainFrame::OpenJangoExDlg(int nProduct) 
{
	CExJangoDlg dlg;
	dlg.m_nProduct = nProduct ;
	dlg.DoModal() ;	
}

//=======================================================================================
// FUNCTION : 주문가능수량(신규/청산)조회예제 화면 열기
//=======================================================================================
void CMainFrame::OpenAbleQtyExDlg(int nProduct) 
{
	CExAbleOrderQtyDlg dlg;
	dlg.m_nProduct = nProduct ;
	dlg.DoModal() ;	
}

//=======================================================================================
// FUNCTION : 평가현황조회예제 화면 열기
//=======================================================================================
void CMainFrame::OpenDepositExDlg(int nProduct) 
{
	CExDepositDlg dlg;
	dlg.m_nProduct = nProduct ;
	dlg.DoModal() ;		
}


//=======================================================================================
// FUNCTION : 실시간데이터 요청 화면 열기
//=======================================================================================
void CMainFrame::OpenRealtimeDataExDlg(int nProduct) 
{
	CExRealtimeDataDlg dlg;
	dlg.m_nProduct = nProduct ;
	dlg.DoModal() ;	
}

//=======================================================================================
// FUNCTION : 호가 조회 예제 화면 열기
//=======================================================================================
void CMainFrame::OpenHogaExDlg (int nProduct) 
{
	CExHogaDlg dlg;
	dlg.m_nProduct = nProduct ;
	dlg.DoModal() ;
}

//==========================================================================
// 선물옵션
//==========================================================================

//선옵주문 주문
void CMainFrame::OnOrderFO() 
{
	OpenOrderExDlg(ID_PRODUCT_FO);
}

//선옵 잔고조회
void CMainFrame::OnJangoFO() 
{
	OpenJangoExDlg(ID_PRODUCT_FO) ;
}
//선옵 체결
void CMainFrame::OnChegyulFO() 
{
	OpenChegyulExDlg(ID_PRODUCT_FO) ;
}
//선옵 미체결
void CMainFrame::OnMiChegyulFO() 
{
	OpenMiChegyulExDlg(ID_PRODUCT_FO) ;
}

//선옵 주문가능수량
void CMainFrame::OnAbleQtyFO() 
{
	OpenAbleQtyExDlg(ID_PRODUCT_FO) ;	
}

//선옵 예수금 현황
void CMainFrame::OnDepositFO() 
{
	OpenDepositExDlg(ID_PRODUCT_FO);
}

//선물 실시간데이터 요청
void CMainFrame::OnRealtimeFUT() 
{
	OpenRealtimeDataExDlg(ID_PRODUCT_FUT);	
}

//옵션 실시간데이터 요청
void CMainFrame::OnRealtimeOPT() 
{
	OpenRealtimeDataExDlg(ID_PRODUCT_OPT);	
}

//선물 호가조회
void CMainFrame::OnHogaFut() 
{
	OpenHogaExDlg(ID_PRODUCT_FUT);
}

//옵션 호가조회
void CMainFrame::OnHogaOpt() 
{
	OpenHogaExDlg(ID_PRODUCT_OPT);
}



//==========================================================================
//CME선물
//==========================================================================
//CME선물 주문
void CMainFrame::OnOrderCME() 
{
	OpenOrderExDlg(ID_PRODUCT_CME);
}
//CME선물 잔고
void CMainFrame::OnJangoCME() 
{
	OpenJangoExDlg(ID_PRODUCT_CME) ;
}

//CME선물 주문가능수량
void CMainFrame::OnAbleQtyCME() 
{
	OpenAbleQtyExDlg(ID_PRODUCT_CME) ;	
}

//CME선물 체결
void CMainFrame::OnChegyulCME() 
{
	OpenChegyulExDlg(ID_PRODUCT_CME) ;
}
//CME선물 미체결
void CMainFrame::OnMiChegyulCME() 
{
	OpenMiChegyulExDlg(ID_PRODUCT_CME) ;
}

//CME선물 예수금 현황
void CMainFrame::OnDepositCME() 
{
	OpenDepositExDlg(ID_PRODUCT_CME);
}

//CME선물 실시간
void CMainFrame::OnRealtimeCME() 
{
	OpenRealtimeDataExDlg(ID_PRODUCT_CME);		
}

//CME 투자자 시간대별 추이
void CMainFrame::OnInvestChange() 
{
	//CExInvestTodayDlg dlg;	
	//dlg.DoModal() ;

}


//==========================================================================
// 주식 선물옵션
//==========================================================================
//주식선옵 주문
void CMainFrame::OnOrderSFO() 
{
	OpenOrderExDlg(ID_PRODUCT_SFO);
}
//주식선옵 주문가능수량
void CMainFrame::OnAbleQtySFO() 
{
	OpenAbleQtyExDlg(ID_PRODUCT_SFO) ;	
}

//주식선물 실시간
void CMainFrame::OnRealtimeSFUT() 
{
	OpenRealtimeDataExDlg(ID_PRODUCT_SOPT);	
}

//주식옵션 실시간
void CMainFrame::OnRealtimeSOPT() 
{
	OpenRealtimeDataExDlg(ID_PRODUCT_SOPT);	
}



//==========================================================================
// 주식
//==========================================================================

//주식 주문
void CMainFrame::OnOrderSK() 
{
	OpenOrderExDlg(ID_PRODUCT_SK);
}

void CMainFrame::OnAbleQtySK() 
{
	OpenAbleQtyExDlg(ID_PRODUCT_SK) ;	
}
//주식 잔고
void CMainFrame::OnJangoSK() 
{
	OpenJangoExDlg(ID_PRODUCT_SK) ;
}

//주식 체결
void CMainFrame::OnChegyulSK() 
{
	OpenChegyulExDlg(ID_PRODUCT_SK) ;
}
//주식 미체결
void CMainFrame::OnMiChegyulSK() 
{
	OpenMiChegyulExDlg(ID_PRODUCT_SK) ;
}
//주식 투자자 당일 추정
void CMainFrame::OnInvestToday() 
{
	//CExInvestTodayDlg dlg;	
	//dlg.DoModal() ;

}
//투자자/프로그램 매매종합
void CMainFrame::OnInvestSK() 
{
	CExInvestChu dlg;	
	dlg.DoModal() ;
}

void CMainFrame::OnSvrOrderSetAll() 
{
	CExSvrAutoOrderDlg dlg;	
	dlg.DoModal() ;
}
void CMainFrame::OnSvrOrderSet() 
{
	//CExInvestChu dlg;	
	//dlg.DoModal() ;
}

//CME선물 예수금 현황
void CMainFrame::OnDepositSK() 
{
	OpenDepositExDlg(ID_PRODUCT_SK);
}
//주식 실시간
void CMainFrame::OnRealtimeSK() 
{
	OpenRealtimeDataExDlg(ID_PRODUCT_SK);	
}
//주식 현재가
void CMainFrame::OnSiseSK() 
{
	CExSiseDlg dlg;
	dlg.m_nProduct = ID_PRODUCT_SK ;
	dlg.DoModal() ;	
}

//주식 호가
void CMainFrame::OnHogaSK() 
{
	OpenHogaExDlg(ID_PRODUCT_SK);
}

//내 dialog 테스트
void CMainFrame::OnMyTest() 
{
	ExTest dlg;
	dlg.m_nProduct = ID_PRODUCT_SK;
	dlg.DoModal();
}










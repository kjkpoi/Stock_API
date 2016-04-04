
// MainFrm.cpp : CMainFrame Ŭ������ ����
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
	

	//���� ����
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
	

	//CME ����
	ON_COMMAND(IDM_CME_ORDER,		OnOrderCME)
	ON_COMMAND(IDM_CME_ABLEQTY,		OnAbleQtyCME)
	ON_COMMAND(IDM_CME_JANGO,		OnJangoCME)
	ON_COMMAND(IDM_CME_CHE,			OnChegyulCME)
	ON_COMMAND(IDM_CME_MICHE,		OnMiChegyulCME)
	ON_COMMAND(IDM_CME_DEPOSIT,		OnDepositCME)
	ON_COMMAND(IDM_CME_RT,			OnRealtimeCME)
	ON_COMMAND(IDM_CME_INVESTCHG,	OnInvestChange)
	

	//�ֽ� ����
	ON_COMMAND(IDM_SFO_ORDER,		OnOrderSFO) 
	ON_COMMAND(IDM_SFO_ABLEQTY,		OnAbleQtySFO)
			
	//�ֽ�
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
	ID_SEPARATOR,           // ���� �� ǥ�ñ�
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/�Ҹ�

CMainFrame::CMainFrame()
{
	// TODO: ���⿡ ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	//BOOL bNameValid;

	// ��� ����� �������̽� ��Ҹ� �׸��� �� ����ϴ� ���־� �����ڸ� �����մϴ�.
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2005));

	CMDITabInfo mdiTabParams;
	mdiTabParams.m_style = CMFCTabCtrl::STYLE_3D_ONENOTE; // ����� �� �ִ� �ٸ� ��Ÿ��...
	mdiTabParams.m_bActiveTabCloseButton = TRUE;      // FALSE�� �����Ͽ� �� ���� �����ʿ� �ݱ� ���߸� ��ġ�մϴ�.
	mdiTabParams.m_bTabIcons = FALSE;    // TRUE�� �����Ͽ� MDI ���� ���� �������� Ȱ��ȭ�մϴ�.
	mdiTabParams.m_bAutoColor = TRUE;    // FALSE�� �����Ͽ� MDI ���� �ڵ� �� ������ ��Ȱ��ȭ�մϴ�.
	mdiTabParams.m_bDocumentMenu = TRUE; // �� ������ ������ �����ڸ��� ���� �޴��� Ȱ��ȭ�մϴ�.
	EnableMDITabbedGroups(TRUE, mdiTabParams);

	if (!m_wndMenuBar.Create(this))
	{
		TRACE0("�޴� ������ ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
	}

	m_wndMenuBar.SetPaneStyle(m_wndMenuBar.GetPaneStyle() | CBRS_SIZE_DYNAMIC | CBRS_TOOLTIPS | CBRS_FLYBY);


	SetWindowTextEx();

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWndEx::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return TRUE;
}

// CMainFrame ����

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
	// �⺻ Ŭ������ ���� �۾��� �����մϴ�.

	if (!CMDIFrameWndEx::LoadFrame(nIDResource, dwDefaultStyle, pParentWnd, pContext))
	{
		return FALSE;
	}

	return TRUE;
}

void CMainFrame::SetWindowTextEx() 
{
	CString szText = "����API ���� ���α׷� >> ";

	if ( theApp.g_bConnected )	
		szText += "����API�� ������...." ;		
	else
		szText += "����API�� ���Ӿȵ�" ;		
			
	
	this->SetWindowText(szText) ;
}

//=======================================================================================
// FUNCTION : DRCM���� ������ WM_COPYDATA �޽��� ó��
// RETURN   : 
//=======================================================================================
BOOL CMainFrame::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
{
	COPYDATASTRUCT* pCDS = pCopyDataStruct ;

	int nDataType = (int)pCDS->dwData ;

	switch (nDataType)
	{
	case DRCM_DISCONNECT : //DRCM �� ����ɶ� ���� �޽���

		if ( theApp.g_hDongbuDRCM )
		{		
			theApp.g_hDongbuDRCM  = NULL ;	
			theApp.g_bConnected = FALSE ;
		}
		
		SetWindowTextEx();

		break;	

	case DRCM_F_ACCLIST :  //���ɰ��¸���Ʈ
	case DRCM_S_ACCLIST :  //�ֽİ��¸���Ʈ
		GetAccountList((LPSTR)pCDS->lpData, (int)pCDS->cbData);
		break ;	
	}

	return CMDIFrameWndEx::OnCopyData(pWnd, pCopyDataStruct);
}


//�α���/�α׾ƿ�
void CMainFrame::OnLogin() 
{
	CExLoginDlg dlg;
	dlg.DoModal() ;

	SetWindowTextEx();
}

//���ɰ��¸���Ʈ
void CMainFrame::OnInquryAccountListFO() 
{
	COPYDATASTRUCT cds;	
	cds.dwData = (DWORD)DRCM_F_ACCLIST;			
	cds.cbData = 0 ;
	::SendMessage(theApp.g_hDongbuDRCM, WM_COPYDATA, (WPARAM)m_hWnd, (LPARAM)&cds);			
}
//�ֽİ��¸���Ʈ
void CMainFrame::OnInquryAccountListSK() 
{
	COPYDATASTRUCT cds;	
	cds.dwData = (DWORD)DRCM_S_ACCLIST;			
	cds.cbData = 0 ;
	::SendMessage(theApp.g_hDongbuDRCM, WM_COPYDATA, (WPARAM)m_hWnd, (LPARAM)&cds);	

}

//=======================================================================================
// FUNCTION : ���� ���¸���Ʈ 
//            GEJA_SIZE : ���ӱ���(1) + ����(11) + ���¸�(20)
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

//���� �����ڵ�
void CMainFrame::OnSymbolFinderFut() 
{
	CSymbolFindDialog dlg;
	dlg.m_nProduct = ID_PRODUCT_FUT ;
	dlg.DoModal() ;	
}

//�ɼ� �����ڵ�
void CMainFrame::OnSymbolFinderOpt() 
{
	CSymbolFindDialog dlg;
	dlg.m_nProduct = ID_PRODUCT_OPT ;
	dlg.DoModal() ;	
}

//=======================================================================================
// FUNCTION : �ֹ����� ȭ�� ����
//=======================================================================================
void CMainFrame::OpenOrderExDlg(int nProduct) 
{
	CExOrderDlg dlg;
	dlg.m_nProduct = nProduct ;
	dlg.DoModal() ;	
}

//=======================================================================================
// FUNCTION : ü�᳻����ȸ ���� ȭ�� ����
//=======================================================================================
void CMainFrame::OpenChegyulExDlg(int nProduct) 
{
	CExChegyulDlg dlg;
	dlg.m_nProduct = nProduct ;
	dlg.DoModal() ;
}

//=======================================================================================
// FUNCTION : ��ü�᳻����ȸ ���� ȭ�� ����
//=======================================================================================
void CMainFrame::OpenMiChegyulExDlg (int nProduct) 
{
	CExMiChegyulDlg dlg;
	dlg.m_nProduct = nProduct ;
	dlg.DoModal() ;
}

//=======================================================================================
// FUNCTION : �ܰ���ȸ���� ȭ�� ����
//=======================================================================================
void CMainFrame::OpenJangoExDlg(int nProduct) 
{
	CExJangoDlg dlg;
	dlg.m_nProduct = nProduct ;
	dlg.DoModal() ;	
}

//=======================================================================================
// FUNCTION : �ֹ����ɼ���(�ű�/û��)��ȸ���� ȭ�� ����
//=======================================================================================
void CMainFrame::OpenAbleQtyExDlg(int nProduct) 
{
	CExAbleOrderQtyDlg dlg;
	dlg.m_nProduct = nProduct ;
	dlg.DoModal() ;	
}

//=======================================================================================
// FUNCTION : ����Ȳ��ȸ���� ȭ�� ����
//=======================================================================================
void CMainFrame::OpenDepositExDlg(int nProduct) 
{
	CExDepositDlg dlg;
	dlg.m_nProduct = nProduct ;
	dlg.DoModal() ;		
}


//=======================================================================================
// FUNCTION : �ǽð������� ��û ȭ�� ����
//=======================================================================================
void CMainFrame::OpenRealtimeDataExDlg(int nProduct) 
{
	CExRealtimeDataDlg dlg;
	dlg.m_nProduct = nProduct ;
	dlg.DoModal() ;	
}

//=======================================================================================
// FUNCTION : ȣ�� ��ȸ ���� ȭ�� ����
//=======================================================================================
void CMainFrame::OpenHogaExDlg (int nProduct) 
{
	CExHogaDlg dlg;
	dlg.m_nProduct = nProduct ;
	dlg.DoModal() ;
}

//==========================================================================
// �����ɼ�
//==========================================================================

//�����ֹ� �ֹ�
void CMainFrame::OnOrderFO() 
{
	OpenOrderExDlg(ID_PRODUCT_FO);
}

//���� �ܰ���ȸ
void CMainFrame::OnJangoFO() 
{
	OpenJangoExDlg(ID_PRODUCT_FO) ;
}
//���� ü��
void CMainFrame::OnChegyulFO() 
{
	OpenChegyulExDlg(ID_PRODUCT_FO) ;
}
//���� ��ü��
void CMainFrame::OnMiChegyulFO() 
{
	OpenMiChegyulExDlg(ID_PRODUCT_FO) ;
}

//���� �ֹ����ɼ���
void CMainFrame::OnAbleQtyFO() 
{
	OpenAbleQtyExDlg(ID_PRODUCT_FO) ;	
}

//���� ������ ��Ȳ
void CMainFrame::OnDepositFO() 
{
	OpenDepositExDlg(ID_PRODUCT_FO);
}

//���� �ǽð������� ��û
void CMainFrame::OnRealtimeFUT() 
{
	OpenRealtimeDataExDlg(ID_PRODUCT_FUT);	
}

//�ɼ� �ǽð������� ��û
void CMainFrame::OnRealtimeOPT() 
{
	OpenRealtimeDataExDlg(ID_PRODUCT_OPT);	
}

//���� ȣ����ȸ
void CMainFrame::OnHogaFut() 
{
	OpenHogaExDlg(ID_PRODUCT_FUT);
}

//�ɼ� ȣ����ȸ
void CMainFrame::OnHogaOpt() 
{
	OpenHogaExDlg(ID_PRODUCT_OPT);
}



//==========================================================================
//CME����
//==========================================================================
//CME���� �ֹ�
void CMainFrame::OnOrderCME() 
{
	OpenOrderExDlg(ID_PRODUCT_CME);
}
//CME���� �ܰ�
void CMainFrame::OnJangoCME() 
{
	OpenJangoExDlg(ID_PRODUCT_CME) ;
}

//CME���� �ֹ����ɼ���
void CMainFrame::OnAbleQtyCME() 
{
	OpenAbleQtyExDlg(ID_PRODUCT_CME) ;	
}

//CME���� ü��
void CMainFrame::OnChegyulCME() 
{
	OpenChegyulExDlg(ID_PRODUCT_CME) ;
}
//CME���� ��ü��
void CMainFrame::OnMiChegyulCME() 
{
	OpenMiChegyulExDlg(ID_PRODUCT_CME) ;
}

//CME���� ������ ��Ȳ
void CMainFrame::OnDepositCME() 
{
	OpenDepositExDlg(ID_PRODUCT_CME);
}

//CME���� �ǽð�
void CMainFrame::OnRealtimeCME() 
{
	OpenRealtimeDataExDlg(ID_PRODUCT_CME);		
}

//CME ������ �ð��뺰 ����
void CMainFrame::OnInvestChange() 
{
	//CExInvestTodayDlg dlg;	
	//dlg.DoModal() ;

}


//==========================================================================
// �ֽ� �����ɼ�
//==========================================================================
//�ֽļ��� �ֹ�
void CMainFrame::OnOrderSFO() 
{
	OpenOrderExDlg(ID_PRODUCT_SFO);
}
//�ֽļ��� �ֹ����ɼ���
void CMainFrame::OnAbleQtySFO() 
{
	OpenAbleQtyExDlg(ID_PRODUCT_SFO) ;	
}

//�ֽļ��� �ǽð�
void CMainFrame::OnRealtimeSFUT() 
{
	OpenRealtimeDataExDlg(ID_PRODUCT_SOPT);	
}

//�ֽĿɼ� �ǽð�
void CMainFrame::OnRealtimeSOPT() 
{
	OpenRealtimeDataExDlg(ID_PRODUCT_SOPT);	
}



//==========================================================================
// �ֽ�
//==========================================================================

//�ֽ� �ֹ�
void CMainFrame::OnOrderSK() 
{
	OpenOrderExDlg(ID_PRODUCT_SK);
}

void CMainFrame::OnAbleQtySK() 
{
	OpenAbleQtyExDlg(ID_PRODUCT_SK) ;	
}
//�ֽ� �ܰ�
void CMainFrame::OnJangoSK() 
{
	OpenJangoExDlg(ID_PRODUCT_SK) ;
}

//�ֽ� ü��
void CMainFrame::OnChegyulSK() 
{
	OpenChegyulExDlg(ID_PRODUCT_SK) ;
}
//�ֽ� ��ü��
void CMainFrame::OnMiChegyulSK() 
{
	OpenMiChegyulExDlg(ID_PRODUCT_SK) ;
}
//�ֽ� ������ ���� ����
void CMainFrame::OnInvestToday() 
{
	//CExInvestTodayDlg dlg;	
	//dlg.DoModal() ;

}
//������/���α׷� �Ÿ�����
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

//CME���� ������ ��Ȳ
void CMainFrame::OnDepositSK() 
{
	OpenDepositExDlg(ID_PRODUCT_SK);
}
//�ֽ� �ǽð�
void CMainFrame::OnRealtimeSK() 
{
	OpenRealtimeDataExDlg(ID_PRODUCT_SK);	
}
//�ֽ� ���簡
void CMainFrame::OnSiseSK() 
{
	CExSiseDlg dlg;
	dlg.m_nProduct = ID_PRODUCT_SK ;
	dlg.DoModal() ;	
}

//�ֽ� ȣ��
void CMainFrame::OnHogaSK() 
{
	OpenHogaExDlg(ID_PRODUCT_SK);
}

//�� dialog �׽�Ʈ
void CMainFrame::OnMyTest() 
{
	ExTest dlg;
	dlg.m_nProduct = ID_PRODUCT_SK;
	dlg.DoModal();
}










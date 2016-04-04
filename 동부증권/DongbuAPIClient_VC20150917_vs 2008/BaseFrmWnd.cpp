// BaseFrmWnd.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"

#include "DongbuAPIClient_VC.h"
#include "ExSvrAutoOrderDlg.h"
#include "BaseFrmWnd.h"


#include "include_auto/globalauto.h"
#include "include_auto/MasterDataSub.h"


#include "include_auto/TR13242.h"
#include "include_auto/TR10051.h"  // ��Ŷ TR_10051 : �ֽ�

#include "include_auto/TR10117.h"
#include "include_auto/TR10112.h"  // ��������
#include "include_auto/TR09292.h"  // ��Ŷ TR_09292 : ȣ��  //����
#include "include_auto/TR10142.h"  // TR_10142 ������� ���ɼ���
#include "include_auto/TR10144.h"  // TR_10144 �ſ�ŵ����ɼ�����ȸ

#include "include_auto/TR14055.h"
#include "include_auto/TR14051.h"
#include "include_auto/TR04012.h"


#include "include_auto/DrdsXX9.h"



//�ߴ� �����ǿ� ��ġ�� ���������� ID + n
#define ID_ORDER_CONDWND 900
#define SCREEN_WIDTH	 400


#define HEIGHT_LEFT_TOP_WND	75
#define WIDTH_LEFT_WND		455

#define ID_TEMP_CODEINPUT	2001


// CBaseFrmWnd

IMPLEMENT_DYNCREATE(CBaseFrmWnd, CDialog)


//extern HINSTANCE g_hInstance;
//extern CTrSvrAutoOrdApp theApp;

const		UINT		ERRORCHECK_TYPELIST[] = { -301, -201, -202, -203, -204 };

CBaseFrmWnd::CBaseFrmWnd()	: CDialog(CBaseFrmWnd::IDD)

{

	LOGFONT	  logFont;
	GETFONT(logFont, 12, 400, m_fontDefault);
	m_clrBk = COLOR_MAIN_CANVAS;
	m_clrText = RGB(0, 0, 0);
	m_brushBk.CreateSolidBrush(m_clrBk);

	m_bParentInitialized = FALSE;

	m_hwndJCode		= NULL;
	m_hwndJName		= NULL;
	m_hwndJMarket	= NULL;	


	m_clOrdMinSet.m_enOrdType	  = NORMAL_ORDER;
	m_clOrdMinSet.m_strMarketType = SVRORD_MARKETTYPE_STOCK;
	m_clOrdMinSet.m_strMMType	  = SVRORD_MMTYPE_BUY;	
//	m_hConditionMng = NULL;
	m_strAppPath	= "";
	m_nElementIndex = 0;
	m_nChkCtrlID = INDEX_START_CHKBOX;
	m_nCmbCtrlID = INDEX_START_COMBO;
	m_strWaitingTr = "";
	m_bConTabInit = FALSE;
	m_strJobFlag = SVRORD_JOB_REG;
	m_nVolCheck  = VOLCHECK;
	m_bEnableReg = TRUE;

	m_nScreenWidth = SCREEN_WIDTH;
	

	m_bInit = FALSE;

	m_pPriceInfo = NULL; //new CPriceInfo; //NULL;	

	m_bCreditAcnt = FALSE;
	m_bCreateDone = FALSE;

	m_bBaseRequestState		= FALSE;
	m_rtCode = CRect(0, 0, 0, 0);


	m_pParent = NULL;	
	m_pMapCtrlGroup = NULL;	
}

CBaseFrmWnd::~CBaseFrmWnd()
{
	m_fontDefault.DeleteObject();
	m_brushBk.DeleteObject();
}


BEGIN_MESSAGE_MAP(CBaseFrmWnd, CDialog)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_WM_DESTROY()
	ON_WM_COPYDATA()

	//ON_MESSAGE(WM_DRDS_DATA, OnBaseDrdsData)

	ON_NOTIFY(TCN_SELCHANGE, IDCT_TAB_ORDERTYPE, OnChangeGroupTab)
	ON_NOTIFY(TCN_SELCHANGE, IDCT_TAB_ORDERCOND, OnChangeCondGroupTab)	
	ON_CBN_SELCHANGE(IDC_CREDITTYPE,    OnChangeCreditType)

	ON_BN_CLICKED(IDCT_RADIO_CASH, OnBtnRadioCash)
	ON_BN_CLICKED(IDCT_RADIO_CREDIT, OnBtnRadioCredit)

	ON_BN_CLICKED(IDCT_RADIO_AUTO, OnBtnRadioAuto)
	ON_BN_CLICKED(IDCT_RADIO_SEMIAUTO, OnBtnRadioSemiAuto)
	
	ON_BN_CLICKED(IDB_ORDERLIST, OnBtnShowOrderlist)
	ON_WM_CTLCOLOR()
	
	ON_BN_CLICKED(IDC_BTN_INIT, &CBaseFrmWnd::OnBnClickedBtnInit)
	
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CBaseFrmWnd, CDialog)
END_DISPATCH_MAP()

// {9D9EABB2-5605-495c-915E-488A4A1AB9A8}
static const IID IID_IBaseFrmWnd = 
{ 0x9d9eabb2, 0x5605, 0x495c, { 0x91, 0x5e, 0x48, 0x8a, 0x4a, 0x1a, 0xb9, 0xa8 } };

BEGIN_INTERFACE_MAP(CBaseFrmWnd, CDialog)
	INTERFACE_PART(CBaseFrmWnd, IID_IBaseFrmWnd, Dispatch)
END_INTERFACE_MAP()


// CBaseFrmWnd �޽��� ó�����Դϴ�.




int CBaseFrmWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

//	int nIdx;

	GetDir_DrfnRoot(m_strAppPath);

	return 0;
}

void CBaseFrmWnd::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	if (m_bInit == FALSE)
		return;

	Resize();
	
}

BOOL CBaseFrmWnd::OnEraseBkgnd(CDC* pDC)
{
	CRect rtClient, rtCtrl;
	GetClientRect(rtClient);

	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);
	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(pDC, rtClient.Width(), rtClient.Height());
	CBitmap* pOldbitmap = MemDC.SelectObject(&bitmap);

	MemDC.FillSolidRect(&rtClient, m_clrBk);
	
	MemDC.Draw3dRect(&m_rtLeftTopWnd, COLOR_BORDER, COLOR_BORDER);
	MemDC.Draw3dRect(&m_rtLeftBtmWnd, COLOR_BORDER, COLOR_BORDER);
	MemDC.Draw3dRect(&m_rtRightWnd, COLOR_BORDER, COLOR_BORDER);
	
	pDC->BitBlt(0, 0, rtClient.Width(), rtClient.Height(), &MemDC, 0, 0, SRCCOPY);
	return TRUE;
}

void CBaseFrmWnd::SetInit()
{
	int nIndex;

	//�� ��Ʈ�� �ʱ�ȭ
	for(nIndex = 0; nIndex < _countof(ORDER_COND_STRING); nIndex++)		
		m_tabOrderCond.InsertItem(nIndex, (LPSTR)ORDER_COND_STRING[nIndex]);	
			

	for(nIndex = 0; nIndex < _countof(ORDER_TYPE_STRING); nIndex++)		
		m_tabOrderType.InsertItem(nIndex, (LPSTR)ORDER_TYPE_STRING[nIndex]);		
}

void CBaseFrmWnd::SetBaseSettingInfo(int nOpenType)
{
	switch(nOpenType)
	{
		case OPENTYPE_STOCK_BUY:
			m_clOrdMinSet.m_enOrdType     = NORMAL_ORDER;
			m_clOrdMinSet.m_strMarketType = SVRORD_MARKETTYPE_STOCK;
			m_clOrdMinSet.m_strMMType     = SVRORD_MMTYPE_BUY;
			break;
		case OPENTYPE_STOCK_SELL:
			m_clOrdMinSet.m_enOrdType     = NORMAL_ORDER;
			m_clOrdMinSet.m_strMarketType = SVRORD_MARKETTYPE_STOCK;
			m_clOrdMinSet.m_strMMType     = SVRORD_MMTYPE_SELL;
			break;
		
	}	

	//������ ���� xml List����
	int nIndex;
	for(nIndex = 0; nIndex < 1/*m_ptrarrCondWnd.GetCount()*/; nIndex++)
	{
		COrdCondWnd* pOrdConWnd = (COrdCondWnd*)m_ptrarrCondWnd.GetAt(nIndex);
		if(pOrdConWnd)
		{
			pOrdConWnd->SetOrdCondWndInit();//SetXMLInfoList(&m_mapXMLTreeInfo);
		}
	}

	ChangeTabWithIndex(0);
	ChangeCondTabWithIndex(0);

	
	m_tabOrderType.SetCurSel(0);
	m_tabOrderCond.SetCurSel(0);
	
	m_OrderTypeWndNormal.SetOrderTypeInit(&m_clOrdMinSet);
	m_OrderTypeWndHogaDiv.SetOrderTypeInit(&m_clOrdMinSet);


	SetCtrlShowStatus();

	if(m_clOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_STOCK) == 0) // ||m_clOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_KOSPI) == 0 ||m_clOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_KOSDAQ) == 0)
		m_nScreenWidth += 50;
	
	Invalidate();	
}

void CBaseFrmWnd::SetCtrlShowStatus()
{
	
	m_radioCash.ShowWindow(SW_SHOW);

	if( m_bUseCredit )
	{
		m_radioCredit.ShowWindow(SW_SHOW);	
		if(m_radioCredit.GetCheck())
			SetCreditSet(TRUE);			
	}
		
	int nIndex;
	if(m_clOrdMinSet.m_strMMType.CompareNoCase(SVRORD_MMTYPE_BUY) == 0)
	{
		
		m_OrderTypeWndNormal.m_btnOrderReg.SetWindowText("�ż����");		
		m_OrderTypeWndHogaDiv.m_btnOrderReg.SetWindowText("�ż����");
		
		m_cmbCreditType.ResetContent();		
		for (nIndex = 0; nIndex < _countof(CREDIT_BUY_TYPE_STRING); nIndex++)
			m_cmbCreditType.AddString(CREDIT_BUY_TYPE_STRING[nIndex]);
		m_cmbCreditType.SetCurSel(0);	
	}
	else
	{		
		m_OrderTypeWndNormal.m_btnOrderReg.SetWindowText("�ŵ����");	
		m_OrderTypeWndHogaDiv.m_btnOrderReg.SetWindowText("�ŵ����");
		
		m_cmbCreditType.ResetContent();		
		for (nIndex = 0; nIndex < _countof(CREDIT_SELL_TYPE_STRING); nIndex++)
			m_cmbCreditType.AddString(CREDIT_SELL_TYPE_STRING[nIndex]);
		m_cmbCreditType.SetCurSel(0);	
	}
		
}

void CBaseFrmWnd::SetLinkPlatformCtrl()
{
	if(m_radioSimiAuto.GetCheck())
	{
		m_OrderTypeWndNormal.SetExpiredDateCtrl(FALSE);
		m_OrderTypeWndHogaDiv.SetExpiredDateCtrl(FALSE);

	}
	else
	{
		m_OrderTypeWndNormal.SetExpiredDateCtrl(TRUE);
		m_OrderTypeWndHogaDiv.SetExpiredDateCtrl(TRUE);

	}
}


void CBaseFrmWnd::OnDestroy()
{
	while (!m_BaseTrInfoList.IsEmpty())
		delete m_BaseTrInfoList.RemoveHead();


	if (m_pPriceInfo)
	{
		delete m_pPriceInfo;
		m_pPriceInfo = NULL;
	}


	//�ֹ� ���� ������ Release
	int nIdx;
	COrdCondWnd* pOrdConWnd;
	for(nIdx = 0; nIdx < m_ptrarrCondWnd.GetCount(); nIdx++)
	{
		pOrdConWnd = (COrdCondWnd*)m_ptrarrCondWnd.GetAt(nIdx);
		if(pOrdConWnd)
		{
			pOrdConWnd->DestroyWindow();
			delete pOrdConWnd;
			pOrdConWnd = NULL;
		}
	}
	m_ptrarrCondWnd.RemoveAll();


	CDialog::OnDestroy();	

}

void CBaseFrmWnd::Resize()
{
	CRect rtClient, rtTemp;
	GetClientRect(&rtClient);
	//rtClient.DeflateRect(1, 0, 1, 0);

	// �»�� ��������
	m_rtLeftTopWnd.left = rtClient.left;
	m_rtLeftTopWnd.top = rtClient.top;
	m_rtLeftTopWnd.right = m_rtLeftTopWnd.left + WIDTH_LEFT_WND;

	m_rtLeftTopWnd.bottom = m_rtLeftTopWnd.top + HEIGHT_LEFT_TOP_WND;


	rtTemp = m_rtLeftTopWnd;
	rtTemp.DeflateRect(1, 1, 1, 1);
	ResizeTopRect(rtTemp);

	// ���� tab
	CRect rtLeftTab;
	rtLeftTab.left = rtClient.left;
	rtLeftTab.top = m_rtLeftTopWnd.bottom + 1;
	rtLeftTab.right = rtLeftTab.left + WIDTH_LEFT_WND;
	rtLeftTab.bottom = rtLeftTab.top + HEIGHT_TAB_ITEM;

	if ( m_tabOrderCond)
		m_tabOrderCond.MoveWindow(rtLeftTab);

	// ���ϴ� �ֹ�����
	m_rtLeftBtmWnd.left = rtClient.left;
	m_rtLeftBtmWnd.top = rtLeftTab.bottom + 1;
	m_rtLeftBtmWnd.right = m_rtLeftBtmWnd.left + WIDTH_LEFT_WND;
	m_rtLeftBtmWnd.bottom = rtClient.bottom;

	rtTemp = m_rtLeftBtmWnd;
	rtTemp.DeflateRect(1, 1, 1, 1);
	int nCnt = m_ptrarrCondWnd.GetCount();
	for (int i = 0; i < nCnt; i++)
	{
		COrdCondWnd* pOrdCondWnd = (COrdCondWnd*)m_ptrarrCondWnd.GetAt(i);
		if (pOrdCondWnd)
			pOrdCondWnd->MoveWindow(rtTemp);
	}

	// ���� tab
	CRect rtRightTab;
	rtRightTab.left = rtClient.left + WIDTH_LEFT_WND + 1;
	rtRightTab.top = rtClient.top;
	rtRightTab.right = rtClient.right;
	rtRightTab.bottom = rtRightTab.top + HEIGHT_TAB_ITEM;

	if (m_tabOrderType )
		m_tabOrderType.MoveWindow(rtRightTab);

	// ���� �ֹ�����
	m_rtRightWnd.left = rtClient.left + WIDTH_LEFT_WND + 1;
	m_rtRightWnd.top = rtRightTab.bottom + 1;
	m_rtRightWnd.right = rtClient.right;
	m_rtRightWnd.bottom = rtClient.bottom;

	rtTemp = m_rtRightWnd;
	rtTemp.DeflateRect(1, 1, 1, 1);

	if ( m_OrderTypeWndNormal)
		m_OrderTypeWndNormal.MoveWindow(rtTemp);

	if ( m_OrderTypeWndHogaDiv)
		m_OrderTypeWndHogaDiv.MoveWindow(rtTemp);
}

void CBaseFrmWnd::ResizeTopRect(CRect rtTop)
{
	
	rtTop.DeflateRect(1, 1, 1, 1);
	

	CRect rtTemp = rtTop;
	
	//Line 2
	//�����ڵ� static
	rtTemp.bottom = rtTemp.top  + LEN_CTRL_HEIGHT;
	rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX4;
	m_ctrlItemCodeText.MoveWindow(rtTemp);

	CRect rtWnd(0, 0, 0, 0);
	
	m_ctlCodeInput.GetWindowRect(&rtWnd);	


	rtTemp.left = rtTemp.right + LEN_TEXT_TO_CTRL;
	rtTemp.right = rtTemp.right + rtWnd.Width();
	m_rtCode = rtTemp;
	
	if (m_ctlCodeInput)
		m_ctlCodeInput.MoveWindow(&rtTemp);

	/*pWnd = GetDlgItem(IDC_PIC_CODENAME);
	if (pWnd)
		pWnd->GetWindowRect(&rtWnd);*/

	rtTemp.left = rtTemp.right + LEN_CTRL_HGAPTYPE1;
	//if (IsEquitiesMap())
	{
		rtTemp.right = rtTemp.right + rtWnd.Width();
		//m_ctlStkCodeName.MoveWindow(&rtTemp);
		
	}

	rtTemp.left = rtTemp.right + LEN_CTRL_HGAPTYPE1;
	rtTemp.right = rtTemp.right + LEN_CTRL_50;
	//m_rdoStk.MoveWindow(&rtTemp);
	//m_rdoFO.MoveWindow(&rtTemp);

	rtTemp.left = rtTemp.right + LEN_CTRL_HGAPTYPE1;
	rtTemp.right = rtTemp.right + LEN_CTRL_70;
	//m_rdoElw.MoveWindow(&rtTemp);
	//m_rdoSFO.MoveWindow(&rtTemp);
	// 20120723 ssj - �����ڵ��ֹ� <<

	//Line 3
	//SMS�뺸 üũ�ڽ�
	rtTemp.top	   = rtTemp.bottom + LEN_CTRL_VGAP + 4;
	rtTemp.bottom  = rtTemp.top + LEN_CTRL_HEIGHT;


	rtTemp.left = rtTop.left;
	rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX4;
	m_stcAutoTitle.MoveWindow(rtTemp);

	//�ڵ� ���� ��ư
	rtTemp.left = rtTemp.right + LEN_TEXT_TO_CTRL;
	rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX4 + 20;
	m_radioAuto.MoveWindow(rtTemp);

	//���ڵ� ���� ��ư
	rtTemp.left = rtTemp.right + LEN_CTRL_HGAPTYPE1;
	rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX4 + 20;
	m_radioSimiAuto.MoveWindow(rtTemp);



	//����/�ſ� ���� ��ư
	rtTemp.top	   = rtTemp.bottom + LEN_CTRL_VGAP + 4;
	rtTemp.bottom  = rtTemp.top + LEN_CTRL_HEIGHT;

	rtTemp.left = rtTop.left;
	rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX4;
	m_stcCashTitle.MoveWindow(rtTemp);

	rtTemp.left  = rtTemp.right + LEN_TEXT_TO_CTRL;
	rtTemp.right = rtTemp.left + LEN_CTRL_50;
	m_radioCash.MoveWindow(rtTemp);

	rtTemp.left  = rtTemp.right + LEN_TEXT_TO_CTRL;
	rtTemp.right = rtTemp.left + LEN_CTRL_50;
	m_radioCredit.MoveWindow(rtTemp);

	//�ſ�Ÿ��
	rtTemp.left  = rtTemp.right + 10;
	rtTemp.right = rtTemp.left + LEN_CTRL_100;
	rtTemp.bottom += 100;
	m_cmbCreditType.MoveWindow(rtTemp);
	rtTemp.bottom -= 100;

	//������
	rtTemp.left  = rtTemp.right + LEN_CTRL_HGAPTYPE1;
	rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX8;
	m_ExpireDateCtrl.MoveWindow(rtTemp);	
	


	//if (IsEquitiesMap())
	{
		rtTemp.right = rtTop.right - 10;
		rtTemp.left  = rtTemp.right - LEN_CTRL_WIDTHX4;	
		m_btnInit.MoveWindow(rtTemp);
	}

}

void CBaseFrmWnd::ChangeSkinColor(long lpColor)
{
	ST_CLIENTCOLOR* pstClrClient = (ST_CLIENTCOLOR*)lpColor;

	if(!pstClrClient)
		return;

	m_clrBk = pstClrClient->m_clrBkGnd;
	if(m_brushBk.DeleteObject())
		m_brushBk.CreateSolidBrush(m_clrBk);

	m_OrderTypeWndNormal.ChangeSkinColor(lpColor);
	m_OrderTypeWndHogaDiv.ChangeSkinColor(lpColor);
	

	int nCount = m_ptrarrCondWnd.GetCount();
	int nIdx;
	for(nIdx = 0; nIdx < nCount; nIdx++)
	{
		COrdCondWnd* pOrdCondWnd = (COrdCondWnd*)m_ptrarrCondWnd.GetAt(nIdx);
		if(pOrdCondWnd)
			pOrdCondWnd->ChangeSkinColor(lpColor);
	}


	Invalidate();
}

void CBaseFrmWnd::OnChangeGroupTab(NMHDR* pNMHDR, LRESULT* pResult)
{
	int nIndex = m_tabOrderType.GetCurSel();
	ChangeTabWithIndex(nIndex);

}

void CBaseFrmWnd::OnChangeCondGroupTab(NMHDR* pNMHDR, LRESULT* pResult)
{
	//������ ���� xml List����
	InitOrdCondSet();

	int nIndex = m_tabOrderCond.GetCurSel();
	ChangeCondTabWithIndex(nIndex);
}

void CBaseFrmWnd::OnChangeCreditType()
{
	ShowLoanDateCtrl();
}

void CBaseFrmWnd::InitOrdCondSet()
{
	if(!m_bConTabInit)
	{
		int nIndex;
		for(nIndex = 1; nIndex < m_ptrarrCondWnd.GetCount(); nIndex++)
		{
			COrdCondWnd* pOrdConWnd = (COrdCondWnd*)m_ptrarrCondWnd.GetAt(nIndex);
			if(pOrdConWnd)
			{
				pOrdConWnd->SetOrdCondWndInit();

				if (nIndex == COND_BM) // BM������ ��� ���� ��Ʈ�ѵ��� ��ġ�� ���忡 ���� ������ �־�� �Ѵ�
				{
					pOrdConWnd->m_ctrlMapLoad.MoveCodeInputCtrl();					
				}
			}
		}
		m_bConTabInit = TRUE;			
	}
}

void CBaseFrmWnd::ChangeTabWithIndex(int nIndex)
{
	if(nIndex == 0)
	{
		m_OrderTypeWndNormal.ShowWindow(SW_SHOW);
		m_OrderTypeWndHogaDiv.ShowWindow(SW_HIDE);


		m_OrderTypeWndNormal.MoveControlOnTabChange();
		m_clOrdMinSet.m_enOrdType = NORMAL_ORDER;
	}
	else if(nIndex == 1)
	{
		m_OrderTypeWndHogaDiv.ShowWindow(SW_SHOW);
		m_OrderTypeWndNormal.ShowWindow(SW_HIDE);		
	

		m_OrderTypeWndHogaDiv.MoveControlOnTabChange();
		m_clOrdMinSet.m_enOrdType = HOGADIV_ORDER;
	}
	
	m_OrderTypeWndNormal.OnTypeTabSelChange(nIndex);
	m_OrderTypeWndHogaDiv.OnTypeTabSelChange(nIndex);

}


void CBaseFrmWnd::ChangeCondTabWithIndex(int nIndex)
{
	int nIdx;
	COrdCondWnd* pOrdCondWnd = (COrdCondWnd*)m_ptrarrCondWnd.GetAt(nIndex);
	if(pOrdCondWnd)
		pOrdCondWnd->ShowWindow(SW_SHOW);

	int nCount = m_ptrarrCondWnd.GetCount();
	if(!m_bConTabInit)
		nCount = 1;
		
	for(nIdx = 0; nIdx < nCount; nIdx++)
	{
		COrdCondWnd* pOrdCondWnd = (COrdCondWnd*)m_ptrarrCondWnd.GetAt(nIdx);
		if(pOrdCondWnd && (nIndex != nIdx))
			pOrdCondWnd->ShowWindow(SW_HIDE);
	}	
}

HBRUSH CBaseFrmWnd::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	if(nCtlColor == CTLCOLOR_STATIC)
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(m_clrText);
		hbr = m_brushBk;
	}
	else if(pWnd->GetDlgCtrlID() == IDCT_RADIO_AUTO)	
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(m_clrText);
		hbr = m_brushBk;
	}

	return hbr;
}

COrdTypeBase CBaseFrmWnd::GetOrderTypeInfo()
{
	int nOrdTypeSel = m_tabOrderType.GetCurSel();
	if(nOrdTypeSel == 0)
		return m_OrderTypeWndNormal.GetOrderTypeInfo();
	else if(nOrdTypeSel == 1)
		return m_OrderTypeWndHogaDiv.GetOrderTypeInfo();
	
	return m_OrderTypeWndNormal.GetOrderTypeInfo();
}

COrdCondBase CBaseFrmWnd::GetAllConditionInfo(BOOL& bValid, CString &strErrorMsg)
{
	BOOL bErrCheck = TRUE;
	int nTotCond = 0;	  //���Ǽ� ����
	int nOneConde = 0;
	CString strExpResult = ""; //���ǥ���� ����

	COrdCondBase cOrdCondOne;			//���� ���� ���
	COrdCondBase cOrdCondTot;

	int nCount = m_ptrarrCondWnd.GetCount();

	if(!m_bConTabInit)
		nCount = 1;

	int nIndex;
	for(nIndex = 0; nIndex < nCount; nIndex++)
	{
		COrdCondWnd* pOrdConWnd = (COrdCondWnd*)m_ptrarrCondWnd.GetAt(nIndex);
		if(pOrdConWnd)
		{
			cOrdCondOne = pOrdConWnd->GetOrderConditionInfo(bErrCheck, strErrorMsg);
			if(bErrCheck == FALSE)
			{
				bValid = FALSE;

				return cOrdCondTot;
			}

			nOneConde = cOrdCondOne.GetCondCount();
			nTotCond += nOneConde;

			if(nOneConde > 0 && strExpResult != "")
			{
				if(	strExpResult.ReverseFind('|') != (strExpResult.GetLength() -1) )
					strExpResult += _T("|");
			}
			strExpResult += cOrdCondOne.GetCondExp();

			if(pOrdConWnd->m_strCondType.CompareNoCase(_T("BM����")) == 0)
			{
				cOrdCondTot.SetCondCode1(cOrdCondOne.GetCondCode1());
				cOrdCondTot.SetCondCode2(cOrdCondOne.GetCondCode2());
				cOrdCondTot.SetCondCode3(cOrdCondOne.GetCondCode3());
				cOrdCondTot.SetCondCode4(cOrdCondOne.GetCondCode4());
			}
			cOrdCondTot.SetUserDefineList(&cOrdCondOne.m_listUser_Define);

			if (pOrdConWnd->m_ctrlMapLoad.m_bAddSysCtrl)
			{
				cOrdCondTot.m_nEvalUnit = pOrdConWnd->m_ctrlMapLoad.GetSelEvalUnit();
				cOrdCondTot.m_nBasePriceType = pOrdConWnd->m_ctrlMapLoad.GetBasePriceType();
				cOrdCondTot.m_strBasePrice = pOrdConWnd->m_ctrlMapLoad.GetBasePrice();
			}
		}
	}	
	strExpResult += _T("!");
	cOrdCondTot.SetCondCount(nTotCond);
	cOrdCondTot.SetCondExp(strExpResult);	

	return cOrdCondTot;
}


void CBaseFrmWnd::GetOrdBaseInfo()
{
	m_clOrdBase.m_strMMType			= m_clOrdMinSet.m_strMMType;			//�Ÿű��� '1':�ŵ�,  '2':�ż�
	m_clOrdBase.m_strMarketType		= m_clOrdMinSet.m_strMarketType;	//S(Stock), E(ELW), F(FUT), O(OPT)
	m_clOrdBase.m_enOrdType			= m_clOrdMinSet.m_enOrdType;

	CString strItemCode, strItemName;
	strItemCode = GetCurCode();
	strItemName = GetCurCodeName();
	CString strAccNum, strAccPass;
	GetParent()->SendMessage(RMSG_GET_ACCOUNTNUM, (WPARAM)&strAccNum, (LPARAM)&strAccPass);

	m_clOrdBase.m_strMarketType = SVRORD_MARKETTYPE_STOCK;

	m_clOrdBase.m_nAutoFlag			= GetAutoFlag();			//���ڵ� Flag '0':�ڵ�, '1':���ڵ�

	m_clOrdBase.m_strItemCode.Format("%-8s", strItemCode);		//�����ڵ�
	m_clOrdBase.m_strItemName = strItemName;					//�����

	m_clOrdBase.m_bCredit = (m_radioCredit.GetCheck() == BST_CHECKED);


	//>>[KSJ000000026] �ſ��ֹ��߰�, �ֹ������߰�
	CString strExpireDate;
	if(m_clOrdBase.m_bCredit)
	{
		if (IsCreditDateValid())
		{
			m_ExpireDateCtrl.GetWindowText(strExpireDate);
			strExpireDate.Remove('-');
		}
		else
			strExpireDate = "        ";		
	}
	else
		strExpireDate = "";	
	
	m_clOrdBase.m_strExpireDate = strExpireDate;
	
	CString strIp;
	LPCTSTR pstrIP = (LPCTSTR)(GetParent()->SendMessage(UMSG_GET_IP, 0, 0));
	if (pstrIP != NULL)
		strIp = pstrIP;
	
	m_clOrdBase.m_strPcIp = strIp;
}

void CBaseFrmWnd::MakePacketForSendTr(CString strTrID, CString strOther, CString strOther2)
{
	if(strTrID.CompareNoCase(TR_SET_COND) == 0)
	{
		BOOL bError = TRUE;
		GetOrdBaseInfo();
		CString strErrorMsg;
		COrdCondBase cOrdCondTot = GetAllConditionInfo(bError, strErrorMsg);	
		if(!bError)
		{
			if (strErrorMsg.GetLength() > 0)
				DefMessageBox(GetSafeHwnd(), strErrorMsg);
			else
				DefMessageBox(GetSafeHwnd(), _T("�� �Է� ���� ���� �մϴ�."));
			return;
		}
		COrdTypeBase cOrdTypeTot = GetOrderTypeInfo();
		
 		TR_ORDER_REGIN stOrdRegIn;
		int nCount = cOrdCondTot.GetCondCount();

		int nLen = sizeof(TR_ORDER_REGIN);

	
 		memset(&stOrdRegIn, 0x20, SZ_TR_ORDER_REGIN);
	//	stOrdRegIn.stUser_Define = new User_Define[nCount];
		int nSize = SZ_TR_ORDER_REGIN - (sizeof(User_Define) *  (LEN_MAXCONDCOUNT - nCount));
	
		
  		memcpy(stOrdRegIn.cJobFlag,	 m_strJobFlag, min(m_strJobFlag.GetLength(), sizeof(stOrdRegIn.cJobFlag)));
  		
		TRSetOrderBase(&stOrdRegIn, &m_clOrdBase);
 		TRSetOrderType(&stOrdRegIn, &cOrdTypeTot);
		TRSetOrderCond(&stOrdRegIn, &cOrdCondTot);

		if(CheckPacket(&stOrdRegIn) == FALSE)
			return; 		
				
		 CopyString(stOrdRegIn.sMassId, sizeof(stOrdRegIn.sMassId), MASS_ID);
		

	    nSize+= 5 ;  //add trcode size
		char* pData = new char[nSize +  1];
		memset(pData, 0x00, sizeof(nSize + 1));
		memcpy(pData, strTrID, 5);
		memcpy(pData+5, (char*)&stOrdRegIn, nSize);
		
		theApp.SendToServerEx(strTrID, (BYTE*)pData, nSize, GetParent()->m_hWnd ) ;
		

	}
}

void CBaseFrmWnd::TRSetOrderBase(TR_ORDER_REGIN* pstOrdRegIn, COrdBase* cOrdBase)
{
	char tmpVal[100] = {0,};

	memcpy(pstOrdRegIn->szMMType,	 cOrdBase->GetCurMMType(),		min(sizeof(pstOrdRegIn->szMMType), cOrdBase->GetCurMMType().GetLength()));
	memcpy(pstOrdRegIn->szMarketType, cOrdBase->GetOrdMarketType(),	min(sizeof(pstOrdRegIn->szMarketType), cOrdBase->GetOrdMarketType().GetLength()));


	INT2STR_BUF(tmpVal, sizeof(pstOrdRegIn->szOrdType), cOrdBase->GetCurOrderType());				
	memcpy(pstOrdRegIn->szOrdType,	 tmpVal,	sizeof(pstOrdRegIn->szOrdType));

	memcpy(pstOrdRegIn->szUserID,	m_strID,			min(sizeof(pstOrdRegIn->szUserID), m_strID.GetLength()));

	CString strAccNum, strAccPass;
	GetParent()->SendMessage(RMSG_GET_ACCOUNTNUM, (WPARAM)&strAccNum, (LPARAM)&strAccPass);
	memcpy(pstOrdRegIn->szAccount,	strAccNum,		min(sizeof(pstOrdRegIn->szAccount), strAccNum.GetLength()));	
	memcpy(pstOrdRegIn->szAccPass,	strAccPass,		min(sizeof(pstOrdRegIn->szAccPass), strAccPass.GetLength()));	


	INT2STR_BUF(tmpVal, sizeof(pstOrdRegIn->szAutoFlag), cOrdBase->GetOrderFlag());	
	memcpy(pstOrdRegIn->szAutoFlag,	tmpVal,		sizeof(pstOrdRegIn->szAutoFlag));
		
	memcpy(pstOrdRegIn->szShcode,	cOrdBase->GetItemCode(),			min(sizeof(pstOrdRegIn->szShcode), cOrdBase->GetItemCode().GetLength()));
	
	INT2STR_BUF(tmpVal, sizeof(pstOrdRegIn->szCredit), cOrdBase->GetCredit());	

	memcpy(pstOrdRegIn->sPcIp,	cOrdBase->GetIP(),			min(sizeof(pstOrdRegIn->sPcIp), cOrdBase->GetIP().GetLength()));

	//>>[KSJ000000026] �ſ��ֹ��߰�, �ֹ������߰�
	if(cOrdBase->GetCredit())
	{	
		// '0':����, '1':�������ڽű�, '2':�ڱ����ڽű�, '3':�������, '4':�ڱ���ֽű�, '5':�������ڻ�ȯ, '6':�ڱ����ڻ�ȯ, '7':������ֻ�ȯ, '8':�ڱ���ֻ�ȯ, '9':��Ź�㺸�����ȯ"
		CString strCreditVal = GetCreditCmbValue(cOrdBase->GetCurMMType());
		memcpy(pstOrdRegIn->szCredit,	strCreditVal,		sizeof(pstOrdRegIn->szCredit));
	}
	else
		memcpy(pstOrdRegIn->szCredit,	tmpVal,		sizeof(pstOrdRegIn->szCredit));

	memcpy(pstOrdRegIn->szCrdate,	cOrdBase->GetExpireDate(), min(cOrdBase->GetExpireDate().GetLength(), sizeof(pstOrdRegIn->szCrdate)));
	//<<[KSJ000000026] �ſ��ֹ��߰�, �ֹ������߰�

	memcpy(pstOrdRegIn->szDestTime,	  "      ", sizeof(pstOrdRegIn->szDestTime));	/* �����ð� �ֹ��� ���� �ð�.(HHMMSS)        */

}

void CBaseFrmWnd::TRSetOrderType(TR_ORDER_REGIN* pstOrdRegIn, COrdTypeBase* cOrdType)
{
	char tmpVal[100] = {0,};
	memcpy(pstOrdRegIn->szExpiredate, cOrdType->GetExpireDate(),	min(sizeof(pstOrdRegIn->szExpiredate),	cOrdType->GetExpireDate().GetLength()));	

	memcpy(pstOrdRegIn->szPriceType, cOrdType->GetPriceType(),	sizeof(pstOrdRegIn->szPriceType));
	memcpy(pstOrdRegIn->szOrdBaseQty, cOrdType->GetBaseQty(),	sizeof(pstOrdRegIn->szOrdBaseQty));

	//���� �Է� ����
	INT2STR_BUF(tmpVal, sizeof(pstOrdRegIn->sQtyGb), cOrdType->GetQtyGb());
	memcpy(pstOrdRegIn->sQtyGb,		tmpVal,	sizeof(pstOrdRegIn->sQtyGb));	

	CStringArray* psarrQty = cOrdType->GetOrdReqQty();
	int nIndex;
	CString strData;
	for(nIndex = 0; nIndex < psarrQty->GetCount(); nIndex++)
	{
		strData = psarrQty->GetAt(nIndex);
		memcpy(pstOrdRegIn->szOrdReqQty[nIndex], strData,	min(strData.GetLength(), sizeof(pstOrdRegIn->szOrdReqQty)));
	}

	CStringArray* psarrPrice = cOrdType->GetOrdReqPrice();
	int nSize = 0;
	for(nIndex = 0; nIndex < psarrPrice->GetCount(); nIndex++)
	{
		strData = psarrPrice->GetAt(nIndex);
		strData.Trim();		
		memcpy(pstOrdRegIn->szOrdReqPrice + nSize, strData,	strData.GetLength());
		nSize += strData.GetLength();
	}

 	INT2STR_BUF(tmpVal, sizeof(pstOrdRegIn->szOrdCnt), cOrdType->GetOrdDivCnt());
 	memcpy(pstOrdRegIn->szOrdCnt,		tmpVal,	sizeof(pstOrdRegIn->szOrdCnt));	

	INT2STR_BUF(tmpVal, sizeof(pstOrdRegIn->szInterval), cOrdType->GetOrdUnit());
	memcpy(pstOrdRegIn->szInterval,		tmpVal,	sizeof(pstOrdRegIn->szInterval));	

	//���ұ���
	INT2STR_BUF(tmpVal, sizeof(pstOrdRegIn->sDivGb), cOrdType->GetDivStd());
	memcpy(pstOrdRegIn->sDivGb,		tmpVal,	sizeof(pstOrdRegIn->sDivGb));	

	//���ҹ���
	INT2STR_BUF(tmpVal, sizeof(pstOrdRegIn->sDivDir), cOrdType->GetDivWay());
	memcpy(pstOrdRegIn->sDivDir,	tmpVal,	sizeof(pstOrdRegIn->sDivDir));	
	
}

void CBaseFrmWnd::TRSetOrderCond(TR_ORDER_REGIN* pstOrdRegIn, COrdCondBase* cOrdCond)
{
	BOOL bConvert = FALSE;
	if (m_ptrarrCondWnd.GetSize() > 0)
	{
		COrdCondWnd *pCondWnd = (COrdCondWnd *)m_ptrarrCondWnd.GetAt(COND_PL);
		if (pCondWnd)
		{
			//if (IsEquitiesMap())
			{
				if (IsWindow(pCondWnd->m_ctrlMapLoad.m_btnWon.GetSafeHwnd()))
				{
					if (pCondWnd->m_ctrlMapLoad.m_btnWon.GetCheck() == BST_CHECKED)
						bConvert = TRUE;
				}
			}
			
		}
	}

	char tmpVal[100] = {0,};
	int nCoundCount = cOrdCond->GetCondCount();
	INT2STR_BUF(tmpVal, sizeof(pstOrdRegIn->szCondCnt), nCoundCount);
	memcpy(pstOrdRegIn->szCondCnt,	tmpVal,	sizeof(pstOrdRegIn->szCondCnt));	

	memcpy(pstOrdRegIn->szCondExp,	cOrdCond->GetCondExp(),		min(sizeof(pstOrdRegIn->szCondExp),	cOrdCond->GetCondExp().GetLength()));	

	INT2STR_BUF(tmpVal, sizeof(pstOrdRegIn->szCondFlag), cOrdCond->GetCondFlag());
	memcpy(pstOrdRegIn->szCondFlag,	tmpVal,		sizeof(pstOrdRegIn->szCondFlag));	

	memcpy(pstOrdRegIn->szCode1,		cOrdCond->GetCondCode1(),	min(sizeof(pstOrdRegIn->szCode1),	cOrdCond->GetCondCode1().GetLength()));	
	memcpy(pstOrdRegIn->szCode2,		cOrdCond->GetCondCode2(),	min(sizeof(pstOrdRegIn->szCode2),	cOrdCond->GetCondCode2().GetLength()));	
	memcpy(pstOrdRegIn->szCode3,		cOrdCond->GetCondCode3(),	min(sizeof(pstOrdRegIn->szCode3),	cOrdCond->GetCondCode3().GetLength()));	
	memcpy(pstOrdRegIn->szCode4,		cOrdCond->GetCondCode4(),	min(sizeof(pstOrdRegIn->szCode4),	cOrdCond->GetCondCode4().GetLength()));	
	
	CString strVal;
	strVal.Format("%d", cOrdCond->m_nBasePriceType);
	memcpy(pstOrdRegIn->sAvgPrcFlag,	strVal,						min(sizeof(pstOrdRegIn->sAvgPrcFlag),	strVal.GetLength()));
	memcpy(pstOrdRegIn->sAvgPrc,		cOrdCond->m_strBasePrice,	min(sizeof(pstOrdRegIn->sAvgPrc),		cOrdCond->m_strBasePrice.GetLength()));

	POSITION pos = cOrdCond->m_listUser_Define.GetHeadPosition();
	int nIndex;
	for(nIndex = 0; pos && nIndex < nCoundCount; nIndex++)
	{
		User_Define stUserDefine = cOrdCond->m_listUser_Define.GetNext(pos);

		memcpy(pstOrdRegIn->stUser_Define[nIndex].giIndexNo			 ,        stUserDefine.giIndexNo 				     , sizeof(stUserDefine.giIndexNo 			  ));                        
		memcpy(pstOrdRegIn->stUser_Define[nIndex].giGroupNo			 ,        stUserDefine.giGroupNo 					   , sizeof(stUserDefine.giGroupNo 			  ));                        
		memcpy(pstOrdRegIn->stUser_Define[nIndex].giGroupIdxCnt		,       stUserDefine.giGroupIdxCnt 				 , sizeof(stUserDefine.giGroupIdxCnt 	   ));                        
		memcpy(pstOrdRegIn->stUser_Define[nIndex].giTargetBase		,       stUserDefine.giTargetBase 				 , sizeof(stUserDefine.giTargetBase 	   ));                      

	
		if (bConvert)
		{
			CString strType;
			strType = CString(stUserDefine.giType, sizeof(stUserDefine.giType));
			strType.Trim();
			
			CString strConvertType = strType;
			if (strType.GetLength() >3 && strType.Left(3) == "-10" && strType != "-108") // "-108"�� ���ܶ�� �Ѵ�
			{
				//if (IsEquitiesMap())
				//	strConvertType = "-12" + strType.Right(1);
				//else
				//	strConvertType = "-11" + strType.Right(1);

				strConvertType = "-12" + strType.Right(1);
			}

			memcpy(pstOrdRegIn->stUser_Define[nIndex].giType, strConvertType, min(sizeof(pstOrdRegIn->stUser_Define[nIndex].giType), strConvertType.GetLength()));
		}
		else		
		{
			memcpy(pstOrdRegIn->stUser_Define[nIndex].giType				 ,        stUserDefine.giType 	 				     , sizeof(stUserDefine.giType 	 			    ));                      
		}
		
		memcpy(pstOrdRegIn->stUser_Define[nIndex].giType1			   ,        stUserDefine.giType1 	 					   , sizeof(stUserDefine.giType1 	 			 ));                        
		memcpy(pstOrdRegIn->stUser_Define[nIndex].giType2			   ,        stUserDefine.giType2 	 			       , sizeof(stUserDefine.giType2 	 			   ));                        
		memcpy(pstOrdRegIn->stUser_Define[nIndex].giSTerm			   ,        stUserDefine.giSTerm 						   , sizeof(stUserDefine.giSTerm 				 ));                        
		memcpy(pstOrdRegIn->stUser_Define[nIndex].giETerm			   ,        stUserDefine.giETerm 					     , sizeof(stUserDefine.giETerm 				  ));                        
		memcpy(pstOrdRegIn->stUser_Define[nIndex].giRank				 ,        stUserDefine.giRank 						   , sizeof(stUserDefine.giRank 				   ));                      
		memcpy(pstOrdRegIn->stUser_Define[nIndex].giTrend			   ,        stUserDefine.giTrend 						   , sizeof(stUserDefine.giTrend 				 ));                        
		memcpy(pstOrdRegIn->stUser_Define[nIndex].giSignalCnt1		,       stUserDefine.giSignalCnt1 				 , sizeof(stUserDefine.giSignalCnt1 	   ));                      
		memcpy(pstOrdRegIn->stUser_Define[nIndex].giSignalCnt2		,       stUserDefine.giSignalCnt2 				 , sizeof(stUserDefine.giSignalCnt2 	   ));                      
		memcpy(pstOrdRegIn->stUser_Define[nIndex].giResultViewNum,	      stUserDefine.giResultViewNum 	     , sizeof(stUserDefine.giResultViewNum    ));                       
		

		memcpy(&pstOrdRegIn->stUser_Define[nIndex].IndexType,		&stUserDefine.IndexType,			sizeof(pstOrdRegIn->stUser_Define[nIndex].IndexType));	
		memcpy(&pstOrdRegIn->stUser_Define[nIndex].SearchType,		&stUserDefine.SearchType,			sizeof(pstOrdRegIn->stUser_Define[nIndex].SearchType));
		memcpy(&pstOrdRegIn->stUser_Define[nIndex].Operator,		&stUserDefine.Operator,			sizeof(pstOrdRegIn->stUser_Define[nIndex].Operator));
		memcpy(&pstOrdRegIn->stUser_Define[nIndex].Reverse,			&stUserDefine.Reverse,			sizeof(pstOrdRegIn->stUser_Define[nIndex].Reverse));
		memcpy(&pstOrdRegIn->stUser_Define[nIndex].IdxContiGubun,	&stUserDefine.IdxContiGubun,		sizeof(pstOrdRegIn->stUser_Define[nIndex].IdxContiGubun));
		memcpy(&pstOrdRegIn->stUser_Define[nIndex].Element,			&stUserDefine.Element,			sizeof(pstOrdRegIn->stUser_Define[nIndex].Element));
		memcpy(pstOrdRegIn->stUser_Define[nIndex].Code,				stUserDefine.Code,				sizeof(pstOrdRegIn->stUser_Define[nIndex].Code));

		int nIndex2;
		for(nIndex2 = 0; nIndex2 < MAX_PARAM; nIndex2++)
		{
			memcpy(&pstOrdRegIn->stUser_Define[nIndex].Param[nIndex2], &stUserDefine.Param[nIndex2], sizeof(stUserDefine.Param[nIndex2]));
		}

		for(nIndex2 = 0; nIndex2 < MAX_CONDI; nIndex2++)
		{
			memcpy(&pstOrdRegIn->stUser_Define[nIndex].Condition[nIndex2], &stUserDefine.Condition[nIndex2], sizeof(stUserDefine.Condition[nIndex2]));
		}
	}
}

void CBaseFrmWnd::ByteOrderRevDouble(LPSTR pDouble)
{
	int nCount, nLength = 4;

	for (nCount = 0; nCount < nLength; nCount++)
	{
		unsigned char chTemp;
		chTemp = *(pDouble + nCount);
		*(pDouble + nCount) = *(pDouble + sizeof(double) - 1 - nCount);
		*(pDouble + sizeof(double) - 1 - nCount) = chTemp;
	}
}

HRESULT CBaseFrmWnd::ReceiveFromMain(long dwKey, LPCSTR szTR, LPCSTR szMsgCode, LPCSTR szMessage, LPVOID	aTRData, long dwTRDateLen)
{
	BOOL bResult = TRUE;  	

	if (dwTRDateLen == 0)	
	{
	}
	else if (dwTRDateLen > 0)
	{		
		if (strcmp(szTR ,TR_SET_COND)==0)
		{	
			Receive_REG((char*)aTRData, dwTRDateLen);
		}
		else
		{
			////TRACEP("1", "");
		}
	}
	return 0L;
}


BOOL CBaseFrmWnd::Receive_REG(LPTSTR pData, DWORD dwDataLen)
{
	if (dwDataLen < sizeof(TR_ORDER_REGOUT))
		return FALSE;

	TR_ORDER_REGOUT stOrder_RegOut;
	memset(&stOrder_RegOut, 0x00, SZ_TR_ORDER_REGOUT);
	memcpy(&stOrder_RegOut, pData, SZ_TR_ORDER_REGOUT);



	return TRUE;
}


LRESULT CBaseFrmWnd::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	CString* pStrData1;
	switch(message)
	{
	
	//case UMSG_GETMARKETTYPE:
	//	{
	//		return CDRCodeTypeInfo::DRCODETYPE_KOSPI_STOCK;
	//	}
	//	break;
	
	case UMSG_REGCONDITION:
		{
			
			OnBtnRegCondition();
		}
		break;
	case UMSG_SETTYPE_VOLCHECK:
		{
		
			ReqCheckVolAvail((BOOL)wParam, (LPCTSTR)lParam);
			
		}
		break;
	case UMSG_TR_STOCKHOGA:
		GetParent()->SendMessage(UMSG_TR_STOCKHOGA, 0, 0);
		break;	
	case UMSG_GET_ORDAUTOFLAG:
		return m_radioSimiAuto.GetCheck();
		break;
	case UMSG_GET_MMTYPE:
		pStrData1 = (CString*)wParam;
		*pStrData1 = m_clOrdMinSet.m_strMMType;
		return 1L;
		break;
	case UMSG_GET_GRID_LOSSANDPROFIT:
		
		return FALSE;

		break;

	case UMSG_GET_TYPE_TAB_CUR_SEL:
		return m_tabOrderType.GetCurSel();

	case UMSG_GET_RDO_CASH_CREDIT:
		if (m_radioCredit.GetCheck() == BST_CHECKED)
			return 1; // �ſ�
		else
			return 0; // ����
	case UMSG_IS_SELL_TAB_SELECTED:
		return IsSellTabSelected();

	default:
		break;	

	}


	return CDialog::WindowProc(message, wParam, lParam);

}

void CBaseFrmWnd::OnBtnRegCondition()
{
	memset(&m_stCurRegItem, 0x00, sizeof(StOrdKey));//[KSJ000000024]�ֹ� ���� ���� ����
	
	UpdateMap();
	ResetElement();
	
	MakePacketForSendTr(TR_SET_COND);
}


void CBaseFrmWnd::OnBtnShowOrderlist()
{

}

void CBaseFrmWnd::UpdateMap()
{
	int nIndex;
	int nCount = m_ptrarrCondWnd.GetCount();
	if(!m_bConTabInit)
		nCount = 1;

	for(nIndex = 0; nIndex < nCount; nIndex++)
	{
		COrdCondWnd* pOrdConWnd = (COrdCondWnd*)m_ptrarrCondWnd.GetAt(nIndex);
		if(pOrdConWnd)
		{
			pOrdConWnd->SendMessage(WM_NOTIFY_MAPLOAD, NM_MAPLOAD_UPDATE, (LPARAM)0);
		}
	}		
}

void CBaseFrmWnd::OnBtnInit()
{
	if (m_bCreateDone == FALSE)
		return;

	InitAllCond();
}

void CBaseFrmWnd::InitAllCond(BOOL bTabSelChange)
{
	int nIndex;
	int nCount = m_ptrarrCondWnd.GetCount();

	if(!m_bConTabInit)
		nCount = 1;

	//������ �ʱ�ȭ
	for(nIndex = 0; nIndex < nCount; nIndex++)
	{
		COrdCondWnd* pOrdCondWnd = (COrdCondWnd*)m_ptrarrCondWnd.GetAt(nIndex);
		if(pOrdCondWnd)
		{
			pOrdCondWnd->m_ctrlMapLoad.SetInitChkCtrl();	

			// ���鵵 �ʱ�ȭ
			pOrdCondWnd->InitAllCondVal();
			if (nCount == 2) // BM���� �� ���� ����鵵 �ʱ�ȭ
			{
				pOrdCondWnd->m_ctrlMapLoad.m_ctlStkCodeInput.SetWindowText("");
				if (pOrdCondWnd->m_ctrlMapLoad.m_pStcStkCodeName)
					pOrdCondWnd->m_ctrlMapLoad.m_pStcStkCodeName->SetWindowText("");
			}
			
		}
	}
	if (bTabSelChange)
		ChangeCondTabMessage(0);

	//�ڵ�,���ڵ�
	if(m_radioAuto.GetSafeHwnd())
		m_radioAuto.SetCheck(TRUE);

	if(m_radioSimiAuto.GetSafeHwnd())
		m_radioSimiAuto.SetCheck(FALSE);


	m_radioCash.EnableWindow(TRUE);
	if (m_bCreditAcnt)
	{
		if (m_clOrdMinSet.m_strMMType.CompareNoCase(SVRORD_MMTYPE_SELL) == 0)
		{
			// �ŵ��� ǥ��. �ż��� ������ ���´�
			m_radioCredit.EnableWindow(TRUE);
			m_cmbCreditType.EnableWindow(TRUE);
			m_ExpireDateCtrl.EnableWindow(TRUE);
		}
	}

	
	InitCreditCtrl();


	//�Ϲ�, ���� �ʱ�ȭ
	InitializeOrdTypeInfo(bTabSelChange);

	SetRegBtnText(m_clOrdMinSet.m_strMMType, SVRORD_JOB_REG);
}

void CBaseFrmWnd::OnBtnRadioAuto()
{
	m_radioAuto.SetCheck(TRUE);
	m_radioSimiAuto.SetCheck(FALSE);
	m_clOrdBase.m_nAutoFlag	= SVRORD_AUTO_YES;

	m_OrderTypeWndNormal.SetExpiredDateCtrl(TRUE);
	m_OrderTypeWndHogaDiv.SetExpiredDateCtrl(TRUE);
}

void CBaseFrmWnd::OnBtnRadioSemiAuto()
{
	m_radioAuto.SetCheck(FALSE);
	m_radioSimiAuto.SetCheck(TRUE);	
	m_clOrdBase.m_nAutoFlag	= SVRORD_AUTO_NO;

	m_OrderTypeWndNormal.SetExpiredDateCtrl(FALSE);
	m_OrderTypeWndHogaDiv.SetExpiredDateCtrl(FALSE);

}

void CBaseFrmWnd::OnBtnRadioCash()
{
	m_radioCash.SetCheck(TRUE);
	m_radioCredit.SetCheck(FALSE);
	m_clOrdBase.m_bCredit = SVRORD_CASH;			//����:SVRORD_CASH(0), �ſ�:SVRORD_CREDIT(1) 
	SetCreditSet(FALSE);
}

void CBaseFrmWnd::OnBtnRadioCredit()
{
	m_radioCash.SetCheck(FALSE);
	m_radioCredit.SetCheck(TRUE);	
	m_clOrdBase.m_bCredit = SVRORD_CREDIT;	
	SetCreditSet(TRUE);
}

void CBaseFrmWnd::SetCreditSet(BOOL bCredit)
{
	if(bCredit)
	{
		m_cmbCreditType.ShowWindow(SW_SHOW);
		ShowLoanDateCtrl();
	}
	else
	{
		m_cmbCreditType.ShowWindow(SW_HIDE);
		m_ExpireDateCtrl.ShowWindow(SW_HIDE);
	}
		
	m_OrderTypeWndNormal.ApplyCreditChange(bCredit);
	m_OrderTypeWndHogaDiv.ApplyCreditChange(bCredit);
}

CString CBaseFrmWnd::GetElement()
{
	return CONDITION_INDEX[m_nElementIndex++];
}

void CBaseFrmWnd::ResetElement()
{
	m_nElementIndex = 0;
}

int CBaseFrmWnd::GetChkCtrlID()
{
	return m_nChkCtrlID;
}

int CBaseFrmWnd::GetCmbCtrlID()
{
	return m_nCmbCtrlID;
}

int CBaseFrmWnd::GetChkCtrlIDAndPlusCnt()
{
	return m_nChkCtrlID++;
}

int CBaseFrmWnd::GetCmbCtrlIDAndPlusCnt()
{
	return m_nCmbCtrlID++;
}

void CBaseFrmWnd::ResetChkCtrlID()
{
	m_nChkCtrlID = INDEX_START_CHKBOX;
}

void CBaseFrmWnd::ResetCmbCtrlID()
{
	m_nCmbCtrlID = INDEX_START_COMBO;
}

void CBaseFrmWnd::SetFlagCredit(int nFlag)
{
	//>>[KSJ000000026] �ſ��ֹ��߰�, �ֹ������߰�

	BOOL bProcess = TRUE;
	if (m_nSellBuy == WND_BUY) // �ż��� ��� ���ָ� ó��
	{
		if (nFlag != 5 && nFlag != 7)
			bProcess = FALSE;		
	}

	if (nFlag > 0 && bProcess)
	{
		m_radioCash.SetCheck(BST_UNCHECKED);
		m_radioCredit.SetCheck(BST_CHECKED);

		m_cmbCreditType.ShowWindow(SW_SHOW);
		SetValueToCreditCmb(nFlag);
	}
	else
	{
		m_radioCredit.SetCheck(FALSE);
		m_radioCash.SetCheck(TRUE);

		m_cmbCreditType.ShowWindow(SW_HIDE);
		m_ExpireDateCtrl.ShowWindow(SW_HIDE);
	}
	//<<[KSJ000000026] �ſ��ֹ��߰�, �ֹ������߰�
}

void CBaseFrmWnd::SetHogaPrice(CString strPrice)
{
	m_OrderTypeWndNormal.SetHogaPrice(strPrice);
	m_OrderTypeWndHogaDiv.SetHogaPrice(strPrice);
}

int CBaseFrmWnd::GetAutoFlag()
{
	int nResult = SVRORD_AUTO_YES;
	if(m_radioSimiAuto.GetCheck())
		nResult = SVRORD_AUTO_NO;

	return nResult;
}

void CBaseFrmWnd::SetAutoFlag(int nFlag)
{
	if(nFlag == SVRORD_AUTO_YES)
	{
		m_radioAuto.SetCheck(TRUE);
		m_radioSimiAuto.SetCheck(FALSE);

		m_OrderTypeWndNormal.EnableExDateCtrl(TRUE);
		m_OrderTypeWndHogaDiv.EnableExDateCtrl(TRUE);
	}
	else
	{
		m_radioAuto.SetCheck(FALSE);
		m_radioSimiAuto.SetCheck(TRUE);

		m_OrderTypeWndNormal.EnableExDateCtrl(FALSE);
		m_OrderTypeWndHogaDiv.EnableExDateCtrl(FALSE);
	}
}

void CBaseFrmWnd::SetOrdInfo(TR_ORDER_REGIN* pstOrdRegIn)
{	
	CString strData;
	int		nData;

	CString strCode;

	//�⺻���� Set//////

	strData = CString(pstOrdRegIn->szShcode, sizeof(pstOrdRegIn->szShcode));
	m_clOrdBase.SetItemCode(strData.Trim()); 
	strCode = strData;

	SetCode(strCode);

	strData = CString(pstOrdRegIn->szMMType, sizeof(pstOrdRegIn->szMMType));
	m_clOrdBase.SetCurMMType(strData.Trim());

	strData = CString(pstOrdRegIn->szMarketType, sizeof(pstOrdRegIn->szMarketType));
	m_clOrdBase.SetOrdMarketType(strData.Trim());

	strData = CString(pstOrdRegIn->szOrdType, sizeof(pstOrdRegIn->szOrdType));
	nData = atoi(strData);
	m_clOrdBase.SetCurOrderType((enORDTYPE)nData);
	ChangeTypeTabMessage(nData - 1);
	//m_tabOrderType.SetCurSel(nData - 1);

	
	strData = CString(pstOrdRegIn->szAutoFlag, sizeof(pstOrdRegIn->szAutoFlag));
	nData = atoi(strData);
	m_clOrdBase.SetOrderFlag(nData); 
	SetAutoFlag(nData);	

	//>>[KSJ000000026] �ſ��ֹ��߰�, �ֹ������߰�
	strData = CString(pstOrdRegIn->szCredit, sizeof(pstOrdRegIn->szCredit));
	int nCredit = atoi(strData);
	
	if(nCredit == SVRORD_CREDIT || nCredit == SVRORD_CREDIT_YU)
		m_clOrdBase.SetCredit(TRUE);
	else 
		m_clOrdBase.SetCredit(FALSE);

	strData = CString(pstOrdRegIn->szCrdate, sizeof(pstOrdRegIn->szCrdate));
	strData.Trim();
	if(!strData.IsEmpty() && strData.GetLength() > 7)
	{
		CTime time(atoi(strData.Left(4)), atoi(strData.Mid(4, 2)), atoi(strData.Mid(6)), 0, 0, 0);
		m_ExpireDateCtrl.SetTime(&time);
	}
	

	//�������� Set/////////////////
	COrdCondBase cOrdCond;

	//���ǽ�
	CString strCondExp = CString(pstOrdRegIn->szCondExp, sizeof(pstOrdRegIn->szCondExp));
	strCondExp.Trim();

	//���Ǳ��� '1':�Ϲ�����(����/�ü�/...), '2':���������
	strData = CString(pstOrdRegIn->szCondFlag, sizeof(pstOrdRegIn->szCondFlag));
	int nCondType = atoi(strData);
	cOrdCond.SetCondFlag(nCondType);

	//���Ǽ� (�ִ� 20��)
	strData = CString(pstOrdRegIn->szCondCnt, sizeof(pstOrdRegIn->szCondCnt));
	int nCondCnt = atoi(strData);
	cOrdCond.SetCondCount(nCondCnt);

	//ǥ����
	strData = CString(pstOrdRegIn->szCondExp, sizeof(pstOrdRegIn->szCondExp));
	cOrdCond.SetCondExp(strData);


	strData = CString(pstOrdRegIn->szCode1, sizeof(pstOrdRegIn->szCode1));
	cOrdCond.SetCondCode1(strData.Trim());
	strData = CString(pstOrdRegIn->szCode2, sizeof(pstOrdRegIn->szCode2));
	cOrdCond.SetCondCode2(strData.Trim());
	strData = CString(pstOrdRegIn->szCode3, sizeof(pstOrdRegIn->szCode3));
	cOrdCond.SetCondCode3(strData.Trim());
	strData = CString(pstOrdRegIn->szCode4, sizeof(pstOrdRegIn->szCode4));
	cOrdCond.SetCondCode4(strData.Trim());

	int nIndex;
	for(nIndex = 0; nIndex < nCondCnt; nIndex++)
		cOrdCond.SetUserDefine(pstOrdRegIn->stUser_Define[nIndex]);

	strData = CString(pstOrdRegIn->sAvgPrcFlag, sizeof(pstOrdRegIn->sAvgPrcFlag));
	cOrdCond.SetBasePriceType(atol(strData));

	strData = CString(pstOrdRegIn->sAvgPrc, sizeof(pstOrdRegIn->sAvgPrc));
	cOrdCond.SetBasePrice(strData, m_nMapMode);

	//�ֹ�Ÿ�� Set//////////////////
	COrdTypeBase cOrdType;
	cOrdType.ClearData();

	//��ȿ�Ⱓ
	strData = CString(pstOrdRegIn->szExpiredate, sizeof(pstOrdRegIn->szExpiredate));
	cOrdType.SetExpireDate(strData.Trim());

	//�ֹ�����
	//[KSJ000000026] �ſ��ֹ��߰�, �ֹ������߰�	
	strData = CString(pstOrdRegIn->szPriceType, sizeof(pstOrdRegIn->szPriceType));
	strData.Trim();
	cOrdType.SetPriceType(strData);

	//���� �Է� ����
	strData = CString(pstOrdRegIn->sQtyGb, sizeof(pstOrdRegIn->sQtyGb));
	cOrdType.SetQtyGb(atoi(strData.Trim()));

	//�⺻����,����
	strData = CString(pstOrdRegIn->szOrdBaseQty, sizeof(pstOrdRegIn->szOrdBaseQty));
	cOrdType.SetBaseQty(strData.Trim());

	//���Ҽ�	
	strData = CString(pstOrdRegIn->szOrdCnt, sizeof(pstOrdRegIn->szOrdCnt));	
	int nOrdCnt = atoi(strData);
	cOrdType.SetOrdDivCnt(nOrdCnt);

	//����
	for(nIndex = 0; nIndex < nOrdCnt; nIndex++)
	{
		strData = CString(pstOrdRegIn->szOrdReqQty[nIndex], 10);
		cOrdType.AddOrdReqQty(strData);
	}

	//����
	int nSize = 0;
	if(nOrdCnt == 1)
	{
		strData = CString(pstOrdRegIn->szOrdReqPrice, sizeof(pstOrdRegIn->szOrdReqPrice));
		cOrdType.AddOrdReqPrice(strData.Trim());
	}
	else
	{	
		for(nIndex = 0; nIndex < nOrdCnt; nIndex++)
		{			
			strData = CString(pstOrdRegIn->szOrdReqPrice + nSize, 2);
			cOrdType.AddOrdReqPrice(strData);
			nSize += 2;
		}
	}

	strData = CString(pstOrdRegIn->szInterval, sizeof(pstOrdRegIn->szInterval));
	cOrdType.SetOrdUnit(atoi(strData.Trim()));

	//���ұ���
	strData = CString(pstOrdRegIn->sDivGb, sizeof(pstOrdRegIn->sDivGb));
	cOrdType.SetDivStd(atoi(strData));
	//���ҹ���
	strData = CString(pstOrdRegIn->sDivDir, sizeof(pstOrdRegIn->sDivDir));
	cOrdType.SetDivWay(atoi(strData));

	//���� ȭ�鿡 �ݿ�////////////////
	SetOrdBaseInfo();
	SetFlagCredit(nCredit);
	SetOrderTypeInfo(cOrdType);
	SetOrderConditionInfo(cOrdCond);

	nData = m_clOrdBase.GetOrderFlag(); 
	if(nData == SVRORD_AUTO_YES)
	{
		m_OrderTypeWndNormal.EnableExDateCtrl(TRUE);
		m_OrderTypeWndHogaDiv.EnableExDateCtrl(TRUE);
	}
	else
	{
		m_OrderTypeWndNormal.EnableExDateCtrl(FALSE);
		m_OrderTypeWndHogaDiv.EnableExDateCtrl(FALSE);
	}
	
	CString strJobFlag = CString(pstOrdRegIn->cJobFlag, sizeof(pstOrdRegIn->cJobFlag));
	CString strMMType  = m_clOrdBase.GetCurMMType();
	SetRegBtnText(strMMType, strJobFlag, pstOrdRegIn);	
}

void CBaseFrmWnd::SetRegBtnText(CString strMMType, CString strJobFlag, TR_ORDER_REGIN* pstOrdRegIn/*= NULL*/)
{
	CString strText1 = _T("�ŵ�");
	CString strText2 = _T("���");
	CString strText = "";


	if(strMMType.CompareNoCase("2") == 0)
	{
		strText1 = _T("�ż�");
		m_strJobFlag = SVRORD_JOB_REG;		
	}
	else
	{
		m_strJobFlag = SVRORD_JOB_REG;
	}

	BOOL bWatching = FALSE;
	if (pstOrdRegIn)
	{
		CString strCode = CString(pstOrdRegIn->szShcode, sizeof(pstOrdRegIn->szShcode));
		CString strMMType = CString(pstOrdRegIn->szMMType, sizeof(pstOrdRegIn->szMMType));
		CString strCredit = CString(pstOrdRegIn->szCredit, sizeof(pstOrdRegIn->szCredit));
		CString strLoanDate = CString(pstOrdRegIn->szCrdate, sizeof(pstOrdRegIn->szCrdate));

		bWatching = CheckWatching(strCode, strMMType, strCredit, strLoanDate);
	}

	if (bWatching == FALSE && strJobFlag.CompareNoCase("S") == 0) // S: ���� // || strJobFlag.CompareNoCase("R") == 0)
	{
		strText2 = _T("����");
		m_strJobFlag = SVRORD_JOB_UPDATE;

		m_radioCash.EnableWindow(FALSE);
		m_radioCredit.EnableWindow(FALSE);
		m_cmbCreditType.EnableWindow(FALSE);
		m_ExpireDateCtrl.EnableWindow(FALSE);
	}


	strText = strText1 + strText2;
	
	m_OrderTypeWndNormal.m_btnOrderReg.SetWindowText(strText);
	m_OrderTypeWndHogaDiv.m_btnOrderReg.SetWindowText(strText);

}

void CBaseFrmWnd::EnableRegBtn(BOOL bEnable)
{
	m_bEnableReg = bEnable;
}

void CBaseFrmWnd::SetOrdBaseInfo()
{
	m_clOrdMinSet.m_strMMType		= m_clOrdBase.GetCurMMType();		//�Ÿű��� '1':�ŵ�,  '2':�ż�
	m_clOrdMinSet.m_strMarketType  	= m_clOrdBase.GetOrdMarketType();	//S(Stock), E(ELW), F(FUT), O(OPT)
	m_clOrdMinSet.m_enOrdType		= m_clOrdBase.GetCurOrderType();	//�ֹ����� '1':�Ϲ��ֹ�, '2':ȣ�������ֹ�, '3':�ð������ֹ�	

	SetCtrlShowStatus();

	//���¼���
	//�����ڵ弼��
}

void CBaseFrmWnd::SetOrderConditionInfo(COrdCondBase clOrdCond)
{
	//�ҷ����� �κ� �߰� ����
	int nCondIndex = 0;
	int nIndex;
	for(nIndex = 0; nIndex < m_ptrarrCondWnd.GetCount(); nIndex++)
	{
		COrdCondWnd* pOrdConWnd = (COrdCondWnd*)m_ptrarrCondWnd.GetAt(nIndex);
		if(pOrdConWnd)
			pOrdConWnd->SetOrderConditionInfo(clOrdCond);		
	}	

}

void CBaseFrmWnd::SetOrderTypeInfo(COrdTypeBase clOrdType)
{
	m_OrderTypeWndNormal.SetOrderTypeInit(&m_clOrdMinSet);
	m_OrderTypeWndHogaDiv.SetOrderTypeInit(&m_clOrdMinSet);

	int nOrdTypeSel = m_tabOrderType.GetCurSel();
	//�ҷ����� �κ� �߰� ����
	if(nOrdTypeSel == 0)
		m_OrderTypeWndNormal.SetOrderTypeInfo(clOrdType);
	else if(nOrdTypeSel == 1)
		m_OrderTypeWndHogaDiv.SetOrderTypeInfo(clOrdType);
}

BOOL CBaseFrmWnd::CheckPacket(TR_ORDER_REGIN* pTrInput)
{
	if (m_strJobFlag.CompareNoCase(SVRORD_JOB_UPDATE) == 0)
	{
		CString strCode = CString(pTrInput->szShcode, sizeof(pTrInput->szShcode));
		CString strMMType = CString(pTrInput->szMMType, sizeof(pTrInput->szMMType));
		CString strCredit = CString(pTrInput->szCredit, sizeof(pTrInput->szCredit));
		CString strLoanDate = CString(pTrInput->szCrdate, sizeof(pTrInput->szCrdate));
		BOOL bWatching = CheckWatching(strCode, strMMType, strCredit, strLoanDate);
		if (bWatching)
		{
			DefMessageBox(GetSafeHwnd(), "�ֹ������� �����������¿����� �����մϴ�");
			return FALSE;
		}

		if (IsMP(strCode, strMMType, strCredit, strLoanDate))
		{
			DefMessageBox(GetSafeHwnd(), E_STR_MP);
			return FALSE;
		}
	}

	int nCondCnd = atoi(CString(pTrInput->szCondCnt, sizeof(pTrInput->szCondCnt)));
	if(nCondCnd < 1)
	{
		DefMessageBox(GetSafeHwnd(), _T("�ϳ� �̻��� ���ǿ� üũ�� �ֽñ� �ٶ��ϴ�."));
		return FALSE;
	}

	char szBuf[9] = { 0x00, };
	memcpy(szBuf, pTrInput->szExpiredate, min(8, sizeof(pTrInput->szExpiredate)));
	CString strExpDate = szBuf;
	strExpDate.Trim();
	if (strExpDate.GetLength() >= 8)
	{
		CString strYear = strExpDate.Mid(0, 4);
		CString strMon = strExpDate.Mid(4, 2);
		CString strDay = strExpDate.Mid(6, 2);
		CTime time = CTime(atol(strYear), atol(strMon), atol(strDay), 0, 0, 0);
		CTimeSpan span = time - CTime::GetCurrentTime();
		if (span.GetDays() > 90)
		{
			DefMessageBox(GetSafeHwnd(), "��ȿ�Ⱓ�� 90���̳��� �����Ͻʽÿ�.");
			return FALSE;
		}
	}

	//�Ϲ��ֹ�&������&����0�ΰ�� Error
	int nOrdType = atoi(CString(pTrInput->szOrdType, sizeof(pTrInput->szOrdType)));
	CString strPriceType = CString(pTrInput->szPriceType, sizeof(pTrInput->szPriceType));
	CString strPrice = CString(pTrInput->szOrdReqPrice, sizeof(pTrInput->szOrdReqPrice));

	if(nOrdType != 1 && m_OrderTypeWndHogaDiv.GetChangeState() == TRUE)
	{
		DefMessageBox(GetSafeHwnd(), "ȣ������ �׸� ������ ������ �ֽ��ϴ�. (����)��ư�� Ŭ���� �ֽʽÿ�.");
		return FALSE;
	}

	BOOL IsTargetPrice = FALSE;
	if(strPrice.Find("J") > -1)
		IsTargetPrice = TRUE;

	strPrice.Replace("J", "");
	strPrice.Trim();
	double dOrdPrice = atof(strPrice);

	if(nOrdType == 1 && (strPriceType == "1" || strPriceType == "9" || strPriceType == "A" || strPriceType == "D") && (IsTargetPrice && dOrdPrice == 0))
	{
		DefMessageBox(GetSafeHwnd(), _T("�ֹ��ܰ��� Ȯ���Ͽ� �ֽñ� �ٶ��ϴ�."));
		return FALSE;
	}

	long lBaseVol = atol(CString(pTrInput->szOrdBaseQty, sizeof(pTrInput->szOrdBaseQty)));
	long lVolume = atol(CString(pTrInput->szOrdReqQty[0], sizeof(pTrInput->szOrdReqQty[0])));
	if(nOrdType == 1) //�Ϲ��ֹ�
	{
		if (pTrInput->sQtyGb[0] == '1') // ����
		{
			if (lVolume == 0)
			{
				//�ֹ�����,���� 0�ΰ��
				DefMessageBox(GetSafeHwnd(), _T("�ֹ������� Ȯ���Ͽ� �ֽñ� �ٶ��ϴ�."));
				return FALSE;
			}
		}
		else // %
		{
			if (lVolume <= 0 || lVolume > 100)
			{
				//�ֹ�����,���� 0�ΰ��
				DefMessageBox(GetSafeHwnd(), _T("�ֹ������� 1~100(%)�̳��� ���̾�� �մϴ�."));
				return FALSE;
			}
		}
	}	
	else if(nOrdType == 2 && lBaseVol == 0)
	{
		DefMessageBox(GetSafeHwnd(), _T("�ֹ�����(����)�� Ȯ���Ͽ� �ֽñ� �ٶ��ϴ�."));
		return FALSE;
	}

	CString strItemCode = CString(pTrInput->szShcode, sizeof(pTrInput->szShcode));
	CString strCode1 = CString(pTrInput->szCode1, sizeof(pTrInput->szCode1));
	CString strCode2 = CString(pTrInput->szCode2, sizeof(pTrInput->szCode2));
	CString strCode3 = CString(pTrInput->szCode3, sizeof(pTrInput->szCode3));
	CString strCode4 = CString(pTrInput->szCode4, sizeof(pTrInput->szCode4));

	strItemCode.Trim();
	strCode1.Trim();
	strCode2.Trim();
	strCode3.Trim();
	strCode4.Trim();


	//BM������ �����ڵ�� ������ ����ó��
	if(strItemCode.CompareNoCase(strCode1.Mid(1)) == 0 || strItemCode.CompareNoCase(strCode2.Mid(1)) == 0 ||
		strItemCode.CompareNoCase(strCode3.Mid(1)) == 0 || strItemCode.CompareNoCase(strCode4.Mid(1)) == 0)
	{
		DefMessageBox(GetSafeHwnd(), _T("BM���ǰ� ������ �����ڵ�� ����� �Ұ��� �մϴ�."));
		return FALSE;
	}

	if(nOrdType > 1 && (m_clOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_FUT) == 0 ||
		m_clOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_OPT) == 0))
	{
		if(strPrice.Find("6") > -1 || strPrice.Find("7") > -1)
		{
			DefMessageBox(GetSafeHwnd(), "������ �ִ� 5ȣ�� ���� �Դϴ�..");
			return FALSE;
		}		
	}

	//���ֿ���ó��
	int nMarketType =CDRCodeTypeInfo::DRCODETYPE_KOSPI_STOCK ;
	if(	m_clOrdMinSet.m_strMMType.CompareNoCase(SVRORD_MMTYPE_BUY) == 0 &&		//�ż�
		(nMarketType == CDRCodeTypeInfo::DRCODETYPE_KOSPI_STOCK || nMarketType == CDRCodeTypeInfo::DRCODETYPE_ELW) && //�ڽ��� or ELW
		m_clOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_FUT) != 0 &&
		m_clOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_OPT) != 0)		//����,�ɼ��� ����
	{	
		if (m_pPriceInfo && m_pPriceInfo->m_nQtyUnit != 0)
		{
			if(m_clOrdMinSet.m_enOrdType == enORDTYPE::NORMAL_ORDER)
			{
				if( lVolume % m_pPriceInfo->m_nQtyUnit != 0) 
				{
					CString strMsg;
					strMsg.Format("�ż������� %d�� ������ �Է��Ͻʽÿ�.", m_pPriceInfo->m_nQtyUnit);
					DefMessageBox(GetSafeHwnd(), strMsg);
					return FALSE;
				}	
			}
			else
			{
				// ȣ������

				// �ż��� ��� ���̽��� üũ(2012-12-21 ��û��: ������(drfn))
				if (lBaseVol % m_pPriceInfo->m_nQtyUnit != 0)
				{
					CString strMsg;
					strMsg.Format("�ż������� %d�� ������ �Է��Ͻʽÿ�.", m_pPriceInfo->m_nQtyUnit);
					DefMessageBox(GetSafeHwnd(), strMsg);
					return FALSE;
				}
				
				// ���� ���յ� üũ(2012-12-21 ��û��: ������(drfn))
				int nSum = 0;
				for(int nIndex = 0; nIndex < 10; nIndex++)
				{
					lVolume = atol(CString(pTrInput->szOrdReqQty[nIndex], sizeof(pTrInput->szOrdReqQty[nIndex])));
					if(lVolume > 0)
					{
						if( lVolume % m_pPriceInfo->m_nQtyUnit != 0) 
						{
							CString strMsg;
							strMsg.Format("�ֹ������� %d�� ������ �Է��Ͻʽÿ�.", m_pPriceInfo->m_nQtyUnit);
							DefMessageBox(GetSafeHwnd(), strMsg);
							return FALSE;
						}	
					}

					nSum = nSum + lVolume;
				}

				if (nSum <= 0)
				{
					CString strMsg;
					strMsg.Format("�������� ������ ��� 0�Դϴ�.", m_pPriceInfo->m_nQtyUnit);
					DefMessageBox(GetSafeHwnd(), strMsg);
					return FALSE;
				}
			}
		}
	}

	if (m_nSellBuy == WND_SELL )
	{
		if (m_clOrdMinSet.m_enOrdType == enORDTYPE::NORMAL_ORDER)
		{
			if (m_OrderTypeWndNormal.m_rdoVolDigit.GetCheck() == BST_CHECKED)
			{
				if( lVolume % m_pPriceInfo->m_nQtyUnit != 0) 
				{
					CString strMsg;
					strMsg.Format("�ŵ������� %d�� ������ �Է��Ͻʽÿ�.", m_pPriceInfo->m_nQtyUnit);
					DefMessageBox(GetSafeHwnd(), strMsg);
					return FALSE;
				}	
			}
		}
	}

	return TRUE;
}


BOOL CBaseFrmWnd::SendTrFromMain(CString strTrCode,CString szData,long nSize, BOOL bFirstSend)
{
	CExSvrAutoOrderDlg* pView = (CExSvrAutoOrderDlg*)GetParent();
	if(pView)
		return pView->SendTr(strTrCode,szData, nSize);
	return 0;
}

void CBaseFrmWnd::ChangeCondTabMessage(int nIndex)
{
	int nCnt = m_tabOrderCond.GetItemCount();
	if (nCnt <= 0)
		return;
		
	m_tabOrderCond.SetCurSel(nIndex);
	NMHDR nmhdr;
	nmhdr.code=TCN_SELCHANGE;
	nmhdr.idFrom = m_tabOrderCond.GetDlgCtrlID();
	nmhdr.hwndFrom = m_tabOrderCond.GetSafeHwnd();
	SendMessage(WM_NOTIFY,m_tabOrderCond.GetDlgCtrlID(),(LPARAM)&nmhdr);	
}

void CBaseFrmWnd::ChangeTypeTabMessage(int nIndex)
{
	int nCnt = m_tabOrderType.GetItemCount();
	if (nCnt <= 0)
		return;

	m_tabOrderType.SetCurSel(nIndex);
	NMHDR nmhdr;
	nmhdr.code=TCN_SELCHANGE;
	nmhdr.idFrom = m_tabOrderType.GetDlgCtrlID();
	nmhdr.hwndFrom = m_tabOrderType.GetSafeHwnd();
	SendMessage(WM_NOTIFY,m_tabOrderType.GetDlgCtrlID(),(LPARAM)&nmhdr);	
}


void CBaseFrmWnd::InitializeOrdInfo(int nSellType, int nCondType, CString strCode)
{	
	if (m_pPriceInfo && m_pPriceInfo->m_strCode != strCode) // ������ �ٲ�� ȣ�������͸� �����
	{
		m_pPriceInfo->ClearPriceInfo();
	}

	int nIndex;
	int nCount = m_ptrarrCondWnd.GetCount();

	if(!m_bConTabInit)
		nCount = 1;

	for(nIndex = 0; nIndex < nCount; nIndex++)
	{
		COrdCondWnd* pOrdCondWnd = (COrdCondWnd*)m_ptrarrCondWnd.GetAt(nIndex);
		if(pOrdCondWnd)
			pOrdCondWnd->m_ctrlMapLoad.SetInitChkCtrl();	
	}	

	ChangeCondTabMessage(nCondType);	

	InitializeOrdTypeInfo();
	
}

void CBaseFrmWnd::InitializeOrdTypeInfo(BOOL bTabSelChange)
{
	if(m_radioCash.GetSafeHwnd())
	{
		m_radioCash.SetCheck(TRUE);
	}

	if(m_radioCredit.GetSafeHwnd())
	{
		m_radioCredit.SetCheck(FALSE);
	}

	SetCreditSet(FALSE);
	
	if (bTabSelChange)
		ChangeTypeTabMessage(0);		

	m_OrderTypeWndNormal.InitCtrlValue();
	m_OrderTypeWndHogaDiv.InitCtrlValue();
}


//>>[0000260] �ս����ѷ�, ��ǥ���ͷ� ���ͷ��� �ڵ����� ���� SJ_KIM(20110720)
void CBaseFrmWnd::Init_ActivationRate()
{
	COrdCondWnd* pCondWnd = (COrdCondWnd*)m_ptrarrCondWnd.GetAt(COND_PL);
	if(pCondWnd)
		pCondWnd->m_ctrlMapLoad.InitActivationRate();
}
//<<[0000260] �ս����ѷ�, ��ǥ���ͷ� ���ͷ��� �ڵ����� ���� SJ_KIM(20110720)

BOOL CBaseFrmWnd::Create(UINT nID,CWnd* pParentWnd)
{
	// TODO: Add your specialized code here and/or call the base class

	HINSTANCE hInstance = AfxGetResourceHandle();
	AfxSetResourceHandle(theApp.m_hInstance);

	BOOL bRet = CDialog::Create(nID, pParentWnd);

	AfxSetResourceHandle(hInstance);
	return bRet;
}

void CBaseFrmWnd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	
	DDX_Control(pDX, IDC_BTN_INIT,			m_btnInit);
	DDX_Control(pDX, IDC_EDT_JONGMOK,		m_ctlCodeInput);	
		
}


BOOL CBaseFrmWnd::OnInitDialog()
{
	CDialog::OnInitDialog();

	
	CString strImagePath;
	GetDir_DrfnRoot(strImagePath);
	strImagePath += "\\Image";

	m_pPriceInfo = new CPriceInfo() ;

	{
		m_stcCashTitle.Create("���ݱ���", WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE, CRect(0, 0, 0, 0), this, IDC_STATIC);
		m_stcCashTitle.SetFont(&m_fontDefault);

		m_radioCash.Create(_T("����"), WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,	CRect(0, 0, 0, 0), this, IDCT_RADIO_CASH);
		m_radioCash.SetFont(&m_fontDefault);
		m_radioCash.SetCheck(TRUE);

		m_radioCredit.Create(_T("�ſ�"), WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON, CRect(0, 0, 0, 0), this, IDCT_RADIO_CREDIT);
		m_radioCredit.SetFont(&m_fontDefault);
	

		//�ſ�Type
		m_cmbCreditType.Create(WS_CHILD | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST, CRect(0, 0, 0, 0), this, IDC_CREDITTYPE);		
		m_cmbCreditType.SetFont(&m_fontDefault);
		m_cmbCreditType.ResetContent();	

		CString strData;
		int nIndex;
		for (nIndex = 0; nIndex < _countof(CREDIT_SELL_TYPE_STRING); nIndex++)
			m_cmbCreditType.AddString(CREDIT_SELL_TYPE_STRING[nIndex]);

		m_cmbCreditType.SetCurSel(0);	
		m_cmbCreditType.ShowWindow(SW_HIDE);


		m_ExpireDateCtrl.Create(WS_VISIBLE | WS_CHILD | WS_TABSTOP | DTS_SHORTDATEFORMAT,
			CRect(0, 0, 0, 0), this, IDCT_EXPIREDATE);
		m_ExpireDateCtrl.SetFont(&m_fontDefault);
		m_ExpireDateCtrl.ShowWindow(SW_HIDE);		
	}

	m_ctrlItemCodeText.Create(_T("�����ڵ�"), WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE, CRect(0, 0, 0, 0), this);
	m_ctrlItemCodeText.SetFont(&m_fontDefault);


	m_stcAutoTitle.Create("�ֹ����", WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE, CRect(0, 0, 0, 0), this, IDC_STATIC);
	m_stcAutoTitle.SetFont(&m_fontDefault);

	m_radioAuto.Create(_T(""), WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
		CRect(0, 0, 0, 0), this, IDCT_RADIO_AUTO);
	m_radioAuto.SetFont(&m_fontDefault);
	m_radioAuto.SetWindowText(_T("�ڵ��ֹ�"));
	m_radioAuto.SetCheck(TRUE);

	m_radioSimiAuto.Create(_T(""), WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON ,
		CRect(0, 0, 0, 0), this, IDCT_RADIO_SEMIAUTO);
	m_radioSimiAuto.SetFont(&m_fontDefault);
	m_radioSimiAuto.SetWindowText(_T("���ڵ��ֹ�"));


	m_tabOrderCond.Create(TCS_FOCUSNEVER | WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, IDCT_TAB_ORDERCOND);
	m_tabOrderCond.SetFont(&m_fontDefault);

	//�ֹ� ���� ������ ����	(����� �� ���ڸ�ŭ)
	for( int nIdx = 0; nIdx < _countof(ORDER_COND_STRING); nIdx++)
	{
		COrdCondWnd* pOrdConWnd = new COrdCondWnd(ORDER_COND_STRING[nIdx]);
		
		pOrdConWnd->SetMapMode(m_nMapMode, ORDER_COND_INT[nIdx]);		
		pOrdConWnd->SetXmlTreeInfo(m_pMapXmlTreeInfo, m_pMapCtrlGroup);
		pOrdConWnd->Create(NULL, _T(""), WS_CHILD | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,	CRect(0, 0, 0, 0), this, ID_ORDER_CONDWND + nIdx);		
		m_ptrarrCondWnd.Add((LPVOID)pOrdConWnd);
	}

	//�ϴ� �ֹ� ���� TAB	
	m_tabOrderType.Create(TCS_FOCUSNEVER | WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, IDCT_TAB_ORDERTYPE);
	m_tabOrderType.SetFont(&m_fontDefault);	
	
	m_OrderTypeWndNormal.SetPriceInfoPtrForTypeWnd(m_pPriceInfo, m_nMapMode, this);
	m_OrderTypeWndHogaDiv.SetPriceInfoPtrForTypeWnd(m_pPriceInfo, m_nMapMode, this);
	
	//�ֹ� Ÿ�� ������ ����
	m_OrderTypeWndNormal.Create(this, NORMAL_ORDER,   &m_clOrdMinSet, IDCT_ORDERWND_NORMAL);
	m_OrderTypeWndHogaDiv.Create(this, HOGADIV_ORDER, &m_clOrdMinSet, IDCT_ORDERWND_HOGADIV);
	

	m_bUseCredit = GetParent()->SendMessage(UMSG_GETUSECREDIT, 0, 0);
		
	CRect rect;
	CWnd *pWnd = GetDlgItem(IDC_PIC_CODENAME);
	if (pWnd)
	{
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);
		pWnd->ShowWindow(SW_HIDE);
	}
	
	m_bInit = TRUE;

	return TRUE;
}
LRESULT CBaseFrmWnd::OnEventCodeInput(WPARAM wParam, LPARAM lParam)
{

	//LPST_CTRLEVENT stEvent = (LPST_CTRLEVENT)lParam;
	//if (strcmp(stEvent->lpszEventName, "LengthFull") == 0 || strcmp(stEvent->lpszEventName, "SelChanged") == 0)
	//{
	//	CString strCode = GetCurCode();

	//	if (IsEquitiesMap())
	//	{
	//		if (m_bElwMode)
	//		{
	//			if (IsELWCode(strCode) == FALSE)
	//				return 0;
	//		}
	//		else
	//		{
	//			if (IsELWCode(strCode))
	//				return 0;
	//		}
	//	}
	
	//	if (m_strCurrentCode == strCode)
	//		return 0L;

	//	m_strCurrentCode = strCode;
	//	SetCodeName(strCode);

	//	// ���񺯰����� �ʱ�ȣ ���� 
	//	m_strJobFlag = SVRORD_JOB_REG;

	//	// ���ǵ� ��� �ʱ�ȭ
	//	int nCount = m_ptrarrCondWnd.GetCount();
	//	for (int nIndex = 0; nIndex < nCount; nIndex++)
	//	{
	//		COrdCondWnd* pOrdCondWnd = (COrdCondWnd*)m_ptrarrCondWnd.GetAt(nIndex);
	//		if(pOrdCondWnd)
	//		{
	//			// ���ǵ� üũǥ�� ����
	//			pOrdCondWnd->m_ctrlMapLoad.SetInitChkCtrl();
	//			
	//			// ���鵵 �ʱ�ȭ
	//			pOrdCondWnd->InitAllCondVal();
	//			if (nIndex == 2) // BM���� �� ���� ����鵵 �ʱ�ȭ
	//			{
	//				pOrdCondWnd->m_ctrlMapLoad.m_ctlStkCodeInput.SetDataText("");
	//				if (pOrdCondWnd->m_ctrlMapLoad.m_pStcStkCodeName)
	//					pOrdCondWnd->m_ctrlMapLoad.m_pStcStkCodeName->SetWindowText("");	
	//			}
	//		}
	//	}		

	//	// �ڵ����� �ʱ�ȭ
	//	OnBtnRadioAuto();

	//	// �ֽ��� �������� �ʱ�ȭ
	//	if (IsEquitiesMap())
	//	{
	//		if (m_bElwMode)
	//		{
	//		}
	//		else
	//		{
	//			
	//			InitCreditCtrl();
	//		}
	//	}

	//	// Ȥ�� �ż����� Ȥ�� �ŵ����� �����ϼ��� ������ ����������
	//	SetRegBtnText(m_clOrdMinSet.m_strMMType, SVRORD_JOB_REG);

	//	// �Ϲ��ֹ�,ȣ������â�� �ʱ�ȭ
	//	m_OrderTypeWndNormal.InitCtrlValue();
	//	m_OrderTypeWndHogaDiv.InitCtrlValue();

	//	// �ŵ�/�ż� ���� ������ ��������
	//	m_OrderTypeWndNormal.ClearVolCheck();
	//	m_OrderTypeWndHogaDiv.ClearVolCheck();

	//	if (IsEquitiesMap())
	//	{
	//		// ���� ���� ��ȸ ��û

	//		ReqPriceInfo(m_bElwMode, strCode);

	//		if (m_bElwMode == FALSE)
	//		{
	//			ReqDepositInfo(strCode);
	//		}
	//	}
	
			
	return 0L;
}

void CBaseFrmWnd::ShowLoanDateCtrl()
{
	int nCmdShow = SW_SHOW;
	if (IsCreditDateValid() == FALSE)
		nCmdShow = SW_HIDE;
		
	m_ExpireDateCtrl.ShowWindow(nCmdShow);
}

CString CBaseFrmWnd::GetCurCode()
{
	CString strCode;

	m_ctlCodeInput.GetWindowText(strCode);
	return strCode.Trim();
}

CString CBaseFrmWnd::GetCurCodeName()
{
	CString strCodeName;

	//m_ctlStkCodeName.GetWindowText(strCodeName);

	return strCodeName.Trim();
}

CString CBaseFrmWnd::GetCreditCmbValue(CString strMMType)
{
	int nSel = m_cmbCreditType.GetCurSel();

	// �ŵ��ż� ����
	if (strMMType == SVRORD_MMTYPE_SELL)
	{
		//�޺� - const LPCTSTR CREDIT_SELL_TYPE_STRING[] = { "����", "�ڱ����ڻ�ȯ", "�������ڻ�ȯ", "�㺸�����ȯ" };
		//���ϰ� - 0 ����, 1 �ſ���������, 3 �ſ��ڱ�����, 5 �ſ��������, 7 �ſ��ڱ����, 8 ��Ź�ֽĴ㺸�ſ����
		switch (nSel)
		{
		case 0:
			return "5";
		case 1:
			return "3";
		case 2:
			return "1";
		case 3:
			return "8";
		}
	}
	else
	{
		
		return "5";
	}
	
	return "";
}

void CBaseFrmWnd::SetValueToCreditCmb(int nVal)
{
	//nVal: 0 ����, 1 �ſ���������, 3 �ſ��ڱ�����, 5 �ſ��������, 7 �ſ��ڱ����, 8 ��Ź�ֽĴ㺸�ſ����

	int nSetIdx = -1;

	if (IsSellTabSelected()) // �ŵ�
	{
		//�޺� - const LPCTSTR CREDIT_SELL_TYPE_STRING[] = { "����", "�ڱ����ڻ�ȯ", "�������ڻ�ȯ", "�㺸�����ȯ" };

		switch (nVal)
		{
		case 1:
			nSetIdx = 2;
			break;
		case 3:
			nSetIdx = 1;
			break;
		case 5:
		case 7:
			nSetIdx = 0;
			break;
		case 8:
			nSetIdx = 3;
			break;
		}
	}
	else
	{
		
		nSetIdx = 0;
	}

	m_cmbCreditType.SetCurSel(nSetIdx);

	ShowLoanDateCtrl();
}

BOOL CBaseFrmWnd::IsCreditDateValid()
{
	if (m_radioCredit.GetCheck() == BST_UNCHECKED)
		return FALSE;

	int nIdx = m_cmbCreditType.GetCurSel();
	if (nIdx != CB_ERR)
	{
		CString strText;
		m_cmbCreditType.GetLBText(nIdx, strText);
		
		if (strText == "����" || strText == "����")
			return FALSE;
	}

	return TRUE;
}

void CBaseFrmWnd::OnBnClickedBtnInit()
{
	OnBtnInit();
}

void CBaseFrmWnd::ReqCheckVolAvail(BOOL bSell, CString strPrice)
{

	strPrice.Trim();
	strPrice.Remove(',');
	strPrice.Format("%d", atol(strPrice));

	CString strItemCode;//, strItemName;
	
	strItemCode = GetCurCode();
	if (strItemCode.GetLength() <= 0)
	{
		DefMessageBox(GetSafeHwnd(), E_STR_CODE_NEEDED);
		
		return;
	}

	CString strAccNum, strAccPass;
	GetParent()->SendMessage(RMSG_GET_ACCOUNTNUM, (WPARAM)&strAccNum, (LPARAM)&strAccPass);
	strAccNum.Trim();


	strAccPass.Trim();

	if (m_radioCredit.GetCheck() == BST_CHECKED)
	{
		// �ſ��� ���
		ReqCheckVolAvailCredit(strAccNum, strAccPass, strItemCode, bSell, strPrice);
	}
	else
	{		
		strPrice.Remove(',');

		CTR_10117_I tr_input;
		if (bSell)
			tr_input.gb =  '1';	//�ŵ�
		else
			tr_input.gb =  '2';	//�ż�

		tr_input.geja = strAccNum;
		tr_input.passwd = strAccPass;
		tr_input.code = strItemCode;
		tr_input.price = strPrice;
		
		

		//int nRet = m_pOrderMng->RequestTR10117(&tr_input);
		CString szInput ;
		int nSize = sizeof(TR_10117_I) ;
		szInput.Format("%-*.*s", nSize , nSize,(LPCTSTR)&tr_input);
		BaseSendTr(TR_10117, szInput,nSize); 
	}
}
void CBaseFrmWnd::RecvCheckVolAvail(char *p, int n, BOOL bELW)
{
	CString strBuyVol;
	CString strMax;
	
	{
		if (n < sizeof(TR_10117_O))
			return;

		CTR_10117_O out((TR_10117_O*)p);
		strBuyVol = out.pqty;
		strMax = out.maxqty;
	}

	strMax.Trim();
	int nMaxQty = atol(strMax);
	if (m_pPriceInfo && m_pPriceInfo->m_nQtyUnit != 0)
		nMaxQty = nMaxQty - (nMaxQty % m_pPriceInfo->m_nQtyUnit);

	strMax.Format("%d", nMaxQty);

	if (m_tabOrderType.GetCurSel() == 0) // �Ϲ��ֹ���
		m_OrderTypeWndNormal.SetJangoVolume(strMax, strBuyVol);
	else // ȣ��������
		m_OrderTypeWndHogaDiv.SetJangoVolume(strMax, strBuyVol);

}


void CBaseFrmWnd::EnableCreditCtrl(BOOL bEnable)
{
	m_bCreditAcnt = bEnable;

	InitCreditCtrl();
}

void CBaseFrmWnd::SetCode(CString strCode)
{
	//if (ChangeMarketTo(SVRORD_MARKETTYPE_STOCK))
	//	InitAllCond(FALSE);
	
	m_ctlCodeInput.SetWindowText(strCode);
}


void CBaseFrmWnd::AdjustCreditCtrl(int nCredit, CString strLoanDate)
{
	//0:����, 
	//1 ����
	//3 �ڱ�
	//5 ����
	//7 ����
	//8 �㺸

	
	
	if (m_nSellBuy == WND_SELL)
	{
		if (nCredit == 0)
		{
			OnBtnRadioCash();
		}
		else
		{
			OnBtnRadioCredit();
			SetValueToCreditCmb(nCredit);
			
			if (strLoanDate.GetLength() >= 8)
			{
				CTime time(atoi(strLoanDate.Left(4)), atoi(strLoanDate.Mid(4, 2)), atoi(strLoanDate.Mid(6)), 0, 0, 0);
				m_ExpireDateCtrl.SetTime(&time);
			}
		}
	}
	// �ż���
	else
	{
		// ���ְ� �ƴϸ� �� ����ó��
		if (nCredit == 5 || nCredit == 7)
		{
			m_radioCredit.ShowWindow(SW_SHOW);

			OnBtnRadioCredit();
			SetValueToCreditCmb(nCredit);
			
			if (strLoanDate.GetLength() >= 8)
			{
				CTime time(atoi(strLoanDate.Left(4)), atoi(strLoanDate.Mid(4, 2)), atoi(strLoanDate.Mid(6)), 0, 0, 0);
				m_ExpireDateCtrl.SetTime(&time);
			}
		}
		else
		{
			//m_radioCredit.ShowWindow(SW_HIDE);
			OnBtnRadioCash();
		}
	}
	
}

void CBaseFrmWnd::ReqCheckVolAvailCredit(CString sAcct, CString sPwd, CString strItemCode, BOOL bSell, CString sPrice)
{
	int nSel = m_cmbCreditType.GetCurSel();

	// �ſ뱸���� "����"�� �ƴϸ鼭 �ŵ����ɼ��� ��ȸ�� ���
	if (bSell && nSel != 0) 
	{
		TR_10144_I tr_input;

		memset(&tr_input, ' ', sizeof(tr_input));

		memcpy(tr_input.acct	, (LPSTR)(LPCTSTR)sAcct	, min(sAcct.GetLength(), sizeof(tr_input.acct)));
		memcpy(tr_input.passwd	, (LPSTR)(LPCTSTR)sPwd	, min(sPwd.GetLength(), sizeof(tr_input.passwd)));
		
		// �Ÿű���
		CString strTemp = "1";	// 1:�ŵ�
		int nLen = sizeof(tr_input.trdgb);
		memcpy(tr_input.trdgb	, (LPSTR)(LPCTSTR)strTemp	, min(strTemp.GetLength(), nLen));
		

		strTemp = CREDIT_SELL_TYPE_VAL[nSel];
		nLen = sizeof(tr_input.sinygb);
		memcpy(tr_input.sinygb	, (LPSTR)(LPCTSTR)strTemp	, min(strTemp.GetLength(), nLen));
		

		strTemp = strItemCode;
		nLen = sizeof(tr_input.jcode);
		strTemp.Format("%-*.*s", nLen, nLen, strTemp);
		memcpy(tr_input.jcode	, (LPSTR)(LPCTSTR)strTemp	, min(strTemp.GetLength(), nLen));


		strTemp = sPrice;
		nLen = sizeof(tr_input.price);
		int nPrice = atoi(strTemp);
		if (nPrice >= 0)
			strTemp.Format("+%0*d", nLen-4, nPrice);
		else
			strTemp.Format("-%0*d", nLen-4, nPrice);
		strTemp += ".00";
		memcpy(tr_input.price	, (LPSTR)(LPCTSTR)strTemp	, min(strTemp.GetLength(), nLen));


		// ������
		CString strLoanDate;
		CTime timeLoanDate;
		m_ExpireDateCtrl.GetTime(timeLoanDate);
		strLoanDate = timeLoanDate.Format("%Y%m%d");

		strTemp = strLoanDate;
		nLen = sizeof(tr_input.lndate);
		strTemp.Format("%-*.*s", nLen, nLen, strTemp);
		memcpy(tr_input.lndate	, (LPSTR)(LPCTSTR)strTemp	, min(strTemp.GetLength(), nLen));
		
		strTemp = theApp.g_szMyIP ;
		nLen = sizeof(tr_input.ipaddr);		
		memcpy(tr_input.ipaddr	, (LPSTR)(LPCTSTR)strTemp	, min(strTemp.GetLength(),nLen));

		BaseSendTr(TR_10144, (LPCTSTR)&tr_input, sizeof(TR_10144_I));
		return;
	}

	// �׿� �ſ�ż�,�ſ�ŵ�('����'�� ��츸) ���� ���� ��ȸ
	TR_10142_I tr_input;

	memset(&tr_input, ' ', sizeof(tr_input));

	memcpy(tr_input.acct	, (LPSTR)(LPCTSTR)sAcct	, min(sAcct.GetLength(), sizeof(tr_input.acct)));

	memcpy(tr_input.passwd	, (LPSTR)(LPCTSTR)sPwd	, min(sPwd.GetLength(), sizeof(tr_input.passwd)));
	
	CString strTemp;
	if (bSell)
		strTemp = CREDIT_SELL_TYPE_VAL[nSel];
	else
	{
		strTemp = CREDIT_BUY_TYPE_VAL[nSel];
		
		// �ſ�ż��� ��� ���ֻ�ȯ�� ������ȸ�� ����
		if (strTemp == "���ֻ�ȯ")
		{
			DefMessageBox(GetSafeHwnd(), "���ֻ�ȯ�� ��� ��ȸ�� �� �����ϴ�.");
			return;
		}
	}

	int nLen = sizeof(tr_input.sinygb);
	memcpy(tr_input.sinygb	, (LPSTR)(LPCTSTR)strTemp	, min(strTemp.GetLength(), nLen));
	

	strTemp = strItemCode;
	nLen = sizeof(tr_input.jcode);
	strTemp.Format("%-*.*s", nLen, nLen, strTemp);
	memcpy(tr_input.jcode	, (LPSTR)(LPCTSTR)strTemp	, min(strTemp.GetLength(), nLen));


	strTemp = sPrice;
	nLen = sizeof(tr_input.price);
	int nPrice = atoi(strTemp);
	if (nPrice >= 0)
		strTemp.Format("+%0*d", nLen-4, nPrice);
	else
		strTemp.Format("-%0*d", nLen-4, nPrice);
	strTemp += ".00";	
	memcpy(tr_input.price	, (LPSTR)(LPCTSTR)strTemp	, min(strTemp.GetLength(), nLen));
	
	strTemp = theApp.g_szMyIP ;
	nLen = sizeof(tr_input.ipaddr);	
	memcpy(tr_input.ipaddr	, (LPSTR)(LPCTSTR)strTemp	, min(strTemp.GetLength(), nLen));
    
	//SendTrFromMain(TR_10142, (BYTE *)&tr_input, sizeof(TR_10142_I));
	BaseSendTr(TR_10142, (LPCTSTR)&tr_input, sizeof(TR_10142_I));
}

void CBaseFrmWnd::RecvCheckVolAvailCredit(char *p, int n, CString strTr)
{
	CString strMax;
	if (strTr == TR_10142) // ���� �ż�,�ŵ�(����) ���� ����
	{
		if (n < sizeof(TR_10142_O))
			return;

		TR_10142_O* pOut = (TR_10142_O*)p;
		strMax = pOut->maxqty;
	}
	else if (strTr == TR_10144) // ���� �ŵ�(���ְ� �ƴ� ��츸) ���� ����
	{
		if (n < sizeof(TR_10144_O))
			return;

		CTR_10144_O out((TR_10144_O*)p);
		strMax = out.maxqty;
	}

	strMax.Trim();
	int nMaxQty = atol(strMax);
	if (m_pPriceInfo && m_pPriceInfo->IsValid() && m_pPriceInfo->m_nQtyUnit != 0)
		nMaxQty = nMaxQty - (nMaxQty % m_pPriceInfo->m_nQtyUnit);

	strMax.Format("%d", nMaxQty);

	if (m_tabOrderType.GetCurSel() == 0) // �Ϲ��ֹ���
		m_OrderTypeWndNormal.SetJangoVolume(strMax, "");
	else // ȣ��������
		m_OrderTypeWndHogaDiv.SetJangoVolume(strMax);
}

BOOL CBaseFrmWnd::IsSellTabSelected()
{
	int nType = GetParent()->SendMessage(UMSG_GETCURMARKETTAB, 0, 0);
	return (nType == 0);
}

CString	CBaseFrmWnd::GetMatchPrice(CString strCode, int nMPFlag)
{
	CString strRet;

	if (m_pParent)
		strRet = ((CExSvrAutoOrderDlg *)m_pParent)->FindMatchPrice(strCode, nMPFlag);

	return strRet;
}

int CBaseFrmWnd::GetPositions(CString strCode)
{
	if (m_pParent)
		return ((CExSvrAutoOrderDlg *)m_pParent)->FindPositions(strCode);

	return -1;
}


BOOL CBaseFrmWnd::CheckWatching(CString strCode, CString strSellBuy, CString strCredit, CString strLoanDate)
{
	strCode.Trim();
	strSellBuy.Trim();
	strCredit.Trim();
	strLoanDate.Trim();

	CGridKey clsGridKey(strCode, strSellBuy, strCredit, strLoanDate);
	return GetParent()->SendMessage(UMSG_CHECKWATCHING, 0, (LPARAM)&clsGridKey);
}

BOOL CBaseFrmWnd::IsMP(CString strCode, CString strMMType, CString strCredit, CString strLoanDate)
{
	strCode.Trim();
	strMMType.Trim();
	strCredit.Trim();
	strLoanDate.Trim();

	CGridKey clsGridKey(strCode, strMMType, strCredit, strLoanDate);
	return GetParent()->SendMessage(UMSG_CHECK_MP, 0, (LPARAM)&clsGridKey);
}




BOOL CBaseFrmWnd::PreTranslateMessage(MSG* pMsg)
{
	//if (m_WaitCursor.WaitCursorProc(pMsg)) 
	//	return TRUE;

	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CBaseFrmWnd::BaseSendTr(CString strTrCode, CString szData, long nSize, BOOL bFirstSend)
{

	CString szInput ;
	szInput.Format("%-*.*s", nSize , nSize, szData);
	return theApp.SendToServerEx (DRCM_SENDDATA, strTrCode, szInput, m_hWnd);	

}


HRESULT CBaseFrmWnd::ReceiveData(long dwKey, LPCSTR szTR, LPCSTR szMsgCode, LPCSTR szMessage, LPVOID	aTRData, long dwTRDateLen)
{
	m_bBaseRequestState = FALSE;

	GetParent()->SendMessage(RMSG_SET_TR_RESULT_MSG, (WPARAM)szMsgCode, (LPARAM)szMessage);

	if (dwTRDateLen != 0)	
	{		
		if (strcmp(szTR, TR_10117) == 0) // ���� �ֹ� ���� ����
		{
			RecvCheckVolAvail((char*)aTRData, dwTRDateLen, FALSE);
		}
		else if (strcmp(szTR, TR_10142) == 0) // ���� �ż�,�ŵ�(����) ���� ����
		{
			RecvCheckVolAvailCredit((char*)aTRData, dwTRDateLen, TR_10142);
		}
		else if (strcmp(szTR, TR_10144) == 0) // ���� �ŵ�(���ְ� �ƴ� ��츸) ���� ����
		{
			RecvCheckVolAvailCredit((char*)aTRData, dwTRDateLen, TR_10144);
		}		
		else if (strcmp(szTR, TR10112) == 0) // ���� ȣ�� ����
		{
			RecvQtyUnitInfo((char *)aTRData, dwTRDateLen);
		}
		else if (strcmp(szTR, TR_10051) == 0) // ���� ���簡/ȣ��
		{
			RecvPriceInfo((char *)aTRData, dwTRDateLen, FALSE);			
		}
		

		else
		{
			////TRACEP("1", "");
		}
	}

	//BaseSendRestTr();

	return 0;
}


// ���簡, ȣ�� ��û
void CBaseFrmWnd::ReqPriceInfo(BOOL bElw, CString strCode)
{
	strCode.Trim();

	tr_10051_I tr;
	memset(&tr, ' ', sizeof(tr_10051_I));
	memcpy(tr.shcode, (LPCTSTR)strCode, min(strCode.GetLength(), sizeof(tr.shcode)));

	BaseSendTr(TR_10051, (LPCTSTR)&tr, sizeof(tr_10051_I));

}

void CBaseFrmWnd::RecvPriceInfo(char *p, int n, BOOL bElw)
{
	CString strCode;

	
	if (n < sizeof(tr_10051_O))
		return;

	tr_10051_O* pTR = (tr_10051_O*)p;

	//strCode.Format("%*.*s", sizeof(pTR->shcode), sizeof(pTR->shcode), pTR->shcode); 
	strCode.Format("%6.6s", pTR->shcode); // ����ü�� 7�ε� ���� 6�̰� 1����Ʈ�� �����Ⱚ�� ���´�. ©�� ����!
	strCode.Trim();

	m_pPriceInfo->m_strCode = strCode;
	m_pPriceInfo->m_bELW = bElw;
	m_pPriceInfo->m_strCurrent.Format("%*.*s", sizeof(pTR->table.price), sizeof(pTR->table.price), pTR->table.price); 
	m_pPriceInfo->m_strDiff.Format("%*.*s", sizeof(pTR->table.change), sizeof(pTR->table.change), pTR->table.change); 
	m_pPriceInfo->m_strSign.Format("%*.*s", sizeof(pTR->table.sign), sizeof(pTR->table.sign), pTR->table.sign); 

	m_pPriceInfo->m_strPrevClose.Format("%*.*s", sizeof(pTR->table.preprice), sizeof(pTR->table.preprice), pTR->table.preprice); 

	m_pPriceInfo->m_strOffer[0].Format("%*.*s", sizeof(pTR->table.offerho1), sizeof(pTR->table.offerho1), pTR->table.offerho1); 
	m_pPriceInfo->m_strOffer[1].Format("%*.*s", sizeof(pTR->table.offerho2), sizeof(pTR->table.offerho2), pTR->table.offerho2); 
	m_pPriceInfo->m_strOffer[2].Format("%*.*s", sizeof(pTR->table.offerho3), sizeof(pTR->table.offerho3), pTR->table.offerho3); 
	m_pPriceInfo->m_strOffer[3].Format("%*.*s", sizeof(pTR->table.offerho4), sizeof(pTR->table.offerho4), pTR->table.offerho4); 
	m_pPriceInfo->m_strOffer[4].Format("%*.*s", sizeof(pTR->table.offerho5), sizeof(pTR->table.offerho5), pTR->table.offerho5); 

	m_pPriceInfo->m_strBid[0].Format("%*.*s", sizeof(pTR->table.bidho1), sizeof(pTR->table.bidho1), pTR->table.bidho1); 
	m_pPriceInfo->m_strBid[1].Format("%*.*s", sizeof(pTR->table.bidho2), sizeof(pTR->table.bidho2), pTR->table.bidho2); 
	m_pPriceInfo->m_strBid[2].Format("%*.*s", sizeof(pTR->table.bidho3), sizeof(pTR->table.bidho3), pTR->table.bidho3); 
	m_pPriceInfo->m_strBid[3].Format("%*.*s", sizeof(pTR->table.bidho4), sizeof(pTR->table.bidho4), pTR->table.bidho4); 
	m_pPriceInfo->m_strBid[4].Format("%*.*s", sizeof(pTR->table.bidho5), sizeof(pTR->table.bidho5), pTR->table.bidho5); 	

	m_pPriceInfo->m_strUpiLmit.Format("%*.*s", sizeof(pTR->table.hprice), sizeof(pTR->table.hprice), pTR->table.hprice); 
	m_pPriceInfo->m_strDownLimit.Format("%*.*s", sizeof(pTR->table.lprice), sizeof(pTR->table.lprice), pTR->table.lprice); 

	m_pPriceInfo->TrimAll();

	// �ǽð� ���
	//m_pPriceInfo->RegisterDrds(ID_S31, "S31", 0);
	//m_pPriceInfo->RegisterDrds(ID_X11, "X11", 1);

	// ����/���� ���� ��ȸ
	ReqQtyUnitInfo(strCode);
	
}


void CBaseFrmWnd::SetHogaPriceInfo(DrdsData* pDrdsData)
{
	/*if (pDrdsData->Id == ID_X11)
	{
		CDRDS_X11_DATA X11;
		X11.Convert((DRDS_X11_DATA*)pDrdsData->Data);

		CString strCode = X11.m_szcode;
		strCode.Trim();

		if (m_pPriceInfo->m_strCode != strCode)
			return;

		m_pPriceInfo->m_strOffer[0] = X11.m_szofferho1;
		m_pPriceInfo->m_strOffer[1] = X11.m_szofferho2;
		m_pPriceInfo->m_strOffer[2] = X11.m_szofferho3;
		m_pPriceInfo->m_strOffer[3] = X11.m_szofferho4;
		m_pPriceInfo->m_strOffer[4] = X11.m_szofferho5;

		m_pPriceInfo->m_strBid[0] = X11.m_szbidho1;
		m_pPriceInfo->m_strBid[1] = X11.m_szbidho2;
		m_pPriceInfo->m_strBid[2] = X11.m_szbidho3;
		m_pPriceInfo->m_strBid[3] = X11.m_szbidho4;
		m_pPriceInfo->m_strBid[4] = X11.m_szbidho5;
	}*/
	

	m_pPriceInfo->TrimAll();
}

void CBaseFrmWnd::ReqQtyUnitInfo(CString strCode)
{
	if (strCode.GetLength() > 0)
		BaseSendTr(TR10112, strCode, strCode.GetLength());
}

void CBaseFrmWnd::RecvQtyUnitInfo(char *p, int n)
{
	if (n < sizeof(TR_10112_O))
		return;

	CTR10112 cUnitInfo((TR_10112_O*)p);
	CString strCode = cUnitInfo.jgcode;
	strCode.Trim();

	if (m_pPriceInfo->m_strCode != strCode)
		return;

	m_pPriceInfo->m_nQtyUnit = atoi(cUnitInfo.prcgb);
	if (m_pPriceInfo->m_nQtyUnit <= 0)
		m_pPriceInfo->m_nQtyUnit = 1;

	//m_pPriceInfo->m_nPriceUnit = atol(cUnitInfo.hodanwi);
	
	ApplyVolUnitInfo();
}

void CBaseFrmWnd::SetCurPriceInfo(DrdsData* pDrdsData)
{
	/*if (pDrdsData->Id == ID_S31)
	{
		C_DRDS_S31_DATA S31;
		S31.Convert((DRDS_S31_DATA*)pDrdsData->Data);

		CString strCode = S31.m_szcode;
		strCode.Trim();

		if (m_pPriceInfo->m_strCode != strCode)
			return;

		m_pPriceInfo->m_strCurrent = S31.m_szprice;	
		m_pPriceInfo->m_strDiff = S31.m_szchange;
		m_pPriceInfo->m_strSign = S31.m_szsign;
	}*/
	

	m_pPriceInfo->TrimAll();
}


void CBaseFrmWnd::ApplyVolUnitInfo()
{
	m_OrderTypeWndNormal.SetEquitiesVolUnitInfo();
	m_OrderTypeWndHogaDiv.SetEquitiesVolUnitInfo();
}



void CBaseFrmWnd::InitCreditCtrl()
{	
	if (m_bCreditAcnt)
	{
		m_radioCash.EnableWindow(TRUE);
		m_radioCredit.EnableWindow(TRUE);
		m_cmbCreditType.EnableWindow(TRUE);
		m_ExpireDateCtrl.EnableWindow(TRUE);
	}
	else
	{
		m_radioCash.EnableWindow(FALSE);
		m_radioCredit.EnableWindow(FALSE);
		m_cmbCreditType.EnableWindow(FALSE);
		m_ExpireDateCtrl.EnableWindow(FALSE);
	}
	
	OnBtnRadioCash();
}

double CBaseFrmWnd::GetFeeRate()
{
	if (m_pParent)
		return ((CExSvrAutoOrderDlg *)m_pParent)->GetFeeRate();
	return 0;
}

void CBaseFrmWnd::ProcessXP1(CString strCode)
{
	strCode.Trim();

	CString strCurCode = GetCurCode();
	if (strCurCode == strCode)
		OnBtnInit();
}


BOOL CBaseFrmWnd::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
{
	COPYDATASTRUCT* pCDS = pCopyDataStruct ;

	int nDataType = (int)pCDS->dwData ;	
	switch (nDataType)
	{	

	case DRCM_DRDS_DATA :  //�ǽð� ����Ÿ		
		break ;		

	default: //��ȸ ������
		{
			STTRHEADER* prData = (STTRHEADER*)pCDS->lpData;
			char szTrCode[5+1] ={0,} ;
			char szMsg[82+1] ={0,} ;
			char szMsgCode[6+1] ={0,} ;
			CString strMsg  ;


			memcpy(szTrCode, prData->TRCode, 5 ) ;
			memcpy(szMsg, prData->Message, 82) ;
			memcpy(szMsgCode, prData->MsgCode, 6) ;

			strMsg = szMsg ;
			strMsg.TrimRight() ;

			int dwTRDateLen = pCDS->cbData ;
			// =====================================================================
			// ���� �ֹ� ���� ����
			// =====================================================================
			if ( strcmp(szTrCode, TR_10117 ) == 0 ) 
			{	
				RecvCheckVolAvail((char*)prData->TRData, dwTRDateLen, FALSE);
			}
			// =====================================================================
			// ���� �ż�,�ŵ�(����) ���� ����
			// =====================================================================
			else if ( strcmp(szTrCode, TR_10142 ) == 0 ) 
			{	
				RecvCheckVolAvailCredit((char*)prData->TRData, dwTRDateLen, FALSE);
			}
			// =====================================================================
			// // ���� �ŵ�(���ְ� �ƴ� ��츸) ���� ����
			// =====================================================================
			else if (strcmp(szTrCode, TR_10144) == 0) 
			{
				RecvCheckVolAvailCredit((char*)prData->TRData, dwTRDateLen, TR_10144);
			}
			// =====================================================================
			// ���� ���簡/ȣ��
			// =====================================================================
			else if (strcmp(szTrCode, TR_10051) == 0) 
			{
				RecvPriceInfo((char*)prData->TRData, dwTRDateLen, FALSE);			
			}
					
		}		
	}

	return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
}


// OrderTypeWnd.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ExSvrAutoOrderDlg.h"
#include "OrderTypeWnd.h"

#include "include_auto/globalauto.h"
#include "include_auto/MasterDataSub.h"
#include "BaseFrmWnd.h"

// 스핀 helper dll 사용
#define		SPIN_HELPER_STOCK   "0"     // 장내,장외


// COrderTypeWnd

IMPLEMENT_DYNAMIC(COrderTypeWnd, CWnd)

COrderTypeWnd::COrderTypeWnd()
{
	LOGFONT	  logFont;
	GETFONT(logFont, 12, 400, m_fontDefault);
	m_cOrdMinSet.m_enOrdType = NORMAL_ORDER;
	m_clrBk = COLOR_MAIN_CANVAS;
	m_clrText = RGB(0, 0, 0);

	m_brushBk.CreateSolidBrush(m_clrBk);

	m_cOrdType.ClearData();
	m_IsChangeSet = FALSE;

	m_pPriceInfo = NULL;
	m_bBuyProper = FALSE;
	m_nVolNewClear = VOL_CLEAR;
	m_pParent = NULL;

}


COrderTypeWnd::~COrderTypeWnd()
{
}


BEGIN_MESSAGE_MAP(COrderTypeWnd, CWnd)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_CTLCOLOR()
//	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
//	ON_BN_CLICKED(IDB_DIVIDESET, OnBtnDivideSet)
	ON_CBN_SELCHANGE(IDC_PRICETYPE, OnChangePriceType)
	ON_CBN_SELCHANGE(IDC_PRICEGB, OnChangePriceUnit)
	ON_CBN_SELCHANGE(IDC_DIVWAY,    OnChangeDivWay)
	ON_CBN_SELCHANGE(IDC_DIVSTD,    OnChangeDivStd)
	ON_CBN_SELCHANGE(IDC_STDCOST,    OnChangeStdCost)
	
	
	ON_NOTIFY(UDN_DELTAPOS, IDCT_SPIN_DIVCNT, OnChangeDivCnt)
	ON_NOTIFY(UDN_DELTAPOS, IDCT_SPIN_DIVUNIT, OnChangeDivUnit)
	ON_BN_CLICKED(IDB_VOLCHECK, OnBtnVolCheck)
	ON_BN_CLICKED(IDB_VOLCLEAR, OnBtnVolClear)
	// 20120723 ssj - 서버자동주문 >>
	ON_BN_CLICKED(IDC_BTN_BUY_VOL_MAX, OnBtnBuyVolMax)
	ON_BN_CLICKED(IDC_BTN_BUY_VOL_TOT, OnBtnBuyVolTot)
	ON_BN_CLICKED(IDC_BTN_BUY_VOL_TOT_APPLY, OnBtnBuyVolTotApply)
	// 20120723 ssj - 서버자동주문 <<
	//ON_BN_CLICKED(IDB_LQVOLCHECK, OnBtnLQVolCheck)
	ON_BN_CLICKED(IDH_PRICETYPE, OnBtnMarketPriceCheck)
	ON_BN_CLICKED(IDB_REG, OnBtnRegCondition)

	ON_NOTIFY(UDN_DELTAPOS, IDCT_SPIN_BUYVOL,	   OnChangeBuyVolSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDCT_SPIN_SELLVOLRATE, OnChangeSellVolSpin)

	//ON_NOTIFY(UDN_DELTAPOS, IDCT_SPIN_BUYPRICE,	   OnChangeBuyPriceSpin)
	//ON_NOTIFY(UDN_DELTAPOS, IDCT_SPIN_SELLPRICE,	   OnChangeSellPriceSpin)
	
	
	ON_BN_CLICKED(IDC_BTN_SELL_VOL_PERCENT, OnBtnSellVolPercent)
	ON_BN_CLICKED(IDC_BTN_SELL_VOL_DIGIT, OnBtnSellVolDigit)
	ON_BN_CLICKED(IDC_BTN_BIDASKDLG, OnBtnBidAskDlg)
	
//	ON_EN_SETFOCUS(IDE_SELLVOLRATE, &COrderTypeWnd::OnEnSetfocusSellVolRate)
END_MESSAGE_MAP()



// COrderTypeWnd 메시지 처리기입니다.

BOOL COrderTypeWnd::Create(CWnd* pParentWnd, enORDTYPE nOrdType, COrdMinSet* clOrdMinSet, UINT nID)
{
	if(clOrdMinSet)
	{
		m_cOrdMinSet.m_enOrdType	 = nOrdType;
		m_cOrdMinSet.m_strMarketType = clOrdMinSet->m_strMarketType;
		m_cOrdMinSet.m_strMMType	 = clOrdMinSet->m_strMMType;
	}
	else
	{
		m_cOrdMinSet.m_enOrdType	 = NORMAL_ORDER;		//일반주문
		m_cOrdMinSet.m_strMarketType = SVRORD_MARKETTYPE_STOCK;				//주식
		m_cOrdMinSet.m_strMMType	 = SVRORD_MMTYPE_BUY;	//매수
	}
	m_cOrdType.SetOrdType(m_cOrdMinSet.m_enOrdType);

	BOOL bCreate = CWnd::Create(NULL, _T(""), WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, CRect(0, 0, 0, 0), pParentWnd, nID, NULL);
	return bCreate; 
}

int COrderTypeWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	UDACCEL accels[]={{0,1}}; 

	CString strImagePath;
	GetDir_DrfnRoot(strImagePath);
	strImagePath += "\\Image";

	m_dtmExpireDate.Create(WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, IDC_EXDATE);
	m_dtmExpireDate.SetFont(&m_fontDefault);	
	m_dtmExpireDate.SetFormat("yyyy/MM/dd");

	m_ctrlExpiredateText1.Create(_T("유효기간"), WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE, 	CRect(0, 0, 0, 0), this);
	m_ctrlExpiredateText1.SetFont(&m_fontDefault);


	m_ctrlPriceTypeText.Create(_T("주문구분"), WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE, CRect(0, 0, 0, 0), this);
	m_ctrlPriceTypeText.SetFont(&m_fontDefault);

	m_comboPriceType.Create(WS_CHILD | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST, 	CRect(0, 0, 0, 0), this, IDC_PRICETYPE);

	m_comboPriceType.SetFont(&m_fontDefault);
	m_comboPriceType.ResetContent();

	//주문 가격 형식 구문
	int nIndex;
	//시장가 체크박스
	m_chkMarketPrice.Create(_T(""), WS_CHILD | WS_VISIBLE | BS_CHECKBOX | BS_AUTOCHECKBOX,
		CRect(0, 0, 0, 0), this, IDH_PRICETYPE);
	m_chkMarketPrice.SetFont(&m_fontDefault);
	m_chkMarketPrice.SetWindowText(_T("시장가"));
	

	m_ctrlVolText1.Create(_T("매도비중"), WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE , 
		CRect(0, 0, 0, 0), this);
	m_ctrlVolText1.SetFont(&m_fontDefault);

	CString strCaption1, strCaption2;
	if (IsEquitiesMap())
	{
		strCaption1 = "%";
		strCaption2 = "수량";
	}
	else
	{
		strCaption1 = "청산비율";
		strCaption2 = "주문수량";
	}

	m_rdoVolPercent.Create(strCaption1,  WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP, CRect(0, 0, 0, 0), this, IDC_BTN_SELL_VOL_PERCENT);
	m_rdoVolPercent.SetFont(&m_fontDefault);
	m_rdoVolPercent.SetCheck(BST_CHECKED);

	m_rdoVolDigit.Create(strCaption2,  WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON , CRect(0, 0, 0, 0), this, IDC_BTN_SELL_VOL_DIGIT);
	m_rdoVolDigit.SetFont(&m_fontDefault);
	
	//매도비중 edit
	m_editSellVolRate.Create(WS_CHILD | WS_VISIBLE | ES_RIGHT | ES_NUMBER , CRect(0,0,10,20), this, IDE_SELLVOLRATE);
	m_editSellVolRate.SetFont(&m_fontDefault);
	m_editSellVolRate.SetWindowText("10");
	m_editSellVolRate.SetPlaces(3, 0);
	m_editSellVolRate.SetEditRange(0, 100);


	//매도비중 spin
	m_spinSellVolRate.SetImagePath(strImagePath);
	m_spinSellVolRate.Create(WS_CHILD | WS_VISIBLE | UDS_ALIGNRIGHT  | UDS_AUTOBUDDY, CRect(0,10,0,20), this, IDCT_SPIN_SELLVOLRATE);
	m_spinSellVolRate.SetBuddy(&m_editSellVolRate);
	m_spinSellVolRate.SetDecimalPlaces(0);
	m_spinSellVolRate.SetTrimTrailingZeros (FALSE);
	m_spinSellVolRate.SetRangeAndDelta(0, 100, 5);
	m_spinSellVolRate.SetPos(0);

	m_ctrlSellVolRateText2.Create(_T("(%)"), WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE, CRect(0, 0, 0, 0), this);
	m_ctrlSellVolRateText2.SetFont(&m_fontDefault);

	m_stcCheckVolOutput.Create(_T(""), WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,CRect(0, 0, 0, 0), this);
	m_stcCheckVolOutput.SetFont(&m_fontDefault);
	m_stcCheckVolOutput.SetWindowText("");


	//매도단가 edit
	m_ctrlWonText1.Create(_T("매도단가"), WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE, CRect(0, 0, 0, 0), this);
	m_ctrlWonText1.SetFont(&m_fontDefault);
	
	m_editSellPrice.Create(WS_CHILD | WS_VISIBLE | ES_RIGHT, CRect(0,0,10,20), this, IDE_SELLPRICE);
	m_editSellPrice.SetFont(&m_fontDefault);
	m_editSellPrice.SetWindowText("10");
	m_editSellPrice.SetEditRange(0, 999999999);

	//매도단가 spin
	m_spinSellPrice.SetImagePath(strImagePath);
	m_spinSellPrice.Create(WS_CHILD | WS_VISIBLE | UDS_ALIGNRIGHT  | UDS_AUTOBUDDY, CRect(0,10,0,20), this, IDCT_SPIN_SELLPRICE);
	m_spinSellPrice.SetBuddy(&m_editSellPrice);
	m_spinSellPrice.SetDecimalPlaces(0);
	m_spinSellPrice.SetTrimTrailingZeros (FALSE);
	m_spinSellPrice.SetRangeAndDelta (0, 999999999, 1);
	m_spinSellPrice.SetPos (0);
	m_spinSellPrice.SetAccel(1,accels);


	m_btnBidAskDlg.Create("", WS_CHILD | WS_VISIBLE  /*BS_OWNERDRAW*/, CRect(0, 0, 0, 0), this, IDC_BTN_BIDASKDLG);
	m_btnBidAskDlg.SetFont(&m_fontDefault);
	if (IsEquitiesMap())
		m_btnBidAskDlg.SetWindowText("원");
	else
		m_btnBidAskDlg.SetWindowText("호");

	//단가 구문
	m_cmbPriceGb.Create(WS_CHILD | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST,	CRect(0, 0, 0, 0), this, IDC_PRICEGB);

	m_cmbPriceGb.SetFont(&m_fontDefault);
	m_cmbPriceGb.ResetContent();

	CString strData;
	int nCnt = _countof(PRICE_GB_STRING);
	if(m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_ELW) == 0)
		nCnt -= 2;

	for (nIndex = 0; nIndex < nCnt; nIndex++)
		m_cmbPriceGb.AddString(PRICE_GB_STRING[nIndex]);
	m_cmbPriceGb.SetCurSel(0);


	//매수수량 edit
	m_editBuyVolume.Create(WS_CHILD | WS_VISIBLE | ES_RIGHT, CRect(0,0,10,20), this, IDE_BUYVOL);
	m_editBuyVolume.SetFont(&m_fontDefault);
	if (IsEquitiesMap())
	{
		m_editBuyVolume.SetWindowText("10");
		m_editBuyVolume.SetEditRange(0, 999999999);
	}
	else
	{
		m_editBuyVolume.SetPlaces(3, 0);
		m_editBuyVolume.SetEditRange(0, 100);
	}

	//매수수량 spin
	m_spinBuyVolume.SetImagePath(strImagePath);
	m_spinBuyVolume.Create(WS_CHILD | WS_VISIBLE | UDS_ALIGNRIGHT  | UDS_AUTOBUDDY, CRect(0,10,0,20), this, IDCT_SPIN_BUYVOL);
	m_spinBuyVolume.SetBuddy(&m_editBuyVolume);
	m_spinBuyVolume.SetDecimalPlaces(0);
	m_spinBuyVolume.SetTrimTrailingZeros (FALSE);
	if (IsEquitiesMap())
	{
		m_spinBuyVolume.SetRangeAndDelta (0, 999999999, 1);
		m_spinBuyVolume.SetPos (0);
		m_spinBuyVolume.SetAccel(1,accels);
	}
	else
	{
		m_spinBuyVolume.SetNoRemain(FALSE);
		m_spinBuyVolume.SetRangeAndDelta(0, 100, 5);
		m_spinBuyVolume.SetPos (0);
	}

	m_ctrlBuyVolText.Create(_T("주"), WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE, 
		CRect(0, 0, 0, 0), this);
	m_ctrlBuyVolText.SetFont(&m_fontDefault);

	//매수단가 edit
	m_editBuyPrice.Create(WS_CHILD | WS_VISIBLE | ES_RIGHT, CRect(0,0,10,20), this, IDE_BUYPRICE);
	m_editBuyPrice.SetFont(&m_fontDefault);
	m_editBuyPrice.SetWindowText("10");
	m_editBuyPrice.SetEditRange(0, 999999999);
	

	//매수단가 spin
	m_spinBuyPrice.SetImagePath(strImagePath);
	m_spinBuyPrice.Create(WS_CHILD | WS_VISIBLE | UDS_ALIGNRIGHT  | UDS_AUTOBUDDY, CRect(0,10,0,20), this, IDCT_SPIN_BUYPRICE);
	m_spinBuyPrice.SetBuddy(&m_editBuyPrice);
	m_spinBuyPrice.SetDecimalPlaces(0);
	m_spinBuyPrice.SetTrimTrailingZeros (FALSE);
	m_spinBuyPrice.SetRangeAndDelta (0, 999999999, 1);
	m_spinBuyPrice.SetPos (0);
	m_spinBuyPrice.SetAccel(1,accels);


	//분할탭//
	m_ctrlDivStdText.Create(_T("분할기준"), WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE, 
		CRect(0, 0, 0, 0), this);
	m_ctrlDivStdText.SetFont(&m_fontDefault);

	m_cmbDivStd.Create(WS_CHILD | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST,
		CRect(0, 0, 0, 0), this,
		IDC_DIVSTD);
	m_cmbDivStd.SetFont(&m_fontDefault);
	m_cmbDivStd.ResetContent();

	//분할수
	m_ctrlDivCnt.Create(_T("분할수"), WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE, 
		CRect(0, 0, 0, 0), this);
	m_ctrlDivCnt.SetFont(&m_fontDefault);

	m_EditDivCnt.Create(WS_CHILD | WS_VISIBLE | ES_RIGHT, CRect(0,0,10,20), this, IDE_DIVCNT);
	m_EditDivCnt.SetFont(&m_fontDefault);
	m_EditDivCnt.SetWindowText("10");

	m_SpinDivCnt.SetImagePath(strImagePath);
	m_SpinDivCnt.Create(WS_CHILD | WS_VISIBLE | UDS_ALIGNRIGHT  | UDS_AUTOBUDDY, CRect(0,10,0,20), this, IDCT_SPIN_DIVCNT);
	m_SpinDivCnt.SetBuddy(&m_EditDivCnt);
	m_SpinDivCnt.SetDecimalPlaces(0);
	m_SpinDivCnt.SetTrimTrailingZeros (FALSE);
	m_SpinDivCnt.SetRangeAndDelta (2, 5, 1);
	m_SpinDivCnt.SetPos (3);

	//기준가
	m_ctrlStdCost.Create(_T("기준가"), WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE, 
		CRect(0, 0, 0, 0), this);
	m_ctrlStdCost.SetFont(&m_fontDefault);

	m_cmbStdCost.Create(WS_CHILD | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST,
		CRect(0, 0, 0, 0), this,
		IDC_STDCOST);
	m_cmbStdCost.SetFont(&m_fontDefault);
	m_cmbStdCost.ResetContent();


	//분할 방향
	m_ctrlDivWay.Create(_T("분할방향"), WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE, 
		CRect(0, 0, 0, 0), this);
	m_ctrlDivWay.SetFont(&m_fontDefault);

	m_cmbDivWay.Create(WS_CHILD | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST,
		CRect(0, 0, 0, 0), this,
		IDC_DIVWAY);
	m_cmbDivWay.SetFont(&m_fontDefault);
	m_cmbDivWay.ResetContent();

	//분할단위
	m_ctrlDivUnit.Create(_T("분할단위"), WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE, 
		CRect(0, 0, 0, 0), this);
	m_ctrlDivUnit.SetFont(&m_fontDefault);

	m_EditDivUnit.Create(WS_CHILD | WS_VISIBLE | ES_RIGHT, CRect(0,0,10,20), this, IDE_DIVUNIT);
	m_EditDivUnit.SetFont(&m_fontDefault);
	m_EditDivUnit.SetWindowText("10");

	m_SpinDivUnit.SetImagePath(strImagePath);
	m_SpinDivUnit.Create(WS_CHILD | WS_VISIBLE | UDS_ALIGNRIGHT  | UDS_AUTOBUDDY , CRect(0,10,0,20), this, IDCT_SPIN_DIVUNIT);
	m_SpinDivUnit.SetBuddy(&m_EditDivUnit);
	m_SpinDivUnit.SetDecimalPlaces(0);
	m_SpinDivUnit.SetTrimTrailingZeros (FALSE);
	m_SpinDivUnit.SetRangeAndDelta (0, 100, 1);
	m_SpinDivUnit.SetPos (5);

	m_btnDivSet.Create(_T("적용"), WS_CHILD | WS_VISIBLE /*| BS_OWNERDRAW*/, 
		CRect(0, 0, 0, 0), this, IDB_DIVIDESET);
	m_btnDivSet.SetFont(&m_fontDefault);
	m_btnDivSet.SetWindowText("적용");

	m_btnVolCheck.Create(_T(""), WS_CHILD | WS_VISIBLE /*| BS_OWNERDRAW*/, 
		CRect(0, 0, 0, 0), this, IDB_VOLCHECK);
	m_btnVolCheck.SetFont(&m_fontDefault);
	m_btnVolCheck.SetWindowText("가");
	if (IsDerivativesMap())
		m_btnVolClear.ShowWindow(SW_HIDE);

	m_btnBuyVolMax.Create("", WS_CHILD | WS_VISIBLE /*| BS_OWNERDRAW*/, CRect(0, 0, 0, 0), this, IDC_BTN_BUY_VOL_MAX);
	m_btnBuyVolMax.SetFont(&m_fontDefault);
	m_btnBuyVolMax.SetWindowText("최");
	if (IsDerivativesMap())
		m_btnBuyVolMax.ShowWindow(SW_HIDE);

	m_btnVolClear.Create(_T(""), WS_CHILD | WS_VISIBLE /*| BS_OWNERDRAW*/, 
		CRect(0, 0, 0, 0), this, IDB_VOLCLEAR);
	m_btnVolClear.SetFont(&m_fontDefault);
	m_btnVolClear.SetWindowText("청");

	m_btnBuyVolTot.Create("", WS_CHILD | WS_VISIBLE /*| BS_OWNERDRAW*/, CRect(0, 0, 0, 0), this, IDC_BTN_BUY_VOL_TOT);
	m_btnBuyVolTot.SetFont(&m_fontDefault);
	m_btnBuyVolTot.SetWindowText("금");
	if (IsDerivativesMap())
		m_btnBuyVolTot.ShowWindow(SW_HIDE);

	m_edtBuyVolTot.Create(WS_CHILD | WS_VISIBLE | ES_RIGHT, CRect(0, 0, 0, 0), this, IDC_EDT_BUY_VOL_TOT);
	m_edtBuyVolTot.SetFont(&m_fontDefault);
	if (IsDerivativesMap())
		m_edtBuyVolTot.ShowWindow(SW_HIDE);

	m_btnBuyVolTotApply.Create("", WS_CHILD | WS_VISIBLE /*| BS_OWNERDRAW*/, CRect(0, 0, 0, 0), this, IDC_BTN_BUY_VOL_TOT_APPLY);
	m_btnBuyVolTotApply.SetFont(&m_fontDefault);
	m_btnBuyVolTotApply.SetWindowText("만원");	
	if (IsDerivativesMap())
		m_btnBuyVolTotApply.ShowWindow(SW_HIDE);
	

	m_btnOrderReg.Create(_T("등록"), WS_CHILD | WS_VISIBLE /*| BS_OWNERDRAW*/, 
		CRect(0, 0, 0, 0), this, IDB_REG);
	m_btnOrderReg.SetFont(&m_fontDefault);

	// 20120723 ssj - 서버자동주문 >>
	CString strText1, strText2, strText3;
	if (IsEquitiesMap())
	{
		strText1 = "[일반주문, 분할주문 주의사항]";
		strText2 = "1. 매도가능 수량을 100%미만으로 등록하였을 때 조건만족시 10주";
		strText3 = "   단위로 거래가 가능한 종목인 경우에 주문수량중 단주수량은 버리고";
	}
	else
	{
		strText1 = "[당일청산 주의사항]";
		strText2 = "1. 당일청산 주문 만족시 무조건 지정된 시각에 시장가로 청산가능 수량으로 주문접수";
		strText3 = "   되므로 다른 조건 등록시 저장한 주문수량, 단가, 주문구분이 적용되지 않음";
	}
	// 20120723 ssj - 서버자동주문 <<

	m_ctrlHelpText1.Create(strText1,
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE, 
		CRect(0, 0, 0, 0), this);
	m_ctrlHelpText1.SetFont(&m_fontDefault);

	m_ctrlHelpText2.Create(strText2,
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE, 
		CRect(0, 0, 0, 0), this);
	m_ctrlHelpText2.SetFont(&m_fontDefault);

	m_ctrlHelpText3.Create(strText3,
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE, 
		CRect(0, 0, 0, 0), this);
	m_ctrlHelpText3.SetFont(&m_fontDefault);

	m_ctrlHelpText4.Create(_T("   10주 단위로 주문이 전송됩니다.(EX:매도가능 수량이 90주이고,"),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE, 
		CRect(0, 0, 0, 0), this);
	m_ctrlHelpText4.SetFont(&m_fontDefault);

	m_ctrlHelpText5.Create(_T("   수량이 90%인 경우에 주문수량이 81주로 되어 80주만 주문)"),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE, 
		CRect(0, 0, 0, 0), this);
	m_ctrlHelpText5.SetFont(&m_fontDefault);

	m_ctrlHelpText6.Create(_T("2. 분할주문시에 분할비율로 주문수량이 계산될 때 단주수량은 버리고 마지막"),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE, 
		CRect(0, 0, 0, 0), this);
	m_ctrlHelpText6.SetFont(&m_fontDefault);

	m_ctrlHelpText7.Create(_T("   호가에 버린 수량이 적용된 후 1번항목 처럼 10주단위로 주문전송"),
		WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE, 
		CRect(0, 0, 0, 0), this);
	m_ctrlHelpText7.SetFont(&m_fontDefault);


	if(!m_Statistic.CreateWnd(this, IDCT_STATISTIC_CTRL))
		return FALSE;

//	InitCtrlValue();
//	SetInit();
	return 0;
}

void COrderTypeWnd::OnDestroy()
{
	CWnd::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}

void COrderTypeWnd::SetExpiredDateCtrl(BOOL bNormal)
{
	//유효기간 	
	CTime time = CTime::GetCurrentTime(); //KSLink_GetCurrentTime();

	m_dtmExpireDate.SetTime(&time);
	m_dtmExpireDate.EnableWindow(bNormal);
}

void COrderTypeWnd::EnableExDateCtrl(BOOL bEnable)
{		
	m_dtmExpireDate.EnableWindow(bEnable);
}


void COrderTypeWnd::InitCtrlValue()
{	
	
	m_rdoVolPercent.SetCheck(BST_CHECKED);
	m_rdoVolDigit.SetCheck(BST_UNCHECKED);

	OnBtnSellVolPercent();
	
	if(GetParent()->SendMessage(UMSG_GET_ORDAUTOFLAG, 0, 0))
		SetExpiredDateCtrl(FALSE);
	else
		SetExpiredDateCtrl(TRUE);
	
	int nIndex;
	//분할기준
	m_cmbDivStd.ResetContent();
	for(nIndex = 0; nIndex < _countof(DIV_STANDARD_STRING); nIndex++)
		m_cmbDivStd.AddString(DIV_STANDARD_STRING[nIndex]);
	m_cmbDivStd.SetCurSel(1);
	m_Statistic.SetDivType(m_cmbDivStd.GetCurSel());

	//기준가	
	m_cmbStdCost.ResetContent();
	for(nIndex = DIVSTANDARD_INDEX; nIndex <= DIVSTANDARD_INDEX * 2 + 1; nIndex++)
		m_cmbStdCost.AddString(PRICE_STANDARD_STRING[nIndex]);
	m_cmbStdCost.SetCurSel(0);
	m_Statistic.SetStandardPrice(m_cmbStdCost.GetCurSel());

	//분할방향
	m_cmbDivWay.ResetContent();
	m_cmbDivWay.AddString(_T("매수방향"));
	m_cmbDivWay.AddString(_T("매도방향"));	
	m_cmbDivWay.SetCurSel(0);
	m_Statistic.SetDivWay(0);
	
	//분할수
	m_SpinDivCnt.SetPos(5);	
	m_Statistic.SetRowCount(5);
	m_EditDivCnt.SetWindowText("5");
	//분할단위
	m_SpinDivUnit.SetPos(5);	

	CString strValue;
	if(m_cOrdMinSet.m_enOrdType == TIMEDIV_ORDER)
	{
		m_EditDivCnt.GetWindowText(strValue);
		if(strValue == "0")
			strValue = "5";
		m_Statistic.SetHogaOrTimeDiv(TIMEDIV_ORDER, atoi(strValue));
	}
	else if(m_cOrdMinSet.m_enOrdType == HOGADIV_ORDER)
	{
		m_EditDivCnt.GetWindowText(strValue);
		if(strValue == "0")
			strValue = "2";
		m_Statistic.SetHogaOrTimeDiv(HOGADIV_ORDER, atoi(strValue));
	}		
	
// 

	//주문구분
	m_comboPriceType.ResetContent();
	//주문 가격 형식 구문
	//>>[KSJ000000026] 신용주문추가, 주문구분추가
	int nPTypeCnt = PRICETYPE_CNT_STOCK;
	if(m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_STOCK) == 0) // ||m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_KOSPI) == 0 ||m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_KOSDAQ) == 0)
	{
		if (m_nNormalDiv == ORDTYPEWND_NORMAL)
			m_chkMarketPrice.ShowWindow(SW_SHOW);
		for (int nIndex = 0; nIndex < nPTypeCnt; nIndex++)
			m_comboPriceType.AddString(PRICE_TYPE_STRING_EX[nIndex]);
	}
	/*else if(m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_ELW) == 0)
	{
		nPTypeCnt = PRICETYPE_CNT_ELW; 
		m_chkMarketPrice.ShowWindow(SW_HIDE);

		for (int nIndex = 0; nIndex < nPTypeCnt; nIndex++)
			m_comboPriceType.AddString(PRICE_TYPE_STRING_ELW_EX[nIndex]);	
	}
	else if(m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_FUT) == 0 ||
			m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_OPT) == 0)
	{
		m_chkMarketPrice.EnableWindow(TRUE);

		nPTypeCnt = PRICETYPE_CNT_FUTOPT;
		for (int nIndex = 0; nIndex < nPTypeCnt; nIndex++)
			m_comboPriceType.AddString(PRICE_TYPE_STRING_FUTOPT_EX[nIndex]);
	}	
	else if (m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_SFUT) == 0)
	{
		m_chkMarketPrice.EnableWindow(FALSE);

		nPTypeCnt = PRICETYPE_CNT_SFUT;
		for (int nIndex = 0; nIndex < nPTypeCnt; nIndex++)
			m_comboPriceType.AddString(PRICE_TYPE_STRING_SFUT[nIndex]);
	}*/



	m_comboPriceType.SetCurSel(0);
	//시장가 체크박스
	m_chkMarketPrice.SetCheck(FALSE);

	//단가구분
	m_cmbPriceGb.ResetContent();
	//단가구분

	int nCnt = _countof(PRICE_GB_STRING);
	if(m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_ELW) == 0		
		|| m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_FUT) == 0
		|| m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_OPT) == 0
		|| m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_SFUT) == 0		
		)
	{
		nCnt -= 2;
	}

	for (int nIndex = 0; nIndex < nCnt; nIndex++)
		m_cmbPriceGb.AddString(PRICE_GB_STRING[nIndex]);
	m_cmbPriceGb.SetCurSel(0);

	OnChangePriceType();

	
	SetPriceUnit();
	
	if(m_cOrdMinSet.m_strMMType.CompareNoCase(SVRORD_MMTYPE_SELL) == 0) //매도
	{
		//매도비중
		m_spinSellVolRate.SetPos(0);
		//매도단가
		m_spinSellPrice.SetPos(0);
	}
	else
	{
		//매수수량
		m_spinBuyVolume.SetPos(0);
		//매수단가
		m_spinBuyPrice.SetPos(0);
	}
	m_stcCheckVolOutput.SetWindowText("");

	DivideSet();
	
}

void COrderTypeWnd::SetInit()
{
	InitCtrlStateWithFlag(&m_cOrdMinSet);	

}

void COrderTypeWnd::SetOrderTypeInit(COrdMinSet* pcOrdMinSet)
{
	m_cOrdMinSet.m_strMarketType = pcOrdMinSet->m_strMarketType;
	m_cOrdMinSet.m_strMMType	  = pcOrdMinSet->m_strMMType;
	InitCtrlStateWithFlag(&m_cOrdMinSet);	

	InitCtrlValue();	

}

void COrderTypeWnd::InitCtrlStateWithFlag(COrdMinSet* pclOrdMinSet)
{
	m_Statistic.SetBaseInfo(m_cOrdMinSet);
	
	m_ctrlPriceTypeText.ShowWindow(SW_HIDE);	
	m_comboPriceType.ShowWindow(SW_HIDE);	

	m_ctrlVolText1.ShowWindow(SW_HIDE);	
	m_editSellVolRate.ShowWindow(SW_HIDE);			//매도비중 edit
	m_spinSellVolRate.ShowWindow(SW_HIDE);			//매도비중 spin
	m_stcCheckVolOutput.ShowWindow(SW_HIDE);
	m_ctrlSellVolRateText2.ShowWindow(SW_HIDE);		//% 단위 static
	m_ctrlWonText1.ShowWindow(SW_HIDE);		
	m_editSellPrice.ShowWindow(SW_HIDE);			//매도단가 edit	
	m_spinSellPrice.ShowWindow(SW_HIDE);			//매도단가 spin	
	m_editBuyVolume.ShowWindow(SW_HIDE);			//매수수량edit
	m_spinBuyVolume.ShowWindow(SW_HIDE);			//매수수량 spin
	m_ctrlBuyVolText.ShowWindow(SW_HIDE);			//'주'단위 static
	m_editBuyPrice.ShowWindow(SW_HIDE);				//매수단가 edit	
	m_spinBuyPrice.ShowWindow(SW_HIDE);				//매수단가 spin
	m_btnBidAskDlg.ShowWindow(SW_HIDE);
	m_ctrlDivStdText.ShowWindow(SW_HIDE);
	m_cmbDivStd.ShowWindow(SW_HIDE);				//분할기준
	m_ctrlDivCnt.ShowWindow(SW_HIDE);	
	m_EditDivCnt.ShowWindow(SW_HIDE);				//분할수 Edit
	m_SpinDivCnt.ShowWindow(SW_HIDE);				//분할수 Spin
	m_ctrlStdCost.ShowWindow(SW_HIDE);				//기준가
	m_cmbStdCost.ShowWindow(SW_HIDE);
	m_ctrlDivWay.ShowWindow(SW_HIDE);				//기준가방향
	m_cmbDivWay.ShowWindow(SW_HIDE);	

	m_ctrlDivUnit.ShowWindow(SW_HIDE);	
	m_EditDivUnit.ShowWindow(SW_HIDE);				//분할단위 Edit
	m_SpinDivUnit.ShowWindow(SW_HIDE);				//분할단위 Spin
		
	m_chkMarketPrice.ShowWindow(SW_HIDE);			//시장가 checkbox

	m_ctrlExpiredateText1.ShowWindow(SW_SHOW);	
	
	m_dtmExpireDate.ShowWindow(SW_SHOW);
	

	//매수, 매도에 따른 초기화 세팅
	if(pclOrdMinSet->m_strMMType.CompareNoCase(SVRORD_MMTYPE_SELL) == 0) //매도
	{
		m_ctrlVolText1.ShowWindow(SW_SHOW);	
		m_editSellVolRate.ShowWindow(SW_SHOW);			//매도비중 edit
		m_spinSellVolRate.ShowWindow(SW_SHOW);			//매도비중 spin
		m_stcCheckVolOutput.ShowWindow(SW_SHOW);
		m_ctrlSellVolRateText2.ShowWindow(SW_SHOW);		//% 단위 static
		m_ctrlWonText1.ShowWindow(SW_SHOW);		
		m_editSellPrice.ShowWindow(SW_SHOW);			//매도단가 edit	
		m_spinSellPrice.ShowWindow(SW_SHOW);			//매도단가 spin
		//m_ctrlWonText2.ShowWindow(SW_SHOW);			//원 단위 static	

		//선옵일 경우 수량처리
		if(pclOrdMinSet->m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_FUT) == 0 ||
			pclOrdMinSet->m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_OPT) == 0 ||
			pclOrdMinSet->m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_SFUT) == 0)
		{
			m_ctrlVolText1.SetWindowText("매도수량");			
			m_ctrlSellVolRateText2.SetWindowText(_T("주"));			
		}
		else
			m_ctrlVolText1.SetWindowText("매도비중");

		m_ctrlWonText1.SetWindowText("매도단가");

		
		m_btnBuyVolMax.ShowWindow(SW_HIDE);
		m_btnBuyVolTot.ShowWindow(SW_HIDE);
		m_edtBuyVolTot.ShowWindow(SW_HIDE);
		m_btnBuyVolTotApply.ShowWindow(SW_HIDE);
	
	}
	else if(pclOrdMinSet->m_strMMType.CompareNoCase(SVRORD_MMTYPE_BUY) == 0) //매수
	{
		if (IsDerivativesMap())
			m_stcCheckVolOutput.ShowWindow(SW_SHOW);

		m_editBuyVolume.ShowWindow(SW_SHOW);			//매수수량edit
		m_spinBuyVolume.ShowWindow(SW_SHOW);			//매수수량 spin
		m_ctrlBuyVolText.ShowWindow(SW_SHOW);			//'주'단위 static
		m_editBuyPrice.ShowWindow(SW_SHOW);				//매수단가 edit	
		m_spinBuyPrice.ShowWindow(SW_SHOW);				//매수단가 spin
		

		m_ctrlVolText1.ShowWindow(SW_SHOW);
		m_ctrlWonText1.ShowWindow(SW_SHOW);

		m_ctrlVolText1.SetWindowText("매수수량");
		m_ctrlWonText1.SetWindowText("매수단가");



		if (IsEquitiesMap() && m_nSellBuy == WND_BUY)
		{
			m_btnBuyVolMax.ShowWindow(SW_SHOW);
			m_btnBuyVolTot.ShowWindow(SW_SHOW);
		}
		m_edtBuyVolTot.ShowWindow(SW_HIDE);
		m_btnBuyVolTotApply.ShowWindow(SW_HIDE);

	}
		
	//주문타입에 따른 초기화 세팅
	switch(pclOrdMinSet->m_enOrdType)
	{
	case NORMAL_ORDER:		
		//m_ctrlExpiredateText2.ShowWindow(SW_SHOW);	
		m_ctrlPriceTypeText.ShowWindow(SW_SHOW);	
		m_comboPriceType.ShowWindow(SW_SHOW);	
		m_chkMarketPrice.ShowWindow(SW_SHOW);	
		m_ctrlHelpText1.ShowWindow(SW_SHOW);
		m_ctrlHelpText2.ShowWindow(SW_SHOW);
		m_ctrlHelpText3.ShowWindow(SW_SHOW);
		if (IsEquitiesMap())
		{
			m_ctrlHelpText4.ShowWindow(SW_SHOW);
			m_ctrlHelpText5.ShowWindow(SW_SHOW);
			m_ctrlHelpText6.ShowWindow(SW_SHOW);
			m_ctrlHelpText7.ShowWindow(SW_SHOW);
		}
		m_cmbPriceGb.ShowWindow(SW_SHOW);
		m_btnDivSet.ShowWindow(SW_HIDE);
		m_Statistic.ShowWindow(SW_HIDE);		

		// 20120723 ssj - 서버자동주문 >>
		if (IsEquitiesMap())
		{
			if(pclOrdMinSet->m_strMMType.CompareNoCase(SVRORD_MMTYPE_SELL) == 0) //매도
			{
				m_rdoVolPercent.ShowWindow(SW_SHOW);
				m_rdoVolDigit.ShowWindow(SW_SHOW);
			}
			else
			{
				m_rdoVolPercent.ShowWindow(SW_HIDE);
				m_rdoVolDigit.ShowWindow(SW_HIDE);
			}
		}
		else
		{
			m_rdoVolPercent.ShowWindow(SW_SHOW);
			m_rdoVolDigit.ShowWindow(SW_SHOW);
		}

		m_btnBidAskDlg.ShowWindow(SW_SHOW);
		// 20120723 ssj - 서버자동주문 <<

		break;

	case HOGADIV_ORDER:
		m_ctrlDivStdText.ShowWindow(SW_SHOW);	
		m_cmbDivStd.ShowWindow(SW_SHOW);	
		m_ctrlDivCnt.ShowWindow(SW_SHOW);
		m_EditDivCnt.ShowWindow(SW_SHOW);
		m_SpinDivCnt.ShowWindow(SW_SHOW);
		m_ctrlStdCost.ShowWindow(SW_SHOW);
		m_cmbStdCost.ShowWindow(SW_SHOW);
		m_ctrlDivWay.ShowWindow(SW_SHOW);
		m_cmbDivWay.ShowWindow(SW_SHOW);

		m_editSellPrice.ShowWindow(SW_HIDE);			//매도단가 edit	
		m_spinSellPrice.ShowWindow(SW_HIDE);			//매도단가 spin
		m_editBuyPrice.ShowWindow(SW_HIDE);				//매수단가 edit	
		m_spinBuyPrice.ShowWindow(SW_HIDE);

		m_ctrlWonText1.ShowWindow(SW_HIDE);	
		//m_ctrlWonText2.ShowWindow(SW_HIDE);	
		m_btnDivSet.ShowWindow(SW_SHOW);
		m_Statistic.ShowWindow(SW_SHOW);
		m_ctrlHelpText1.ShowWindow(SW_HIDE);
		m_ctrlHelpText2.ShowWindow(SW_HIDE);
		m_ctrlHelpText3.ShowWindow(SW_HIDE);
		m_ctrlHelpText4.ShowWindow(SW_HIDE);
		m_ctrlHelpText5.ShowWindow(SW_HIDE);
		m_ctrlHelpText6.ShowWindow(SW_HIDE);
		m_ctrlHelpText7.ShowWindow(SW_HIDE);
		m_cmbPriceGb.ShowWindow(SW_HIDE);
		
		m_rdoVolPercent.ShowWindow(SW_HIDE);
		m_rdoVolDigit.ShowWindow(SW_HIDE);
	
		break;


	default:
		break;
	}	
}


void COrderTypeWnd::SetInitWithData(COrdTypeBase* pOrdTypeBase)	
{
	
}


void COrderTypeWnd::SetValuesFromClassToCtrl()
{

}
void COrderTypeWnd::SetValuesFromCtrlToClass()
{

}

BOOL COrderTypeWnd::CheckSettingIsValid()
{
	BOOL bOk = TRUE;
	return bOk;
}

void COrderTypeWnd::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	Resize();
}

void COrderTypeWnd::Resize()
{
	CRect rtClient, rtTemp;
	GetClientRect(rtClient);	

	if ( rtClient.Width() <= 0 || rtClient.Height() <= 0)
		return  ;

	rtTemp = rtClient;

	//Line1
	//유효기간
	rtTemp.top += 2;
	rtTemp.bottom = rtTemp.top  + LEN_CTRL_HEIGHT;
	rtTemp.right  = rtTemp.left + LEN_CTRL_WIDTHX4;

	if (m_ctrlExpiredateText1 )
	m_ctrlExpiredateText1.MoveWindow(rtTemp);

	rtTemp.left  = rtTemp.right + LEN_TEXT_TO_CTRL;
	rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX10;
	//rtTemp.bottom += LEN_COMBO_HEIGHT;
	//m_comboExpiredate.MoveWindow(rtTemp);
	//rtTemp.bottom -= LEN_COMBO_HEIGHT;
	m_dtmExpireDate.MoveWindow(rtTemp);

	//rtTemp.left  = rtTemp.right + LEN_TEXT_TO_CTRL;
	//rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX10;
	//m_ctrlExpiredateText2.MoveWindow(rtTemp);

	//Line2
	//주문구분
	rtTemp.left    = rtClient.left;
	rtTemp.top	   = rtTemp.bottom + LEN_CTRL_VGAP;
	rtTemp.bottom  = rtTemp.top + LEN_CTRL_HEIGHT;
	rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX4;
	CRect rtLine2 = rtTemp;
	m_ctrlPriceTypeText.MoveWindow(rtTemp);

	//주문 가격 형식 구문	
	rtTemp.left  = rtTemp.right + LEN_TEXT_TO_CTRL;
	rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX10;
	rtTemp.bottom += LEN_COMBO_HEIGHT;
	m_comboPriceType.MoveWindow(rtTemp);
	rtTemp.bottom -= LEN_COMBO_HEIGHT;

	//시장가 체크박스
	rtTemp.left  = rtTemp.right + LEN_TEXT_TO_CTRL;
	rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX10;
	m_chkMarketPrice.MoveWindow(rtTemp);


	//Line3
	//매도비중 text
	rtTemp.left    = rtClient.left;
	rtTemp.top	   = rtLine2.bottom + LEN_CTRL_VGAP;
	rtTemp.bottom  = rtTemp.top + LEN_CTRL_HEIGHT;
	rtTemp.right  = rtTemp.left + LEN_CTRL_WIDTHX4;
	CRect rtLine3 = rtTemp;

	if(m_cOrdMinSet.m_enOrdType != NORMAL_ORDER)
		rtTemp = rtLine2;
	m_ctrlVolText1.MoveWindow(rtTemp);


	rtTemp.left  = rtTemp.right + LEN_TEXT_TO_CTRL;
	if (IsEquitiesMap())
		rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX1 + 12;
	else
		rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX4 + 12;
	m_rdoVolPercent.MoveWindow(&rtTemp);

	rtTemp.left  = rtTemp.right + LEN_TEXT_TO_CTRL;
	rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX4 + 11;
	m_rdoVolDigit.MoveWindow(&rtTemp);

	//매도비중 edit
	rtTemp.left  = rtTemp.right + LEN_TEXT_TO_CTRL;
	rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX4 + 12;
	m_editSellVolRate.MoveWindow(rtTemp);

	//매도비중 spin
	rtTemp.left  = rtTemp.right;
	rtTemp.right = rtTemp.left + LEN_SPIN_WIDTH;
 	m_spinSellVolRate.MoveWindow(rtTemp);

	rtTemp.left  = rtTemp.right + 1;
	rtTemp.right = rtTemp.left + LEN_SPIN_WIDTH;
	m_ctrlSellVolRateText2.MoveWindow(rtTemp);


	// 20120723 ssj - 서버자동주문 >>
	if (IsEquitiesMap())
	{
		//if (m_cOrdMinSet.m_strMMType.CompareNoCase(SVRORD_MMTYPE_SELL) == 0)//매도
		if (m_nSellBuy == WND_SELL)
		{
			rtTemp.left = rtTemp.right + 2;
			rtTemp.right = rtTemp.left + 20;
			m_btnVolCheck.MoveWindow(rtTemp);
			
			rtTemp.left = rtTemp.right + 5;
			rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX8;
			m_stcCheckVolOutput.MoveWindow(rtTemp);
		}
	}
	

	//Line4
	//매도단가 text		
	rtTemp.left    = rtClient.left;
	rtTemp.top	   = rtLine3.bottom + LEN_CTRL_VGAP;
	rtTemp.bottom  = rtTemp.top + LEN_CTRL_HEIGHT;
	rtTemp.right  = rtTemp.left + LEN_CTRL_WIDTHX4;
	CRect rtLine4 = rtTemp;
	m_ctrlWonText1.MoveWindow(rtTemp);

	rtTemp.left  = rtTemp.right + LEN_TEXT_TO_CTRL;
	rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX4 + 12 + LEN_SPIN_WIDTH;
	rtTemp.bottom += 100;
	m_cmbPriceGb.MoveWindow(rtTemp);	
	rtTemp.bottom -= 100;

	//매도단가 edit
	rtTemp.left  = rtTemp.right + LEN_TEXT_TO_CTRL;
	rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX4 + 12;
	m_editSellPrice.MoveWindow(rtTemp);

	//매도단가 spin
	rtTemp.left  = rtTemp.right;
	rtTemp.right = rtTemp.left + LEN_SPIN_WIDTH;
	m_spinSellPrice.MoveWindow(rtTemp);

	// 20120723 ssj - 서버자동주문 >>
	if (m_nSellBuy == WND_SELL && m_cOrdMinSet.m_enOrdType == NORMAL_ORDER)
	{
		rtTemp.left  = rtTemp.right + 1;
		rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX1;
		m_btnBidAskDlg.MoveWindow(rtTemp);
	}
	// 20120723 ssj - 서버자동주문 <<

	//rtTemp.left  = rtTemp.right + 1;
	//rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX1;
	//m_ctrlWonText2.MoveWindow(rtTemp);

	//Line3
	//분할기준 text
	rtTemp = rtLine3;
	m_ctrlDivStdText.MoveWindow(rtTemp);

	//분할기준 edit
	rtTemp.left  = rtTemp.right + LEN_TEXT_TO_CTRL;
	rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX4 + 20;
	rtTemp.bottom += LEN_COMBO_HEIGHT;
	m_cmbDivStd.MoveWindow(rtTemp);
	rtTemp.bottom -= LEN_COMBO_HEIGHT;

	//분할수
	rtTemp.left  = rtTemp.right + LEN_TEXT_TO_CTRL;
	rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX4;
	m_ctrlDivCnt.MoveWindow(rtTemp);

	//분할수 edit
	rtTemp.left  = rtTemp.right + LEN_TEXT_TO_CTRL;
	rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX2;
	m_EditDivCnt.MoveWindow(rtTemp);

	//분할수 spin
	rtTemp.left  = rtTemp.right;
	rtTemp.right = rtTemp.left + LEN_SPIN_WIDTH;
	m_SpinDivCnt.MoveWindow(rtTemp);

	//Line4
	//기준가 Text
	rtTemp = rtLine4;
	m_ctrlStdCost.MoveWindow(rtTemp);

	//기준가 Combo
	rtTemp.left  = rtTemp.right + LEN_TEXT_TO_CTRL;
	rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX4 + 20;
	rtTemp.bottom += LEN_COMBO_HEIGHT;
	m_cmbStdCost.MoveWindow(rtTemp);
	rtTemp.bottom -= LEN_COMBO_HEIGHT;

	//분할단위
	rtTemp.left  = rtTemp.right + LEN_TEXT_TO_CTRL;
	rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX4;
	m_ctrlDivUnit.MoveWindow(rtTemp);
	//분할방향
	m_ctrlDivWay.MoveWindow(rtTemp);

	//분할단위 edit
	rtTemp.left  = rtTemp.right + LEN_TEXT_TO_CTRL;
	rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX4;
	m_EditDivUnit.MoveWindow(rtTemp);
	//분할방향
	rtTemp.right += 12;
	rtTemp.bottom += 40;
	m_cmbDivWay.MoveWindow(rtTemp);
	rtTemp.right -= 12;
	rtTemp.bottom -= 40;

	//분할단위 spin
	rtTemp.left  = rtTemp.right;
	rtTemp.right = rtTemp.left + LEN_SPIN_WIDTH;
	m_SpinDivUnit.MoveWindow(rtTemp);

	//적용버튼
	rtTemp.bottom = rtTemp.top - 1;
	rtTemp.top	  = rtTemp.bottom - LEN_CTRL_HEIGHT;
//	rtTemp.left  = rtTemp.right + LEN_TEXT_TO_CTRL;
	rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX2;
	m_btnDivSet.MoveWindow(rtTemp);


	//매수수량 edit
	// 20120723 ssj - 서버자동주문 >>
	//m_editSellVolRate.GetWindowRect(rtTemp); //매수,매도 따라 다르지만 같은위치
	//ScreenToClient(rtTemp);
	//m_editBuyVolume.MoveWindow(rtTemp);
	CRect rtVolEdit;
	m_editSellVolRate.GetWindowRect(rtVolEdit); //매수,매도 따라 다르지만 같은위치이므로 기준으로 삼는다
	if (IsEquitiesMap())
	{
		m_ctrlVolText1.GetWindowRect(rtTemp);
		ScreenToClient(rtTemp);
		rtTemp.left = rtTemp.right + LEN_TEXT_TO_CTRL;
		rtTemp.right = rtTemp.left + rtVolEdit.Width();
	}
	else
	{
		ScreenToClient(rtVolEdit);
		rtTemp = rtVolEdit;
	}
	m_editBuyVolume.MoveWindow(&rtTemp);
	// 20120723 ssj - 서버자동주문 <<

	//매수수량 spin
	// 20120723 ssj - 서버자동주문 >>
	//m_spinSellVolRate.GetWindowRect(rtTemp); //매수,매도 따라 다르지만 같은위치
	//ScreenToClient(rtTemp);
	rtTemp.left  = rtTemp.right + 1;
	rtTemp.right = rtTemp.left + LEN_SPIN_WIDTH; 
	// 20120723 ssj - 서버자동주문 <<
	m_spinBuyVolume.MoveWindow(rtTemp);

	//매수수량 '주'
	rtTemp.left  = rtTemp.right + 1;
	rtTemp.right = rtTemp.left + LEN_SPIN_WIDTH; 
	m_ctrlBuyVolText.MoveWindow(rtTemp);

	//매수단가 edit
	m_editSellPrice.GetWindowRect(rtTemp); //매수,매도 따라 다르지만 같은위치
	ScreenToClient(rtTemp);
	m_editBuyPrice.MoveWindow(rtTemp);

	//매수단가 spin
	rtTemp.left  = rtTemp.right;
	rtTemp.right = rtTemp.left + LEN_SPIN_WIDTH; 
	m_spinBuyPrice.MoveWindow(rtTemp);

	// 20120723 ssj - 서버자동주문 >>
	if (m_nSellBuy == WND_BUY && m_cOrdMinSet.m_enOrdType == NORMAL_ORDER)
	{
		rtTemp.left  = rtTemp.right + 1;
		rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX1;
		m_btnBidAskDlg.MoveWindow(rtTemp);
	}
	// 20120723 ssj - 서버자동주문 <<

	//등록버튼
	rtTemp.left    = rtClient.left + LEN_CTRL_WIDTHX4 + LEN_TEXT_TO_CTRL;
	rtTemp.top	   = rtTemp.bottom + 2;
	rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX8;
	rtTemp.bottom  = rtTemp.top + LEN_CTRL_HEIGHT;
	m_btnOrderReg.MoveWindow(rtTemp);

	//그리드
	//Line4
	//매도단가 text
	rtTemp.left    = rtClient.left;
	rtTemp.top	   = rtTemp.bottom + LEN_CTRL_VGAP5;
	rtTemp.bottom  = rtTemp.top + 140;
	rtTemp.right  = rtClient.right;
	m_Statistic.MoveWindow(rtTemp);

	MoveHelpTextWnd();
	// 20120723 ssj - 서버자동주문 <<
}

COrdTypeBase COrderTypeWnd::GetOrderTypeInfo()
{
	m_cOrdType.ClearData();

	CString strExpireDate, strPrice, strDivCnt, strVol;
	//유효기간
	//m_comboExpiredate.GetWindowText(strExpireDate);
	//strExpireDate.Trim();
	//strExpireDate.Replace("-", "");
	CTime tm;
	m_dtmExpireDate.GetTime(tm);
	strExpireDate = tm.Format("%Y%m%d");
	m_cOrdType.SetExpireDate(strExpireDate);  

	//주문타입

	//주문구분
	int nPriceType = m_comboPriceType.GetCurSel(); 
	CString strPriceType;
	m_comboPriceType.GetWindowText(strPriceType);

	int nIndex;
	for(nIndex = 0; nIndex < _countof(PRICE_TYPE_VALUE_EX); nIndex++)
	{
		if(	strPriceType.CompareNoCase(PRICE_TYPE_STRING_EX[nIndex]) == 0)
		{
			m_cOrdType.SetPriceType(PRICE_TYPE_VALUE_EX[nIndex]); //[KSJ000000026] 신용주문추가, 주문구분추가	
			break;
		}
	}

	//지정가 인지 여부
	BOOL IsTargetPrice = FALSE;
	for(nIndex = 0; nIndex < _countof(PRICE_TYPE_TARGET); nIndex++)
	{
		if(strPriceType.CompareNoCase(PRICE_TYPE_TARGET[nIndex]) == 0)
		{
			IsTargetPrice = TRUE;
			break;
		}
	}
	
	
	////분할수
	m_EditDivCnt.GetWindowText(strDivCnt);
	m_cOrdType.SetOrdDivCnt(atoi(strDivCnt));

	//분할단위
	int nOrdUnit = (int)m_SpinDivUnit.GetPos();

	//분할기준
	int nDivStd = m_cmbDivStd.GetCurSel();
	m_cOrdType.SetDivStd(nDivStd);
	//분할방향
	int nDivWay = m_cmbDivWay.GetCurSel();
	m_cOrdType.SetDivWay(nDivWay);

	
	CString strData;
	if(m_cOrdMinSet.m_strMMType.CompareNoCase(SVRORD_MMTYPE_BUY) == 0)//매수
	{
		if(m_cOrdMinSet.m_enOrdType == NORMAL_ORDER) //일반주문
		{	
			m_cOrdType.SetOrdDivCnt(1);	//분할수
			m_editBuyPrice.GetWindowText(strPrice);
			strPrice = _T("J") + strPrice;
			strPrice.Remove(',');
			
		//	m_cOrdType.m_saOrdPrice.Add(strPrice);	

			//매수수량
			m_editBuyVolume.GetWindowText(strVol);
			strVol.Remove(',');
			m_cOrdType.SetBaseQty(strVol);

			m_cOrdType.AddOrdReqQty(strVol);
			m_cOrdType.SetOrdUnit(0);

			if(!IsTargetPrice)
 				strPrice = _T("J0");			

			//단가타입
			int nPriceUnit = m_cmbPriceGb.GetCurSel();			
			if(IsTargetPrice) //지정가일경우 조건부지정가, 지정가[IOC], 지정가[FOK]
			{
				if(nPriceUnit == 0)
					m_cOrdType.m_saOrdPrice.Add(strPrice);
				else
					m_cOrdType.m_saOrdPrice.Add(PRICE_TYPE_STRING2[nPriceUnit]);
			}
			else
				m_cOrdType.m_saOrdPrice.Add(strPrice);			

		}
		else
		{
			int nDivWay = m_cmbDivWay.GetCurSel(); //분할방향 0:매수방향 1:매도방향
			int nStandardPriceSel =	m_cmbStdCost.GetCurSel() + 4;	//기준가 ex)매수1호가
			//실제 콤보박스에 보여지는 인덱스와 정의된 배열과의의 차이 4
			int nDivCnt = atoi(strDivCnt);						    //분할수

			//주문가격	
			if(nDivWay == 1)
			{
				int nDivCnt = atoi(strDivCnt);
				nStandardPriceSel -= (nDivCnt-1);
			}

			for(nIndex = 0; nIndex < nDivCnt; nIndex++)
			{				
				strData = PRICE_STANDARD_STRING_CONVERT[nStandardPriceSel++];
				m_cOrdType.AddOrdReqPrice(strData);	
			}
			//매수수량
			m_editBuyVolume.GetWindowText(strVol);
			strVol.Remove(',');
			m_cOrdType.SetBaseQty(strVol);

			m_cOrdType.SetOrdReqQty(m_Statistic.GetDivQtyValue());
			m_cOrdType.SetOrdUnit(nOrdUnit);
		}
		
		//수량, 백분율 구분
		if (IsEquitiesMap())
		{
			m_cOrdType.SetQtyGb(1);
		}
		else
		{
			if (m_cOrdMinSet.m_enOrdType == NORMAL_ORDER) //일반주문
			{
				if (m_rdoVolPercent.GetCheck() == BST_CHECKED)
					m_cOrdType.SetQtyGb(2);
				else
					m_cOrdType.SetQtyGb(1);
			}
			else
			{
				m_cOrdType.SetQtyGb(1);
			}
		}
	}
	else //매도
	{
		if(m_cOrdMinSet.m_enOrdType == NORMAL_ORDER) //일반주문
		{
			m_cOrdType.SetOrdDivCnt(1); //분할수
			m_editSellPrice.GetWindowText(strPrice);
			strPrice = _T("J") + strPrice;
			strPrice.Remove(',');
			/*m_cOrdType.m_saOrdPrice.Add(strPrice);*/

			m_editSellVolRate.GetWindowText(strVol);
			strVol.Remove(',');

			//매도 일반주문일경우 기본 수량%는 100%로 세팅
			m_cOrdType.SetBaseQty("100");
			m_cOrdType.AddOrdReqQty(strVol);
			m_cOrdType.SetOrdUnit(0);

			if(!IsTargetPrice)
				strPrice = _T("J0");

			//단가타입
			int nPriceUnit = m_cmbPriceGb.GetCurSel();

			//[KSJ000000026] 신용주문추가, 주문구분추가
			if(IsTargetPrice) //지정가일경우 조건부지정가, 지정가[IOC] 지정가[FOK]
			{
				if(nPriceUnit == 0)
					m_cOrdType.m_saOrdPrice.Add(strPrice);
				else
					m_cOrdType.m_saOrdPrice.Add(PRICE_TYPE_STRING2[nPriceUnit]);
			}
			else
				m_cOrdType.m_saOrdPrice.Add(strPrice);	

		}
		else
		{
			int nDivWay = m_cmbDivWay.GetCurSel(); //분할방향 0:매수방향 1:매도방향
			int nStandardPriceSel =	m_cmbStdCost.GetCurSel() + 4;	//기준가 ex)매수1호가
			int nDivCnt = atoi(strDivCnt);						//분할수

			m_editSellVolRate.GetWindowText(strVol);
			strVol.Remove(',');
			m_cOrdType.SetBaseQty(strVol);

			//주문가격	
			if(nDivWay == 1)
			{
				int nDivCnt = atoi(strDivCnt);
				nStandardPriceSel -= (nDivCnt-1);
			}
			//주문가격
			for(nIndex = 0; nIndex < nDivCnt; nIndex++)
				m_cOrdType.AddOrdReqPrice(PRICE_STANDARD_STRING_CONVERT[nStandardPriceSel++]);		
	
			m_cOrdType.SetOrdReqQty(m_Statistic.GetDivQtyValue());
			m_cOrdType.SetOrdUnit(nOrdUnit);

		}

		//수량, 백분율 구분
		if (IsEquitiesMap())
		{
			if (m_rdoVolPercent.GetCheck() == BST_CHECKED)
				m_cOrdType.SetQtyGb(2);
			else
				m_cOrdType.SetQtyGb(1);
		}
		
	}

	return m_cOrdType;
}

void COrderTypeWnd::SetOrderTypeInfo(COrdTypeBase cOrderTypeInfo)
{
	m_cOrdType = cOrderTypeInfo;


	CString strExpireDate = m_cOrdType.GetExpireDate();
	CString strPrice, strDivCnt, strVol, strData;
	int nData;
	int nDivCnt;
	//유효기간
	int nIndex;
	
	if (strExpireDate.GetLength() >= 8)
	{
		CString strYear = strExpireDate.Mid(0, 4);
		CString strMon = strExpireDate.Mid(4, 2);
		CString strDay = strExpireDate.Mid(6, 2);
		CTime time(atol(strYear), atol(strMon), atol(strDay), 0, 0, 0);
		m_dtmExpireDate.SetTime(&time);
	}


	strData = m_cOrdType.GetPriceType();
	strData.Trim();
	if(m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_STOCK) == 0)
	{
		for(nIndex = 0; nIndex < _countof(PRICE_TYPE_VALUE_EX); nIndex++)
		{
			if(strData.CompareNoCase(PRICE_TYPE_VALUE_EX[nIndex]) == 0)
			{
				m_comboPriceType.SetCurSel(nIndex);
				break;
			}
		}
	}
	
	

	////분할수
	nDivCnt = m_cOrdType.GetOrdDivCnt();
	if(nDivCnt == 0)//최소 두개이상
		nDivCnt = 2;

	m_SpinDivCnt.SetPos(nDivCnt);	
	strData.Format("%d", nDivCnt);
	m_EditDivCnt.SetWindowText(strData);

	int nPtypeCnt = _countof(PRICE_TYPE_STRING2);
	if(m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_ELW) == 0)
		nPtypeCnt -= 2;

	BOOL IsTargetPrice = TRUE;
	if(m_cOrdMinSet.m_strMMType.CompareNoCase(SVRORD_MMTYPE_BUY) == 0)//매수
	{
		if(m_cOrdMinSet.m_enOrdType == NORMAL_ORDER) //일반주문
		{	
			strPrice = m_cOrdType.m_saOrdPrice.GetAt(0);

			for(nIndex = 0; nIndex < nPtypeCnt; nIndex++)
			{	
				if(strPrice.CompareNoCase(PRICE_TYPE_STRING2[nIndex]) == 0)
				{
					m_cmbPriceGb.SetCurSel(nIndex);		
					IsTargetPrice = FALSE;
					break;
				}			
			}	
			//지정가일 경우
			if(IsTargetPrice)
			{
				strPrice.Replace("J", "");
				strPrice.Remove(',');
				double dPrice = atof(strPrice);
				m_spinBuyPrice.SetPos(dPrice);	
			}
			OnChangePriceUnit();			

			//기본수량 (일반 매수일때는 100으로 등록하므로 실제값은 요기)
			strVol = m_cOrdType.GetOrdReqQty()->GetAt(0);
			m_spinBuyVolume.SetPos(atof(strVol));

			
		}
		else
		{
			//분할기준
			int nDivStd = m_cOrdType.GetDivStd();
			m_cmbDivStd.SetCurSel(nDivStd);

			//분할방향
			int nDivWay = m_cOrdType.GetDivWay(); 
			m_cmbDivWay.SetCurSel(nDivWay);	
			// 20130627 ssj - 호가데이터 초기화 오류 수정 >>
			m_Statistic.SetDivWay(nDivWay);
			// 20130627 ssj - 호가데이터 초기화 오류 수정 <<

			//기준가
			CString strDiv;
			if(nDivWay == 0)
			{
				strDiv = m_cOrdType.m_saOrdPrice.GetAt(0);
			}
			else
			{
				if (m_cOrdType.m_saOrdPrice.GetCount() > 0)
					strDiv = m_cOrdType.m_saOrdPrice.GetAt(m_cOrdType.m_saOrdPrice.GetCount() - 1);
			}

			for(nIndex = 0; nIndex < _countof(PRICE_STANDARD_STRING_CONVERT); nIndex++)
			{
				if(strDiv.CompareNoCase(PRICE_STANDARD_STRING_CONVERT[nIndex]) == 0)
				{				
					break;
				}
			}
			m_cmbStdCost.SetCurSel(nIndex - 4);

		
			DivideSet();
			

			//분할단위
			nData = m_cOrdType.GetOrdUnit();
			m_SpinDivUnit.SetPos(nData);

			//기본수량 (일반 매수일때는 100으로 등록하므로 실제값은 요기)
			strVol = m_cOrdType.GetBaseQty();
			strVol.Remove(',');
			m_spinBuyVolume.SetPos(atof(strVol));

			//분할수량
			if(m_cOrdType.GetOrdReqQty())
				m_Statistic.SetDivQtyValue(m_cOrdType.GetOrdReqQty());		
			
			
		}
		//수량, 백분율 구분
		//m_cOrdType.SetQtyGb(1);
	}
	else //매도
	{
		if(m_cOrdMinSet.m_enOrdType == NORMAL_ORDER) //일반주문
		{
			strPrice = m_cOrdType.m_saOrdPrice.GetAt(0);

			for(nIndex = 0; nIndex < nPtypeCnt; nIndex++)
			{	
				if(strPrice.CompareNoCase(PRICE_TYPE_STRING2[nIndex]) == 0)
				{
					m_cmbPriceGb.SetCurSel(nIndex);		
					IsTargetPrice = FALSE;
					break;
				}			
			}	
			//지정가일 경우
			if(IsTargetPrice)
			{
				strPrice.Replace("J", "");
				strPrice.Remove(',');
				double dPrice = atof(strPrice);
				m_spinSellPrice.SetPos(dPrice);	
			}
			OnChangePriceUnit();				

 			strVol = m_cOrdType.GetOrdReqQty()->GetAt(0);
 			strVol.Remove(',');
			m_spinSellVolRate.SetPos(atof(strVol));

			if (m_cOrdType.GetQtyGb() == 1) // 수량
			{
				m_rdoVolPercent.SetCheck(BST_UNCHECKED);
				m_rdoVolDigit.SetCheck(BST_CHECKED);

				OnBtnSellVolDigit();
			}
			else
			{
				m_rdoVolPercent.SetCheck(BST_CHECKED);
				m_rdoVolDigit.SetCheck(BST_UNCHECKED);

				OnBtnSellVolPercent();
			}
		}
		else
		{
			//분할기준
			int nDivStd = m_cOrdType.GetDivStd();
			m_cmbDivStd.SetCurSel(nDivStd);

			//분할방향
			int nDivWay = m_cOrdType.GetDivWay(); 
			m_cmbDivWay.SetCurSel(nDivWay);	
			m_Statistic.SetDivWay(nDivWay);

			//기준가
			CString strDiv;
			if(nDivWay == 0)
				strDiv = m_cOrdType.m_saOrdPrice.GetAt(0);
			else
			{
				if (m_cOrdType.m_saOrdPrice.GetCount() > 0)
					strDiv = m_cOrdType.m_saOrdPrice.GetAt(m_cOrdType.m_saOrdPrice.GetCount() - 1);
			}

			for(nIndex = 0; nIndex < _countof(PRICE_STANDARD_STRING_CONVERT); nIndex++)
			{
				if(strDiv.CompareNoCase(PRICE_STANDARD_STRING_CONVERT[nIndex]) == 0)
				{				
					break;
				}
			}
			m_cmbStdCost.SetCurSel(nIndex - 4);

			DivideSet();
			
		

			//분할단위
			nData = m_cOrdType.GetOrdUnit();
			m_SpinDivUnit.SetPos(nData);

			//기본수량/비중
			strVol = m_cOrdType.GetBaseQty();
			strVol.Remove(',');
			m_spinSellVolRate.SetPos(atof(strVol));

			//분할비중
			if(m_cOrdType.GetOrdReqQty())
				m_Statistic.SetDivQtyValue(m_cOrdType.GetOrdReqQty());		

			

		}
	}

	OnChangePriceType();
}

void COrderTypeWnd::ChangeSkinColor(long lpColor)
{
	ST_CLIENTCOLOR* pstClrClient = (ST_CLIENTCOLOR*)lpColor;

	if(!pstClrClient)
		return;

	m_clrBk = pstClrClient->m_clrBkGnd;
	if(m_brushBk.DeleteObject())
		m_brushBk.CreateSolidBrush(m_clrBk);

	m_Statistic.ChangeSkinColor(lpColor);
	Invalidate();

}

HBRUSH COrderTypeWnd::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CWnd::OnCtlColor(pDC, pWnd, nCtlColor);

	if(nCtlColor == CTLCOLOR_STATIC) 	
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(m_clrText);
		hbr = m_brushBk;
	}

	return hbr;
}


BOOL COrderTypeWnd::OnEraseBkgnd(CDC* pDC)
{
	CRect rc;
	GetClientRect(rc);

	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);
	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());
	CBitmap* pOldbitmap = MemDC.SelectObject(&bitmap);

	MemDC.FillSolidRect(&rc, m_clrBk);
	pDC->BitBlt(0, 0, rc.Width(), rc.Height(), &MemDC, 0, 0, SRCCOPY);
	return TRUE;
}

void COrderTypeWnd::OnChangePriceType()
{
	int nCurSel = m_comboPriceType.GetCurSel();
	CString strText;

	m_comboPriceType.GetWindowText(strText);
	
	//>>[KSJ000000026] 신용주문추가, 주문구분추가
	CString strType;// = _T("지정가");
	BOOL bTargetPrice = FALSE;
	int nIndex;
	for(nIndex = 0; nIndex < _countof(PRICE_TYPE_TARGET); nIndex++)
	{
		strType = PRICE_TYPE_TARGET[nIndex];
		if(strType.CompareNoCase(strText) == 0)
		{
			bTargetPrice = TRUE;
			break;
		}
	}

	if(bTargetPrice) //<<[KSJ000000026] 신용주문추가, 주문구분추가
	{
		if(m_cmbPriceGb.GetCurSel() == 0)
		{
			m_editBuyPrice.EnableWindow(TRUE);
			m_editSellPrice.EnableWindow(TRUE);
		}
		else
		{
			m_editBuyPrice.EnableWindow(FALSE);
			m_editSellPrice.EnableWindow(FALSE);
		}
		m_cmbPriceGb.EnableWindow(TRUE);
	}
	else 
	{
		m_editBuyPrice.EnableWindow(FALSE);
		m_editSellPrice.EnableWindow(FALSE); 		
		m_cmbPriceGb.EnableWindow(FALSE);
	}

	m_spinBuyPrice.EnableWindow(TRUE);
	m_spinSellPrice.EnableWindow(TRUE);

	strType = _T("시장가");
	if(strType.CompareNoCase(strText) == 0) //>>[KSJ000000026] 신용주문추가, 주문구분추가
		m_chkMarketPrice.SetCheck(TRUE);
	else
		m_chkMarketPrice.SetCheck(FALSE);
}

void COrderTypeWnd::OnChangePriceUnit()
{
	int nCurSel = m_cmbPriceGb.GetCurSel();
	CString strUnit = _T("지정가");

	if(strUnit.CompareNoCase(PRICE_GB_STRING[nCurSel]) == 0)
	{
		m_editBuyPrice.EnableWindow(TRUE);
		m_editSellPrice.EnableWindow(TRUE);
	}
	else 
	{
		m_editBuyPrice.EnableWindow(FALSE);
		m_editSellPrice.EnableWindow(FALSE);
	}

}

void COrderTypeWnd::OnChangeDivWay()
{
	int nCurSel = m_cmbDivWay.GetCurSel();
	m_Statistic.SetDivWay(nCurSel);
	m_IsChangeSet = TRUE;
}

void COrderTypeWnd::OnChangeDivStd()
{
	m_IsChangeSet = TRUE;	
}

void COrderTypeWnd::OnChangeStdCost()
{
	m_IsChangeSet = TRUE;	
}


void COrderTypeWnd::OnBtnDivideSet()
{

	CString strData;
	if(IsSellTabSelected())
	{
		if(m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_FUT) == 0 ||
		   m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_OPT) == 0 ||
		   m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_SFUT) == 0)
		{
			m_editSellVolRate.GetWindowText(strData);
			if(strData.IsEmpty() || strData.CompareNoCase("0") == 0)
				DefMessageBox(GetSafeHwnd(), "매수(매도) 수량이 0일 경우에는 분할주문수량이 계산되지 않습니다.");
		}
		else
		{
			m_stcCheckVolOutput.GetWindowText(strData);
			if(strData.IsEmpty())
				DefMessageBox(GetSafeHwnd(), "가 버튼을 이용하여 수량을 조회해야 분할 주문수량을  확인할 수 있습니다.");
		}
	}
	else
	{
		m_editBuyVolume.GetWindowText(strData);
		if(strData.IsEmpty() || strData.CompareNoCase("0") == 0)
			DefMessageBox(GetSafeHwnd(), "매수(매도) 수량이 0일 경우에는 분할주문수량이 계산되지 않습니다");
	}

	DivideSet();
	m_IsChangeSet = FALSE;
}

void COrderTypeWnd::DivideSet()
{

	if (m_cOrdMinSet.m_enOrdType != HOGADIV_ORDER)
	{

		return;
	}

	//분할단위
	CString strDivUnit;
	m_EditDivUnit.GetWindowText(strDivUnit);
	m_Statistic.SetHogaOrTimeDiv(m_cOrdMinSet.m_enOrdType, atoi(strDivUnit));

	m_Statistic.SetStandardPrice(m_cmbStdCost.GetCurSel());
	m_Statistic.SetBarType(m_cmbDivStd.GetCurSel());


	CString strCount;
	m_EditDivCnt.GetWindowText(strCount);
	int nCount = atoi(strCount);

	m_Statistic.SetDivType(m_cmbDivStd.GetCurSel());

	if(nCount < 2 || nCount > 5)
	{
		DefMessageBox(GetSafeHwnd(), _T("분할수는 2 ~ 5사이의 숫자를 입력해 주십시오."));
		return;		
	}
	m_Statistic.SetRowCount(nCount);
	m_Statistic.CalcVolume();
}


void COrderTypeWnd::OnBtnBuyVolMax()
{
	m_edtBuyVolTot.ShowWindow(SW_HIDE);
	m_btnBuyVolTotApply.ShowWindow(SW_HIDE);

	GetVolAvail(FALSE);
}

void COrderTypeWnd::OnBtnBuyVolTot()
{
	m_edtBuyVolTot.ShowWindow(SW_SHOW);
	m_btnBuyVolTotApply.ShowWindow(SW_SHOW);
}

void COrderTypeWnd::OnBtnBuyVolTotApply()
{
	if (IsEquitiesMap() == FALSE)
		return;

	m_bBuyProper = FALSE;

	__int64 dAmt = 0;
	__int64 dPrc = 0;

	LONGLONG	dQty = 0;

	CString strAmt, strPrice;
	m_edtBuyVolTot.GetWindowText(strAmt);
	strAmt.Remove(',');
	dAmt = _atoi64(strAmt) * 10000;

	if (m_cOrdMinSet.m_strMarketType == SVRORD_MARKETTYPE_STOCK)
		strPrice = GetPriceVal();
	else if (m_cOrdMinSet.m_strMarketType == SVRORD_MARKETTYPE_ELW)
		strPrice = GetElwPriceVal();

	if (strPrice == "-1")
		return;

	dPrc = _atoi64(strPrice);

	if(dPrc <= 0 )
		return;

	dQty = (long)(dAmt / dPrc);
	if (m_pParent)
	{
		dQty = (long)(dAmt / (dPrc * (1 + ((CBaseFrmWnd *)m_pParent)->GetFeeRate())));
	}

	if (m_pPriceInfo && m_pPriceInfo->m_nQtyUnit != 0)
		dQty = dQty - (dQty % m_pPriceInfo->m_nQtyUnit);

	CString strVol;
	strVol.Format("%I64d", dQty);

	SetJangoVolume(strVol, "0");
}

void COrderTypeWnd::OnBtnVolClear()
{
	if (IsEquitiesMap())
	{
		return;
	}
	else
	{
		m_nVolNewClear = VOL_CLEAR;
		CString strPrice = GetDerivativesPriceVal();		
		GetParent()->SendMessage(RMSG_REQ_ALLFO_VOL, m_nVolNewClear, (LPARAM)(LPCTSTR)strPrice);
	}
}

void COrderTypeWnd::OnBtnVolCheck()
{
	if (IsEquitiesMap())
	{
		m_edtBuyVolTot.ShowWindow(SW_HIDE);
		m_btnBuyVolTotApply.ShowWindow(SW_HIDE);

		GetVolAvail(TRUE);
	}
	else
	{
		m_nVolNewClear = VOL_NEW;
		CString strPrice = GetDerivativesPriceVal();
		GetParent()->SendMessage(RMSG_REQ_ALLFO_VOL, m_nVolNewClear, (LPARAM)(LPCTSTR)strPrice);
	}

}


void COrderTypeWnd::OnBtnMarketPriceCheck()
{
	CString strPriceType =_T("시장가");
	int nPriceTypeSel = m_comboPriceType.GetCurSel();


	
	if(m_chkMarketPrice.GetCheck() )
	{
		
		for (int nIndex = 0; nIndex < _countof(PRICE_TYPE_STRING_EX); nIndex++) //>>[KSJ000000026] 신용주문추가, 주문구분추가
		{
			if(strPriceType.CompareNoCase(PRICE_TYPE_STRING_EX[nIndex]) == 0)
			{
				m_comboPriceType.SetCurSel(nIndex);				
				break;
			}
		}	
		m_editBuyPrice.EnableWindow(FALSE);
		m_editSellPrice.EnableWindow(FALSE);
		m_cmbPriceGb.EnableWindow(FALSE);
	}
	else
	{
		strPriceType = _T("지정가");
		for (int nIndex = 0; nIndex < _countof(PRICE_TYPE_STRING_EX); nIndex++) //>>[KSJ000000026] 신용주문추가, 주문구분추가
		{
			if(strPriceType.CompareNoCase(PRICE_TYPE_STRING_EX[nIndex]) == 0)
			{
				m_comboPriceType.SetCurSel(nIndex);		
				break;
			}
		}			
		m_cmbPriceGb.EnableWindow(TRUE);
		if(m_cmbPriceGb.GetCurSel() == 0)
		{
			m_editBuyPrice.EnableWindow(TRUE);
			m_editSellPrice.EnableWindow(TRUE);
		}

	}
		
	
}

void COrderTypeWnd::OnChangeDivCnt(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	m_IsChangeSet = TRUE;

	*pResult = 0;
}

void COrderTypeWnd::OnChangeDivUnit(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

	int nPos = pNMUpDown->iPos;
	//int nCnt = m_SpinDivUnit.GetPos();

	*pResult = 0;
}

void COrderTypeWnd::MoveControlOnTabChange()
{
	CRect rtTemp;

	if(m_cOrdMinSet.m_strMMType.CompareNoCase("1") == 0)//매도
		m_ctrlSellVolRateText2.GetWindowRect(rtTemp);
	else
		m_ctrlBuyVolText.GetWindowRect(rtTemp);//매수수량

	ScreenToClient(rtTemp);	

	rtTemp.left = rtTemp.right + 2;
	rtTemp.right = rtTemp.left + 20;
	m_btnVolCheck.MoveWindow(rtTemp);
	
	if (IsDerivativesMap())
	{
		if (m_cOrdMinSet.m_enOrdType == HOGADIV_ORDER)
		{
			rtTemp.left = rtTemp.right + 2;
			rtTemp.right = rtTemp.left + 20;
		}
		m_btnVolClear.MoveWindow(&rtTemp);
	}
	else
	{
		rtTemp.left  = rtTemp.right + 1;
		rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX1; 
		m_btnBuyVolMax.MoveWindow(&rtTemp);
		
		rtTemp.left  = rtTemp.right + 1;
		rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX1; 
		m_btnBuyVolTot.MoveWindow(&rtTemp);

		rtTemp.left  = rtTemp.right + 3;
		rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX4; 
		m_edtBuyVolTot.MoveWindow(&rtTemp);

		rtTemp.left  = rtTemp.right + 1;
		rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX2; 
		m_btnBuyVolTotApply.MoveWindow(&rtTemp);
	}

	//rtTemp.left = rtTemp.right + 1;
	//rtTemp.right = rtTemp.left + 20;
	//m_btnLQCheck.MoveWindow(rtTemp);

	rtTemp.left = rtTemp.right + 1;
	rtTemp.right = rtTemp.left + LEN_CTRL_WIDTHX10;
	m_stcCheckVolOutput.MoveWindow(rtTemp);

}

void COrderTypeWnd::SetJangoVolume(CString strVol, CString strBuyProperVol)//, BOOL bClear)
{
	strVol.Trim();
	long lVol = atol(strVol);
	strVol.Format("%d", lVol);

	strBuyProperVol.Trim();
	long lBuyProperVol = atol(strBuyProperVol);
	strBuyProperVol.Format("%d", lBuyProperVol);

	
	
	if(m_cOrdMinSet.m_strMMType.CompareNoCase("1") == 0)//매도비중
	{
		CString strText;
		InsertComma(strVol);
		strText = strVol + _T(" 주");
	
		m_stcCheckVolOutput.SetWindowText(strText);	
	}
	else
	{
		m_spinBuyVolume.SetFormatString(_T("%.0f"));
		if (m_bBuyProper)
		{
			m_editBuyVolume.SetWindowText(strBuyProperVol);
			m_spinBuyVolume.SetPos(lBuyProperVol);//매수수량
		}				
		else
		{
			m_editBuyVolume.SetWindowText(strVol);
			m_spinBuyVolume.SetPos(lVol);//매수수량
		}
	}
	
	DivideSet();

}

void COrderTypeWnd::SetHogaPrice(CString strPrice)
{
	double dPrice = atof(strPrice);

	if(m_cOrdMinSet.m_strMMType.CompareNoCase("1") == 0)//매도단가
		m_spinSellPrice.SetPos(dPrice);	
	else
		m_spinBuyPrice.SetPos(dPrice);					//매수수량
}

LRESULT COrderTypeWnd::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	CString strVolume;
	long lVolume = 0;
	double dRate;
	
	switch(message)
	{
	case UMSG_GET_BUY_VOLUME:
		{	
			double *pVol = (double *)lParam;
			*pVol = GetBuyVol();

			return 1L;
		}
		break;
	case UMSG_GET_SELL_VOLUME:
		{			
			double *pVol = (double *)lParam;
			if ( pVol)
				*pVol = GetSellVol();

			return 1L;
		}
		break;

	default:
		break;


	}


	return CWnd::WindowProc(message, wParam, lParam);
}

BOOL COrderTypeWnd::PreTranslateMessage(MSG* pMsg)
{
	CString strValue;
	switch (pMsg->message)
	{		
	/*
	case WM_KEYUP:
		{
			if(pMsg->hwnd)
			{	
				if(pMsg->wParam == VK_ESCAPE)
					return FALSE;

				CWnd* pWnd = CWnd::FromHandle(pMsg->hwnd);
				if(pWnd)
				{
					HWND hFocus = pWnd->GetSafeHwnd();			

					if(hFocus == m_editBuyVolume.GetSafeHwnd())
					{
						if((pMsg->wParam > 47 & pMsg->wParam < 58) || (pMsg->wParam > 95 & pMsg->wParam < 106))
						{				
							m_editBuyVolume.GetWindowText(strValue);
						}						
						m_Statistic.CalcVolume();
						return 1L;
					}
					else if(//(m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_FUT) == 0 ||
						//m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_OPT) == 0) &&
						hFocus == m_editSellVolRate.GetSafeHwnd())
					{
						if((pMsg->wParam > 47 & pMsg->wParam < 58) || (pMsg->wParam > 95 & pMsg->wParam < 106))
						{				
							m_editSellVolRate.GetWindowText(strValue);
						}						
						m_Statistic.CalcVolume();
						return 1L;

					}
				}
			}

		}
		break;
	*/

	case WM_LBUTTONDOWN:
		if (pMsg->hwnd == m_btnDivSet.GetSafeHwnd())
		{
			CRect rtBtn;
			m_btnDivSet.GetWindowRect(&rtBtn);
			//ScreenToClient(&rtBtn);
			if (rtBtn.PtInRect(pMsg->pt)) // 핸들이 같은 값으로 계속 들어오는 경우(?)가 있어서 다시 체크
			{
				OnBtnDivideSet();
			}
		}
		break;
	}

	return CWnd::PreTranslateMessage(pMsg);
}

void COrderTypeWnd::OnChangeBuyVolSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
	m_Statistic.CalcVolume();
}


void COrderTypeWnd::OnChangeSellVolSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
	m_Statistic.CalcVolume();
}


void COrderTypeWnd::OnBtnRegCondition()
{
	GetParent()->SendMessage(UMSG_REGCONDITION, 0, 0);
}

void COrderTypeWnd::SetEquitiesVolUnitInfo()
{


	if (m_pPriceInfo->m_nQtyUnit == 10)
	{
		// sell
		if (m_nSellBuy == WND_SELL)
		{
			// normal
			if (m_nNormalDiv == ORDTYPEWND_NORMAL)
			{
				// %
				if (m_rdoVolPercent.GetCheck() == BST_CHECKED)
				{
					m_editSellVolRate.SetPlaces(3, 0);
					m_editSellVolRate.SetEditRange(0, 100);

					m_spinSellVolRate.SetNoRemain(FALSE);
					m_spinSellVolRate.SetRangeAndDelta(0, 100, 5);
				}
				// 수량
				else
				{
					m_editSellVolRate.SetPlaces(9, 0);
					m_editSellVolRate.SetEditRange(0, 999999999);

					m_spinSellVolRate.SetNoRemain(TRUE);
					m_spinSellVolRate.SetRangeAndDelta(0, 999999999, 10);
				}
			}
			// div
			else
			{
				m_editSellVolRate.SetPlaces(3, 0);
				m_editSellVolRate.SetEditRange(0, 100);

				m_spinSellVolRate.SetNoRemain(FALSE);

				m_spinSellVolRate.SetRangeAndDelta(0, 100, 5);
				m_Statistic.SetVolLimit(TRUE);
			}
		}
		// buy
		else
		{
			m_spinBuyVolume.SetNoRemain(TRUE);
			m_spinBuyVolume.SetRangeAndDelta(0, 999999999, 10);
			m_Statistic.SetVolLimit(TRUE);
		}
	}
	else
	{
		// sell
		if (m_nSellBuy == WND_SELL)
		{
			// normal
			if (m_nNormalDiv == ORDTYPEWND_NORMAL)
			{
				// %
				if (m_rdoVolPercent.GetCheck() == BST_CHECKED)
				{
					m_editSellVolRate.SetPlaces(3, 0);
					m_editSellVolRate.SetEditRange(0, 100);

					m_spinSellVolRate.SetNoRemain(FALSE);
					m_spinSellVolRate.SetRangeAndDelta(0, 100, 5);
				}
				// 수량
				else
				{
					m_editSellVolRate.SetPlaces(9, 0);
					m_editSellVolRate.SetEditRange(0, 999999999);

					m_spinSellVolRate.SetNoRemain(FALSE);
					m_spinSellVolRate.SetRangeAndDelta(0, 999999999, 1);
				}
			}
			// div
			else
			{
				m_editSellVolRate.SetPlaces(3, 0);
				m_editSellVolRate.SetEditRange(0, 100);

				m_spinSellVolRate.SetNoRemain(FALSE);
				m_spinSellVolRate.SetRangeAndDelta(0, 100, 5);
				m_Statistic.SetVolLimit(FALSE);
			}
		}
		// buy
		else
		{
			m_spinBuyVolume.SetNoRemain(FALSE);
			m_spinBuyVolume.SetRangeAndDelta(0, 999999999, 1);
			m_Statistic.SetVolLimit(FALSE);
		}
	}
}

int COrderTypeWnd::GetHogaTick(int nMarketType, int nPrice, int nTick, BOOL bETF/* = FALSE*/)
{	
	CString strTick;


	int nCount = abs(nTick);
	int nSign = nTick > 0?1:-1;

	int nMultiple = 1;

	if (bETF)
	{
		nPrice = nPrice + 5 * nSign;
		if (nPrice < 5) 
			nPrice = 5;

		nPrice = nPrice - (nPrice % nMultiple);
		return nPrice;
	}

	if(nMarketType == CDRCodeTypeInfo::DRCODETYPE_KOSPI_STOCK)
	{  
		if(nSign == 1)
		{		
			for(int i = 0; i < nCount; i++)
			{
				if(nPrice<1000)		
					nMultiple = 1;
				else if(nPrice<5000)	
					nMultiple = 5;
				else if(nPrice<10000) 
					nMultiple = 10;
				else if(nPrice<50000) 
					nMultiple = 50;
				else if(nPrice<100000) 
					nMultiple = 100;
				else if(nPrice<500000) 
					nMultiple = 500;
				else				
					nMultiple = 1000;
				nPrice = nPrice + nMultiple*nSign;
			}

			if(nPrice < 5) 
				nPrice = 5;
		}
		else
		{
			for(int i = 0; i < nCount; i++)
			{
				if(nPrice<=1000)		
					nMultiple = 1;
				else if(nPrice<=5000)	
					nMultiple = 5;
				else if(nPrice<=10000) 
					nMultiple = 10;
				else if(nPrice<=50000) 
					nMultiple = 50;
				else if(nPrice<=100000) 
					nMultiple = 100;
				else if(nPrice<=500000) 
					nMultiple = 500;
				else				
					nMultiple = 1000;
				nPrice = nPrice + nMultiple*nSign;
			}

			if(nPrice <= 5) 
				nPrice = 5;

		}
	}

	else if(nMarketType == CDRCodeTypeInfo::DRCODETYPE_KOSDAQ_STOCK)  //코스닥
	{ 
		if(nSign == 1)
		{
			for(int i = 0; i < nCount; i++)
			{
				if(nPrice<1000)			nMultiple = 1;
				else if(nPrice<5000)	nMultiple = 5;
				else if(nPrice<10000)   nMultiple = 10;
				else if(nPrice<50000)   nMultiple = 50;
				else					nMultiple = 100;

				nPrice = nPrice + nMultiple*nSign;
			}
			if(nPrice < 5) nPrice = 5;
		}
		else
		{
			for(int i = 0; i < nCount; i++)
			{
				if(nPrice<=1000)			nMultiple = 1;
				else if(nPrice<=5000)	nMultiple = 5;
				else if(nPrice<=10000)   nMultiple = 10;
				else if(nPrice<=50000)   nMultiple = 50;
				else					nMultiple = 100;

				nPrice = nPrice + nMultiple*nSign;
			}
			if(nPrice <= 5) nPrice = 5;

		}

		
	}


	nPrice = nPrice - (nPrice % nMultiple);

	return nPrice;
}

void COrderTypeWnd::MoveHelpTextWnd()
{
	CRect rtBase;
	//m_ctrlWonText1.GetWindowRect(&rtBase);
	m_btnOrderReg.GetWindowRect(&rtBase);
	ScreenToClient(&rtBase);
	
	CRect rtClient;
	GetClientRect(&rtClient);

	CRect rtCtrl = rtClient;
	rtCtrl.left += 20;
	rtCtrl.top = rtBase.bottom + LEN_CTRL_VGAP5;
	rtCtrl.bottom = rtCtrl.top + 20;

	m_ctrlHelpText1.MoveWindow(&rtCtrl);
	rtCtrl.OffsetRect(0, 20);
	m_ctrlHelpText2.MoveWindow(&rtCtrl);
	rtCtrl.OffsetRect(0, 20);
	m_ctrlHelpText3.MoveWindow(&rtCtrl);
	rtCtrl.OffsetRect(0, 20);
	m_ctrlHelpText4.MoveWindow(&rtCtrl);
	rtCtrl.OffsetRect(0, 20);
	m_ctrlHelpText5.MoveWindow(&rtCtrl);
	rtCtrl.OffsetRect(0, 20);
	m_ctrlHelpText6.MoveWindow(&rtCtrl);
	rtCtrl.OffsetRect(0, 20);
	m_ctrlHelpText7.MoveWindow(&rtCtrl);
	rtCtrl.OffsetRect(0, 20);
}

void COrderTypeWnd::OnBtnSellVolPercent()
{
	SetEquitiesVolUnitInfo();
	m_ctrlSellVolRateText2.SetWindowText("(%)");	
}

void COrderTypeWnd::OnBtnSellVolDigit()
{		
	SetEquitiesVolUnitInfo();	
}

void COrderTypeWnd::OnTypeTabSelChange(int nTypeTabCurSel)
{
	if (IsEquitiesMap())
	{
		//if (m_cOrdMinSet.m_strMMType.CompareNoCase(SVRORD_MMTYPE_SELL) != 0)//매도가 아니면
		if (m_nSellBuy == WND_BUY)
			return;
	}

	CRect rtBase, rtCtrl;

	if (nTypeTabCurSel == 0) // 일반주문탭
	{
		m_rdoVolPercent.ShowWindow(SW_SHOW);
		m_rdoVolDigit.ShowWindow(SW_SHOW);

		m_rdoVolDigit.GetWindowRect(&rtBase);
	}
	else if (nTypeTabCurSel ==  1) // 호가분할 탭
	{
		m_rdoVolPercent.ShowWindow(SW_HIDE);
		m_rdoVolDigit.ShowWindow(SW_HIDE);

		m_rdoVolPercent.SetCheck(BST_CHECKED);
		m_rdoVolDigit.SetCheck(BST_UNCHECKED);

		OnBtnSellVolPercent();

		m_ctrlVolText1.GetWindowRect(&rtBase);
	}
	else
		return;

	ScreenToClient(&rtBase);

	rtCtrl = rtBase;

	//매도비중 edit
	rtCtrl.left  = rtBase.right + LEN_TEXT_TO_CTRL;
	rtCtrl.right = rtCtrl.left + LEN_CTRL_WIDTHX4 + 12;
	m_editSellVolRate.MoveWindow(rtCtrl);

	if (IsDerivativesMap())
		m_editBuyVolume.MoveWindow(rtCtrl);

	//매도비중 spin
	rtCtrl.left  = rtCtrl.right;
	rtCtrl.right = rtCtrl.left + LEN_SPIN_WIDTH;
 	m_spinSellVolRate.MoveWindow(rtCtrl);

	if (IsDerivativesMap())
		m_spinBuyVolume.MoveWindow(rtCtrl);

	rtCtrl.left  = rtCtrl.right + 1;
	rtCtrl.right = rtCtrl.left + LEN_SPIN_WIDTH;
	m_ctrlSellVolRateText2.MoveWindow(rtCtrl);
	
	if (IsDerivativesMap())
		m_ctrlBuyVolText.MoveWindow(rtCtrl);

	rtCtrl.left = rtCtrl.right + 2;
	rtCtrl.right = rtCtrl.left + 20;
	m_btnVolCheck.MoveWindow(rtCtrl);

	if (IsDerivativesMap())
	{
		if (m_cOrdMinSet.m_enOrdType == HOGADIV_ORDER)
		{
			rtCtrl.left = rtCtrl.right + 2;
			rtCtrl.right = rtCtrl.left + 20;
		}
		m_btnVolClear.MoveWindow(&rtCtrl);
	}

	rtCtrl.left = rtCtrl.right + 5;
	rtCtrl.right = rtCtrl.left + LEN_CTRL_WIDTHX8;
	m_stcCheckVolOutput.MoveWindow(rtCtrl);
}

void COrderTypeWnd::GetVolAvail(BOOL bBuyProper)
{
	
	ClearVolCheck();

	if (m_pPriceInfo == NULL)
	{
		DefMessageBox(GetSafeHwnd(), "현재가 및 호가 정보가 존재하지 않습니다.");
		return;
	}

	if (IsEquitiesMap() == FALSE)
		return;

	m_bBuyProper = bBuyProper;
	CString strPrice;
	if (m_cOrdMinSet.m_strMarketType == SVRORD_MARKETTYPE_STOCK)
		strPrice = GetPriceVal();
	else if (m_cOrdMinSet.m_strMarketType == SVRORD_MARKETTYPE_ELW)
		strPrice = GetElwPriceVal();

	if (strPrice == "-1")
		return;

	BOOL bSell;
	if (IsSellTabSelected())
		bSell = TRUE;
	else
		bSell = FALSE;

	GetParent()->SendMessage(UMSG_SETTYPE_VOLCHECK, bSell, (LPARAM)(LPCTSTR)strPrice);
	// 20120723 ssj - 서버자동주문 <<
}

BOOL COrderTypeWnd::IsNormalTabSelected()
{
	int nType = GetParent()->SendMessage(UMSG_GET_TYPE_TAB_CUR_SEL, 0, 0);
	return (nType == 0);
}

BOOL COrderTypeWnd::IsSellTabSelected()
{
	return GetParent()->SendMessage(UMSG_IS_SELL_TAB_SELECTED, 0, 0);
}


CString COrderTypeWnd::GetPriceVal()
{
	CString strPrice;

	// 신용구분
	BOOL bCreditSelected = GetParent()->SendMessage(UMSG_GET_RDO_CASH_CREDIT, 0, 0);

	if (IsNormalTabSelected()) // 일반주문탭
	{
		int nIdx = m_comboPriceType.GetCurSel();
		if (nIdx == 0) // 지정가
		{
			int nGB = m_cmbPriceGb.GetCurSel();
			if (nGB == 0) // 지정가
			{
				if (IsSellTabSelected())
				{
					m_editSellPrice.GetWindowText(strPrice);
				}
				else
				{
					m_editBuyPrice.GetWindowText(strPrice);
					strPrice.Trim();
					if (atol(strPrice) <= 0)
					{
						DefMessageBox(GetSafeHwnd(), "가격을 입력하세요.!!");
						return "-1";
					}
				}
			}
			else if (nGB == 1) // 현재가
				strPrice = m_pPriceInfo->m_strCurrent;
			else if (nGB == 2) // 매수1호가
				strPrice = m_pPriceInfo->m_strBid[0];
			else if (nGB == 3) // 매수2호가
				strPrice = m_pPriceInfo->m_strBid[1];
			else if (nGB == 4) // 매도1호가
				strPrice = m_pPriceInfo->m_strOffer[0];
			else if (nGB == 5) // 매도2호가
				strPrice = m_pPriceInfo->m_strOffer[1];
			else if (nGB == 6) // 상한가
				strPrice = m_pPriceInfo->m_strUpiLmit;
			else if (nGB == 7) // 하한가
				strPrice = m_pPriceInfo->m_strDownLimit;
		}
		else if (nIdx == 1) // 시장가
		{
			if (bCreditSelected)
			{
				DefMessageBox(GetSafeHwnd(), "가능수량조회는 지정가에서만 가능합니다.");
				return "-1";
			}
			else
			{
				if (IsSellTabSelected())
					strPrice = m_pPriceInfo->m_strDownLimit; // 매도 시장가는 하한가 
				else
					strPrice = m_pPriceInfo->m_strUpiLmit; // 매수 시장가는 상한가 
			}
		}
		else
		{
			if (bCreditSelected)
			{
				DefMessageBox(GetSafeHwnd(), "가능수량조회는 지정가에서만 가능합니다.");
				return "-1";
			}
			else
			{
				DefMessageBox(GetSafeHwnd(), "가능수량조회는 지정가, 시장가에서만 가능합니다.");
				return "-1";
			}		
		}
	}
	else // 호가분할탭
	{
		// 기준단가를 가져온다
		int nSel = m_cmbStdCost.GetCurSel();
		switch (nSel)
		{
		case 0: //매도3호가
			strPrice = m_pPriceInfo->m_strOffer[2];
			break;
		case 1: //매도2호가
			strPrice = m_pPriceInfo->m_strOffer[1];
			break;
		case 2: //매도1호가
			strPrice = m_pPriceInfo->m_strOffer[0];
			break;
		case 3: //매수1호가
			strPrice = m_pPriceInfo->m_strBid[0];
			break;
		case 4: //매수2호가
			strPrice = m_pPriceInfo->m_strBid[1];
			break;
		case 5: //매수3호가
			strPrice = m_pPriceInfo->m_strBid[2];
			break;
		default:
			strPrice = m_pPriceInfo->m_strCurrent;
		}
	}

	strPrice.Trim();
	strPrice.Remove(',');
	return strPrice;
}


void COrderTypeWnd::ApplyCreditChange(BOOL bCredit)
{
	m_edtBuyVolTot.ShowWindow(SW_HIDE);
	m_btnBuyVolTotApply.ShowWindow(SW_HIDE);

	if (bCredit)
	{
		m_btnBuyVolMax.ShowWindow(SW_HIDE); // 최 버튼
		m_btnBuyVolTot.ShowWindow(SW_HIDE); // 금 버튼
	}
	else
	{
		if (IsSellTabSelected())
		{
		}
		else
		{
			if (IsEquitiesMap() && m_nSellBuy == WND_BUY)
			{
				m_btnBuyVolMax.ShowWindow(SW_SHOW); // 최 버튼
				m_btnBuyVolTot.ShowWindow(SW_SHOW); // 금 버튼
			}
		}
	}
}

// 가능/청산 수량 클리어
void COrderTypeWnd::ClearVolCheck()
{
	if (IsEquitiesMap())
	{
		if (m_nSellBuy == WND_SELL) // 매도
		{
			m_stcCheckVolOutput.SetWindowText("");
		}
		else
		{
			m_editBuyVolume.SetWindowText("");
			m_spinBuyVolume.SetPos(0);//매수수량
		}
	}
	else
	{
		if (m_nSellBuy == WND_SELL) // 매도
		{
			m_stcCheckVolOutput.SetWindowText("");
		}
		else
		{
			m_editBuyVolume.SetWindowText("");
			m_spinBuyVolume.SetPos(0);//매수수량
		}
	}

	DivideSet();
}

CString COrderTypeWnd::GetElwPriceVal()
{
	CString strPrice;

	if (IsNormalTabSelected()) // 일반주문탭
	{
		int nGB = m_cmbPriceGb.GetCurSel();
		if (nGB == 0) // 지정가
		{
			if (IsSellTabSelected())
			{
				m_editSellPrice.GetWindowText(strPrice);
			}
			else
			{
				m_editBuyPrice.GetWindowText(strPrice);
				strPrice.Trim();
				if (atol(strPrice) <= 0)
				{
					DefMessageBox(GetSafeHwnd(), "가격을 입력하세요.!!");
					return "-1";
				}
			}
		}
		else if (nGB == 1) // 현재가
			strPrice = m_pPriceInfo->m_strCurrent;
		else if (nGB == 2) // 매수1호가
			strPrice = m_pPriceInfo->m_strBid[0];
		else if (nGB == 3) // 매수2호가
			strPrice = m_pPriceInfo->m_strBid[1];
		else if (nGB == 4) // 매도1호가
			strPrice = m_pPriceInfo->m_strOffer[0];
		else if (nGB == 5) // 매도2호가
			strPrice = m_pPriceInfo->m_strOffer[1];
		else if (nGB == 6) // 상한가
			strPrice = m_pPriceInfo->m_strUpiLmit;
		else if (nGB == 7) // 하한가
			strPrice = m_pPriceInfo->m_strDownLimit;
	}
	else // 호가분할탭
	{
		// 기준단가를 가져온다
		int nSel = m_cmbStdCost.GetCurSel();
		switch (nSel)
		{
		case 0: //매도3호가
			strPrice = m_pPriceInfo->m_strOffer[2];
			break;
		case 1: //매도2호가
			strPrice = m_pPriceInfo->m_strOffer[1];
			break;
		case 2: //매도1호가
			strPrice = m_pPriceInfo->m_strOffer[0];
			break;
		case 3: //매수1호가
			strPrice = m_pPriceInfo->m_strBid[0];
			break;
		case 4: //매수2호가
			strPrice = m_pPriceInfo->m_strBid[1];
			break;
		case 5: //매수3호가
			strPrice = m_pPriceInfo->m_strBid[2];
			break;
		default:
			strPrice = m_pPriceInfo->m_strCurrent;
		}
	}

	strPrice.Trim();
	strPrice.Remove(',');
	return strPrice;
}

CString COrderTypeWnd::GetDerivativesPriceVal()
{
	CString strPrice;

	if (m_nNormalDiv == ORDTYPEWND_NORMAL) // 일반주문탭
	{
		// 선옵
		if (m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_FUT) == 0 || m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_OPT) == 0)
		{
			//PRICE_TYPE_STRING_FUTOPT_EX[] = {_T("지정가"), _T("시장가"), _T("최유리지정가"), _T("조건부지정가"), _T("지정가[IOC]"), 
			//                                 _T("시장가[IOC]"), _T("최유리[IOC]"), _T("지정가[FOK]"), _T("시장가[FOK]"), _T("최유리[FOK]")};
			int nIdx = m_comboPriceType.GetCurSel();
			if (nIdx == 0 || nIdx == 3 || nIdx == 4 || nIdx == 7) // 지정가
			{
				if (m_nSellBuy == WND_SELL)
					m_editSellPrice.GetWindowText(strPrice);
				else
					m_editBuyPrice.GetWindowText(strPrice);
			}
			else
			{
				strPrice = "";
			}
		}

		// 주식선옵
		else
		{
			// PRICE_TYPE_STRING_SFUT[] = {_T("지정가"), _T("시장가"), _T("최유리지정가"), _T("조건부지정가"), _T("지정가[IOC]"), _T("지정가[FOK]")};
			int nIdx = m_comboPriceType.GetCurSel();
			if (nIdx == 0 || nIdx == 3 || nIdx == 4 || nIdx == 5) // 지정가
			{
				if (m_nSellBuy == WND_SELL)
					m_editSellPrice.GetWindowText(strPrice);
				else
					m_editBuyPrice.GetWindowText(strPrice);
			}
			else
			{
				strPrice = "";
			}
		}
	}
	else // 호가분할탭
	{
		// 기준단가를 가져온다
		int nSel = m_cmbStdCost.GetCurSel();
		switch (nSel)
		{
		case 0: //매도3호가
			strPrice = m_pPriceInfo->m_strOffer[2];
			break;
		case 1: //매도2호가
			strPrice = m_pPriceInfo->m_strOffer[1];
			break;
		case 2: //매도1호가
			strPrice = m_pPriceInfo->m_strOffer[0];
			break;
		case 3: //매수1호가
			strPrice = m_pPriceInfo->m_strBid[0];
			break;
		case 4: //매수2호가
			strPrice = m_pPriceInfo->m_strBid[1];
			break;
		case 5: //매수3호가
			strPrice = m_pPriceInfo->m_strBid[2];
			break;
		default:
			strPrice = m_pPriceInfo->m_strCurrent;
		}
	}

	strPrice.Trim();
	strPrice.Remove(',');
	return strPrice;
}

// 20120723 ssj - 서버자동주문 >>
void COrderTypeWnd::SetDerivativesJangoVol(LONGLONG lnNew, LONGLONG lnClear)
{
	CString strVol;
	if (m_nVolNewClear == VOL_NEW)
		strVol.Format("%I64d", lnNew);
	else
		strVol.Format("%I64d", lnClear);

	if (m_nSellBuy == WND_SELL)
	{
		if (m_nNormalDiv == ORDTYPEWND_NORMAL)
		{
		}
		else
		{
		}

	}
	else
	{
		m_spinBuyVolume.SetFormatString(_T("%.0f"));
		if (m_nNormalDiv == ORDTYPEWND_NORMAL)
		{
		}
		else
		{
		}

	}

	InsertComma(strVol);
	CString strText = strVol + _T(" 계약");
	m_stcCheckVolOutput.SetWindowText(strText);	

	DivideSet();
}
// 20120723 ssj - 서버자동주문 <<

void COrderTypeWnd::SetPriceUnit()
{
	m_editSellPrice.SetUseMinus(FALSE);
	m_editBuyPrice.SetUseMinus(FALSE);

	
	 // 주식, ELW, 주식선물	
	m_spinBuyPrice.SetDecimalPlaces(0);
	m_spinBuyPrice.SetRangeAndDelta (0, 999999999, 1);
	m_spinBuyPrice.SetFormatString(_T("%.0f"));

	m_spinSellPrice.SetDecimalPlaces(0);
	m_spinSellPrice.SetRangeAndDelta (0, 999999999, 1);
	m_spinSellPrice.SetFormatString(_T("%.0f"));

	m_editSellPrice.SetPlaces(9, 0);
	m_editBuyPrice.SetPlaces(9, 0);

	// 20131212 ssj - 주식선물스프레드 에러 수정 >>
	if (m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_SFUT) == 0)
	{
		CString strCode = ((CBaseFrmWnd *)m_pParent)->GetCurCode();
		if (strCode.GetLength() <= 0)
			return;
		
		if (strCode.GetAt(0) == '4')
		{
			m_spinSellPrice.SetRangeAndDelta(-9999999, 999999999, 1);
			m_editSellPrice.SetEditRange(-9999999, 999999999);

			m_spinBuyPrice.SetRangeAndDelta(-9999999, 999999999, 1);
			m_editBuyPrice.SetEditRange(-9999999, 999999999);

			m_editSellPrice.SetUseMinus(TRUE);
			m_editBuyPrice.SetUseMinus(TRUE);
		}
	}

}


// 20120723 ssj - 서버자동주문 >>
void COrderTypeWnd::OnBtnBidAskDlg()
{
	//CString strRet, strType, strTag, strPackData;
	//CRect rc;

	//CString strCode = ((CBaseFrmWnd *)m_pParent)->GetCurCode();
	//if (strCode.GetLength() <= 0)
	//	return;

	//int nMkt = GetMarketType(strCode);
	//if (nMkt == CDRCodeTypeInfo::DRCODETYPE_KOSPI_STOCK || nMkt == CDRCodeTypeInfo::DRCODETYPE_KOSDAQ_STOCK)
	//{
	//	if (IsETFCode(strCode))
	//	{
	//		strType = SPIN_HELPER_ETF;
	//		strTag = "A";
	//	}
	//	else
	//	{
	//		strType = SPIN_HELPER_STOCK;
	//		strTag = "1";
	//	}
	//}	
	//else
	//{
	//	return;
	//}

	//if (m_pPriceInfo == NULL)
	//{
	//	DefMessageBox(GetSafeHwnd(), "호가가 존재하지 않습니다.");
	//	return;
	//}
	
	//	double dCurPrice, dRecPrice, dMaxLimit, dMinLimit;
	//	dRecPrice = atof(m_pPriceInfo->m_strPrevClose) * 100; // 기준가
	//	dCurPrice = atof(m_pPriceInfo->m_strCurrent) * 100; // 현재가
	//	dMaxLimit = atof(m_pPriceInfo->m_strUpiLmit) * 100; // 상한가
	//	dMinLimit = atof(m_pPriceInfo->m_strDownLimit) * 100; // 하한가
	//	strPackData.Format("%1s%09.0f%09.0f%09.0f%09.0f", strTag, dRecPrice, dCurPrice, dMaxLimit, dMinLimit);
	
	

	//m_btnBidAskDlg.GetWindowRect(rc);
	//strRet = CallHelperDll(strType, rc, strPackData);
	//if (strRet.GetLength() > 0)
	//{
	//	strRet.Remove(',');
	//	double dVal;
	//	if (IsEquitiesMap())
	//	{
	//		dVal = atol(strRet);
	//	}
	//	else
	//	{
	//		dVal = atof(strRet);
	//		if (strCode.GetAt(0) == '4') // 스프레드
	//		{
	//			// 20131212 ssj - 주식선물스프레드 에러 수정 >>
	//			if (IsSFOCode(strCode) == FALSE)
	//			// 20131212 ssj - 주식선물스프레드 에러 수정 >>
	//			{
	//			dVal = dVal / 100;
	//	}	

	//	if (m_nSellBuy == WND_SELL)
	//	{
	//		m_spinSellPrice.SetPos(dVal);
	//	}
	//	else
	//	{
	//		m_spinBuyPrice.SetPos(dVal);
	//	}
	//}
}

void COrderTypeWnd::ApplyMarketChanged()
{
	if (m_cOrdMinSet.m_enOrdType == NORMAL_ORDER)
	{
		if(m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_ELW) == 0) // ELW는 호가창이 없다
			m_btnBidAskDlg.ShowWindow(SW_HIDE);
		else
			m_btnBidAskDlg.ShowWindow(SW_SHOW);
	}
}

double COrderTypeWnd::GetSellVol()
{
	if(m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_FUT) == 0 ||
		m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_OPT) == 0 ||
		m_cOrdMinSet.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_SFUT) == 0)
	{
		CString strVol;
		m_editSellVolRate.GetWindowText(strVol);
		return atof(strVol);
	}
	else
	{
		CString strRate, strRmains;
		m_editSellVolRate.GetWindowText(strRate);
		m_stcCheckVolOutput.GetWindowText(strRmains);
		strRmains.Remove(',');

		return atof(strRmains) * (atof(strRate) / 100.0);
	}
}

double COrderTypeWnd::GetBuyVol()
{
	CString strVol;
	m_editBuyVolume.GetWindowText(strVol);
	strVol.Remove(',');
	return atof(strVol);//m_spinBuyVolume.GetPos();
}

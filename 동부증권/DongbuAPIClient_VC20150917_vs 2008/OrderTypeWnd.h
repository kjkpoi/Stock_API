#pragma once

#include "OrdTypeBase.h"
#include "OrdBase.h"
#include "./control_auto/StatisticCtrl.h"

// 20120723 ssj - 서버자동주문 >>
//.#include "../../DrCommon/Dr_Control/DrBtnCtrl.h"
//.#include "../../DrCommon/Dr_Control/DrCombo.h"

//#include "../../_Include/ExComboBox.h"
//#include "../../_Include/ExDrawButton.h"
// 20120723 ssj - 서버자동주문 <<

// COrderTypeWnd

class COrderTypeWnd : public CWnd
{
	DECLARE_DYNAMIC(COrderTypeWnd)

public:
	COrderTypeWnd();
	virtual ~COrderTypeWnd();

	COrdMinSet			m_cOrdMinSet;
	COrdTypeBase		m_cOrdType;				


	COLORREF			m_clrBk;
	COLORREF			m_clrText;
	CBrush				m_brushBk;

	BOOL				m_IsChangeSet;
	BOOL				m_bBuyProper;

protected:
	CStatic				m_ctrlHelpText1;
	CStatic				m_ctrlHelpText2;
	CStatic				m_ctrlHelpText3;
	CStatic				m_ctrlHelpText4;
	CStatic				m_ctrlHelpText5;
	CStatic				m_ctrlHelpText6;
	CStatic				m_ctrlHelpText7;
	CDateTimeCtrl		m_dtmExpireDate;

	CStatic				m_ctrlExpiredateText1;	

	CStatic				m_ctrlPriceTypeText;

	CButton				m_chkMarketPrice;		//시장가 체크박스
	
	CStatic				m_ctrlVolText1;	
	CDrEdit				m_editSellVolRate;		//매도비중 edit
	CNumSpinCtrl		m_spinSellVolRate;		//매도비중 spin
	CStatic				m_ctrlSellVolRateText2;	//% 단위 static
	CStatic				m_stcCheckVolOutput;	//주식: 매도가능수량, 선옵: 매도,매수 가능수량

	CStatic				m_ctrlWonText1;	
	CDrEdit				m_editSellPrice;		//매도단가 edit	
	CNumSpinCtrl		m_spinSellPrice;		//매도단가 spin

	CComboBox			m_cmbPriceGb;			//단가구분

	CDrEdit				m_editBuyVolume;		//매수수량edit
	CNumSpinCtrl		m_spinBuyVolume;		//매수수량 spin
	CStatic				m_ctrlBuyVolText;		//% 단위 static

	CDrEdit				m_editBuyPrice;			//매수단가 edit	
	CNumSpinCtrl		m_spinBuyPrice;			//매수단가 spin

	CStatic				m_ctrlDivStdText;
	CComboBox			m_cmbDivStd;			//분할기준

	CStatic				m_ctrlDivCnt;	
	CDrEdit				m_EditDivCnt;			//분할수 Edit
	CNumSpinCtrl		m_SpinDivCnt;			//분할수 Spin

	CStatic				m_ctrlStdCost;			//기준가
	CComboBox			m_cmbStdCost;

	CStatic				m_ctrlDivWay;			//기준가방향
	CComboBox			m_cmbDivWay;

	CStatic				m_ctrlDivUnit;	
	CDrEdit				m_EditDivUnit;			//분할단위 Edit
	CNumSpinCtrl		m_SpinDivUnit;			//분할단위 Spin

	CStatisticCtrl		m_Statistic;

	CButton		m_btnDivSet;			//적용버튼
	CButton		m_btnVolCheck;			//수량 체크 조회 버튼 ("가"버튼)
	CButton		m_btnVolClear;			//청산가능수량 조회
	
	CButton		m_btnBidAskDlg;	// 호가창

	CButton		m_btnBuyVolMax;
	CButton		m_btnBuyVolTot;
	CDrEdit				m_edtBuyVolTot;
	CButton		m_btnBuyVolTotApply;

	CPriceInfo			*m_pPriceInfo;
	CWnd				*m_pParent;
	int					m_nSellBuy;
	int					m_nNormalDiv;
	int					m_nMapMode;
	int					m_nVolNewClear;
	
public:	
	CButton				m_rdoVolPercent;
	CButton				m_rdoVolDigit;

	CString  m_strCurPrice;
	CString  m_strBHoga1;
	CString  m_strBHoga2;
	CString  m_strSHoga1;
	CString  m_strSHoga2;

	// 20120723 ssj - 서버자동주문 >>
	//.CDrBtnCtrl			m_btnOrderReg;			//주문등록버튼
	CButton			m_btnOrderReg;			//주문등록버튼

	// 20120723 ssj - 서버자동주문 >>
	//.CDrCombo			m_comboPriceType;		//주문구분 1:SVRORD_PRICETYPE_TARGET 지정가
	//		   2:SVRORD_PRICETYPE_MARKET 시장가
	CComboBox			m_comboPriceType;

	CFont				m_fontDefault;

protected:
	
	void	MoveHelpTextWnd();
	

public:
	
	void    Resize();
	BOOL	Create(CWnd* pParentWnd, enORDTYPE nOrdType, COrdMinSet* clOrdMinSet, UINT nID = -1);

	void	SetInit();
	void	SetOrderTypeInit(COrdMinSet* pcOrdMinSet);
	void	SetInitWithData(COrdTypeBase* pclOrdTypeBase);	//초기화시 넘어온 데이터 셋
	void    InitCtrlStateWithFlag(COrdMinSet* pclOrdMinSet); //매수, 매도에 따라 화면 셋
	
	void	SetValuesFromClassToCtrl();	//데이터 값에 맞게 컨트롤 세팅
	void	SetValuesFromCtrlToClass(); //컨트롤로 부터 데이터 세팅

	BOOL	CheckSettingIsValid();

	void    ChangeSkinColor(long lpColor);
	COrdTypeBase	GetOrderTypeInfo();
	void			SetOrderTypeInfo(COrdTypeBase cOrderTypeInfo);
	void	InitCtrlValue();
	void	MoveControlOnTabChange();
	void	SetJangoVolume(CString strVol, CString strBuyProperVol = ""); //, BOOL bClear = FALSE);
	void	SetHogaPrice(CString strPrice);
	void	SetExpiredDateCtrl(BOOL bNormal = TRUE);
	void	OnBtnRegCondition();
	
	int		GetHogaTick(int nMarketType, int nPrice, int nTick, BOOL bETF = FALSE);
	
	void	DivideSet();

	BOOL	GetChangeState() {return m_IsChangeSet;};
	void	EnableExDateCtrl(BOOL bEnable);

	void	SetPriceInfoPtrForTypeWnd(CPriceInfo *p, int nMapMode, CWnd *pParent)
	{
		m_pPriceInfo = p;
		m_nMapMode = nMapMode;
		m_pParent = pParent;
	}

	BOOL IsDerivativesMap()
	{
		return (m_nMapMode == MODE_DERIVATIVES);
	}

	BOOL IsEquitiesMap()
	{
		return (m_nMapMode == MODE_EQUITIES);
	}

	void	OnTypeTabSelChange(int nTypeTabCurSel);
	void	GetVolAvail(BOOL bBuyVolMax);
	BOOL	IsNormalTabSelected();
	BOOL	IsSellTabSelected();
	CString GetPriceVal();
	CString GetElwPriceVal();
	CString GetDerivativesPriceVal();

	void	ApplyCreditChange(BOOL bCredit);

	void	SetInitVal(int nSellBuy, int nNormalDiv)
	{
		m_nSellBuy = nSellBuy;
		m_nNormalDiv = nNormalDiv;
	}

	void SetEquitiesVolUnitInfo();
	void SetDerivativesVolUnitInfo();

	void OnBtnDivideSet();

	void ClearVolCheck();
	void SetDerivativesJangoVol(LONGLONG lnNew, LONGLONG lnClear);

	void SetPriceUnit();

	void ApplyMarketChanged();
	
	double	GetBuyVol();
	double	GetSellVol();


protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnChangePriceType();
	afx_msg void OnChangePriceUnit();	
	afx_msg void OnChangeDivWay();
	afx_msg void OnChangeDivStd();
	afx_msg void OnChangeStdCost();	

	afx_msg void OnBtnVolCheck();	
	afx_msg void OnBtnVolClear();
	
	afx_msg void OnBtnBuyVolMax();
	afx_msg void OnBtnBuyVolTot();
	afx_msg void OnBtnBuyVolTotApply();
	
	afx_msg void OnBtnMarketPriceCheck();
	afx_msg void OnChangeDivCnt(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnChangeDivUnit(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	afx_msg void OnChangeBuyVolSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnChangeSellVolSpin(NMHDR *pNMHDR, LRESULT *pResult);
	
	afx_msg void OnBtnSellVolPercent();
	afx_msg void OnBtnSellVolDigit();
	afx_msg void OnBtnBidAskDlg();
	

	virtual BOOL PreTranslateMessage(MSG* pMsg);

	
};



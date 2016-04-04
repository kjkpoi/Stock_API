#pragma once

#include "OrdTypeBase.h"
#include "OrdBase.h"
#include "./control_auto/StatisticCtrl.h"

// 20120723 ssj - �����ڵ��ֹ� >>
//.#include "../../DrCommon/Dr_Control/DrBtnCtrl.h"
//.#include "../../DrCommon/Dr_Control/DrCombo.h"

//#include "../../_Include/ExComboBox.h"
//#include "../../_Include/ExDrawButton.h"
// 20120723 ssj - �����ڵ��ֹ� <<

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

	CButton				m_chkMarketPrice;		//���尡 üũ�ڽ�
	
	CStatic				m_ctrlVolText1;	
	CDrEdit				m_editSellVolRate;		//�ŵ����� edit
	CNumSpinCtrl		m_spinSellVolRate;		//�ŵ����� spin
	CStatic				m_ctrlSellVolRateText2;	//% ���� static
	CStatic				m_stcCheckVolOutput;	//�ֽ�: �ŵ����ɼ���, ����: �ŵ�,�ż� ���ɼ���

	CStatic				m_ctrlWonText1;	
	CDrEdit				m_editSellPrice;		//�ŵ��ܰ� edit	
	CNumSpinCtrl		m_spinSellPrice;		//�ŵ��ܰ� spin

	CComboBox			m_cmbPriceGb;			//�ܰ�����

	CDrEdit				m_editBuyVolume;		//�ż�����edit
	CNumSpinCtrl		m_spinBuyVolume;		//�ż����� spin
	CStatic				m_ctrlBuyVolText;		//% ���� static

	CDrEdit				m_editBuyPrice;			//�ż��ܰ� edit	
	CNumSpinCtrl		m_spinBuyPrice;			//�ż��ܰ� spin

	CStatic				m_ctrlDivStdText;
	CComboBox			m_cmbDivStd;			//���ұ���

	CStatic				m_ctrlDivCnt;	
	CDrEdit				m_EditDivCnt;			//���Ҽ� Edit
	CNumSpinCtrl		m_SpinDivCnt;			//���Ҽ� Spin

	CStatic				m_ctrlStdCost;			//���ذ�
	CComboBox			m_cmbStdCost;

	CStatic				m_ctrlDivWay;			//���ذ�����
	CComboBox			m_cmbDivWay;

	CStatic				m_ctrlDivUnit;	
	CDrEdit				m_EditDivUnit;			//���Ҵ��� Edit
	CNumSpinCtrl		m_SpinDivUnit;			//���Ҵ��� Spin

	CStatisticCtrl		m_Statistic;

	CButton		m_btnDivSet;			//�����ư
	CButton		m_btnVolCheck;			//���� üũ ��ȸ ��ư ("��"��ư)
	CButton		m_btnVolClear;			//û�갡�ɼ��� ��ȸ
	
	CButton		m_btnBidAskDlg;	// ȣ��â

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

	// 20120723 ssj - �����ڵ��ֹ� >>
	//.CDrBtnCtrl			m_btnOrderReg;			//�ֹ���Ϲ�ư
	CButton			m_btnOrderReg;			//�ֹ���Ϲ�ư

	// 20120723 ssj - �����ڵ��ֹ� >>
	//.CDrCombo			m_comboPriceType;		//�ֹ����� 1:SVRORD_PRICETYPE_TARGET ������
	//		   2:SVRORD_PRICETYPE_MARKET ���尡
	CComboBox			m_comboPriceType;

	CFont				m_fontDefault;

protected:
	
	void	MoveHelpTextWnd();
	

public:
	
	void    Resize();
	BOOL	Create(CWnd* pParentWnd, enORDTYPE nOrdType, COrdMinSet* clOrdMinSet, UINT nID = -1);

	void	SetInit();
	void	SetOrderTypeInit(COrdMinSet* pcOrdMinSet);
	void	SetInitWithData(COrdTypeBase* pclOrdTypeBase);	//�ʱ�ȭ�� �Ѿ�� ������ ��
	void    InitCtrlStateWithFlag(COrdMinSet* pclOrdMinSet); //�ż�, �ŵ��� ���� ȭ�� ��
	
	void	SetValuesFromClassToCtrl();	//������ ���� �°� ��Ʈ�� ����
	void	SetValuesFromCtrlToClass(); //��Ʈ�ѷ� ���� ������ ����

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



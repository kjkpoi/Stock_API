#if !defined(AFX_MAPLOADCTRL_H__C21F6089_E2DD_44A2_882D_F258DBF11103__INCLUDED_)
#define AFX_MAPLOADCTRL_H__C21F6089_E2DD_44A2_882D_F258DBF11103__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MapLoadCtrl.h : header file



#import "msxml3.dll"
using namespace MSXML2;

#include <afxtempl.h>   //#<= CList
//#include "../DefineFiles/server_typedef.h"

// 20120723 ssj - �����ڵ��ֹ� >>
//.#include "../../DrCommon/Dr_Control/DrBtnCtrl.h"
//.#include "../../DrCommon/Dr_Control/DrCombo.h"

//#include "../../../_Include/ExComboBox.h"
//#include "../../../_Include/ExDrawButton.h"
//#include "../../../_Include/ExCodeInput.h"
//#include "../../../_Include/ExStatic.h"
#include "../control_auto/DrEdit.h"
// 20120723 ssj - �����ڵ��ֹ� <<

#include "TEditCtrlWnd.h"
#include "../DataParser.h"

class CCtrlInfo
{
public:
	CString		m_strMapType;
	CString		m_strID;
	CString		m_strCtrlType;
	CString		m_strExtraInfo;
	UINT		m_nResourceID;
	CWnd		*m_pWnd;

	CCtrlInfo() { m_pWnd = NULL; }
};

class CComboBoxExtraInfo
{
public:
	CString		m_strMapType; // -101, -102....
	
	UINT		m_unResourceID;

	CString		m_strComboItem;
	CString		m_strComboItemExtra;

	CString		m_strComboIndex;
	CString		m_strComboIndexExtra;
};

/////////////////////////////////////////////////////////////////////////////
// CMapLoadCtrl window
typedef struct tagControlInfo
{
	int nResourceID;
	CString	strControlType;
} ControlInfo;

class CBaseFrmWnd;
class CMapLoadCtrl : public CStatic
{
	// Construction
public:
	CMapLoadCtrl();
	virtual ~CMapLoadCtrl();
	
public:
	int m_nOneLineHeight;								//# Map One Line Height 
	CString					m_strAfterMapTag;
	int m_TopExp; //���� 
	CString m_strAppPath;

	int		m_nResourceJCode;
	//int		m_nResourceUpCode;
	//int		m_nResourceFCode;
	//int		m_nResourceOCode;

	CRect   m_rtJCode;
	//CRect   m_rtUpCode;
	//CRect   m_rtFCode;
	//CRect   m_rtOCode;

	CWnd*	m_pwndMsgTarget;

	// 20120723 ssj - �����ڵ��ֹ� >>
	//CExCodeInput	m_ctlStkCodeInput;
	//CExCodeInput	m_ctlIdxCodeInput;
	//CExCodeInput	m_ctlFutCodeInput;
	//CExCodeInput	m_ctlOptCodeInput;


	CEdit			m_ctlStkCodeInput ; //eunsook

	CStatic			m_stcStcDummy;
	//CStatic			m_stcIdxDummy;
	//CStatic			m_stcFutDummy;
	//CStatic			m_stcOptDummy;

	CStatic		*m_pStcStkCodeName;
	//CStatic		*m_pStcIdxCodeName;
	//CStatic		*m_pStcFutCodeName;
	//CStatic		*m_pStcOptCodeName;

	BOOL			m_bAddSysCtrl;

	CStatic			m_stcUnitTitle;
	CButton			m_btnPercent;
	CButton			m_btnWon;
	CButton			m_btnTick;
	CStatic			m_stcBasePriceTitle;
	CButton			m_btnMatchPrice;
	CButton			m_btnUserPrice;
	CDrEdit			m_edtUserPrice;
	CStatic			m_stcSuffix;

	CStatic			*m_pStaticLossTitle;
	CStatic			*m_pStaticProfitTile;

	int				m_nCondType;
	
	CMap<CString, LPCTSTR, CCtrlGroup *, CCtrlGroup *>	*m_pMapCtrlGroup;
	

private:
	CBaseFrmWnd* m_pBase;
	int			 m_nIndexChk;

	BOOL	m_bChkMode;
	CWnd*	m_pwndMain;
	BOOL m_bIndustry;
  
	//## Condition Map Values ##
	CString				m_strAfterMapFileName;
	XMLTreeInfo			m_stNowXMLInfo;		
	CList <ControlInfo, ControlInfo&>		m_listControlInfo;

	//## System ##
	CFont			m_fontDefault, m_fontBold;
	CBrush			m_brushDefault;
	COLORREF		m_clrSkin;	

	//## Map Control ##
	CStatic*		m_pStatic;	//# STATIC ��Ʈ��
	CTEditCtrlWnd*	m_pEdit;		//# EDIT ��Ʈ��
//	CComboBox*		m_pComboBox; //# COMBOBOX ��Ʈ��
//	CDrEdit*		m_pEdit;	
	
	// 20120723 ssj - �����ڵ��ֹ� >>
	//.CDrCombo*		m_pComboBox;
	CComboBox*			m_pComboBox;
	CButton				*m_pRadioBtn;	// ���� ��ư

	int				m_nMultiLineCount;
	// 20120723 ssj - �����ڵ��ֹ� <<

	CDateTimeCtrl*	m_pDateTime;

	//>>[0000260] �ս����ѷ�, ��ǥ���ͷ� ���ͷ��� �ڵ����� ���� SJ_KIM(20110720)
	CTEditCtrlWnd	m_editEarningRate;		//��ǥ���ͷ�
	CTEditCtrlWnd	m_editpreventLossRate; 

	// 20120723 ssj - �����ڵ��ֹ� >>
	/*
	CDrBtnCtrl		m_btnEarningRate;		//�ս����ѷ�
	CDrBtnCtrl		m_btnpreventLossRate;
	*/
	//CExDrawButton		m_btnEarningRate;		//�ս����ѷ�
	//CExDrawButton		m_btnpreventLossRate;

	CButton		m_btnEarningRate;		//�ս����ѷ�
	CButton		m_btnpreventLossRate;
	// 20120723 ssj - �����ڵ��ֹ� <<

	int				m_nActivationRate;	
	int				m_nIDEarningRate;		//���ͷ� Edit ���ҽ� ID
	int				m_nIDPreventLossRate;	//���ͷ� Edit ���ҽ� ID
	//<<[0000260] �ս����ѷ�, ��ǥ���ͷ� ���ͷ��� �ڵ����� ���� SJ_KIM(20110720)

	CButton*		m_pBtnChk;		//��ư��Ʈ��
	//int				m_nIndexChk;	//üũ�ڽ� �ε���
	
	//## system Control ##
	CButton*		m_pNotCheckBtn;
	CButton*		m_pGubunCheckBtn;
	CStatic*		m_pConditionTitleStatic;
	
	// 20120723 ssj - �����ڵ��ֹ� >>
	/*
	CDrBtnCtrl*		m_pUpdateBtn;
	CDrBtnCtrl*		m_pOKBtn;
	CDrBtnCtrl*		m_pBaseBtn;
	*/
	CButton*		m_pUpdateBtn;
	CButton*		m_pOKBtn;
	CButton*		m_pBaseBtn;

	CArray<CStatic *, CStatic *>	m_arStatics;
	CArray<CTEditCtrlWnd *, CTEditCtrlWnd *> m_arEdits;

	CComboBox		*m_pCmbSync1;
	CComboBox		*m_pCmbSync2;
	CTEditCtrlWnd	*m_pEditSync2;
	// 20120723 ssj - �����ڵ��ֹ� <<

	int				m_nAfterMapTagPos;
	CStringArray	m_saDelCtrlData;


	int				m_nLastResourceID;
 	CMapStringToPtr	m_mapResourceID;	//���ҽ� ����ID
 	CStringArray	m_sarrCtrlType;


	//## Map Loader Values ##
	// 20130213 ssj - �ε� ������� ���� >>
	//MSXML2::IXMLDOMDocumentPtr	m_domConditionMap;
	// 20130213 ssj - �ε� ������� ���� <<

	CStringArray m_saName_Kospi, m_saCode_Kospi;
	CStringArray m_saName_Kosdaq, m_saCode_Kosdaq;

	CMapStringToPtr	m_mapTagID;

	BOOL m_bCmbInit;
	int		m_nLastTopLine;

	// 20120723 ssj - �����ڵ��ֹ� >>
	CArray<CComboBoxExtraInfo *, CComboBoxExtraInfo *>	m_arrCmbExtraInfo;
	CString		m_strMarket;
	int			m_nMapMode;
	CMapStringToPtr		m_mapAllCtrlList; // MAP_TYPE(-101, -102...)�� Ű������ �ϴ� ��Ʈ�Ѹ���Ʈ map�� map
	// 20120723 ssj - �����ڵ��ֹ� <<

public:
	CString GetAppFileRoot();
	
	BOOL Create(CWnd* pParentWnd, UINT nID);
	BOOL SetMapLoadCtrlInit(BOOL bIndustry);
	
	BOOL GetLoad_MarketInfo();

	void CreateUpdateBtn();
	void DestroyUpdateBtn();
	BOOL CheckUpdataBtnDrawState();
	
	void CreateOKBtn();
	void DestroyOKBtn();
	BOOL CheckOKBtnDrawState();
	
	void CreateBaseBtn();
	void DestroyBaseBtn();
	BOOL CheckBaseBtnDrawState();
	
	void CreateConditionTitleStatic();
	void DestroyConditionTitleStatic();
	void SetConditionTitleText(CString strConditionTitle);
	BOOL CheckConditionTitleStaticDrawState();
	void DestroyChkbtnCtrl();
	
	void CreateNotCheckBtn(int nNotUser);
	void DestroyNotCheckBtn();
	BOOL CheckNotCheckBtnDrawState();
	void SetNotCheckValues(int nState);
	BOOL GetNotCheckValues();

	void CreateGubunCheckBtn(int nGubun, BOOL bEnable = TRUE);
	void DestroyGubunCheckBtn();
	BOOL CheckGubunCheckBtnDrawState();
	void SetGubunCheckValues(int nState);
	BOOL GetGubunCheckValues();
	BOOL CheckCondiGubunState(CString strTagID);
		
	void DestoryAllCtrl();
	
	//## Real Condition Map Drew ##
	// 20130213 ssj - �ε� ������� ���� >>
	/*
	BOOL SetLoadTagIDToXMLFile(CString strTagID);	//#<= Not User
	BOOL SetLoadXMLFile(CString strFileName);
	*/
	// 20130213 ssj - �ε� ������� ���� <<
	
	BOOL SetDrewConditionMap(XMLTreeInfo *pstXMLTreeInfo, BOOL bModifyBtnView = TRUE);
	void SetValueToControl(CString strMapType, User_Define stUserDefine);
	BOOL GetCheckIsNotEmpty(CString strMapType);
	void ChangeCmbMessage(int nIndex, CString strMapType, int nID);

	
	//## Data ##
	BOOL GetMapValuesToStruct(CString strTagID,
		User_Define &stResultUserDefine, 
		CString &strResultComposition,
		BOOL &bHaveTerm);
	

	void SetDefultToMapValues(XMLTreeInfo *pstXMLTreeInfo, BOOL bOtherBtnSet = TRUE);

	BOOL GetChartDefultData(CString strConditionName, CStringArray &saDefultData);
	void SetChartDefultToMapValues(CString strTagID, CStringArray* psaDefultData);
	
	BOOL GetUserPattenData(CString strName, CStringArray &saUserPattenInfo);
	void SetUserPattenDefultToMapValues(CString strTagID, CStringArray* psaDefultData);

	
	void SetStructToMapValues(CString strTagID, User_Define* stUserDefine);
	
	BOOL CheckConditionMapDrewState();

	void SetStructDataClear(User_Define &stUserDefine);
	
	void PlatFormCheckBtnExNot();
	void EuBtnUpdate();
	void EuBtnBase();
	CWnd* GetNotChkBtnWnd() {return  m_pNotCheckBtn;};
	CWnd* GetBtnWnd() {return m_pUpdateBtn;};
	CWnd* GetBaseBtnWnd() {return m_pBaseBtn;};
	void ChangeSkinColor(COLORREF clrBk);
	int  GetConditionMapCount();
	void SetCheckMode(BOOL bChkMode = FALSE) {m_bChkMode = bChkMode;};
	void AddTagIDForMapType(CString strMapType = "", CString strTagID = "", int nChkBtnID = -1);
	void SetInitChkCtrl();
	void AddCtrlIDForMapType(CString strMapType, int nCmbID);
	void AddLinkEventCtrlIDForMapType(CString strMapType, int nLinkCtrlID, int nPoint);

	//[0000260] �ս����ѷ�, ��ǥ���ͷ� ���ͷ��� �ڵ����� ���� SJ_KIM(20110720)
	void InitActivationRate() {m_nActivationRate = -1;};	
	
	// 20130213 ssj - �ε� ������� ���� >>
	void SetXmlTreeInfo(CMap<CString, LPCTSTR, CCtrlGroup *, CCtrlGroup *> * pMapCtrlGroup)
	{
		m_pMapCtrlGroup = pMapCtrlGroup;
	}
	// 20130213 ssj - �ε� ������� ���� <<

private:
	
	void DestroyConditionMap();
	
	//## Values Search ##
	CString GetTagToNodeData(CString strTagID, CString strNode);
	CString GetTagToControlNodeValues(CString strTagID, CString strNode, 
		int nNodeIndex);

	void OnSize_ConditionTitleStatic();
	
	// Overrides
	// ClassWizard generated virtual function overrides

	//{{AFX_VIRTUAL(CMapLoadCtrl)
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL
	
	// Generated message map functions
protected:
	//{{AFX_MSG(CMapLoadCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	
	afx_msg void OnBtnUpdate();
	afx_msg void OnBtnOK();
	afx_msg void OnBtnBase();
	afx_msg void OnBtnNotCheck();
	afx_msg void OnBtnGubunCheck();
	afx_msg void OnChkMapCtrl(UINT nID);
	afx_msg void OnCmbMapCtrl(UINT nID);
	//[0000260] �ս����ѷ�, ��ǥ���ͷ� ���ͷ��� �ڵ����� ���� SJ_KIM(20110720)
	afx_msg void OnBtnEarningRate();
	afx_msg void OnBtnPreventLossRate();	
	
	// 20120723 ssj - �����ڵ��ֹ� >>
	afx_msg void OnBtnPercent();
	afx_msg void OnBtnWon();
	afx_msg void OnBtnTick();
	afx_msg void OnBtnMatchPrice();
	afx_msg void OnBtnBasePrice();
	afx_msg LRESULT OnEventCodeInput(WPARAM wParam, LPARAM lParam);
	// 20120723 ssj - �����ڵ��ֹ� <<

	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

public:
	// 20120723 ssj - �����ڵ��ֹ� >>
	void		MoveCodeInputCtrl();

	int			GetSelEvalUnit();
	int			GetBasePriceType();
	CString		GetBasePrice();

	void		ChangeMarketTo(CString strMMType);
	// 20120723 ssj - �����ڵ��ֹ� >>
	void SetMapMode(int nMapMode, int nCondType)
	{
		m_nMapMode = nMapMode;
		m_nCondType = nCondType;
		if (IsEquitiesMap())
			m_strMarket = SVRORD_MARKETTYPE_STOCK;
		else
			m_strMarket = SVRORD_MARKETTYPE_FUT;
	}
	void		AdjustCtrlToFO(BOOL bFutOptOnly = TRUE);
	// 20120723 ssj - �����ڵ��ֹ� <<

	// 20120723 ssj - �����ڵ��ֹ� <<

protected:
	// 20120723 ssj - �����ڵ��ֹ� >>
	CString		ConvertPercentWon(CString strMapType);
	void		SetCalcRate(BOOL bLoss);
	CString		GetCurSelCode();
	CString		GetMatchPrice(CString strCode);
	int			GetPositions(CString strCode);
	void		ChangePcntWonTitleTo(CString str, BOOL bChangeEdit);
	CString		GetComboIndexByMarket(UINT nResourceID);
	BOOL		HasExtraInfo(UINT nResourceID);
	void		AddToAllCtrlList(CString strMapType, CString strID, CString strCtrlType, UINT nResourceID, CWnd *pWndCtrl, CString strExtra);
	void		RemoveAllCtrlList();
	//void		ShowCtrl(int nCmdShow, CString strMapType, CExCodeInput *pExCodeInput);
	//void		OffsetCtrl(CString strMapType, int dx, int dy, CExCodeInput *pExCodeInput);

	BOOL IsDerivativesMap()
	{
		return (m_nMapMode == MODE_DERIVATIVES);
	}

	BOOL IsEquitiesMap()
	{
		return (m_nMapMode == MODE_EQUITIES);
	}
	// 20120723 ssj - �����ڵ��ֹ� <<
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPLOADCTRL_H__C21F6089_E2DD_44A2_882D_F258DBF11103__INCLUDED_)

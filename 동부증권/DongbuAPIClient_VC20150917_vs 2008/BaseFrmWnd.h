#pragma once


#include "OrdCondWnd.h"
#include "OrderTypeWnd.h"
#include "OrdBase.h"
#include "OrdCondBase.h"

#include "afxwin.h"

class CTrInfo
{
public:

	int			m_nDataSize;
	CString		m_strTR;
	BYTE *		m_pData;

public:
	CTrInfo()
	{
		m_pData = NULL;
	}

	~CTrInfo()
	{
		if(m_pData)
			delete [] m_pData;
	}
};
typedef CList < CTrInfo *, CTrInfo *> CTrInfoList;



// CBaseFrmWnd 프레임입니다.


class CBaseFrmWnd : public CDialog
{	
	DECLARE_DYNCREATE(CBaseFrmWnd)

public:
	CBaseFrmWnd();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CBaseFrmWnd();
	
	COrdMinSet		m_clOrdMinSet;
	COLORREF		m_clrBk;
	COLORREF		m_clrText;
	CBrush			m_brushBk;
	int				m_nElementIndex;
	int				m_nChkCtrlID;	
	int				m_nCmbCtrlID;
	int				m_nScreenWidth;

private:
	CString			m_strJobFlag;
	BOOL			m_bConTabInit;

	CString			m_strWaitingTr;
	CString			m_strPrice;			//단가
	

	CStatic			m_ctrlItemCodeText;
	
public:
	
	CEdit			m_ctlCodeInput;
	
	
	BOOL			m_bCreditAcnt; // 신용계좌여부
	

	BOOL			m_bUseCredit;			//신용주문 사용여부
	COrdBase		m_clOrdBase;			//자동주문 기본 Class	

	CFont			m_fontDefault;

	CStatic			m_stcCashTitle;
	CButton			m_radioCash;			//현금 라디오 버튼
	CButton			m_radioCredit;			//신용 라디오 버튼	
	CComboBox		m_cmbCreditType;		//신용타입
	
	CStatic			m_ctrlExpiredate;		//유효기간 Static
	CStatic			m_ctrlPriceType;		//주문구분 Static
	CStatic			m_ctrlVolume;			//수량 Static
	CStatic			m_ctrlPrice;			//단가 Static		
	
	CStatic			m_stcAutoTitle;
	CButton			m_radioSimiAuto;		//반자동 주문 선택 radio
	CButton			m_radioAuto;			//자동 주문 선택 radio

	
	CTabCtrl		m_tabOrderCond;			//주문 조건 탭
	CTabCtrl		m_tabOrderType;			//주문 분류 탭

	CButton			m_btnOrderReg;			//주문등록버튼
	CButton			m_btnInit;			   // 초기화 버튼
	

	CRect			m_rtLeftTopWnd;
	CRect			m_rtLeftBtmWnd;
	CRect			m_rtRightWnd;

	CPtrArray		m_ptrarrCondWnd;	//주문탭 윈도우 PtrArr
	CDateTimeCtrl   m_ExpireDateCtrl;


	COrderTypeWnd  m_OrderTypeWndNormal;
	COrderTypeWnd  m_OrderTypeWndHogaDiv;

	BOOL	Receive_REG(LPTSTR pData, DWORD dwDataLen);

	void	SetFlagCredit(int nFlag);
	void	SetHogaPrice(CString strPrice);
	int		GetAutoFlag();
	void	SetAutoFlag(int nFlag);
	void	GetOrdBaseInfo();
	BOOL	CheckPacket(TR_ORDER_REGIN* pTrInput);


	BOOL	SendTrFromMain(CString strTrCode, CString szData,long nSize, BOOL bFirstSend = FALSE);

	void	ByteOrderRevDouble(LPSTR pDouble);

	HRESULT ReceiveFromMain(long dwKey, LPCSTR szTR, LPCSTR szMsgCode, LPCSTR szMessage, LPVOID	aTRData, long dwTRDateLen);

	void SetXmlTreeInfo(CMapStringToPtr	*p, CMap<CString, LPCTSTR, CCtrlGroup *, CCtrlGroup *> * pMapCtrlGroup)
	{
		m_pMapXmlTreeInfo = p;
		m_pMapCtrlGroup = pMapCtrlGroup;
	}


public:
	CString	m_strAppPath;
	long	m_lCurPrice;
	long	m_lHogaUnit;
	int		m_nVolCheck;	
	BOOL	m_bEnableReg;

public:
	void SetInit();
	void Resize();
	void ResizeTopRect(CRect rtTop);
	void ChangeSkinColor(long lpColor);

	void SetVolTypeCheck(int nType) {m_nVolCheck = nType;};
	

//플랫폼 인터페이스 연결
public:
	BOOL	m_bParentInitialized;
	HWND	m_hwndJCode;
	HWND	m_hwndJName;
	HWND	m_hwndJMarket;	


	HWND	m_hwndTab;


	void	SetLinkPlatformCtrl();
	void	ReSizePlatformCtrl();
	void	SetInitState(BOOL bInitState) {m_bParentInitialized = bInitState;};

	void	MakePacketForSendTr(CString strTrID, CString strOther = "", CString strOther2 = "");

	COrdTypeBase GetOrderTypeInfo();
	COrdCondBase GetAllConditionInfo(BOOL& bValid, CString &strErrorMsg);

	void	SetOrdInfo(TR_ORDER_REGIN* pstOrdRegIn);
	void    SetOrdBaseInfo();
	void	SetOrderTypeInfo(COrdTypeBase clOrdType);
	void	SetOrderConditionInfo(COrdCondBase clOrdCond);
	
	void	InitializeOrdInfo(int nSellType, int nCondType, CString strCode);
	
	void	InitializeOrdTypeInfo(BOOL bTabSelChange = TRUE);
	
	enORDTYPE GetCurOrderType() {return m_clOrdMinSet.m_enOrdType;};						//현재 주문타입 얻어오기


	void	SetBaseSettingInfo(int nOrderSet);	//화면 기본 정보 세팅(주식/선물/옵션, 매수/매도 화면 여부)
	void	SetCtrlShowStatus();				//화면에 따른 컨트롤 표시
	
	BOOL	CheckWatching(CString strCode, CString strSellBuy, CString strCredit, CString strLoanDate);
	BOOL	IsMP(CString strCode, CString strMMType, CString strCredit, CString strLoanDate);


//Library
private:


public:
	
	CMapStringToPtr		*m_pMapXmlTreeInfo;	
	CMap<CString, LPCTSTR, CCtrlGroup *, CCtrlGroup *>	*m_pMapCtrlGroup;


	void    ChangeTabWithIndex(int nIndex);	
	void    ChangeCondTabWithIndex(int nIndex = -1);
	void	InitOrdCondSet();
	void	ChangeCondTabMessage(int nIndex);
	void	ChangeTypeTabMessage(int nIndex);
	


	void	OnBtnRegCondition();
	void	OnBtnShowOrderlist();
	void	UpdateMap();
	void	SetRegBtnText(CString strMMType, CString strJobFlag, TR_ORDER_REGIN* pstOrdRegIn = NULL);
	

	void	TRSetOrderType(TR_ORDER_REGIN* stOrdRegIn,  COrdTypeBase* cOrdType);
	void	TRSetOrderCond(TR_ORDER_REGIN* pstOrdRegIn, COrdCondBase* cOrdCond);
	void	TRSetOrderBase(TR_ORDER_REGIN* pstOrdRegIn, COrdBase* cOrdType);
	CString GetElement();
	void	ResetElement();
	int		GetChkCtrlID();
	void	ResetChkCtrlID();
	int		GetChkCtrlIDAndPlusCnt();
	int		GetCmbCtrlID();
	void	ResetCmbCtrlID();
	int		GetCmbCtrlIDAndPlusCnt();
	void	SetCreditSet(BOOL bCredit);
	void	EnableRegBtn(BOOL bEnable);

	StOrdKey m_stCurRegItem; //[KSJ000000024]주문 감시 여부 선택
	void Init_ActivationRate();//[0000260] 손실제한률, 목표이익률 수익률이 자동으로 셋팅 SJ_KIM(20110720)
   
protected:
	DECLARE_MESSAGE_MAP()

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()


public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDestroy();
	afx_msg void OnChangeGroupTab(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeCondGroupTab(NMHDR* pNMHDR, LRESULT* pResult);	
	afx_msg void OnChangeCreditType();	
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

	afx_msg void OnBtnRadioCash();
	afx_msg void OnBtnRadioCredit();
	afx_msg void OnBtnRadioAuto();
	afx_msg void OnBtnRadioSemiAuto();		
	afx_msg void OnBtnInit();	

	afx_msg LRESULT OnEventCodeInput(WPARAM wParam, LPARAM lParam);
	afx_msg void OnBnClickedBtnInit();


public:

	CString			m_strCurrentCode;

	CPriceInfo		*m_pPriceInfo;

	
	CString			m_strID;
	BOOL			m_bCreateDone;

	int				m_nSellBuy;
	int				m_nMapMode;
	CWnd			*m_pParent;

	BOOL			m_bBaseRequestState;
	CTrInfoList		m_BaseTrInfoList;
	
	CRect			m_rtCode;

	BOOL			m_bInit;
	
public:
	
	enum { IDD = IDD_DLG_AUTO_BASE_FRM };
	
	CString GetCurCode();
	CString GetCurCodeName();
	
	void	SetPriceInfoPtr(/*CPriceInfo *p, */int nSellBuy, int nMapMode, CWnd *pParent)
	{
		m_nSellBuy = nSellBuy;
		m_nMapMode = nMapMode;
		m_pParent = pParent;
	}
	

	void	EnableCreditCtrl(BOOL bEnable);
	void	SetCode(CString strCode);
	void	AdjustCreditCtrl(int nCredit, CString strLoanDate);
	CString	GetMatchPrice(CString strCode, int nMPFlag);
	int		GetPositions(CString strCode);
	
	double	GetFeeRate();
	void	ProcessXP1(CString strCode) ;
	
protected:
	
	
	void	ShowLoanDateCtrl();

	CString	GetCreditCmbValue(CString strMMType);
	void	SetValueToCreditCmb(int nVal);
	
	BOOL	IsCreditDateValid();
	
	void	ReqCheckVolAvail(BOOL bSell, CString strPrice);
	void	RecvCheckVolAvail(char *p, int n, BOOL bELW);
	
	void	ReqCheckVolAvailCredit(CString strAccNum, CString strAccPass, CString strItemCode, BOOL bSell,CString strPrice);
	void	RecvCheckVolAvailCredit(char *p, int n, CString strTr);

	BOOL	IsSellTabSelected();
	

	void	ReqDepositInfo(CString strCode);
	void	RecvDepositInfo(char *p, int n);

	
	HRESULT		ReceiveData(long dwKey, LPCSTR szTR, LPCSTR szMsgCode, LPCSTR szMessage, LPVOID	aTRData, long dwTRDateLen);	
	BOOL		BaseSendTr(CString strTrCode, CString szData, long nSize, BOOL bFirstSend = FALSE);	
	void		ReqPriceInfo(BOOL bElw, CString strCode);
	void		RecvPriceInfo(char *p, int n, BOOL bElw);
	void		SetCurPriceInfo(DrdsData* pDrdsData);
	void		SetHogaPriceInfo(DrdsData* pDrdsData);

	void		ReqQtyUnitInfo(CString strCode);
	void		RecvQtyUnitInfo(char *p, int n);

	void		ApplyVolUnitInfo();
	void		InitAllCond(BOOL bTabSelChange = TRUE);
	void		InitCreditCtrl();
	

public:
	
	virtual BOOL Create(UINT nID,CWnd* pParentWnd);
	virtual void OnOK() { }
	virtual void OnCancel() { }
	

protected:
	
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	

public:
	
	//afx_msg	LRESULT OnBaseDrdsData(UINT wParam, LPARAM lParam);
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
};



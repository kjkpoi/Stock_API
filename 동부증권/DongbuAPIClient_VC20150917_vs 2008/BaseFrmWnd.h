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



// CBaseFrmWnd �������Դϴ�.


class CBaseFrmWnd : public CDialog
{	
	DECLARE_DYNCREATE(CBaseFrmWnd)

public:
	CBaseFrmWnd();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
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
	CString			m_strPrice;			//�ܰ�
	

	CStatic			m_ctrlItemCodeText;
	
public:
	
	CEdit			m_ctlCodeInput;
	
	
	BOOL			m_bCreditAcnt; // �ſ���¿���
	

	BOOL			m_bUseCredit;			//�ſ��ֹ� ��뿩��
	COrdBase		m_clOrdBase;			//�ڵ��ֹ� �⺻ Class	

	CFont			m_fontDefault;

	CStatic			m_stcCashTitle;
	CButton			m_radioCash;			//���� ���� ��ư
	CButton			m_radioCredit;			//�ſ� ���� ��ư	
	CComboBox		m_cmbCreditType;		//�ſ�Ÿ��
	
	CStatic			m_ctrlExpiredate;		//��ȿ�Ⱓ Static
	CStatic			m_ctrlPriceType;		//�ֹ����� Static
	CStatic			m_ctrlVolume;			//���� Static
	CStatic			m_ctrlPrice;			//�ܰ� Static		
	
	CStatic			m_stcAutoTitle;
	CButton			m_radioSimiAuto;		//���ڵ� �ֹ� ���� radio
	CButton			m_radioAuto;			//�ڵ� �ֹ� ���� radio

	
	CTabCtrl		m_tabOrderCond;			//�ֹ� ���� ��
	CTabCtrl		m_tabOrderType;			//�ֹ� �з� ��

	CButton			m_btnOrderReg;			//�ֹ���Ϲ�ư
	CButton			m_btnInit;			   // �ʱ�ȭ ��ư
	

	CRect			m_rtLeftTopWnd;
	CRect			m_rtLeftBtmWnd;
	CRect			m_rtRightWnd;

	CPtrArray		m_ptrarrCondWnd;	//�ֹ��� ������ PtrArr
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
	

//�÷��� �������̽� ����
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
	
	enORDTYPE GetCurOrderType() {return m_clOrdMinSet.m_enOrdType;};						//���� �ֹ�Ÿ�� ������


	void	SetBaseSettingInfo(int nOrderSet);	//ȭ�� �⺻ ���� ����(�ֽ�/����/�ɼ�, �ż�/�ŵ� ȭ�� ����)
	void	SetCtrlShowStatus();				//ȭ�鿡 ���� ��Ʈ�� ǥ��
	
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

	StOrdKey m_stCurRegItem; //[KSJ000000024]�ֹ� ���� ���� ����
	void Init_ActivationRate();//[0000260] �ս����ѷ�, ��ǥ���ͷ� ���ͷ��� �ڵ����� ���� SJ_KIM(20110720)
   
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
	
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	

public:
	
	//afx_msg	LRESULT OnBaseDrdsData(UINT wParam, LPARAM lParam);
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
};



#pragma once


#include "resource.h"
#include "BaseFrmWnd.h"


// CExSvrAutoOrderDlg 대화 상자입니다.

class CExSvrAutoOrderDlg : public CDialog
{
	DECLARE_DYNAMIC(CExSvrAutoOrderDlg)

public:
	CExSvrAutoOrderDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CExSvrAutoOrderDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_AUTO_DUMMY_FORM };

	double			m_dFeeRate;

	void		ReqChangeAll(int nAction, void *p);
	void		ReqGridList(CString strNextKey = "");
	void		RecvChageAll(char *p, int n);

	void		ReqAcntFeeRate() ;
	void		RecvAcntFeeRate(char *p, int n);


	BOOL		IsValidAcnt(char *p, int n);
	void		RecvGridList(char *p, int n);
	void		RecvAcntCreditInfo(char *p, int n);

	BOOL		SendTr(CString strTrCode, CString szData, long nSize) ;



	BOOL		GetLoadXml(CString strFileRoot, MSXML2::IXMLDOMDocumentPtr &pXmlDom);
	BOOL		InitConditionFromXml();
	void		SetInitContidion(MSXML2::IXMLDOMNodeList *pNodes);
	void		AddConditionListAsKey(CString strGroupName);

	void		LoadAllCondXml();
	void		ParseCondition(XNodePtr pParent);
	void		ParseControl(CCtrlGroup *pCtrlGroup, XNodePtr pParent);

	void		ReqChangeState(int nState, TR_ORDER_DETAIL_IN *pOrdDetail);

	CString		GetParsedCondStmt(CString strCondStmt);

	CString		FindMatchPrice(CString strCode, int nMPFlag);
	int			FindPositions(CString strCode);

	double		GetFeeRate() { return m_dFeeRate; }


protected:
	

	CString     m_strAccount ;
	CString     m_strAcctPwd ;

	CListBox	m_lstMsg;

	int			m_nMapMode;	
	int			m_nOpenTypeBuy;
	int			m_nOpenTypeSell;

	CBaseFrmWnd* m_pBaseWndBuy;
	CBaseFrmWnd* m_pBaseWndSell;



	CTabCtrl	m_tabSellBuy;

	CString		m_strAppPath ;

	TR77010_IN	*m_pTr77010Input;

	BOOL			m_bUseCredit;		//신용주문 사용여부
	BOOL			m_IsInitalized;	

	void		CreateBaseWnd();

	void		ChangeTabSel(int nIndex) ;

	void		ProcessXP1(DrdsData* pDrdsData);

	HRESULT		OnRecv77080(WPARAM wParam, LPARAM lParam) ;
	HRESULT		OnRmsgGetAccountNum(WPARAM wParam, LPARAM lParam) ;


	CString			m_strCurType;
	CMapStringToPtr	m_mapXMLTreeInfo;
	CList<XMLTreeInfo, XMLTreeInfo&> m_listXMLTreeInfo;	
	CMap<CString, LPCTSTR, CCtrlGroup *, CCtrlGroup *>	m_mapCtrlGroup; // A1, A2, A3을 키로하는 CCtrlGroup(콘트롤들 집합) 리스트


	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnChangeTypeTab(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClose() ;
	
		

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnSetEnv();
	afx_msg void OnBnClickedBtnDeleteAll();
	afx_msg void OnBnClickedBtnCancelAll();
	afx_msg void OnBnClickedBtnWatchAll();
	afx_msg void OnBnClickedBtnRefresh();
	afx_msg void OnBnClickedButton1();
};

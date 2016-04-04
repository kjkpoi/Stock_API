#pragma once

#include "OrdCondBase.h"
#include "OrdBase.h"
#include "./control_auto/MapLoadCtrl.h"
#include "./control_auto/dataadmin.h"
// COrdCondWnd

class COrdCondWnd : public CWnd
{
	DECLARE_DYNAMIC(COrdCondWnd)

public:
	COrdCondWnd();
	COrdCondWnd(CString strCondType, CWnd* pParent = NULL);
	virtual ~COrdCondWnd();

	CWnd*	m_pParentWnd;
	int	m_nTargetBaseIndex;
	int	m_nElementIndex;

public:	
	CString			m_strCondType;
	COrdCondBase	m_cOrdCondition;
	CMapLoadCtrl	m_ctrlMapLoad;

	COLORREF	m_clrBk;
	CBrush		m_brushBk;
	BOOL		m_bSelectCond;

	
	CDataAdmin		m_DataAdmin;    
	CList<XMLTreeInfo, XMLTreeInfo&> m_listXMLTreeInfo;

	typedef struct tagSelectCondition{
		int nGroup;
		int	nIndex;			
		int nRow;
		CString strElement;
		CString	strTag;
	} SelectCondition;
	SelectCondition	m_stSelectCondition[MAX_CONDCNT_INSCREEN];

	int	m_nConditionIndex;
	
	
protected:
	// 20120723 ssj - 서버자동주문 >>
	int			m_nMapMode;
	int			m_nCondType;
	// 20130213 ssj - 로드 오버헤드 제거 >>
	CMapStringToPtr *m_pMapXmlTreeInfo;
	CMap<CString, LPCTSTR, CCtrlGroup *, CCtrlGroup *>	*m_pMapCtrlGroup;
	// 20130213 ssj - 로드 오버헤드 제거 <<
	// 20120723 ssj - 서버자동주문 <<

public:

	void SetOrdCondWndInit();
	void InitMapCtrl();
	// 20130213 ssj - 로드 오버헤드 제거 >>
	//BOOL SetXMLInfoList(CMapStringToPtr* mapXMLTreeInfo = NULL);
	BOOL SetXMLInfoList();
	// 20130213 ssj - 로드 오버헤드 제거 <<
	void FuncForXML(UINT nID, LPVOID lpVoid = NULL);
	BOOL SetCondition(XMLTreeInfo* pstXMLTreeInfo, BOOL bMode = TRUE);
	void InitInfoSet();
	void ChangeSkinColor(long lpColor);
	void SetShowMapLoader(BOOL bView, int nGroup = -1, int nRow = -1, CPoint pPosition = NULL);
	
	COrdCondBase GetOrderConditionInfo(BOOL& bValid, CString &strErrorMsg);
	void		 SetOrderConditionInfo(COrdCondBase cOrdCondOrigin); 
	BOOL		 SetMakePacket(CString &strErrorMsg);
	void		 SetConditionItemCode(long lType);

	// 20120723 ssj - 서버자동주문 >>
	void SetMapMode(int nMapMode, int nCondType)
	{
		m_nMapMode = nMapMode;
		m_nCondType = nCondType;
	}
	void InitAllCondVal();
	// 20120723 ssj - 서버자동주문 <<
	
	// 20130213 ssj - 로드 오버헤드 제거 >>
	void SetXmlTreeInfo(CMapStringToPtr	*p, CMap<CString, LPCTSTR, CCtrlGroup *, CCtrlGroup *> * pMapCtrlGroup)
	{
		m_pMapXmlTreeInfo = p;
		m_pMapCtrlGroup = pMapCtrlGroup;
	}
	// 20130213 ssj - 로드 오버헤드 제거 <<

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg LRESULT OnNotifyMapLoad(WPARAM wParam, LPARAM lParam);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};



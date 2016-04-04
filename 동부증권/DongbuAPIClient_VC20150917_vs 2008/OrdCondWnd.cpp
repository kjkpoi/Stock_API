// OrdCondWnd.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ExSvrAutoOrderDlg.h"
#include "OrdCondWnd.h"
#include "BaseFrmWnd.h"

#include "include_auto/MasterDataSub.h"
#include "include_auto/globalAuto.h"

// COrdCondWnd
IMPLEMENT_DYNAMIC(COrdCondWnd, CWnd)

COrdCondWnd::COrdCondWnd()
{
	m_clrBk = COLOR_MAIN_CANVAS;
	m_brushBk.CreateSolidBrush(m_clrBk);
	m_nConditionIndex = 0;

	m_nMapMode = MODE_EQUITIES;
	m_nCondType = COND_PL;
	
	m_pMapCtrlGroup = NULL;
}

COrdCondWnd::COrdCondWnd(CString strCondType, CWnd* pParent)
{
	m_strCondType = strCondType;
	m_pParentWnd = pParent;
	m_clrBk = COLOR_MAIN_CANVAS;
	m_brushBk.CreateSolidBrush(m_clrBk);
	m_nConditionIndex = 0;

	m_nMapMode = MODE_EQUITIES;
	m_nCondType = COND_PL;
}

COrdCondWnd::~COrdCondWnd()
{
	m_brushBk.DeleteObject();
}


BEGIN_MESSAGE_MAP(COrdCondWnd, CWnd)
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
	ON_WM_SIZE()

	ON_MESSAGE(WM_NOTIFY_MAPLOAD, OnNotifyMapLoad)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()



// COrdCondWnd 메시지 처리기입니다.



void COrdCondWnd::OnDestroy()
{
	m_ctrlMapLoad.DestroyWindow();

	m_listXMLTreeInfo.RemoveAll();

	m_DataAdmin.DeleteAll();

	CWnd::OnDestroy();	
}

BOOL COrdCondWnd::OnEraseBkgnd(CDC* pDC)
{
	CRect rc;
	GetClientRect(rc);

	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);
	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());
	CBitmap* pOldbitmap = MemDC.SelectObject(&bitmap);

	MemDC.FillSolidRect(&rc, RGB(0, 255, 0));

	pDC->BitBlt(0, 0, rc.Width(), rc.Height(), &MemDC, 0, 0, SRCCOPY);
	return TRUE;
}

int COrdCondWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;


	m_ctrlMapLoad.Create(this, IDCT_MAPLOAD);	
	m_ctrlMapLoad.SetMapMode(m_nMapMode, m_nCondType);
	
	m_ctrlMapLoad.SetXmlTreeInfo(m_pMapCtrlGroup);	
	m_ctrlMapLoad.SetCheckMode(TRUE);
	m_ctrlMapLoad.ShowWindow(SW_SHOW);

	//SetInit();

	return 0;
}

void COrdCondWnd::SetOrdCondWndInit()
{
	if(!m_pParentWnd)
		m_pParentWnd = GetParent();	

	m_bSelectCond = TRUE;
	m_ctrlMapLoad.SetMapLoadCtrlInit(FALSE);
	InitInfoSet();

	SetXMLInfoList();
	FuncForXML(MCTRL_SETALL_ITEM);
}

void COrdCondWnd::InitMapCtrl()
{
	m_ctrlMapLoad.DestoryAllCtrl();
}

COrdCondBase COrdCondWnd::GetOrderConditionInfo(BOOL& bValid, CString &strErrorMsg)
{
	m_cOrdCondition.InitValue();
	bValid = SetMakePacket(strErrorMsg);
	return m_cOrdCondition;
}

//상세조회 데이터값 컨트롤로 반영.
void COrdCondWnd::SetOrderConditionInfo(COrdCondBase cOrdCondOrigin) 
{
	m_cOrdCondition.InitValue();
	int nConCnt = cOrdCondOrigin.GetCondCount();

	POSITION pos = cOrdCondOrigin.m_listUser_Define.GetHeadPosition();

 	User_Define stUserDefine;
	long lMapType = 0;
	CString strMapType;

	int nIndex;
	for(nIndex = 0; nIndex < _countof(ORDER_COND_STRING); nIndex++)
	{
		if(m_strCondType.CompareNoCase(ORDER_COND_STRING[nIndex]) == 0)
			break;
	}
	
 	while(pos)
 	{
		stUserDefine = m_cOrdCondition.m_listUser_Define.GetNext(pos);		
		
		lMapType = GetLong(stUserDefine.giType, sizeof(stUserDefine.giType));
		
		strMapType.Format("%ld", lMapType);

		//-106 지정시간
		//손익조건
		if(nIndex == 0 && ((lMapType < MAPTYPE_COND_ACCOUNT && lMapType > (MAPTYPE_COND_ACCOUNT - 100)) && lMapType != -106))
		{
			if (cOrdCondOrigin.m_nBasePriceType == BASE_TYPE_MATCH)
			{
				m_ctrlMapLoad.m_btnMatchPrice.SetCheck(BST_CHECKED);
				m_ctrlMapLoad.m_btnUserPrice.SetCheck(BST_UNCHECKED);

				m_ctrlMapLoad.m_edtUserPrice.SetWindowText("");
				m_ctrlMapLoad.m_edtUserPrice.ShowWindow(SW_HIDE);
				m_ctrlMapLoad.m_stcSuffix.ShowWindow(SW_HIDE);
			}
			else
			{
				m_ctrlMapLoad.m_btnMatchPrice.SetCheck(BST_UNCHECKED);
				m_ctrlMapLoad.m_btnUserPrice.SetCheck(BST_CHECKED);

				m_ctrlMapLoad.m_edtUserPrice.SetWindowText(cOrdCondOrigin.m_strBasePrice);
				m_ctrlMapLoad.m_edtUserPrice.ShowWindow(SW_SHOW);
				m_ctrlMapLoad.m_stcSuffix.ShowWindow(SW_SHOW);
			}

			m_ctrlMapLoad.SetValueToControl(strMapType, stUserDefine);
		}
		//시세조건
		else if(nIndex == 1 && ((lMapType < MAPTYPE_COND_BASE && lMapType > (MAPTYPE_COND_BASE - 100)) || lMapType == -106))
			m_ctrlMapLoad.SetValueToControl(strMapType, stUserDefine);
		//BM조건
		else if(nIndex == 2 && (lMapType < MAPTYPE_COND_ITEM && lMapType > (MAPTYPE_COND_ITEM - 100)))
			m_ctrlMapLoad.SetValueToControl(strMapType, stUserDefine);	
		//지표조건
		else if(nIndex == 3 && (lMapType < MAPTYPE_COND_INDEX && lMapType > (MAPTYPE_COND_INDEX - 100)))
			m_ctrlMapLoad.SetValueToControl(strMapType, stUserDefine);		
	}

	//BM조건은 별로도 Set(빌더 종목컨트롤 사용하기때문에 따로 뺌)
	CString strCondCode1 = cOrdCondOrigin.GetCondCode1();
	CString strData;
	CString strType;
	if(!strCondCode1.IsEmpty())
	{
		
		strType = SVRORD_MARKETTYPE_STOCK;
		strData = strCondCode1.Mid(1);
		
		m_ctrlMapLoad.m_ctlStkCodeInput.SetWindowText(strData.Trim());
		
	}
	
}

void COrdCondWnd::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	CRect rtClient;
	GetClientRect(rtClient);

	//--> 2011.09.22 jhj error report
	if(m_ctrlMapLoad.GetSafeHwnd() && IsWindow(m_ctrlMapLoad.GetSafeHwnd()))	
		m_ctrlMapLoad.MoveWindow(rtClient);
	
}

LRESULT COrdCondWnd::OnNotifyMapLoad(WPARAM wParam, LPARAM lParam)
{
	if ((NM_MAPLOAD_OK == wParam) || (NM_MAPLOAD_CLOSE == wParam))
		SetShowMapLoader(FALSE);
	else if (NM_MAPLOAD_UPDATE == wParam)
	{
		if(!m_bSelectCond) return FALSE;

		User_Define stResultUserDefine;
		CString			strResultComposition;
		BOOL bHaveTerm = FALSE;

		int nIndex;
		for(nIndex = 0; nIndex < m_nConditionIndex; nIndex++)
		{		

			if (m_ctrlMapLoad.GetMapValuesToStruct(m_stSelectCondition[nIndex].strTag, 
				stResultUserDefine, 
				strResultComposition,
				bHaveTerm) == TRUE)
			{
				OneConditionInfo  stOneConditionInfo;
				m_DataAdmin.GetElementToOneConditionInfo(m_stSelectCondition[nIndex].strElement, stOneConditionInfo);

				int nTemp;
				nTemp = GetLong(stResultUserDefine.giETerm, sizeof(stResultUserDefine.giETerm));
				if (nTemp < 1 || nTemp > 20)
				{
					MessageBox("봉이내는 1 ~ 20까지만 입력가능합니다.", (CString)PROGRAM_TITLE, MB_OK);
					return FALSE;
				}

				nTemp = GetLong(stResultUserDefine.giSTerm, sizeof(stResultUserDefine.giSTerm));
				if (nTemp < 0 || nTemp > 399)
				{
					MessageBox("봉전기준은 0 ~ 399까지만 입력가능합니다.", (CString)PROGRAM_TITLE, MB_OK);
					return FALSE;
				}

				if (m_stSelectCondition[nIndex].strTag == stOneConditionInfo.strTag)
				{
					m_DataAdmin.ModifyConditionUserDefine(m_stSelectCondition[nIndex].strElement, 
						stResultUserDefine,
						strResultComposition);
				}
			}
			SetShowMapLoader(FALSE);
		}
		
	}
	else if(NM_CHECK_CONDITION ==  wParam)
	{
		int nID = HIWORD(lParam);
		BOOL bCheck = LOWORD(lParam);
		CString strElement = CONDITION_INDEX[nID - INDEX_START_CHKBOX];
		m_DataAdmin.ModifyConditionCheck(strElement, bCheck);
	}
	else if(NM_SELECT_CONDITION == wParam)
	{		
		int nID = (int)wParam;
		int nIndex = nID - INDEX_START_CHKBOX; //조건 index 0~
		m_bSelectCond = TRUE;
		SetShowMapLoader(TRUE, 0, nIndex);

	}
	return TRUE;
}

BOOL COrdCondWnd::SetXMLInfoList()
{
	//한번 얻어오면 다시 요청할 필요 없음.
	if(m_listXMLTreeInfo.GetCount() > 0)
		return TRUE;


	CList<XMLTreeInfo, XMLTreeInfo&>* plistXMLTreeInfo;
	if(m_pMapXmlTreeInfo && m_pMapXmlTreeInfo->Lookup(m_strCondType, (void*&)plistXMLTreeInfo))
	{
		POSITION pos = plistXMLTreeInfo->GetHeadPosition();
		while(pos)
		{	
			m_listXMLTreeInfo.AddTail(plistXMLTreeInfo->GetNext(pos));
		}
		return TRUE;
	}
	return FALSE;
}

void COrdCondWnd::FuncForXML(UINT nID, LPVOID lpVoid)
{
	if(nID == MCTRL_ADD_ITEM) //개별 조건 Set
	{
		XMLTreeInfo* pstXMLTreeInfo = (XMLTreeInfo*)lpVoid;
		if(pstXMLTreeInfo)
			SetCondition(pstXMLTreeInfo);

	}
	else if(nID == MCTRL_SETALL_ITEM) //해당 모든 조건 Set
	{
		POSITION pos = m_listXMLTreeInfo.GetHeadPosition();
		while(pos)
		{	
			XMLTreeInfo stXmlTreeInfo = m_listXMLTreeInfo.GetNext(pos);
				SetCondition(&stXmlTreeInfo);
		}		
	}
}

BOOL COrdCondWnd::SetCondition(XMLTreeInfo* pstXMLTreeInfo, BOOL bMode)
{
	BOOL bResult = FALSE;

	int nGroup = 0;					//m_stSelectCondition.nGroup;
	int nIndex = m_nConditionIndex;//m_stSelectCondition.nIndex;

	if (m_ctrlMapLoad.m_strAfterMapTag != pstXMLTreeInfo->strTag)
	{
		if (m_ctrlMapLoad.SetDrewConditionMap(pstXMLTreeInfo) == TRUE)
			m_ctrlMapLoad.SetDefultToMapValues(pstXMLTreeInfo);
		else
		{
			MessageBox("조건 Map 파일이 존재 하지 않습니다.\n 고객 센터로 문의 하시기 바랍니다.", (CString)PROGRAM_TITLE, MB_OK);
			return bResult;
		}
	}
	else
		m_ctrlMapLoad.SetDefultToMapValues(pstXMLTreeInfo);

	OneConditionInfo  stOneConditionInfo;
	int nTotCondition = 0;

	if (nTotCondition + 1 > MAX_IDXCNT)
	{
		MessageBox("조건은 20까지 입력 가능합니다.", (CString)PROGRAM_TITLE, MB_OK);
		return bResult;
	}
	stOneConditionInfo.bFalg = TRUE;
	stOneConditionInfo.nNotUserFlag = pstXMLTreeInfo->nNotUser;
	stOneConditionInfo.nGubunUserFlag = pstXMLTreeInfo->nGubun;

	stOneConditionInfo.strTag = pstXMLTreeInfo->strTag;
	stOneConditionInfo.strMapFile = pstXMLTreeInfo->strMapFile;

	stOneConditionInfo.nNonAlert = pstXMLTreeInfo->nNonAlert;
	stOneConditionInfo.nChartValSet = pstXMLTreeInfo->nChartValSet;

	stOneConditionInfo.strName = pstXMLTreeInfo->strName;
	stOneConditionInfo.nTargetBaseType = pstXMLTreeInfo->nTargetBase_Type;

	//## Get Map Loader Info ##
	//#=> Set User_Defind
	BOOL bHaveTerm = FALSE;
	if (m_ctrlMapLoad.GetMapValuesToStruct(pstXMLTreeInfo->strTag,
		stOneConditionInfo.stCondition, 
		stOneConditionInfo.strText,
		bHaveTerm) == TRUE)
	{
		CString strOtherTitle;
		CONVERT_TYPETOTITLE(pstXMLTreeInfo->nItemType, strOtherTitle);
		if (strOtherTitle.IsEmpty() == FALSE)
			stOneConditionInfo.strText = "[" + strOtherTitle + "] " + pstXMLTreeInfo->strName;
	}
	else
		return bResult;

	int nTargetBase;
	

	if (m_nTargetBaseIndex == 0)
		nTargetBase = 0;
	else if (m_nTargetBaseIndex > 0)
		nTargetBase = m_nTargetBaseIndex - 1;

	if (pstXMLTreeInfo->nTargetBase_Type == 0)
		SetLong(stOneConditionInfo.stCondition.giTargetBase, sizeof(stOneConditionInfo.stCondition.giTargetBase), TARGETINDEX_TYPE1[m_nTargetBaseIndex]);
	else if (pstXMLTreeInfo->nTargetBase_Type == 1)
		SetLong(stOneConditionInfo.stCondition.giTargetBase, sizeof(stOneConditionInfo.stCondition.giTargetBase), TARGETINDEX_TYPE2[0]);
	else if (pstXMLTreeInfo->nTargetBase_Type == 2)
		SetLong(stOneConditionInfo.stCondition.giTargetBase, sizeof(stOneConditionInfo.stCondition.giTargetBase), TARGETINDEX_TYPE3[m_nTargetBaseIndex]);

	if (bHaveTerm == FALSE)
	{
		SetLong(stOneConditionInfo.stCondition.giSTerm, sizeof(stOneConditionInfo.stCondition.giSTerm), 0);
		SetLong(stOneConditionInfo.stCondition.giETerm, sizeof(stOneConditionInfo.stCondition.giETerm), 1);
	}

	//# 검색 구분 
	if (pstXMLTreeInfo->nCondiType < 0)
		return bResult;
	
	CString strTemp;
	strTemp.Format("%d", pstXMLTreeInfo->nCondiType);
	memcpy(&stOneConditionInfo.stCondition.IndexType, strTemp.GetBuffer(0), sizeof(char));

	//# 검색형태
	if ((pstXMLTreeInfo->nItemType == (int)TREE_SELECT_TYPE_ITEM_COMM) ||
		(pstXMLTreeInfo->nItemType == (int)TREE_SELECT_TYPE_ITEM_ORDER))
		stOneConditionInfo.stCondition.SearchType = '0';	//# 일반
	else if (pstXMLTreeInfo->nItemType == (int)TREE_SELECT_TYPE_PORTPOLIO)
	{

	}
	else if (pstXMLTreeInfo->nItemType == (int)TREE_SELECT_TYPE_LANGUAGE)
		stOneConditionInfo.stCondition.SearchType = '1';	//# 사용자 정의

	//## Element 정렬
	BOOL bTargetEnable = TRUE;
	if (/*(nGroup == 0) && */(m_nTargetBaseIndex == 0))
		bTargetEnable = FALSE;

	if (bMode == TRUE)		//# Add
	{
 		if (m_DataAdmin.AddCondition(nGroup, ((CBaseFrmWnd*)m_pParentWnd)->m_nElementIndex, stOneConditionInfo, pstXMLTreeInfo->strResultViewID,
 			(pstXMLTreeInfo->nResultViewDefVal == 1) ? TRUE : FALSE) == FALSE)
 		{
 			MessageBox("데이터 입력 오류", (CString)PROGRAM_TITLE, MB_OK);
 			return bResult;
 		}	


		//# Select Map Info
 		m_stSelectCondition[m_nConditionIndex].nGroup = nGroup;
 		m_stSelectCondition[m_nConditionIndex].nIndex = nIndex;
 	//	m_stSelectCondition[m_nConditionIndex].nRow = m_pGridCtrl->GetGroupRowCnt(nGroup) - 1;
 		m_stSelectCondition[m_nConditionIndex].strElement = CONDITION_INDEX[((CBaseFrmWnd*)m_pParentWnd)->m_nElementIndex];
 		m_stSelectCondition[m_nConditionIndex].strTag = pstXMLTreeInfo->strTag;

 	}

	//체크박스 선택안되게 초기화.
	m_DataAdmin.ModifyConditionCheck(CONDITION_INDEX[((CBaseFrmWnd*)m_pParentWnd)->m_nElementIndex], FALSE);
	((CBaseFrmWnd*)m_pParentWnd)->m_nElementIndex++;
	m_nConditionIndex++;		
	return TRUE;

}

void COrdCondWnd::SetShowMapLoader(BOOL bView, int nGroup, int nRow, CPoint pPosition)
{
	if (bView == TRUE)
	{
		OneConditionInfo  stOneConditionInfo;

		//SJ_KIM
		//CString strElement = m_pGridCtrl->GetElementInfo(nGroup, nRow);
		CString strElement;

		if (m_DataAdmin.GetElementToOneConditionInfo(strElement, stOneConditionInfo) == FALSE)
		{
			m_ctrlMapLoad.DestoryAllCtrl();

			MessageBox("저장 데이터 오류.\n 초기화 후 사용하십시오.", (CString)PROGRAM_TITLE, MB_OK);
			return;
		}

		//# Select Condition Info!
 		m_stSelectCondition[m_nConditionIndex].nGroup = nGroup;
 		m_stSelectCondition[m_nConditionIndex].nRow = nRow;
 		m_stSelectCondition[m_nConditionIndex].strElement = strElement;
 		m_stSelectCondition[m_nConditionIndex].strTag = stOneConditionInfo.strTag;

		XMLTreeInfo stXMLTreeInfo;

		int nItemType;
		CONVERT_TAGTOTYPE(stOneConditionInfo.strTag, nItemType);
		if (nItemType == -1)
		{
			if (nGroup == 0)
				stXMLTreeInfo.nItemType = (int)TREE_SELECT_TYPE_ITEM_COMM;
			else
				stXMLTreeInfo.nItemType = (int)TREE_SELECT_TYPE_ITEM_ORDER;
		}
		else
			stXMLTreeInfo.nItemType = nItemType;

		stXMLTreeInfo.strName = stOneConditionInfo.strName;
		stXMLTreeInfo.strTag = stOneConditionInfo.strTag;

		char *pBuff;
		pBuff = new char[sizeof(stOneConditionInfo.stCondition.IndexType) + 1];
		memset(pBuff, 0x00, sizeof(stOneConditionInfo.stCondition.IndexType) + 1);
		memcpy(pBuff, &stOneConditionInfo.stCondition.IndexType, sizeof(stOneConditionInfo.stCondition.IndexType));
		stXMLTreeInfo.nCondiType = atoi(pBuff);
		delete[] pBuff;

		stXMLTreeInfo.nTargetBase_Type = stOneConditionInfo.nTargetBaseType;
		stXMLTreeInfo.nGubun = stOneConditionInfo.nGubunUserFlag;

		pBuff = new char[sizeof(stOneConditionInfo.stCondition.IdxContiGubun) + 1];
		memset(pBuff, 0x00, sizeof(stOneConditionInfo.stCondition.IdxContiGubun) + 1);
		memcpy(pBuff, &stOneConditionInfo.stCondition.IdxContiGubun, sizeof(stOneConditionInfo.stCondition.IdxContiGubun));
		stXMLTreeInfo.nGubunDefVal = atoi(pBuff);
		delete[] pBuff;

		stXMLTreeInfo.nNotUser = stOneConditionInfo.nNotUserFlag;

		pBuff = new char[sizeof(stOneConditionInfo.stCondition.Reverse) + 1];
		memset(pBuff, 0x00, sizeof(stOneConditionInfo.stCondition.Reverse) + 1);
		memcpy(pBuff, &stOneConditionInfo.stCondition.Reverse, sizeof(stOneConditionInfo.stCondition.Reverse));
		stXMLTreeInfo.nNotDefVal = atoi(pBuff);
		delete[] pBuff;

		CString strID;
		HeadInfoType		stHeadInfoType;
		for (int nIndex = 0; nIndex < stOneConditionInfo.stHeadMoveInfo.nColCnt; nIndex++)
		{
			stHeadInfoType = stOneConditionInfo.stHeadMoveInfo.stHeadType[nIndex];

			strID.Format("%d", stHeadInfoType.lHeadID);
			stXMLTreeInfo.strResultViewID += strID + "/";
		}
		stXMLTreeInfo.nResultViewDefVal = stOneConditionInfo.stHeadMoveInfo.bView;
		stXMLTreeInfo.strMapFile = stOneConditionInfo.strMapFile;

		if (m_ctrlMapLoad.SetDrewConditionMap(&stXMLTreeInfo) == TRUE)
		{
			m_ctrlMapLoad.SetStructToMapValues(stOneConditionInfo.strTag, &stOneConditionInfo.stCondition);

//			SetNowXMLTreeInfo(&stXMLTreeInfo);
		}
		else
		{
			MessageBox("선택한 지표의 Map 파일이 존재 하지 않습니다.\n"
				"고객 센터로 문의 하시기 바랍니다.", (CString)PROGRAM_TITLE, MB_OK);
			return;
		}
	
	}

}

void COrdCondWnd::InitInfoSet()
{
	//m_nElementIndex = 0;
	//((CBaseFrmWnd*)m_pParentWnd)->ResetElement();
	m_nTargetBaseIndex = 0;

	m_DataAdmin.DeleteAll();
}

void COrdCondWnd::ChangeSkinColor(long lpColor)
{
	ST_CLIENTCOLOR* pstClrClient = (ST_CLIENTCOLOR*)lpColor;

	if(!pstClrClient)
		return;

	// 20120723 ssj - 서버자동주문 >>
	//m_clrBk = pstClrClient->m_stClrTab.m_clrTabBody;
	m_clrBk = pstClrClient->m_clrBkGnd;
	// 20120723 ssj - 서버자동주문 <<
	if(m_brushBk.DeleteObject())
		m_brushBk.CreateSolidBrush(m_clrBk);

	m_ctrlMapLoad.ChangeSkinColor(m_clrBk);	
}


//NM_SELECT_CONDITION
HBRUSH COrdCondWnd::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CWnd::OnCtlColor(pDC, pWnd, nCtlColor);

	if (nCtlColor == CTLCOLOR_STATIC)
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetBkColor(m_clrBk);	
		hbr = m_brushBk;
	}
	return hbr;
}

BOOL COrdCondWnd::SetMakePacket(CString &strErrorMsg)
{
	m_cOrdCondition.m_listUser_Define.RemoveAll();

	int nIndexNo;
	int nUserDefineIndex = 0;
	POSITION posFirstOrder = NULL;
	
	User_Define		stUser_Define[MAX_IDXCNT];
	CList<User_Define, User_Define> listUser_Define;
	

	memset((LPVOID)stUser_Define, 0x00, SZ_User_Define * MAX_IDXCNT);
	
	nIndexNo = 1;

	int nCntCandle = 0;
	CString strElement;
	OneConditionInfo stOneConditionInfo;
	// 20120723 ssj - 서버자동주문 >>
	//stOneConditionInfo.stCondition.IndexNo = 0;
	SetLong(stOneConditionInfo.stCondition.giIndexNo, sizeof(stOneConditionInfo.stCondition.giIndexNo), 0);
	// 20120723 ssj - 서버자동주문 <<
	CString strMapType;

// 	int nCondCnt = m_DataAdmin.m_arrGroups.GetSize();
// 	m_cOrdCondition.m_pstUser_Define = new User_Define[nCondCnt];
// 	memset((LPVOID)stUser_Define, 0x00, SZ_User_Define * nCondCnt);
	
	// 20120723 ssj - 서버자동주문 >>
	int nOp1 = -1;
	int nCompVal1 = 0;
	int nOp2 = -1;
	int nCompVal2 = 0;
	// 20120723 ssj - 서버자동주문 <<

	int nEleCount = m_DataAdmin.m_arrGroups.GetSize();
	for (int nGroupIndex = 0; nGroupIndex < nEleCount; ++nGroupIndex)
	{ 

		GROUP_INFO* pGroup = m_DataAdmin.m_arrGroups.GetAt(nGroupIndex);

	
		int nCondCount = m_DataAdmin.GetGroupToConditionCnt(pGroup->nGroup, FALSE);
		if(0 == nCondCount)
			continue;

		for (int nConditionIndex = 0; nConditionIndex < nCondCount; ++nConditionIndex)
		{
			strElement = ((CBaseFrmWnd*)m_pParentWnd)->GetElement();
			
			
			if (strElement.IsEmpty() == FALSE)
			{
				m_DataAdmin.GetElementToOneConditionInfo(strElement, stOneConditionInfo);	
				
				if (stOneConditionInfo.bFalg == TRUE)
				{
					// 20120723 ssj - 서버자동주문 >>
					//SetConditionItemCode(stOneConditionInfo.stCondition.Type);
					//strMapType.Format("%ld", stOneConditionInfo.stCondition.Type);
					int nTemp = GetLong(stOneConditionInfo.stCondition.giType, sizeof(stOneConditionInfo.stCondition.giType));
					SetConditionItemCode(nTemp);
					strMapType.Format("%ld", nTemp);
					// 20120723 ssj - 서버자동주문 <<

					if(!m_ctrlMapLoad.GetCheckIsNotEmpty(strMapType))
						return FALSE;
					
					// 20120723 ssj - 서버자동주문 >>
					if (strMapType == "-301")
					{
						nOp1 = atol(CString(stOneConditionInfo.stCondition.giType2, sizeof(stOneConditionInfo.stCondition.giType2)));
						nCompVal1 = atol(CString((LPCTSTR)&stOneConditionInfo.stCondition.Condition[0], sizeof(CHAR10)));
					}
					else if (strMapType == "-307")
					{
						nOp2 = atol(CString(stOneConditionInfo.stCondition.giType2, sizeof(stOneConditionInfo.stCondition.giType2)));
						nCompVal2 = atol(CString((LPCTSTR)&stOneConditionInfo.stCondition.Condition[0], sizeof(CHAR10)));
					}
					// 20120723 ssj - 서버자동주문 <<

					m_cOrdCondition.AddCondExp(strElement);			

					// 20120723 ssj - 서버자동주문 >>
					//stOneConditionInfo.stCondition.IndexNo = nIndexNo;
					SetLong(stOneConditionInfo.stCondition.giIndexNo, sizeof(stOneConditionInfo.stCondition.giIndexNo), nIndexNo);
					// 20120723 ssj - 서버자동주문 <<
					nIndexNo++;					

					// 20120723 ssj - 서버자동주문 >>
					//stOneConditionInfo.stCondition.GroupNo = 0;//pGroup->nGroup;
					//stOneConditionInfo.stCondition.GroupIdxCnt = m_DataAdmin.GetGroupToConditionCnt(pGroup->nGroup);
					SetLong(stOneConditionInfo.stCondition.giGroupNo, sizeof(stOneConditionInfo.stCondition.giGroupNo), 0);
					SetLong(stOneConditionInfo.stCondition.giGroupIdxCnt, sizeof(stOneConditionInfo.stCondition.giGroupIdxCnt), m_DataAdmin.GetGroupToConditionCnt(pGroup->nGroup));
					// 20120723 ssj - 서버자동주문 <<

					memcpy(&stOneConditionInfo.stCondition.Element, strElement, sizeof(stOneConditionInfo.stCondition.Element));
					
					// 20120723 ssj - 서버자동주문 >>
					//stOneConditionInfo.stCondition.STerm += nCntCandle;
					//stOneConditionInfo.stCondition.ETerm += nCntCandle;
					int n1 = GetLong(stOneConditionInfo.stCondition.giSTerm, sizeof(stOneConditionInfo.stCondition.giSTerm));
					int n2 = GetLong(stOneConditionInfo.stCondition.giETerm, sizeof(stOneConditionInfo.stCondition.giETerm));
					SetLong(stOneConditionInfo.stCondition.giSTerm, sizeof(stOneConditionInfo.stCondition.giSTerm), n1 + nCntCandle);
					SetLong(stOneConditionInfo.stCondition.giETerm, sizeof(stOneConditionInfo.stCondition.giETerm), n2 + nCntCandle);
					// 20120723 ssj - 서버자동주문 <<
					
					if (stOneConditionInfo.stCondition.IdxContiGubun == '0')
					{
						if ((stOneConditionInfo.bFieldState == TRUE) &&
							(stOneConditionInfo.bFieldVal == TRUE))
						{	
							//# Add Move Filed Info!
// 							((CConditionResultWnd*)pwndMainFrm->GetWnd("RESULT"))->SetAdd_MoveHead(stOneConditionInfo.stHeadMoveInfo);
// 							stOneConditionInfo.stCondition.ResultViewNum = stOneConditionInfo.stHeadMoveInfo.nColCnt;
						}
						else
						{
							// 20120723 ssj - 서버자동주문 >>
							//stOneConditionInfo.stCondition.ResultViewNum = 0;
							SetLong(stOneConditionInfo.stCondition.giResultViewNum, sizeof(stOneConditionInfo.stCondition.giResultViewNum), 0);
							// 20120723 ssj - 서버자동주문 <<
						}

						if (posFirstOrder == NULL)
						{
							listUser_Define.AddTail(stOneConditionInfo.stCondition);
						}
						else
							listUser_Define.InsertBefore(posFirstOrder, stOneConditionInfo.stCondition);
					}
					else
					{
						if ((stOneConditionInfo.bFieldState == TRUE) &&
							(stOneConditionInfo.bFieldVal == TRUE))
						{
							//# Add Move Filed Info!
// 							((CConditionResultWnd*)pwndMainFrm->GetWnd("RESULT"))->SetAdd_MoveHead(stOneConditionInfo.stHeadMoveInfo);
// 							stOneConditionInfo.stCondition.ResultViewNum = stOneConditionInfo.stHeadMoveInfo.nColCnt;
						}
						else
						{
							// 20120723 ssj - 서버자동주문 <<
							//stOneConditionInfo.stCondition.ResultViewNum = 0;
							SetLong(stOneConditionInfo.stCondition.giResultViewNum, sizeof(stOneConditionInfo.stCondition.giResultViewNum), 0);
							// 20120723 ssj - 서버자동주문 <<
						}
						
						if (posFirstOrder == NULL)
						{
							listUser_Define.AddTail(stOneConditionInfo.stCondition);
							posFirstOrder = listUser_Define.GetTailPosition();
						}
						else
							listUser_Define.AddTail(stOneConditionInfo.stCondition);
					}
				}
			}
		}

		m_cOrdCondition.SetUserDefineList(&listUser_Define);
		
// 		if (listUser_Define.GetCount() > 0)
// 		{
// 			for (nIndex = 0; nIndex < listUser_Define.GetCount(); nIndex++)
// 			{
// 				pos = listUser_Define.FindIndex(nIndex);
// 				memcpy(&stUser_Finder.stUser_Define[nUserDefineIndex], &listUser_Define.GetAt(pos), SZ_User_Define);
// 				
// 				//# News Condition => C1 Val Change 
// 				if (stUser_Finder.stUser_Define[nUserDefineIndex].Type == NEWS_TYPE)
// 				{
// 					//stUser_Define[nUserDefineIndex].Condition[0] = GetNewsCodeToIndex((int)stUser_Define[nUserDefineIndex].Condition[0]);
// 					
// 					stUser_Finder.stUser_Define[nUserDefineIndex].SignalCnt1 = 1;
// 					stUser_Finder.stUser_Define[nUserDefineIndex].SignalCnt2 = 1;
// 				}		
// 				nUserDefineIndex++;
// 			}
// 		}
		listUser_Define.RemoveAll();
		posFirstOrder = NULL;
	}

	// 20120723 ssj - 서버자동주문 >>
	strErrorMsg = "";
	if (nOp1 != -1 && nOp2 != -1) // 시세조건중 첫번째, 두번째것이 선택되었다면
	{
		//0: >,  1: >=,  2: ==,  3: <=,  4: <
		switch (nOp1) 
		{
		case 0://0: >,  1: >=,  2: ==,  3: <=,  4: <
			switch (nOp2)
			{
			case 0:
			case 1:
				strErrorMsg = "시세조건의 첫번째 조건값과 두번째 조건값의 유효 범위가 중첩되었습니다.";
				break;
			case 2:
				break;
			case 3:
			case 4:
				if (nCompVal1 < nCompVal2)
					strErrorMsg = "시세조건의 첫번째 조건값이 두번째 조건값보다 커야 합니다.";
				break;
			}
			break;
		case 1://0: >,  1: >=,  2: ==,  3: <=,  4: <
			switch (nOp2)
			{
			case 0:
			case 1:
				strErrorMsg = "시세조건의 첫번째 조건값과 두번째 조건값의 유효 범위가 중첩되었습니다.";
				break;
			case 2:
				break;
			case 3:
			case 4:
				if (nCompVal1 < nCompVal2)
					strErrorMsg = "시세조건의 첫번째 조건값이 두번째 조건값보다 커야 합니다.";
				break;
			}
			break;
		case 2://0: >,  1: >=,  2: ==,  3: <=,  4: <
			switch (nOp2)
			{
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			}
			break;
		case 3://0: >,  1: >=,  2: ==,  3: <=,  4: <
			switch (nOp2)
			{
			case 0:
			case 1:
				if (nCompVal1 > nCompVal2)
					strErrorMsg = "시세조건의 첫번째 조건값이 두번째 조건값보다 작아야 합니다.";
				break;
			case 2:
				break;
			case 3:
			case 4:
				strErrorMsg = "시세조건의 첫번째 조건값과 두번째 조건값의 유효 범위가 중첩되었습니다.";
				break;
			}
			break;
		case 4://0: >,  1: >=,  2: ==,  3: <=,  4: <
			switch (nOp2)
			{
			case 0:
			case 1:
				if (nCompVal1 > nCompVal2)
					strErrorMsg = "시세조건의 첫번째 조건값이 두번째 조건값보다 작아야 합니다.";
				break;
			case 2:
				break;
			case 3:
			case 4:
				strErrorMsg = "시세조건의 첫번째 조건값과 두번째 조건값의 유효 범위가 중첩되었습니다.";
				break;
			}
			break;
		}
	}
	// 20120723 ssj - 서버자동주문 <<

	if (strErrorMsg.GetLength() > 0)
		return FALSE;

	return TRUE;
}

void COrdCondWnd::SetConditionItemCode(long lType)
{
	if(lType < -204 || lType > 201)
		return;
	
	CString strType;
	CString strData, strCode;
	int nMarketType;
	if(lType == -201)
	{
		//strType = SVRORD_MARKETTYPE_STOCK;		
		nMarketType = GetMarketType(strData);

		if ( nMarketType == CDRCodeTypeInfo::DRCODETYPE_KOSPI_STOCK)//코스피
			strType = _T("J");
		else if(nMarketType == CDRCodeTypeInfo::DRCODETYPE_KOSDAQ_STOCK)//코스닥
			strType = _T("Q");

		strCode = strType + strData;
		m_cOrdCondition.SetCondCode1(strCode);
	}
	//else if(lType == -202)
	//{	
	//	strType =SVRORD_MARKETTYPE_UP;
	//	
	//	// 20120723 ssj - 서버자동주문 >>
	//	//m_pParentWnd->SendMessage(UMSG_GETITEMCODE, (WPARAM)(LPCTSTR)strType, (LPARAM)&strData);
	//	strData = m_ctrlMapLoad.m_ctlIdxCodeInput.GetDataText();
	//	// 20120723 ssj - 서버자동주문 <<

	//	strCode = strType + strData;
	//	m_cOrdCondition.SetCondCode2(strCode);
	//}
	//else if(lType == -203)
	//{
	//	strType =SVRORD_MARKETTYPE_FUT;
	//	//m_pParentWnd->SendMessage(UMSG_GETITEMCODE, (WPARAM)(LPCTSTR)strType, (LPARAM)&strData);
	//	strData = m_ctrlMapLoad.m_ctlFutCodeInput.GetDataText();
	//	strCode = strType + strData;
	//	m_cOrdCondition.SetCondCode3(strCode);
	//}
	//else if(lType == -204)
	//{
	//	strType =SVRORD_MARKETTYPE_OPT;
	//	//m_pParentWnd->SendMessage(UMSG_GETITEMCODE, (WPARAM)(LPCTSTR)strType, (LPARAM)&strData);
	//	strData = m_ctrlMapLoad.m_ctlOptCodeInput.GetDataText();
	//	strCode = strType + strData;
	//	m_cOrdCondition.SetCondCode4(strCode);
	//}
}

// 20120723 ssj - 서버자동주문 >>
void COrdCondWnd::InitAllCondVal()
{
	POSITION pos = m_listXMLTreeInfo.GetHeadPosition();
	while (pos != NULL)
	{	
		XMLTreeInfo stXmlTreeInfo = m_listXMLTreeInfo.GetNext(pos);
		m_ctrlMapLoad.SetDefultToMapValues(&stXmlTreeInfo);
	}	
}
// 20120723 ssj - 서버자동주문 <<
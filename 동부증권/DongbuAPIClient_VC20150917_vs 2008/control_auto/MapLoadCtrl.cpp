// MapLoadCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "../DongbuAPIClient_VC.h"
#include "MapLoadCtrl.h"
#include <math.h>

#include "../resource.h"


#include "../include_auto/globalauto.h"
#include "../include_auto/MasterDataSub.h"

#include "../BaseFrmWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/****************************************************/
/*																		              */
/*							Map Loader Control							    */
/*							(Mouse Control)								      */
/*																		              */
/*							작성일 : 2002. 10~							    */
/*						작성자 : 우동우 (TEXEN SYSTEM)		    */
/*																		              */
/****************************************************/
//#include "../DefineFiles/color_typedef.h"   //# <= Color define 

/////////////////////////////////////////////////////////////////////////////
// CMapLoadCtrl

//## resource ID ##
#define IDC_BUTTON_UPDATA					510
#define IDC_BUTTON_NOTCHECK				520
#define IDC_BUTTON_OK							530
#define IDC_BUTTON_BASE						540
#define IDC_BUTTON_GUBUNCHECK			550
#define IDC_STITIC_CONDITIONTITLE	560


#define NEWS_CONTROL_TYPE				"KeyWord"
#define NEWS_FILENAME						"News"


//## Condition Title Position
#define POSITION_X_TITLE				10
#define CONDITIONTITLE_WIDTH			270
#define NOTCHECK_WIDTH					95
#define GUBUNCHECK_WIDTH				75

#define RESOLUTION_X					400
#define RESOLUTION_Y					100

const int m_nConstBtnWidth = 50;
const int m_nConstBtnHeight = 20;



const CString m_strConstMapSection = "map";
#define FILE_UPJONG				"/data/upname.dat"
#define INDUSTRY_TYPE			2	//# 업종 (상장산업)
#define KOSDAK_TYPE				3	//# 코스닥 (거래원)
#define GROUP_TYPE				11	//# 계열사 (그룹사)

//static int m_nIndexChk = INDEX_START_CHKBOX;
//<<[0000260] 손실제한률, 목표이익률 수익률이 자동으로 셋팅 SJ_KIM(20110720)
#define	ACTIVATION_EARNRATE			1
#define ACTIVATION_PREVENTLOSSRATE  2

// 20120723 ssj - 서버자동주문 >>
#define			ID_STK_CODEINPUT		950
//#define			ID_IDX_CODEINPUT		1001
//#define			ID_FUT_CODEINPUT		1002
//#define			ID_OPT_CODEINPUT		1003
// 20120723 ssj - 서버자동주문 <<

//extern HINSTANCE g_hInstance;
//extern CTrSvrAutoOrdApp theApp;

CMapLoadCtrl::CMapLoadCtrl()
{
	LOGFONT	  logFont;
	GETFONT(logFont, 12, 400, m_fontDefault);
	GETFONT(logFont, 12, 600, m_fontBold);
//	m_brushDefault.CreateSolidBrush(COLOR_MAPLOAD);
	m_brushDefault.CreateSolidBrush(RGB(232, 226, 210));		// KB투자증권
	m_clrSkin = RGB(232, 226, 210);
	
	m_nOneLineHeight = 22;
	m_strAfterMapTag = "XXX";
	m_strAfterMapFileName = "XXX";
	m_listControlInfo.RemoveAll();
	
	
	m_pNotCheckBtn = NULL;
	m_pGubunCheckBtn = NULL;
	
	m_pConditionTitleStatic = NULL;
	
	m_pUpdateBtn = NULL;
	m_pOKBtn = NULL;
	m_pBaseBtn = NULL;
	m_pwndMsgTarget = NULL;
	m_pwndMain = NULL;

	m_TopExp = 0;
	m_nLastResourceID = 1;
	m_bChkMode = FALSE;

	m_pBase = NULL;

	m_nResourceJCode  = -1;

	m_rtJCode  = CRect(0, 0, 0, 0);

	m_bCmbInit = TRUE; //

	m_nActivationRate = -1;//[0000260] 손실제한률, 목표이익률 수익률이 자동으로 셋팅 SJ_KIM(20110720)
	m_nLastTopLine = 1;

	// 20120723 ssj - 서버자동주문 >>
	m_bAddSysCtrl = FALSE;
	m_pCmbSync1 = NULL;
	m_pCmbSync2 = NULL;
	m_pEditSync2 = NULL;

	m_pStaticLossTitle = NULL;
	m_pStaticProfitTile = NULL;

	m_nMultiLineCount = 0;

	m_strMarket = SVRORD_MARKETTYPE_STOCK;
	m_nMapMode = MODE_EQUITIES;
	m_nCondType = COND_PL;

	m_pStcStkCodeName = NULL;
	m_pMapCtrlGroup = NULL;
}

CMapLoadCtrl::~CMapLoadCtrl()
{
	
}

BEGIN_MESSAGE_MAP(CMapLoadCtrl, CStatic)
	//{{AFX_MSG_MAP(CMapLoadCtrl)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP

	ON_BN_CLICKED(IDC_BUTTON_UPDATA, OnBtnUpdate)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnBtnOK)
	ON_BN_CLICKED(IDC_BUTTON_BASE, OnBtnBase)
	ON_BN_CLICKED(IDC_BUTTON_NOTCHECK, OnBtnNotCheck)
	ON_BN_CLICKED(IDC_BUTTON_GUBUNCHECK, OnBtnGubunCheck)
	ON_CONTROL_RANGE(BN_CLICKED, INDEX_START_CHKBOX, INDEX_END_CHKBOX, OnChkMapCtrl)
	ON_CONTROL_RANGE(CBN_SELCHANGE, INDEX_START_COMBO, INDEX_END_COMBO, OnCmbMapCtrl)
	//[0000260] 손실제한률, 목표이익률 수익률이 자동으로 셋팅 SJ_KIM(20110720)
	ON_BN_CLICKED(IDB_EARNINGRATE, OnBtnEarningRate)
	ON_BN_CLICKED(IDB_PREVENTLOSSRATE, OnBtnPreventLossRate)

	// 20120723 ssj - 서버자동주문 >>
	ON_BN_CLICKED(IDC_BTN_PERCENT, OnBtnPercent)
	ON_BN_CLICKED(IDC_BTN_PRICE, OnBtnWon)
	ON_BN_CLICKED(IDC_BTN_TICK, OnBtnTick)

	ON_BN_CLICKED(IDC_BTN_MATCH_PRICE, OnBtnMatchPrice)
	ON_BN_CLICKED(IDC_BTN_BASE_PRICE, OnBtnBasePrice)
	//ON_REGISTERED_MESSAGE(RMSG_EVENT_CODEINPUT, OnEventCodeInput)
	// 20120723 ssj - 서버자동주문 <<

	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMapLoadCtrl message handlers
CString CMapLoadCtrl::GetAppFileRoot()
{
	char buf[255];
	GetModuleFileName(NULL, buf, 255); //# 실행되는 위치보기 
	
	int lastlocationofbackslash = 0;
	
	int nBufCnt = strlen(buf);
	for (int i = 0; i < nBufCnt; i++)
	{
		if (buf[i] == '\\') 
			lastlocationofbackslash = i;
	}
	
	CString strAppPath = _T("");
	for (int j = 0; j < lastlocationofbackslash; j++)
		strAppPath += buf[j];
	
	return strAppPath;
}


BOOL CMapLoadCtrl::Create(CWnd* pParentWnd, UINT nID)
{
	BOOL bResult = FALSE;
	
	bResult = CStatic::Create(_T(""), WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, //| WS_BORDER, 
		CRect(0, 0, 100, 100), pParentWnd, nID);
	
	m_pwndMsgTarget = pParentWnd;
	m_pBase = (CBaseFrmWnd*)m_pwndMsgTarget->GetParent();
	
	return bResult;
}

int CMapLoadCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CStatic::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	//## Front Load Condition Map File Tag! ##
	m_strAfterMapFileName = "XXXX";
	m_strAfterMapTag = "XXXX";
	
	//## delete Ctrl List ##
	m_saDelCtrlData.RemoveAll();	
	GetDir_DrfnRoot(m_strAppPath);


	m_stcStcDummy.Create("", WS_CHILD, CRect(0, 0, 0, 0), this, ID_STK_CODEINPUT);


	return 0;
}

BOOL CMapLoadCtrl::SetMapLoadCtrlInit(BOOL bIndustry)
{
	m_bIndustry = bIndustry;
	
	CWnd* pwndParent = GetParent(); //CConditionMakeWnd
	if(!pwndParent)
		return FALSE;

	pwndParent = pwndParent->GetParent();		//CConditionView
	if(!pwndParent)
		return FALSE;

	pwndParent = pwndParent->GetParent();		
	if(!pwndParent)
		return FALSE;

	pwndParent = pwndParent->GetParent();		//CMainFrmWnd	
	if(!pwndParent)
		return FALSE;
	
	m_pwndMain = pwndParent;
	
	GetLoad_MarketInfo();
	
	return TRUE;
}


BOOL CMapLoadCtrl::GetLoad_MarketInfo()
{
	BOOL bResult = TRUE;
	
	// 	CODE_ALLJONGMOK - 장내종목 + 코스닥종목
	//	CODE_JONGMOK - 장내종목
	//	CODE_KJONGMOK - 코스닥종목
	//	CODE_UPJONG - 장내업종
	//	CODE_KUPJONG - 코스닥업종

	
	return bResult;
}

void CMapLoadCtrl::OnDestroy() 
{
	//	CStatic::OnDestroy();
	
	RemoveAllCtrlList();

	int nCnt = m_arrCmbExtraInfo.GetCount();
	for (int i = 0; i < nCnt; i++)
	{
		CComboBoxExtraInfo *p = m_arrCmbExtraInfo.GetAt(i);
		if (p)
			delete p;
	}
	m_arrCmbExtraInfo.RemoveAll();

	if (m_pStcStkCodeName)
		delete m_pStcStkCodeName;


	TRACE("\n# MapLoader OnDestroy!");
	
	m_fontDefault.DeleteObject();
	m_fontBold.DeleteObject();
	
	m_brushDefault.DeleteObject();	
	DestoryAllCtrl();

	POSITION pos;
	CString	strCtrlTag;
	int nIndex = 0;
	CUIntArray* plarrResourceID;
	for (pos = m_mapResourceID.GetStartPosition(); pos != NULL;)
	{
		m_mapResourceID.GetNextAssoc(pos, strCtrlTag, (void*&)plarrResourceID);
		plarrResourceID->RemoveAll();
		delete plarrResourceID;
		m_mapResourceID.RemoveKey(strCtrlTag);
	}
	m_mapResourceID.RemoveAll();


	CString strKey;
	StCondKey* pStCondKey;
	for (pos = m_mapTagID.GetStartPosition(); pos != NULL;)
	{
		m_mapTagID.GetNextAssoc(pos, strKey, (void*&)pStCondKey);

		if(!pStCondKey)
			continue;

		delete pStCondKey;
		pStCondKey = NULL;
		m_mapTagID.RemoveKey(strKey);
	}
	m_mapTagID.RemoveAll();	
	
	CStatic::OnDestroy();
}

void CMapLoadCtrl::DestoryAllCtrl()
{
	//## Regist Control Data ##
	DestroyConditionMap();
	
	DestroyNotCheckBtn();
	DestroyUpdateBtn();	
	DestroyOKBtn();
	DestroyBaseBtn();
	
	DestroyGubunCheckBtn();
	DestroyConditionTitleStatic();
	DestroyChkbtnCtrl();

	TRACE("\n# MapLoader DestoryAllCtrl!\n");

	m_nResourceJCode = -1;
	
}


CString CMapLoadCtrl::GetTagToNodeData(CString strTagID, CString strNode)
{
	
	CString strRet = "";
	if (m_pMapCtrlGroup)
	{
		CCtrlGroup *pCtrlGroup = NULL;
		m_pMapCtrlGroup->Lookup(strTagID, pCtrlGroup);
		if (pCtrlGroup)
		{
			pCtrlGroup->m_mapGrpKeyVal.Lookup(strNode, strRet);
		}
		else
			AfxMessageBox("parse error:" + strTagID + "/" + strNode);
	}

	return strRet;
}


CString CMapLoadCtrl::GetTagToControlNodeValues(CString strTagID, CString strNode, int nNodeIndex)
{
	

	CString strRet = "";
	if (m_pMapCtrlGroup)
	{
		CCtrlGroup *pCtrlGroup = NULL;
		m_pMapCtrlGroup->Lookup(strTagID, pCtrlGroup);
		if (pCtrlGroup)
		{
			CString strID;
			strID.Format("%d", nNodeIndex + 1);
			CCtrl *pCtrl = NULL;
			pCtrlGroup->m_mapCtrl.Lookup(strID, pCtrl);
			if (pCtrl)
			{
				pCtrl->m_mapCtrlKeyVal.Lookup(strNode, strRet);
			}
			else
				AfxMessageBox("parse error:" + strTagID + "/" + strID + "/" + strNode);
		}
		else
			AfxMessageBox("parse error:" + strTagID);
	}

	return strRet;
}


BOOL CMapLoadCtrl::CheckCondiGubunState(CString strTagID)
{
	//## 단일 방생이 되지 않는 지표 
	BOOL bResult = FALSE;
	
	if (strTagID.Left(1) == "Y")
	{
		if ((strTagID.Compare("Y1_6") == 0) ||
			(strTagID.Compare("Y1_23") == 0) ||
			(strTagID.Compare("Y1_29") == 0) ||
			(strTagID.Compare("Y2_3") == 0))
			bResult = FALSE;
		else
			bResult = TRUE;
	}
	
	return bResult;
}

BOOL CMapLoadCtrl::SetDrewConditionMap(XMLTreeInfo *pstXMLTreeInfo, BOOL bModifyBtnView)
{
	BOOL bResult = FALSE;
	
	if ((pstXMLTreeInfo->strTag.IsEmpty() == TRUE) || (pstXMLTreeInfo->strMapFile.IsEmpty() == TRUE))
		return bResult;
	
	//m_stNowXMLInfo = *pstXMLTreeInfo;
	COPY_XMLTreeInfo(pstXMLTreeInfo, (&m_stNowXMLInfo));
	m_listControlInfo.RemoveAll();
	
	ControlInfo		stControlInfo;

	
	//## Condition Map Info All Delete ##
//	DestroyConditionMap();
	//동일한 태그 중복 방지
	int nCurCondCount = m_mapResourceID.GetCount();
	CString strKey;
	CUIntArray* parrlExistTest;
	if(nCurCondCount > 0)
	{
		if(m_mapResourceID.Lookup(pstXMLTreeInfo->strTag, (void*&)parrlExistTest) == TRUE)
			return bResult;
	}
	
	HINSTANCE hInstSave = AfxGetResourceHandle();
	AfxSetResourceHandle(theApp.m_hInstance);
	
	BOOL bVisible = pstXMLTreeInfo->bVisible;
	CString strType, strTerm;
	CString strNodeVal = GetTagToNodeData(pstXMLTreeInfo->strTag, "CONTROL_NUMBER");
	int nControlNum = atoi(strNodeVal.operator const char*());

	// 20120723 ssj - 서버자동주문 >>
	CString strMapName = GetTagToNodeData(pstXMLTreeInfo->strTag, "MAP_NAME");
	// 20120723 ssj - 서버자동주문 <<

	CString strMapType;
	strMapType = GetTagToNodeData(pstXMLTreeInfo->strTag, "MAP_TYPE");

	int nChkBtnID;
	CString strChkBtnID, strData;
	int nOffsetForChkBox = 0;
	CUIntArray* parrlResourceID = new CUIntArray;

	int nParentGrpID = -1;
	int nTopLineTemp = 0;
	if(m_nLastTopLine > 1)
		nTopLineTemp = m_nLastTopLine - 1;
	
	int nLines = nCurCondCount + m_nMultiLineCount;
	if (strMapType.CompareNoCase("-101") == 0)
	{
		m_bAddSysCtrl = TRUE;

		CRect rtTemp, rtCtrl(10, 2, 60, 2 + m_nOneLineHeight);
		m_stcUnitTitle.Create("평가단위",  WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE, rtCtrl, this, IDC_BTN_PERCENT);
		m_stcUnitTitle.SetFont(&m_fontDefault);		

		rtCtrl.OffsetRect(60, 0);
		rtCtrl.right = rtCtrl.left + 65;
		m_btnPercent.Create("%",  WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP, rtCtrl, this, IDC_BTN_PERCENT);
		m_btnPercent.SetCheck(BST_CHECKED);
		m_btnPercent.SetFont(&m_fontDefault);		

		rtCtrl.OffsetRect(65, 0);
		m_btnWon.Create("원",  WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, rtCtrl, this, IDC_BTN_PRICE);
		m_btnWon.SetFont(&m_fontDefault);
		if (IsDerivativesMap())
			m_btnWon.ShowWindow(SW_HIDE);

		//rtCtrl.OffsetRect(40, 0);
		CRect rtTck = rtCtrl;
		rtTck.right = rtTck.right + rtCtrl.Width();
		m_btnTick.Create("Tick",  WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, rtTck, this, IDC_BTN_TICK);
		m_btnTick.SetFont(&m_fontDefault);
		if (IsEquitiesMap())
			m_btnTick.ShowWindow(SW_HIDE);

		//
		rtCtrl = CRect(10, 2 + m_nOneLineHeight, 60, 2 + m_nOneLineHeight * 2);
		rtTemp = rtCtrl;
		rtTemp.DeflateRect(0, 2 + 2);
		m_stcBasePriceTitle.Create("기준단가", WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE, rtTemp, this, IDC_STC_PRICE_TITLE);
		m_stcBasePriceTitle.SetFont(&m_fontDefault);
		if (IsDerivativesMap())
			m_stcBasePriceTitle.ShowWindow(SW_HIDE);

		rtCtrl.OffsetRect(60, 0);
		rtCtrl.right = rtCtrl.left + 65;
		m_btnMatchPrice.Create("매입가",  WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP, rtCtrl, this, IDC_BTN_MATCH_PRICE);
		m_btnMatchPrice.SetCheck(BST_CHECKED);
		m_btnMatchPrice.SetFont(&m_fontDefault);
		if (IsDerivativesMap())
			m_btnMatchPrice.ShowWindow(SW_HIDE);

		rtCtrl.OffsetRect(65, 0);
		rtCtrl.right = rtCtrl.left + 90;
		m_btnUserPrice.Create("수정단가",  WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, rtCtrl, this, IDC_BTN_BASE_PRICE);
		m_btnUserPrice.SetFont(&m_fontDefault);
		if (m_pBase->m_clOrdMinSet.m_strMMType == SVRORD_MMTYPE_BUY)
			m_btnUserPrice.ShowWindow(SW_HIDE);
		if (IsDerivativesMap())
			m_btnUserPrice.ShowWindow(SW_HIDE);
		
		rtCtrl.OffsetRect(90, 0);
		rtTemp = rtCtrl;
		rtTemp.DeflateRect(0, 2);
		m_edtUserPrice.Create(WS_CHILD | WS_VISIBLE | ES_RIGHT, rtTemp, this, IDC_EDT_PRICE);
		m_edtUserPrice.ShowWindow(SW_HIDE);
		m_edtUserPrice.SetFont(&m_fontDefault);
		m_edtUserPrice.SetEditRange(0, 999999999);
		if (m_nMapMode == MODE_EQUITIES)
			m_edtUserPrice.SetPlaces(9, 0);
		else
			m_edtUserPrice.SetPlaces(9, 2);

		if (m_pBase->m_clOrdMinSet.m_strMMType == SVRORD_MMTYPE_BUY)
			m_edtUserPrice.ShowWindow(SW_HIDE);
		
		rtCtrl.OffsetRect(90 + 2, 0);
		rtTemp = rtCtrl;
		rtTemp.DeflateRect(0, 2 + 2);
		m_stcSuffix.Create("원", WS_CHILD | WS_VISIBLE, rtTemp, this, IDC_STC_SUFFIX);
		m_stcSuffix.ShowWindow(SW_HIDE);
		m_stcSuffix.SetFont(&m_fontDefault);
		if (m_pBase->m_clOrdMinSet.m_strMMType == SVRORD_MMTYPE_BUY)
			m_stcSuffix.ShowWindow(SW_HIDE);
	}

	if (m_bAddSysCtrl)
	{
		if (IsEquitiesMap())
		{
			nTopLineTemp = nTopLineTemp + 2;
			nLines = nLines + 2;
		}
		else
		{
			nTopLineTemp = nTopLineTemp + 1;
			nLines = nLines + 1;
		}
	}
	CString strOldTopLine;
	for (int i = 0; i <= nControlNum - 1; i++) 
	{
		CWnd *pWndCtrl = NULL;
		CString strExtraInfo = "";

		strType = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "TYPE", i);
		
		int nFlag = 0;
		if (pstXMLTreeInfo->nGubun == 2) //# 순차검색
		{
			strTerm = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "PACKET_ID", i);
			if (strTerm == "TERM")
				nFlag = 1;
		}
		
		CString strTemp, strID;
		strTemp = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "ID", i);
		strID = strTemp;

		int nResourceID = m_nLastResourceID++;		
		
		int nLeft, nTop, nRight, nBottom;
		CString Left = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "LEFT", i);
		CString strTop_Line = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "TOP_LINE", i);
		CString strWidth = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "WIDTH", i);
		CString strHeight = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "HEIGHT", i);
	
		//조건 맵 별로 라인 위치 변경하도록 수정 
		//20110817 임시로 멀티라인 처리(조건사이에 들어갈경우 추가 작업 필요) SJ_KIM
		if(m_nLastTopLine < atoi(strTop_Line))
			m_nLastTopLine = atoi(strTop_Line);

		if (strOldTopLine.GetLength() <= 0)
			strOldTopLine = strTop_Line;

		if (strOldTopLine != strTop_Line)
		{
			strOldTopLine = strTop_Line;
			nLines++;
			m_nMultiLineCount++;
		}
		// 20120723 ssj - 서버자동주문 <<

		nLeft = atoi(Left.operator const char*());
		nTop = nLines * m_nOneLineHeight + 2;
		nRight = atoi(strWidth.operator const char*()) + nLeft;
		nBottom = nTop + atoi(strHeight.operator const char*());

		CRect reControl(nLeft, nTop, nRight, nBottom);


		//체크박스 선택 모드(컨트롤 가장 앞에 체크박스 배치)

		if(m_bChkMode && i == 0)
		{
			// 20120723 ssj - 서버자동주문 >>
//			if (strMapType.CompareNoCase("-901") == 0 || strMapType.CompareNoCase("-902") == 0)
//			{
//				nChkBtnID = m_pBase->GetChkCtrlIDAndPlusCnt();
//			}
//			else
			// 20120723 ssj - 서버자동주문 <<
			{
				CRect reChkBtn = reControl;
				reChkBtn.right = reChkBtn.left + 20;

				m_pBtnChk = new CButton;
				nChkBtnID = m_pBase->GetChkCtrlIDAndPlusCnt();
				strChkBtnID.Format("%d", nChkBtnID);
				m_pBtnChk->Create(_T(""), WS_CHILD | WS_VISIBLE | BS_CHECKBOX | SS_CENTERIMAGE | BS_AUTOCHECKBOX,
					reChkBtn, this, nChkBtnID);
				m_pBtnChk->SetFont(&m_fontDefault);

				//TraceLog("m_pBtnChk ID: %d [MAP_NAME: %s, ID: %s]\n", nChkBtnID, strMapName, strTemp);

				//체크박스 ID정보 저장
				AddTagIDForMapType(strMapType, "", nChkBtnID);		

				nOffsetForChkBox = 22;
			}
		}
		reControl.left += nOffsetForChkBox;
		reControl.right += nOffsetForChkBox;		

//이벤트 처리 해야할 컨트롤들
		CString strEvent = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "EVENTUSE", i);
		if(atoi(strEvent) == 1)
		{
			//이벤트받을 ID로 대체
			nResourceID = m_pBase->GetCmbCtrlIDAndPlusCnt();
			AddCtrlIDForMapType(strMapType, nResourceID);
		}
		//이벤트 연결된 컨트롤들
		CString strLink = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "EVENT_LINK", i);
		CString strPoint = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "NPOINT", i);
		if(atoi(strLink) == 1)
			AddLinkEventCtrlIDForMapType(strMapType, nResourceID, atoi(strPoint));


		parrlResourceID->Add(nResourceID);

		if (strType.Compare(NEWS_CONTROL_TYPE) == 0)
			strTemp.Format("%s,%d", "Static", nResourceID);
		else 
			strTemp.Format("%s,%d", strType, nResourceID);
		m_saDelCtrlData.Add(strTemp);

		//>>[0000260] 손실제한률, 목표이익률 수익률이 자동으로 셋팅 SJ_KIM(20110720)
		if(strMapType.CompareNoCase(_T("-101")) == 0)
		{
			CRect reTemp;
			reTemp = reControl;			

			if(i == nControlNum - 1)
			{
				int nPoint = 0;
				
				if (m_nMapMode == MODE_DERIVATIVES)
					nPoint = 2;
				reTemp.left = reTemp.right + 49;
				reTemp.right = reTemp.left + 86;

				m_editpreventLossRate.Create(reTemp, this, IDE_EARNINGRATE, 0xFFFFFF, 9, nPoint, FALSE, FALSE);
				m_editpreventLossRate.SetFont(&m_fontDefault);
				m_editpreventLossRate.SetDefReturn(TRUE);

				reTemp.left = reTemp.right + 2;
				reTemp.right = reTemp.left + 80;
				m_btnpreventLossRate.Create(_T("손실률 계산"), WS_CHILD | WS_VISIBLE /*| BS_OWNERDRAW*/, 
					reTemp, this, IDB_PREVENTLOSSRATE);	
				m_btnpreventLossRate.SetFont(&m_fontDefault);
				m_btnpreventLossRate.SetWindowText("손실률 계산");

				m_nIDPreventLossRate = nResourceID - 1;//손익률 Edit 리소스 ID
			}
		}
		else if(strMapType.CompareNoCase(_T("-102")) == 0)
		{
			if(i == nControlNum - 1)
			{
				CRect reTemp;
				reTemp = reControl;	

				int nPoint = 0;
				
				if (m_nMapMode == MODE_DERIVATIVES)
					nPoint = 2;
				reTemp.left = reTemp.right + 49;
				reTemp.right = reTemp.left + 86;

				m_editEarningRate.Create(reTemp, this, IDE_PREVENTLOSSRATE, 0xFFFFFF, 9, nPoint, FALSE, FALSE);
				m_editEarningRate.SetFont(&m_fontDefault);
				m_editEarningRate.SetDefReturn(TRUE);

				reTemp.left = reTemp.right + 2;
				reTemp.right = reTemp.left + 80;
				m_btnEarningRate.Create(_T("이익률 계산"), WS_CHILD | WS_VISIBLE /*| BS_OWNERDRAW*/, 
					reTemp, this, IDB_EARNINGRATE);	
				m_btnEarningRate.SetFont(&m_fontDefault);
				
				m_btnEarningRate.SetWindowText("이익률 계산");

				m_nIDEarningRate = nResourceID - 1;//이익률 Edit 리소스 ID
			}
		}
		//<<[0000260] 손실제한률, 목표이익률 수익률이 자동으로 셋팅 SJ_KIM(20110720)
//////////////	
		
		if (strType.Compare("ExStatic") == 0) 
		{
			CStatic *p = new CStatic;

			p->Create("",
				WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE,// | SS_WHITERECT,
				reControl,
				this,
				nResourceID);
			p->SetFont(&m_fontDefault);

			if (strMapType == "-201")
				m_pStcStkCodeName = p;
			

			pWndCtrl = p;
		}

		else if (strType.Compare("Static") == 0) 
		{
			reControl.top += 3;
			CString strCaption = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "STATIC_CAPTION", i);
			
			m_pStatic = new CStatic;
			int nFindPos = strCaption.Find("&");
			if (nFindPos != -1)
				strCaption.Replace("&", " && ");
			
			m_pStatic->Create((LPCTSTR)strCaption,
				WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE,// | SS_WHITERECT,
				reControl,
				this,
				nResourceID);
			GetDlgItem(nResourceID)->SetFont(&m_fontDefault);

			// 20120723 ssj - 서버자동주문 >>
			if (strMapType == "-101" || strMapType == "-102" || strMapType == "-105" || strMapType == "-107")
			{
				if (strCaption.Find("%") >= 0)
					m_arStatics.Add(m_pStatic);
				else if (strCaption == "손실제한률")
				{
					m_pStaticLossTitle = m_pStatic;
				}
				else if (strCaption == "목표이익률")
				{
					m_pStaticProfitTile = m_pStatic;
				}
			}

			pWndCtrl = m_pStatic;
			// 20120723 ssj - 서버자동주문 <<
		}
		else if (strType.Compare(NEWS_CONTROL_TYPE) == 0) 
		{
			reControl.top += 3;
			
			m_pStatic = new CStatic;
		
			m_pStatic->Create((LPCTSTR)pstXMLTreeInfo->strName,
				WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE,
				reControl,
				this,
				nResourceID);
			GetDlgItem(nResourceID)->SetFont(&m_fontDefault);

			pWndCtrl = m_pStatic;
		}
		else if(strType.Compare("TimeCtrl") == 0)
		{			
			m_pDateTime = new CDateTimeCtrl;
			m_pDateTime->Create(WS_CHILD | WS_VISIBLE | DTS_TIMEFORMAT, reControl, this, nResourceID);
			GetDlgItem(nResourceID)->SetFont(&m_fontDefault);

			CString strFormat = _T("HH:mm:ss");
			m_pDateTime->SetFormat(strFormat);

			stControlInfo.nResourceID = nResourceID;
			stControlInfo.strControlType = "EDIT";
			m_listControlInfo.AddTail(stControlInfo);

			pWndCtrl = m_pDateTime;
		}
		else if (strType.Compare("Edit") == 0) 
		{
			CString strEditLength = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "EDIT_LENGTH", i);
			
			int nFind = strEditLength.Find('.', 0);
			int nIntegerLength, nRealLength;
			if (nFind > -1)
			{
				nIntegerLength = atoi(strEditLength.Left(nFind));
				nRealLength = atoi(strEditLength.Right(strEditLength.GetLength() - (nFind + 1))); 
			}
			else
			{
				nIntegerLength = atoi(strEditLength);
				nRealLength = 0;
			}
			//부호사용여부
			BOOL bMinus = TRUE;
			CString strMinus = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "EDIT_NOMINUS", i);
			if(strMinus.CompareNoCase("1") == 0)
				bMinus = FALSE;
			
			m_pEdit = new CTEditCtrlWnd;
			
			//# 2005.04.12 => User Patten!
			BOOL bEnable = FALSE;
			if ((pstXMLTreeInfo->nItemType == (int)TREE_SELECT_TYPE_USERPATTEN) && 
				(GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "PACKET_ID", i) == "CODE"))
				bEnable = TRUE;
			
			m_pEdit->Create(reControl, this, nResourceID, 0xFFFFFF, nIntegerLength, nRealLength, bEnable, bMinus);
			GetDlgItem(nResourceID)->SetFont(&m_fontDefault);

			CString strShareGroupNum = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "SHARE_GRP", i);
			if(!strShareGroupNum.IsEmpty())
			{
				CString Group = strShareGroupNum.Left(1);
				CString GNum = strShareGroupNum.Mid(1);

				if(atoi(GNum) == 0)
					nParentGrpID = nResourceID;
				else
				{
					CTEditCtrlWnd* pEditTemp = (CTEditCtrlWnd*)GetDlgItem(nParentGrpID);
					if(!pEditTemp)
						continue;

					DWORD dw = (DWORD)m_pEdit->GetSafeHwnd();
					pEditTemp->SetShareGroup((DWORD)m_pEdit->GetSafeHwnd());
					m_pEdit->EnableWindow(FALSE);		
				}
			}
			
			if(GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "PACKET_ID", i) == "CODE")
				m_pEdit->IngnoreComma(TRUE);

			if(pstXMLTreeInfo->strTag == "D1_30" || pstXMLTreeInfo->strTag == "D1_31" ||
				pstXMLTreeInfo->strTag == "D7_3" || pstXMLTreeInfo->strTag == "D7_4" )

			{
				if(GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "PACKET_ID", i) == "C1")
					m_pEdit->IngnoreComma(TRUE);
			}

			//## Tab Move Info
			stControlInfo.nResourceID = nResourceID;
			stControlInfo.strControlType = "EDIT";
			m_listControlInfo.AddTail(stControlInfo);

			if(atoi(strLink) == 1)
				ChangeCmbMessage(0, strMapType, nResourceID);

			// 20120723 ssj - 서버자동주문 >>
			if (strMapType == "-101" || strMapType == "-102" || strMapType == "-105" || strMapType == "-107")
			{
				m_arEdits.Add(m_pEdit);
			}

			if (strMapType == "-307" && strID == "3")
				m_pEditSync2 = m_pEdit;

			pWndCtrl = m_pEdit;
			// 20120723 ssj - 서버자동주문 <<
		}
		else if (strType.Compare("ComboBox") == 0) 
		{
			reControl.bottom += 100;

			CString strImagePath;
			GetDir_DrfnRoot(strImagePath);
			strImagePath += "\\Image";

			//DrCombo로 교체

			// 20120723 ssj - 서버자동주문 >>
			//.m_pComboBox = new CDrCombo;
			m_pComboBox = new CComboBox;			
			

			m_pComboBox->Create(WS_CHILD | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST,
				reControl, this, nResourceID);


			GetDlgItem(nResourceID)->SetFont(&m_fontDefault);
			
			//## Tab Move Info
			stControlInfo.nResourceID = nResourceID;
			stControlInfo.strControlType = "COMBOBOX";
			m_listControlInfo.AddTail(stControlInfo);
			
			CString strComboPacketID = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "PACKET_ID", i);
			CString strComboLoadType = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "COMBO_LOAD_TYPE", i);
			if (atoi(strComboLoadType) == 1) 
			{
				CString strComboLoadData = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "COMBO_LOAD_DATA", i);
				
				int nItemFileType = -1;
				CStringArray saName;
				CWnd* pParent = GetParent();
				CWnd* pBase = pParent->GetParent();
				CWnd* pViewWnd = pBase->GetParent();
				if(!pViewWnd)
					return FALSE;

				if(strComboLoadData.CompareNoCase("@주식") == 0)
				{
					m_nResourceJCode = nResourceID;
					reControl.bottom -= 100;
					m_rtJCode = reControl;
					reControl.bottom -= 100;
					m_pComboBox->ShowWindow(SW_HIDE);		
					// 20120723 ssj - 서버자동주문 >>
					m_ctlStkCodeInput.ShowWindow(SW_SHOW);
					strExtraInfo = strComboLoadData;
					// 20120723 ssj - 서버자동주문 <<
				}
				

				
				if (nItemFileType != -1)
				{
					TRACE("\n [ Map Load Combo Info]");
					for (int nIndex = 0; nIndex < saName.GetSize(); nIndex++)
					{
						CString strTemp;
						strTemp = saName.GetAt(nIndex);
						strTemp.TrimRight();
						
						CString strTrim;
						for (int nPos = 0; nPos < strTemp.GetLength(); nPos++)
						{
							if (strTemp[nPos] != ' ')
								strTrim += (CString)strTemp[nPos];
						}
						m_pComboBox->AddString(strTrim);
					}
				}
			}
			else
			{
				CString strComboItem = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "COMBO_ITEM", i);
				int nFindPos;
				do
				{
					nFindPos = strComboItem.Find('/');
					if (nFindPos < 0) 
					{
						m_pComboBox->AddString((LPCTSTR)strComboItem);
						break;
					}
					m_pComboBox->AddString((LPCTSTR)strComboItem.Mid(0, nFindPos));
					strComboItem = strComboItem.Mid(nFindPos + 1, strComboItem.GetLength() - nFindPos);
				}while(1);
			}	

			CString strDisable = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "DISABLE", i);
			if (strMapType.CompareNoCase("-307") == 0 && strDisable == "1")
				m_pComboBox->EnableWindow(FALSE);

			if (strMapType == "-301" && strID == "1")
				m_pCmbSync1 = m_pComboBox;
			else if (strMapType == "-307" && strID == "1")
				m_pCmbSync2 = m_pComboBox;

			if ((strMapType == "-302" && strID == "3") || (strMapType == "-305" && strID == "4"))
			{
				CComboBoxExtraInfo *p = new CComboBoxExtraInfo;
				p->m_strMapType = strMapType;
				p->m_unResourceID = nResourceID;
				p->m_strComboItem = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "COMBO_ITEM", i);;
				p->m_strComboIndex = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "COMBO_INDEX", i);;
				p->m_strComboItemExtra = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "COMBO_ITEM_ELW", i);;
				p->m_strComboIndexExtra = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "COMBO_INDEX_ELW", i);;

				m_arrCmbExtraInfo.Add(p);
			}

			pWndCtrl = m_pComboBox;
		}

		else if (strType.Compare("Radio") == 0)
		{
			CString strCaption = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "STATIC_CAPTION", i);
			if (strCaption.Find("&") >= 0)
				strCaption.Replace("&", " && ");
			
			CString strGroup = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "GROUP", i);
			UINT nStyle = WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON;
			if (strGroup == "1")
				nStyle = nStyle | WS_GROUP;

			m_pRadioBtn = new CButton;
			reControl.DeflateRect(0, 1); // 그룹박스를 넣는 경우가 있으니깐 줄여주자
			reControl.OffsetRect(0, 2); // 스태틱이 3픽셀 아래로 그리고 있으니 맞춰준다
			m_pRadioBtn->Create((LPCTSTR)strCaption,
				nStyle,
				reControl,
				this,
				nResourceID);
			GetDlgItem(nResourceID)->SetFont(&m_fontDefault);

			pWndCtrl = m_pRadioBtn;
		}

		AddToAllCtrlList(strMapType, strID, strType, nResourceID, pWndCtrl, strExtraInfo);

	}

	m_mapResourceID.SetAt(pstXMLTreeInfo->strTag, (void*)parrlResourceID);

	AfxSetResourceHandle(hInstSave);

	m_pStatic = NULL;
	m_pEdit = NULL;
	m_pComboBox = NULL;
	m_pBtnChk = NULL;
	m_pDateTime = NULL;
	
	m_pRadioBtn = NULL;

	//## Check Button Create! ##
//	CreateNotCheckBtn(pstXMLTreeInfo->nNotUser);

	//## 연속/단일 Check Button Create! ##
	BOOL bEnable = TRUE;
	if ((pstXMLTreeInfo->strTag == "Z2_55") ||		//# 이평간 비교(연속)
		(pstXMLTreeInfo->strTag == "Z2_56") ||	//# 이평대비 가격등락율(연속) 
		(pstXMLTreeInfo->strTag == "Z2_57"))	//# 가격/이평비교(연속)
			bEnable = FALSE;

	Invalidate();


	CRect rect;
	GetClientRect(&rect);
	SendMessage(WM_SIZE, (WPARAM)SIZE_RESTORED, MAKELPARAM(rect.Width(), rect.Height())); 	
	
	bResult = TRUE;
	return bResult;
}


void CMapLoadCtrl::SetDefultToMapValues(XMLTreeInfo *pstXMLTreeInfo, BOOL bOtherBtnSet)
{
	//## Draw Map Set Defult ##
	if(pstXMLTreeInfo->strTag.IsEmpty())
		return;
	

	BOOL bChartValSet = FALSE;
	CStringArray saDefultData;
	if (pstXMLTreeInfo->nChartValSet == 1)
	{
		if (GetChartDefultData(pstXMLTreeInfo->strName, saDefultData) == TRUE)
		{
			SetChartDefultToMapValues(pstXMLTreeInfo->strTag, &saDefultData);
			bChartValSet = TRUE;
		}
		saDefultData.RemoveAll();
	}
	else if (pstXMLTreeInfo->nChartValSet == 2)		//# User Patten!
	{
		if (GetUserPattenData(pstXMLTreeInfo->strName, saDefultData) == TRUE)
		{
			SetUserPattenDefultToMapValues(pstXMLTreeInfo->strTag, &saDefultData);
			bChartValSet = TRUE;
		}
		saDefultData.RemoveAll();
	}
	
	if (bChartValSet == FALSE)
	{
		CString strControlCnt = GetTagToNodeData(pstXMLTreeInfo->strTag, "CONTROL_NUMBER");
		int nControlCnt = atoi(strControlCnt.operator const char*());
		
		CString strType;
		CUIntArray* plarrResourceID = NULL;


		m_mapResourceID.Lookup(pstXMLTreeInfo->strTag, (void*&)plarrResourceID);
		if(!plarrResourceID)
			return;

		for (int i = 0; i <= nControlCnt - 1; i++) 
		{
			strType = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "TYPE", i);			
			
			int nResourceID = plarrResourceID->GetAt(i);			
			
			CString strTemp;
			CString strComma;
			if (strType.Compare("Edit") == 0) 
			{
				CTEditCtrlWnd *pEditWnd = (CTEditCtrlWnd*)GetDlgItem(nResourceID);
				if (pstXMLTreeInfo->strTag == "P1")
				{
					strTemp = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "PACKET_ID", i);
					
					CTime ctrlTime(CTime::GetCurrentTime());
					if (strTemp == "C1")
					{
						ctrlTime -= CTimeSpan(50, 0, 0, 0);
						strTemp = ctrlTime.Format("%Y%m%d");
					}
					else if (strTemp == "C3")
						strTemp = ctrlTime.Format("%Y%m%d");
					else
						strTemp = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "DEFAULT_VALUE", i);
				}
				else
					strTemp = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "DEFAULT_VALUE", i);
				
				strComma = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "EDIT_COMMA", i);

				if(strComma.CompareNoCase("NO") == 0)
					pEditWnd->IngnoreComma(TRUE);

				pEditWnd->InsertComma(strTemp);			
				pEditWnd->SetWindowText(strTemp);
				pEditWnd->Invalidate();
			}
			else if (strType.Compare("TimeCtrl") == 0)
			{
				CDateTimeCtrl *pTimeCtrl = (CDateTimeCtrl*)GetDlgItem(nResourceID);				
				strTemp = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "DEFAULT_VALUE", i);

				strTemp.Remove(':');	
				
				CTime timeCur = CTime::GetCurrentTime();						
				CTime time(timeCur.GetYear(), timeCur.GetMonth(), timeCur.GetDay(), atoi(strTemp.Left(2)), atoi(strTemp.Mid(2, 2)), atoi(strTemp.Mid(4, 3)));
			
				pTimeCtrl->SetTime(&time);
				pTimeCtrl->Invalidate();
			}
			else if (strType.Compare("ComboBox") == 0) 
			{
				CComboBox *pComboBoxWnd = (CComboBox*)GetDlgItem(nResourceID);
				
				int nComboSel;
				CString strDefaultValues = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "DEFAULT_VALUE", i);
				if (strDefaultValues.IsEmpty() == TRUE)
					nComboSel = 0;
				else
				{
					//# Defult Val => Combo Index Val
					CString	strComboVal = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "COMBO_INDEX", i);

					strComboVal += "/";
					
					BOOL bDefultFalg = FALSE;
					int nFindPos, nSelecetedIndex;
					nFindPos = 0;
					nSelecetedIndex = 0;
					while (nFindPos > -1)
					{
						nFindPos = strComboVal.Find('/');
						if (strDefaultValues == strComboVal.Mid(0, nFindPos))
						{
							bDefultFalg = TRUE;
							break;
						}
						
						strComboVal = strComboVal.Mid(nFindPos + 1, strComboVal.GetLength() - nFindPos);
						nSelecetedIndex++;
					}
					
					if (bDefultFalg == TRUE)
						nComboSel = nSelecetedIndex;
					else
						nComboSel = 0;
				}
				
				pComboBoxWnd->SetCurSel(nComboSel);
				pComboBoxWnd->Invalidate();
			}

			else if (strType.Compare("Radio") == 0)
			{
				CString strDefaultValues = GetTagToControlNodeValues(pstXMLTreeInfo->strTag, "DEFAULT_VALUE", i);
				CButton *pRadio = (CButton*)GetDlgItem(nResourceID);
				if (pRadio)
				{
					if (atol(strDefaultValues))
						pRadio->SetCheck(BST_CHECKED);
				}
			}
		}
	}
	
	if (bOtherBtnSet == TRUE)
	{
		SetNotCheckValues(pstXMLTreeInfo->nNotDefVal);
		SetGubunCheckValues(pstXMLTreeInfo->nGubunDefVal);
	}
}


void CMapLoadCtrl::SetChartDefultToMapValues(CString strTagID, 
											 CStringArray* psaDefultData)
{
	int nChartDefultValIndex = 0;
	int nChartDefultValCnt = psaDefultData->GetSize();
	
	//## Draw Map Set Defult ##
	if(strTagID.IsEmpty())
		return;
	
	CString strControlCnt = GetTagToNodeData(strTagID, "CONTROL_NUMBER");
	int nControlCnt = atoi(strControlCnt.operator const char*());
	
	CUIntArray* plarrResourceID;
	CString strType;
	m_mapResourceID.Lookup(strTagID, (void*&)plarrResourceID);
	if(!plarrResourceID)
		return;

	for (int i = 0; i <= nControlCnt - 1; i++) 
	{
 		strType = GetTagToControlNodeValues(strTagID, "TYPE", i);		

		int nResourceID = plarrResourceID->GetAt(i);
		
		CString strTemp;
		if (strType.Compare("Edit") == 0) 
		{
			CTEditCtrlWnd *pEditWnd = (CTEditCtrlWnd*)GetDlgItem(nResourceID);
			
			if (nChartDefultValCnt == nChartDefultValIndex)
				strTemp = GetTagToControlNodeValues(strTagID, "DEFAULT_VALUE", i);
			else
			{
				strTemp = psaDefultData->GetAt(nChartDefultValIndex);
				nChartDefultValIndex++;
			}
			
			
			pEditWnd->SetWindowText((LPCTSTR)strTemp);
			pEditWnd->Invalidate();
		}
		else if (strType.Compare("ComboBox") == 0) 
		{
			CComboBox *pComboBoxWnd = (CComboBox*)GetDlgItem(nResourceID);
			
			if (pComboBoxWnd != NULL)
				pComboBoxWnd->ResetContent();
			
			CString strComboItem = GetTagToControlNodeValues(strTagID, "ITEM_STRING", i);
			CString strDefaultIndex = GetTagToControlNodeValues(strTagID, "DEFAULT_VALUE", i);
			int nFindPos;
			do
			{
				nFindPos = strComboItem.Find('/');
				if (nFindPos < 0) 
				{
					pComboBoxWnd->AddString((LPCTSTR)strComboItem);
					break;
				}
				CString strTemp;
				strTemp = strComboItem.Mid(0, nFindPos);
				
				pComboBoxWnd->AddString((LPCTSTR)strComboItem.Mid(0, nFindPos));
				strComboItem = strComboItem.Mid(nFindPos + 1, strComboItem.GetLength() - nFindPos);
			} while(1);
			
			int nComboSel;
			if (strDefaultIndex.IsEmpty())
				nComboSel = 0;
			else
				nComboSel = atoi(strDefaultIndex.operator const char*());
			pComboBoxWnd->SetCurSel(nComboSel);
			pComboBoxWnd->Invalidate();
		}
	}
}


BOOL CMapLoadCtrl::GetChartDefultData(CString strConditionName,
									  CStringArray &saDefultData)
{
	BOOL bResult = FALSE;
	
	
	return bResult;
}


void CMapLoadCtrl::SetUserPattenDefultToMapValues(CString strTagID, 
												  CStringArray* psaDefultData)
{
	int nChartDefultValIndex = 1;
	int nChartDefultValCnt = psaDefultData->GetSize();
	
	//## Draw Map Set Defult ##
	if(strTagID.IsEmpty())
		return;
	
	CString strControlCnt = GetTagToNodeData(strTagID, "CONTROL_NUMBER");
	int nControlCnt = atoi(strControlCnt.operator const char*());
	

	CUIntArray* plarrResourceID;
	CString strType;
	m_mapResourceID.Lookup(strTagID, (void*&)plarrResourceID);
	if(!plarrResourceID)
		return;
	for (int i = 0; i <= nControlCnt - 1; i++) 
	{
		strType = GetTagToControlNodeValues(strTagID, "TYPE", i);		

		int nResourceID = plarrResourceID->GetAt(i);
		
		CString strTemp;
		if (strType.Compare("Edit") == 0) 
		{
			CString strEditPacketID;
			CTEditCtrlWnd *pEditWnd = (CTEditCtrlWnd*)GetDlgItem(nResourceID);
			
			if (nChartDefultValCnt < nChartDefultValIndex)
				strTemp = GetTagToControlNodeValues(strTagID, "DEFAULT_VALUE", i);
			else
			{
				strEditPacketID = GetTagToControlNodeValues(strTagID, "PACKET_ID", i);
				if (strEditPacketID.Left(1) == "C")
				{
					strTemp = psaDefultData->GetAt(nChartDefultValIndex);
					
					if (strTemp.IsEmpty() == TRUE)
						strTemp = GetTagToControlNodeValues(strTagID, "DEFAULT_VALUE", i);
					
					nChartDefultValIndex++;
				}
				else
					strTemp = GetTagToControlNodeValues(strTagID, "DEFAULT_VALUE", i);
			}
			
			pEditWnd->SetWindowText((LPCTSTR)strTemp);
			pEditWnd->Invalidate();
		}
		else if (strType.Compare("ComboBox") == 0) 
		{
			CComboBox *pComboBoxWnd = (CComboBox*)GetDlgItem(nResourceID);
			
			if (pComboBoxWnd != NULL)
				pComboBoxWnd->ResetContent();
			
			CString strComboItem = GetTagToControlNodeValues(strTagID, "ITEM_STRING", i);
			CString strDefaultIndex = GetTagToControlNodeValues(strTagID, "DEFAULT_VALUE", i);
			int nFindPos;
			do
			{
				nFindPos = strComboItem.Find('/');
				if (nFindPos < 0) 
				{
					pComboBoxWnd->AddString((LPCTSTR)strComboItem);
					break;
				}
				CString strTemp;
				strTemp = strComboItem.Mid(0, nFindPos);
				
				pComboBoxWnd->AddString((LPCTSTR)strComboItem.Mid(0, nFindPos));
				strComboItem = strComboItem.Mid(nFindPos + 1, strComboItem.GetLength() - nFindPos);
			} while(1);
			
			int nComboSel;
			if (strDefaultIndex.IsEmpty())
				nComboSel = 0;
			else
				nComboSel = atoi(strDefaultIndex.operator const char*());
			pComboBoxWnd->SetCurSel(nComboSel);
			pComboBoxWnd->Invalidate();
		}
	}
}


BOOL CMapLoadCtrl::GetUserPattenData(CString strName, CStringArray &saUserPattenInfo)
{
	typedef struct tagUserPattenInfo
	{
		CString strName;
		CString strCode;
		int		nPattenType;
		int		nTerm;
		int		nCycle;
		CString strStartDate;
		CString strStartTime;
		CString strEndDate;
		CString strEndTime;
	} UserPattenInfo;
	
	
	BOOL bResult = TRUE;
	
	
	return bResult;
}


void CMapLoadCtrl::DestroyConditionMap()
{
	int nDivisionPos;
	CString strDelData;
	
	CString strCtrlType;
	int nResourceID;
	
	int nDelCnt = m_saDelCtrlData.GetSize();
	for (int i = 0; i < nDelCnt; i++)
	{
		strDelData = m_saDelCtrlData.GetAt(i);
		nDivisionPos = strDelData.Find(",");
		
		nResourceID = atoi(strDelData.Mid(nDivisionPos + 1, strDelData.GetLength() - nDivisionPos-1).operator const char*());
		strCtrlType = strDelData.Left(nDivisionPos);
		
		if (strCtrlType.Compare("Static") == 0) 
		{
			CStatic *pStaticWnd = (CStatic*)GetDlgItem(nResourceID);
			if (pStaticWnd)
			{
				pStaticWnd->DestroyWindow();
				delete pStaticWnd;
			}
		}
		else if (strCtrlType.Compare("TimeCtrl") == 0)
		{
			CDateTimeCtrl *pDateTimeWnd = (CDateTimeCtrl*)GetDlgItem(nResourceID);
			if (pDateTimeWnd)
			{
				pDateTimeWnd->DestroyWindow();
				delete pDateTimeWnd;
			}
		}
		else if (strCtrlType.Compare("Edit") == 0) 
		{
			CTEditCtrlWnd *pEditWnd = (CTEditCtrlWnd*)GetDlgItem(nResourceID);
			if (pEditWnd)
			{
				pEditWnd->DestroyWindow();
				delete pEditWnd;
			}
		}
		else if (strCtrlType.Compare("ComboBox") == 0) 
		{			
			CComboBox *pComboBoxWnd = (CComboBox*)GetDlgItem(nResourceID);			
			if (pComboBoxWnd)
			{
				pComboBoxWnd->DestroyWindow();
				delete pComboBoxWnd;
			}
		}
	}
	
	m_saDelCtrlData.RemoveAll();
	m_nLastResourceID = 1;
}

BOOL CMapLoadCtrl::CheckConditionMapDrewState()
{
	BOOL bResult = FALSE;
	
	int nCount = m_saDelCtrlData.GetSize();
	
	if (nCount > 0)
		bResult = TRUE;
	
	return bResult;
}

void CMapLoadCtrl::CreateConditionTitleStatic()
{
	if (CheckConditionTitleStaticDrawState() == TRUE)
	{
		m_pConditionTitleStatic->BringWindowToTop();
		return;
	}
	
	CRect reClient, reStatic;
	int nHeight = 15;
	GetClientRect(&reClient);
	
	reStatic.left = reClient.left + POSITION_X_TITLE;
	reStatic.right = reStatic.left + (int)CONDITIONTITLE_WIDTH;
	reStatic.top = reClient.top + 5;
	reStatic.bottom = reStatic.top + nHeight;
	
	HINSTANCE hInstSave = AfxGetResourceHandle();
	AfxSetResourceHandle(theApp.m_hInstance);
	
	m_pConditionTitleStatic = new CStatic;
	m_pConditionTitleStatic->Create(_T("조건명"), 
		WS_CHILD | WS_VISIBLE,// | WS_BORDER, 
		reStatic,
		this, 
		IDC_STITIC_CONDITIONTITLE);
	m_pConditionTitleStatic->SetFont(&m_fontBold);
	
	AfxSetResourceHandle(hInstSave);
}

void CMapLoadCtrl::DestroyConditionTitleStatic()
{
	CStatic *pConditionTitleStatic = (CStatic*)GetDlgItem(IDC_STITIC_CONDITIONTITLE);
	
	if (pConditionTitleStatic)
	{
		pConditionTitleStatic->DestroyWindow();
		delete pConditionTitleStatic;
	}
}

void CMapLoadCtrl::DestroyChkbtnCtrl()
{
	int nIndex = INDEX_START_CHKBOX;
	for(nIndex; nIndex < m_pBase->GetChkCtrlID(); nIndex++)
	{
		CButton* pBtnChk = (CButton*)GetDlgItem(nIndex);
		if(pBtnChk)
		{
			pBtnChk->DestroyWindow();
			delete pBtnChk;
			pBtnChk = NULL;
		}
	}
	m_pBase->ResetChkCtrlID();
	m_pBase->ResetCmbCtrlID();
}



void CMapLoadCtrl::SetConditionTitleText(CString strConditionTitle)
{
	CStatic *pConditionTitleStatic = (CStatic*)GetDlgItem(IDC_STITIC_CONDITIONTITLE);
	
	if (pConditionTitleStatic)
	{
		int nFindPos = strConditionTitle.Find("&");
		if (nFindPos != -1)
			strConditionTitle.Replace("&", " && ");
		
		pConditionTitleStatic->SetWindowText(strConditionTitle);
		pConditionTitleStatic->Invalidate();
	}
}

BOOL CMapLoadCtrl::CheckConditionTitleStaticDrawState()
{
	BOOL bResult = FALSE;
	
	CStatic *pConditionTitleStatic = (CStatic*)GetDlgItem(IDC_STITIC_CONDITIONTITLE);
	if (pConditionTitleStatic)
		bResult = TRUE;
	
	return bResult;
}


void CMapLoadCtrl::CreateGubunCheckBtn(int nGubun, BOOL bEnable /*= TRUE*/)
{
	//## Birth Check Button Create ##
	if (nGubun == 1)
	{
		if (CheckGubunCheckBtnDrawState() == TRUE)
		{
			m_pGubunCheckBtn->BringWindowToTop();
			m_pGubunCheckBtn->EnableWindow(bEnable);
		}
		else
		{
			CRect reClient, reChkBtn;
			
			int nHeight = 15;
			GetClientRect(&reClient);
			
			if (CheckNotCheckBtnDrawState() == TRUE)
				reClient.right -= NOTCHECK_WIDTH + 5;
			
			reChkBtn.right = reClient.right - 5;
			reChkBtn.left = reChkBtn.right - GUBUNCHECK_WIDTH;
			
			reChkBtn.top = reClient.top + 5;
			reChkBtn.bottom = reChkBtn.top + nHeight;
			
			
			HINSTANCE hInstSave = AfxGetResourceHandle();
			AfxSetResourceHandle(theApp.m_hInstance);
			
			m_pGubunCheckBtn = new CButton;
			m_pGubunCheckBtn->Create((LPCTSTR)"연속발생",
				WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
				reChkBtn,
				this,
				IDC_BUTTON_GUBUNCHECK);
			
			GetDlgItem(IDC_BUTTON_GUBUNCHECK)->SetFont(&m_fontDefault);
			GetDlgItem(IDC_BUTTON_GUBUNCHECK)->EnableWindow(bEnable);
			
			AfxSetResourceHandle(hInstSave);
		}
	}
	else if (nGubun == 0)
	{
		if (CheckGubunCheckBtnDrawState() == TRUE)
			DestroyGubunCheckBtn();
	}
}


void CMapLoadCtrl::DestroyGubunCheckBtn()
{
	CButton *pCheckBtn = (CButton*)GetDlgItem(IDC_BUTTON_GUBUNCHECK);
	
	if (pCheckBtn)
	{
		pCheckBtn->DestroyWindow();
		pCheckBtn = NULL;
	}
}


BOOL CMapLoadCtrl::CheckGubunCheckBtnDrawState()
{
	BOOL bResult = FALSE;
	
	CButton *pGubunCheckBtn = (CButton*)GetDlgItem(IDC_BUTTON_GUBUNCHECK);
	if (pGubunCheckBtn)
		bResult = TRUE;
	
	return bResult;
}


void CMapLoadCtrl::OnBtnGubunCheck()
{
	TRACE("\n# Map Loader 단일/연속 Btn Event");
}


void CMapLoadCtrl::SetGubunCheckValues(int nState)
{
	if (CheckGubunCheckBtnDrawState() == TRUE)
	{
		CButton *pGubunCheckBtn = (CButton*)GetDlgItem(IDC_BUTTON_GUBUNCHECK);
		if (pGubunCheckBtn)
		{
			pGubunCheckBtn->SetCheck(nState);
			pGubunCheckBtn->Invalidate();
		}
	}
}


BOOL CMapLoadCtrl::GetGubunCheckValues()
{
	BOOL bResult = FALSE;
	
	if (CheckGubunCheckBtnDrawState() == TRUE)
	{
		CButton *pGubunCheckBtn = (CButton*)GetDlgItem(IDC_BUTTON_GUBUNCHECK);
		if (pGubunCheckBtn)
			bResult = pGubunCheckBtn->GetCheck();
	}
	
	return bResult;
}


void CMapLoadCtrl::CreateNotCheckBtn(int nNotUser)
{
	//## Not Check Button Create ##
	
	if (nNotUser == 1)
	{
		if (CheckNotCheckBtnDrawState() == TRUE)
			m_pNotCheckBtn->BringWindowToTop();
		else
		{
			CRect reClient, reChkBtn;
			
			int nHeight = 15;
			GetClientRect(&reClient);
			
			reChkBtn.right = reClient.right - 5;
			reChkBtn.left = reChkBtn.right - NOTCHECK_WIDTH;
			reChkBtn.top = reClient.top + 5;
			reChkBtn.bottom = reChkBtn.top + nHeight;
			
			HINSTANCE hInstSave = AfxGetResourceHandle();
			AfxSetResourceHandle(theApp.m_hInstance);
			
			m_pNotCheckBtn = new CButton;
			m_pNotCheckBtn->Create((LPCTSTR)"NOT 결과제외",
				WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,// | WS_BORDER,
				reChkBtn,
				this,
				IDC_BUTTON_NOTCHECK);
			
			GetDlgItem(IDC_BUTTON_NOTCHECK)->SetFont(&m_fontDefault);
			
			AfxSetResourceHandle(hInstSave);
		}
	}
	else if (nNotUser == 0)
	{
		if (CheckNotCheckBtnDrawState() == TRUE)
			DestroyNotCheckBtn();
	}
}

void CMapLoadCtrl::DestroyNotCheckBtn()
{
	CButton *pCheckBtn = (CButton*)GetDlgItem(IDC_BUTTON_NOTCHECK);
	
	if (pCheckBtn)
	{
		pCheckBtn->DestroyWindow();
		pCheckBtn = NULL;
	}
}

BOOL CMapLoadCtrl::CheckNotCheckBtnDrawState()
{
	BOOL bResult = FALSE;
	
	CButton *pNotCheckBtn = (CButton*)GetDlgItem(IDC_BUTTON_NOTCHECK);
	if (pNotCheckBtn)
		bResult = TRUE;
	
	return bResult;
}

void CMapLoadCtrl::OnBtnNotCheck()
{
	
}

void CMapLoadCtrl::SetNotCheckValues(int nState)
{
	if (CheckNotCheckBtnDrawState() == TRUE)
	{
		CButton *pCheckBtn = (CButton*)GetDlgItem(IDC_BUTTON_NOTCHECK);
		pCheckBtn->SetCheck(nState);
		pCheckBtn->Invalidate();
	}
}

BOOL CMapLoadCtrl::GetNotCheckValues()
{
	BOOL bResult = FALSE;
	
	if (CheckNotCheckBtnDrawState() == TRUE)
	{
		CButton *pCheckBtn = (CButton*)GetDlgItem(IDC_BUTTON_NOTCHECK);
		bResult = pCheckBtn->GetCheck();
	}
	
	return bResult;
}

void CMapLoadCtrl::OnBtnUpdate()
{
	m_pwndMsgTarget->SendMessage(WM_NOTIFY_MAPLOAD, NM_MAPLOAD_UPDATE, (LPARAM)0);
}

void CMapLoadCtrl::CreateUpdateBtn()
{
	if (CheckUpdataBtnDrawState() == TRUE)
	{
		m_pUpdateBtn->BringWindowToTop();
		return;
	}
	
	CRect reClient, reUpdataBtn;
	GetClientRect(&reClient);
	
	reUpdataBtn.right = reClient.right - 5;
	reUpdataBtn.left = reUpdataBtn.right - m_nConstBtnWidth;
	reUpdataBtn.bottom = reClient.bottom - 5;
	reUpdataBtn.top = reUpdataBtn.bottom - m_nConstBtnHeight;
	
	HINSTANCE hInstSave = AfxGetResourceHandle();
	AfxSetResourceHandle(theApp.m_hInstance);
	
	m_pUpdateBtn = new CButton;

	m_pUpdateBtn->Create((LPCTSTR)"수정", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		reUpdataBtn, this, IDC_BUTTON_UPDATA);
	m_pUpdateBtn->SetFont(&m_fontBold);	
	
	
	AfxSetResourceHandle(hInstSave);
	
}


void CMapLoadCtrl::DestroyUpdateBtn()
{
	CButton *pUpdateBtn = (CButton*)GetDlgItem(IDC_BUTTON_UPDATA);
	
	if (pUpdateBtn)
	{
		pUpdateBtn->DestroyWindow();
		m_pUpdateBtn = NULL;
		pUpdateBtn = NULL;
	}

}

BOOL CMapLoadCtrl::CheckUpdataBtnDrawState()
{
	BOOL bResult = FALSE;
	
	CButton *pUpdateBtn = (CButton*)GetDlgItem(IDC_BUTTON_UPDATA);

	if (pUpdateBtn)
		bResult = TRUE;
	
	return bResult;
}

void CMapLoadCtrl::OnBtnOK()
{
	HWND hParentHwnd = GetParent()->GetSafeHwnd();
	m_pwndMsgTarget->SendMessage(WM_NOTIFY_MAPLOAD, NM_MAPLOAD_OK, (LPARAM)0);
}


void CMapLoadCtrl::CreateOKBtn()
{
	if (CheckOKBtnDrawState() == TRUE)
	{
		m_pOKBtn->BringWindowToTop();
		return;
	}
	
	CRect reClient, reOKBtn;
	GetClientRect(&reClient);
	
	reOKBtn.right = reClient.right - 5;
	reOKBtn.left = reOKBtn.right - m_nConstBtnWidth;
	
	reOKBtn.bottom = reClient.bottom - m_nConstBtnHeight * 2 - 5;
	reOKBtn.bottom -= 2 * 2;  //# 버튼 간격
	reOKBtn.top = reOKBtn.bottom - m_nConstBtnHeight;
	
	HINSTANCE hInstSave = AfxGetResourceHandle();
	AfxSetResourceHandle(theApp.m_hInstance);
	
	m_pOKBtn = new CButton;

	m_pOKBtn->Create((LPCTSTR)"취소", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		reOKBtn, this, IDC_BUTTON_OK);
	m_pOKBtn->SetFont(&m_fontDefault);
	
	AfxSetResourceHandle(hInstSave);
}

void CMapLoadCtrl::DestroyOKBtn()
{
	// 20120723 ssj - 서버자동주문 >>
	//.CDrBtnCtrl *pOKBtn = (CDrBtnCtrl*)GetDlgItem(IDC_BUTTON_OK);
	CButton *pOKBtn = (CButton*)GetDlgItem(IDC_BUTTON_OK);
	// 20120723 ssj - 서버자동주문 <<
	
	if (pOKBtn)
	{
		pOKBtn->DestroyWindow();
		pOKBtn = NULL;
	}
}

BOOL CMapLoadCtrl::CheckOKBtnDrawState()
{
	BOOL bResult = FALSE;
	
	// 20120723 ssj - 서버자동주문 >>
	//.CDrBtnCtrl *pOKBtn = (CDrBtnCtrl*)GetDlgItem(IDC_BUTTON_OK);
	CButton *pOKBtn = (CButton*)GetDlgItem(IDC_BUTTON_OK);
	// 20120723 ssj - 서버자동주문 <<

	if (pOKBtn)
		bResult = TRUE;
	
	return bResult;
}


void CMapLoadCtrl::OnBtnBase()
{
	//SetDefultToMapValues(m_strNowMapTag, m_strNowMapFileName);
	SetDefultToMapValues(&m_stNowXMLInfo);
}


void CMapLoadCtrl::CreateBaseBtn()
{
	if (CheckBaseBtnDrawState() == TRUE)
	{
		m_pBaseBtn->BringWindowToTop();
		return;
	}
	
	CRect reClient, reBaseBtn;
	GetClientRect(&reClient);
	
	reBaseBtn.right = reClient.right - 5;
	reBaseBtn.left = reBaseBtn.right - m_nConstBtnWidth;
	
	reBaseBtn.bottom = reClient.bottom - m_nConstBtnHeight - 5;
	reBaseBtn.bottom -= 2;  //# 버튼 간격
	reBaseBtn.top = reBaseBtn.bottom - m_nConstBtnHeight;
	
	HINSTANCE hInstSave = AfxGetResourceHandle();
	AfxSetResourceHandle(theApp.m_hInstance);
	
	// 20120723 ssj - 서버자동주문 >>
	//.m_pBaseBtn = new CDrBtnCtrl;
	m_pBaseBtn = new CButton;
	// 20120723 ssj - 서버자동주문 <<

	m_pBaseBtn->Create((LPCTSTR)"기본값", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		reBaseBtn, this, IDC_BUTTON_BASE);
	m_pBaseBtn->SetFont(&m_fontBold);
	// 20120723 ssj - 서버자동주문 >>
	//.m_pBaseBtn->SetBtnColor(2);
	//m_pBaseBtn->SetButtonColor(SKINBTN_TAB); // SKINBTN_TAB = 2;
	// 20120723 ssj - 서버자동주문 <<
	
	AfxSetResourceHandle(hInstSave);
}

void CMapLoadCtrl::DestroyBaseBtn()
{
	// 20120723 ssj - 서버자동주문 >>
	//.CDrBtnCtrl *pBaseBtn = (CDrBtnCtrl*)GetDlgItem(IDC_BUTTON_BASE);
	CButton *pBaseBtn = (CButton*)GetDlgItem(IDC_BUTTON_BASE);
	// 20120723 ssj - 서버자동주문 <<
	
	if (pBaseBtn)
	{
		pBaseBtn->DestroyWindow();
		pBaseBtn = NULL;
	}
}

BOOL CMapLoadCtrl::CheckBaseBtnDrawState()
{
	BOOL bResult = FALSE;
	
	// 20120723 ssj - 서버자동주문 >>
	//.CDrBtnCtrl *pBaseBtn = (CDrBtnCtrl*)GetDlgItem(IDC_BUTTON_BASE);
	CButton *pBaseBtn = (CButton*)GetDlgItem(IDC_BUTTON_BASE);
	// 20120723 ssj - 서버자동주문 <<

	if (pBaseBtn)
		bResult = TRUE;
	
	return bResult;
}


void CMapLoadCtrl::SetStructDataClear(User_Define &stUserDefine)
{
	// 20120723 ssj - 서버자동주문 >>
	memset(&stUserDefine, 0, sizeof(User_Define));
	// 20120723 ssj - 서버자동주문 <<

	//User_Index 초기화

	// 20120723 ssj - 서버자동주문 >>
	/*
	stUserDefine.IndexNo = 0; 			// 지표 index 
	stUserDefine.GroupNo = 0; 			// 소속 그룹번호
	stUserDefine.GroupIdxCnt = 0;		// 그룹내 지표 개수 
	stUserDefine.TargetBase = 0;		// 0:일간, 1:주간, 2:월간 3:1분,  4:5분    
	// 5:10분, 6:20분, 7:30분, 8:60분   
	stUserDefine.Type = 0; 					// 지표의 종류
	stUserDefine.Type1 = 0; 				// 조건 형태
	stUserDefine.Type2 = 0; 				// 상세 형태
	
	stUserDefine.STerm = 0;         // n봉전 기준               	
	stUserDefine.ETerm = 1;         // n봉이내                 	
	
	stUserDefine.SignalCnt1 = 1;				// 발생회수	(new)	X번에서 X번 만족
	stUserDefine.SignalCnt2 = 1;				// 발생회수	(new)									
	stUserDefine.ResultViewNum = 0;		// 결과값보기 필드 갯수(0:사용안함)	    
	*/
	SetLong(stUserDefine.giIndexNo      , sizeof(stUserDefine.giIndexNo      )     , 0); 			
	SetLong(stUserDefine.giGroupNo      , sizeof(stUserDefine.giGroupNo      )     , 0); 			
	SetLong(stUserDefine.giGroupIdxCnt  , sizeof(stUserDefine.giGroupIdxCnt  )         , 0);		
	SetLong(stUserDefine.giTargetBase   , sizeof(stUserDefine.giTargetBase   )        , 0);		
	SetLong(stUserDefine.giType         , sizeof(stUserDefine.giType         )  , 0); 					
	SetLong(stUserDefine.giType1        , sizeof(stUserDefine.giType1        )   , 0); 				
	SetLong(stUserDefine.giType2        , sizeof(stUserDefine.giType2        )   , 0); 				
	SetLong(stUserDefine.giSTerm        , sizeof(stUserDefine.giSTerm        )   , 0);         
	SetLong(stUserDefine.giETerm        , sizeof(stUserDefine.giETerm        )   , 1);         
	SetLong(stUserDefine.giSignalCnt1   , sizeof(stUserDefine.giSignalCnt1   )        , 1);		
	SetLong(stUserDefine.giSignalCnt2   , sizeof(stUserDefine.giSignalCnt2   )        , 1);		
	SetLong(stUserDefine.giResultViewNum, sizeof(stUserDefine.giResultViewNum)           , 0);	
	// 20120723 ssj - 서버자동주문 <<

	// 검색형태 0:일반 1:사용자정의	2:뉴스 3:패턴   (new) */
	memcpy(&stUserDefine.SearchType, "0", sizeof(stUserDefine.SearchType));   
	
	// 20120723 ssj - 서버자동주문 >>
	/*
	stUserDefine.Rank = 100;        // 순위검색 종목 수             	
	stUserDefine.Trend = 2;         // 추세횟수                     	
	stUserDefine.ResultViewNum = 0;	// 결과값보기 필드 갯수(0:사용안함)    
	*/
	SetLong(stUserDefine.giRank         , sizeof(stUserDefine.giRank         )  , 100);        
	SetLong(stUserDefine.giTrend        , sizeof(stUserDefine.giTrend        )   , 2);         
	SetLong(stUserDefine.giResultViewNum, sizeof(stUserDefine.giResultViewNum)           , 0);	
	// 20120723 ssj - 서버자동주문 <<

	/* 검색구분 0:일반 1:순위 2:복합*/
	memcpy(&stUserDefine.IndexType, "0", sizeof(stUserDefine.IndexType));   
	
	/* 연산자'0':OR '1':AND '2':NEXT*/
	memcpy(&stUserDefine.Operator, "1", sizeof(stUserDefine.Operator)); 
	
	/* 결과제외 '0':A, '1':Not A    */
	memcpy(&stUserDefine.Reverse, "0", sizeof(stUserDefine.Reverse));   
	
	/* 지표의 연속발생 구분 '0':단일발생, 1:연속발생지표 */
	memcpy(&stUserDefine.IdxContiGubun, "0", sizeof(stUserDefine.IdxContiGubun));  
	
	memcpy(&stUserDefine.Code, "000000", sizeof(stUserDefine.Code));  
	
	/* 지표관련 변수값 (ex.12,26,9) 	*/
	memset(stUserDefine.Param, 0, sizeof(stUserDefine.Param));    
	
	/* 기타 설정 변수값             */
	memset(stUserDefine.Condition, 0, sizeof(stUserDefine.Condition));
}


BOOL CMapLoadCtrl::GetMapValuesToStruct(CString strTagID,
										User_Define &stResultUserDefine, 
										CString &strResultComposition, BOOL &bHaveTerm)
{
	//## 현재 조건 화면에서 구성된 값을 Packet와 완성 구문의 만든다. ##
	
	//#### Need Make Conposition! ####
	CString strParam[MAX_PARAM + 1];      //#define		MAX_PARAM		3
	CString strCondition[MAX_CONDI + 1];	//#define		MAX_CONDI		6
	CString strTrend, strSTerm, strETerm, strType2, strRank, strCode;
	
	//# 2003. 11. 25 추가 
	CString strSignalCnt1, strSignalCnt2, strGubun;
	
	//## Struct Clear ##
	SetStructDataClear(stResultUserDefine);
	
	CString strTemp;
	strTemp = GetTagToNodeData(strTagID, "CONTROL_NUMBER");
	int nControlCount = atoi(strTemp.operator const char*());
	
	CString strMapType;
	strMapType = strTemp = GetTagToNodeData(strTagID, "MAP_TYPE");
	// 20120723 ssj - 서버자동주문 >>
	//stResultUserDefine.Type = atoi(strTemp.operator const char*());
	 CopyString(stResultUserDefine.giType, sizeof(stResultUserDefine.giType), strTemp);
	// 20120723 ssj - 서버자동주문 <<

	AddTagIDForMapType(strMapType, strTagID);
	
	strTemp = GetTagToNodeData(strTagID, "T1");
	if (!strTemp.IsEmpty())
	{
		// 20120723 ssj - 서버자동주문 >>
		//stResultUserDefine.Type1 = atoi(strTemp.operator const char*());
		 CopyString(stResultUserDefine.giType1, sizeof(stResultUserDefine.giType1), strTemp);
	}

	strTemp = GetTagToNodeData(strTagID, "T2");
	if (!strTemp.IsEmpty())
	{
		// 20120723 ssj - 서버자동주문 >>
		//stResultUserDefine.Type2 = atoi(strTemp.operator const char*());
		 CopyString(stResultUserDefine.giType2, sizeof(stResultUserDefine.giType2), strTemp);
		// 20120723 ssj - 서버자동주문 <<
	}

	//# m_nCondiType	: 0 (기본검색)
	//#					: 1 (순위검색)
	//#					: 2 (순차검색)
	CString strSearchType;
	strSearchType.Format("%d", m_stNowXMLInfo.nGubun);
	memcpy(&stResultUserDefine.IndexType, strSearchType.operator const char*(), sizeof(stResultUserDefine.IndexType));
	
	if (m_stNowXMLInfo.nGubun == 1)
		stResultUserDefine.IdxContiGubun = (GetGubunCheckValues() == TRUE) ? '1':'0';
	else
		stResultUserDefine.IdxContiGubun = '0';
	
	if (m_stNowXMLInfo.nNotUser == 1)
		stResultUserDefine.Reverse = (GetNotCheckValues() == TRUE) ? '1':'0';
	else
		stResultUserDefine.Reverse = '0';
	
	CString strControlType;
	int nResourceID;
	

	CUIntArray* plarrResourceID;
	CString strType;
	m_mapResourceID.Lookup(strTagID, (void*&)plarrResourceID);
	if(!plarrResourceID)
		return 0;

	for (int i = 0; i <= nControlCount - 1; i++) 
	{
		//#=> 컨트롤의 타입을 얻는다.(EDIT, STATIC, COMBOBOX, BUTTON)
		strControlType = GetTagToControlNodeValues(strTagID, "TYPE", i);		
	//	strTemp = GetTagToControlNodeValues(strTagID, "ID", i);
	//	nResourceID = atoi(strTemp.operator const char*()); 
		nResourceID = plarrResourceID->GetAt(i);
		
		if ((strControlType.Compare("Edit") == 0) ||
			(strControlType.Compare("Static") == 0) ||
			strControlType.Compare("TimeCtrl") == 0)     
		{
			CString strEditText;
			if (strControlType.Compare("Edit") == 0)
			{
				CTEditCtrlWnd *pEdit = (CTEditCtrlWnd*)GetDlgItem(nResourceID);
				
				if (pEdit == NULL)
					return FALSE;
				
				pEdit->GetWindowText(strEditText);
		
			}
			else if (strControlType.Compare("Static") == 0)
				strEditText = GetTagToControlNodeValues(strTagID, "DEFAULT_VALUE", i);
			else if (strControlType.Compare("TimeCtrl") == 0)
			{
				CDateTimeCtrl *pTimeCtrl = (CDateTimeCtrl*)GetDlgItem(nResourceID);

				if (pTimeCtrl == NULL)
					return FALSE;

				CTime time;
				pTimeCtrl->GetWindowText(strEditText);
			}

			
			CString strEditPacketID = GetTagToControlNodeValues(strTagID, "PACKET_ID", i);
			if ((!strEditText.IsEmpty()) && (!strEditPacketID.IsEmpty())) 
			{
//				int nTempEdit;
				//## Modify :
				if (strEditPacketID.Compare("STERM") == 0) 
				{
					bHaveTerm = TRUE;
					
					// 20120723 ssj - 서버자동주문 >>
					//nTempEdit = atoi(strEditText.operator const char*());
					//stResultUserDefine.STerm = nTempEdit;
					 CopyString(stResultUserDefine.giSTerm, sizeof(stResultUserDefine.giSTerm), strEditText);
					// 20120723 ssj - 서버자동주문 <<
					
					//## Need Make Composition ##
					strSTerm = strEditText;
				}
				else if (strEditPacketID.Compare("ETERM") == 0) 
				{
					bHaveTerm = TRUE;
					
					// 20120723 ssj - 서버자동주문 >>
					//nTempEdit = atoi(strEditText.operator const char*());
					//stResultUserDefine.ETerm = nTempEdit;
					 CopyString(stResultUserDefine.giETerm, sizeof(stResultUserDefine.giETerm), strEditText);
					// 20120723 ssj - 서버자동주문 <<
					
					//## Need Make Composition ##
					strETerm = strEditText;
				}
				else if (strEditPacketID.Compare("RANK") == 0) 
				{
					// 20120723 ssj - 서버자동주문 >>
					//nTempEdit = atoi(strEditText.operator const char*());
					//stResultUserDefine.Rank = nTempEdit;
					 CopyString(stResultUserDefine.giRank, sizeof(stResultUserDefine.giRank), strEditText);
					// 20120723 ssj - 서버자동주문 <<
					
					//## Need Make Composition ##
					strRank = strEditText;
				}
				else if (strEditPacketID.Compare("TR") == 0) 
				{
					// 20120723 ssj - 서버자동주문 >>
					//nTempEdit = atoi(strEditText.operator const char*());
					//stResultUserDefine.Trend = nTempEdit;
					 CopyString(stResultUserDefine.giTrend, sizeof(stResultUserDefine.giTrend), strEditText);
					// 20120723 ssj - 서버자동주문 <<
					
					//## Need Make Composition ##
					strTrend = strEditText;
				}
				else if (strEditPacketID.Compare("SCNT1") == 0) 
				{
					// 20120723 ssj - 서버자동주문 >>
					//nTempEdit = atoi(strEditText.operator const char*());
					//stResultUserDefine.SignalCnt1 = nTempEdit;
					 CopyString(stResultUserDefine.giSignalCnt1, sizeof(stResultUserDefine.giSignalCnt1), strEditText);
					// 20120723 ssj - 서버자동주문 <<

					//## Need Make Composition ##
					strSignalCnt1 = strEditText;
				}
				else if (strEditPacketID.Compare("SCNT2") == 0) 
				{
					// 20120723 ssj - 서버자동주문 >>
					//nTempEdit = atoi(strEditText.operator const char*());
					//stResultUserDefine.SignalCnt2 = nTempEdit;
					 CopyString(stResultUserDefine.giSignalCnt2, sizeof(stResultUserDefine.giSignalCnt2), strEditText);
					// 20120723 ssj - 서버자동주문 <<

					//## Need Make Composition ##
					strSignalCnt2 = strEditText;
				}
				else if (strEditPacketID.Compare("CODE") == 0) 
				{
					int nJongCodeLength = 6;
					if (strEditText.GetLength() > nJongCodeLength)
						strEditText.Left(nJongCodeLength);
					else
					{
						int nAddTestCnt = nJongCodeLength - strEditText.GetLength();
						for (int nIndex = 0; nIndex < nAddTestCnt; nIndex++)
							strEditText = "0" + strEditText;
					}
					
					memcpy(&stResultUserDefine.Code, strEditText.operator const char*(), sizeof(stResultUserDefine.Code));
					
					//## Need Make Composition ##
					strCode = strEditText;
				}
				else 
				{
				//콤마 관련 추가
					CString strWithComma = strEditText;
					strEditText.Remove(',');
					strEditText.Remove(':');
				//////////////////////////////
					double dTempEdit;
					dTempEdit = atof(strEditText.operator const char*());
					
					CString strEditPacketName = strEditPacketID.Left(1);
					CString strEditPacketNum = strEditPacketID.Right(1);
					int nEditPacketNum = atoi(strEditPacketNum.operator const char*());
					
					if (strEditPacketName.Compare("C") == 0) 
					{
						// 20120723 ssj - 서버자동주문 >>
						//stResultUserDefine.Condition[nEditPacketNum - 1] = dTempEdit;
						memcpy(&stResultUserDefine.Condition[nEditPacketNum - 1], strEditText, min(sizeof(stResultUserDefine.Condition[nEditPacketNum - 1]),
							strEditText.GetLength()));
						// 20120723 ssj - 서버자동주문 <<
						
						//## Need Make Composition ##
					//	strCondition[nEditPacketNum - 1] = strEditText;
						strCondition[nEditPacketNum - 1] = strWithComma;
					}
					else if (strEditPacketName.Compare("P") == 0) 
					{
						// 20120723 ssj - 서버자동주문 >>
						//stResultUserDefine.Param[nEditPacketNum - 1] = dTempEdit;
						memcpy(&stResultUserDefine.Param[nEditPacketNum - 1], strEditText, min(sizeof(stResultUserDefine.Param[nEditPacketNum - 1]),
							strEditText.GetLength()));
						// 20120723 ssj - 서버자동주문 <<
						
						//## Need Make Composition ##
					//	strParam[nEditPacketNum - 1] = strEditText;
						strParam[nEditPacketNum - 1] = strWithComma;

					}
				}
			}
	}
	else if (strControlType.Compare(NEWS_CONTROL_TYPE) == 0) 
	{
		// 20120723 ssj - 서버자동주문 >>
		//stResultUserDefine.Condition[0] = m_stNowXMLInfo.nResultViewDefVal;		//# KeyWord Code!
		CString strTemp;
		strTemp.Format("%d", m_stNowXMLInfo.nResultViewDefVal);
		memcpy(&stResultUserDefine.Condition[0], strTemp, min(sizeof(stResultUserDefine.Condition[0]),
							strTemp.GetLength()));
		// 20120723 ssj - 서버자동주문 <<

		//## Need Make Composition ##
		strCondition[0] = m_stNowXMLInfo.strName;
	}
	else if (strControlType.Compare("ComboBox") == 0) 
	{
		CComboBox *pComboBox = (CComboBox*)GetDlgItem(nResourceID);
		
		if (pComboBox == NULL)
			return FALSE;
		
		//# Index start = 0
		CString strComboText;
		pComboBox->GetWindowText(strComboText);
		
		int nSelecetedIndex = pComboBox->GetCurSel();
		CString strComboPacketID = GetTagToControlNodeValues(strTagID, "PACKET_ID", i);
		if ((nSelecetedIndex >= 0) && (!strComboPacketID.IsEmpty())) 
		{
			CString strSearchData;
			CString strComboPacketName = strComboPacketID.Left(1);
			int nComboPacketNum = atoi(strComboPacketID.Right(1).operator const char*());
			
			CString strComboLoadType = GetTagToControlNodeValues(strTagID, "COMBO_LOAD_TYPE", i);
			if (atoi(strComboLoadType) == 1) 
			{
				CString strComboLoadData = GetTagToControlNodeValues(strTagID, "COMBO_LOAD_DATA", i);
				
				int nItemFileType = -1;
				CStringArray saCode;
				if (strComboLoadData.Compare("거래소") == 0)
				{
				/*
				if (((m_stNowXMLInfo.strTag.Compare("A1") == 0) && (strComboPacketID.Compare("C1") == 0)) ||	//# 거래소
				((m_stNowXMLInfo.strTag.Compare("A3") == 0) && (strComboPacketID.Compare("C1") == 0)))		//# 거래소 + 코스닥
					*/
					if ((m_stNowXMLInfo.strTag.Compare("A1") == 0) || (m_stNowXMLInfo.strTag.Compare("A3") == 0))
					{
						nItemFileType = INDUSTRY_TYPE;
						saCode.Copy(m_saCode_Kospi);
					}
				}
				else if (strComboLoadData.Compare("코스닥") == 0)
				{
				/*
				if (((m_stNowXMLInfo.strTag.Compare("A2") == 0) && (strComboPacketID.Compare("C1") == 0)) || 
				((m_stNowXMLInfo.strTag.Compare("A3") == 0) && (strComboPacketID.Compare("C2") == 0)))		//# 거래소 + 코스닥
					*/
					if ((m_stNowXMLInfo.strTag.Compare("A2") == 0) || (m_stNowXMLInfo.strTag.Compare("A3") == 0))
					{
						nItemFileType = KOSDAK_TYPE;
						saCode.Copy(m_saCode_Kosdaq);
					}
				}
				else if (strComboLoadData.Compare("계열사") == 0)
				{
					if ((m_stNowXMLInfo.strTag.Compare("A7") == 0) && (strComboPacketID.Compare("C1") == 0))		//# 계열사
					{
						nItemFileType = GROUP_TYPE;
						
					}
				}
				
				if (nItemFileType != -1)
					strSearchData = saCode.GetAt(nSelecetedIndex);
			}
			else
			{
				CString	strItemData = GetTagToControlNodeValues(strTagID, "COMBO_INDEX", i);
				// 20120723 ssj - 서버자동주문 >>
				if (HasExtraInfo(nResourceID))
				{
					strItemData = GetComboIndexByMarket(nResourceID);
				}
				// 20120723 ssj - 서버자동주문 <<
				strItemData += "/";
				
				int nFindPos;
				int nCount = 0;
				do
				{
					nFindPos = strItemData.Find('/');
					if (nCount > nSelecetedIndex)
						break;
					
					if (nFindPos == -1) 
					{
						nFindPos = 1;
						strSearchData = strItemData.Mid(0, nFindPos);
						break;
					}
					strSearchData = strItemData.Mid(0, nFindPos);
					strItemData = strItemData.Mid(nFindPos + 1, strItemData.GetLength() - nFindPos);
					nCount++;
				} while(1);
			}
			
			if (strComboPacketName.Compare("C") == 0) 
			{
				double dComboSearchData = atof(strSearchData.operator const char*());

				// 20120723 ssj - 서버자동주문 >>
				//stResultUserDefine.Condition[nComboPacketNum - 1] = dComboSearchData;
				memcpy(&stResultUserDefine.Condition[nComboPacketNum - 1], strSearchData, min(sizeof(stResultUserDefine.Condition[nComboPacketNum - 1]),
							strSearchData.GetLength()));
				// 20120723 ssj - 서버자동주문 <<
				
				//## Need Make Composition ##
				strCondition[nComboPacketNum - 1] = strComboText;
			}
			else if (strComboPacketName.Compare("T") == 0) 
			{
				int nComboSearchData = atoi(strSearchData.operator const char*());
				

				if((strMapType.Left(2).CompareNoCase(_T("-2")) == 0 || strMapType.Left(2).CompareNoCase(_T("-3")) == 0 || strMapType.Left(2).CompareNoCase(_T("-4")) == 0) &&
						strComboPacketID.CompareNoCase("T1") == 0 )
				{
					// 20120723 ssj - 서버자동주문 >>
					//stResultUserDefine.Type1 = nComboSearchData;						
					 CopyString(stResultUserDefine.giType1, sizeof(stResultUserDefine.giType1), strSearchData);
					// ssJ <<
				}
				else
				{
					// 20120723 ssj - 서버자동주문 >>
					//stResultUserDefine.Type2 = nComboSearchData;
					 CopyString(stResultUserDefine.giType2, sizeof(stResultUserDefine.giType2), strSearchData);
					// 20120723 ssj - 서버자동주문 <<
					
					//## Need Make Composition ##
					strType2 = strComboText;
				}
				
			}
			else if (strComboPacketName.Compare("P") == 0) 
			{
				CString strWithComma = strComboText;
				double dComboSearchData = atof(strSearchData.operator const char*());

				// 20120723 ssj - 서버자동주문 >>
				//stResultUserDefine.Param[nComboPacketNum - 1] = dComboSearchData;			
				memcpy(&stResultUserDefine.Param[nComboPacketNum - 1], strSearchData, min(sizeof(stResultUserDefine.Param[nComboPacketNum - 1]),
							strSearchData.GetLength()));
				// 20120723 ssj - 서버자동주문 <<
				
				strParam[nComboPacketNum - 1] = strWithComma;

			}
		
		}
	}
}



//## 완성된 조건 해당 문구
CString strComposition = GetTagToNodeData(strTagID, "COMPLETE_INDEX_NAME");

TRACE("\n\n# 맵 완성 구문 : %s", strComposition);

//## RETURN 할 완성 구문 ##
//## strResultComposition : Return Composition
strResultComposition = strComposition; 

CString strExtractData;
CString strReplaceTarget;  //교환될 데이터
CString strReplaceData;    //교환할 데이터 

int nStartPos; //<= '(' 를 찾은위치
int nEndPos;   //<= ')' 를 찾은위치

do
{
	nStartPos = strComposition.Find('(');
	nEndPos = strComposition.Find(')');
	if (nStartPos < 0 || nEndPos < 0)
		break;
	
	//( ) 사이에서 뽑아낸 데이터가 단일인지 복수인지 판별
	strExtractData = strComposition.Mid(nStartPos + 1, nEndPos - (nStartPos + 1));
	strReplaceTarget = "(" + strExtractData + ")";
	
	//해당자리의 실제값을 치완한다.
	CString strItem = strExtractData.Left(1);
	CString strItemIndex = strExtractData.Right(1);
	int nIndex = atoi(strItemIndex.operator const char*());
	
	if (strItem.Compare("C") == 0)
	{
		if (strExtractData.Compare("CODE") == 0)
			strReplaceData = strCode;
		else
			strReplaceData = strCondition[nIndex - 1];
	}
	else if (strItem.Compare("P") == 0) 
		strReplaceData = strParam[nIndex - 1];
	else if(strItem.Compare("T") == 0) 
	{
		if (strExtractData.Compare("TR") == 0)
			strReplaceData = strTrend;
		else if (strExtractData.Compare("T2") == 0)
			strReplaceData = strType2; 
	}
	else if (strItem.Compare("R") == 0)
	{
		if (strExtractData.Compare("RANK") == 0)
			strReplaceData = strRank;
	}
	else if (strItem.Compare("S") == 0)
	{
		if (strExtractData.Compare("STERM") == 0)
			strReplaceData = strSTerm;
		else if (strExtractData.Compare("SCNT1") == 0)
			strReplaceData = strSignalCnt1;
		else if (strExtractData.Compare("SCNT2") == 0)
			strReplaceData = strSignalCnt2;
	}
	else if (strItem.Compare("E") == 0)
	{
		if (strExtractData.Compare("ETERM") == 0)
			strReplaceData = strETerm;
	}
	
	//## Composition Modify! ##
	strResultComposition.Replace((LPCTSTR)strReplaceTarget, (LPCTSTR)strReplaceData);
	
	strComposition = strComposition.Mid(nEndPos + 1, strComposition.GetLength() - nEndPos);
}while(1);

CString strFrontResultComposition = "";
if (m_stNowXMLInfo.nGubun == 1)
{
	if (stResultUserDefine.IdxContiGubun == '0')
		strFrontResultComposition = "[단일] ";
	else if (stResultUserDefine.IdxContiGubun == '1')
		strFrontResultComposition = "[연속] ";
}

strFrontResultComposition += strResultComposition;
strResultComposition = strFrontResultComposition;

if (stResultUserDefine.Reverse == '1')
strResultComposition += " (결과제외)";

TRACE("\n\n# 맵 완성 구문 : %s", strResultComposition);

return TRUE;
}


void CMapLoadCtrl::SetStructToMapValues(CString strTagID, User_Define* stUserDefine)
{
	//## 사용자가 설정한지표값을 구조체에서 읽어 화면에 셋팅한다.
	
	CString strTemp = GetTagToNodeData(strTagID, "CONTROL_NUMBER");
	int nControlCount = atoi(strTemp.operator const char*());
	
	CUIntArray* plarrResourceID;
	CString strType;
	m_mapResourceID.Lookup(strTagID, (void*&)plarrResourceID);
	if(!plarrResourceID)
		return;

	CString strControlType;
	for (int i = 0 ; i <= nControlCount - 1 ; i++) 
	{
		strControlType = GetTagToControlNodeValues(strTagID, "TYPE", i);
		
		strTemp = GetTagToControlNodeValues(strTagID, "EDIT_LENGTH", i);
		int nFind = strTemp.Find('.', 0);
		int nIntegerLength, nRealLength;
		if (nFind > -1)
		{
			nIntegerLength = atoi(strTemp.Left(nFind));
			nRealLength = atoi(strTemp.Right(strTemp.GetLength() - (nFind + 1))); 
		}
		else
		{
			if (strTemp.IsEmpty() == TRUE)
				nIntegerLength = 0;
			else
				nIntegerLength = atoi(strTemp);
			nRealLength = 0;
		}
		
		//# 소숫점 예외 처리 적용 => 2005.03.22
		CString strFormat;
		strFormat.Format("%d", nRealLength);
		strFormat = "%." + strFormat + "f";
		
	//	strTemp = GetTagToControlNodeValues(strTagID, "ID", i);
	//	int nResourceID = atoi(strTemp.operator const char*()); 
		int nResourceID = plarrResourceID->GetAt(i);
		
		CString strPacketName = GetTagToControlNodeValues(strTagID, "PACKET_ID", i);
		CString strItem = strPacketName.Left(1);
		CString strItemIndex = strPacketName.Right(1);
		int nIndex = atoi(strItemIndex.operator const char*());
		
		CString strSetControlValues;
		if (strItem.Compare("C") == 0)
		{
			if (strPacketName.Compare("CODE") == 0)		//# 종목
			{
				strSetControlValues.Format("%.6s", stUserDefine->Code);
				
				while (strSetControlValues.GetLength() < 6)
					strSetControlValues = "0" + strSetControlValues;
			}
			else
			{
				// 20120723 ssj - 서버자동주문 >>
				//strSetControlValues.Format(strFormat, stUserDefine->Condition[nIndex - 1]);
				CString strTemp((char *)&stUserDefine->Condition[nIndex - 1], sizeof(stUserDefine->Condition[nIndex - 1]));
				strTemp.Trim();
				strSetControlValues.Format(strFormat, atof(strTemp));
				// 20120723 ssj - 서버자동주문 <<
			}
		}
		else if (strItem.Compare("E") == 0)
		{
			if (strPacketName.Compare("ETERM") == 0)
			{
				// 20120723 ssj - 서버자동주문 >>
				//strSetControlValues.Format("%ld", stUserDefine->ETerm);
				strSetControlValues = GetString(stUserDefine->giETerm, sizeof(stUserDefine->giETerm));
				// 20120723 ssj - 서버자동주문 <<
			}
		}
		else if (strItem.Compare("P") == 0) 
			strSetControlValues.Format(strFormat, stUserDefine->Param[nIndex - 1]);
		else if(strItem.Compare("T") == 0) 
		{
			if (strPacketName.Compare("TR") == 0)
			{
				// 20120723 ssj - 서버자동주문 >>
				//strSetControlValues.Format("%ld", stUserDefine->Trend);
				strSetControlValues = GetString(stUserDefine->giTrend, sizeof(stUserDefine->giTrend));
				// 20120723 ssj - 서버자동주문 <<
			}
			else if (strPacketName.Compare("T2") == 0)
			{
				// 20120723 ssj - 서버자동주문 >>
				//strSetControlValues.Format("%ld", stUserDefine->Type2);
				strSetControlValues = GetString(stUserDefine->giType2, sizeof(stUserDefine->giType2));
				// 20120723 ssj - 서버자동주문 <<
			}
		}
		else if (strItem.Compare("R") == 0)
		{
			if (strPacketName.Compare("RANK") == 0)
				// 20120723 ssj - 서버자동주문 >>
				//strSetControlValues.Format("%ld", stUserDefine->Rank);
				strSetControlValues = GetString(stUserDefine->giRank, sizeof(stUserDefine->giRank));
				// 20120723 ssj - 서버자동주문 <<
		}
		else if (strItem.Compare("S") == 0)
		{
			if (strPacketName.Compare("STERM") == 0)
				// 20120723 ssj - 서버자동주문 >>
				//strSetControlValues.Format("%ld", stUserDefine->STerm);
				strSetControlValues = GetString(stUserDefine->giSTerm, sizeof(stUserDefine->giSTerm));
				// 20120723 ssj - 서버자동주문 <<
			else if (strPacketName.Compare("SCNT1") == 0)
				// 20120723 ssj - 서버자동주문 >>
				//strSetControlValues.Format("%ld", stUserDefine->SignalCnt1);
				strSetControlValues = GetString(stUserDefine->giSignalCnt1, sizeof(stUserDefine->giSignalCnt1));
				// 20120723 ssj - 서버자동주문 <<
			else if (strPacketName.Compare("SCNT2") == 0)
				// 20120723 ssj - 서버자동주문 >>
				//strSetControlValues.Format("%ld", stUserDefine->SignalCnt2);
				strSetControlValues = GetString(stUserDefine->giSignalCnt2, sizeof(stUserDefine->giSignalCnt2));
				// 20120723 ssj - 서버자동주문 <<
		}
		
		//## Find Values Set Control ##
		if (strControlType.Compare("Edit") == 0) 
		{
			CTEditCtrlWnd *pEditWnd = (CTEditCtrlWnd*)GetDlgItem(nResourceID);
			pEditWnd->SetWindowText(strSetControlValues);
			pEditWnd->Invalidate();
		}
		else if (strControlType.Compare("TimeCtrl") == 0) 
		{
			CDateTimeCtrl *pTimeCtrl = (CDateTimeCtrl*)GetDlgItem(nResourceID);

			strSetControlValues.Remove(':');	
			CTime timeCur = CTime::GetCurrentTime();	
			CTime time(timeCur.GetYear(), timeCur.GetMonth(), timeCur.GetDay(), atoi(strSetControlValues.Left(2)), atoi(strSetControlValues.Mid(2, 2)), atoi(strSetControlValues.Mid(4, 3)));
			
			pTimeCtrl->SetTime(&time);
			pTimeCtrl->Invalidate();
		}
		else if (strControlType.Compare("ComboBox") == 0) 
		{
			CComboBox *pComboBoxWnd = (CComboBox*)GetDlgItem(nResourceID);
			
			int nFindIndex = -1;
			CString strComboLoadType = GetTagToControlNodeValues(strTagID, "COMBO_LOAD_TYPE", i);
			if (atoi(strComboLoadType) == 1) 
			{
				CString strComboLoadData = GetTagToControlNodeValues(strTagID, "COMBO_LOAD_DATA", i);
				
				int nItemFileType = -1;
				CStringArray saCode;
				if (strComboLoadData.Compare("거래소") == 0)
				{
				/*
				if (((strTagID.Compare("A1") == 0) && (strPacketName.Compare("C1") == 0)) ||	//# 거래소
				((strTagID.Compare("A3") == 0) && (strPacketName.Compare("C1") == 0)))		//# 거래소 + 코스닥
					*/
					if ((strTagID.Compare("A1") == 0) || (strTagID.Compare("A3") == 0))
					{
						nItemFileType = INDUSTRY_TYPE;
						saCode.Copy(m_saCode_Kospi);
					}
				}
				else if (strComboLoadData.Compare("코스닥") == 0)
				{
				/*
				if (((strTagID.Compare("A2") == 0) && (strPacketName.Compare("C2") == 0)) || 
				((strTagID.Compare("A3") == 0) && (strPacketName.Compare("C2") == 0)))		//# 거래소 + 코스닥
					*/
					if ((strTagID.Compare("A2") == 0) || (strTagID.Compare("A3") == 0))
					{
						nItemFileType = KOSDAK_TYPE;
						saCode.Copy(m_saCode_Kosdaq);
					}
				}
				else if (strComboLoadData.Compare("계열사") == 0)
				{
					if ((strTagID.Compare("A7") == 0) && (strPacketName.Compare("C1") == 0))		//# 계열사
					{
						nItemFileType = GROUP_TYPE;
						
					}
				}
				
				if (nItemFileType != -1)
				{
					for (nFindIndex = 0; nFindIndex < saCode.GetSize(); nFindIndex++)
					{
						strTemp = saCode.GetAt(nFindIndex);
						if (strSetControlValues == saCode.GetAt(nFindIndex))
							break;
					}
				}
			}
			else
			{
				CString	strItemData = GetTagToControlNodeValues(strTagID, "COMBO_INDEX", i);
				// 20120723 ssj - 서버자동주문 >>
				if (HasExtraInfo(nResourceID))
				{
					strItemData = GetComboIndexByMarket(nResourceID);
				}
				// 20120723 ssj - 서버자동주문 <<

				strItemData += "/";
				
				int nFindPos;
				CString strSearchData; //추출된 패킷에 들어갈 데이터
				
				do
				{
					nFindPos = strItemData.Find('/');
					if (nFindPos == -1) 
					{
						nFindPos = 1;
						strSearchData = strItemData.Mid(0, nFindPos);
						break;
					}
					else
					{
						strSearchData = strItemData.Mid(0, nFindPos);
						nFindIndex++;
					}
					
					if (atoi(strSearchData) == atoi(strSetControlValues))
						break;
					
					strItemData = strItemData.Mid(nFindPos + 1, strItemData.GetLength() - nFindPos);
				}while(1);
			}
			
			pComboBoxWnd->SetCurSel(nFindIndex);
			pComboBoxWnd->Invalidate();
		}
}

//## Set Not Check Btn ##
if (CheckNotCheckBtnDrawState() == TRUE)
{
	int nNotCheck = (stUserDefine->Reverse == '1') ? 1 : 0;
	
	CButton* pNotCheck = (CButton*)GetDlgItem(IDC_BUTTON_NOTCHECK);
	pNotCheck->SetCheck(nNotCheck);
	pNotCheck->Invalidate();
}

//## Set Not Check Btn ##
if (CheckGubunCheckBtnDrawState() == TRUE)
{
	int nGubunCheck = (stUserDefine->IdxContiGubun == '1') ? 1 : 0;
	CButton* pGubunCheck = (CButton*)GetDlgItem(IDC_BUTTON_GUBUNCHECK);
	pGubunCheck->SetCheck(nGubunCheck);
	
	/*
	//# Case Order => Enable
	BOOL bEnable = (stUserDefine->GroupNo > 0) ? FALSE : TRUE;
	pGubunCheck->EnableWindow(bEnable);
	*/
	
	pGubunCheck->Invalidate();
}
}

void CMapLoadCtrl::OnSize(UINT nType, int cx, int cy) 
{
	CStatic::OnSize(nType, cx, cy);
	
	CRect reClient, reChkBtn, reBtn;
	GetClientRect(&reClient);
	reBtn = reClient;
	
	reChkBtn.top = reClient.top + 5;
	reChkBtn.bottom = reChkBtn.top + 20;
	reChkBtn.right = reClient.right - 5;
	if ((CheckNotCheckBtnDrawState() == TRUE) && (CheckGubunCheckBtnDrawState() == FALSE))
	{
		reChkBtn.left = reChkBtn.right - NOTCHECK_WIDTH;

		if ( m_pNotCheckBtn )
			m_pNotCheckBtn->MoveWindow(reChkBtn);	

	}
	else if ((CheckNotCheckBtnDrawState() == FALSE) && (CheckGubunCheckBtnDrawState() == TRUE))
	{
		reChkBtn.left = reChkBtn.right - GUBUNCHECK_WIDTH;

		if ( m_pNotCheckBtn )
			m_pNotCheckBtn->MoveWindow(reChkBtn);	
	}
	else if ((CheckNotCheckBtnDrawState() == TRUE) && (CheckGubunCheckBtnDrawState() == TRUE))
	{
		reChkBtn.left = reChkBtn.right - NOTCHECK_WIDTH;
		m_pNotCheckBtn->MoveWindow(reChkBtn);	
		
		reChkBtn.right = reChkBtn.left - 5;
		reChkBtn.left = reChkBtn.right - GUBUNCHECK_WIDTH;

		if ( m_pGubunCheckBtn )
			m_pGubunCheckBtn->MoveWindow(reChkBtn);	
	}
	
	OnSize_ConditionTitleStatic();
	
	reBtn.right = reClient.right - 5;
	reBtn.left = reBtn.right - m_nConstBtnWidth;	
	
	
	reBtn.bottom = reBtn.bottom - 5;
	reBtn.top = reBtn.bottom - m_nConstBtnHeight;
	if (CheckUpdataBtnDrawState() == TRUE)
	{
		if ( m_pUpdateBtn )
			m_pUpdateBtn->MoveWindow(reBtn);
	}
		
	reBtn.bottom = reBtn.top - 2;
	reBtn.top = reBtn.bottom - m_nConstBtnHeight;
	if (CheckBaseBtnDrawState() == TRUE)
	{
		if ( m_pBaseBtn )
			m_pBaseBtn->MoveWindow(reBtn); 
	}
		
	//# 기본값  
	reBtn.bottom = reBtn.top - 2;
	reBtn.top = reBtn.bottom - m_nConstBtnHeight;
	if (CheckOKBtnDrawState() == TRUE)
	{
		if ( m_pOKBtn )
			m_pBaseBtn->MoveWindow(reBtn); 
	}		
}

void CMapLoadCtrl::OnSize_ConditionTitleStatic()
{
	CRect reClient, reStatic;
	int nOffsetPos = 5;
	GetClientRect(reClient);
	if ((CheckNotCheckBtnDrawState() == TRUE) && (CheckGubunCheckBtnDrawState() == FALSE))
		nOffsetPos = (int)NOTCHECK_WIDTH + 5 * 2;
	else if (CheckGubunCheckBtnDrawState() == TRUE)
		nOffsetPos = (int)NOTCHECK_WIDTH + (int)GUBUNCHECK_WIDTH + 5 * 3;
	
	if (CheckConditionTitleStaticDrawState() == TRUE)
	{
		reStatic.left = reClient.left + POSITION_X_TITLE;
		reStatic.right = reClient.right - nOffsetPos;
		
		reStatic.top = reClient.top + 5;
		reStatic.bottom = reStatic.top + 15;

		if ( m_pConditionTitleStatic )
			m_pConditionTitleStatic->MoveWindow(reStatic);
	}
}

BOOL CMapLoadCtrl::PreTranslateMessage(MSG* pMsg) 
{
	/*
	if(pMsg->message == WM_KEYDOWN)
	{		
		if(pMsg->wParam == VK_RETURN)
		{
			//0000260: [자동주문]기능추가 및 로직변경 검토안
			if(pMsg->hwnd)
			{				
				CWnd* pWnd = CWnd::FromHandle(pMsg->hwnd);
				CWnd* pParent = pWnd->GetParent();
				if(pParent)
				{
					HWND hFocus = pParent->GetSafeHwnd();
					if(hFocus == m_editEarningRate.GetSafeHwnd())
					{
						OnBtnEarningRate();
					}
					else if(hFocus == m_editpreventLossRate.GetSafeHwnd())
					{
						OnBtnPreventLossRate();
					}
				}
			}

			HWND hParentHwnd = GetParent()->GetSafeHwnd();

			OnBtnUpdate();	
		}
		else if(pMsg->wParam == VK_ESCAPE)
			m_pwndMsgTarget->SendMessage(WM_NOTIFY_MAPLOAD, NM_MAPLOAD_CLOSE, (LPARAM)0);
	}
	*/
	
	return CStatic::PreTranslateMessage(pMsg);
}


HBRUSH CMapLoadCtrl::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CStatic::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if (nCtlColor == CTLCOLOR_STATIC)
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetBkColor(m_clrSkin);	// KB투자증권
		hbr = m_brushDefault;

	}

	return hbr;
}

void CMapLoadCtrl::PlatFormCheckBtnExNot()
{
	if(!m_pNotCheckBtn)
		return;
	BOOL bCheck = m_pNotCheckBtn->GetCheck();
	m_pNotCheckBtn->SetCheck(!bCheck);
	OnBtnNotCheck();
}

void CMapLoadCtrl::EuBtnUpdate()
{
	OnBtnUpdate();
}

void CMapLoadCtrl::EuBtnBase()
{
	OnBtnBase();
}

LRESULT CMapLoadCtrl::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{	//CConditionView -> CConditionresultwnd -> OnExpand()호출시
	//유진 (수정, 기본값)버튼 보이기/감추기 위한 플래그  
	if(message == CHANGE_EXP)
		m_TopExp = (int)lParam;
	
	return CStatic::WindowProc(message, wParam, lParam);
}

void CMapLoadCtrl::ChangeSkinColor(COLORREF clrBk)
{
	if(!clrBk)
		return;

	m_clrSkin = clrBk;

	//// 20120723 ssj - 서버자동주문 >>
	//if (m_pStcStkCodeName)
	//	m_pStcStkCodeName->SetStaticColor(COLOR_BORDER, m_clrSkin, RGB(0, 0, 0));
	//if (m_pStcIdxCodeName)
	//	m_pStcIdxCodeName->SetStaticColor(COLOR_BORDER, m_clrSkin, RGB(0, 0, 0));
	//if (m_pStcFutCodeName)
	//	m_pStcFutCodeName->SetStaticColor(COLOR_BORDER, m_clrSkin, RGB(0, 0, 0));
	//if (m_pStcOptCodeName)
	//	m_pStcOptCodeName->SetStaticColor(COLOR_BORDER, m_clrSkin, RGB(0, 0, 0));
	//// 20120723 ssj - 서버자동주문 <<

	if(m_brushDefault.DeleteObject())
		m_brushDefault.CreateSolidBrush(clrBk);
}


BOOL CMapLoadCtrl::OnEraseBkgnd(CDC* pDC)
{
	CRect rc;
	GetClientRect(rc);

	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);
	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());
	CBitmap* pOldbitmap = MemDC.SelectObject(&bitmap);

	MemDC.FillSolidRect(&rc, m_clrSkin);
	pDC->BitBlt(0, 0, rc.Width(), rc.Height(), &MemDC, 0, 0, SRCCOPY);
	return TRUE;
}

int CMapLoadCtrl::GetConditionMapCount()
{
	return m_saDelCtrlData.GetSize();	
}

void CMapLoadCtrl::OnChkMapCtrl(UINT nID)
{	
	
	CButton* pButton = (CButton*)GetDlgItem(nID);
	if(!pButton)
		return;

	BOOL bCheck = pButton->GetCheck();
	
		
	m_pwndMsgTarget->SendMessage(WM_NOTIFY_MAPLOAD, (WPARAM)NM_CHECK_CONDITION, (LPARAM)MAKEWPARAM(bCheck, nID));	
}

void CMapLoadCtrl::OnCmbMapCtrl(UINT nID)
{
	// 20120723 ssj - 서버자동주문 >>
	//.CDrCombo* pCombo = (CDrCombo*)GetDlgItem(nID);
	CComboBox* pCombo = (CComboBox*)GetDlgItem(nID);
	// 20120723 ssj - 서버자동주문 <<

	if(!pCombo)
		return;

	int nSel = pCombo->GetCurSel();
	int nLinkCtrlID = -1;

	int nInteger = 9;
	int nPoint = 0;
	
	POSITION pos;
	CString strKey;
	StCondKey* pStCondKey;
	for (pos = m_mapTagID.GetStartPosition(); pos != NULL;)
	{
		m_mapTagID.GetNextAssoc(pos, strKey, (void*&)pStCondKey);

		if(!pStCondKey)
			continue;

		if(pStCondKey->nComboID == nID)
		{
			nLinkCtrlID = pStCondKey->nLinkCtrlID;
			nPoint = pStCondKey->nPoint;
			break;
		}	
	}

	if(nLinkCtrlID == -1)
		return;

	CTEditCtrlWnd* pEdit = (CTEditCtrlWnd*)GetDlgItem(nLinkCtrlID);
	if(!pEdit)
		return;

	
	

	if(m_pBase && nPoint == 0)
	{
		/*
		CString strCode, strName;
		m_pBase->GetParent()->SendMessage(RMSG_GET_ITEMCODE, (WPARAM)&strCode, (LPARAM)&strName);
		int nMarketType = m_pBase->SendMessage(UMSG_GETMARKETTYPE, (WPARAM)(LPCTSTR)strCode, 0);

		if (nMarketType == CDRCodeTypeInfo::DRCODETYPE_KFUTURE ||
			nMarketType == CDRCodeTypeInfo::DRCODETYPE_KOPTION ||
			nMarketType == CDRCodeTypeInfo::DRCODETYPE_STOCKFUT || 
			nMarketType == CDRCodeTypeInfo::DRCODETYPE_STOCKOPT)
		*/
		if (IsDerivativesMap())
		{
			nPoint = 2;

			// 20120723 ssj - 서버자동주문 >>
			if (m_strMarket == SVRORD_MARKETTYPE_SFUT) // 주식선물의 경우 소숫점을 막자
				nPoint = 0;

			if (strKey == "-201") // BM조건에 주식은 소숫점없다
				nPoint = 0;
			// 20120723 ssj - 서버자동주문 <<
		}		
	}

	pEdit->SetText("");
	if(nSel == 0)	//현재가
	{
		pEdit->SetNumPlaces(nInteger, nPoint);
		pEdit->SetUseMinus(FALSE);
	}
	else if(nSel == 1)//대비
	{
		pEdit->SetNumPlaces(nInteger, nPoint);
		pEdit->SetUseMinus(TRUE);
	}
	else if(nSel == 2)//등락률
	{
		pEdit->SetNumPlaces(3, 2);
		pEdit->SetUseMinus(TRUE);
	}
	else if(nSel == 3)//거래량
	{
		pEdit->SetNumPlaces(9, 0);
		pEdit->SetUseMinus(FALSE);
	}
	if(m_bCmbInit)
	{
		pEdit->SetEditFocus();
		m_bCmbInit = TRUE;
	}

	// 20120723 ssj - 서버자동주문 >> 주식ELW에서의 시세조건탭의 경우 연관 컨트롤도 설정(-301과 -307)
	if (m_pCmbSync1 && m_pCmbSync1->GetSafeHwnd() == pCombo->GetSafeHwnd())
	{
		if (m_pCmbSync2 && m_pEditSync2)
		{
			m_pCmbSync2->SetCurSel(nSel);

			m_pEditSync2->SetText("");
			if(nSel == 0)	//현재가
			{
				m_pEditSync2->SetNumPlaces(nInteger, nPoint);
				m_pEditSync2->SetUseMinus(FALSE);
			}
			else if(nSel == 1)//대비
			{
				m_pEditSync2->SetNumPlaces(nInteger, nPoint);
				m_pEditSync2->SetUseMinus(TRUE);
			}
			else if(nSel == 2)//등락률
			{
				m_pEditSync2->SetNumPlaces(3, 2);
				m_pEditSync2->SetUseMinus(TRUE);
			}
			else if(nSel == 3)//거래량
			{
				m_pEditSync2->SetNumPlaces(9, 0);
				m_pEditSync2->SetUseMinus(FALSE);
			}

			m_pEditSync2->SetFocus();
		}
	}	
	

}

BOOL CMapLoadCtrl::GetCheckIsNotEmpty(CString strMapType)
{
	CString strTagID;
	CString strControlType;
	CString strData;
	StCondKey* pStCondKey;
	if(m_mapTagID.Lookup(strMapType, (void*&)pStCondKey))
	{
		if(!pStCondKey)
			return FALSE;
	}
	else
		return FALSE;	

	int nIndex;
	strTagID = pStCondKey->strTagID;
	CUIntArray* plarrResourceID;
	m_mapResourceID.Lookup(strTagID, (void*&)plarrResourceID);	

	CString strEditText;
	for(nIndex = 0; nIndex < plarrResourceID->GetCount(); nIndex++)
	{	
		strControlType = GetTagToControlNodeValues(strTagID, "TYPE", nIndex);	
		if(strControlType.Compare("Edit") == 0)
		{	
			// 20120723 ssj - 서버자동주문 >>
			//.CDrBtnCtrl* pBtn = (CDrBtnCtrl*)GetDlgItem(plarrResourceID->GetAt(nIndex));
			CButton* pBtn = (CButton*)GetDlgItem(plarrResourceID->GetAt(nIndex));
			// 20120723 ssj - 서버자동주문 <<

			if(!pBtn)
				return FALSE;

			pBtn->GetWindowText(strEditText);
			if(strEditText.IsEmpty())
				return FALSE;			
		}		
	}
	return TRUE;
}

void CMapLoadCtrl::SetValueToControl(CString strMapType, User_Define stUserDefine)
{
	// 20120723 ssj - 서버자동주문 >>
	CString strOrgType = strMapType;
	if (IsWindow(m_btnWon.GetSafeHwnd()) && IsWindow(m_btnPercent.GetSafeHwnd()) && IsWindow(m_btnTick.GetSafeHwnd()))
	{
		if (strOrgType.GetLength() > 3 && strOrgType.Left(3) == "-12") // -121, -122, ...
		{
			// 원
			m_btnPercent.SetCheck(BST_UNCHECKED);
			m_btnWon.SetCheck(BST_CHECKED);

			ChangePcntWonTitleTo("원", TRUE);
		}
		else if (strOrgType.GetLength() > 3 && strOrgType.Left(3) == "-11") // -111, -112, ...
		{
			// Tick
			m_btnPercent.SetCheck(BST_UNCHECKED);
			m_btnTick.SetCheck(BST_CHECKED);

			ChangePcntWonTitleTo("틱", TRUE);
		}
		else
		{
			// %
			m_btnPercent.SetCheck(BST_CHECKED);			
			if (IsEquitiesMap())
				m_btnWon.SetCheck(BST_UNCHECKED);
			else
				m_btnTick.SetCheck(BST_UNCHECKED);

			ChangePcntWonTitleTo("%", TRUE);
		}
	}
	strMapType = ConvertPercentWon(strOrgType);
	// 20120723 ssj - 서버자동주문 <<

	CString strTagID;
	CString strControlType;
	CString strData;
	StCondKey* pStCondKey;
	if(m_mapTagID.Lookup(strMapType, (void*&)pStCondKey))
	{
		if(!pStCondKey)
			return;
	}
	else
		return;	

	int nIndex;
	strTagID = pStCondKey->strTagID;
	CUIntArray* plarrResourceID;
	m_mapResourceID.Lookup(strTagID, (void*&)plarrResourceID);	

	for(nIndex = 0; nIndex < plarrResourceID->GetCount(); nIndex++)
	{	
		strControlType = GetTagToControlNodeValues(strTagID, "TYPE", nIndex);	
		if(strControlType.Compare("Edit") == 0)
		{	
			CTEditCtrlWnd* pEdit = (CTEditCtrlWnd*)GetDlgItem(plarrResourceID->GetAt(nIndex));
			if(!pEdit)
				return;

			CString strEditPacketID = GetTagToControlNodeValues(strTagID, "PACKET_ID", nIndex);

			CString strEditPacketName = strEditPacketID.Left(1);
			CString strEditPacketNum = strEditPacketID.Right(1);
			int nEditPacketNum = atoi(strEditPacketNum.operator const char*());

			if (strEditPacketName.Compare("C") == 0) 
			{	
				// 20120723 ssj - 서버자동주문 >>
				//strData.Format("%lf", stUserDefine.Condition[nEditPacketNum - 1]);
				//strData.TrimRight('0');
				//if(strData.Right(1) == ".")
				//	strData.Remove('.');			
				strData = CString((LPCTSTR)&stUserDefine.Condition[nEditPacketNum - 1], sizeof(stUserDefine.Condition[nEditPacketNum - 1]));
				strData.Trim();
				// 20120723 ssj - 서버자동주문 <<

				pEdit->SetText(strData);
				// 20120723 ssj - 서버자동주문 >>
				pEdit->AdjustText();
				// 20120723 ssj - 서버자동주문 <<
			}
			else if (strEditPacketName.Compare("P") == 0) 
			{
				pEdit->Invalidate();
			}	
		}
		if(strControlType.Compare("TimeCtrl") == 0)
		{	
			CDateTimeCtrl* pTimeCtrl = (CDateTimeCtrl*)GetDlgItem(plarrResourceID->GetAt(nIndex));
			if(!pTimeCtrl)
				return;

			CString strEditPacketID = GetTagToControlNodeValues(strTagID, "PACKET_ID", nIndex);

			CString strEditPacketName = strEditPacketID.Left(1);
			CString strEditPacketNum = strEditPacketID.Right(1);
			int nEditPacketNum = atoi(strEditPacketNum.operator const char*());

			if (strEditPacketName.Compare("C") == 0) 
			{				
				// 20120723 ssj - 서버자동주문 >>
				//strData.Format("%lf", stUserDefine.Condition[nEditPacketNum - 1]);
				//strData.TrimRight('0');
				//if(strData.Right(1) == ".")
				//	strData.Remove('.');
				strData = CString((LPCTSTR)&stUserDefine.Condition[nEditPacketNum - 1], sizeof(stUserDefine.Condition[nEditPacketNum - 1]));
				strData.Trim();
				// 20120723 ssj - 서버자동주문 <<

				strData.Format("%06d", atoi(strData));		

				CTime timeCur = CTime::GetCurrentTime();	
				CTime time(timeCur.GetYear(), timeCur.GetMonth(), timeCur.GetDay(), atoi(strData.Left(2)), atoi(strData.Mid(2, 2)), atoi(strData.Mid(4, 3)));

				pTimeCtrl->SetTime(&time);
			}
			else if (strEditPacketName.Compare("P") == 0) 
			{

			}	
			pTimeCtrl->Invalidate();
		}
		else if (strControlType.Compare("ComboBox") == 0) 
		{
			// 20120723 ssj - 서버자동주문 >>
			//.CDrCombo *pComboBox = (CDrCombo*)GetDlgItem(plarrResourceID->GetAt(nIndex));
			UINT nComboID = plarrResourceID->GetAt(nIndex);
			CComboBox *pComboBox = (CComboBox*)GetDlgItem(nComboID);
			// 20120723 ssj - 서버자동주문 <<			
			
			if (pComboBox == NULL)
				return;
			
			CString strComboText;				
			//int nSelecetedIndex = pComboBox->GetCurSel();

			CString strComboPacketID = GetTagToControlNodeValues(strTagID, "PACKET_ID", nIndex);
			if (!strComboPacketID.IsEmpty()) 
			{
				CString strSearchData;
				CString strComboPacketName = strComboPacketID.Left(1);
				int nComboPacketNum = atoi(strComboPacketID.Right(1).operator const char*());
				
				CString strComboLoadType = GetTagToControlNodeValues(strTagID, "COMBO_LOAD_TYPE", nIndex);
				if (atoi(strComboLoadType) == 1) 
				{
					CString strComboLoadData = GetTagToControlNodeValues(strTagID, "COMBO_LOAD_DATA", nIndex);				
				
				}
				else
				{
					CString	strItemData = GetTagToControlNodeValues(strTagID, "COMBO_INDEX", nIndex);
// 					strItemData += "/";
// 					
// 					int nFindPos;
// 					int nCount = 0;
// 					do
// 					{
// 						nFindPos = strItemData.Find('/');
// 						if (nCount > nSelecetedIndex)
// 							break;
// 						
// 						if (nFindPos == -1) 
// 						{
// 							nFindPos = 1;
// 							strSearchData = strItemData.Mid(0, nFindPos);
// 							break;
// 						}
// 						strSearchData = strItemData.Mid(0, nFindPos);
// 						strItemData = strItemData.Mid(nFindPos + 1, strItemData.GetLength() - nFindPos);
// 						nCount++;
// 					} while(1);
				}
				
				if (strComboPacketName.Compare("C") == 0) 
				{
					// 20120723 ssj - 서버자동주문 >>
					//strData.Format("%lf", stUserDefine.Condition[nComboPacketNum - 1]);
					//strData.TrimRight('0');
					//if(strData.Right(1) == ".")
					//	strData.Remove('.');	
					strData = CString((LPCTSTR)&stUserDefine.Condition[nComboPacketNum - 1], sizeof(stUserDefine.Condition[nComboPacketNum - 1]));
					strData.Trim();
					// 20120723 ssj - 서버자동주문 <<

					pComboBox->SetCurSel(atoi(strData));				
					OnCmbMapCtrl(nComboID);
				}
 				else if (strComboPacketName.Compare("T") == 0) 
 				{
 					int nComboSearchData = atoi(strSearchData.operator const char*());

					long lType1, lType2;
					// 20120723 ssj - 서버자동주문 >>
					//lType1 = stUserDefine.Type1;
					//lType2 = stUserDefine.Type2; 					
					lType1 = GetLong(stUserDefine.giType1, sizeof(stUserDefine.giType1));
					lType2 = GetLong(stUserDefine.giType2, sizeof(stUserDefine.giType2));
					// 20120723 ssj - 서버자동주문 <<
 
 					if((strMapType.Left(2).CompareNoCase(_T("-2")) == 0 || strMapType.Left(2).CompareNoCase(_T("-3")) == 0 || strMapType.Left(2).CompareNoCase(_T("-4")) == 0) &&
 							strComboPacketID.CompareNoCase("T1") == 0 )
					{
 						pComboBox->SetCurSel(lType1);							
						OnCmbMapCtrl(nComboID);
					}
 					else
					{
						// 20120723 ssj - 서버자동주문 >>
						//pComboBox->SetCurSel(lType2);
						if (pStCondKey && HasExtraInfo(plarrResourceID->GetAt(nIndex)))
						{
							CString strComboIndex = GetComboIndexByMarket(plarrResourceID->GetAt(nIndex));
							CStringArray arTemp;
							int nCnt = GetArgs(strComboIndex, arTemp, '/');
							for (int i = 0; i < nCnt; i++)
							{
								if (lType2 == atol(arTemp.GetAt(i)))
								{
									if (pComboBox->GetCount() > i)
									{
										pComboBox->SetCurSel(i);
										OnCmbMapCtrl(nComboID);
									}
								}
							}
						}
						else
						{
							pComboBox->SetCurSel(lType2);
							OnCmbMapCtrl(nComboID);
						}
						// 20120723 ssj - 서버자동주문 <<						
					}					
 				}
				else if (strComboPacketName.Compare("P") == 0) 
				{
					// 20120723 ssj - 서버자동주문 >>
					/*
					strData.Format("%lf", stUserDefine.Param[nComboPacketNum - 1]);
					strData.TrimRight('0');
					if(strData.Right(1) == ".")
						strData.Remove('.');	
					*/
					CString strTemp((char *)&stUserDefine.Param[nComboPacketNum - 1], sizeof(stUserDefine.Param[nComboPacketNum - 1]));		
					strTemp.Trim();
					strData.Format("%.0f", atof(strTemp));
					// 20120723 ssj - 서버자동주문 <<

					pComboBox->SetCurSel(atoi(strData));		
					OnCmbMapCtrl(nComboID);
				}			
			}
		} // "ComboBox"
	}

	// 20120723 ssj - 서버자동주문 >>
	if (m_pCmbSync1 && m_pCmbSync1->GetSafeHwnd() && m_pCmbSync2 && m_pCmbSync2->GetSafeHwnd())
	{
		int nSel1 = m_pCmbSync1->GetCurSel();
		int nSel2 = m_pCmbSync2->GetCurSel();
		if (nSel1 != nSel2)
			m_pCmbSync2->SetCurSel(nSel1);
	}
	// 20120723 ssj - 서버자동주문 <<

	//체크박스 체크처리 및 체크메세지처리
	CButton* pBtnChk = (CButton*)GetDlgItem(pStCondKey->nChkBtnID);
	pBtnChk->SetCheck(TRUE);
	m_pwndMsgTarget->SendMessage(WM_NOTIFY_MAPLOAD, (WPARAM)NM_CHECK_CONDITION, (LPARAM)MAKEWPARAM(TRUE, pStCondKey->nChkBtnID));
	
}

//BM조건 Key값 저장.
void CMapLoadCtrl::AddTagIDForMapType(CString strMapType, CString strTagID, int nChkBtnID)
{
	StCondKey* pStCondKey;
	if(m_mapTagID.Lookup(strMapType, (void*&)pStCondKey) == FALSE)
	{
		pStCondKey = new StCondKey;
		pStCondKey->strMapType = strMapType;

		if(!strTagID.IsEmpty())
			pStCondKey->strTagID = strTagID;

		if(nChkBtnID != -1)
			pStCondKey->nChkBtnID = nChkBtnID;		//컨트롤 세팅하는 부분에서 따로 세팅

		//초기화
		pStCondKey->nComboID = -1;
		pStCondKey->nLinkCtrlID = -1;

		m_mapTagID.SetAt(strMapType, (void*)pStCondKey);
	}
	else
	{
		if(!pStCondKey)
			return;

		pStCondKey->strMapType = strMapType;

		if(!strTagID.IsEmpty())
			pStCondKey->strTagID = strTagID;

		if(nChkBtnID != -1)
			pStCondKey->nChkBtnID = nChkBtnID;		//컨트롤 세팅하는 부분에서 따로 세팅
	
	}
}

//콤보박스 이벤트 ID
void CMapLoadCtrl::AddCtrlIDForMapType(CString strMapType, int nCmbID)
{
	StCondKey* pStCondKey;
	if(m_mapTagID.Lookup(strMapType, (void*&)pStCondKey) == TRUE)
	{
		if(!pStCondKey)
			return;

		pStCondKey->nComboID = nCmbID;
	}

}

//콤보박스와 연결된 EditCtrl ID
void CMapLoadCtrl::AddLinkEventCtrlIDForMapType(CString strMapType, int nLinkCtrlID, int nPoint)
{
	StCondKey* pStCondKey;
	if(m_mapTagID.Lookup(strMapType, (void*&)pStCondKey) == TRUE)
	{
		if(!pStCondKey)
			return;

		pStCondKey->nLinkCtrlID = nLinkCtrlID;
		pStCondKey->nPoint = nPoint;
	}
	
}

void CMapLoadCtrl::SetInitChkCtrl()
{
	// 20120723 ssj - 서버자동주문 >>
	if (m_bAddSysCtrl)
	{
		m_btnPercent.SetCheck(BST_CHECKED);
		if (IsEquitiesMap())
			m_btnWon.SetCheck(BST_UNCHECKED);
		else
			m_btnTick.SetCheck(BST_UNCHECKED);

		ChangePcntWonTitleTo("%", TRUE);
		//m_stcBasePriceTitle;
		
		m_btnMatchPrice.SetCheck(BST_CHECKED);
		m_btnUserPrice.SetCheck(BST_UNCHECKED);
		OnBtnMatchPrice();

		//m_edtUserPrice.SetWindowText("");
		//m_stcSuffix;
	}
	// 20120723 ssj - 서버자동주문 <<

	POSITION pos;
	CString strKey;
	StCondKey* pStCondKey;
	CButton* pBtnChk;
	for (pos = m_mapTagID.GetStartPosition(); pos != NULL;)
	{
		m_mapTagID.GetNextAssoc(pos, strKey, (void*&)pStCondKey);

		if(!pStCondKey)
			continue;

		pBtnChk = (CButton*)GetDlgItem(pStCondKey->nChkBtnID);
		pBtnChk->SetCheck(FALSE);
		m_pwndMsgTarget->SendMessage(WM_NOTIFY_MAPLOAD, (WPARAM)NM_CHECK_CONDITION, (LPARAM)MAKEWPARAM(FALSE, pStCondKey->nChkBtnID));
	}
}

void CMapLoadCtrl::ChangeCmbMessage(int nIndex, CString strMapType, int nID)
{
	int nComboID;
	StCondKey* pStCondKey;
	if(m_mapTagID.Lookup(strMapType, (void*&)pStCondKey) == TRUE)
	{
		if(!pStCondKey)
			return;

		nComboID = pStCondKey->nComboID;
	}

	// 20120723 ssj - 서버자동주문 >>
	//.CDrCombo* pCombo = (CDrCombo*)GetDlgItem(nComboID);
	CComboBox* pCombo = (CComboBox*)GetDlgItem(nComboID);
	// 20120723 ssj - 서버자동주문 <<

	if(!pCombo)
		return;
	pCombo->SetCurSel(nIndex);

	m_bCmbInit = FALSE;
	OnCmbMapCtrl(nComboID);

}

//>>[0000260] 손실제한률, 목표이익률 수익률이 자동으로 셋팅 SJ_KIM(20110720)

void CMapLoadCtrl::OnBtnEarningRate()
{		
	SetCalcRate(FALSE);
}


void CMapLoadCtrl::OnBtnPreventLossRate()
{	
	SetCalcRate(TRUE);
}

//<<[0000260] 손실제한률, 목표이익률 수익률이 자동으로 셋팅 SJ_KIM(20110720)

// 20120723 ssj - 서버자동주문 >>
void CMapLoadCtrl::MoveCodeInputCtrl()
{
	/*
	m_ctlStkCodeInput.MoveWindow(m_rtJCode);
	m_ctlIdxCodeInput.MoveWindow(m_rtUpCode);
	m_ctlFutCodeInput.MoveWindow(m_rtFCode);
	m_ctlOptCodeInput.MoveWindow(m_rtOCode);
	*/
}
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
int CMapLoadCtrl::GetSelEvalUnit()
{
	// EVAL_UNIT_PERCENT: %, EVAL_UNIT_WON: 원, EVAL_UNIT_TICK: tick
	if (m_btnPercent.GetCheck() == BST_CHECKED)
		return EVAL_UNIT_PERCENT;
	else
	{
		if (IsEquitiesMap())
			return EVAL_UNIT_WON;
		else
			return EVAL_UNIT_TICK;
	}
}
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
int CMapLoadCtrl::GetBasePriceType()
{
	// BASE_TYPE_MATCH: 매입가, BASE_TYPE_USER: 기준가
	if (m_btnMatchPrice.GetCheck() == BST_CHECKED)
		return BASE_TYPE_MATCH;
	else
		return BASE_TYPE_USER;
}
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
CString CMapLoadCtrl::GetBasePrice()
{
	CString strUserPrice;
	m_edtUserPrice.GetWindowText(strUserPrice);
	strUserPrice.Trim();
	strUserPrice.Replace(",", "");
	return strUserPrice;
}
// 20120723 ssj - 서버자동주문 <<

void CMapLoadCtrl::ChangePcntWonTitleTo(CString str, BOOL bChangeEdit)
{
	if (str == "%")
	{
		// 원, 틱 -> %
		int nCnt = m_arStatics.GetCount();
		for (int i = 0; i < nCnt; i++)
		{
			CStatic *pStatic = m_arStatics.GetAt(i);
			CString strText;
			pStatic->GetWindowText(strText);
			if (IsEquitiesMap())
				strText.Replace("원", "%");
			else
				strText.Replace("틱", "%");
			pStatic->SetWindowText(strText);
		}

		if (bChangeEdit)
		{
			// 에디트박스의 자릿수, 소숫점
			int nCnt = m_arEdits.GetCount();
			for (int i = 0; i < nCnt; i++)
			{
				CTEditCtrlWnd *pEdit = m_arEdits.GetAt(i);
				if (pEdit == NULL)
					continue;
				
				CString strText;
				pEdit->GetWindowText(strText);
				strText.Trim();
				strText.Remove(',');
				if (atof(strText) > 100.0)
				{
					strText = "100";
					pEdit->SetNumPlaces(3, 2);
					pEdit->SetText(strText);
				}
				else
				{
					pEdit->SetNumPlaces(3, 2);
					pEdit->AdjustText();
				}
			}
		}

		// 가,틱 -> 률
		if (m_pStaticLossTitle)
			m_pStaticLossTitle->SetWindowText("손실제한률");
		if (m_pStaticProfitTile)
			m_pStaticProfitTile->SetWindowText("목표이익률");

		m_editpreventLossRate.ShowWindow(SW_SHOW);
		m_btnpreventLossRate.ShowWindow(SW_SHOW);
		m_editEarningRate.ShowWindow(SW_SHOW);
		m_btnEarningRate.ShowWindow(SW_SHOW);
	}
	else if (str == "원")
	{
		// % -> 원
		int nCnt = m_arStatics.GetCount();
		for (int i = 0; i < nCnt; i++)
		{
			CStatic *pStatic = m_arStatics.GetAt(i);
			CString strText;
			pStatic->GetWindowText(strText);
			strText.Replace("%", "원");
			pStatic->SetWindowText(strText);
		}

		if (bChangeEdit)
		{
			int nCnt = m_arEdits.GetCount();
			for (int i = 0; i < nCnt; i++)
			{
				CTEditCtrlWnd *pEdit = m_arEdits.GetAt(i);
				if (pEdit == NULL)
					continue;

				pEdit->SetNumPlaces(9, 0);
				pEdit->AdjustText();
			}
		}

		// 률->가
		if (m_pStaticLossTitle)
			m_pStaticLossTitle->SetWindowText("손실제한가");
		if (m_pStaticProfitTile)
			m_pStaticProfitTile->SetWindowText("목표이익가");

		m_editpreventLossRate.ShowWindow(SW_HIDE);
		m_btnpreventLossRate.ShowWindow(SW_HIDE);
		m_editEarningRate.ShowWindow(SW_HIDE);
		m_btnEarningRate.ShowWindow(SW_HIDE);
	}
	else if (str == "틱")
	{
		// % -> 틱
		int nCnt = m_arStatics.GetCount();
		for (int i = 0; i < nCnt; i++)
		{
			CStatic *pStatic = m_arStatics.GetAt(i);
			CString strText;
			pStatic->GetWindowText(strText);
			strText.Replace("%", "틱");
			pStatic->SetWindowText(strText);
		}

		if (bChangeEdit)
		{
			int nCnt = m_arEdits.GetCount();
			for (int i = 0; i < nCnt; i++)
			{
				CTEditCtrlWnd *pEdit = m_arEdits.GetAt(i);
				if (pEdit == NULL)
					continue;

				pEdit->SetNumPlaces(9, 0);
				pEdit->AdjustText();
			}
		}

		// 률->가
		if (m_pStaticLossTitle)
			m_pStaticLossTitle->SetWindowText("손실제한틱");
		if (m_pStaticProfitTile)
			m_pStaticProfitTile->SetWindowText("목표이익틱");

		m_editpreventLossRate.ShowWindow(SW_HIDE);
		m_btnpreventLossRate.ShowWindow(SW_HIDE);
		m_editEarningRate.ShowWindow(SW_HIDE);
		m_btnEarningRate.ShowWindow(SW_HIDE);
	}
}

// 20120723 ssj - 서버자동주문 >>
void CMapLoadCtrl::OnBtnPercent()
{
	ChangePcntWonTitleTo("%", FALSE);

	if (IsEquitiesMap()) // 주식의 경우는 에디트 박스의 값으로 %를 계산한다
	{
		CString strCode = GetCurSelCode();
		CString strMatchPrice = GetMatchPrice(strCode);
		double dMatchPrice = atof(strMatchPrice);

		// 에디트박스의 자릿수, 소숫점
		double dBase = 0.0;
		int nCnt = m_arEdits.GetCount();
		for (int i = 0; i < nCnt; i++)
		{
			CTEditCtrlWnd *pEdit = m_arEdits.GetAt(i);
			if (pEdit == NULL)
				continue;

			// 기존 입력된 금액을 %로 변경
			CString strText;
			pEdit->GetWindowText(strText);
			strText.Trim();
			strText.Remove(',');
			double dEdit = atof(strText);
			double dRate = 0.0;
			BOOL bChangeText = TRUE;
			CString strNewVal;

			if (IsSame(dMatchPrice, 0)) //fabs(dMatchPrice - 0.0) <= 0.0001) // == 0
			{
				strNewVal = "";
			}
			else
			{
				switch (i)
				{
				case 0: // 손실제한률
				case 1: // 목표이익률
				case 2: // 목표보정
					dRate = (dMatchPrice - dEdit) / dMatchPrice * 100;
					strNewVal.Format("%.2f", fabs(dRate));
					break;

				case 3: // 고가대비 하락
					strNewVal = "";
					break;

				case 4: // 고가대비 목표보전
					bChangeText = FALSE;
					break;

				case 5: // 손실보전
					dBase = dEdit;

					dRate = (dEdit - dMatchPrice) / dMatchPrice * 100;
					strNewVal.Format("%.2f", fabs(dRate));
					break;

				case 6: // 손실제한가 대비 상승
				case 7: // 손실제한가 추가 하락
					if (IsSame(dBase, 0)) // fabs(dBase) < 0.0001 ) // == 0
					{
						strNewVal = "";
					}
					else
					{
						dRate = dEdit / dBase * 100;
						strNewVal.Format("%.2f", fabs(dRate));
					}
					break;
				}
			}
			
			pEdit->SetNumPlaces(3, 2);
			if (bChangeText)
				pEdit->SetText(strNewVal);
			pEdit->AdjustText();
		}
	}
	else
	{
		int nCnt = m_arEdits.GetCount();
		for (int i = 0; i < nCnt; i++)
		{
			CTEditCtrlWnd *pEdit = m_arEdits.GetAt(i);
			if (pEdit == NULL)
				continue;			
			pEdit->SetNumPlaces(3, 2);
			pEdit->SetText("");
			pEdit->AdjustText();
		}
	}
}
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
void CMapLoadCtrl::OnBtnWon()
{
	ChangePcntWonTitleTo("원", FALSE);

	CString strCode = GetCurSelCode();
	CString strMatchPrice = GetMatchPrice(strCode);
	double dMatchPrice = atof(strMatchPrice);

	// 에디트박스의 자릿수, 소숫점
	double dBase = 0.0;
	int nCnt = m_arEdits.GetCount();
	for (int i = 0; i < nCnt; i++)
	{
		CTEditCtrlWnd *pEdit = m_arEdits.GetAt(i);
		if (pEdit == NULL)
			continue;			

		// 기존 입력된 %을 금액으로 변경
		CString strText;
		pEdit->GetWindowText(strText);
		double dEdit = atof(strText);
		strText.Trim();
		strText.Remove(',');
		double dAmt = 0.0;
		BOOL bChangeText = TRUE;
		CString strNewVal;

		if (IsSame(dMatchPrice, 0))// fabs(dMatchPrice - 0.0) <= 0.0001) // == 0
		{
			strNewVal = "";
		}
		else
		{
			switch (i)
			{
			case 0: // 손실제한률
				dAmt = dMatchPrice - (dMatchPrice * dEdit / 100.0);
				strNewVal.Format("%.0f", dAmt);
				break;

			case 1: // 목표이익률
			case 2: // 목표보정
				dAmt = dMatchPrice + (dMatchPrice * dEdit / 100.0);
				strNewVal.Format("%.0f", dAmt);
				break;

			case 3: // 고가대비 하락
				strNewVal = "";
				break;

			case 4: // 고가대비 목표보전
				bChangeText = FALSE;
				break;

			case 5: // 손실보전
				dAmt = dMatchPrice - (dMatchPrice * dEdit / 100.0);
				strNewVal.Format("%.0f", dAmt);

				dBase = dAmt;
				break;

			case 6: // 손실제한가 대비 상승
			case 7: // 손실제한가 추가 하락
				if (IsSame(dBase, 0)) // fabs(dBase) < 0.0001 ) // == 0
				{
					strNewVal = "";
				}
				else
				{
					dAmt = dBase * dEdit / 100;
					strNewVal.Format("%.0f", dAmt);
				}
				break;
			}
		}

		pEdit->SetNumPlaces(9, 0);
		if (bChangeText)
			pEdit->SetText(strNewVal);
		pEdit->AdjustText();
	}
}
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
void CMapLoadCtrl::OnBtnTick()
{
	ChangePcntWonTitleTo("틱", FALSE);
	
	// 에디트박스의 자릿수, 소숫점
	int nCnt = m_arEdits.GetCount();
	for (int i = 0; i < nCnt; i++)
	{
		CTEditCtrlWnd *pEdit = m_arEdits.GetAt(i);
		if (pEdit == NULL)
			continue;			
		pEdit->SetNumPlaces(9, 0);
		pEdit->SetText("");
		pEdit->AdjustText();
	}

	/*
	CString strCode = GetCurSelCode();
	CString strMatchPrice = GetMatchPrice(strCode);
	double dMatchPrice = atof(strMatchPrice);

	// 에디트박스의 자릿수, 소숫점
	double dBase = 0.0;
	int nCnt = m_arEdits.GetCount();
	for (int i = 0; i < nCnt; i++)
	{
		CTEditCtrlWnd *pEdit = m_arEdits.GetAt(i);

		// 기존 입력된 %을 금액으로 변경
		CString strText;
		pEdit->GetWindowText(strText);
		double dEdit = atof(strText);
		strText.Trim();
		strText.Remove(',');
		double dAmt = 0.0;
		BOOL bChangeText = TRUE;
		CString strNewVal;

		if (IsSame(dMatchPrice, 0))// fabs(dMatchPrice - 0.0) <= 0.0001) // == 0
		{
			strNewVal = "";
		}
		else
		{
			switch (i)
			{
			case 0: // 손실제한률
				dAmt = dMatchPrice - (dMatchPrice * dEdit / 100.0);
				strNewVal.Format("%.0f", dAmt);
				break;

			case 1: // 목표이익률
			case 2: // 목표보정
				dAmt = dMatchPrice + (dMatchPrice * dEdit / 100.0);
				strNewVal.Format("%.0f", dAmt);
				break;

			case 3: // 고가대비 하락
				strNewVal = "";
				break;

			case 4: // 고가대비 목표보전
				bChangeText = FALSE;
				break;

			case 5: // 손실보전
				dAmt = dMatchPrice - (dMatchPrice * dEdit / 100.0);
				strNewVal.Format("%.0f", dAmt);

				dBase = dAmt;
				break;

			case 6: // 손실제한가 대비 상승
			case 7: // 손실제한가 추가 하락
				if (IsSame(dBase, 0)) // fabs(dBase) < 0.0001 ) // == 0
				{
					strNewVal = "";
				}
				else
				{
					dAmt = dBase * dEdit / 100;
					strNewVal.Format("%.0f", dAmt);
				}
				break;
			}
		}

		pEdit->SetNumPlaces(9, 0);
		if (bChangeText)
			pEdit->SetText(strNewVal);
		pEdit->AdjustText();
	}
	*/
}
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
void CMapLoadCtrl::OnBtnMatchPrice()
{
	m_edtUserPrice.SetWindowText("");
	m_edtUserPrice.ShowWindow(SW_HIDE);
	m_stcSuffix.ShowWindow(SW_HIDE);
}
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
void CMapLoadCtrl::OnBtnBasePrice()
{
	m_edtUserPrice.ShowWindow(SW_SHOW);
	m_stcSuffix.ShowWindow(SW_SHOW);
}
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
CString CMapLoadCtrl::ConvertPercentWon(CString strMapType)
{
	CString strRet = strMapType;
	if (strMapType.GetLength() < 3)
		return strRet;

	if (strMapType.Left(3) == "-10") // %
	{
		m_btnPercent.SetCheck(BST_CHECKED);
		if (IsEquitiesMap())
			m_btnWon.SetCheck(BST_UNCHECKED);
		else
			m_btnTick.SetCheck(BST_UNCHECKED);
	}
	else if (strMapType.Left(3) == "-11") // tick
	{
		strRet = "-10" + strMapType.Right(1);

		m_btnPercent.SetCheck(BST_UNCHECKED);
		if (IsEquitiesMap())
			m_btnWon.SetCheck(BST_CHECKED);
		else
			m_btnTick.SetCheck(BST_CHECKED);
	}
	else if (strMapType.Left(3) == "-12") // 원
	{
		strRet = "-10" + strMapType.Right(1);

		m_btnPercent.SetCheck(BST_UNCHECKED);
		if (IsEquitiesMap())
			m_btnWon.SetCheck(BST_CHECKED);
		else
			m_btnTick.SetCheck(BST_CHECKED);
	}

	return strRet;
}
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
void CMapLoadCtrl::SetCalcRate(BOOL bLoss)
{
	CString strCode = GetCurSelCode();
	CString strMatchPrice = GetMatchPrice(strCode);
	int nPosition = POS_BUY; // 디폴트는 매수잔고
	if (m_nMapMode == MODE_DERIVATIVES)
		nPosition = GetPositions(strCode); // 선옵인경우는 매도,매수잔고 확인

	double dMatchPrice = atof(strMatchPrice);
	if (IsSame(dMatchPrice, 0)) // fabs(dMatchPrice - 0.0) <= 0.0001)
	{
		DefMessageBox(GetSafeHwnd(), _T("해당 종목은 매입단가가 없어 수익률 계산이 되지 않습니다"));
		return;
	}	

	if (nPosition == -1)
	{
		DefMessageBox(GetSafeHwnd(), _T("해당 종목 포지션 확인 불가로 수익률 계산이 되지 않습니다"));
		return;
	}

	CString strEdit;
	if (bLoss)
		m_editpreventLossRate.GetWindowText(strEdit);
	else
		m_editEarningRate.GetWindowText(strEdit);
	strEdit.Remove(',');
	if(strEdit == "")
		return;
	double dEdit = atof(strEdit);

	double dRate = 0;
	CWnd* pWnd = NULL;
	if (bLoss)
	{
		if (nPosition == POS_BUY)
		{
			if (dMatchPrice < dEdit)
			{
				DefMessageBox(GetSafeHwnd(), _T("매수단가 보다 낮은 가격을 입력 하여 주세요"));
				return;
			}
		}
		else
		{
			if (dMatchPrice > dEdit)
			{
				DefMessageBox(GetSafeHwnd(), _T("매도단가 보다 높은 가격을 입력 하여 주세요"));
				return;
			}
		}

		//dRate = (dEdit - dMatchPrice) / dMatchPrice * 100; //100 - ((dEdit / dMatchPrice) * 100.0);
		//strEdit.Format("%.2lf", dRate);

		pWnd = GetDlgItem(m_nIDPreventLossRate);
	}
	else
	{
		if (nPosition == POS_BUY)
		{
			if (dMatchPrice > dEdit)
			{
				DefMessageBox(GetSafeHwnd(), _T("매수단가 보다 높은 가격을 입력 하여 주세요"));
				return;
			}
		}
		else
		{
			if (dMatchPrice < dEdit)
			{
				DefMessageBox(GetSafeHwnd(), _T("매도단가 보다 낮은 가격을 입력 하여 주세요"));
				return;
			}
		}

		//dRate = (dMatchPrice - dEdit) / dMatchPrice * 100; //(dEdit / dMatchPrice) * 100 - 100;
		//strEdit.Format("%.2lf", dRate);

		pWnd = GetDlgItem(m_nIDEarningRate);
	}

	if(pWnd)
	{
		if (nPosition == POS_BUY)
			dRate = (dEdit - dMatchPrice) / dMatchPrice * 100;
		else
			dRate = (dMatchPrice - dEdit) / dMatchPrice * 100;

		strEdit.Format("%.2f", fabs(dRate));

		pWnd->SetWindowText(strEdit);
		pWnd->Invalidate();
	}
}


CString	CMapLoadCtrl::GetCurSelCode()
{
	return m_pBase->GetCurCode();
}

int CMapLoadCtrl::GetPositions(CString strCode)
{
	return m_pBase->GetPositions(strCode);
}

CString	CMapLoadCtrl::GetMatchPrice(CString strCode)
{
	if (m_btnMatchPrice.GetCheck() == BST_CHECKED)
		// 매입가가 체크되어 있으면 잔고 그리드에서 매수단가를 찾는다
		return m_pBase->GetMatchPrice(strCode, MPRICE_MATCH);
	else
	{
		// 수정단가가 체크되어 있으면 현재 입력한 단가 리턴
		CString strUserPrice;
		m_edtUserPrice.GetWindowText(strUserPrice);
		strUserPrice.Trim();
		strUserPrice.Remove(',');
		if (strUserPrice.GetLength() > 0)
			return strUserPrice;
		else
			// 없으면 그리드에서 수정단가 찾는다
			return m_pBase->GetMatchPrice(strCode, MPRICE_USER);
	}
}

void CMapLoadCtrl::ChangeMarketTo(CString strMarket)
{
	// 같으면 리턴
	if (m_strMarket == strMarket)
		return;

	// 선물인데 옵션, 옵션인데 선물이 들어오면 리턴
	if ((m_strMarket == SVRORD_MARKETTYPE_FUT && strMarket == SVRORD_MARKETTYPE_OPT) || 
		(m_strMarket == SVRORD_MARKETTYPE_OPT && strMarket == SVRORD_MARKETTYPE_FUT))
	{
		m_strMarket = strMarket;
		return;
	}

	m_strMarket = strMarket;

	if (strMarket == SVRORD_MARKETTYPE_STOCK || strMarket == SVRORD_MARKETTYPE_ELW)
	{
		// 시세조건의 경우 ELW는 상한/하한 등이 없다
		if (m_nCondType == COND_Q)
		{
			int nCnt = m_arrCmbExtraInfo.GetCount();
			for (int i = 0; i < nCnt; i++)
			{
				CComboBoxExtraInfo *p = m_arrCmbExtraInfo.GetAt(i);
				if (p == NULL)
					continue;

				CComboBox *pCmb = (CComboBox *)GetDlgItem(p->m_unResourceID);
				if (pCmb == NULL)
					continue;

				pCmb->ResetContent();

				CString strComboItem;
				if (strMarket == SVRORD_MARKETTYPE_STOCK)
					strComboItem = p->m_strComboItem;
				else if (strMarket == SVRORD_MARKETTYPE_ELW)
					strComboItem = p->m_strComboItemExtra;

				int nFindPos;
				do
				{
					nFindPos = strComboItem.Find('/');
					if (nFindPos < 0) 
					{
						pCmb->AddString((LPCTSTR)strComboItem);
						break;
					}
					pCmb->AddString((LPCTSTR)strComboItem.Mid(0, nFindPos));
					strComboItem = strComboItem.Mid(nFindPos + 1, strComboItem.GetLength() - nFindPos);
				}while(1);

				if (pCmb->GetCount() > 0)
					pCmb->SetCurSel(0);
			}
		}
	}
	else
	{
		// BM조건의 경우 종목 컨트롤들 처리
		if (m_nCondType == COND_BM)
		{
			if (strMarket == SVRORD_MARKETTYPE_FUT || strMarket == SVRORD_MARKETTYPE_OPT)
				AdjustCtrlToFO();
			else if (strMarket == SVRORD_MARKETTYPE_SFUT)
				AdjustCtrlToFO(FALSE);
		}

		// 시세조건에서는 콤보는 모두 재처리(소숫점 때문)
		if (m_nCondType == COND_Q)
		{
			POSITION pos = m_mapAllCtrlList.GetStartPosition();
			while (pos != NULL)
			{
				CMapStringToPtr *pMapCtrl = NULL;
				CString strMapType;
				m_mapAllCtrlList.GetNextAssoc(pos, strMapType, (void *&)pMapCtrl);
				if (pMapCtrl != NULL && strMapType.GetLength() > 2 && strMapType.Left(2) == "-3") // -3xx 시세조건
				{
					POSITION posInner = pMapCtrl->GetStartPosition();
					while (posInner != NULL)
					{
						CCtrlInfo *pCtrlInfo = NULL;
						CString strID;
						pMapCtrl->GetNextAssoc(posInner, strID, (void *&)pCtrlInfo);
						if (pCtrlInfo && pCtrlInfo->m_strCtrlType.CompareNoCase("ComboBox") == 0)
							OnCmbMapCtrl(pCtrlInfo->m_nResourceID); // 콤보박스 이벤트를 호출해서 연관에디트의 소숫점을 맞추자
					}
				}
			}		
		}
	}
}

BOOL CMapLoadCtrl::HasExtraInfo(UINT nResourceID)
{
	if (m_strMarket != SVRORD_MARKETTYPE_STOCK && m_strMarket != SVRORD_MARKETTYPE_ELW)
		return FALSE;

	int nCnt = m_arrCmbExtraInfo.GetCount();
	for (int i = 0; i < nCnt; i++)
	{
		CComboBoxExtraInfo *p = m_arrCmbExtraInfo.GetAt(i);
		if (p == NULL)
			continue;

		if (nResourceID == p->m_unResourceID)
			return TRUE;
	}
	return FALSE;
}

CString CMapLoadCtrl::GetComboIndexByMarket(UINT nResourceID)
{
	if (m_strMarket != SVRORD_MARKETTYPE_STOCK && m_strMarket != SVRORD_MARKETTYPE_ELW)
		return "";

	int nCnt = m_arrCmbExtraInfo.GetCount();
	for (int i = 0; i < nCnt; i++)
	{
		CComboBoxExtraInfo *p = m_arrCmbExtraInfo.GetAt(i);
		if (p == NULL)
			continue;

		if (nResourceID == p->m_unResourceID)
		{
			if (m_strMarket == SVRORD_MARKETTYPE_STOCK)
				return p->m_strComboIndex;
			else if (m_strMarket == SVRORD_MARKETTYPE_ELW)
				return p->m_strComboIndexExtra;
		}
	}

	return "";
}

LRESULT CMapLoadCtrl::OnEventCodeInput(WPARAM wParam, LPARAM lParam)
{
	/*LPST_CTRLEVENT stEvent = (LPST_CTRLEVENT)lParam;
	if (strcmp(stEvent->lpszEventName, "LengthFull") == 0 || strcmp(stEvent->lpszEventName, "SelChanged") == 0)
	{
		CString strCode;
		HWND hWnd = (HWND)wParam;
		if (hWnd == m_ctlStkCodeInput.GetSafeHwnd() && m_pStcStkCodeName)
			m_pStcStkCodeName->SetWindowText(" " + GetEquitiesCodeName(m_ctlStkCodeInput.GetDataText()));
		else if (hWnd == m_ctlIdxCodeInput.GetSafeHwnd() && m_pStcIdxCodeName)
			m_pStcIdxCodeName->SetWindowText(" " + GetIndexCodeName(m_ctlIdxCodeInput.GetDataText()));
		else if (hWnd == m_ctlFutCodeInput.GetSafeHwnd() && m_pStcFutCodeName)
			m_pStcFutCodeName->SetWindowText(" " + GetDerivativesCodeName(m_ctlFutCodeInput.GetDataText()));
		else if (hWnd == m_ctlOptCodeInput.GetSafeHwnd() && m_pStcOptCodeName)
			m_pStcOptCodeName->SetWindowText(" " + GetDerivativesCodeName(m_ctlOptCodeInput.GetDataText()));
	}*/

	return 0;
}

void CMapLoadCtrl::AddToAllCtrlList(CString strMapType, CString strID, CString strCtrlType, UINT nResourceID, CWnd *pWndCtrl, CString strExtra)
{
	CMapStringToPtr *pMapCtrl = NULL;
	m_mapAllCtrlList.Lookup(strMapType, (void *&)pMapCtrl);
	if (pMapCtrl == NULL)
	{
		pMapCtrl = new CMapStringToPtr;
		m_mapAllCtrlList.SetAt(strMapType, pMapCtrl);
	}

	CCtrlInfo *pCtrlInfo = NULL;
	pMapCtrl->Lookup(strID, (void *&)pCtrlInfo);
	if (pCtrlInfo == NULL)
	{
		pCtrlInfo = new CCtrlInfo;
		pMapCtrl->SetAt(strID, pCtrlInfo);
	}

	pCtrlInfo->m_strMapType = strMapType;
	pCtrlInfo->m_strID = strID;
	pCtrlInfo->m_strCtrlType = strCtrlType;
	pCtrlInfo->m_nResourceID = nResourceID;
	pCtrlInfo->m_pWnd = pWndCtrl;
	pCtrlInfo->m_strExtraInfo = strExtra;
}

void CMapLoadCtrl::RemoveAllCtrlList()
{
	POSITION pos = m_mapAllCtrlList.GetStartPosition();
	while (pos != NULL)
	{
		CMapStringToPtr *pMapCtrl = NULL;
		CString strMapType;
		m_mapAllCtrlList.GetNextAssoc(pos, strMapType, (void *&)pMapCtrl);

		if (pMapCtrl)
		{
			POSITION pos2 = pMapCtrl->GetStartPosition();
			while (pos2 != NULL)
			{
				CCtrlInfo *pCtrlInfo = NULL;
				CString strID;
				pMapCtrl->GetNextAssoc(pos2, strID, (void *&)pCtrlInfo);
				if (pCtrlInfo)
					delete pCtrlInfo;
			}

			pMapCtrl->RemoveAll();

			delete pMapCtrl;
		}
	}
	m_mapAllCtrlList.RemoveAll();
}
//
//void CMapLoadCtrl::ShowCtrl(int nCmdShow, CString strMapType, CExCodeInput *pExCodeInput) 
//{
//	CMapStringToPtr *pMapCtrl = NULL;
//	m_mapAllCtrlList.Lookup(strMapType, (void *&)pMapCtrl);
//	if (pMapCtrl)
//	{
//		POSITION pos = pMapCtrl->GetStartPosition();
//		while (pos != NULL)
//		{
//			CString strID;
//			CCtrlInfo *pCtrlInfo = NULL;
//			pMapCtrl->GetNextAssoc(pos,  strID, (void *&)pCtrlInfo);
//			if (pCtrlInfo)
//			{
//				if (pCtrlInfo->m_pWnd && pCtrlInfo->m_strExtraInfo.GetLength() <= 0)
//					pCtrlInfo->m_pWnd->ShowWindow(nCmdShow);
//			}
//		}
//	}
//
//	if (pExCodeInput)
//		pExCodeInput->ShowWindow(nCmdShow);
//
//	// 체크 버튼
//	StCondKey* pStCondKey = NULL;
//	m_mapTagID.Lookup(strMapType, (void*&)pStCondKey);
//	if (pStCondKey)
//	{
//		if (pStCondKey->nChkBtnID != -1)
//		{
//			CWnd *pWnd = GetDlgItem(pStCondKey->nChkBtnID);
//			if (pWnd)
//				pWnd->ShowWindow(nCmdShow);
//		}
//	}
//}
//
//void CMapLoadCtrl::OffsetCtrl(CString strMapType, int dx, int dy, CExCodeInput *pExCodeInput)
//{
//	CRect rt;
//	CMapStringToPtr *pMapCtrl = NULL;
//	m_mapAllCtrlList.Lookup(strMapType, (void *&)pMapCtrl);
//	if (pMapCtrl)
//	{
//		POSITION pos = pMapCtrl->GetStartPosition();
//		while (pos != NULL)
//		{
//			CString strID;
//			CCtrlInfo *pCtrlInfo = NULL;
//			pMapCtrl->GetNextAssoc(pos,  strID, (void *&)pCtrlInfo);
//			if (pCtrlInfo)
//			{
//				if (pCtrlInfo->m_pWnd && pCtrlInfo->m_strExtraInfo.GetLength() <= 0)
//				{
//					pCtrlInfo->m_pWnd->GetWindowRect(&rt);
//					ScreenToClient(&rt);
//					rt.OffsetRect(dx, dy);
//					pCtrlInfo->m_pWnd->MoveWindow(&rt);
//				}
//			}
//		}
//	}
//
//	if (pExCodeInput)
//	{
//		pExCodeInput->GetWindowRect(&rt);
//		ScreenToClient(&rt);
//		rt.OffsetRect(dx, dy);
//		pExCodeInput->MoveWindow(&rt);
//	}
//
//	// 체크 버튼
//	StCondKey* pStCondKey = NULL;
//	m_mapTagID.Lookup(strMapType, (void*&)pStCondKey);
//	if (pStCondKey)
//	{
//		if (pStCondKey->nChkBtnID != -1)
//		{
//			CWnd *pWnd = GetDlgItem(pStCondKey->nChkBtnID);
//			if (pWnd)
//			{
//				pWnd->GetWindowRect(&rt);
//				ScreenToClient(&rt);
//				rt.OffsetRect(dx, dy);
//				pWnd->MoveWindow(&rt);
//			}
//		}
//	}
//}

void CMapLoadCtrl::AdjustCtrlToFO(BOOL bFutOptOnly)
{/*
	if (m_nCondType == COND_BM)
	{
		if (bFutOptOnly)
		{
			ShowCtrl(SW_HIDE, "-201", &m_ctlStkCodeInput);
			ShowCtrl(SW_HIDE, "-202", &m_ctlIdxCodeInput);

			OffsetCtrl("-203", 0, -44, &m_ctlFutCodeInput);
			OffsetCtrl("-204", 0, -44, &m_ctlOptCodeInput);
		}
		else
		{
			ShowCtrl(SW_SHOW, "-201", &m_ctlStkCodeInput);
			ShowCtrl(SW_SHOW, "-202", &m_ctlIdxCodeInput);

			OffsetCtrl("-203", 0, 44, &m_ctlFutCodeInput);
			OffsetCtrl("-204", 0, 44, &m_ctlOptCodeInput);
		}
	}*/
}


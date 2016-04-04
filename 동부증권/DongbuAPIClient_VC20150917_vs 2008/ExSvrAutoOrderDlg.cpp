// ExSvrAutoOrderDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "DongbuAPIClient_VC.h"
#include "ExSvrAutoOrderDlg.h"
#include "DlgSetting.h"


#include "StmtHelper.h"


#include "include_auto/globalauto.h"
#include "include_auto/TR13242.h"
#include "include_auto/TR10051.h"	// 패킷 TR_10051 : 주식

#include "include_auto/TR10117.h"
#include "include_auto/TR10112.h"	// 수량단위

#include "include_auto/TR10142.h"	// TR_10142 유통대주 가능수량
#include "include_auto/TR10144.h"	// TR_10144 신용매도가능수량조회

#include "include_auto/TR14055.h"
#include "include_auto/TR14051.h"
#include "include_auto/TR04012.h"
#include "include_auto/TR10000.h" // TR_10000 : 수수료 조회


#include "include_auto/DrdsXX9.h"


const int m_nTreeIconIndex0St		 = 0;
const int m_nTreeIconIndex0St_File	 = 2;   //# Add : 2006.09
const int m_nTreeIconIndex1St		 = 4;
const int m_nTreeIconIndex2St		 = 6;
const int m_nTreeIconIndexNormal	 = 8;		//#<= Normal
const int m_nTreeIconIndexNonAlert	 = 9;		//#<= Alert


#define TOPPOS_BASEWND 293


// CExSvrAutoOrderDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CExSvrAutoOrderDlg, CDialog)

CExSvrAutoOrderDlg::CExSvrAutoOrderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExSvrAutoOrderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExSvrAutoOrderDlg)	
	m_strAccount = "" ;
	m_strAcctPwd =  "";

	//}}AFX_DATA_INIT

	m_pTr77010Input = NULL;	
	m_IsInitalized			= FALSE;


	//m_lBkColor				= 1;
	m_IsInitalized			= FALSE;
		
	m_pBaseWndBuy			= NULL;
	m_pBaseWndSell			= NULL;	
	m_nMapMode				= MODE_EQUITIES;
	m_nOpenTypeBuy			= OPENTYPE_STOCK_BUY;
	m_nOpenTypeSell			= OPENTYPE_STOCK_SELL;


	m_strAppPath = "";
	
	m_pTr77010Input = NULL;

	m_dFeeRate = 0.0;

	m_strAccount = theApp.g_strAccount ;
	m_strAcctPwd = theApp.g_strAcctPwd ;
	
	
}

CExSvrAutoOrderDlg::~CExSvrAutoOrderDlg()
{
}

void CExSvrAutoOrderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);


	//{{AFX_DATA_MAP(CExJangoDlg)
	DDX_Control(pDX, IDC_LIST,			m_lstMsg);	
	DDX_Control(pDX, IDC_TAB1,			m_tabSellBuy);	
	

	DDX_Text(pDX, IDC_EDT_ACCOUNT,		m_strAccount);	
	DDX_Text(pDX, IDC_EDT_ACCTPWD,		m_strAcctPwd);	
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExSvrAutoOrderDlg, CDialog)
	ON_WM_COPYDATA()
	ON_WM_SIZE()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BTN_SET_ENV, &CExSvrAutoOrderDlg::OnBnClickedBtnSetEnv)


	ON_REGISTERED_MESSAGE(RMSG_RECV_77080, OnRecv77080)

	ON_BN_CLICKED(IDC_BTN_DELETE_ALL, &CExSvrAutoOrderDlg::OnBnClickedBtnDeleteAll)
	ON_BN_CLICKED(IDC_BTN_CANCEL_ALL, &CExSvrAutoOrderDlg::OnBnClickedBtnCancelAll)
	ON_BN_CLICKED(IDC_BTN_WATCH_ALL, &CExSvrAutoOrderDlg::OnBnClickedBtnWatchAll)
	ON_BN_CLICKED(IDC_BTN_REFRESH, &CExSvrAutoOrderDlg::OnBnClickedBtnRefresh)

	ON_REGISTERED_MESSAGE(RMSG_GET_ACCOUNTNUM, OnRmsgGetAccountNum)

	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnChangeTypeTab)
	
END_MESSAGE_MAP()


// CExSvrAutoOrderDlg 메시지 처리기입니다.

#define TR_SET_ENV				"77010" // 전체설정 등록
#define TR_SET_COND				"77020"	// 개별조건 등록
#define TR_REQ_COND_LIST		"77030"	// 조건리스트 조회
#define TR_REQ_COND_DETAIL		"77040"	// 개별조건 상세 조회
#define TR_REQ_ENV				"77080" // 전체설정 조회
#define TR_CHANGE_ALL			"77130" // 전체감시,전체해제,전체삭제,전체설정

#define APPPATH					"C:\\서버조건주문예제"


BOOL CExSvrAutoOrderDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	LoadSymbols()  ;
	GetDir_DrfnRoot (m_strAppPath) ;

	m_nMapMode = MODE_EQUITIES;

	m_nOpenTypeBuy  = OPENTYPE_STOCK_BUY;
	m_nOpenTypeSell = OPENTYPE_STOCK_SELL;


	InitConditionFromXml();

	LoadAllCondXml();

	
	CreateBaseWnd();

	m_tabSellBuy.InsertItem(WND_SELL, _T("매도"));
	m_tabSellBuy.InsertItem(WND_BUY, _T("매수"));


	///////////////////////////////////////////////
	CRect rtClient ;
	GetClientRect(rtClient) ;
	rtClient.DeflateRect(1, 0, 2, 5); // 풀랫폼 사이즈 오류 보정

	
	CRect rtGrid;
	rtGrid.left = rtClient.left + 1;
	rtGrid.right = rtClient.right - 1;
	rtGrid.top = 25 ;
	rtGrid.bottom = rtGrid.top + HEIGHT_GRID;
	//m_OrdGrid.MoveWindow(&rtGrid);	
	m_lstMsg.MoveWindow(&rtGrid);


	CRect rtTab;
	rtTab.left = rtClient.left + 1;
	rtTab.right = rtClient.right - 1;
	rtTab.top = rtGrid.bottom + 2;
	rtTab.bottom = rtTab.top + HEIGHT_TAB_ITEM;
	if ( m_tabSellBuy )
		m_tabSellBuy.MoveWindow(&rtTab);

	CRect rtBaseWnd ;
	rtBaseWnd.left = rtClient.left + 1;
	rtBaseWnd.right = rtClient.right - 1;
	rtBaseWnd.top = rtTab.bottom  + 5;
	rtBaseWnd.bottom = rtClient.bottom - 1;

	if (m_pBaseWndBuy)
		m_pBaseWndBuy->MoveWindow(&rtBaseWnd);
	if (m_pBaseWndSell)
		m_pBaseWndSell->MoveWindow(&rtBaseWnd);


	theApp.SendToServerEx (DRCM_ADVICE, "XF1", theApp.g_szId, m_hWnd );	
	theApp.SendToServerEx (DRCM_ADVICE, "XP2", theApp.g_szId, m_hWnd );	
		
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}



void CExSvrAutoOrderDlg::OnClose()
{
	if (m_pTr77010Input)
	{
		delete m_pTr77010Input;
		m_pTr77010Input = NULL;
	}


	ReleaseSymbols();

	POSITION pos;
	CString strGroupName;
	CList<XMLTreeInfo, XMLTreeInfo&>* plistXMLInfo;
	for (pos = m_mapXMLTreeInfo.GetStartPosition(); pos != NULL;)
	{
		m_mapXMLTreeInfo.GetNextAssoc(pos, strGroupName, (void*&)plistXMLInfo);

		plistXMLInfo->RemoveAll();
		delete plistXMLInfo;
		m_mapXMLTreeInfo.RemoveKey(strGroupName);
	}
	m_mapXMLTreeInfo.RemoveAll();
	m_listXMLTreeInfo.RemoveAll();
	
	pos = m_mapCtrlGroup.GetStartPosition();
	while (pos != NULL)
	{
		CCtrlGroup *pCtrlGroup = NULL;
		CString strNodeName;
		m_mapCtrlGroup.GetNextAssoc(pos, strNodeName, pCtrlGroup);
		if (pCtrlGroup)
		{
			POSITION posCtrl = pCtrlGroup->m_mapCtrl.GetStartPosition();
			while (posCtrl != NULL)
			{
				CCtrl *pCtrl = NULL;
				CString strID;
				pCtrlGroup->m_mapCtrl.GetNextAssoc(posCtrl, strID, pCtrl);
				if (pCtrl)
					delete pCtrl;
			}
			pCtrlGroup->m_mapCtrl.RemoveAll();

			delete pCtrlGroup;
		}
	}
	m_mapCtrlGroup.RemoveAll();
	

	if(	m_pBaseWndBuy)
	{	
		m_pBaseWndBuy->DestroyWindow();
		delete m_pBaseWndBuy;
		m_pBaseWndBuy = NULL;
	}
	if(	m_pBaseWndSell)
	{	
		m_pBaseWndSell->DestroyWindow();
		delete m_pBaseWndSell;
		m_pBaseWndSell = NULL;
	}

	CDialog::OnClose() ;
}



void CExSvrAutoOrderDlg::OnChangeTypeTab(NMHDR* pNMHDR, LRESULT* pResult)
{
	int nIndex = m_tabSellBuy.GetCurSel();

	if (m_pBaseWndBuy == NULL || m_pBaseWndBuy == NULL)
		return;

	if(nIndex == WND_SELL)
	{

		m_pBaseWndBuy->ShowWindow(SW_HIDE);
		m_pBaseWndSell->ShowWindow(SW_SHOW);
		m_pBaseWndSell->SetLinkPlatformCtrl();		
	}
	else
	{

		m_pBaseWndBuy->ShowWindow(SW_SHOW);			
		m_pBaseWndSell->ShowWindow(SW_HIDE);
		m_pBaseWndBuy->SetLinkPlatformCtrl();	
	}
}

void CExSvrAutoOrderDlg::ChangeTabSel(int nIndex)
{	
	if ( nIndex == WND_SELL )
	{		
		m_pBaseWndBuy->ShowWindow(SW_HIDE);
		m_pBaseWndSell->ShowWindow(SW_SHOW);
		m_pBaseWndSell->SetLinkPlatformCtrl();		
	}
	else
	{		
		m_pBaseWndBuy->ShowWindow(SW_SHOW);			
		m_pBaseWndSell->ShowWindow(SW_HIDE);
		m_pBaseWndBuy->SetLinkPlatformCtrl();	
	}

	m_tabSellBuy.SetCurSel(nIndex);
	
}

void CExSvrAutoOrderDlg::CreateBaseWnd()
{

	BOOL bResult = FALSE;
	BOOL bResult2 = FALSE;

	HINSTANCE hInstSave = AfxGetResourceHandle();
	AfxSetResourceHandle(theApp.m_hInstance);

	m_pBaseWndBuy = new CBaseFrmWnd;	
	m_pBaseWndBuy->SetPriceInfoPtr(/*&m_PriceInfo,*/ WND_BUY, m_nMapMode, this);//m_piBuy);	
	m_pBaseWndBuy->SetXmlTreeInfo(&m_mapXMLTreeInfo, &m_mapCtrlGroup);	
	m_pBaseWndBuy->m_strID = theApp.g_szId ;
	bResult = m_pBaseWndBuy->Create(IDD_DLG_AUTO_BASE_FRM, this);

	m_pBaseWndSell = new CBaseFrmWnd;
	m_pBaseWndSell->SetPriceInfoPtr(/*&m_PriceInfo,*/ WND_SELL, m_nMapMode, this);//m_piSell);	
	m_pBaseWndSell->SetXmlTreeInfo(&m_mapXMLTreeInfo, &m_mapCtrlGroup);	
	m_pBaseWndSell->m_strID = theApp.g_szId ;
	bResult = m_pBaseWndSell->Create(IDD_DLG_AUTO_BASE_FRM, this);
	
	if(m_pBaseWndSell)
	{	
		m_IsInitalized	= TRUE;
		m_pBaseWndSell->SetInitState(m_IsInitalized);			
		m_pBaseWndSell->SetInit();		
		m_pBaseWndSell->SetBaseSettingInfo(m_nOpenTypeSell);	
		m_pBaseWndSell->SetLinkPlatformCtrl();		
		m_pBaseWndSell->m_OrderTypeWndNormal.SetPriceUnit();		
	}	

	if(m_pBaseWndBuy)
	{		
		m_IsInitalized	= TRUE;
		m_pBaseWndBuy->SetInitState(m_IsInitalized);		
		m_pBaseWndBuy->SetInit();		
		m_pBaseWndBuy->SetBaseSettingInfo(m_nOpenTypeBuy);
		m_pBaseWndBuy->SetLinkPlatformCtrl();		
		m_pBaseWndBuy->m_OrderTypeWndNormal.SetPriceUnit();	
	}
	m_pBaseWndBuy->ShowWindow(SW_HIDE);
	m_pBaseWndSell->ShowWindow(SW_SHOW);	

	
	AfxSetResourceHandle(hInstSave);
}


HRESULT CExSvrAutoOrderDlg::OnRmsgGetAccountNum(WPARAM wParam, LPARAM lParam)
{	
	UpdateData(TRUE) ;

	CString* pstrAccountNum = (CString*)wParam;
	CString* pstrAccountPass = (CString*)lParam;  

	
	CString strAcct = m_strAccount ;
	strAcct.Trim();
	*pstrAccountNum = strAcct;
	
	
	CString strPasswd = m_strAcctPwd ;
	strPasswd.Trim();
	*pstrAccountPass = strPasswd;
	

	if (pstrAccountNum->IsEmpty())
		return 0L;

	return 1L;	
}


LRESULT CExSvrAutoOrderDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{		

	case UMSG_GETCURMARKETTAB:
		{			
			return m_tabSellBuy.GetCurSel();		
		}
		break;
		
	case UMSG_MESSAGEBOX:
		{
			CString strText = (LPCTSTR)wParam;
			DefMessageBox(GetSafeHwnd(), strText);
		}
		break;
	
	/*case UMSG_CHECK_MP:   //고객화면에 맞게 설정
		{
			CGridKey *pGridKey = (CGridKey *)lParam;
			return m_OrdGrid.IsMP(pGridKey);
		}
		break;*/
	//case UMSG_CHECKWATCHING: //고객화면에 맞게 설정
	//	{
	//		CGridKey *pGridKey = (CGridKey *)lParam;
	//		return m_OrdGrid.CheckWatching(pGridKey);
	//		// 20120723 ssj - 서버자동주문 <<
	//	}
	//	break;	
	
	case UMSG_GETUSECREDIT:
		{
			return m_bUseCredit;
		}
		break;
		

	case UMSG_SET_RESULT_MSG:
		{
			CString szText ;
			szText.Format("%s",  (LPCTSTR)lParam) ;
			m_lstMsg.InsertString(0, szText) ;
		}
		//SetMsgFromCode("", (LPCTSTR)lParam);
		break;

		// 20120723 ssj - 서버자동주문 >>
	case UMSG_GET_IP:
		return (LRESULT)(LPCTSTR)theApp.g_szMyIP;
		break;

		
	default:
		break;
	}

	if (message == RMSG_SET_TR_RESULT_MSG)
	{
		CString strMsgCode = (LPCTSTR)wParam;
		strMsgCode.Trim();
		CString strMsg = (LPCTSTR)lParam;
		strMsg.Trim();

		CString szTmp ;
		szTmp = strMsgCode + " : " + strMsg ;
		m_lstMsg.InsertString(0,szTmp ) ;				
	}

	return CDialog::WindowProc(message, wParam, lParam);
	
}

BOOL CExSvrAutoOrderDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
{
	COPYDATASTRUCT* pCDS = pCopyDataStruct ;

	int nDataType = (int)pCDS->dwData ;	
	switch (nDataType)
	{	

	case DRCM_DRDS_DATA :  //실시간 데이타	
		{
			DrdsData* pDrdsData = (DrdsData*)pCDS->lpData;
			if (memcmp(pDrdsData->Name, "XP1", 3) == 0)	
			{			
				ProcessXP1(pDrdsData);

				CString strMsg ;
				strMsg= "XP1 received>>" ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;
			}
			else if (memcmp(pDrdsData->Name, "XP2", 3) == 0)	
			{	
				CString strMsg ;
				CString strUserID = pDrdsData->Key;
				strUserID.Trim();
				if (strUserID != theApp.g_strID)
					return 0;

				strMsg= "XP2 received>>" ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;
				
			}

		}

		

		break ;		

	default: //조회 데이터
		{
			STTRHEADER* prData = (STTRHEADER*)pCDS->lpData;
			char szTrCode[5+1] ={0,} ;
			char szMsg[82+1] ={0,} ;
			char szMsgCode[6+1] ={0,} ;
			CString strMsg  ;


			memcpy(szTrCode, prData->TRCode, 5 ) ;
			memcpy(szMsg, prData->Message, 82) ;
			memcpy(szMsgCode, prData->MsgCode, 6) ;

			strMsg = szMsg ;
			strMsg.TrimRight() ;

			CString strMsgCode = szMsgCode;
			strMsgCode.Trim();	
			
			// =====================================================================
			// 전체설정 조회
			// =====================================================================
			if ( strcmp(szTrCode, TR_REQ_ENV ) == 0 ) 
			{									
				strMsg= "서버자동주문 전체설정 결과>>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;

				if (strMsgCode == "N1190") 
				{
					return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
				}

				int nTRDateLen = pCDS->cbData ;
				char *pData = new char[nTRDateLen];
				memcpy(pData, prData->TRData, nTRDateLen);
				PostMessage(RMSG_RECV_77080, nTRDateLen, (LPARAM)pData);
			}
			// =====================================================================
			// 전체설정 조회
			// =====================================================================
			else if (strcmp(szTrCode, TR_SET_ENV) == 0)
			{
				strMsg= "서버자동주문 전체설정 조회 결과>>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;

				if (strMsgCode == "N1190") 
				{
					return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
				}

				int nTRDateLen = (int) pCDS->cbData ;
				int nLen = sizeof(TR77010_OUT) ;

				if (nTRDateLen >= sizeof(TR77010_OUT))
				{
					TR77010_OUT stOut;
					memcpy(&stOut, (char *)prData->TRData, nLen);
					
					if (stOut.sRetVal[0] != 'S') // 전체설정 저장 성공이 아니면 메세지 박스 표시
					{
						CString sTmpMsg = szMsg;
						sTmpMsg.Trim();
						DefMessageBox(GetSafeHwnd(), sTmpMsg);
					}
					else
					{						

						ReqChangeAll(CHANGE_ALL_SET, NULL);
					}
				}

				// clear는 무조건 해야 한다
				if (m_pTr77010Input)
				{
					delete m_pTr77010Input;
					m_pTr77010Input = NULL;
				}
			}
			// =====================================================================
			// 조건 등록 수정 삭제 등등
			// =====================================================================
			else if (strcmp(szTrCode ,TR_SET_COND)==0) // 조건 등록 수정 삭제 등등				
			{
				strMsg= "서버자동주문 조건 (77020)등록/수정/삭제 결과>>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;

				if (strMsgCode == "N1190") 
				{
					return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
				}

				int nTRDateLen = pCDS->cbData ;

				int nCurTab = m_tabSellBuy.GetCurSel();
				if (nCurTab == WND_SELL && m_pBaseWndSell)
					m_pBaseWndSell->ReceiveFromMain(1, szTrCode, szMsgCode, szMsg, (char *)prData->TRData, nTRDateLen);
				if (nCurTab == WND_BUY && m_pBaseWndBuy)
					m_pBaseWndBuy->ReceiveFromMain(1, szTrCode, szMsgCode, szMsg, (char *)prData->TRData, nTRDateLen);
			}

			
			// =====================================================================
			// 전체감시,전체해제,전체삭제,전체설정
			// =====================================================================
			else if (strcmp(szTrCode, TR_CHANGE_ALL) == 0)
			{
				strMsg= "서버자동주문 조건 (77130)전체감시,전체해제,전체삭제,전체설정>>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );

				if (strMsgCode == "N1190") 
				{
					return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
				}

				
				if ((int)pCDS->cbData < sizeof(OUTPUT_TR_CHANGE_ALL))
					return CDialog::OnCopyData(pWnd, pCopyDataStruct);	

				int nLen = sizeof(OUTPUT_TR_CHANGE_ALL) ;

				RecvChageAll((char *) prData->TRData, nLen);
			}			
			// =====================================================================
			// 계좌 수수료율 조회
			// =====================================================================
			else if (strcmp(szTrCode, TR_10000) == 0) // 계좌 수수료율 조회
			{
				if (strMsgCode == "N1190") 
				{
					return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
				}

				strMsg= "계좌 수수료율 조회 >>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;

				RecvAcntFeeRate((char *) prData->TRData, (int)pCDS->cbData);
			}

			// =====================================================================
			// 신용계좌여부
			// =====================================================================
			else if (strcmp(szTrCode, TR12151) == 0) 
			{
				if (strMsgCode == "N1190") 
				{
					return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
				}

				strMsg= "신용계좌여부조회 >>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;
				RecvAcntCreditInfo((char *) prData->TRData, (int)pCDS->cbData);
			}

			// =====================================================================
			// 등록 리스트 조회
			// =====================================================================
			else if(strcmp(szTrCode ,TR_REQ_COND_LIST)==0)	
			{
				strMsg= "서버자동주문 등록 리스트 조회 (77030)>>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;

							
				if (strMsgCode != "N1190") // 비번 오류(코드: N1190)가 아니면 잔고 표시(RecvGridList에서 잔고가 조회되기 때문)
					RecvGridList((char *) prData->TRData, (int)pCDS->cbData);
			}
			else if(strcmp(szTrCode ,TR_REQ_COND_DETAIL)==0)
			{
				strMsg= "서버자동주문 조건 디테일 조회 (77040)>>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;

				TR_ORDER_REGIN stRegResult;
				memset(&stRegResult, 0x20, SZ_TR_ORDER_REGIN);
				memcpy(&stRegResult, (char *) prData->TRData, (int)pCDS->cbData);
				int ncount = atoi(CString(stRegResult.szCondCnt, sizeof(stRegResult.szCondCnt)));

				CString strMMType = CString(stRegResult.szMMType, sizeof(stRegResult.szMMType));
				int nType = m_tabSellBuy.GetCurSel();  //매도:0 매수:1

				if(strMMType.CompareNoCase(SVRORD_MMTYPE_SELL) == 0 && nType == WND_SELL)
					m_pBaseWndSell->SetOrdInfo(&stRegResult);
				else if(strMMType.CompareNoCase(SVRORD_MMTYPE_BUY) == 0 && nType == WND_BUY)
					m_pBaseWndBuy->SetOrdInfo(&stRegResult);
			}			

		}		
	}

	return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
}


void CExSvrAutoOrderDlg::RecvAcntCreditInfo(char *p, int n)
{
	BOOL bEnable = FALSE;

	if (n >= sizeof(TR12151_OUT))
	{
		TR12151_OUT *pOut = (TR12151_OUT *)p;
		if (n > 0 && pOut->ret[0] == '1')
			bEnable = TRUE;

		if (m_pBaseWndSell)
			m_pBaseWndSell->EnableCreditCtrl(bEnable);
		if (m_pBaseWndBuy)
			m_pBaseWndBuy->EnableCreditCtrl(bEnable);
	}
	
}

BOOL CExSvrAutoOrderDlg::IsValidAcnt(char *p, int n)
{
	UpdateData(TRUE) ;

	char szBuf[BUFSIZ] = { 0x00, };
	memcpy(szBuf, p, min(BUFSIZ, n));

	CString strAcnt = szBuf;
	strAcnt.Trim();

	CString strCurAcnt = m_strAccount;
	strCurAcnt.Trim();

	if (strAcnt != strCurAcnt)
		return FALSE;
	
	return TRUE;
}

void CExSvrAutoOrderDlg::RecvGridList(char *p, int n)
{
	if (n < sizeof(TR_ORDLIST_OUT))
		return;


	TR_ORDLIST_OUT stOrdInfo;
	memset(&stOrdInfo, 0x00, SZ_TR_ORDLIST_OUT);
	memcpy(&stOrdInfo.szCount, (char*)p, sizeof(stOrdInfo.szCount));
	int nMarket;

	int nCount = atoi(CString(stOrdInfo.szCount, sizeof(stOrdInfo.szCount)));
	int nIndex;
	
	CString strLastNextKey;


	ST_ORDINFO stDetail;
	for(nIndex = 0; nIndex < nCount; nIndex++)
	{	
		memset(&stDetail, 0x00, SZ_ST_ORDINFO);
		memcpy(&stDetail, (char*)p + sizeof(stOrdInfo.szCount) + SZ_ST_ORDINFO * nIndex, SZ_ST_ORDINFO);

		char szLastNextKey[30 + 1] = { 0x00, };
		memcpy(szLastNextKey, stDetail.sNextKey, sizeof(stDetail.sNextKey));
		strLastNextKey = szLastNextKey;
		strLastNextKey.Trim();

		if (IsValidAcnt(stDetail.szAccount, sizeof(stDetail.szAccount)) == FALSE)
			continue;
		
		StOrdCondData *pOrdCondData = new StOrdCondData;

		pOrdCondData->strAccount  = CString(stDetail.szAccount, sizeof(stDetail.szAccount));
		pOrdCondData->strCode	  = CString(stDetail.szItemCode, sizeof(stDetail.szItemCode));
		pOrdCondData->strMMType   = CString(stDetail.szMMType, sizeof(stDetail.szMMType));
		pOrdCondData->strCredit   = CString(stDetail.szCredit, sizeof(stDetail.szCredit));
		pOrdCondData->strAuto	  = CString(stDetail.cAutoFlag, sizeof(stDetail.cAutoFlag));
		pOrdCondData->strItemName = CString(stDetail.szItemName, sizeof(stDetail.szItemName));		
		pOrdCondData->strPrice	  = CString(stDetail.szPrice, sizeof(stDetail.szPrice));
		pOrdCondData->strState	  = CString(stDetail.cResult, sizeof(stDetail.cResult));
		pOrdCondData->strExpiredData  = CString(stDetail.szExpiredDate, sizeof(stDetail.szExpiredDate));

		pOrdCondData->strCondAcc    = CString(stDetail.cbCondAcc, sizeof(stDetail.cbCondAcc));
		pOrdCondData->strCondItem   = CString(stDetail.cbCondItem, sizeof(stDetail.cbCondItem));
		pOrdCondData->strCondPrice	= CString(stDetail.cbCondPrice, sizeof(stDetail.cbCondPrice));
		pOrdCondData->strCondIndex	= CString(stDetail.cbCondIndex, sizeof(stDetail.cbCondIndex));
		pOrdCondData->strCondUesr	= CString(stDetail.cbCondUser, sizeof(stDetail.cbCondUser));
		pOrdCondData->strCondText	= CString(stDetail.szCondStatement, sizeof(stDetail.szCondStatement));
		pOrdCondData->strLoanDate	= CString(stDetail.szLoanDate, sizeof(stDetail.szLoanDate));

		if (stDetail.sAvgPrcFlag[0] == '1')
			pOrdCondData->strUserPrice	= CString(stDetail.sAvgPrc, sizeof(stDetail.sAvgPrc));
		else
			pOrdCondData->strUserPrice = "0";

		pOrdCondData->strCode.Trim();
		pOrdCondData->strAccount.Trim();
		pOrdCondData->strCondText.Trim();	
		pOrdCondData->strLoanDate.Trim();	
		pOrdCondData->strItemName.Trim();

		nMarket = GetMarketType(pOrdCondData->strCode); 

		pOrdCondData->nMarket = nMarket;

		pOrdCondData->strHtsMtsMp = CString(stDetail.sMassID, sizeof(stDetail.sMassID));
		pOrdCondData->strHtsMtsMp.Trim();

		//AddGridItem(pOrdCondData, NULL);
	}	
	
	if (strLastNextKey.GetLength())
	{
		ReqGridList(strLastNextKey);
		return;
	}
	// 20120723 ssj - 서버자동주문 <<

	
	//ReqEquitiesBalance();   //eun
	
}
//
//void CExSvrAutoOrderDlg::AddGridItem(StOrdCondData *pOrdCondData, StOrdJango *pOrdJango)
//{
//	CGridItem *pGridItem = new CGridItem;
//
//	if (pOrdCondData)
//	{
//		pGridItem->m_strCode = pOrdCondData->strCode;
//		pGridItem->m_strCodeName = pOrdCondData->strItemName;
//		pGridItem->m_pOrdCondData = pOrdCondData;
//	}
//	else if (pOrdJango)
//	{
//		pGridItem->m_strCode = pOrdJango->strCode;
//		pGridItem->m_strCodeName = pOrdJango->strItemName;
//		pGridItem->m_pOrdJango = pOrdJango;
//	}
//	else
//	{
//		delete pGridItem;
//		return;
//	}
//
//	//pGridItem->m_bFO = (IsFutCode(pGridItem->m_strCode) || IsOptCode(pGridItem->m_strCode));
//
//	m_arGridItem.Add(pGridItem);
//}


void CExSvrAutoOrderDlg::RecvChageAll(char *p, int n)
{
	if (n < sizeof(OUTPUT_TR_CHANGE_ALL))
		return;

	OUTPUT_TR_CHANGE_ALL *pOut = (OUTPUT_TR_CHANGE_ALL *)p;
	if (pOut != NULL)
	{
		//		if (pOut->sRetVal[0] != 'S')
		//			DefMessageBox(GetSafeHwnd(), "작업요청에 실패하였습니다.");
	}
}


HRESULT CExSvrAutoOrderDlg::OnRecv77080(WPARAM wParam, LPARAM lParam)
{
	UpdateData(TRUE) ;
	if ((int)wParam <= 0 || (int)wParam < sizeof(TR77080_OUT))
		return 0;

	
	TR77080_OUT stOut;
	memcpy(&stOut, (char *)lParam, sizeof(TR77080_OUT));

	HINSTANCE hInstSave = AfxGetResourceHandle();
	AfxSetResourceHandle(theApp.m_hInstance);
	CDlgSetting dlg( this);	

	dlg.m_strAcnt = m_strAccount;
	dlg.m_strPasswd = m_strAcctPwd ;
	dlg.m_strUsreID =theApp.g_szId;
	dlg.m_strIP = theApp.g_szMyIP;
	dlg.m_pPrevSet = &stOut;	
	dlg.m_nMapMode = MODE_EQUITIES;  //주식
	
	if (dlg.DoModal() == IDOK)
	{
		m_pTr77010Input = new TR77010_IN;

		int nLen = sizeof(TR77010_IN) ;
		memcpy(m_pTr77010Input, &dlg.m_stInput, nLen);

		CString szInput ;
		szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&dlg.m_stInput);
		theApp.SendToServerEx (DRCM_SENDDATA, TR_SET_ENV, szInput, m_hWnd);			
	}
	AfxSetResourceHandle(hInstSave);	
	
	delete (char *)lParam;
	return 0;
}



BOOL CExSvrAutoOrderDlg::SendTr(CString strTrCode, CString szData, long nSize)
{


	CString szInput ;
	szInput.Format("%-*.*s", nSize , nSize, (LPCTSTR)szData);
	theApp.SendToServerEx (DRCM_SENDDATA, strTrCode, szData, m_hWnd);			


	return FALSE;

}


//전체 조건 조회
void CExSvrAutoOrderDlg::OnBnClickedBtnSetEnv()
{
	UpdateData (TRUE) ;


	CString szInput ;
	CString szNext ;

	int nLen = sizeof(TR77080_INPUT) ;

	TR77080_INPUT stInput ;
	memset (&stInput, 0x20, nLen) ;

	CString szAccount = m_strAccount ; 	

	szAccount.TrimLeft() ;
	szAccount.TrimRight() ;
	szAccount.Remove('-');


	memcpy(stInput.sId, (LPCTSTR)theApp.g_szId , theApp.g_szId .GetLength());
	memcpy(stInput.sAcnt_no, (LPCTSTR)szAccount, szAccount.GetLength());

	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);
	theApp.SendToServerEx (DRCM_SENDDATA, TR_REQ_ENV, szInput, m_hWnd);	
	
}


//전체 조건 삭제 조회
void CExSvrAutoOrderDlg::OnBnClickedBtnDeleteAll()
{
	int nRet = MessageBox("모든 등록 종목에 대하여 삭제하시겠습니까?", "확인", MB_ICONQUESTION | MB_YESNO);
	if (nRet != IDYES)
		return;

	ReqChangeAll(CHANGE_ALL_DELETE, NULL);
}


//전체 해제
void CExSvrAutoOrderDlg::OnBnClickedBtnCancelAll()
{

	int nRet = MessageBox("모든 종목에 대하여 감시해제하시겠습니까?", "확인", MB_ICONQUESTION | MB_YESNO);
	if (nRet != IDYES)
		return;

	ReqChangeAll(CHANGE_ALL_STOP, NULL);	
}


//전체 감시
void CExSvrAutoOrderDlg::OnBnClickedBtnWatchAll()
{
	int nRet = MessageBox("모든 종목에 대하여 전체감시하시겠습니까?", "확인", MB_ICONQUESTION | MB_YESNO);
	if (nRet != IDYES)
		return;

	ReqChangeAll(CHANGE_ALL_WATCH, NULL);

}

//조건 조회
void CExSvrAutoOrderDlg::OnBnClickedBtnRefresh()
{

	ReqGridList() ;
	
}

void CExSvrAutoOrderDlg::RecvAcntFeeRate(char *p, int n)
{
	if (n < sizeof(TR_10000_O))
		return;

	TR_10000_O *pOut = (TR_10000_O *)p;

	CString strFeeRate(pOut->frate1, sizeof(pOut->frate1));
	m_dFeeRate = atof(strFeeRate) / 100;
}

void CExSvrAutoOrderDlg::ReqAcntFeeRate()
{
	UpdateData(TRUE) ;

	m_dFeeRate = 0.0;

	CString strAcnt = m_strAccount;
	strAcnt.Trim();
	if (strAcnt.GetLength() <= 0)
		return;

	TR_10000_I tr_input;
	memset(&tr_input, 0x20, sizeof(tr_input));
	memcpy(tr_input.acct	, (LPSTR)(LPCTSTR)strAcnt		, min(strAcnt.GetLength(), sizeof(tr_input.acct)));

	CString szInput ;
	int nLen = sizeof(TR_10000_I) ;

	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&tr_input);
	theApp.SendToServerEx (DRCM_SENDDATA, TR_10000, szInput, m_hWnd);	
}

void CExSvrAutoOrderDlg::ReqGridList(CString strNextKey)
{
	UpdateData(TRUE);

	// 조회
	TR_ORDLIST_IN stOrdList;
	memset(&stOrdList, 0x20, SZ_TR_ORDLIST_IN);

	CString strAccNum, strAccPass;
	CString strUserId = theApp.g_szId ;
	strAccNum = m_strAccount ;

	memcpy(stOrdList.szAccount , strAccNum, min(strAccNum.GetLength(), sizeof(stOrdList.szAccount)));
	memcpy(stOrdList.szUserID, strUserId, min(strUserId.GetLength(), sizeof(stOrdList.szUserID)));

	CString strPassw = m_strAcctPwd ;	
	strPassw.Trim();
	memcpy(stOrdList.sPswd, strPassw, min(strPassw.GetLength(), sizeof(stOrdList.sPswd)));
	if (strNextKey.GetLength() > 0)
	{
		memcpy(stOrdList.sNextKey, strNextKey, min(sizeof(stOrdList.sNextKey), strNextKey.GetLength()));
	}

	CString szInput ;
	int nLen = SZ_TR_ORDLIST_IN ;

	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stOrdList);
	theApp.SendToServerEx (DRCM_SENDDATA, TR_REQ_COND_LIST, szInput, m_hWnd);	

	UpdateData(FALSE);
}



void CExSvrAutoOrderDlg::ReqChangeAll(int nAction, void *p)
{
	UpdateData (TRUE) ;

	INPUT_TR_CHANGE_ALL in;
	memset(&in, ' ', sizeof(INPUT_TR_CHANGE_ALL));

	CString strAcnt = m_strAccount ;
	strAcnt.Trim();
	CopyString(in.sAcct, sizeof(in.sAcct), strAcnt);

	CString strPasswd = m_strAcctPwd;	
	strPasswd.Trim();
	CopyString(in.sPswd, sizeof(in.sPswd), strPasswd);

	CopyString(in.sMassId, sizeof(in.sMassId), MASS_ID);

	switch (nAction)
	{
	case CHANGE_ALL_WATCH:
		in.sJobFlag[0] = 'R';
		break;

	case CHANGE_ALL_STOP:
		in.sJobFlag[0] = 'S';
		break;

	case CHANGE_ALL_DELETE:
		in.sJobFlag[0] = 'D';
		break;

	case CHANGE_ALL_SET:
		in.sJobFlag[0] = 'I';

		if (m_pTr77010Input == NULL)
		{
			DefMessageBox(GetSafeHwnd(), "환경설정 데이터를 찾을 수 없습니다.");
			return;
		}

		// 시장구분 S:주식,ELW, F:지수선옵, 주식선물
		//if (IsEquitiesMap())
			CopyString(in.sMktGbn, sizeof(in.sMktGbn), SVRORD_MARKETTYPE_STOCK);
		//else
		//	CopyString(in.sMktGbn, sizeof(in.sMktGbn), SVRORD_MARKETTYPE_FUT);

		// 조건 유효기간(YYYYMMDD) 
		memcpy(in.sExpireDate, m_pTr77010Input->sCond_expr_date, min(sizeof(in.sExpireDate), sizeof(m_pTr77010Input->sCond_expr_date)));

		// HTS User ID
		memcpy(in.sUserID, m_pTr77010Input->sId, min(sizeof(in.sUserID), sizeof(m_pTr77010Input->sId)));

		// 반자동 Flag'0':자동, '1':반자동
		memcpy(in.sMFlag, m_pTr77010Input->sAuto_gbn, min(sizeof(in.sMFlag), sizeof(m_pTr77010Input->sAuto_gbn)));

		// 주문 종류 '1':일반주문'2':호가분할주문 '3':시간분할주문 
		memcpy(in.sOrdKind, m_pTr77010Input->sOrd_div_gbn, min(sizeof(in.sOrdKind), sizeof(m_pTr77010Input->sOrd_div_gbn)));

		// 분할횟수 (MAX = 5)1 : 일반주문 n : 호가/시간분할주문
		memcpy(in.sOrdCnt, m_pTr77010Input->sOrd_cnt, min(sizeof(in.sOrdCnt), sizeof(m_pTr77010Input->sOrd_cnt)));

		// 시간분할 주문시 주문 Interval (5 ~ 60)
		// CopyString(in.sInterval, sizeof(in.sInterval), "");

		// 주문구분'1':지정가, '2':시장가'3':최유리지정가, '4':최우선지정가 '5':매수1호가,'6':매수2호가 '7':매도1호가,
		//        '8':매도2호가 '9':조건부지정가 'A':지정가(IOC) 'B':시장가(IOC) 'C':최유리(IOC) 'D':지정가(FOK) 'E':시장가(FOK) 'F':최유리(FOK) 
		memcpy(in.sOrdGb, m_pTr77010Input->sOrd_gbn, min(sizeof(in.sOrdGb), sizeof(m_pTr77010Input->sOrd_gbn)));

		// 수량 입력구분 (2010.10.01 추가)'1':수량직접입력, '2':백분률로 입력 
		memcpy(in.sQtyGb, m_pTr77010Input->sORD_QRY_GBN, min(sizeof(in.sQtyGb), sizeof(m_pTr77010Input->sORD_QRY_GBN)));

		// 기준수량
		memcpy(in.sOrdBaseQty, m_pTr77010Input->sORD_BASE_QRY, min(sizeof(in.sOrdBaseQty), sizeof(m_pTr77010Input->sORD_BASE_QRY)));

		// 주문수량(수량 or 백분율)
		if (m_pTr77010Input->sOrd_div_gbn[0] == '1') // 일반주문
		{
			memcpy(in.sOrdRegQty[0], m_pTr77010Input->sOrd_qty1, sizeof(in.sOrdRegQty[0]));
		}
		else if (m_pTr77010Input->sOrd_div_gbn[0] == '2') // 호가분할주문
		{
			memcpy(in.sOrdRegQty[0], m_pTr77010Input->sOrd_qty1, sizeof(in.sOrdRegQty[0]) * 10);
		}

		// 매도1/2/3호가 매수1/2/3호가 현재가, 상한가 하한가 
		memcpy(in.sOrdRegPrc, m_pTr77010Input->sOrd_prc, min(sizeof(in.sOrdRegPrc),sizeof(m_pTr77010Input->sOrd_prc)));

		// 조건구분 '1' : 일반조건(계좌/시세/...) '2' : 사용자조건 
		CopyString(in.sCondFlag, sizeof(in.sCondFlag), "1");

		// 조건수 (최대 20개)
		memcpy(in.sTargCnt, m_pTr77010Input->sCond_obs_cnt, sizeof(in.sTargCnt));

		// 조건계산식(표현식)
		memcpy(in.sTargExp, m_pTr77010Input->sCond_obs_mix, sizeof(in.sTargExp));

		// 분할기준 : 0:정배열, 1:등배열, 2:역배열
		memcpy(in.sDivGb, m_pTr77010Input->sDIV_GBN, sizeof(in.sDivGb));

		// 분할방향 : 0:매수방향, 1:매도방향
		memcpy(in.sDivDir, m_pTr77010Input->sDIV_ORD_GBN, sizeof(in.sDivDir));

		// 사설IP format : 999.999.999.999(15자리사용)
		memcpy(in.sPcIp, m_pTr77010Input->sPcIp, sizeof(in.sPcIp));

		//평균매입단가 플래그 : 0:설정안함, 1:설정
		CopyString(in.sAvgPrcFlag, sizeof(in.sAvgPrcFlag), "0");

		//평균매입단가
		// CopyString(in.sAvgPrc, sizeof(in.sAvgPrc), "");

		// 2840 조건 (화면 하단에 상세내역 기재) 조건1개Size(81) * 조건수(20)
		memcpy(&(in.stUser_Define), m_pTr77010Input->sCond_obs_detl, sizeof(User_Define) * 4);

		break;
	}

	//SendTr(TR_CHANGE_ALL, (BYTE *)&in, sizeof(INPUT_TR_CHANGE_ALL));

	int nLen =  sizeof(INPUT_TR_CHANGE_ALL) ;
	CString szInput ;
	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&in);
	theApp.SendToServerEx (DRCM_SENDDATA, TR_CHANGE_ALL, szInput, m_hWnd);	
	
}



// 20130213 ssj - 로드 오버헤드 제거 >> 기존 소스 위치 이동
BOOL CExSvrAutoOrderDlg::GetLoadXml(CString strFileRoot, MSXML2::IXMLDOMDocumentPtr &pXmlDom)
{
	pXmlDom->async = false;
	if (!pXmlDom->load (strFileRoot.AllocSysString())) 
		return FALSE;
	else
		return TRUE;
}
// 20130213 ssj - 로드 오버헤드 제거 <<

// 20130213 ssj - 로드 오버헤드 제거 >> 기존 소스 위치 이동
BOOL CExSvrAutoOrderDlg::InitConditionFromXml()
{
	BOOL bResult = TRUE;

	HRESULT hr = CoInitialize(NULL);
	if( !SUCCEEDED(hr) )
		return FALSE;

	CString strFilePath;
	
	strFilePath = m_strAppPath + FOLDER_DATA + _T("\\") + SVR_AUTO_ORDER_STOCK_FILE;
	

	MSXML2::IXMLDOMDocumentPtr pXmlDom ("Microsoft.XMLDOM", NULL, CLSCTX_INPROC_SERVER);
	if (GetLoadXml(strFilePath, pXmlDom) == FALSE)
		return FALSE;

	SetInitContidion(pXmlDom->childNodes);

	return bResult;

}
// 20130213 ssj - 로드 오버헤드 제거 <<

// 20130213 ssj - 로드 오버헤드 제거 >> 기존 소스 위치 이동
void CExSvrAutoOrderDlg::SetInitContidion(MSXML2::IXMLDOMNodeList *pNodes)
{
	if (pNodes == NULL) 
		return; 

	BOOL bTreeInsertFlag = FALSE;
	int nTreeIconIndex = 0;

	CString strNodeName, strAttName;
	CString strNodeVal;
	MSXML2::IXMLDOMNamedNodeMapPtr pattrs;	

	try {
		for (long idx = 0; idx < pNodes->length; idx++) 
		{
			MSXML2::IXMLDOMNodePtr pNode = pNodes->item[idx];
			if (!wcscmp((const wchar_t *)pNode->nodeTypeString,L"element"))
			{
				strNodeName = BSTR(pNode->nodeName);			
				if (SUCCEEDED(pNode->get_attributes(&pattrs))) 
				{
					MSXML2::IXMLDOMNodePtr pDomNode = pattrs->item[0];
					if ((pattrs->length) > 0) 
					{
						_bstr_t bstrName = pDomNode->nodeName;
						strAttName = (LPTSTR)(LPCTSTR)bstrName;

						bTreeInsertFlag = TRUE;
						if (!strAttName.Compare("NAME"))
						{
							nTreeIconIndex = m_nTreeIconIndex1St;

							_variant_t variantValue = pDomNode->nodeValue;
							_bstr_t bstrValue(variantValue);
							strNodeVal = (LPTSTR)(LPCTSTR)bstrValue;

							MSXML2::IXMLDOMNodePtr	pDomNode1St;
							CString			strAttName1St;
							CString			strNodeVal1St;
							XMLTreeInfo		stXMLTreeInfo;


							stXMLTreeInfo.nItemType = (int)TREE_SELECT_TYPE_ITEM_COMM;

							stXMLTreeInfo.bVisible = TRUE;
							stXMLTreeInfo.strName = strNodeVal; 
							stXMLTreeInfo.strTag = strNodeName;

							if (pDomNode1St = pattrs->item[1])
							{
								_bstr_t bstrAttName1St = pDomNode1St->nodeName;
								strAttName1St = (LPTSTR)(LPCTSTR)bstrAttName1St;

								if (!strAttName1St.Compare("NON_ALERT"))
								{
									_variant_t variantValue1St = pDomNode1St->nodeValue;
									_bstr_t bstrValue1St(variantValue1St);

									stXMLTreeInfo.nNonAlert = atoi((LPCTSTR)bstrValue1St);


									if (stXMLTreeInfo.nNonAlert == 1)	//#<= Non Alert
										nTreeIconIndex = m_nTreeIconIndexNonAlert;
									else
										nTreeIconIndex = m_nTreeIconIndexNormal;
								}
							}

							if ((nTreeIconIndex == m_nTreeIconIndexNonAlert) || (nTreeIconIndex == m_nTreeIconIndexNormal))
							{
								int nIndex = 2;
								if (pDomNode1St = pattrs->item[nIndex])
								{
									_bstr_t bstrAttName1St = pDomNode1St->nodeName;
									strAttName1St = (LPTSTR)(LPCTSTR)bstrAttName1St;
									if (!strAttName1St.Compare("CONDI_TYPE"))
									{
										_variant_t variantValue1St = pDomNode1St->nodeValue;
										_bstr_t bstrValue1St(variantValue1St);
										stXMLTreeInfo.nCondiType = atoi((LPCTSTR)bstrValue1St);
										nIndex++;
									}

								}

								if (pDomNode1St = pattrs->item[nIndex])
								{
									_bstr_t bstrAttName1St = pDomNode1St->nodeName;
									strAttName1St = (LPTSTR)(LPCTSTR)bstrAttName1St;
									if (!strAttName1St.Compare("TARGETBASE_TYPE"))
									{
										_variant_t variantValue1St = pDomNode1St->nodeValue;
										_bstr_t bstrValue1St(variantValue1St);
										stXMLTreeInfo.nTargetBase_Type = atoi((LPCTSTR)bstrValue1St);
										nIndex++;
									}

								}

								if (pDomNode1St = pattrs->item[nIndex])
								{
									_bstr_t bstrAttName1St = pDomNode1St->nodeName;
									strAttName1St = (LPTSTR)(LPCTSTR)bstrAttName1St;
									if (!strAttName1St.Compare("GUBUN"))
									{
										_variant_t variantValue1St = pDomNode1St->nodeValue;
										_bstr_t bstrValue1St(variantValue1St);
										stXMLTreeInfo.nGubun = atoi((LPCTSTR)bstrValue1St);
										nIndex++;
									}

								}

								if (pDomNode1St = pattrs->item[nIndex])
								{
									_bstr_t bstrAttName1St = pDomNode1St->nodeName;
									strAttName1St = (LPTSTR)(LPCTSTR)bstrAttName1St;
									if (!strAttName1St.Compare("GUBUN_DEFVAL"))
									{
										_variant_t variantValue1St = pDomNode1St->nodeValue;
										_bstr_t bstrValue1St(variantValue1St);
										stXMLTreeInfo.nGubunDefVal = atoi((LPCTSTR)bstrValue1St);
										nIndex++;
									}

								}

								if (pDomNode1St = pattrs->item[nIndex])
								{
									_bstr_t bstrAttName1St = pDomNode1St->nodeName;
									strAttName1St = (LPTSTR)(LPCTSTR)bstrAttName1St;
									if (!strAttName1St.Compare("NOT_USER"))
									{
										_variant_t variantValue1St = pDomNode1St->nodeValue;
										_bstr_t bstrValue1St(variantValue1St);
										stXMLTreeInfo.nNotUser = atoi((LPCTSTR)bstrValue1St);
										nIndex++;
									}

								}

								if (pDomNode1St = pattrs->item[nIndex])
								{
									_bstr_t bstrAttName1St = pDomNode1St->nodeName;
									strAttName1St = (LPTSTR)(LPCTSTR)bstrAttName1St;
									if (!strAttName1St.Compare("NOT_DEFVAL"))
									{
										_variant_t variantValue1St = pDomNode1St->nodeValue;
										_bstr_t bstrValue1St(variantValue1St);
										stXMLTreeInfo.nNotDefVal = atoi((LPCTSTR)bstrValue1St);
										nIndex++;
									}

								}

								if (pDomNode1St = pattrs->item[nIndex])
								{
									_bstr_t bstrAttName1St = pDomNode1St->nodeName;
									strAttName1St = (LPTSTR)(LPCTSTR)bstrAttName1St;
									if (!strAttName1St.Compare("RESULT_VIEW_ID"))
									{
										_variant_t variantValue1St = pDomNode1St->nodeValue;
										_bstr_t bstrValue1St(variantValue1St);
										stXMLTreeInfo.strResultViewID = (LPCTSTR)bstrValue1St;
										nIndex++;
									}

								}

								if (pDomNode1St = pattrs->item[nIndex])
								{
									_bstr_t bstrAttName1St = pDomNode1St->nodeName;
									strAttName1St = (LPTSTR)(LPCTSTR)bstrAttName1St;
									if (!strAttName1St.Compare("RESULT_VIEW_DEFVAL"))
									{
										_variant_t variantValue1St = pDomNode1St->nodeValue;
										_bstr_t bstrValue1St(variantValue1St);
										stXMLTreeInfo.nResultViewDefVal = atoi((LPCTSTR)bstrValue1St);
										nIndex++;
									}

								}

								if (pDomNode1St = pattrs->item[nIndex])
								{
									_bstr_t bstrAttName1St = pDomNode1St->nodeName;
									strAttName1St = (LPTSTR)(LPCTSTR)bstrAttName1St;
									if (!strAttName1St.Compare("CHART_VALSET"))
									{
										_variant_t variantValue1St = pDomNode1St->nodeValue;
										_bstr_t bstrValue1St(variantValue1St);
										stXMLTreeInfo.nChartValSet = atoi((LPCTSTR)bstrValue1St);
										nIndex++;
									}

								}								

								if (pDomNode1St = pattrs->item[nIndex])
								{
									_bstr_t bstrAttName1St = pDomNode1St->nodeName;
									strAttName1St = (LPTSTR)(LPCTSTR)bstrAttName1St;
									if (!strAttName1St.Compare("VISIBLE"))
									{
										_variant_t variantValue1St = pDomNode1St->nodeValue;
										_bstr_t bstrValue1St(variantValue1St);
										stXMLTreeInfo.bVisible = atoi((LPCTSTR)bstrValue1St);
										nIndex++;
									}

								}

								if (pDomNode1St = pattrs->item[nIndex])
								{
									_bstr_t bstrAttName1St = pDomNode1St->nodeName;
									strAttName1St = (LPTSTR)(LPCTSTR)bstrAttName1St;
									if (!strAttName1St.Compare("FILE_NAME"))
									{
										_variant_t variantValue1St = pDomNode1St->nodeValue;
										_bstr_t bstrValue1St(variantValue1St);
										stXMLTreeInfo.strMapFile = (LPTSTR)(LPCTSTR)bstrValue1St;
									}
								}

							}	
							m_listXMLTreeInfo.AddTail(stXMLTreeInfo);

						}
						else if (!strAttName.Compare("TYPE"))
						{
							AddConditionListAsKey(m_strCurType);

							m_strCurType = strNodeVal = strNodeName;
							nTreeIconIndex = m_nTreeIconIndex0St;


							if (strNodeVal == PORTPOLIO_SUBROOTTITLE || strNodeVal == ACCOUNT_SUBROOTTITLE ||
								strNodeVal == LANGUAGE_SUBROOTTITLE || strNodeVal == NEWS_SUBROOTTITLE ||
								strNodeVal == PATTEN_ROOTTITLE || strNodeVal == BOOKMARK_SUBROOTTITLE )
							{
								bTreeInsertFlag = FALSE;
							}					
							else if (strNodeVal == USER_ROOTTITLE || strNodeVal == RECOMMEND_ROOTTITLE)
							{
								nTreeIconIndex = m_nTreeIconIndex0St_File;
								bTreeInsertFlag = FALSE;
							}						
						}
					}
					else		//# Main Root
						bTreeInsertFlag = FALSE;
				}

				if (bTreeInsertFlag == TRUE)
				{
					if ((nTreeIconIndex != m_nTreeIconIndexNormal) && (nTreeIconIndex != m_nTreeIconIndexNonAlert))
						SetInitContidion(pNode->childNodes);
				}
				else
					SetInitContidion(pNode->childNodes);
			}
			pNode = NULL;
		}
		pattrs = NULL;
	}
	catch(...){ }
}

void CExSvrAutoOrderDlg::AddConditionListAsKey(CString strGroupName)
{
	CList<XMLTreeInfo, XMLTreeInfo&>* plistXMLTreeInfo;

	if(m_mapXMLTreeInfo.Lookup(strGroupName, (void*&)plistXMLTreeInfo) == FALSE)
	{
		plistXMLTreeInfo = new CList<XMLTreeInfo, XMLTreeInfo&>;

		POSITION pos = m_listXMLTreeInfo.GetHeadPosition();
		while(pos)
		{	
			plistXMLTreeInfo->AddTail(m_listXMLTreeInfo.GetNext(pos));
		}
		m_mapXMLTreeInfo.SetAt(strGroupName, (void*)plistXMLTreeInfo);
	}
	m_listXMLTreeInfo.RemoveAll();
}

void CExSvrAutoOrderDlg::LoadAllCondXml()
{
	CString strXmlPath = m_strAppPath + FOLDER_DATA + "\\map\\maporda.xml";
	CDataParser parser;
	parser.ReadXml(strXmlPath);

	XNodePtr pRoot = parser.GetRoot();
	if (pRoot == NULL) // pRoot: <종목조건설정
		return;

	for (XNodePtr pChild = pRoot->firstChild; pChild != NULL; pChild = pChild->nextSibling)
	{		
		ParseCondition(pChild);
	}
}

void CExSvrAutoOrderDlg::ParseCondition(XNodePtr pParent)
{
	if (pParent == NULL)
		return;

	CString strNodeName;
	for (XNodePtr pChild = pParent->firstChild; pChild != NULL; pChild = pChild->nextSibling)
	{
		//XTRACE(2, "NodeName: %s", (char *)pChild->nodeName); // <A##

		strNodeName = (char *)pChild->nodeName; // A1, A2...

		XNamedNodeMapPtr pAttr = pChild->attributes;
		if (pAttr == NULL)
			continue;

		CCtrlGroup *pCtrlGroup = new CCtrlGroup;
		CString strKey;
		CString strVal;
		for (int i = 0; i < pAttr->length; i++)
		{
			
			strKey = (char *)pAttr->item[i]->nodeName;
			strVal = (char *)pAttr->item[i]->text;
			pCtrlGroup->m_mapGrpKeyVal.SetAt(strKey, strVal);
		}		


		m_mapCtrlGroup.SetAt(strNodeName, pCtrlGroup);
		ParseControl(pCtrlGroup, pChild);
	}
}

void CExSvrAutoOrderDlg::ParseControl(CCtrlGroup *pCtrlGroup, XNodePtr pParent)
{
	for (XNodePtr pChild = pParent->firstChild; pChild != NULL; pChild = pChild->nextSibling)
	{
		//XTRACE(4, "NodeName: %s", (char *)pChild->nodeName); // <CONTROL
		XNamedNodeMapPtr pAttr = pChild->attributes;
		if (pAttr == NULL)
			continue;

		CCtrl *pCtrl = new CCtrl;
		CString strKey;
		CString strVal;
		for (int i = 0; i < pAttr->length; i++)
		{

			if (stricmp((char *)pAttr->item[i]->nodeName, "ID") == 0)
				pCtrl->m_strId = (char *)pAttr->item[i]->text;
			
			strKey = (char *)pAttr->item[i]->nodeName;
			strVal = (char *)pAttr->item[i]->text;
			pCtrl->m_mapCtrlKeyVal.SetAt(strKey, strVal);
		}
		
		pCtrlGroup->m_mapCtrl.SetAt(pCtrl->m_strId, pCtrl);
	}
}


int CExSvrAutoOrderDlg::FindPositions(CString strCode)
{
	/*CString strPositionStr;
	int nRows = m_OrdGrid.GetNumberRows();
	for (int iRow = 0; iRow < nRows; iRow++)
	{
		CUGCell cell;
		m_OrdGrid.GetCell(ITEMCODE_COL, iRow, &cell);
		CString strJanCode = cell.GetOtherJongCode();

		if (strCode == strJanCode)
		{
			m_OrdGrid.GetCell(COL_CREDIT_FOSELLBUY, iRow, &cell);
			strPositionStr = cell.GetText();
			strPositionStr.Trim();
			if (strPositionStr == "매도")
				return POS_SELL;
			else if (strPositionStr == "매수")
				return POS_BUY;
			else
				return -1;

			break;
		}
	}*/

	return -1;
}

CString CExSvrAutoOrderDlg::FindMatchPrice(CString strCode, int nMPFlag)
{
	CString strMatchPrice, strUserPrice;
	//int nRows = m_OrdGrid.GetNumberRows();
	//for (int iRow = 0; iRow < nRows; iRow++)
	//{
	//	CUGCell cell;
	//	m_OrdGrid.GetCell(ITEMCODE_COL, iRow, &cell);
	//	CString strJanCode = cell.GetOtherJongCode();

	//	if (strCode == strJanCode)
	//	{
	//		if (nMPFlag == MPRICE_USER)
	//		{
	//			m_OrdGrid.GetCell(COL_USER_PRICE, iRow, &cell);
	//			strUserPrice = cell.GetText();
	//			strUserPrice.Trim();
	//			strUserPrice.Remove(',');

	//			// 수정단가가 있으면 리턴
	//			if (strUserPrice.GetLength() > 0)
	//				return strUserPrice;
	//		}
	//		else if (nMPFlag == MPRICE_MATCH)
	//		{
	//			m_OrdGrid.GetCell(UNITPRICE, iRow, &cell);
	//			strMatchPrice = cell.GetText();
	//			strMatchPrice.Trim();
	//			strMatchPrice.Remove(',');
	//			// 매입가가 있으면 리턴
	//			if (strMatchPrice.GetLength() > 0)
	//				return strMatchPrice;
	//		}
	//	}
	//}

	return "";
}

CString CExSvrAutoOrderDlg::GetParsedCondStmt(CString strStatement)
{
	CStmtHelper clsHelper;
	strStatement.Trim();
	CString strRet;

	CString strCurrentPreFix;
	CString strText;
	CStringArray arEachSec;
	int nSec = GetArgs(strStatement, arEachSec, '@'); // 섹션은 '@'으로 구분
	for (int i = 0; i < nSec; i++)
	{
		CStringArray arEachCond;
		CString strSection = arEachSec.GetAt(i);
		int nCond = GetArgs(strSection, arEachCond, ','); // 각 조건은 ','로 구분
		for (int k = 0; k < nCond; k++)
		{
			CStringArray arVal;
			CString strCond = arEachCond.GetAt(k);
			int nCnt = GetArgs(strCond, arVal, '|'); // 개별 값은 '|'로 구분

			CString strIndexType, strArg1, strArg2, strArg3, strArg4, strArg5;
			if (nCnt > 0)
				strIndexType = arVal.GetAt(0); // 0번째는 조건타입(-101, -102, -103...)

			if (nCnt > 1)
				strArg1 = arVal.GetAt(1);
			if (nCnt > 2)
				strArg2 = arVal.GetAt(2);
			if (nCnt > 3)
				strArg3 = arVal.GetAt(3);
			if (nCnt > 4)
				strArg4 = arVal.GetAt(4);
			if (nCnt > 5)
				strArg5 = arVal.GetAt(5);

			strText = clsHelper.GetParsedCondText(atol(strIndexType), strArg1, strArg2, strArg3, strArg4, strArg5);
			if (strIndexType.GetLength() > 1)
			{
				CString strPreFix = strIndexType.Left(2);
				// 예외처리
				if (strIndexType == "-106")
					strPreFix = "-3"; // -106만 시세조건인데 -3XX가 아닌 -106으로 온다. -3으로 변경해주자

				if (strCurrentPreFix != strPreFix)
				{
					strCurrentPreFix = strPreFix;
					if (strRet.GetLength() > 0)
						strRet = strRet + "\n";

					if (strCurrentPreFix == "-1")
					{
						strText = "[손익조건]\n" + strText;
					}
					else if (strCurrentPreFix == "-2")
					{
						strText = "[BM조건]\n" + strText;
					}
					else if (strCurrentPreFix == "-3")
					{
						strText = "[시세조건]\n" + strText;
					}
					else if (strCurrentPreFix == "-4")
					{
						strText = "[지표조건]\n" + strText;
					}
					else if (strCurrentPreFix == "+1")
					{
						strText = "[주문조건]\n" + strText;
					}
				}
			}

			strRet = strRet + strText;
		}
	}

	return strRet;
}



void CExSvrAutoOrderDlg::OnSize(UINT nType, int cx, int cy)
{
	
	CDialog::OnSize(nType, cx, cy);

	
}

void CExSvrAutoOrderDlg::ProcessXP1(DrdsData* pDrdsData)
{
	
	CString strUserID = pDrdsData->Key;
	strUserID.Trim();
	if (strUserID.CompareNoCase(theApp.g_strID))
		return;

	ST_XP1 xp1;
	memcpy(&xp1, pDrdsData->Data, min(pDrdsData->Len, sizeof(ST_XP1)));

	CString strAcnt = m_strAccount ;

	StOrdCondData stOrdCond;
	stOrdCond.strAccount     = CString(xp1.Acct, sizeof(xp1.Acct));
	if (stOrdCond.strAccount.Trim() != strAcnt.Trim())
		return;

	stOrdCond.strCode        = CString(xp1.ShCode, sizeof(xp1.ShCode));
	stOrdCond.strMMType      = CString(xp1.Mmgbn, sizeof(xp1.Mmgbn));
	stOrdCond.strCredit      = CString(xp1.CrGbn, sizeof(xp1.CrGbn));
	stOrdCond.strAuto        = CString(xp1.AutoGbn, sizeof(xp1.AutoGbn));
	//stOrdCond.strItemName    = 
	stOrdCond.strPrice	     = CString(xp1.OrdRegPrc, sizeof(xp1.OrdRegPrc));
	//stOrdCond.strState	     = CString(xp1., sizeof(xp1.));
	stOrdCond.strExpiredData = CString(xp1.ExpireDate, sizeof(xp1.ExpireDate));

	stOrdCond.strCondAcc     = CString(xp1.CondAcct, sizeof(xp1.CondAcct));
	stOrdCond.strCondItem    = CString(xp1.CondItem, sizeof(xp1.CondItem));
	stOrdCond.strCondPrice	 = CString(xp1.CondPrice, sizeof(xp1.CondPrice));
	stOrdCond.strCondIndex	 = CString(xp1.CondIndex, sizeof(xp1.CondIndex));
	//stOrdCond.strCondUesr    = CString(xp1., sizeof(xp1.));

	CString strCondStmt = CString(xp1.CondStmt, sizeof(xp1.CondStmt));
	stOrdCond.strCondText	 = GetParsedCondStmt(strCondStmt);
	stOrdCond.strLoanDate    = CString(xp1.CrDate, sizeof(xp1.CrDate));

	if (xp1.AvgPrcFlag[0] == '1')
		stOrdCond.strUserPrice	= CString(xp1.AvgPrc, sizeof(xp1.AvgPrc));
	else
		stOrdCond.strUserPrice = "0";

	stOrdCond.nMarket        = GetMarketType(stOrdCond.strCode);


	stOrdCond.strCode.Trim();
	stOrdCond.strAccount.Trim();
	stOrdCond.strCondText.Trim();	
	stOrdCond.strLoanDate.Trim();	

	CString strCurAcnt = m_strAccount ;
	if (stOrdCond.strAccount != strCurAcnt)
		return;

	stOrdCond.strHtsMtsMp = CString(xp1.sMassID, sizeof(xp1.sMassID));		
	//stOrdCond.strItemName = GetEquitiesCodeName(stOrdCond.strCode);


	BOOL bSort = FALSE;
	BOOL bReset = FALSE;

	// state
	switch (xp1.Act_gbn[0])
	{
	case 'I': // insert
		stOrdCond.strState = "2"; // '1':감시,  '2':휴면(중지) [from cResult in ST_ORDINFO]
		bSort = TRUE;
		bReset = TRUE;
		//m_OrdGrid.ChangeItem(stOrdCond);//고객화면처리
		break;

	case 'U': // update
		stOrdCond.strState = "2"; // '1':감시,  '2':휴면(중지) [from cResult in ST_ORDINFO]
		bReset = TRUE;
		//m_OrdGrid.ChangeItem(stOrdCond); //고객화면처리
		break;

	case 'A': // active
		stOrdCond.strState = "1"; // '1':감시,  '2':휴면(중지) [from cResult in ST_ORDINFO]
		//m_OrdGrid.ChangeItem(stOrdCond);  //고객화면처리
		break;

	case 'S': // stopped
		stOrdCond.strState = "2"; // '1':감시,  '2':휴면(중지) [from cResult in ST_ORDINFO]
		//m_OrdGrid.ChangeItem(stOrdCond); //고객화면처리
		break;

	case 'D': // Delete
	case 'F': // Finished
	case 'E': // Expired
		bReset = TRUE;
		//m_OrdGrid.RemoveItem(stOrdCond);
		break;

	default:
		{
		}
	}

	if (bReset)
	{
		if (m_pBaseWndBuy)
			m_pBaseWndBuy->ProcessXP1(stOrdCond.strCode);
		if (m_pBaseWndSell)
			m_pBaseWndSell->ProcessXP1(stOrdCond.strCode);
	}

}


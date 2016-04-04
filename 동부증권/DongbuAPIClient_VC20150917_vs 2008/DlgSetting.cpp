// DlgSetting.cpp : 구현 파일입니다.
//

#include "stdafx.h"

#include "DlgSetting.h"
#include "resource.h"

#include "include_auto/globalAuto.h"

// CDlgSetting 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgSetting, CDialog)

CDlgSetting::CDlgSetting( CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSetting::IDD, pParent)
{

	m_pCurrentDlg = NULL;
	m_pCommWnd = pParent;

	m_bSending = FALSE;
	m_pPrevSet = NULL;

	m_bInitClicked = FALSE;

	m_nMapMode = MODE_EQUITIES;  //주식
	
}

CDlgSetting::~CDlgSetting()
{
}

void CDlgSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RDO_AUTO, m_rdoAuto);
	DDX_Control(pDX, IDC_RDO_SEMI, m_rdoSemi);
	DDX_Control(pDX, IDC_CHK_LOSS, m_chkLoss);
	DDX_Control(pDX, IDC_CHK_PROFIT, m_chkProfit);
	DDX_Control(pDX, IDC_CHK_FIX_PROFIT, m_chkFixProfit);
	DDX_Control(pDX, IDC_CHK_FIX_LOSS, m_chkFixLoss);	
	DDX_Control(pDX, IDC_TAB_RULE, m_tabRule);
	DDX_Control(pDX, IDC_CHK_APPLY_NEWITEM, m_chkApplyNewItem);
}


BEGIN_MESSAGE_MAP(CDlgSetting, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgSetting::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDlgSetting::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BTN_INITSET, &CDlgSetting::OnBnClickedBtnInitset)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_RULE, &CDlgSetting::OnTcnSelchangeTabRule)
	
ON_WM_DESTROY()

END_MESSAGE_MAP()


// CDlgSetting 메시지 처리기입니다.

void CDlgSetting::OnBnClickedOk()
{
	m_bSending = TRUE;

	memset(&m_stInput, ' ', sizeof(m_stInput));

	CopyString(m_stInput.sAcnt_no, sizeof(m_stInput.sAcnt_no), m_strAcnt);
	CopyString(m_stInput.sMass_id, sizeof(m_stInput.sMass_id), MASS_ID);
	

	CString strData;
	int nTabSel = m_tabRule.GetCurSel();
	CTime tm = CTime::GetCurrentTime();
	if (nTabSel == 0)
	{	
		//m_dlgNormal.m_dtpValidDate.GetTime(tm);
		strData = tm.Format("%Y%m%d");
	}
	else
	{		
		//m_dlgDiv.m_dtpValidDate.GetTime(tm);
		strData = tm.Format("%Y%m%d");
	}
	CTimeSpan span = tm - CTime::GetCurrentTime();
	if (span.GetDays() > 90)
	{
		DefMessageBox(GetSafeHwnd(), "유효기간은 90일이내로 설정하십시오.");
		m_bSending = FALSE;
		return;
	}

	
	CopyString(m_stInput.sCond_expr_date, sizeof(m_stInput.sCond_expr_date), strData);

	// 신규유입처리 - 0:처리안함, 1:신규유입처리함		
	if (m_chkApplyNewItem.GetCheck() == BST_CHECKED)
		strData = "1";
	else
		strData = "0";	
	
			
	CopyString(m_stInput.sNewitem_add    , sizeof(m_stInput.sNewitem_add    ), strData);
	CopyString(m_stInput.sScrt_no        , sizeof(m_stInput.sScrt_no        ), m_strPasswd);
	CopyString(m_stInput.sId             , sizeof(m_stInput.sId             ), m_strUsreID);
	
	// 1: 매도, 2: 매수
	CopyString(m_stInput.sSEL_BUY_GBN    , sizeof(m_stInput.sSEL_BUY_GBN    ), "1");

	// 1 : 반자동 주문, 0 : 자동주문
	if (m_rdoAuto.GetCheck() ==  BST_CHECKED)
		strData = "0";
	else
		strData = "1";
	CopyString(m_stInput.sAuto_gbn       , sizeof(m_stInput.sAuto_gbn       ), strData);

	// 1 : 일반 주문, 2 : 호가분할 주문, 3 : 시간분할 주문
	if (nTabSel == 0)
		strData = "1";
	else
		strData = "2";
	CopyString(m_stInput.sOrd_div_gbn    , sizeof(m_stInput.sOrd_div_gbn    ), strData);

	if (nTabSel == 1)
	{
		// '0 ': 정배열, '1':등배열, '2':역배열
		int nSel = m_dlgDiv.m_cmbInc.GetCurSel();
		strData.Format("%d", nSel);
		CopyString(m_stInput.sDIV_GBN        , sizeof(m_stInput.sDIV_GBN        ), strData);

		// '0' : 매수방향, '1':매도방향
		nSel = m_dlgDiv.m_cmbDir.GetCurSel();
		strData.Format("%d", nSel);
		CopyString(m_stInput.sDIV_ORD_GBN    , sizeof(m_stInput.sDIV_ORD_GBN    ), strData);
	}

	// 일반주문의 경우 1. 호가분할 및 시간 분할인 경우 분할 횟수
	if (nTabSel == 0)
		strData = "1";
	else
		m_dlgDiv.m_edtCount.GetWindowText(strData);
	strData.Trim();
	strData.Remove(',');
	CopyString(m_stInput.sOrd_cnt        , sizeof(m_stInput.sOrd_cnt        ), strData);
	//CopyString(m_stInput.sORD_INTERVAL   , sizeof(m_stInput.sORD_INTERVAL   ), "");

	//
	if (nTabSel == 0)
	{
		int nSel = m_dlgNormal.m_cmbPriceType.GetCurSel();
		strData = PRICE_TYPE_VALUE_EX[nSel];
	}
	else
	{
		strData = "1"; // 1: 지정가
	}
	CopyString(m_stInput.sOrd_gbn        , sizeof(m_stInput.sOrd_gbn        ), strData);

	// 1:수량직접입력, 2:백분율로 입력
	CopyString(m_stInput.sORD_QRY_GBN    , sizeof(m_stInput.sORD_QRY_GBN    ), "2");

	/*
	일반주문 텝에서는
	sORD_BASE_QRY는 무조건 100
	sOrd_qty1 에 매도 비중을 넣으시면 되구요
	호가분할 텝에서는
	sORD_BASE_QRY 에 매도비중을 넣으시고
	sOrd_qty1~ 순서로 구성 비율을 넣으시면 됩니다
	*/

	if (nTabSel == 0)
	{
		strData = "100";
	}
	else
	{
		m_dlgDiv.m_edtRate.GetWindowText(strData);
		strData.Trim();
		strData.Remove(',');
		if (atol(strData) <= 0)
		{
			DefMessageBox(GetSafeHwnd(), _T("주문수량(비중)을 확인하여 주시기 바랍니다."));
			m_bSending = FALSE;
			return;
		}
	}	
	CopyString(m_stInput.sORD_BASE_QRY   , sizeof(m_stInput.sORD_BASE_QRY   ), strData);

	if (nTabSel == 0)
	{
		m_dlgNormal.m_edtRate.GetWindowText(strData);
		strData.Trim();
		strData.Remove(',');
		if (atol(strData) <= 0)
		{
			DefMessageBox(GetSafeHwnd(), _T("주문수량(비중)을 확인하여 주시기 바랍니다."));
			m_bSending = FALSE;
			return;
		}
		CopyString(m_stInput.sOrd_qty1       , sizeof(m_stInput.sOrd_qty1       ), strData);
	}
	else
	{
		CStringArray *pArrRet = m_dlgDiv.m_stcComplex.GetDivQtyRate();
		if (pArrRet)
		{
			int nCnt = pArrRet->GetSize();
			if (nCnt <= 0)
			{
				DefMessageBox(GetSafeHwnd(), "적용 버튼을 클릭하여 구성비율을 설정하여 주십시오.");
				m_bSending = FALSE;
				return;
			}
			if (nCnt > 0)
				CopyString(m_stInput.sOrd_qty1       , sizeof(m_stInput.sOrd_qty1       ), pArrRet->GetAt(0));
			if (nCnt > 1)
				CopyString(m_stInput.sOrd_qty2       , sizeof(m_stInput.sOrd_qty2       ), pArrRet->GetAt(1));
			if (nCnt > 2)
				CopyString(m_stInput.sOrd_qty3       , sizeof(m_stInput.sOrd_qty3       ), pArrRet->GetAt(2));
			if (nCnt > 3)
				CopyString(m_stInput.sOrd_qty4       , sizeof(m_stInput.sOrd_qty4       ), pArrRet->GetAt(3));
			if (nCnt > 4)
				CopyString(m_stInput.sOrd_qty5       , sizeof(m_stInput.sOrd_qty5       ), pArrRet->GetAt(4));
		}
		
	}

	strData = "";
	if (nTabSel == 0)
	{
		//if (m_stInput.sOrd_gbn[0] != '2') // 시장가가 아니면
		if (m_stInput.sOrd_gbn[0] == '1' || m_stInput.sOrd_gbn[0] == '9' || m_stInput.sOrd_gbn[0] == 'A' || m_stInput.sOrd_gbn[0] == 'D')  // 
		{
			int nSel = m_dlgNormal.m_cmbSelPrice.GetCurSel();
			if (nSel == 0) // 지정가면
			{
				m_dlgNormal.m_edtPrice.GetWindowText(strData);
				strData.Trim();
				strData.Remove(',');
				if (atol(strData) <= 0)
				{
					DefMessageBox(GetSafeHwnd(), _T("주문단가를 확인하여 주시기 바랍니다."));
					m_bSending = FALSE;
					return;
				}
				strData = "J" + strData; // 지정가는 J를 붙인다
			}
			else
			{
				strData = PRICE_TYPE_STRING2[nSel];
			}
		}
	}
	else
	{
		CString strDivCnt;
		m_dlgDiv.m_edtCount.GetWindowText(strDivCnt);
		int nDivCnt = atol(strDivCnt);
		
		// '0' : 매수방향, '1':매도방향
		int nDir = m_dlgDiv.m_cmbDir.GetCurSel();

		int nSel = m_dlgDiv.m_cmbBasePrice.GetCurSel();
		for (int i = nSel, nTmp = 0; nTmp < nDivCnt; nTmp++)
		{
			strData = strData + PRICE_STANDARD_STRING_CONVERT[DIVSTANDARD_INDEX + i];
			if (nDir == 0)
				i++;
			else
				i--;
		}
	}
	CopyString(m_stInput.sOrd_prc        , sizeof(m_stInput.sOrd_prc        ), strData);

	// 1': 손익조건, '2':사용자조건
	CopyString(m_stInput.sCond_obs_gbn   , sizeof(m_stInput.sCond_obs_gbn   ), "1");

	int nCondCnt = GetCondCount();

	strData.Format("%d", nCondCnt);
	CopyString(m_stInput.sCond_obs_cnt   , sizeof(m_stInput.sCond_obs_cnt   ), strData);

	strData = GetCondExp();
	CopyString(m_stInput.sCond_obs_mix   , sizeof(m_stInput.sCond_obs_mix   ), strData);

	GetCondDetail(&m_stInput);

	CopyString(m_stInput.sPcIp           , sizeof(m_stInput.sPcIp           ), m_strIP);
	
	//if (m_pCommWnd)
	//	m_pCommWnd->SendMessage(RMSG_SEND_REQ, REQ_REG_SETTING, (LPARAM)&m_stInput);

	m_bInitClicked = FALSE;

	OnOK();
}

void CDlgSetting::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	if (m_bInitClicked)
	{
		//DefMessageBox(GetSafeHwnd(), "초기화 내용을 저장하지 않았습니다.")
		//return;
	}

	if (m_bSending)
	{
		DefMessageBox(GetSafeHwnd(), "서버와 통신 중입니다. 잠시후 다시 시도하여 주십시오.");
		return;
	}

	OnCancel();
}

void CDlgSetting::OnBnClickedBtnInitset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	m_bInitClicked = TRUE;
	SetDefaultVal();
}

BOOL CDlgSetting::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	UINT nID = IDC_SETTING_START;
	InitEditCtrl(IDC_EDT_LOSS, nID++, &m_edtLoss);
	InitEditCtrl(IDC_EDT_PROFIT, nID++, &m_edtProfit);
	InitEditCtrl(IDC_EDT_FIX_PROFIT1, nID++, &m_edtFixProfit1);
	InitEditCtrl(IDC_EDT_FIX_PROFIT2, nID++, &m_edtFixProfit2);
	InitEditCtrl(IDC_EDT_FIX_PROFIT3, nID++, &m_edtFixProfit3);
	InitEditCtrl(IDC_EDT_FIX_LOSS1, nID++, &m_edtFixLoss1);
	InitEditCtrl(IDC_EDT_FIX_LOSS2, nID++, &m_edtFixLoss2);
	InitEditCtrl(IDC_EDT_FIX_LOSS3, nID++, &m_edtFixLoss3);
	
	m_edtFixProfit1.SetShareGroup((DWORD)m_edtFixProfit3.GetSafeHwnd());
	m_edtFixProfit3.EnableWindow(FALSE);

	InitTabDlg();

	SetDefaultVal();
	SetPrevValue();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlgSetting::InitEditCtrl(UINT nBaseID, UINT nID, CTEditCtrlWnd *pEdit)
{
	CWnd *pWnd = GetDlgItem(nBaseID);
	if (pWnd)
	{
		CRect rtBaseCtrl;
		pWnd->GetWindowRect(&rtBaseCtrl);
		ScreenToClient(&rtBaseCtrl);

		if (pEdit)
		{
			pEdit->Create(rtBaseCtrl, this, nID, 0xFFFFFF, 3, 2, FALSE, FALSE);
			pWnd->ShowWindow(SW_HIDE);
		}
	}		
}

void CDlgSetting::InitTabDlg()
{
	m_tabRule.InsertItem(0, "일반주문");
	m_tabRule.InsertItem(1, "호가주문");

	CRect rtTab, rtItem;
	m_tabRule.GetClientRect(&rtTab);
	m_tabRule.GetItemRect(0, &rtItem);
	

	m_dlgNormal.m_nMapMode = m_nMapMode;
	m_dlgNormal.Create(IDD_DLG_AUTO_SET_NORMAL, &m_tabRule); //this
	m_dlgNormal.m_pCommWnd = m_pCommWnd;
	m_dlgNormal.SetWindowPos(NULL, 0, rtItem.bottom, rtTab.Width(), rtTab.Height() - rtItem.Height(), SWP_SHOWWINDOW | SWP_NOZORDER);
	//m_dlgNormal.SetWindowPos(NULL, rtItem.left, rtItem.top, rtItem.Width(), rtItem.Height(), SWP_SHOWWINDOW | SWP_NOZORDER);
	m_pCurrentDlg = &m_dlgNormal;

	m_dlgDiv.m_nMapMode = m_nMapMode;
	m_dlgDiv.Create(IDD_DLG_AUTO_SET_DIV, &m_tabRule); //this
	m_dlgDiv.m_pCommWnd = m_pCommWnd;
	m_dlgDiv.SetWindowPos(NULL, 0, rtItem.bottom, rtTab.Width(), rtTab.Height() - rtItem.Height(), SWP_HIDEWINDOW | SWP_NOZORDER);
	//m_dlgDiv.SetWindowPos(NULL, rtItem.left, rtItem.top, rtItem.Width(), rtItem.Height(), SWP_SHOWWINDOW | SWP_NOZORDER);
}

void CDlgSetting::OnTcnSelchangeTabRule(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	ShowHideSubDlgByTab();

	*pResult = 0;
}

void CDlgSetting::SetDefaultVal()
{
	m_rdoAuto.SetCheck(BST_CHECKED);
	m_rdoSemi.SetCheck(BST_UNCHECKED);

	m_chkLoss.SetCheck(BST_UNCHECKED);
	m_edtLoss.SetText("3.5");

	m_chkProfit.SetCheck(BST_UNCHECKED);
	m_edtProfit.SetText("3");

	m_chkFixProfit.SetCheck(BST_UNCHECKED);
	m_edtFixProfit1.SetText("15");
	m_edtFixProfit2.SetText("3");
	m_edtFixProfit3.SetText("15");

	m_chkFixLoss.SetCheck(BST_UNCHECKED);
	m_edtFixLoss1.SetText("15");
	m_edtFixLoss2.SetText("3");
	m_edtFixLoss3.SetText("2");

	m_dlgNormal.SetDefaultNormalVal();
	m_dlgDiv.SetDefaultDivVal();

	m_chkApplyNewItem.SetCheck(BST_UNCHECKED);
}

int CDlgSetting::GetCondCount()
{
	int nRet = 0;
	if (m_chkLoss.GetCheck() == BST_CHECKED)
		nRet++;
	if (m_chkProfit.GetCheck() == BST_CHECKED)
		nRet++;
	if (m_chkFixProfit.GetCheck() == BST_CHECKED)
		nRet++;
	if (m_chkFixLoss.GetCheck() == BST_CHECKED)
		nRet++;

	return nRet;
}

CString CDlgSetting::GetCondExp()
{
	CString strRet = "";
	if (m_chkLoss.GetCheck() == BST_CHECKED)
		strRet = strRet + "|A";
	if (m_chkProfit.GetCheck() == BST_CHECKED)
		strRet = strRet + "|B";
	if (m_chkFixProfit.GetCheck() == BST_CHECKED)
		strRet = strRet + "|C";
	if (m_chkFixLoss.GetCheck() == BST_CHECKED)
		strRet = strRet + "|D";

	if (strRet.GetLength() > 0)
	{
		if (strRet[0] == '|')
			strRet = strRet.Mid(1);
	}
	
	if (strRet.GetLength() > 0)
		strRet = strRet + "!";

	return strRet;
}

void CDlgSetting::GetCondDetail(TR77010_IN *pInput)
{
	int nIndex = 0;
	//char cCondExp = 'A';

	if (m_chkLoss.GetCheck() == BST_CHECKED)
	{
		GetLossCondDetail(nIndex, 'A', &pInput->sCond_obs_detl[nIndex]);
		nIndex++;
		//cCondExp++;
	}

	if (m_chkProfit.GetCheck() == BST_CHECKED)
	{
		GetProfitCondDetail(nIndex, 'B', &pInput->sCond_obs_detl[nIndex]);
		nIndex++;
		//cCondExp++;
	}

	if (m_chkFixProfit.GetCheck() == BST_CHECKED)
	{
		GetFixProfitCondDetail(nIndex, 'C', &pInput->sCond_obs_detl[nIndex]);
		nIndex++;
		//cCondExp++;
	}

	if (m_chkFixLoss.GetCheck() == BST_CHECKED)
	{
		GetFixLossCondDetail(nIndex, 'D', &pInput->sCond_obs_detl[nIndex]);
		nIndex++;
		//cCondExp++;
	}
}

void CDlgSetting::GetLossCondDetail(int nIndex, char cCondExp, User_Define *pUserDef)
{
	InitBuff(pUserDef);

	CString strData;	
	strData.Format("%d", nIndex + 1);
	CopyString(pUserDef->giIndexNo      , sizeof(pUserDef->giIndexNo      ), strData); // 지표 번호
	CopyString(pUserDef->giGroupIdxCnt  , sizeof(pUserDef->giGroupIdxCnt  ), strData); // 그룹내의 지표 개수

	CopyString(pUserDef->giType         , sizeof(pUserDef->giType         ), "-101"); // 지표의 종류

	pUserDef->Element = cCondExp; //	조건식 사용문자

	m_edtLoss.GetWindowText(strData);
	strData.Trim();
	strData.Remove(',');
	CopyString((char *)&pUserDef->Condition[0]	    , sizeof(pUserDef->Condition[0]	    ), strData); //	기타 설정 변수값
}

void CDlgSetting::InitBuff(User_Define *pUserDef)
{
	memset(pUserDef, ' ', sizeof(User_Define));
	CopyString(pUserDef->giGroupNo      , sizeof(pUserDef->giGroupNo      ), "0"); // 그룹 번호
	CopyString(pUserDef->giTargetBase   , sizeof(pUserDef->giTargetBase   ), "0"); // 0:일간, 1:주간, 2:월간, 3:1분, 4:3분 5:5분, 6:10분, 7:15분, 8:30분, 9:60분
	CopyString(pUserDef->giType1        , sizeof(pUserDef->giType1        ), "99"); // Type1 조건 형태
	CopyString(pUserDef->giType2	      , sizeof(pUserDef->giType2	      ), "99"); // 상세 형태  
	CopyString(pUserDef->giSTerm	      , sizeof(pUserDef->giSTerm	      ), "0"); // 그룹검색 시작위치
	CopyString(pUserDef->giETerm	      , sizeof(pUserDef->giETerm	      ), "1"); // 그룹검색 끝  위치
	CopyString(pUserDef->giRank         , sizeof(pUserDef->giRank         ), "100"); // 순위검색 종목 수
	CopyString(pUserDef->giTrend	      , sizeof(pUserDef->giTrend	      ), "2"); // 추세횟수 
	CopyString(pUserDef->giSignalCnt1   , sizeof(pUserDef->giSignalCnt1   ), "1"); // 신호 발생횟수1 
	CopyString(pUserDef->giSignalCnt2	  , sizeof(pUserDef->giSignalCnt2	  ), "1"); // 신호 발생횟수2
	CopyString(pUserDef->giResultViewNum, sizeof(pUserDef->giResultViewNum), "0"); //	결과값보기 필드 갯수(0:사용안함)
	pUserDef->IndexType = '0';// 검색구분 0:일반 1:순위 2:복합
	pUserDef->SearchType = '0'; // 검색형태 0:일반 1:Language 
	pUserDef->Operator = '1'; // 연산자'0':OR '1':AND '2':NEXT
	pUserDef->Reverse = '0'; //	결과제외 '0':A, '1':Not A  
	pUserDef->IdxContiGubun = '0'; //	'0':단일발생, 1:연속발생지표
}

void CDlgSetting::GetProfitCondDetail(int nIndex, char cCondExp, User_Define *pUserDef)
{
	InitBuff(pUserDef);

	CString strData;	
	strData.Format("%d", nIndex);
	CopyString(pUserDef->giIndexNo      , sizeof(pUserDef->giIndexNo      ), strData); // 지표 번호

	strData.Format("%d", nIndex);
	CopyString(pUserDef->giGroupIdxCnt  , sizeof(pUserDef->giGroupIdxCnt  ), strData); // 그룹내의 지표 개수

	CopyString(pUserDef->giType         , sizeof(pUserDef->giType         ), "-102"); // 지표의 종류

	pUserDef->Element = cCondExp; //	조건식 사용문자

	m_edtProfit.GetWindowText(strData);
	strData.Trim();
	strData.Remove(',');
	CopyString((char *)&pUserDef->Condition[0]	    , sizeof(pUserDef->Condition[0]	    ), strData); //	기타 설정 변수값
}

void CDlgSetting::GetFixProfitCondDetail(int nIndex, char cCondExp, User_Define *pUserDef)
{
	InitBuff(pUserDef);

	CString strData;	
	strData.Format("%d", nIndex);
	CopyString(pUserDef->giIndexNo      , sizeof(pUserDef->giIndexNo      ), strData); // 지표 번호

	strData.Format("%d", nIndex);
	CopyString(pUserDef->giGroupIdxCnt  , sizeof(pUserDef->giGroupIdxCnt  ), strData); // 그룹내의 지표 개수

	CopyString(pUserDef->giType         , sizeof(pUserDef->giType         ), "-105"); // 지표의 종류

	pUserDef->Element = cCondExp; //	조건식 사용문자

	m_edtFixProfit1.GetWindowText(strData);
	strData.Trim();
	strData.Remove(',');
	CopyString((char *)&pUserDef->Condition[0]	    , sizeof(pUserDef->Condition[0]	    ), strData); //	기타 설정 변수값

	m_edtFixProfit2.GetWindowText(strData);
	strData.Trim();
	strData.Remove(',');
	CopyString((char *)&pUserDef->Condition[1]	    , sizeof(pUserDef->Condition[1]	    ), strData); //	기타 설정 변수값

	m_edtFixProfit3.GetWindowText(strData);
	strData.Trim();
	strData.Remove(',');
	CopyString((char *)&pUserDef->Condition[2]	    , sizeof(pUserDef->Condition[2]	    ), strData); //	기타 설정 변수값
}

void CDlgSetting::GetFixLossCondDetail(int nIndex, char cCondExp, User_Define *pUserDef)
{
	InitBuff(pUserDef);

	CString strData;	
	strData.Format("%d", nIndex);
	CopyString(pUserDef->giIndexNo      , sizeof(pUserDef->giIndexNo      ), strData); // 지표 번호

	strData.Format("%d", nIndex);
	CopyString(pUserDef->giGroupIdxCnt  , sizeof(pUserDef->giGroupIdxCnt  ), strData); // 그룹내의 지표 개수

	CopyString(pUserDef->giType         , sizeof(pUserDef->giType         ), "-107"); // 지표의 종류

	pUserDef->Element = cCondExp; //	조건식 사용문자

	m_edtFixLoss1.GetWindowText(strData);
	strData.Trim();
	strData.Remove(',');
	CopyString((char *)&pUserDef->Condition[0]	    , sizeof(pUserDef->Condition[0]	    ), strData); //	기타 설정 변수값

	m_edtFixLoss2.GetWindowText(strData);
	strData.Trim();
	strData.Remove(',');
	CopyString((char *)&pUserDef->Condition[1]	    , sizeof(pUserDef->Condition[1]	    ), strData); //	기타 설정 변수값

	m_edtFixLoss3.GetWindowText(strData);
	strData.Trim();
	strData.Remove(',');
	CopyString((char *)&pUserDef->Condition[2]	    , sizeof(pUserDef->Condition[2]	    ), strData); //	기타 설정 변수값
}

void CDlgSetting::SetPrevValue()
{
	if (m_pPrevSet == NULL)
		return;
	
	// 조건 만료 일자. (YYYYMMDD)
	char szBuf[9] = { 0x00, };
	memcpy(szBuf, m_pPrevSet->sCond_expr_date, min(8, sizeof(m_pPrevSet->sCond_expr_date)));
	CString strValidDate = szBuf;
	strValidDate.Trim();

	// 0:처리안함, 1:신규유입처리함

	if (m_pPrevSet->sNewitem_add[0] == '1')
		m_chkApplyNewItem.SetCheck(BST_CHECKED);
	else
		m_chkApplyNewItem.SetCheck(BST_UNCHECKED);


	// 1 : 반자동 주문, 0 : 자동주문
	if (m_pPrevSet->sAuto_gbn[0] == '1')
	{
		m_rdoAuto.SetCheck(BST_UNCHECKED);
		m_rdoSemi.SetCheck(BST_CHECKED);
	}
	else
	{
		m_rdoAuto.SetCheck(BST_CHECKED);
		m_rdoSemi.SetCheck(BST_UNCHECKED);
	}

	BOOL bDiv = FALSE;

	// 1 : 일반 주문, 2 : 호가분할 주문, 3 : 시간분할 주문
	CTime time = CTime::GetCurrentTime();
	if (strValidDate.GetLength() >= 8)
	{
		CString strYear = strValidDate.Mid(0, 4);
		CString strMon = strValidDate.Mid(4, 2);
		CString strDay = strValidDate.Mid(6, 2);
		time = CTime(atol(strYear), atol(strMon), atol(strDay), 0, 0, 0);
	}

	if (m_pPrevSet->sOrd_div_gbn[0] == '1')
	{
		m_tabRule.SetCurSel(0);
		m_dlgNormal.m_dtpValidDate.SetTime(&time);
	}
	else if (m_pPrevSet->sOrd_div_gbn[0] == '2')
	{
		m_tabRule.SetCurSel(1);
		m_dlgDiv.m_dtpValidDate.SetTime(&time);
		bDiv = TRUE;
	}
	else
		return;

	CString strData;

	if (bDiv)
	{
		// '0 ': 정배열, '1':등배열, '2':역배열
		strData = CString(m_pPrevSet->sDIV_GBN, sizeof(m_pPrevSet->sDIV_GBN));
		SetComboCurSel(atol(strData), &m_dlgDiv.m_cmbInc);

		// '0' : 매수방향, '1':매도방향
		strData = CString(m_pPrevSet->sDIV_ORD_GBN, sizeof(m_pPrevSet->sDIV_ORD_GBN));
		SetComboCurSel(atol(strData), &m_dlgDiv.m_cmbDir);

		// 일반주문의 경우 1. 호가분할 및 시간 분할인 경우 분할 횟수
		strData = CString(m_pPrevSet->sOrd_cnt, sizeof(m_pPrevSet->sOrd_cnt));
		m_dlgDiv.m_edtCount.SetWindowText(strData);
		m_dlgDiv.m_spnCount.SetPos(atol(strData));
	}
	
	//m_pPrevSet->sORD_INTERVAL// 시간분할 주문시 분할 간격 (최소 1분 ~ 최대 60분.)

	// " '1':지정가,       '2':시장가 '3':최유리지정가, '4':최우선지정가 '5':매수1호가,    '6':매수2호가 '7':매도1호가,    '8':매도2호가"
	strData = CString(m_pPrevSet->sOrd_gbn, sizeof(m_pPrevSet->sOrd_gbn));
	strData.Trim();
	for (int i = 0; i < _countof(PRICE_TYPE_VALUE_EX); i++)
	{
		if (strData == PRICE_TYPE_VALUE_EX[i])
		{
			CString strPriceTypeText = PRICE_TYPE_STRING_EX[i];
			SetComboText(strPriceTypeText, &m_dlgNormal.m_cmbPriceType);
			break;
		}
	}

	//m_pPrevSet->sORD_QRY_GBN// 1:수량직접입력, 2:백분율로 입력

	// 기준수량 (ex: 잔고의 50%) 수량 구분에 따라 수량 혹은 백분율로 입력됨.
	CString strBaseQty = CString(m_pPrevSet->sORD_BASE_QRY, sizeof(m_pPrevSet->sORD_BASE_QRY));
	strBaseQty.Trim();

	// 주문수량1  수량 혹은 백분률( 1 ~ 100%)  로 입력됨.
	CString strQty1 = CString(m_pPrevSet->sOrd_qty1, sizeof(m_pPrevSet->sOrd_qty1));
	strQty1.Trim();

	if (bDiv == FALSE)
	{
		
		m_dlgNormal.m_edtRate.SetWindowText(strQty1);
		m_dlgNormal.m_spnRate.SetPos(atol(strQty1));
	}
	else
	{
		m_dlgDiv.m_edtRate.SetWindowText(strBaseQty);
		m_dlgDiv.m_spnRate.SetPos(atol(strBaseQty));

		//m_dlgDiv.m_edtCount.SetWindowText(strData);
		int nCnt = m_dlgDiv.m_spnCount.GetPos();		
		m_dlgDiv.m_stcComplex.SetRowCount(nCnt);

		CString strTemp;
		if (nCnt > 0)
		{
			strTemp = CString(m_pPrevSet->sOrd_qty1, sizeof(m_pPrevSet->sOrd_qty1));
			strTemp.Trim();
			m_dlgDiv.m_stcComplex.m_SpinRate1.SetPos(atol(strTemp));
		}

		if (nCnt > 1)
		{
			strTemp = CString(m_pPrevSet->sOrd_qty2, sizeof(m_pPrevSet->sOrd_qty2));
			strTemp.Trim();
			m_dlgDiv.m_stcComplex.m_SpinRate2.SetPos(atol(strTemp));
		}

		if (nCnt > 2)
		{
			strTemp = CString(m_pPrevSet->sOrd_qty3, sizeof(m_pPrevSet->sOrd_qty3));
			strTemp.Trim();
			m_dlgDiv.m_stcComplex.m_SpinRate3.SetPos(atol(strTemp));
		}

		if (nCnt > 3)
		{
			strTemp = CString(m_pPrevSet->sOrd_qty4, sizeof(m_pPrevSet->sOrd_qty4));
			strTemp.Trim();
			m_dlgDiv.m_stcComplex.m_SpinRate4.SetPos(atol(strTemp));
		}

		if (nCnt > 4)
		{
			strTemp = CString(m_pPrevSet->sOrd_qty5, sizeof(m_pPrevSet->sOrd_qty5));
			strTemp.Trim();
			m_dlgDiv.m_stcComplex.m_SpinRate5.SetPos(atol(strTemp));
		}
	}	

	// 주문가격 (매수1/2/3호가, 매도 1/2/3 호가) 혹은 지정가로 저장 (ex) D1 :매도1호가, S2 :매수2호가, J12300 : 지정가 12300원)
	strData = CString(m_pPrevSet->sOrd_prc, sizeof(m_pPrevSet->sOrd_prc));
	strData.Trim();

	if (bDiv == FALSE)
	{
		BOOL bSet = FALSE;
		for (int i = 0; i < _countof(PRICE_TYPE_STRING2); i++)
		{
			if (strData == PRICE_TYPE_STRING2[i])
			{
				CString strCmbText = PRICE_GB_STRING[i];
				SetComboText(strCmbText, &m_dlgNormal.m_cmbSelPrice);
				bSet = TRUE;
				break;
			}
		}

		if (bSet == FALSE)
		{
			// JXXXX 방식의 지정가
			if (strData.GetLength() > 0 && strData[0] == 'J')
			{
				strData = strData.Mid(1);
				m_dlgNormal.m_cmbSelPrice.SetCurSel(0); // 지정가
				m_dlgNormal.m_edtPrice.SetWindowText(strData);
				m_dlgNormal.m_spnPrice.SetPos(atol(strData));
			}
		}
	}
	else
	{
		for (int i = DIVSTANDARD_INDEX; i < _countof(PRICE_STANDARD_STRING_CONVERT); i++)
		{
			if (strData == PRICE_STANDARD_STRING_CONVERT[i])
			{
				CString strCmbText = PRICE_STANDARD_STRING[i];
				SetComboText(strCmbText, &m_dlgNormal.m_cmbSelPrice);
				break;
			}
		}
	}

	//m_pPrevSet->sCond_obs_gbn// 1': 손익조건, '2':사용자조건

	// 최대 20개, USER_DEF 사이즈과 관련
	strData = CString(m_pPrevSet->sCond_obs_cnt, sizeof(m_pPrevSet->sCond_obs_cnt));
	strData.Trim();
	int nCnt = atol(strData);

	// "조건검색의 EXPLEN값 사용(80) 게좌조건의 경우는 모두 'OR'로 연결 사용자조건의 경우는 사용자 입력 조합식"
	CStringArray arAlphabet;
	strData = CString(m_pPrevSet->sCond_obs_mix, sizeof(m_pPrevSet->sCond_obs_mix));
	strData.Trim();
	if (strData.GetLength() > 1)
	{
		strData = strData.Left(strData.GetLength() - 1);
		GetArgs(strData, arAlphabet, '|');
	}

	int nArrs = arAlphabet.GetSize();
	for (int i = 0; i < nCnt && i < nArrs; i++)
	{
		CString str = arAlphabet.GetAt(i);
		SetCondCtrl(str, &m_pPrevSet->sCond_obs_detl[i]);
	}

	if (bDiv)
	{
		//m_dlgDiv.OnBnClickedBtnDivApply();
		m_dlgDiv.m_stcComplex.CalcVolume();
	}
	else
	{
		m_dlgNormal.OnCbnSelchangeCmbPriceType();
		int nSel = m_dlgNormal.m_cmbPriceType.GetCurSel();
		if (nSel != CB_ERR)
		{
			CString strVal;
			m_dlgNormal.m_cmbPriceType.GetLBText(nSel, strVal);
			if (strVal.Find("시장가") < 0) // 시장가가 아니면
			{
				m_dlgNormal.OnCbnSelchangeCmbSelPrice(); // 구분콤보에 대한 처리
			}
		}
	}

	if (bDiv)
	{
		m_tabRule.SetCurSel(1);
		ShowHideSubDlgByTab();
	}
}

void CDlgSetting::SetComboText(CString strText, CComboBox *pCombo)
{
	if (pCombo == NULL)
		return;

	int nIdx = pCombo->FindStringExact(0, strText);
	if (nIdx != CB_ERR)
		pCombo->SetCurSel(nIdx);
}

void CDlgSetting::SetComboCurSel(int nIdx, CComboBox *pCombo)
{
	if (pCombo == NULL)
		return;

	int nCnt = pCombo->GetCount();
	if (nIdx < nCnt)
		pCombo->SetCurSel(nIdx);
}

void CDlgSetting::SetCondCtrl(CString strCondType, User_Define *pUserDef)
{
	if (strCondType.GetLength() <= 0 || pUserDef == NULL)
		return;

	if (strCondType[0] == 'A')
	{
		m_chkLoss.SetCheck(BST_CHECKED);
		CString strData = CString(pUserDef->Condition[0].szData, sizeof(CHAR10));
		m_edtLoss.SetWindowText(strData.Trim());
		m_edtLoss.AdjustText();
	}
	else if (strCondType[0] == 'B')
	{
		m_chkProfit.SetCheck(BST_CHECKED);
		CString strData = CString(pUserDef->Condition[0].szData, sizeof(CHAR10));
		m_edtProfit.SetWindowText(strData.Trim());
		m_edtProfit.AdjustText();
	}
	else if (strCondType[0] == 'C')
	{
		m_chkFixProfit.SetCheck(BST_CHECKED);
		CString strData1 = CString(pUserDef->Condition[0].szData, sizeof(CHAR10));
		CString strData2 = CString(pUserDef->Condition[1].szData, sizeof(CHAR10));
		CString strData3 = CString(pUserDef->Condition[2].szData, sizeof(CHAR10));
		m_edtFixProfit1.SetWindowText(strData1.Trim());
		m_edtFixProfit2.SetWindowText(strData2.Trim());
		m_edtFixProfit3.SetWindowText(strData3.Trim());
		m_edtFixProfit1.AdjustText();
		m_edtFixProfit2.AdjustText();
		m_edtFixProfit3.AdjustText();
	}
	else if (strCondType[0] == 'D')
	{
		m_chkFixLoss.SetCheck(BST_CHECKED);
		CString strData1 = CString(pUserDef->Condition[0].szData, sizeof(CHAR10));
		CString strData2 = CString(pUserDef->Condition[1].szData, sizeof(CHAR10));
		CString strData3 = CString(pUserDef->Condition[2].szData, sizeof(CHAR10));
		m_edtFixLoss1.SetWindowText(strData1.Trim());
		m_edtFixLoss2.SetWindowText(strData2.Trim());
		m_edtFixLoss3.SetWindowText(strData3.Trim());
		m_edtFixLoss1.AdjustText();
		m_edtFixLoss2.AdjustText();
		m_edtFixLoss3.AdjustText();
	}
}

void CDlgSetting::ShowHideSubDlgByTab()
{
	if (m_pCurrentDlg)
		m_pCurrentDlg->ShowWindow(SW_HIDE);

	int nSel = m_tabRule.GetCurSel();
	if (nSel == 0)
		m_pCurrentDlg = &m_dlgNormal;
	else
		m_pCurrentDlg = &m_dlgDiv;

	m_pCurrentDlg->ShowWindow(SW_SHOW);
}


BOOL CDlgSetting::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	switch (pMsg->message)
	{
	case WM_KEYDOWN:
		if (pMsg->wParam == VK_RETURN)
		{
			return TRUE;
		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}


void CDlgSetting::OnDestroy()
{
	CDialog::OnDestroy();
}


// DlgSetDiv.cpp : 구현 파일입니다.
//

#include "stdafx.h"
//#include "TrSvrAutoOrd.h"
#include "DlgSetDiv.h"

#include "include_auto/globalauto.h"

// CDlgSetDiv 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgSetDiv, CDialog)

CDlgSetDiv::CDlgSetDiv(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSetDiv::IDD, pParent)
{
	LOGFONT logFont;
	GETFONT(logFont, 12, 400, m_fntDefault);

	m_nAvailSellVol = 100; // 종목을 알 수 없으니 그냥 디폴트 100으로 셋팅
	m_pCommWnd = NULL;
	m_nMapMode = MODE_EQUITIES;
}

CDlgSetDiv::~CDlgSetDiv()
{
}

void CDlgSetDiv::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CMB_INC, m_cmbInc);
	DDX_Control(pDX, IDC_CMB_BASE_PRICE, m_cmbBasePrice);
	DDX_Control(pDX, IDC_CMB_DIR, m_cmbDir);
	DDX_Control(pDX, IDC_DTP_VALID_DATE, m_dtpValidDate);
}


BEGIN_MESSAGE_MAP(CDlgSetDiv, CDialog)
	//ON_BN_CLICKED(IDC_BTN_DIV_APPLY, &CDlgSetDiv::OnBnClickedBtnDivApply)
	//ON_BN_CLICKED(IDC_BTN_AVAILSELLVOL, &CDlgSetDiv::OnBnClickedBtnAvailsellvol)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DTP_VALID_DATE, &CDlgSetDiv::OnDtnDatetimechangeDtpValidDate)
	ON_NOTIFY(DTN_CLOSEUP, IDC_DTP_VALID_DATE, &CDlgSetDiv::OnDtnCloseupDtpValidDate)
END_MESSAGE_MAP()


// CDlgSetDiv 메시지 처리기입니다.

void CDlgSetDiv::ShowVolDiv(BOOL bShowMsg)
{
	////TRACEP("1", "ShowVolDiv");
	CString strCount;
	m_edtCount.GetWindowText(strCount);
	
	if (bShowMsg)
	{
		if (m_nAvailSellVol == 0)
		{
			DefMessageBox(GetSafeHwnd(), "가 버튼을 이용하여 수량을 조회해야 분할 주문수량을  확인할 수 있습니다.");
			return;
		}

		if (atol(strCount) <= 0)
		{
			DefMessageBox(GetSafeHwnd(), "매도비중을 입력하여 주십시오.");
			return;
		}
	}

	m_stcComplex.SetDivWay(m_cmbDir.GetCurSel()); // 분할방향
	m_stcComplex.SetHogaOrTimeDiv(HOGADIV_ORDER, atoi(strCount));
	m_stcComplex.SetStandardPrice(m_cmbBasePrice.GetCurSel()); // 기준가 적용
	m_stcComplex.SetBarType(m_cmbInc.GetCurSel());
	m_stcComplex.SetDivType(m_cmbInc.GetCurSel()); // 분할기준 적용
	
	
	if (strCount.GetLength() <= 0 || strCount == "0")
		strCount = "2";
	m_stcComplex.SetRowCount(atol(strCount)); // 분할수 적용

	////TRACEP("2", "CalcVolume");
	m_stcComplex.CalcVolume();
}

void CDlgSetDiv::OnBnClickedBtnDivApply()
{

	ShowVolDiv(TRUE);
}

void CDlgSetDiv::SetDefaultDivVal()
{
	// data
	m_nAvailSellVol = 100; // 주문가능수량은 종목을 알 수 없으니 그냥 디폴트 100으로 셋팅

	// ctrl
	//m_cmbValidDate.SetCurSel(0);

	m_edtRate.SetWindowText("0");
	m_spnRate.SetPos(0);

	m_cmbInc.SetCurSel(1);
	
	m_edtCount.SetWindowText("5");
	m_spnCount.SetPos(5);

	m_cmbBasePrice.SetCurSel(0);
	m_cmbDir.SetCurSel(0);

	m_stcComplex.SetDivType(m_cmbInc.GetCurSel());
	m_stcComplex.SetStandardPrice(m_cmbBasePrice.GetCurSel());

	// 적용
	ShowVolDiv(FALSE);
}

BOOL CDlgSetDiv::OnInitDialog()
{
	CDialog::OnInitDialog();

	//유효기간
	m_dtpValidDate.SetFormat("yyyy/MM/dd");
	CTime tm = CTime::GetCurrentTime();
	m_dtpValidDate.SetTime(&tm);

	// 매도비중/청산비중 타이틀
	if (m_nMapMode == MODE_EQUITIES)
	{
	}
	else
	{
		CWnd *pWnd = GetDlgItem(IDC_STC_RATE);
		if (pWnd)
			pWnd->SetWindowText("청산비중");
	}

	// 매도비중
	UINT nID = IDC_SETNORMAL_START;
	CWnd *pWnd = GetDlgItem(IDC_EDT_RATE);
	CRect rtBase(0, 0, 0, 0);
	if (pWnd)
	{
		pWnd->GetWindowRect(&rtBase);
		pWnd->ShowWindow(SW_HIDE);
	}
	ScreenToClient(&rtBase);
	CRect rtEdit = rtBase;
	rtEdit.right = rtEdit.right + LEN_SPIN_WIDTH;
	m_edtRate.Create(WS_CHILD | WS_VISIBLE | ES_RIGHT, rtEdit, this, nID++);
	m_edtRate.SetFont(&m_fntDefault);
	m_edtRate.SetPlaces(3, 0);
	m_edtRate.SetEditRange(0, 100);
	
	CString strImagePath;
	GetDir_DrfnRoot(strImagePath);
	strImagePath += "\\Image";
	CRect rtSpin = rtBase;
	rtSpin.left = rtSpin.right - LEN_SPIN_WIDTH;
	m_spnRate.SetImagePath(strImagePath);
	m_spnRate.Create(WS_CHILD | WS_VISIBLE | UDS_ALIGNRIGHT  | UDS_AUTOBUDDY, rtSpin, this, nID++);
	m_spnRate.SetBuddy(&m_edtRate);
	m_spnRate.SetDecimalPlaces(0);
	m_spnRate.SetTrimTrailingZeros(FALSE);
	m_spnRate.SetNoRemain(FALSE);
	m_spnRate.SetRangeAndDelta(0, 100, 5);
	m_spnRate.SetPos(0);

	// 분할기준
	for(int i = 0; i < _countof(DIV_STANDARD_STRING); i++)
		m_cmbInc.AddString(DIV_STANDARD_STRING[i]);
	
	// 분할수
	pWnd = GetDlgItem(IDC_EDT_COUNT);
	rtBase = CRect(0, 0, 0, 0);
	if (pWnd)
	{
		pWnd->GetWindowRect(&rtBase);
		pWnd->ShowWindow(SW_HIDE);
	}
	ScreenToClient(&rtBase);
	rtEdit = rtBase;
	rtEdit.right = rtEdit.right + LEN_SPIN_WIDTH;
	m_edtCount.Create(WS_CHILD | WS_VISIBLE | ES_RIGHT, rtEdit, this, nID++);
	m_edtCount.SetFont(&m_fntDefault);
	m_edtCount.SetPlaces(1, 0);
	m_edtCount.SetEditRange(0, 5);	

	rtSpin = rtBase;
	rtSpin.left = rtSpin.right - LEN_SPIN_WIDTH;
	m_spnCount.SetImagePath(strImagePath);
	m_spnCount.Create(WS_CHILD | WS_VISIBLE | UDS_ALIGNRIGHT  | UDS_AUTOBUDDY, rtSpin, this, nID++);
	m_spnCount.SetBuddy(&m_edtCount);
	m_spnCount.SetDecimalPlaces(0);
	m_spnCount.SetTrimTrailingZeros(FALSE);
	m_spnCount.SetRangeAndDelta (2, 5, 1);
	
	// 기준가
	for (int i = DIVSTANDARD_INDEX; i <= DIVSTANDARD_INDEX * 2 + 1; i++)
		m_cmbBasePrice.AddString(PRICE_STANDARD_STRING[i]);
	
	// 분할방향
	m_cmbDir.AddString("매수방향");
	m_cmbDir.AddString("매도방향");

	
	// 
	m_stcComplex.ShowComment(TRUE);
	m_stcComplex.CreateWnd(this, IDC_STC_DIV);
	pWnd = GetDlgItem(IDC_STC_DIV);
	rtBase = CRect(0, 0, 0, 0);
	if (pWnd)
	{
		pWnd->GetWindowRect(&rtBase);
		pWnd->ShowWindow(SW_HIDE);
	}
	ScreenToClient(&rtBase);
	m_stcComplex.MoveWindow(&rtBase);

	//
	SetDefaultDivVal();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlgSetDiv::OnBnClickedBtnAvailsellvol()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (m_pCommWnd)
	{
	}
}

LRESULT CDlgSetDiv::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	switch (message)
	{
	case UMSG_GET_SELL_VOLUME:
		{
			double *pVol = (double *)lParam;

			CString strRate;
			m_edtRate.GetWindowText(strRate);
			*pVol = (double)m_nAvailSellVol * (atof(strRate) / 100.0);
			return 1L;
		}
		break;

	case WM_KEYDOWN:
		if (wParam == VK_RETURN)
		{
		}
	}

	return CDialog::WindowProc(message, wParam, lParam);
}

void CDlgSetDiv::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

//	CDialog::OnOK();
}

void CDlgSetDiv::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

//	CDialog::OnCancel();
}

BOOL CDlgSetDiv::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	if (pMsg->message == WM_LBUTTONDOWN)
	{
		////TRACEP("1", "LD");
		CWnd *pWnd = GetDlgItem(IDC_BTN_DIV_APPLY);
		if (pMsg->hwnd == pWnd->GetSafeHwnd())
		{
			CRect rtBtn;
			pWnd->GetWindowRect(&rtBtn);
			//ScreenToClient(&rtBtn);
			if (rtBtn.PtInRect(pMsg->pt)) // 핸들이 같은 값으로 계속 들어오는 경우(?)가 있어서 다시 체크
			{
				OnBnClickedBtnDivApply();
			}
		}		
	}

	return CDialog::PreTranslateMessage(pMsg);
}

void CDlgSetDiv::OnDtnDatetimechangeDtpValidDate(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	/*
	CTime tm;
	m_dtpValidDate.GetTime(tm);
	CTimeSpan span = tm - CTime::GetCurrentTime();
	if (span.GetDays() > 90)
	{
		DefMessageBox(GetSafeHwnd(), "유효기간은 90일이내로 설정하십시오.");
	}
	*/

	*pResult = 0;
}

void CDlgSetDiv::OnDtnCloseupDtpValidDate(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}

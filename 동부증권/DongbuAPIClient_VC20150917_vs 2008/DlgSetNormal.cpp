// DlgSetNormal.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "DlgSetNormal.h"
#include "include_auto/globalauto.h"



// CDlgSetNormal ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgSetNormal, CDialog)

CDlgSetNormal::CDlgSetNormal(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSetNormal::IDD, pParent)
{
	LOGFONT logFont;
	GETFONT(logFont, 12, 400, m_fntDefault);

	m_pCommWnd = NULL;
	m_nMapMode = MODE_EQUITIES;
}

CDlgSetNormal::~CDlgSetNormal()
{
}

void CDlgSetNormal::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_CMB_VALID_DATE, m_cmbValidDate);
	DDX_Control(pDX, IDC_CMB_PRICE_TYPE, m_cmbPriceType);
	//DDX_Control(pDX, IDC_EDT_RATE, m_edtRate);
	DDX_Control(pDX, IDC_CMB_SEL_PRICE, m_cmbSelPrice);
	DDX_Control(pDX, IDC_CHK_BEST_PRICE, m_chkBestPrice);
	DDX_Control(pDX, IDC_DTP_VALID_DATE, m_dtpValidDate);
}


BEGIN_MESSAGE_MAP(CDlgSetNormal, CDialog)
	ON_BN_CLICKED(IDC_CHK_BEST_PRICE, &CDlgSetNormal::OnBnClickedChkBestPrice)
	ON_CBN_SELCHANGE(IDC_CMB_PRICE_TYPE, &CDlgSetNormal::OnCbnSelchangeCmbPriceType)
	ON_CBN_SELCHANGE(IDC_CMB_SEL_PRICE, &CDlgSetNormal::OnCbnSelchangeCmbSelPrice)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DTP_VALID_DATE, &CDlgSetNormal::OnDtnDatetimechangeDtpValidDate)
	ON_NOTIFY(DTN_CLOSEUP, IDC_DTP_VALID_DATE, &CDlgSetNormal::OnDtnCloseupDtpValidDate)
END_MESSAGE_MAP()


// CDlgSetNormal �޽��� ó�����Դϴ�.

void CDlgSetNormal::SetDefaultNormalVal()
{
	//m_cmbValidDate.SetCurSel(0);

	m_cmbSelPrice.EnableWindow(TRUE);
	m_cmbPriceType.SetCurSel(0);
	
	m_chkBestPrice.SetCheck(BST_UNCHECKED);
	OnBnClickedChkBestPrice();

	m_edtRate.SetWindowText("0");
	m_spnRate.SetPos(0);
	
	m_cmbSelPrice.SetCurSel(0);
	
	m_edtPrice.SetWindowText("0");
	m_spnPrice.SetPos(0);
}

BOOL CDlgSetNormal::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��ȿ�Ⱓ
	m_dtpValidDate.SetFormat("yyyy/MM/dd");
	CTime tm = CTime::GetCurrentTime();
	m_dtpValidDate.SetTime(&tm);

	// �ֹ�����
	for (int i = 0; i < PRICETYPE_CNT_STOCK; i++)
		m_cmbPriceType.AddString(PRICE_TYPE_STRING_EX[i]);
	
	// �ŵ�����/û����� Ÿ��Ʋ
	if (m_nMapMode == MODE_EQUITIES)
	{
	}
	else
	{
		CWnd *pWnd = GetDlgItem(IDC_STC_RATE);
		if (pWnd)
			pWnd->SetWindowText("û�����");
	}

	// �ŵ�����
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
	m_edtRate.Create(WS_CHILD | WS_VISIBLE | ES_RIGHT | ES_NUMBER, rtEdit, this, nID++);
	m_edtRate.SetFont(&m_fntDefault);
	m_edtRate.SetPlaces(3, 0);
	m_edtRate.SetEditRange(0, 100);	

	CString strImagePath;
	GetDir_DrfnRoot(strImagePath);
	strImagePath += "\\Image";
	CRect rtSpin = rtBase;
	rtSpin.left = rtSpin.right - LEN_SPIN_WIDTH;
	//m_spnRate.SetImagePath(strImagePath);
	m_spnRate.Create(WS_CHILD | WS_VISIBLE | UDS_ALIGNRIGHT  | UDS_AUTOBUDDY, rtSpin, this, nID++);
	m_spnRate.SetBuddy(&m_edtRate);
	m_spnRate.SetDecimalPlaces(0);
	m_spnRate.SetTrimTrailingZeros(FALSE);
	m_spnRate.SetRangeAndDelta(0, 100, 5);
	m_spnRate.SetPos(0);

	// �ŵ��ܰ�/û��ܰ� Ÿ��Ʋ
	if (m_nMapMode == MODE_EQUITIES)
	{
	}
	else
	{
		CWnd *pWnd = GetDlgItem(IDC_STC_SEL_PRICE);
		if (pWnd)
			pWnd->SetWindowText("û��ܰ�");
	}

	// �ŵ��ܰ� �޺�
	int nCnt = _countof(PRICE_GB_STRING);

	if (m_nMapMode == MODE_EQUITIES)
	{
	}
	else
	{
		nCnt = nCnt - 2; // ����, �ֽļ������� ������, ���Ѱ� ����
	}

	for (int i = 0; i < nCnt; i++)
		m_cmbSelPrice.AddString(PRICE_GB_STRING[i]);
	
	// �ŵ��ܰ� ����Ʈ
	pWnd = GetDlgItem(IDC_EDT_PRICE);
	rtBase = CRect(0, 0, 0, 0);
	if (pWnd)
	{
		pWnd->GetWindowRect(&rtBase);
		pWnd->ShowWindow(SW_HIDE);
	}
	ScreenToClient(&rtBase);
	rtEdit = rtBase;
	rtEdit.right = rtEdit.right + LEN_SPIN_WIDTH;
	m_edtPrice.Create(WS_CHILD | WS_VISIBLE | ES_RIGHT, rtEdit, this, nID++);
	m_edtPrice.SetFont(&m_fntDefault);

	UDACCEL accels[]={{0,1}}; 
	rtSpin = rtBase;
	rtSpin.left = rtSpin.right - LEN_SPIN_WIDTH;
	//m_spnPrice.SetImagePath(strImagePath);
	m_spnPrice.Create(WS_CHILD | WS_VISIBLE | UDS_ALIGNRIGHT  | UDS_AUTOBUDDY, rtSpin, this, nID++);
	m_spnPrice.SetBuddy(&m_edtPrice);
	m_spnPrice.SetTrimTrailingZeros(FALSE);

	if (m_nMapMode == MODE_EQUITIES)
	{
		m_spnPrice.SetDecimalPlaces(0);
		m_spnPrice.SetRangeAndDelta(0, 999999999, 1);
		m_spnPrice.SetPos(0);

		//m_edtPrice.SetEditRange(0, 999999999);
		m_edtPrice.SetPlaces(9, 0);
	}
	else
	{
		m_spnPrice.SetDecimalPlaces(2);
		m_spnPrice.SetRangeAndDelta(0, 999999999, 0.01);
		m_spnPrice.SetPos(0);
		m_spnPrice.SetFormatString("%.2f");
		
		m_edtPrice.SetPlaces(9, 2);
	}
	m_spnPrice.SetAccel(1,accels);

	SetDefaultNormalVal();

	if (m_nMapMode == MODE_EQUITIES)
	{
	}
	else
	{
		UINT unID[] = { IDC_STATIC4, IDC_STATIC5, IDC_STATIC6, IDC_STATIC7 };
		for (int i = 0; i < 4; i++)
		{
			CWnd *pWnd = GetDlgItem(unID[i]);
			pWnd->ShowWindow(SW_HIDE);
		}

		// 20140811 ssj - ���� ���� �߰� �� �ǽð� �����Ѱ� >>
		GetDlgItem(IDC_STATIC1)->SetWindowText("�� ���� ��");
		GetDlgItem(IDC_STATIC2)->SetWindowText("��ü������ ����/�ֽļ��� �����ϰ� ����˴ϴ�.");
		GetDlgItem(IDC_STATIC3)->SetWindowText("�ֽļ����� �ֹ������� ������(IOC/FOK)�� �ֹ�ó���� �����մϴ�.");

		CRect rtTemp2, rtTemp3;
		GetDlgItem(IDC_STATIC2)->GetWindowRect(&rtTemp2);
		GetDlgItem(IDC_STATIC3)->GetWindowRect(&rtTemp3);
		rtTemp3.left = rtTemp2.left;
		ScreenToClient(&rtTemp3);
		GetDlgItem(IDC_STATIC3)->MoveWindow(&rtTemp3);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CDlgSetNormal::OnBnClickedChkBestPrice()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	if (m_chkBestPrice.GetCheck() == BST_CHECKED)
	{
		m_cmbSelPrice.EnableWindow(FALSE);
		m_edtPrice.EnableWindow(FALSE);
		m_edtPrice.SetWindowText("");
		m_cmbPriceType.SetCurSel(1);
	}
	else
	{
		m_cmbSelPrice.EnableWindow(TRUE);
		m_edtPrice.EnableWindow(TRUE);
		m_cmbPriceType.SetCurSel(0);
	}
}

void CDlgSetNormal::OnCbnSelchangeCmbPriceType()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	int nSel = m_cmbPriceType.GetCurSel();
	if (nSel != CB_ERR)
	{
		CString strVal;
		m_cmbPriceType.GetLBText(nSel, strVal);
		if (strVal.Find("���尡") >= 0)
		{
			m_chkBestPrice.SetCheck(BST_CHECKED);

			m_cmbSelPrice.EnableWindow(FALSE);
			m_edtPrice.EnableWindow(FALSE);
			m_edtPrice.SetWindowText("");
		}
		else
		{
			m_chkBestPrice.SetCheck(BST_UNCHECKED);

			m_cmbSelPrice.EnableWindow(TRUE);
			m_edtPrice.EnableWindow(TRUE);
		}
	}
}

void CDlgSetNormal::OnCbnSelchangeCmbSelPrice()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	int nSel = m_cmbSelPrice.GetCurSel();
	if (nSel == 0) // �������� �̸�
	{
		m_edtPrice.EnableWindow(TRUE);
	}
	else
	{
		m_edtPrice.EnableWindow(FALSE);
	}
}

void CDlgSetNormal::OnOK()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

//	CDialog::OnOK();
}

void CDlgSetNormal::OnCancel()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

//	CDialog::OnCancel();
}

void CDlgSetNormal::OnDtnDatetimechangeDtpValidDate(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	/*
	CTime tm;
	m_dtpValidDate.GetTime(tm);
	CTimeSpan span = tm - CTime::GetCurrentTime();
	if (span.GetDays() > 90)
	{
		DefMessageBox(GetSafeHwnd(), "��ȿ�Ⱓ�� 90���̳��� �����Ͻʽÿ�.");
	}
	*/

	*pResult = 0;
}

void CDlgSetNormal::OnDtnCloseupDtpValidDate(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}

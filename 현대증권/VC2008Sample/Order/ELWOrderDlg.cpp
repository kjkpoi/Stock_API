// ELWOrderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ELWOrder.h"
#include "ELWOrderDlg.h"

// �߰�
#include "Events.h"

//��ȸ������ó����ü
IYFRequestDataPtr m_pRequestData;
CYFRequestEvent* m_pRequestEvent;

//�ǽð������� ���/���� ��ü
IYFRealPtr m_pRealData;
CYFRealEvent* m_pRealEvent;


//�ֹ�ó����ü
IYFOrderPtr m_pOrder;
CYFOrderEvent* m_pOrderEvent;


//���ŵ� ������ ó�� ��ü(���ϼ�������--���簡,�ǽð�������)
IYFValuesPtr m_pValueData;

//���ŵ� ������ ó�� ��ü(����Ʈ��������--���񸮽�Ʈ ��)
IYFValueListPtr m_pValueListData;
CYFValueListEvent* m_pValueListEvent;

/////////////////////////////////////////////////////////////////////////////
//�ֹ� �� ��ȸ TR�� �����ؼ� ����Ͻø� ELW �ֹ� �� ��ȸ�� �����մϴ�.
////////////////////////////////////////////////////////////////////////////


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CELWOrderDlg dialog

CELWOrderDlg::CELWOrderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CELWOrderDlg::IDD, pParent)
{
	AfxEnableControlContainer();

	//{{AFX_DATA_INIT(CELWOrderDlg)
	m_txtStatus = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	EnableAutomation();
	EnableConnections();


}

void CELWOrderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CELWOrderDlg)
	DDX_Control(pDX, IDC_STATIC_STATUS, m_ctlStatus);
	DDX_Control(pDX, IDC_AMOUNT, m_edtAmount);
	DDX_Control(pDX, IDC_PRICE, m_edtPrice);
	DDX_Control(pDX, IDC_ORDER_NO, m_edtOrderNo);
	DDX_Control(pDX, IDC_ORDER_GUBUN, m_cmbOrderGubun);
	DDX_Control(pDX, IDC_CODE, m_edtCode);
	DDX_Control(pDX, IDC_TAB_ORDER, m_tabOrder);
	DDX_Control(pDX, IDC_COMBO_ACCOUNTNO, m_cmbAccountNo);
	DDX_Text(pDX, IDC_STATIC_STATUS, m_txtStatus);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_CURDATA, m_edtCurData);
	DDX_Control(pDX, IDC_BUTTON1, m_btnUnexec);
//	DDX_Control(pDX, IDC_UNEXEC, m_edtUnexec);
	DDX_Control(pDX, IDC_EDIT1, m_edtPasswd);
	DDX_Control(pDX, IDC_CURDATA3, m_edtCurData1);
	DDX_Control(pDX, IDC_UNEXEC2, m_edtUnexec2);
	DDX_Control(pDX, IDC_REALDATA, m_edtRealData);
}

BEGIN_MESSAGE_MAP(CELWOrderDlg, CDialog)
	//{{AFX_MSG_MAP(CELWOrderDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_ORDER, OnSelchangeTabOrder)
	ON_BN_CLICKED(IDC_ORDERBTN, OnOrderbtn)
	ON_BN_CLICKED(IDC_BTN_CODE, OnBtnCode)
	ON_BN_CLICKED(IDC_BTN_ELWCur, OnBTNELWCur)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CELWOrderDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BTN_CODEREG, &CELWOrderDlg::OnBnClickedBtnCodereg)
	ON_BN_CLICKED(IDC_BTN_ACCOUNTREG, &CELWOrderDlg::OnBnClickedBtnAccountreg)
	ON_BN_CLICKED(IDC_BTN_CODEREG2, &CELWOrderDlg::OnBnClickedBtnCodereg2)
	ON_BN_CLICKED(IDC_BTN_ACCOUNTREG2, &CELWOrderDlg::OnBnClickedBtnAccountreg2)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CELWOrderDlg message handlers

BOOL CELWOrderDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	//AtlAdviseSinkMap (this, TRUE);

	// TODO: Add extra initialization here
	m_tabOrder.SetCurSel(0);
	OrderTab_ControlEnable(0);

	TCITEM tcItem;
	tcItem.mask = TCIF_TEXT;
	tcItem.pszText = _T("�ŵ�");
	m_tabOrder.InsertItem( 0, &tcItem );
	tcItem.pszText = _T("�ż�");
	m_tabOrder.InsertItem( 1, &tcItem );
	tcItem.pszText = _T("����");
	m_tabOrder.InsertItem( 2, &tcItem );
	tcItem.pszText = _T("���");
	m_tabOrder.InsertItem( 3, &tcItem );

	HRESULT hr;
	CString Str;

	::CoInitialize(NULL);


	m_edtCode.SetWindowText(_T(""));
	m_edtOrderNo.SetWindowText(_T("0"));
	m_cmbOrderGubun.AddString(_T("1 ������"));
	m_cmbOrderGubun.AddString(_T("2 ������(IOC)"));
	m_cmbOrderGubun.AddString(_T("3 ������(FOK)"));
	m_cmbOrderGubun.SetCurSel(0);
	m_edtAmount.SetWindowText(_T("0"));
	m_edtPrice.SetWindowText(_T("0"));

	//�߰�
	hr = m_pRequestData.CreateInstance(CLSID_YFRequestData);
	m_pRequestEvent = new CYFRequestEvent(this);
	hr = m_pRequestEvent->DispEventAdvise(m_pRequestData);

	m_pRequestData->ComInit();


	hr = m_pRealData.CreateInstance(CLSID_YFReal);
	m_pRealEvent = new CYFRealEvent(this);
	hr = m_pRealEvent->DispEventAdvise(m_pRealData);


	hr = m_pOrder.CreateInstance(CLSID_YFOrder);
	m_pOrderEvent = new CYFOrderEvent(this);
	hr = m_pOrderEvent->DispEventAdvise(m_pOrder);


	hr = m_pValueListData.CreateInstance(CLSID_YFValueList);
	m_pValueListEvent = new CYFValueListEvent(this);
	hr = m_pValueListEvent->DispEventAdvise(m_pValueListData);

	hr = m_pValueData.CreateInstance(CLSID_YFValues);


	InitAccount(); // ����
    ////////////////////////////////////////////////////////////////////////////////////


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CELWOrderDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CELWOrderDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CELWOrderDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CELWOrderDlg::InitAccount()
{
	HRESULT hr;
	CString Str;
	int n = m_pRequestData->AccountCount();
	


	for (int i = 0; i < n; i++)
	{
		Str = (LPCTSTR)(_bstr_t)m_pRequestData->AccountItem(i);
		m_cmbAccountNo.AddString(Str);
	}

	if (m_cmbAccountNo.GetCount() > 0)
		m_cmbAccountNo.SetCurSel(0);

}


void CELWOrderDlg::Request_ReceiveData(BSTR TrCode, BSTR Value, BSTR ValueList, long NextFlag, long SelectCount, BSTR MsgCode, BSTR MsgName) //��ȸ������ ���� ���Ž� �߻�
{
	CString tmp(TrCode);
	//ELW ���簡
	//if (tmp == "TQ3001")
	//���� ���簡
	if (tmp == "TQ1001")
	{
		CString Str = "";
		CString sData = "";


		sData = Value;
		m_edtCurData.SetWindowText(sData);
	
		//���ŵ� �����͸� �Ľ��ؼ� ����ϱ����� ó����ƾ
		//m_pValueData->SetValueData(m_pRequestData->GetKorValueHeader("TQ3001"),  Value);
		m_pValueData->SetValueData(m_pRequestData->GetKorValueHeader("TQ1001"),  Value);
		for (int i = 0; i < m_pValueData->GetColCount(); i++)
		{
			Str += (LPCTSTR)(_bstr_t) m_pValueData->GetName(i);
			Str += "=";
			Str += (LPCTSTR)(_bstr_t) m_pValueData->GetValue(i);
			Str += "\r\n";
		}
		m_edtCurData1.SetWindowText(Str);

	}
	//����,ETF, ELW ��ü���ֹ�������
	if (tmp == "TA1006")
	{
		CString sDataList = "";
		long nCol = 0;
		long nRow = 0;


		sDataList = ValueList;
		m_edtUnexec2.SetWindowTextA(sDataList);
	

		//���ŵ� �����͸� �Ľ��ؼ� ����ϱ����� ó����ƾ
		m_pValueListData->SetListData(m_pRequestData->GetKorValueHeader("TA1006"), ValueList, SelectCount-1); 


	}

}

void CELWOrderDlg::Request_Status(long Status, BSTR TrCode, BSTR MsgCode, BSTR MsgName) //��ȸ������ �ۼ��� ������ �߻�
{

}
	
void CELWOrderDlg::Order_ReceiveData(BSTR TrCode, BSTR Value, BSTR MsgCode, BSTR MsgName) //�ֹ������� ���� ���Ž� �߻�
{

}

void CELWOrderDlg::Order_Status(long Status, BSTR TrCode, BSTR MsgCode, BSTR MsgName) //�ֹ������� �ۼ��� ������ �߻�
{
	CString sMsg;
	sMsg = MsgName;
	AfxMessageBox(sMsg);
}

void CELWOrderDlg::Real_ReceiveData(BSTR TrCode, BSTR Value, BSTR MsgCode, BSTR MsgName) //�ǽð������� ���� ���Ž� �߻� 
{
	CString tmp(TrCode);
	CString sdata(Value);
	CString smsg(MsgName);
	CString sdatalist;
	m_edtRealData.GetWindowText(sdatalist);
	sdatalist += tmp;
	sdatalist += "=";
	sdatalist += sdata;
	sdatalist +=  "\r\n";

	
	//m_edtRealData.SetWindowTextA(smsg);
	m_edtRealData.SetWindowTextA(sdatalist);

}
void CELWOrderDlg::Real_Status(long Status, BSTR TrCode, BSTR MsgCode, BSTR MsgName) //�ǽð� ������ �ۼ��� ������ �߻�
{

}

//���ŵ� �������� ����Ʈ�� ������ ó��
void CELWOrderDlg::ValueList_Update(long RecNo) 
{


}


void CELWOrderDlg::OrderTab_ControlEnable(int Index)
{
	switch(Index)
	{
	case 0:
		m_edtCode.EnableWindow(TRUE);
		m_edtOrderNo.EnableWindow(FALSE);
		m_cmbOrderGubun.EnableWindow(TRUE);
		m_edtAmount.EnableWindow(TRUE);
		m_edtPrice.EnableWindow(TRUE);
		break;
	case 1:
		m_edtCode.EnableWindow(TRUE);
		m_edtOrderNo.EnableWindow(FALSE);
		m_cmbOrderGubun.EnableWindow(TRUE);
		m_edtAmount.EnableWindow(TRUE);
		m_edtPrice.EnableWindow(TRUE);
		break;
	case 2:
		m_edtCode.EnableWindow(TRUE);
		m_edtOrderNo.EnableWindow(TRUE);
		m_cmbOrderGubun.EnableWindow(TRUE);
		m_edtAmount.EnableWindow(TRUE);
		m_edtPrice.EnableWindow(TRUE);
		break;
	case 3:
		m_edtCode.EnableWindow(TRUE);
		m_edtOrderNo.EnableWindow(TRUE);
		m_cmbOrderGubun.EnableWindow(FALSE);
		m_edtAmount.EnableWindow(TRUE);
		m_edtPrice.EnableWindow(FALSE);
		break;
	}
}

void CELWOrderDlg::ElwOrder_Sell()
{
    CString sAccount, sPasswd, sCode, sPrice, sAmount, sType;
	CString sTemp;
    
	m_cmbAccountNo.GetLBText(m_cmbAccountNo.GetCurSel(), sAccount);	// ���¹�ȣ
	m_edtPasswd.GetWindowText(sPasswd);								// ��й�ȣ
	m_edtCode.GetWindowText(sCode);									// �����ڵ�
	m_cmbOrderGubun.GetLBText(m_cmbOrderGubun.GetCurSel(), sTemp);	// �ֹ�����
	sType = sTemp.Mid(0,1);										
	m_edtAmount.GetWindowText(sAmount);								// �ֹ�����
	m_edtPrice.GetWindowText(sPrice);								// �ֹ�����

	m_pOrder->RequestInit();
	m_pOrder->SetData("Account",(_variant_t)sAccount);
	m_pOrder->SetData("Password",(_variant_t)sPasswd);
	m_pOrder->SetData("Code",(_variant_t)sCode);
	m_pOrder->SetData("OrderQty",(_variant_t)sAmount);
	m_pOrder->SetData("OrderPr",(_variant_t)sPrice);
	m_pOrder->SetData("OrderType",(_variant_t)sType);

	//m_pOrder->RequestData("TO3201"); //ELW �ŵ��ֹ�
	m_pOrder->RequestData("TO1101"); //���� �ŵ��ֹ�
    

}
void CELWOrderDlg::ElwOrder_Buy()
{
    CString sAccount, sPasswd, sCode, sPrice, sAmount, sType;
	CString sTemp;
    
	m_cmbAccountNo.GetLBText(m_cmbAccountNo.GetCurSel(), sAccount);	// ���¹�ȣ
	m_edtPasswd.GetWindowText(sPasswd);								// ��й�ȣ
	m_edtCode.GetWindowText(sCode);									// �����ڵ�
	m_cmbOrderGubun.GetLBText(m_cmbOrderGubun.GetCurSel(), sTemp);	// �ֹ�����
	sType = sTemp.Mid(0,1);										
	m_edtAmount.GetWindowText(sAmount);								// �ֹ�����
	m_edtPrice.GetWindowText(sPrice);								// �ֹ�����
    
	m_pOrder->RequestInit();
	m_pOrder->SetData("Account",(_variant_t)sAccount);
	m_pOrder->SetData("Password",(_variant_t)sPasswd);
	m_pOrder->SetData("Code",(_variant_t)sCode);
	m_pOrder->SetData("OrderQty",(_variant_t)sAmount);
	m_pOrder->SetData("OrderPr",(_variant_t)sPrice);
	m_pOrder->SetData("OrderType",(_variant_t)sType);

	//m_pOrder->RequestData("TO3202"); //ELW �ż��ֹ�
	m_pOrder->RequestData("TO1102"); //���� �ż��ֹ�

}
void CELWOrderDlg::ElwOrder_Modify()
{
    CString sAccount, sPasswd, sCode, sOrderNo, sPrice, sAmount, sType, sAll;
	CString sTemp;
    
	m_cmbAccountNo.GetLBText(m_cmbAccountNo.GetCurSel(), sAccount);	// ���¹�ȣ
	m_edtPasswd.GetWindowText(sPasswd);								// ��й�ȣ
	m_edtCode.GetWindowText(sCode);									// �����ڵ�
	m_edtOrderNo.GetWindowText(sOrderNo);							// �ֹ���ȣ
	m_cmbOrderGubun.GetLBText(m_cmbOrderGubun.GetCurSel(), sTemp);		// �ֹ�����
	sType = sTemp.Mid(0,1);										
	m_edtAmount.GetWindowText(sAmount);								// �ֹ�����
	m_edtPrice.GetWindowText(sPrice);								// �ֹ�����
	sAll = "1";														// ���� 1-���� 2-�Ϻ�
    
	m_pOrder->RequestInit();
	m_pOrder->SetData("Account",(_variant_t)sAccount);
	m_pOrder->SetData("Password",(_variant_t)sPasswd);
	m_pOrder->SetData("Code",(_variant_t)sCode);
	m_pOrder->SetData("OrderQty",(_variant_t)sAmount);
	m_pOrder->SetData("OrderPr",(_variant_t)sPrice);
	m_pOrder->SetData("OrderType",(_variant_t)sType);
	m_pOrder->SetData("AllPartCls",(_variant_t)sAll);
	m_pOrder->SetData("OrgOrderNo",(_variant_t)sOrderNo);

	//m_pOrder->RequestData("TO3203"); //ELW �����ֹ�
	m_pOrder->RequestData("TO1103"); //���� �����ֹ�
}
void CELWOrderDlg::ElwOrder_Cancel()
{
    CString sAccount, sPasswd, sCode, sOrderNo, sPrice, sAmount, sType, sAll;
	CString sTemp;
    
	m_cmbAccountNo.GetLBText(m_cmbAccountNo.GetCurSel(), sAccount);	// ���¹�ȣ
	m_edtPasswd.GetWindowText(sPasswd);								// ��й�ȣ
	m_edtCode.GetWindowText(sCode);									// �����ڵ�
	m_edtOrderNo.GetWindowText(sOrderNo);							// �ֹ���ȣ
	m_cmbOrderGubun.GetLBText(m_cmbOrderGubun.GetCurSel(), sTemp);		// �ֹ�����
	sType = sTemp.Mid(0,1);										
	m_edtAmount.GetWindowText(sAmount);								// �ֹ�����
	m_edtPrice.GetWindowText(sPrice);								// �ֹ�����
	sAll = "1";														// ���� 1-���� 2-�Ϻ�
    
	m_pOrder->RequestInit();
	m_pOrder->SetData("Account",(_variant_t)sAccount);
	m_pOrder->SetData("Password",(_variant_t)sPasswd);
	m_pOrder->SetData("Code",(_variant_t)sCode);
	m_pOrder->SetData("OrderQty",(_variant_t)sAmount);
	m_pOrder->SetData("OrderPr",(_variant_t)sPrice);
	m_pOrder->SetData("OrderType",(_variant_t)sType);
	m_pOrder->SetData("AllPartCls",(_variant_t)sAll);
	m_pOrder->SetData("OrgOrderNo",(_variant_t)sOrderNo);

	//m_pOrder->RequestData("TO3204"); //ELW ����ֹ�
	m_pOrder->RequestData("TO1104"); //���� ����ֹ�(�̴Ͽ���)
}

void CELWOrderDlg::OnSelchangeTabOrder(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i = m_tabOrder.GetCurSel();
	OrderTab_ControlEnable(i);
	
	*pResult = 0;
}

void CELWOrderDlg::OnOrderbtn() 
{
	// TODO: Add your control notification handler code here
	int i = m_tabOrder.GetCurSel();
	switch(i)
	{
	case 0:
		ElwOrder_Sell();
		break;
	case 1:
		ElwOrder_Buy();
		break;
	case 2:
		ElwOrder_Modify();
		break;
	case 3:
		ElwOrder_Cancel();
		break;
	}
	
}

void CELWOrderDlg::OnBtnCode() 
{
	// TODO: Add your control notification handler code here
	
}



void CELWOrderDlg::OnBTNELWCur() 
{
	// TODO: Add your control notification handler code here
	CString Str, sTemp;

	m_edtCode.GetWindowText(Str);

	m_pRequestData->RequestInit(); //�ʱ�ȭ�Լ�
	m_pRequestData->SetData("Code",(_variant_t) Str); //��ȸ�� �����ڵ� �Է�
	//m_pRequestData->RequestData("TQ3001",0); //��ȸ�� TR�ڵ� �Է� ELW�ü���ȸ
	m_pRequestData->RequestData("TQ1001",0); //��ȸ�� TR�ڵ� �Է� �����ü���ȸ

	//���ŵ����� ó���� �̺�Ʈ���� �Ͻø� �˴ϴ�.
}

BEGIN_EVENTSINK_MAP(CELWOrderDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CELWOrderDlg)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()


BOOL CELWOrderDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class

	if (NULL != m_pRequestData)
	{
		m_pRequestEvent->DispEventUnadvise(m_pRequestData);
		delete m_pRequestEvent;

		m_pRequestData.Release();
	}

	if (NULL != m_pRealData)
	{
		m_pRealEvent->DispEventUnadvise(m_pRealData);
		delete m_pRealEvent;

		m_pRealData.Release();
	}

	if (NULL != m_pOrder)
	{
		m_pOrderEvent->DispEventUnadvise(m_pOrder);
		delete m_pOrderEvent;

		m_pOrder.Release();
	}

	if (NULL != m_pValueListData)
	{
		m_pValueListEvent->DispEventUnadvise(m_pValueListData);
		delete m_pValueListEvent;

		m_pValueListData.Release();
	}

	if (NULL != m_pValueData)
	{
		m_pValueData.Release();
	}

	return CDialog::DestroyWindow();
}

//��ü�ᵥ������ȸ
void CELWOrderDlg::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    CString sAccount, sPasswd, sCode, sPrice, sAmount, sType, sDate;
	CString sTemp;


	long nSel = m_cmbAccountNo.GetCurSel();

	if (nSel < 0)
		return;

	m_cmbAccountNo.GetLBText(nSel, sAccount);	// ���¹�ȣ
	m_edtPasswd.GetWindowText(sPasswd);								// ��й�ȣ
	m_edtCode.GetWindowText(sCode);									// �����ڵ�

	CTime tm = CTime::GetCurrentTime();
	sDate.Format("%04d%02d%02d", tm.GetYear(), tm.GetMonth(), tm.GetDay());

	m_pRequestData->RequestInit(); //�ʱ�ȭ�Լ�

	//��ȸ ���� �Է� 
	m_pRequestData->SetData("SecCode","3");						//�����ڵ� : 1 �ֹ�/ü�� 2 ü�� 3 ��ü��
	m_pRequestData->SetData("QrySec","9");						//��ȸ�����ڵ� : 1 �ֽ� 2 ä�� 5 ELW 9 ��ü 
	m_pRequestData->SetData("Account",(_variant_t) sAccount);	//���¹�ȣ
	m_pRequestData->SetData("Password",(_variant_t) sPasswd);	//��й�ȣ
	m_pRequestData->SetData("OrderDate",(_variant_t) sDate);	//�ֹ�����
	m_pRequestData->SetData("Code",(_variant_t) sCode);		//�����ڵ�
	
	m_pRequestData->RequestData("TA1006",0); //��ȸ�� TR�ڵ� �Է� 

	//���ŵ����� ó���� �̺�Ʈ���� �Ͻø� �˴ϴ�.
}

//ELW ���� �ü� �ǽð������͸� �ޱ����� �����ڵ� ���
void CELWOrderDlg::OnBnClickedBtnCodereg()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString sCode;


	m_edtCode.GetWindowText(sCode);									// �����ڵ�

	//m_pRealData->AddRealCode((_variant_t) sCode,"RQ3101");	//ELW ü�Ḯ��
	//m_pRealData->AddRealCode((_variant_t) sCode,"RQ3102");	//ELW ȣ������
	
	//m_pRealData->AddRealCode((_variant_t) sCode,"RQ1101");	//���� ü�Ḯ��
	m_pRealData->AddRealCode((_variant_t) sCode,"RQ1102");	//���� ȣ������

}

//�ֹ� �ǽð� �����͸� �ޱ����� ���� ���
void CELWOrderDlg::OnBnClickedBtnAccountreg()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    CString sAccount;


	long nSel = m_cmbAccountNo.GetCurSel();

	if (nSel < 0)
		return;

	m_cmbAccountNo.GetLBText(nSel, sAccount);	// ���¹�ȣ
	//m_pRealData->AddAccount((_variant_t) sAccount,"RA3002");	//ELW �ֹ������� ��ü��
	m_pRealData->AddAccount((_variant_t) sAccount,"RA1002");    //���� �ֹ�������	��ü��
}
//��� �����ڵ忡���� ��������
void CELWOrderDlg::OnBnClickedBtnCodereg2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_pRealData->AllDeleteCodeReal();
}

void CELWOrderDlg::OnBnClickedBtnAccountreg2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_pRealData->AllDeleteAccountReal();
}

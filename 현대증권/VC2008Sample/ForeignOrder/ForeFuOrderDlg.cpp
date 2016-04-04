// ForeFuOrderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ForeFuOrder.h"
#include "ForeFuOrderDlg.h"

// �߰�
#include "Events.h"
/*
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
*/

//�ؿܼ���

//��ȸ������ó����ü
IYFGRequestPtr m_pGRequestData;
CYFGRequestEvent* m_pGRequestEvent;

//�ǽð������� ���/���� ��ü
IYFGRealPtr m_pGRealData;
CYFGRealEvent* m_pGRealEvent;


//�ֹ�ó����ü
IYFGOrderPtr m_pGOrder;
CYFGOrderEvent* m_pGOrderEvent;


//���ŵ� ������ ó�� ��ü(���ϼ�������--���簡,�ǽð�������)
IYFGValuesPtr m_pGValueData;

//���ŵ� ������ ó�� ��ü(����Ʈ��������--���񸮽�Ʈ ��)
IYFGValueListPtr m_pGValueListData;
CYFGValueListEvent* m_pGValueListEvent;

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
// CForeFuOrderDlg dialog

CForeFuOrderDlg::CForeFuOrderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CForeFuOrderDlg::IDD, pParent)
{
	AfxEnableControlContainer();

	//{{AFX_DATA_INIT(CForeFuOrderDlg)
	m_txtStatus = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	EnableAutomation();
	EnableConnections();


}

void CForeFuOrderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CForeFuOrderDlg)
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
	DDX_Control(pDX, IDC_COMBO1, m_cmbTrdSec);
	DDX_Control(pDX, IDC_EDIT2, m_edtStopPr);
}

BEGIN_MESSAGE_MAP(CForeFuOrderDlg, CDialog)
	//{{AFX_MSG_MAP(CForeFuOrderDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_ORDER, OnSelchangeTabOrder)
	ON_BN_CLICKED(IDC_ORDERBTN, OnOrderbtn)
	ON_BN_CLICKED(IDC_BTN_CODE, OnBtnCode)
	ON_BN_CLICKED(IDC_BTN_ForeFuCur, OnBTNForeFuCur)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CForeFuOrderDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BTN_CODEREG, &CForeFuOrderDlg::OnBnClickedBtnCodereg)
	ON_BN_CLICKED(IDC_BTN_ACCOUNTREG, &CForeFuOrderDlg::OnBnClickedBtnAccountreg)
	ON_BN_CLICKED(IDC_BTN_CODEREG2, &CForeFuOrderDlg::OnBnClickedBtnCodereg2)
	ON_BN_CLICKED(IDC_BTN_ACCOUNTREG2, &CForeFuOrderDlg::OnBnClickedBtnAccountreg2)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CForeFuOrderDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CForeFuOrderDlg message handlers

BOOL CForeFuOrderDlg::OnInitDialog()
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

	//�ֹ������� ���尡 �������� ���÷� ����
	m_edtCode.SetWindowText(_T(""));
	m_edtOrderNo.SetWindowText(_T(""));
	m_cmbOrderGubun.AddString(_T("1 ���尡"));
	m_cmbOrderGubun.AddString(_T("2 ������"));
	//m_cmbOrderGubun.AddString(_T("3 STOP"));
	//m_cmbOrderGubun.AddString(_T("4 STOP LIMIT"));
	m_cmbOrderGubun.SetCurSel(0);
	m_edtAmount.SetWindowText(_T("0"));
	m_edtPrice.SetWindowText(_T(""));
	m_edtStopPr.SetWindowText(_T(""));
	m_cmbTrdSec.AddString(_T("1 �ż�"));
	m_cmbTrdSec.AddString(_T("2 �ŵ�"));
/*
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
*/
	//�ؿܼ��� �߰�
	hr = m_pGRequestData.CreateInstance(CLSID_YFGRequest);
	m_pGRequestEvent = new CYFGRequestEvent(this);
	hr = m_pGRequestEvent->DispEventAdvise(m_pGRequestData);

	m_pGRequestData->GlobalInit();


	hr = m_pGRealData.CreateInstance(CLSID_YFGReal);
	m_pGRealEvent = new CYFGRealEvent(this);
	hr = m_pGRealEvent->DispEventAdvise(m_pGRealData);


	hr = m_pGOrder.CreateInstance(CLSID_YFGOrder);
	m_pGOrderEvent = new CYFGOrderEvent(this);
	hr = m_pGOrderEvent->DispEventAdvise(m_pGOrder);


	hr = m_pGValueListData.CreateInstance(CLSID_YFGValueList);
	m_pGValueListEvent = new CYFGValueListEvent(this);
	hr = m_pGValueListEvent->DispEventAdvise(m_pGValueListData);

	hr = m_pGValueData.CreateInstance(CLSID_YFGValues);

	InitAccount(); // ����
    ////////////////////////////////////////////////////////////////////////////////////


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CForeFuOrderDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CForeFuOrderDlg::OnPaint() 
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
HCURSOR CForeFuOrderDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CForeFuOrderDlg::InitAccount()
{
	HRESULT hr;
	CString Str;
	int n = m_pGRequestData->AccountCount();
	


	for (int i = 0; i < n; i++)
	{
		Str = (LPCTSTR)(_bstr_t)m_pGRequestData->AccountItem(i);
		m_cmbAccountNo.AddString(Str);
	}

	if (m_cmbAccountNo.GetCount() > 0)
		m_cmbAccountNo.SetCurSel(0);


	/* ��ȯ�����Լ�
	CString sT1, sT2;
	sT1 = "3";
	sT2 = "11111";

	CString sTemp = (LPCTSTR)(_bstr_t)m_pGRequestData->GetGFormatValue((_variant_t)sT1,(_variant_t)sT2);
	*/

}


void CForeFuOrderDlg::Request_ReceiveData(BSTR TrCode, BSTR Value, BSTR ValueList, long NextFlag, long SelectCount, BSTR MsgCode, BSTR MsgName) //��ȸ������ ���� ���Ž� �߻�
{
	CString tmp(TrCode);
	//ForeFu ���簡
	//if (tmp == "TQ3001")
	//���� ���簡
/*	if (tmp == "TQ1001")
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
	//����,ETF, ForeFu ��ü���ֹ�������
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
*/
}

void CForeFuOrderDlg::Request_Status(long Status, BSTR TrCode, BSTR MsgCode, BSTR MsgName) //��ȸ������ �ۼ��� ������ �߻�
{

}
	
void CForeFuOrderDlg::Order_ReceiveData(BSTR TrCode, BSTR Value, BSTR MsgCode, BSTR MsgName) //�ֹ������� ���� ���Ž� �߻�
{

}

void CForeFuOrderDlg::Order_Status(long Status, BSTR TrCode, BSTR MsgCode, BSTR MsgName) //�ֹ������� �ۼ��� ������ �߻�
{
	CString sMsg;
	sMsg = MsgName;
	AfxMessageBox(sMsg);
}

void CForeFuOrderDlg::Real_ReceiveData(BSTR TrCode, BSTR Value, BSTR MsgCode, BSTR MsgName) //�ǽð������� ���� ���Ž� �߻� 
{
/*	CString tmp(TrCode);
	CString sdata(Value);
	CString smsg(MsgName);
	m_edtRealData.SetWindowTextA(smsg);
	m_edtRealData.SetWindowTextA(sdata);*/

}
void CForeFuOrderDlg::Real_Status(long Status, BSTR TrCode, BSTR MsgCode, BSTR MsgName) //�ǽð� ������ �ۼ��� ������ �߻�
{

}

//���ŵ� �������� ����Ʈ�� ������ ó��
void CForeFuOrderDlg::ValueList_Update(long RecNo) 
{


}

//�ؿܼ���

void CForeFuOrderDlg::GRequest_ReceiveData(BSTR TrCode, BSTR Value, BSTR ValueList, long NextFlag, long SelectCount, BSTR MsgCode, BSTR MsgName) //��ȸ������ ���� ���Ž� �߻�
{
	CString tmp(TrCode);
	//ForeFu ���簡
	//if (tmp == "TQ3001")
	//���� ���簡
	if (tmp == "GQ9001")
	{
		CString Str = "";
		CString sData = "";


		sData = Value;
		m_edtCurData.SetWindowText(sData);
	
		//���ŵ� �����͸� �Ľ��ؼ� ����ϱ����� ó����ƾ
		//m_pValueData->SetValueData(m_pRequestData->GetKorValueHeader("TQ3001"),  Value);
		m_pGValueData->SetValueData(m_pGRequestData->GetKorValueHeader("GQ9001"),  Value);
		for (int i = 0; i < m_pGValueData->GetColCount(); i++)
		{
			Str += (LPCTSTR)(_bstr_t) m_pGValueData->GetName(i);
			Str += "=";
			Str += (LPCTSTR)(_bstr_t) m_pGValueData->GetValue(i);
			Str += "\r\n";
		}
		m_edtCurData1.SetWindowText(Str);

	}
	//����,ETF, ForeFu ��ü���ֹ�������
	if (tmp == "GA9005")
	{
		CString sDataList("");
		m_edtUnexec2.SetWindowTextA(sDataList);
		long nCol = 0;
		long nRow = 0;


		sDataList = ValueList;
		m_edtUnexec2.SetWindowTextA(sDataList);
	

		//���ŵ� �����͸� �Ľ��ؼ� ����ϱ����� ó����ƾ
		m_pGValueListData->SetListData(m_pGRequestData->GetKorValueHeader("GA9005"), ValueList, SelectCount-1); 


	}

}

void CForeFuOrderDlg::GRequest_Status(long Status, BSTR TrCode, BSTR MsgCode, BSTR MsgName) //��ȸ������ �ۼ��� ������ �߻�
{

}
	
void CForeFuOrderDlg::GOrder_ReceiveData(BSTR TrCode, BSTR Value, BSTR MsgCode, BSTR MsgName) //�ֹ������� ���� ���Ž� �߻�
{
	CString sMsg;
	sMsg = MsgName;
	AfxMessageBox(sMsg);
}

void CForeFuOrderDlg::GOrder_Status(long Status, BSTR TrCode, BSTR MsgCode, BSTR MsgName) //�ֹ������� �ۼ��� ������ �߻�
{
	CString sMsg;
	sMsg = MsgName;
	AfxMessageBox(sMsg);
}

void CForeFuOrderDlg::GReal_ReceiveData(BSTR TrCode, BSTR Value, BSTR MsgCode, BSTR MsgName) //�ǽð������� ���� ���Ž� �߻� 
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
void CForeFuOrderDlg::GReal_Status(long Status, BSTR TrCode, BSTR MsgCode, BSTR MsgName) //�ǽð� ������ �ۼ��� ������ �߻�
{

}

//���ŵ� �������� ����Ʈ�� ������ ó��
void CForeFuOrderDlg::GValueList_Update(long RecNo) 
{


}


void CForeFuOrderDlg::OrderTab_ControlEnable(int Index)
{
	switch(Index)
	{
	case 0:
		m_edtCode.EnableWindow(TRUE);
		m_edtOrderNo.EnableWindow(FALSE);
		m_cmbOrderGubun.EnableWindow(TRUE);
		m_edtAmount.EnableWindow(TRUE);
		m_edtPrice.EnableWindow(TRUE);
		m_cmbTrdSec.EnableWindow(FALSE);
		break;
	case 1:
		m_edtCode.EnableWindow(TRUE);
		m_edtOrderNo.EnableWindow(FALSE);
		m_cmbOrderGubun.EnableWindow(TRUE);
		m_edtAmount.EnableWindow(TRUE);
		m_edtPrice.EnableWindow(TRUE);
		m_cmbTrdSec.EnableWindow(FALSE);
		break;
	case 2:
		m_edtCode.EnableWindow(TRUE);
		m_edtOrderNo.EnableWindow(TRUE);
		m_cmbOrderGubun.EnableWindow(TRUE);
		m_edtAmount.EnableWindow(TRUE);
		m_edtPrice.EnableWindow(TRUE);
		m_cmbTrdSec.EnableWindow(TRUE);
		break;
	case 3:
		m_edtCode.EnableWindow(TRUE);
		m_edtOrderNo.EnableWindow(TRUE);
		m_cmbOrderGubun.EnableWindow(TRUE);
		m_edtAmount.EnableWindow(TRUE);
		m_edtPrice.EnableWindow(TRUE);
		m_cmbTrdSec.EnableWindow(TRUE);
		break;
	}
}

void CForeFuOrderDlg::ForeFuOrder_Sell()
{
    CString sAccount, sPasswd, sCode, sPrice, sAmount, sType, sTrdSec, sStopPr;
	CString sTemp;
    
	m_cmbAccountNo.GetLBText(m_cmbAccountNo.GetCurSel(), sAccount);	// ���¹�ȣ
	m_edtPasswd.GetWindowText(sPasswd);								// ��й�ȣ
	m_edtCode.GetWindowText(sCode);									// �����ڵ�
	m_cmbOrderGubun.GetLBText(m_cmbOrderGubun.GetCurSel(), sTemp);	// �ֹ�����
	sType = sTemp.Mid(0,1);										
	m_edtAmount.GetWindowText(sAmount);								// �ֹ�����
	m_edtPrice.GetWindowText(sPrice);								// �ֹ�����
	sTrdSec = "2";													// 1 �ż� 2 �ŵ�
	sStopPr = "";													// ���ǰ���

	m_pGOrder->RequestInit();
	m_pGOrder->SetData("Account",(_variant_t)sAccount);
	m_pGOrder->SetData("Password",(_variant_t)sPasswd);
	m_pGOrder->SetData("Code",(_variant_t)sCode);
	m_pGOrder->SetData("TrdSection",(_variant_t)sTrdSec);
	m_pGOrder->SetData("TrdType",(_variant_t)sType);
	m_pGOrder->SetData("OrderQty",(_variant_t)sAmount);
	m_pGOrder->SetData("OrderPr",(_variant_t)sPrice);
	m_pGOrder->SetData("OrderStopPr",(_variant_t)sStopPr);

	
	m_pGOrder->RequestData("TG1001"); //�ؿܼ��� �ŵ��ֹ�
    

}
void CForeFuOrderDlg::ForeFuOrder_Buy()
{
    CString sAccount, sPasswd, sCode, sPrice, sAmount, sType, sTrdSec, sStopPr;
	CString sTemp;
    
	m_cmbAccountNo.GetLBText(m_cmbAccountNo.GetCurSel(), sAccount);	// ���¹�ȣ
	m_edtPasswd.GetWindowText(sPasswd);								// ��й�ȣ
	m_edtCode.GetWindowText(sCode);									// �����ڵ�
	m_cmbOrderGubun.GetLBText(m_cmbOrderGubun.GetCurSel(), sTemp);	// �ֹ�����
	sType = sTemp.Mid(0,1);										
	m_edtAmount.GetWindowText(sAmount);								// �ֹ�����
	m_edtPrice.GetWindowText(sPrice);								// �ֹ�����
    
	m_pGOrder->RequestInit();
	sTrdSec = "1";													// 1 �ż� 2 �ŵ�
	sStopPr = "";													// ���ǰ���

	m_pGOrder->RequestInit();
	m_pGOrder->SetData("Account",(_variant_t)sAccount);
	m_pGOrder->SetData("Password",(_variant_t)sPasswd);
	m_pGOrder->SetData("Code",(_variant_t)sCode);
	m_pGOrder->SetData("TrdSection",(_variant_t)sTrdSec);
	m_pGOrder->SetData("TrdType",(_variant_t)sType);
	m_pGOrder->SetData("OrderQty",(_variant_t)sAmount);
	m_pGOrder->SetData("OrderPr",(_variant_t)sPrice);
	m_pGOrder->SetData("OrderStopPr",(_variant_t)sStopPr);

	m_pGOrder->RequestData("TG1001"); //�ؿܼ��� �ż��ֹ�

}
void CForeFuOrderDlg::ForeFuOrder_Modify()
{
    CString sAccount, sPasswd, sCode, sOrderNo, sPrice, sAmount, sType, sCls, sTrdSec, sStopPr;
	CString sTemp;
    
	m_cmbAccountNo.GetLBText(m_cmbAccountNo.GetCurSel(), sAccount);	// ���¹�ȣ
	m_edtPasswd.GetWindowText(sPasswd);								// ��й�ȣ
	m_edtCode.GetWindowText(sCode);									// �����ڵ�
	m_edtOrderNo.GetWindowText(sOrderNo);							// �ֹ���ȣ
	m_cmbOrderGubun.GetLBText(m_cmbOrderGubun.GetCurSel(), sTemp);		// �ֹ�����
	sType = sTemp.Mid(0,1);										
	m_edtAmount.GetWindowText(sAmount);								// �ֹ�����
	m_edtPrice.GetWindowText(sPrice);								// �ֹ�����
	m_cmbTrdSec.GetLBText(m_cmbTrdSec.GetCurSel(), sTemp);	        // �ŵ��ż�����
	sTrdSec = sTemp.Mid(0,1);										
	sCls = "20";													// ������ұ��� 20 ���� 30 ���
	sStopPr = "";													// ���ǰ���
    
	m_pGOrder->RequestInit();
	m_pGOrder->SetData("Account",(_variant_t)sAccount);
	m_pGOrder->SetData("Password",(_variant_t)sPasswd);
	m_pGOrder->SetData("ChangeCancel",(_variant_t)sCls);
	m_pGOrder->SetData("OrgOrderNo",(_variant_t)sOrderNo);
	m_pGOrder->SetData("Code",(_variant_t)sCode);
	m_pGOrder->SetData("TrdSection",(_variant_t)sTrdSec);
	m_pGOrder->SetData("TrdType",(_variant_t)sType);
	m_pGOrder->SetData("OrderQty",(_variant_t)sAmount);
	m_pGOrder->SetData("OrderPr",(_variant_t)sPrice);
	m_pGOrder->SetData("OrderStopPr",(_variant_t)sStopPr);

	m_pGOrder->RequestData("TG1002"); //�ؿܼ��� �����ֹ�
}
void CForeFuOrderDlg::ForeFuOrder_Cancel()
{
    CString sAccount, sPasswd, sCode, sOrderNo, sPrice, sAmount, sType, sCls, sTrdSec, sStopPr;
	CString sTemp;
    
	m_cmbAccountNo.GetLBText(m_cmbAccountNo.GetCurSel(), sAccount);	// ���¹�ȣ
	m_edtPasswd.GetWindowText(sPasswd);								// ��й�ȣ
	m_edtCode.GetWindowText(sCode);									// �����ڵ�
	m_edtOrderNo.GetWindowText(sOrderNo);							// �ֹ���ȣ
	m_cmbOrderGubun.GetLBText(m_cmbOrderGubun.GetCurSel(), sTemp);	// �ֹ�����
	sType = sTemp.Mid(0,1);										
	m_edtAmount.GetWindowText(sAmount);								// �ֹ�����
	m_edtPrice.GetWindowText(sPrice);								// �ֹ�����
	m_cmbTrdSec.GetLBText(m_cmbTrdSec.GetCurSel(), sTemp);	        // �ŵ��ż�����
	sTrdSec = sTemp.Mid(0,1);										
	sCls = "30";													// ������ұ��� 20 ���� 30 ���
	sStopPr = "";													// ���ǰ���
    
	m_pGOrder->RequestInit();
	m_pGOrder->SetData("Account",(_variant_t)sAccount);
	m_pGOrder->SetData("Password",(_variant_t)sPasswd);
	m_pGOrder->SetData("ChangeCancel",(_variant_t)sCls);
	m_pGOrder->SetData("OrgOrderNo",(_variant_t)sOrderNo);
	m_pGOrder->SetData("Code",(_variant_t)sCode);
	m_pGOrder->SetData("TrdSection",(_variant_t)sTrdSec);
	m_pGOrder->SetData("TrdType",(_variant_t)sType);
	m_pGOrder->SetData("OrderQty",(_variant_t)sAmount);
	m_pGOrder->SetData("OrderPr",(_variant_t)sPrice);
	m_pGOrder->SetData("OrderStopPr",(_variant_t)sStopPr);

	m_pGOrder->RequestData("TG1002"); //�ؿܼ��� ����ֹ�
}

void CForeFuOrderDlg::OnSelchangeTabOrder(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int i = m_tabOrder.GetCurSel();
	OrderTab_ControlEnable(i);
	
	*pResult = 0;
}

void CForeFuOrderDlg::OnOrderbtn() 
{
	// TODO: Add your control notification handler code here
	int i = m_tabOrder.GetCurSel();
	switch(i)
	{
	case 0:
		ForeFuOrder_Sell();
		break;
	case 1:
		ForeFuOrder_Buy();
		break;
	case 2:
		ForeFuOrder_Modify();
		break;
	case 3:
		ForeFuOrder_Cancel();
		break;
	}
	
}

void CForeFuOrderDlg::OnBtnCode() 
{
	// TODO: Add your control notification handler code here
	
}



void CForeFuOrderDlg::OnBTNForeFuCur() 
{
	// TODO: Add your control notification handler code here
	CString Str, sTemp;

	m_edtCode.GetWindowText(Str);

	m_pGRequestData->RequestInit(); //�ʱ�ȭ�Լ�
	m_pGRequestData->SetData("Code",(_variant_t) Str); //��ȸ�� �����ڵ� �Է�
	//m_pRequestData->RequestData("TQ3001",0); //��ȸ�� TR�ڵ� �Է� ForeFu�ü���ȸ
	m_pGRequestData->RequestData("GQ9001",0); //��ȸ�� TR�ڵ� �Է� �����ü���ȸ

	//���ŵ����� ó���� �̺�Ʈ���� �Ͻø� �˴ϴ�.
}

BEGIN_EVENTSINK_MAP(CForeFuOrderDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CForeFuOrderDlg)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()


BOOL CForeFuOrderDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class

	if (NULL != m_pGRequestData)
	{
		m_pGRequestEvent->DispEventUnadvise(m_pGRequestData);
		delete m_pGRequestEvent;

		m_pGRequestData.Release();
	}

	if (NULL != m_pGRealData)
	{
		m_pGRealEvent->DispEventUnadvise(m_pGRealData);
		delete m_pGRealEvent;

		m_pGRealData.Release();
	}

	if (NULL != m_pGOrder)
	{
		m_pGOrderEvent->DispEventUnadvise(m_pGOrder);
		delete m_pGOrderEvent;

		m_pGOrder.Release();
	}

	if (NULL != m_pGValueListData)
	{
		m_pGValueListEvent->DispEventUnadvise(m_pGValueListData);
		delete m_pGValueListEvent;

		m_pGValueListData.Release();
	}

	if (NULL != m_pGValueData)
	{
		m_pGValueData.Release();
	}

	return CDialog::DestroyWindow();
}

//��ü�ᵥ������ȸ
void CForeFuOrderDlg::OnBnClickedButton1()
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

	m_pGRequestData->RequestInit(); //�ʱ�ȭ�Լ�

	//��ȸ ���� �Է� 
	//m_pGRequestData->SetData("SecCode","3");						//�����ڵ� : 1 �ֹ�/ü�� 2 ü�� 3 ��ü��
	//m_pGRequestData->SetData("QrySec","9");						//��ȸ�����ڵ� : 1 �ֽ� 2 ä�� 5 ForeFu 9 ��ü 
	m_pGRequestData->SetData("Account",(_variant_t) sAccount);	//���¹�ȣ
	m_pGRequestData->SetData("Password",(_variant_t) sPasswd);	//��й�ȣ
	//m_pGRequestData->SetData("OrderDate",(_variant_t) sDate);	//�ֹ�����
	//m_pGRequestData->SetData("Code",(_variant_t) sCode);		//�����ڵ�
	
	m_pGRequestData->RequestData("GA9005",0); //��ȸ�� TR�ڵ� �Է� 

	//���ŵ����� ó���� �̺�Ʈ���� �Ͻø� �˴ϴ�.
}

//ForeFu ���� �ü� �ǽð������͸� �ޱ����� �����ڵ� ���
void CForeFuOrderDlg::OnBnClickedBtnCodereg()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString sCode;


	m_edtCode.GetWindowText(sCode);									// �����ڵ�

	
	m_pGRealData->AddRealCode((_variant_t) sCode,"RG9101");	//�ؿܼ��� ȣ������
	m_pGRealData->AddRealCode((_variant_t) sCode,"RG9102");	//�ؿܼ��� ü�Ḯ��

}

//�ֹ� �ǽð� �����͸� �ޱ����� ���� ���
void CForeFuOrderDlg::OnBnClickedBtnAccountreg()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    CString sAccount;


	long nSel = m_cmbAccountNo.GetCurSel();

	if (nSel < 0)
		return;

	m_cmbAccountNo.GetLBText(nSel, sAccount);	// ���¹�ȣ
	m_pGRealData->AddAccount((_variant_t) sAccount,"RG9103");	//�ؿܼ��� �ֹ�����
	m_pGRealData->AddAccount((_variant_t) sAccount,"RG9104");   //�ؿܼ��� ��ü��
	m_pGRealData->AddAccount((_variant_t) sAccount,"RG9105");	//�ؿܼ��� ü��
	m_pGRealData->AddAccount((_variant_t) sAccount,"RG9106");   //�ؿܼ��� ü���
	m_pGRealData->AddAccount((_variant_t) sAccount,"RG9107");	//�ؿܼ��� �̰�������
}
//��� �����ڵ忡���� ��������
void CForeFuOrderDlg::OnBnClickedBtnCodereg2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_pGRealData->AllDeleteCodeReal();
}

void CForeFuOrderDlg::OnBnClickedBtnAccountreg2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_pGRealData->AllDeleteAccountReal();
}


void CForeFuOrderDlg::OnCbnSelchangeCombo1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

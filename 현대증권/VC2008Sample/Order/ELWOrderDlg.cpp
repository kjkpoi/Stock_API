// ELWOrderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ELWOrder.h"
#include "ELWOrderDlg.h"

// 추가
#include "Events.h"

//조회데이터처리객체
IYFRequestDataPtr m_pRequestData;
CYFRequestEvent* m_pRequestEvent;

//실시간데이터 등록/해제 객체
IYFRealPtr m_pRealData;
CYFRealEvent* m_pRealEvent;


//주문처리객체
IYFOrderPtr m_pOrder;
CYFOrderEvent* m_pOrderEvent;


//수신된 데이터 처리 객체(단일성데이터--현재가,실시간데이터)
IYFValuesPtr m_pValueData;

//수신된 데이터 처리 객체(리스트성데이터--종목리스트 등)
IYFValueListPtr m_pValueListData;
CYFValueListEvent* m_pValueListEvent;

/////////////////////////////////////////////////////////////////////////////
//주문 및 조회 TR를 변경해서 사용하시면 ELW 주문 및 조회도 가능합니다.
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
	tcItem.pszText = _T("매도");
	m_tabOrder.InsertItem( 0, &tcItem );
	tcItem.pszText = _T("매수");
	m_tabOrder.InsertItem( 1, &tcItem );
	tcItem.pszText = _T("정정");
	m_tabOrder.InsertItem( 2, &tcItem );
	tcItem.pszText = _T("취소");
	m_tabOrder.InsertItem( 3, &tcItem );

	HRESULT hr;
	CString Str;

	::CoInitialize(NULL);


	m_edtCode.SetWindowText(_T(""));
	m_edtOrderNo.SetWindowText(_T("0"));
	m_cmbOrderGubun.AddString(_T("1 지정가"));
	m_cmbOrderGubun.AddString(_T("2 지정가(IOC)"));
	m_cmbOrderGubun.AddString(_T("3 지정가(FOK)"));
	m_cmbOrderGubun.SetCurSel(0);
	m_edtAmount.SetWindowText(_T("0"));
	m_edtPrice.SetWindowText(_T("0"));

	//추가
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


	InitAccount(); // 계좌
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


void CELWOrderDlg::Request_ReceiveData(BSTR TrCode, BSTR Value, BSTR ValueList, long NextFlag, long SelectCount, BSTR MsgCode, BSTR MsgName) //조회데이터 정상 수신시 발생
{
	CString tmp(TrCode);
	//ELW 현재가
	//if (tmp == "TQ3001")
	//현물 현재가
	if (tmp == "TQ1001")
	{
		CString Str = "";
		CString sData = "";


		sData = Value;
		m_edtCurData.SetWindowText(sData);
	
		//수신된 데이터를 파싱해서 사용하기위한 처리루틴
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
	//현물,ETF, ELW 미체결주문데이터
	if (tmp == "TA1006")
	{
		CString sDataList = "";
		long nCol = 0;
		long nRow = 0;


		sDataList = ValueList;
		m_edtUnexec2.SetWindowTextA(sDataList);
	

		//수신된 데이터를 파싱해서 사용하기위한 처리루틴
		m_pValueListData->SetListData(m_pRequestData->GetKorValueHeader("TA1006"), ValueList, SelectCount-1); 


	}

}

void CELWOrderDlg::Request_Status(long Status, BSTR TrCode, BSTR MsgCode, BSTR MsgName) //조회데이터 송수신 에러시 발생
{

}
	
void CELWOrderDlg::Order_ReceiveData(BSTR TrCode, BSTR Value, BSTR MsgCode, BSTR MsgName) //주문데이터 정상 수신시 발생
{

}

void CELWOrderDlg::Order_Status(long Status, BSTR TrCode, BSTR MsgCode, BSTR MsgName) //주문데이터 송수신 에러시 발생
{
	CString sMsg;
	sMsg = MsgName;
	AfxMessageBox(sMsg);
}

void CELWOrderDlg::Real_ReceiveData(BSTR TrCode, BSTR Value, BSTR MsgCode, BSTR MsgName) //실시간데이터 정상 수신시 발생 
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
void CELWOrderDlg::Real_Status(long Status, BSTR TrCode, BSTR MsgCode, BSTR MsgName) //실시간 데이터 송수신 에러시 발생
{

}

//수신된 데이터중 리스트성 데이터 처리
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
    
	m_cmbAccountNo.GetLBText(m_cmbAccountNo.GetCurSel(), sAccount);	// 계좌번호
	m_edtPasswd.GetWindowText(sPasswd);								// 비밀번호
	m_edtCode.GetWindowText(sCode);									// 종목코드
	m_cmbOrderGubun.GetLBText(m_cmbOrderGubun.GetCurSel(), sTemp);	// 주문구분
	sType = sTemp.Mid(0,1);										
	m_edtAmount.GetWindowText(sAmount);								// 주문수량
	m_edtPrice.GetWindowText(sPrice);								// 주문가격

	m_pOrder->RequestInit();
	m_pOrder->SetData("Account",(_variant_t)sAccount);
	m_pOrder->SetData("Password",(_variant_t)sPasswd);
	m_pOrder->SetData("Code",(_variant_t)sCode);
	m_pOrder->SetData("OrderQty",(_variant_t)sAmount);
	m_pOrder->SetData("OrderPr",(_variant_t)sPrice);
	m_pOrder->SetData("OrderType",(_variant_t)sType);

	//m_pOrder->RequestData("TO3201"); //ELW 매도주문
	m_pOrder->RequestData("TO1101"); //현물 매도주문
    

}
void CELWOrderDlg::ElwOrder_Buy()
{
    CString sAccount, sPasswd, sCode, sPrice, sAmount, sType;
	CString sTemp;
    
	m_cmbAccountNo.GetLBText(m_cmbAccountNo.GetCurSel(), sAccount);	// 계좌번호
	m_edtPasswd.GetWindowText(sPasswd);								// 비밀번호
	m_edtCode.GetWindowText(sCode);									// 종목코드
	m_cmbOrderGubun.GetLBText(m_cmbOrderGubun.GetCurSel(), sTemp);	// 주문구분
	sType = sTemp.Mid(0,1);										
	m_edtAmount.GetWindowText(sAmount);								// 주문수량
	m_edtPrice.GetWindowText(sPrice);								// 주문가격
    
	m_pOrder->RequestInit();
	m_pOrder->SetData("Account",(_variant_t)sAccount);
	m_pOrder->SetData("Password",(_variant_t)sPasswd);
	m_pOrder->SetData("Code",(_variant_t)sCode);
	m_pOrder->SetData("OrderQty",(_variant_t)sAmount);
	m_pOrder->SetData("OrderPr",(_variant_t)sPrice);
	m_pOrder->SetData("OrderType",(_variant_t)sType);

	//m_pOrder->RequestData("TO3202"); //ELW 매수주문
	m_pOrder->RequestData("TO1102"); //현물 매수주문

}
void CELWOrderDlg::ElwOrder_Modify()
{
    CString sAccount, sPasswd, sCode, sOrderNo, sPrice, sAmount, sType, sAll;
	CString sTemp;
    
	m_cmbAccountNo.GetLBText(m_cmbAccountNo.GetCurSel(), sAccount);	// 계좌번호
	m_edtPasswd.GetWindowText(sPasswd);								// 비밀번호
	m_edtCode.GetWindowText(sCode);									// 종목코드
	m_edtOrderNo.GetWindowText(sOrderNo);							// 주문번호
	m_cmbOrderGubun.GetLBText(m_cmbOrderGubun.GetCurSel(), sTemp);		// 주문구분
	sType = sTemp.Mid(0,1);										
	m_edtAmount.GetWindowText(sAmount);								// 주문수량
	m_edtPrice.GetWindowText(sPrice);								// 주문가격
	sAll = "1";														// 수량 1-전부 2-일부
    
	m_pOrder->RequestInit();
	m_pOrder->SetData("Account",(_variant_t)sAccount);
	m_pOrder->SetData("Password",(_variant_t)sPasswd);
	m_pOrder->SetData("Code",(_variant_t)sCode);
	m_pOrder->SetData("OrderQty",(_variant_t)sAmount);
	m_pOrder->SetData("OrderPr",(_variant_t)sPrice);
	m_pOrder->SetData("OrderType",(_variant_t)sType);
	m_pOrder->SetData("AllPartCls",(_variant_t)sAll);
	m_pOrder->SetData("OrgOrderNo",(_variant_t)sOrderNo);

	//m_pOrder->RequestData("TO3203"); //ELW 정정주문
	m_pOrder->RequestData("TO1103"); //현물 정정주문
}
void CELWOrderDlg::ElwOrder_Cancel()
{
    CString sAccount, sPasswd, sCode, sOrderNo, sPrice, sAmount, sType, sAll;
	CString sTemp;
    
	m_cmbAccountNo.GetLBText(m_cmbAccountNo.GetCurSel(), sAccount);	// 계좌번호
	m_edtPasswd.GetWindowText(sPasswd);								// 비밀번호
	m_edtCode.GetWindowText(sCode);									// 종목코드
	m_edtOrderNo.GetWindowText(sOrderNo);							// 주문번호
	m_cmbOrderGubun.GetLBText(m_cmbOrderGubun.GetCurSel(), sTemp);		// 주문구분
	sType = sTemp.Mid(0,1);										
	m_edtAmount.GetWindowText(sAmount);								// 주문수량
	m_edtPrice.GetWindowText(sPrice);								// 주문가격
	sAll = "1";														// 수량 1-전부 2-일부
    
	m_pOrder->RequestInit();
	m_pOrder->SetData("Account",(_variant_t)sAccount);
	m_pOrder->SetData("Password",(_variant_t)sPasswd);
	m_pOrder->SetData("Code",(_variant_t)sCode);
	m_pOrder->SetData("OrderQty",(_variant_t)sAmount);
	m_pOrder->SetData("OrderPr",(_variant_t)sPrice);
	m_pOrder->SetData("OrderType",(_variant_t)sType);
	m_pOrder->SetData("AllPartCls",(_variant_t)sAll);
	m_pOrder->SetData("OrgOrderNo",(_variant_t)sOrderNo);

	//m_pOrder->RequestData("TO3204"); //ELW 취소주문
	m_pOrder->RequestData("TO1104"); //현물 취소주문(미니원장)
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

	m_pRequestData->RequestInit(); //초기화함수
	m_pRequestData->SetData("Code",(_variant_t) Str); //조회할 종목코드 입력
	//m_pRequestData->RequestData("TQ3001",0); //조회할 TR코드 입력 ELW시세조회
	m_pRequestData->RequestData("TQ1001",0); //조회할 TR코드 입력 현물시세조회

	//수신데이터 처리는 이벤트에서 하시면 됩니다.
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

//미체결데이터조회
void CELWOrderDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    CString sAccount, sPasswd, sCode, sPrice, sAmount, sType, sDate;
	CString sTemp;


	long nSel = m_cmbAccountNo.GetCurSel();

	if (nSel < 0)
		return;

	m_cmbAccountNo.GetLBText(nSel, sAccount);	// 계좌번호
	m_edtPasswd.GetWindowText(sPasswd);								// 비밀번호
	m_edtCode.GetWindowText(sCode);									// 종목코드

	CTime tm = CTime::GetCurrentTime();
	sDate.Format("%04d%02d%02d", tm.GetYear(), tm.GetMonth(), tm.GetDay());

	m_pRequestData->RequestInit(); //초기화함수

	//조회 조건 입력 
	m_pRequestData->SetData("SecCode","3");						//구부코드 : 1 주문/체결 2 체결 3 미체결
	m_pRequestData->SetData("QrySec","9");						//조회구분코드 : 1 주식 2 채권 5 ELW 9 전체 
	m_pRequestData->SetData("Account",(_variant_t) sAccount);	//계좌번호
	m_pRequestData->SetData("Password",(_variant_t) sPasswd);	//비밀번호
	m_pRequestData->SetData("OrderDate",(_variant_t) sDate);	//주문일자
	m_pRequestData->SetData("Code",(_variant_t) sCode);		//종목코드
	
	m_pRequestData->RequestData("TA1006",0); //조회할 TR코드 입력 

	//수신데이터 처리는 이벤트에서 하시면 됩니다.
}

//ELW 종목 시세 실시간데이터를 받기위해 종목코드 등록
void CELWOrderDlg::OnBnClickedBtnCodereg()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString sCode;


	m_edtCode.GetWindowText(sCode);									// 종목코드

	//m_pRealData->AddRealCode((_variant_t) sCode,"RQ3101");	//ELW 체결리얼
	//m_pRealData->AddRealCode((_variant_t) sCode,"RQ3102");	//ELW 호가리얼
	
	//m_pRealData->AddRealCode((_variant_t) sCode,"RQ1101");	//현물 체결리얼
	m_pRealData->AddRealCode((_variant_t) sCode,"RQ1102");	//현물 호가리얼

}

//주문 실시간 데이터를 받기위해 계좌 등록
void CELWOrderDlg::OnBnClickedBtnAccountreg()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    CString sAccount;


	long nSel = m_cmbAccountNo.GetCurSel();

	if (nSel < 0)
		return;

	m_cmbAccountNo.GetLBText(nSel, sAccount);	// 계좌번호
	//m_pRealData->AddAccount((_variant_t) sAccount,"RA3002");	//ELW 주문리얼등록 미체결
	m_pRealData->AddAccount((_variant_t) sAccount,"RA1002");    //현물 주문리얼등록	미체결
}
//모든 종목코드에대한 리얼해지
void CELWOrderDlg::OnBnClickedBtnCodereg2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRealData->AllDeleteCodeReal();
}

void CELWOrderDlg::OnBnClickedBtnAccountreg2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pRealData->AllDeleteAccountReal();
}

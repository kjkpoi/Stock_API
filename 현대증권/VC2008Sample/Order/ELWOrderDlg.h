// ELWOrderDlg.h : header file
//
//{{AFX_INCLUDES()
//}}AFX_INCLUDES
#include "afxwin.h"
#if !defined(AFX_ELWORDERDLG_H__43DE49E8_36E8_4227_9865_F63D18761E95__INCLUDED_)
#define AFX_ELWORDERDLG_H__43DE49E8_36E8_4227_9865_F63D18761E95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


// 추가
//#include "Events.h"
//

/////////////////////////////////////////////////////////////////////////////
// CELWOrderDlg dialog

class CELWOrderDlg : public CDialog
{
// Construction
public:
	CELWOrderDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CELWOrderDlg)
	enum { IDD = IDD_ELWORDER_DIALOG };
	CStatic	m_ctlStatus;
	CEdit	m_edtAmount;
	CEdit	m_edtPrice;
	CEdit	m_edtOrderNo;
	CComboBox	m_cmbOrderGubun;
	CEdit	m_edtCode;
	CTabCtrl	m_tabOrder;
	CComboBox	m_cmbAccountNo;
	CString	m_txtStatus;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CELWOrderDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CELWOrderDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTabOrder(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnOrderbtn();
	afx_msg void OnBtnCode();
	afx_msg void OnBtnElw2342();
	afx_msg void OnBtnElw2514();
	afx_msg void OnBTNELWCur();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// 추가
public:

	void Request_ReceiveData(BSTR TrCode, BSTR Value, BSTR ValueList, long NextFlag, long SelectCount, BSTR MsgCode, BSTR MsgName); //조회데이터 정상 수신시 발생
	void Request_Status(long Status, BSTR TrCode, BSTR MsgCode, BSTR MsgName); //조회데이터 송수신 에러시 발생
	
	void Order_ReceiveData(BSTR TrCode, BSTR Value, BSTR MsgCode, BSTR MsgName); //주문데이터 정상 수신시 발생
	void Order_Status(long Status, BSTR TrCode, BSTR MsgCode, BSTR MsgName); //주문데이터 송수신 에러시 발생
	
	void Real_ReceiveData(BSTR TrCode, BSTR Value, BSTR MsgCode, BSTR MsgName); //실시간데이터 정상 수신시 발생 
	void Real_Status(long Status, BSTR TrCode, BSTR MsgCode, BSTR MsgName); //실시간 데이터 송수신 에러시 발생

	void ValueList_Update(long RecNo); //수신된 데이터중 리스트성 데이터 처리



protected:
	//IYFRequestDataPtr m_pRequestData;
	//CYFRequestEvent* m_pRequestEvent;

	void InitAccount();
	
	void ElwUnexec_Update();
	void ElwExec_Update();
	void ElwCur_DisplayHogaData();
	void OrderTab_ControlEnable(int Index);

	void ElwOrder_Sell();
	void ElwOrder_Buy();
	void ElwOrder_Modify();
	void ElwOrder_Cancel();
public:
	void ClickGridElw2514();
	CEdit m_edtCurData;
	CButton m_btnUnexec;
	afx_msg void OnBnClickedButton1();
	CEdit m_edtUnexec;
	CEdit m_edtPasswd;
	CEdit m_edtCurData1;
	afx_msg void OnBnClickedBtnCodereg();
	afx_msg void OnBnClickedBtnAccountreg();
	afx_msg void OnBnClickedBtnCodereg2();
	afx_msg void OnBnClickedBtnAccountreg2();
	CEdit m_edtUnexec2;
	CEdit m_edtRealData;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ELWORDERDLG_H__43DE49E8_36E8_4227_9865_F63D18761E95__INCLUDED_)

// ForeFuOrderDlg.h : header file
//
//{{AFX_INCLUDES()
//}}AFX_INCLUDES
#include "afxwin.h"
#if !defined(AFX_ForeFuORDERDLG_H__43DE49E8_36E8_4227_9865_F63D18761E95__INCLUDED_)
#define AFX_ForeFuORDERDLG_H__43DE49E8_36E8_4227_9865_F63D18761E95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


// �߰�
//#include "Events.h"
//

/////////////////////////////////////////////////////////////////////////////
// CForeFuOrderDlg dialog

class CForeFuOrderDlg : public CDialog
{
// Construction
public:
	CForeFuOrderDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CForeFuOrderDlg)
	enum { IDD = IDD_ForeFuORDER_DIALOG };
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
	//{{AFX_VIRTUAL(CForeFuOrderDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CForeFuOrderDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTabOrder(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnOrderbtn();
	afx_msg void OnBtnCode();
	afx_msg void OnBtnForeFu2342();
	afx_msg void OnBtnForeFu2514();
	afx_msg void OnBTNForeFuCur();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// �߰�
public:

	void Request_ReceiveData(BSTR TrCode, BSTR Value, BSTR ValueList, long NextFlag, long SelectCount, BSTR MsgCode, BSTR MsgName); //��ȸ������ ���� ���Ž� �߻�
	void Request_Status(long Status, BSTR TrCode, BSTR MsgCode, BSTR MsgName); //��ȸ������ �ۼ��� ������ �߻�
	
	void Order_ReceiveData(BSTR TrCode, BSTR Value, BSTR MsgCode, BSTR MsgName); //�ֹ������� ���� ���Ž� �߻�
	void Order_Status(long Status, BSTR TrCode, BSTR MsgCode, BSTR MsgName); //�ֹ������� �ۼ��� ������ �߻�
	
	void Real_ReceiveData(BSTR TrCode, BSTR Value, BSTR MsgCode, BSTR MsgName); //�ǽð������� ���� ���Ž� �߻� 
	void Real_Status(long Status, BSTR TrCode, BSTR MsgCode, BSTR MsgName); //�ǽð� ������ �ۼ��� ������ �߻�

	void ValueList_Update(long RecNo); //���ŵ� �������� ����Ʈ�� ������ ó��

	//�ؿܼ���
	void GRequest_ReceiveData(BSTR TrCode, BSTR Value, BSTR ValueList, long NextFlag, long SelectCount, BSTR MsgCode, BSTR MsgName); //��ȸ������ ���� ���Ž� �߻�
	void GRequest_Status(long Status, BSTR TrCode, BSTR MsgCode, BSTR MsgName); //��ȸ������ �ۼ��� ������ �߻�
	
	void GOrder_ReceiveData(BSTR TrCode, BSTR Value, BSTR MsgCode, BSTR MsgName); //�ֹ������� ���� ���Ž� �߻�
	void GOrder_Status(long Status, BSTR TrCode, BSTR MsgCode, BSTR MsgName); //�ֹ������� �ۼ��� ������ �߻�
	
	void GReal_ReceiveData(BSTR TrCode, BSTR Value, BSTR MsgCode, BSTR MsgName); //�ǽð������� ���� ���Ž� �߻� 
	void GReal_Status(long Status, BSTR TrCode, BSTR MsgCode, BSTR MsgName); //�ǽð� ������ �ۼ��� ������ �߻�

	void GValueList_Update(long RecNo); //���ŵ� �������� ����Ʈ�� ������ ó��


protected:
	//IYFRequestDataPtr m_pRequestData;
	//CYFRequestEvent* m_pRequestEvent;

	void InitAccount();
	
	void ForeFuUnexec_Update();
	void ForeFuExec_Update();
	void ForeFuCur_DisplayHogaData();
	void OrderTab_ControlEnable(int Index);

	void ForeFuOrder_Sell();
	void ForeFuOrder_Buy();
	void ForeFuOrder_Modify();
	void ForeFuOrder_Cancel();
public:
	void ClickGridForeFu2514();
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
	CComboBox m_cmbTrdSec;
	CEdit m_edtStopPr;
	afx_msg void OnCbnSelchangeCombo1();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ForeFuORDERDLG_H__43DE49E8_36E8_4227_9865_F63D18761E95__INCLUDED_)

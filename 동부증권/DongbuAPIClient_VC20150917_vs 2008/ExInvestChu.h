#pragma once


// CExInvestChu ��ȭ �����Դϴ�.

class CExInvestChu : public CDialog
{
	DECLARE_DYNAMIC(CExInvestChu)

public:

	CListBox	m_lstMsg;
	CComboBox	m_cmbInvestCode ;
	CComboBox	m_cmbInvestCode2 ;
	CComboBox	m_cmbUpjong ;
	CComboBox	m_cmbQty ;
	CComboBox	m_cmbQty2 ;

	void        MakePacket() ;
	void        MakePacket_Program() ;
	CExInvestChu(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CExInvestChu();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_INVEST_CHU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	virtual BOOL OnInitDialog();	
	afx_msg void OnBtnInquery();
	afx_msg void OnBtnInquery2();	
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnCbnSelchangeCmbInvest();	
};

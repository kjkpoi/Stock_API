#pragma once


// CExInvestChu 대화 상자입니다.

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
	CExInvestChu(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CExInvestChu();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_INVEST_CHU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	virtual BOOL OnInitDialog();	
	afx_msg void OnBtnInquery();
	afx_msg void OnBtnInquery2();	
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnCbnSelchangeCmbInvest();	
};

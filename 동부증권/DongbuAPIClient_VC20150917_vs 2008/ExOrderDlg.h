#pragma once


// CExOrderDlg 대화 상자입니다.

class CExOrderDlg : public CDialog
{
	DECLARE_DYNAMIC(CExOrderDlg)

public:
	CExOrderDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CExOrderDlg();

	//{{AFX_DATA(CExOrderDlg)
	enum { IDD = IDD_DLG_ORDER };
	CListBox	m_lstMsg;
	CComboBox	m_cmbPriceType;
	CString		m_strAcctPwd;
	CString		m_strDate;
	CString		m_strJongmok;
	CString		m_strPrice;
	CString		m_strQty;
	CString		m_strAccount;
	CString		m_strOrgOrderNo;


	int		m_nProduct ;
	int		m_nScreenNo ;

	void    MakeOrder(int nOrdSect) 	;	
	void	MakePacket(CString szTrNo, int nOrdSect, long nPrice) ;
	void    MakePacket_SK(CString szTrNo, int nOrdSect, long nPrice) 	;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	virtual BOOL OnInitDialog();
	afx_msg void OnBtnMesu();
	afx_msg void OnBtnMedo();
	afx_msg void OnBtnModify();
	afx_msg void OnBtnCancel();
	afx_msg void OnBtnAbleqty();

	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);

	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedBtnAbleqty();
};

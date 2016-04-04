#pragma once


// CExAbleOrderQtyDlg ��ȭ �����Դϴ�.

class CExAbleOrderQtyDlg : public CDialog
{
	DECLARE_DYNAMIC(CExAbleOrderQtyDlg)

public:
	CExAbleOrderQtyDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CExAbleOrderQtyDlg();

	//{{AFX_DATA(CExAbleOrderQtyDlg)
	enum { IDD = IDD_DLG_ABLEQTY };
	CListBox	m_lstMsg;

	int		m_nProduct ;
	CComboBox	m_cmbPriceType;
	CComboBox   m_cmbCreditType ;


	CString		m_strAcctPwd;
	
	CString		m_strJongmok;
	CString		m_strPrice;	
	CString		m_strAccount;

	void		MakePacket_FO() ;
	void		MakePacket_SFO() ;
	void		MakePacket_CME() ;
	void		MakePacket_SK() ;
	void        MakePacket_SK_Credit() ;
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	virtual BOOL OnInitDialog();	
	afx_msg void OnBtnAbleqty();
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);

	DECLARE_MESSAGE_MAP()
public:

};

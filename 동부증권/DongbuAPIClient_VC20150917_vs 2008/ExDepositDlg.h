#pragma once


// CExDepositDlg ��ȭ �����Դϴ�.

class CExDepositDlg : public CDialog
{
	DECLARE_DYNAMIC(CExDepositDlg)

public:
	CExDepositDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CExDepositDlg();

	//{{AFX_DATA(CExDepositDlg)
	enum { IDD = IDD_DLG_DEPOSIT };
	CListBox	m_lstMsg;

	int			m_nProduct ;

	CString		m_strAccount;
	CString		m_strAcctPwd;
	CString		m_strDate ;

	void		MakePacket_FO() ;
	void		MakePacket_CME() ;
	void		MakePacket_SK();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	virtual BOOL OnInitDialog();	
	afx_msg void OnBtnInquery();
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);

	DECLARE_MESSAGE_MAP()
};

#pragma once


// CExMiChegyulDlg 대화 상자입니다.

class CExMiChegyulDlg : public CDialog
{
	DECLARE_DYNAMIC(CExMiChegyulDlg)

public:
	CExMiChegyulDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CExMiChegyulDlg();

	//{{AFX_DATA(CExMiChegyulDlg)
	enum { IDD = IDD_DLG_CHE };
	CListBox	m_lstMsg;

	int			m_nProduct ;
	
	CString		m_strAccount;
	CString		m_strAcctPwd;

	CString		m_szNextKey ;
	
	void		MakePacket_FO() ;
	void		MakePacket_CME() ;
	void		MakePacket_SK() ;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	virtual BOOL OnInitDialog();	
	afx_msg void OnBtnInquery();
	afx_msg void OnBnClickedBtnInqueryNext();	
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);

	DECLARE_MESSAGE_MAP()
};

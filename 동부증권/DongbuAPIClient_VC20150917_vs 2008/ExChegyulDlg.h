#pragma once


// CExChegyulDlg 대화 상자입니다.

class CExChegyulDlg : public CDialog
{
	DECLARE_DYNAMIC(CExChegyulDlg)

public:
	CExChegyulDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CExChegyulDlg();

	//{{AFX_DATA(CExChegyulDlg)
	enum { IDD = IDD_DLG_CHE };

	CListBox	m_lstMsg;
	int			m_nProduct ;	
	CString		m_strAccount;
	CString		m_strAcctPwd;
	CString		m_szNextKey;
	
	void		MakePacket_FO() ;
	void		MakePacket_CME() ;
	void		MakePacket_SK();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	virtual BOOL OnInitDialog();	
	afx_msg void OnBtnInquery();
	afx_msg void OnBtnRequestRealtimeData();
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);

	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnBnClickedBtnInqueryNext();
};

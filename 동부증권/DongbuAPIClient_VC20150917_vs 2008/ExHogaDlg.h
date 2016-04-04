#pragma once


// CExHogaDlg 대화 상자입니다.

class CExHogaDlg : public CDialog
{
	DECLARE_DYNAMIC(CExHogaDlg)

public:
	CExHogaDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CExHogaDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_SISE };

	int			m_nProduct ;
	CString		m_strJongmok ;

	CListBox	m_lstMsg;

	void		MakePacket_SK() ;
	void		MakePacket_FO(CString szTRCode);
	

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	virtual BOOL OnInitDialog();	

	afx_msg void OnBtnRequestSise();	
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);

	DECLARE_MESSAGE_MAP()
};

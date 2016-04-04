#pragma once


// CExInvestTodayDlg 대화 상자입니다.

class CExInvestTodayDlg : public CDialog
{
	DECLARE_DYNAMIC(CExInvestTodayDlg)

public:

	CListBox	m_lstMsg;
	CString		m_strJongmok ;

	CString     m_szNextKey ;

	void        MakePacket() ;
	CExInvestTodayDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CExInvestTodayDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_INVEST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	virtual BOOL OnInitDialog();	
	afx_msg void OnBtnInquery();
	afx_msg void OnBnClickedBtnInqueryNext();	
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);

	DECLARE_MESSAGE_MAP()

};

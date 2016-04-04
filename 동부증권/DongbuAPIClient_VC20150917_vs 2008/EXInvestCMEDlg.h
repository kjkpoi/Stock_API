#pragma once


// CExInvestCMEDlg 대화 상자입니다.

class CExInvestCMEDlg : public CDialog
{
	DECLARE_DYNAMIC(CExInvestCMEDlg)

public:

	CListBox	m_lstMsg;


	CString     m_szNextKey ;

	void        MakePacket() ;
	CExInvestCMEDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CExInvestCMEDlg();

	// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_INVESTCME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	virtual BOOL OnInitDialog();	
	afx_msg void OnBtnInquery();
	afx_msg void OnBnClickedBtnInqueryNext();	
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedBtnInquery2();
};

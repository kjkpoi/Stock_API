#pragma once


// CExInvestTodayDlg ��ȭ �����Դϴ�.

class CExInvestTodayDlg : public CDialog
{
	DECLARE_DYNAMIC(CExInvestTodayDlg)

public:

	CListBox	m_lstMsg;
	CString		m_strJongmok ;

	CString     m_szNextKey ;

	void        MakePacket() ;
	CExInvestTodayDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CExInvestTodayDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_INVEST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	virtual BOOL OnInitDialog();	
	afx_msg void OnBtnInquery();
	afx_msg void OnBnClickedBtnInqueryNext();	
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);

	DECLARE_MESSAGE_MAP()

};

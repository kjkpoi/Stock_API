#pragma once


// CExInvestCMEDlg ��ȭ �����Դϴ�.

class CExInvestCMEDlg : public CDialog
{
	DECLARE_DYNAMIC(CExInvestCMEDlg)

public:

	CListBox	m_lstMsg;


	CString     m_szNextKey ;

	void        MakePacket() ;
	CExInvestCMEDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CExInvestCMEDlg();

	// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_INVESTCME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	virtual BOOL OnInitDialog();	
	afx_msg void OnBtnInquery();
	afx_msg void OnBnClickedBtnInqueryNext();	
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedBtnInquery2();
};

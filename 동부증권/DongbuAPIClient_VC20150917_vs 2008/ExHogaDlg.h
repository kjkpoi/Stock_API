#pragma once


// CExHogaDlg ��ȭ �����Դϴ�.

class CExHogaDlg : public CDialog
{
	DECLARE_DYNAMIC(CExHogaDlg)

public:
	CExHogaDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CExHogaDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_SISE };

	int			m_nProduct ;
	CString		m_strJongmok ;

	CListBox	m_lstMsg;

	void		MakePacket_SK() ;
	void		MakePacket_FO(CString szTRCode);
	

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	virtual BOOL OnInitDialog();	

	afx_msg void OnBtnRequestSise();	
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);

	DECLARE_MESSAGE_MAP()
};

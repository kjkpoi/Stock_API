#pragma once


// CExSiseDlg ��ȭ �����Դϴ�.

class CExSiseDlg : public CDialog
{
	DECLARE_DYNAMIC(CExSiseDlg)

public:
	CExSiseDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CExSiseDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_SISE };

	int			m_nProduct ;
	CString		m_strJongmok ;

	CListBox	m_lstMsg;

	void		MakePacket_SK() ;
	

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	virtual BOOL OnInitDialog();	

	afx_msg void OnBtnRequestSise();	
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);

	DECLARE_MESSAGE_MAP()
};

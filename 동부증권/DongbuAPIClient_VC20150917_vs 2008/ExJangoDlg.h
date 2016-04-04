#pragma once


// CExJangoDlg ��ȭ �����Դϴ�.

class CExJangoDlg : public CDialog
{
	DECLARE_DYNAMIC(CExJangoDlg)

public:
	CExJangoDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CExJangoDlg();

	//{{AFX_DATA(CExJangoDlg)
	enum { IDD = IDD_DLG_JANGO };

	CListBox	m_lstMsg;
	int			m_nProduct ;	
	CString		m_strAccount;
	
	void		MakePacket_FO() ;
	void		MakePacket_CME() ;
	void		MakePacket_SK() ;
	void        MakePacket_SK_Simple();
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	virtual BOOL OnInitDialog();	
	afx_msg void OnBtnInquery();
	afx_msg void OnBtnRequestRealtimeData();
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	

	DECLARE_MESSAGE_MAP()
public:
	
};

#pragma once


// CExRealtimeDataDlg ��ȭ �����Դϴ�.

class CExRealtimeDataDlg : public CDialog
{
	DECLARE_DYNAMIC(CExRealtimeDataDlg)

public:
	CExRealtimeDataDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CExRealtimeDataDlg();

	//{{AFX_DATA(CExRealtimeDataDlg)
	enum { IDD = IDD_DLG_RT };
	
	int			m_nProduct ;
	CString		m_strJongmok ;
	
	void		MakePacket() ;
	void		MakePacket_CME() ;


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	virtual BOOL OnInitDialog();	
	
	afx_msg void OnBtnRequestSise();
	afx_msg void OnBtnRequestHoga();
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);


	DECLARE_MESSAGE_MAP()
public:

};

#pragma once
#include "afxwin.h"
#include "APITest.h"

class ExTest :
	public CDialog
{
	DECLARE_DYNAMIC(ExTest)

public:
	ExTest(CWnd* pParent = NULL);
	virtual ~ExTest();

	enum { IDD = IDD_DLG_TEST };

	int			m_nProduct ;
	CString		m_strJongmok ;

	APITest* apiTest;

	CListBox	m_lstMsg;

	void		MakePacket_SK() ;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	virtual BOOL OnInitDialog();	

	afx_msg void OnBtnRequestSise();	
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);

	CString getString(char *, int);

	UINT ThreadFunc(LPVOID pParam);

	DECLARE_MESSAGE_MAP()
};

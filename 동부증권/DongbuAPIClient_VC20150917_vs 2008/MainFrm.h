
// MainFrm.h : CMainFrame Ŭ������ �������̽�
//

#pragma once

class CMainFrame : public CMDIFrameWndEx
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame();

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);

// �����Դϴ�.
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // ��Ʈ�� ������ ���Ե� ����Դϴ�.
	CMFCMenuBar       m_wndMenuBar;
	CMFCToolBar       m_wndToolBar;
	CMFCStatusBar     m_wndStatusBar;
	CMFCToolBarImages m_UserImages;

	void			SetWindowTextEx() ;

	void			OpenOrderExDlg(int nProduct) ;
	void			OpenRealtimeDataExDlg(int nProduct) ;
	void			OpenJangoExDlg(int nProduct) ;
	void			OpenChegyulExDlg(int nProduct) ;
	void			OpenMiChegyulExDlg(int nProduct) ;
	void			OpenAbleQtyExDlg(int nProduct) ;
	void			OpenDepositExDlg(int nProduct) ;
	void			OpenHogaExDlg(int nProduct) ;

	void			GetAccountList(LPSTR szData, int nLen) ;
	
// ������ �޽��� �� �Լ�
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//afx_msg void OnWindowManager();
	//afx_msg void OnViewCustomize();

	afx_msg void OnLogin() ;

	afx_msg void OnInquryAccountListFO() ;
	afx_msg void OnInquryAccountListSK() ;

	//CME����
	afx_msg void OnOrderCME() ;	
	afx_msg void OnAbleQtyCME() ;
	afx_msg void OnJangoCME() ;
	afx_msg void OnChegyulCME() ;
	afx_msg void OnMiChegyulCME() ;
	afx_msg void OnDepositCME() ;
	afx_msg void OnInvestChange() ;

	afx_msg void OnRealtimeCME() ;


	//���� �����ɼ�
	afx_msg void OnOrderFO() ;	
	afx_msg void OnJangoFO() ;
	afx_msg void OnChegyulFO() ;
	afx_msg void OnMiChegyulFO() ;
	afx_msg void OnAbleQtyFO() ;
	afx_msg void OnDepositFO() ;

	afx_msg void OnRealtimeFUT() ;
	afx_msg void OnRealtimeOPT() ;
	afx_msg void OnSymbolFinderFut() ;
	afx_msg void OnSymbolFinderOpt() ;
	
	


	//�ֽ� �����ɼ�
	afx_msg void OnOrderSFO() ;
	afx_msg void OnAbleQtySFO() ;	
	afx_msg void OnRealtimeSFUT() ;
	afx_msg void OnRealtimeSOPT() ;
			
	
	//�ֽ�
	afx_msg void OnOrderSK() ;
	afx_msg void OnJangoSK() ;
	afx_msg void OnChegyulSK() ;
	afx_msg void OnMiChegyulSK() ;
	afx_msg void OnDepositSK() ;
	afx_msg void OnAbleQtySK();
	
	afx_msg void OnRealtimeSK() ;

	afx_msg void OnSiseSK() ;
	afx_msg void OnHogaSK() ;
	afx_msg void OnHogaFut() ;
	afx_msg void OnHogaOpt() ;
	afx_msg void OnInvestToday() ;
	afx_msg void OnInvestSK() ;

	afx_msg void OnSvrOrderSetAll() ;
	afx_msg void OnSvrOrderSet() ;

	//�ֽ� my function
	afx_msg void OnMyTest();
	
		
	//afx_msg LRESULT OnToolbarCreateNew(WPARAM wp, LPARAM lp);

	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	DECLARE_MESSAGE_MAP()

};



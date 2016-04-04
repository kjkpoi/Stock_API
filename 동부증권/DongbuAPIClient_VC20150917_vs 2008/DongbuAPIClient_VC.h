
// DongbuAPIClient_VC.h : DongbuAPIClient_VC ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CDongbuAPIClient_VCApp:
// �� Ŭ������ ������ ���ؼ��� DongbuAPIClient_VC.cpp�� �����Ͻʽÿ�.
//

class CDongbuAPIClient_VCApp : public CWinAppEx
{
public:
	CDongbuAPIClient_VCApp();

	CString			g_szId ;
	BOOL			g_bConnected ;
	HWND			g_hDongbuDRCM;
	CString			g_szMyIP ;
	CString			g_strRoot ;

	CString			g_strAccount ;
	CString			g_strAcctPwd ;
	CString			g_strJongmok ;
	CString			g_strPrice ;
	CString			g_strQty ;
	CString			g_strDate ;


	CString			g_strID ;
	CString			g_strPwd ;
	CString			g_strCertPwd ;



	CMapStringToString gKospi_Map;
	CMapStringToString gKosdaq_Map;

	BOOL			SendToServerEx(int nWorkType, CString szTrCode, CString szData, HWND hSender) ;
	BOOL			SendToServerEx(CString strTrCode,BYTE * lpData,long nSize, HWND hSender) ;

	int				gatoi(LPSTR lpstrSrc, UINT uSize) ;
	double			gatof(LPSTR lpstrSrc, UINT uSize) ;
	CString			gatosz(LPSTR lpstrSrc, UINT uSize) ;
	void			CopyString(char *pDest, int nDest, const char *pSrc);

	HRESULT			OnRecv77080(WPARAM wParam, LPARAM lParam) ;

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDongbuAPIClient_VCApp theApp;

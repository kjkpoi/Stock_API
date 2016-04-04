
// DongbuAPIClient_VC.h : DongbuAPIClient_VC 응용 프로그램에 대한 주 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'stdafx.h'를 포함합니다."
#endif

#include "resource.h"       // 주 기호입니다.


// CDongbuAPIClient_VCApp:
// 이 클래스의 구현에 대해서는 DongbuAPIClient_VC.cpp을 참조하십시오.
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

// 재정의입니다.
public:
	virtual BOOL InitInstance();

// 구현입니다.
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDongbuAPIClient_VCApp theApp;

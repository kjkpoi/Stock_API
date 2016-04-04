// DongbuAPIClient.h : main header file for the DONGBUAPICLIENT application
//

#if !defined(AFX_DONGBUAPICLIENT_H__D4339494_CCF0_4F69_8CE2_D162214787BB__INCLUDED_)
#define AFX_DONGBUAPICLIENT_H__D4339494_CCF0_4F69_8CE2_D162214787BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDongbuAPIClientApp:
// See DongbuAPIClient.cpp for the implementation of this class
//

class CDongbuAPIClientApp : public CWinApp
{
public:
	CDongbuAPIClientApp();

	HWND	g_hDongbuDRCM;
	CString	g_szMyIP ;

	BOOL	SendToServerEx(int nWorkType, CString szTrCode, CString szData, HWND hSender) ;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDongbuAPIClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDongbuAPIClientApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CDongbuAPIClientApp		theApp;

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DONGBUAPICLIENT_H__D4339494_CCF0_4F69_8CE2_D162214787BB__INCLUDED_)

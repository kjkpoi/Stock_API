// ForeFuOrder.h : main header file for the ForeFuORDER application
//

#if !defined(AFX_ForeFuORDER_H__2D19E4DD_0517_4894_9429_0AEB8EC2FD15__INCLUDED_)
#define AFX_ForeFuORDER_H__2D19E4DD_0517_4894_9429_0AEB8EC2FD15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "ForeFuOrder_i.h"

/////////////////////////////////////////////////////////////////////////////
// CForeFuOrderApp:
// See ForeFuOrder.cpp for the implementation of this class
//

class CForeFuOrderApp : public CWinApp
{
public:
	CForeFuOrderApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CForeFuOrderApp)
	public:
	virtual BOOL InitInstance();
		virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CForeFuOrderApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bATLInited;
private:
	BOOL InitATL();
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ForeFuORDER_H__2D19E4DD_0517_4894_9429_0AEB8EC2FD15__INCLUDED_)

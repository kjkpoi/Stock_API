// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__94394C20_DAFA_40AA_BC22_18DD96E81530__INCLUDED_)
#define AFX_STDAFX_H__94394C20_DAFA_40AA_BC22_18DD96E81530__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#define WINVER 0x0501		// 필요한 최소 플랫폼을 Windows XP로 지정
//#define _WIN32_WINNT 0x0501
#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

// 추가
#include <comdef.h>
#import "C:\Cyber21Plus\ExpertPlus\YFExpertPlus.dll" no_namespace named_guids
#import "C:\Cyber21Plus\ExpertPlus\YFGExpertPlus.dll" no_namespace named_guids
////////////////////////////////////////////////////////////////////////

#define _ATL_APARTMENT_THREADED
#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
class CForeFuOrderModule : public CComModule
{
public:
	LONG Unlock();
	LONG Lock();
	LPCTSTR FindOneOf(LPCTSTR p1, LPCTSTR p2);
	DWORD dwThreadID;
};
extern CForeFuOrderModule _Module;
#include <atlcom.h>


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__94394C20_DAFA_40AA_BC22_18DD96E81530__INCLUDED_)

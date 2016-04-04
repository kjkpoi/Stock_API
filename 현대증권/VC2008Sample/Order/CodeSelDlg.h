#if !defined(AFX_CODESELDLG_H__7DBCA79C_8BED_4E5B_9109_30D8338499AB__INCLUDED_)
#define AFX_CODESELDLG_H__7DBCA79C_8BED_4E5B_9109_30D8338499AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CodeSelDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCodeSelDlg dialog

class CCodeSelDlg : public CDialog
{
// Construction
public:
	CCodeSelDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCodeSelDlg)
	enum { IDD = IDD_CODEDLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCodeSelDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCodeSelDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CODESELDLG_H__7DBCA79C_8BED_4E5B_9109_30D8338499AB__INCLUDED_)

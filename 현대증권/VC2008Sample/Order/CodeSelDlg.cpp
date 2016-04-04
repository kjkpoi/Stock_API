// CodeSelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ELWOrder.h"
#include "CodeSelDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCodeSelDlg dialog


CCodeSelDlg::CCodeSelDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCodeSelDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCodeSelDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCodeSelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCodeSelDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCodeSelDlg, CDialog)
	//{{AFX_MSG_MAP(CCodeSelDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCodeSelDlg message handlers

// SymbolFindDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "DongbuAPIClient_VC.h"
#include "SymbolFindDialog.h"
#include "SymbolFile.h"


// CSymbolFindDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSymbolFindDialog, CDialog)

CSymbolFindDialog::CSymbolFindDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSymbolFindDialog::IDD, pParent)
{

}

CSymbolFindDialog::~CSymbolFindDialog()
{
}

void CSymbolFindDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSymbolFindDialog)
	DDX_Control(pDX, IDC_LIST,			m_List1);		
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSymbolFindDialog, CDialog)
END_MESSAGE_MAP()


// CSymbolFindDialog 메시지 처리기입니다.

BOOL CSymbolFindDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();

	switch (m_nProduct)
	{
	case ID_PRODUCT_FUT :   // 지수 선물
		CSymbolFile(theApp.g_strRoot	+ "\\Data\\Master\\FMaster.dat").LoadSymbolFuture(gKospiFO_Map, 4);
		break ;
	case ID_PRODUCT_OPT :  // 주식 옵션
		CSymbolFile(theApp.g_strRoot + "\\Data\\Master\\PMaster.dat").LoadSymbolOption(gKospiFO_Map);
		break;		
	}	
	
	DWORD styles = LVS_EX_FULLROWSELECT;
	ListView_SetExtendedListViewStyleEx(m_List1.m_hWnd, styles, styles);
	
	LV_COLUMN lvcolumn;
	lvcolumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	lvcolumn.fmt = LVCFMT_CENTER;
	lvcolumn.cx = 80;
	lvcolumn.pszText = (LPSTR)(LPCTSTR)"종목코드";	
	m_List1.InsertColumn(0, &lvcolumn);

	LV_COLUMN lvcolumn2;
	lvcolumn2.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	lvcolumn2.fmt = LVCFMT_LEFT;
	lvcolumn2.cx = 120;
	lvcolumn2.pszText = (LPSTR)(LPCTSTR)"종목명";	
	m_List1.InsertColumn(1, &lvcolumn2);

	
	CStringArray StrArray;
	StrMapToArray(gKospiFO_Map, FALSE, ";", StrArray);
	AddSymbolList(&StrArray, FALSE, ";");
	
	return TRUE;
}


void CSymbolFindDialog::AddRecord(LPCTSTR strCode, LPCTSTR strName)
{
	LV_ITEM lvItem;

	lvItem.mask = LVIF_TEXT; // | LVIF_PARAM ;
	lvItem.iSubItem = 0;
	lvItem.cchTextMax = strlen(strCode);
	lvItem.pszText = const_cast<LPTSTR>(strCode);
	lvItem.iItem = m_List1.GetItemCount();
	//lvItem.lParam = ;
	m_List1.InsertItem(&lvItem);

	lvItem.mask = LVIF_TEXT;
	lvItem.iSubItem = 1;
	lvItem.cchTextMax = strlen(strName);
	lvItem.pszText = const_cast<LPTSTR>(strName);
	m_List1.SetItem(&lvItem);
}

void CSymbolFindDialog::AddSymbolList(CMapStringToString *pMapString)
{
	CString strKey, strValue;

	for (POSITION pos = pMapString->GetStartPosition(); pos != NULL; ) 
	{
		pMapString->GetNextAssoc(pos, strKey, strValue);

		AddRecord(strKey, strValue);

	}
}

void CSymbolFindDialog::AddSymbolList(CStringArray *pStrArray, BOOL bNameAndCode, LPCTSTR strSep)
{
	CString strRecord, strCode, strName;
	int nSep;

	for (int i = 0; i < pStrArray->GetSize(); i++) 
	{
		strRecord = pStrArray->GetAt(i);
		nSep = strRecord.Find(strSep);

		if (bNameAndCode) {
			strName = strRecord.Left(nSep);
			strCode = strRecord.Mid(nSep + 1);
		} else {
			strCode = strRecord.Left(nSep);
			strName = strRecord.Mid(nSep + 1);
		}

		AddRecord(strCode, strName);
	}
}

void CSymbolFindDialog::StrMapToArray(CMapStringToString &StrMap, BOOL bValueAndKey, LPCTSTR strSep, CStringArray &StrArray)
{
	ASSERT(StrArray.GetSize() == 0);

	CString strKey, strValue;

	StrArray.SetSize(StrMap.GetCount());

	int i = 0;
	for (POSITION pos = StrMap.GetStartPosition(); pos != NULL; i++) {
		StrMap.GetNextAssoc(pos, strKey, strValue);
		if (bValueAndKey == TRUE)
			StrArray[i] = strValue + strSep + strKey;
		else
			StrArray[i] = strKey + strSep + strValue;
	}
}

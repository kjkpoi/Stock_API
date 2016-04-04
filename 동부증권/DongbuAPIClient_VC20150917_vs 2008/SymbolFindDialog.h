#pragma once


// CSymbolFindDialog ��ȭ �����Դϴ�.

class CSymbolFindDialog : public CDialog
{
	DECLARE_DYNAMIC(CSymbolFindDialog)

public:
	CSymbolFindDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSymbolFindDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_FINDER };

	CListCtrl	m_List1;
	int			m_nProduct ;


	CMapStringToString gKospiFO_Map;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	virtual BOOL OnInitDialog();
	
	void				AddRecord(LPCTSTR strCode, LPCTSTR strName) ;
	void				AddSymbolList(CMapStringToString *pMapString);
	void				AddSymbolList(CStringArray *pStrArray, BOOL bNameAndCode, LPCTSTR strSep);
	void				StrMapToArray(CMapStringToString &StrMap, BOOL bValueAndKey, LPCTSTR strSep, CStringArray &StrArray);

	DECLARE_MESSAGE_MAP()
};

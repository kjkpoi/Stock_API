#pragma once


// CSymbolFindDialog 대화 상자입니다.

class CSymbolFindDialog : public CDialog
{
	DECLARE_DYNAMIC(CSymbolFindDialog)

public:
	CSymbolFindDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CSymbolFindDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_FINDER };

	CListCtrl	m_List1;
	int			m_nProduct ;


	CMapStringToString gKospiFO_Map;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	virtual BOOL OnInitDialog();
	
	void				AddRecord(LPCTSTR strCode, LPCTSTR strName) ;
	void				AddSymbolList(CMapStringToString *pMapString);
	void				AddSymbolList(CStringArray *pStrArray, BOOL bNameAndCode, LPCTSTR strSep);
	void				StrMapToArray(CMapStringToString &StrMap, BOOL bValueAndKey, LPCTSTR strSep, CStringArray &StrArray);

	DECLARE_MESSAGE_MAP()
};

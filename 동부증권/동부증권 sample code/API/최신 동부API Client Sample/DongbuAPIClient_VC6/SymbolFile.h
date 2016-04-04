// SymbolFile.h: interface for the CSymbolFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SYMBOLFILE_H__9932DF96_3D50_4187_9A72_BE73FCBA9C7B__INCLUDED_)
#define AFX_SYMBOLFILE_H__9932DF96_3D50_4187_9A72_BE73FCBA9C7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>

class CSymbolFile  
{
public:
	CString m_strFilePath;
public:
	CSymbolFile(LPCTSTR strFilePath);
	virtual ~CSymbolFile();

	BOOL LoadSymbol(CMapStringToString &SymbolMap, int nLoadCnt = -1);
	BOOL LoadSymbolKosdaq(CMapStringToString &SymbolMap, int nLoadCnt = -1);
	BOOL LoadSymbolStock(CMapStringToString &SymbolMap, int nLoadCnt = -1);
	BOOL LoadSymbolFuture(CMapStringToString &SymbolMap, int nLoadCnt = -1);
	BOOL LoadSymbolOption(CMapStringToString &SymbolMap, int nLoadCnt = -1);
};

#endif // !defined(AFX_SYMBOLFILE_H__9932DF96_3D50_4187_9A72_BE73FCBA9C7B__INCLUDED_)

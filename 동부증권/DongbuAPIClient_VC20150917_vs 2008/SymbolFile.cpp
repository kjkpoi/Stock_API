// SymbolFile.cpp: implementation of the CSymbolFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SymbolFile.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSymbolFile::CSymbolFile(LPCTSTR strFilePath)
{
	m_strFilePath = strFilePath;
}

CSymbolFile::~CSymbolFile()
{

}

BOOL CSymbolFile::LoadSymbolKosdaq(CMapStringToString &SymbolMap, int nLoadCnt)
{
	FILE *fp = fopen(m_strFilePath, "r+t");

	if (fp == NULL) return FALSE;

	CString temp, strSymbol, strDescription;
	char buffer[1024];

	//header를 읽어서 symbol과 description필드의 index를 찾았으므로 해당 필드를 찾아 SymbolMap을 채운다.
	//이때 심볼 읽기 수 제한 있으면 이 제한수 만큼만 읽는다.
	int nCurCnt = 0;

	while (true) {
		memset(buffer, 0, sizeof(buffer));

		if (fgets(buffer, sizeof(buffer) -1, fp) == NULL)
			break;

		temp = buffer;

		strSymbol = "";
		strDescription = "";

		strSymbol.Format("%6.6s", buffer+20);
		strDescription.Format("%18.18s", buffer+2);
	
		strSymbol.TrimLeft(); strSymbol.TrimRight();
		strDescription.TrimLeft(); strDescription.TrimRight();

		if (strSymbol.IsEmpty() || strDescription.IsEmpty()) {
			fclose(fp);
			return FALSE;
		}

		if (strSymbol.GetLength() != 6)
			continue;

		//맵에 심볼, 심볼명 추가.
		SymbolMap.SetAt(strSymbol, strDescription);
		
		//심볼 읽기 수 제한 수만큼만 읽도록한다.
		if ((nLoadCnt > 0) && (++nCurCnt >= nLoadCnt)) {
			break;
		}
	}
	
	fclose(fp);

	return TRUE;
}

BOOL CSymbolFile::LoadSymbolStock(CMapStringToString &SymbolMap, int nLoadCnt)
{
	FILE *fp = fopen(m_strFilePath, "r+t");

	if (fp == NULL) return FALSE;

	CString temp, strSymbol, strDescription;
	char buffer[1024];

	//header를 읽어서 symbol과 description필드의 index를 찾았으므로 해당 필드를 찾아 SymbolMap을 채운다.
	//이때 심볼 읽기 수 제한 있으면 이 제한수 만큼만 읽는다.
	int nCurCnt = 0;

	while (true) {
		memset(buffer, 0, sizeof(buffer));

		if (fgets(buffer, sizeof(buffer) -1, fp) == NULL)
			break;

		temp = buffer;

		strSymbol = "";
		strDescription = "";

		strSymbol.Format("%6.6s", buffer+20);
		strDescription.Format("%18.18s", buffer+2);
	
		strSymbol.TrimLeft(); strSymbol.TrimRight();
		strDescription.TrimLeft(); strDescription.TrimRight();

		if (strSymbol.IsEmpty() || strDescription.IsEmpty()) {
			fclose(fp);
			return FALSE;
		}

		if (strSymbol.GetLength() != 6)
			continue;

		//맵에 심볼, 심볼명 추가.
		SymbolMap.SetAt(strSymbol, strDescription);
		
		//심볼 읽기 수 제한 수만큼만 읽도록한다.
		if ((nLoadCnt > 0) && (++nCurCnt >= nLoadCnt)) {
			break;
		}
	}
	
	fclose(fp);

	return TRUE;
}

BOOL CSymbolFile::LoadSymbolFuture(CMapStringToString &SymbolMap, int nLoadCnt)
{
	FILE *fp = fopen(m_strFilePath, "r+t");

	if (fp == NULL) return FALSE;

	CString temp, strSymbol, strDescription;
	char buffer[1024];

	//header를 읽어서 symbol과 description필드의 index를 찾았으므로 해당 필드를 찾아 SymbolMap을 채운다.
	//이때 심볼 읽기 수 제한 있으면 이 제한수 만큼만 읽는다.
	int nCurCnt = 0;

	while (true) {
		memset(buffer, 0, sizeof(buffer));

		if (fgets(buffer, sizeof(buffer) -1, fp) == NULL)
			break;

		temp = buffer;

		strSymbol = "";
		strDescription = "";

		strSymbol.Format("%8.8s", buffer+30);
		strDescription.Format("%24.24s", buffer);

		strSymbol.TrimLeft(); strSymbol.TrimRight();
		strDescription.TrimLeft(); strDescription.TrimRight();

		if (strSymbol.IsEmpty() || strDescription.IsEmpty()) {
			fclose(fp);
			return FALSE;
		}

		//m_strFileName에 따른 TS 가장심볼 제거.
//		if (m_strFilePath.Find("future") > -1 || m_strFilePath.Find("option") > -1) 
		{
			if (strSymbol.GetLength() != 8)
				continue;
			if (strSymbol.Left(3) != "101" && strSymbol.Left(3) != "201" && strSymbol.Left(3) != "301")
				continue;
		}

		//맵에 심볼, 심볼명 추가.
		SymbolMap.SetAt(strSymbol, strDescription);
		
		//심볼 읽기 수 제한 수만큼만 읽도록한다.
		if ((nLoadCnt > 0) && (++nCurCnt >= nLoadCnt)) {
			break;
		}
	}
	
	fclose(fp);

	return TRUE;
}

BOOL CSymbolFile::LoadSymbolOption(CMapStringToString &SymbolMap, int nLoadCnt)
{
	FILE *fp = fopen(m_strFilePath, "r+t");

	if (fp == NULL) return FALSE;

	CString temp, strSymbol, strDescription;
	char buffer[1024];

	//header를 읽어서 symbol과 description필드의 index를 찾았으므로 해당 필드를 찾아 SymbolMap을 채운다.
	//이때 심볼 읽기 수 제한 있으면 이 제한수 만큼만 읽는다.
	int nCurCnt = 0;

	while (true) {
		memset(buffer, 0, sizeof(buffer));

		if (fgets(buffer, sizeof(buffer) -1, fp) == NULL)
			break;

		temp = buffer;

		strSymbol = "";
		strDescription = "";

		strSymbol.Format("%8.8s", buffer+14);
		strDescription.Format("%14.14s", buffer);

		strSymbol.TrimLeft(); strSymbol.TrimRight();
		strDescription.TrimLeft(); strDescription.TrimRight();

		if (strSymbol.IsEmpty() || strDescription.IsEmpty()) {
			fclose(fp);
			return FALSE;
		}

		//m_strFileName에 따른 TS 가장심볼 제거.
//		if (m_strFilePath.Find("future") > -1 || m_strFilePath.Find("option") > -1) 
		{
			if (strSymbol.GetLength() != 8)
				continue;
			if (strSymbol.Left(3) != "101" && strSymbol.Left(3) != "201" && strSymbol.Left(3) != "301")
				continue;
		}

	
		//맵에 심볼, 심볼명 추가.
		SymbolMap.SetAt(strSymbol, strDescription);
		
		//심볼 읽기 수 제한 수만큼만 읽도록한다.
		if ((nLoadCnt > 0) && (++nCurCnt >= nLoadCnt)) {
			break;
		}
	}
	
	fclose(fp);

	return TRUE;
}

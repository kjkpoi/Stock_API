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

//심볼파일로부터 심볼코드/심볼명 맵을 로딩.
BOOL CSymbolFile::LoadSymbol(CMapStringToString &SymbolMap, int nLoadCnt)
{
	FILE *fp = fopen(m_strFilePath, "r+t");

	if (fp == NULL) return FALSE;

	CString temp, strSymbol, strDescription;
	char buffer[1024];
	int nIndexSymbol = -1, nIndexDescription = -1, nIndex;

	//header 읽기. header에서 ";"를 구분자로 "Symbol", "Description"필드의 index를 얻는다.
	memset(buffer, 0, sizeof(buffer));
	if (NULL == fgets(buffer, sizeof(buffer) - 1, fp)) {
		fclose(fp);
		return FALSE;
	}

	temp = buffer;

	for(int i = 0; (nIndex = temp.Find(';')) > 0; i++) {
		if (temp.Left(nIndex).CompareNoCase("symbol") == 0) {
			nIndexSymbol = i;
		} else if (temp.Left(nIndex).CompareNoCase("description") == 0) {
			nIndexDescription = i;
		}
		
		temp = temp.Mid(nIndex + 1);
	}

	if (temp.CompareNoCase("symbol") == 0) {
		nIndexSymbol = i;
	} else if (temp.CompareNoCase("description") == 0) {
		nIndexDescription = i;
	}

	if (nIndexSymbol == -1 || nIndexDescription == -1) {
		fclose(fp);
		ASSERT(FALSE);
		return FALSE;
	}

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
		
		for (int i = 0; (nIndex = temp.Find(';')) > 0; i++) {
			if (i == nIndexSymbol) {
				strSymbol = temp.Left(nIndex);
			} else if (i == nIndexDescription) {
				strDescription = temp.Left(nIndex);
			}

			temp = temp.Mid(nIndex + 1);
		}

		if (i == nIndexSymbol) {
			strSymbol = temp;
		} else if (i == nIndexDescription) {
			strDescription = temp;
		}
		
		strSymbol.TrimLeft(); strSymbol.TrimRight();
		strDescription.TrimLeft(); strDescription.TrimRight();

		if (strSymbol.IsEmpty() || strDescription.IsEmpty()) {
			fclose(fp);
			return FALSE;
		}

		//m_strFileName에 따른 TS 가장심볼 제거.
		if (m_strFilePath.Find("future") > -1 || m_strFilePath.Find("option") > -1) {
			if (strSymbol.GetLength() != 8)
				continue;
			if (strSymbol.Left(3) != "101" && strSymbol.Left(3) != "201" && strSymbol.Left(3) != "301")
				continue;
		}
		if (m_strFilePath.Find("stock") > -1 || m_strFilePath.Find("kosdaq") > -1) {
			if (strSymbol.GetLength() != 6)
				continue;
		}

		
		if (strDescription.Left(1) == '*' || strDescription.Left(1) == '#') {
			strDescription = strDescription.Mid(1);
		}

		//인베스트웨어 선물/옵션 코드를 동부코드에 맞춘다.
		if ((m_strFilePath.Find("future") > -1 || m_strFilePath.Find("option") > -1) && strSymbol.GetLength() == 8) {
			//ㅇㅇㅇ는 선물코드에 행사가를 붙이지 않으므로.. 옵션에만 행사가를 붙인다.
// 			if (strSymbol.Left(3) == "101")
// 				temp = strSymbol.Left(5);
// 			else
// 				temp = strSymbol;
// 
//			strSymbol = temp;
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

		//인베스트웨어 선물/옵션 코드를 동부코드에 맞춘다.
		if ((m_strFilePath.Find("future") > -1 || m_strFilePath.Find("option") > -1) && strSymbol.GetLength() == 8) {
			//ㅇㅇㅇ는 선물코드에 행사가를 붙이지 않으므로.. 옵션에만 행사가를 붙인다.
// 			if (strSymbol.Left(3) == "101")
// 				temp = strSymbol.Left(5);
// 			else
// 				temp = strSymbol;
// 
//			strSymbol = temp;
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

		//인베스트웨어 선물/옵션 코드를 동부코드에 맞춘다.
		if ((m_strFilePath.Find("future") > -1 || m_strFilePath.Find("option") > -1) && strSymbol.GetLength() == 8) {
			//ㅇㅇㅇ는 선물코드에 행사가를 붙이지 않으므로.. 옵션에만 행사가를 붙인다.
// 			if (strSymbol.Left(3) == "101")
// 				temp = strSymbol.Left(5);
// 			else
// 				temp = strSymbol;
// 
//			strSymbol = temp;
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

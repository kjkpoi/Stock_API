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

//宿瑳督析稽採斗 宿瑳坪球/宿瑳誤 己聖 稽漁.
BOOL CSymbolFile::LoadSymbol(CMapStringToString &SymbolMap, int nLoadCnt)
{
	FILE *fp = fopen(m_strFilePath, "r+t");

	if (fp == NULL) return FALSE;

	CString temp, strSymbol, strDescription;
	char buffer[1024];
	int nIndexSymbol = -1, nIndexDescription = -1, nIndex;

	//header 石奄. header拭辞 ";"研 姥歳切稽 "Symbol", "Description"琶球税 index研 条澗陥.
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

	//header研 石嬢辞 symbol引 description琶球税 index研 達紹生糠稽 背雁 琶球研 達焼 SymbolMap聖 辰錘陥.
	//戚凶 宿瑳 石奄 呪 薦廃 赤生檎 戚 薦廃呪 幻鏑幻 石澗陥.
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

		//m_strFileName拭 魚献 TS 亜舌宿瑳 薦暗.
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

		//昔今什闘裾嬢 識弘/辛芝 坪球研 疑採坪球拭 限秩陥.
		if ((m_strFilePath.Find("future") > -1 || m_strFilePath.Find("option") > -1) && strSymbol.GetLength() == 8) {
			//ししし澗 識弘坪球拭 楳紫亜研 細戚走 省生糠稽.. 辛芝拭幻 楳紫亜研 細昔陥.
// 			if (strSymbol.Left(3) == "101")
// 				temp = strSymbol.Left(5);
// 			else
// 				temp = strSymbol;
// 
//			strSymbol = temp;
		}

		//己拭 宿瑳, 宿瑳誤 蓄亜.
		SymbolMap.SetAt(strSymbol, strDescription);
		
		//宿瑳 石奄 呪 薦廃 呪幻鏑幻 石亀系廃陥.
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

	//header研 石嬢辞 symbol引 description琶球税 index研 達紹生糠稽 背雁 琶球研 達焼 SymbolMap聖 辰錘陥.
	//戚凶 宿瑳 石奄 呪 薦廃 赤生檎 戚 薦廃呪 幻鏑幻 石澗陥.
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

		//己拭 宿瑳, 宿瑳誤 蓄亜.
		SymbolMap.SetAt(strSymbol, strDescription);
		
		//宿瑳 石奄 呪 薦廃 呪幻鏑幻 石亀系廃陥.
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

	//header研 石嬢辞 symbol引 description琶球税 index研 達紹生糠稽 背雁 琶球研 達焼 SymbolMap聖 辰錘陥.
	//戚凶 宿瑳 石奄 呪 薦廃 赤生檎 戚 薦廃呪 幻鏑幻 石澗陥.
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

		//己拭 宿瑳, 宿瑳誤 蓄亜.
		SymbolMap.SetAt(strSymbol, strDescription);
		
		//宿瑳 石奄 呪 薦廃 呪幻鏑幻 石亀系廃陥.
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

	//header研 石嬢辞 symbol引 description琶球税 index研 達紹生糠稽 背雁 琶球研 達焼 SymbolMap聖 辰錘陥.
	//戚凶 宿瑳 石奄 呪 薦廃 赤生檎 戚 薦廃呪 幻鏑幻 石澗陥.
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

		//m_strFileName拭 魚献 TS 亜舌宿瑳 薦暗.
//		if (m_strFilePath.Find("future") > -1 || m_strFilePath.Find("option") > -1) 
		{
			if (strSymbol.GetLength() != 8)
				continue;
			if (strSymbol.Left(3) != "101" && strSymbol.Left(3) != "201" && strSymbol.Left(3) != "301")
				continue;
		}

		//昔今什闘裾嬢 識弘/辛芝 坪球研 疑採坪球拭 限秩陥.
		if ((m_strFilePath.Find("future") > -1 || m_strFilePath.Find("option") > -1) && strSymbol.GetLength() == 8) {
			//ししし澗 識弘坪球拭 楳紫亜研 細戚走 省生糠稽.. 辛芝拭幻 楳紫亜研 細昔陥.
// 			if (strSymbol.Left(3) == "101")
// 				temp = strSymbol.Left(5);
// 			else
// 				temp = strSymbol;
// 
//			strSymbol = temp;
		}

		//己拭 宿瑳, 宿瑳誤 蓄亜.
		SymbolMap.SetAt(strSymbol, strDescription);
		
		//宿瑳 石奄 呪 薦廃 呪幻鏑幻 石亀系廃陥.
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

	//header研 石嬢辞 symbol引 description琶球税 index研 達紹生糠稽 背雁 琶球研 達焼 SymbolMap聖 辰錘陥.
	//戚凶 宿瑳 石奄 呪 薦廃 赤生檎 戚 薦廃呪 幻鏑幻 石澗陥.
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

		//m_strFileName拭 魚献 TS 亜舌宿瑳 薦暗.
//		if (m_strFilePath.Find("future") > -1 || m_strFilePath.Find("option") > -1) 
		{
			if (strSymbol.GetLength() != 8)
				continue;
			if (strSymbol.Left(3) != "101" && strSymbol.Left(3) != "201" && strSymbol.Left(3) != "301")
				continue;
		}

		//昔今什闘裾嬢 識弘/辛芝 坪球研 疑採坪球拭 限秩陥.
		if ((m_strFilePath.Find("future") > -1 || m_strFilePath.Find("option") > -1) && strSymbol.GetLength() == 8) {
			//ししし澗 識弘坪球拭 楳紫亜研 細戚走 省生糠稽.. 辛芝拭幻 楳紫亜研 細昔陥.
// 			if (strSymbol.Left(3) == "101")
// 				temp = strSymbol.Left(5);
// 			else
// 				temp = strSymbol;
// 
//			strSymbol = temp;
		}

		//己拭 宿瑳, 宿瑳誤 蓄亜.
		SymbolMap.SetAt(strSymbol, strDescription);
		
		//宿瑳 石奄 呪 薦廃 呪幻鏑幻 石亀系廃陥.
		if ((nLoadCnt > 0) && (++nCurCnt >= nLoadCnt)) {
			break;
		}
	}
	
	fclose(fp);

	return TRUE;
}

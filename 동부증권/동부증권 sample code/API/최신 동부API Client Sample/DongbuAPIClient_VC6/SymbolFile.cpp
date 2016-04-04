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

//�ɺ����Ϸκ��� �ɺ��ڵ�/�ɺ��� ���� �ε�.
BOOL CSymbolFile::LoadSymbol(CMapStringToString &SymbolMap, int nLoadCnt)
{
	FILE *fp = fopen(m_strFilePath, "r+t");

	if (fp == NULL) return FALSE;

	CString temp, strSymbol, strDescription;
	char buffer[1024];
	int nIndexSymbol = -1, nIndexDescription = -1, nIndex;

	//header �б�. header���� ";"�� �����ڷ� "Symbol", "Description"�ʵ��� index�� ��´�.
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

	//header�� �о symbol�� description�ʵ��� index�� ã�����Ƿ� �ش� �ʵ带 ã�� SymbolMap�� ä���.
	//�̶� �ɺ� �б� �� ���� ������ �� ���Ѽ� ��ŭ�� �д´�.
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

		//m_strFileName�� ���� TS ����ɺ� ����.
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

		//�κ���Ʈ���� ����/�ɼ� �ڵ带 �����ڵ忡 �����.
		if ((m_strFilePath.Find("future") > -1 || m_strFilePath.Find("option") > -1) && strSymbol.GetLength() == 8) {
			//�������� �����ڵ忡 ��簡�� ������ �����Ƿ�.. �ɼǿ��� ��簡�� ���δ�.
// 			if (strSymbol.Left(3) == "101")
// 				temp = strSymbol.Left(5);
// 			else
// 				temp = strSymbol;
// 
//			strSymbol = temp;
		}

		//�ʿ� �ɺ�, �ɺ��� �߰�.
		SymbolMap.SetAt(strSymbol, strDescription);
		
		//�ɺ� �б� �� ���� ����ŭ�� �е����Ѵ�.
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

	//header�� �о symbol�� description�ʵ��� index�� ã�����Ƿ� �ش� �ʵ带 ã�� SymbolMap�� ä���.
	//�̶� �ɺ� �б� �� ���� ������ �� ���Ѽ� ��ŭ�� �д´�.
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

		//�ʿ� �ɺ�, �ɺ��� �߰�.
		SymbolMap.SetAt(strSymbol, strDescription);
		
		//�ɺ� �б� �� ���� ����ŭ�� �е����Ѵ�.
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

	//header�� �о symbol�� description�ʵ��� index�� ã�����Ƿ� �ش� �ʵ带 ã�� SymbolMap�� ä���.
	//�̶� �ɺ� �б� �� ���� ������ �� ���Ѽ� ��ŭ�� �д´�.
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

		//�ʿ� �ɺ�, �ɺ��� �߰�.
		SymbolMap.SetAt(strSymbol, strDescription);
		
		//�ɺ� �б� �� ���� ����ŭ�� �е����Ѵ�.
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

	//header�� �о symbol�� description�ʵ��� index�� ã�����Ƿ� �ش� �ʵ带 ã�� SymbolMap�� ä���.
	//�̶� �ɺ� �б� �� ���� ������ �� ���Ѽ� ��ŭ�� �д´�.
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

		//m_strFileName�� ���� TS ����ɺ� ����.
//		if (m_strFilePath.Find("future") > -1 || m_strFilePath.Find("option") > -1) 
		{
			if (strSymbol.GetLength() != 8)
				continue;
			if (strSymbol.Left(3) != "101" && strSymbol.Left(3) != "201" && strSymbol.Left(3) != "301")
				continue;
		}

		//�κ���Ʈ���� ����/�ɼ� �ڵ带 �����ڵ忡 �����.
		if ((m_strFilePath.Find("future") > -1 || m_strFilePath.Find("option") > -1) && strSymbol.GetLength() == 8) {
			//�������� �����ڵ忡 ��簡�� ������ �����Ƿ�.. �ɼǿ��� ��簡�� ���δ�.
// 			if (strSymbol.Left(3) == "101")
// 				temp = strSymbol.Left(5);
// 			else
// 				temp = strSymbol;
// 
//			strSymbol = temp;
		}

		//�ʿ� �ɺ�, �ɺ��� �߰�.
		SymbolMap.SetAt(strSymbol, strDescription);
		
		//�ɺ� �б� �� ���� ����ŭ�� �е����Ѵ�.
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

	//header�� �о symbol�� description�ʵ��� index�� ã�����Ƿ� �ش� �ʵ带 ã�� SymbolMap�� ä���.
	//�̶� �ɺ� �б� �� ���� ������ �� ���Ѽ� ��ŭ�� �д´�.
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

		//m_strFileName�� ���� TS ����ɺ� ����.
//		if (m_strFilePath.Find("future") > -1 || m_strFilePath.Find("option") > -1) 
		{
			if (strSymbol.GetLength() != 8)
				continue;
			if (strSymbol.Left(3) != "101" && strSymbol.Left(3) != "201" && strSymbol.Left(3) != "301")
				continue;
		}

		//�κ���Ʈ���� ����/�ɼ� �ڵ带 �����ڵ忡 �����.
		if ((m_strFilePath.Find("future") > -1 || m_strFilePath.Find("option") > -1) && strSymbol.GetLength() == 8) {
			//�������� �����ڵ忡 ��簡�� ������ �����Ƿ�.. �ɼǿ��� ��簡�� ���δ�.
// 			if (strSymbol.Left(3) == "101")
// 				temp = strSymbol.Left(5);
// 			else
// 				temp = strSymbol;
// 
//			strSymbol = temp;
		}

		//�ʿ� �ɺ�, �ɺ��� �߰�.
		SymbolMap.SetAt(strSymbol, strDescription);
		
		//�ɺ� �б� �� ���� ����ŭ�� �е����Ѵ�.
		if ((nLoadCnt > 0) && (++nCurCnt >= nLoadCnt)) {
			break;
		}
	}
	
	fclose(fp);

	return TRUE;
}

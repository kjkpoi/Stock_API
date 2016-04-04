#include "stdafx.h"
#include "../DongbuAPIClient_VC.h"
#include "globalAuto.h"

#include "MasterDataSub.h"
#include <math.h>
#include "../SymbolFile.h"

void GetDir_DrfnRoot(CString &strRet)
{
	strRet = "C:\\���������ֹ�����" ;
}

void CopyString(char *pDest, int nDest, const char *pSrc)
{
	//memset(pDest, 0x00, nDest);
	memset(pDest, 0x20, nDest);
	memcpy(pDest, pSrc, min(nDest, strlen(pSrc)));
}

CString GetString(char *p, int n)
{
	CString strRet(p, min(strlen(p), n));
	return strRet.Trim();
}

long GetLong(char *p, int n)
{
	return atol(GetString(p, n));
}

void SetLong(char *pDest, int nDest, int nVal)
{
	CString strTemp;
	strTemp.Format("%d", nVal);
	
	memset(pDest, 0x00, nDest);
	memcpy(pDest, strTemp, min(nDest, strTemp.GetLength()));
}

void TraceLog(LPCTSTR szMsg, ...)
{
#ifndef _DEBUG
	return;
#endif

	::CreateDirectory("C:\\���������ֹ�����_logs",NULL);
	CTime tm = CTime::GetCurrentTime();

	CString	strLog;
	va_list args;

	va_start(args, szMsg);
	strLog.FormatV(szMsg, args);
	strLog = tm.Format("[%H:%M:%S] ") + strLog;

	CString strPath = "C:\\���������ֹ�����_logs\logs\\MR_TraceLog_" + tm.Format("%y%m%d") + ".log";
	FILE *fp = fopen(strPath, "a+");
	if (fp == NULL)
		return;

	fwrite(strLog, sizeof(char), strLog.GetLength(), fp);

	fflush(fp);
	fclose(fp);
}

long GetArgs(CString strString, CStringArray &arrStr, TCHAR chDel)
{
	int nPos;
	int nOldPos = 0;
	CString strTemp;
	while ( (nPos = strString.Find(chDel, nOldPos)) > 0 ) {
		strTemp = strString.Mid(nOldPos, (nPos - nOldPos));
//		strTemp.TrimLeft();
//		strTemp.TrimRight();
		if (!strTemp.IsEmpty()) arrStr.Add(strTemp);
		nOldPos = nPos + 1;
	}
	if (nOldPos != strString.GetLength()) {
		arrStr.Add(strString.Mid(nOldPos));
	}
	return arrStr.GetSize();
}

void TRACEP(CString strCode, CString sMessage)
{
	HWND hWnd = ::FindWindow(NULL, _T("pyTrace"));
	if (hWnd) 
	{ 
		struct TRACEMSG {
			char    m_szMsg[256];
			long    m_lCode;
		} Data;

		COPYDATASTRUCT cData;
		//ICatForm	*pForm = VMOBJ->GetCatForm();
		//CString strCode = pForm->GetFormCode();
		memset(&Data, 0x00, sizeof(TRACEMSG));

		strcpy(Data.m_szMsg, sMessage);
		Data.m_lCode = atol(strCode);

		cData.cbData = sizeof(TRACEMSG);
		cData.dwData = 1000;
		cData.lpData = (PVOID)&Data;
		::SendMessage(hWnd, WM_COPYDATA, 0, (LPARAM)&cData);
	}

}

void InsertComma(CString & str1)
{
	CString str,strTemp1,strTemp2,strTemp3;
	str = str1;
	//��ȣ ó��.
	if(str.GetLength() > 0)
	{
		if(str.GetAt(0) == '-' || str.GetAt(0) == '+')
		{
			strTemp1 = str.Left(1);
			str = str.Mid(1);//��ȣ������ ���ڿ�.
		}
	}

	int pos ;
	int x,y,i;
	//�Ҽ��� �κ��� �����Ѵ�.
	if((pos = str.Find(".")) != -1)
	{
		strTemp3 = str.Mid(pos);//�Ҽ������� ���ϰ��� ������ �ִ� ����.
		str = str.Left(pos);//�Ҽ��� ���� ������ ������ �ִ�.
	}
	//���ڿ��� ���̸� ���Ѵ�.
	int nLength = str.GetLength();
	int max;//�޸��� �ִ밹��

	//���� 3�ڸ� �̻��� ���� ���.
	if((x = nLength / 3) > 0)//��->x
	{
		if((y = nLength % 3) > 0) //��Ȯ�� ������ �������� ���� ��.
			max = x;
		else if(y == 0)
			max = x-1;

		for(i = 0 ; i < max ; i++)//������ �޸��� �����ϴ� �κ�.
		{
			if((pos = str.Find(','))== -1)//�޸��� ���ڿ��� ���� ���.
			{
				str = str.Left(nLength-3)+","+str.Mid(nLength-3);					
			}
			else
			{
				str = str.Left(pos-3)+","+str.Mid(pos-3);					
			}
		}
		str1 = strTemp1 + str + strTemp3;		
	}
}

BOOL IsSame(double d1, double d2)
{
	if (fabs(d1 - d2) < 0.0001)
		return TRUE;

	return FALSE;
}

BOOL IsGreater(double d1, double d2)
{
	if (IsSame(d1, d2))
		return FALSE;

	return (d1 > d2);		
}

BOOL IsLess(double d1, double d2)
{
	if (IsSame(d1, d2))
		return FALSE;

	return (d1 < d2);
}


void DefMessageBox(HWND hWnd, CString strMsg, CString strCaption)
{
	if (hWnd)
	{
		::MessageBox(hWnd, strMsg, strCaption, MB_OK);
	}
}

void LoadSymbols ()
{
	CSymbolFile(theApp.g_strRoot + "\\Data\\Master\\JMaster.dat").LoadSymbolStock(theApp.gKospi_Map);
	CSymbolFile(theApp.g_strRoot + "\\Data\\Master\\KMaster.dat").LoadSymbolKosdaq(theApp.gKosdaq_Map);
}

void ReleaseSymbols ()
{
	theApp.gKospi_Map.RemoveAll() ;
	theApp.gKosdaq_Map.RemoveAll() ;
}

BOOL FindSymbolList(CMapStringToString *pMapString, CString szCodee)
{
	BOOL bFound = FALSE ;
	CString strKey, strValue;

	for (POSITION pos = pMapString->GetStartPosition(); pos != NULL; ) 
	{
		pMapString->GetNextAssoc(pos, strKey, strValue);

		if ( szCodee == strKey)
		{
			bFound = TRUE ;
			break ;
		}
	}
	return bFound ;
}


int GetMarketType ( CString strCode )
{	

	BOOL bRet = FindSymbolList (&theApp.gKospi_Map, strCode ) ;
	if ( bRet  )
	{
		return CDRCodeTypeInfo::DRCODETYPE_KOSPI_STOCK;
	}
	
	bRet = FindSymbolList (&theApp.gKosdaq_Map, strCode ) ;
	if ( bRet )
	{
		return CDRCodeTypeInfo::DRCODETYPE_KOSDAQ_STOCK;
	}

	return CDRCodeTypeInfo::DRCODETYPE_UNKNOWN;

	
}


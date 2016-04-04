#include "stdafx.h"
#include "DataParser.h"


CDataParser::CDataParser()
{
	HRESULT hr = CoInitialize(NULL);
	if (SUCCEEDED(hr))
	{
		hr = m_pXmlDoc.CreateInstance(__uuidof(XDocument));
		if (SUCCEEDED(hr))
		{
			m_pXmlDoc->async = VARIANT_FALSE;
			m_pXmlDoc->validateOnParse = VARIANT_TRUE;
			m_pXmlDoc->resolveExternals = VARIANT_TRUE;
		}
	}
}

CDataParser::~CDataParser()
{
	CoUninitialize();
}

BOOL CDataParser::ReadXml(CString strPath)
{
	BOOL bRet = FALSE;
	CString strErrMsg;

	if (m_pXmlDoc)
	{
		m_pXmlDoc->load((LPCTSTR)strPath);

		XParseErrorPtr pErr = m_pXmlDoc->parseError; // get last error
		if (pErr->errorCode == S_OK)
			bRet = TRUE;
		else
			strErrMsg.Format("%s (%s - %dline)", (LPCTSTR)pErr->Getreason(), (LPCTSTR)pErr->GetsrcText(), pErr->Getline());			

		pErr.Release();
	}
	
	return bRet;
}

XElementPtr	CDataParser::GetRoot()
{
	if (m_pXmlDoc)
		return m_pXmlDoc->documentElement;

	return NULL;
}


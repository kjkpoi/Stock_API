
#pragma once

#import "msxml3.dll"
using namespace MSXML2;

#ifndef _XMLTYPE_DEFINE
#define _XMLTYPE_DEFINE
	typedef MSXML2::DOMDocument				XDocument;
	typedef MSXML2::IXMLDOMDocumentPtr		XDocumentPtr;
	typedef MSXML2::IXMLDOMParseErrorPtr		XParseErrorPtr;
	typedef MSXML2::IXMLDOMElementPtr		XElementPtr;
	typedef MSXML2::IXMLDOMNodePtr			XNodePtr;
	typedef MSXML2::IXMLDOMNamedNodeMapPtr	XNamedNodeMapPtr;
#endif

class CCtrl
{
public:
	CString		m_strMapType; // -101, -102...
	
	CString 	m_strId; // key
	
	CMapStringToString		m_mapCtrlKeyVal;
};

class CCtrlGroup
{
public:
	
	CMapStringToString		m_mapGrpKeyVal;

	CMap<CString, LPCTSTR, CCtrl *, CCtrl *>	m_mapCtrl; // CCtrl::m_strID 를 키로하는 CCtrl 리스트
};

class CDataParser
{
protected:
	XDocumentPtr		m_pXmlDoc;

public:
	CDataParser();
	~CDataParser();

public:
	BOOL		ReadXml(CString strPath);
	XElementPtr	GetRoot();
};

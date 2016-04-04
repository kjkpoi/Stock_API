
// DongbuAPIClient_VCDoc.cpp : CDongbuAPIClient_VCDoc 클래스의 구현
//

#include "stdafx.h"
#include "DongbuAPIClient_VC.h"

#include "DongbuAPIClient_VCDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDongbuAPIClient_VCDoc

IMPLEMENT_DYNCREATE(CDongbuAPIClient_VCDoc, CDocument)

BEGIN_MESSAGE_MAP(CDongbuAPIClient_VCDoc, CDocument)
END_MESSAGE_MAP()


// CDongbuAPIClient_VCDoc 생성/소멸

CDongbuAPIClient_VCDoc::CDongbuAPIClient_VCDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CDongbuAPIClient_VCDoc::~CDongbuAPIClient_VCDoc()
{
}

BOOL CDongbuAPIClient_VCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CDongbuAPIClient_VCDoc serialization

void CDongbuAPIClient_VCDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}


// CDongbuAPIClient_VCDoc 진단

#ifdef _DEBUG
void CDongbuAPIClient_VCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDongbuAPIClient_VCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDongbuAPIClient_VCDoc 명령

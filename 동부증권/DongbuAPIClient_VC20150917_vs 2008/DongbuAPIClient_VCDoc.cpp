
// DongbuAPIClient_VCDoc.cpp : CDongbuAPIClient_VCDoc Ŭ������ ����
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


// CDongbuAPIClient_VCDoc ����/�Ҹ�

CDongbuAPIClient_VCDoc::CDongbuAPIClient_VCDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CDongbuAPIClient_VCDoc::~CDongbuAPIClient_VCDoc()
{
}

BOOL CDongbuAPIClient_VCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CDongbuAPIClient_VCDoc serialization

void CDongbuAPIClient_VCDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}


// CDongbuAPIClient_VCDoc ����

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


// CDongbuAPIClient_VCDoc ���

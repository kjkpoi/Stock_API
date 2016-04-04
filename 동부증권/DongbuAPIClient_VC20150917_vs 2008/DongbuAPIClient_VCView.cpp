
// DongbuAPIClient_VCView.cpp : CDongbuAPIClient_VCView Ŭ������ ����
//

#include "stdafx.h"
#include "DongbuAPIClient_VC.h"

#include "DongbuAPIClient_VCDoc.h"
#include "DongbuAPIClient_VCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDongbuAPIClient_VCView

IMPLEMENT_DYNCREATE(CDongbuAPIClient_VCView, CView)

BEGIN_MESSAGE_MAP(CDongbuAPIClient_VCView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDongbuAPIClient_VCView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDongbuAPIClient_VCView ����/�Ҹ�

CDongbuAPIClient_VCView::CDongbuAPIClient_VCView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CDongbuAPIClient_VCView::~CDongbuAPIClient_VCView()
{
}

BOOL CDongbuAPIClient_VCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CDongbuAPIClient_VCView �׸���

void CDongbuAPIClient_VCView::OnDraw(CDC* /*pDC*/)
{
	CDongbuAPIClient_VCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CDongbuAPIClient_VCView �μ�


void CDongbuAPIClient_VCView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CDongbuAPIClient_VCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CDongbuAPIClient_VCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CDongbuAPIClient_VCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CDongbuAPIClient_VCView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	//OnContextMenu(this, point);
}

/*
void CDongbuAPIClient_VCView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}
*/


// CDongbuAPIClient_VCView ����

#ifdef _DEBUG
void CDongbuAPIClient_VCView::AssertValid() const
{
	CView::AssertValid();
}

void CDongbuAPIClient_VCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDongbuAPIClient_VCDoc* CDongbuAPIClient_VCView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDongbuAPIClient_VCDoc)));
	return (CDongbuAPIClient_VCDoc*)m_pDocument;
}
#endif //_DEBUG


// CDongbuAPIClient_VCView �޽��� ó����

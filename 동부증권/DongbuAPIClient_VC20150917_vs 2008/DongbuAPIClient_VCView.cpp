
// DongbuAPIClient_VCView.cpp : CDongbuAPIClient_VCView 클래스의 구현
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDongbuAPIClient_VCView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDongbuAPIClient_VCView 생성/소멸

CDongbuAPIClient_VCView::CDongbuAPIClient_VCView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CDongbuAPIClient_VCView::~CDongbuAPIClient_VCView()
{
}

BOOL CDongbuAPIClient_VCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CDongbuAPIClient_VCView 그리기

void CDongbuAPIClient_VCView::OnDraw(CDC* /*pDC*/)
{
	CDongbuAPIClient_VCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CDongbuAPIClient_VCView 인쇄


void CDongbuAPIClient_VCView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CDongbuAPIClient_VCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CDongbuAPIClient_VCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CDongbuAPIClient_VCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
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


// CDongbuAPIClient_VCView 진단

#ifdef _DEBUG
void CDongbuAPIClient_VCView::AssertValid() const
{
	CView::AssertValid();
}

void CDongbuAPIClient_VCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDongbuAPIClient_VCDoc* CDongbuAPIClient_VCView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDongbuAPIClient_VCDoc)));
	return (CDongbuAPIClient_VCDoc*)m_pDocument;
}
#endif //_DEBUG


// CDongbuAPIClient_VCView 메시지 처리기

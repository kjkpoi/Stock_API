
// DongbuAPIClient_VCView.h : CDongbuAPIClient_VCView 클래스의 인터페이스
//


#pragma once


class CDongbuAPIClient_VCView : public CView
{
protected: // serialization에서만 만들어집니다.
	CDongbuAPIClient_VCView();
	DECLARE_DYNCREATE(CDongbuAPIClient_VCView)

// 특성입니다.
public:
	CDongbuAPIClient_VCDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CDongbuAPIClient_VCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // DongbuAPIClient_VCView.cpp의 디버그 버전
inline CDongbuAPIClient_VCDoc* CDongbuAPIClient_VCView::GetDocument() const
   { return reinterpret_cast<CDongbuAPIClient_VCDoc*>(m_pDocument); }
#endif


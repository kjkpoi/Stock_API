
// DongbuAPIClient_VCView.h : CDongbuAPIClient_VCView Ŭ������ �������̽�
//


#pragma once


class CDongbuAPIClient_VCView : public CView
{
protected: // serialization������ ��������ϴ�.
	CDongbuAPIClient_VCView();
	DECLARE_DYNCREATE(CDongbuAPIClient_VCView)

// Ư���Դϴ�.
public:
	CDongbuAPIClient_VCDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CDongbuAPIClient_VCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // DongbuAPIClient_VCView.cpp�� ����� ����
inline CDongbuAPIClient_VCDoc* CDongbuAPIClient_VCView::GetDocument() const
   { return reinterpret_cast<CDongbuAPIClient_VCDoc*>(m_pDocument); }
#endif



// DongbuAPIClient_VCDoc.h : CDongbuAPIClient_VCDoc Ŭ������ �������̽�
//


#pragma once


class CDongbuAPIClient_VCDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CDongbuAPIClient_VCDoc();
	DECLARE_DYNCREATE(CDongbuAPIClient_VCDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// �����Դϴ�.
public:
	virtual ~CDongbuAPIClient_VCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};



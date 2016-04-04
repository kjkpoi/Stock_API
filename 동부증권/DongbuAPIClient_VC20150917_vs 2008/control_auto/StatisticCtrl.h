#pragma once

//#include "PieChart.h"
#include "DrEdit.h"
#include "NumSpinCtrl.h"
#include "../OrdBase.h"

typedef struct stCellInof
{
	int			nRow;
	int			nCol;
	int			nHeight;
	int			nWidth;
	int			nBarWidth;
	CString		strText;
	COLORREF	crBack;
	COLORREF	crText;
	CRect		rcCell;
	int			nType;
	DWORD		dwAlign;
	BOOL		bShow;
}CELLINFO;

typedef CArray<CELLINFO *, CELLINFO *>		ArrCellInfo;

#define NORMAL_TABLE_HEIGHT		22
#define KOSPI_TABLE_HEIGHT		NORMAL_TABLE_HEIGHT * 2

#define TABLE_BORDER_COLOR		RGB(0, 0, 0)
#define TABEL_CELL_TEXTCOLOR	RGB(0, 0, 0)
#define TABEL_CELL_BKCOLOR		RGB(255, 255, 255)
#define TABLE_LINE_COLOR		RGB(192, 192, 192)
#define TABLE_UP_COLOR			RGB(255, 0, 0)
#define TABLE_DOWN_COLOR		RGB(0, 0, 255)

// CStatisticCtrl

class CStatisticCtrl : public CWnd
{
	DECLARE_DYNAMIC(CStatisticCtrl)

public:
	CStatisticCtrl();
	virtual ~CStatisticCtrl();

	BOOL CreateWnd(CWnd * pParent, int nID);
	BOOL RegisterWndClass(HINSTANCE hInstance);

	void InitNormalTable();
	void InitKospiTable();
	void InitDivValue();

	void DrawContents(CDC* pDC);
	void DrawTable(CDC* pDC, CRect& rcTable, ArrCellInfo& arrCellInfo, int nCols);
	void DrawCellData(CDC* pDC, CELLINFO& cell);
	void DrawTextInRect(CDC* pDC, LPCTSTR lpText, CRect rcDraw, COLORREF clBkColr, DWORD dwAlign);
	void DrawUpDownBar(CDC* pDC, CRect rcBar);
	CELLINFO* GetCellInfo(ArrCellInfo& arrCellInfos, int nRow, int nCol);
	void SetStatisticData(STATICSTIC& stStatisticData);
	void AddToolInfo(CRect& rcBar);
	void ResizeCtrl();
	void SetRowCount(int nRow); 
	void SetDivType(int nType);
	void SetHogaStartIndex(int nIndex) {m_nHogaStartIndex = nIndex;};
	void SetStandardPrice(int nSel);
	void SetBarType(int nType) {m_nBarType = nType;};
	void SetHogaOrTimeDiv(enORDTYPE nDivType, int nDivUint);
	CStringArray* GetDivQtyValue();
	void SetDivQtyValue(CStringArray* psaQtyValue);

	void		  CheckRateAndSet(HWND hCtrl);
	CNumSpinCtrl* GetBuddySpinCtrl(HWND hWnd);
	int		  	  GetSumOtherRate(HWND hWnd);

	// 20120723 ssj - 서버자동주문 >>
	CStringArray *GetDivQtyRate();
	void	ShowComment(BOOL bShowComment, BOOL bInavlidate = FALSE)
	{
		m_bShowComment = bShowComment;
		if (bInavlidate)
			Invalidate();
	}
	// 20120723 ssj - 서버자동주문 <<

protected:
	// 20120723 ssj - 서버자동주문 >>
	BOOL			m_bShowComment;
	// 20120723 ssj - 서버자동주문 <<

	COLORREF		m_clrBk;
	CBrush			m_brushBk;
	COrdMinSet		m_OrdMinset;
	int				m_nDivType;	//nType 0:정마름모 1:사각형 2:역마름모
	int				m_nLastRow;	//그리드 Row
	ArrCellInfo		m_arrNormal;
	CRect			m_rcNormal;

//	CPieChart		m_PieChart;
	CStringArray	m_arrUpDown;
	CFont m_Font;
	CToolTipCtrl	m_ToolTipCtrl;

	CDrEdit			m_EditVolume1;
	CDrEdit			m_EditVolume2;
	CDrEdit			m_EditVolume3;
	CDrEdit			m_EditVolume4;
	CDrEdit			m_EditVolume5;

	CStringArray	m_sarrHogaText;
	int				m_nHogaStartIndex;

	int				m_nBarType;
	enORDTYPE		m_nFlagHogaOrTimeDiv;	//일반,호가,시간분할
	int				m_nDivUint;				//기준단위
	int				m_nDivArrow;			//분할방향 0:아래 1:위로

	CRect			m_rectBar;
	BOOL			m_bVolLimit;

public:
	CDrEdit			m_EditRate1;
	CNumSpinCtrl	m_SpinRate1;

	CDrEdit			m_EditRate2;
	CNumSpinCtrl	m_SpinRate2;

	CDrEdit			m_EditRate3;
	CNumSpinCtrl	m_SpinRate3;

	CDrEdit			m_EditRate4;
	CNumSpinCtrl	m_SpinRate4;

	CDrEdit			m_EditRate5;
	CNumSpinCtrl	m_SpinRate5;


public:
	void SetVolLimit(BOOL bLimit) {m_bVolLimit = bLimit;};
	void SetBaseInfo(COrdMinSet& cOrdMinsetOrigin);
	void CalcVolume();
	void SetDivWay(int nType) {m_nDivArrow = nType;};
	void ChangeSkinColor(long lpColor);
	void InsertComma(CString & str1);
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);

	afx_msg void OnChangeRateSpin(UINT nID, NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};



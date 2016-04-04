// StatisticCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "StatisticCtrl.h"
#include "../resource.h"

#include <math.h>

// 20120723 ssj - 서버자동주문 >>
#include "../include_auto/globalauto.h"
#include "../OrderTypeWnd.h"
// 20120723 ssj - 서버자동주문 <<

// CStatisticCtrl
const double pi = 3.1415926535;
const COLORREF crText	  = RGB(255, 255, 255);
const COLORREF crStrongUp = RGB(192, 0, 0);
const COLORREF crNormalUp = RGB(254, 0, 0);
const COLORREF crSoftUp   = RGB(255, 192, 0);
const COLORREF crSoftDown = RGB(145, 211, 245);
const COLORREF crNormalDown = RGB(114, 184, 254);
const COLORREF crStrongDown = RGB(0, 113, 193);

const COLORREF crGreen = RGB(0, 176, 80);

const LPCTSTR szColName[] = {_T("주문가격"), _T("구성비율"), _T("주문수량")};

IMPLEMENT_DYNAMIC(CStatisticCtrl, CWnd)

CStatisticCtrl::CStatisticCtrl()
{
	RegisterWndClass(AfxGetApp()->m_hInstance);

	LOGFONT	  stFont;
	GETFONT(stFont, 12, 400, m_Font);

	m_nLastRow = 5;
	m_nDivType = 0;	
	m_nFlagHogaOrTimeDiv = HOGADIV_ORDER;
	m_nDivArrow = 0;

	m_clrBk = RGB(255, 255, 255);
	m_brushBk.CreateSolidBrush(m_clrBk);
	m_bVolLimit = FALSE;

	// 20120723 ssj - 서버자동주문 >>
	m_bShowComment = FALSE;
	// 20120723 ssj - 서버자동주문 <<
}

CStatisticCtrl::~CStatisticCtrl()
{
	m_brushBk.DeleteObject();
}

BOOL CStatisticCtrl::CreateWnd(CWnd * pParent, int nID)
{
	DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS /*| WS_VSCROLL |WS_HSCROLL*/;
	return Create("STATISTIC_CTRL", NULL, dwStyle, CRect(0,0,0,0), pParent, nID);	
}

BOOL CStatisticCtrl::RegisterWndClass(HINSTANCE hInstance)
{
	WNDCLASS wc;
	wc.lpszClassName	= "STATISTIC_CTRL";
	wc.hInstance		= hInstance;
	wc.lpfnWndProc		= ::DefWindowProc;
	wc.hCursor			= ::LoadCursor(NULL,IDC_ARROW);
	wc.hIcon			= 0;
	wc.lpszMenuName		= NULL;	
	wc.hbrBackground	= (HBRUSH)::GetStockObject(WHITE_BRUSH);	
	wc.style			= CS_GLOBALCLASS | CS_DBLCLKS;
	wc.cbClsExtra		= 0;
	wc.cbWndExtra		= sizeof(HWND);

	return (::RegisterClass(&wc) != 0);
}

void CStatisticCtrl::InitNormalTable()
{
	int		nColWidth[] = {100, 60, 80};

	m_rcNormal.SetRectEmpty();
	m_rcNormal.right = 240;
	m_rcNormal.bottom = NORMAL_TABLE_HEIGHT * (m_nLastRow + 1);

	// 20120723 ssj - 서버자동주문 >>
	CRect rtCell = m_rcNormal;
	rtCell.OffsetRect(4, 4);
	CRect rtBase = rtCell;
	rtCell.right = rtCell.left;

	int nCount = m_arrNormal.GetSize();
	int i;
	int nCols = _countof(szColName);
	for(i = 0; i < nCount; ++i)
	{	
		CELLINFO *pCell = m_arrNormal.GetAt(i);
		
		rtCell.top = rtBase.top + pCell->nHeight*pCell->nRow;
		rtCell.right = rtCell.left + pCell->nWidth;
		rtCell.bottom = rtCell.top + pCell->nHeight;
		pCell->rcCell = rtCell;

		if(i > 0 && i% nCols == nCols-1)
			rtCell.left = rtBase.left;
		else
			rtCell.left = rtCell.right;
	}
	ResizeCtrl();
	// 20120723 ssj - 서버자동주문 <<

	int nRow, nCol;
	
	// 20120723 ssj - 서버자동주문 >>
	int nArrSize = m_arrNormal.GetCount();
	for (int i = 0; i < nArrSize; i++)
	{
		CELLINFO *pCell = m_arrNormal.GetAt(i);
		if (pCell)
			delete pCell;
	}
	m_arrNormal.RemoveAll();
	// 20120723 ssj - 서버자동주문 <<

	for(nRow = 0; nRow <= m_nLastRow; ++nRow)
	{
		for(nCol = 0; nCol < _countof(szColName); ++nCol)
		{
			CELLINFO *pCell = new CELLINFO;
			if(0 == nRow)
			{
				pCell->strText = szColName[nCol];
				pCell->crBack = COLOR_GRID_HEADER_FACE;
				pCell->dwAlign = DT_CENTER;
			}
			else
			{
				pCell->strText = "";
				pCell->crBack = TABEL_CELL_BKCOLOR;
				pCell->dwAlign = DT_CENTER;
			}

			pCell->nRow = nRow;
			pCell->nCol = nCol;
			pCell->nHeight = NORMAL_TABLE_HEIGHT;
			pCell->nWidth = nColWidth[nCol];
			pCell->nType = 1;
			pCell->nBarWidth = 0;
			pCell->bShow = TRUE;

			m_arrNormal.Add(pCell);
		}
	}

	CELLINFO* pCell;

	int nIndex, nCellIndex = 1;
	int nStartIndex;
	int nEndIndex;
	if(m_nDivArrow == 1)
	{
		nStartIndex = DIVSTANDARD_INDEX + m_nHogaStartIndex - m_nLastRow + 1;
		nEndIndex   = DIVSTANDARD_INDEX + m_nHogaStartIndex + 1;
	}
	else
	{
		nStartIndex = DIVSTANDARD_INDEX + m_nHogaStartIndex;
		nEndIndex = DIVSTANDARD_INDEX + m_nHogaStartIndex + m_nLastRow;
	}

	
	for(nIndex = nStartIndex; nIndex < nEndIndex; nIndex++)
	{
		pCell = GetCellInfo(m_arrNormal, nCellIndex++, 0);
		if(pCell)
		{
			pCell->strText = m_sarrHogaText.GetAt(nIndex);		
		}
	}

}



void CStatisticCtrl::InitDivValue()
{
	int narrDivRate_2[2];
	int narrDivRate_3[3];
	int narrDivRate_4[4];
	int narrDivRate_5[5];
	//nType 0:정마름모 1:사각형 2:역마름모
	if(m_nDivType == 0)
	{
		narrDivRate_2[0] = 30;
		narrDivRate_2[1] = 70;

		narrDivRate_3[0] = 20;
		narrDivRate_3[1] = 35;
		narrDivRate_3[2] = 45;

		narrDivRate_4[0] = 10;
		narrDivRate_4[1] = 20;
		narrDivRate_4[2] = 30;
		narrDivRate_4[3] = 40;

		narrDivRate_5[0] = 5;
		narrDivRate_5[1] = 10;
		narrDivRate_5[2] = 15;
		narrDivRate_5[3] = 25;
		narrDivRate_5[4] = 45;
	}
	else if(m_nDivType == 1)
	{
		narrDivRate_2[0] = 50;
		narrDivRate_2[1] = 50;

		narrDivRate_3[0] = 35;
		narrDivRate_3[1] = 35;
		narrDivRate_3[2] = 30;

		narrDivRate_4[0] = 25;
		narrDivRate_4[1] = 25;
		narrDivRate_4[2] = 25;
		narrDivRate_4[3] = 25;

		narrDivRate_5[0] = 20;
		narrDivRate_5[1] = 20;
		narrDivRate_5[2] = 20;
		narrDivRate_5[3] = 20;
		narrDivRate_5[4] = 20;		

	}
	else if(m_nDivType == 2)
	{
		narrDivRate_2[0] = 70;
		narrDivRate_2[1] = 30;

		narrDivRate_3[0] = 45;
		narrDivRate_3[1] = 35;
		narrDivRate_3[2] = 20;

		narrDivRate_4[0] = 40;
		narrDivRate_4[1] = 30;
		narrDivRate_4[2] = 20;
		narrDivRate_4[3] = 10;

		narrDivRate_5[0] = 45;
		narrDivRate_5[1] = 25;
		narrDivRate_5[2] = 15;
		narrDivRate_5[3] = 10;
		narrDivRate_5[4] = 5;

	}

	switch(m_nLastRow)
	{
		case 2:
			m_SpinRate1.SetPos(narrDivRate_2[0]);
			m_SpinRate2.SetPos(narrDivRate_2[1]);
			break;
		case 3:
			m_SpinRate1.SetPos(narrDivRate_3[0]);
			m_SpinRate2.SetPos(narrDivRate_3[1]);
			m_SpinRate3.SetPos(narrDivRate_3[2]);
			break;
		case 4:
			m_SpinRate1.SetPos(narrDivRate_4[0]);
			m_SpinRate2.SetPos(narrDivRate_4[1]);
			m_SpinRate3.SetPos(narrDivRate_4[2]);
			m_SpinRate4.SetPos(narrDivRate_4[3]);
			break;
		case 5:
			m_SpinRate1.SetPos(narrDivRate_5[0]);
			m_SpinRate2.SetPos(narrDivRate_5[1]);
			m_SpinRate3.SetPos(narrDivRate_5[2]);
			m_SpinRate4.SetPos(narrDivRate_5[3]);
			m_SpinRate5.SetPos(narrDivRate_5[4]);
			break;
		default:
			break;
	}
}


void CStatisticCtrl::DrawContents(CDC* pDC)
{
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);

	CRect rcClient;
	GetClientRect(rcClient);

	CBitmap memBitmap;
	memBitmap.CreateCompatibleBitmap(pDC, rcClient.Width(), rcClient.Height());

	CBitmap* pOldBitmap = memDC.SelectObject(&memBitmap);
	memDC.FillSolidRect(0, 0, rcClient.Width(), rcClient.Height(), m_clrBk);

	CFont* pOldFont = memDC.SelectObject(&m_Font);
	memDC.SetBkMode(TRANSPARENT);
	
	CPen line;
	line.CreatePen(PS_SOLID, 1, TABLE_LINE_COLOR);
	CPen* pOldPen = memDC.SelectObject(&line);

	CRect rcTemp = m_rcNormal;
	rcTemp.OffsetRect(4, 4);
	DrawTable(&memDC, rcTemp, m_arrNormal, _countof(szColName));
	memDC.Draw3dRect(rcTemp, COLOR_BORDER, COLOR_BORDER);
	
// 	rcTemp.SetRect(5, 50, 65, 70);
// 	DrawTextInRect(&memDC, _T("거래소"), rcTemp, COLOR_GRID_HEADER_FACE, DT_CENTER);
// 
// 	rcTemp.SetRect(214, 50, 275, 70);
// 	DrawTextInRect(&memDC, _T("코스닥"), rcTemp, COLOR_GRID_HEADER_FACE, DT_CENTER);

// 	rcTemp = m_rcKospi;
// 	rcTemp.OffsetRect(5, 5+30+40);
// 	DrawTable(&memDC, rcTemp, m_arrKospi, 6);
// 	memDC.Draw3dRect(rcTemp, TABLE_BORDER_COLOR, TABLE_BORDER_COLOR);

// 	rcTemp.left	 = 5+420+20;
// 	rcTemp.top	 = 5;
// 	rcTemp.right = rcTemp.left + rcClient.Height() - 30;
// 	rcTemp.bottom= rcTemp.top + rcClient.Height() - 30;

//	m_PieChart.SetChartRect(rcTemp);
//	m_PieChart.OnPaint(&memDC);

	rcTemp.left = rcTemp.right + 2;
	rcTemp.right = rcClient.right - 4;
	

	CRect rtText = rcTemp;
	rtText.bottom = rtText.top + 20;
	// 20120723 ssj - 서버자동주문 >>
	//CString strText = _T("* 참고용 수량 입니다.");
	if (m_bShowComment)
	{
		CString strText = _T("* 참고용 수량 입니다.");
		memDC.DrawText(strText, &rtText, DT_SINGLELINE|DT_VCENTER);
	}
	// 20120723 ssj - 서버자동주문 <<

	rcTemp.top += 20;
// 	AddToolInfo(rcTemp);
	memDC.Draw3dRect(rcTemp, COLOR_BORDER, COLOR_BORDER);
	m_rectBar = rcTemp;
	DrawUpDownBar(&memDC, rcTemp);

	pDC->BitBlt(0, 0, rcClient.Width(), rcClient.Height(), &memDC, 0, 0, SRCCOPY);

	memDC.SelectObject(pOldPen);
	line.DeleteObject();
	memDC.SelectObject(pOldFont);
	memDC.SelectObject(pOldBitmap);
	memBitmap.DeleteObject();
	memDC.DeleteDC();
}

void CStatisticCtrl::DrawTable(CDC* pDC, CRect& rcTable, ArrCellInfo& arrCellInfo, int nCols)
{
	CRect rtCell = rcTable;
	rtCell.right = rtCell.left;

//	CELLINFO cell;
	int nCount = arrCellInfo.GetSize();
	int i;
	for(i = 0; i < nCount; ++i)
	{	
		CELLINFO *pCell = arrCellInfo.GetAt(i);
		
		rtCell.top = rcTable.top + pCell->nHeight*pCell->nRow;
		rtCell.right = rtCell.left + pCell->nWidth;
		rtCell.bottom = rtCell.top + pCell->nHeight;
		pCell->rcCell = rtCell;
		pDC->FillSolidRect(rtCell, pCell->crBack);
		DrawCellData(pDC, *pCell);

		if(0 == pCell->nRow)					// 첫 행
		{
			if(nCols - 1 == pCell->nCol)		// 끝 컬럼
			{
				pDC->MoveTo(rtCell.right-2, rtCell.bottom - 1);
				pDC->LineTo(rtCell.left-1,  rtCell.bottom - 1);
			}
			else
			{
				pDC->MoveTo(rtCell.right-1, rtCell.top+1);
				pDC->LineTo(rtCell.right-1, rtCell.bottom - 1);
				if(0 == pCell->nCol)
					pDC->LineTo(rtCell.left,  rtCell.bottom - 1);
				else
					pDC->LineTo(rtCell.left-1,  rtCell.bottom - 1);
			}
		}
		else if(arrCellInfo.GetSize() / nCols - 1 == pCell->nRow)		// 끝행
		{
			if(nCols - 1 != pCell->nCol)		// 끝 컬럼이 아니면
			{
				pDC->MoveTo(rtCell.right-1, rtCell.top);
				pDC->LineTo(rtCell.right-1, rtCell.bottom - 1);
			}
		}
		else
		{
			if(nCols - 1 == pCell->nCol)		// 끝 컬럼
			{
				pDC->MoveTo(rtCell.right-2, rtCell.bottom - 1);
				pDC->LineTo(rtCell.left-1,  rtCell.bottom - 1);
			}
			else
			{
				pDC->MoveTo(rtCell.right-1, rtCell.top);
				pDC->LineTo(rtCell.right-1, rtCell.bottom - 1);

				if(0 == pCell->nCol)
					pDC->LineTo(rtCell.left,  rtCell.bottom - 1);
				else
					pDC->LineTo(rtCell.left-1,  rtCell.bottom - 1);
			}
		}

		if(i > 0 && i%nCols == nCols-1)
			rtCell.left = rcTable.left;
		else
			rtCell.left = rtCell.right;
	}
}

void CStatisticCtrl::DrawCellData(CDC* pDC, CELLINFO& cell)
{
	CRect rcTemp = cell.rcCell;
	if(1 == cell.nType)
	{
		if(DT_RIGHT == cell.dwAlign)
			rcTemp.right -= 4;

		pDC->DrawText(cell.strText, rcTemp, DT_SINGLELINE | DT_VCENTER | cell.dwAlign);
	}
	else 
	{
		CRect rcBar = cell.rcCell;
		rcBar.InflateRect(0, -5);
		rcBar.right = rcBar.left + cell.nBarWidth;

		if(cell.nCol % 3 == 2 && cell.nRow == 0) 
			pDC->FillSolidRect(rcBar, COLOR_GRID_HEADER_FACE);
		else if(cell.nCol % 3 == 2 && cell.nRow == 1) 
			pDC->FillSolidRect(rcBar, TABLE_UP_COLOR);
		else if(cell.nCol % 3 == 2 && cell.nRow == 2) 
			pDC->FillSolidRect(rcBar, TABLE_DOWN_COLOR);
		else if(cell.nCol % 3 == 2 && cell.nRow == 3) 
		{
			if( 0 <= atof(cell.strText))
				pDC->FillSolidRect(rcBar, TABLE_UP_COLOR);
			else
				pDC->FillSolidRect(rcBar, TABLE_DOWN_COLOR);
		}
	}
}

void CStatisticCtrl::DrawTextInRect(CDC* pDC, LPCTSTR lpText, CRect rcDraw, COLORREF clBkColr, DWORD dwAlign)
{
	pDC->FillSolidRect(rcDraw, clBkColr);
	pDC->DrawText(lpText, rcDraw, DT_SINGLELINE | DT_VCENTER | dwAlign);
	pDC->Draw3dRect(rcDraw, TABLE_LINE_COLOR, TABLE_LINE_COLOR);
}

void CStatisticCtrl::DrawUpDownBar(CDC* pDC, CRect rcBar)
{
	COLORREF crCell[] = {crGreen, crGreen, crGreen, crGreen, crGreen, crGreen};

	CRect rtCell = rcBar;	

	int nWidth = (rcBar.Width() - 6) / 5;//m_nLastRow;
	rtCell.left += 4;
	rtCell.right = rtCell.left + nWidth;
	rtCell.top += 4;
	rtCell.bottom  = rtCell.top + nWidth;

	CString strRate;
	CUIntArray arrRate;

	CDrEdit* pEdit = NULL;
	for(int nIndex = 0; nIndex < m_nLastRow; nIndex++)
	{
		pEdit = (CDrEdit*)GetDlgItem(IDE_RATE1 + nIndex);
		pEdit->GetWindowText(strRate);
		arrRate.Add(atoi(strRate));
	}

	int nX1 = rtCell.left;
	int nY1 = rtCell.top - 2;// + 18;
	int nY2 = nY1 + 18;
	int nX2;

	int nWidthTot = rcBar.Width() - 8;

	for(int nIndex = 0; nIndex < m_nLastRow; nIndex++)
	{
		nX2 = nWidthTot * ((double)arrRate.GetAt(nIndex) / 100);

		pDC->FillSolidRect(nX1, nY1, nX2, 20, crCell[nIndex]);
	//	pDC->Draw3dRect(rtCell, RGB(255, 255, 255), RGB(255, 255, 255));
		nY1 = nY2 + 4;
		nY2 = nY1 + 18;
	}



// 	if(m_nBarType == 1)
// 	{	
// 		int nWidth = (rcBar.Width() - 6) / 5;//m_nLastRow;
// 		rtCell.left += 4;
// 		rtCell.right = rtCell.left + nWidth;
// 		rtCell.top += 4;
// 		rtCell.bottom  = rtCell.top + nWidth;
// 
// 		int i;
// 		for(i = 0; i < m_nLastRow; ++i)
// 		{
// 			pDC->FillSolidRect(rtCell, crCell[i]);
// 			pDC->Draw3dRect(rtCell, RGB(255, 255, 255), RGB(255, 255, 255));
// 			rtCell.OffsetRect(nWidth, 0);	
// 		}
// 	}
// 	else
// 	{
// 		rtCell.top += 2;
// 		rtCell.bottom -= 2;
// 		rtCell.left += 2;
// 		rtCell.right -= 2;
// 
// 		CPoint ptTrapezoid1[4];
// 		CPoint ptTrapezoid2[4];
// 		CPoint ptTrapezoid3[4];
// 		CPoint ptTrapezoid4[4];
// 		CPoint ptTrapezoid5[4];
// 
// 		int nHCenter = rtCell.left + rtCell.Width() / 2;
// 		int nOneHeight = (rtCell.Height() - 24) / m_nLastRow;
// 		int nTop = rtCell.top + ( rtCell.Height() - nOneHeight*m_nLastRow) / m_nLastRow;
// 		int nHGap = 8;
// 
// 		int nStartX = nHCenter - 10;
// 		int nEndX   = nHCenter + 10;
// 		int nIndex;		
// 		//정마름모형
// 		if(m_nBarType == 0)	
// 		{
// 			nIndex = 1;
// 
// 			ptTrapezoid1[0] = CPoint(nStartX, nTop);
// 			ptTrapezoid1[1] = CPoint(nEndX,   nTop);
// 			ptTrapezoid1[2] = CPoint(nEndX   + nHGap*nIndex, nTop + nOneHeight*nIndex);
// 			ptTrapezoid1[3] = CPoint(nStartX - nHGap*nIndex, nTop + nOneHeight*nIndex);
// 
// 
// 			ptTrapezoid2[0] = CPoint(nStartX - nHGap*nIndex, nTop + nOneHeight*nIndex + 2);
// 			ptTrapezoid2[1] = CPoint(nEndX   + nHGap*nIndex, nTop + nOneHeight*nIndex + 2);
// 			nIndex++;
// 			nOneHeight++;
// 			ptTrapezoid2[2] = CPoint(nEndX   + nHGap*nIndex, nTop + nOneHeight*nIndex);
// 			ptTrapezoid2[3] = CPoint(nStartX - nHGap*nIndex, nTop + nOneHeight*nIndex);
// 
// 			ptTrapezoid3[0] = CPoint(nStartX - nHGap*nIndex, nTop + nOneHeight*nIndex + 2);
// 			ptTrapezoid3[1] = CPoint(nEndX   + nHGap*nIndex, nTop + nOneHeight*nIndex + 2);
// 			nIndex++;
// 			nOneHeight++;
// 			ptTrapezoid3[2] = CPoint(nEndX   + nHGap*nIndex, nTop + nOneHeight*nIndex);
// 			ptTrapezoid3[3] = CPoint(nStartX - nHGap*nIndex, nTop + nOneHeight*nIndex);
// 
// 			ptTrapezoid4[0] = CPoint(nStartX - nHGap*nIndex, nTop + nOneHeight*nIndex + 2);
// 			ptTrapezoid4[1] = CPoint(nEndX   + nHGap*nIndex, nTop + nOneHeight*nIndex + 2);
// 			nIndex++;
// 			nOneHeight++;
// 			ptTrapezoid4[2] = CPoint(nEndX   + nHGap*nIndex, nTop + nOneHeight*nIndex);
// 			ptTrapezoid4[3] = CPoint(nStartX - nHGap*nIndex, nTop + nOneHeight*nIndex);
// 
// 			ptTrapezoid5[0] = CPoint(nStartX - nHGap*nIndex, nTop + nOneHeight*nIndex + 2);
// 			ptTrapezoid5[1] = CPoint(nEndX   + nHGap*nIndex, nTop + nOneHeight*nIndex + 2);
// 			nIndex++;
// 			nOneHeight++;
// 			ptTrapezoid5[2] = CPoint(nEndX   + nHGap*nIndex, nTop + nOneHeight*nIndex);
// 			ptTrapezoid5[3] = CPoint(nStartX - nHGap*nIndex, nTop + nOneHeight*nIndex);
// 			
// 		}
// 		//역마름모형
// 		else if(m_nBarType == 2)
// 		{
// 			nIndex = 5;
// 			int nHIndex = 1;
// 
// 			ptTrapezoid1[0] = CPoint(nStartX - nHGap*nIndex, nTop);
// 			ptTrapezoid1[1] = CPoint(nEndX   + nHGap*nIndex, nTop);
// 			nIndex--;
// 			ptTrapezoid1[2] = CPoint(nEndX   + nHGap*nIndex, nTop + nOneHeight*nHIndex);
// 			ptTrapezoid1[3] = CPoint(nStartX - nHGap*nIndex, nTop + nOneHeight*nHIndex);
// 
// 			ptTrapezoid2[0] = CPoint(nStartX - nHGap*nIndex, nTop + nOneHeight*nHIndex + 2);
// 			ptTrapezoid2[1] = CPoint(nEndX   + nHGap*nIndex, nTop + nOneHeight*nHIndex + 2);
// 			nIndex--;
// 			nOneHeight++;
// 			nHIndex++;
// 			ptTrapezoid2[2] = CPoint(nEndX   + nHGap*nIndex, nTop + nOneHeight*nHIndex);
// 			ptTrapezoid2[3] = CPoint(nStartX - nHGap*nIndex, nTop + nOneHeight*nHIndex);
// 
// 			ptTrapezoid3[0] = CPoint(nStartX - nHGap*nIndex, nTop + nOneHeight*nHIndex + 2);
// 			ptTrapezoid3[1] = CPoint(nEndX   + nHGap*nIndex, nTop + nOneHeight*nHIndex + 2);
// 			nIndex--;
// 			nOneHeight++;
// 			nHIndex++;
// 			ptTrapezoid3[2] = CPoint(nEndX   + nHGap*nIndex, nTop + nOneHeight*nHIndex);
// 			ptTrapezoid3[3] = CPoint(nStartX - nHGap*nIndex, nTop + nOneHeight*nHIndex);
// 
// 			ptTrapezoid4[0] = CPoint(nStartX - nHGap*nIndex, nTop + nOneHeight*nHIndex + 2);
// 			ptTrapezoid4[1] = CPoint(nEndX   + nHGap*nIndex, nTop + nOneHeight*nHIndex + 2);
// 			nIndex--;
// 			nOneHeight++;
// 			nHIndex++;
// 			ptTrapezoid4[2] = CPoint(nEndX   + nHGap*nIndex, nTop + nOneHeight*nHIndex);
// 			ptTrapezoid4[3] = CPoint(nStartX - nHGap*nIndex, nTop + nOneHeight*nHIndex);
// 
// 			ptTrapezoid5[0] = CPoint(nStartX - nHGap*nIndex, nTop + nOneHeight*nHIndex + 2);
// 			ptTrapezoid5[1] = CPoint(nEndX   + nHGap*nIndex, nTop + nOneHeight*nHIndex + 2);
// 			nIndex--;
// 			nOneHeight++;
// 			nHIndex++;
// 			ptTrapezoid5[2] = CPoint(nEndX   + nHGap*nIndex, nTop + nOneHeight*nHIndex);
// 			ptTrapezoid5[3] = CPoint(nStartX - nHGap*nIndex, nTop + nOneHeight*nHIndex);
// 		}
// 
// 		CBrush brush;
// 		brush.CreateSolidBrush(crGreen);
// 		CBrush* pOldBrush = (CBrush*)pDC->SelectObject(&brush);
// 		pDC->SetPolyFillMode(ALTERNATE);
// 		pDC->Polygon(ptTrapezoid1, 4);
// 		pDC->Polygon(ptTrapezoid2, 4);
// 
// 		if(m_nLastRow >= 3)
// 			pDC->Polygon(ptTrapezoid3, 4);
// 		if(m_nLastRow >= 4)
// 			pDC->Polygon(ptTrapezoid4, 4);
// 		if(m_nLastRow >= 5)
// 			pDC->Polygon(ptTrapezoid5, 4);
// 		pDC->SelectObject(pOldBrush);
// 	}
}


CELLINFO* CStatisticCtrl::GetCellInfo(ArrCellInfo& arrCellInfos, int nRow, int nCol)
{
	int i;
	for(i = 0; i < arrCellInfos.GetSize(); ++i)
	{
		CELLINFO *pCell = arrCellInfos.GetAt(i);
		if(pCell->nRow == nRow && pCell->nCol == nCol)
			return pCell;
	}

	return NULL;
}

void CStatisticCtrl::SetStatisticData(STATICSTIC& stStatisticData)
{
// 	float fVal = 0.0;
// 
// 	int nRow;
// 	int nCol;
// 	for(nRow = 1; nRow <= m_nLastRow; nRow++)
// 	{
// 		for(nCol= 0; nCol < _countof(szColName); nCol++)
// 		{
// 			
// 		}
// 	}
// 
// 
// 	CELLINFO* pCell = GetCellInfo(m_arrNormal, 1, 1);
// 	if(pCell)
// 		pCell->strText.Format("%d", stStatisticData.nTotalUp);
// 
// 	pCell = GetCellInfo(m_arrNormal, 1, 2);
// 	if(pCell)
// 		pCell->strText.Format("%d", stStatisticData.nTotalBalance);
// 
// 	CELLINFO* pCell = GetCellInfo(m_arrNormal, 1, 1);
// 	if(pCell)
// 		pCell->strText.Format("%d", stStatisticData.nTotalUp);
// 
// 	pCell = GetCellInfo(m_arrNormal, 1, 2);
// 	if(pCell)
// 		pCell->strText.Format("%d", stStatisticData.nTotalBalance);


// --- 파이차트--
//	m_PieChart.SetPieceData(stStatisticData, m_arrUpDown);

	Invalidate();
}

BEGIN_MESSAGE_MAP(CStatisticCtrl, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
	ON_WM_SIZE()
	
	ON_NOTIFY_RANGE(UDN_DELTAPOS, IDCT_SPIN_RATE1, IDCT_SPIN_RATE5, OnChangeRateSpin)
END_MESSAGE_MAP()



// CStatisticCtrl 메시지 처리기입니다.

void CStatisticCtrl::OnPaint()
{
	CPaintDC dc(this); // device context for painting	
}

BOOL CStatisticCtrl::OnEraseBkgnd(CDC* pDC)
{	
	// 20120723 ssj - 서버자동주문 >>
//	ResizeCtrl();
	// 20120723 ssj - 서버자동주문 <<
	DrawContents(pDC);	
	return TRUE;
}

int CStatisticCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	int nIndex;
	if(m_nFlagHogaOrTimeDiv == HOGADIV_ORDER)
	{
		for(nIndex = 0; nIndex < _countof(PRICE_STANDARD_STRING); nIndex++)
			m_sarrHogaText.Add(PRICE_STANDARD_STRING[nIndex]);
	}
	else if(m_nFlagHogaOrTimeDiv == TIMEDIV_ORDER)
	{
		CString strText;
		for(nIndex = 0; nIndex < _countof(PRICE_STANDARD_STRING); nIndex++)
		{
			if(nIndex == 0)
				strText = _T("조건시점");
			else
				strText.Format("%s %d분후", "조건시점", m_nDivUint * nIndex);
			m_sarrHogaText.Add(strText);
		}
	}
	
	
	m_nHogaStartIndex = 0;
	m_nBarType = 0;

	InitNormalTable();	
//	InitKospiTable();
	CString strImagePath;
	GetDir_DrfnRoot(strImagePath);
	strImagePath += "\\Image";

	m_ToolTipCtrl.Create(this);
	m_ToolTipCtrl.Activate(FALSE);

	//구성비율1 
	m_EditRate1.Create(WS_CHILD | WS_VISIBLE | ES_RIGHT, CRect(0,0,10,20), this, IDE_RATE1);
	m_EditRate1.SetFont(&m_Font);
	m_EditRate1.SetWindowText("10");

	m_SpinRate1.SetImagePath(strImagePath);
	m_SpinRate1.Create(WS_CHILD | WS_VISIBLE | UDS_ALIGNRIGHT  | UDS_AUTOBUDDY | WS_TABSTOP, CRect(0,10,0,20), this, IDCT_SPIN_RATE1);
	m_SpinRate1.SetBuddy(&m_EditRate1);
	m_SpinRate1.SetDecimalPlaces(0);
	m_SpinRate1.SetTrimTrailingZeros (FALSE);
	m_SpinRate1.SetRangeAndDelta(5, 100, 5);
	m_SpinRate1.SetPos(0);

	//구성비율2
	m_EditRate2.Create(WS_CHILD | WS_VISIBLE | ES_RIGHT, CRect(0,0,10,20), this, IDE_RATE2);
	m_EditRate2.SetFont(&m_Font);
	m_EditRate2.SetWindowText("10");

	m_SpinRate2.SetImagePath(strImagePath);
	m_SpinRate2.Create(WS_CHILD | WS_VISIBLE | UDS_ALIGNRIGHT  | UDS_AUTOBUDDY | WS_TABSTOP, CRect(0,10,0,20), this, IDCT_SPIN_RATE2);
	m_SpinRate2.SetBuddy(&m_EditRate2);
	m_SpinRate2.SetDecimalPlaces(0);
	m_SpinRate2.SetTrimTrailingZeros (FALSE);
	m_SpinRate2.SetRangeAndDelta(5, 100, 5);
	m_SpinRate2.SetPos(0);

	//구성비율3
	m_EditRate3.Create(WS_CHILD | WS_VISIBLE | ES_RIGHT, CRect(0,0,10,20), this, IDE_RATE3);
	m_EditRate3.SetFont(&m_Font);
	m_EditRate3.SetWindowText("10");

	m_SpinRate3.SetImagePath(strImagePath);
	m_SpinRate3.Create(WS_CHILD | WS_VISIBLE | UDS_ALIGNRIGHT  | UDS_AUTOBUDDY | WS_TABSTOP, CRect(0,10,0,20), this, IDCT_SPIN_RATE3);
	m_SpinRate3.SetBuddy(&m_EditRate3);
	m_SpinRate3.SetDecimalPlaces(0);
	m_SpinRate3.SetTrimTrailingZeros (FALSE);
	m_SpinRate3.SetRangeAndDelta(5, 100, 5);
	m_SpinRate3.SetPos(0);

	//구성비율4
	m_EditRate4.Create(WS_CHILD | WS_VISIBLE | ES_RIGHT, CRect(0,0,10,20), this, IDE_RATE4);
	m_EditRate4.SetFont(&m_Font);
	m_EditRate4.SetWindowText("10");

	m_SpinRate4.SetImagePath(strImagePath);
	m_SpinRate4.Create(WS_CHILD | WS_VISIBLE | UDS_ALIGNRIGHT  | UDS_AUTOBUDDY | WS_TABSTOP, CRect(0,10,0,20), this, IDCT_SPIN_RATE4);
	m_SpinRate4.SetBuddy(&m_EditRate4);
	m_SpinRate4.SetDecimalPlaces(0);
	m_SpinRate4.SetTrimTrailingZeros (FALSE);
	m_SpinRate4.SetRangeAndDelta(5, 100, 5);
	m_SpinRate4.SetPos(0);

	//구성비율5
	m_EditRate5.Create(WS_CHILD | WS_VISIBLE | ES_RIGHT, CRect(0,0,10,20), this, IDE_RATE5);
	m_EditRate5.SetFont(&m_Font);
	m_EditRate5.SetWindowText("10");

	m_SpinRate5.SetImagePath(strImagePath);
	m_SpinRate5.Create(WS_CHILD | WS_VISIBLE | UDS_ALIGNRIGHT  | UDS_AUTOBUDDY | WS_TABSTOP, CRect(0,10,0,20), this, IDCT_SPIN_RATE5);
	m_SpinRate5.SetBuddy(&m_EditRate5);
	m_SpinRate5.SetDecimalPlaces(0);
	m_SpinRate5.SetTrimTrailingZeros (FALSE);
	m_SpinRate5.SetRangeAndDelta(0, 100, 1);
	m_SpinRate5.SetPos(0);
	m_SpinRate5.ShowWindow(SW_HIDE);

	m_EditRate1.SetEditRangeKillFocus(5, 100);
	m_EditRate2.SetEditRangeKillFocus(5, 100);
	m_EditRate3.SetEditRangeKillFocus(5, 100);
	m_EditRate4.SetEditRangeKillFocus(5, 100);
	m_EditRate5.SetEditRangeKillFocus(5, 100);


	//수량1
	m_EditVolume1.Create(WS_CHILD | WS_VISIBLE | ES_RIGHT | WS_TABSTOP, CRect(0,0,10,20), this, IDE_VOLUME1);
	m_EditVolume1.SetFont(&m_Font);
	// 20120723 ssj - 서버자동주문 >>
	m_EditVolume1.EnableWindow(FALSE);
	// 20120723 ssj - 서버자동주문 <<
	m_EditVolume1.SetWindowText("0");

	//수량2
	m_EditVolume2.Create(WS_CHILD | WS_VISIBLE | ES_RIGHT | WS_TABSTOP, CRect(0,0,10,20), this, IDE_VOLUME2);
	m_EditVolume2.SetFont(&m_Font);
	// 20120723 ssj - 서버자동주문 >>
	m_EditVolume2.EnableWindow(FALSE);
	// 20120723 ssj - 서버자동주문 <<
	m_EditVolume2.SetWindowText("0");

	//수량3
	m_EditVolume3.Create(WS_CHILD | WS_VISIBLE | ES_RIGHT | WS_TABSTOP, CRect(0,0,10,20), this, IDE_VOLUME3);
	m_EditVolume3.SetFont(&m_Font);
	// 20120723 ssj - 서버자동주문 >>
	m_EditVolume3.EnableWindow(FALSE);
	// 20120723 ssj - 서버자동주문 <<
	m_EditVolume3.SetWindowText("0");

	//수량4
	m_EditVolume4.Create(WS_CHILD | WS_VISIBLE | ES_RIGHT | WS_TABSTOP, CRect(0,0,10,20), this, IDE_VOLUME4);
	m_EditVolume4.SetFont(&m_Font);
	// 20120723 ssj - 서버자동주문 >>
	m_EditVolume4.EnableWindow(FALSE);
	// 20120723 ssj - 서버자동주문 <<
	m_EditVolume4.SetWindowText("0");

	//수량5
	m_EditVolume5.Create(WS_CHILD | WS_VISIBLE | ES_RIGHT | WS_TABSTOP, CRect(0,0,10,20), this, IDE_VOLUME5);
	m_EditVolume5.SetFont(&m_Font);
	// 20120723 ssj - 서버자동주문 >>
	m_EditVolume5.EnableWindow(FALSE);
	// 20120723 ssj - 서버자동주문 <<
	m_EditVolume5.SetWindowText("0");



	// 	m_SpinRate1.SetWindowPos(m_SpinRate2.GetSafeHwnd(), 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
// 	m_SpinRate2.SetWindowPos(m_SpinRate3.GetSafeHwnd(), 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
// 	m_SpinRate3.SetWindowPos(m_SpinRate4.GetSafeHwnd(), 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
// 	m_SpinRate4.SetWindowPos(m_SpinRate5.GetSafeHwnd(), 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

// 	::SetWindowPos(m_EditVolume2.GetSafeHwnd(), m_EditVolume1.GetSafeHwnd(), 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
// 	::SetWindowPos(m_EditVolume3.GetSafeHwnd(), m_EditVolume2.GetSafeHwnd(), 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
// 	::SetWindowPos(m_EditVolume4.GetSafeHwnd(), m_EditVolume3.GetSafeHwnd(), 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
// 	::SetWindowPos(m_EditVolume5.GetSafeHwnd(), m_EditVolume4.GetSafeHwnd(), 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	return 0;
}

void CStatisticCtrl::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

//	ResizeCtrl();
}

BOOL CStatisticCtrl::PreTranslateMessage(MSG* pMsg)
{
	/*
	m_ToolTipCtrl.RelayEvent(pMsg);
	CString strValue;
	switch (pMsg->message)
	{
	case WM_KEYUP:
		{
			if(pMsg->hwnd)
			{	
				if(pMsg->wParam == VK_ESCAPE)
					return FALSE;

				CWnd* pWnd = CWnd::FromHandle(pMsg->hwnd);
				if(pWnd)
				{
					HWND hFocus = pWnd->GetSafeHwnd();
					
				
					if(hFocus == m_EditRate1.GetSafeHwnd() || hFocus == m_EditRate2.GetSafeHwnd() ||
					   hFocus == m_EditRate3.GetSafeHwnd() || hFocus == m_EditRate4.GetSafeHwnd() ||
					   hFocus == m_EditRate5.GetSafeHwnd())
					{
						CheckRateAndSet(hFocus);
						return 1L;
					}
					else
						return FALSE;						
									
				}
			}
		}
		break;
	default:
		break;
	
	}
	*/
	return CWnd::PreTranslateMessage(pMsg);
}

void CStatisticCtrl::CheckRateAndSet(HWND hCtrl)
{
	CDrEdit* pEdit = (CDrEdit*)FromHandle(hCtrl);

	CString strData;
	pEdit->GetWindowText(strData);

	int nRate1, nRate2, nRate3, nRate4, nRate5;
	int nTargetRate = atoi(strData);
	int nChangeRate;
	CString strVol1, strVol2, strVol3, strVol4, strVol5;	

	CNumSpinCtrl* pSpinCtrl = GetBuddySpinCtrl(hCtrl);

	m_EditRate1.GetWindowText(strData);
	nRate1 = atoi(strData);
	m_EditRate2.GetWindowText(strData);
	nRate2 = atoi(strData);
	m_EditRate3.GetWindowText(strData);
	nRate3 = atoi(strData);
	m_EditRate4.GetWindowText(strData);
	nRate4 = atoi(strData);
	m_EditRate5.GetWindowText(strData);
	nChangeRate = nRate5 = atoi(strData);

	int nOtherSum = GetSumOtherRate(hCtrl);

	int nPrevTargetRate = pSpinCtrl->GetPos();

	pSpinCtrl->SetPos(nTargetRate);
	nRate5 = 100 - (nRate1 + nRate2 + nRate3 + nRate4);
	if(nRate5 >= 0)
		m_SpinRate5.SetPos(nRate5);
	else
	{
		nTargetRate = 100 - (nOtherSum - nChangeRate);
		pSpinCtrl->SetPos(nTargetRate);
		m_SpinRate5.SetPos(0);
	}	
	CalcVolume();
	InvalidateRect(m_rectBar);
}

CNumSpinCtrl* CStatisticCtrl::GetBuddySpinCtrl(HWND hWnd)
{
	if(m_EditRate1.GetSafeHwnd() == hWnd)
		return &m_SpinRate1;
	else if(m_EditRate2.GetSafeHwnd() == hWnd)
		return &m_SpinRate2;
	else if(m_EditRate3.GetSafeHwnd() == hWnd)
		return &m_SpinRate3;
	else if(m_EditRate4.GetSafeHwnd() == hWnd)
		return &m_SpinRate4;
	else if(m_EditRate5.GetSafeHwnd() == hWnd)
		return &m_SpinRate5;

	return NULL;
}

int CStatisticCtrl::GetSumOtherRate(HWND hWnd)
{
	CString strData1, strData2, strData3, strData4, strData5;
	int nSum = 0;

	m_EditRate1.GetWindowText(strData1);
	m_EditRate2.GetWindowText(strData2);
	m_EditRate3.GetWindowText(strData3);
	m_EditRate4.GetWindowText(strData4);
	m_EditRate5.GetWindowText(strData5);

	if(m_EditRate1.GetSafeHwnd() == hWnd)
		nSum = atoi(strData2) + atoi(strData3) + atoi(strData4) + atoi(strData5);		
	else if(m_EditRate2.GetSafeHwnd() == hWnd)
		nSum = atoi(strData1) + atoi(strData3) + atoi(strData4) + atoi(strData5);			
	else if(m_EditRate3.GetSafeHwnd() == hWnd)
		nSum = atoi(strData1) + atoi(strData2) + atoi(strData4) + atoi(strData5);	
	else if(m_EditRate4.GetSafeHwnd() == hWnd)
		nSum = atoi(strData1) + atoi(strData2) + atoi(strData3) + atoi(strData5);		
	else if(m_EditRate5.GetSafeHwnd() == hWnd)
		nSum = atoi(strData1) + atoi(strData2) + atoi(strData3) + atoi(strData4);

	return nSum;		
}

void CStatisticCtrl::AddToolInfo(CRect& rcBar)
{
	if (m_ToolTipCtrl.GetToolCount() == 0)
	{
		CRect rcTemp = rcBar;
		int nWidth = rcBar.Width() / 6;
		
		rcTemp.right = rcTemp.left + nWidth;
		m_ToolTipCtrl.AddTool(this, _T("강상승: 15.00% ~ 10.01%"), rcTemp, 1);

		rcTemp.OffsetRect(nWidth, 0);
		m_ToolTipCtrl.AddTool(this, _T("상  승: 10.00% ~ 5.01%"), rcTemp, 2);

		rcTemp.OffsetRect(nWidth, 0);
		m_ToolTipCtrl.AddTool(this, _T("약상승: 5.00% ~ 0%"), rcTemp, 3);

		rcTemp.OffsetRect(nWidth, 0);
		m_ToolTipCtrl.AddTool(this, _T("약하락: -0.01% ~ -5.00%"), rcTemp, 4);

		rcTemp.OffsetRect(nWidth, 0);
		m_ToolTipCtrl.AddTool(this, _T("하  락: -5.01% ~ -10.00%"), rcTemp, 5);

		rcTemp.OffsetRect(nWidth, 0);
		m_ToolTipCtrl.AddTool(this, _T("강하락: -10.01% ~ -15.00%"), rcTemp, 6);

		m_ToolTipCtrl.Activate(TRUE);
	}
}

void CStatisticCtrl::ResizeCtrl()
{
	CELLINFO* pCell = GetCellInfo(m_arrNormal, 1, 1);
	if(pCell)
	{
		m_EditRate1.MoveWindow(pCell->rcCell.left, pCell->rcCell.top, pCell->rcCell.Width() - 18, NORMAL_TABLE_HEIGHT);
		m_SpinRate1.MoveWindow(pCell->rcCell.left + (pCell->rcCell.Width() - 18), pCell->rcCell.top, 17, NORMAL_TABLE_HEIGHT);
	}

	pCell = GetCellInfo(m_arrNormal, 2, 1);
	if(pCell)
	{
		m_EditRate2.MoveWindow(pCell->rcCell.left, pCell->rcCell.top, pCell->rcCell.Width() - 18, NORMAL_TABLE_HEIGHT);
		m_SpinRate2.MoveWindow(pCell->rcCell.left + (pCell->rcCell.Width() - 18), pCell->rcCell.top, 17, NORMAL_TABLE_HEIGHT);
	}

	pCell = GetCellInfo(m_arrNormal, 3, 1);
	if(pCell)
	{
		m_EditRate3.MoveWindow(pCell->rcCell.left, pCell->rcCell.top, pCell->rcCell.Width() - 18, NORMAL_TABLE_HEIGHT);
		m_SpinRate3.MoveWindow(pCell->rcCell.left + (pCell->rcCell.Width() - 18), pCell->rcCell.top, 17, NORMAL_TABLE_HEIGHT);
	}

	pCell = GetCellInfo(m_arrNormal, 4, 1);
	if(pCell)
	{
		m_EditRate4.MoveWindow(pCell->rcCell.left, pCell->rcCell.top, pCell->rcCell.Width() - 18, NORMAL_TABLE_HEIGHT);
		m_SpinRate4.MoveWindow(pCell->rcCell.left + (pCell->rcCell.Width() - 18), pCell->rcCell.top, 17, NORMAL_TABLE_HEIGHT);
	}

	pCell = GetCellInfo(m_arrNormal, 5, 1);
	if(pCell)
	{
		m_EditRate5.MoveWindow(pCell->rcCell.left, pCell->rcCell.top, pCell->rcCell.Width() - 18, NORMAL_TABLE_HEIGHT);
	//	m_SpinRate5.MoveWindow(pCell->rcCell.left + (pCell->rcCell.Width() - 18), pCell->rcCell.top, 17, NORMAL_TABLE_HEIGHT);
	}

	pCell = GetCellInfo(m_arrNormal, 1, 2);
	if(pCell)
		m_EditVolume1.MoveWindow(pCell->rcCell.left, pCell->rcCell.top, pCell->rcCell.Width() - 1, NORMAL_TABLE_HEIGHT);

	pCell = GetCellInfo(m_arrNormal, 2, 2);
	if(pCell)
		m_EditVolume2.MoveWindow(pCell->rcCell.left, pCell->rcCell.top, pCell->rcCell.Width() - 1, NORMAL_TABLE_HEIGHT);

	pCell = GetCellInfo(m_arrNormal, 3, 2);
	if(pCell)
		m_EditVolume3.MoveWindow(pCell->rcCell.left, pCell->rcCell.top, pCell->rcCell.Width() - 1, NORMAL_TABLE_HEIGHT);

	pCell = GetCellInfo(m_arrNormal, 4, 2);
	if(pCell)
		m_EditVolume4.MoveWindow(pCell->rcCell.left, pCell->rcCell.top, pCell->rcCell.Width() - 1, NORMAL_TABLE_HEIGHT);

	pCell = GetCellInfo(m_arrNormal, 5, 2);
	if(pCell)
		m_EditVolume5.MoveWindow(pCell->rcCell.left, pCell->rcCell.top, pCell->rcCell.Width() - 1, NORMAL_TABLE_HEIGHT);
	
}


void CStatisticCtrl::SetRowCount(int nRow)
{
	m_nLastRow = nRow;
	InitNormalTable();
	InitDivValue();
	
	int nIndex;
	
	for(nIndex = 0; nIndex < nRow; nIndex++)
	{
		(GetDlgItem(IDE_RATE1 + nIndex))->ShowWindow(TRUE);
		(GetDlgItem(IDCT_SPIN_RATE1 + nIndex))->ShowWindow(TRUE);
		(GetDlgItem(IDE_VOLUME1 + nIndex))->ShowWindow(TRUE);			
	}
	(GetDlgItem(IDCT_SPIN_RATE1 + nRow - 1))->ShowWindow(FALSE);


	for(nIndex = nRow; nIndex < 5; nIndex++)
	{
		(GetDlgItem(IDE_RATE1 + nIndex))->ShowWindow(FALSE);
		(GetDlgItem(IDCT_SPIN_RATE1 + nIndex))->ShowWindow(FALSE);
		(GetDlgItem(IDE_VOLUME1 + nIndex))->ShowWindow(FALSE);

	}
	Invalidate();
}

void CStatisticCtrl::SetDivType(int nType)
{
	m_nDivType = nType;
}

void CStatisticCtrl::SetStandardPrice(int nSel)
{
	SetHogaStartIndex(nSel);
	InitNormalTable();
}

void CStatisticCtrl::SetHogaOrTimeDiv(enORDTYPE nDivType, int nDivUint)
{
	m_nFlagHogaOrTimeDiv = nDivType;
	m_nDivUint = nDivUint;

	if(m_nFlagHogaOrTimeDiv == TIMEDIV_ORDER)
	{
		int nIndex;
		CString strText;
		m_sarrHogaText.RemoveAll();
		for(nIndex = 0; nIndex < _countof(PRICE_STANDARD_STRING); nIndex++)
		{
			if(nIndex == 0)
				strText = _T("조건시점");
			else
				strText.Format("%s %d분후", "조건시점", m_nDivUint * nIndex);
			m_sarrHogaText.Add(strText);
		}
	}
	InitNormalTable();
}

CStringArray* CStatisticCtrl::GetDivQtyValue()
{
	CStringArray* psaQtyValue;
	psaQtyValue = new CStringArray;
	int nRate1 = (int)m_SpinRate1.GetPos();
	int nRate2 = (int)m_SpinRate2.GetPos();
	int nRate3 = (int)m_SpinRate3.GetPos();
	int nRate4 = (int)m_SpinRate4.GetPos();
	int nRate5 = (int)m_SpinRate5.GetPos();

	int nIndex = 0;	
	int nRate;
	CString strData;
	CNumSpinCtrl* pSpinCtrl;
	CDrEdit* pEdit;

	//선물, 옵션일경우는 매도시 비중이 아닌 수량으로 처리
	if(m_OrdMinset.m_strMMType.CompareNoCase(SVRORD_MMTYPE_BUY) == 0 || 
		m_OrdMinset.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_FUT) == 0 ||
		m_OrdMinset.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_SFUT) == 0 ||
		m_OrdMinset.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_OPT) == 0) //매수
	{
		for(nIndex = 0; nIndex < m_nLastRow; nIndex++)
		{
			pEdit = (CDrEdit*)GetDlgItem(IDE_VOLUME1 + nIndex);
			pEdit->GetWindowText(strData);
			strData.Remove(',');	
			psaQtyValue->Add(strData);
		}
	}
	else
	{	
		for(nIndex = 0; nIndex < m_nLastRow; nIndex++)
		{
			pSpinCtrl = (CNumSpinCtrl*)GetDlgItem(IDCT_SPIN_RATE1 + nIndex);
			nRate = (int)pSpinCtrl->GetPos();
			strData.Format("%d", nRate);
			psaQtyValue->Add(strData);
		}
	}


	return psaQtyValue;
}

void CStatisticCtrl::SetDivQtyValue(CStringArray* psaQtyValue)
{
	int nIndex = 0;	
	double dRate;
	CString strData;
	CNumSpinCtrl* pSpinCtrl;
	CDrEdit* pEdit;

	long lVolume;
	int nCount = min(m_nLastRow, psaQtyValue->GetCount());

	// 20130627 ssj - 호가데이터 초기화 오류 수정 >>
	//if(m_OrdMinset.m_strMMType.CompareNoCase(SVRORD_MMTYPE_BUY) == 0) //매수
	if (m_OrdMinset.m_strMMType.CompareNoCase(SVRORD_MMTYPE_BUY) == 0 ||
		m_OrdMinset.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_FUT) == 0 ||
		m_OrdMinset.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_SFUT) == 0 ||
		m_OrdMinset.m_strMarketType.CompareNoCase(SVRORD_MARKETTYPE_OPT) == 0) // 선물옵션 또는 주식은 매수인 경우 무조건 계산 수량 보여준다
	// 20130627 ssj - 호가데이터 초기화 오류 수정 <<
	{
		long lVol[5] = {0, };
		long lVolTot = 0;
		double dRate[5];
		
		for(nIndex = 0; nIndex < psaQtyValue->GetCount(); nIndex++)
		{
			lVol[nIndex] = atol(psaQtyValue->GetAt(nIndex));	
			lVolTot += lVol[nIndex];
		}

		for(nIndex = 0; nIndex < psaQtyValue->GetCount(); nIndex++)
		{
			if (lVolTot != 0)
				dRate[nIndex] = (double)lVol[nIndex]/ lVolTot * 100;
			else
				dRate[nIndex] = 0;
		}

		for(nIndex = 0; nIndex < psaQtyValue->GetCount(); nIndex++)
		{
			pSpinCtrl = (CNumSpinCtrl*)GetDlgItem(IDCT_SPIN_RATE1 + nIndex);
			if(!pSpinCtrl)
				continue;
			if(pSpinCtrl)
				pSpinCtrl->SetPos(dRate[nIndex]);
		}

		for(nIndex = 0; nIndex < nCount; nIndex++)
		{
			pEdit = (CDrEdit*)GetDlgItem(IDE_VOLUME1 + nIndex);

			if(!pEdit)
				continue;

			lVolume =  atol(psaQtyValue->GetAt(nIndex));
			strData.Format("%ld", lVolume);
			InsertComma(strData);
 			pEdit->SetWindowText(strData);
		}
	}
	else
	{	
		for(nIndex = 0; nIndex < psaQtyValue->GetCount(); nIndex++)
		{
			pSpinCtrl = (CNumSpinCtrl*)GetDlgItem(IDCT_SPIN_RATE1 + nIndex);
			if(!pSpinCtrl)
				continue;

			strData = psaQtyValue->GetAt(nIndex);
			dRate = atof(strData);
			if(pSpinCtrl)
				pSpinCtrl->SetPos(dRate);
		}
	}
	return;
}


void CStatisticCtrl::OnChangeRateSpin(UINT nID, NMHDR *pNMHDR, LRESULT *pResult)
{
	CNumSpinCtrl* pSpinCtrl = (CNumSpinCtrl*)GetDlgItem(nID);

	if(!pSpinCtrl)
		return;

	double dVol;
	CString strVol1, strVol2, strVol3, strVol4, strVol5;	

	int nCnt = m_nLastRow;
	int nIndex;	
	double dRate[5] = {0, };


	dRate[0] = m_SpinRate1.GetPos();
	dRate[1] = m_SpinRate2.GetPos();
	dRate[2] = m_SpinRate3.GetPos();
	dRate[3] = m_SpinRate4.GetPos();
	dRate[4] = m_SpinRate5.GetPos();

	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	int nPos = pNMUpDown->iPos;
	int nPrevPos;
	double dResult = 100;

	for(nIndex = 0; nIndex < nCnt - 1; nIndex++)
		dResult -= dRate[nIndex];	


//	int nValue = pSpinCtrl->GetPos();
	int nCtrlID = abs(int(IDCT_SPIN_RATE1 - nID));
	if(dResult >= 0)
	{
		CNumSpinCtrl* pSpinCtrlLast = (CNumSpinCtrl*)(GetDlgItem(IDCT_SPIN_RATE1 + nCnt - 1));
		pSpinCtrlLast->SetPos(dResult);
		dRate[nCnt - 1] = dResult;
	}
	else
	{
		nPrevPos = pSpinCtrl->GetPos() - (5 * pNMUpDown->iDelta);
		pSpinCtrl->SetPos(nPrevPos);
		dRate[nCtrlID] = nPrevPos;
	}



	CStringArray arrVol;
	if(m_OrdMinset.m_strMMType.CompareNoCase(SVRORD_MMTYPE_BUY) == 0) //매수
		//dVol = GetParent()->SendMessage(UMSG_GET_BUY_VOLUME, 0, 0);
		GetParent()->SendMessage(UMSG_GET_BUY_VOLUME, 0, (LPARAM)&dVol);
	else
		//dVol = GetParent()->SendMessage(UMSG_GET_SELL_VOLUME, 0, 0);
		GetParent()->SendMessage(UMSG_GET_SELL_VOLUME, 0, (LPARAM)&dVol);

	double dValue = floor((double)dVol * (dRate[0] / 100));	
	if(m_bVolLimit)
		dValue =int(dValue / 10) * 10;
	strVol1.Format("%.0f", dValue);

	dValue = floor((double)dVol * (dRate[1] / 100));
	if(m_bVolLimit)
		dValue = int(dValue / 10) * 10;
	strVol2.Format("%.0f", dValue );

	dValue = floor((double)dVol * (dRate[2] / 100));
	if(m_bVolLimit)
		dValue = int(dValue / 10) * 10;
	strVol3.Format("%.0f", dValue);

	dValue = floor((double)dVol * (dRate[3] / 100));
	if(m_bVolLimit)
		dValue = int(dValue / 10) * 10;
	strVol4.Format("%.0f", dValue );

	dValue = floor((double)dVol * (dRate[4] / 100));
	if(m_bVolLimit)
		dValue = int(dValue / 10) * 10;
	strVol5.Format("%.0f", dValue);

	arrVol.Add(strVol1);
	arrVol.Add(strVol2);
	arrVol.Add(strVol3);
	arrVol.Add(strVol4);
	arrVol.Add(strVol5);

	
	for(nIndex = 0; nIndex < nCnt - 1; nIndex++)
	{
		dVol -= atol(arrVol.GetAt(nIndex));
	}
	dVol = floor(dVol);

	// 20120723 ssj - 서버자동주문 >>
	if(m_bVolLimit)
		dVol = int(dVol / 10) * 10;
	// 20120723 ssj - 서버자동주문 <<

	CString strResultVol;
	strResultVol.Format("%.0f", dVol);

	arrVol.SetAt(nCnt - 1, strResultVol);

	for(nIndex = 0; nIndex < nCnt; nIndex++)
		(GetDlgItem(IDE_VOLUME1 + nIndex))->SetWindowText(arrVol.GetAt(nIndex));

	InvalidateRect(m_rectBar);

}

void CStatisticCtrl::CalcVolume()
{
	////TRACEP("3", "CalcVolume");

	double dRate1, dRate2, dRate3, dRate4, dRate5;
	double dVol;
	CString strVol1, strVol2, strVol3, strVol4, strVol5;	


	int nCnt = m_nLastRow;
	

	dRate1 = m_SpinRate1.GetPos();
	dRate2 = m_SpinRate2.GetPos();
	dRate3 = m_SpinRate3.GetPos();
	dRate4 = m_SpinRate4.GetPos();
	dRate5 = m_SpinRate5.GetPos();

	CStringArray arrVol;

	if(m_OrdMinset.m_strMMType.CompareNoCase(SVRORD_MMTYPE_BUY) == 0) //매수		
		GetParent()->SendMessage(UMSG_GET_BUY_VOLUME, 0, (LPARAM)&dVol);
	else	//매도
		
		GetParent()->SendMessage(UMSG_GET_SELL_VOLUME, 0, (LPARAM)&dVol);

	double dValue;

	dValue = floor((double)dVol * (dRate1 / 100));
	if(m_bVolLimit)
		dValue = int(dValue / 10) * 10;
	strVol1.Format("%.0f", dValue );

	dValue = floor((double)dVol * (dRate2 / 100));
	if(m_bVolLimit)
		dValue = int(dValue / 10) * 10;
	strVol2.Format("%.0f", dValue );

	dValue = floor((double)dVol * (dRate3 / 100));
	if(m_bVolLimit)
		dValue = int(dValue / 10) * 10;
	strVol3.Format("%.0f", dValue );

	dValue = floor((double)dVol * (dRate4 / 100));
	if(m_bVolLimit)
		dValue = int(dValue / 10) * 10;
	strVol4.Format("%.0f", dValue );

	dValue = floor((double)dVol * (dRate5 / 100));
	if(m_bVolLimit)
		dValue = int(dValue / 10) * 10;
	strVol5.Format("%.0f", dValue );

	arrVol.Add(strVol1);
	arrVol.Add(strVol2);
	arrVol.Add(strVol3);
	arrVol.Add(strVol4);
	arrVol.Add(strVol5);

	int nIndex;
	for(nIndex = 0; nIndex < nCnt - 1; nIndex++)
	{
		dVol -= atol(arrVol.GetAt(nIndex));
	}
	dVol = floor(dVol);

	// 20120723 ssj - 서버자동주문 >>
	if(m_bVolLimit)
		dVol = int(dVol / 10) * 10;
	// 20120723 ssj - 서버자동주문 <<

	if(nCnt == 2)
		strVol2.Format("%.0f", dVol);
	else if(nCnt == 3)
		strVol3.Format("%.0f", dVol);
	else if(nCnt == 4)
		strVol4.Format("%.0f", dVol);
	else if(nCnt == 5)
		strVol5.Format("%.0f", dVol);


	InsertComma(strVol1);
	m_EditVolume1.SetWindowText(strVol1);
	InsertComma(strVol2);
	m_EditVolume2.SetWindowText(strVol2);
	InsertComma(strVol3);
	m_EditVolume3.SetWindowText(strVol3);
	InsertComma(strVol4);
	m_EditVolume4.SetWindowText(strVol4);
	InsertComma(strVol5);
	m_EditVolume5.SetWindowText(strVol5);

	// 20120723 ssj - 서버자동주문 >>
//	ResizeCtrl();
	// 20120723 ssj - 서버자동주문 <<
}

void CStatisticCtrl::SetBaseInfo(COrdMinSet& cOrdMinsetOrigin)
{
	m_OrdMinset.m_enOrdType			=	cOrdMinsetOrigin.m_enOrdType;
	m_OrdMinset.m_strMMType			=	cOrdMinsetOrigin.m_strMMType;
	m_OrdMinset.m_strMarketType		=	cOrdMinsetOrigin.m_strMarketType;
}

void CStatisticCtrl::ChangeSkinColor(long lpColor)
{
	return;
	ST_CLIENTCOLOR* pstClrClient = (ST_CLIENTCOLOR*)lpColor;

	if(!pstClrClient)
		return;

	m_clrBk = pstClrClient->m_clrBkGnd;
	if(m_brushBk.DeleteObject())
		m_brushBk.CreateSolidBrush(m_clrBk);
	Invalidate();

}

void CStatisticCtrl::InsertComma(CString & str1)
{	

	CString str,strTemp1,strTemp2,strTemp3;
	str = str1;
	//부호 처리.
	if(str.GetLength() > 0)
	{
		if(str.GetAt(0) == '-' || str.GetAt(0) == '+')
		{
			strTemp1 = str.Left(1);
			str = str.Mid(1);//부호제거한 문자열.
		}
	}

	int pos ;
	int x,y,i;
	//소수점 부분을 제거한다.
	if((pos = str.Find(".")) != -1)
	{
		strTemp3 = str.Mid(pos);//소수점부터 이하값을 가지고 있는 변수.
		str = str.Left(pos);//소수점 위의 내용을 가지고 있다.
	}
	//문자열의 길이를 구한다.
	int nLength = str.GetLength();
	int max;//콤마의 최대갯수

	//정수 3자리 이상의 값일 경우.
	if((x = nLength / 3) > 0)//몫->x
	{
		if((y = nLength % 3) > 0) //정확히 나누어 떨어지지 않을 때.
			max = x;
		else if(y == 0)
			max = x-1;

		for(i = 0 ; i < max ; i++)//실제로 콤마를 삽입하는 부분.
		{
			if((pos = str.Find(','))== -1)//콤마가 문자열에 없을 경우.
			{
				str = str.Left(nLength-3)+","+str.Mid(nLength-3);					
			}
			else
			{
				str = str.Left(pos-3)+","+str.Mid(pos-3);					
			}
		}
		str1 = strTemp1 + str + strTemp3;		
	}
}

// 20120723 ssj - 서버자동주문 >>
CStringArray *CStatisticCtrl::GetDivQtyRate()
{
	CStringArray *pRet = new CStringArray();

	CString strData;
	if (m_nLastRow > 0)
	{
		strData.Format("%.0f", m_SpinRate1.GetPos());
		pRet->Add(strData);
	}
	if (m_nLastRow > 1)
	{
		strData.Format("%.0f", m_SpinRate2.GetPos());
		pRet->Add(strData);
	}
	if (m_nLastRow > 2)
	{
		strData.Format("%.0f", m_SpinRate3.GetPos());
		pRet->Add(strData);
	}
	if (m_nLastRow > 3)
	{
		strData.Format("%.0f", m_SpinRate4.GetPos());
		pRet->Add(strData);
	}
	if (m_nLastRow > 4)
	{
		strData.Format("%.0f", m_SpinRate5.GetPos());
		pRet->Add(strData);
	}
	return pRet;
}
// 20120723 ssj - 서버자동주문 <<
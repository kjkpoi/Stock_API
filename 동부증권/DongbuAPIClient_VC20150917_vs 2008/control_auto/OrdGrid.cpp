// OrdGrid.cpp: implementation of the COrdGrid class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "../TrSvrAutoOrd.h"
#include "OrdGrid.h"

#include "../resource.h"
#include "../BaseFrmWnd.h"
#include "../MsgBoxDlg.h"
#include <math.h>

// 20120723 ssj - 서버자동주문 >>
#include "../include/MasterDataSub.h"
#include "../include/global.h"
// 20120723 ssj - 서버자동주문 <<

#define RoundOff(x)  (((x) > 0) ? floor(((x) * 100)) / 100 : ceil(((x) * 100)) / 100);

// 20120723 ssj - 서버자동주문 >>
const UINT RMSG_MAINSKINCHANGE  = ::RegisterWindowMessage(_T("RMSG_MAINSKINCHANGE"));

#define TID_TOOTIP		1001
#define HEIGHT_HEATHER	47
// 20120723 ssj - 서버자동주문 <<



#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//extern HINSTANCE g_hInstance;
extern CTrSvrAutoOrdApp theApp;

const		LPCTSTR		DGN_HEADER_NAME_UP[] = {
	_T("감시"), _T("종목명"), 
	_T("구분"), _T("평가손익"), _T(""), _T(""), _T(""), _T(""), _T(""), 
	_T("대출일"), 
	_T("유효기간"), _T(""), _T("조건항목"), _T(""), _T(""), _T(""), _T(""), _T(""), _T(""), _T(""), /*_T(""), _T(""),*/ 
	_T("매체"), _T("삭제"), _T("")
	// 20140709 ssj - 거래승수 저장방식으로 변경 >>
	, _T("")
	// 20140709 ssj - 거래승수 저장방식으로 변경 <<
};

const		UINT		DGN_HEADER_UP_SIZE[] = { 
	32, 80, 
	33, 60, 60, 62, 60, 75, 55, 
	70, 
	37, 37, 30, 30, 30, 30, 30, 30, 30, 30, 
	37, 33, 0
	// 20140709 ssj - 거래승수 저장방식으로 변경 >>
	, 0
	// 20140709 ssj - 거래승수 저장방식으로 변경 <<
};

const		LPCTSTR		DGN_HEADER_NAME[] = {
	_T(""), _T(""),
	_T("구분"), _T("보유수량"), _T("매입가"), _T("수정단가"), _T("현재가"), _T("손익"), _T("수익률"), 
	_T("대출일"), 
	_T("매수"), _T("매도"), _T("손익"), _T(""), _T("시세"), _T(""), _T("BM"), _T(""), _T("지표"), _T(""), 
	_T("매체"), _T("삭제"), _T("")
	// 20140709 ssj - 거래승수 저장방식으로 변경 >>
	, _T("")
	// 20140709 ssj - 거래승수 저장방식으로 변경 <<
};

const		LPCTSTR		SEMIAUTO_HEADER_NAME[] = { _T("주문호가"), _T("주문"), _T("삭제") };

// 20120723 ssj - 서버자동주문 >>
//const		UINT		DGN_HEADER_SIZE[] =    { 20, 90, 60, /*300, 300,*/ 60, 60, 75, 55, 35, 70, 70, 30, 30, 30, 30, 30, 30, 30, 30, /*30, 30,*/ 33, 0};
const		UINT		DGN_HEADER_SIZE[] =    { 
	32, 80, 
	33, 60, 60, 62, 60, 75, 55, 
	70, 
	37, 37, 30, 30, 30, 30, 30, 30, 30, 30, 
	37, 33, 0
	// 20140709 ssj - 거래승수 저장방식으로 변경 >>
	, 0
	// 20140709 ssj - 거래승수 저장방식으로 변경 <<
};
// 20120723 ssj - 서버자동주문 <<

const		UINT		SEMIAUTO_HEADER_SIZE[] = { 120, 60, 60 };

// 20120723 ssj - 서버자동주문 >>
const LPCTSTR ORD_IMAGE[] = {
	"Circle_Sell.bmp",
	"Circle_Buy.bmp",
	"Circle_AutoRegSell.bmp",
	"Circle_AutoRegBuy.bmp",
	"Circle_AutoStopSell.bmp",
	"Circle_AutoStopBuy.bmp",
	"Circle_SemiAutoRegSell.bmp",
	"Circle_SemiAutoRegBuy.bmp",
	"Circle_SemiAutoStopSell.bmp",
	"Circle_SemiAutoStopBuy.bmp" 
};
// 20120723 ssj - 서버자동주문 <<

#define ROW_DEFHEIGHT							18
#define ROW_HEAD_DEFHEIGHT						20

// 20120723 ssj - 서버자동주문 >>
/*
const   COLORREF  clrHeader	   = COLOR_GRID_HEADER_FACE;
const   COLORREF  clrSelRow    = COLOR_GRID_SEL_ROW;
const   COLORREF  clrEvenRow   = COLOR_GRID_EVEN_ROW;
const   COLORREF  clrOddRow	   = COLOR_GRID_ODD_ROW;
const   COLORREF  clrGridLine  = COLOR_GRID_LINE;
*/
// 20120723 ssj - 서버자동주문 <<

#define RED     RGB(255,0,0)
#define YELLOW  RGB(255,255,0)
#define MAGENTA RGB(255,0,255)
#define WHITE   RGB(255,255,255)
#define BLUE    RGB(0,0,255)
#define BLACK	RGB(82,92,108)

/*const UINT RMSG_DBCLICK = ::RegisterWindowMessage(_T("RMSG_DBCLICK"));*/

BEGIN_MESSAGE_MAP(COrdGrid,CUGCtrl)
	//{{AFX_MSG_MAP(ShowGrid)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
//	ON_COMMAND_RANGE(ID_LINKMENU, ID_LINKMENU + 40, OnLinkSelect)
	ON_WM_TIMER()
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// 20120723 ssj - 서버자동주문 >>
/*
extern double dll_GetOptionMultiplier(CString strCode); //옵션 승수
*/
// 20120723 ssj - 서버자동주문 <<

COrdGrid::COrdGrid()
{
	m_nSortMethode		= UG_SORT_DESCENDING;
	m_nSortArrow		= AddCellType(&m_sortArrow);
	m_nSortCol			= -1;

	m_bCallAdjustOneTime = FALSE;
  
	LOGFONT	  logFont;
	GETFONT(logFont, 12, 400, m_fontDefault);
	//m_penGridLine.CreatePen(PS_SOLID, 1, clrGridLine);
	m_bTypeChange = FALSE;
	// 20120723 ssj - 서버자동주문 >>
	//m_nRow = -1;
	//m_nType = 0;
	// 20120723 ssj - 서버자동주문 <<

	m_nFixCol = 0;

	
	// 20120723 ssj - 서버자동주문 >>
	//m_nLastSelRow = -1;
	//m_nLastSelCol = -1;
	//m_nCondMaxRow = -1;
	// 20120723 ssj - 서버자동주문 <<
	m_bMsgBox = FALSE;

	// 20120723 ssj - 서버자동주문 >>
	CBitmap bmp;
	CString strMainPath, strImagePath;
	GetDir_DrfnRoot(strMainPath);
	
	for (int i = 0; i < sizeof(ORD_IMAGE) / sizeof(ORD_IMAGE[0]); i++)
	{	
		strImagePath = strMainPath + "\\image\\Contents\\" + ORD_IMAGE[i];
		HBITMAP hBitmap = (HBITMAP)::LoadImage(NULL, strImagePath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION | LR_DEFAULTSIZE);
		
		//if (hBitmap == NULL)
		//TraceLog("load Fail: %s <=======!!!\n", strImagePath);

		m_arBitmap[i].Attach(hBitmap);
	}

	UseHints(TRUE);

	m_pISkinColorManager = NULL;
	//m_clrBuyText = BLACK;
	//m_clrSellText = BLACK;
	// 20120723 ssj - 서버자동주문 <<

	m_clrSelect				= RGB(0, 0, 0);
	m_clrCellBack			= RGB(0, 0, 0);
	m_clrText				= RGB(0, 0, 0);
	m_clrBack				= RGB(0, 0, 0);
	// 20090209 권휘영 >> Insert
	m_clrEvenRow			= RGB(0, 0, 0);
	m_clrOddRow				= RGB(0, 0, 0);

	m_bEvenOddClr			= FALSE;
	// 20090209 권휘영  <<

	m_PenHeaderLine			= NULL;
	m_PenBorderLine			= NULL;

	m_pISkinColorManager	= NULL;
	m_nHeaderFlag			= HORIZON;

	// 헤더 라인색 지정
	m_PenHeaderLine = new CPen;

	// 셀 라인 스타일을 지정한다.
	m_PenBorderLine = new CPen;

	// 20120723 ssj - 서버자동주문 >>
	m_nMapMode = MODE_EQUITIES;
	// 20120723 ssj - 서버자동주문 <<
}

COrdGrid::~COrdGrid()
{
	if(m_PenHeaderLine)
	{
		delete m_PenHeaderLine;
	}
	if(m_PenBorderLine)
	{
		delete m_PenBorderLine;
	}

	m_fontDefault.DeleteObject();
	//m_penGridLine.DeleteObject();
	m_mapCount.RemoveAll();

	m_tipInfo.RemoveTool(this);
}

void COrdGrid::ClearAll()
{
	// 20120723 ssj - 서버자동주문 >>
	//m_nRow = -1;
	//m_nCondMaxRow = -1;
	// 20120723 ssj - 서버자동주문 <<
	//m_nMaxRow = 0;
	for (int nCount = 0; nCount < GetNumberRows(); nCount++)
		RemoveDataSource(nCount);
	
	while(GetNumberRows()) 
	{
		m_GI->m_defDataSource->DeleteRow(0);
		m_GI->m_numberRows = m_GI->m_numberRows - 1;
	}

	QuickSetCellType(m_nSortCol, -1, 0);
	m_nSortMethode	= UG_SORT_DESCENDING;
	m_nSortCol = -1;

	SetNumberRows(0);
	RedrawAll();
}

BOOL COrdGrid::PreTranslateMessage(MSG* pMsg) 
{	
	return CWnd::PreTranslateMessage(pMsg);
}

void COrdGrid::OnSetup()
{
	SetMultiSelectMode(2); // row select 모드

	SetSH_Width(0);
	SetSH_NumberCols(0);
	SetTH_NumberRows(2);
	SetTH_Height(HEIGHT_HEATHER);
	

	SetHighlightRow(FALSE); 
	
	//SetTH_Height(24);
	SetDefRowHeight(22);

	SetCancelMode(FALSE);
	EnableMenu(TRUE);

	EnableUpdate(TRUE);
	// 20120723 ssj - 서버자동주문 >>
	//UseHints(TRUE);
	// 20120723 ssj - 서버자동주문 <<

	EnableExcelBorders(FALSE);
 	SetVScrollMode(UG_SCROLLTRACKING);
	SetHScrollMode(UG_SCROLLNORMAL);
	//
	

	// 20120723 ssj - 서버자동주문 >>
	//SetUserSizingMode(FALSE);
	// 20120723 ssj - 서버자동주문 <<
	AdjustComponentSizes();

	// 20120723 ssj - 서버자동주문 >>
	//m_bCandleLoadFalg = LoadCandleIndexToXml();
	// 20120723 ssj - 서버자동주문 <<

	CSize szFont = GetFontSize();
	m_nFontHeight = szFont.cy;
	m_nFontWidth = szFont.cx;

	m_tipInfo.Create(this, "BASE", 1);
	m_tipInfo.SetFont(&m_fontDefault);
	m_tipInfo.AddTool(this, (LPCTSTR)" ");
}

void COrdGrid::HeaderSetup(int nType)
{
	SetOrdGridColor();

	if (m_pISkinColorManager == NULL)
		return;
	
	//m_clrBuyText = m_pISkinColorManager->GetColor(COLOR_UP_INDEX);
	//m_clrSellText = m_pISkinColorManager->GetColor(COLOR_DOWN_INDEX);	

	// 20120723 ssj - 서버자동주문 >>
	//m_nType = nType;
	// 20120723 ssj - 서버자동주문 <<
	CUGCell cell;
	if(nType == 0)
	{			
		int nColCnt = _countof(DGN_HEADER_SIZE);
		SetNumberCols(nColCnt);
//		COLORREF clrBk;		
		for (int nCol = 0; nCol < nColCnt; nCol++)
		{
			QuickSetAlignment(nCol, -2, UG_ALIGNVCENTER | UG_ALIGNCENTER);
			QuickSetText(nCol, -2, DGN_HEADER_NAME_UP[nCol]);

			// 20120723 ssj - 서버자동주문 >>
//			if (m_nMapMode == MODE_DERIVATIVES)
//			{
//				if (nCol == ITEMCODE_COL)
//					QuickSetText(nCol, -2, "종목코드");
//			}
			// 20120723 ssj - 서버자동주문 <<

			SetColWidth(nCol, (int)(DGN_HEADER_UP_SIZE[nCol]));
			QuickSetBackColor(nCol, -2, m_pISkinColorManager->GetColor(COLOR_GRID_HEADER_INDEX));//clrHeader);		
			QuickSetTextColor(nCol, -2, m_pISkinColorManager->GetColor(COLOR_GRID_TEXT_INDEX));//COLOR_GRID_HEADER_TEXT);
			QuickSetFont(nCol, -2, &m_fontDefault);
			// 20120723 ssj - 서버자동주문 >>
			//QuickSetBorderColor(nCol, -2, &m_penGridLine);
			// 20120723 ssj - 서버자동주문 <<
			//if (nCol == 0)
			//	QuickSetBorder(nCol, -2, UG_BDR_RTHIN);
			//else
			//	QuickSetBorder(nCol, -2, UG_BDR_RTHIN | UG_BDR_BTHIN);
			QuickSetBorder(nCol, -2, UG_BDR_RTHIN | UG_BDR_BTHIN);
			
			QuickSetAlignment(nCol, -1, UG_ALIGNVCENTER | UG_ALIGNCENTER);
			QuickSetText(nCol, -1, DGN_HEADER_NAME[nCol]);
			SetColWidth(nCol, (int)(DGN_HEADER_SIZE[nCol]));
			QuickSetBackColor(nCol, -1, m_pISkinColorManager->GetColor(COLOR_GRID_HEADER_INDEX));		
			QuickSetTextColor(nCol, -1, m_pISkinColorManager->GetColor(COLOR_GRID_TEXT_INDEX));
			QuickSetFont(nCol, -1, &m_fontDefault);
			// 20120723 ssj - 서버자동주문 >>
			//QuickSetBorderColor(nCol, -1, &m_penGridLine);
			// 20120723 ssj - 서버자동주문 <<
			QuickSetBorder(nCol, -1, UG_BDR_RTHIN | UG_BDR_BTHIN);
// 			for(int nRow = 0; nRow < m_nMaxRow; nRow++)
// 			{
// 				//조건항목 Circle 영역설정
// 				for(int nOrdCols = COL_BUY_COND1_ACC; nOrdCols < 17; nOrdCols++)
// 				{
// 					QuickSetCellTypeEx(nOrdCols, nRow, UGCELL_ORDCIRCLE_SET);
// 					GetCell(nOrdCols, nRow, &cell);	
// 					cell.SetOrdCircleData("");
// 					SetCell(nOrdCols, nRow, &cell);	
// 				}
// 
// 				GetEvenOddBkColor(nRow, clrBk);
// 				QuickSetBackColor(nCol, nRow, clrBk);
// 				QuickSetTextColor(nCol, nRow, BLACK);
// 				QuickSetBorder(nCol, nRow, UG_BDR_RTHIN | UG_BDR_BTHIN);
// 				QuickSetBorderColor(nCol, nRow, &m_penGridLine);
// 				if(nCol == 0)
// 				{
// 					QuickSetCellType(nCol, nRow, UGCT_CHECKBOX);	
//   					QuickSetCellTypeEx(nCol, nRow, UGCT_CHECKBOXCHECKMARK);				
// 				}	
// 				else if( nCol == (nColCnt - 1))
// 				{
// 					int nButtonIndex = AddCellType(&m_ugButtonType);					
// 					GetCell(nCol, nRow, &cell);
// 					cell.SetText(_T("X"));
// 					cell.SetFont(&m_fontDefault);
// 					cell.SetCellType(nButtonIndex);
// 					cell.SetCellTypeEx(UGCT_BUTTONNOFOCUS);
// 					cell.SetBackColor(clrBk);
// 					cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNCENTER);
// 					SetCell(nCol, nRow, &cell);	
// 
// 				}
// 			}
		}

		// 20120723 ssj - 서버자동주문 >>
		/* commented
		GetCell(0, -2, &cell);
		//cell.SetTextColor(BLACK);
		cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
		cell.SetBorderColor(&m_penGridLine);		
		cell.SetCellType(UGCT_CHECKBOX);
		cell.SetCellTypeEx(UGCT_CHECKBOXCHECKMARK);
		SetCell(0, -2, &cell);
		*/
		// 20120723 ssj - 서버자동주문 <<
	}
	// 20120723 ssj - 서버자동주문 >>
	/*
	else if(nType == 1)
	{
		int nColCnt = _countof(SEMIAUTO_HEADER_NAME);
		SetNumberCols(nColCnt);
		COLORREF clrBk;

		int nRowCnt = GetNumberRows();
		for (int nCol = 0; nCol < nColCnt; nCol++)
		{
			QuickSetAlignment(nCol, -2, UG_ALIGNVCENTER | UG_ALIGNCENTER);
			QuickSetText(nCol, -2, DGN_HEADER_NAME_UP[nCol]);
			SetColWidth(nCol, (int)(DGN_HEADER_UP_SIZE[nCol]));
			QuickSetBackColor(nCol, -2, clrHeader);		
			QuickSetTextColor(nCol, -2, COLOR_GRID_HEADER_TEXT);
			QuickSetFont(nCol, -2, &m_fontDefault);

			QuickSetAlignment(nCol, -1, UG_ALIGNVCENTER | UG_ALIGNCENTER);
			QuickSetText(nCol, -1, SEMIAUTO_HEADER_NAME[nCol]);
			SetColWidth(nCol, (int)(SEMIAUTO_HEADER_SIZE[nCol]));
			QuickSetBackColor(nCol, -1, COLOR_ORD_HEADER);		
			QuickSetTextColor(nCol, -1, COLOR_GRID_HEADER_TEXT);
			QuickSetFont(nCol, -1, &m_fontDefault);
			
			
			for(int nRow = 0; nRow < nRowCnt; nRow++)
			{
				GetEvenOddBkColor(nRow, clrBk);
				QuickSetBackColor(nCol, nRow, clrBk);
				QuickSetBorder(nCol, nRow, UG_BDR_RTHIN | UG_BDR_BTHIN);
				QuickSetBorderColor(nCol, nRow, &m_penGridLine);			

				if( nCol == (nColCnt - 2))
				{
					int nButtonIndex = AddCellType(&m_ugButtonType);	
					GetCell(nCol, nRow, &cell);
					cell.SetText(_T("X"));
					cell.SetFont(&m_fontDefault);
					cell.SetCellType(nButtonIndex);
					// 20120723 ssj - 서버자동주문 >>
					cell.SetBorder(UG_BDR_RTHICK | UG_BDR_BTHICK);
					// 20120723 ssj - 서버자동주문 <<
					cell.SetCellTypeEx(UGCT_BUTTONNOFOCUS);
					cell.SetBackColor(clrBk);
					cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNCENTER);
					SetCell(nCol, nRow, &cell);	
				}
			}
		}
	}
	*/
	// 20120723 ssj - 서버자동주문 <<

	m_bCallAdjustOneTime = FALSE;

	// 20120723 ssj - 서버자동주문 >>
	/*
	JoinCells(10, -1,  11, -1);
	JoinCells(12, -1, 13, -1);
	JoinCells(14, -1, 15, -1);
	JoinCells(16, -1, 17, -1);
	*/
	JoinCells(12, -1, 13, -1);
	JoinCells(14, -1, 15, -1);
	JoinCells(16, -1, 17, -1);
	JoinCells(18, -1, 19, -1);
	// 20120723 ssj - 서버자동주문 <<

//	JoinCells(17, -1, 18, -1);

	JoinCells(0, -2, 0, -1);
	JoinCells(1, -2, 1, -1);

	// 20120723 ssj - 서버자동주문 >>
	/*
	JoinCells(7, -2, 7, -1);
	JoinCells(8, -2, 8, -1);
	JoinCells(9, -2, 9, -1);
	*/
	JoinCells(2, -2, 2, -1);
	JoinCells(9, -2, 9, -1);
	JoinCells(10, -2, 11, -2);
	// 20120723 ssj - 서버자동주문 <<

	// 20120723 ssj - 서버자동주문 >>
	/*
	JoinCells(2, -2, 6, -2);
	JoinCells(10, -2, 17, -2);
	JoinCells(18, -2, 18, -1);
	*/
	JoinCells(3, -2, 8, -2);
	JoinCells(12, -2, 19, -2);
	JoinCells(20, -2, 20, -1);
	JoinCells(21, -2, 21, -1);
	// 20120723 ssj - 서버자동주문 <<

	// 20120723 ssj - 서버자동주문 >>
	//BOOL bUseCredit = GetParent()->SendMessage(UMSG_GETUSECREDIT, 0, 0);
	//if(!bUseCredit)
	if (m_nMapMode == MODE_DERIVATIVES)
	{
		int nDel = GetColWidth(COL_USER_PRICE);
		nDel = nDel + GetColWidth(COL_LOANDATE);

		HideColumn(COL_USER_PRICE, TRUE);
		HideColumn(COL_LOANDATE, TRUE);

		int nDiv = 5;
		SetColWidth(ITEMCODE_COL, GetColWidth(ITEMCODE_COL) + nDel / nDiv);
		SetColWidth(UNITPRICE, GetColWidth(UNITPRICE) + nDel / nDiv);
		//SetColWidth(COL_USER_PRICE, GetColWidth(COL_USER_PRICE) + nDel / nDiv);
		SetColWidth(CUR_PRICE, GetColWidth(CUR_PRICE) + nDel / nDiv);
		SetColWidth(EVALUATE_COL, GetColWidth(EVALUATE_COL) + nDel / nDiv);
		SetColWidth(EVALUATERATE_COL, GetColWidth(EVALUATERATE_COL) + (nDel - (nDel / nDiv) * (nDiv - 1)));
	}
	// 20120723 ssj - 서버자동주문 <<

	AdjustComponentSizes();
	RedrawAll();
}

//주문등록리스트용
int COrdGrid::FindModifyRow(StOrdCondData stOrdCond)
{
	int nRow;
	CUGCell cell;
	CString strCode;
		
	CString strDate, strExDate;
	int nCredit;
//	int nMMtype;

	//매수, 매도 셀구분
	int nOrdInfoCol = COL_BUY_COND1_ACC;
	if(stOrdCond.strMMType.CompareNoCase(SVRORD_MMTYPE_SELL) == 0)
		nOrdInfoCol++;
	
	for(nRow = 0; nRow < GetNumberRows(); nRow++)
	{
		//종목코드
		GetCell(ITEMCODE_COL, nRow, &cell);
		strCode = cell.GetOtherJongCode();		

		//신용구분
		GetCell(COL_CREDIT_FOSELLBUY, nRow, &cell);
		nCredit = cell.GetOtherDataInt();

		//대출일
		GetCell(COL_LOANDATE, nRow, &cell);
		strDate = cell.GetText();
		strDate.Replace("-", "");
		
		// 20120723 ssj - 서버자동주문 >>
		/*
		//유효기간
		GetCell(COL_EXPIRE_DATE, nRow, &cell);
		strExDate = cell.GetText();
		strExDate.Replace("-", "");
		*/
		// 20120723 ssj - 서버자동주문 <<

		if(stOrdCond.strCode.CompareNoCase(strCode) == 0)
		{
			// 20120723 ssj - 서버자동주문 >>
			/*
			GetCell(nOrdInfoCol, nRow, &cell);	
			nMMtype = cell.GetOtherDataInt();

			if(nMMtype == atoi(stOrdCond.strMMType))
				return -1;
			*/

			// 20120723 ssj - 서버자동주문 >>
			//if(atoi(stOrdCond.strCredit) == nCredit && stOrdCond.strLoanDate.CompareNoCase(strDate) == 0 && 
			//	stOrdCond.strExpiredData.CompareNoCase(strExDate) == 0)
			//	return nRow;
			if(atoi(stOrdCond.strCredit) == nCredit && stOrdCond.strLoanDate.CompareNoCase(strDate) == 0)
				return nRow;
			// 20120723 ssj - 서버자동주문 <<
			
			/*
			if (atoi(stOrdCond.strCredit) == nCredit && stOrdCond.strLoanDate.CompareNoCase(strDate) == 0)
			{
				if (strExDate.GetLength() > 0)
				{
					if (stOrdCond.strExpiredData.CompareNoCase(strExDate) == 0)
						return nRow;
				}
				else
				{
					return nRow;
				}
			}
			*/
			// 20120723 ssj - 서버자동주문 <<
		}	
	}
	return -1;
}

//잔고용
int COrdGrid::FindModifyRow(StOrdJango stOrdJango)
{
	int nRow;
	CUGCell cell;
	CString strCode;
	int nCredit;
	CString strDate;
	CString strCreditTextOri, strCreditTextComp, strLoanDate;
	for(nRow = 0; nRow < GetNumberRows(); nRow++)
	{
		//종목코드
		GetCell(ITEMCODE_COL, nRow, &cell);
		strCode = cell.GetOtherJongCode();

		if(stOrdJango.strCode.CompareNoCase(strCode) == 0)
		{
			// 주식이면
			if (stOrdJango.nMarketType == CDRCodeTypeInfo::DRCODETYPE_KOSPI_STOCK || 
				stOrdJango.nMarketType == CDRCodeTypeInfo::DRCODETYPE_KOSDAQ_STOCK ||
				stOrdJango.nMarketType == CDRCodeTypeInfo::DRCODETYPE_ELW)
			{
				//신용구분
				GetCell(COL_CREDIT_FOSELLBUY, nRow, &cell);
				nCredit = cell.GetOtherDataInt();
				strCreditTextOri = cell.GetText();

				// 잔고구분 --> 0:현금, 1 신용유통융자, 3 신용자기융자, 5 신용유통대주, 7 신용자기대주, 8 예탁주식담보신용대출
				if(atoi(stOrdJango.strCreditOrdJango) > 0) // 신용일 경우
				{
					strCreditTextComp = GetCreditText(stOrdJango.strCreditOrdJango);
					if(strCreditTextOri.CompareNoCase(strCreditTextComp) == 0) // 신용구분이 같고
					{
						GetCell(COL_LOANDATE, nRow, &cell);
						strLoanDate = cell.GetText();
						strLoanDate.Remove('-');
						// 20120723 ssj - 서버자동주문 >>
						//if(strLoanDate == "" && stOrdJango.strMMType.CompareNoCase(SVRORD_MMTYPE_BUY) == 0)
						//	return -1;
						//else if(strLoanDate.CompareNoCase(stOrdJango.strLoanDateOrdJango) == 0)
						//	return nRow;
						if (strLoanDate.CompareNoCase(stOrdJango.strLoanDateOrdJango) == 0) // 대출일이 같으면 같은 항목
							return nRow;
						// 20120723 ssj - 서버자동주문 <<
					}
				}
				else
				{
					if(atoi(stOrdJango.strCreditOrdJango) == nCredit)
						return nRow;
				}
			}
			// 선옵이면
			else
			{
				return nRow;
			}
		}	
	}
	return -1;
}

//잔고
BOOL COrdGrid::SetAddRow(StOrdJango stOrdJangoData, BOOL bInsert, BOOL bRedraw)
{
	BOOL bAdded = FALSE;

	CUGCell cell;
//	COLORREF clrBk;
	COLORREF clrText;


	int nRow;	
	int nRowCount = GetNumberRows();
	// 20120723 ssj - 서버자동주문 >>
	//m_nRow++;
	//nRow = m_nRow;
	nRow = -1;
	// 20120723 ssj - 서버자동주문 <<
	
	
	CString strData;

	// 20120723 ssj - 서버자동주문 >>
	//GetEvenOddBkColor(nRow, clrBk);
	// 20120723 ssj - 서버자동주문 <<

	int nFindRow = FindModifyRow(stOrdJangoData);

	//조건항목과 종목코드 일치할 경우 병합
	if(nFindRow > -1)
	{
		// 잔고 컬럼들 지우자
		for(int i = ITEMCODE_COL; i <= COL_LOANDATE; i++)
		{
			// 20120723 ssj - 서버자동주문 >> 사용자가 입력한 수정단가는 지우면 안된다
			if (i == COL_USER_PRICE)
				continue;
			// 20120723 ssj - 서버자동주문 <<

			GetCell(i, nRow, &cell);	
			
			// 20120723 ssj - 서버자동주문 >>
			//cell.SetBackColor(clrBk);
			/*
			if (i == 0)
			{
				CString strTemp = cell.GetText();
				if (strTemp == STR_ON)
					cell.SetBackColor(COLOR_STR_ON);
				else
					cell.SetBackColor(m_clrBack);
			}
			else
			{
				//cell.SetBackColor(clrBk);	
			}
			*/
			// 20120723 ssj - 서버자동주문 <<

			////cell.SetTextColor(BLACK);
			cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
			//cell.SetBorderColor(&m_penGridLine);
			cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER);
			cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNCENTER);
			SetCell(i, nRow, &cell);	
		}
		nRow = nFindRow;
		// 20120723 ssj - 서버자동주문 >>
		//m_nRow--;
		// 20120723 ssj - 서버자동주문 <<

		// 잔고 수량이 0인 경우
		if (atol(stOrdJangoData.strQty) <= 0)
		{
			// 조건항목이 있으면 잔고만 제거
			if (IsCondExist(nRow))
			{
				for (int i = COL_CREDIT_FOSELLBUY; i <= COL_LOANDATE; i++)
				{
					// 수정단가와 신용/현금 구분 텍스트는 조건과 관련 있으므로 skip
					if (i == COL_USER_PRICE || i == COL_CREDIT_FOSELLBUY)
						continue;
					RemoveCellInfo(i, nRow);
				}
				return FALSE;
			}
			// 조건항목이 없으면 삭제하자
			else
			{
				DeleteRow(nRow);
				return FALSE;
			}
		}
	}

	// 20120723 ssj - 서버자동주문 >>
	//if(m_nRow >= nRowCount)	
	if (nRow == -1) // 기존 잔고나 조건항목이 없는경우
	// 20120723 ssj - 서버자동주문 <<
	{
		// 잔고 수량이 0인 경우는 그냥 리턴
		if (atol(stOrdJangoData.strQty) <= 0)
			return FALSE;

		AppendRow();
		nRow = GetNumberRows() - 1;
		//m_nMaxRow++;

		// 새로운 잔고가 들어온 경우 조건항목 셀들 초기화
		MakeCellForCondtion(nRow);

		bAdded = TRUE;
	}

	GetCell(CEL_BTN_ONOFF, nRow, &cell);	
	// 20120723 ssj - 서버자동주문 >>
	//cell.SetBackColor(clrBk);
	CString strTemp = cell.GetText();
	if (strTemp == STR_ON)
		cell.SetBackColor(COLOR_STR_ON);
	else
		cell.SetBackColor(m_clrBack);
	// 20120723 ssj - 서버자동주문 <<
	////cell.SetTextColor(BLACK);
	cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
	//cell.SetBorderColor(&m_penGridLine);
	cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER);
	cell.SetFont(&m_fontDefault);
	cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNCENTER);
	SetCell(CEL_BTN_ONOFF, nRow, &cell);		
	
	//종목명 및 종목코드
	GetCell(ITEMCODE_COL, nRow, &cell);	
	//cell.SetBackColor(clrBk);
	////cell.SetTextColor(BLACK);
	cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
	//cell.SetBorderColor(&m_penGridLine);
	cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER);
	cell.SetFont(&m_fontDefault);
	
	/*
	if (stOrdJangoData.nMarketType == CDRCodeTypeInfo::DRCODETYPE_KFUTURE || 
		stOrdJangoData.nMarketType == CDRCodeTypeInfo::DRCODETYPE_KOPTION)
	{
		cell.SetText(stOrdJangoData.strCode);
	}
	else
	{
		cell.SetText(stOrdJangoData.strItemName);
	}
	*/
	cell.SetText(stOrdJangoData.strItemName);

	cell.SetOtherJongCode(stOrdJangoData.strCode);
	cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNLEFT);
	SetCell(ITEMCODE_COL, nRow, &cell);	

	//보유수량
	GetCell(JANGO_VOL_COL, nRow, &cell);	
	//cell.SetBackColor(clrBk);
	////cell.SetTextColor(BLACK);
	cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
	//cell.SetBorderColor(&m_penGridLine);
	cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER);

	cell.SetFont(&m_fontDefault);
	strData = stOrdJangoData.strQty;
	InsetCommar(strData);
	cell.SetText(strData);
	cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNRIGHT);
	SetCell(JANGO_VOL_COL, nRow, &cell);	

	//매입가
	GetCell(UNITPRICE, nRow, &cell);	
	////cell.SetTextColor(BLACK);
	//cell.SetBackColor(clrBk);
	cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
	//cell.SetBorderColor(&m_penGridLine);
	cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER);

	cell.SetFont(&m_fontDefault);
	strData = stOrdJangoData.strUintPrice;
	InsetCommar(strData);
	cell.SetText(strData);
	cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNRIGHT);
	SetCell(UNITPRICE, nRow, &cell);

	//현재가
	GetCell(CUR_PRICE, nRow, &cell);	
	////cell.SetTextColor(BLACK);
	//cell.SetBackColor(clrBk);
	cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
	//cell.SetBorderColor(&m_penGridLine);
	cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER);

	cell.SetFont(&m_fontDefault);
 	strData = stOrdJangoData.strCurPrice;
 	InsetCommar(strData);
	cell.SetText(strData);
	cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNRIGHT);
	SetCell(CUR_PRICE, nRow, &cell);

	//주식잔고는 필드값 그대로 사용해도 되는데
	//선옵은 필드에 엉터리 값이 내려와서 따로 처리
	if (stOrdJangoData.nMarketType == CDRCodeTypeInfo::DRCODETYPE_KOSPI_STOCK || 
		stOrdJangoData.nMarketType == CDRCodeTypeInfo::DRCODETYPE_KOSDAQ_STOCK ||
		stOrdJangoData.nMarketType == CDRCodeTypeInfo::DRCODETYPE_ELW)
	{
		//손익
		GetCell(EVALUATE_COL, nRow, &cell);
		//cell.SetBackColor(clrBk);
		cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
		//cell.SetBorderColor(&m_penGridLine);
		cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER);

		cell.SetFont(&m_fontDefault);
		strData = stOrdJangoData.strProfitandLoss;

		CString strTemp = strData;
		strTemp.Remove(',');
		strTemp.Trim();
		double dVal = atof(strTemp);
		if(IsSame(dVal, 0)) // fabs(dVal) < 0.0001) // == 0
			clrText = BLACK;
		else if (IsGreater(dVal, 0)) // > 0
			clrText = m_clrUp;
		else
			clrText = m_clrDown; //RED;

		InsetCommar(strData);
		cell.SetText(strData);
		//cell.SetOtherDataLong(atol(stOrdJangoData.strHideContract)); //약정금액 요기
		cell.SetTextColor(clrText);
		cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNRIGHT);
		SetCell(EVALUATE_COL, nRow, &cell);

		//약정금액 (HIDE된 마지막셀)
		//int nLastCol = GetNumberCols() - 1;
		GetCell(COL_COST, nRow, &cell);
		cell.SetText(stOrdJangoData.strHideContract); //약정금액 요기
		SetCell(COL_COST, nRow, &cell);

		// 20140709 ssj - 거래승수 저장방식으로 변경 >>
		// 거래승수
		GetCell(COL_UNIT, nRow, &cell);
		cell.SetText(stOrdJangoData.strUnit);
		SetCell(COL_UNIT, nRow, &cell);
		// 20140709 ssj - 거래승수 저장방식으로 변경 <<

		//수익률
		GetCell(EVALUATERATE_COL, nRow, &cell);		
		//cell.SetBackColor(clrBk);
		cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
		//cell.SetBorderColor(&m_penGridLine);
		cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER);
		cell.SetFont(&m_fontDefault);
		//cell.SetText(stOrdJangoData.strROP);
		strTemp.Format("%.2f%%", atof(stOrdJangoData.strROP));
		cell.SetText(strTemp);
		cell.SetTextColor(clrText);
		cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNRIGHT);
 		SetCell(EVALUATERATE_COL, nRow, &cell);

		//구분
		GetCell(COL_CREDIT_FOSELLBUY, nRow, &cell);	
		//cell.SetTextColor(BLACK);
		//cell.SetBackColor(clrBk);
		cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
		//cell.SetBorderColor(&m_penGridLine);
		cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER);

		cell.SetFont(&m_fontDefault);
		CString strCreditText = GetCreditText(stOrdJangoData.strCreditOrdJango);
		cell.SetText(strCreditText);

		// 20120723 ssj - 서버자동주문 >>
		//if(GetCreditText(stOrdJangoData.strCreditOrdJango).CompareNoCase("자융") == 0)
		//	cell.SetOtherDataInt(3);
		//else if(GetCreditText(stOrdJangoData.strCreditOrdJango).CompareNoCase("유융") == 0)
		//	cell.SetOtherDataInt(1);		
		// 20120723 ssj - 서버자동주문 <<

		// 20120723 ssj - 서버자동주문 >>
		cell.SetOtherDataInt(atol(stOrdJangoData.strCreditOrdJango));
		// 20120723 ssj - 서버자동주문 <<

		cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNCENTER);
		SetCell(COL_CREDIT_FOSELLBUY, nRow, &cell);

		//>>[KSJ000000026] 신용주문추가, 주문구분추가
		// 20120723 ssj - 서버자동주문 >>
		/*
		if(GetCreditText(stOrdJangoData.strCreditOrdJango).CompareNoCase("유융") == 0 || GetCreditText(stOrdJangoData.strCreditOrdJango).CompareNoCase("자융") == 0)
		{
			if(stOrdJangoData.nMarketType != CDRCodeTypeInfo::DRCODETYPE_ELW)
			{
				GetCell(COL_LOANDATE, nRow, &cell);	
				//cell.SetTextColor(BLACK);
				cell.SetBackColor(clrBk);
				cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
				cell.SetBorderColor(&m_penGridLine);
				cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER);

				cell.SetFont(&m_fontDefault);
				cell.SetOtherDataInt(atoi(stOrdJangoData.strLoanDateOrdJango));

				if(stOrdJangoData.strLoanDateOrdJango == "")
					strData = "";
				else
					strData.Format("%s-%s-%s", stOrdJangoData.strLoanDateOrdJango.Left(4), stOrdJangoData.strLoanDateOrdJango.Mid(4, 2), stOrdJangoData.strLoanDateOrdJango.Mid(6, 2)); 
				cell.SetText(strData);
				cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNCENTER);
				SetCell(COL_LOANDATE, nRow, &cell);
			}			
		}
		else 
		{
			GetCell(COL_LOANDATE, nRow, &cell);	
			//cell.SetTextColor(BLACK);
			cell.SetBackColor(clrBk);
			cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
			cell.SetBorderColor(&m_penGridLine);
			cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER);
			cell.SetFont(&m_fontDefault);	
			cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNCENTER);
			SetCell(COL_LOANDATE, nRow, &cell);
		}
		*/

		GetCell(COL_LOANDATE, nRow, &cell);	
		//cell.SetTextColor(BLACK);
		//cell.SetBackColor(clrBk);
		cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
		//cell.SetBorderColor(&m_penGridLine);
		cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER);
		cell.SetFont(&m_fontDefault);	
		cell.SetOtherDataInt(atoi(stOrdJangoData.strLoanDateOrdJango));
		if (atoi(stOrdJangoData.strLoanDateOrdJango) > 0 && stOrdJangoData.strLoanDateOrdJango.GetLength() >= 8)
		{
			strData.Format("%s-%s-%s", stOrdJangoData.strLoanDateOrdJango.Left(4), stOrdJangoData.strLoanDateOrdJango.Mid(4, 2), stOrdJangoData.strLoanDateOrdJango.Mid(6, 2)); 
			cell.SetText(strData);
		}
		cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNCENTER);
		SetCell(COL_LOANDATE, nRow, &cell);
		// 20120723 ssj - 서버자동주문 <<
		//<<[KSJ000000026] 신용주문추가, 주문구분추가
	}
	else
	{
		//손익
		GetCell(EVALUATE_COL, nRow, &cell);	
		cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
		cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER);
		strData = stOrdJangoData.strProfitandLoss;

		CString strTemp = strData;
		strTemp.Remove(',');
		strTemp.Trim();
		double dVal = atof(strTemp);
		if(IsSame(dVal, 0)) // fabs(dVal) < 0.0001) // == 0
			clrText = BLACK;
		else if (IsGreater(dVal, 0)) // > 0
			clrText = m_clrUp;
		else
			clrText = m_clrDown; //RED;
		
		InsetCommar(strData);
		cell.SetText(strData);
		cell.SetTextColor(clrText);
		cell.SetFont(&m_fontDefault);
		cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNRIGHT);
		SetCell(EVALUATE_COL, nRow, &cell);
		
		// 약정금액
		GetCell(COL_COST, nRow, &cell);
		cell.SetText(stOrdJangoData.strHideContract); //약정금액 요기
		SetCell(COL_COST, nRow, &cell);

		// 20140709 ssj - 거래승수 저장방식으로 변경 >>
		// 거래승수
		GetCell(COL_UNIT, nRow, &cell);
		cell.SetText(stOrdJangoData.strUnit);
		SetCell(COL_UNIT, nRow, &cell);
		// 20140709 ssj - 거래승수 저장방식으로 변경 <<

		//수익률
		GetCell(EVALUATERATE_COL, nRow, &cell);	
		cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
		cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER);
		cell.SetFont(&m_fontDefault);
		cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNRIGHT);
		//cell.SetText(stOrdJangoData.strROP);
		strTemp.Format("%.2f%%", atof(stOrdJangoData.strROP));
		cell.SetText(strTemp);
		cell.SetTextColor(clrText);
		SetCell(EVALUATERATE_COL, nRow, &cell);

		//구분
		GetCell(COL_CREDIT_FOSELLBUY, nRow, &cell);	
		cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
		cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER);
		cell.SetFont(&m_fontDefault);
		cell.SetText(stOrdJangoData.strFOSellBuy);
		clrText = GetFOPositionTypeColor(stOrdJangoData.strFOSellBuy);
		cell.SetTextColor(clrText);
		cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNCENTER);
		SetCell(COL_CREDIT_FOSELLBUY, nRow, &cell);
	}	

	// 20120723 ssj - 서버자동주문 >>
	if (bAdded)
	{
		// 잔고가 추가된 경우는 온오프버튼과 삭제버튼 셀은 라인만 그려주자
		GetCell(CEL_BTN_ONOFF, nRow, &cell);
		cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
		SetCell(CEL_BTN_ONOFF, nRow, &cell);

		GetCell(COL_BTN_X, nRow, &cell);
		cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
		SetCell(COL_BTN_X, nRow, &cell);
	}
	// 20120723 ssj - 서버자동주문 <<

	RedrawAll();

	return bAdded;
}

//조건항목
int COrdGrid::SetAddRow(StOrdCondData stOrdGridData, BOOL bInsert, BOOL bRedraw)
{
	CUGCell cell;
	COLORREF clrBk;
//	COLORREF clrText;

	// 20120723 ssj - 서버자동주문 >>
//	int nCol;
	int nRow = -1;	
	int nRowCount = GetNumberRows();
	int nFindRow = FindModifyRow(stOrdGridData);
	if(nFindRow > -1)
	{
		nRow = nFindRow;
		AdjustOnOffBtn(nRow, stOrdGridData);
	}
	else
	{
		AppendRow();
		nRow = GetNumberRows() - 1;
		SetOrdCellState(stOrdGridData, nRow);
	}

	SetRestItem(nRow, stOrdGridData); //, clrBk);
	// 20120723 ssj - 서버자동주문 <<

	return nRow;
}

void COrdGrid::GetRowData(int nRow, CString &strData1, CString &strData2)
{
	CUGCell cell;
	
	int nCol = 0;
	GetCell(nCol, nRow, &cell);
	strData1 = cell.GetText();

	nCol = 1;
	GetCell(nCol, nRow, &cell);
	strData2 = cell.GetText();
}

void COrdGrid::GetRowData(int nRow, int &nData1, int &nData2)
{
	CUGCell cell;
	
	int nCol = 0;
	GetCell(nCol, nRow, &cell);
	nData1 = cell.GetOtherDataInt();

	nCol = 1;
	GetCell(nCol, nRow, &cell);
	nData2 = cell.GetOtherDataInt();
}

int COrdGrid::OnCanSizeTopHdg()
{
	return FALSE;
}

void COrdGrid::GetGridOrdData(int nRow, TR_ORDER_DETAIL_IN* pGridData, CString strMMType)
{
	CUGCell	cell;
	CString strCode;
	int nMMType;
	long lCredit;

	CString strLoanDate = "";

	//조건항목 - 계좌 1번셀(매수정보)
	if(strMMType.CompareNoCase(SVRORD_MMTYPE_BUY) == 0)
	{
		GetCell(COL_BUY_COND1_ACC, nRow, &cell);
		strCode = cell.GetOtherJongCode();
		nMMType = cell.GetOtherDataInt();
		lCredit = cell.GetOtherDataLong();
	}
	else //조건항목 - 계좌 2번셀(매도정보)
	{
		GetCell(COL_BUY_COND1_ACC + 1, nRow, &cell);
		strCode = cell.GetOtherJongCode();
		nMMType = cell.GetOtherDataInt();
		lCredit = cell.GetOtherDataLong();
	}	

	CWnd *pParent = GetParent();
	if(!pParent)
		return;

	CString strData;
	strData.Format("%ld", lCredit);
	memcpy(pGridData->szCredit, strData, min(strData.GetLength(), sizeof(pGridData->szCredit)));

	memcpy(pGridData->szItemCode, strCode, min(strCode.GetLength(), sizeof(pGridData->szItemCode)));

	strData.Format("%d", nMMType);
	memcpy(pGridData->szMMType, strData, min(strData.GetLength(), sizeof(pGridData->szMMType)));

	if(lCredit > 0/* && strData.CompareNoCase(SVRORD_MMTYPE_SELL) == 0*/)
	{
		GetCell(COL_LOANDATE, nRow, &cell);
		strLoanDate = cell.GetText();
		strLoanDate.Remove('-');
		strLoanDate.Trim();
	}
	memcpy(pGridData->szCrDate, strLoanDate, min(strLoanDate.GetLength(), sizeof(pGridData->szCrDate)));
	
}

// 20120723 ssj - 서버자동주문 >>
/*
void COrdGrid::SetGridOrdData(int nRow, TR_ORDER_REGOUT* pGridData)
{
	CUGCell	cell, cellSell;		

// 	GetCell(3, nRow, &cell);
// 	CString strData = CString(pGridData->stDetail.szItemCode, sizeof(pGridData->stDetail.szItemCode));
// 	strData.Trim();
// 	cell.SetOtherJongCode(strData);
// 	SetCell(3, nRow, &cell);

// 	GetCell(6, nRow, &cell);
// 	strData = CString(pGridData->stDetail.szMMType, sizeof(pGridData->stDetail.szMMType));
// 	cell.SetOtherDataInt(atoi(strData));
// 	SetCell(6, nRow, &cell);

// 	GetCell(0, nRow, &cell);
// 	strData = CString(pGridData->stDetail.szCredit, sizeof(pGridData->stDetail.szCredit));
// 	int nCredit = cell.SetOtherDataInt(atoi(strData));
// 	SetCell(0, nRow, &cell);

	StOrdCondData stOrdGridData;

	CString strTemp;
	strTemp = CString(pGridData->szJobFlag, sizeof(pGridData->szJobFlag));
	//등록,재등록
	if(strTemp.CompareNoCase(SVRORD_JOB_REG) == 0 || strTemp.CompareNoCase(SVRORD_JOB_START) == 0)
	{
		stOrdGridData.strState = _T("1");
	}
	//정지,수정
	else if(strTemp.CompareNoCase(SVRORD_JOB_STOP) == 0 || strTemp.CompareNoCase(SVRORD_JOB_UPDATE) == 0)
	{
		stOrdGridData.strState = _T("2");
	}
	//삭제
	else if(strTemp.CompareNoCase(SVRORD_JOB_DELETE) == 0)
	{	
		//매수항목
		int nCondCnt = 0;
		GetCell(COL_BUY_COND1_ACC, nRow, &cell);
		CString strCode = cell.GetOtherJongCode();
		if(!strCode.IsEmpty())
			nCondCnt++;			
		//매도항목
		GetCell(COL_BUY_COND1_ACC + 1, nRow, &cellSell);
		strCode = cellSell.GetOtherJongCode();
		if(!strCode.IsEmpty())
			nCondCnt++;		

		//매수 or 매도주문 하나만 걸려있을때
		if(nCondCnt < 2)
		{
			CString strVol;
			QuickGetText(JANGO_VOL_COL, nRow, &strVol);

			if(strVol.IsEmpty())	//잔고데이터는 없고 조건항목이 모두 있을경우는 DeleteRow
			{
				DeleteRow(nRow);
				if(m_nCondMaxRow > -1)
					m_nCondMaxRow--;
			}
			else					//잔고데이터와 조건항목이 모두 있을경우는 조건항목 부분만 Remove
			{
				for(int nCodCol = COL_BUY_COND1_ACC - 1; nCodCol < GetNumberCols() - 2; nCodCol++)
					RemoveCellInfo(nCodCol, nRow);
			}
			RedrawRow(nRow);
			return;
		}
		else
		{
			stOrdGridData.strState = _T("3");
		}		
	}
	
		
	//I:등록, U:수정, D:삭제 R:재등록 S:중지
	//1:등록, 2:휴면(중지) 3:완료(조건만족), 4:만료(기간만족)

	//매도, 매수셀 구분
	int nOrdInfoCol = COL_BUY_COND1_ACC;
	CString strMMType = CString(pGridData->stDetail.szMMType, sizeof(pGridData->stDetail.szMMType));
	strMMType.Trim();
	if(strMMType.CompareNoCase(SVRORD_MMTYPE_SELL) == 0)
		nOrdInfoCol++;

	
	GetCell(nOrdInfoCol, nRow, &cell);
	cell.SetParam(atol(stOrdGridData.strState));	
	SetCell(nOrdInfoCol, nRow, &cell);

	CString strCode = cell.GetOtherJongCode();
	int nMMType  = cell.GetOtherDataInt();
	long lCredit = cell.GetOtherDataLong();

	CString strData = cell.GetLabelText();
	CString strAuto = strData.Left(1);
	CString strCond = strData.Mid(1);
	//stOrdGridData.strCondText = cell.GetOtherDataCellText();
	stOrdGridData.strAuto = strAuto;
	stOrdGridData.strMMType = strMMType;
	stOrdGridData.strCredit.Format("%ld", lCredit);
	stOrdGridData.strCode = strCode;

	stOrdGridData.strCondAcc	= strCond.Left(1);
	stOrdGridData.strCondPrice  = strCond.Mid(1, 1);
	stOrdGridData.strCondItem   = strCond.Mid(2, 1);
	stOrdGridData.strCondIndex  = strCond.Mid(3, 1);

	//손익조건
	int nCol;
	nOrdInfoCol = COL_BUY_COND1_ACC; //매수주문정보(Key)저장 Col , 매도주분정보는 nOrdInfoCol+1
	if(stOrdGridData.strCondAcc == "1")
	{
		nCol = COL_BUY_COND1_ACC;
		stOrdGridData.strCondText = GetCondCircleToolTip(nCol, nRow, stOrdGridData);
		SetCondCircle(nCol, nRow, stOrdGridData);
	}

	//시세조건
	if(stOrdGridData.strCondPrice == "1")
	{
		nCol = COL_BUY_COND1_ACC + 2;
		stOrdGridData.strCondText = GetCondCircleToolTip(nCol, nRow, stOrdGridData);
		SetCondCircle(nCol, nRow, stOrdGridData);
	}

	//BM조건
	if(stOrdGridData.strCondItem == "1")
	{	
		nCol = COL_BUY_COND1_ACC + 4;
		stOrdGridData.strCondText = GetCondCircleToolTip(nCol, nRow, stOrdGridData);
		SetCondCircle(nCol, nRow, stOrdGridData);
	}	

	//지표조건
	if(stOrdGridData.strCondIndex == "1")
	{	
		nCol = COL_BUY_COND1_ACC + 6;
		stOrdGridData.strCondText = GetCondCircleToolTip(nCol, nRow, stOrdGridData);
		SetCondCircle(nCol, nRow, stOrdGridData);
	}

	int nStateBuy = GetCheckWatchState(nRow, atoi(SVRORD_MMTYPE_BUY));
	int nStateSell = GetCheckWatchState(nRow, atoi(SVRORD_MMTYPE_SELL));

	

	int nDelCol = GetNumberCols() - 2;
	GetCell(nDelCol, nRow, &cell);

//	if(nStateSell == STATE_STOP || nStateBuy == STATE_STOP)
//	{	
		int nButtonIndex = AddCellType(&m_ugButtonType);
		cell.SetCellType(nButtonIndex);
		cell.SetCellTypeEx(UGCT_BUTTONNOFOCUS);
		cell.SetText("X");
//	}
// 	else
// 	{
// 		cell.SetBorderColor(&m_penGridLine);
// 		cell.SetCellType(UGCT_NORMAL);
// 		cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER);
// 		cell.SetCellTypeEx(UGCT_NORMAL);
// 		cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
// 		cell.SetText("");
// 	}
	
	// 20120723 ssj - 서버자동주문 >>
	cell.SetBorder(UG_BDR_RTHICK | UG_BDR_BTHICK);
	// 20120723 ssj - 서버자동주문 <<
	SetCell(nDelCol, nRow, &cell);	

	RedrawRow(nRow);
}
*/
// 20120723 ssj - 서버자동주문 <<

void COrdGrid::OnLClicked(int col, long row, int updn, RECT *rect, POINT *point, BOOL processed)
{
	// 20120723 ssj - 서버자동주문 >>
	//if(m_nType != 0)
	//	return;
	// 20120723 ssj - 서버자동주문 <<

	if (row == -1)
		return;
		
	//OnRowChange(row, row);
	// 20120723 ssj - 서버자동주문 >>
	//SetSelectRow(m_nLastSelRow, row);
	// 20120723 ssj - 서버자동주문 <<
	

	//int nColCnt = GetNumberCols();

	CUGCell cell, cellSell;
	//int nCondCol;

	if(updn == 1)
	{	
		// 20120723 ssj - 서버자동주문 >>
		/*
		m_bMsgBox = FALSE;
		if(col == nColCnt - 2)
		{	
			int nStateBuy; //등록,중지여부
			int nStateSell;
			int nCondCnt = 0;
			nCondCol = COL_BUY_COND1_ACC;
			GetCell(nCondCol, row, &cell);
			CString strCodeBuy = cell.GetOtherJongCode();
			nStateBuy = cell.GetParam();
			if(!strCodeBuy.IsEmpty())
			{
				nCondCnt++;								
			}

			nCondCol++;
			GetCell(nCondCol, row, &cellSell);
			CString strCodeSell = cellSell.GetOtherJongCode();
			if(!strCodeSell.IsEmpty())
			{
				nCondCnt++;			
			}	
			nStateSell = cellSell.GetParam();
			
			int nID;
			
			if(nCondCnt == 0) //매수,매도 모두 중지없는경우
				return;
			else if(nCondCnt > 0 && (nStateBuy != 2 && nStateSell != 2))
			{
				m_bMsgBox = TRUE;						
				return;
			}				
			else if(nCondCnt == 2 && (nStateBuy == 2 && nStateSell == 2))	//한줄에 매도,매수 주문을 모두 포함하는 경우
				nID = OpenMsgBoxDlg(MB_MSGBOX_SELLBUYCANCEL);
			else			//매수 or 매도 각 하나의 주문만을 포함하는경우
				nID = OpenMsgBoxDlg(MB_MSGBOX_OKCANCEL);		

			if(nID == MSGBOXID_OK)
			{
				if(!strCodeBuy.IsEmpty())	//매수주문삭제
					GetParent()->SendMessage(WM_NOTIFY_GRID, (WPARAM)NM_GRID_CLK_BUY_DELBTN, (LPARAM)row);		
				if(!strCodeSell.IsEmpty())	//매도주문삭제 //<<[KSJ000000024]주문 감시 여부 선택
					GetParent()->SendMessage(WM_NOTIFY_GRID, (WPARAM)NM_GRID_CLK_SELL_DELBTN, (LPARAM)row);
			}
			else if(nID == MSGBOXID_SELL)
			{
				GetParent()->SendMessage(WM_NOTIFY_GRID, (WPARAM)NM_GRID_CLK_SELL_DELBTN, (LPARAM)row);
			}
			else if(nID == MSGBOXID_BUY)
			{
				GetParent()->SendMessage(WM_NOTIFY_GRID, (WPARAM)NM_GRID_CLK_BUY_DELBTN, (LPARAM)row);		
			}	
			else if(nID == MSGBOXID_SELLBUY)
			{
				if(!strCodeSell.IsEmpty())
					GetParent()->SendMessage(WM_NOTIFY_GRID, (WPARAM)NM_GRID_CLK_SELL_DELBTN, (LPARAM)row);
				if(!strCodeBuy.IsEmpty())
					GetParent()->SendMessage(WM_NOTIFY_GRID, (WPARAM)NM_GRID_CLK_BUY_DELBTN, (LPARAM)row);	
			}

		}			
		*/
		// 20120723 ssj - 서버자동주문 <<
	}
	else if(updn == 0)
	{
		if(col == COL_BTN_X)
		{	
			if (IsMP(row))
			{
				DefMessageBox(GetSafeHwnd(), E_STR_MP);
				return;
			}
			// 20120723 ssj - 서버자동주문 >>
			//if(m_bMsgBox)
			//{					
			//	CString strText = _T("주문삭제는 감시해제상태에서만 가능합니다.");
			//	DefMessageBox(GetSafeHwnd(), strText);	
			//	m_bMsgBox = FALSE;
			//}
			int nStateBuy; //등록,중지여부
			int nStateSell;
			int nCondCnt = 0;
			GetCell(COL_BUY_COND1_ACC, row, &cell);
			CString strCodeBuy = cell.GetOtherJongCode();
			nStateBuy = cell.GetParam();
			if(!strCodeBuy.IsEmpty())
			{
				nCondCnt++;								
			}

			GetCell(COL_BUY_COND1_ACC + 1, row, &cellSell);
			CString strCodeSell = cellSell.GetOtherJongCode();
			if(!strCodeSell.IsEmpty())
			{
				nCondCnt++;			
			}	
			nStateSell = cellSell.GetParam();
			
			int nID;
			
			if(nCondCnt == 0) //매수,매도 모두 중지없는경우
				return;
			else if(nCondCnt > 0 && (nStateBuy != 2 && nStateSell != 2))
			{
				DefMessageBox(GetSafeHwnd(), _T("주문삭제는 감시해제상태에서만 가능합니다."));	
				return;
			}				
			else if(nCondCnt == 2 && (nStateBuy == 2 && nStateSell == 2))	//한줄에 매도,매수 주문을 모두 포함하는 경우
				nID = OpenMsgBoxDlg(MB_MSGBOX_SELLBUYCANCEL);
			else			//매수 or 매도 각 하나의 주문만을 포함하는경우
				nID = OpenMsgBoxDlg(MB_MSGBOX_OKCANCEL);		

			if(nID == MSGBOXID_OK)
			{
				if(!strCodeBuy.IsEmpty())	//매수주문삭제
					GetParent()->SendMessage(WM_NOTIFY_GRID, (WPARAM)NM_GRID_CLK_BUY_DELBTN, (LPARAM)row);		
				if(!strCodeSell.IsEmpty())	//매도주문삭제 //<<[KSJ000000024]주문 감시 여부 선택
					GetParent()->SendMessage(WM_NOTIFY_GRID, (WPARAM)NM_GRID_CLK_SELL_DELBTN, (LPARAM)row);
			}
			else if(nID == MSGBOXID_SELL)
			{
				GetParent()->SendMessage(WM_NOTIFY_GRID, (WPARAM)NM_GRID_CLK_SELL_DELBTN, (LPARAM)row);
			}
			else if(nID == MSGBOXID_BUY)
			{
				GetParent()->SendMessage(WM_NOTIFY_GRID, (WPARAM)NM_GRID_CLK_BUY_DELBTN, (LPARAM)row);		
			}	
			else if(nID == MSGBOXID_SELLBUY)
			{
				if(!strCodeSell.IsEmpty())
					GetParent()->SendMessage(WM_NOTIFY_GRID, (WPARAM)NM_GRID_CLK_SELL_DELBTN, (LPARAM)row);
				if(!strCodeBuy.IsEmpty())
					GetParent()->SendMessage(WM_NOTIFY_GRID, (WPARAM)NM_GRID_CLK_BUY_DELBTN, (LPARAM)row);	
			}
			// 20120723 ssj - 서버자동주문 <<
		}
		else if(col != CEL_BTN_ONOFF)
		{
			// 20120723 ssj - 서버자동주문 >>
			//m_nLastSelCol = col;
			// 20120723 ssj - 서버자동주문 <<

			CWnd *pParent = GetParent();
			if(!pParent)
				return;
			
			if(col > 0 && col < COL_BUY_COND1_ACC)
			{
				GetCell(ITEMCODE_COL, row, &cell);
				CString strCode = cell.GetOtherJongCode();
				if(strCode.IsEmpty())
					return;

				// 20120723 ssj - 서버자동주문 >>
				/*
				pParent->SendMessage(WM_NOTIFY_GRID, (WPARAM)NM_GRID_CLK_SHARECODE, (LPARAM)(LPCTSTR)strCode);

				GetCell(COL_LOANDATE, row, &cell);
				CString strLoanDate = cell.GetText();
				if(!strLoanDate.IsEmpty())
					pParent->SendMessage(WM_NOTIFY_GRID, (WPARAM)NM_GRID_SET_LOANDATE, (LPARAM)(LPCTSTR)strLoanDate);
				*/

				int nCredit = -1;
				CString strLoanDate = "";

				GetCell(COL_CREDIT_FOSELLBUY, row, &cell);
				CString strText = cell.GetText();
				if (strText.GetLength() > 0)
				{
					nCredit = cell.GetOtherDataInt();

					GetCell(COL_LOANDATE, row, &cell);
					strLoanDate = cell.GetText();
					strLoanDate.Remove('-');
				}						

				CString strParam;
				strParam.Format("%s|%d|%s", strCode.Trim(), nCredit, strLoanDate.Trim());

				pParent->SendMessage(WM_NOTIFY_GRID, (WPARAM)NM_GRID_CLK_SHARECODE, (LPARAM)(LPCTSTR)strParam);
				// 20120723 ssj - 서버자동주문 <<
			}
			else//조건항목
			{
			//	int nMarketTab = pParent->SendMessage(UMSG_GETCURMARKETTAB, 0, 0);
				//int nCond;		//조건항목
				//CString strCode;
				//int nCondCol = COL_BUY_COND1_ACC;
//감시여부 체크	
// 						if((col == nCondCol) || (col == nCondCol + 2) || (col == nCondCol + 4) || (col == nCondCol + 6)) //매수 항목 셀
// 							GetCell(nCondCol, row, &cell);	//COL_BUY_COND1_ACC셀에 매수정보 있음					
// 						else //매도 항목 셀
// 							GetCell(nCondCol + 1, row, &cell);	//COL_BUY_COND1_ACC셀에 매도정보 있음					

				//Circle체크
				GetCell(col, row, &cell);
				CString strCond = cell.GetOrdCircleData();
				if(strCond.IsEmpty())
				{
// 							GetCell(ITEMCODE_COL, row, &cell);
// 							CString strCode = cell.GetOtherJongCode();
// 							if(strCode.IsEmpty())
// 								return;
// 
// 							pParent->SendMessage(WM_NOTIFY_GRID, (WPARAM)NM_GRID_CLK_SHARECODE, (LPARAM)(LPCTSTR)strCode);
					return;
				}

// 						strCode = cell.GetOtherJongCode();
// 						if(strCode.IsEmpty())
// 							return;	

				// 20130627 ssj - 호가데이터 초기화 오류 수정 >>
				//pParent->SendMessage(WM_NOTIFY_GRID, (WPARAM)NM_GRID_CLK, (LPARAM)MAKELPARAM(row, col));
				CUGCell tmpCell;
				GetCell(ITEMCODE_COL, row, &tmpCell);
				CString strCode = tmpCell.GetOtherJongCode();
				CString strParam;
				strParam.Format("%d,%d,%s", row, col, strCode);
				pParent->SendMessage(WM_NOTIFY_GRID, (WPARAM)NM_GRID_CLK, (LPARAM)(LPTSTR)(LPCTSTR)strParam);
				// 20130627 ssj - 호가데이터 초기화 오류 수정 <<
			}					
		}	
		else if(col == 0)
		{
			// 20120723 ssj - 서버자동주문 >>
			/*
			int nChkCnt = 0;
			int nValidCnt = 0;
			int nRowCount = GetNumberRows();
			CString strData;
			BOOL bCheck;
			for(int nRow = 0; nRow < nRowCount; nRow++)
			{
				CUGCell cellDate;
				CUGCell cellChk;
				GetCell(COL_BUY_COND1_ACC - 1, nRow, &cellDate);//유효기간셀
				strData = cellDate.GetText();
				if(strData.IsEmpty())
					continue;

				nValidCnt++;
				GetCell(col, nRow, &cellChk);						
				bCheck = cellChk.GetBool();

				if(bCheck)
					nChkCnt++;					
			}	
			
			if(nChkCnt == nValidCnt)
			{
				GetCell(0, -2, &cell);
				cell.SetBool(TRUE);		
				SetCell(0, -2, &cell);	
				RedrawCell(0, -2);
			}
			else
			{
				GetCell(0, -2, &cell);
				cell.SetBool(FALSE);		
				SetCell(0, -2, &cell);
				RedrawCell(0, -2);

			}
			*/

			// On-Off 토글
			CWnd *pParent = GetParent();
			if (pParent)
				pParent->SendMessage(WM_NOTIFY_GRID, (WPARAM)NM_GRID_TOGGLE_WATCHING, (LPARAM)row);
			// 20120723 ssj - 서버자동주문 <<
		}				
	}
}

BOOL COrdGrid::CheckWatching(CGridKey *pGridKey)
{
	// 20120723 ssj - 서버자동주문 >>
	/*
	int nCond;		//조건항목
	CString strCode;
	int nCondCol = COL_BUY_COND1_ACC;
	CUGCell cell;
	if((m_nLastSelCol == nCondCol) || (m_nLastSelCol == nCondCol + 2) || (m_nLastSelCol == nCondCol + 4) || (m_nLastSelCol == nCondCol + 6)) //매수 항목 셀
		GetCell(COL_BUY_COND1_ACC, m_nLastSelRow, &cell);	//COL_BUY_COND1_ACC셀에 매수정보 있음					
	else //매도 항목 셀
		GetCell(COL_BUY_COND1_ACC + 1, m_nLastSelRow, &cell);

	
	//감시여부 체크		
	strCode = cell.GetOtherJongCode();
	if(strCode.IsEmpty())
		return FALSE;

	int nState = cell.GetParam();
	if(nState == 2)
		return TRUE;
	else
		return FALSE;
	
	return TRUE;
	*/

	if (pGridKey == NULL)
		return FALSE;
	
	CUGCell cell;
	int nRows = GetNumberRows();
	int nFindRow = -1;

	for (int nRow = 0; nRow < nRows; nRow++)
	{
		//종목코드
		GetCell(ITEMCODE_COL, nRow, &cell);
		CString strCode = cell.GetOtherJongCode();		

		//신용구분
		GetCell(COL_CREDIT_FOSELLBUY, nRow, &cell);
		int nCredit = cell.GetOtherDataInt();

		//대출일
		GetCell(COL_LOANDATE, nRow, &cell);
		int nLoanDate = cell.GetOtherDataInt();
		
		if (strCode == pGridKey->m_strCode)
		{
			if(atoi(pGridKey->m_strCredit) == nCredit && atol(pGridKey->m_strLoanDate) == nLoanDate)
			{
				nFindRow = nRow;
				break;
			}
		}
	}

	if (nFindRow != -1)
	{
		int nState = GetCheckWatchState(nFindRow, atol(pGridKey->m_strSellBuy));
		if (nState == STATE_WATCH)
			return TRUE;
	}

	return FALSE;
	// 20120723 ssj - 서버자동주문 <<
}

void COrdGrid::Sorting(int col)
{
	QuickSetCellType(m_nSortCol, -1, 0);

	// 20120723 ssj - 서버자동주문 >>
	/*
	if (m_nSortCol == col && m_nSortMethode == UG_SORT_ASCENDING) 
	{
		m_nSortMethode = UG_SORT_DESCENDING;
		m_nArrowType   = UGCT_SORTARROWUP;
	} 
	else 
	{
		m_nSortMethode = UG_SORT_ASCENDING;
		m_nArrowType   = UGCT_SORTARROWDOWN;
	}
	*/

	m_nSortMethode = UG_SORT_ASCENDING;
	m_nArrowType   = UGCT_SORTARROWDOWN;
	// 20120723 ssj - 서버자동주문 <<

	m_nSortCol = col;
	SortBy(m_nSortCol, m_nSortMethode);
	QuickSetCellType(m_nSortCol, -1, m_nSortArrow);
	QuickSetCellTypeEx(m_nSortCol, -1, m_nArrowType);

	// 20120723 ssj - 서버자동주문 >>
	//EvenOddColorSetting();
	// 20120723 ssj - 서버자동주문 <<

	RedrawAll();
}

void COrdGrid::OnTH_LClicked(int col, long row, int updn, RECT *rect , POINT *point , BOOL processed)
{
	// 20120723 ssj - 서버자동주문 >>
	/*
	if(m_nType == 0)
	{	
		if (updn && !processed)
		{		
			if ((row == -1) && (col == 0))
			{
				
			}
			else
			{	
				if(col == 1)
				{
				//	Sorting(col);
				}	
			}
		}
		else if(!updn)
		{
			if(col == 0)
			{	
				int nRowCount = GetNumberRows();
				int nRow;
				CUGCell cell;	
				BOOL bCheck;				

				CString strData;
				if ((row == -2))
				{	
					GetCell(0, -2, &cell);
					bCheck = cell.GetBool();	

					if(point->y > 18 && point->y < 24)
					{
						bCheck = !cell.GetBool();		
						cell.SetBool(bCheck);		
						SetCell(0, -2, &cell);
					}			
			
					for(nRow = 0; nRow < nRowCount; nRow++)
					{
						CUGCell cellChk;
						GetCell(COL_BUY_COND1_ACC - 1, nRow, &cellChk);//유효기간셀
						strData = cellChk.GetText();
						if(strData.IsEmpty())
							continue;

						GetCell(col, nRow, &cellChk);						
						cellChk.SetBool(bCheck);
						SetCell(col, nRow, &cellChk);
					}	
					
				}
				else if((row == -1))
				{
					GetCell(0, -2, &cell);
					bCheck = !cell.GetBool();		
					cell.SetBool(bCheck);		
					SetCell(0, -2, &cell);

					for(nRow = 0; nRow < nRowCount; nRow++)
					{
						CUGCell cellChk;
						GetCell(COL_BUY_COND1_ACC - 1, nRow, &cellChk);//유효기간셀
						strData = cellChk.GetText();
						if(strData.IsEmpty())
							continue;

						GetCell(col, nRow, &cellChk);
						cellChk.SetBool(bCheck);
						SetCell(col, nRow, &cellChk);
					}

				}
				RedrawAll();
			}
		}
	}
	*/
	// 20120723 ssj - 서버자동주문 <<
}

int COrdGrid::OnSortEvaluate(CUGCell *cell1, CUGCell *cell2, int flags)
{
	int  nResult = 0;
	CString strCell1, strCell2;

	if (cell1 == NULL || cell2 == NULL)
		return nResult;

	if (m_nSortCol == 1)
	{
		nResult = cell1->m_string.Compare(cell2->m_string);
	}
	else
	{
		if (cell1->m_lOtherData > cell2->m_lOtherData)
			nResult = 1;
		else if (cell1->m_lOtherData < cell2->m_lOtherData)
			nResult = -1;
	}

	nResult *= (-(flags * 2 - 3));

// 	CString strCell1, strCell2;
// 
// 	if (m_nSortType[m_nSortCol]/*m_nSortCol == 0*/)
// 		nResult = cell1->m_string.Compare(cell2->m_string);
// 	else
// 	{
// 		if (cell1->m_lOtherData > cell2->m_lOtherData)
// 			nResult = 1;
// 		else if (cell1->m_lOtherData < cell2->m_lOtherData)
// 			nResult = -1;
// 	}
// 
// 	nResult *= (-(flags * 2 - 3));

	return nResult;
}

// 20120723 ssj - 서버자동주문 >>
/*
void COrdGrid::EvenOddColorSetting()
{
	long nRow, nRowCnt;
	int  nCol, nColCnt;

	COLORREF clrBk;
	CUGCell cell;

	nRowCnt = GetNumberRows();
	nColCnt = GetNumberCols();
	for (nRow = 0; nRow < nRowCnt; nRow++)
	{
		GetEvenOddBkColor(nRow, clrBk);
		for (nCol = 0; nCol < nColCnt; nCol++)
		{
			GetCell(nCol, nRow, &cell);
			// 20120723 ssj - 서버자동주문 >>
			//cell.SetBackColor(clrBk);
			if (nCol == 0)
			{
				CString strTemp = cell.GetText();
				if (strTemp == STR_ON)
					cell.SetBackColor(COLOR_STR_ON);
				else
					cell.SetBackColor(clrBk);
			}
			else
			{
				cell.SetBackColor(clrBk);	
			}
			// 20120723 ssj - 서버자동주문 <<

      //## Line Color ##
			//cell.SetBorderColor(&m_penGridLine);
			cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);

			SetCell(nCol, nRow, &cell);
		}
	}
}
*/
// 20120723 ssj - 서버자동주문 <<

void COrdGrid::OnRowChange(long oldrow, long newrow)
{
/*
	int nCount, nLength;
	COLORREF clrBk;
	CUGCell	cell;

	nLength = GetNumberCols();
	GetEvenOddBkColor(oldrow, clrBk);
	for (nCount = 0; nCount < nLength; nCount++)
	{
		if (oldrow != -1)
		{
			GetCell(nCount, oldrow, &cell);
			cell.SetBackColor(clrBk);
			SetCell(nCount, oldrow, &cell);
		}
		
		if (newrow != -1)
		{
			GetCell(nCount, newrow, &cell);
			cell.SetBackColor(clrSelRow);
			SetCell(nCount, newrow, &cell);
		}
	}

	m_nLastSelRow = newrow;
  
  CWnd *pwndParent = GetParent();
//  pwndParent->SendMessage(WM_NOTIFY_GRID, (WPARAM)NM_ITEM_CLK, (LPARAM)m_nLastSelRow);

	RedrawAll();
*/
}

// 20120723 ssj - 서버자동주문 >>
/*
inline void COrdGrid::GetEvenOddBkColor(int nRow, COLORREF &clrBk)
{
	clrBk = clrEvenRow;
	
	if (nRow % 2) 
		clrBk = clrOddRow;
}
*/
// 20120723 ssj - 서버자동주문 <<

void COrdGrid::OnSysColorChange() 
{
	CUGCtrl::OnSysColorChange();
	//m_GI->m_hdgDefaults->SetBackColor(m_pISkinColorManager->GetColor(COLOR_GRID_HEADER_INDEX));
}

void COrdGrid::OnDClicked(int col,long row, RECT *rect, POINT *point, BOOL processed)
{
// 	LONG dwData = MAKELONG(row, col);
// 	GetParent()->SendMessage(RMSG_DBCLICK, 0, dwData);
}

int COrdGrid::OnHint(int col, long row, int section, CString *string)
{
	//CUGCell cell;
	//ShowToolTip(col, row);

	return TRUE;
}

void COrdGrid::OnAdjustComponentSizes(RECT *grid, RECT *topHdg,RECT *sideHdg, 
													 RECT *cnrBtn,RECT *vScroll,
													 RECT *hScroll,RECT *tabs)
{
/*
	CRect  rtGrid;
	double dWidthCell = 0.0;
		  
	if (!m_bCallAdjustOneTime)
	{
		rtGrid = CRect(grid);
		dWidthCell = rtGrid.Width() - 1 - DGN_HEADER_SIZE[0];;

		SetColWidth(0, (int)DGN_HEADER_SIZE[0]);
		SetColWidth(1, (int)dWidthCell);

		m_bCallAdjustOneTime = TRUE;
		AdjustComponentSizes();
		m_bCallAdjustOneTime = FALSE;
	}
*/
}

inline void COrdGrid::GetSignColor(int nSign, COLORREF &clrSignText)
{
	// 20120723 ssj - 서버자동주문 >>
	/*
	//'3':하한,'4':하락,'5':보합,'6':상승,'7':상한
	switch (nSign)
	{
	case 7:		// 상한(화살표)
		clrSignText = RED;
	case 6:		// 상승(삼각형)
		clrSignText = RED;
		break;
	case 3:		// 하한(화살표)
		clrSignText = BLUE;
		break;
	case 4:		// 하락(삼각형)
		clrSignText = BLUE;
		break;
	case 5:		// 보합
	default:
		clrSignText = BLACK;
	}
	*/

	// 1:상한 2:상승 3:보합 4:하한 5:하락
	switch (nSign)
	{
	case 1:		// 상한(화살표)
		clrSignText = RED;
	case 2:		// 상승(삼각형)
		clrSignText = RED;
		break;
	case 3:		// 보합
		clrSignText = BLACK;
		break;
	case 4:		// 하한(화살표)
		clrSignText = BLUE;
		break;
	case 5:		// 하락(삼각형)
	default:
		clrSignText = BLUE;
	}
}


void COrdGrid::InsetCommar(CString& str1)
{
	// 20120723 ssj - 서버자동주문 >>
	str1.Trim();
	str1.Remove(',');
	// 20120723 ssj - 서버자동주문 <<

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
/*
void COrdGrid::PaintSelectRow(long oldrow, long newrow, BOOL bAdd)
{
	if (m_pISkinColorManager == NULL)
		return;

	if (GetNumberRows() - 1 < newrow)
		return;
	
	COLORREF clrBk;
	CUGCell	cell;
	
	int nColCnt = GetNumberCols();
	GetEvenOddBkColor(oldrow, clrBk);
	for (int nCol = 0; nCol < nColCnt; nCol++)
	{
		if (oldrow != -1)
		{
			GetCell(nCol, oldrow, &cell);
			cell.SetBackColor(clrBk);
			SetCell(nCol, oldrow, &cell);
		}
		
		if (newrow != -1)
		{
			GetCell(nCol, newrow, &cell);
			cell.SetBackColor(m_pISkinColorManager->GetColor(COLOR_GRID_SELECT_INDEX));
			SetCell(nCol, newrow, &cell);
		}
	}
	RedrawAll();
}
*/
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
/*
void COrdGrid::SetSelectRow(long oldrow, long newrow, BOOL bAdd)
{
	if (m_pISkinColorManager == NULL)
		return;

	if (GetNumberRows() - 1 < newrow)
		return;
	
	COLORREF clrBk;
	CUGCell	cell;
	
	int nColCnt = GetNumberCols();
	GetEvenOddBkColor(oldrow, clrBk);
	for (int nCol = 0; nCol < nColCnt; nCol++)
	{
		if (oldrow != -1)
		{
			GetCell(nCol, oldrow, &cell);
			// 20120723 ssj - 서버자동주문 >>
			//cell.SetBackColor(clrBk);
			if (nCol == 0)
			{
				CString strTemp = cell.GetText();
				if (strTemp == STR_ON)
					cell.SetBackColor(COLOR_STR_ON);
				else
					cell.SetBackColor(clrBk);
			}
			else
			{
				cell.SetBackColor(clrBk);	
			}
			// 20120723 ssj - 서버자동주문 <<

			SetCell(nCol, oldrow, &cell);
		}
		
		if (newrow != -1)
		{
			GetCell(nCol, newrow, &cell);
			// 20120723 ssj - 서버자동주문 >>
			//cell.SetBackColor(clrSelRow);
			if (nCol == 0)
			{
				CString strTemp = cell.GetText();
				if (strTemp == STR_ON)
					cell.SetBackColor(COLOR_STR_ON);
				else
					cell.SetBackColor(m_pISkinColorManager->GetColor(COLOR_GRID_SELECT_INDEX));
			}
			else
			{
				cell.SetBackColor(m_pISkinColorManager->GetColor(COLOR_GRID_SELECT_INDEX));	
			}
			// 20120723 ssj - 서버자동주문 <<

			SetCell(nCol, newrow, &cell);
		}
	}
	
	m_nLastSelRow = newrow;
	RedrawAll();

	if(!bAdd)
	{
// 		GetCell(COL_BUY_COND1_ACC, newrow, &cell);
// 		CString strCode = cell.GetOtherJongCode();
// 		if(strCode.IsEmpty())
// 			return;
// 
// 		CWnd *pParent = GetParent();
// 		pParent->SendMessage(WM_NOTIFY_GRID, (WPARAM)NM_GRID_CLK, (LPARAM)newrow);
	}
}
*/
// 20120723 ssj - 서버자동주문 <<

void COrdGrid::HideColumn(int nCol, BOOL bHide)
{
	if(bHide)
	{
		SetColWidth(nCol, 0);
	}
	else
	{
		SetColWidth(nCol, DGN_HEADER_SIZE[nCol]);
	}

	RedrawCol(nCol);
}

// void COrdGrid::ChangeGridColor(ST_GRIDCOLOR stGridColor)
// {
// 	if(!stGridColor.clrGridHeader)
// 		return;
// 	
// 	m_clrHeader = stGridColor.clrGridHeader;
// 	m_clrSelRow = stGridColor.clrGridHilight;
// 	
// 	int nCurRow = GetCurrentRow();
// 	CUGCell cell;
// 	for(int nCol = 0; nCol < GetNumberCols(); nCol++)
// 	{
// 		GetCell(nCol, -1, &cell);
// 		cell.SetBackColor(m_clrHeader);
// 		SetCell(nCol, -1, &cell);
// 		
// 		if(nCurRow > -1)
// 		{		
// 			GetCell(nCol, nCurRow, &cell);
// 			cell.SetBackColor(m_clrSelRow);
// 			SetCell(nCol, nCurRow, &cell);	
// 		}
// 	}	
// }

// 20120723 ssj - 서버자동주문 >>
/*
const		LPCTSTR		HEADNAME_BASE[] = {_T("시각"), _T("종목코드"), _T("종목명") };
const		int			HEADWIDTH_BASE[] = {90, 50, 90};

const   int       MAX_COL = 21;
#include "math.h"
#define COL_CODE      0
#define COL_NAME      1
void COrdGrid::SetHeader(CList <HeadInfoType, HeadInfoType&> *plistField)
{
	CUGCell	cell;

	ClearAll();
	//ZeroMemory(&m_nSortType, sizeof(int) * RESULT_FIELD_MAX);

	int nColCnt = plistField->GetCount();
	SetNumberCols(nColCnt + 3);

	int nCol = 0;
	GetColDefault(nCol, &cell);
	cell.SetAlignment(UG_ALIGNLEFT | UG_ALIGNVCENTER);
	//SetColDefault(nSetartHead, &cell);
	QuickSetText(nCol, -1, HEADNAME_BASE[nCol]);
	SetColWidth(nCol, HEADWIDTH_BASE[nCol]);
	QuickSetBackColor(nCol, -1, m_pISkinColorManager->GetColor(COLOR_GRID_HEADER_INDEX));
	QuickSetTextColor(nCol, -1, m_pISkinColorManager->GetColor(COLOR_GRID_TEXT_INDEX));
	QuickSetFont(nCol, -1, &m_fontDefault);
	m_nSortType[nCol] = 1;
	nCol++;

	GetColDefault(nCol, &cell);
	cell.SetAlignment(UG_ALIGNLEFT | UG_ALIGNVCENTER);
	//SetColDefault(nSetartHead, &cell);
	QuickSetText(nCol, -1, HEADNAME_BASE[nCol]);
	SetColWidth(nCol, HEADWIDTH_BASE[nCol]);
	QuickSetBackColor(nCol, -1, m_pISkinColorManager->GetColor(COLOR_GRID_HEADER_INDEX));
	QuickSetTextColor(nCol, -1, m_pISkinColorManager->GetColor(COLOR_GRID_TEXT_INDEX));
	QuickSetFont(nCol, -1, &m_fontDefault);
	m_nSortType[nCol] = 1;
	nCol++;

	GetColDefault(nCol, &cell);
	cell.SetAlignment(UG_ALIGNLEFT | UG_ALIGNVCENTER);
	//SetColDefault(nSetartHead, &cell);
	QuickSetText(nCol, -1, HEADNAME_BASE[nCol]);
	SetColWidth(nCol, HEADWIDTH_BASE[nCol]);
	QuickSetBackColor(nCol, -1, m_pISkinColorManager->GetColor(COLOR_GRID_HEADER_INDEX));
	QuickSetTextColor(nCol, -1, m_pISkinColorManager->GetColor(COLOR_GRID_TEXT_INDEX));
	QuickSetFont(nCol, -1, &m_fontDefault);
	m_nSortType[nCol] = 1;
	nCol++;

	POSITION   pos;
	HeadInfoType    stHeadType;
	for (int nIndex = 0; nIndex < nColCnt; nIndex++)
	{
		pos = plistField->FindIndex(nIndex);
		stHeadType = m_plistField->GetAt(pos);

		TRACE("\n # Count      : %d", nCol);
		TRACE("\n   # HeadName : %s", stHeadType.strHeadName);
		TRACE("\n   # HeadID   : %d", stHeadType.lHeadID);

		QuickSetAlignment(nCol, -1, UG_ALIGNVCENTER | UG_ALIGNCENTER);
		QuickSetText(nCol, -1, stHeadType.strHeadName);
		SetColWidth(nCol, (int)(stHeadType.nColWidth * (m_nFontWidth + 1)));
		SetRowHeight(nCol, m_nFontHeight + 4);
		QuickSetBackColor(nCol, -1, m_pISkinColorManager->GetColor(COLOR_GRID_HEADER_INDEX));
		QuickSetTextColor(nCol, -1, m_pISkinColorManager->GetColor(COLOR_GRID_TEXT_INDEX));
		QuickSetFont(nCol, -1, &m_fontDefault);

		if ((stHeadType.strDataType == "code") ||  //## 종목 CODE ##
			(stHeadType.strDataType == "candle")	|| //# 캔들
			(stHeadType.strDataType == "pattern") ||	//# 패턴
			(stHeadType.strDataType == "period")	// 기간
			)	
			m_nSortType[nCol] = 1;
		nCol++;
	}

	RedrawAll();
}
*/
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
/*
void COrdGrid::SetLockColumns(int nCol, BOOL bOffSet)
{
	if (bOffSet == TRUE)
		m_nFixCol = 2 + nCol;
	else
		m_nFixCol = nCol;

	LockColumns(m_nFixCol);
}
*/
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
/*
CString COrdGrid::FindCandleIdFromName(long lCandleID)
{
	CString strResult = "--";

	int i, nCount;
	POSITION pos;

	CandleInfo      TempCandleInfo;

	if (m_bCandleLoadFalg == FALSE)
		return strResult;

	nCount = m_listCnadle.GetCount() - 1;
	for (i = 0; i < nCount; i++)
	{
		pos = m_listCnadle.FindIndex(i);
		TempCandleInfo = m_listCnadle.GetAt(pos);

		if (TempCandleInfo.lID == lCandleID)
		{
			strResult = TempCandleInfo.strName;
			break;
		}
	}

	return strResult;
}
*/
// sj <<

// 20120723 ssj - 서버자동주문 >>
/*
BOOL COrdGrid::LoadCandleIndexToXml()
{
	MSXML::IXMLDOMNodePtr		      pNIndex;    // Header
	MSXML::IXMLDOMNodeListPtr	    pNS_FItem;  // Item List
	MSXML::IXMLDOMNodePtr			    pN_FItem;   // Item
	MSXML::IXMLDOMNamedNodeMapPtr	pNA_FItem;

	CandleInfo      TempCandleInfo;

	BOOL bResult = TRUE;
	VARIANT_BOOL bLoadedXMLFile;
	CString strIndexFilePath;
	//## Candle Index 파일 LOAD ##

	// 20120723 ssj - 서버자동주문 >>
	//GETPATH_APP(strAppPath);
	CString strAppPath;
	GetDir_DrfnRoot(strAppPath);
	// 20120723 ssj - 서버자동주문 <<

	strIndexFilePath = strAppPath + FOLDER_DATA + "\\" + CANDLE_INDEX_FILE;

	MSXML::IXMLDOMDocumentPtr pDOMConditionIndex ("Microsoft.XMLDOM", NULL, CLSCTX_INPROC_SERVER);
	pDOMConditionIndex->async = false;
	bLoadedXMLFile = pDOMConditionIndex->load(_bstr_t(strIndexFilePath));

	if(bLoadedXMLFile == VARIANT_FALSE) 
	{
		bResult = FALSE;
		return bResult;
	}

	m_listCnadle.RemoveAll();
	try {
		//# header의 node를 얻는다.
		pNIndex = pDOMConditionIndex->selectSingleNode("INDEX");
		pNS_FItem  = pNIndex->selectNodes("FITEM");

		int nCount, nLength;
		CString strTemp;

		nLength = pNS_FItem->length;
		for(nCount = 0; nCount < nLength; nCount++)
		{
			//# node를 얻어온다.
			pN_FItem = pNS_FItem->item[nCount];	

			//# 속성을 얻어온다.
			MSXML::IXMLDOMNodePtr	pNAttributeTemp;
			pNA_FItem= pN_FItem->attributes;

			//##### Each Filed Information START #####
			pNAttributeTemp = pNA_FItem->getNamedItem("ID");
			strTemp = CString((PCHAR)pNAttributeTemp->text);
			TempCandleInfo.lID = atol(strTemp);

			pNAttributeTemp = pNA_FItem->getNamedItem("FIELD_NAME");
			TempCandleInfo.strName = CString((PCHAR)pNAttributeTemp->text);
			//## Candle ID insert ##
			m_listCnadle.AddTail(TempCandleInfo);
		}
	}
	catch(...) {
		bResult = FALSE;
		return bResult;
	}

	return bResult;
}
*/
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
/*
CString COrdGrid::FindPatenIdFromName(long lPatenID)
{
	CString strResult = "--";

	int i, nCount;
	POSITION pos;

	PatenInfo      TempPatenInfo;

// 	if (m_bPatenLoadFalg == FALSE)
// 		return strResult;

	nCount = m_listPaten.GetCount() - 1;
	for (i = 0; i < nCount; i++)
	{
		pos = m_listPaten.FindIndex(i);
		TempPatenInfo = m_listPaten.GetAt(pos);

		if (TempPatenInfo.lID == lPatenID)
		{
			strResult = TempPatenInfo.strName;
			break;
		}
	}

	return strResult;
}
*/
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
/*
BOOL COrdGrid::LoadPatenIndexToXml()
{
	MSXML::IXMLDOMNodePtr		      pNIndex;    // Header
	MSXML::IXMLDOMNodeListPtr	    pNS_FItem;  // Item List
	MSXML::IXMLDOMNodePtr			    pN_FItem;   // Item
	MSXML::IXMLDOMNamedNodeMapPtr	pNA_FItem;

	PatenInfo      TempPatenInfo;

	BOOL bResult = TRUE;
	VARIANT_BOOL bLoadedXMLFile;
	CString strIndexFilePath;
	//## Candle Index 파일 LOAD ##

	// 20120723 ssj - 서버자동주문 >>
	//GETPATH_APP(strAppPath);
	CString strAppPath;
	GetDir_DrfnRoot(strAppPath);
	// 20120723 ssj - 서버자동주문 <<

	strIndexFilePath = strAppPath + FOLDER_DATA + "\\" + PATEN_INDEX_FILE;

	MSXML::IXMLDOMDocumentPtr pDOMConditionIndex ("Microsoft.XMLDOM", NULL, CLSCTX_INPROC_SERVER);
	pDOMConditionIndex->async = false;
	bLoadedXMLFile = pDOMConditionIndex->load(_bstr_t(strIndexFilePath));

	if(bLoadedXMLFile == VARIANT_FALSE) 
	{
		bResult = FALSE;
		return bResult;
	}

	m_listPaten.RemoveAll();
	try {
		//# header의 node를 얻는다.
		pNIndex = pDOMConditionIndex->selectSingleNode("INDEX");
		pNS_FItem  = pNIndex->selectNodes("FITEM");

		int nCount, nLength;
		CString strTemp;

		nLength = pNS_FItem->length;
		for(nCount = 0; nCount < nLength; nCount++)
		{
			//# node를 얻어온다.
			pN_FItem = pNS_FItem->item[nCount];	

			//# 속성을 얻어온다.
			MSXML::IXMLDOMNodePtr	pNAttributeTemp;
			pNA_FItem= pN_FItem->attributes;

			//##### Each Filed Information START #####
			pNAttributeTemp = pNA_FItem->getNamedItem("ID");
			strTemp = CString((PCHAR)pNAttributeTemp->text);
			TempPatenInfo.lID = atol(strTemp);

			pNAttributeTemp = pNA_FItem->getNamedItem("FIELD_NAME");
			TempPatenInfo.strName = CString((PCHAR)pNAttributeTemp->text);
			//## Candle ID insert ##
			m_listPaten.AddTail(TempPatenInfo);
		}
	}
	catch(...) {
		bResult = FALSE;
		return bResult;
	}

	return bResult;
}
*/
// 20120723 ssj - 서버자동주문 <<

CSize COrdGrid::GetFontSize()
{
	CClientDC	dc(this);
	CFont*	pOldFont = dc.SelectObject(m_GI->m_defFont);

	CSize	sizeFont;
	TEXTMETRIC	tm;

	dc.GetTextMetrics(&tm);
	sizeFont.cx	=	tm.tmAveCharWidth;
	sizeFont.cy	=	tm.tmHeight;

	dc.SelectObject(pOldFont);

	return	sizeFont;
}

int COrdGrid::GetCheckWatchState(int nRow, int nType)
{
	int nResult;
	CUGCell cell;

	if(nType == 2) //매수
	{
		GetCell(COL_BUY_COND1_ACC, nRow, &cell);
	}
	else if(nType == 1)//매도
	{
		GetCell(COL_BUY_COND1_ACC + 1, nRow, &cell);
	}

	//감시여부 체크	
	CString strCond = cell.GetLabelText();
	int nstate = (int)cell.GetParam();
	CString strCode = cell.GetOtherJongCode();
	if(strCode.IsEmpty())
		return STATE_NODATA;

	if(nstate == 1)
		nResult = STATE_WATCH;
	else if(nstate == 2)
		nResult = STATE_STOP;
	else
		nResult = STATE_ERROR;	

	return nResult;
}

// 20120723 ssj - 서버자동주문 >>
/*
BOOL COrdGrid::GetChecknRow(int nRow)
{
	CUGCell cell;
	//체크상태
	GetCell(0, nRow, &cell);
	BOOL bCheck = cell.GetBool();
	return bCheck;
}
*/
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
/*
void COrdGrid::SetAddRowSiseData(StItemPrice stItemPrice, int nMarketType)
{
	int nRow;
	CString strCode;
	COLORREF clr;
	CString strData;
	
	
	long lUnitPrice;	   //단가
	long lCurPrice;		   //현재가
	LONGLONG lPrice1, lPrice2; //평가금액, 매입금액
	LONGLONG lPrice;		   //평가손익
 
	int nBasePrice;				//기준금액(선물:50만, 옵션:10만, 주식선물:10)	
	double dUnitPrice;			//단가
	double dPrice1, dPrice2;	//평가금액, 약정금액
	double dCurPrice;			//현재가
	double dPrice;				//평가손익
	CString strPrice2;

	double dRate;				//손익률
	long   lVol;				//보유수량

	COLORREF clrText;
	double   dPoint = 1;
	stItemPrice.strCode.Trim();
	int nLastCol = GetNumberCols() - 1;


	if(nMarketType == CDRCodeTypeInfo::DRCODETYPE_KFUTURE)//선물
	{
		dPoint = 0.01;
		nBasePrice = 500000;
	}	
	else if(nMarketType == CDRCodeTypeInfo::DRCODETYPE_KOPTION)//옵션
	{
		dPoint = 0.01;
//		nBasePrice = 100000;
		nBasePrice = (int)dll_GetOptionMultiplier(stItemPrice.strCode);
	}
	else if(nMarketType == CDRCodeTypeInfo::DRCODETYPE_STOCKFUT || nMarketType == CDRCodeTypeInfo::DRCODETYPE_STOCKOPT)//주식선물
	{
		dPoint = 1;
		nBasePrice = 10;
	}
	else 
	{
		dPoint = 1;
		nBasePrice = 1;
	}

	dCurPrice = atof(stItemPrice.strCurPrice) * dPoint;	
	GetSignColor(atoi(stItemPrice.strSign), clr);


	int nRowCnt = GetNumberRows();
	for(nRow = 0; nRow < nRowCnt; nRow++)
	{
		CUGCell cell;
		GetCell(ITEMCODE_COL, nRow, &cell);
		strCode = cell.GetOtherJongCode();
		CString strtext = cell.GetText();

		if(strCode.CompareNoCase(stItemPrice.strCode) == 0)
		{
			if(dPoint != 1)	
			{	
				//보유수량
				GetCell(JANGO_VOL_COL, nRow, &cell);
				strData = cell.GetText();
				strData.Remove(',');
				lVol	= atol(strData);
				if(lVol == 0)
 					continue;

				//단가
				GetCell(UNITPRICE, nRow, &cell);
				strData = cell.GetText();
				strData.Remove(',');
				dUnitPrice = atol(strData);		

				//현재가
				strData.Format("%.2lf", dCurPrice);
				InsetCommar(strData);
				GetCell(CUR_PRICE, nRow, &cell);			
				cell.SetText(strData);			
				cell.SetTextColor(clr);
				SetGridStatie(cell, nRow);
				SetCell(CUR_PRICE, nRow, &cell);

				//평가금액
				dPrice1 = dCurPrice * lVol * nBasePrice;

				//매입금액
				GetCell(nLastCol, nRow, &cell);	
				strPrice2 = cell.GetText();
				dPrice2 = _atoi64(strPrice2);

				if(dPrice2 == 0)
					CString str = "sdf";
			//	dPrice2 = cell.GetOtherDataLong(); //약정금액 요기
			//	dPrice2 = dUnitPrice * lVol * nBasePrice;

				//평가손익
				dPrice = dPrice1 - dPrice2; 
				GetCell(COL_CREDIT_FOSELLBUY, nRow, &cell);
				strData = cell.GetText();
				if(strData.CompareNoCase("매도") == 0)
					dPrice = dPrice2 - dPrice1;

				//평가손익률
				dRate = (dPrice / dPrice2) * 100;

				if(dPrice < 0)
					clrText = BLUE;
				else if(dPrice > 0)
					clrText = RED;
				else 
					clrText = BLACK;

				//평가손익
				GetCell(EVALUATE_COL, nRow, &cell);	

				strData.Format("%lf", dPrice);
				strData.TrimRight('0');
				if(strData.Right(1) == ".")
					strData.Remove('.');			

				InsetCommar(strData);
				cell.SetText(strData);
				cell.SetTextColor(clrText);
				SetGridStatie(cell, nRow);
				SetCell(EVALUATE_COL, nRow, &cell);

				//평가손익률
				dRate = RoundOff(dRate);

				if(dRate < 0.0)
					clrText = BLUE;
				else if(dRate > 0.0)
					clrText = RED;
				else 
				{	
					dRate = 0.0;
					clrText = BLACK;
				}

				strData.Format("%.2lf%s", dRate, "%");
				GetCell(EVALUATERATE_COL, nRow, &cell);
				cell.SetText(strData);
				cell.SetTextColor(clrText);
				SetGridStatie(cell, nRow);
				SetCell(EVALUATERATE_COL, nRow, &cell);

				
				RedrawRow(nRow);
			}
			else
			{
				//보유수량
				GetCell(JANGO_VOL_COL, nRow, &cell);
				strData = cell.GetText();
				strData.Remove(',');
				lVol	= atol(strData);
 				if(lVol == 0)
 					continue;
				//단가
				GetCell(UNITPRICE, nRow, &cell);
				strData = cell.GetText();
				strData.Remove(',');
				lUnitPrice = atol(strData);

				//현재가
				lCurPrice = atol(stItemPrice.strCurPrice);	
				strData.Format("%ld", lCurPrice);
				InsetCommar(strData);
				GetCell(CUR_PRICE, nRow, &cell);			
				cell.SetText(strData);	
				cell.SetTextColor(clr);
				SetGridStatie(cell, nRow);
				SetCell(CUR_PRICE, nRow, &cell);
				

				//평가금액
				lPrice1 = lCurPrice * lVol * nBasePrice;

				//매입금액
				GetCell(nLastCol, nRow, &cell);	
				strPrice2 = cell.GetText();
				lPrice2 = _atoi64(strPrice2);
				//lPrice2 = cell.GetOtherDataLong(); //약정금액 요기
				//lPrice2 = lUnitPrice * lVol * nBasePrice;

				//평가손익
				lPrice = lPrice1 - lPrice2;

				if(lPrice < 0)
					clrText = BLUE;
				else if(lPrice > 0)
					clrText = RED;
				else 
					clrText = BLACK;
				GetCell(EVALUATE_COL, nRow, &cell);

				strData.Format("%I64d", lPrice);
				InsetCommar(strData);
				cell.SetText(strData);
				cell.SetTextColor(clrText);
				SetGridStatie(cell, nRow);
				SetCell(EVALUATE_COL, nRow, &cell);

				//손익률
				dRate = ((double)lPrice / lPrice2) * 100; //평가손익률
				dRate = RoundOff(dRate);

				if(dRate < 0.0)
					clrText = BLUE;
				else if(dRate > 0.0)
					clrText = RED;
				else 
				{	
					dRate = 0.0;
					clrText = BLACK;
				}

				strData.Format("%.2lf%s", dRate, "%");
				GetCell(EVALUATERATE_COL, nRow, &cell);
				cell.SetText(strData);
				cell.SetTextColor(clrText);
				SetGridStatie(cell, nRow);
				SetCell(EVALUATERATE_COL, nRow, &cell);
				
				RedrawRow(nRow);
			}			
		}
	}

}
*/
// 20120723 ssj - 서버자동주문 <<

void COrdGrid::SetAddRowOnCode(StItemPrice stItemPrice, int nMarketType)
{
// 	int nRow;
// 	CString strCode;
// 	COLORREF clr;
// 	CString strData;
// 
// 	int nBasePrice;
// 	double dUnitPrice;
// 	double dPrice1, dPrice2;
// 	double dCurPrice;
// 	double dPrice;//평가손익
// 	double dRate;//손익률
// 	long   lVol;
// 	COLORREF clrText;
// 	double   dPoint = 1;
// 	stItemPrice.strCode.Trim();

	int nRow;
	CString strCode;
	COLORREF clr;
	CString strData;


	//long lUnitPrice;	   //매입가
	long lCurPrice;		   //현재가
	LONGLONG lPrice1, lPrice2; //평가금액, 매입금액
	LONGLONG lPrice;		   //평가손익

	// 20140709 ssj - 거래승수 저장방식으로 변경 >> commented
	//int nBasePrice;				//기준금액(선물:50만, 옵션:10만, 주식선물:10)	
	// 20140709 ssj - 거래승수 저장방식으로 변경 <<

	//double dUnitPrice;			//매입가
	double dPrice1, dPrice2;	//평가금액, 약정금액
	double dCurPrice;			//현재가
	double dPrice;				//평가손익
	CString strPrice2;

	double dRate;				//손익률
	long   lVol;				//보유수량

	COLORREF clrText;
	double   dPoint = 1;
	stItemPrice.strCode.Trim();
	
	//int nLastCol = GetNumberCols() - 1;

	if(nMarketType == CDRCodeTypeInfo::DRCODETYPE_KFUTURE || nMarketType == CDRCodeTypeInfo::DRCODETYPE_KOPTION)
	{
		dPoint = 0.01;
		// 20140709 ssj - 거래승수 저장방식으로 변경 >> commented
		//nBasePrice = 500000;
		// 20140709 ssj - 거래승수 저장방식으로 변경 <<
	}
	else if(nMarketType == CDRCodeTypeInfo::DRCODETYPE_STOCKFUT || nMarketType == CDRCodeTypeInfo::DRCODETYPE_STOCKOPT)
	{
		dPoint = 1;
		// 20140709 ssj - 거래승수 저장방식으로 변경 >> commented
		//nBasePrice = 10;
		// 20140709 ssj - 거래승수 저장방식으로 변경 <<
	}
	else 
	{
		dPoint = 1;
		// 20140709 ssj - 거래승수 저장방식으로 변경 >> commented
		//nBasePrice = 1;
		// 20140709 ssj - 거래승수 저장방식으로 변경 <<
	}

	// 20120723 ssj - 서버자동주문 >>
	//dCurPrice = atof(stItemPrice.strCurPrice) * dPoint;
	dCurPrice = atof(stItemPrice.strCurPrice);
	// 20120723 ssj - 서버자동주문 <<
	GetSignColor(atoi(stItemPrice.strSign), clr);
	
	int nRowCnt = GetNumberRows();
	for(nRow = 0; nRow < nRowCnt; nRow++)
	{
		CUGCell cell;
		GetCell(ITEMCODE_COL, nRow, &cell);
		strCode = cell.GetOtherJongCode();
		CString strtext = cell.GetText();
		
		if(strCode.CompareNoCase(stItemPrice.strCode) == 0 )
		{
			//if(dPoint != 1)
			if (nMarketType == CDRCodeTypeInfo::DRCODETYPE_KFUTURE ||
				nMarketType == CDRCodeTypeInfo::DRCODETYPE_KOPTION ||
				nMarketType == CDRCodeTypeInfo::DRCODETYPE_STOCKFUT ||
				nMarketType == CDRCodeTypeInfo::DRCODETYPE_STOCKOPT)
			{		
				//보유수량
				GetCell(JANGO_VOL_COL, nRow, &cell);
				strData = cell.GetText();
				strData.Remove(',');
				lVol	= atol(strData);
 				if(lVol == 0)
 					continue;

				//매입가
				//GetCell(UNITPRICE, nRow, &cell);
				//strData = cell.GetText();
				//strData.Remove(',');
				//dUnitPrice = atof(strData);		

				// 20120723 ssj - 서버자동주문 >> 수정단가
				GetCell(COL_USER_PRICE, nRow, &cell);
				strData = cell.GetText();
				strData.Remove(',');
				double dUserPrice = atof(strData);
				// 20120723 ssj - 서버자동주문 <<

				//현재가
				strData.Format("%.2lf", dCurPrice);
				InsetCommar(strData);
				GetCell(CUR_PRICE, nRow, &cell);			
				cell.SetText(strData);			
				cell.SetTextColor(clr);
				// 20120723 ssj - 서버자동주문 >>
				cell.SetOtherDataLong(atoi(stItemPrice.strSign));
				// 20120723 ssj - 서버자동주문 <<
				SetGridStatie(cell, nRow);
				SetCell(CUR_PRICE, nRow, &cell);					
				
				//평가금액
				// 20140709 ssj - 거래승수 저장방식으로 변경 >>
				//dPrice1 = dCurPrice * lVol * nBasePrice;
				GetCell(COL_UNIT, nRow, &cell);
				CString strUnit = cell.GetText();
				double dUnit = atof(strUnit);
				dPrice1 = dCurPrice * lVol * dUnit;
				// 20140709 ssj - 거래승수 저장방식으로 변경 <<

				//매입금액(약정금액)
				GetCell(COL_COST, nRow, &cell);	
				strPrice2 = cell.GetText();
				dPrice2 = _atoi64(strPrice2);
				//dPrice2 = cell.GetOtherDataLong(); //약정금액 요기
				//dPrice2 = dUnitPrice * lVol * nBasePrice;		
				
				// 20120723 ssj - 서버자동주문 >>
				if (IsSame(dUserPrice, 0) == FALSE) // dUserPrice이 '0'이 아니면
				{
					// 20140709 ssj - 거래승수 저장방식으로 변경 >>
					//dPrice2 = dUserPrice * lVol * nBasePrice;
					dPrice2 = dUserPrice * lVol * dUnit;
					// 20140709 ssj - 거래승수 저장방식으로 변경 <<
				}
				// 20120723 ssj - 서버자동주문 <<

				//평가손익
				dPrice = dPrice1 - dPrice2; 
				GetCell(COL_CREDIT_FOSELLBUY, nRow, &cell);
				strData = cell.GetText();
				if(strData.CompareNoCase("매도") == 0)
					dPrice = dPrice2 - dPrice1;

				//평가손익률
				if (IsSame(dPrice2, 0) == FALSE)
					dRate = (dPrice / dPrice2) * 100;
				else
					dRate = 0;

				if (IsSame(dPrice, 0))
					clrText = BLACK;
				else if (IsGreater(dPrice, 0))
					clrText = m_clrUp; //RED;				
				else
					clrText = m_clrDown; //BLUE;

				//평가손익
				GetCell(EVALUATE_COL, nRow, &cell);	
				
				// 20120723 ssj - 서버자동주문 >>
				/*
				strData.Format("%lf", dPrice);
				strData.TrimRight('0');
				if(strData.Right(1) == ".")
					strData.Remove('.');			
				*/
				strData.Format("%.0f", dPrice);
				// 20120723 ssj - 서버자동주문 <<

				InsetCommar(strData);
				cell.SetText(strData);
				cell.SetTextColor(clrText);
				SetGridStatie(cell, nRow);
				SetCell(EVALUATE_COL, nRow, &cell);

				//평가손익률
				//dRate = RoundOff(dRate);
				strData.Format("%.2lf%s", dRate, "%");
				GetCell(EVALUATERATE_COL, nRow, &cell);
				cell.SetText(strData);
				cell.SetTextColor(clrText);
				SetGridStatie(cell, nRow);
				SetCell(EVALUATERATE_COL, nRow, &cell);
				RedrawRow(nRow);
			}
			else
			{
// 				//현재가
// 				GetCell(CUR_PRICE, nRow, &cell);
// 				strData = stItemPrice.strCurPrice;
// 				InsetCommar(strData);
// 				cell.SetText(strData);			
// 				cell.SetTextColor(clr);
// 				SetCell(CUR_PRICE, nRow, &cell);
// 				RedrawRow(nRow);

				//보유수량
				GetCell(JANGO_VOL_COL, nRow, &cell);
				strData = cell.GetText();
				strData.Remove(',');
				lVol	= atol(strData);
 				if(lVol == 0)
 					continue;

				// 20120723 ssj - 서버자동주문 >>
				/*
				//매입가
				GetCell(UNITPRICE, nRow, &cell);
				strData = cell.GetText();
				strData.Remove(',');
				lUnitPrice = atol(strData);
				*/
				// 20120723 ssj - 서버자동주문 <<

				// 20120723 ssj - 서버자동주문 >> 수정단가
				GetCell(COL_USER_PRICE, nRow, &cell);
				strData = cell.GetText();
				strData.Remove(',');
				long lUserPrice = atol(strData);
				// 20120723 ssj - 서버자동주문 <<

				//현재가
				lCurPrice = atol(stItemPrice.strCurPrice);	
				strData.Format("%ld", lCurPrice);
				InsetCommar(strData);
				GetCell(CUR_PRICE, nRow, &cell);			
				cell.SetText(strData);	
				// 20120723 ssj - 서버자동주문 >>
				cell.SetOtherDataLong(atoi(stItemPrice.strSign));
				// 20120723 ssj - 서버자동주문 <<
				cell.SetTextColor(clr);
				SetGridStatie(cell, nRow);
				SetCell(CUR_PRICE, nRow, &cell);

				// 20140709 ssj - 거래승수 저장방식으로 변경 >>
				int nBasePrice = 1; // 주식,ELW은 승수가 1
				// 20140709 ssj - 거래승수 저장방식으로 변경 <<

				//평가금액
				lPrice1 = lCurPrice * lVol * nBasePrice;

				//매입금액(약정금액)
				GetCell(COL_COST, nRow, &cell);	
				strPrice2 = cell.GetText();
				lPrice2 = _atoi64(strPrice2);
				//lPrice2 = cell.GetOtherDataLong(); //약정금액 요기
				//lPrice2 = lUnitPrice * lVol * nBasePrice;
				
				// 20120723 ssj - 서버자동주문 >>
				if (lUserPrice != 0) // 수정단가가 '0'이 아니면
				{
					lPrice2 = lUserPrice * lVol * nBasePrice;
				}
				// 20120723 ssj - 서버자동주문 <<

				//평가손익
				lPrice = lPrice1 - lPrice2;	
				
				GetCell(COL_CREDIT_FOSELLBUY, nRow, &cell);
				CString strCredit = cell.GetText();
				int nCredit = cell.GetOtherDataInt();
				if(strCredit.CompareNoCase("대주") == 0 || nCredit == 5)
					lPrice = lPrice2 - lPrice1; // 신용구분이 '대주'이면 거꾸로 계산

				if(lPrice < 0)
					clrText = BLUE;
				else if(lPrice > 0)
					clrText = RED;
				else 
					clrText = BLACK;
				GetCell(EVALUATE_COL, nRow, &cell);

				strData.Format("%I64d", lPrice);
				InsetCommar(strData);
				cell.SetText(strData);
				cell.SetTextColor(clrText);
				SetGridStatie(cell, nRow);
				SetCell(EVALUATE_COL, nRow, &cell);

				//손익률
				if (lPrice2 != 0)
					dRate = ((double)lPrice / lPrice2) * 100; //평가손익률
				else
					dRate = 0;

				strData.Format("%.2lf%s", dRate, "%");
				GetCell(EVALUATERATE_COL, nRow, &cell);
				cell.SetText(strData);
				cell.SetTextColor(clrText);
				SetGridStatie(cell, nRow);
				SetCell(EVALUATERATE_COL, nRow, &cell);

				RedrawRow(nRow);
			}			
		}
	}
}

//조건항목 조회시 Circle Setting
void COrdGrid::SetCondCircle(int nCol, int nRow, StOrdCondData stOrdGridData)
{
	CUGCell cell;

	if(stOrdGridData.strMMType == "2") //매수
	{
		// 20120723 ssj - 서버자동주문 >>
		QuickSetCellTypeEx(nCol, nRow, UGCELL_ORDCIRCLE_SET);
		// 20120723 ssj - 서버자동주문 <<

		if(stOrdGridData.strAuto == "0") //자동
		{
			if(stOrdGridData.strState == "1") //등록
			{
				//계좌+매수+자동+등록
				GetCell(nCol, nRow, &cell);
				cell.SetOrdCircleData(ORDTYPE_AUTO_REG_BUY);
				// 20120723 ssj - 서버자동주문 >>
				cell.SetOrdCircleBitmap(GetCircleBitmap(atol(ORDTYPE_AUTO_REG_BUY)));
				//TraceLog("BMP: [%d, %d] Set\n", nRow, nCol);
				// 20120723 ssj - 서버자동주문 <<
				cell.SetOtherDataCellText(stOrdGridData.strCondText);
				SetCell(nCol, nRow, &cell);
			}
			else if(stOrdGridData.strState == "2") //정지
			{
				//계좌+매수+자동+정지
				GetCell(nCol, nRow, &cell);
				cell.SetOrdCircleData(ORDTYPE_AUTO_STOP_BUY);
				// 20120723 ssj - 서버자동주문 >>
				cell.SetOrdCircleBitmap(GetCircleBitmap(atol(ORDTYPE_AUTO_STOP_BUY)));
				//TraceLog("BMP: [%d, %d] Set\n", nRow, nCol);
				// 20120723 ssj - 서버자동주문 <<
				cell.SetOtherDataCellText(stOrdGridData.strCondText);
				SetCell(nCol, nRow, &cell);
			}	
			else if(stOrdGridData.strState == "3") //삭제
			{
				RemoveCellInfo(nCol, nRow);
			}
		}
		else//반자동
		{
			if(stOrdGridData.strState == "1") //등록
			{
				//계좌+매수+반자동+등록
				GetCell(nCol, nRow, &cell);
				cell.SetOrdCircleData(ORDTYPE_SEMIAUTO_REG_BUY);
				// 20120723 ssj - 서버자동주문 >>
				cell.SetOrdCircleBitmap(GetCircleBitmap(atol(ORDTYPE_SEMIAUTO_REG_BUY)));
				//TraceLog("BMP: [%d, %d] Set\n", nRow, nCol);
				// 20120723 ssj - 서버자동주문 <<
				cell.SetOtherDataCellText(stOrdGridData.strCondText);
				SetCell(nCol, nRow, &cell);
			}
			else if(stOrdGridData.strState == "2") //정지
			{
				//계좌+매수+반자동+정지
				GetCell(nCol, nRow, &cell);
				cell.SetOrdCircleData(ORDTYPE_SEMIAUTO_STOP_BUY);
				// 20120723 ssj - 서버자동주문 >>
				cell.SetOrdCircleBitmap(GetCircleBitmap(atol(ORDTYPE_SEMIAUTO_STOP_BUY)));
				//TraceLog("BMP: [%d, %d] Set\n", nRow, nCol);
				// 20120723 ssj - 서버자동주문 <<
				cell.SetOtherDataCellText(stOrdGridData.strCondText);
				SetCell(nCol, nRow, &cell);
			}
			else if(stOrdGridData.strState == "3") //삭제
			{
				RemoveCellInfo(nCol, nRow);
			}
		}
	}
	else //매도
	{
		// 20120723 ssj - 서버자동주문 >>
		QuickSetCellTypeEx(nCol+1, nRow, UGCELL_ORDCIRCLE_SET);
		// 20120723 ssj - 서버자동주문 <<

		if(stOrdGridData.strAuto == "0") //자동
		{
			if(stOrdGridData.strState == "1") //등록
			{
				//계좌+매도+자동+등록
				GetCell(nCol+1, nRow, &cell);
				cell.SetOrdCircleData(ORDTYPE_AUTO_REG_SELL);
				// 20120723 ssj - 서버자동주문 >>
				cell.SetOrdCircleBitmap(GetCircleBitmap(atol(ORDTYPE_AUTO_REG_SELL)));
				//TraceLog("BMP: [%d, %d] Set\n", nRow, nCol);
				// 20120723 ssj - 서버자동주문 <<
				cell.SetOtherDataCellText(stOrdGridData.strCondText);
				SetCell(nCol+1, nRow, &cell);
			}
			else if(stOrdGridData.strState == "2") //정지
			{
				//계좌+매도+자동+정지
				GetCell(nCol+1, nRow, &cell);
				cell.SetOrdCircleData(ORDTYPE_AUTO_STOP_SELL);
				// 20120723 ssj - 서버자동주문 >>
				cell.SetOrdCircleBitmap(GetCircleBitmap(atol(ORDTYPE_AUTO_STOP_SELL)));
				//TraceLog("BMP: [%d, %d] Set\n", nRow, nCol);
				// 20120723 ssj - 서버자동주문 <<
				cell.SetOtherDataCellText(stOrdGridData.strCondText);
				SetCell(nCol+1, nRow, &cell);
			}
			else if(stOrdGridData.strState == "3") //삭제
			{
				RemoveCellInfo(nCol + 1, nRow);
			}
		}
		else//반자동
		{
			if(stOrdGridData.strState == "1") //등록
			{
				//계좌+매도+반자동+등록
				GetCell(nCol+1, nRow, &cell);
				cell.SetOrdCircleData(ORDTYPE_SEMIAUTO_REG_SELL);
				// 20120723 ssj - 서버자동주문 >>
				cell.SetOrdCircleBitmap(GetCircleBitmap(atol(ORDTYPE_SEMIAUTO_REG_SELL)));
				//TraceLog("BMP: [%d, %d] Set\n", nRow, nCol);
				// 20120723 ssj - 서버자동주문 <<
				cell.SetOtherDataCellText(stOrdGridData.strCondText);
				SetCell(nCol+1, nRow, &cell);
			}
			else if(stOrdGridData.strState == "2") //정지
			{
				//계좌+매도+반자동+정지
				GetCell(nCol+1, nRow, &cell);
				cell.SetOrdCircleData(ORDTYPE_SEMIAUTO_STOP_SELL);
				// 20120723 ssj - 서버자동주문 >>
				cell.SetOrdCircleBitmap(GetCircleBitmap(atol(ORDTYPE_SEMIAUTO_STOP_SELL)));
				//TraceLog("BMP: [%d, %d] Set\n", nRow, nCol);
				// 20120723 ssj - 서버자동주문 <<
				cell.SetOtherDataCellText(stOrdGridData.strCondText);
				SetCell(nCol+1, nRow, &cell);
			}
			else if(stOrdGridData.strState == "3") //삭제
			{
				RemoveCellInfo(nCol + 1, nRow);
			}
		}
	}
}

CString COrdGrid::GetCondCircleToolTip(int nCol, int nRow, StOrdCondData stOrdGridData)
{
	CUGCell cell;
	CString strTooltip;

	if(stOrdGridData.strMMType == "2") //매수
	{
		if(stOrdGridData.strAuto == "0") //자동
		{
			if(stOrdGridData.strState == "1") //등록
			{
				//계좌+매수+자동+등록
				GetCell(nCol, nRow, &cell);
				strTooltip = cell.GetOtherDataCellText();

			}
			else if(stOrdGridData.strState == "2") //정지
			{
				//계좌+매수+자동+정지
				GetCell(nCol, nRow, &cell);
				strTooltip = cell.GetOtherDataCellText();
			}		
		}
		else//반자동
		{
			if(stOrdGridData.strState == "1") //등록
			{
				//계좌+매수+반자동+등록
				GetCell(nCol, nRow, &cell);
				strTooltip = cell.GetOtherDataCellText();
			}
			else if(stOrdGridData.strState == "2") //정지
			{
				//계좌+매수+반자동+정지
				GetCell(nCol, nRow, &cell);
				strTooltip = cell.GetOtherDataCellText();
			}		
		}
	}
	else //매도
	{
		if(stOrdGridData.strAuto == "0") //자동
		{
			if(stOrdGridData.strState == "1") //등록
			{
				//계좌+매도+자동+등록
				GetCell(nCol+1, nRow, &cell);
				strTooltip = cell.GetOtherDataCellText();
			}
			else if(stOrdGridData.strState == "2") //정지
			{
				//계좌+매도+자동+정지
				GetCell(nCol+1, nRow, &cell);
				strTooltip = cell.GetOtherDataCellText();
			}	
		}
		else//반자동
		{
			if(stOrdGridData.strState == "1") //등록
			{
				//계좌+매도+반자동+등록
				GetCell(nCol+1, nRow, &cell);
				strTooltip = cell.GetOtherDataCellText();
			}
			else if(stOrdGridData.strState == "2") //정지
			{
				//계좌+매도+반자동+정지
				GetCell(nCol+1, nRow, &cell);
				strTooltip = cell.GetOtherDataCellText();
			}	
		}
	}
	return strTooltip;
}

void COrdGrid::ShowToolTip(int nCol, int nRow)
{
	CString strTip;
	CUGCell cell;

	GetCell(nCol, nRow, &cell);
	if (m_tipInfo.GetShowState() == FALSE)
	{
		CString strText;
		strText = cell.GetOtherDataCellText();

		strText.Trim();

		if (strText.IsEmpty() == TRUE)
			return;
		m_tipInfo.UpdateToolTip(this, strText, 1);
		m_tipInfo.Show(strText);
	}
}

CString COrdGrid::GetCreditText(CString strType)
{
	// 20120723 ssj - 서버자동주문 >>
	/*
	CString strText;
	if(strType.CompareNoCase("0") == 0)
		strText = _T("현금");
	else if(strType.CompareNoCase("1") == 0)
		strText = _T("유융");
	else if(strType.CompareNoCase("3") == 0)
		strText = _T("자융");
	else if(strType.CompareNoCase("5") == 0)
		strText = _T("유대");
	else if(strType.CompareNoCase("7") == 0)
		strText = _T("자대");
	else if(strType.CompareNoCase("8") == 0)
		strText = _T("주담");
	else if(strType.CompareNoCase("9") == 0)
		strText = _T("예담");
	else if(strType.CompareNoCase("A") == 0)
		strText = _T("수담");
	else if(strType.CompareNoCase("B") == 0)
		strText = _T("매담");
	else if(strType.CompareNoCase("C") == 0)
		strText = _T("채담");
	else if(strType.CompareNoCase("E") == 0)
		strText = _T("ELS담");	
	*/

	//0:현금, 
	//1 신용유통융자
	//3 신용자기융자
	//5 신용유통대주
	//7 신용자기대주
	//8 예탁주식담보신용대출
	CString strText;
	if(strType.CompareNoCase("0") == 0)
		strText = "현금";
	else if(strType.CompareNoCase("1") == 0)
		strText = "유통";
	else if(strType.CompareNoCase("3") == 0)
		strText = "자기";
	else if(strType.CompareNoCase("5") == 0)
		strText = "대주";
	else if(strType.CompareNoCase("7") == 0)
		strText = "대주";
	else if(strType.CompareNoCase("8") == 0)
		strText = "담보";
	else
		strText = strType;
	// 20120723 ssj - 서버자동주문 <<

	return strText;
}

void COrdGrid::RemoveCellInfo(int nCol, int nRow)
{
	CUGCell cell;
	GetCell(nCol, nRow, &cell);
	cell.SetOtherJongCode("");
	cell.SetOtherDataInt(0);
	cell.SetOtherDataLong(0);
	cell.SetParam(0);
	cell.SetLabelText("");
	cell.SetOrdCircleData("");
	// 20120723 ssj - 서버자동주문 >>
	cell.SetOrdCircleBitmap(NULL);
	//TraceLog("BMP: [%d, %d] NULL-------\n", nRow, nCol);
	// 20120723 ssj - 서버자동주문 <<
	cell.SetOtherDataCellText("");
	cell.SetText("");
	SetCell(nCol, nRow, &cell);
}

void COrdGrid::SetOrdCellState(StOrdCondData stOrdGridData, int nRow)
{	
	//조건항목 Circle 영역설정
//	COLORREF clrBk;
	// 20120723 ssj - 서버자동주문 >>
	//GetEvenOddBkColor(nRow, clrBk);
	// 20120723 ssj - 서버자동주문 <<
	//int nLastCol = GetNumberCols() - 1;
	CUGCell cell;
	int nCol;
	
	// 20120723 ssj - 서버자동주문 >>
	/*
	//체크박스
	GetCell(0, nRow, &cell);			
	cell.SetBackColor(clrBk);
	//cell.SetTextColor(BLACK);
	cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
	cell.SetBorderColor(&m_penGridLine);
	cell.SetOrdCircleData("");
	cell.SetCellType(UGCT_CHECKBOX);
	cell.SetCellTypeEx(UGCT_CHECKBOXCHECKMARK);
	SetCell(0, nRow, &cell);				
	*/
	int nButtonIndex = AddCellType(&m_ugButtonType);	
	GetCell(CEL_BTN_ONOFF, nRow, &cell);
	if (stOrdGridData.strState == "1") // 1: 감시중, 2: 휴면(중지)중
	{
		cell.SetText(STR_ON);
		cell.SetBackColor(COLOR_STR_ON);
	}
	else
	{
		cell.SetText(STR_OFF);
		cell.SetBackColor(m_clrBack);
	}
	cell.SetFont(&m_fontDefault);
	cell.SetCellType(nButtonIndex);
	cell.SetCellTypeEx(UGCT_BUTTONNOFOCUS);
	//cell.SetBorder(UG_BDR_RTHICK | UG_BDR_BTHICK);
	//cell.SetBackColor(clrBk);
	cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNCENTER);
	SetCell(CEL_BTN_ONOFF, nRow, &cell);
	// 20120723 ssj - 서버자동주문 <<

	//종목명 ~ 유효기간
	for(nCol = 1; nCol < COL_BUY_COND1_ACC; nCol++)
	{
		GetCell(nCol, nRow, &cell);			
		//cell.SetBackColor(clrBk);
		//cell.SetTextColor(BLACK);
		cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
		cell.SetFont(&m_fontDefault);
		//cell.SetBorderColor(&m_penGridLine);
		cell.SetOrdCircleData("");
		// 20120723 ssj - 서버자동주문 >>
		cell.SetOrdCircleBitmap(NULL);
		//TraceLog("BMP: [%d, %d] NULL-------\n", nRow, nCol);
		// 20120723 ssj - 서버자동주문 <<

		cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER);
		cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNLEFT);

		// 20120723 ssj - 서버자동주문 >> 수정단가인 경우는 초기값은 "0"
		if (nCol == COL_USER_PRICE)
			cell.SetText(_T("0"));
		else
			cell. SetText(_T(" "));
		// 20120723 ssj - 서버자동주문 <<

		SetCell(nCol, nRow, &cell);	
	}
	
	// 조건항목 CirCle
	for(nCol = COL_BUY_COND1_ACC; nCol <= ORDINFO_END_COL; nCol++)
	{
		QuickSetCellTypeEx(nCol, nRow, UGCELL_ORDCIRCLE_SET);
		GetCell(nCol, nRow, &cell);			
		//cell.SetBackColor(clrBk);
		//cell.SetTextColor(BLACK);
		cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
		//cell.SetBorderColor(&m_penGridLine);
		cell.SetOrdCircleData("");
		// 20120723 ssj - 서버자동주문 >>
		cell.SetOrdCircleBitmap(NULL);
		//TraceLog("BMP: [%d, %d] NULL-------\n", nRow, nCol);
		// 20120723 ssj - 서버자동주문 <<
		SetCell(nCol, nRow, &cell);	
	}			

	// 매체 초기화
	GetCell(COL_MTYPE, nRow, &cell);			
	cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
	cell.SetFont(&m_fontDefault);
	cell.SetOrdCircleData("");
	cell.SetOrdCircleBitmap(NULL);
	cell.SetOtherDataInt(0);
	cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER);
	cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNCENTER);
	cell. SetText(_T(""));
	SetCell(COL_MTYPE, nRow, &cell);	

	//삭제버튼
// 	int nState;
// 	CUGCell cellBuy, cellSell;
// 	GetCell(COL_BUY_COND1_ACC,  nRow, &cellBuy);
// 	GetCell(COL_BUY_COND1_ACC + 1, nRow, &cellSell);	
// 
// 	if(stOrdGridData.strMMType.CompareNoCase(SVRORD_MMTYPE_SELL) == 0)
// 		nState = cellBuy.GetParam();
// 	else
// 		nState = cellSell.GetParam();
// 
// 
// 	GetCell(nLastCol, nRow, &cell);
// 	if(stOrdGridData.strState.CompareNoCase("2") == 0) //2:S:정지
// 	{	
// 		int nButtonIndex = AddCellType(&m_ugButtonType);
// 		cell.SetCellType(nButtonIndex);
// 		cell.SetCellTypeEx(UGCT_BUTTONNOFOCUS);
// 		cell.SetText("X");
// 	}
// 	
// 	cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
// 	cell.SetFont(&m_fontDefault);	
// 	cell.SetBackColor(clrBk);
// 	cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNCENTER);
// 	SetCell(nLastCol, nRow, &cell);		
		
}

int COrdGrid::OpenMsgBoxDlg(int nMode)
{

	HINSTANCE hInstSave = AfxGetResourceHandle();
	AfxSetResourceHandle(theApp.m_hInstance);

	CMsgBoxDlg dlg(this, nMode);


	if(nMode == MB_MSGBOX_SELLBUYCANCEL)
		dlg.SetDlgText(_T("※ 삭제할 주문을 선택하여 주십시오"));
	else if(nMode == MB_MSGBOX_YESNO || nMode == MB_MSGBOX_OKCANCEL)
		dlg.SetDlgText(_T("※ 해당 조건을 삭제 하시겠습니까?"));
	else if(nMode == MB_MSGBOX_SELLBUYCANCEL_WATCH)
		dlg.SetDlgText(_T("※ 감시할 주문을 선택하여 주십시오."));
	else if(nMode == MB_MSGBOX_SELLBUYCANCEL_CLEAR)
		dlg.SetDlgText(_T("※ 해제(정지)할 주문을 선택하여 주십시오."));

	
	
	int nID = dlg.DoModal();	
	AfxSetResourceHandle(hInstSave);

	return nID;
}

void COrdGrid::SetGridStatie(CUGCell& cell, int nRow)
{
//	COLORREF clrBk;
	// 20120723 ssj - 서버자동주문 >>
	//GetEvenOddBkColor(nRow, clrBk);
	// 20120723 ssj - 서버자동주문 <<
	//cell.SetBackColor(clrBk);
	cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
	//cell.SetBorderColor(&m_penGridLine);
	cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER);
	cell.SetFont(&m_fontDefault);
	cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNRIGHT);
}

//매도가능수량수정
CString COrdGrid::GetCellCredit(int nRow, CString& strDate)
{
	CUGCell cell, cellDate;
	GetCell(COL_CREDIT_FOSELLBUY, nRow, &cell);
	CString strCredit = cell.GetText();

	GetCell(COL_LOANDATE, nRow, &cellDate);
	strDate = cellDate.GetText();

	return strCredit;
}

//>>[0000260] 손실제한률, 목표이익률 수익률이 자동으로 셋팅 SJ_KIM(20110720)
// 20120723 ssj - 서버자동주문 >>
/*
BOOL COrdGrid::GetRowInfoToCalcPNL(CString& strPrice, CString& strMMType)
{
	long bExist = FALSE;

	CString strCurCode, strName, strSelectedCode;
	CWnd* pView = GetParent();
	if(pView)
		pView->SendMessage(RMSG_GET_ITEMCODE, (WPARAM)&strCurCode, (LPARAM)&strName);	

	int nRow = m_nLastSelRow;
	CUGCell cellCode, cellPrice, cellType;
	GetCell(ITEMCODE_COL, m_nLastSelRow, &cellCode);
	strSelectedCode = cellCode.GetOtherJongCode();

	if(strCurCode.CompareNoCase(strSelectedCode) == 0)
	{
		bExist = TRUE;
	}
	else
	{
		int nIndex = 0;
		for(nIndex; nIndex < GetNumberRows(); nIndex++)
		{
			GetCell(ITEMCODE_COL, nIndex, &cellCode);
			strSelectedCode = cellCode.GetOtherJongCode();
			if(strCurCode.CompareNoCase(strSelectedCode) == 0)
			{
				bExist = TRUE;
				nRow = nIndex;
				break;
			}
		}
	}		

	GetCell(UNITPRICE, nRow, &cellPrice);
	strPrice = cellPrice.GetText();

	GetCell(COL_CREDIT_FOSELLBUY, nRow, &cellType);
	strMMType = cellType.GetText();	

	return bExist;
}
//<<[0000260] 손실제한률, 목표이익률 수익률이 자동으로 셋팅 SJ_KIM(20110720)
*/
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
CBitmap *COrdGrid::GetCircleBitmap(int nBmpIndex)
{
	nBmpIndex--;
	if (nBmpIndex < 0 || nBmpIndex >= 10)
		return NULL;
	
	CBitmap *pBmp = &(m_arBitmap[nBmpIndex]);
	return pBmp;
}
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
/*
BOOL COrdGrid::IsWatching(int nRow, int nSecBuySell)
{
	if (nSecBuySell == SEC_BUY)
	{
	}
	else if (nSecBuySell == SEC_SELL)
	{
	}
	else // SEC_BOTH
	{
	}

	CUGCell cell;
	GetCell(CEL_BTN_ONOFF, nRow, &cell);
	CString strOnOff = cell.GetText();
	return (strOnOff.CompareNoCase(STR_ON) == 0);
}
*/
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
/*
void COrdGrid::ChangeState(StOrdCondData stOrdCondData)
{
	int nRow = FindModifyRow(stOrdCondData);
	if (nRow < 0)
		return;

	CUGCell	cell;
	GetCell(0, nRow, &cell);
	if (stOrdCondData.strState == "1") // 1: 감시중, 2: 휴면(중지)중
		cell.SetText(STR_ON);
	else
		cell.SetText(STR_OFF);

	SetCell(0, nRow, &cell);
}
*/
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
void COrdGrid::ChangeItem(StOrdCondData stOrdCondData)
{
	int nRow = FindModifyRow(stOrdCondData);
	if (nRow < 0) // 없으면 추가
	{		
		nRow = SetAddRow(stOrdCondData);
	}
	else // 있으면 수정
	{
		COLORREF clrBk;
		// 20120723 ssj - 서버자동주문 >>
		//GetEvenOddBkColor(nRow, clrBk);
		// 20120723 ssj - 서버자동주문 <<
		
		// 온/오프 버튼
		AdjustOnOffBtn(nRow, stOrdCondData);

		// 수정단가 변경

		// 유효기간 변경

		//조건항목 CirCle 클리어
		int nStartCol = COL_BUY_COND1_ACC;
		if (stOrdCondData.strMMType.CompareNoCase(SVRORD_MMTYPE_SELL) == 0)
			nStartCol = COL_BUY_COND1_ACC + 1;

		for (int i = nStartCol; i <= ORDINFO_END_COL; i = i + 2)
			RemoveCellInfo(i, nRow);
		
		SetRestItem(nRow, stOrdCondData); //, clrBk);
	}

	// 잔고가 있다면 손익계산을 다시 하도록 호출(수정단가가 없어도 있다가 없어진 경우 일수도 있으모 재계산)
	RecalcProfit(nRow, stOrdCondData);
	
	RedrawRow(nRow);
}
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
void COrdGrid::RecalcProfit(int nRow, StOrdCondData stOrdCondData)
{
	CString strVol;
	QuickGetText(JANGO_VOL_COL, nRow, &strVol);
	strVol.Remove(',');
	strVol.Trim();

	if (atol(strVol) != 0)//  && atol(strUserPrice) > 0)
	{
		CString strUserPrice;
		QuickGetText(COL_USER_PRICE, nRow, &strUserPrice);
		strUserPrice.Remove(',');
		strUserPrice.Trim();
	
		StItemPrice stItemPrice;
		stItemPrice.strCode = stOrdCondData.strCode;
		stItemPrice.strCode.Trim();

		CString strCurPrice;
		QuickGetText(CUR_PRICE, nRow, &strCurPrice);
		strCurPrice.Remove(',');
		strCurPrice.Trim();
		stItemPrice.strCurPrice = strCurPrice;

		CUGCell cell;
		GetCell(CUR_PRICE, nRow, &cell);
		int nSign = cell.GetOtherDataLong();
		stItemPrice.strSign.Format("%d", nSign);
		
		int nMarketType = GetMarketType(stItemPrice.strCode);
		SetAddRowOnCode(stItemPrice, nMarketType);
	}
}
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
void COrdGrid::RemoveItem(StOrdCondData stOrdCondData)
{
	CString strMsg;
	int nRow = FindModifyRow(stOrdCondData);
	if (nRow < 0)
		return;
	
	int nState;
	BOOL bDeleteAll = TRUE;

	//현재 매도가 변경되어 들어온 경우
	if (stOrdCondData.strMMType.CompareNoCase(SVRORD_MMTYPE_SELL) == 0)
	{
		// 반대편인 매수측 조건이 있는지 체크
		nState = GetCheckWatchState(nRow, atol(SVRORD_MMTYPE_BUY));
		if (nState == STATE_WATCH || nState == STATE_STOP)
			bDeleteAll = FALSE;
	}

	// 현재 매수가 변경되어 들어온 경우
	else 
	{
		// 반대편인 매도측 조건이 있는지 체크
		nState = GetCheckWatchState(nRow, atol(SVRORD_MMTYPE_SELL));
		if (nState == STATE_WATCH || nState == STATE_STOP)
			bDeleteAll = FALSE;
	}			

	// 조건이 다 삭제인 경우
	if (bDeleteAll)	
	{
		CString strVol;
		QuickGetText(JANGO_VOL_COL, nRow, &strVol);
		strVol.Trim();

		// 잔고도 없다면 전체 행 삭제 
		if(strVol.IsEmpty())
		{
			DeleteRow(nRow);
			// 20120723 ssj - 서버자동주문 >>
			//if(m_nCondMaxRow > -1)
			//	m_nCondMaxRow--;
			// 20120723 ssj - 서버자동주문 <<
		}

		// 잔고가 있을 경우는 
		else
		{
			// 조건서클 관련 부분 전체를 클리어
			for(int nCodCol = COL_BUY_COND1_ACC; nCodCol <= ORDINFO_END_COL; nCodCol++)
				RemoveCellInfo(nCodCol, nRow);
			
			// ON-OFF 버튼 제거
			CUGCell cell;
			GetCell(CEL_BTN_ONOFF, nRow, &cell);
			cell.SetCellType(0); // 버튼제거
			cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
			cell.SetText(_T(""));
//			COLORREF clrBk;
			// 20120723 ssj - 서버자동주문 >>
			//GetEvenOddBkColor(nRow, clrBk);
			// 20120723 ssj - 서버자동주문 <<
			cell.SetBackColor(m_clrCellBack);
			SetCell(CEL_BTN_ONOFF, nRow, &cell);

			// 수정단가 제거
			GetCell(COL_USER_PRICE, nRow, &cell);
			cell.SetText(_T(""));
			SetCell(COL_USER_PRICE, nRow, &cell);

			// 유효기간 제거
			GetCell(COL_EXPIRE_DATE, nRow, &cell);
			cell.SetText(_T(""));
			cell.SetOtherDataInt(0);
			SetCell(COL_EXPIRE_DATE, nRow, &cell);

			GetCell(COL_EXPIRE_DATE + 1, nRow, &cell);
			cell.SetText(_T(""));
			cell.SetOtherDataInt(0);
			SetCell(COL_EXPIRE_DATE + 1, nRow, &cell);

			// 매체 제거
			GetCell(COL_MTYPE, nRow, &cell);
			cell.SetText(_T(""));
			cell.SetOtherDataInt(0);
			SetCell(COL_MTYPE, nRow, &cell);

			// X 버튼 제거
			GetCell(COL_BTN_X, nRow, &cell);
			cell.SetCellType(0); // 버튼제거
			cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
			cell.SetText(_T(""));
			SetCell(COL_BTN_X, nRow, &cell);
		}
	}

	// 조건이 남아 있는 경우
	else
	{
		int nStartCol = COL_BUY_COND1_ACC;

		// 조건서클들 둘중 하나 제거
		if (stOrdCondData.strMMType.CompareNoCase(SVRORD_MMTYPE_SELL) == 0)
			nStartCol = COL_BUY_COND1_ACC + 1;

		for (int i = nStartCol; i <= ORDINFO_END_COL; i = i + 2)
			RemoveCellInfo(i, nRow);

		CUGCell cell;
		// 유효기간도 제거
		int nCol = COL_EXPIRE_DATE;
		if (stOrdCondData.strMMType.CompareNoCase(SVRORD_MMTYPE_SELL) == 0)
			nCol++;
		GetCell(nCol, nRow, &cell);
		cell.SetText(_T(""));
		cell.SetOtherDataInt(0);
		SetCell(nCol, nRow, &cell);

		// 매체 지우면 안됨
		//GetCell(COL_MTYPE, nRow, &cell);
		//cell.SetText(_T(""));
		//cell.SetOtherDataInt(0);
		//SetCell(COL_MTYPE, nRow, &cell);

		// 매도면 수정단가도 제거
		if (stOrdCondData.strMMType.CompareNoCase(SVRORD_MMTYPE_SELL) == 0)
		{
			GetCell(COL_USER_PRICE, nRow, &cell);
			cell.SetText(_T(""));
			cell.SetOtherDataInt(0);
			SetCell(COL_USER_PRICE, nRow, &cell);
		}

		// 온오프 버튼 재처리
		GetCell(CEL_BTN_ONOFF, nRow, &cell);
		if (nState == STATE_WATCH)
		{
			cell.SetText(STR_ON);
			cell.SetBackColor(COLOR_STR_ON);
		}
		else
		{
			cell.SetText(STR_OFF);
			cell.SetBackColor(m_clrBack);
		}
		SetCell(CEL_BTN_ONOFF, nRow, &cell);
	}

	// 잔고가 있다면 손익계산을 다시 하도록 호출(수정단가가 없어도 있다가 없어진 경우 일수도 있으모 재계산)
	RecalcProfit(nRow, stOrdCondData);

	RedrawRow(nRow);
}
// 20120723 ssj - 서버자동주문 <<


// 20120723 ssj - 서버자동주문 >>
void COrdGrid::SetRestItem(int nRow, StOrdCondData stOrdGridData) //, COLORREF clrBk)
{
	CUGCell cell;

	//종목코드
	GetCell(ITEMCODE_COL, nRow, &cell);
	//cell.SetBackColor(clrBk);
 //	cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
 	//cell.SetBorderColor(&m_penGridLine);
 	cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER); 
	cell.SetFont(&m_fontDefault);
 	cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNLEFT);
	
	/*
	if (stOrdGridData.nMarket == CDRCodeTypeInfo::DRCODETYPE_KFUTURE || 
		stOrdGridData.nMarket == CDRCodeTypeInfo::DRCODETYPE_KOPTION)
	{
		cell.SetText(stOrdGridData.strCode);
	}
	else
	{
		cell.SetText(stOrdGridData.strItemName);
	}
	*/
	cell.SetText(stOrdGridData.strItemName);

	cell.SetOtherJongCode(stOrdGridData.strCode);
	SetCell(ITEMCODE_COL, nRow, &cell);

	// 20120723 ssj - 서버자동주문 >> 수정단가
	GetCell(COL_USER_PRICE, nRow, &cell);	
	//cell.SetBackColor(clrBk);
	//cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
	//cell.SetBorderColor(&m_penGridLine);
	cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER);
	cell.SetFont(&m_fontDefault);
	cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNRIGHT);
	CString strData;
	if (stOrdGridData.strMMType.CompareNoCase(SVRORD_MMTYPE_SELL) == 0)
	{
		// 매도 경우만 처리
		double dUserPrice = atof(stOrdGridData.strUserPrice);
		if (IsSame(dUserPrice, 0.0) == FALSE)
		{
			if (stOrdGridData.nMarket == CDRCodeTypeInfo::DRCODETYPE_KOSPI_STOCK || 
				stOrdGridData.nMarket == CDRCodeTypeInfo::DRCODETYPE_KOSDAQ_STOCK || 
				stOrdGridData.nMarket == CDRCodeTypeInfo::DRCODETYPE_ELW)
			{
				strData.Format("%0.f", dUserPrice);
			}
			else
			{
				strData.Format("%.2f", dUserPrice);
			}
			InsetCommar(strData);
		}
		cell.SetText(strData);
	}
	else
	{
		// 매수인 경우는 값이 있으면(0이 아니면) 그냥두고 없으면 처리
		CString strExist = cell.GetText();
		strExist.Trim();
		if (strExist.GetLength() <= 0 || IsSame(atof(strExist), 0.0))
			cell.SetText(_T(""));
	}	
	SetCell(COL_USER_PRICE, nRow, &cell);
	// 20120723 ssj - 서버자동주문 <<

	//구분
	GetCell(COL_CREDIT_FOSELLBUY, nRow, &cell);
	//cell.SetBackColor(clrBk);
	//cell.SetBorderColor(&m_penGridLine);
	cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER); 
	cell.SetFont(&m_fontDefault);
	cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNCENTER);

	//자동주문등록은 신용상세구분이 없어 일단 두가지로 구분
	if (stOrdGridData.nMarket == CDRCodeTypeInfo::DRCODETYPE_KFUTURE || 
		stOrdGridData.nMarket == CDRCodeTypeInfo::DRCODETYPE_KOPTION ||
		stOrdGridData.nMarket == CDRCodeTypeInfo::DRCODETYPE_STOCKFUT || 
		stOrdGridData.nMarket == CDRCodeTypeInfo::DRCODETYPE_STOCKOPT)
	{
		//cell.SetText("");
	}
	else
	{
		// 20120723 ssj - 서버자동주문 >>
		/*
		if(stOrdGridData.strCredit.CompareNoCase("0") == 0)
			cell.SetText("현금");
		else if(stOrdGridData.strCredit.CompareNoCase("3") == 0)
			cell.SetText("자융");
		else if(stOrdGridData.strCredit.CompareNoCase("1") == 0)
			cell.SetText("유융");
		*/
		CString strText = GetCreditText(stOrdGridData.strCredit);
		cell.SetText(strText);
		// 20120723 ssj - 서버자동주문 <<
	}	
	cell.SetOtherDataInt(atoi(stOrdGridData.strCredit));
	SetCell(COL_CREDIT_FOSELLBUY, nRow, &cell);

	//대출일
	CString strDate;
	if(stOrdGridData.strLoanDate == "")
		strDate = "";
	else
		strDate.Format("%s-%s-%s", stOrdGridData.strLoanDate.Left(4), stOrdGridData.strLoanDate.Mid(4, 2), stOrdGridData.strLoanDate.Mid(6, 2));
	GetCell(COL_LOANDATE, nRow, &cell);
	//cell.SetBackColor(clrBk);
	//cell.SetBorderColor(&m_penGridLine);
	cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER); 
	cell.SetFont(&m_fontDefault);
	cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNLEFT);
	cell.SetOtherDataInt(atoi(stOrdGridData.strLoanDate));
	cell.SetText(strDate);
	SetCell(COL_LOANDATE, nRow, &cell);

	//유효기간	
	if(stOrdGridData.strExpiredData.GetLength() >= 8)
	{
		//strDate.Format("%s-%s-%s", stOrdGridData.strExpiredData.Left(4), stOrdGridData.strExpiredData.Mid(4, 2), stOrdGridData.strExpiredData.Mid(6, 2));
		strDate.Format("%s/%s", stOrdGridData.strExpiredData.Mid(4, 2), stOrdGridData.strExpiredData.Mid(6, 2));
	}
	else
	{
		strDate = "";
	}
	GetCell(COL_EXPIRE_DATE, nRow, &cell);
	//cell.SetBackColor(clrBk);
	//cell.SetBorderColor(&m_penGridLine);
	cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER); 
	cell.SetFont(&m_fontDefault);
	cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNLEFT);
	cell.SetOtherDataInt(atoi(stOrdGridData.strExpiredData));
	cell.SetText(strDate);
	if(stOrdGridData.strMMType.CompareNoCase(SVRORD_MMTYPE_SELL) == 0)
	{
		cell.SetTextColor(m_clrDown);
		SetCell(COL_EXPIRE_DATE + 1, nRow, &cell);
	}
	else
	{
		cell.SetTextColor(m_clrUp);
		SetCell(COL_EXPIRE_DATE, nRow, &cell);
	}

	//손익조건
	int nCol;
	if(atol(stOrdGridData.strCondAcc) > 0) //stOrdGridData.strCondAcc == "1")
	{
		nCol = COL_BUY_COND1_ACC;
		SetCondCircle(nCol, nRow, stOrdGridData);
	}

	//시세조건
	if(atol(stOrdGridData.strCondPrice) > 0) //stOrdGridData.strCondPrice == "1")
	{
		nCol = COL_BUY_COND1_ACC + 2;		
		SetCondCircle(nCol, nRow, stOrdGridData);
	}

	//BM조건
	if(atol(stOrdGridData.strCondItem) > 0) //stOrdGridData.strCondItem == "1")
	{	
		nCol = COL_BUY_COND1_ACC + 4;
		SetCondCircle(nCol, nRow, stOrdGridData);
	}	

	//지표조건
	if(atol(stOrdGridData.strCondIndex) > 0)//stOrdGridData.strCondIndex == "1")
	{	
		nCol = COL_BUY_COND1_ACC + 6;
		SetCondCircle(nCol, nRow, stOrdGridData);
	}

	//매수, 매도셀 구분
	int nOrdInfoCol = COL_BUY_COND1_ACC; //매수주문정보(Key)저장 Col , 매도주분정보는 nOrdInfoCol+1
	if(stOrdGridData.strMMType.CompareNoCase(SVRORD_MMTYPE_SELL) == 0)
		nOrdInfoCol++;

	//주문정보(Key) Setting
	GetCell(nOrdInfoCol, nRow, &cell);
	cell.SetOtherJongCode(stOrdGridData.strCode);
	cell.SetOtherDataInt(atoi(stOrdGridData.strMMType));
	cell.SetOtherDataLong(atol(stOrdGridData.strCredit));
	cell.SetParam(atol(stOrdGridData.strState));

	CString strCond = stOrdGridData.strAuto + stOrdGridData.strCondAcc + stOrdGridData.strCondPrice + stOrdGridData.strCondItem + stOrdGridData.strCondIndex;
	cell.SetLabelText(strCond);
	SetCell(nOrdInfoCol, nRow, &cell);

	// 매체
	GetCell(COL_MTYPE, nRow, &cell);
	cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER); 
	cell.SetFont(&m_fontDefault);
	cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNCENTER);
	cell.SetText(GetMassText(stOrdGridData.strHtsMtsMp));
	cell.SetOtherDataInt(atol(stOrdGridData.strHtsMtsMp));
	SetCell(COL_MTYPE, nRow, &cell);

	//삭제버튼
	// 20120723 ssj - 서버자동주문 >>
	/*
	int nDelCol = COL_BTN_X;

	int nState;
	CUGCell cellBuy, cellSell;
	GetCell(COL_BUY_COND1_ACC,  nRow, &cellBuy);
	GetCell(COL_BUY_COND1_ACC + 1, nRow, &cellSell);	

	if(stOrdGridData.strMMType.CompareNoCase(SVRORD_MMTYPE_SELL) == 0)
		nState = cellBuy.GetParam();
	else
		nState = cellSell.GetParam();
	*/
	// 20120723 ssj - 서버자동주문 <<

	GetCell(COL_BTN_X, nRow, &cell);
//	if(stOrdGridData.strState.CompareNoCase("2") == 0) //2:S:정지
//	{	
		int nButtonIndex = AddCellType(&m_ugButtonType);
		cell.SetCellType(nButtonIndex);
		cell.SetCellTypeEx(UGCT_BUTTONNOFOCUS);
		cell.SetText("X");
//	}

	// 20120723 ssj - 서버자동주문 >>
	//cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
	//cell.SetBorder(UG_BDR_RTHICK | UG_BDR_BTHICK);
	// 20120723 ssj - 서버자동주문 <<
	cell.SetFont(&m_fontDefault);	
	//cell.SetBackColor(clrBk);
	cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNCENTER);
	SetCell(COL_BTN_X, nRow, &cell);		
	
	// 20120723 ssj - 서버자동주문 >>
	//m_nCondMaxRow++;
	// 20120723 ssj - 서버자동주문 <<
	RedrawAll();
}

// 20120723 ssj - 서버자동주문 >>
void COrdGrid::MakeCellForCondtion(int nRow)
{
//	COLORREF clrBk;
	// 20120723 ssj - 서버자동주문 >>
	//GetEvenOddBkColor(nRow, clrBk);
	// 20120723 ssj - 서버자동주문 <<
	CUGCell cell;

	// 유효기간
	for (int i = COL_EXPIRE_DATE; i < COL_BUY_COND1_ACC; i++)
	{
		GetCell(i, nRow, &cell);			
		//cell.SetBackColor(clrBk);
		//cell.SetTextColor(BLACK);
		cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
		//cell.SetBorderColor(&m_penGridLine);
		cell.SetOrdCircleData("");
		cell.SetOrdCircleBitmap(NULL);
		cell.SetOtherJongCode("");
		cell.SetOtherDataInt(0);
		cell.SetOtherDataLong(0);
		cell.SetParam(0);
		cell.SetLabelText("");
		cell.SetOtherDataCellText("");
		cell.SetText("");
		SetCell(i, nRow, &cell);	
	}

	// 조건서클
	for (int i = COL_BUY_COND1_ACC; i <= ORDINFO_END_COL; i++)
	{
		QuickSetCellTypeEx(i, nRow, UGCELL_ORDCIRCLE_SET);
		GetCell(i, nRow, &cell);			
		//cell.SetBackColor(clrBk);
		//cell.SetTextColor(BLACK);
		cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
		//cell.SetBorderColor(&m_penGridLine);
		cell.SetOrdCircleData("");
		cell.SetOrdCircleBitmap(NULL);
		cell.SetOtherJongCode("");
		cell.SetOtherDataInt(0);
		cell.SetOtherDataLong(0);
		cell.SetParam(0);
		cell.SetLabelText("");
		cell.SetOtherDataCellText("");
		cell.SetText("");
		SetCell(i, nRow, &cell);	
	}

	// 매체
	GetCell(COL_MTYPE, nRow, &cell);			
	cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
	cell.SetOrdCircleData("");
	cell.SetOrdCircleBitmap(NULL);
	cell.SetOtherJongCode("");
	cell.SetOtherDataInt(0);
	cell.SetOtherDataLong(0);
	cell.SetParam(0);
	cell.SetLabelText("");
	cell.SetOtherDataCellText("");
	cell.SetText("");
	SetCell(COL_MTYPE, nRow, &cell);	

	// ON-OFF

	// 수정단가
	GetCell(COL_USER_PRICE, nRow, &cell);
	//cell.SetBackColor(clrBk);
	//cell.SetTextColor(BLACK);
	cell.SetDataType(UGCELLDATA_STRING | UGCELLDATA_OTHER);
	cell.SetFont(&m_fontDefault);
	cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNRIGHT);
	cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
	//cell.SetBorderColor(&m_penGridLine);
	cell.SetOrdCircleData("");
	cell.SetOrdCircleBitmap(NULL);
	cell.SetText(_T(""));
	SetCell(COL_USER_PRICE, nRow, &cell);	

	// X버튼
}
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
void COrdGrid::OnMouseMove(int col,long row,POINT *point,UINT nFlags,BOOL processed)
{
	if (m_ptMouseColRow.x != col || m_ptMouseColRow.y != row)
	{
		KillTimer(TID_TOOTIP);

		m_ptMouseColRow.x = col;
		m_ptMouseColRow.y = row;
	}
	else
	{
		if (m_tipInfo.GetShowState() == FALSE)
		{
			SetTimer(TID_TOOTIP, 300, NULL);
		}
	}

	//CString strTemp;
	//strTemp.Format("pt1: %d, %d", point->x, point->y);
	////TRACEP("2", strTemp);
}
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
void COrdGrid::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == TID_TOOTIP)
	{
		KillTimer(TID_TOOTIP);

		POINT point;
		int col;
		long row;
		GetCursorPos(&point);
		ScreenToClient(&point);
		point.y = point.y - HEIGHT_HEATHER;
	
		//CString strTemp;
		//strTemp.Format("pt2: %d, %d", point.x, point.y);
		////TRACEP("4", strTemp);

		GetCellFromPoint(point.x,point.y,&col,&row);
		
		if (m_ptMouseColRow.x == col && m_ptMouseColRow.y == row)
			ShowToolTip(col, row);

		//CString strMsg;
		//strMsg.Format("%d, %d, %d, %d", m_ptMouseColRow.x, m_ptMouseColRow.y, col, row);
		////TRACEP("1", strMsg);


	}
}
// 20120723 ssj - 서버자동주문 <<

void COrdGrid::OnGetCell(int col, long row, CUGCell *cell)
{
	//cell->SetHBackColor(m_clrSelect);
	//cell->SetHTextColor(m_clrText);
	
	COLORREF clrBack = m_clrSelect;
	COLORREF clrText = m_clrText;
	CString strText = cell->GetText();
	strText.Trim();
	CString strTemp = strText;
	int nSign = 3; // 3: 보합
	
	switch (col)
	{
	case CEL_BTN_ONOFF:
		if (strText == STR_ON)
			clrBack = COLOR_STR_ON;
		break;

	case CUR_PRICE:
		nSign = cell->GetOtherDataLong();
		GetSignColor(nSign, clrText);
		break;
	case EVALUATE_COL:
	case EVALUATERATE_COL:
		strTemp.Trim();
		strTemp.Remove('%');
		strTemp.Remove(',');
		if (IsSame(atof(strTemp), 0)) // 0 이면
			clrText = m_clrText;
		else if (IsGreater(atof(strTemp), 0))
			clrText = m_clrUp;
		else
			clrText = m_clrDown;
		break;
	case COL_EXPIRE_DATE:
		clrText = m_clrUp;
		break;
	case COL_EXPIRE_DATE + 1:
		clrText = m_clrDown;
		break;
	case COL_CREDIT_FOSELLBUY:
		clrText = GetFOPositionTypeColor(strText);
	}

	cell->SetHBackColor(clrBack);
	cell->SetHTextColor(clrText);
}


LRESULT COrdGrid::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	if(message == RMSG_MAINSKINCHANGE)
	{
		SetOrdGridColor();
		RedrawAll();
	}

	return CUGCtrl::WindowProc(message, wParam, lParam);
}

void COrdGrid::SetOrdGridColor()
{
	if (m_pISkinColorManager == NULL)
		return;

	COLORREF clrHeaderLeft		= m_pISkinColorManager->GetColor(UGSKIN_COLOR_HEADEROUTERLINE_INDEX);
	COLORREF clrHeaderRight		= m_pISkinColorManager->GetColor(UGSKIN_COLOR_HEADEROUTERLINE_INDEX);
	COLORREF clrHeaderTop		= m_pISkinColorManager->GetColor(UGSKIN_COLOR_HEADEROUTERLINE_INDEX);
	COLORREF clrBorderLeft		= m_pISkinColorManager->GetColor(UGSKIN_COLOR_GRIDOUTERLINE);
	COLORREF clrBorderRight		= m_pISkinColorManager->GetColor(UGSKIN_COLOR_GRIDOUTERLINE);
	COLORREF clrBorderBottom	= m_pISkinColorManager->GetColor(UGSKIN_COLOR_GRIDOUTERLINE);

	int nSize = 1;
	QuickSetHBdrLeft(nSize, clrHeaderLeft);				// 헤더의 왼쪽 라인색
	QuickSetHBdrRight(nSize, clrHeaderRight);			// 헤더의 오른쪽 라인색
	QuickSetHBdrTop(nSize, clrHeaderTop);				// 헤더의 위쪽 라인색
	QuickSetBdrLeft(nSize, clrBorderLeft);				// 그리드의 왼쪽 라인색
	QuickSetBdrRight(nSize, clrBorderRight);			// 그리드의 오른쪽 라인색
	QuickSetBdrBottom(nSize, clrBorderBottom);			// 그리드의 아래쪽 라인색

	//////////////////////////////////////////////////////////////////////////
	// 헤더 색상 지정
	COLORREF clrHeader			= m_pISkinColorManager->GetColor(UGSKIN_COLOR_HEADER_INDEX);
	COLORREF clrGuidLine		= m_pISkinColorManager->GetColor(UGSKIN_COLOR_GRIDOUTERLINE);
	COLORREF clrBorder			= m_pISkinColorManager->GetColor(UGSKIN_COLOR_CELLLINE_INDEX);
	m_clrBack					= m_pISkinColorManager->GetColor(UGSKIN_COLOR_BACKGROUND_INDEX);

	// 20090209 권휘영 >> Insert
	m_clrHeader					= clrHeader;
	m_clrEvenRow				= m_pISkinColorManager->GetColor(UGSKIN_COLOR_EVENROW);
	m_clrOddRow					= m_pISkinColorManager->GetColor(UGSKIN_COLOR_ODDROW);
	// 20090209 권휘영  <<
	m_clrText					= m_pISkinColorManager->GetColor(UGSKIN_COLOR_BSKIN_TEXT_INDEX);
	m_clrUp						= m_pISkinColorManager->GetColor(UGSKIN_COLOR_TEXTUP_INDEX);
	m_clrDown					= m_pISkinColorManager->GetColor(UGSKIN_COLOR_TEXTDOWN_INDEX);

	SetColorTextUp(m_clrUp);			// 상승색을 저장한다.
	SetColorTextDown(m_clrDown);		// 하락색을 저장한다.
	SetColorTextDef(m_clrText);			// 디폴트색을 저장한다.

	// 헤더 라인색 지정
	m_PenHeaderLine->DeleteObject();
	m_PenHeaderLine->CreatePen(PS_SOLID, 1, clrGuidLine);

	//////////////////////////////////////////////////////////////////////////
	// 셀 라인 스타일을 지정한다.
	m_PenBorderLine->DeleteObject();
	m_PenBorderLine->CreatePen(PS_DOT, 1, clrBorder);

	//////////////////////////////////////////////////////////////////////////
	// 헤더 셀 없는 바탕 배경 색상 지정
	(*m_GIList)->m_hdgDefaults->SetBackColor(clrHeader);

	//////////////////////////////////////////////////////////////////////////
	// 그리드를 선택했을때의 색상을 가져온다.
	m_clrSelect = m_pISkinColorManager->GetColor(UGSKIN_COLOR_SELECT_INDEX);

	//////////////////////////////////////////////////////////////////////////
	// 셀의 바탕색을 바꾼다.
	m_clrCellBack = m_pISkinColorManager->GetColor(UGSKIN_COLOR_BACKGROUND_INDEX);

	for(int nRow = 0; nRow < GetNumberRows(); nRow++)
	{
		SetCellSkin(nRow);
	}

	//////////////////////////////////////////////////////////////////////////
	// OnGetCell Set
	SetHighlightRow(TRUE);
	SetCurrentCellMode(2);
}

void COrdGrid::SetCellSkin(int nRow)
{
	// 20090209 권휘영 >> Insert
	COLORREF clrBk = m_clrCellBack;
	// 20090209 권휘영  <<

	for(int nCol = 0; nCol < GetNumberCols(); nCol++)
	{
		// 20090209 권휘영 >> Insert
		if (m_bEvenOddClr)
		{
			clrBk = m_clrOddRow;
			int nIndex = nRow % 2;
			if (nIndex < 1)
				clrBk = m_clrEvenRow;
		}
		// 20090209 권휘영  <<

		GetCell(nCol, nRow, &m_cell);
		m_cell.SetBorder(UG_BDR_RTHIN | UG_BDR_BTHIN);
		m_cell.SetBorderColor(m_PenBorderLine);
		// 20090209 권휘영 >> Update
		//		m_cell.SetBackColor(m_clrCellBack);
		m_cell.SetBackColor(clrBk);
		// 20090209 권휘영  <<
		m_cell.SetTextColor(m_clrText);
		SetCell(nCol, nRow, &m_cell);
	}
}

int COrdGrid::GetWatchingCount()
{
	int nCnt = 0;
	int nRows = GetNumberRows();
	for (int row = 0; row < nRows; row++)
	{
		if (GetCheckWatchState(row, atoi(SVRORD_MMTYPE_BUY)) == STATE_WATCH)
			nCnt++;

		if (GetCheckWatchState(row, atoi(SVRORD_MMTYPE_SELL)) == STATE_WATCH)
			nCnt++;
	}

	return nCnt;
}

BOOL COrdGrid::IsCondExist(int nRow)
{
	int nCellState = GetCheckWatchState(nRow, atoi(SVRORD_MMTYPE_BUY));
	if (nCellState != STATE_NODATA)
		return TRUE;

	nCellState = GetCheckWatchState(nRow, atoi(SVRORD_MMTYPE_SELL));
	if (nCellState != STATE_NODATA)
		return TRUE;

	return FALSE;
}

COLORREF COrdGrid::GetFOPositionTypeColor(CString strPositionType)
{
	strPositionType.Trim();

	if (strPositionType == TRADINGTYPE_BID)
		return m_clrUp;
	if (strPositionType == TRADINGTYPE_SELL)
		return m_clrDown;

	return BLACK;
}


CString COrdGrid::GetMassText(CString strDigit)
{
	/*
	HTS 일반 : 50 (디럭스, 이지, FX,FX+ 포함)
	HTS 미니 : 51
	아이폰/안드로이드 앱 : 66
	아이패드 앱 : 67 
	*/
	switch (atol(strDigit))
	{
	case 500:
	case 510:
		return "HTS";
		
	case 660:
	case 670:
		return "MTS";

	case 0:
		return "";

	case 501:
	case 511:
	case 661:
	case 671:
		return "MP";
	}

	return "";
}

BOOL COrdGrid::IsMP(int nRow)
{
	CUGCell cell;
	GetCell(COL_MTYPE, nRow, &cell);
	CString strOnOff = cell.GetText();
	return (strOnOff.CompareNoCase("MP") == 0);
}

// 20120723 ssj - 서버자동주문 >>
BOOL COrdGrid::IsMP(CGridKey *pGridKey)
{
	CUGCell cell;
	int nRows = GetNumberRows();
	int nFindRow = -1;

	for (int nRow = 0; nRow < nRows; nRow++)
	{
		//종목코드
		GetCell(ITEMCODE_COL, nRow, &cell);
		CString strCode = cell.GetOtherJongCode();		

		//신용구분
		GetCell(COL_CREDIT_FOSELLBUY, nRow, &cell);
		int nCredit = cell.GetOtherDataInt();

		//대출일
		GetCell(COL_LOANDATE, nRow, &cell);
		int nLoanDate = cell.GetOtherDataInt();
		
		if (strCode == pGridKey->m_strCode)
		{
			if(atoi(pGridKey->m_strCredit) == nCredit && atol(pGridKey->m_strLoanDate) == nLoanDate)
			{
				nFindRow = nRow;
				break;
			}
		}
	}

	if (nFindRow != -1)
		return IsMP(nFindRow);

	return FALSE;
}
// 20120723 ssj - 서버자동주문 <<

void COrdGrid::AdjustOnOffBtn(int nRow, StOrdCondData stOrdCondData)
{
	int nBuyState = -1, nSellState = -1;

	//현재 매도가 변경되어 들어온 경우
	if (stOrdCondData.strMMType.CompareNoCase(SVRORD_MMTYPE_SELL) == 0)
	{
		// 반대편인 매수측 조건이 감시중인지 체크
		nBuyState = GetCheckWatchState(nRow, atol(SVRORD_MMTYPE_BUY));
		nSellState = atol(stOrdCondData.strState); // 1: 감시, 2: 중지
	}

	// 현재 매수가 변경되어 들어온 경우
	else 
	{
		nBuyState = atol(stOrdCondData.strState); // 1: 감시, 2: 중지
		// 반대편인 매도측 조건이 감시중인지 체크
		nSellState = GetCheckWatchState(nRow, atol(SVRORD_MMTYPE_SELL));
	}			

	CUGCell cell;
	GetCell(CEL_BTN_ONOFF, nRow, &cell);
	if (nBuyState == STATE_WATCH || nSellState == STATE_WATCH) // 둘 중 하나가 감시중이면 감시 표시
	{
		cell.SetText(STR_ON);
		cell.SetBackColor(COLOR_STR_ON);
	}
	else
	{
		cell.SetText(STR_OFF);
		cell.SetBackColor(m_clrBack);
	}
	cell.SetFont(&m_fontDefault);
	int nButtonIndex = AddCellType(&m_ugButtonType);	
	cell.SetCellType(nButtonIndex);
	cell.SetCellTypeEx(UGCT_BUTTONNOFOCUS);
	//cell.SetBorder(UG_BDR_RTHICK | UG_BDR_BTHICK);
	//cell.SetBackColor(clrBk);
	cell.SetAlignment(UG_ALIGNVCENTER | UG_ALIGNCENTER);
	SetCell(CEL_BTN_ONOFF, nRow, &cell);
}

// 20120723 ssj - 서버자동주문 >>
int COrdGrid::OnCanSizeCol(int col)
{
	if (m_nMapMode == MODE_EQUITIES)
	{
		if (col == COL_COST
			// 20140709 ssj - 거래승수 저장방식으로 변경 >>
			|| col == COL_UNIT
			// 20140709 ssj - 거래승수 저장방식으로 변경 <<
			)
			return FALSE;
	}
	else
	{
		if (col == COL_COST || col == COL_LOANDATE || col == COL_USER_PRICE
			// 20140709 ssj - 거래승수 저장방식으로 변경 >>
			|| col == COL_UNIT
			// 20140709 ssj - 거래승수 저장방식으로 변경 <<
			)
			return FALSE;
	}

	return TRUE;
}
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
void COrdGrid::OnColSizing(int col,int *width)
{
	RedrawAll();
}
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
void COrdGrid::OnColSized(int col,int *width)
{
}
// 20120723 ssj - 서버자동주문 <<


// ResultGrid.h: interface for the COrdGrid class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OrdGrid_H__312CE096_5941_4D50_9D51_7018BF0EF9AF__INCLUDED_)
#define AFX_OrdGrid_H__312CE096_5941_4D50_9D51_7018BF0EF9AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/*
#include "ugctrl.h"
#include "_Include/UGCTbutn.h"
#include "_Include/ugctelps.h"
#include "_Include/ugctsarw.h"
*/

// 20120723 ssj - �����ڵ��ֹ� >>
//.#include "../../../DrCommon/UGridCtrl/ugctrl.h"
//.#include "../../../DrCommon/UGridCtrl/_Include/UGCTbutn.h"
//.#include "../../../DrCommon/UGridCtrl/_Include/ugctelps.h"
//.#include "../../../DrCommon/UGridCtrl/_Include/ugctsarw.h"
//.#include "../../../DrCommon/Dr_Control/DrInfoTip.h"
#include "../../../_Include/ugctrl.h"
#include "../../../_Include/UGridCtrl_Addons/UGCTbutn.h"
#include "../../../_Include/UGridCtrl_Addons/ugctelps.h"
#include "../../../_Include/UGridCtrl_Addons/ugctsarw.h"
#include "../../../_Include/ISkinColorMng.h"
#include "../../../_Include/UGSkin.h"
#include "DrInfoTip.h"
// 20120723 ssj - �����ڵ��ֹ� <<

//const UINT RMSG_DBCLICK = ::RegisterWindowMessage(_T("RMSG_DBCLICK"));

#define RESULT_FIELD_MAX 20 

// 20120723 ssj - �����ڵ��ֹ� >>
class CGridItem
{
public:
//	BOOL			m_bFO;
	CString			m_strCode;
	CString			m_strCodeName;

	StOrdCondData	*m_pOrdCondData;
	StOrdJango		*m_pOrdJango;

public:
	CGridItem()
	{
//		m_bFO = FALSE;
		m_pOrdCondData = NULL;
		m_pOrdJango = NULL;
	}


};
// 20120723 ssj - �����ڵ��ֹ� <<

class COrdGrid : public CUGCtrl
{
protected:
	// 20120723 ssj - �����ڵ��ֹ� >>
	CBitmap		m_arBitmap[10];
	// 20120723 ssj - �����ڵ��ֹ� <<

public:
	COrdGrid();
	virtual ~COrdGrid();

	
	// 20120723 ssj - �����ڵ��ֹ� >>
	//int		m_nType;
	//CPen	m_penGridLine;
	// 20120723 ssj - �����ڵ��ֹ� <<

	CFont	m_fontDefault;

	BOOL    m_bMsgBox;

	CDrInfoTip				m_tipInfo;

	int						m_nSortCol;
	int						m_nSortMethode;
	int						m_nSortArrow;
	CUGSortArrowType		m_sortArrow;
	long					m_nArrowType;

	BOOL m_bCallAdjustOneTime;
	//int						m_nMaxRow;
	//int						m_nCondMaxRow;
	BOOL					m_bTypeChange;
	
	// 20120723 ssj - �����ڵ��ֹ� >>
	//BOOL					m_nRow; //�ϳ��� ���ŵǴ� ������� ����Ҷ�....
	//COLORREF			m_clrBuyText;
	//COLORREF			m_clrSellText;
	ISkinColorManager*		m_pISkinColorManager;
	int						m_nMapMode;
	// 20120723 ssj - �����ڵ��ֹ� <<

	CMapStringToString		m_mapCount;
	CUGButtonType			m_ugButtonType;

public:
	CString  m_strType;		//# "CODE", "VOL", "PRICE"
	// 20120723 ssj - �����ڵ��ֹ� >>
	//int		 m_nLastSelRow;
	//int		 m_nLastSelCol;
	// 20120723 ssj - �����ڵ��ֹ� <<

	// 20120723 ssj - �����ڵ��ֹ� >>
	//COLORREF m_clrHeader;
	//COLORREF m_clrSelRow;
	// 20120723 ssj - �����ڵ��ֹ� <<

	COLORREF m_clrSelect;								// OnGetCell Use Color
	COLORREF m_clrCellBack;								// SetCellSkin Use Color
	COLORREF m_clrText;									// SetCellSkin Use Color
	COLORREF m_clrBack;									// BackGround Use Color

	COLORREF m_clrEvenRow;
	COLORREF m_clrOddRow;

	BOOL m_bEvenOddClr;
	// 20090209 ���ֿ�  <<
	int m_nHeaderFlag;									// Header Type

	CPen* m_PenHeaderLine;								// HeaderBackColor
	CPen* m_PenBorderLine;								// BorderLineStyle

	COLORREF m_clrUp;									// UGSkinText Use Color
	COLORREF m_clrDown;									// UGSkinText Use Color
	COLORREF m_clrHeader;

protected:
	// 20120723 ssj - �����ڵ��ֹ� >>
	CBitmap		*GetCircleBitmap(int nBmpIndex);
	CPoint		m_ptMouseColRow;
	// 20120723 ssj - �����ڵ��ֹ� <<

public:	 // Member Functions
	void ClearAll();
	void HeaderSetup(int nType = 0);
	// 20120723 ssj - �����ڵ��ֹ� >>
	//void SetModifyRow(int nRow, CString strData1, CString strData2);
	//void SetAddRow(int nData1, int nData2, BOOL bRedraw = FALSE);
	// 20120723 ssj - �����ڵ��ֹ� <<
	int SetAddRow(StOrdCondData stOrdGridData, BOOL bInsert = FALSE, BOOL bRedraw = FALSE);
	
	// 20120723 ssj - �����ڵ��ֹ� >>
	//void SetAddRow(StOrdGridData& stConVolClient, BOOL bInsert = TRUE, BOOL bRedraw = FALSE);
	// 20120723 ssj - �����ڵ��ֹ� <<

	BOOL SetAddRow(StOrdJango stOrdJangoData, BOOL bInsert = FALSE, BOOL bRedraw = FALSE);
	void SetAddRowOnCode(StItemPrice stOrdJangoData, int nMarketType = 1);
	// 20120723 ssj - �����ڵ��ֹ� >>
	//void SetAddRowSiseData(StItemPrice stOrdJangoData, int nMarketType = 1);	
	//BOOL SetAddRowCheJanData(StCheJan stItemPrice, int nMarketType = -1);
	// 20120723 ssj - �����ڵ��ֹ� <<

	void SetCondCircle(int nCol, int nRow, StOrdCondData stOrdGridData);
	void SetOrdCellState(StOrdCondData stOrdGridData, int nRow);
	CString GetCondCircleToolTip(int nCol, int nRow, StOrdCondData stOrdGridData);

	

	// 20120723 ssj - �����ڵ��ֹ� >>
	//void SetModifyRow(int nRow, int nData1, int nData2);
	//void SetModifyRow(int nData1, int nData2);
	//int  GetLastCol() {return m_nLastSelCol;};
	// 20120723 ssj - �����ڵ��ֹ� <<
	void RemoveCellInfo(int nCol, int nRow);




	// 20120723 ssj - �����ڵ��ֹ� >>
	//void SetDeleteRow(int nRow);
	// 20120723 ssj - �����ڵ��ֹ� <<

	void GetRowData(int nRow, CString &strData1, CString &strData2);
	void GetRowData(int nRow, int &nData1, int &nData2);

	inline void GetSignColor(int nSign, COLORREF &clrSignText);
	// 20120723 ssj - �����ڵ��ֹ� >>
	//inline void GetEvenOddBkColor(int nRow, COLORREF &clrBk);
	//void EvenOddColorSetting();
	// 20120723 ssj - �����ڵ��ֹ� <<
	void InsetCommar(CString& str1);
	// 20120723 ssj - �����ڵ��ֹ� >>
	//void SetSelectRow(long oldrow, long newrow, BOOL bAdd = FALSE);
	//void PaintSelectRow(long oldrow, long newrow, BOOL bAdd = FALSE);
	// 20120723 ssj - �����ڵ��ֹ� <<
	void HideColumn(int nCol, BOOL bHide = TRUE);
//	void ChangeGridColor(ST_GRIDCOLOR stGridColor);
	void ShowToolTip(int nCol, int nRow);
	CString GetCreditText(CString strType);
	int FindModifyRow(StOrdCondData stOrdCond);
	int FindModifyRow(StOrdJango stOrdJango);
	int OpenMsgBoxDlg(int nMode);
	void SetGridStatie(CUGCell& cell, int nRow);
	// 20120723 ssj - �����ڵ��ֹ� >>
	//BOOL CheckWatching();
	BOOL CheckWatching(CGridKey *pGridKey);
	BOOL IsMP(CGridKey *pGridKey);
	// sjs <<

	////////////////////////////////////////////////
	// �׸�����
	CList<HeadInfoType, HeadInfoType&>	*m_plistField;
	CList<CandleInfo, CandleInfo&>		m_listCnadle;
	CList<PatenInfo, PatenInfo&>		m_listPaten;
	
	// 20120723 ssj - �����ڵ��ֹ� >>
	//BOOL	m_bCandleLoadFalg;
	// 20120723 ssj - �����ڵ��ֹ� <<

	/*BOOL	m_bPatenLoadFalg;*/
	int		m_nFontHeight; 
	int		m_nFontWidth; 
	int		m_nFixCol;
	int		m_nSortType[RESULT_FIELD_MAX];
	
	
	// 20120723 ssj - �����ڵ��ֹ� >>
	//void    SetHeader(CList <HeadInfoType, HeadInfoType&> *plistField);
	//void	SetLockColumns(int nCol, BOOL bOffSet);
	//void	SetAddRow(int nRow, char chSign, int ntotCol, char chMarkType, CString strItemCode, 
	//				  CString strItemName, char dcolData[960], bool bRedraw);
	// 20120723 ssj - �����ڵ��ֹ� <<

	// 20120723 ssj - �����ڵ��ֹ� >>
	/*
	CString	FindCandleIdFromName(long lCandleID);
	BOOL	LoadCandleIndexToXml();
	CString FindPatenIdFromName(long lPatenID);
	BOOL	LoadPatenIndexToXml();
	*/
	// 20120723 ssj - �����ڵ��ֹ� <<

	CSize	GetFontSize();
	////////////////////////////////////////////////
	void	GetGridOrdData(int nRow, TR_ORDER_DETAIL_IN* pGridData, CString strMMType);
	// 20120723 ssj - �����ڵ��ֹ� >>
	//void	SetGridOrdData(int nRow, TR_ORDER_REGOUT* pGridData);
	// 20120723 ssj - �����ڵ��ֹ� <<

	int    GetCheckWatchState(int nRow, int nType = 1);
	
	// 20120723 ssj - �����ڵ��ֹ� >>
	//BOOL   GetChecknRow(int nRow);
	//BOOL	IsWatching(int nRow);
	BOOL	IsMP(int nRow);

	//void		ChangeState(StOrdCondData stOrdCondData);
	void		ChangeItem(StOrdCondData stOrdCondData);
	void		RemoveItem(StOrdCondData stOrdCondData);
	void		SetRestItem(int nRow, StOrdCondData stOrdGridData); //, COLORREF clrBk);

	void		MakeCellForCondtion(int nRow);
	void		SetOrdGridColor();
	void		SetCellSkin(int nRow);
	int			GetWatchingCount();
	BOOL		IsCondExist(int nRow);
	COLORREF	GetFOPositionTypeColor(CString strPositionType);
	CString		GetMassText(CString strDigit);
	void		AdjustOnOffBtn(int nRow, StOrdCondData stOrdCondData);
	void		RecalcProfit(int nRow, StOrdCondData stOrdCondData);
	// 20120723 ssj - �����ڵ��ֹ� <<

	//�ŵ����ɼ�������
	CString GetCellCredit(int nRow, CString& strDate);
	//>>[0000260] �ս����ѷ�, ��ǥ���ͷ� ���ͷ��� �ڵ����� ���� SJ_KIM(20110720)
	// 20120723 ssj - �����ڵ��ֹ� >>
	//BOOL GetRowInfoToCalcPNL(CString& strPrice, CString& strMMType);
	// 20120723 ssj - �����ڵ��ֹ� <<

protected:
	// sjs >>
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	// 20120723 ssj - �����ڵ��ֹ� <<

public: // Overrides
	virtual void	OnSetup();	
	virtual void	OnLClicked(int col, long row, int updn, RECT *rect, POINT *point, BOOL processed);
	virtual void	OnRowChange(long oldrow, long newrow);
	virtual int		OnSortEvaluate(CUGCell *cell1,CUGCell *cell2,int flags);
	virtual int		OnCanSizeTopHdg();
	virtual void	OnSysColorChange();
	virtual void	OnDClicked(int col,long row, RECT *rect, POINT *point, BOOL processed);
	virtual int		OnHint(int col, long row, int section, CString *string);
	virtual void	OnAdjustComponentSizes(RECT *grid, RECT *topHdg,
						                    RECT *sideHdg, RECT *cnrBtn, 
							                RECT *vScroll, RECT *hScroll, 
								            RECT *tabs);

	virtual void	OnTH_LClicked(int col, long row, int updn, RECT *rect , POINT *point , BOOL processed);
	void			Sorting(int col);

	// 20120723 ssj - �����ڵ��ֹ� >>
	virtual void OnGetCell(int col,long row,CUGCell *cell);
	virtual void OnMouseMove(int col,long row,POINT *point,UINT nFlags,BOOL processed=0);
	virtual int  OnCanSizeCol(int col);
	virtual void OnColSizing(int col,int *width);
	virtual void OnColSized(int col,int *width);
	// 20120723 ssj - �����ڵ��ֹ� <<

	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

	//{{AFX_MSG(ShowGrid)
	// NOTE - the ClassWizard will add and remove member functions here.
	//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG

	afx_msg void OnTimer(UINT nIDEvent);
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_SETGRID_H__312CE096_5941_4D50_9D51_7018BF0EF9AF__INCLUDED_)

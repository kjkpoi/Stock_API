#pragma once
#include "afxwin.h"

#include "control_auto/DrEdit.h"
#include "control_auto/NumSpinCtrl.h"
#include "control_auto/StatisticCtrl.h"
#include "afxdtctl.h"
#include "resource.h"

// CDlgSetDiv ��ȭ �����Դϴ�.

class CDlgSetDiv : public CDialog
{
	DECLARE_DYNAMIC(CDlgSetDiv)

protected:
	CFont	m_fntDefault;
	int		m_nAvailSellVol;

public:
	CWnd	*m_pCommWnd;
	int		m_nMapMode;

protected:
	void	ShowVolDiv(BOOL bShowMsg);

public:
	CDlgSetDiv(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgSetDiv();

	void SetDefaultDivVal();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_AUTO_SET_DIV };



	//void DefMessageBox(HWND hWnd, CString strMsg, CString strCaption="") ;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	//CComboBox m_cmbValidDate;
	CDrEdit m_edtRate;
	CNumSpinCtrl m_spnRate;
	CComboBox m_cmbInc;
	CComboBox m_cmbBasePrice;
	CDrEdit m_edtCount;
	CNumSpinCtrl m_spnCount;
	CComboBox m_cmbDir;
//	afx_msg void OnBnClickedBtnDivApply();
	void OnBnClickedBtnDivApply();
	CStatisticCtrl m_stcComplex;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnAvailsellvol();
protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual void OnOK();
	virtual void OnCancel();
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CDateTimeCtrl m_dtpValidDate;
	afx_msg void OnDtnDatetimechangeDtpValidDate(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDtnCloseupDtpValidDate(NMHDR *pNMHDR, LRESULT *pResult);
};

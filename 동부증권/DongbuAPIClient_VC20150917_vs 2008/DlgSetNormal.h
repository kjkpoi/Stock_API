#pragma once
#include "afxwin.h"

#include "control_auto/DrEdit.h"
#include "control_auto/NumSpinCtrl.h"

#include "afxdtctl.h"
#include "resource.h"

// CDlgSetNormal ��ȭ �����Դϴ�.

class CDlgSetNormal : public CDialog
{
	DECLARE_DYNAMIC(CDlgSetNormal)

protected:
	CFont m_fntDefault;

public:
	CWnd	*m_pCommWnd;
	int		m_nMapMode;

public:
	CDlgSetNormal(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgSetNormal();

	void SetDefaultNormalVal();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_AUTO_SET_NORMAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	//CComboBox m_cmbValidDate;
	CComboBox m_cmbPriceType;
	CDrEdit m_edtRate;
	CNumSpinCtrl m_spnRate;
	CComboBox m_cmbSelPrice;
	CButton m_chkBestPrice;
	CDrEdit m_edtPrice;
	CNumSpinCtrl m_spnPrice;

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedChkBestPrice();
	afx_msg void OnCbnSelchangeCmbPriceType();
	afx_msg void OnCbnSelchangeCmbSelPrice();
protected:
	virtual void OnOK();
	virtual void OnCancel();
public:
	CDateTimeCtrl m_dtpValidDate;
	afx_msg void OnDtnDatetimechangeDtpValidDate(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDtnCloseupDtpValidDate(NMHDR *pNMHDR, LRESULT *pResult);
};

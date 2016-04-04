#pragma once
#include "afxwin.h"
#include "afxcmn.h"

#include "DlgSetDiv.h"
#include "DlgSetNormal.h"
#include "control_auto/TEditCtrlWnd.h"
#include "resource.h"

// CDlgSetting 대화 상자입니다.

class CDlgSetting : public CDialog
{
	DECLARE_DYNAMIC(CDlgSetting)

protected:
	CWnd			*m_pCommWnd;

	CDlgSetNormal	m_dlgNormal;
	CDlgSetDiv		m_dlgDiv;
	CWnd			*m_pCurrentDlg;

	BOOL			m_bSending;
	BOOL			m_bInitClicked;
	
	
public:
	CString			m_strAcnt;
	CString			m_strPasswd;
	CString			m_strUsreID;
	CString			m_strIP;
	int				m_nMapMode;
//	CString			m_strMkt;

	TR77010_IN		m_stInput;
	TR77080_OUT		*m_pPrevSet;
	
protected:
	void InitEditCtrl(UINT nBaseID, UINT nID, CTEditCtrlWnd *pEdit);
	void InitTabDlg();
	void SetDefaultVal();
	
	int	 GetCondCount();
	CString GetCondExp();
	
	void GetCondDetail(TR77010_IN *pInput);
	void GetLossCondDetail(int nIndex, char cCondExp, User_Define *pUserDef);
	void GetProfitCondDetail(int nIndex, char cCondExp, User_Define *pUserDef);
	void GetFixProfitCondDetail(int nIndex, char cCondExp, User_Define *pUserDef);
	void GetFixLossCondDetail(int nIndex, char cCondExp, User_Define *pUserDef);

	void InitBuff(User_Define *pUserDef);

	void SetPrevValue();
	
	void SetComboText(CString strText, CComboBox *pCombo);
	void SetComboCurSel(int nIdx, CComboBox *pCombo);
	void SetCondCtrl(CString strCondType, User_Define *pUserDef);

	void ShowHideSubDlgByTab();	

public:
	CDlgSetting( CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgSetting();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_AUTO_SETTING };



protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CButton m_rdoAuto;
	CButton m_rdoSemi;
	CButton m_chkLoss;
	CButton m_chkProfit;
	CButton m_chkFixProfit;
	CButton m_chkFixLoss;
	CTEditCtrlWnd m_edtLoss;
	CTEditCtrlWnd m_edtProfit;
	CTEditCtrlWnd m_edtFixProfit1;
	CTEditCtrlWnd m_edtFixProfit2;
	CTEditCtrlWnd m_edtFixProfit3;
	CTEditCtrlWnd m_edtFixLoss1;
	CTEditCtrlWnd m_edtFixLoss2;
	CTEditCtrlWnd m_edtFixLoss3;
	CTabCtrl m_tabRule;
	CButton m_chkApplyNewItem;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedBtnInitset();
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTabRule(NMHDR *pNMHDR, LRESULT *pResult);
	
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	
	afx_msg void OnDestroy();	
};

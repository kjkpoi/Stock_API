// ExMiChegyulDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "DongbuAPIClient_VC.h"
#include "ExMiChegyulDlg.h"


// CExMiChegyulDlg 대화 상자입니다.

#include "include_fo/TR13620.h"

#include "include_cme/TR20113.h"

#include "include_SK/TR13118.h"


IMPLEMENT_DYNAMIC(CExMiChegyulDlg, CDialog)

CExMiChegyulDlg::CExMiChegyulDlg(CWnd* pParent /*=NULL*/)
: CDialog(CExMiChegyulDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExMiChegyulDlg)
	m_strAccount = theApp.g_strAccount;
	m_strAcctPwd =  theApp.g_strAcctPwd;		
	//}}AFX_DATA_INIT
}

CExMiChegyulDlg::~CExMiChegyulDlg()
{
}

void CExMiChegyulDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CExMiChegyulDlg)
	DDX_Control(pDX, IDC_LIST,			m_lstMsg);	
	DDX_Text(pDX, IDC_EDT_ACCOUNT,		m_strAccount);
	DDX_Text(pDX, IDC_EDT_ACCTPWD,		m_strAcctPwd);		
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExMiChegyulDlg, CDialog)

	ON_WM_COPYDATA()
	ON_BN_CLICKED(IDC_BTN_INQUERY, OnBtnInquery)
	ON_BN_CLICKED(IDC_BTN_INQUERY_NEXT, OnBnClickedBtnInqueryNext)
	

END_MESSAGE_MAP()


// CExMiChegyulDlg 메시지 처리기입니다.

BOOL CExMiChegyulDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	SetWindowText("미체결 내역 조회") ;
	GetDlgItem(IDC_CHK_REALTIME)->ShowWindow(SW_HIDE) ;

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

//=======================================================================================
// FUNCTION : 다음데이터 조회
// RETURN   : 
//=======================================================================================
void CExMiChegyulDlg::OnBnClickedBtnInqueryNext()
{
	GetDlgItem(IDC_BTN_INQUERY_NEXT)->EnableWindow(FALSE);

	switch (m_nProduct)
	{
	case ID_PRODUCT_FO :
	case ID_PRODUCT_SFO :
		MakePacket_FO();
		break;

	case ID_PRODUCT_CME :
		MakePacket_CME() ;
		break;

	case ID_PRODUCT_SK :
		MakePacket_SK() ;
		break;
	}	

}

//=======================================================================================
// FUNCTION : 조회
// RETURN   : 
//=======================================================================================
void CExMiChegyulDlg::OnBtnInquery()
{
	GetDlgItem(IDC_BTN_INQUERY_NEXT)->EnableWindow(FALSE);
	m_szNextKey ="";

	switch (m_nProduct)
	{
	case ID_PRODUCT_FO :
	case ID_PRODUCT_SFO :
		MakePacket_FO();
		break;

	case ID_PRODUCT_CME :
		MakePacket_CME() ;
		break;

	case ID_PRODUCT_SK :
		MakePacket_SK() ;
		break;
	}	
}


//=======================================================================================
// FUNCTION : 동부api에 데이터 요청 (선물옵션)
// RETURN   : 
//=======================================================================================
void CExMiChegyulDlg::MakePacket_FO()
{
	UpdateData (TRUE) ;

	CString szAccount = m_strAccount ; 	
	CString szPwd = m_strAcctPwd ;
	CString szInput ;
	CString szNext ;
	

	szAccount.TrimLeft() ;
	szAccount.TrimRight() ;
	szAccount.Remove('-');
	
	TR_13620_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_13620_I)) ;
	memcpy ( stInput.geja, szAccount, szAccount.GetLength() ) ;	

	//20130813 >>
	szNext.Format("%0*d", sizeof(stInput.nxtKey), atoi(m_szNextKey) );
	if ( atoi(m_szNextKey) == 0)	
		stInput.nxtGb[0] = '0';
	else
		stInput.nxtGb[0] = '1';	
	
	memcpy(stInput.nxtKey, (LPSTR)(LPCTSTR)szNext, szNext.GetLength()) ;
	//20130813 <<

	memcpy(stInput.checkgb, (LPSTR)(LPCTSTR)"0", sizeof(stInput.checkgb));/* 조회구분 0:전체, 1:종목  */

	stInput.type[0] = '3';/* 3전체 1주가지수선옵 2개별주식선옵 4상품선옵 */
	
	int nLen = sizeof(stInput) ;
	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);				

	theApp.SendToServerEx (DRCM_SENDDATA, TR_13620, szInput, m_hWnd);
	
}


//=======================================================================================
// FUNCTION : 동부api에 데이터 요청 (CME선물)
// RETURN   : 
//=======================================================================================
void CExMiChegyulDlg::MakePacket_CME()
{
	UpdateData (TRUE) ;
	
	CString szAccount = m_strAccount ; 	
	CString szPwd = m_strAcctPwd ;
	CString szInput ;
	
	szAccount.TrimLeft() ;
	szAccount.TrimRight() ;
	szAccount.Remove('-');

	TR_20113_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_20113_I)) ;
	memcpy ( stInput.geja, szAccount, szAccount.GetLength() ) ;
	memcpy ( stInput.passwd, szPwd, szPwd.GetLength() ) ;
	memcpy ( stInput.sort, "2", 1 ) ;	//정순(1) 역순(2)  

	int nLen = sizeof(stInput) ;
	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);				
	
	theApp.SendToServerEx (DRCM_SENDDATA, TR_20113, szInput, m_hWnd);
}


//=======================================================================================
// FUNCTION : 동부api에 데이터 요청 (주식)
// RETURN   : 
//=======================================================================================
void CExMiChegyulDlg::MakePacket_SK()
{
	UpdateData (TRUE) ;

	CString szAccount = m_strAccount ; 	
	CString szPwd = m_strAcctPwd ;
	CString szInput ;
	CString szNext ;

	szAccount.TrimLeft() ;
	szAccount.TrimRight() ;
	szAccount.Remove('-');

	TR_13118_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_13118_I)) ;
	memcpy ( stInput.geja, szAccount, szAccount.GetLength() ) ;
	memcpy ( stInput.sgb, "2", 1 ) ;  // 1:주문/체결 2:미체결		
	memcpy ( stInput.sort, "2", 1 ) ; //역순
	szNext.Format("%0*d", sizeof(stInput.next), 0 );

	if ( atoi(szNext) == 0)	
	{		
		memcpy ( stInput.ngbn, "0", 1 ) ;	
	}
	else
	{		
		memcpy ( stInput.ngbn, "1", 1 ) ;	
	}

	memcpy ( stInput.next, (LPCTSTR)szNext, szNext.GetLength() ) ;

	int nLen = sizeof(stInput) ;
	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);				

	theApp.SendToServerEx (DRCM_SENDDATA, TR_13118, szInput, m_hWnd);	
}


//=======================================================================================
// FUNCTION : 동부apI 로부터 데이터 수신
// RETURN   : 
//=======================================================================================
BOOL CExMiChegyulDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
{
	COPYDATASTRUCT* pCDS = pCopyDataStruct ;

	int nDataType = (int)pCDS->dwData ;

	STTRHEADER* prData = (STTRHEADER*)pCDS->lpData;
	char szTrCode[5+1] ={0,} ;
	char szMsg[82+1] ={0,} ;
	CString strMsg  ;


	memcpy(szTrCode, prData->TRCode, 5 ) ;
	memcpy(szMsg, prData->Message, 82) ;

	strMsg = szMsg ;
	strMsg.TrimRight() ;

	//선옵 미체결조회
	if ( strcmp(szTrCode, TR_13620 ) == 0 ) 
	{						
		TR_13620_O* pData = (TR_13620_O*)prData->TRData;

		CTR_13620_O tr_13620_output;
		tr_13620_output.Convert(pData);
		if ( tr_13620_output.m_szNextFlag = "1")	
		{
			m_szNextKey = tr_13620_output.m_szNextVal ;
			GetDlgItem(IDC_BTN_INQUERY_NEXT)->EnableWindow(TRUE) ;
		}
		else
		{
			m_szNextKey = "" ;	
			GetDlgItem(IDC_BTN_INQUERY_NEXT)->EnableWindow(FALSE) ;
		}

		int nCnt = tr_13620_output.m_DataList.GetCount();

		if (nCnt > 0)
		{
			
			POSITION  pos = tr_13620_output.m_DataList.GetHeadPosition();
			for(;pos;)
			{
				CTR_13620_G* pData = tr_13620_output.m_DataList.GetNext(pos);
			}

		}
		strMsg= "선옵 미체결조회 결과>>" + strMsg ;
		m_lstMsg.InsertString( 0, strMsg );
		UpdateData(FALSE) ;

		//*********************************
		//화면에 맞게 데이터를 처리
		//*********************************
	}

	//CME 선옵미체결조회
	if ( strcmp(szTrCode, TR_20113 ) == 0 ) 
	{					
		TR_20113_O* pData = (TR_20113_O*)prData->TRData;

		int count = theApp.gatoi( pData->gridcnt, sizeof(pData->gridcnt) ) ;		
		for ( int i =0; i < count; i++)
		{					
		}

		strMsg= "CME 선옵미체결조회 결과>>" + strMsg ;
		m_lstMsg.InsertString( 0, strMsg );
		UpdateData(FALSE) ;

		//*********************************
		//화면에 맞게 데이터를 처리
		//*********************************
	}

	//주식 미체결 내역
	if ( strcmp(szTrCode, TR_13118 ) == 0 )
	{								
		TR_13118_O* pData = (TR_13118_O*)prData->TRData;
		TR_13118_G* pGR = (TR_13118_G *)(pData->gr_DATA);
		int count = theApp.gatoi( pData->gr_cnt, sizeof(pData->gr_cnt) ) ;

		for ( int i =0; i < count; i++)
		{	
			TR_13118_G* pGridData = (TR_13118_G*)(&pGR[i]);

			//*********************************
			//화면에 맞게 데이터를 처리
			//*********************************

						
		}
		strMsg= "주식 미체결조회 결과>>" + strMsg ;
		m_lstMsg.InsertString( 0, strMsg );
		UpdateData(FALSE) ;
	}

	return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
}

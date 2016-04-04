// ExInvestTodayDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "DongbuAPIClient_VC.h"
#include "ExInvestTodayDlg.h"

#include "include_sk/TR01921.h"


// CExInvestTodayDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CExInvestTodayDlg, CDialog)

CExInvestTodayDlg::CExInvestTodayDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExInvestTodayDlg::IDD, pParent)
{

}

CExInvestTodayDlg::~CExInvestTodayDlg()
{
}

void CExInvestTodayDlg::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(ExInvestTodayDlg)
	DDX_Control(pDX, IDC_LIST,			m_lstMsg);	
	DDX_Text(pDX, IDC_EDT_JONGMOK,		m_strJongmok);	
	//}}AFX_DATA_MAP
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CExInvestTodayDlg, CDialog)

	ON_WM_COPYDATA()
	ON_BN_CLICKED(IDC_BTN_INQUERY,		OnBtnInquery)	
	ON_BN_CLICKED(IDC_BTN_INQUERY_NEXT, OnBnClickedBtnInqueryNext)
	
END_MESSAGE_MAP()

// CExInvestTodayDlg 메시지 처리기입니다.

BOOL CExInvestTodayDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


//=======================================================================================
// FUNCTION : 다음데이터 조회
// RETURN   : 
//=======================================================================================
void CExInvestTodayDlg::OnBnClickedBtnInqueryNext()
{
	GetDlgItem(IDC_BTN_INQUERY_NEXT)->EnableWindow(FALSE);

	MakePacket() ;
}


//=======================================================================================
// FUNCTION : 조회
// RETURN   : 
//=======================================================================================
void CExInvestTodayDlg::OnBtnInquery()
{
	GetDlgItem(IDC_BTN_INQUERY_NEXT)->EnableWindow(FALSE);
	m_szNextKey ="";

	MakePacket() ;
}

//=======================================================================================
// FUNCTION : 동부api에 데이터 요청 
// RETURN   : 
//=======================================================================================
void CExInvestTodayDlg::MakePacket()
{
	UpdateData (TRUE) ;

	
	CString szInput ;
	CString szNext ;

	TR_01921_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_01921_I)) ;

	BOOL bAll = ((CButton *)GetDlgItem(IDC_RADIO_ALL))->GetCheck() ;
	BOOL bForeign = ((CButton *)GetDlgItem(IDC_RADIO_FOREIGN))->GetCheck() ;
	CString szGubun;

	if ( bAll )
		szGubun = "0" ;
	else if ( bForeign)
		szGubun = "1" ;
	else
	{
		szGubun = "2" ; //기관계2 보험/기타금융3 투신4 은행5 연기금6 국가지자체7 기타법인8 */
	}

	memcpy ( stInput.tuja_tp, szGubun, 1 ) ;  /* 0전체 외국인1 기관계2 보험/기타금융 투신4 은행5 연기금6 국가지자체7 기타법인8 */	
	memcpy ( stInput.shcode, m_strJongmok, SH_KSIZE ) ; 

	memcpy ( stInput.sort_tp, "00", 1 ) ; /* 정렬순서: 00외국인순매수순 01외국인순매도순 02기관계순매수순 03기관계순매도순~ */

	szNext.Format("%0*d", sizeof(stInput.nxtKey), atoi(m_szNextKey) );
	
	if ( atoi(szNext) == 0)	
	{		
		memcpy ( stInput.nxtTp, "0", 1 ) ;	
	}
	else
	{		
		memcpy ( stInput.nxtTp, "1", 1 ) ;	
	}

	memcpy ( stInput.nxtKey, (LPCTSTR)szNext, szNext.GetLength() ) ;
	
	int nLen = sizeof(stInput) ;
	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);				

	theApp.SendToServerEx (DRCM_SENDDATA, TR_01921, szInput, m_hWnd);	

	m_szNextKey = "" ;
}


//=======================================================================================
// FUNCTION : 동부apI 로부터 데이터 수신
// RETURN   : 
//=======================================================================================
BOOL CExInvestTodayDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
{
	COPYDATASTRUCT* pCDS = pCopyDataStruct ;

	int nDataType = (int)pCDS->dwData ;	
	switch (nDataType)
	{	

	case DRCM_DRDS_DATA : 	
			break ;					

	default: //조회 데이터
		{
			STTRHEADER* prData = (STTRHEADER*)pCDS->lpData;
			char szTrCode[5+1] ={0,} ;
			char szMsg[82+1] ={0,} ;
			CString strMsg  ;


			memcpy(szTrCode, prData->TRCode, 5 ) ;
			memcpy(szMsg, prData->Message, 82) ;

			strMsg = szMsg ;
			strMsg.TrimRight() ;

			
			//투자자 당일 매매추정 조회
			if ( strcmp(szTrCode, TR_01921) == 0 )
			{								
				TR_01921_O* pData = (TR_01921_O*)prData->TRData;
				TR_01921_OS* pGR = (TR_01921_OS *)(pData->data);
				int count = theApp.gatoi( pData->grdCnt, sizeof(pData->grdCnt) ) ;

				for ( int i =0; i < count; i++)
				{	
					TR_01921_OS* pGridData = (TR_01921_OS*)(&pData->data[i]);

					//*********************************
					//화면에 맞게 데이터를 처리
					//*********************************
				}
				strMsg= "투자자 당일 매매추정 조회>>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;

			}

		}
	}

	return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
}

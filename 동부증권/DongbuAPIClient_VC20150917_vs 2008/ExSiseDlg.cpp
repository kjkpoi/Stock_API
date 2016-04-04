// ExSiseDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "DongbuAPIClient_VC.h"
#include "ExSiseDlg.h"


// CExSiseDlg 대화 상자입니다.

#include "include_sk/TR09110.h"


IMPLEMENT_DYNAMIC(CExSiseDlg, CDialog)

CExSiseDlg::CExSiseDlg(CWnd* pParent /*=NULL*/)
: CDialog(CExSiseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExSiseDlg)	
	m_strJongmok = theApp.g_strJongmok;
	//}}AFX_DATA_INIT
}

CExSiseDlg::~CExSiseDlg()
{
}

void CExSiseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CExSiseDlg)
	
	DDX_Text(pDX, IDC_EDT_JONGMOK,		m_strJongmok);	
	DDX_Control(pDX, IDC_LIST,			m_lstMsg);	
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExSiseDlg, CDialog)

	ON_WM_COPYDATA()
	
	ON_BN_CLICKED(IDC_BTN_INQUERY,		OnBtnRequestSise)
END_MESSAGE_MAP()


// CExSiseDlg 메시지 처리기입니다.

BOOL CExSiseDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


//=======================================================================================
// FUNCTION : 동부apI 로부터 데이터 수신
// RETURN   : 
//=======================================================================================
BOOL CExSiseDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
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

	//주식 현재가
	if ( strcmp(szTrCode, TR_09110 ) == 0 )
	{		
		TR_09110_O* pData = (TR_09110_O*)prData->TRData;
		int nPrice = theApp.gatoi( pData->jong.price, sizeof(pData->jong.price) ) ;

		CString szJong ;
		szJong.Format( "%.*s 현재가 : %d", sizeof(pData->hname), pData->hname , nPrice) ;

	
		//*********************************
		//화면에 맞게 데이터를 처리
		//*********************************
		m_lstMsg.InsertString( 0, szJong );

		strMsg= "주식 현재가 조회 결과>>" ;
		m_lstMsg.InsertString( 0, strMsg );

		UpdateData(FALSE) ;
	}

	return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
}

//=======================================================================================
// FUNCTION : 실시간 데이터 요청_ 시세
// RETURN   : 
//=======================================================================================
void CExSiseDlg::OnBtnRequestSise()
{	
	switch (m_nProduct)
	{
	case ID_PRODUCT_SK : //주식
		MakePacket_SK();
		break;
	}	
}


//=======================================================================================
// FUNCTION : 동부api에 데이터 요청 (주식)
// RETURN   : 
//=======================================================================================
void CExSiseDlg::MakePacket_SK()
{	
	
	CString szJongmok = m_strJongmok ; 
	
	CString szInput ;

	szJongmok.TrimLeft() ;
	szJongmok.TrimRight() ;
	
	int nLen = sizeof(TR_09110_I) ;
	TR_09110_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_09110_I)) ;
	memcpy ( stInput.code, szJongmok, szJongmok.GetLength() ) ;

	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput );	

	theApp.SendToServerEx (DRCM_SENDDATA, TR_09110, szInput, m_hWnd);

}


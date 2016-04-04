// ExHogaDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "DongbuAPIClient_VC.h"
#include "ExHogaDlg.h"


// CExHogaDlg 대화 상자입니다.

#include "include_sk/TR10051.h"
#include "include_fo/TR09650.h"
#include "include_fo/TR09651.h"

IMPLEMENT_DYNAMIC(CExHogaDlg, CDialog)

CExHogaDlg::CExHogaDlg(CWnd* pParent /*=NULL*/)
: CDialog(CExHogaDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExHogaDlg)	
	m_strJongmok = theApp.g_strJongmok;
	//}}AFX_DATA_INIT
}

CExHogaDlg::~CExHogaDlg()
{
}

void CExHogaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CExHogaDlg)
	
	DDX_Text(pDX, IDC_EDT_JONGMOK,		m_strJongmok);	
	DDX_Control(pDX, IDC_LIST,			m_lstMsg);	
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExHogaDlg, CDialog)

	ON_WM_COPYDATA()
	
	ON_BN_CLICKED(IDC_BTN_INQUERY,		OnBtnRequestSise)
END_MESSAGE_MAP()


// CExHogaDlg 메시지 처리기입니다.

BOOL CExHogaDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


//=======================================================================================
// FUNCTION : 동부apI 로부터 데이터 수신
// RETURN   : 
//=======================================================================================
BOOL CExHogaDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
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

	//주식 호가
	if ( strcmp(szTrCode, TR_10051 ) == 0 )
	{		
		TR_10051_O* pData = (TR_10051_O*)prData->TRData;
		
		CString szJong ;
		szJong.Format( "종목명: %.*s", sizeof(pData->table.hname), pData->table.hname ) ;

	
		//*********************************
		//화면에 맞게 데이터를 처리
		//*********************************
		m_lstMsg.InsertString( 0, szJong );

		strMsg= "주식 호가조회 조회 결과>>" ;
		m_lstMsg.InsertString( 0, strMsg );

		UpdateData(FALSE) ;
	}
	//선물 호가
	else if ( strcmp(szTrCode, TR_09650 ) == 0 )
	{		
		TR_09650_O* pData = (TR_09650_O*)prData->TRData;
		
		CString szTmp ;
		szTmp.Format( " %.*s", sizeof(TR_09650_O), pData) ;

	
		//*********************************
		//화면에 맞게 데이터를 처리
		//*********************************
		m_lstMsg.InsertString( 0, szTmp );

		strMsg= "선물 호가조회 조회 결과>>" ;
		m_lstMsg.InsertString( 0, strMsg );

		UpdateData(FALSE) ;
	}

	//옵션 호가
	else if ( strcmp(szTrCode, TR_09651 ) == 0 )
	{		
		TR_09651_O* pData = (TR_09651_O*)prData->TRData;
		
		CString szTmp ;
		szTmp.Format( " %.*s", sizeof(TR_09651_O), pData) ;

	
		//*********************************
		//화면에 맞게 데이터를 처리
		//*********************************
		m_lstMsg.InsertString( 0, szTmp );


		strMsg= "옵션 호가조회 조회 결과>>" ;
		m_lstMsg.InsertString( 0, strMsg );

		UpdateData(FALSE) ;
	}

	return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
}

//=======================================================================================
// FUNCTION : 실시간 데이터 요청_ 시세
// RETURN   : 
//=======================================================================================
void CExHogaDlg::OnBtnRequestSise()
{	
	switch (m_nProduct)
	{
	case ID_PRODUCT_SK : //주식
		MakePacket_SK();
		break;

	case ID_PRODUCT_FUT : //선물
		MakePacket_FO(TR_09650);
		break;
	case ID_PRODUCT_OPT : //옵션
		MakePacket_FO(TR_09651);
		break;
	}	
}

//=======================================================================================
// FUNCTION : 동부api에 데이터 요청 (선물옵션)
// RETURN   : 
//=======================================================================================
void CExHogaDlg::MakePacket_FO(CString szTRCode)
{		
	UpdateData(TRUE);
	CString szJongmok = m_strJongmok ; 

	CString szInput ;

	szJongmok.TrimLeft() ;
	szJongmok.TrimRight() ;

	int nLen = sizeof(TR_09650_I) ;
	TR_09650_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_09650_I)) ;
	memcpy ( stInput.jmcode, szJongmok, szJongmok.GetLength() ) ;

	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput );	

	theApp.SendToServerEx (DRCM_SENDDATA, szTRCode, szInput, m_hWnd);

}



//=======================================================================================
// FUNCTION : 동부api에 데이터 요청 (주식)
// RETURN   : 
//=======================================================================================
void CExHogaDlg::MakePacket_SK()
{		
	UpdateData(TRUE);

	CString szJongmok = m_strJongmok ; 
	
	CString szInput ;

	szJongmok.TrimLeft() ;
	szJongmok.TrimRight() ;
	
	int nLen = sizeof(TR_10051_I) ;
	TR_10051_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_10051_I)) ;
	memcpy ( stInput.shcode, szJongmok, szJongmok.GetLength() ) ;

	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput );	

	theApp.SendToServerEx (DRCM_SENDDATA, TR_10051, szInput, m_hWnd);

}


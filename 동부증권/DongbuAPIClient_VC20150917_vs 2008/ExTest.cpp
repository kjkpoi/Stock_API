#include "StdAfx.h"
#include "DongbuAPIClient_VC.h"
#include "ExTest.h"
#include "APITest.h"

#include "include_sk/TR10051.h"
#include "include_fo/TR09650.h"
#include "include_fo/TR09651.h"

IMPLEMENT_DYNAMIC(ExTest, CDialog)

ExTest::ExTest(CWnd* pParent) 
: CDialog(ExTest::IDD, pParent)
{
	apiTest = (APITest *) AfxGetApp();
	m_strJongmok = theApp.g_strJongmok;
}

ExTest::~ExTest(void)
{
}


void ExTest::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CExHogaDlg)
	
	DDX_Text(pDX, IDC_EDT_JONGMOK,		m_strJongmok);	
	DDX_Control(pDX, IDC_LIST,			m_lstMsg);	
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(ExTest, CDialog)

	ON_WM_COPYDATA()
	
	ON_BN_CLICKED(IDC_BTN_INQUERY,		OnBtnRequestSise)
END_MESSAGE_MAP()



BOOL ExTest::OnInitDialog() 
{
	CDialog::OnInitDialog();

	return TRUE;
}

CString ExTest::getString(char *str, int len) 
{
	char *tmp;
	CString result;
	tmp = (char *)malloc(len + 1);
	for(int i = 0; i < len; i++) {
		tmp[i] = str[i];
	}
	tmp[len] = '\0';

	result.Format("%s", tmp);
	result.Trim();
	free(tmp);
	return result;
}

BOOL ExTest::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
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
		CString tt = getString(pData->baseprice, 9);
		strMsg.Format("코드: %s, 기준가: %s", getString(pData->upcode, 7), getString(pData->baseprice, 9));
		m_lstMsg.InsertString( 0, szJong );

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


void ExTest::OnBtnRequestSise()
{	
	switch (m_nProduct)
	{
	case ID_PRODUCT_SK : //주식
		MakePacket_SK();
		break;
	}	
}

void ExTest::MakePacket_SK()
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
	apiTest->Test();
	//::SendMessage(apiTest->m_hWnd, WM_COPYDATA, NULL, NULL);
	//::SendMessage(apiTest->GetSafeHwnd(), WM_MSGTEST, NULL, NULL); // 메시지 보냄
	//::SendMessage(apiTest->m_hWnd, WM_MSGTEST, NULL, NULL); // 메시지 보냄
	//::SendMessage(apiTest->GetSafeHwnd(), WM_COPYDATA, NULL, NULL);

	int nNumber = 1000; 

	//CWinThread *pThread = ::AfxBeginThread(ThreadFunc, &nNumber); 

	theApp.SendToServerEx (DRCM_SENDDATA, TR_10051, szInput, m_hWnd);
	//theApp.SendToServerEx (DRCM_SENDDATA, TR_10051, szInput, m_hWnd);

}

/*UINT ExTest::ThreadFunc(LPVOID pParam) { 
	int j = (int)pParam; 
	for (int i=0; i<j; i++) 
	{ 
		printf("%d", i);
	} 
}*/
// ExSiseDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "DongbuAPIClient_VC.h"
#include "ExSiseDlg.h"


// CExSiseDlg ��ȭ �����Դϴ�.

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


// CExSiseDlg �޽��� ó�����Դϴ�.

BOOL CExSiseDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


//=======================================================================================
// FUNCTION : ����apI �κ��� ������ ����
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

	//�ֽ� ���簡
	if ( strcmp(szTrCode, TR_09110 ) == 0 )
	{		
		TR_09110_O* pData = (TR_09110_O*)prData->TRData;
		int nPrice = theApp.gatoi( pData->jong.price, sizeof(pData->jong.price) ) ;

		CString szJong ;
		szJong.Format( "%.*s ���簡 : %d", sizeof(pData->hname), pData->hname , nPrice) ;

	
		//*********************************
		//ȭ�鿡 �°� �����͸� ó��
		//*********************************
		m_lstMsg.InsertString( 0, szJong );

		strMsg= "�ֽ� ���簡 ��ȸ ���>>" ;
		m_lstMsg.InsertString( 0, strMsg );

		UpdateData(FALSE) ;
	}

	return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
}

//=======================================================================================
// FUNCTION : �ǽð� ������ ��û_ �ü�
// RETURN   : 
//=======================================================================================
void CExSiseDlg::OnBtnRequestSise()
{	
	switch (m_nProduct)
	{
	case ID_PRODUCT_SK : //�ֽ�
		MakePacket_SK();
		break;
	}	
}


//=======================================================================================
// FUNCTION : ����api�� ������ ��û (�ֽ�)
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


// ExChegyulDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "DongbuAPIClient_VC.h"
#include "ExChegyulDlg.h"


// CExChegyulDlg ��ȭ �����Դϴ�.

#include "include_cme/TR20111.h"
#include "include_cme/DrdsXF5.h"

//#include "include_fo/TR13615.h"
#include "include_fo/TR13616.h"
#include "include_fo/DrdsXF2.h"

#include "include_SK/TR13118.h"
#include "include_SK/DrdsXX1.h"


IMPLEMENT_DYNAMIC(CExChegyulDlg, CDialog)

CExChegyulDlg::CExChegyulDlg(CWnd* pParent /*=NULL*/)
: CDialog(CExChegyulDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExChegyulDlg)
	m_strAccount = theApp.g_strAccount;
	m_strAcctPwd =  theApp.g_strAcctPwd;		
	//}}AFX_DATA_INIT
}

CExChegyulDlg::~CExChegyulDlg()
{
}

void CExChegyulDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CExChegyulDlg)
	DDX_Control(pDX, IDC_LIST,			m_lstMsg);	
	DDX_Text(pDX, IDC_EDT_ACCOUNT,		m_strAccount);
	DDX_Text(pDX, IDC_EDT_ACCTPWD,		m_strAcctPwd);		
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExChegyulDlg, CDialog)

	ON_WM_COPYDATA()
	ON_BN_CLICKED(IDC_BTN_INQUERY, OnBtnInquery)
	ON_BN_CLICKED(IDC_CHK_REALTIME, OnBtnRequestRealtimeData)
	ON_BN_CLICKED(IDC_BTN_INQUERY_NEXT, &CExChegyulDlg::OnBnClickedBtnInqueryNext)
END_MESSAGE_MAP()


// CExChegyulDlg �޽��� ó�����Դϴ�.

BOOL CExChegyulDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	SetWindowText("ü�� ���� ��ȸ") ;

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

//=======================================================================================
// FUNCTION : �ǽð� ������ ��û
// RETURN   : 
//=======================================================================================
void CExChegyulDlg::OnBtnRequestRealtimeData()
{
	BOOL bAdvise = ((CButton *)GetDlgItem(IDC_CHK_REALTIME))->GetCheck() ;
	int nAdvise = bAdvise ? DRCM_ADVICE : DRCM_UNADVICE ;

	switch (m_nProduct)
	{
	// �����ɼ�	ü��	
	case ID_PRODUCT_FO :
		theApp.SendToServerEx (nAdvise, R_XF2, theApp.g_szId, m_hWnd );	
		break;

	case ID_PRODUCT_CME : //CME����	ü��	
		theApp.SendToServerEx (nAdvise, R_XF5, theApp.g_szId, m_hWnd );	
		break;

	// �ֽ�	ü��	
	case ID_PRODUCT_SK :
		theApp.SendToServerEx (nAdvise, R_XX1, theApp.g_szId, m_hWnd );	
		break;
	}	
}

//=======================================================================================
// FUNCTION : ���������� ��ȸ
// RETURN   : 
//=======================================================================================
void CExChegyulDlg::OnBnClickedBtnInqueryNext()
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
// FUNCTION : ��ȸ
// RETURN   : 
//=======================================================================================
void CExChegyulDlg::OnBtnInquery()
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
// FUNCTION : ����api�� ������ ��û(CME����)
// RETURN   : 
//=======================================================================================
void CExChegyulDlg::MakePacket_CME()
{
	UpdateData (TRUE) ;
	
	CString szAccount = m_strAccount ; 	
	CString szPwd = m_strAcctPwd ;
	CString szInput ;
	
	szAccount.TrimLeft() ;
	szAccount.TrimRight() ;
	szAccount.Remove('-');

	TR_20111_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_20111_I)) ;
	memcpy ( stInput.geja, szAccount, szAccount.GetLength() ) ;
	memcpy ( stInput.passwd, szPwd, szPwd.GetLength() ) ;
	memcpy ( stInput.sort, "2", 1 ) ;	//����(1) ����(2)  

	int nLen = sizeof(stInput) ;
	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);				
	
	theApp.SendToServerEx (DRCM_SENDDATA, TR_20111, szInput, m_hWnd);
}

//=======================================================================================
// FUNCTION : ����api�� ������ ��û (��������, �ֽļ���)
// RETURN   : ����ó�� �ȵ� 
//=======================================================================================
//void CExChegyulDlg::MakePacket_FO()
//{
//	UpdateData (TRUE) ;
//
//	CString szAccount = m_strAccount ; 	
//	CString szPwd = m_strAcctPwd ;
//	CString szInput ;
//
//	szAccount.TrimLeft() ;
//	szAccount.TrimRight() ;
//	szAccount.Remove('-');
//
//	TR_13615_I stInput ;
//	memset (&stInput, 0x20, sizeof(TR_13615_I)) ;
//	memcpy ( stInput.geja, szAccount, szAccount.GetLength() ) ;
//	memcpy ( stInput.passwd, szPwd, szPwd.GetLength() ) ;
//	memcpy ( stInput.sort, "2", 1 ) ;	//����(1) ����(2)  
//
//	int nLen = sizeof(stInput) ;
//	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);				
//
//	theApp.SendToServerEx (DRCM_SENDDATA, TR_13615, szInput, m_hWnd);	
//}

//=======================================================================================
// FUNCTION : ����api�� ������ ��û (��������, �ֽļ���)
// RETURN   : ����ó�� ������ TR
//=======================================================================================
void CExChegyulDlg::MakePacket_FO()
{
	UpdateData (TRUE) ;

	CString szAccount = m_strAccount ; 	
	CString szPwd = m_strAcctPwd ;
	CString szJongmok ;
	CString szNext ;
	CString szInput ;
	
	szAccount.TrimLeft() ;
	szAccount.TrimRight() ;
	szAccount.Remove('-');

	TR_13616_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_13616_I)) ;
	memcpy ( stInput.geja, szAccount, szAccount.GetLength() ) ;
	memcpy ( stInput.checkgb, "0", 1 ) ;	//��ȸ���� 0:��ü, 1:���� 
	//memcpy ( stInput.jgcode, szJongmok, szJongmok.GetLength() ) ; //�����ڵ� 
	
	szNext.Format("%0*d", sizeof(stInput.nxtKey), atoi(m_szNextKey) );
	if ( atoi(m_szNextKey) == 0)	
		stInput.nxtGb[0] = '0';
	else
		stInput.nxtGb[0] = '1';	

	stInput.jugb[0] = '0'; /* 0��ü 1�ż� 2�ŵ�                */
	memcpy(stInput.nxtKey, (LPSTR)(LPCTSTR)szNext, szNext.GetLength()) ;
		

	int nLen = sizeof(stInput) ;
	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);				

	theApp.SendToServerEx (DRCM_SENDDATA, TR_13616, szInput, m_hWnd);	


	m_szNextKey = "" ;
}

//=======================================================================================
// FUNCTION : ����api�� ������ ��û (�ֽ�)
// RETURN   : 
//=======================================================================================
void CExChegyulDlg::MakePacket_SK()
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
	memcpy ( stInput.sgb, "1", 1 ) ;  // 1:�ֹ�/ü�� 2:��ü��		
	memcpy ( stInput.sort, "2", 1 ) ; //����
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
// FUNCTION : ����apI �κ��� ������ ����
// RETURN   : 
//=======================================================================================
BOOL CExChegyulDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
{
	COPYDATASTRUCT* pCDS = pCopyDataStruct ;

	int nDataType = (int)pCDS->dwData ;	
	switch (nDataType)
	{	

	case DRCM_DRDS_DATA :  //�ǽð� ����Ÿ
		{
			DrdsData* pDrdsData = (DrdsData*)pCDS->lpData;

			//���� ü�� �ǽð�������
			if (memcmp(pDrdsData->Name, R_XF2, 3) == 0)
			{
				nDataType = eXF2 ;
				DRDS_XF2_DATA* pReal = (DRDS_XF2_DATA*)pDrdsData->Data;	
				//*********************************
				//ȭ�鿡 �°� �����͸� ó��
				//*********************************
			}
			//CME���� ü�� �ǽð�������
			else if (memcmp(pDrdsData->Name, R_XF5, 3) == 0)
			{
				nDataType = eXF5 ;
				DRDS_XF5_DATA* pReal = (DRDS_XF5_DATA*)pDrdsData->Data;	
				//*********************************
				//ȭ�鿡 �°� �����͸� ó��
				//*********************************
			}

			//�ֽ� ü�� �ǽð�������
			else if (memcmp(pDrdsData->Name, R_XX1, 3) == 0)
			{
				nDataType = eXX1 ;
				DRDS_XX1_DATA* pReal = (DRDS_XX1_DATA*)pDrdsData->Data;	

				CDRDS_XX1_DATA stRealData ;
				stRealData.Convert(pReal) ;

				CString strMsg ;
				strMsg= "�ֽ� ü�� �ǽð������� ����(�ֹ���ȣ) >>" + stRealData.m_szjuno;
				m_lstMsg.InsertString( 0, strMsg );

				//*********************************
				//ȭ�鿡 �°� �����͸� ó��
				//*********************************
			}
			break ;	
		}			

	default: //��ȸ ������
		{
			STTRHEADER* prData = (STTRHEADER*)pCDS->lpData;
			char szTrCode[5+1] ={0,} ;
			char szMsg[82+1] ={0,} ;
			CString strMsg  ;


			memcpy(szTrCode, prData->TRCode, 5 ) ;
			memcpy(szMsg, prData->Message, 82) ;

			strMsg = szMsg ;
			strMsg.TrimRight() ;

			//�������� ü�᳻��
			//	
			//}
			if ( strcmp(szTrCode, TR_13616 ) == 0 ) 
			{
				TR_13616_O* pData = (TR_13616_O*)prData->TRData;

				CTR_13616_O tr_13616_output;
				tr_13616_output.Convert(pData);
				if ( tr_13616_output.m_szNextFlag = "1")	
				{
					m_szNextKey = tr_13616_output.m_szNextVal ;
					GetDlgItem(IDC_BTN_INQUERY_NEXT)->EnableWindow(TRUE) ;
				}
				else
				{
					m_szNextKey = "" ;		
					GetDlgItem(IDC_BTN_INQUERY_NEXT)->EnableWindow(FALSE) ;
				}

				for(int i=0; i < tr_13616_output.m_ngridcnt; i++)
				{
					m_lstMsg.InsertString( 0, pData->grid[i].juno );
					//*********************************
					//ȭ�鿡 �°� �����͸� ó��
					//*********************************
				}

				strMsg= "���� ü����ȸ ���>>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;
			}

			//CME���� ü�᳻��
			if ( strcmp(szTrCode, TR_20111 ) == 0 ) 
			{					
				TR_20111_O* pData = (TR_20111_O*)prData->TRData;

				int count = theApp.gatoi( pData->gridcnt, sizeof(pData->gridcnt) ) ;		
				for ( int i =0; i < count; i++)
				{											
				}

				strMsg= "CME���� ü����ȸ ���>>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;

				//*********************************
				//ȭ�鿡 �°� �����͸� ó��
				//*********************************
			}

			//�ֽ� ü�� ����
			if ( strcmp(szTrCode, TR_13118 ) == 0 )
			{								
				TR_13118_O* pData = (TR_13118_O*)prData->TRData;
				TR_13118_G* pGR = (TR_13118_G *)(pData->gr_DATA);
				int count = theApp.gatoi( pData->gr_cnt, sizeof(pData->gr_cnt) ) ;

				for ( int i =0; i < count; i++)
				{	
					TR_13118_G* pGridData = (TR_13118_G*)(&pGR[i]);

					//*********************************
					//ȭ�鿡 �°� �����͸� ó��
					//*********************************
				}
				strMsg= "�ֽ� ü����ȸ ���>>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;


			}

		}
	}

	return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
}


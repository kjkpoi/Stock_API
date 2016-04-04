// ExJangoDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "DongbuAPIClient_VC.h"
#include "ExJangoDlg.h"


// CExJangoDlg ��ȭ �����Դϴ�.

#include "include_cme/TR20110.h"
#include "include_fo/TR13655.h"
#include "include_sk/TR13148.h"
#include "include_sk/TR13147.h"

#include "include_cme/DrdsXF6.h"
#include "include_fo/DrdsXF3.h"
#include "include_sk/DrdsXX6.h"
#include "include_sk/DrdsXX9.h"

IMPLEMENT_DYNAMIC(CExJangoDlg, CDialog)

CExJangoDlg::CExJangoDlg(CWnd* pParent /*=NULL*/)
: CDialog(CExJangoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExJangoDlg)
	m_strAccount = theApp.g_strAccount;
	//}}AFX_DATA_INIT
}

CExJangoDlg::~CExJangoDlg()
{
}

void CExJangoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CExJangoDlg)
	DDX_Control(pDX, IDC_LIST,			m_lstMsg);	
	DDX_Text(pDX, IDC_EDT_ACCOUNT,		m_strAccount);	
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExJangoDlg, CDialog)

	ON_WM_COPYDATA()
	ON_BN_CLICKED(IDC_BTN_INQUERY,  OnBtnInquery)
	ON_BN_CLICKED(IDC_CHK_REALTIME, OnBtnRequestRealtimeData)	
END_MESSAGE_MAP()


// CExJangoDlg �޽��� ó�����Դϴ�.

BOOL CExJangoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CExJangoDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
{
	COPYDATASTRUCT* pCDS = pCopyDataStruct ;

	int nDataType = (int)pCDS->dwData ;	
	switch (nDataType)
	{	
	case DRCM_DRDS_DATA :  //�ǽð� ����Ÿ
		{
			CString strMsg ;
			DrdsData* pDrdsData = (DrdsData*)pCDS->lpData;

			//���� �ܰ� �ǽð�������
			if (memcmp(pDrdsData->Name, R_XF3, 3) == 0)
			{
				nDataType = eXF3 ;
				DRDS_XF3_DATA* pReal = (DRDS_XF3_DATA*)pDrdsData->Data;	

				strMsg.Format("XF3 �ܰ� �ǽð� ������ ����");
				m_lstMsg.InsertString( 0, strMsg );
				//*********************************
				//ȭ�鿡 �°� �����͸� ó��
				//*********************************
			}
			//CME���� �ܰ� �ǽð�������
			else if (memcmp(pDrdsData->Name, R_XF6, 3) == 0)
			{
				nDataType = eXF6 ;
				DRDS_XF6_DATA* pReal = (DRDS_XF6_DATA*)pDrdsData->Data;	

				strMsg.Format("XF6 �ܰ� �ǽð� ������ ����");
				m_lstMsg.InsertString( 0, strMsg );
				//*********************************
				//ȭ�鿡 �°� �����͸� ó��
				//*********************************
				
			}
			//�ֽ� �ܰ� �ǽð�������
			else if (memcmp(pDrdsData->Name, R_XX6, 3) == 0)
			{
				nDataType = eXX6 ;
				DRDS_XX6_DATA* pReal = (DRDS_XX6_DATA*)pDrdsData->Data;	

				CDRDS_XX6_DATA stRealData ;
				stRealData.Convert(pReal) ;

				CString strMsg ;
				strMsg= "�ֽ� �ܰ� �ǽð������� ����(�����ڵ�) >>" + stRealData.m_szjgcode;
				m_lstMsg.InsertString( 0, strMsg );
				
			}
			//�ֽ� �ܰ� �ǽð�������(�ſ�����)
			else if (memcmp(pDrdsData->Name, R_XX9, 3) == 0)
			{
				nDataType = eXX9 ;
				DRDS_XX9_DATA* pReal = (DRDS_XX9_DATA*)pDrdsData->Data;	

				CDRDS_XX9_DATA stRealData ;
				stRealData.Convert(pReal) ;

				CString strMsg ;
				strMsg= "�ֽ� �ܰ� �ǽð�������(�ſ�����) ����(�����ڵ�) >>" + stRealData.m_szjgcode;
				m_lstMsg.InsertString( 0, strMsg );

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

			//���� �ܰ�
			if ( strcmp(szTrCode, TR_13655 ) == 0 ) 
			{					
				TR_13655_O* pData = (TR_13655_O*)prData->TRData;	
				int count = theApp.gatoi( pData->gridcnt, sizeof(pData->gridcnt) ) ;		
				for ( int i =0; i < count; i++)
				{		
					CString szTmp, szJongmok, szQty, szPrice ;

					int nSize = sizeof(TR_13655_G) ;
					szJongmok.Format("%*.*s", sizeof(pData->gr[i].jocode), sizeof(pData->gr[i].jocode), pData->gr[i].jocode) ;
					szQty.Format("%*.*s", sizeof(pData->gr[i].tnonqty), sizeof(pData->gr[i].tnonqty), pData->gr[i].tnonqty) ;
					szPrice.Format("%*.*s", sizeof(pData->gr[i].tnonprc), sizeof(pData->gr[i].tnonprc), pData->gr[i].tnonprc) ;

					szTmp.Format("����:%s ��������:%s ���Դܰ�:%s", szJongmok, szQty, szPrice) ;

					m_lstMsg.InsertString( 0, szTmp );							
				}

				strMsg= "���� �ܰ���ȸ ���>>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;

				//*********************************
				//ȭ�鿡 �°� �����͸� ó��
				//*********************************
			}

			//CME �ܰ�
			else if ( strcmp(szTrCode, TR_20110 ) == 0 ) 
			{					
				TR_20110_O* pData = (TR_20110_O*)prData->TRData;	
				int count = theApp.gatoi( pData->gridcnt, sizeof(pData->gridcnt) ) ;		
				for ( int i =0; i < count; i++)
				{		
					CString szTmp, szJongmok, szQty, szPrice ;

					int nSize = sizeof(TR_20110_G) ;
					szJongmok.Format("%*.*s", sizeof(pData->gr[i].jocode), sizeof(pData->gr[i].jocode), pData->gr[i].jocode) ;
					szQty.Format("%*.*s", sizeof(pData->gr[i].tnonqty), sizeof(pData->gr[i].tnonqty), pData->gr[i].tnonqty) ;
					szPrice.Format("%*.*s", sizeof(pData->gr[i].tnonprc), sizeof(pData->gr[i].tnonprc), pData->gr[i].tnonprc) ;

					szTmp.Format("����:%s ��������:%s ���Դܰ�:%s", szJongmok, szQty, szPrice) ;

					m_lstMsg.InsertString( 0, szTmp );							
				}

				strMsg= "CME ���� �ܰ���ȸ ���>>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;

				//*********************************
				//ȭ�鿡 �°� �����͸� ó��
				//*********************************
			}

			//�ֽ� �ܰ�
			else if ( strcmp(szTrCode, TR_13148 ) == 0 ) 
			{					
				TR_13148_O* pData = (TR_13148_O*)prData->TRData;					
				int count = theApp.gatoi(pData->gr_bjlen, 4) ;		
				for ( int i =0; i < count; i++)
				{		
					CString szTmp, szJongmok, szQty, szPrice ;

					int nSize = sizeof(TR_13148_G) ;
					szJongmok.Format("%*.*s", sizeof(pData->gr[i].jocode), sizeof(pData->gr[i].jocode), pData->gr[i].jocode) ;
					szQty.Format("%*.*s", sizeof(pData->gr[i].qntybooknon), sizeof(pData->gr[i].qntybooknon), pData->gr[i].qntybooknon) ;
					szPrice.Format("%*.*s", sizeof(pData->gr[i].prcebooknon), sizeof(pData->gr[i].prcebooknon), pData->gr[i].prcebooknon) ;

					szTmp.Format("����:%s ��������:%s ���Դܰ�:%s", szJongmok, szQty, szPrice) ;

					m_lstMsg.InsertString( 0, szTmp );							
				}

				strMsg= "�ֽ� �ܰ���ȸ ���>>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;

				//*********************************
				//ȭ�鿡 �°� �����͸� ó��
				//*********************************
			}

			//�ֽ� �ܰ�2
			else if ( strcmp(szTrCode, TR_13147 ) == 0 ) 
			{					
				TR_13147_O* pData = (TR_13147_O*)prData->TRData;					
				int count = theApp.gatoi(pData->gr_bjlen, 4) ;		
				for ( int i =0; i < count; i++)
				{		
					CString szTmp, szJongmok, szQty, szPrice ;

					int nSize = sizeof(TR_13147_G) ;
					szJongmok.Format("%*.*s", sizeof(pData->gr[i].jocode), sizeof(pData->gr[i].jocode), pData->gr[i].jocode) ;
					szQty.Format("%*.*s", sizeof(pData->gr[i].qntybooknon), sizeof(pData->gr[i].qntybooknon), pData->gr[i].qntybooknon) ;
					szPrice.Format("%*.*s", sizeof(pData->gr[i].prcebooknon), sizeof(pData->gr[i].prcebooknon), pData->gr[i].prcebooknon) ;

					szTmp.Format("����:%s ��������:%s ���Դܰ�:%s", szJongmok, szQty, szPrice) ;

					m_lstMsg.InsertString( 0, szTmp );							
				}

				strMsg= "�ֽ� �ܰ���ȸ2 ���>>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;

				//*********************************
				//ȭ�鿡 �°� �����͸� ó��
				//*********************************
			}
		}		
	}

	return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
}

//=======================================================================================
// FUNCTION : �ǽð� ������ ��û
// RETURN   : 
//=======================================================================================
void CExJangoDlg::OnBtnRequestRealtimeData()
{
	BOOL bAdvise = ((CButton *)GetDlgItem(IDC_CHK_REALTIME))->GetCheck() ;
	int nAdvise = bAdvise ? DRCM_ADVICE : DRCM_UNADVICE ;

	switch (m_nProduct)
	{
	case ID_PRODUCT_FO :// �����ɼ�	�ܰ�
		theApp.SendToServerEx (nAdvise, R_XF3, theApp.g_szId, m_hWnd );	
		break;

	case ID_PRODUCT_CME : //CME���� �ܰ�
		theApp.SendToServerEx (nAdvise, R_XF6, theApp.g_szId, m_hWnd );	
		break;

	case ID_PRODUCT_SK :// �ֽ�
		theApp.SendToServerEx (nAdvise, R_XX6, theApp.g_szId, m_hWnd );	
		break;
	}	
}

//=======================================================================================
// FUNCTION : ��ȸ
// RETURN   : 
//=======================================================================================
void CExJangoDlg::OnBtnInquery()
{
	switch (m_nProduct)
	{
	case ID_PRODUCT_FO :   // ���� �����ɼ�	
	case ID_PRODUCT_SFO :  // �ֽ� �����ɼ�
		MakePacket_FO();
		break;

	case ID_PRODUCT_CME : // CME����	
		MakePacket_CME() ;
		break;

	case ID_PRODUCT_SK : // �ֽ�
		//MakePacket_SK() ;
		MakePacket_SK_Simple() ;
		break;
	}	
}

//=======================================================================================
// FUNCTION : ����api�� ������ ��û (CME����)
// RETURN   : 
//=======================================================================================
void CExJangoDlg::MakePacket_CME()
{
	UpdateData (TRUE) ;

	CString szAccount = m_strAccount ; 	
	CString szInput ;
	
	szAccount.TrimLeft() ;
	szAccount.TrimRight() ;
	szAccount.Remove('-');

	int nLen = sizeof(TR_20110_I) ;
	szInput.Format("%-*.*s", nLen , nLen, szAccount );	
	theApp.SendToServerEx (DRCM_SENDDATA, TR_20110, szInput, m_hWnd);
}

//=======================================================================================
// FUNCTION : ����api�� ������ ��û (�����ɼ�)
// RETURN   : 
//=======================================================================================
void CExJangoDlg::MakePacket_FO()
{	
	UpdateData (TRUE) ;

	int nLen = 0 ;
	
	CString szAccount = m_strAccount ; 
	
	CString szInput ;
	
	szAccount.TrimLeft() ;
	szAccount.TrimRight() ;
	szAccount.Remove('-');

	nLen = sizeof(TR_13655_I) ;
	szInput.Format("%-*.*s", nLen , nLen, szAccount );	
	theApp.SendToServerEx (DRCM_SENDDATA, TR_13655, szInput, m_hWnd);
	
}

//=======================================================================================
// FUNCTION : ����api�� ������ ��û (�ֽ�)
// RETURN   : 
//=======================================================================================
void CExJangoDlg::MakePacket_SK()
{	
	UpdateData (TRUE) ;

	int nLen = 0 ;

	CString szAccount = m_strAccount ; 
	CString szGubun = "0" ;/* ��ȸ���� 0:�ܰ� 1:�� 2:ü���ܰ� */
	CString szNext ;

	CString szInput ;

	szAccount.TrimLeft() ;
	szAccount.TrimRight() ;
	szAccount.Remove('-');

	nLen = sizeof(TR_13147_I) ;
	TR_13147_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_13147_I)) ;
	memcpy ( stInput.geja, szAccount, szAccount.GetLength() ) ;
	memcpy ( stInput.gbun, szGubun, 1 ) ;
	memcpy ( stInput.ngbn, "0", 1 ) ;	

	szNext.Format("%0*d", sizeof(stInput.next), 0 );
	memcpy ( stInput.next, (LPCTSTR)szNext, szNext.GetLength() ) ;

	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput );	

	theApp.SendToServerEx (DRCM_SENDDATA, TR_13147, szInput, m_hWnd);
}


//=======================================================================================
// FUNCTION : ����api�� ������ ��û (�ֽ�)
// RETURN   : 
//=======================================================================================
void CExJangoDlg::MakePacket_SK_Simple()
{	
	UpdateData (TRUE) ;

	int nLen = 0 ;

	CString szAccount = m_strAccount ; 
	CString szGubun = "0" ;/* ��ȸ���� 0:�ܰ� 1:�� 2:ü���ܰ� */
	CString szNext ;

	CString szInput ;

	szAccount.TrimLeft() ;
	szAccount.TrimRight() ;
	szAccount.Remove('-');

	nLen = sizeof(TR_13148_I) ;
	TR_13148_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_13148_I)) ;
	memcpy ( stInput.geja, szAccount, szAccount.GetLength() ) ;
	memcpy ( stInput.gbun, szGubun, 1 ) ;
	memcpy ( stInput.ngbn, "0", 1 ) ;	

	szNext.Format("%0*d", sizeof(stInput.next), 0 );
	memcpy ( stInput.next, (LPCTSTR)szNext, szNext.GetLength() ) ;

	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput );	

	theApp.SendToServerEx (DRCM_SENDDATA, TR_13148, szInput, m_hWnd);
}



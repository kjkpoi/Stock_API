// ExInvestTodayDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "DongbuAPIClient_VC.h"
#include "ExInvestTodayDlg.h"

#include "include_sk/TR01921.h"


// CExInvestTodayDlg ��ȭ �����Դϴ�.

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

// CExInvestTodayDlg �޽��� ó�����Դϴ�.

BOOL CExInvestTodayDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


//=======================================================================================
// FUNCTION : ���������� ��ȸ
// RETURN   : 
//=======================================================================================
void CExInvestTodayDlg::OnBnClickedBtnInqueryNext()
{
	GetDlgItem(IDC_BTN_INQUERY_NEXT)->EnableWindow(FALSE);

	MakePacket() ;
}


//=======================================================================================
// FUNCTION : ��ȸ
// RETURN   : 
//=======================================================================================
void CExInvestTodayDlg::OnBtnInquery()
{
	GetDlgItem(IDC_BTN_INQUERY_NEXT)->EnableWindow(FALSE);
	m_szNextKey ="";

	MakePacket() ;
}

//=======================================================================================
// FUNCTION : ����api�� ������ ��û 
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
		szGubun = "2" ; //�����2 ����/��Ÿ����3 ����4 ����5 �����6 ��������ü7 ��Ÿ����8 */
	}

	memcpy ( stInput.tuja_tp, szGubun, 1 ) ;  /* 0��ü �ܱ���1 �����2 ����/��Ÿ���� ����4 ����5 �����6 ��������ü7 ��Ÿ����8 */	
	memcpy ( stInput.shcode, m_strJongmok, SH_KSIZE ) ; 

	memcpy ( stInput.sort_tp, "00", 1 ) ; /* ���ļ���: 00�ܱ��μ��ż��� 01�ܱ��μ��ŵ��� 02�������ż��� 03�������ŵ���~ */

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
// FUNCTION : ����apI �κ��� ������ ����
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

			
			//������ ���� �Ÿ����� ��ȸ
			if ( strcmp(szTrCode, TR_01921) == 0 )
			{								
				TR_01921_O* pData = (TR_01921_O*)prData->TRData;
				TR_01921_OS* pGR = (TR_01921_OS *)(pData->data);
				int count = theApp.gatoi( pData->grdCnt, sizeof(pData->grdCnt) ) ;

				for ( int i =0; i < count; i++)
				{	
					TR_01921_OS* pGridData = (TR_01921_OS*)(&pData->data[i]);

					//*********************************
					//ȭ�鿡 �°� �����͸� ó��
					//*********************************
				}
				strMsg= "������ ���� �Ÿ����� ��ȸ>>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;

			}

		}
	}

	return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
}

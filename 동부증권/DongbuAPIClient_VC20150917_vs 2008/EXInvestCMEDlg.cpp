// ExInvestCMEDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "DongbuAPIClient_VC.h"
#include "ExInvestCMEDlg.h"

#include "include_CME/TR25220.h"


// CExInvestCMEDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CExInvestCMEDlg, CDialog)

CExInvestCMEDlg::CExInvestCMEDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExInvestCMEDlg::IDD, pParent)
{

}

CExInvestCMEDlg::~CExInvestCMEDlg()
{
}

void CExInvestCMEDlg::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(ExInvestCMEDlg)
	DDX_Control(pDX, IDC_LIST,			m_lstMsg);	

	//}}AFX_DATA_MAP
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CExInvestCMEDlg, CDialog)

	ON_WM_COPYDATA()
	ON_BN_CLICKED(IDC_BTN_INQUERY,		OnBtnInquery)	
	ON_BN_CLICKED(IDC_BTN_INQUERY_NEXT, OnBnClickedBtnInqueryNext)
	
	ON_BN_CLICKED(IDC_BTN_INQUERY2, &CExInvestCMEDlg::OnBnClickedBtnInquery2)
END_MESSAGE_MAP()

// CExInvestCMEDlg �޽��� ó�����Դϴ�.

BOOL CExInvestCMEDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


//=======================================================================================
// FUNCTION : ���������� ��ȸ
// RETURN   : 
//=======================================================================================
void CExInvestCMEDlg::OnBnClickedBtnInqueryNext()
{
	GetDlgItem(IDC_BTN_INQUERY_NEXT)->EnableWindow(FALSE);

	MakePacket() ;
}


//=======================================================================================
// FUNCTION : ��ȸ
// RETURN   : 
//=======================================================================================
void CExInvestCMEDlg::OnBtnInquery()
{
	GetDlgItem(IDC_BTN_INQUERY_NEXT)->EnableWindow(FALSE);
	m_szNextKey ="";

	MakePacket() ;
}

//=======================================================================================
// FUNCTION : ����api�� ������ ��û 
// RETURN   : 
//=======================================================================================
void CExInvestCMEDlg::MakePacket()
{
	UpdateData (TRUE) ;

	
	CString szInput ;
	CString szNext ;

	TR_25220_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_25220_I)) ;

	BOOL b100 = ((CButton *)GetDlgItem(IDC_RADIO_BACK))->GetCheck() ;
	BOOL bQty = ((CButton *)GetDlgItem(IDC_RADIO_COUNT))->GetCheck() ;
	CString szGubun;

	if ( b100 )
		szGubun = "1" ;
	else if ( bQty)
		szGubun = "2" ;
	else	
		szGubun = "3" ;/* �ݾ�(1), ����(2), �ݾ�(���)(3)	*/
	

	memcpy ( stInput.gubun, szGubun, 1 ) ; /* �ݾ�(1), ����(2), �ݾ�(���)(3)	*/

	szNext.Format("%0*d", sizeof(stInput.next), atoi(m_szNextKey) );
	
	
	memcpy ( stInput.next, (LPCTSTR)szNext, szNext.GetLength() ) ;
	
	int nLen = sizeof(stInput) ;
	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);				

	theApp.SendToServerEx (DRCM_SENDDATA, TR_25220, szInput, m_hWnd);	

	m_szNextKey = "" ;
}


//=======================================================================================
// FUNCTION : ����apI �κ��� ������ ����
// RETURN   : 
//=======================================================================================
BOOL CExInvestCMEDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
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

			
			//cme �����ں�����-
			if ( strcmp(szTrCode, TR_25220) == 0 )
			{								
				TR_25220_O* pData = (TR_25220_O*)prData->TRData;				
				int count = theApp.gatoi( pData->grid_len, sizeof(pData->grid_len) ) ;

				for ( int i =0; i < count; i++)
				{	
					TR_25220_S* pGridData = (TR_25220_S*)(&pData->grid[i]);

					//*********************************
					//ȭ�鿡 �°� �����͸� ó��
					//*********************************
				}
				strMsg= "��ȸ���>>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;

			}

		}
	}

	return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
}

void CExInvestCMEDlg::OnBnClickedBtnInquery2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

// ExInqueryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dongbuapiclient.h"
#include "ExInqueryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExInqueryDlg dialog

CExInqueryDlg::CExInqueryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExInqueryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExInqueryDlg)
	m_strAcctPwd = _T("");
	m_strDate = _T("20121214");
	m_strAccount = _T("");
	//}}AFX_DATA_INIT
}


void CExInqueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExInqueryDlg)
	DDX_Control(pDX, IDC_LIST, m_lstMsg);
	DDX_Text(pDX, IDC_EDT_ACCTPWD, m_strAcctPwd);
	DDX_Text(pDX, IDC_EDT_DATE, m_strDate);
	DDX_Text(pDX, IDC_EDT_ACCOUNT, m_strAccount);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExInqueryDlg, CDialog)
	//{{AFX_MSG_MAP(CExInqueryDlg)
	ON_BN_CLICKED(IDC_BTN_INQURY, OnBtnInqury)
	ON_WM_COPYDATA()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExInqueryDlg message handlers

BOOL CExInqueryDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();		


	CString szText ;
	switch ( m_nTRCode)
	{
	case 13655 : 	
		szText.Format("�ܰ���ȸ ����[TR Code %d]", m_nTRCode) ;		
		break;

	case 13615 : 
		szText.Format("ü����ȸ ����[TR Code %d]", m_nTRCode) ;			
		break;

	case 15813: 
		szText.Format("����Ȳ ����[TR Code %d]", m_nTRCode) ;	

		GetDlgItem(IDC_STATIC_DATE)->ShowWindow(SW_SHOW) ;
		GetDlgItem(IDC_EDT_DATE)->ShowWindow(SW_SHOW) ;		
		break;

	case 13653 : //������ �� �ֹ����� �ݾ�	
		szText.Format("������ �� �ֹ����ɱݾ� ��ȸ ����[TR Code %d]", m_nTRCode) ;	

		GetDlgItem(IDC_STATIC_DATE)->ShowWindow(SW_SHOW) ;
		GetDlgItem(IDC_EDT_DATE)->ShowWindow(SW_SHOW) ;		
		break;
	}

	SetWindowText(szText) ;

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CExInqueryDlg::OnBtnInqury() 
{
	UpdateData(TRUE);	
		
	//CString szData ;
	int nLen = 0 ;
	CString szPwd = m_strAcctPwd ;
	CString szAccount = m_strAccount; 
	CString szDate = m_strDate;
	CString szInput ;
	CString szNextKey = m_szNextKey ;
	CString szIP = theApp.g_szMyIP ;

	switch ( m_nTRCode)
	{
	case 13655 : //�ܰ�
		nLen = sizeof(TR_13655_I) ;
		szInput.Format("%-*.*s", nLen , nLen, szAccount );	
		theApp.SendToServerEx (DRCM_SENDDATA, TR_13655, szInput, m_hWnd);
		break;
	case 13615 : //ü��
		{			
			TR_13615_I stInput ;
			memset (&stInput, 0x20, sizeof(TR_13615_I)) ;
			memcpy ( stInput.geja, szAccount, szAccount.GetLength() ) ;
			memcpy ( stInput.passwd, szPwd, szPwd.GetLength() ) ;
			memcpy ( stInput.sort, "1", 1 ) ;	//����(1) ����(2)  

			nLen = sizeof(stInput) ;
			szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);				
			theApp.SendToServerEx (DRCM_SENDDATA, TR_13615, szInput, m_hWnd);
			break;
		}

	case 15813: //����Ȳ
		{			
			TR_15813_I stInput ;
			memset (&stInput, 0x20, sizeof(TR_15813_I)) ;

			memcpy ( stInput.accno, szAccount, szAccount.GetLength() ) ;
			memcpy ( stInput.pass, szPwd, szPwd.GetLength() ) ;
			memcpy ( stInput.date, szDate, szDate.GetLength() ) ;		
			memcpy ( stInput.janggubun, "2", 1) ;		//�ܰ��򰡱��� #0:�⺻����1:�̵���չ�2:���Լ���� (������ '0'�� ���)
			memcpy ( stInput.futuregubun, "1", 1) ;		//���������򰡱���  #2:��������1:���ʰ�
			memcpy ( stInput.ip_addr, szIP, szIP.GetLength()) ;						
			if (szNextKey.IsEmpty())
				szNextKey.Format("%0*d", sizeof(stInput.nxtKey), 0);
			memcpy ( stInput.nxtKey, szNextKey, szNextKey.GetLength()) ;

			nLen = sizeof(stInput) ;
			szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);
			theApp.SendToServerEx (DRCM_SENDDATA, TR_15813, szInput, m_hWnd);
		}
		break ;
	case 13653 : //������ �� �ֹ����� �ݾ�
		{
			TR_13653_I stInput ;
			memset (&stInput, 0x20, sizeof(TR_13653_I)) ;

			memcpy ( stInput.accno, szAccount, szAccount.GetLength() ) ;
			memcpy ( stInput.pass, szPwd, szPwd.GetLength() ) ;
			memcpy ( stInput.date, szDate, szDate.GetLength() ) ;			
			memcpy ( stInput.ip_addr, szIP, szIP.GetLength()) ;

			nLen = sizeof(stInput) ;
			szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);
			theApp.SendToServerEx (DRCM_SENDDATA, TR_13653, szInput, m_hWnd);	
		}
		break;		
	} // for switch
}


BOOL CExInqueryDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
{
	COPYDATASTRUCT* pCDS = pCopyDataStruct ;

	int nDataType = (int)pCDS->dwData ;

	STTRHEADER* prData = (STTRHEADER*)pCDS->lpData;
	char szTrCode[5+1] ={0,} ;
	char szMsg[82+1] ={0,} ;
	CString strMsg  ;


	int nLen = 0;

	switch (nDataType)
	{
		case DRCM_DISCONNECT : //DRCM �� ����ɶ� ���� �޽���			
			break;
		case DRCM_CLIENT_IP :  //client ip						
			break ;
		case DRCM_F_ACCLIST :  //get future account list						
			break ;
		case DRCM_DRDS_DATA :  //�ǽð� ����Ÿ			
			break;
		default :						
			memcpy(szTrCode, prData->TRCode, 5 ) ;
			memcpy(szMsg, prData->Message, 82) ;

			strMsg = szMsg ;
			strMsg.TrimRight() ;

			//�ܰ���ȸ
			if ( strcmp(szTrCode, TR_13655 ) == 0 )
			{					
				TR_13655_O* pData = (TR_13655_O*)prData->TRData;

				int nSize = sizeof(TR_13655_G);

				strMsg= "�ܰ���ȸ >>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
						
				UpdateData(FALSE) ;
			}
			//ü�᳻�� ��ȸ
			else if (strcmp(szTrCode, TR_13615)==0)
			{
				strMsg= "ü�᳻�� >>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );		
			}
			//����Ȳ
			else if ( strcmp(szTrCode, TR_15813 ) == 0 )
			{			
				strMsg= "����Ȳ >>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
			}
			
			break ;	
	}
	return CDialog::OnCopyData(pWnd, pCopyDataStruct);
}

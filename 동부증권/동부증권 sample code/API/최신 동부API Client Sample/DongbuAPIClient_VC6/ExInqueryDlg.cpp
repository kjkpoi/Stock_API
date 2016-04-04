// ExInqueryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dongbuapiclient.h"
#include "ExInqueryDlg.h"

#include "include/TR15813.h"
#include "include/TR13655.h"
#include "include/TR13653.h"
#include "include/TR13615.h"
#include "include/TR15812.h"

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
	m_strDate = _T("20120103");
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
		szText.Format("잔고조회 예제[TR Code %d]", m_nTRCode) ;		
		break;

	case 13615 : 
		szText.Format("체결조회 예제[TR Code %d]", m_nTRCode) ;			
		break;

	case 15813: 
		szText.Format("평가현황 예제[TR Code %d]", m_nTRCode) ;	

		GetDlgItem(IDC_STATIC_DATE)->ShowWindow(SW_SHOW) ;
		GetDlgItem(IDC_EDT_DATE)->ShowWindow(SW_SHOW) ;		
		break;

	case 13653 : //수수료 및 주문가능 금액	
		szText.Format("수수료 및 주문가능금액 조회 예제[TR Code %d]", m_nTRCode) ;	

		GetDlgItem(IDC_STATIC_DATE)->ShowWindow(SW_SHOW) ;
		GetDlgItem(IDC_EDT_DATE)->ShowWindow(SW_SHOW) ;		
		break;

	case 15812: 
		szText.Format("잔고(원장)조회 예제[TR Code %d]", m_nTRCode) ;	
		
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
	case 13655 : //잔고
		nLen = sizeof(TR_13655_I) ;
		szInput.Format("%-*.*s", nLen , nLen, szAccount );	
		theApp.SendToServerEx (DRCM_SENDDATA, TR_13655, szInput, m_hWnd);
		break;
	case 13615 : //체결
		{			
			TR_13615_I stInput ;
			memset (&stInput, 0x20, sizeof(TR_13615_I)) ;
			memcpy ( stInput.geja, szAccount, szAccount.GetLength() ) ;
			memcpy ( stInput.passwd, szPwd, szPwd.GetLength() ) ;
			memcpy ( stInput.sort, "1", 1 ) ;	//정순(1) 역순(2)  

			nLen = sizeof(stInput) ;
			szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);				
			theApp.SendToServerEx (DRCM_SENDDATA, TR_13615, szInput, m_hWnd);
			break;
		}

	case 15812: //잔고조회(원장)
		{	
			CString szReqCount = "1" ;
			TR_15812_I stInput ;
			memset (&stInput, 0x20, sizeof(TR_15812_I)) ;
			
			memcpy ( stInput.accno, szAccount, szAccount.GetLength() ) ;
			memcpy ( stInput.pass, szPwd, szPwd.GetLength() ) ;
			memcpy ( stInput.date, szDate, szDate.GetLength() ) ;		
			memcpy ( stInput.janggubun, "0", 1) ;		//잔고평가구분 #0:기본설정1:이동평균법2:선입선출법 (보통은 '0'을 사용)
			memcpy ( stInput.futuregubun, "1", 1) ;		//선물가격평가구분  #2:전일종가1:당초가
			memcpy ( stInput.ip_addr, szIP, szIP.GetLength()) ;						
			if (szNextKey.IsEmpty())
				szNextKey.Format("%0*d", sizeof(stInput.nxtKey), 0);
			memcpy ( stInput.nxtKey, szNextKey, szNextKey.GetLength()) ;

			//memcpy ( stInput.reqreccnt, szReqCount, szReqCount.GetLength() ) ;
			
			nLen = sizeof(stInput) ;
			szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);
			theApp.SendToServerEx (DRCM_SENDDATA, TR_15812, szInput, m_hWnd);
		}
		break ;

	case 15813: //평가현황
		{			
			TR_15813_I stInput ;
			memset (&stInput, 0x20, sizeof(TR_15813_I)) ;

			memcpy ( stInput.accno, szAccount, szAccount.GetLength() ) ;
			memcpy ( stInput.pass, szPwd, szPwd.GetLength() ) ;
			memcpy ( stInput.date, szDate, szDate.GetLength() ) ;		
			memcpy ( stInput.janggubun, "0", 1) ;		//잔고평가구분 #0:기본설정1:이동평균법2:선입선출법 (보통은 '0'을 사용)
			memcpy ( stInput.futuregubun, "1", 1) ;		//선물가격평가구분  #2:전일종가1:당초가
			memcpy ( stInput.ip_addr, szIP, szIP.GetLength()) ;						
			if (szNextKey.IsEmpty())
				szNextKey.Format("%0*d", sizeof(stInput.nxtKey), 0);
			memcpy ( stInput.nxtKey, szNextKey, szNextKey.GetLength()) ;

			nLen = sizeof(stInput) ;
			szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);
			theApp.SendToServerEx (DRCM_SENDDATA, TR_15813, szInput, m_hWnd);
		}
		break ;
	case 13653 : //수수료 및 주문가능 금액
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


//보조메시지 파싱 (data count, nextkey 추출)
void CExInqueryDlg::ParseSubMessage(char *pTRData, int &nOffset, int &nCount) 
{
	CString szCount, szData, szHeader, szNextFlag, szNextKey ;
	
	char szTmp[200] = {0x00,};				
	
	//1. 버튼보조메시지 >>				
	int nLenMsg = *(pTRData+nOffset) << 8;
	nLenMsg += *(pTRData+nOffset + 1); 
	
	int nSZ_HEADER = nLenMsg + 2 ;
	
	memcpy(szTmp, (char*)pTRData, nSZ_HEADER);
	for ( int i = 0; i < nSZ_HEADER; i++)
	{
		if (szTmp[i] == NULL)
			szTmp[i] = ' ' ;
	}
	szHeader.Format("%*.*s",nSZ_HEADER, nSZ_HEADER, szTmp);
	szNextFlag = szHeader.Mid(szHeader.Find("EN=") + 3, 1) ;				
	szNextKey = szHeader.Mid(szHeader.Find("DT=") + 3, 18) ;
	
	
	//2.그리드 보조메시지 구조
	nOffset+= nSZ_HEADER ;
	szCount.Format("%4.4s",pTRData + nOffset ) ;
	nCount = atoi(szCount) ;
	
	nOffset+=4;				
	int nLenMsg2 = *(pTRData+nOffset) << 8;
	nLenMsg2 += *(pTRData+nOffset + 1); 
	
	nOffset+=2;
	nOffset += nLenMsg2 ;			
	
	//연속키
	if ( atoi(szNextFlag) == 1) 	
		m_szNextKey.Format("%s%s", szNextFlag, szNextKey) ;
	else
		m_szNextKey.Empty();
	
}

BOOL CExInqueryDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
{
	COPYDATASTRUCT* pCDS = pCopyDataStruct ;

	int nDataType = (int)pCDS->dwData ;

	STTRHEADER* prData = (STTRHEADER*)pCDS->lpData;
	char szTrCode[5+1] ={0,} ;
	char szMsgCode[6+1]={0,} ;
	char szMsg[82+1] ={0,} ;
	CString strMsg  ;

	int nLen = 0;

	switch (nDataType)
	{
		case DRCM_DISCONNECT : //DRCM 이 종료될때 오는 메시지			
			break;
		case DRCM_CLIENT_IP :  //client ip						
			break ;
		case DRCM_F_ACCLIST :  //get future account list						
			break ;
		case DRCM_DRDS_DATA :  //실시간 데이타			
			break;
		default :						
			memcpy(szTrCode, prData->TRCode, sizeof(prData->TRCode) ) ;
			memcpy(szMsgCode, prData->MsgCode, sizeof(prData->MsgCode) ) ;
			memcpy(szMsg, prData->Message, sizeof(prData->Message)) ;
			strMsg = szMsg ;
			strMsg.TrimRight() ;

			//잔고조회
			if ( strcmp(szTrCode, TR_13655 ) == 0 )
			{					
				TR_13655_O* pData = (TR_13655_O*)prData->TRData;

				int nSize = sizeof(TR_13655_G);

				strMsg= "잔고조회 >>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
						
				UpdateData(FALSE) ;
			}
			//체결내역 조회
			else if (strcmp(szTrCode, TR_13615)==0)
			{
				strMsg= "체결내역 >>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );		
			}
			//평가현황
			else if ( strcmp(szTrCode, TR_15813 ) == 0 )
			{			
				strMsg= "평가현황 >>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
			}
			
			//20120109 EUNSOOK 잔고(원장)조회>>			
			else if ( strcmp(szTrCode, TR_15812 ) == 0 )
			{							
				strMsg= "잔고(원장)조회 >>" + strMsg ;				
				m_lstMsg.InsertString( 0, strMsg );

				int nMsgCode  = atoi(szMsgCode+1) ;
				if ( nMsgCode > 1000 )
				{				
					return CDialog::OnCopyData(pWnd, pCopyDataStruct);
				}
				
				int nOffset = sizeof(TR_15812_S) ;
				int nCount = 0 ;
				ParseSubMessage(prData->TRData, nOffset, nCount );

				//잔고리스트
				for ( int i = 0; i < nCount; i++)
				{
					CString szData ;
					int nSZData = sizeof(TR_15812_G) ;
					TR_15812_G* pData = (TR_15812_G*)(prData->TRData+nOffset);
					
					szData.Format("%-*.*s",nSZData, nSZData, pData );
					m_lstMsg.InsertString( 0, szData );					
					nOffset += nSZData;
				}
			}
			//20120109 EUNSOOK <<
			break ;	
	}
	return CDialog::OnCopyData(pWnd, pCopyDataStruct);
}



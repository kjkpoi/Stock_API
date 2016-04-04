// ExInvestChu.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "DongbuAPIClient_VC.h"
#include "ExInvestChu.h"

#include "include_sk/TR01932.h"
#include "include_sk/TR02120.h"


// CExInvestChu ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CExInvestChu, CDialog)

CExInvestChu::CExInvestChu(CWnd* pParent /*=NULL*/)
	: CDialog(CExInvestChu::IDD, pParent)
{

}

CExInvestChu::~CExInvestChu()
{
}

void CExInvestChu::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(ExInvestChu)
	DDX_Control(pDX, IDC_LIST,				m_lstMsg);	
	DDX_Control(pDX, IDC_CMB_INVEST,		m_cmbInvestCode);
	DDX_Control(pDX, IDC_CMB_INVEST2,		m_cmbInvestCode2);

	DDX_Control(pDX, IDC_CMB_UPJONGCODE,	m_cmbUpjong);
	
	DDX_Control(pDX, IDC_CMB_QTY,			m_cmbQty);
	DDX_Control(pDX, IDC_CMB_QTY2,			m_cmbQty2);
	
	//}}AFX_DATA_MAP
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CExInvestChu, CDialog)

	ON_WM_COPYDATA()
	ON_BN_CLICKED(IDC_BTN_INQUERY,		OnBtnInquery)		
	ON_BN_CLICKED(IDC_BTN_INQUERY2,		OnBtnInquery2)	
	
	ON_CBN_SELCHANGE(IDC_CMB_INVEST, &CExInvestChu::OnCbnSelchangeCmbInvest)	
END_MESSAGE_MAP()

// CExInvestChu �޽��� ó�����Դϴ�.

BOOL CExInvestChu::OnInitDialog() 
{
	CDialog::OnInitDialog();

	//������ ����
	m_cmbInvestCode.AddString("1:�ڽ���");
	m_cmbInvestCode.AddString("2:�ڽ���");
	m_cmbInvestCode.AddString("3:����");
	m_cmbInvestCode.AddString("4:�ݿɼ�");
	m_cmbInvestCode.AddString("5:ǲ�ɼ�");


	m_cmbQty.AddString("2:����(õ��)");
	m_cmbQty.AddString("1:�ݾ�(�鸸)");
	m_cmbQty.AddString("3:�ݾ�(���)");

	m_cmbQty.SetCurSel(0);
	m_cmbInvestCode.SetCurSel(0);
	OnCbnSelchangeCmbInvest();

	

	

	//���α׷��Ÿ�����

	m_cmbInvestCode2.AddString("1:�ڽ���");
	m_cmbInvestCode2.AddString("2:�ڽ���");
	
	m_cmbQty2.AddString("2:����(õ��)");
	m_cmbQty2.AddString("1:�ݾ�(�鸸)");
	m_cmbQty2.AddString("3:�ݾ�(���)");

	m_cmbQty2.SetCurSel(0);
	m_cmbInvestCode2.SetCurSel(0);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}



//=======================================================================================
// FUNCTION : ��ȸ (������ ����)
// RETURN   : 
//=======================================================================================
void CExInvestChu::OnBtnInquery()
{
	MakePacket() ;
}



//=======================================================================================
// FUNCTION : ��ȸ (���α׷��Ÿ�����)
// RETURN   : 
//=======================================================================================
void CExInvestChu::OnBtnInquery2()
{
	MakePacket_Program() ;
}

//=======================================================================================
// FUNCTION : ����api�� ������ ��û / ����������
// RETURN   : 
//=======================================================================================
void CExInvestChu::MakePacket_Program()
{
	UpdateData (TRUE) ;

	CString szInput ;
	CString szNext ;

	TR_02120_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_02120_I)) ;

	int nInvestType = 0;
	CString szInvestType ;	
	m_cmbInvestCode2.GetLBText(m_cmbInvestCode2.GetCurSel(), szInvestType);	
	if ( !szInvestType.IsEmpty())
	{
		szInvestType = szInvestType.Left(1);		
	}
	else
	{
		AfxMessageBox("������ ������ �����Ͻʽÿ�") ;
		return ;
	}

	
	int nQtyType = 0;
	CString szQtyType ;	
	m_cmbQty.GetLBText(m_cmbQty.GetCurSel(), szQtyType);	
	if ( !szQtyType.IsEmpty())
	{
		szQtyType = szQtyType.Left(1);			
	}
	else
	{
		AfxMessageBox("���� Ÿ���� �����Ͻʽÿ�") ;
		return ;
	}

	memcpy ( stInput.next, "0", 1 ) ; 
	memcpy ( stInput.mastebit, szInvestType, 1 ) ; 
	memcpy ( stInput.su_gum, szQtyType, 1 ) ;

	int nLen = sizeof(stInput) ;
	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);				

	theApp.SendToServerEx (DRCM_SENDDATA, TR_02120, szInput, m_hWnd);	

}
//=======================================================================================
// FUNCTION : ����api�� ������ ��û / ���α׷��Ÿ�����
// RETURN   : d
//=======================================================================================
void CExInvestChu::MakePacket()
{
	UpdateData (TRUE) ;

	
	CString szInput ;
	CString szNext ;

	TR_01932_I stInput ;
	memset (&stInput, 0x20, sizeof(TR_01932_I)) ;

	int nInvestType = 0;
	CString szInvestType ;	
	m_cmbInvestCode.GetLBText(m_cmbInvestCode.GetCurSel(), szInvestType);	
	if ( !szInvestType.IsEmpty())
	{
		szInvestType = szInvestType.Left(1);		
	}
	else
	{
		AfxMessageBox("������ ������ �����Ͻʽÿ�") ;
		return ;
	}

	int nUpjong = 0;
	CString szUpjong ;	
	//�ڽ��ǿ� �ڽ��ڸ� �����ڵ带 �Է���.
	if ( szInvestType == "1" || szInvestType == "2")
	{
		m_cmbUpjong.GetLBText(m_cmbUpjong.GetCurSel(), szUpjong);	
		if ( !szUpjong.IsEmpty())
		{
			szUpjong = szUpjong.Left(4);					
		}
		else
		{
			AfxMessageBox("������ �����Ͻʽÿ�") ;
			return ;
		}
	}

	int nQtyType = 0;
	CString szQtyType ;	
	m_cmbQty.GetLBText(m_cmbQty.GetCurSel(), szQtyType);	
	if ( !szQtyType.IsEmpty())
	{
		szQtyType = szQtyType.Left(1);			
	}
	else
	{
		AfxMessageBox("���� Ÿ���� �����Ͻʽÿ�") ;
		return ;
	}
	

	memcpy ( stInput.gubun1, szInvestType, 1 ) ; 
	memcpy ( stInput.gubun3, szQtyType, 1 ) ;

	if ( !szUpjong.IsEmpty())
		memcpy ( stInput.gubun2, szUpjong, 4 ) ; 
	
	int nLen = sizeof(stInput) ;
	szInput.Format("%-*.*s", nLen , nLen, (LPCTSTR)&stInput);				

	theApp.SendToServerEx (DRCM_SENDDATA, TR_01932, szInput, m_hWnd);	

}


//=======================================================================================
// FUNCTION : ����apI �κ��� ������ ����
// RETURN   : 
//=======================================================================================
BOOL CExInvestChu::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
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
			if ( strcmp(szTrCode, TR_01932) == 0 )
			{											
				TR_01932_O* pData = (TR_01932_O*)prData->TRData;
				TR_01932_OS* pGridData = (TR_01932_OS*)(&pData->tbl);
				
				CString szGubun = theApp.gatosz( pGridData->gubun, sizeof(pGridData->gubun) ) ;

				
				strMsg= "[01932]������ ���� ��ȸ>>" + strMsg + "[" + szGubun + "]" ;
				m_lstMsg.InsertString( 0, strMsg );
				
				CString szData;
				for ( int i =0; i < tr_01932Inv; i++)
				{	
				
					int medo = theApp.gatoi( pGridData->medo[i], sizeof(pGridData->medo[i]) ) ;
					int mesu = theApp.gatoi( pGridData->mesu[i], sizeof(pGridData->mesu[i]) ) ;
					int smesu = theApp.gatoi( pGridData->smesu[i], sizeof(pGridData->smesu[i]) ) ;


					szData.Format("�ŵ�:%d, �ż�:%d, ���ż�:%d", medo, mesu, smesu) ;
					m_lstMsg.InsertString( 0, szData );
				
					//*********************************
					//ȭ�鿡 �°� �����͸� ó��
					//*********************************
				}
								
				UpdateData(FALSE) ;

			}

			else if ( strcmp(szTrCode, TR_02120) == 0 )
			{							

				TR_02120_O* pData = (TR_02120_O*)prData->TRData;
				int count = theApp.gatoi( pData->gr_cnt, sizeof(pData->gr_cnt) ) ;

				for ( int i =0; i < count; i++)
				{	
					TR_02120_GD* pGridData = (TR_02120_GD*)(&pData->grid[i]);

					//*********************************
					//ȭ�鿡 �°� �����͸� ó��
					//*********************************
				}

				strMsg= "[02120]���α׷��Ÿ� ���� ��ȸ>>" + strMsg ;
				m_lstMsg.InsertString( 0, strMsg );
				UpdateData(FALSE) ;

			}

		}
	}

	return CDialog::OnCopyData(pWnd, pCopyDataStruct);	
}

void CExInvestChu::OnCbnSelchangeCmbInvest()
{
	UpdateData(TRUE);

	int nIdx = m_cmbInvestCode.GetCurSel();
	m_cmbUpjong.ResetContent() ;


	//�ڽ���, �ڽ��� �϶���.. �������� �޺��� �����Ѵ�
	switch ( nIdx )
	{
	case 0 : //�ڽ���
		for ( int i=1001; i <= 1027; i++)
		{
			CString szCode;
			szCode.Format("%d", i) ;
			m_cmbUpjong.AddString(szCode);
		}	

		m_cmbUpjong.SetCurSel(0);
		break;
	
	case 1 : //�ڽ�������
		for ( int i=2001; i <= 2004; i++)
		{
			CString szCode;
			szCode.Format("%d", i) ;
			m_cmbUpjong.AddString(szCode);
		}	
		m_cmbUpjong.SetCurSel(0);
		break;
	}

	UpdateData(FALSE);

}

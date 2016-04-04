#if !defined(AFX_TR_13616_HEADER_)
#define AFX_TR_13616_HEADER_

#include "../include/Data_Common.h"

#define  TR_13616	"13616"

#define TR_13616_MAX 400 

#define  FUTBID             700   /* ����/�ɼ�-�ż�-�ֹ�          */
#define  FUTOFF             710   /* ����/�ɼ�-�ŵ�-�ֹ�          */
#define  FUTJUN             720   /* ����/�ɼ�-����-�ֹ�          */
#define  FUTCAN             730   /* ����/�ɼ�-���-�ֹ�          */
#define  FUTBIDJUNCON       702   /* ����/�ɼ�-�ż�-����Ȯ��      */
#define  FUTOFFJUNCON       712   /* ����/�ɼ�-�ŵ�-����Ȯ��      */
#define  FUTBIDCANCON       703   /* ����/�ɼ�-�ż�-���Ȯ��      */
#define  FUTOFFCANCON       713   /* ����/�ɼ�-�ŵ�-���Ȯ��      */
#define  FUTBIDCHECON       701   /* ����/�ɼ�-�ż�-ü��Ȯ��      */
#define  FUTOFFCHECON       711   /* ����/�ɼ�-�ŵ�-ü��Ȯ��      */
#define  FUTBIDRJTCON       709   /* ����/�ɼ�-�ż��ź�Ȯ��       */
#define  FUTOFFRJTCON       719   /* ����/�ɼ�-�ŵ��ź�Ȯ��       */
#define  FUTJJJRJTCON       729   /* ����/�ɼ�-�����ź�Ȯ��       */ d
#define  FUTCANRJTCON       739   /* ����/�ɼ�-��Ұź�Ȯ��       */
#define  FUTSY1RJTCON       749   /* ����/�ɼ�-���Ӱź�Ȯ��       */
#define  FUTSY2RJTCON       759   /* ����/�ɼ�-�ŸŰź�Ȯ��       */

//-------------------------------------------------------------------------------##
// �����ǽð�ü��         ���TR��ȣ:13616                                     ##
//--------------------------------[INPUT ]---------------------------------------##
// [NOTE] ���� ������ ���� : �⺻�� "����"

typedef struct _tr13616_i
{
	char  geja     [20];    /* ������ȣ(3)+���¹�ȣ(8) + space  */
	char  checkgb  [ 1];    /* ��ȸ���� 0:��ü, 1:����          */
	char  jgcode   [ 8];    /* �����ڵ�                         */

	char  nxtGb    [ 1];    /* 0:ó��, 1:����                   */
	char  nxtKey   [ 9];    /* ������ȸ KEY: �ֹ���ȣ           */
	char  jugb     [ 1];    /* 0��ü 1�ż� 2�ŵ�                */

	char  userfld  [100];   /* ���� �״�� �����ش�             */
} TR_13616_I;

#define  TR_13616_I_SIZE sizeof(TR_13616_I)

//--------------------------------[OUTPUT�ݺ� ]-----------------------------------##

typedef struct _tr_13616_g
{
	char  juno      [ 9];   /* �ֹ���ȣ       */
	char  jgcode    [15];   /* �����ڵ�       */
	char  jgname    [40];   /* ����       */
	char  jugb      [12];   /* �ֹ�����       */
	char  juprc     [12];   /* �ֹ��ܰ�       */
	char  juqty     [15];   /* �ֹ�����       */
	char  cheprc    [12];   /* ü�ᰡ��       */
	char  cheqty    [15];   /* ü�����       */
	char  nonqty    [15];   /* ��ü��         */
	char  wonjuno   [ 9];   /* ���ֹ���ȣ     */
	char  jutype    [12];   /* ����           */
	char  denymsg   [40];   /* ���ΰźλ���   */
} TR_13616_G;

#define  TR_13616_G_SIZE sizeof(TR_13616_G)


typedef struct _tr_13616_o
{
	char  userfld  [100];
	char  nxtBtnSz   [ 2];  /* ���Ӱ�����   */
	char  nxtKey     [50];  /* ����Ű��     */

	char  gridcnt   [ 6];
	char  gridmsg   [ 4];
	TR_13616_G  grid[TR_13616_MAX];
} TR_13616_O;


class CTR_13616_G
{
public: //Variable
//    DEFINE_DRDS_LINE0(
	CString  m_szjuno;     	 /* �ֹ���ȣ  */
	CString  m_szjgcode;     /* �����ڵ�  */
	CString  m_szjgname ;
	CString  m_szjugb;   	/* �ֹ�����	*/
	CString  m_szjuprc;     /* �ֹ��ܰ� 	*/
	CString  m_szjuqty;    	/* �ֹ����� 	*/
	CString  m_szcheprc;    /* ü��ܰ� 	*/
	CString  m_szcheqty;    /* ü����� 	*/
	CString  m_sznonqty;    /* ��ü�� 		*/
	CString  m_szwonjuno;  	/* ���ֹ���ȣ   */
	CString  m_szjutype;    /* �Ÿű��� 	*/
	CString  m_szdenymsg;	 /* ���ΰźλ���   */

public:
	CTR_13616_G()
	{
	}

	virtual void  Convert(TR_13616_G* pInput)
	{		
		CString sTemp1;
		char sTmp[40+1];

		DATA_MEMCOPY(sTmp, pInput, juno		);   	/* �ֹ���ȣ   */
		DATA_MEMCOPY(sTmp, pInput, jgcode	);   	/* �����ڵ�   */
		DATA_MEMCOPY(sTmp, pInput, jgname	);   	/* ����   */
		DATA_MEMCOPY(sTmp, pInput, jugb		);   	/* �ֹ�����	  */
  		DATA_MEMCOPY(sTmp, pInput, juprc	);   	/* �ֹ��ܰ�   */
		DATA_MEMCOPY(sTmp, pInput, juqty	);   	/* �ֹ�����   */
		DATA_MEMCOPY(sTmp, pInput, cheprc	);   	/* ü��ܰ�   */
		DATA_MEMCOPY(sTmp, pInput, cheqty	);   	/* ü�����   */
		DATA_MEMCOPY(sTmp, pInput, nonqty	);   	/* ��ü�� 	  */
		DATA_MEMCOPY(sTmp, pInput, wonjuno  ); 	    /* ���ֹ���ȣ	*/
		DATA_MEMCOPY(sTmp, pInput, jutype	);   	/* �ֹ����� 	*/
		DATA_MEMCOPY(sTmp, pInput, denymsg	);   	/* ���ΰźλ���  	*/		
	}
};

typedef CList<CTR_13616_G*, CTR_13616_G*> LIST_TR_13616_G;


class CTR_13616_O
{
public:
    CString m_szgridcnt;                  /* Grid count           */
  
  	int m_ngridcnt;                  /* Grid count           */


	CString m_sznxtKey ;

	CString m_szNextFlag ;
	CString m_szNextVal ;

	LIST_TR_13616_G m_DataList;

public:
	CTR_13616_O()
	{
		ResetAll();
	}

	~CTR_13616_O()
	{
		ResetAll();
	}

	virtual void  Convert(TR_13616_O* pInput)
	{		
		char sTmp[100+1]={0,};

		//20130814 EUNSOOK >>
		char sTmpNxt[50+1]={0,};
		DATA_MEMCOPY(sTmpNxt, pInput, nxtKey);   	/* Next key   */
		m_szNextFlag = m_sznxtKey.Mid(m_sznxtKey.Find("EN=") + 3, 1) ;				
		m_szNextVal = m_sznxtKey.Mid(m_sznxtKey.Find("DT=") + 3, 9) ;
		//20130814 EUNSOOK <<

    	DATA_MEMCOPY(sTmp, pInput, gridcnt);         /* Grid count           */
		
		DATA_CONVERT_int_0(gridcnt);					/* Grid count           */
		    	
	}

	virtual void  ClearList()
	{
		for(POSITION pos=m_DataList.GetHeadPosition(); pos; )
		{
			CTR_13616_G* pItem = m_DataList.GetNext(pos);
			if(pItem) delete pItem;
		}
		m_DataList.RemoveAll();
	}

	void ResetAll()
	{
	
		m_ngridcnt= 0;

		m_szNextFlag ="";
		m_szNextVal ="";
		m_sznxtKey="" ;

		ClearList();
	}
	
	

};

class CTR_13616_I
{
public:
	CString geja;
	CString	jgcode;
	CString	strTemp;

public:
	CTR_13616_I(TR_13616_I* pIn, LPCTSTR lpstrgeja, LPCTSTR lpstrjgcode, char csgb, char csort)
	{
		// ����
		geja	= lpstrgeja;
		geja.Remove('-'); geja.Remove('_'); geja.Remove(' ');
		strTemp.Format("%-*.*s", sizeof(pIn->geja), sizeof(pIn->geja), geja);
		memcpy(pIn->geja, strTemp, sizeof(pIn->geja));
		// ����	
		jgcode	= lpstrjgcode;
		pIn->checkgb[0] = (jgcode == "")? '1' : '0'; //[ 1] �����ڵ� üũ���� : 0:��ü, 1:����
		if(jgcode == "") jgcode = " ";
		else			jgcode.Remove(' ');
		strTemp.Format("%-*.*s", sizeof(pIn->jgcode), sizeof(pIn->jgcode), jgcode);
		memcpy(pIn->jgcode, strTemp, sizeof(pIn->jgcode));
	}
	CTR_13616_I()
	{
		geja	= "";
		jgcode	= "";
	}
};

#endif //AFX_TR_13616_HEADER_

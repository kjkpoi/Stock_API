#if !defined(AFX_TR_13620_HEADER_)
#define AFX_TR_13620_HEADER_

#include "../include/Data_Common.h"

#define  TR_13620	"13620"

//-------------------------------------------------------------------------------##
// �����ǽð���ü��         ���TR��ȣ:13620                                     ##
//--------------------------------[INPUT ]---------------------------------------##
// [NOTE] ���� ������ ���� : �⺻�� "����"

typedef struct _tr13620_i
{
	char  geja     [20];    /* ������ȣ(3)+���¹�ȣ(8)      */
	char  checkgb  [ 1];    /* ��ȸ���� 0:��ü, 1:����      */
	char  jgcode   [ 8];    /* �����ڵ�                     */

    char  nxtGb    [ 1];    /* 0:ó��, 1:����                   */
    char  nxtKey   [ 9];    /* ������ȸ KEY: �ֹ���ȣ           */
	char  type     [ 1];	/* 3��ü 1�ְ��������� 2�����ֽļ��� 4��ǰ���� */	// 20110414 dyh ������ �ʵ� �߰�
} TR_13620_I;

#define  TR_13620_I_SIZE sizeof(TR_13620_I)

//--------------------------------[OUTPUT�ݺ� ]-----------------------------------##

typedef struct _tr_13620_g
{
	char  juno      [9];   /* �ֹ���ȣ       */
	char  jgcode    [15];   /* �����ڵ�       */
	char  jugb      [12];				/* �ֹ�����       */
	char  juprc     [12];	/* �ֹ��ܰ�       */
	char  juqty     [15];	/* �ֹ�����       */
	char  nonqty    [15];	/* ��ü��         */
	char  wonjuno   [ 9];	/* ���ֹ���ȣ     */
	char  jutype    [ 6];				/* �Ÿű���       */
} TR_13620_G;

#define  TR_13620_G_SIZE sizeof(TR_13620_G)


typedef struct _tr_13620_o
{
    char  nxtBtnSz  [ 2];    /* ���Ӱ�����   */
    char  nxtKey    [50];    /* ����Ű��     */
    char        gr_cnt[4];                  /* Grid count           */
    char        gr_bjlen[2];                /* Grid Bojo Data Length*/
    char        gr_bjdata[5];               /* Grid Bojo Data       */
    char	    gr_DATA[1];		              // �����ŭ �˾Ƽ�..
} TR_13620_O;


class CTR_13620_G
{
public: //Variable
//    DEFINE_DRDS_LINE0(
	CString  m_szjuno;     	 /* �ֹ���ȣ  */
	CString  m_szjgcode;     /* �����ڵ�  */
	CString  m_szjugb;   	 /* �ֹ�����	*/
	CString  m_szjuprc;      /* �ֹ��ܰ� 	*/
	CString  m_szjuqty;    	 /* �ֹ����� 	*/
	CString  m_sznonqty;     /* ��ü�� 		*/
	CString  m_szwonjuno;  	 /* ���ֹ���ȣ*/
	CString  m_szjutype;     /* �Ÿű��� 	*/

public:
	CTR_13620_G()
	{
	}

	virtual void  Convert(TR_13620_G* pInput)
	{		
		CString sTemp1;
		char sTmp[20+1];

		DATA_MEMCOPY(sTmp, pInput, juno		);   	/* �ֹ���ȣ   */
		DATA_MEMCOPY(sTmp, pInput, jgcode	);   	/* �����ڵ�   */
		DATA_MEMCOPY(sTmp, pInput, jugb		);   	/* �ֹ�����	  */
  		DATA_MEMCOPY(sTmp, pInput, juprc	);   	/* �ֹ��ܰ�   */
		DATA_MEMCOPY(sTmp, pInput, juqty	);   	/* �ֹ�����   */
		DATA_MEMCOPY(sTmp, pInput, nonqty	);   	/* ��ü�� 	  */
		DATA_MEMCOPY(sTmp, pInput, wonjuno  ); 	    /* ���ֹ���ȣ	*/
		DATA_MEMCOPY(sTmp, pInput, jutype	);   	/* �ֹ����� 	*/
	}
};

typedef CList<CTR_13620_G*, CTR_13620_G*> LIST_TR_13620_G;


class CTR_13620_O
{
public:
    CString m_szgr_cnt;                  /* Grid count           */
    CString m_szgr_bjlen;                /* Grid Bojo Data Length*/
    CString m_szgr_bjdata;               /* Grid Bojo Data       */

  	int m_ngr_cnt;                  /* Grid count           */
    int m_ngr_bjlen;                /* Grid Bojo Data Length*/
    int m_ngr_bjdata;               /* Grid Bojo Data       */

	CString m_sznxtKey ;

	CString m_szNextFlag ;
	CString m_szNextVal ;

	LIST_TR_13620_G m_DataList;

public:
	CTR_13620_O()
	{
		ResetAll();
	}

	~CTR_13620_O()
	{
		ResetAll();
	}

	virtual void  Convert(TR_13620_O* pInput)
	{		
		char sTmp[5+1]={0,};

		//20130814 EUNSOOK >>
		char sTmpNxt[50+1]={0,};
		DATA_MEMCOPY(sTmpNxt, pInput, nxtKey);   	/* Next key   */
		m_szNextFlag = m_sznxtKey.Mid(m_sznxtKey.Find("EN=") + 3, 1) ;				
		m_szNextVal = m_sznxtKey.Mid(m_sznxtKey.Find("DT=") + 3, 9) ;
		//20130814 EUNSOOK <<

    	DATA_MEMCOPY(sTmp, pInput, gr_cnt);         /* Grid count           */
    	DATA_MEMCOPY(sTmp, pInput, gr_bjlen);       /* Grid Bojo Data Length*/
    	DATA_MEMCOPY(sTmp, pInput, gr_bjdata);      /* Grid Bojo Data       */

    	DATA_CONVERT_int_0(gr_cnt);					/* Grid count           */
    	DATA_CONVERT_int_0(gr_bjlen);               /* Grid Bojo Data Length*/
    	DATA_CONVERT_int_0(gr_bjdata);              /* Grid Bojo Data       */

		CTR_13620_G *pNewItem=NULL;
		TR_13620_G *pData=NULL;
		CString sTemp1, sTemp2;
		for(int i=0; i < m_ngr_cnt; i++)
		{
			pData = (TR_13620_G*)&pInput->gr_DATA[i*sizeof(TR_13620_G)];
			pNewItem = new CTR_13620_G;
			pNewItem->Convert(pData);
			m_DataList.AddTail(pNewItem);
		}
	}

	virtual void  ClearList()
	{
		for(POSITION pos=m_DataList.GetHeadPosition(); pos; )
		{
			CTR_13620_G* pItem = m_DataList.GetNext(pos);
			if(pItem) delete pItem;
		}
		m_DataList.RemoveAll();
	}

	void ResetAll()
	{
		m_ngr_cnt = 0;
		m_ngr_bjlen = 0;
		m_ngr_bjdata= 0;

		m_szNextFlag ="";
		m_szNextVal ="";

		ClearList();
	}
	
	

};

class CTR_13620_I
{
public:
	CString geja;
	CString	jgcode;
	CString	strTemp;

public:
	CTR_13620_I(TR_13620_I* pIn, LPCTSTR lpstrgeja, LPCTSTR lpstrjgcode, char csgb, char csort)
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
	CTR_13620_I()
	{
		geja	= "";
		jgcode	= "";
	}
};

#endif //AFX_TR_13620_HEADER_

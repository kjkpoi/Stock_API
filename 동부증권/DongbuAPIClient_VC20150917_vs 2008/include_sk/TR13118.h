#if !defined(AFX_TR_13118_HEADER_)
#define AFX_TR_13118_HEADER_

#define		tr_13118MAX					250
#define		TR_STOCKCHEGYUL				"13118"

#define DATA_MEMCOPY(xTmp, xStruct, xKey) memcpy(xTmp, xStruct->xKey, sizeof(xStruct->xKey)); \
			xTmp[sizeof(xStruct->xKey)]=0;  m_sz##xKey=xTmp; \
			m_sz##xKey.TrimLeft(); m_sz##xKey.TrimRight();

//-------------------------------------------------------------------------------##
// �ǽð�ü��         ���TR��ȣ:13118                                           ##
//--------------------------------[INPUT ]---------------------------------------##
typedef struct _tr13118_i
{
	char  geja		[20];   	/* ������ȣ(3)+���¹�ȣ(8) 	*/
	char  sgb		[ 1];		/* 1:�ֹ�/ü�� 2:��ü��		*/
	char  chk		[ 1];		/* �����ڵ� üũ����		*/
	char  jcode		[ 6];		/* �����ڵ�					*/ 
	char  sort	 	[ 1];  		/* ����(1) ����(2) 			*/

	char  ngbn		[ 1];		/* 0:ó��, 1:����          */
	char  next		[50];		/* ������ȸ KEY            */
} TR_13118_I;


#define  TR_13118_I_SIZE sizeof(TR_13118_I)

//--------------------------------[OUTPUT�ݺ� ]-----------------------------------##
typedef struct _tr_13118_g
{
    char  juno		[ 9];    	/* �ֹ���ȣ 	*/ //5->9
	char  jgcode	[12];   	/* �����ڵ�     */
	char  jgname	[20];  		/* �����	 	*/
	char  jugb_attr	[ 3]; 		/* �Ÿű��мӼ� */
	char  jugb		[16];   	/* �Ÿű���		*/ 
	char  juqty		[15];    	/* �ֹ����� 	*/ //9->15
	char  juprc		[12];    	/* �ֹ��ܰ� 	*/ //9->12
	char  cheqty	[15];   	/* ü����� 	*/ //9->15
	char  cheprc	[12];   	/* ü�����		*/ //9->12
	char  nonqty	[15];   	/* ��ü�� 		*/ //9->15
	char  mmgb		[10];    	/* �ֹ����� 	*/			
	char  wonjuno	[ 9];  		/* ���ֹ���ȣ	*/ //5->9
	char  status	[10];		/* ó������		*/
	char  cherate	[ 9];		/* ü���		*/
	char  time  	[ 6];		/* �ֹ��ð�		*/
	char  feentax	[ 9];		/* �����		*/
	char  fee 		[ 9];		/* ������		*/
	char  tax		[ 9];		/* ����			*/	
	char  singb		[ 3];		/* �ſ뱸��		*/	
} TR_13118_G;

#define  TR_13118_G_SIZE sizeof(TR_13118_G)

typedef struct _tr_13118_o
{
	char		geja[20];   	/* ������ȣ(3)+���¹�ȣ(8) 	*/

	char		ngbn[ 1];					/* ��������Ÿ ����  */
											/* 0:����, 1:����   */
	char		next[50];					/* ������ȸ KEY     */

    char        gr_cnt[4];                  /* Grid count           */
    char        gr_bjlen[2];                /* Grid Bojo Data Length*/
    char        gr_bjdata[4];               /* Grid Bojo Data       */
    // TR_13118_G  grid[tr_13118MAX];
	char		gr_DATA[1];		// �����ŭ �˾Ƽ�..
} TR_13118_O;


class CTR_13118_G
{
public: //Variable
//    DEFINE_DRDS_LINE0(
	CString  m_szjuno		;    	/* �ֹ���ȣ 	*/
	CString  m_szjgcode		;   	/* �����ڵ�     */
	CString  m_szjgname		;  		/* �����	 	*/
	CString  m_szjugb_attr	; 		/* �Ÿű��мӼ� */
	CString  m_szjugb		;   	/* �Ÿű���		*/
	CString  m_szjuqty		;    	/* �ֹ����� 	*/	
	CString  m_szjuprc		;    	/* �ֹ��ܰ� 	*/
	CString  m_szcheqty		;   	/* ü����� 	*/
	CString  m_szcheprc		;   	/* ü�����		*/
	CString  m_sznonqty		;   	/* ��ü�� 		*/
	CString  m_szmmgb		;    	/* �ֹ����� 	*/			
	CString  m_szwonjuno	;  		/* ���ֹ���ȣ	*/
	CString  m_szstatus		;		/* ó������		*/
	CString  m_szcherate	;		/* ü���		*/
	CString  m_sztime  		;		/* �ֹ��ð�		*/
	CString  m_szfeentax	;		/* �����		*/
	CString  m_szfee 		;		/* ������		*/
	CString  m_sztax		;		/* ����			*/

public:
	CTR_13118_G()
	{
	}

	virtual void  Convert(TR_13118_G* pInput)
	{
		CString sTemp1 ;
		char sTmp[20+1];

		DATA_MEMCOPY(sTmp, pInput, juno		);    	/* �ֹ���ȣ 	*/		
		DATA_MEMCOPY(sTmp, pInput, jgcode	);   	/* �����ڵ�     */
		DATA_MEMCOPY(sTmp, pInput, jgname	);  	/* �����	 	*/
		DATA_MEMCOPY(sTmp, pInput, jugb_attr); 		/* �Ÿű��мӼ� */
		DATA_MEMCOPY(sTmp, pInput, jugb		);   	/* �Ÿű���		*/
		DATA_MEMCOPY(sTmp, pInput, juqty	);    	/* �ֹ����� 	*/
		DATA_MEMCOPY(sTmp, pInput, juprc	);    	/* �ֹ��ܰ� 	*/
		DATA_MEMCOPY(sTmp, pInput, cheqty	);   	/* ü����� 	*/
		DATA_MEMCOPY(sTmp, pInput, cheprc	);   	/* ü�����		*/
		DATA_MEMCOPY(sTmp, pInput, nonqty	);   	/* ��ü�� 		*/
		DATA_MEMCOPY(sTmp, pInput, mmgb		);    	/* �ֹ����� 	*/
		DATA_MEMCOPY(sTmp, pInput, wonjuno	);  	/* ���ֹ���ȣ	*/
		DATA_MEMCOPY(sTmp, pInput, status	);		/* ó������		*/
		DATA_MEMCOPY(sTmp, pInput, cherate	);		/* ü���		*/
		DATA_MEMCOPY(sTmp, pInput, time  	);		/* �ֹ��ð�		*/
		DATA_MEMCOPY(sTmp, pInput, feentax	);		/* �����		*/
		DATA_MEMCOPY(sTmp, pInput, fee 		);		/* ������		*/
		DATA_MEMCOPY(sTmp, pInput, tax		);		/* ����			*/
	}
};

//typedef CList<CTR_13118_G*, CTR_13118_G*> LIST_TR_13118_G;


#endif //AFX_TR_13118_HEADER_

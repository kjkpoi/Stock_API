#ifndef _DEFINEDLL_TR13148_
#define	_DEFINEDLL_TR13148_
/**************************************************************/
/* 01. ���α׷���      : {tr_13148.h}                         */
/* 02. ��  ��  ��      : {������}                             */
/* 03. �� �� �� ��     : {2007/04/06}                         */
/* 04. ���α׷����    : {�ֽ� �ſ�ǽð��ܰ�, ��}       	   */
/**************************************************************/

#define		tr_13148MAX				500
#define		SH_KSIZE				6

#define		TR_STOCKJANGO			"13148"
#define		TR_STOCKEVAL			"20051"

typedef struct _tr13148_i
{
	char  geja[20];   	/* ������ȣ(3)+���¹�ȣ(8) */

	char  gbun[ 1];   	/* ��ȸ���� 0:�ܰ� 1:�� 2:ü���ܰ� */

	char  ngbn[ 1];     /* 0:ó��, 1:����          */
	char  next[50];     /* ������ȸ KEY            */
} TR_13148_I;


typedef struct _tr_13148_s
{
	char  amotmsmdtot[15]; 	/* ��   ���Աݾ�	*/ //12->15
	char  pyungpltot [15]; 	/* ��   �򰡼���	*/ //12->15
	char  amotdealtot[15];  /* ���� �ŵ��ݾ� 	*/ //12->15
	char  amotpyngtot[15];	/* ��   �򰡱ݾ�	*/ //12->15
	char  suikratetot[15]; 	/* ��   ������		*/ //12->15
	char  realpltot  [15];  /* ���� ��������	*/ //12->15

	char  ngbn       [ 1];  /* ��������Ÿ ����  */
	                        /* 0:����, 1:����   */
	char  next       [50];  /* ������ȸ KEY     */
} TR_13148_S;
typedef struct 
{
	char  amotmsmdtot[12]; 	/* ��   ���Աݾ�	*/
	char  pyungpltot [12]; 	/* ��   �򰡼���	*/
	char  amotdealtot[12];  /* ���� �ŵ��ݾ� 	*/
	char  amotpyngtot[12];	/* ��   �򰡱ݾ�	*/
	char  suikratetot[12]; 	/* ��   ������		*/
	char  realpltot  [12];  /* ���� ��������	*/

	char  ngbn       [ 1];  /* ��������Ÿ ����  */
	                        /* 0:����, 1:����   */
	char  next       [50];  /* ������ȸ KEY     */
} TR_13148_S_1;

typedef struct _tr_13148_g
{
	char  jocode     [SH_KSIZE];	/* �����ڵ�		*/
	char  joname     [20]; 			/* �����		*/
	char  qntybooknon[15]; 			/* �������		*/ //9->15
	char  pyungpl    [15]; 			/* �򰡼���		*/ //12->15
	char  suikrate   [ 7]; 			/* ������		*/
	char  amotbook   [15]; 			/* �ܰ�ݾ�		*/ //12->15
	char  amotbooknon[15];			/* �򰡱ݾ� 	*/ //12->15
	char  qntydealbef[15]; 			/* ���Ϻ���		*/ //9->15
	char  qntydeal   [15]; 			/* ���Ϻ���		*/ //9->15
	char  qntyrest   [15]; 			/* �����ܰ�		*/ //9->15
	char  prcebooknon[ 9]; 			/* ��δܰ�		*/ //7->9
	char  feentax    [ 9]; 			/* �����(������+������) */
	char  stocktax   [ 9]; 			/* �ִ���				 */
	char  fee		 [ 9];			/* ������  				 */
	char  tax		 [ 9];			/* ���� 				 */
	char  price      [ 7]; 			/* ���簡		*/
	char  change	 [ 7];			/* ���ϴ��		*/
	char  date		 [ 8];			/* ����������   */
	char  sign		 [ 1];			/* �����ȣ		*/
	char  realpl     [15];          /* ��������		*/ //12->15
	char  amotsell   [15]; 	        /* ���ϸŵ��ݾ�	*/ //12->15

	char  jango_gb   [ 1];          /* �ܰ���     */
									// 20080508 �ڵ��� >>
	                                /* ���� 0:����,1:����,2:�ڱ� */
									/* ���� 0:����,1:����,3:�ڱ�,5&7:����,8:�㺸 */
									// 20080508 �ڵ��� <<
	char  daechul    [ 8];          /* ������       */
	char  mangiil    [ 8];          /* ������       */
	char  sinamt     [15];          /* �ſ�ݾ�     */ //12->15
	char  interest   [ 9];          /* ��������     */
    char  bocash     [ 3];          /* �������ű��� */
} TR_13148_G;
typedef struct 
{
	char  jocode     [SH_KSIZE];	/* �����ڵ�		*/
	char  joname     [20]; 			/* �����		*/
	char  qntybooknon[ 9]; 			/* �������		*/ //
	char  pyungpl    [12]; 			/* �򰡼���		*/
	char  suikrate   [ 7]; 			/* ������		*/
	char  amotbook   [12]; 			/* �ܰ�ݾ�		*/
	char  amotbooknon[12];			/* �򰡱ݾ� 	*/
	char  qntydealbef[ 9]; 			/* ���Ϻ���		*/
	char  qntydeal   [ 9]; 			/* ���Ϻ���		*/
	char  qntyrest   [ 9]; 			/* �����ܰ�		*/
	char  prcebooknon[ 7]; 			/* ��δܰ�		*/
	char  feentax    [ 9]; 			/* �����(������+������) */
	char  stocktax   [ 9]; 			/* �ִ���				 */
	char  fee		 [ 9];			/* ������  				 */
	char  tax		 [ 9];			/* ���� 				 */
	char  price      [ 7]; 			/* ���簡		*/
	char  change	 [ 7];			/* ���ϴ��		*/
	char  date		 [ 8];			/* ����������   */
	char  sign		 [ 1];			/* �����ȣ		*/
	char  realpl     [12];          /* ��������		*/
	char  amotsell   [12]; 	        /* ���ϸŵ��ݾ�	*/

	char  jango_gb   [ 1];          /* �ܰ���     */
	                                /* 0:����,1:����*/
	                                /* 2:�ڱ�       */
	char  daechul    [ 8];          /* ������       */
	char  mangiil    [ 8];          /* ������       */
	char  sinamt     [12];          /* �ſ�ݾ�     */
	char  interest   [ 9];          /* ��������     */
    char  bocash     [ 3];          /* �������ű��� */
} TR_13148_G_1;


typedef struct _tr_13148_o
{
	char		sm_bjlen[6];				/* Grid Bojo Data Length*/
	char		sm_bjdata[5];				/* Grid Bojo Data		*/
	TR_13148_S  sm;

	char		gr_bjlen[6];				/* Grid Bojo Data Length*/
	char		gr_bjdata[5];				/* Grid Bojo Data		*/
	TR_13148_G  gr[tr_13148MAX];
} TR_13148_O;



/*-----------------------------------------------------------*/
/* Map���� �ö�� Input Data ����                            */
/*-----------------------------------------------------------*/
typedef struct
{
	char	geja	[20];       /* ���¹�ȣ             	*/
	char    passwd	[ 8];       /* ��й�ȣ             	*/
    char 	ipaddr  [16];   	/* client ipaddr(199.99.9.90->199099009090)   */
} TR_20051_I;                   

/*-----------------------------------------------------------*/
/* Map���� ���� Output Data ����                             */
/*-----------------------------------------------------------*/
typedef struct
{
    char    geja      [20];    /* ���¹�ȣ                      */
	char    dpsast    [15];    /* ��Ź�ڻ��Ѿ�                  */
	char	d2		  [15];      /* D+2������   S9(15)          */
	char    mgnrat    [15];    /* ���űݷ�100�ۼ�Ʈ�ֹ����ɱݾ� */ 
} TR_20051_O;

#endif
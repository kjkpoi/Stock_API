/******************************************************************/
/* 01. ���α׷���      : {tr_13147.h}                             */
/* 04. ���α׷����    : {����API-�ǽð��ܰ�}           	  	      */
/* 05. ��  ��  ��	   : {KHS}     							      */
/* 06. ��  ��  ��	   : {2013/04/18}                             */
/******************************************************************/

#define	tr_13147MAX 500

typedef struct _tr13147_i
{
	char  geja[20];   	/* ������ȣ(3)+���¹�ȣ(8) + sp(9) */
	char  gbun[ 1];   	/* ��ȸ���� 0:�ܰ� 1:�� 2:ü���ܰ� */

	char  ngbn[ 1];     /* 0:ó��, 1:����          */
	char  next[50];     /* ������ȸ KEY            */
} TR_13147_I;

typedef struct _tr_13147_s
{
	char  amotmsmdtot[15]; 	/* ��   ���Աݾ�	*/
	char  pyungpltot [15]; 	/* ��   �򰡼���	*/
	char  amotdealtot[15];  /* ���� �ŵ��ݾ� 	*/
	char  amotpyngtot[15];	/* ��   �򰡱ݾ�	*/
	char  suikratetot[15]; 	/* ��   ������		*/
	char  realpltot  [15];  /* ���� ��������	*/

	char  ngbn       [ 1];  /* ��������Ÿ ����  */
	                        /* 0:����, 1:����   */
	char  next       [50];  /* ������ȸ KEY     */
} TR_13147_S;

typedef struct _tr_13147_g
{
	char  jocode     [SH_KSIZE];	/* �����ڵ�		*/
	char  joname     [20]; 			/* �����		*/
	char  qntybooknon[15]; 			/* �������		*/
	char  pyungpl    [15]; 			/* �򰡼���		*/
	char  suikrate   [ 7]; 			/* ������		*/
	char  amotbook   [15]; 			/* �ܰ�ݾ�		*/
	char  amotbooknon[15];			/* �򰡱ݾ� 	*/
	char  qntydealbef[15]; 			/* ���Ϻ���		*/
	char  qntydeal   [15]; 			/* ���Ϻ���		*/
	char  qntyrest   [15]; 			/* �����ܰ�		*/
	char  prcebooknon[ 9]; 			/* ��δܰ�		*/
	char  feentax    [ 9]; 			/* �����(������+������) */
	char  stocktax   [ 9]; 			/* �ִ���				 */
	char  fee		 [ 9];			/* ������  				 */
	char  tax		 [ 9];			/* ���� 				 */
	char  price      [ 7]; 			/* ���簡		*/
	char  change	 [ 7];			/* ���ϴ��		*/
	char  date		 [ 8];			/* ����������   */
	char  sign		 [ 1];			/* �����ȣ		*/
	char  realpl     [15];          /* ��������		*/
	char  amotsell   [15]; 	        /* ���ϸŵ��ݾ�	*/

	char  jango_gb   [ 1];          /* �ܰ���     */
	                                /* 0:����, 
	                                1 �ſ���������
                                    3 �ſ��ڱ�����
                                    5 �ſ��������
                                    7 �ſ��ڱ����
                                    8 ��Ź�ֽĴ㺸�ſ���� */
	char  daechul    [ 8];          /* ������       */
	char  mangiil    [ 8];          /* ������       */
	char  sinamt     [15];          /* �ſ�ݾ�     */
	char  interest   [ 9];          /* ��������     */
    char  bocash     [ 3];          /* �������ű��� */

	/* 2013.04.18 �߰� */
	char  qntyposs   [15]; 			/* �ŵ�����		*/
	char  jo_gb      [ 1]; 			/* ���񱸺�: 0=�ڽ���, 1=�ڽ���, 2=ELW, 3=ETF */
	char  chrate     [ 7]; 			/* �����		*/
	char  hprice     [ 7]; 			/* ���Ѱ�		*/
	char  bid	     [ 7]; 			/* �ż�ȣ��		*/
	char  bidremain  [10]; 			/* �ż��ܷ�     */
} TR_13147_G;

typedef struct _tr_13147_o
{
	char		sm_bjlen[6];				/* Grid Bojo Data Length*/
	char		sm_bjdata[5];				/* Grid Bojo Data		*/
	TR_13147_S  sm;

	char		gr_bjlen[6];				/* Grid Bojo Data Length*/
	char		gr_bjdata[5];				/* Grid Bojo Data		*/
	TR_13147_G  gr[tr_13147MAX];
} TR_13147_O;

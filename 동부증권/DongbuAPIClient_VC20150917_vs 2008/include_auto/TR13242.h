#ifndef _DEFINEDLL_TR13242_
#define	_DEFINEDLL_TR13242_
/**************************************************************/
/* 01. ���α׷���      : {tr_13242.h}                         */
/* 02. ��  ��  ��      : {������}                             */
/* 03. �� �� �� ��     : {2007/04/06}                         */
/* 04. ���α׷����    : {�ǽð��ܰ�}           	  	      */
/* 05. ��  ��  ��	   : {KHS}							      */
/* 06. ��  ��  ��	   : 2010.11.08							  */
/**************************************************************/

#define TR_13242	"13242"
#define	tr_13242MAX 500
#define CODE_SIZE	9

typedef struct _tr13242_i
{
	char  geja     [20];          /* ������ȣ(3)+���¹�ȣ(8) + sp(9)   */
	char  gbun     [ 1];          /* ��ȸ���� 0:�ܰ� 1:�� 2:ü���ܰ� */
	char  checkgb  [ 1];          /* ��ȸ���� 0:��ü, 1:����           */
	char  jgcode   [CODE_SIZE];   /* �����ڵ�                          */
	char  creditmon[ 1];		  /* 0:�������� ����, 1:����		   */

	char  ngbn     [ 1];          /* 0:ó��, 1:����          */
	char  next     [50];          /* ������ȸ KEY            */
} TR_13242_I;

typedef struct _tr_13242_s
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
} TR_13242_S;

typedef struct _tr_13242_g
{
	char  jocode     [ 6];			/* �����ڵ�		*/
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
	char  amotbuy	 [15];			/* ���ϸż��ݾ� */ 
	char  jango_gb   [ 1];          /* �ܰ���     */
	                                /* 0:����, 
	                                1 �ſ���������
                                    3 �ſ��ڱ�����
                                    5 �ſ��������
                                    7 �ſ��ڱ����
                                    8 ��Ź�ֽĴ㺸�ſ����      */
	char  daechul    [ 8];          /* ������       */
	char  mangiil    [ 8];          /* ������       */
	char  sinamt     [15];          /* �ſ�ݾ�     */
	char  interest   [ 9];          /* ��������     */
    char  bocash     [ 3];          /* �������ű��� */
	char  qntyposs   [15]; 			/* �ŵ�����		*/
	// 20120723 ssj - �����ڵ��ֹ� >> �ּ�����
	char  codegb	 [ 1];			/* ETF=4 ELW=3 KOSDAQ=2 KOSPI=1 */
	// 20120723 ssj - �����ڵ��ֹ� <<
	// 20110627 �ֿ��� >>
	char  chrate	  [ 7];			/* ����� */
	// 20110627 �ֿ��� <<
	// 20110908 �ֿ��� >>
	char  high		  [ 7];			/*���Ѱ� */
	char  masuhoga	  [ 7];			/*�ż�ȣ�� */
	char  masuqty	  [10];			/*�ż��ܷ�  */
	// 20110908 �ֿ��� <<

} TR_13242_G;

typedef struct _tr_13242_o
{
	char		sm_bjlen[6];				/* Grid Bojo Data Length*/
	char		sm_bjdata[5];				/* Grid Bojo Data		*/
	TR_13242_S  sm;

	char		gr_bjlen[6];				/* Grid Bojo Data Length*/
	char		gr_bjdata[5];				/* Grid Bojo Data		*/
	TR_13242_G  gr[tr_13242MAX];
} TR_13242_O;

#endif
#ifndef _DEFINEDLL_TR09292_
#define _DEFINEDLL_TR09291_

#define TR_09292	"09292"
/*************************************************************/
/* 01. ���α׷���      : {D09292.h}                          */
/* 04. ���α׷����    : {�̴�ȣ��-10ȣ��}                */
/* 07. REMARKS ����    : {}                                  */
/*************************************************************/
#define	GRD_MAX	100

typedef struct{
	char	shcode[9];        	/* �����ڵ� */
} TR_09292_I;

typedef struct{
	char	price		[ 7];	/* ���簡	  */
	char	preprice[ 9]; /* �������� */ /*20100302 �ڻ�� */
	char	volume		[ 8];	/* �ŷ��� 	  */	
	char	sign		[ 1];	/* �����ȣ	  */	
} TR_09292_CUR; 

typedef struct{
	char	name		[10];	/* �����ڻ�         */
	char 	price		[ 9];	/* �����ڻ갡��	    */
	char	sign		[ 1];	/* �����ȣ	        */
	char	change		[ 9];	/* ���ϴ��(�����) */
	char	rate		[ 7];	/* ����� 	*/
} TR_09292_CUR1; 

typedef struct{
	char	openam		[ 7];	/* �ð�			*/
	char	high		[ 7];	/* ��			*/
	char	low			[ 7];	/* ����			*/
	char	recprice	[10];	/* ���ذ�		*/
	char	listing		[12];	/* �����ֽļ�	*/
	char	value		[15];	/* �ŷ����		*/
	char    prevol      [ 8];   /* ���ϰŷ���   */
	char	expprice	[ 9];	/* ����ü�ᰡ	*/
	char	expvol		[12];	/* ����ü�����	*/
} TR_09292_CUR2; 

typedef struct{
	char	name		[10];	/* �����ڻ�         */
	char 	price		[ 9];	/* �����ڻ갡��	    */
	char	sign		[ 1];	/* �����ȣ	        */
	char	change		[ 9];	/* ���ϴ��(�����) */
	char	rate		[ 7];	/* ����� 	*/
} TR_09292_CUR3; 

typedef struct {
	char sign		[1];	/* �����ȣ				*/
	char change		[9];	/* ���ϴ��(�����) 	*/
	char rate		[7];	/* ����� 				*/	
	
	char ofremain	[8];  	/* 1�ܰ� �ŵ�ȣ�� �ܷ� 	*/
	char offerho	[7];  	/* 1�ܰ� �ŵ�ȣ�� 		*/
	char bidho		[7];  	/* 1�ܰ� �ż�ȣ�� 		*/
	char bidremain	[8];  	/* 1�ܰ� �ż�ȣ�� �ܷ� 	*/
	
	char ofremain1	[8];  	/* 2�ܰ� �ŵ�ȣ�� �ܷ� 	*/
	char offerho1	[7];  	/* 2�ܰ� �ŵ�ȣ�� 		*/
	char bidho1		[7];  	/* 2�ܰ� �ż�ȣ�� 		*/
	char bidremain1	[8];  	/* 2�ܰ� �ż�ȣ�� �ܷ� 	*/
	
	char ofremain2	[8];  	/* 3�ܰ� �ŵ�ȣ�� �ܷ� 	*/
	char offerho2	[7];  	/* 3�ܰ� �ŵ�ȣ�� 		*/	
	char bidho2		[7];  	/* 3�ܰ� �ż�ȣ�� 		*/
	char bidremain2	[8];  	/* 3�ܰ� �ż�ȣ�� �ܷ� 	*/

	char ofremain3	[8];  	/* 4�ܰ� �ŵ�ȣ�� �ܷ� 	*/
	char offerho3	[7];  	/* 4�ܰ� �ŵ�ȣ�� 		*/
	char bidho3		[7];  	/* 4�ܰ� �ż�ȣ�� 		*/
	char bidremain3	[8];  	/* 4�ܰ� �ż�ȣ�� �ܷ� 	*/
				
	char ofremain4	[8];  	/* 5�ܰ� �ŵ�ȣ�� �ܷ� 	*/
	char offerho4	[7];  	/* 5�ܰ� �ŵ�ȣ��		*/	
	char bidho4		[7];  	/* 5�ܰ� �ż�ȣ�� 		*/
	char bidremain4	[8];  	/* 5�ܰ� �ż�ȣ�� �ܷ� 	*/

	char ofremain5	[8];  	/* 6�ܰ� �ŵ�ȣ�� �ܷ� 	*/
	char offerho5	[7];  	/* 6�ܰ� �ŵ�ȣ�� 		*/
	char bidho5		[7];  	/* 6�ܰ� �ż�ȣ�� 		*/
	char bidremain5	[8];  	/* 6�ܰ� �ż�ȣ�� �ܷ� 	*/
	
	char ofremain6	[8];  	/* 7�ܰ� �ŵ�ȣ�� �ܷ� 	*/
	char offerho6	[7];  	/* 7�ܰ� �ŵ�ȣ�� 		*/
	char bidho6		[7];  	/* 7�ܰ� �ż�ȣ�� 		*/
	char bidremain6	[8];  	/* 7�ܰ� �ż�ȣ�� �ܷ� 	*/
	
	char ofremain7	[8];  	/* 8�ܰ� �ŵ�ȣ�� �ܷ� 	*/
	char offerho7	[7];  	/* 8�ܰ� �ŵ�ȣ�� 		*/	
	char bidho7		[7];  	/* 8�ܰ� �ż�ȣ�� 		*/
	char bidremain7	[8];  	/* 8�ܰ� �ż�ȣ�� �ܷ� 	*/

	char ofremain8	[8];  	/* 9�ܰ� �ŵ�ȣ�� �ܷ� 	*/
	char offerho8	[7];  	/* 9�ܰ� �ŵ�ȣ�� 		*/
	char bidho8		[7];  	/* 9�ܰ� �ż�ȣ�� 		*/
	char bidremain8	[8];  	/* 9�ܰ� �ż�ȣ�� �ܷ� 	*/
				
	char ofremain9	[8];  	/* 10�ܰ� �ŵ�ȣ�� �ܷ� 	*/
	char offerho9	[7];  	/* 10�ܰ� �ŵ�ȣ��		*/	
	char bidho9		[7];  	/* 10�ܰ� �ż�ȣ�� 		*/
	char bidremain9	[8];  	/* 10�ܰ� �ż�ȣ�� �ܷ� 	*/
		
	char offertot	[8];  	/* �ŵ� ���ܷ� 			*/
	char soontot	[8];	/* ���ż����ܷ�  		*/
	char bidtot		[8];  	/* �ż� ���ܷ� 			*/
} TR_09292_HOGA;

typedef struct{
	char	shcode  [9];    /* �����ڵ� */
	
	char	curlen	[6];
	char	curmsg	[5];
	TR_09292_CUR	cur;
		
	char	curlen1	[6];
	char	curmsg1	[5];
	TR_09292_CUR1	cur1;
	
	char	curlen3	[6];
	char	curmsg3	[5];
	TR_09292_CUR3	cur3;	
	
	char	curlen2	[6];
	char	curmsg2	[5];
	TR_09292_CUR2	cur2;			

	char	hogalen	[6];
	char	hogamsg	[5];
	TR_09292_HOGA	ho;

} TR_09292_O;

#endif // _DEFINEDLL_TR09292_
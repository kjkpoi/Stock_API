#ifndef _DEFINEDLL_TR09292_
#define _DEFINEDLL_TR09291_

#define TR_09292	"09292"
/*************************************************************/
/* 01. 프로그램명      : {D09292.h}                          */
/* 04. 프로그램기능    : {미니호가-10호가}                */
/* 07. REMARKS 사항    : {}                                  */
/*************************************************************/
#define	GRD_MAX	100

typedef struct{
	char	shcode[9];        	/* 종목코드 */
} TR_09292_I;

typedef struct{
	char	price		[ 7];	/* 현재가	  */
	char	preprice[ 9]; /* 전일종가 */ /*20100302 박상운 */
	char	volume		[ 8];	/* 거래량 	  */	
	char	sign		[ 1];	/* 등락부호	  */	
} TR_09292_CUR; 

typedef struct{
	char	name		[10];	/* 기초자산         */
	char 	price		[ 9];	/* 기초자산가격	    */
	char	sign		[ 1];	/* 등락부호	        */
	char	change		[ 9];	/* 전일대비(등락폭) */
	char	rate		[ 7];	/* 등락율 	*/
} TR_09292_CUR1; 

typedef struct{
	char	openam		[ 7];	/* 시가			*/
	char	high		[ 7];	/* 고가			*/
	char	low			[ 7];	/* 저가			*/
	char	recprice	[10];	/* 기준가		*/
	char	listing		[12];	/* 발행주식수	*/
	char	value		[15];	/* 거래대금		*/
	char    prevol      [ 8];   /* 전일거래량   */
	char	expprice	[ 9];	/* 예상체결가	*/
	char	expvol		[12];	/* 예상체결수량	*/
} TR_09292_CUR2; 

typedef struct{
	char	name		[10];	/* 기초자산         */
	char 	price		[ 9];	/* 기초자산가격	    */
	char	sign		[ 1];	/* 등락부호	        */
	char	change		[ 9];	/* 전일대비(등락폭) */
	char	rate		[ 7];	/* 등락율 	*/
} TR_09292_CUR3; 

typedef struct {
	char sign		[1];	/* 등락부호				*/
	char change		[9];	/* 전일대비(등락폭) 	*/
	char rate		[7];	/* 등락율 				*/	
	
	char ofremain	[8];  	/* 1단계 매도호가 잔량 	*/
	char offerho	[7];  	/* 1단계 매도호가 		*/
	char bidho		[7];  	/* 1단계 매수호가 		*/
	char bidremain	[8];  	/* 1단계 매수호가 잔량 	*/
	
	char ofremain1	[8];  	/* 2단계 매도호가 잔량 	*/
	char offerho1	[7];  	/* 2단계 매도호가 		*/
	char bidho1		[7];  	/* 2단계 매수호가 		*/
	char bidremain1	[8];  	/* 2단계 매수호가 잔량 	*/
	
	char ofremain2	[8];  	/* 3단계 매도호가 잔량 	*/
	char offerho2	[7];  	/* 3단계 매도호가 		*/	
	char bidho2		[7];  	/* 3단계 매수호가 		*/
	char bidremain2	[8];  	/* 3단계 매수호가 잔량 	*/

	char ofremain3	[8];  	/* 4단계 매도호가 잔량 	*/
	char offerho3	[7];  	/* 4단계 매도호가 		*/
	char bidho3		[7];  	/* 4단계 매수호가 		*/
	char bidremain3	[8];  	/* 4단계 매수호가 잔량 	*/
				
	char ofremain4	[8];  	/* 5단계 매도호가 잔량 	*/
	char offerho4	[7];  	/* 5단계 매도호가		*/	
	char bidho4		[7];  	/* 5단계 매수호가 		*/
	char bidremain4	[8];  	/* 5단계 매수호가 잔량 	*/

	char ofremain5	[8];  	/* 6단계 매도호가 잔량 	*/
	char offerho5	[7];  	/* 6단계 매도호가 		*/
	char bidho5		[7];  	/* 6단계 매수호가 		*/
	char bidremain5	[8];  	/* 6단계 매수호가 잔량 	*/
	
	char ofremain6	[8];  	/* 7단계 매도호가 잔량 	*/
	char offerho6	[7];  	/* 7단계 매도호가 		*/
	char bidho6		[7];  	/* 7단계 매수호가 		*/
	char bidremain6	[8];  	/* 7단계 매수호가 잔량 	*/
	
	char ofremain7	[8];  	/* 8단계 매도호가 잔량 	*/
	char offerho7	[7];  	/* 8단계 매도호가 		*/	
	char bidho7		[7];  	/* 8단계 매수호가 		*/
	char bidremain7	[8];  	/* 8단계 매수호가 잔량 	*/

	char ofremain8	[8];  	/* 9단계 매도호가 잔량 	*/
	char offerho8	[7];  	/* 9단계 매도호가 		*/
	char bidho8		[7];  	/* 9단계 매수호가 		*/
	char bidremain8	[8];  	/* 9단계 매수호가 잔량 	*/
				
	char ofremain9	[8];  	/* 10단계 매도호가 잔량 	*/
	char offerho9	[7];  	/* 10단계 매도호가		*/	
	char bidho9		[7];  	/* 10단계 매수호가 		*/
	char bidremain9	[8];  	/* 10단계 매수호가 잔량 	*/
		
	char offertot	[8];  	/* 매도 총잔량 			*/
	char soontot	[8];	/* 순매수총잔량  		*/
	char bidtot		[8];  	/* 매수 총잔량 			*/
} TR_09292_HOGA;

typedef struct{
	char	shcode  [9];    /* 종목코드 */
	
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
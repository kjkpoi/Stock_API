#ifndef _DEFINEDLL_TR13148_
#define	_DEFINEDLL_TR13148_
/**************************************************************/
/* 01. 프로그램명      : {tr_13148.h}                         */
/* 02. 작  성  자      : {이장헌}                             */
/* 03. 작 성 일 자     : {2007/04/06}                         */
/* 04. 프로그램기능    : {주식 신용실시간잔고, 평가}       	   */
/**************************************************************/

#define		tr_13148MAX				500
#define		SH_KSIZE				6

#define		TR_STOCKJANGO			"13148"
#define		TR_STOCKEVAL			"20051"

typedef struct _tr13148_i
{
	char  geja[20];   	/* 지점번호(3)+계좌번호(8) */

	char  gbun[ 1];   	/* 조회구분 0:잔고 1:평가 2:체결잔고 */

	char  ngbn[ 1];     /* 0:처음, 1:다음          */
	char  next[50];     /* 다음조회 KEY            */
} TR_13148_I;


typedef struct _tr_13148_s
{
	char  amotmsmdtot[15]; 	/* 총   매입금액	*/ //12->15
	char  pyungpltot [15]; 	/* 총   평가손익	*/ //12->15
	char  amotdealtot[15];  /* 당일 매도금액 	*/ //12->15
	char  amotpyngtot[15];	/* 총   평가금액	*/ //12->15
	char  suikratetot[15]; 	/* 총   수익율		*/ //12->15
	char  realpltot  [15];  /* 당일 실현손익	*/ //12->15

	char  ngbn       [ 1];  /* 다음데이타 구분  */
	                        /* 0:없음, 1:있음   */
	char  next       [50];  /* 다음조회 KEY     */
} TR_13148_S;
typedef struct 
{
	char  amotmsmdtot[12]; 	/* 총   매입금액	*/
	char  pyungpltot [12]; 	/* 총   평가손익	*/
	char  amotdealtot[12];  /* 당일 매도금액 	*/
	char  amotpyngtot[12];	/* 총   평가금액	*/
	char  suikratetot[12]; 	/* 총   수익율		*/
	char  realpltot  [12];  /* 당일 실현손익	*/

	char  ngbn       [ 1];  /* 다음데이타 구분  */
	                        /* 0:없음, 1:있음   */
	char  next       [50];  /* 다음조회 KEY     */
} TR_13148_S_1;

typedef struct _tr_13148_g
{
	char  jocode     [SH_KSIZE];	/* 종목코드		*/
	char  joname     [20]; 			/* 종목명		*/
	char  qntybooknon[15]; 			/* 가용수량		*/ //9->15
	char  pyungpl    [15]; 			/* 평가손익		*/ //12->15
	char  suikrate   [ 7]; 			/* 수익율		*/
	char  amotbook   [15]; 			/* 잔고금액		*/ //12->15
	char  amotbooknon[15];			/* 평가금액 	*/ //12->15
	char  qntydealbef[15]; 			/* 전일변동		*/ //9->15
	char  qntydeal   [15]; 			/* 금일변동		*/ //9->15
	char  qntyrest   [15]; 			/* 결제잔고		*/ //9->15
	char  prcebooknon[ 9]; 			/* 장부단가		*/ //7->9
	char  feentax    [ 9]; 			/* 제비용(수수료+제세금) */
	char  stocktax   [ 9]; 			/* 주당비용				 */
	char  fee		 [ 9];			/* 수수료  				 */
	char  tax		 [ 9];			/* 세금 				 */
	char  price      [ 7]; 			/* 현재가		*/
	char  change	 [ 7];			/* 전일대비		*/
	char  date		 [ 8];			/* 최종매입일   */
	char  sign		 [ 1];			/* 등락부호		*/
	char  realpl     [15];          /* 실현손익		*/ //12->15
	char  amotsell   [15]; 	        /* 금일매도금액	*/ //12->15

	char  jango_gb   [ 1];          /* 잔고구분     */
									// 20080508 박동관 >>
	                                /* 기존 0:현금,1:융자,2:자기 */
									/* 수정 0:현금,1:유통,3:자기,5&7:대주,8:담보 */
									// 20080508 박동관 <<
	char  daechul    [ 8];          /* 대출일       */
	char  mangiil    [ 8];          /* 만기일       */
	char  sinamt     [15];          /* 신용금액     */ //12->15
	char  interest   [ 9];          /* 대출이자     */
    char  bocash     [ 3];          /* 현금증거금율 */
} TR_13148_G;
typedef struct 
{
	char  jocode     [SH_KSIZE];	/* 종목코드		*/
	char  joname     [20]; 			/* 종목명		*/
	char  qntybooknon[ 9]; 			/* 가용수량		*/ //
	char  pyungpl    [12]; 			/* 평가손익		*/
	char  suikrate   [ 7]; 			/* 수익율		*/
	char  amotbook   [12]; 			/* 잔고금액		*/
	char  amotbooknon[12];			/* 평가금액 	*/
	char  qntydealbef[ 9]; 			/* 전일변동		*/
	char  qntydeal   [ 9]; 			/* 금일변동		*/
	char  qntyrest   [ 9]; 			/* 결제잔고		*/
	char  prcebooknon[ 7]; 			/* 장부단가		*/
	char  feentax    [ 9]; 			/* 제비용(수수료+제세금) */
	char  stocktax   [ 9]; 			/* 주당비용				 */
	char  fee		 [ 9];			/* 수수료  				 */
	char  tax		 [ 9];			/* 세금 				 */
	char  price      [ 7]; 			/* 현재가		*/
	char  change	 [ 7];			/* 전일대비		*/
	char  date		 [ 8];			/* 최종매입일   */
	char  sign		 [ 1];			/* 등락부호		*/
	char  realpl     [12];          /* 실현손익		*/
	char  amotsell   [12]; 	        /* 금일매도금액	*/

	char  jango_gb   [ 1];          /* 잔고구분     */
	                                /* 0:현금,1:융자*/
	                                /* 2:자기       */
	char  daechul    [ 8];          /* 대출일       */
	char  mangiil    [ 8];          /* 만기일       */
	char  sinamt     [12];          /* 신용금액     */
	char  interest   [ 9];          /* 대출이자     */
    char  bocash     [ 3];          /* 현금증거금율 */
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
/* Map에서 올라온 Input Data 정의                            */
/*-----------------------------------------------------------*/
typedef struct
{
	char	geja	[20];       /* 계좌번호             	*/
	char    passwd	[ 8];       /* 비밀번호             	*/
    char 	ipaddr  [16];   	/* client ipaddr(199.99.9.90->199099009090)   */
} TR_20051_I;                   

/*-----------------------------------------------------------*/
/* Map으로 보낼 Output Data 정의                             */
/*-----------------------------------------------------------*/
typedef struct
{
    char    geja      [20];    /* 계좌번호                      */
	char    dpsast    [15];    /* 예탁자산총액                  */
	char	d2		  [15];      /* D+2예수금   S9(15)          */
	char    mgnrat    [15];    /* 증거금률100퍼센트주문가능금액 */ 
} TR_20051_O;

#endif
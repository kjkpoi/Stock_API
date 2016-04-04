/******************************************************************/
/* 01. 프로그램명      : {tr_13147.h}                             */
/* 04. 프로그램기능    : {동부API-실시간잔고}           	  	      */
/* 05. 수  정  자	   : {KHS}     							      */
/* 06. 수  정  일	   : {2013/04/18}                             */
/******************************************************************/

#define	tr_13147MAX 500

typedef struct _tr13147_i
{
	char  geja[20];   	/* 지점번호(3)+계좌번호(8) + sp(9) */
	char  gbun[ 1];   	/* 조회구분 0:잔고 1:평가 2:체결잔고 */

	char  ngbn[ 1];     /* 0:처음, 1:다음          */
	char  next[50];     /* 다음조회 KEY            */
} TR_13147_I;

typedef struct _tr_13147_s
{
	char  amotmsmdtot[15]; 	/* 총   매입금액	*/
	char  pyungpltot [15]; 	/* 총   평가손익	*/
	char  amotdealtot[15];  /* 당일 매도금액 	*/
	char  amotpyngtot[15];	/* 총   평가금액	*/
	char  suikratetot[15]; 	/* 총   수익율		*/
	char  realpltot  [15];  /* 당일 실현손익	*/

	char  ngbn       [ 1];  /* 다음데이타 구분  */
	                        /* 0:없음, 1:있음   */
	char  next       [50];  /* 다음조회 KEY     */
} TR_13147_S;

typedef struct _tr_13147_g
{
	char  jocode     [SH_KSIZE];	/* 종목코드		*/
	char  joname     [20]; 			/* 종목명		*/
	char  qntybooknon[15]; 			/* 가용수량		*/
	char  pyungpl    [15]; 			/* 평가손익		*/
	char  suikrate   [ 7]; 			/* 수익율		*/
	char  amotbook   [15]; 			/* 잔고금액		*/
	char  amotbooknon[15];			/* 평가금액 	*/
	char  qntydealbef[15]; 			/* 전일변동		*/
	char  qntydeal   [15]; 			/* 금일변동		*/
	char  qntyrest   [15]; 			/* 결제잔고		*/
	char  prcebooknon[ 9]; 			/* 장부단가		*/
	char  feentax    [ 9]; 			/* 제비용(수수료+제세금) */
	char  stocktax   [ 9]; 			/* 주당비용				 */
	char  fee		 [ 9];			/* 수수료  				 */
	char  tax		 [ 9];			/* 세금 				 */
	char  price      [ 7]; 			/* 현재가		*/
	char  change	 [ 7];			/* 전일대비		*/
	char  date		 [ 8];			/* 최종매입일   */
	char  sign		 [ 1];			/* 등락부호		*/
	char  realpl     [15];          /* 실현손익		*/
	char  amotsell   [15]; 	        /* 금일매도금액	*/

	char  jango_gb   [ 1];          /* 잔고구분     */
	                                /* 0:현금, 
	                                1 신용유통융자
                                    3 신용자기융자
                                    5 신용유통대주
                                    7 신용자기대주
                                    8 예탁주식담보신용대출 */
	char  daechul    [ 8];          /* 대출일       */
	char  mangiil    [ 8];          /* 만기일       */
	char  sinamt     [15];          /* 신용금액     */
	char  interest   [ 9];          /* 대출이자     */
    char  bocash     [ 3];          /* 현금증거금율 */

	/* 2013.04.18 추가 */
	char  qntyposs   [15]; 			/* 매도가능		*/
	char  jo_gb      [ 1]; 			/* 종목구분: 0=코스피, 1=코스닥, 2=ELW, 3=ETF */
	char  chrate     [ 7]; 			/* 등락률		*/
	char  hprice     [ 7]; 			/* 상한가		*/
	char  bid	     [ 7]; 			/* 매수호가		*/
	char  bidremain  [10]; 			/* 매수잔량     */
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

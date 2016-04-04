#ifndef _DEFINEDLL_TR13242_
#define	_DEFINEDLL_TR13242_
/**************************************************************/
/* 01. 프로그램명      : {tr_13242.h}                         */
/* 02. 작  성  자      : {이장헌}                             */
/* 03. 작 성 일 자     : {2007/04/06}                         */
/* 04. 프로그램기능    : {실시간잔고}           	  	      */
/* 05. 수  정  자	   : {KHS}							      */
/* 06. 수  정  일	   : 2010.11.08							  */
/**************************************************************/

#define TR_13242	"13242"
#define	tr_13242MAX 500
#define CODE_SIZE	9

typedef struct _tr13242_i
{
	char  geja     [20];          /* 지점번호(3)+계좌번호(8) + sp(9)   */
	char  gbun     [ 1];          /* 조회구분 0:잔고 1:평가 2:체결잔고 */
	char  checkgb  [ 1];          /* 조회구분 0:전체, 1:종목           */
	char  jgcode   [CODE_SIZE];   /* 종목코드                          */
	char  creditmon[ 1];		  /* 0:포함하지 않음, 1:포함		   */

	char  ngbn     [ 1];          /* 0:처음, 1:다음          */
	char  next     [50];          /* 다음조회 KEY            */
} TR_13242_I;

typedef struct _tr_13242_s
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
} TR_13242_S;

typedef struct _tr_13242_g
{
	char  jocode     [ 6];			/* 종목코드		*/
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
	char  amotbuy	 [15];			/* 금일매수금액 */ 
	char  jango_gb   [ 1];          /* 잔고구분     */
	                                /* 0:현금, 
	                                1 신용유통융자
                                    3 신용자기융자
                                    5 신용유통대주
                                    7 신용자기대주
                                    8 예탁주식담보신용대출      */
	char  daechul    [ 8];          /* 대출일       */
	char  mangiil    [ 8];          /* 만기일       */
	char  sinamt     [15];          /* 신용금액     */
	char  interest   [ 9];          /* 대출이자     */
    char  bocash     [ 3];          /* 현금증거금율 */
	char  qntyposs   [15]; 			/* 매도가능		*/
	// 20120723 ssj - 서버자동주문 >> 주석변경
	char  codegb	 [ 1];			/* ETF=4 ELW=3 KOSDAQ=2 KOSPI=1 */
	// 20120723 ssj - 서버자동주문 <<
	// 20110627 주우주 >>
	char  chrate	  [ 7];			/* 등락률 */
	// 20110627 주우주 <<
	// 20110908 주우주 >>
	char  high		  [ 7];			/*상한가 */
	char  masuhoga	  [ 7];			/*매수호가 */
	char  masuqty	  [10];			/*매수잔량  */
	// 20110908 주우주 <<

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
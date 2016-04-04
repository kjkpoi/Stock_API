#if !defined(AFX_TR_20110_HEADER_)
#define AFX_TR_20110_HEADER_


/*************************************************************/
/* 04. 프로그램기능    : {CME선물 잔고조회}					 */
/*************************************************************/

#define tr_20110MAX		250

typedef struct _TR_20110_I	
{
	char  geja     [20];    /* 지점번호(3)+계좌번호(8) ->20 */
} TR_20110_I;

typedef struct _TR_20110_S	
{
	char  yakjungtot [17];  /* 총   약정금액                    */
	char  pyungpltot [17];  /* 총   평가손익                    */
	char  jumuntot   [17];  /* 주문가능총액                     */

	char  amotpyngtot[17];  /* 총   평가금액                    */
	char  realpltot  [17];  /* 당일 실현손익                    */
	char  jumuncash  [17];  /* 주문가능현금                     */
	char  suikratetot[ 9];  /* 총   수익율   7->9               */

} TR_20110_S;

typedef struct _TR_20110_G	
{
	char  jocode     [15];  /* 종목코드                8 -> 15  */	
	char  mmgb       [ 5];  /* 매매구분                5 ->  5  */
	char  avqty      [15];  /* 청산가능                9 -> 15  */
	char  pnonqty    [15];  /* 전일잔고                9 -> 15  */
	char  qtychg     [15];  /* 증감                    9 -> 15  */
	char  tnonqty    [15];  /* 보유수량                9 -> 15  */
	char  tnocontqty [15];  /* 미체결주문수량          9 -> 15  */
	char  tnonprc    [12];  /* 매입단가               12 -> 12  */
	char  price      [ 6];  /* 현재가                  6 ->  6  */
	char  pyungpl    [15];  /* 평가손익               15 -> 15  */
	char  suikrate   [ 9];  /* 수익율                  9 ->  9  */
	char  tnonamt    [15];  /* 약정금액               15 -> 15  */
	char  pyungamt   [15];  /* 평가금액               15 -> 15  */
	char  fee        [12];  /* 수수료                 12 -> 12  */
	char  bid        [ 6];  /* 매수호가                6 ->  6  */
	char  offer      [ 6];  /* 매도호가                6 ->  6  */
	char  hprice     [ 6];  /* 상한가                  6 ->  6  */
	char  lprice     [ 6];  /* 하한가                  6 ->  6  */
	char  gdssect    [ 1];  /* 시장소속구분            1 ->  1  */
	char  resbpl     [15];  /* 당일실현손익           15 -> 15  */
	char  jutp       [ 3];  /* 주문유형                3 ->  3  */
	char  trdunt     [15];  /* 거래단위               15 -> 15  */
	char  tdmemeamt  [15];  /* 당일매수또는매도금액   15 -> 15  */
	char  memeamt    [15];  /* 매매대금합             15 -> 15  */
} TR_20110_G;

typedef struct _tr_20110_o
{
	TR_20110_S		sm;
	char  gridcnt    [  4]; // Grid count
	TR_20110_G  gr[tr_20110MAX];

} TR_20110_O;

#define  SZ_TR20110_I sizeof(TR_20110_I)
#define  SZ_TR20110_G sizeof(TR_20110_G)

#endif //AFX_TR_20110_HEADER_
#if !defined(AFX_TR_13655_HEADER_)
#define AFX_TR_13655_HEADER_


/*************************************************************/
/* 01. 프로그램명      : {tr_13655.h}                        */
/* 03. 작 성 일 자     : {2009/10/28}                        */
/* 04. 프로그램기능    : {선옵 잔고}						 */
/* 05. 수  정  자      : {}		                             */
/* 06. 수 정 일 자     : {}     		                     */
/* 07. REMARKS 사항    : {}                                  */
/*************************************************************/
#define	TR_FUTJANGO		"13655"
#define	TR_FUTEVAL		"15813"
#define	TR_FUTFEE		"13653"

#define tr_13655MAX		250

typedef struct _TR_13655_I	
{
	char  geja     [20];    /* 지점번호(3)+계좌번호(8) ->20 */
} TR_13655_I;

typedef struct _TR_13655_S	
{
	char  yakjungtot [17];  /* 총   약정금액                    */
	char  pyungpltot [17];  /* 총   평가손익                    */
	char  jumuntot   [17];  /* 주문가능총액                     */

	char  amotpyngtot[17];  /* 총   평가금액                    */
	char  realpltot  [17];  /* 당일 실현손익                    */
	char  jumuncash  [17];  /* 주문가능현금                     */
	char  suikratetot[ 9];  /* 총   수익율   7->9               */

} TR_13655_S;

typedef struct _TR_13655_G	
{
	char  jocode     [15];  /* 종목코드                8 -> 15  */
	char  mmgb_attr  [ 3];  /* 매매구분                3 ->  3  */
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
} TR_13655_G;

typedef struct _tr_13655_o
{
	TR_13655_S		sm;
	char  gridcnt    [  4]; // Grid count
	TR_13655_G  gr[tr_13655MAX];

} TR_13655_O;

#define  SZ_TR13655_I sizeof(TR_13655_I)
#define  SZ_TR13655_G sizeof(TR_13655_G)

//=======================================================================================
// 선옵실시간잔고 수수료조회
//=======================================================================================
typedef struct
{
	char        accno [20];			//계좌번호
	char        pass [18];			//입력비밀번호
	char        date [8];			//주문일
	char        ip_addr [16];		//privateip
} TR_13653_I;

typedef struct
{
	char        data1 [15]; //평가예탁금총액
	char        data2 [16]; //주문가능금액
	char        fee   [16]; //수수료
} TR_13653_O;


//=======================================================================================
//# title : 15813 계좌잔고 및 평가현황(자동주문 용)
//=======================================================================================
typedef struct
{
	char        accno [20];			//계좌번호
	char        pass [8];			//입력비밀번호
	char        date [8];			//주문일

	char        janggubun [1];		//잔고평가구분 #0:기본설정1:이동평균법2:선입선출법 (보통은 '0'을 사용)
	char        futuregubun [1];	//선물가격평가구분  #2:전일종가1:당초가
	char        ip_addr [16];		//privateip
	char		nxtKey [19];		//연속키:0 :O_SETCONTBTNKEY    -> 실제 19바이트
} TR_15813_I;


typedef struct
{
	char        data11 [15]; //예탁금총액
	char        data12 [15]; //예탁현금
	char        data13 [15]; //예탁대용

	char        data21 [15]; //위탁증거금총액
	char        data22 [15]; //현금위탁증거금액
	char        data23 [14]; //유지증거금총액
	char        data24 [15]; //현금유지증거금액

	char        data31 [14]; //추가증거금총액
	char        data32 [15]; //현금추가증거금액
	char        data33 [14]; //주문가능총금액
	char        data34 [15]; //현금주문가능금액

	char        data41 [14]; //인출가능총금액
	char        data42 [15]; //인출가능현금액

	char		nxtKey [19];  //연속키:0 :O_SETCONTBTNKEY    -> 실제 19바이트

} TR_15813_O;



#endif //AFX_TR_13655_HEADER_
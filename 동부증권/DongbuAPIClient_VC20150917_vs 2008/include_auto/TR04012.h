/****************************************************************/
/* 01. 프로그램명      : {tr_04012.h}                         	*/
/* 02. 작  성  자      : {이근웅}                             	*/
/* 03. 작 성 일 자     : {2002/09/13}                         	*/
/* 04. 프로그램기능    : {선물현재가-B2(상세/체결)}           	*/
/* 05. REMARKS 사항    : {}    		  						  	*/
/****************************************************************/

// 20120723 ssj - 서버자동주문 >>
#define TR_04012	"04012"
// 20120723 ssj - 서버자동주문 <<

#define  TR04012GridMAX			10

typedef struct
{
	char sCode      [8];    /* 종목코드    				        */
} TR_04012_I;

typedef struct {
    char offersu    [4];    /* 1우선 매도호가건수       		*/
    char offerjan   [7];    /* 1     매도     잔량      		*/
    char offer      [6];    /* 1     매도호가           		*/
    char bid        [6];    /* 1     매수호가           		*/
    char bidjan     [7];    /* 1     매수잔량           		*/
    char bidsu      [4];    /* 1우선 매수호가건수       		*/
    char joffersu   [4];    /* 2차선 매도호가건수       		*/
    char jofferjan  [7];    /* 2차선 매도호가 잔량      		*/
    char joffer     [6];    /* 2차선 매도호가           		*/
    char jbid       [6];    /* 2차선 매수호가           		*/
    char jbidjan    [7];    /* 2차선 매수호가 잔량      		*/
    char jbidsu     [4];    /* 2차선 매수호가건수       		*/
    char jjoffersu  [4];    /* 3차차 매도호가건수       		*/
    char jjofferjan [7];    /* 3차차 매도호가 잔량      		*/
    char jjoffer    [6];    /* 3차차 매도호가           		*/
    char jjbid      [6];    /* 3차차 매수호가           		*/
    char jjbidjan   [7];    /* 3차차 매수호가 잔량      		*/
    char jjbidsu    [4];    /* 3차차 매수호가건수       		*/
    char j4offersu  [4];    /* 4차선 매도호가건수       		*/
    char j4offerjan [7];    /* 4차선 매도호가 잔량      		*/
    char j4offer    [6];    /* 4차선 매도호가           		*/
    char j4bid      [6];    /* 4차선 매수호가           		*/
    char j4bidjan   [7];    /* 4차선 매수호가 잔량      		*/
    char j4bidsu    [4];    /* 4차선 매수호가건수       		*/
    char j5offersu  [4];    /* 5차선 매도호가건수       		*/
    char j5offerjan [7];    /* 5차선 매도호가 잔량      		*/
    char j5offer    [6];    /* 5차선 매도호가           		*/
    char j5bid      [6];    /* 5차선 매수호가           		*/
    char j5bidjan   [7];    /* 5차선 매수호가 잔량      		*/
    char j5bidsu    [4];    /* 5차선 매수호가건수       		*/
    char toffersu   [5];    /* 총매도호가건수           		*/
    char tofferjan  [7];    /* 총매도호가 잔량          		*/
    char remngap    [7];    /* 잔량차                           */
    char tobidjan   [7];    /* 총매수 호가 잔량         		*/
    char tbidsu     [5];    /* 총매수호가건수           		*/
} TR_04012_h;

typedef struct {
    char fuopen     [6];    /* 시가                 9(3)v9(2)  */
    char fuopen_chg [6];    /* 시가대비             9(3)v9(2)  */
    char theoryprice[6];    /* 이론가               9(3)v9(2)  */

    char fuhigh     [6];    /* 고가                 9(3)v9(2)  */
    char fuhigh_chg [6];    /* 고가대비             9(3)v9(2)  */
    char gyrirate   [6];    /* 괴리율               9(3)v9(2)  */

    char fulow      [6];    /* 저가                 9(3)v9(2)  */
    char fulow_chg  [6];    /* 저가대비             9(3)v9(2)  */
    char cbhprice   [8];    /* CB상한                S9(3)v9(4)  */

    char openyak    [6];    /* 미결제약정수량       9(6)       */
	char open_1     [6];    /* 금일-전일 미결제약정수량        */
	char cblprice   [8];    /* CB하한                S9(3)v9(4)  */

    char hprice     [6];    /* 상한가               9(3)v9(2)  */
    char lprice     [6];    /* 하한가               9(3)v9(2)  */
    char baseprice  [8];    /* 기준가               S9(3)v9(4)  */

	char listhprice [6];    /* 상장후 최고가 */
	char listhdate  [8];    /* 상장후 최고가일 */
	char spread     [6];    /* 스프레드             9(3)v9(2)  */

	char listlprice [6];    /* 상장후 최저가 */
	char listldate  [8];    /* 상장후 최저가일 */
	char jandatecnt [4];    /* 잔존일수             9(4)       */
} TR_04012_fp;

typedef struct {
    char opopen     [6];    /* 시가                 9(3)v9(2)  */
    char opopen_chg [6];    /* 시가대비             9(3)v9(2)  */
    char theoryprice[6];    /* 이론가               9(3)v9(2)  */

    char ophigh     [6];    /* 고가                 9(3)v9(2)  */
    char ophigh_chg [6];    /* 고가대비             9(3)v9(2)  */
    char gyrirate   [6];    /* 괴리율               9(3)v9(2)  */

    char oplow      [6];    /* 저가                 9(3)v9(2)  */
    char oplow_chg  [6];    /* 저가대비             9(3)v9(2)  */
    char delta      [8];    /* 델타                S9(3)v9(4)  */

    char openyak    [6];    /* 미결제약정수량       9(6)       */
	char open_1     [6];    /* 금일-전일 미결제약정수량        */
	char gmma       [8];    /* 감마                S9(3)v9(4)  */

    char hprice     [6];    /* 상한가               9(3)v9(2)  */
    char lprice     [6];    /* 하한가               9(3)v9(2)  */
    char theta      [8];    /* 세타                S9(3)v9(4)  */

	char listhprice [6];    /* 상장후 최고가 */
	char listhdate  [8];    /* 상장후 최고가일 */
	char impv       [6];    /* 내재변동성           9(3)v9(2)  */

	char listlprice [6];    /* 상장후 최저가 */
	char listldate  [8];    /* 상장후 최저가일 */
	char jandatecnt [4];    /* 잔존일수             9(4)       */
} TR_04012_op;

typedef struct {
	char sign       [1];    /* 등락부호    							*/
	char time       [6];    /* 시간        							*/
	char curr       [6];    /* 현재가      							*/
	char change     [6];    /* 전일비      							*/
	char msuvol   	[9];    /* 매수체결수량 						*/
	char mdovol   	[9];    /* 매도체결수량 						*/
	char volall   	[9];    /* 누적거래량   						*/
} TR_04012_G;

typedef struct 
{
/*	char impv		[6]; */
	char baseprice  [6];    /* 기준가 (2002.02.27추가)       - 숨김 */

	char nextfucode [8] ; 	/* 원월물(다음회차의 선물코드)   - 숨김 */
    char nextfucurr [6] ; 	/* 원월물 현재가                 - 숨김 */

    char curr   	[6] ; 	/* 선물/옵션 현재가              - 숨김 */

    char tbllen     [6];    /* 0001xx 								*/ 
    char tblmsg     [5];    /* "UM=E@" 								*/
	TR_04012_h      hoga;

    char tbllen2    [6];    /* 0001xx 								*/
    char tblmsg2    [5];    /* "UM=E@" 								*/
	TR_04012_fp 	fprice;

    char tbllen3    [6];    /* 0001xx 								*/
    char tblmsg3    [5];    /* "UM=E@" 								*/
	TR_04012_op 	oprice;

	char gridlen    [4+2];  /* Grid Row + Bojo Length 				*/
	char gridbojo   [4];    /* "UM=E" Setting 						*/ 
	TR_04012_G 		grid [TR04012GridMAX];
} TR_04012_O;

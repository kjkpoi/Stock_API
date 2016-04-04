#ifndef _DEFINEDLL_TR09110_
#define	_DEFINEDLL_TR09110_

/**************************************************************/
/* 01. 프로그램명      : {tr_09110.h}                         */
/* 04. 프로그램기능    : {주식현재가}                         */
/* 05. REMARKS 사항    : {}                                   */         
/**************************************************************/


#define TR_09110    "09110"

typedef struct
{
	char code[6]; /* 종목코드 */
} TR_09110_I;

typedef struct
{
	char price       [9];  /* 현 재 가     */
	char sign        [1];  /* 등락부호     */
	char change      [9];  /* 전일대비     */
	char updyul      [7];  /* 등 락 율     */
	char uplmtprice  [9];  /* 상 한 가     */
	char changerate  [7];  /* 상한가변동률 */
	char volume      [12]; /* 누적거래량   */
	char openam      [9];  /* 시    가     */
	char changerate1 [7];  /* 시가 변동률 */
	char offer       [9];  /* 매도호가     */
	char high        [9];  /* 고    가     */
	char changerate2 [7];  /* 고가 변동률 */
	char bid         [9];  /* 매수호가     */
	char low         [9];  /* 저    가     */
	char changerate3 [7];  /* 저가 변동률 */
	char predicprice[9];   /* 예상체결가격 */
	char predicvol  [12];  /* 예상체결수량 */
	char dnlmtprice  [9];  /* 하 한 가     */
	char changerate4 [7];  /* 하한가변동률 */

} TR_09110_JONG;

typedef struct
{

	char  hname    [20];/* 한글명 */
	char  offertot [9]; /* 총매도호가잔량 */
	char  bidtot   [9]; /* 총매수호가잔량 */

	/* 현재가 테이블 */
	char             jonglen[6];
	char             jongmsg[5];
	TR_09110_JONG    jong;

} TR_09110_O;



#endif
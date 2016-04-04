/*------------------------------------------------------------*/
/* 01. 프로그램명      : {tr_01922.h}                         */
/* 02. 작  성  자      : {KHS}                                */
/* 03. 작 성 일 자     : {2012/01/20}                         */
/* 04. 프로그램기능    : {외국인집계 조회}                    */
/* 05. REMARKS 사항    : {외국인거래원 합산}                  */
/*------------------------------------------------------------*/
///기관계......
#define	 TR_01922_MAX 100
/*#define	 TR_01922_MAX 500*/

typedef struct
{
	char	mkt_tp		[1];		/* 0전체 코스피1 코스닥2 */
	char	tuja_tp		[1];		/* 0전체 외국인1 기관계2 보험/기타금융3 투신4 은행5 연기금6 국가지자체7 기타법인8 */
	char	shcode		[SH_KSIZE];	/* 종목번호    */
	char	sort_tp		[2];		/* 정렬순서: 00순매수순 01순매도순 02매수량순 03매도량순 */

	char	nxtTp		[1];		/* 연속구분: 1연속 0조회 */
	char	nxtKey		[20];		/* 연속키: 종목 순서 */
} TR_01922_I;

typedef struct _TR_01922_OS
{
	char	shcode		[SH_KSIZE];	/* 종목코드    */
	char	hname		[20];		/* 종 목 명    */
	char	price		[ 9];		/* 현 재 가    */
	char	debi		[ 6];		/* 전일대비    */
	char	sign		[ 1];		/* 등락구분    */
	char	debiper		[ 7];		/* 대비율(%)   */
	char	volume		[15];		/* 거 래 량    */
	char	medo		[ 9];		/* 매도        */
	char	mesu		[ 9];		/* 매수        */
	char	soon		[ 9];		/* 순매수      */
} TR_01922_OS;

typedef struct _TR_01922_TMP
{
	char	shcode		[SH_KSIZE];	/* 종목코드    */
	char	hname		[20];		/* 종 목 명    */
	char	price		[ 9];		/* 현 재 가    */
	char	debi		[ 6];		/* 전일대비    */
	char	sign		[ 1];		/* 등락구분    */
	char	debiper		[ 7];		/* 대비율(%)   */
	char	volume		[15];		/* 거 래 량    */
	double	medo			;		/* 매도        */
	double	mesu			;		/* 매수        */
	double	soon			;		/* 순매수      */
} TR_01922_TMP;

typedef struct
{
	char	btnCnt		[ 2];
	char	btnBjMsg	[20];

	char	grdCnt		[6];      /* Grid Count          */
	char	grdBjMsg	[5];      /* Message Count       */
	TR_01922_OS data[TR_01922_MAX];
} TR_01922_O;

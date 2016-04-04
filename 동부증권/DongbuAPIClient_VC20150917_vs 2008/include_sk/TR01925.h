/*------------------------------------------------------------*/
/* 01. 프로그램명      : {tr_01925.h}                         */
/* 02. 작  성  자      : {KHS}                                */
/* 03. 작 성 일 자     : {2012/01/20}                         */
/* 04. 프로그램기능    : {외국인집계 조회}                    */
/* 05. REMARKS 사항    : {외국인거래원 합산}                  */
/*------------------------------------------------------------*/
//.... 외국인
#define	 TR_01925_MAX 100
/*#define	 TR_01925_MAX 500*/

typedef struct
{
	char	mkt_tp		[1];		/* 0전체 코스피1 코스닥2 */
	char	tuja_tp		[1];		/* 외국인1 */
	char	shcode		[SH_KSIZE];	/* 종목번호    */
	char	sort_tp		[2];		/* 정렬순서: 00순매수순 01순매도순 02매수량순 03매도량순 */

	char	nxtTp		[1];		/* 연속구분: 1연속 0조회 */
	char	nxtKey		[20];		/* 연속키: 종목 순서 */
} TR_01925_I;

typedef struct _TR_01925_OS
{
	char	shcode		[SH_KSIZE];	/* 종목코드    */
	char	hname		[20];		/* 종 목 명    */
	char	price		[ 9];		/* 현 재 가    */
	char	debi		[ 6];		/* 전일대비    */
	char	sign		[ 1];		/* 등락구분    */
	char	debiper		[ 7];		/* 대비율(%)   */
	char	volume		[15];		/* 거 래 량    */
	char	dome_medo	[ 9];		/* 국내증권사 매도        */
	char	dome_mesu	[ 9];		/* 국내증권사 매수        */
	char	dome_soon	[ 9];		/* 국내증권사 순매수      */
	char	fore_medo	[ 9];		/* 외국계증권사 매도      */
	char	fore_mesu	[ 9];		/* 외국계증권사 매수      */
	char	fore_soon	[ 9];		/* 외국계증권사 순매수    */
	char	sum_medo	[15];		/* 합계 매도      */
	char	sum_mesu	[15];		/* 합계 매수      */
	char	sum_soon	[15];		/* 합계 순매수    */
} TR_01925_OS;

typedef struct _TR_01925_TMP
{
	char	shcode		[SH_KSIZE];	/* 종목코드    */
	char	hname		[20];		/* 종 목 명    */
	char	price		[ 9];		/* 현 재 가    */
	char	debi		[ 6];		/* 전일대비    */
	char	sign		[ 1];		/* 등락구분    */
	char	debiper		[ 7];		/* 대비율(%)   */
	char	volume		[15];		/* 거 래 량    */
	double	dome_medo		;		/* 국내증권사 매도        */
	double	dome_mesu		;		/* 국내증권사 매수        */
	double	dome_soon		;		/* 국내증권사 순매수      */
	double	fore_medo		;		/* 외국계증권사 매도      */
	double	fore_mesu		;		/* 외국계증권사 매수      */
	double	fore_soon		;		/* 외국계증권사 순매수    */
} TR_01925_TMP;

typedef struct
{
	char	btnCnt		[ 2];
	char	btnBjMsg	[20];

	char	grdCnt		[6];      /* Grid Count          */
	char	grdBjMsg	[5];      /* Message Count       */
	TR_01925_OS data[TR_01925_MAX];
} TR_01925_O;

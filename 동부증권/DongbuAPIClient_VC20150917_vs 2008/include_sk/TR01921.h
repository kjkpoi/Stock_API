/*------------------------------------------------------------*/
/* 01. 프로그램명      : {tr_01921.h}                         */
/* 02. 작  성  자      : {KHS}                                */
/* 03. 작 성 일 자     : {2012/01/20}                         */
/* 04. 프로그램기능    : {외국인집계 조회}                    */
/* 05. REMARKS 사항    : {외국인거래원 합산}                  */
/*------------------------------------------------------------*/
// 전체.....
#define	 TR_01921_MAX 100
/*#define	 TR_01921_MAX 500*/

#define SH_KSIZE   6
#define TR_01921      "01921"


typedef struct
{
	char	mkt_tp		[1];		/* 0전체 코스피1 코스닥2 */
	char	tuja_tp		[1];		/* 0전체 외국인1 기관계2 보험/기타금융 투신4 은행5 연기금6 국가지자체7 기타법인8 */
	char	shcode		[SH_KSIZE];	/* 종목번호    */
	char	sort_tp		[2];		/* 정렬순서: 00외국인순매수순 01외국인순매도순 02기관계순매수순 03기관계순매도순~ */

	char	nxtTp		[1];		/* 연속구분: 1연속 0조회 */
	char	nxtKey		[20];		/* 연속키: 종목 순서 */
} TR_01921_I;

typedef struct _TR_01921_OS
{
	char	shcode		[SH_KSIZE];	/* 종목코드    */
	char	hname		[20];		/* 종 목 명    */
	char	price		[ 9];		/* 현 재 가    */
	char	debi		[ 6];		/* 전일대비    */
	char	sign		[ 1];		/* 등락구분    */
	char	debiper		[ 7];		/* 대비율(%)   */
	char	volume		[15];		/* 거 래 량    */
	char	fore		[ 9];		/* 외국인      */
	char	ggt			[ 9];		/* 기관계      */
	char	boh			[ 9];		/* 보험/종금   */
	char	tus			[ 9];		/* 투신        */
	char	bnk			[ 9];		/* 은행        */
	char	gyg			[ 9];		/* 기금        */
	char	nat			[ 9];		/* 국가지자체  */
	char	etc			[ 9];		/* 기타        */
} TR_01921_OS;

typedef struct
{
	char	btnCnt      [ 2];
	char	btnBjMsg    [20];

	char	grdCnt		[ 6];      /* Grid Count          */
	char	grdBjMsg	[ 5];      /* Message Count       */
	TR_01921_OS data[TR_01921_MAX];
} TR_01921_O;

typedef struct
{
	char	shcode		[SH_KSIZE];	/* 종목코드    */
	char	hname		[20];		/* 종 목 명    */
	long	price			;		/* 현 재 가    */
	long	debi			;		/* 전일대비    */
	char	sign		[ 1];		/* 등락구분    */
	double	debiper			;		/* 대비율(%)   */
	double	volume			;		/* 거 래 량    */
	double	fore			;		/* 외국인      */
	double	ggt				;		/* 기관계      */
	double	boh				;		/* 보험/기타금융 */
	double	tus				;		/* 투신        */
	double	bnk				;		/* 은행        */
	double	gyg				;		/* 연기금      */
	double	nat				;		/* 국가지자체  */
	double	etc				;		/* 기타법인    */
} TR_01921_TMP;

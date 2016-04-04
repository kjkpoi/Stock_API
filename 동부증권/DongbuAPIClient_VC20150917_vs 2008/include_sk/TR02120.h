/*----------------------------------------------------------------------*/
/** tr_02120.h                                                          */
/**         : 프로그램매매(차익,비차익) 그래프                          */
/*          : grid&그래프                                               */
/*----------------------------------------------------------------------*/

#define     tr_02120GRIDMAX     500
#define     tr_02120GRAPHMAX    500
#define     tr_02120MAX         40960

#define     tr_02120TimeL       8
#define     tr_02120DataL       10

#define		TR_02120			"02120"

typedef struct
{
    char    next 		[14];	/* 시간     */
	char    mastebit    [ 1];   /* 1(KOSPI), 2(KOSDAQ)      */
	char    su_gum      [ 1];   /* 2(수량), 1(금액), 3(금액)(억원)         */
/*	char    grid_num    [ 1];				 1(10), 2(20)				*/
} TR_02120_I;

typedef struct _tr_02120_gd
{
	char    time        [ 6];               /* 시간                     */
	char	jisu		[ 9];				/* 지수						*/
	char    chado       [ 9];               /* 차익매도체결(천주)       */
	char    chasu       [ 9];               /* 차익매수체결(천주)       */
	char    chasoon     [ 9];               /* 차익매수체결(천주)       */
	char    bido        [ 9];               /* 비차익매도체결(천주)     */
	char    bisu        [ 9];               /* 비차익매수체결(천주)     */
	char    bisoon      [ 9];               /* 비차익매수체결(천주)     */
	char    todo        [ 9];               /* 전체매도체결(천주)       */
	char    tosu        [ 9];               /* 전체매수체결(천주)       */
	char    tosoon      [ 9];               /* 전체매수체결(천주)       */
} TR_02120_GD;

typedef struct _tr_02120_ch
{
	char    time        [ 6];               /* 시간                     */
	char	jisu		[ 9];				/* 지수						*/
	char    cha         [10];               /* 차익   순매수            */
	char    bi          [10];               /* 비차익 순매수            */
	char    tot         [10];               /* 전체 순매수              */
} TR_02120_CH;


typedef struct
{
    char    btnmsgcnt	[ 2];       /* 버튼의 보조 메세지 길이 */
    char    btnmsg		[22];   	/* EN=1@DT=000660 버튼의 보조 메세지 */

	char	gongji		[80];		/* 공지사항추가(2004.05.13) */

	char	tblcnt		[ 6];
	char	tblmsg		[50];

	char    time        [ 6];       /* 시간                     */
	char	name		[20];		/* 코스피, 코스탁			*/
	char    jisu        [ 9];       /* 지수                     */
	char    sign        [ 1];       /* 등락부호                 */
	char    change      [ 9];       /* 대비                     */

	char    gr_cnt      [ 6];        /* Grid count              */ 
	char    gr_bjdata   [ 4];        /* Grid Bojo Data          */ 
	TR_02120_GD  grid[tr_02120GRIDMAX];      /* Grid                   */ 

	char    chart_cnt   [ 5];        /* Chart Count              */
	char    chart_bjdata[256];       /* Chart Bojo Data          */
	TR_02120_CH  graph[tr_02120GRAPHMAX];   /* Chart                    */

} TR_02120_O;

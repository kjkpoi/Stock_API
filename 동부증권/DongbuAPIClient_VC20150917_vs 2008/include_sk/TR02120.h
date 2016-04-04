/*----------------------------------------------------------------------*/
/** tr_02120.h                                                          */
/**         : ���α׷��Ÿ�(����,������) �׷���                          */
/*          : grid&�׷���                                               */
/*----------------------------------------------------------------------*/

#define     tr_02120GRIDMAX     500
#define     tr_02120GRAPHMAX    500
#define     tr_02120MAX         40960

#define     tr_02120TimeL       8
#define     tr_02120DataL       10

#define		TR_02120			"02120"

typedef struct
{
    char    next 		[14];	/* �ð�     */
	char    mastebit    [ 1];   /* 1(KOSPI), 2(KOSDAQ)      */
	char    su_gum      [ 1];   /* 2(����), 1(�ݾ�), 3(�ݾ�)(���)         */
/*	char    grid_num    [ 1];				 1(10), 2(20)				*/
} TR_02120_I;

typedef struct _tr_02120_gd
{
	char    time        [ 6];               /* �ð�                     */
	char	jisu		[ 9];				/* ����						*/
	char    chado       [ 9];               /* ���͸ŵ�ü��(õ��)       */
	char    chasu       [ 9];               /* ���͸ż�ü��(õ��)       */
	char    chasoon     [ 9];               /* ���͸ż�ü��(õ��)       */
	char    bido        [ 9];               /* �����͸ŵ�ü��(õ��)     */
	char    bisu        [ 9];               /* �����͸ż�ü��(õ��)     */
	char    bisoon      [ 9];               /* �����͸ż�ü��(õ��)     */
	char    todo        [ 9];               /* ��ü�ŵ�ü��(õ��)       */
	char    tosu        [ 9];               /* ��ü�ż�ü��(õ��)       */
	char    tosoon      [ 9];               /* ��ü�ż�ü��(õ��)       */
} TR_02120_GD;

typedef struct _tr_02120_ch
{
	char    time        [ 6];               /* �ð�                     */
	char	jisu		[ 9];				/* ����						*/
	char    cha         [10];               /* ����   ���ż�            */
	char    bi          [10];               /* ������ ���ż�            */
	char    tot         [10];               /* ��ü ���ż�              */
} TR_02120_CH;


typedef struct
{
    char    btnmsgcnt	[ 2];       /* ��ư�� ���� �޼��� ���� */
    char    btnmsg		[22];   	/* EN=1@DT=000660 ��ư�� ���� �޼��� */

	char	gongji		[80];		/* ���������߰�(2004.05.13) */

	char	tblcnt		[ 6];
	char	tblmsg		[50];

	char    time        [ 6];       /* �ð�                     */
	char	name		[20];		/* �ڽ���, �ڽ�Ź			*/
	char    jisu        [ 9];       /* ����                     */
	char    sign        [ 1];       /* �����ȣ                 */
	char    change      [ 9];       /* ���                     */

	char    gr_cnt      [ 6];        /* Grid count              */ 
	char    gr_bjdata   [ 4];        /* Grid Bojo Data          */ 
	TR_02120_GD  grid[tr_02120GRIDMAX];      /* Grid                   */ 

	char    chart_cnt   [ 5];        /* Chart Count              */
	char    chart_bjdata[256];       /* Chart Bojo Data          */
	TR_02120_CH  graph[tr_02120GRAPHMAX];   /* Chart                    */

} TR_02120_O;

/*------------------------------------------------------------*/
/* 01. ���α׷���      : {tr_01925.h}                         */
/* 02. ��  ��  ��      : {KHS}                                */
/* 03. �� �� �� ��     : {2012/01/20}                         */
/* 04. ���α׷����    : {�ܱ������� ��ȸ}                    */
/* 05. REMARKS ����    : {�ܱ��ΰŷ��� �ջ�}                  */
/*------------------------------------------------------------*/
//.... �ܱ���
#define	 TR_01925_MAX 100
/*#define	 TR_01925_MAX 500*/

typedef struct
{
	char	mkt_tp		[1];		/* 0��ü �ڽ���1 �ڽ���2 */
	char	tuja_tp		[1];		/* �ܱ���1 */
	char	shcode		[SH_KSIZE];	/* �����ȣ    */
	char	sort_tp		[2];		/* ���ļ���: 00���ż��� 01���ŵ��� 02�ż����� 03�ŵ����� */

	char	nxtTp		[1];		/* ���ӱ���: 1���� 0��ȸ */
	char	nxtKey		[20];		/* ����Ű: ���� ���� */
} TR_01925_I;

typedef struct _TR_01925_OS
{
	char	shcode		[SH_KSIZE];	/* �����ڵ�    */
	char	hname		[20];		/* �� �� ��    */
	char	price		[ 9];		/* �� �� ��    */
	char	debi		[ 6];		/* ���ϴ��    */
	char	sign		[ 1];		/* �������    */
	char	debiper		[ 7];		/* �����(%)   */
	char	volume		[15];		/* �� �� ��    */
	char	dome_medo	[ 9];		/* �������ǻ� �ŵ�        */
	char	dome_mesu	[ 9];		/* �������ǻ� �ż�        */
	char	dome_soon	[ 9];		/* �������ǻ� ���ż�      */
	char	fore_medo	[ 9];		/* �ܱ������ǻ� �ŵ�      */
	char	fore_mesu	[ 9];		/* �ܱ������ǻ� �ż�      */
	char	fore_soon	[ 9];		/* �ܱ������ǻ� ���ż�    */
	char	sum_medo	[15];		/* �հ� �ŵ�      */
	char	sum_mesu	[15];		/* �հ� �ż�      */
	char	sum_soon	[15];		/* �հ� ���ż�    */
} TR_01925_OS;

typedef struct _TR_01925_TMP
{
	char	shcode		[SH_KSIZE];	/* �����ڵ�    */
	char	hname		[20];		/* �� �� ��    */
	char	price		[ 9];		/* �� �� ��    */
	char	debi		[ 6];		/* ���ϴ��    */
	char	sign		[ 1];		/* �������    */
	char	debiper		[ 7];		/* �����(%)   */
	char	volume		[15];		/* �� �� ��    */
	double	dome_medo		;		/* �������ǻ� �ŵ�        */
	double	dome_mesu		;		/* �������ǻ� �ż�        */
	double	dome_soon		;		/* �������ǻ� ���ż�      */
	double	fore_medo		;		/* �ܱ������ǻ� �ŵ�      */
	double	fore_mesu		;		/* �ܱ������ǻ� �ż�      */
	double	fore_soon		;		/* �ܱ������ǻ� ���ż�    */
} TR_01925_TMP;

typedef struct
{
	char	btnCnt		[ 2];
	char	btnBjMsg	[20];

	char	grdCnt		[6];      /* Grid Count          */
	char	grdBjMsg	[5];      /* Message Count       */
	TR_01925_OS data[TR_01925_MAX];
} TR_01925_O;

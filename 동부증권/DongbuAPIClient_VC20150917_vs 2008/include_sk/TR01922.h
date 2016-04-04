/*------------------------------------------------------------*/
/* 01. ���α׷���      : {tr_01922.h}                         */
/* 02. ��  ��  ��      : {KHS}                                */
/* 03. �� �� �� ��     : {2012/01/20}                         */
/* 04. ���α׷����    : {�ܱ������� ��ȸ}                    */
/* 05. REMARKS ����    : {�ܱ��ΰŷ��� �ջ�}                  */
/*------------------------------------------------------------*/
///�����......
#define	 TR_01922_MAX 100
/*#define	 TR_01922_MAX 500*/

typedef struct
{
	char	mkt_tp		[1];		/* 0��ü �ڽ���1 �ڽ���2 */
	char	tuja_tp		[1];		/* 0��ü �ܱ���1 �����2 ����/��Ÿ����3 ����4 ����5 �����6 ��������ü7 ��Ÿ����8 */
	char	shcode		[SH_KSIZE];	/* �����ȣ    */
	char	sort_tp		[2];		/* ���ļ���: 00���ż��� 01���ŵ��� 02�ż����� 03�ŵ����� */

	char	nxtTp		[1];		/* ���ӱ���: 1���� 0��ȸ */
	char	nxtKey		[20];		/* ����Ű: ���� ���� */
} TR_01922_I;

typedef struct _TR_01922_OS
{
	char	shcode		[SH_KSIZE];	/* �����ڵ�    */
	char	hname		[20];		/* �� �� ��    */
	char	price		[ 9];		/* �� �� ��    */
	char	debi		[ 6];		/* ���ϴ��    */
	char	sign		[ 1];		/* �������    */
	char	debiper		[ 7];		/* �����(%)   */
	char	volume		[15];		/* �� �� ��    */
	char	medo		[ 9];		/* �ŵ�        */
	char	mesu		[ 9];		/* �ż�        */
	char	soon		[ 9];		/* ���ż�      */
} TR_01922_OS;

typedef struct _TR_01922_TMP
{
	char	shcode		[SH_KSIZE];	/* �����ڵ�    */
	char	hname		[20];		/* �� �� ��    */
	char	price		[ 9];		/* �� �� ��    */
	char	debi		[ 6];		/* ���ϴ��    */
	char	sign		[ 1];		/* �������    */
	char	debiper		[ 7];		/* �����(%)   */
	char	volume		[15];		/* �� �� ��    */
	double	medo			;		/* �ŵ�        */
	double	mesu			;		/* �ż�        */
	double	soon			;		/* ���ż�      */
} TR_01922_TMP;

typedef struct
{
	char	btnCnt		[ 2];
	char	btnBjMsg	[20];

	char	grdCnt		[6];      /* Grid Count          */
	char	grdBjMsg	[5];      /* Message Count       */
	TR_01922_OS data[TR_01922_MAX];
} TR_01922_O;

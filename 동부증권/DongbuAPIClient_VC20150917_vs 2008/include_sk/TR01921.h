/*------------------------------------------------------------*/
/* 01. ���α׷���      : {tr_01921.h}                         */
/* 02. ��  ��  ��      : {KHS}                                */
/* 03. �� �� �� ��     : {2012/01/20}                         */
/* 04. ���α׷����    : {�ܱ������� ��ȸ}                    */
/* 05. REMARKS ����    : {�ܱ��ΰŷ��� �ջ�}                  */
/*------------------------------------------------------------*/
// ��ü.....
#define	 TR_01921_MAX 100
/*#define	 TR_01921_MAX 500*/

#define SH_KSIZE   6
#define TR_01921      "01921"


typedef struct
{
	char	mkt_tp		[1];		/* 0��ü �ڽ���1 �ڽ���2 */
	char	tuja_tp		[1];		/* 0��ü �ܱ���1 �����2 ����/��Ÿ���� ����4 ����5 �����6 ��������ü7 ��Ÿ����8 */
	char	shcode		[SH_KSIZE];	/* �����ȣ    */
	char	sort_tp		[2];		/* ���ļ���: 00�ܱ��μ��ż��� 01�ܱ��μ��ŵ��� 02�������ż��� 03�������ŵ���~ */

	char	nxtTp		[1];		/* ���ӱ���: 1���� 0��ȸ */
	char	nxtKey		[20];		/* ����Ű: ���� ���� */
} TR_01921_I;

typedef struct _TR_01921_OS
{
	char	shcode		[SH_KSIZE];	/* �����ڵ�    */
	char	hname		[20];		/* �� �� ��    */
	char	price		[ 9];		/* �� �� ��    */
	char	debi		[ 6];		/* ���ϴ��    */
	char	sign		[ 1];		/* �������    */
	char	debiper		[ 7];		/* �����(%)   */
	char	volume		[15];		/* �� �� ��    */
	char	fore		[ 9];		/* �ܱ���      */
	char	ggt			[ 9];		/* �����      */
	char	boh			[ 9];		/* ����/����   */
	char	tus			[ 9];		/* ����        */
	char	bnk			[ 9];		/* ����        */
	char	gyg			[ 9];		/* ���        */
	char	nat			[ 9];		/* ��������ü  */
	char	etc			[ 9];		/* ��Ÿ        */
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
	char	shcode		[SH_KSIZE];	/* �����ڵ�    */
	char	hname		[20];		/* �� �� ��    */
	long	price			;		/* �� �� ��    */
	long	debi			;		/* ���ϴ��    */
	char	sign		[ 1];		/* �������    */
	double	debiper			;		/* �����(%)   */
	double	volume			;		/* �� �� ��    */
	double	fore			;		/* �ܱ���      */
	double	ggt				;		/* �����      */
	double	boh				;		/* ����/��Ÿ���� */
	double	tus				;		/* ����        */
	double	bnk				;		/* ����        */
	double	gyg				;		/* �����      */
	double	nat				;		/* ��������ü  */
	double	etc				;		/* ��Ÿ����    */
} TR_01921_TMP;

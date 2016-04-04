/**************************************************************/
/* 01. ���α׷���      : {tr_01932.h}                         */
/* 04. ���α׷����    : {�ð��뺰������}                     */
/**************************************************************/

#define SMAX	13
#define FMAX	14
#define TR01932ROWMAX	15
#define YES		0
#define NO		1
#define tr_01932Inv 12
#define TR_01932    "01932"

typedef struct
{
	char gubun1 [1]; /* '1'�ڽ��� '2'�ڽ��� '3'���� '4'�ݿɼ� '5'ǲ�ɼ� */
	char gubun2 [4]; /* �����ڵ� ; gubun1�� '3','4','5' �̸� Disable    */
	char gubun3 [1]; /* '1'= �ݾ״���  '2'=��������  '3'=�ݾ�(���)     */
} TR_01932_I;

typedef struct {
	char gubun	[10];		/* ���屸��        */

	char medo	[tr_01932Inv][9];
	char mesu	[tr_01932Inv][9];
	char smesu	[tr_01932Inv][9];
} TR_01932_OS;

typedef struct
{
	char	tbllen [6];
	char	tblmsg [50];
	TR_01932_OS tbl;
} TR_01932_O;

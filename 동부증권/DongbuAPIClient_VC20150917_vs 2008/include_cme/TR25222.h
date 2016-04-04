/**************************************************************/
/* 01. ���α׷���      : {tr_25222.h}                         */
/* 02. ��  ��  ��      : {�����}                             */
/* 03. �� �� �� ��     : {2001/05/07}                         */
/* 04. ���α׷����    : {�ð��뺰������}                     */
/* 05. REMARKS ����    : 2005/11 - Modified by St.Choi		  */
/**************************************************************/

//[2522]
//25220 ���� �ϴ� �׸���
//25221 ������ ��Ʈ
//25222 ���� ��� �׸���


#define SMAX	13
#define FMAX	14
#define TR25222ROWMAX	15
#define YES		0
#define NO		1
#define tr_25222Inv 12

typedef struct
{
	char gubun2 [4]; /* �����ڵ� ; gubun1�� '3','4','5' �̸� Disable    */
	char gubun3 [1]; /* '1'= �ݾ״���  '2'=��������  '3'=�ݾ�(���)     */
} TR_25222_I;

typedef struct {
	char gubun	[10];		/* ���屸��        */

	char medo	[tr_25222Inv][9];
	char mesu	[tr_25222Inv][9];
	char smesu	[tr_25222Inv][9];
} TR_25222_T;

typedef struct
{
	char	tbllen [6];
	char	tblmsg [50];
	TR_25222_T tbl;
} TR_25222_O;

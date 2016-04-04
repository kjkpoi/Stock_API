/**************************************************************/
/* 01. 프로그램명      : {tr_01932.h}                         */
/* 04. 프로그램기능    : {시간대별투자자}                     */
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
	char gubun1 [1]; /* '1'코스피 '2'코스닥 '3'선물 '4'콜옵션 '5'풋옵션 */
	char gubun2 [4]; /* 업종코드 ; gubun1이 '3','4','5' 이면 Disable    */
	char gubun3 [1]; /* '1'= 금액단위  '2'=수량단위  '3'=금액(억원)     */
} TR_01932_I;

typedef struct {
	char gubun	[10];		/* 시장구분        */

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

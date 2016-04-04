/**************************************************************/
/* 01. 프로그램명      : {tr_25222.h}                         */
/* 02. 작  성  자      : {김경한}                             */
/* 03. 작 성 일 자     : {2001/05/07}                         */
/* 04. 프로그램기능    : {시간대별투자자}                     */
/* 05. REMARKS 사항    : 2005/11 - Modified by St.Choi		  */
/**************************************************************/

//[2522]
//25220 왼쪽 하단 그리드
//25221 오른쪽 차트
//25222 왼쪽 상단 그리드


#define SMAX	13
#define FMAX	14
#define TR25222ROWMAX	15
#define YES		0
#define NO		1
#define tr_25222Inv 12

typedef struct
{
	char gubun2 [4]; /* 업종코드 ; gubun1이 '3','4','5' 이면 Disable    */
	char gubun3 [1]; /* '1'= 금액단위  '2'=수량단위  '3'=금액(억원)     */
} TR_25222_I;

typedef struct {
	char gubun	[10];		/* 시장구분        */

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

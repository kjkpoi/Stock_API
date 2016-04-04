/**************************************************************/
/* 01. 프로그램명      : {D25221.h}                           */
/* 02. 작  성  자      : {최성태}                             */
/* 03. 작 성 일 자     : {2005.11.16}						  */
/* 04. 프로그램기능    : {투자자별동향- Chart}	  			  */
/* 05. REMARKS 사항    : 									  */
/**************************************************************/
/*#define  tr_25221Max	1000*/
#define  tr_25221Max	800
#define  tr_25221Inv    12

typedef struct
{
	char	code[4];        	/* 업종코드 	*/
	char	gubun[1];			/* 금액(1), 수량(2)	*/
} TR_25221_I;

typedef struct _TR_25221_S
{
  	char    	time	[6];   	/* Time 			*/
	char		soon[12][9];
	char		jisu	[9];	/* KP200 지수		*/
} TR_25221_S;

typedef struct _TR_25221_O
{
  	char    	cht_len [  5]; 	/* cht Count 	*/
	char		cht_bojo[256];
	TR_25221_S	cht[tr_25221Max];
} TR_25221_O;

typedef struct _TR_25221_TMP
{
	int     	time	   ;   	/* Time 			*/
	char		soon[12][9];
	char		jisu	[9];	/* KP200 지수		*/
} TR_25221_TMP;

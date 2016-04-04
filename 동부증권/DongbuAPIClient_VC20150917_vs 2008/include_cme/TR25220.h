/**************************************************************/
/* 01. 프로그램명      : {D25220.h}                           */
/* 04. 프로그램기능    : {투자자별동향- Grid}	  			  */
/* 05. REMARKS 사항    : 									  */
/**************************************************************/

#define  tr_25220Max		19
#define  tr_25220Inv        12
#define  TR_25220			"25220"

typedef struct
{
	char	code	[4];   	/* 업종코드 	*/
	char	gubun	[1];	/* 금액(1), 수량(2), 금액(억원)(3)	*/
	char	next	[7];	/* 다음버튼		*/
} TR_25220_I;

typedef struct _TR_25220_S
{
  	char    	time	[6];   	/* Time 			*/
	char		soon[tr_25220Inv][9];    /* 사모/국가지자체 추가 by KSJ */
} TR_25220_S;

typedef struct _TR_25220_O
{
	char		bt_len[2];		/* Button Bojolen*/
	char		bt_bojo[14];	/* Button Bojodata*/

  	char    	grid_len[6];   	/* Grid Count 	*/
	char		grid_bojo[5];
	TR_25220_S	grid[tr_25220Max];
} TR_25220_O;

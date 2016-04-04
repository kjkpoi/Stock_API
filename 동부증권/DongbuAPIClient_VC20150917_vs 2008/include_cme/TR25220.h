/**************************************************************/
/* 01. ���α׷���      : {D25220.h}                           */
/* 04. ���α׷����    : {�����ں�����- Grid}	  			  */
/* 05. REMARKS ����    : 									  */
/**************************************************************/

#define  tr_25220Max		19
#define  tr_25220Inv        12
#define  TR_25220			"25220"

typedef struct
{
	char	code	[4];   	/* �����ڵ� 	*/
	char	gubun	[1];	/* �ݾ�(1), ����(2), �ݾ�(���)(3)	*/
	char	next	[7];	/* ������ư		*/
} TR_25220_I;

typedef struct _TR_25220_S
{
  	char    	time	[6];   	/* Time 			*/
	char		soon[tr_25220Inv][9];    /* ���/��������ü �߰� by KSJ */
} TR_25220_S;

typedef struct _TR_25220_O
{
	char		bt_len[2];		/* Button Bojolen*/
	char		bt_bojo[14];	/* Button Bojodata*/

  	char    	grid_len[6];   	/* Grid Count 	*/
	char		grid_bojo[5];
	TR_25220_S	grid[tr_25220Max];
} TR_25220_O;

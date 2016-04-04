#if !defined(AFX_TR_20113_HEADER_)
#define AFX_TR_20113_HEADER_

/**************************************************************/
/* 04. 프로그램기능    : {CME선물 미체결}       	   */
/**************************************************************/

#define	TR_FUTCHEGYUL	"20113"
#define tr_20113MAX		300

typedef struct _tr20113_i	
{
	char  geja     [20];    /* 지점번호(3)+계좌번호(8) ->20 */
	char  passwd    [8];	/* 4->8 */
	char  sort      [1];    /* 정순(1) 역순(2)         */

	char  userfld [100];    /* 입력그대로 RETURN       */
} TR_20113_I;


typedef struct _tr_20113_g	
{
	char  juno      [9];    /* 주문번호     5->6->9  */
	char  wonjuno   [9];    /* 원주문번호   5->6->9  */
	char  jgcode    [15];   /* 종목코드     8->15->15 */	
	char  jugb      [12];   /* 주문구분     8->12->12 */
	char  jutype    [12];   /* 주문유형     6->6->12  */
	char  juprc     [12];   /* 주문단가     6->10->12 */
	char  juqty     [15];   /* 주문수량     5->7->15  */
	char  cheprc    [12];   /* 체결가격     6->10->12 */
	char  cheqty    [15];   /* 체결수량     5->7->15  */
	char  nonqty    [15];   /* 미체결       5->7->15  */
	char  denymsg   [40];   /* 세부거부사유       */
} TR_20113_G;

typedef struct _tr_20113_o	
{
	char        userfld [100];             /* 입력그대로 RETURN    */

	char        gridcnt [4];               /* Grid count           */
	char        gridlen [4];               /* Bojo Length          */
	char        gridmsg [5];               /* Grid Bojo Data       */
	TR_20113_G  grid[tr_20113MAX];
} TR_20113_O;

#define  SZ_TR20113_I sizeof(TR_20113_I)
#define  SZ_TR20113_G sizeof(TR_20113_G)
#define  SZ_TR20113_O sizeof(TR_20113_O)


#endif //AFX_TR_20113_HEADER_
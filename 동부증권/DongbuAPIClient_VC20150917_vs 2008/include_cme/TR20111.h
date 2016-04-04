#if !defined(AFX_TR_20111_HEADER_)
#define AFX_TR_20111_HEADER_


/**************************************************************/
/*  프로그램기능    : {CME 선물 체결 }		   *
/**************************************************************/

#define	TR_CMECHEGYUL	"20111"
#define tr_20111MAX		300

typedef struct _tr20111_i	
{
	char  geja     [20];    /* 지점번호(3)+계좌번호(8) ->20 */
	char  passwd    [8];	/* 4->8 */
	char  sort      [1];    /* 정순(1) 역순(2)         */

	char  userfld [100];    /* 입력그대로 RETURN       */
} TR_20111_I;


typedef struct _tr_20111_g	
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
} TR_20111_G;

typedef struct _tr_20111_o	
{
	char        userfld [100];             /* 입력그대로 RETURN    */

	char        gridcnt [4];               /* Grid count           */
	char        gridlen [4];               /* Bojo Length          */
	char        gridmsg [5];               /* Grid Bojo Data       */
	TR_20111_G  grid[tr_20111MAX];
} TR_20111_O;

#define  SZ_TR20111_I sizeof(TR_20111_I)
#define  SZ_TR20111_G sizeof(TR_20111_G)
#define  SZ_TR20111_O sizeof(TR_20111_O)


#endif //AFX_TR_20111_HEADER_
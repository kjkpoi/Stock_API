#if !defined(AFX_TR_13615_HEADER_)
#define AFX_TR_13615_HEADER_

/*************************************************************/
/* 01. 프로그램명      : {tr_13615.h}                        */
/* 03. 작 성 일 자     : {2009/10/28}                        */
/* 04. 프로그램기능    : {선옵 체결리스트}                    */
/* 05. 수  정  자      : {}		                             */
/* 06. 수 정 일 자     : {}     		                     */
/* 07. REMARKS 사항    : {}                                  */
/*************************************************************/
#define	TR_FUTCHEGYUL	"13615"
#define tr_13615MAX		300

typedef struct _tr13615_i	//20080111 EUNSOOK
{
	char  geja     [20];    /* 지점번호(3)+계좌번호(8) ->20 */
	char  passwd    [8];	/* 4->8 */
	char  sort      [1];    /* 정순(1) 역순(2)         */

	char  userfld [100];    /* 입력그대로 RETURN       */
} TR_13615_I;


typedef struct _tr_13615_g	//20080111 EUNSOOK
{
	char  juno      [9];    /* 주문번호     5->6->9  */
	char  wonjuno   [9];    /* 원주문번호   5->6->9  */
	char  jgcode    [15];   /* 종목코드     8->15->15 */
	char  jugb_attr [3];    /* 주문구분속성 3->3->3  */
	char  jugb      [12];   /* 주문구분     8->12->12 */
	char  jutype    [12];   /* 주문유형     6->6->12  */
	char  juprc     [12];   /* 주문단가     6->10->12 */
	char  juqty     [15];   /* 주문수량     5->7->15  */
	char  cheprc    [12];   /* 체결가격     6->10->12 */
	char  cheqty    [15];   /* 체결수량     5->7->15  */
	char  nonqty    [15];   /* 미체결       5->7->15  */
	char  denymsg   [40];   /* 세부거부사유       */
} TR_13615_G;

typedef struct _tr_13615_o	//20080111 EUNSOOK
{
	char        userfld [100];             /* 입력그대로 RETURN    */

	char        gridcnt [4];               /* Grid count           */
	char        gridlen [4];               /* Bojo Length          */
	char        gridmsg [5];               /* Grid Bojo Data       */
	TR_13615_G  grid[tr_13615MAX];
} TR_13615_O;

#define  SZ_TR13615_I sizeof(TR_13615_I)
#define  SZ_TR13615_G sizeof(TR_13615_G)
#define  SZ_TR13615_O sizeof(TR_13615_O)


#endif //AFX_TR_13615_HEADER_
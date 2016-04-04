#if !defined(AFX_TR_13615_HEADER_)
#define AFX_TR_13615_HEADER_

/*************************************************************/
/* 01. ���α׷���      : {tr_13615.h}                        */
/* 03. �� �� �� ��     : {2009/10/28}                        */
/* 04. ���α׷����    : {���� ü�Ḯ��Ʈ}                    */
/* 05. ��  ��  ��      : {}		                             */
/* 06. �� �� �� ��     : {}     		                     */
/* 07. REMARKS ����    : {}                                  */
/*************************************************************/
#define	TR_FUTCHEGYUL	"13615"
#define tr_13615MAX		300

typedef struct _tr13615_i	//20080111 EUNSOOK
{
	char  geja     [20];    /* ������ȣ(3)+���¹�ȣ(8) ->20 */
	char  passwd    [8];	/* 4->8 */
	char  sort      [1];    /* ����(1) ����(2)         */

	char  userfld [100];    /* �Է±״�� RETURN       */
} TR_13615_I;


typedef struct _tr_13615_g	//20080111 EUNSOOK
{
	char  juno      [9];    /* �ֹ���ȣ     5->6->9  */
	char  wonjuno   [9];    /* ���ֹ���ȣ   5->6->9  */
	char  jgcode    [15];   /* �����ڵ�     8->15->15 */
	char  jugb_attr [3];    /* �ֹ����мӼ� 3->3->3  */
	char  jugb      [12];   /* �ֹ�����     8->12->12 */
	char  jutype    [12];   /* �ֹ�����     6->6->12  */
	char  juprc     [12];   /* �ֹ��ܰ�     6->10->12 */
	char  juqty     [15];   /* �ֹ�����     5->7->15  */
	char  cheprc    [12];   /* ü�ᰡ��     6->10->12 */
	char  cheqty    [15];   /* ü�����     5->7->15  */
	char  nonqty    [15];   /* ��ü��       5->7->15  */
	char  denymsg   [40];   /* ���ΰźλ���       */
} TR_13615_G;

typedef struct _tr_13615_o	//20080111 EUNSOOK
{
	char        userfld [100];             /* �Է±״�� RETURN    */

	char        gridcnt [4];               /* Grid count           */
	char        gridlen [4];               /* Bojo Length          */
	char        gridmsg [5];               /* Grid Bojo Data       */
	TR_13615_G  grid[tr_13615MAX];
} TR_13615_O;

#define  SZ_TR13615_I sizeof(TR_13615_I)
#define  SZ_TR13615_G sizeof(TR_13615_G)
#define  SZ_TR13615_O sizeof(TR_13615_O)


#endif //AFX_TR_13615_HEADER_
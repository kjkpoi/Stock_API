
#define		DRCM_CONNECT			-70			//����
#define		DRCM_DISCONNECT			-71			//���� ����
#define		DRCM_SENDDATA			-72			//TR����
#define		DRCM_ADVICE				-73			//�ǽð� ����Ÿ ���
#define		DRCM_UNADVICE			-74			//�ǽð� ����Ÿ �������

#define		DRCM_CLIENT_IP			-75			//���� ������ 
#define		DRCM_F_ACCLIST			-76			//���¸���Ʈ

//20100701 EUNSOOK >>
#define		DRCM_IS_ALIVE			-77			//alive
#define		DRCM_ERR_SOCKET			-78			//���Ͽ���
//20100701 EUNSOOK <<

//20111130 EUNSOOK >>
#define		DRCM_S_ACCLIST			-79			//�ֽİ��¸���Ʈ
#define		DRCM_ALL_ACCLIST		-80			//����,�ֽİ��¸���Ʈ
//20111130 EUNSOOK <<

#define		DRCM_DRDS_DATA			-700		//�ǽð� ����Ÿ RECEIVE

#define		DRCM_MSG_LOGINFAIL		  -1		//�α��� ����
#define		DRCM_MSG_SOCKETFAIL		  -2		//���� ���� ����
#define		DRCM_MSG_RESTART		  -3		//������

#define		SIZE_TRCODE				5			//TR CODE ���� ����
#define		SIZE_RTCODE				3			//�ǽð� CODE ���� ����


#define		DRCM_RISK_AGREEMENT		700	   	    //������� ����

#define		TR_20000			"20000"		//�ֹ�
#define		TR_RISK_AGREEMENT	"20010"
#define		TR_20030			"20030"		//�����ֹ�
#define		TR_20020			"20020"		//�ֽ��ֹ�
#define		TR_13655			"13655"		//�ܰ���ȸ
#define		TR_13615			"13615"		//ü�᳻����ȸ
#define		TR_15813			"15813"		//����Ȳ��ȸ
#define		TR_13653			"13653"		//������ �� �ֹ����ɱݾ� ��ȸ
#define		TR_16260			"16260"		//�ɼ����񺰸ŵ����ű�
#define		TR_14051			"14051"		//�ű�/û�� ���ɼ���


#define		TR_13118			"13118"  //�ֽ�ü��
#define		TR_13148			"13148"  //�ֽ��ܰ�
#define		TR_STOCKEVAL		"20051"	 //����Ȳ��ȸ

//DRCM �� �����ϱ� ���� ����ü
typedef struct {		
	HWND		hClientWnd;			// �����͸� ���� ���	
	char		szUserId[20];		// �α��� ���̵�
	char		szPwd[20];			// �α��� �н�����	
	char		szCertPwd[20];		// �������� �н�����	
	BOOL		bShowLoginDlg ;		// �α���â�� �����ٰ�����
	
} ST_DRCM_USER ;




//------------------------------------------------------------------------------------------
// �ֹ����� ���� INPUT HEADER & OUTPUT STRUCTURES
//------------------------------------------------------------------------------------------
typedef struct _TRORDER_I
{
	char    incnt    [ 4];      /* �ֹ� cnt								*/
	char    mapno    [ 5];      /* TR����ϴ� Map��ȣ					*/
} TR_ORDER_I;

typedef struct _TRORDER_O
{
	char    outcnt   [ 4];       /* �ֹ� cnt                  */
} TR_ORDER_O;

#define SZ_ORDER_O     sizeof(TR_ORDER_O)

typedef struct _TRORDER_OS
{
	char	clikey   [ 8];      /* �ֹ� key                  */
	char    juno     [ 9];      /* �ֹ���ȣ                  */
	char    msgcd    [ 6];      /* �޽����ڵ�                */
	char    msgcm   [100];      /* ó���޽���                */
} TR_ORDER_OS;

#define SZ_ORDER_OS     sizeof(TR_ORDER_OS)

/*-----------------------------------------------------------*/
/* �����ɼ� �ֹ�				                             */
/*-----------------------------------------------------------*/
typedef struct _TR20030_IS
{
	char	clikey   [ 8];      /* �ֹ� key								*/
	char	gb       [ 1];      /* 1:�ŵ�, 2:�ż�, 3:����, 4:���		*/
	char    geja     [20];      /* ���¹�ȣ								*/
	char    passwd   [ 8];      /* ��й�ȣ								*/
	char    code     [15];      /* �����ڵ�								*/
	char    wonno    [ 9];      /* ���ֹ���ȣ							*/
	char    jutype   [ 2];      /* ȣ�������ڵ�							*/
								/* 00:����,03:����,05:���Ǻ�,06:������	*/
	char    juprc    [12];      /* �ֹ����� S9(9).99					*/
	char    qty      [15];      /* �ֹ����� S9(15)						*/
	char    ip       [16];      /* Ŭ���̾�Ʈ IP�ּ�(��: 192009101031)	*/
} TR_20030_IS;

#define SZ_FUTURE_IS     sizeof(TR_20030_IS)

/*-----------------------------------------------------------*/
/* �ֽ� �ֹ�				                             */
/*-----------------------------------------------------------*/
typedef struct _TR20020_IS
{
	char	clikey     [ 8];   /* �ֹ� key								     */
	char	gb         [ 1];   /* 1:�ŵ�, 2:�ż�, 3:����, 4:���		     */
	char    geja       [20];   /* ���¹�ȣ								     */
	char    passwd     [ 8];   /* ��й�ȣ								     */
	char    code       [15];   /* �����ڵ�								     */
	char    wonno      [ 9];   /* ���ֹ���ȣ							     */
	char    jutype     [ 2];   /* ȣ�������ڵ�							     */
							   /* 00:����,03:����,05:���Ǻ�,06:������	     */
	char    juprc      [12];   /* �ֹ����� S9(9).99					         */
	char    qty        [15];   /* �ֹ����� S9(15)						     */
	char    zMgntrnCode[ 3];   /* �ſ�ŷ��ڵ�                               */
	                           /* 000:���� 001:�������ڽű� 003:�ڱ����ڽű� */
	                           /* 007:�ڱ���ֽű� 101:�������ڻ�ȯ          */
	                           /* 103:�ڱ����ڻ�ȯ 107:�ڱ���ֻ�ȯ          */
	                           /* 180:��Ź�㺸�����ȯ(�ſ�)                 */
	char    zLoanDt    [ 8];   /* ��������                                   */
	char    ip         [16];   /* Ŭ���̾�Ʈ IP�ּ�(��: 192009101031)        */
} TR_20020_IS;

#define SZ_STOCK_IS     sizeof(TR_20020_IS)

typedef struct
{
	int  m_nRow ;
	int  m_nTrIndex ;
	int	 m_nOrderNo ;
	int	 m_nOrgOrderNo ;	
}ST_ORDERINFO;


//=======================================================================================
// �ܰ���ȸ
//=======================================================================================
#define tr_13655MAX 250

typedef struct 
{
	char  geja     [20];    /* ������ȣ(3)+���¹�ȣ(8) ->20 */
} TR_13655_I;


typedef struct 	
{
	char  yakjungtot [17];  /* ��   �����ݾ�                    */
	char  pyungpltot [17];  /* ��   �򰡼���                    */
	char  jumuntot   [17];  /* �ֹ������Ѿ�                     */

	char  amotpyngtot[17];  /* ��   �򰡱ݾ�                    */
	char  realpltot  [17];  /* ���� ��������                    */
	char  jumuncash  [17];  /* �ֹ���������                     */
	char  suikratetot[ 9];  /* ��   ������   7->9               */

} TR_13655_S;

typedef struct 
{
	char  jocode     [15];  /* �����ڵ�                8 -> 15  */
	char  mmgb_attr  [ 3];  /* �Ÿű���                3 ->  3  */
	char  mmgb       [ 5];  /* �Ÿű���                5 ->  5  */

	char  avqty      [15];  /* û�갡��                9 -> 15  */
	char  pnonqty    [15];  /* �����ܰ�                9 -> 15  */
	char  qtychg     [15];  /* ����                    9 -> 15  */
	char  tnonqty    [15];  /* ��������                9 -> 15  */
	char  tnocontqty [15];  /* ��ü���ֹ�����          9 -> 15  */

	char  tnonprc    [12];  /* ���Դܰ�               12 -> 12  */
	char  price      [ 6];  /* ���簡                  6 ->  6  */
	char  pyungpl    [15];  /* �򰡼���               15 -> 15  */
	char  suikrate   [ 9];  /* ������                  9 ->  9  */

	char  tnonamt    [15];  /* �����ݾ�               15 -> 15  */
	char  pyungamt   [15];  /* �򰡱ݾ�               15 -> 15  */
	char  fee        [12];  /* ������                 12 -> 12  */

	char  bid        [ 6];  /* �ż�ȣ��                6 ->  6  */
	char  offer      [ 6];  /* �ŵ�ȣ��                6 ->  6  */
	char  hprice     [ 6];  /* ���Ѱ�                  6 ->  6  */
	char  lprice     [ 6];  /* ���Ѱ�                  6 ->  6  */

	char  gdssect    [ 1];  /* ����Ҽӱ���            1 ->  1  */
	char  resbpl     [15];  /* ���Ͻ�������           15 -> 15  */
	char  jutp       [ 3];  /* �ֹ�����                3 ->  3  */
	char  trdunt     [15];  /* �ŷ�����               15 -> 15  */
	char  tdmemeamt  [15];  /* ���ϸż��Ǵ¸ŵ��ݾ�   15 -> 15  */
	char  memeamt    [15];  /* �ŸŴ����             15 -> 15  */
} TR_13655_G;

typedef struct 	
{
	TR_13655_S		sm;

	char  gridcnt    [  4]; // Grid count
	TR_13655_G  gr[tr_13655MAX];
	
} TR_13655_O;


//=======================================================================================
// ü�� ���� ��ȸ
//=======================================================================================
#define tr_13615MAX 300
typedef struct 
{
	char  geja     [20];    /* ������ȣ(3)+���¹�ȣ(8) ->20 */
	char  passwd    [8];	/* 4->8 */
	char  sort      [1];    /* ����(1) ����(2)         */
	char  userfld [100];    /* �Է±״�� RETURN       */
} TR_13615_I;


typedef struct 
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

typedef struct 
{
	char        userfld [100];             /* �Է±״�� RETURN    */

	char        gridcnt [4];               /* Grid count           */
	char        gridlen [4];               /* Bojo Length          */
	char        gridmsg [5];               /* Grid Bojo Data       */
	TR_13615_G  grid[tr_13615MAX];
} TR_13615_O;

//ü�᳻�� <<

//=======================================================================================
// ������ ��ȸ
//=======================================================================================
typedef struct
{
	char        accno [20];			//���¹�ȣ
	char        pass [18];			//�Էº�й�ȣ
	char        date [8];			//�ֹ���
	char        ip_addr [16];		//privateip
} TR_13653_I;

typedef struct
{
	char        data1 [15]; //�򰡿�Ź���Ѿ�
	char        data2 [16]; //�ֹ����ɱݾ�
	char        fee   [16]; //������
} TR_13653_O;



//����Ȳ >>
typedef struct
{
	char        accno [20];			//���¹�ȣ
	char        pass [8];			//�Էº�й�ȣ
	char        date [8];			//�ֹ���

	char        janggubun [1];		//�ܰ��򰡱��� #0:�⺻����1:�̵���չ�2:���Լ���� (������ '0'�� ���)
	char        futuregubun [1];	//���������򰡱���  #2:��������1:���ʰ�
	char        ip_addr [16];		//privateip
	char		nxtKey [19];		//����Ű:0 :O_SETCONTBTNKEY    -> ���� 19����Ʈ
} TR_15813_I;


typedef struct
{
	char        data11 [15]; //��Ź���Ѿ�
	char        data12 [15]; //��Ź����
	char        data13 [15]; //��Ź���

	char        data21 [15]; //��Ź���ű��Ѿ�
	char        data22 [15]; //������Ź���űݾ�
	char        data23 [14]; //�������ű��Ѿ�
	char        data24 [15]; //�����������űݾ�

	char        data31 [14]; //�߰����ű��Ѿ�
	char        data32 [15]; //�����߰����űݾ�
	char        data33 [14]; //�ֹ������ѱݾ�
	char        data34 [15]; //�����ֹ����ɱݾ�

	char        data41 [14]; //���Ⱑ���ѱݾ�
	char        data42 [15]; //���Ⱑ�����ݾ�

	char		nxtKey [19];  //����Ű:0 :O_SETCONTBTNKEY    -> ���� 19����Ʈ

} TR_15813_O;
//����Ȳ <<

//�ɼ� ���� ���ű�
typedef struct
{
	char        itemcode [2];			//��ǰ���ڵ�
	char        baseassetcode [3];		//�����ڻ��ڵ�
	char        month [1];				//�ֱٿ�������
	char        ip_addr[16];			//privateip
	char		nxtKey [19];			//����Ű:0 :O_SETCONTBTNKEY    -> ���� 19����Ʈ
} TR_16260_I;

typedef struct
{
	char        exeprice [13]; //��簡

	char        jongmok_C [32];		//C�����ɼǰ��������ȣ
	char        name_C [40];		//C���и�
	char        theoryprice_C [19]; //C�̷а�
	char        baseprice_C [13];	//C���ذ�
	char        deposit_C [16];		//C�ֹ����ű�

	char        jongmok_P [32];		//P�����ɼǰ��������ȣ
	char        name_P [40];		//P���и�
	char        theoryprice_P [19]; //P�̷а�
	char        baseprice_P [13];	//P���ذ�
	char        deposit_P [16];		//P�ֹ����ű�
	
} TR_16260_OS;

//�ű�/û�� ���� ����
typedef struct
{
    char    geja		[20];		/* ���¹�ȣ */ //11->20
    char    passwd		[ 8];       /* ��й�ȣ */
	char    jcode		[12];		/* �����ڵ� 8 + 7space */ //15->32  32--> 12
    char    gb			[ 1];		/* �Ÿű���  1:�ŵ� 2:�ż� */
	char    price		[12];		/* �ֹ����� */ //9->12
    char    ord_type	[ 2];       /* �ֹ�����  1:������ 2:���尡 3:���Ǻ������� 4:������������*/ //1->2
	char    zLqdtQtyQryTp [ 1];     /* û����� ��ȸ���� : ���δ� 1 */
    char    ip			[16];       /* Ŭ���̾�Ʈ IP�ּ�(��:192009101031)*/	
} TR_14051_I;

typedef struct
{
	char    newqty		[15];		/* �ű��ֹ����� ���� */ //7->15
    char    clearqty	[15];		/* û�갡�� ���� */ //7->15
} TR_14051_O;


/*-----------------------------------------------------------*/
/* TrNo: 20000 ��Ŷ			                                 */
/*-----------------------------------------------------------*/

typedef struct
{
    char    incnt    [ 4];       /* �ֹ� cnt                 */
    char    mapno    [ 5];       /* TR����ϴ� Map��ȣ       */
} TR_20000_I;

typedef struct
{
    char    clikey   [ 8];      /* �ֹ� key                                 */
    char    gb       [ 1];      /* 1:�ŵ�, 2:�ż�,  3:����, 4:���          */
    char    geja  [20];      /* ���¹�ȣ                                 */
    char    passwd [ 8];      /* ��й�ȣ                                 */
    char    code[15];      /* �����ڵ�                                 */
    char    wonno[ 9];      /* ���ֹ���ȣ   S9(9)                       */
    char    jutype [ 2];  /* �����ɼ�ȣ�������ڵ�                */
                                /* 00:������ 03:���尡 05:���Ǻ�������      */
                                /* 06:������������                          */
    char    juprc  [12];      /* �ֹ���     S9(9).99 ->�Ҽ�������         */
    char    qty  [15];      /* �ֹ�����   S9(15)                        */
    char    ip       [16];      /* Ŭ���̾�Ʈ IP�ּ�(��: 192009101031)      */
} TR_20000_IS; //106

typedef struct 
{
    char    outcnt   [ 4];       /* �ֹ���ȣ cnt              */
} TR_20000_O;

typedef struct
{
    char    clikey   [ 8];       /* �ֹ� key                  */
    char    lOrdNo   [ 9];       /* �ֹ���ȣ   S9(9)          */
    char    msgcd    [ 6];       /* �޽����ڵ�                */
    char    msgcm   [100];       /* ó���޽���                */
} TR_20000_OS;






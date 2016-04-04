
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
#define		TR_13118			"13118"		//�ֽ�ü��
#define		TR_13148			"13148"		//�ֽ��ܰ�
#define		TR_STOCKEVAL		"20051"		//����Ȳ��ȸ

//20120109 EUNSOOK >>
#define		TR_15812			"15812"		//����(����)�ܰ���
//20120109 EUNSOOK <<

//20130219 EUNSOOK >>
#define		TR_20001			"20001"		//CME���� �ֹ�

#define		TR_26011			"26011"		//CME���� �ű�/û�� ���ɼ���

#define		TR_20110			"20110"		//CME���� �ǽð� �ܰ���ȸ
#define		TR_20111			"20111"		//CME���� �ǽð� ü��
#define		TR_20113			"20113"		//CME���� �ǽð� ��ü��
#define		TR_20112			"20112"		//CME���� ��������Ȳ


#define		TR_14055			"14055"		//�ֽ�-�ű�/û�� ���ɼ���
//20130219 EUNSOOK <<

//20130219 EUNSOOK >>
#define		TR_13147			"13147"		//�ֽĽǽð��ܰ�2
//20130219 EUNSOOK <<


//DRCM �� �����ϱ� ���� ����ü
typedef struct {		
	HWND		hClientWnd;			// �����͸� ���� ���	
	char		szUserId[20];		// �α��� ���̵�
	char		szPwd[20];			// �α��� �н�����	
	char		szCertPwd[20];		// �������� �н�����	
	BOOL		bShowLoginDlg ;		// �α���â�� �����ٰ�����
	
} ST_DRCM_USER ;


//
///*-----------------------------------------------------------*/
///* �����ɼ� �ֹ�				                             */
///*-----------------------------------------------------------*/
//typedef struct _TR20030_IS
//{
//	char	clikey   [ 8];      /* �ֹ� key								*/
//	char	gb       [ 1];      /* 1:�ŵ�, 2:�ż�, 3:����, 4:���		*/
//	char    geja     [20];      /* ���¹�ȣ								*/
//	char    passwd   [ 8];      /* ��й�ȣ								*/
//	char    code     [15];      /* �����ڵ�								*/
//	char    wonno    [ 9];      /* ���ֹ���ȣ							*/
//	char    jutype   [ 2];      /* ȣ�������ڵ�							*/
//								/* 00:����,03:����,05:���Ǻ�,06:������	*/
//	char    juprc    [12];      /* �ֹ����� S9(9).99					*/
//	char    qty      [15];      /* �ֹ����� S9(15)						*/
//	char    ip       [16];      /* Ŭ���̾�Ʈ IP�ּ�(��: 192009101031)	*/
//} TR_20030_IS;
//
//#define SZ_FUTURE_IS     sizeof(TR_20030_IS)
//
///*-----------------------------------------------------------*/
///* �ֽ� �ֹ�				                             */
///*-----------------------------------------------------------*/
//typedef struct _TR20020_IS
//{
//	char	clikey     [ 8];   /* �ֹ� key								     */
//	char	gb         [ 1];   /* 1:�ŵ�, 2:�ż�, 3:����, 4:���		     */
//	char    geja       [20];   /* ���¹�ȣ								     */
//	char    passwd     [ 8];   /* ��й�ȣ								     */
//	char    code       [15];   /* �����ڵ�								     */
//	char    wonno      [ 9];   /* ���ֹ���ȣ							     */
//	char    jutype     [ 2];   /* ȣ�������ڵ�							     */
//							   /* 00:����,03:����,05:���Ǻ�,06:������	     */
//	char    juprc      [12];   /* �ֹ����� S9(9).99					         */
//	char    qty        [15];   /* �ֹ����� S9(15)						     */
//	char    zMgntrnCode[ 3];   /* �ſ�ŷ��ڵ�                               */
//	                           /* 000:���� 001:�������ڽű� 003:�ڱ����ڽű� */
//	                           /* 007:�ڱ���ֽű� 101:�������ڻ�ȯ          */
//	                           /* 103:�ڱ����ڻ�ȯ 107:�ڱ���ֻ�ȯ          */
//	                           /* 180:��Ź�㺸�����ȯ(�ſ�)                 */
//	char    zLoanDt    [ 8];   /* ��������                                   */
//	char    ip         [16];   /* Ŭ���̾�Ʈ IP�ּ�(��: 192009101031)        */
//} TR_20020_IS;

#define SZ_STOCK_IS     sizeof(TR_20020_IS)


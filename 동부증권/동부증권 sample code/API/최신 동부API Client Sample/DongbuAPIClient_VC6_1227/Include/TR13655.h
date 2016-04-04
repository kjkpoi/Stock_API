#if !defined(AFX_TR_13655_HEADER_)
#define AFX_TR_13655_HEADER_


/*************************************************************/
/* 01. ���α׷���      : {tr_13655.h}                        */
/* 03. �� �� �� ��     : {2009/10/28}                        */
/* 04. ���α׷����    : {���� �ܰ�}						 */
/* 05. ��  ��  ��      : {}		                             */
/* 06. �� �� �� ��     : {}     		                     */
/* 07. REMARKS ����    : {}                                  */
/*************************************************************/
#define	TR_FUTJANGO		"13655"
#define	TR_FUTEVAL		"15813"
#define	TR_FUTFEE		"13653"

#define tr_13655MAX		250

typedef struct _TR_13655_I	
{
	char  geja     [20];    /* ������ȣ(3)+���¹�ȣ(8) ->20 */
} TR_13655_I;

typedef struct _TR_13655_S	
{
	char  yakjungtot [17];  /* ��   �����ݾ�                    */
	char  pyungpltot [17];  /* ��   �򰡼���                    */
	char  jumuntot   [17];  /* �ֹ������Ѿ�                     */

	char  amotpyngtot[17];  /* ��   �򰡱ݾ�                    */
	char  realpltot  [17];  /* ���� ��������                    */
	char  jumuncash  [17];  /* �ֹ���������                     */
	char  suikratetot[ 9];  /* ��   ������   7->9               */

} TR_13655_S;

typedef struct _TR_13655_G	
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

typedef struct _tr_13655_o
{
	TR_13655_S		sm;
	char  gridcnt    [  4]; // Grid count
	TR_13655_G  gr[tr_13655MAX];

} TR_13655_O;

#define  SZ_TR13655_I sizeof(TR_13655_I)
#define  SZ_TR13655_G sizeof(TR_13655_G)

//=======================================================================================
// ���ɽǽð��ܰ� ��������ȸ
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


//=======================================================================================
//# title : 15813 �����ܰ� �� ����Ȳ(�ڵ��ֹ� ��)
//=======================================================================================
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



#endif //AFX_TR_13655_HEADER_
/****************************************************************/
/* 01. ���α׷���      : {tr_04012.h}                         	*/
/* 02. ��  ��  ��      : {�̱ٿ�}                             	*/
/* 03. �� �� �� ��     : {2002/09/13}                         	*/
/* 04. ���α׷����    : {�������簡-B2(��/ü��)}           	*/
/* 05. REMARKS ����    : {}    		  						  	*/
/****************************************************************/

// 20120723 ssj - �����ڵ��ֹ� >>
#define TR_04012	"04012"
// 20120723 ssj - �����ڵ��ֹ� <<

#define  TR04012GridMAX			10

typedef struct
{
	char sCode      [8];    /* �����ڵ�    				        */
} TR_04012_I;

typedef struct {
    char offersu    [4];    /* 1�켱 �ŵ�ȣ���Ǽ�       		*/
    char offerjan   [7];    /* 1     �ŵ�     �ܷ�      		*/
    char offer      [6];    /* 1     �ŵ�ȣ��           		*/
    char bid        [6];    /* 1     �ż�ȣ��           		*/
    char bidjan     [7];    /* 1     �ż��ܷ�           		*/
    char bidsu      [4];    /* 1�켱 �ż�ȣ���Ǽ�       		*/
    char joffersu   [4];    /* 2���� �ŵ�ȣ���Ǽ�       		*/
    char jofferjan  [7];    /* 2���� �ŵ�ȣ�� �ܷ�      		*/
    char joffer     [6];    /* 2���� �ŵ�ȣ��           		*/
    char jbid       [6];    /* 2���� �ż�ȣ��           		*/
    char jbidjan    [7];    /* 2���� �ż�ȣ�� �ܷ�      		*/
    char jbidsu     [4];    /* 2���� �ż�ȣ���Ǽ�       		*/
    char jjoffersu  [4];    /* 3���� �ŵ�ȣ���Ǽ�       		*/
    char jjofferjan [7];    /* 3���� �ŵ�ȣ�� �ܷ�      		*/
    char jjoffer    [6];    /* 3���� �ŵ�ȣ��           		*/
    char jjbid      [6];    /* 3���� �ż�ȣ��           		*/
    char jjbidjan   [7];    /* 3���� �ż�ȣ�� �ܷ�      		*/
    char jjbidsu    [4];    /* 3���� �ż�ȣ���Ǽ�       		*/
    char j4offersu  [4];    /* 4���� �ŵ�ȣ���Ǽ�       		*/
    char j4offerjan [7];    /* 4���� �ŵ�ȣ�� �ܷ�      		*/
    char j4offer    [6];    /* 4���� �ŵ�ȣ��           		*/
    char j4bid      [6];    /* 4���� �ż�ȣ��           		*/
    char j4bidjan   [7];    /* 4���� �ż�ȣ�� �ܷ�      		*/
    char j4bidsu    [4];    /* 4���� �ż�ȣ���Ǽ�       		*/
    char j5offersu  [4];    /* 5���� �ŵ�ȣ���Ǽ�       		*/
    char j5offerjan [7];    /* 5���� �ŵ�ȣ�� �ܷ�      		*/
    char j5offer    [6];    /* 5���� �ŵ�ȣ��           		*/
    char j5bid      [6];    /* 5���� �ż�ȣ��           		*/
    char j5bidjan   [7];    /* 5���� �ż�ȣ�� �ܷ�      		*/
    char j5bidsu    [4];    /* 5���� �ż�ȣ���Ǽ�       		*/
    char toffersu   [5];    /* �Ѹŵ�ȣ���Ǽ�           		*/
    char tofferjan  [7];    /* �Ѹŵ�ȣ�� �ܷ�          		*/
    char remngap    [7];    /* �ܷ���                           */
    char tobidjan   [7];    /* �Ѹż� ȣ�� �ܷ�         		*/
    char tbidsu     [5];    /* �Ѹż�ȣ���Ǽ�           		*/
} TR_04012_h;

typedef struct {
    char fuopen     [6];    /* �ð�                 9(3)v9(2)  */
    char fuopen_chg [6];    /* �ð����             9(3)v9(2)  */
    char theoryprice[6];    /* �̷а�               9(3)v9(2)  */

    char fuhigh     [6];    /* ��                 9(3)v9(2)  */
    char fuhigh_chg [6];    /* �����             9(3)v9(2)  */
    char gyrirate   [6];    /* ������               9(3)v9(2)  */

    char fulow      [6];    /* ����                 9(3)v9(2)  */
    char fulow_chg  [6];    /* �������             9(3)v9(2)  */
    char cbhprice   [8];    /* CB����                S9(3)v9(4)  */

    char openyak    [6];    /* �̰�����������       9(6)       */
	char open_1     [6];    /* ����-���� �̰�����������        */
	char cblprice   [8];    /* CB����                S9(3)v9(4)  */

    char hprice     [6];    /* ���Ѱ�               9(3)v9(2)  */
    char lprice     [6];    /* ���Ѱ�               9(3)v9(2)  */
    char baseprice  [8];    /* ���ذ�               S9(3)v9(4)  */

	char listhprice [6];    /* ������ �ְ� */
	char listhdate  [8];    /* ������ �ְ��� */
	char spread     [6];    /* ��������             9(3)v9(2)  */

	char listlprice [6];    /* ������ ������ */
	char listldate  [8];    /* ������ �������� */
	char jandatecnt [4];    /* �����ϼ�             9(4)       */
} TR_04012_fp;

typedef struct {
    char opopen     [6];    /* �ð�                 9(3)v9(2)  */
    char opopen_chg [6];    /* �ð����             9(3)v9(2)  */
    char theoryprice[6];    /* �̷а�               9(3)v9(2)  */

    char ophigh     [6];    /* ��                 9(3)v9(2)  */
    char ophigh_chg [6];    /* �����             9(3)v9(2)  */
    char gyrirate   [6];    /* ������               9(3)v9(2)  */

    char oplow      [6];    /* ����                 9(3)v9(2)  */
    char oplow_chg  [6];    /* �������             9(3)v9(2)  */
    char delta      [8];    /* ��Ÿ                S9(3)v9(4)  */

    char openyak    [6];    /* �̰�����������       9(6)       */
	char open_1     [6];    /* ����-���� �̰�����������        */
	char gmma       [8];    /* ����                S9(3)v9(4)  */

    char hprice     [6];    /* ���Ѱ�               9(3)v9(2)  */
    char lprice     [6];    /* ���Ѱ�               9(3)v9(2)  */
    char theta      [8];    /* ��Ÿ                S9(3)v9(4)  */

	char listhprice [6];    /* ������ �ְ� */
	char listhdate  [8];    /* ������ �ְ��� */
	char impv       [6];    /* ���纯����           9(3)v9(2)  */

	char listlprice [6];    /* ������ ������ */
	char listldate  [8];    /* ������ �������� */
	char jandatecnt [4];    /* �����ϼ�             9(4)       */
} TR_04012_op;

typedef struct {
	char sign       [1];    /* �����ȣ    							*/
	char time       [6];    /* �ð�        							*/
	char curr       [6];    /* ���簡      							*/
	char change     [6];    /* ���Ϻ�      							*/
	char msuvol   	[9];    /* �ż�ü����� 						*/
	char mdovol   	[9];    /* �ŵ�ü����� 						*/
	char volall   	[9];    /* �����ŷ���   						*/
} TR_04012_G;

typedef struct 
{
/*	char impv		[6]; */
	char baseprice  [6];    /* ���ذ� (2002.02.27�߰�)       - ���� */

	char nextfucode [8] ; 	/* ������(����ȸ���� �����ڵ�)   - ���� */
    char nextfucurr [6] ; 	/* ������ ���簡                 - ���� */

    char curr   	[6] ; 	/* ����/�ɼ� ���簡              - ���� */

    char tbllen     [6];    /* 0001xx 								*/ 
    char tblmsg     [5];    /* "UM=E@" 								*/
	TR_04012_h      hoga;

    char tbllen2    [6];    /* 0001xx 								*/
    char tblmsg2    [5];    /* "UM=E@" 								*/
	TR_04012_fp 	fprice;

    char tbllen3    [6];    /* 0001xx 								*/
    char tblmsg3    [5];    /* "UM=E@" 								*/
	TR_04012_op 	oprice;

	char gridlen    [4+2];  /* Grid Row + Bojo Length 				*/
	char gridbojo   [4];    /* "UM=E" Setting 						*/ 
	TR_04012_G 		grid [TR04012GridMAX];
} TR_04012_O;


#define LEN_ACCOUNT		11  //���¹�ȣ ����
#define LEN_ITEMCODE	8   //�����ڵ� ����
#define LEN_ITEMNAME	20   //����� ����

#define LEN_ACCPASS		8   //���� �����ȣ ����
#define LEN_USERID		20  //����� ID ����
#define LEN_ORDPRICE	20  //�ֹ� ���� ����
#define LEN_MAXEXP		80  //���ǰ��� Max
#include "StdAfx.h"

#define LEN_MAXCONDCOUNT 20

#define TR_SET_ENV				"77010" // ��ü���� ���
#define TR_SET_COND				"77020"	// �������� ���

#define TR_REQ_COND_LIST		"77030"	// ���Ǹ���Ʈ ��ȸ
#define TR_REQ_COND_DETAIL		"77040"	// �������� �� ��ȸ
#define TR_REQ_ENV				"77080" // ��ü���� ��ȸ
#define TR_AGREE				"20019" // ����ڵ���
#define TR_CHANGE_ALL			"77130" // ��ü����,��ü����,��ü����,��ü����

#define		TR10112		"10112"			// �ֹ�ȣ������
#define		TR12151		"12151"			// �ſ���¿��� ��ȸ
#define		TR_14055	"14055"			// �ֽļ��� ���ɼ��� ��ȸ
#define		TR_14051	"14051"			// ���� ���ɼ��� ��ȸ


#define REALNUM_HOGA_STOCK 0x30


#define HEIGHT_TAB_ITEM		25
#define HEIGHT_GRID			100

#include "Condition_MngDef.h"

typedef struct _INPUT_TR_CHANGE_ALL
{
	char sJobFlag	             [1];             // I:���, D:����, S:���� R: ����
	char sMktGbn	               [1];           // ���屸�� S:�ֽ�,ELW, F:��������, �ֽļ���
	char sAcct 	               [12];            // ���¹�ȣ
	char sExpireDate   	       [8];             // ���� ��ȿ�Ⱓ(YYYYMMDD)
	char sPswd         	       [40];            // ���º�й�ȣ
	char sUserID       	       [20];            // HTS User ID
	char sMassId	               [3];           // HTS, Mobile ����
	char sMFlag        	       [1];             // ���ڵ� Flag  '0':�ڵ�, '1':���ڵ�
	char sOrdKind      	       [1];             // �ֹ� ���� '1':�Ϲ��ֹ�  '2':ȣ�������ֹ�   '3':�ð������ֹ�
	char sOrdCnt       	       [1];             // ����Ƚ�� (MAX = 5)  1 : �Ϲ��ֹ� n : ȣ��/�ð������ֹ�
	char sInterval     	       [2];             // �ð����� �ֹ��� �ֹ� Interval (5 ~ 60)
	char sOrdGb        	       [1];             // �ֹ�����  '1':������, '2':���尡  '3':������������, '4':�ֿ켱������ '5':�ż�1ȣ��,    '6':�ż�2ȣ��   '7':�ŵ�1ȣ��,    '8':�ŵ�2ȣ�� '9':���Ǻ������� 'A':������(IOC) 'B':���尡(IOC) 'C':������(IOC) 'D':������(FOK) 'E':���尡(FOK) 'F':������(FOK)
	char sQtyGb        	       [1];             // ���� �Է±��� (2010.10.01 �߰�)  '1':���������Է�, '2':��з��� �Է�
	char sOrdBaseQty   	       [10];            // ���ؼ���
	char sOrdRegQty	           [10][10];    // �ֹ�����(���� or �����)
	char sOrdRegPrc    	       [20];            // �ŵ�1/2/3ȣ�� �ż�1/2/3ȣ�� ���簡, ���Ѱ� ���Ѱ�
	char sCondFlag     	       [1];             // ���Ǳ��� '1' : �Ϲ�����(����/�ü�/...) '2' : ���������
	char sTargCnt      	       [2];             // ���Ǽ� (�ִ� 20��)
	char sTargExp      	       [80];            // ���ǰ���(ǥ����)
//	char sCode     	           [(4*9)36];       // ���� Check�� ���Ǵ����� (4������)  ���屸��(1) + �����ڵ�(8) S(STOCK),E(ELW)
	char szCode1[9];							//���屸��(1) + �����ڵ�(8)                                                                                                                                                                                                                                       
	char szCode2[9];							//���屸��(1) + �����ڵ�(8)                                                                                                                                                                                                                                       
	char szCode3[9];							//���屸��(1) + �����ڵ�(8)                                                                                                                                                                                                                                       
	char szCode4[9];							//���屸��(1) + �����ڵ�(8)                                                                                                                                                                                                                                       
	char sDestTime     	       [6];             //  �����ð� �ֹ��� ���� �ð�
	char sDestONTime	           [6];         // ��/�� �������� ���� �����ð� (HHMMSS)
	char sDivGb        	       [1];             // ���ұ��� : 0:���迭,   1:��迭, 2:���迭
	char sDivDir       	       [1];             // ���ҹ��� : 0:�ż�����, 1:�ŵ�����
	char sPcIp  	               [15];        // �缳IP format : 999.999.999.999  (15�ڸ����)
	char sAvgPrcFlag	           [1];         // ��ո��Դܰ� �÷��� : 0:��������, 1:����
	char sAvgPrc	               [15];        // ��ո��Դܰ�
	User_Define			stUser_Define[20];      // ���� (ȭ�� �ϴܿ� �󼼳��� ����) ����1��Size(81) * ���Ǽ�(20)
	char sFiller	               [64];        // filler
} INPUT_TR_CHANGE_ALL;

typedef struct _OUTPUT_TR_CHANGE_ALL
{
	char sJobFlag      [1]; // I:���, U:����, D:����  
	char sRetVal       [1]; // 'S' : ����, 'F' : ����
} OUTPUT_TR_CHANGE_ALL;

typedef struct _TR_ORDER_REGIN                                                                                                                                                                                                                                                              
{                                                                                                                                                                                                                                                                                           
	char cJobFlag      [1];   // I:���, U:����, D:����, S:���� R: ����                                                                                                                                                                                                                       
	char szAccount         [12];  // ���¹�ȣ                                                                                                                                                                                                                                                 
	char szShcode       [8];   // �����ڵ�                                                                                                                                                                                                                                                    
	char szMMType         [1];   // �Ÿű���     '1':�ŵ�, '2':�ż�                                                                                                                                                                                                                           
	char szCredit         [1];   // "�ſ뱸��     '0':����, '1':�������ڽű�, '2':�ڱ����ڽű�, '3':�������, '4':�ڱ���ֽű�, '5':�������ڻ�ȯ, '6':�ڱ����ڻ�ȯ, '7':������ֻ�ȯ,  '8':�ڱ���ֻ�ȯ, '9':��Ź�㺸�����ȯ"                                                                
	char szExpiredate   [8];   // ���� ��ȿ�Ⱓ(YYYYMMDD)                                                                                                                                                                                                                                     
	char szAccPass         [40];  // ���º�й�ȣ                                                                                                                                                                                                                                             
	char szMarketType     [1];   // S(STOCK),E(ELW)                                                                                                                                                                                                                                           
	char szUserID       [20];  // HTS User ID                                                                                                                                                                                                                                                 
	char sMassId       [3];   // HTS, Mobile ����                                                                                                                                                                                                                                             
	char szAutoFlag        [1];   // ���ڵ� Flag  '0':�ڵ�, '1':���ڵ�                                                                                                                                                                                                                        
	char szOrdType      [1];   // �ֹ� ���� '1':�Ϲ��ֹ�  '2':ȣ�������ֹ�   '3':�ð������ֹ�                                                                                                                                                                                                 
	char szOrdCnt       [1];   // ����Ƚ�� (MAX = 5)  1 : �Ϲ��ֹ� n : ȣ��/�ð������ֹ�                                                                                                                                                                                                      
	char szInterval     [2];   // �ð����� �ֹ��� �ֹ� Interval (5 ~ 60)                                                                                                                                                                                                                      
	char szPriceType        [1];   // �ֹ�����  '1':������, '2':���尡  '3':������������, '4':�ֿ켱������ '5':�ż�1ȣ��,    '6':�ż�2ȣ��   '7':�ŵ�1ȣ��,    '8':�ŵ�2ȣ�� '9':���Ǻ������� 'A':������(IOC) 'B':���尡(IOC) 'C':������(IOC) 'D':������(FOK) 'E':���尡(FOK) 'F':������(FOK) 
	char szCrdate       [8];   // ������(�ſ�ŵ��� ���)                                                                                                                                                                                                                                     
	char sQtyGb        [1];   // ���� �Է±��� (2010.10.01 �߰�)  '1':���������Է�, '2':��з��� �Է�                                                                                                                                                                                         
	char szOrdBaseQty   [10];  // ���ؼ���                                                                                                                                                                                                                                                    
	//char szOrdReqQty    [100]; // �ֹ�����(���� or �����)                                                                                                                                                                                                                                    
	char szOrdReqQty    [10][10]; // �ֹ�����(���� or �����)                                                                                                                                                                                                                                    
	char szOrdReqPrice    [20];  // �ŵ�1/2/3ȣ�� �ż�1/2/3ȣ�� ���簡, ���Ѱ� ���Ѱ�                                                                                                                                                                                                         
	char szCondFlag     [1];   // ���Ǳ��� '1' : �Ϲ�����(����/�ü�/...) '2' : ���������                                                                                                                                                                                                     
	char szCondCnt      [2];   // ���Ǽ� (�ִ� 20��)                                                                                                                                                                                                                                          
	char szCondExp      [80];  // ���ǰ���(ǥ����)                                                                                                                                                                                                                                          
	//char sCode         [36];  // ���� Check�� ���Ǵ����� (4������)  ���屸��(1) + �����ڵ�(8) S(STOCK),E(ELW)                                                                                                                                                                             
	char szCode1[9];					//���屸��(1) + �����ڵ�(8)                                                                                                                                                                                                                                       
	char szCode2[9];					//���屸��(1) + �����ڵ�(8)                                                                                                                                                                                                                                       
	char szCode3[9];					//���屸��(1) + �����ڵ�(8)                                                                                                                                                                                                                                       
	char szCode4[9];					//���屸��(1) + �����ڵ�(8)                                                                                                                                                                                                                                       
	char szDestTime     [6];   // �����ð� �ֹ��� ���� �ð�                                                                                                                                                                                                                                   
	char sDestONTime   [6];   // ��/�� �������� ���� �����ð� (HHMMSS)                                                                                                                                                                                                                        
	char sDivGb        [1];   // ���ұ��� : 0:���迭,   1:��迭, 2:���迭                                                                                                                                                                                                                    
	char sDivDir       [1];   // ���ҹ��� : 0:�ż�����, 1:�ŵ�����                                                                                                                                                                                                                            
	char sPcIp         [15];  // �缳IP format : 999.999.999.999  (15�ڸ����)                                                                                                                                                                                                                
	char sAvgPrcFlag	[1];	//��ո��Դܰ� �÷��� : 0:��������, 1:����
	char sAvgPrc		[15];	//��ո��Դܰ�

	User_Define			stUser_Define[20];      // 2840 ���� (ȭ�� �ϴܿ� �󼼳��� ����) ����1��Size(81) * ���Ǽ�(20)
	char sFiller       [64];  // filler                                                                                                                                                                                                                                                       
} TR_ORDER_REGIN;      
#define SZ_TR_ORDER_REGIN sizeof(TR_ORDER_REGIN)
// 20120723 ssj - �����ڵ��ֹ� <<

// 20120723 ssj - �����ڵ��ֹ� >>
typedef struct tag_OrdListInput
{
	char szAccount[12];			//���¹�ȣ
	char szItemCode[8];			//�����ڵ�
	char szMMType[1];			//�Ÿű��� '1':�ŵ�,  '2':�ż�
	char szCredit[1];			//�ſ뱸��     '0':����, '1':��������&�ڱ����� '2':�㺸����
								//�ſ뱸��     '0':����, '1':�������ڽű�, '2':�ڱ����ڽű�, '3':�������, '4':�ڱ���ֽű�, '5':�������ڻ�ȯ, '6':�ڱ����ڻ�ȯ, '7':������ֻ�ȯ, '8':�ڱ���ֻ�ȯ, '9':��Ź�㺸�����ȯ"
	char szCrDate[8];			// ������        YYYYMMDD                (O)
}TR_ORDER_DETAIL_IN;
#define SZ_TR_ORDER_DETAIL_IN sizeof(TR_ORDER_DETAIL_IN)
// 20120723 ssj - �����ڵ��ֹ� <<

// 20120723 ssj - �����ڵ��ֹ� >>
typedef struct tag_TrSvrOrdRegistOutput
{
	char szJobFlag[1];		//I:���, U:����, D:����, S:����, R:����

	// 20120723 ssj - �����ڵ��ֹ� >>
	char sRetVal[1];		// S:����, F:����
	// 20120723 ssj - �����ڵ��ֹ� <<

	TR_ORDER_DETAIL_IN		stDetail;
}TR_ORDER_REGOUT;
#define SZ_TR_ORDER_REGOUT sizeof(TR_ORDER_REGOUT)
// 20120723 ssj - �����ڵ��ֹ� <<


typedef struct tag_OrdListOut
{
	TR_ORDER_REGIN stReg;
}
TR_ORDER_DETAIL_OUT;
#define SZ_TR_ORDER_DETAIL_OUT sizeof(TR_ORDER_DETAIL_OUT)

typedef struct tag_TrSvrOrdDeleteInput
{
	char cJobFlag[1];					//D:����
	char szAccount[LEN_ACCOUNT];		//���¹�ȣ
	char szShcode[LEN_ITEMCODE];		//�����ڵ�
	char szMMType[1];					//�Ÿű��� '1':�ŵ�,  '2':�ż�
	char szCredit[1];					//�ſ뱸�� '0':����, '1':�ſ�
	char szExpiredate[8];				//��ȿ�Ⱓ
	char szAccPass[LEN_ACCPASS];		//���º�й�ȣ	
	char szUserID[LEN_USERID];			//HTS User ID
	char szCrdate[8];					//������(�ſ�ŵ��� ���)
}TR_ORDER_DELETEIN;
#define SZ_TR_ORDER_DELETEIN sizeof(TR_ORDER_DELETEIN)

typedef struct tag_TrSvrOrdDeleteOutput
{
	char szJobFlag[1];		//I:���, U:����, D:����
	char szRetVal[1];		//'S':��ϼ���, 'F':��Ͻ���
}TR_ORDER_DELETEOUT;
#define SZ_TTR_ORDER_DELETEOUT sizeof(TR_ORDER_DELETEOUT)


typedef struct  _CH550C_3
{
   char tnb_cd              [ 3];   /* I ���¹�ȣ                           */
   char ast_cd              [ 2];   /* I ���¹�ȣ                           */
   char acct_no             [ 6];   /* I ���¹�ȣ                           */
   char trcode              [12];   /* I TR�ڵ�(��Ͽ䱸)                   */
   char reg_aban_gbn        [ 1];   /* I �����������   1:��� 2:����       */
   char prop_mthd_gbn       [ 1];   /* I ��û�������   4:HTS  5:���ͳ�     */
   char serv_chos_gbn       [ 1];   /* I ���񽺼��ñ��� 1:���� 2:��ü       */
} TR_SMS_REG;
#define SZ_TR_SMS_REG  sizeof(TR_SMS_REG)


/*--------------------------------------------------------------------------*
 * << ���º� �ڵ�����ȣ �� TRCODE��û���� (NEW) >>
 * ������ TR ��ȣ : CH550C06,  12�ڸ� TR�ڵ� : TR1501021003
 *--------------------------------------------------------------------------*/
typedef struct  _CH550C_4
{
   char tnb_cd              [ 3];   /* I ���¹�ȣ                           */
   char ast_cd              [ 2];   /* I ���¹�ȣ                           */
   char acct_no             [ 6];   /* I ���¹�ȣ                           */
   char trcode              [12];   /* I TR�ڵ�(��ȸ�䱸)                   */
   char hphn_no             [12];   /* O �ڵ�����ȣ                         */
   char trcode_yn           [ 1];   /* O TR�ڵ��û����    Y or N           */
} TR_PHONENUM;
#define SZ_TR_PHONENUM  sizeof(TR_PHONENUM)

// 20120723 ssj - �����ڵ��ֹ� >>
typedef struct tag_OrdDetailInput
{
	char szUserID[20];		//����� ID
	char szAccount[12];		//���¹�ȣ
	char sPswd[40];			//���º�й�ȣ 
	char sNextKey[30];		//���¹�ȣ+�����ڵ�+�Ÿű���+�ſ뱸��+������
}TR_ORDLIST_IN;
#define SZ_TR_ORDLIST_IN sizeof(TR_ORDLIST_IN)
// 20120723 ssj - �����ڵ��ֹ� <<

// 20120723 ssj - �����ڵ��ֹ� >>
// TR_REQ_COND_LIST (77030)
typedef struct tag_OrdInfo
{
	char sNextKey[30];		//���¹�ȣ+�����ڵ�+�Ÿű���+�ſ뱸��+������+�ſ�On/Off
	char szAccount[12];		//���¹�ȣ
	char sAcctID[15];		//���½ĺ�ID
	char szItemCode[8];		//�����ڵ�
	char szMMType[1];		//�Ÿű��� '1':�ŵ�,  '2':�ż�
	char szCredit[1];		//"�ſ뱸��     '0':����, '1':�������ڽű�, '2':�ڱ����ڽű�, '3':�������, '4':�ڱ���ֽű�, '5':�������ڻ�ȯ, '6':�ڱ����ڻ�ȯ, '7':������ֻ�ȯ, '8':�ڱ���ֻ�ȯ, '9':��Ź�㺸�����ȯ"
	char cAutoFlag[1];		//���ڵ� Flag  '0':�ڵ�, '1':���ڵ�
	char szItemName[40];	//�����
	char szPrice[10];		//���簡
	char szExpiredDate[8];	//��ȿ�Ⱓ
	char cResult[1];		//ó�����    '1':����,  '2':�޸�(����)
	char cbCondAcc[1];		//�������ǿ���  ����
	char cbCondItem[1];		//BM���ǿ��� ����
	char cbCondPrice[1];	//�ü����ǿ��� ����
	char cbCondIndex[1];	//��ǥ���ǿ��� ����
	char cbCondUser[1];		//��������ǿ��� ����
	char szLoanDate[8];                   // ������
	char sOrdGb[1];			// �ֹ�����  2012.03.02 �߰�
	char sOrdRegPrc[20];	// �ֹ�����  2012.03.02 �߰�
	// 20120723 ssj - �����ڵ��ֹ� >>
	char sAvgPrcFlag[1];    // ��մܰ� ����0:���԰�,1������
	char sAvgPrc[15];		// ��ո��Դܰ� ������
	char sMassID[3];		// ��ü���� - HTS �Ϲ�: 50(�𷰽�, ����, FX,FX+ ����), HTS �̴�: 51, ������/�ȵ���̵� ��: 66, �����е� ��: 67
	char sOrdQty[10];		// ���ֹ�����
	// 20120723 ssj - �����ڵ��ֹ� <<
	char szCondStatement[800];	//ȿ������
}ST_ORDINFO;
#define SZ_ST_ORDINFO sizeof(ST_ORDINFO)
// 20120723 ssj - �����ڵ��ֹ� <<

// TR_REQ_COND_LIST (77030)
typedef struct tag_OrdDetailOutput
{
	char szCount[8];		//����ֹ� Count
	ST_ORDINFO* pstOrdInfo;
}TR_ORDLIST_OUT;
#define SZ_TR_ORDLIST_OUT sizeof(TR_ORDLIST_OUT)

// 20120723 ssj - �����ڵ��ֹ� >>
typedef struct _TR77010_IN
{
	char sAcnt_no        [12]; // ���� ��ȣ                                                                                                                         
	char sMass_id        [3]; // ���ǵ�� ��ü (ex)HTS, �����, �� ��                                                                                              
	char sSvr_ip         [15]; // ��ϼ���IP                                                                                                                     
	char sCond_expr_date [8]; // ���� ���� ����. (YYYYMMDD)                                                                                                        
	char sNewitem_add    [1]; // 0:ó������, 1:�ű�����ó����                                                                                                      
	char sScrt_no        [40]; // ���� ��� ��ȣ (�ֹ�, �ܰ� ��ȸ�� �ʿ���.)                                                                                        
	char sId             [20]; // Hts login ID                                                                                                                      
	char sSEL_BUY_GBN    [1]; // 1:�ŵ�, 2:�ż�                                                                                                                    
	char sAuto_gbn       [1]; // 1 : ���ڵ� �ֹ�, 0 : �ڵ��ֹ�                                                                                                     
	char sOrd_div_gbn    [1]; // 1 : �Ϲ� �ֹ�, 2 : ȣ������ �ֹ�, 3 : �ð����� �ֹ�
	char sDIV_GBN        [1]; // '0 ': ���迭, '1':��迭, '2':���迭
	char sDIV_ORD_GBN    [1]; // '0' : �ż�����, '1':�ŵ�����
	char sOrd_cnt        [1]; // �Ϲ��ֹ��� ��� 1. ȣ������ �� �ð� ������ ��� ���� Ƚ��
	char sORD_INTERVAL   [2]; // �ð����� �ֹ��� ���� ���� (�ּ� 1�� ~ �ִ� 60��.)
	char sOrd_gbn        [1]; // " '1':������,       '2':���尡 '3':������������, '4':�ֿ켱������ '5':�ż�1ȣ��,    '6':�ż�2ȣ�� '7':�ŵ�1ȣ��,    '8':�ŵ�2ȣ��"
	char sORD_QRY_GBN    [1]; // 1:���������Է�, 2:������� �Է�
	char sORD_BASE_QRY   [10]; // ���ؼ��� (ex: �ܰ��� 50%) ���� ���п� ���� ���� Ȥ�� ������� �Էµ�.
	char sOrd_qty1       [10]; // �ֹ�����1  ���� Ȥ�� ��з�( 1 ~ 100%)  �� �Էµ�.
	char sOrd_qty2       [10]; // �ֹ�����2  ���� Ȥ�� ��з�( 1 ~ 100%)  �� �Էµ�.
	char sOrd_qty3       [10]; // �ֹ�����3  ���� Ȥ�� ��з�( 1 ~ 100%)  �� �Էµ�.
	char sOrd_qty4       [10]; // �ֹ�����4  ���� Ȥ�� ��з�( 1 ~ 100%)  �� �Էµ�.
	char sOrd_qty5       [10]; // �ֹ�����5  ���� Ȥ�� ��з�( 1 ~ 100%)  �� �Էµ�.
	char sOrd_qty6       [10]; // �ֹ�����6  ���� Ȥ�� ��з�( 1 ~ 100%)  �� �Էµ�.
	char sOrd_qty7       [10]; // �ֹ�����7  ���� Ȥ�� ��з�( 1 ~ 100%)  �� �Էµ�.
	char sOrd_qty8       [10]; // �ֹ�����8  ���� Ȥ�� ��з�( 1 ~ 100%)  �� �Էµ�.
	char sOrd_qty9       [10]; // �ֹ�����9  ���� Ȥ�� ��з�( 1 ~ 100%)  �� �Էµ�.
	char sOrd_qty10      [10]; // �ֹ�����10  ���� Ȥ�� ��з�( 1 ~ 100%)  �� �Էµ�
	char sOrd_prc        [10]; // �ֹ����� (�ż�1/2/3ȣ��, �ŵ� 1/2/3 ȣ��) Ȥ�� �������� ���� (ex) D1 :�ŵ�1ȣ��, S2 :�ż�2ȣ��, J12300 : ������ 12300��)
	char sCond_obs_gbn   [1]; // 1': ��������, '2':���������
	char sCond_obs_cnt   [2]; // �ִ� 20��, USER_DEF ������� ����
	char sCond_obs_mix   [80]; // "���ǰ˻��� EXPLEN�� ���(80) ���������� ���� ��� 'OR'�� ���� ����������� ���� ����� �Է� ���ս�"
	User_Define sCond_obs_detl  [4]; // "���ǰ˻��� UserDefine ����ü ���, �迭 4��(�Է� ���� ���Ǽ��� 4��)"
	char sPcIp           [15]; // ��PcIp
	char sFiller         [49]; // Filler
} TR77010_IN;

typedef struct _TR77010_OUT
{
	char sAcct[12]; // ���¹�ȣ
	char sRetVal[1]; // S' ���� 'F'����
} TR77010_OUT;
 
typedef struct _TR77080_INPUT
{
	char sId             [20]; // Hts login ID
	char sAcnt_no        [12]; // ���� ��ȣ
} TR77080_INPUT;

typedef struct _TR77080_OUT
{
	char sAcnt_no        [12 ]; // ���� ��ȣ
	char sMass_id        [3  ]; // ���ǵ�� ��ü (ex)HTS, �����, �� ��
	char sSvr_ip         [15 ]; // ��ϼ���IP
	char sCond_expr_date [8  ]; // ���� ���� ����. (YYYYMMDD)
	char sNewitem_add    [1  ]; // 0:ó������, 1:�ű�����ó����
	char sScrt_no        [40 ]; // ���� ��� ��ȣ (�ֹ�, �ܰ� ��ȸ�� �ʿ���.)
	char sId             [20 ]; // Hts login ID
	char sSEL_BUY_GBN    [1  ]; // 1:�ŵ�, 2:�ż�
	char sAuto_gbn       [1  ]; // 1 : ���ڵ� �ֹ�, 0 : �ڵ��ֹ�
	char sOrd_div_gbn    [1  ]; // 1 : �Ϲ� �ֹ�, 2 : ȣ������ �ֹ�, 3 : �ð����� �ֹ�
	char sDIV_GBN        [1  ]; // '0 ': ���迭, '1':��迭, '2':���迭
	char sDIV_ORD_GBN    [1  ]; // '0' : �ż�����, '1':�ŵ�����
	char sOrd_cnt        [4  ]; // �Ϲ��ֹ��� ��� 1. ȣ������ �� �ð� ������ ��� ���� Ƚ��
	char sORD_INTERVAL   [4  ]; // �ð����� �ֹ��� ���� ���� (�ּ� 1�� ~ �ִ� 60��.)
	char sOrd_gbn        [1  ]; // " '1':������,       '2':���尡 '3':������������, '4':�ֿ켱������ '5':�ż�1ȣ��,    '6':�ż�2ȣ�� '7':�ŵ�1ȣ��,    '8':�ŵ�2ȣ��"
	char sORD_QRY_GBN    [1  ]; // 1:���������Է�, 2:������� �Է�
	char sORD_BASE_QRY   [10 ]; // ���ؼ��� (ex: �ܰ��� 50%) ���� ���п� ���� ���� Ȥ�� ������� �Էµ�.
	char sOrd_qty1       [10 ]; // �ֹ�����1  ���� Ȥ�� ��з�( 1 ~ 100%)  �� �Էµ�.
	char sOrd_qty2       [10 ]; // �ֹ�����2  ���� Ȥ�� ��з�( 1 ~ 100%)  �� �Էµ�.
	char sOrd_qty3       [10 ]; // �ֹ�����3  ���� Ȥ�� ��з�( 1 ~ 100%)  �� �Էµ�.
	char sOrd_qty4       [10 ]; // �ֹ�����4  ���� Ȥ�� ��з�( 1 ~ 100%)  �� �Էµ�.
	char sOrd_qty5       [10 ]; // �ֹ�����5  ���� Ȥ�� ��з�( 1 ~ 100%)  �� �Էµ�.
	char sOrd_qty6       [10 ]; // �ֹ�����6  ���� Ȥ�� ��з�( 1 ~ 100%)  �� �Էµ�.
	char sOrd_qty7       [10 ]; // �ֹ�����7  ���� Ȥ�� ��з�( 1 ~ 100%)  �� �Էµ�.
	char sOrd_qty8       [10 ]; // �ֹ�����8  ���� Ȥ�� ��з�( 1 ~ 100%)  �� �Էµ�.
	char sOrd_qty9       [10 ]; // �ֹ�����9  ���� Ȥ�� ��з�( 1 ~ 100%)  �� �Էµ�.
	char sOrd_qty10      [10 ]; // �ֹ�����10  ���� Ȥ�� ��з�( 1 ~ 100%)  �� �Էµ�.
	char sOrd_prc        [10 ]; // �ֹ����� (�ż�1/2/3ȣ��, �ŵ� 1/2/3 ȣ��) Ȥ�� �������� ���� (ex) D1 :�ŵ�1ȣ��, S2 :�ż�2ȣ��, J12300 : ������ 12300��)
	char sCond_obs_gbn   [1  ]; // 1': ��������, '2':���������
	char sCond_obs_cnt   [4  ]; // �ִ� 20��, USER_DEF ������� ����
	char sCond_obs_mix   [80 ]; // "���ǰ˻��� EXPLEN�� ���(80) ���������� ���� ��� 'OR'�� ���� ����������� ���� ����� �Է� ���ս�"
	User_Define sCond_obs_detl  [4]; // "���ǰ˻��� UserDefine ����ü ���, �迭 4�� (�Է� ���� ���Ǽ��� 4��)"
} TR77080_OUT;
// 20120723 ssj - �����ڵ��ֹ� <<

//�ſ���� ���� ��ȸ
typedef struct _TR12151_IN
{
	char acct[20]; //���¹�ȣ
	char privateip[16]; //999999999999
	char reqreccnt[4]; //"0001"
} TR12151_IN;

typedef struct _TR12151_OUT
{
	char ret[1]; // 0: �̾��� 1: ����(�ſ����)
} TR12151_OUT;


// �����ڵ��ֹ� ���Ǽ� TR

/****************************************************************************/
/*  TR CODE : tr_20019                                                      */
/****************************************************************************/
typedef struct
{
	char    htsId               [128];   /* �����ID     */
	char    tsGubun             [  1];  /* 0:�̵��,1:���,2:��ȸ      */
	char    ipAddress           [ 12];  /* IP ADDRESS                  */
	char    commCode            [  1];   /* ��ü����: P: �����ڵ��ֹ� S: �ü��˸���     */
} TR_IN_AGREE;

typedef struct
{
	char    tsGubun             [  1];  /* 0:�̵��,1:���             */
	char    result              [  1];  /* 0:����,1:����               */
} TR_OUT_AGREE; 
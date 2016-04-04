#if !defined(AFX_OC0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_OC0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_

// #include "../CommonTR/Drds_OC0.h"
#include "../include/Data_Common.h"

// �ۼ� : ���ؿ�
// ���� : 2005.11.23(��)

/***** �ɼ� ���簡 (OC0) *******************************************/
/***** SVR : �ɼ� ü��, ����, �⼼         ***********************/
/*******************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0( "�����ڵ�",                       jmcode,         char,   8)	
} DRDS_OC0_KEY;

typedef struct {
	DEFINE_DRDS_LINE0("�����ڵ�",                       jmcode,       char,   8)
    DEFINE_DRDS_LINE0("�Ѹ�SEQ",                        jmcodeseq,    char,   3)
    DEFINE_DRDS_LINE0("ü�����",                       cvolume,      char,   6)
    DEFINE_DRDS_LINE0("�ð�HH:MM:SS",                   time,         char,   6)

    DEFINE_DRDS_LINE0("�ŵ��켱ȣ��[9(3)v9(2)]",        offerho1,     char,   7)
    DEFINE_DRDS_LINE0("�ż��켱ȣ��[9(3)v9(2)]",        bidho1,       char,   7)
    DEFINE_DRDS_LINE0("�ŵ��ܷ�",                       offerrem1,    char,   6)
    DEFINE_DRDS_LINE0("�ż��ܷ�",                       bidrem1,      char,   6)
    DEFINE_DRDS_LINE0("�����ŵ�ȣ��[9(3)v9(2)]",        offerho2,     char,   7)
    DEFINE_DRDS_LINE0("�����ż�ȣ��[9(3)v9(2)]",        bidho2,       char,   7)
    DEFINE_DRDS_LINE0("�����ŵ�ȣ���ܷ�",               offerrem2,    char,   6)
    DEFINE_DRDS_LINE0("�����ż�ȣ���ܷ�",               bidrem2,      char,   6)
	DEFINE_DRDS_LINE0("�������ŵ�ȣ��[9(3)v9(2)]",      offerho3,     char,   7)
    DEFINE_DRDS_LINE0("�������ż�ȣ��[9(3)v9(2)]",      bidho3,       char,   7)
    DEFINE_DRDS_LINE0("�������ŵ�ȣ���ܷ�",             offerrem3,    char,   6)
    DEFINE_DRDS_LINE0("�������ż�ȣ���ܷ�",             bidrem3,      char,   6)
    DEFINE_DRDS_LINE0("�Ѹŵ�ȣ���ܷ�",                 offertotrem,  char,   6)
    DEFINE_DRDS_LINE0("�Ѹż�ȣ���ܷ�",                 bidtotrem,    char,   6)

    DEFINE_DRDS_LINE0("���簡[9(3)v99]",                price,        char,   7)
    DEFINE_DRDS_LINE0("�ð�[9(3)v99]",                  open,         char,   7)
    DEFINE_DRDS_LINE0("��[9(3)v99]",                  high,         char,   7)
    DEFINE_DRDS_LINE0("����[9(3)v99]",                  low,          char,   7)
    DEFINE_DRDS_LINE0("���� ü�����",                  volume,       char,   8)
    DEFINE_DRDS_LINE0("���������ż�ü�ᷮ",             bidvol,       char,   8)
    DEFINE_DRDS_LINE0("�����ŷ����",                   value,        char,  11)
	DEFINE_DRDS_LINE0("���ϴ���ȣ",                   sign,         char,   1)
    DEFINE_DRDS_LINE0("���ϴ��",                       change,       char,   7)
    DEFINE_DRDS_LINE0("�����",                         chgrate,      char,   7)

    DEFINE_DRDS_LINE0("4�����ŵ�ȣ��",                  offerho4,     char,   7)
    DEFINE_DRDS_LINE0("4�����ż�ȣ��",                  bidho4,       char,   7)
    DEFINE_DRDS_LINE0("4�����ŵ��ܷ�",                  offerrem4,    char,   6)
    DEFINE_DRDS_LINE0("4�����ż��ܷ�",                  bidrem4,      char,   6)
    DEFINE_DRDS_LINE0("5�����ŵ�ȣ��",                  offerho5,     char,   7)
    DEFINE_DRDS_LINE0("5�����ż�ȣ��",                  bidho5,       char,   7)
    DEFINE_DRDS_LINE0("5�����ŵ��ܷ�",                  offerrem5,    char,   6)
    DEFINE_DRDS_LINE0("5�����ż��ܷ�",                  bidrem5,      char,   6)
    
	DEFINE_DRDS_LINE0("�켱�ŵ��Ǽ�",                   offercnt1,    char,   4)
	DEFINE_DRDS_LINE0("�����ŵ��Ǽ�",                   offercnt2,    char,   4)
	DEFINE_DRDS_LINE0("�������ŵ��Ǽ�",                 offercnt3,    char,   4)
    DEFINE_DRDS_LINE0("4�����ŵ��Ǽ�",                  offercnt4,    char,   4)
    DEFINE_DRDS_LINE0("5�����ŵ��Ǽ�",                  offercnt5,    char,   4)
    DEFINE_DRDS_LINE0("�Ѹŵ��Ǽ�",                     offertotcnt,  char,   5)
    DEFINE_DRDS_LINE0("�켱�ż��Ǽ�",                   bidcnt1,      char,   4)
    DEFINE_DRDS_LINE0("�����ż��Ǽ�",                   bidcnt2,      char,   4)
    DEFINE_DRDS_LINE0("�������ż��Ǽ�",                 bidcnt3,      char,   4)
    DEFINE_DRDS_LINE0("4�����ż��Ǽ�",                  bidcnt4,      char,   4)
    DEFINE_DRDS_LINE0("5�����ż��Ǽ�",                  bidcnt5,      char,   4)
    DEFINE_DRDS_LINE0("�Ѹż��Ǽ�",                     bidtotcnt,    char,   5)
    
	DEFINE_DRDS_LINE0("�̷а�",                         theoryprice,  char,   7)
    DEFINE_DRDS_LINE0("���纯����",                     impv,         char,   7)
	DEFINE_DRDS_LINE0("��Ÿ",                           delta,        char,   7)
    DEFINE_DRDS_LINE0("����",                           gmma,         char,   7)
    DEFINE_DRDS_LINE0("����",                           vega,         char,   7)
    DEFINE_DRDS_LINE0("��Ÿ",                           theta,        char,   7)
    DEFINE_DRDS_LINE0("�ο�",                           rho,          char,   7)
    DEFINE_DRDS_LINE0("�̰�����������",                 openyak,      char,   7)
    DEFINE_DRDS_LINE0("�̰��������������",             openyakchg,   char,   6)

    DEFINE_DRDS_LINE0("�ð����",                       openchg,      char,   7)
    DEFINE_DRDS_LINE0("�����",                       highchg,      char,   7)
    DEFINE_DRDS_LINE0("�������",                       lowchg,       char,   7)
    DEFINE_DRDS_LINE0("�ŵ�ȣ���Ǽ����1",              offcnt1_chg,  char,   4)
    DEFINE_DRDS_LINE0("�ŵ�ȣ���Ǽ����2",              offcnt2_chg,  char,   4)
	DEFINE_DRDS_LINE0("�ŵ�ȣ���Ǽ����3",              offcnt3_chg,  char,   4)
    DEFINE_DRDS_LINE0("�ŵ�ȣ���Ǽ����4",              offcnt4_chg,  char,   4)
    DEFINE_DRDS_LINE0("�ŵ�ȣ���Ǽ����5",              offcnt5_chg,  char,   4)
    DEFINE_DRDS_LINE0("�ż�ȣ���Ǽ����1",              bidcnt1_chg,  char,   4)
    DEFINE_DRDS_LINE0("�ż�ȣ���Ǽ����2",              bidcnt2_chg,  char,   4)
    DEFINE_DRDS_LINE0("�ż�ȣ���Ǽ����3",              bidcnt3_chg,  char,   4)
    DEFINE_DRDS_LINE0("�ż�ȣ���Ǽ����4",              bidcnt4_chg,  char,   4)
    DEFINE_DRDS_LINE0("�ż�ȣ���Ǽ����5",              bidcnt5_chg,  char,   4)
	DEFINE_DRDS_LINE0("KP200",  	 				    kp200jisu,    char,   7)

	DEFINE_DRDS_LINE0("���簡ġ",  	 				    invalue,      char,   6)
	DEFINE_DRDS_LINE0("�ð���ġ",  	 				    tmvalue,      char,   6)
	DEFINE_DRDS_LINE0("�ŷ�������",					    volchange,    char,   9)
	DEFINE_DRDS_LINE0("�ŷ��������",                   valchange,    char,   9)
	DEFINE_DRDS_LINE0("������",                         gyurirate,    char,   7)
	
	//By KHD : 2006.02.6 �����ɼǸ������ �ü� ȭ�鿡 �ʿ��� Drds �ڵ尪 �߰� 
    
	DEFINE_DRDS_LINE0("ü����ż�",                     soonche,      char,   9)
    DEFINE_DRDS_LINE0("�Ѹŵ�ȣ���ܷ�(��ȣ)",           offertotrem1, char,   7)
    DEFINE_DRDS_LINE0("�Ѹż�ȣ���ܷ�(��ȣ)",           bidtotrem1,   char,   7)
    DEFINE_DRDS_LINE0("�̰�����������(��ȣ)",           openyak1,     char,   8)

	// 2006.02.06 : ������û���� ����Ÿ �߰�
	DEFINE_DRDS_LINE0("�ܷ���(�ż��ܷ�-�ŵ��ܷ�)",      remngap,      char,   7)
	DEFINE_DRDS_LINE0("�Ǽ���(�ż��Ǽ�-�ŵ��Ǽ�)",      countgap,     char,   5)

} DRDS_OC0_DATA;


class CDRDS_OC0_DATA
{
public: //Variable
	CString m_szjmcode;			/* "�����ڵ�"			*/          
	CString m_szjmcodeseq;		/* "����SEQ"		    */    
	CString m_szcvolume;		/* "ü�����        	*/          
	CString m_szprice;			/* "���簡[9(3)v99]"    */            

public:
	CDRDS_OC0_DATA()
	{
	}

	virtual void  Convert(DRDS_OC0_DATA* pInput)
	{
		CString sTemp1 ;
		char sTmp[20+1];

		DATA_MEMCOPY(sTmp, pInput, jmcode);			/* "�����ڵ�"			*/	
		DATA_MEMCOPY(sTmp, pInput, jmcodeseq);		/* "����SEQ"		*/		
		DATA_MEMCOPY(sTmp, pInput, cvolume);			/* "�ð�HH:MM:SS "			*/		
		DATA_MEMCOPY(sTmp, pInput, price);			/* "���簡[9(3)v99]"				*/		
	}
};


// �ɼ� ���簡 OC0
typedef struct
{
    char       opitem       [8];		// �����ڵ�
    char       opitemseq    [3];		// �Ѹ�SEQ
    char       opvol        [6];		// ü�����
    char       optime       [6];		// �ð�HH:MM:SS
    char       offer        [7];		// �ŵ��켱ȣ��[9(3)v9(2)]
    char       bid          [7];		// �ż��켱ȣ��[9(3)v9(2)]
    char       offerjan     [6];		// �ŵ��ܷ�
    char       bidjan       [6];		// �ż��ܷ�

    char       joffer       [7];		// �����ŵ�ȣ��[9(3)v9(2)]
    char       jbid         [7];		// �����ż�ȣ��[9(3)v9(2)]
    char       jofferjan    [6];		// �����ŵ�ȣ���ܷ�
    char       jbidjan      [6];		// �����ż�ȣ���ܷ�

    char       jjoffer      [7];		// �������ŵ�ȣ��[9(3)v9(2)]
    char       jjbid        [7];		// �������ż�ȣ��[9(3)v9(2)]
    char       jjofferjan   [6];		// �������ŵ�ȣ���ܷ�
    char       jjbidjan     [6];		// �������ż�ȣ���ܷ�

    char       tofferjan    [6];		// �Ѹŵ�ȣ���ܷ�
    char       tobidjan     [6];		// �Ѹż�ȣ���ܷ�
    char       opcurr       [7];		// ���簡[9(3)v99]
	char       opopen       [7];		// �ð�[9(3)v99]
    char       ophigh       [7];		// ��[9(3)v99]
    char       oplow        [7];		// ����[9(3)v99]
	char       opvolall     [8];		// ����ü�����
	char       bidvol       [8];        // �����ż�ü�ᷮ
	char       opvalall     [11];		// �����ŷ����

	char       opsign       [1];		// ���ϴ���ȣ
    char       opchange     [7];		// ���ϴ��
    char       oprate       [7];		// �����[9(7)]
    
    char       j4offer      [7];		// 4�����ŵ�ȣ��
    char       j4bid        [7];		// 4�����ż�ȣ��
    char       j4offerjan   [6];		// 4�����ŵ��ܷ�
    char       j4bidjan     [6];		// 4�����ż��ܷ�

    char       j5offer      [7];		// 5�����ŵ�ȣ��
    char       j5bid        [7];		// 5�����ż�ȣ��
    char       j5offerjan   [6];		// 5�����ŵ��ܷ�
    char       j5bidjan     [6];		// 5�����ż��ܷ�

    char       offersu      [4];		// �켱�ŵ��Ǽ�
    char       joffersu     [4];		// �����ŵ��Ǽ�
    char       jjoffersu    [4];		// �������ŵ��Ǽ�
    char       j4offersu    [4];		// 4�����ŵ��Ǽ�
    char       j5offersu    [4];		// 5�����ŵ��Ǽ�

    char       toffersu     [5];		// �Ѹŵ��Ǽ�
    char       bidsu        [4];		// �켱�ż��Ǽ�
    char       jbidsu       [4];		// �����ż��Ǽ�
    char       jjbidsu      [4];		// �������ż��Ǽ�
    char       j4bidsu      [4];		// 4�����ż��Ǽ�
    char       j5bidsu      [4];		// 5�����ż��Ǽ�

    char       tbidsu       [5];		// �Ѹż��Ǽ�
    char       theory       [7];		// �̷а�
    char       impv         [7];		// ���纯����
    char       delta        [7];		// ��Ÿ
    char       gmma         [7];		// ����
    char       vega         [7];		// ����
    char       theta        [7];		// ��Ÿ
    char       rho          [7];		// �ο�

	char       openyak      [7];   // �̰�����������
    char       openyakchg   [6];   // �̰��������������
    char       openchg      [7];   // �ð����
    char       highchg      [7];   // �����
    char       lowchg       [7];   // �������

    char       offcnt1_chg  [4];    //�ŵ�ȣ���Ǽ����1
    char       offcnt2_chg  [4];    //�ŵ�ȣ���Ǽ����2
    char       offcnt3_chg  [4];    //�ŵ�ȣ���Ǽ����3
    char       offcnt4_chg  [4];    //�ŵ�ȣ���Ǽ����4
    char       offcnt5_chg  [4];    //�ŵ�ȣ���Ǽ����5
    char       bidcnt1_chg  [4];    //�ż�ȣ���Ǽ����1
    char       bidcnt2_chg  [4];    //�ż�ȣ���Ǽ����2
    char       bidcnt3_chg  [4];    //�ż�ȣ���Ǽ����3
    char       bidcnt4_chg  [4];    //�ż�ȣ���Ǽ����4
    char       bidcnt5_chg  [4];    //�ż�ȣ���Ǽ����5

    char       kp200jisu    [7];    //KP200
    char       invalue      [6];    //���簡ġ
    char       tmvalue      [6];    //�ð���ġ
    char       volchange    [9];    //�ŷ�������
    char       valchange    [9];    //�ŷ��������
    char       gyurirate    [7];    //������
    char       soonche      [9];    //ü����ż�
 
    char       offertotrem1 [7];    //�Ѹŵ�ȣ���ܷ�(��ȣ)
    char       bidtotrem1   [7];    //�Ѹż�ȣ���ܷ�(��ȣ)
    char       openyak1     [8];    //�̰�����������(��ȣ)
	char       remngap      [7];    //�ܷ���(�ż��ܷ�-�ŵ��ܷ�)
	char       countgap     [5];    //�Ǽ���(�ż��Ǽ�-�ŵ��Ǽ�)

    //char       fil          [1];		// Temp
    //char       soonmesu     [6];		// ���ż��ܷ�
} st_OC0;  
#define st_OC0_Size		sizeof(st_OC0) 

#endif // AFX_OC0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


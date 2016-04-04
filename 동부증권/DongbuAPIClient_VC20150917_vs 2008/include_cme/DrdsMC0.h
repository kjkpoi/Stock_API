#if !defined(AFX_MC0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_MC0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_

#include "../include/Data_Common.h"


/***** CME ���� ���簡 (MC0) *******************************************/
/***** SVR : ���� ü��, ����, �⼼           *********************/
/*******************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0( "�����ڵ�",                       jmcode,         char,   8)	
} DRDS_MC0_KEY;

typedef struct {
  DEFINE_DRDS_LINE0("�����ڵ�",                       jmcode,       char,  8) 
	DEFINE_DRDS_LINE0("����SEQ",                        jmcodeseq,    char,  2) 
	DEFINE_DRDS_LINE0("�ð�HH:MM:SS",                   time,         char,  6) 
	DEFINE_DRDS_LINE0("���簡[9(3)v99]",                price,        char,  7) 
	DEFINE_DRDS_LINE0("�ð�[9(3)v99]",                  open,         char,  7) 
	DEFINE_DRDS_LINE0("��[9(3)v99]",                  high,         char,  7) 
	DEFINE_DRDS_LINE0("����[9(3)v99]",                  low,          char,  7) 
	DEFINE_DRDS_LINE0("����ü�����",                   volume,       char,  7) 
	DEFINE_DRDS_LINE0("�����ż�ü�ᷮ",                 bidvol,       char,  7) 
	DEFINE_DRDS_LINE0("�����ŷ����(õ��->�鸸��)",     value,        char, 11) 
	DEFINE_DRDS_LINE0("���ϴ���ȣ",                   sign,         char,  1) 
	DEFINE_DRDS_LINE0("���ϴ��[9(3)v99]",              change,       char,  7) 
	DEFINE_DRDS_LINE0("�����",                         chgrate,      char,  7) 
	DEFINE_DRDS_LINE0("ü�����",                       cvolume,      char,  6) 
	DEFINE_DRDS_LINE0("�ŵ��켱ȣ��[9(3)v9(2)]",        offerho1,     char,  7) 
	DEFINE_DRDS_LINE0("�ż��켱ȣ��[9(3)v9(2)]",        bidho1,       char,  7) 
	DEFINE_DRDS_LINE0("�ŵ��ܷ�",                       offerrem1,    char,  6) 
	DEFINE_DRDS_LINE0("�ż��ܷ�",                       bidrem1,      char,  6) 
	DEFINE_DRDS_LINE0("�����ŵ�ȣ��[9(3)v9(2)]",        offerho2,     char,  7) 
	DEFINE_DRDS_LINE0("�����ż�ȣ��[9(3)v9(2)]",        bidho2,       char,  7) 
	DEFINE_DRDS_LINE0("�����ŵ�ȣ���ܷ�",               offerrem2,    char,  6) 
	DEFINE_DRDS_LINE0("�����ż�ȣ���ܷ�",               bidrem2,      char,  6) 
	DEFINE_DRDS_LINE0("�������ŵ�ȣ��9(3)v9(2)",        offerho3,     char,  7) 
	DEFINE_DRDS_LINE0("�������ż�ȣ��9(3)v9(2)",        bidho3,       char,  7) 
	DEFINE_DRDS_LINE0("�������ŵ�ȣ���ܷ�",             offerrem3,    char,  6) 
	DEFINE_DRDS_LINE0("�������ż�ȣ���ܷ�",             bidrem3,      char,  6) 
	DEFINE_DRDS_LINE0("�Ѹŵ�ȣ���ܷ�",                 offertotrem,  char,  6) 
	DEFINE_DRDS_LINE0("�Ѹż�ȣ���ܷ�",                 bidtotrem,    char,  6) 
	DEFINE_DRDS_LINE0("4�����ŵ�ȣ��",                  offerho4,     char,  7) 
	DEFINE_DRDS_LINE0("4�����ż�ȣ��",                  bidho4,       char,  7) 
	DEFINE_DRDS_LINE0("4�����ŵ��ܷ�",                  offerrem4,    char,  6) 
	DEFINE_DRDS_LINE0("4�����ż��ܷ�",                  bidrem4,      char,  6) 
	DEFINE_DRDS_LINE0("5�����ŵ�ȣ��",                  offerho5,     char,  7) 
	DEFINE_DRDS_LINE0("5�����ż�ȣ��",                  bidho5,       char,  7) 
	DEFINE_DRDS_LINE0("5�����ŵ��ܷ�",                  offerrem5,    char,  6) 
	DEFINE_DRDS_LINE0("5�����ż��ܷ�",                  bidrem5,      char,  6) 
                                                                            
	DEFINE_DRDS_LINE0("�켱�ŵ��Ǽ�",                   offercnt1,    char,  4) 
	DEFINE_DRDS_LINE0("�����ŵ��Ǽ�",                   offercnt2,    char,  4) 
	DEFINE_DRDS_LINE0("�������ŵ��Ǽ�",                 offercnt3,    char,  4) 
	DEFINE_DRDS_LINE0("4�����ŵ��Ǽ�",                  offercnt4,    char,  4) 
	DEFINE_DRDS_LINE0("5�����ŵ��Ǽ�",                  offercnt5,    char,  4) 
	DEFINE_DRDS_LINE0("�Ѹŵ��Ǽ�",                     offertotcnt,  char,  5) 
                                                                            
	DEFINE_DRDS_LINE0("�켱�ż��Ǽ�",                   bidcnt1,      char,  4) 
	DEFINE_DRDS_LINE0("�����ż��Ǽ�",                   bidcnt2,      char,  4) 
	DEFINE_DRDS_LINE0("�������ż��Ǽ�",                 bidcnt3,      char,  4) 
	DEFINE_DRDS_LINE0("4�����ż��Ǽ�",                  bidcnt4,      char,  4) 
	DEFINE_DRDS_LINE0("5�����ż��Ǽ�",                  bidcnt5,      char,  4) 
	DEFINE_DRDS_LINE0("�� �ż� �Ǽ�",                   bidtotcnt,    char,  5) 
                                                                            
	DEFINE_DRDS_LINE0("�̷а�",                         theoryprice,  char,  7) 
                                                                            
	DEFINE_DRDS_LINE0("�̰�����������",                 openyak,      char,  7) 
	DEFINE_DRDS_LINE0("�̰��������������",             openyakchg,   char,  6) 
	DEFINE_DRDS_LINE0("������",                         gyurirate,    char,  7) 
	DEFINE_DRDS_LINE0("���庣�̽ý�",                   basis,        char,  7) 
	DEFINE_DRDS_LINE0("�ð����",                       openchg,      char,  7) 
	DEFINE_DRDS_LINE0("�����",                       highchg,      char,  7) 
	DEFINE_DRDS_LINE0("�������",                       lowchg,       char,  7) 
	DEFINE_DRDS_LINE0("�ŵ�ȣ���Ǽ����1",              offcnt1_chg,  char,  4) 
	DEFINE_DRDS_LINE0("�ŵ�ȣ���Ǽ����2",              offcnt2_chg,  char,  4) 
	DEFINE_DRDS_LINE0("�ŵ�ȣ���Ǽ����3",              offcnt3_chg,  char,  4) 
	DEFINE_DRDS_LINE0("�ŵ�ȣ���Ǽ����4",              offcnt4_chg,  char,  4) 
	DEFINE_DRDS_LINE0("�ŵ�ȣ���Ǽ����5",              offcnt5_chg,  char,  4) 
	DEFINE_DRDS_LINE0("�ż�ȣ���Ǽ����1",              bidcnt1_chg,  char,  4) 
	DEFINE_DRDS_LINE0("�ż�ȣ���Ǽ����2",              bidcnt2_chg,  char,  4) 
	DEFINE_DRDS_LINE0("�ż�ȣ���Ǽ����3",              bidcnt3_chg,  char,  4) 
	DEFINE_DRDS_LINE0("�ż�ȣ���Ǽ����4",              bidcnt4_chg,  char,  4) 
	DEFINE_DRDS_LINE0("�ż�ȣ���Ǽ����5",              bidcnt5_chg,  char,  4) 
                                                                            
	DEFINE_DRDS_LINE0("�����ڻ�����",                   opttarclose,  char,  7) 
	DEFINE_DRDS_LINE0("ȣ�����ܷ� ����",                totrem_chg,   char,  7) 
	DEFINE_DRDS_LINE0("�̷к��̽ý�",                   tbasis,       char,  7) 
	DEFINE_DRDS_LINE0("�ŷ�������",						          volchange,    char,  9)
	DEFINE_DRDS_LINE0("�ŷ��������",                   valchange,    char,  9) 
	DEFINE_DRDS_LINE0("ü����ż�",                     soonche,      char,  9) 
} DRDS_MC0_DATA;


class CDRDS_MC0_DATA
{
public: //Variable
	CString m_szjmcode;			/* "�����ڵ�"			*/          
	CString m_szjmcodeseq;		/* "����SEQ"		    */    
	CString m_sztime;			/* "�ð�HH:MM:SS    	*/          
	CString m_szprice;			/* "���簡[9(3)v99]"	*/            
	CString m_szopen;			/* "�ð�[9(3)v99]"		*/            
	CString m_szhigh;			/* "��[9(3)v99]"		*/            
	CString m_szlow;			/* "����[9(3)v99]"		*/          
	CString m_szvolume;			/* "����ü�����"		*/              
	CString m_szbidvol;			/* "�����ż�ü�ᷮ"		*/              
	CString m_szvalue;			/* "�����ŷ����(õ��->�鸸��)"	*/          
	CString m_szsign;			/* "���ϴ���ȣ"		*/          
	CString m_szchange;			/* "���ϴ��[9(3)v99]"	*/        
	CString m_szchgrate;		/* "�����" 			*/        
	CString m_szcvolume;		/* "ü�����"			*/          
	CString m_szofferho1;		/* "�ŵ��켱ȣ��[9(3)v9(2)]"*/          
	CString m_szbidho1;	    	/* "�ż��켱ȣ��[9(3)v9(2)]"*/            

	//CString m_szofferrem1;		/* "CB����"			*/            
	//CString m_szbidrem1;			/* "STOP"			*/              
	//CString m_szofferho2;	/* "�ð��ܰŷ���"		*/      
	//CString m_szbidho2;		/* "�ð��ܴ뷮�Ÿ�"		*/    
	//CString m_szofferrem2;		/* "�ŵ�ȣ���ܷ�"	*/      
	//CString m_szbidrem2;			/* "�ż�ȣ���ܷ�"	*/      
	//CString m_szofferho3;		/* "�Ѹŵ�ȣ���ܷ�"		*/    

public:
	CDRDS_MC0_DATA()
	{
	}

	virtual void  Convert(DRDS_MC0_DATA* pInput)
	{
		CString sTemp1 ;
		char sTmp[20+1];

		DATA_MEMCOPY(sTmp, pInput, jmcode);			/* "�����ڵ�"			*/	
		DATA_MEMCOPY(sTmp, pInput, jmcodeseq);		/* "����SEQ"		*/		
		DATA_MEMCOPY(sTmp, pInput, time);			/* "�ð�HH:MM:SS "			*/		
		DATA_MEMCOPY(sTmp, pInput, price);			/* "���簡[9(3)v99]"				*/		
		DATA_MEMCOPY(sTmp, pInput, open);			/* "�ð�[9(3)v99]"				*/		
		DATA_MEMCOPY(sTmp, pInput, high);			/* "��[9(3)v99]"				*/		
		DATA_MEMCOPY(sTmp, pInput, low);			/* "����[9(3)v99]"			*/		
		DATA_MEMCOPY(sTmp, pInput, volume);			/* "����ü�����"				*/		
		DATA_MEMCOPY(sTmp, pInput, bidvol);			/* "�����ż�ü�ᷮ"				*/
		DATA_MEMCOPY(sTmp, pInput, value);			/* "�����ŷ����(õ��->�鸸��)"			*/		
		DATA_MEMCOPY(sTmp, pInput, sign);			/* "���ϴ���ȣ"			*/	
		DATA_MEMCOPY(sTmp, pInput, change);			/* "���ϴ��[9(3)v99]"			*/		
		DATA_MEMCOPY(sTmp, pInput, chgrate);		/* "�����"			*/	
		DATA_MEMCOPY(sTmp, pInput, cvolume);		/* "ü�����"			*/		
		DATA_MEMCOPY(sTmp, pInput, offerho1);		/* "�ŵ��켱ȣ��[9(3)v9(2)]"			*/		
		DATA_MEMCOPY(sTmp, pInput, bidho1);		    /* "�ż��켱ȣ��[9(3)v9(2)]"				*/		
	}
};

typedef struct
{
	char       fuitem		    [8];		// �����ڵ�
	char       futitemseq   [2];		// ����SEQ 
	char       futime		    [6];		// �ð�HH:MM:SS
	char       fucurr		    [7];		// ���簡[9(3)v99]      	
	char       fuopen       [7];		// �ð�[9(3)v99]  
	char       fuhigh       [7];		// ��[9(3)v99]
	char       fulow        [7];		// ����[9(3)v99]
									         
	char       fuvolall     [7];		// ����ü�����
	char       bidvol       [7];        // �����ż�ü�ᷮ
	char       fuvalall     [11];		// �����ŷ����(õ��->�鸸��)          
  char       fusign       [1];		// ���ϴ���ȣ
	char       fuchange     [7];		// ���ϴ��[9(3)v99]
	char       furate       [7];		// �����[9(7)]        
	char       fuvol        [6];		// ü�����

	char       offer        [7];		// �ŵ��켱ȣ��[9(3)v9(2)]
	char       bid          [7];		// �ż��켱ȣ��[9(3)v9(2)]
	char       offerjan     [6];		// �ŵ��ܷ�
	char       bidjan       [6];		// �ż��ܷ�
									          
	char       joffer       [7];		// �����ŵ�ȣ��[9(3)v9(2)]
	char       jbid         [7];		// �����ż�ȣ��[9(3)v9(2)]
	char       jofferjan    [6];		// �����ŵ�ȣ���ܷ�
	char       jbidjan      [6];		// �����ż�ȣ���ܷ�
									          
	char       jjoffer      [7];		// �������ŵ�ȣ��9(3)v9(2)
	char       jjbid        [7];		// �������ż�ȣ��9(3)v9(2)
	char       jjofferjan   [6];		// �������ŵ�ȣ���ܷ�
	char       jjbidjan     [6];		// �������ż�ȣ���ܷ�
                            
	char       tofferjan    [6];		// �Ѹŵ�ȣ���ܷ�
	char       tobidjan     [6];		// �Ѹż�ȣ���ܷ�
									          
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
	char       tbidsu       [5];		// �� �ż� �Ǽ�
	                          
	char       theoryprice  [7];		// �̷а�
	                          
	char       openyak      [7];        //�̰�����������
  char       openyakchg   [6];        //�̰��������������
  char       gyurirate    [7];        //������
  char       basis        [7];        //���庣�̽ý�
  char       openchg      [7];        //�ð����
  char       highchg      [7];        //�����
  char       lowchg       [7];        //�������
                           
  char       offcnt1_chg  [4];		//�ŵ�ȣ���Ǽ����1
  char       offcnt2_chg  [4];		//�ŵ�ȣ���Ǽ����2
  char       offcnt3_chg  [4];		//�ŵ�ȣ���Ǽ����3
  char       offcnt4_chg  [4];		//�ŵ�ȣ���Ǽ����4
  char       offcnt5_chg  [4];		//�ŵ�ȣ���Ǽ����5
  char       bidcnt1_chg  [4];		//�ż�ȣ���Ǽ����1
  char       bidcnt2_chg  [4];		//�ż�ȣ���Ǽ����2
  char       bidcnt3_chg  [4];		//�ż�ȣ���Ǽ����3
  char       bidcnt4_chg  [4];	    //�ż�ȣ���Ǽ����4
  char       bidcnt5_chg  [4];        //�ż�ȣ���Ǽ����5
                           
  char       kospi200     [7];		//kospi200
  char       totrem_chg   [7];		//ȣ�����ܷ� ����
  char       tbasis       [7];		//�̷к��̽ý�
  char       volchange    [9];		//�ŷ�������
  char       valchange    [9];		//�ŷ��������
  char       soonche      [9];		//ü����ż�
} _MC0;  
#define st_MC0_Size		sizeof(st_MC0) 


#endif // AFX_MC0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_
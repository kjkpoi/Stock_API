#if !defined(AFX_JC0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_JC0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_

#include "../include/Data_Common.h"

/***** �ֽ� ���� ���簡 (JC0) *******************************************/
/************************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0( "�����ڵ�",                       jmcode,         char,   8)	
} DRDS_JC0_KEY;

typedef struct {
        DEFINE_DRDS_LINE0("�����ڵ�",                   jmcode,      char,         8)
        DEFINE_DRDS_LINE0("���� SEQ",                   jmcodeseq,   char,         4)
        DEFINE_DRDS_LINE0("�ð� HH:MM:SS",              time,        char,         6)
        DEFINE_DRDS_LINE0("���簡",                     price,       char,         7)
        DEFINE_DRDS_LINE0("�ð�",                       open,        char,         7)
        DEFINE_DRDS_LINE0("��",                       high,        char,         7)
        DEFINE_DRDS_LINE0("����",                       low,         char,         7)
        DEFINE_DRDS_LINE0("���� ü�����",              volume,      char,         7)
        DEFINE_DRDS_LINE0("�����ŷ����(õ��)",         value,       char,        11)
        DEFINE_DRDS_LINE0("���ϴ�� ��ȣ",              sign,        char,         1)
        DEFINE_DRDS_LINE0("���ϴ��",                   change,      char,         7)
        DEFINE_DRDS_LINE0("�����",                     chgrate,     char,         7)
        DEFINE_DRDS_LINE0("ü�����",                   cvolume,     char,         6)

        DEFINE_DRDS_LINE0("�ŵ��켱ȣ��",               offerho1,    char,         7)
        DEFINE_DRDS_LINE0("�ż��켱ȣ��",               bidho1,      char,         7)
        DEFINE_DRDS_LINE0("�ŵ��ܷ�",                   offerrem1,   char,         6)
        DEFINE_DRDS_LINE0("�ż��ܷ�",                   bidrem1,     char,         6)
        DEFINE_DRDS_LINE0("���� �ŵ�ȣ��",              offerho2,    char,         7)
        DEFINE_DRDS_LINE0("���� �ż�ȣ��",              bidho2,      char,         7)
        DEFINE_DRDS_LINE0("���� �ŵ�ȣ�� �ܷ�",         offerrem2,   char,         6)
        DEFINE_DRDS_LINE0("�����ż�ȣ�� �ܷ�",          bidrem2,     char,         6)
        DEFINE_DRDS_LINE0("������   �ŵ�ȣ��",          offerho3,    char,         7)
        DEFINE_DRDS_LINE0("������   �ż�ȣ��",          bidho3,      char,         7)
        DEFINE_DRDS_LINE0("������   �ŵ�ȣ�� �ܷ�",     offerrem3,   char,         6)
        DEFINE_DRDS_LINE0("�������ż�ȣ��   �ܷ�",      bidrem3,     char,         6)
        DEFINE_DRDS_LINE0("4����    �ŵ� ȣ��",         offerho4,    char,         7)
        DEFINE_DRDS_LINE0("4����    �ż� ȣ��",         bidho4,      char,         7)
        DEFINE_DRDS_LINE0("4����    �ŵ� �ܷ�",         offerrem4,   char,         6)
        DEFINE_DRDS_LINE0("4����    �ż� �ܷ�",         bidrem4,     char,         6)
        DEFINE_DRDS_LINE0("5����    �ŵ� ȣ��",         offerho5,    char,         7)
        DEFINE_DRDS_LINE0("5����    �ż� ȣ��",         bidho5,      char,         7)
        DEFINE_DRDS_LINE0("5����    �ŵ� �ܷ�",         offerrem5,   char,         6)
        DEFINE_DRDS_LINE0("5����    �ż� �ܷ�",         bidrem5,     char,         6)
        DEFINE_DRDS_LINE0("6����    �ŵ� ȣ��",         offerho6,    char,         7)
        DEFINE_DRDS_LINE0("6����    �ż� ȣ��",         bidho6,      char,         7)
        DEFINE_DRDS_LINE0("6����    �ŵ� �ܷ�",         offerrem6,   char,         6)
        DEFINE_DRDS_LINE0("6����    �ż� �ܷ�",         bidrem6,     char,         6)
        DEFINE_DRDS_LINE0("7����    �ŵ� ȣ��",         offerho7,    char,         7)
        DEFINE_DRDS_LINE0("7����    �ż� ȣ��",         bidho7,      char,         7)
        DEFINE_DRDS_LINE0("7����    �ŵ� �ܷ�",         offerrem7,   char,         6)
        DEFINE_DRDS_LINE0("7����    �ż� �ܷ�",         bidrem7,     char,         6)
        DEFINE_DRDS_LINE0("8����    �ŵ� ȣ��",         offerho8,    char,         7)
        DEFINE_DRDS_LINE0("8����    �ż� ȣ��",         bidho8,      char,         7)
        DEFINE_DRDS_LINE0("8����    �ŵ� �ܷ�",         offerrem8,   char,         6)
        DEFINE_DRDS_LINE0("8����    �ż� �ܷ�",         bidrem8,     char,         6)
        DEFINE_DRDS_LINE0("9����    �ŵ� ȣ��",         offerho9,    char,         7)
        DEFINE_DRDS_LINE0("9����    �ż� ȣ��",         bidho9,      char,         7)
        DEFINE_DRDS_LINE0("9����    �ŵ� �ܷ�",         offerrem9,   char,         6)
        DEFINE_DRDS_LINE0("9����    �ż� �ܷ�",         bidrem9,     char,         6)
        DEFINE_DRDS_LINE0("10����   �ŵ� ȣ��",         offerho10,   char,         7)
        DEFINE_DRDS_LINE0("10����   �ż� ȣ��",         bidho10,     char,         7)
        DEFINE_DRDS_LINE0("10����   �ŵ� �ܷ�",         offerrem10,  char,         6)
        DEFINE_DRDS_LINE0("10����   �ż� �ܷ�",         bidrem10,    char,         6)
        DEFINE_DRDS_LINE0("�Ѹŵ�ȣ�� �ܷ�",            offertotrem, char,         7)
        DEFINE_DRDS_LINE0("�Ѹż� ȣ�� �ܷ�",           bidtotrem,   char,         7)

        DEFINE_DRDS_LINE0("�켱 �ŵ� �Ǽ�",             offercnt1,   char,         4)
        DEFINE_DRDS_LINE0("���� �ŵ� �Ǽ�",             offercnt2,   char,         4)
        DEFINE_DRDS_LINE0("������ �ŵ�  �Ǽ�",          offercnt3,   char,         4)
        DEFINE_DRDS_LINE0("4���� �ŵ� �Ǽ�",            offercnt4,   char,         4)
        DEFINE_DRDS_LINE0("5���� �ŵ� �Ǽ�",            offercnt5,   char,         4)
        DEFINE_DRDS_LINE0("6���� �ŵ� �Ǽ�",            offercnt6,   char,         4)
        DEFINE_DRDS_LINE0("7���� �ŵ� �Ǽ�",            offercnt7,   char,         4)
        DEFINE_DRDS_LINE0("8���� �ŵ� �Ǽ�",            offercnt8,   char,         4)
        DEFINE_DRDS_LINE0("9���� �ŵ� �Ǽ�",            offercnt9,   char,         4)
        DEFINE_DRDS_LINE0("10���� �ŵ� �Ǽ�",           offercnt10,  char,         4)
        DEFINE_DRDS_LINE0("�� �ŵ�  �Ǽ�",              offertotcnt, char,         5)
        DEFINE_DRDS_LINE0("�켱 �ż� �Ǽ�",             bidcnt1,     char,         4)
        DEFINE_DRDS_LINE0("���� �ż� �Ǽ�",             bidcnt2,     char,         4)
        DEFINE_DRDS_LINE0("������ �ż� �Ǽ�",           bidcnt3,     char,         4)
        DEFINE_DRDS_LINE0("4���� �ż� �Ǽ�",            bidcnt4,     char,         4)
       	DEFINE_DRDS_LINE0("5���� �ż� �Ǽ�",            bidcnt5,     char,         4)
        DEFINE_DRDS_LINE0("6���� �ż� �Ǽ�",            bidcnt6,     char,         4)
        DEFINE_DRDS_LINE0("7���� �ż� �Ǽ�",            bidcnt7,     char,         4)
        DEFINE_DRDS_LINE0("8���� �ż� �Ǽ�",            bidcnt8,     char,         4)
        DEFINE_DRDS_LINE0("9���� �ż� �Ǽ�",            bidcnt9,     char,         4)
        DEFINE_DRDS_LINE0("10���� �ż� �Ǽ�",           bidcnt10,    char,         4)
        DEFINE_DRDS_LINE0("�� �ż�  �Ǽ�",              bidtotcnt,   char,         5)

        DEFINE_DRDS_LINE0("�̷а� 9(7)V9(2)",           theoryprice, char,        10)
        DEFINE_DRDS_LINE0("�̰��� ����",                openyak,     char,         7)
        DEFINE_DRDS_LINE0("�̰��� ���� ����",           openyakchg,  char,         7)
        DEFINE_DRDS_LINE0("�ŷ�����(�ֹ�ü�� ���)",    tradeunit,   char,         8)
} DRDS_JC0_DATA;


class CDRDS_JC0_DATA
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
	CString m_szvalue;			/* "�����ŷ����(õ��->�鸸��)"	*/          
	CString m_szsign;			/* "���ϴ���ȣ"		*/          
	CString m_szchange;			/* "���ϴ��[9(3)v99]"	*/        
	CString m_szchgrate;		/* "�����" 			*/        
	CString m_szcvolume;		/* "ü�����"			*/          
	CString m_szofferho1;		/* "�ŵ��켱ȣ��[9(3)v9(2)]"*/          
	CString m_szbidho1;	    	/* "�ż��켱ȣ��[9(3)v9(2)]"*/            

	   

public:
	CDRDS_JC0_DATA()
	{
	}

	virtual void  Convert(DRDS_JC0_DATA* pInput)
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
		DATA_MEMCOPY(sTmp, pInput, value);			/* "�����ŷ����(õ��->�鸸��)"			*/		
		DATA_MEMCOPY(sTmp, pInput, sign);			/* "���ϴ���ȣ"			*/	
		DATA_MEMCOPY(sTmp, pInput, change);			/* "���ϴ��[9(3)v99]"			*/		
		DATA_MEMCOPY(sTmp, pInput, chgrate);		/* "�����"			*/	
		DATA_MEMCOPY(sTmp, pInput, cvolume);		/* "ü�����"			*/		
		DATA_MEMCOPY(sTmp, pInput, offerho1);		/* "�ŵ��켱ȣ��[9(3)v9(2)]"			*/		
		DATA_MEMCOPY(sTmp, pInput, bidho1);		    /* "�ż��켱ȣ��[9(3)v9(2)]"				*/		
	}
};

/***** ���� ���簡 (JH0) *******************************************/
/***** �����ֽ� ���� ȣ�� (�ۼ��� : 2008. 04) *********************/
/*******************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0( "�����ڵ�",                       jmcode,         char,   8)	
} DRDS_JH0_KEY;

typedef struct {
				DEFINE_DRDS_LINE0("�����ڵ�",              jmcode,      char,        8)
				DEFINE_DRDS_LINE0("���� SEQ",              jmcodeseq,   char,        4)
				DEFINE_DRDS_LINE0("ȣ�� �����ð�",         time,        char,        6)
				
				DEFINE_DRDS_LINE0("�ŵ��켱ȣ��",          offerho1,    char,        7)
				DEFINE_DRDS_LINE0("�ż��켱ȣ��",          bidho1,      char,        7)
				DEFINE_DRDS_LINE0("�ŵ��ܷ�",              offerrem1,   char,        6)
				DEFINE_DRDS_LINE0("�ż��ܷ�",              bidrem1,     char,        6)
				DEFINE_DRDS_LINE0("���� �ŵ�ȣ��",         offerho2,    char,        7)
				DEFINE_DRDS_LINE0("���� �ż�ȣ��",         bidho2,      char,        7)
				DEFINE_DRDS_LINE0("���� �ŵ�ȣ�� �ܷ�",    offerrem2,   char,        6)
				DEFINE_DRDS_LINE0("�����ż�ȣ�� �ܷ�",     bidrem2,     char,        6)
				DEFINE_DRDS_LINE0("������ �ŵ�ȣ��",       offerho3,    char,        7)
				DEFINE_DRDS_LINE0("������ �ż�ȣ��",       bidho3,      char,        7)
				DEFINE_DRDS_LINE0("������ �ŵ�ȣ�� �ܷ�",  offerrem3,   char,        6)
				DEFINE_DRDS_LINE0("�������ż�ȣ�� �ܷ�",   bidrem3,     char,        6)
				DEFINE_DRDS_LINE0("4����    �ŵ� ȣ��",    offerho4,    char,        7)
				DEFINE_DRDS_LINE0("4����    �ż� ȣ��",    bidho4,      char,        7)
				DEFINE_DRDS_LINE0("4����    �ŵ� �ܷ�",    offerrem4,   char,        6)
				DEFINE_DRDS_LINE0("4����    �ż� �ܷ�",    bidrem4,     char,        6)
				DEFINE_DRDS_LINE0("5����    �ŵ� ȣ��",    offerho5,    char,        7)
				DEFINE_DRDS_LINE0("5����    �ż� ȣ��",    bidho5,      char,        7)
				DEFINE_DRDS_LINE0("5����    �ŵ� �ܷ�",    offerrem5,   char,        6)
				DEFINE_DRDS_LINE0("5����    �ż� �ܷ�",    bidrem5,     char,        6)
				DEFINE_DRDS_LINE0("6����    �ŵ� ȣ��",    offerho6,    char,        7)
				DEFINE_DRDS_LINE0("6����    �ż� ȣ��",    bidho6,      char,        7)
				DEFINE_DRDS_LINE0("6����    �ŵ� �ܷ�",    offerrem6,   char,        6)
				DEFINE_DRDS_LINE0("6����    �ż� �ܷ�",    bidrem6,     char,        6)
				DEFINE_DRDS_LINE0("7����    �ŵ� ȣ��",    offerho7,    char,        7)
				DEFINE_DRDS_LINE0("7����    �ż� ȣ��",    bidho7,      char,        7)
				DEFINE_DRDS_LINE0("7����    �ŵ� �ܷ�",    offerrem7,   char,        6)
				DEFINE_DRDS_LINE0("7����    �ż� �ܷ�",    bidrem7,     char,        6)
				DEFINE_DRDS_LINE0("8����    �ŵ� ȣ��",    offerho8,    char,        7)
				DEFINE_DRDS_LINE0("8����    �ż� ȣ��",    bidho8,      char,        7)
				DEFINE_DRDS_LINE0("8����    �ŵ� �ܷ�",    offerrem8,   char,        6)
				DEFINE_DRDS_LINE0("8����    �ż� �ܷ�",    bidrem8,     char,        6)
				DEFINE_DRDS_LINE0("9����    �ŵ� ȣ��",    offerho9,    char,        7)
				DEFINE_DRDS_LINE0("9����    �ż� ȣ��",    bidho9,      char,        7)
				DEFINE_DRDS_LINE0("9����    �ŵ� �ܷ�",    offerrem9,   char,        6)
				DEFINE_DRDS_LINE0("9����    �ż� �ܷ�",    bidrem9,     char,        6)
				DEFINE_DRDS_LINE0("10����   �ŵ� ȣ��",    offerho10,   char,        7)
				DEFINE_DRDS_LINE0("10����   �ż� ȣ��",    bidho10,     char,        7)
				DEFINE_DRDS_LINE0("10����   �ŵ� �ܷ�",    offerrem10,  char,        6)
				DEFINE_DRDS_LINE0("10����   �ż� �ܷ�",    bidrem10,    char,        6)
				DEFINE_DRDS_LINE0("�Ѹŵ�ȣ�� �ܷ�",       offertotrem, char,        7)
				DEFINE_DRDS_LINE0("�Ѹż�ȣ�� �ܷ�",       bidtotrem,   char,        7)
				
				DEFINE_DRDS_LINE0("�켱 �ŵ�    �Ǽ�",     offercnt1,   char,        4)
				DEFINE_DRDS_LINE0("���� �ŵ�    �Ǽ�",     offercnt2,   char,        4)
				DEFINE_DRDS_LINE0("������ �ŵ� �Ǽ�",      offercnt3,   char,        4)
				DEFINE_DRDS_LINE0("4����    �ŵ� �Ǽ�",    offercnt4,   char,        4)
				DEFINE_DRDS_LINE0("5����    �ŵ� �Ǽ�",    offercnt5,   char,        4)
				DEFINE_DRDS_LINE0("6����    �ŵ� �Ǽ�",    offercnt6,   char,        4)
				DEFINE_DRDS_LINE0("7����    �ŵ� �Ǽ�",    offercnt7,   char,        4)
				DEFINE_DRDS_LINE0("8����    �ŵ� �Ǽ�",    offercnt8,   char,        4)
				DEFINE_DRDS_LINE0("9����    �ŵ� �Ǽ�",    offercnt9,   char,        4)
				DEFINE_DRDS_LINE0("10����   �ŵ� �Ǽ�",    offercnt10,  char,        4)
				DEFINE_DRDS_LINE0("�� �ŵ� �Ǽ�",          offertotcnt, char,        5)
				
				DEFINE_DRDS_LINE0("�켱 �ż�    �Ǽ�",     bidcnt1,     char,        4)
				DEFINE_DRDS_LINE0("���� �ż�    �Ǽ�",     bidcnt2,     char,        4)
				DEFINE_DRDS_LINE0("������ �ż� �Ǽ�",      bidcnt3,     char,        4)
				DEFINE_DRDS_LINE0("4����    �ż� �Ǽ�",    bidcnt4,     char,        4)
				DEFINE_DRDS_LINE0("5����    �ż� �Ǽ�",    bidcnt5,     char,        4)
				DEFINE_DRDS_LINE0("6����    �ż� �Ǽ�",    bidcnt6,     char,        4)
				DEFINE_DRDS_LINE0("7����    �ż� �Ǽ�",    bidcnt7,     char,        4)
				DEFINE_DRDS_LINE0("8����    �ż� �Ǽ�",    bidcnt8,     char,        4)
				DEFINE_DRDS_LINE0("9����    �ż� �Ǽ�",    bidcnt9,     char,        4)
				DEFINE_DRDS_LINE0("10����   �ż� �Ǽ�",    bidcnt10,    char,        4)
				DEFINE_DRDS_LINE0("�� �ż� �Ǽ�",          bidtotcnt,   char,        5)
} DRDS_JH0_DATA;

typedef struct 
{
	DEFINE_DRDS_LINE0("�����ڵ�",                   jmcode,     char,         8)	
} DRDS_JM0_KEY;

typedef struct {
				DEFINE_DRDS_LINE0("�����ڵ�",                   jmcode,     char,         8)
        DEFINE_DRDS_LINE0("�ð�",                       time,       char,         6)
        DEFINE_DRDS_LINE0("�̰������� ����(����:���)", openyak,    char,         7)
} DRDS_JM0_DATA;
	
#endif // AFX_JC0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_
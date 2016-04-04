#if !defined(AFX_OPC_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_OPC_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_

#include "../include/Data_Common.h"

/***** �ɼ� ���簡 (OPC) *******************************************/
/***** �����ֽ� �ɼ� ü��  (�ۼ��� : 2008. 04)*********************/
/*******************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0( "�����ڵ�",                       jmcode,         char,   8)	
} DRDS_OPC_KEY;

typedef struct {
        DEFINE_DRDS_LINE0("�����ڵ�",                   jmcode,      char,         8)
        DEFINE_DRDS_LINE0("���簡",                     price,       char,         6)
		DEFINE_DRDS_LINE0("���ϴ��",                   change,      char,         6)
		DEFINE_DRDS_LINE0("���ϴ�� ��ȣ",              sign,        char,         1)
        DEFINE_DRDS_LINE0("�����",                     chgrate,     char,         6)

        DEFINE_DRDS_LINE0("�ð�",                       open,        char,         6)
        DEFINE_DRDS_LINE0("��",                       high,        char,         6)
        DEFINE_DRDS_LINE0("����",                       low,         char,         6)
        DEFINE_DRDS_LINE0("���� ü�����",              volume,      char,         7)
        DEFINE_DRDS_LINE0("�����ŷ����(õ��)",         value,       char,        15)
        
        DEFINE_DRDS_LINE0("����seq",                    jmcodeseq,	 char,         4)
        DEFINE_DRDS_LINE0("ü�����",                   cvolume,     char,         7)
		DEFINE_DRDS_LINE0("ü��ð�",                   time,        char,         6)

        DEFINE_DRDS_LINE0("�ŵ��ֿ켱ȣ��",             offerho1,    char,         6)
        DEFINE_DRDS_LINE0("�ŵ��ֿ켱ȣ���ܷ�",         offerrem1,   char,         7)
		DEFINE_DRDS_LINE0("�ŵ� �ֿ켱ȣ�� �Ǽ�",       offercnt1,   char,         5)

		DEFINE_DRDS_LINE0("�ŵ� 2����ȣ��",             offerho2,    char,         6)
        DEFINE_DRDS_LINE0("�ŵ� 2����ȣ���ܷ�",         offerrem2,   char,         7)
		DEFINE_DRDS_LINE0("�ŵ� 2����ȣ�� �Ǽ�",        offercnt2,   char,         5)

		DEFINE_DRDS_LINE0("�ŵ� 3����ȣ��",             offerho3,    char,         6)
        DEFINE_DRDS_LINE0("�ŵ� 3����ȣ���ܷ�",         offerrem3,   char,         7)
		DEFINE_DRDS_LINE0("�ŵ� 3����ȣ�� �Ǽ�",        offercnt3,   char,         5)

		DEFINE_DRDS_LINE0("�ŵ� 4����ȣ��",             offerho4,    char,         6)
        DEFINE_DRDS_LINE0("�ŵ� 4����ȣ���ܷ�",         offerrem4,   char,         7)
		DEFINE_DRDS_LINE0("�ŵ� 4����ȣ�� �Ǽ�",        offercnt4,   char,         5)

		DEFINE_DRDS_LINE0("�ŵ� 5����ȣ��",             offerho5,    char,         6)
        DEFINE_DRDS_LINE0("�ŵ� 5����ȣ���ܷ�",         offerrem5,   char,         7)
		DEFINE_DRDS_LINE0("�ŵ� 5����ȣ�� �Ǽ�",        offercnt5,   char,         5)

		DEFINE_DRDS_LINE0("�ż��ֿ켱ȣ��",             bidho1,    char,         6)
        DEFINE_DRDS_LINE0("�ż��ֿ켱ȣ���ܷ�",         bidrem1,   char,         7)
		DEFINE_DRDS_LINE0("�ż� �ֿ켱ȣ�� �Ǽ�",       bidcnt1,   char,         5)

		DEFINE_DRDS_LINE0("�ż� 2����ȣ��",             bidho2,    char,         6)
        DEFINE_DRDS_LINE0("�ż� 2����ȣ���ܷ�",         bidrem2,   char,         7)
		DEFINE_DRDS_LINE0("�ż� 2����ȣ�� �Ǽ�",        bidcnt2,   char,         5)

		DEFINE_DRDS_LINE0("�ż� 3����ȣ��",             bidho3,    char,         6)
        DEFINE_DRDS_LINE0("�ż� 3����ȣ���ܷ�",         bidrem3,   char,         7)
		DEFINE_DRDS_LINE0("�ż� 3����ȣ�� �Ǽ�",        bidcnt3,   char,         5)

		DEFINE_DRDS_LINE0("�ż� 4����ȣ��",             bidho4,    char,         6)
        DEFINE_DRDS_LINE0("�ż� 4����ȣ���ܷ�",         bidrem4,   char,         7)
		DEFINE_DRDS_LINE0("�ż� 4����ȣ�� �Ǽ�",        bidcnt4,   char,         5)

		DEFINE_DRDS_LINE0("�ż� 5����ȣ��",             bidho5,    char,         6)
        DEFINE_DRDS_LINE0("�ż� 5����ȣ���ܷ�",         bidrem5,   char,         7)
		DEFINE_DRDS_LINE0("�ż� 5����ȣ�� �Ǽ�",        bidcnt5,   char,         5)

		DEFINE_DRDS_LINE0("�ŵ� ��ȣ������",            offertotrem,    char,         7)
        DEFINE_DRDS_LINE0("�ż� ��ȣ������",			bidtotrem,		char,         7)
		DEFINE_DRDS_LINE0("�ŵ� ��ȣ���Ǽ�",			offertotcnt,    char,         6)		
		DEFINE_DRDS_LINE0("�ż� ��ȣ���Ǽ�",            bidtotcnt,      char,         6)
        DEFINE_DRDS_LINE0("delta S9(3)V9(2)",			delta,			char,         7)
		DEFINE_DRDS_LINE0("gmma S9(3)V9(3)",			gmma,			char,         7)
		DEFINE_DRDS_LINE0("vega S9(3)V9(3)",			vega,			char,         7)
		DEFINE_DRDS_LINE0("theta S9(3)V9(3)",			theta,			char,         7)
		DEFINE_DRDS_LINE0("rho S9(3)V9(3)",				rho,			char,         7)
} DRDS_OPC_DATA;


class CDRDS_OPC_DATA
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
	CDRDS_OPC_DATA()
	{
	}

	virtual void  Convert(DRDS_OPC_DATA* pInput)
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

/***** �ɼ� ���簡 (OPH) *******************************************/
/***** �����ֽ� �ɼ� ȣ�� (�ۼ��� : 2008. 04) *********************/
/*******************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0( "�����ڵ�",                       jmcode,         char,   8)	
} DRDS_OPH_KEY;

typedef struct {
		DEFINE_DRDS_LINE0("�����ڵ�",					jmcode,      char,        8)
		DEFINE_DRDS_LINE0("���� SEQ",					jmcodeseq,   char,        4)
		DEFINE_DRDS_LINE0("ȣ�� �����ð�",				time,        char,        6)
		
		DEFINE_DRDS_LINE0("�ŵ��ֿ켱ȣ��",             offerho1,    char,         6)
        DEFINE_DRDS_LINE0("�ŵ��ֿ켱ȣ���ܷ�",         offerrem1,   char,         7)
		DEFINE_DRDS_LINE0("�ŵ� �ֿ켱ȣ�� �Ǽ�",       offercnt1,   char,         5)

		DEFINE_DRDS_LINE0("�ŵ� 2����ȣ��",             offerho2,    char,         6)
        DEFINE_DRDS_LINE0("�ŵ� 2����ȣ���ܷ�",         offerrem2,   char,         7)
		DEFINE_DRDS_LINE0("�ŵ� 2����ȣ�� �Ǽ�",        offercnt2,   char,         5)

		DEFINE_DRDS_LINE0("�ŵ� 3����ȣ��",             offerho3,    char,         6)
        DEFINE_DRDS_LINE0("�ŵ� 3����ȣ���ܷ�",         offerrem3,   char,         7)
		DEFINE_DRDS_LINE0("�ŵ� 3����ȣ�� �Ǽ�",        offercnt3,   char,         5)

		DEFINE_DRDS_LINE0("�ŵ� 4����ȣ��",             offerho4,    char,         6)
        DEFINE_DRDS_LINE0("�ŵ� 4����ȣ���ܷ�",         offerrem4,   char,         7)
		DEFINE_DRDS_LINE0("�ŵ� 4����ȣ�� �Ǽ�",        offercnt4,   char,         5)

		DEFINE_DRDS_LINE0("�ŵ� 5����ȣ��",             offerho5,    char,         6)
        DEFINE_DRDS_LINE0("�ŵ� 5����ȣ���ܷ�",         offerrem5,   char,         7)
		DEFINE_DRDS_LINE0("�ŵ� 5����ȣ�� �Ǽ�",        offercnt5,   char,         5)

		DEFINE_DRDS_LINE0("�ż��ֿ켱ȣ��",             bidho1,    char,         6)
        DEFINE_DRDS_LINE0("�ż��ֿ켱ȣ���ܷ�",         bidrem1,   char,         7)
		DEFINE_DRDS_LINE0("�ż� �ֿ켱ȣ�� �Ǽ�",       bidcnt1,   char,         5)

		DEFINE_DRDS_LINE0("�ż� 2����ȣ��",             bidho2,    char,         6)
        DEFINE_DRDS_LINE0("�ż� 2����ȣ���ܷ�",         bidrem2,   char,         7)
		DEFINE_DRDS_LINE0("�ż� 2����ȣ�� �Ǽ�",        bidcnt2,   char,         5)

		DEFINE_DRDS_LINE0("�ż� 3����ȣ��",             bidho3,    char,         6)
        DEFINE_DRDS_LINE0("�ż� 3����ȣ���ܷ�",         bidrem3,   char,         7)
		DEFINE_DRDS_LINE0("�ż� 3����ȣ�� �Ǽ�",        bidcnt3,   char,         5)

		DEFINE_DRDS_LINE0("�ż� 4����ȣ��",             bidho4,    char,         6)
        DEFINE_DRDS_LINE0("�ż� 4����ȣ���ܷ�",         bidrem4,   char,         7)
		DEFINE_DRDS_LINE0("�ż� 4����ȣ�� �Ǽ�",        bidcnt4,   char,         5)

		DEFINE_DRDS_LINE0("�ż� 5����ȣ��",             bidho5,    char,         6)
        DEFINE_DRDS_LINE0("�ż� 5����ȣ���ܷ�",         bidrem5,   char,         7)
		DEFINE_DRDS_LINE0("�ż� 5����ȣ�� �Ǽ�",        bidcnt5,   char,         5)

		DEFINE_DRDS_LINE0("�ŵ� ��ȣ������",            offertotrem,    char,         7)
        DEFINE_DRDS_LINE0("�ż� ��ȣ������",			bidtotrem,		char,         7)
		DEFINE_DRDS_LINE0("�ŵ� ��ȣ���Ǽ�",			offertotcnt,    char,         6)		
		DEFINE_DRDS_LINE0("�ż� ��ȣ���Ǽ�",            bidtotcnt,      char,         6)
} DRDS_OPH_DATA;

typedef struct 
{
	DEFINE_DRDS_LINE0("�ɼ��ڵ�",                   jmcode,     char,         8)	
} DRDS_OM0_KEY;

typedef struct {
		DEFINE_DRDS_LINE0("�ɼ��ڵ�",					jmcode,			char,         8)
        DEFINE_DRDS_LINE0("�ð�",                       time,			char,         6)
        DEFINE_DRDS_LINE0("�̰������� ����(����:���)", openyak,		char,         7)
		DEFINE_DRDS_LINE0("�̰������� ����(����:���)", openyak_chg,	char,         6)
} DRDS_OM0_DATA;
	
#endif // AFX_OPC_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_

#if !defined(AFX_S31_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_S31_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


#include "../include/Data_Common.h"

//---- ���簡 (S31) --------------------------------------------------
//     SVR : �켱ȣ��, ü��, �⼼, ����, RECOVERY, ����������
//--------------------------------------------------------------------

typedef struct 
{
	DEFINE_DRDS_LINE0( "�����ڵ�",                       code,         char,   6)	
} DRDS_S31_KEY;

//char sign[1]; /* �����ȣ                       M  */
              /* '1':����, '2':���, '3':����      */
              /* '4':����, '5':�϶�, '6':�⼼����  */
              /* '7':�⼼���, '8':�⼼����        */
              /* '9':�⼼�϶�, '0':�⼼����        */

typedef struct {
	DEFINE_DRDS_LINE0( "�����ڵ�",                       code,         char,   6)
    DEFINE_DRDS_LINE0( "�ð�(HH:MM:SS)",                 time,         char,   6)
    DEFINE_DRDS_LINE0( "�����ȣ",                       sign,         char,   1)  
    DEFINE_DRDS_LINE0( "�����",                         change,       char,   9)
    DEFINE_DRDS_LINE0( "���簡",                         price,        char,   9)
    DEFINE_DRDS_LINE0( "�����",                         chrate,       char,   5)
    DEFINE_DRDS_LINE0( "����ð�",                       openam,       char,   9)
    DEFINE_DRDS_LINE0( "��",                           high,         char,   9)
    DEFINE_DRDS_LINE0( "����",                           low,          char,   9)
    DEFINE_DRDS_LINE0( "�ŵ�ȣ��",                       offer,        char,   9)
    DEFINE_DRDS_LINE0( "�ż�ȣ��",                       bid,          char,   9)
    DEFINE_DRDS_LINE0( "�����ŷ���",                     volume,       char,  12)
    DEFINE_DRDS_LINE0( "�����ŷ���",                     movolume,     char,   8)
    DEFINE_DRDS_LINE0( "�ŷ����",                       value,        char,  14)
    DEFINE_DRDS_LINE0( "�Ÿű���",                       maegubun,     char,   1)
    DEFINE_DRDS_LINE0( "�屸��",                         janggubun,    char,   1)
    DEFINE_DRDS_LINE0( "CB����",                         cbgubun,      char,   1)
    DEFINE_DRDS_LINE0( "STOP",                           stop,         char,   1)
    DEFINE_DRDS_LINE0( "�ð��ܰŷ���",                   over_volume,  char,   9)
    DEFINE_DRDS_LINE0( "�ð��ܴ뷮�Ÿ�",                 rep_volume,   char,   9)
    DEFINE_DRDS_LINE0( "�ŵ�ȣ���ܷ�",                   offerrem,     char,  10)
    DEFINE_DRDS_LINE0( "�ż�ȣ���ܷ�",                   bidrem,       char,  10)
    DEFINE_DRDS_LINE0( "�Ѹŵ�ȣ���ܷ�",                 T_offerrem,   char,  10)
    DEFINE_DRDS_LINE0( "�Ѹż�ȣ���ܷ�",                 T_bidrem,     char,  10)
    DEFINE_DRDS_LINE0( "�����ż���",					bidvol,		   char,  10)
    DEFINE_DRDS_LINE0( "�ż�����",						bidstrong,	   char,   9)
    DEFINE_DRDS_LINE0( "�����ŷ���2",					movolume2,	   char,   8)	// ��ȣȭ���� ������� �ŷ���
    DEFINE_DRDS_LINE0( "�����ż���2",					bidvol2,	   char,  10)	// ��ȣȭ���� ������� �ż���
    DEFINE_DRDS_LINE0( "�ż�����2",						bidstrong2,	   char,   9)	// ��ȣȭ���� ������� ����
	DEFINE_DRDS_LINE0( "�Ѹż�ȣ���ܷ�2",				Ebidrem,	   char,  11)	// �Ѹż�ȣ���ܷ�2	
} DRDS_S31_DATA;

class CDRDS_S31_DATA
{
public: //Variable
	CString m_szcode;			/* "�����ڵ�"			*/          
	CString m_sztime;			/* "�ð�(HH:MM:SS)"		*/    
	CString m_szsign;			/* "�����ȣ"			*/          
	CString m_szchange;			/* "�����"				*/            
	CString m_szprice;			/* "���簡"				*/            
	CString m_szchrate;			/* "�����"				*/            
	CString m_szopenam;			/* "����ð�"			*/          
	CString m_szhigh;			/* "��"				*/              
	CString m_szlow;			/* "����"				*/              
	CString m_szoffer;			/* "�ŵ�ȣ��"			*/          
	CString m_szbid;			/* "�ż�ȣ��"			*/          
	CString m_szvolume;			/* "�����ŷ���"			*/        
	CString m_szmovolume;		/* "�����ŷ���"			*/        
	CString m_szvalue;			/* "�ŷ����"			*/          
	CString m_szmaegubun;		/* "�Ÿű���"			*/          
	CString m_szjanggubun;		/* "�屸��"				*/            
	CString m_szcbgubun;		/* "CB����"				*/            
	CString m_szstop;			/* "STOP"				*/              
	CString m_szover_volume;	/* "�ð��ܰŷ���"		*/      
	CString m_szrep_volume;		/* "�ð��ܴ뷮�Ÿ�"		*/    
	CString m_szofferrem;		/* "�ŵ�ȣ���ܷ�"		*/      
	CString m_szbidrem;			/* "�ż�ȣ���ܷ�"		*/      
	CString m_szT_offerrem;		/* "�Ѹŵ�ȣ���ܷ�"		*/    
	CString m_szT_bidrem;		/* "�Ѹż�ȣ���ܷ�"		*/    

	CString m_szbidvol;			/* "�����ż���"			*/    
	CString m_szbidstrong;		/* "�ż�����"			*/    
	CString m_szmovolume2;		/* "�����ŷ���2"		*/    
	CString m_szbidvol2;		/* "�����ż���2"		*/    
	CString m_szbidstrong2;		/* "�ż�����2"			*/   
	CString m_szEbidrem;		// �Ѹż�ȣ���ܷ�2	

	

public:
	CDRDS_S31_DATA()
	{
	}

	virtual void  Convert(DRDS_S31_DATA* pInput)
	{
		CString sTemp1 ;
		char sTmp[20+1];

		DATA_MEMCOPY(sTmp, pInput, code);			/* "�����ڵ�"			*/	
		DATA_MEMCOPY(sTmp, pInput, time);			/* "�ð�(HH:MM:SS)"		*/		
		DATA_MEMCOPY(sTmp, pInput, sign);			/* "�����ȣ"			*/		
		DATA_MEMCOPY(sTmp, pInput, change);			/* "�����"				*/		
		DATA_MEMCOPY(sTmp, pInput, price);			/* "���簡"				*/		
		DATA_MEMCOPY(sTmp, pInput, chrate);			/* "�����"				*/		
		DATA_MEMCOPY(sTmp, pInput, openam);			/* "����ð�"			*/		
		DATA_MEMCOPY(sTmp, pInput, high);			/* "��"				*/		
		DATA_MEMCOPY(sTmp, pInput, low);			/* "����"				*/		
		DATA_MEMCOPY(sTmp, pInput, offer);			/* "�ŵ�ȣ��"			*/		
		DATA_MEMCOPY(sTmp, pInput, bid);			/* "�ż�ȣ��"			*/		
		DATA_MEMCOPY(sTmp, pInput, volume);			/* "�����ŷ���"			*/		
		DATA_MEMCOPY(sTmp, pInput, movolume);		/* "�����ŷ���"			*/		
		DATA_MEMCOPY(sTmp, pInput, value);			/* "�ŷ����"			*/		
		DATA_MEMCOPY(sTmp, pInput, maegubun);		/* "�Ÿű���"			*/		
		DATA_MEMCOPY(sTmp, pInput, janggubun);		/* "�屸��"				*/		
		DATA_MEMCOPY(sTmp, pInput, cbgubun);		/* "CB����"				*/		
		DATA_MEMCOPY(sTmp, pInput, stop);			/* "STOP"				*/		
		DATA_MEMCOPY(sTmp, pInput, over_volume);	/* "�ð��ܰŷ���"		*/		
		DATA_MEMCOPY(sTmp, pInput, rep_volume);		/* "�ð��ܴ뷮�Ÿ�"		*/		
		DATA_MEMCOPY(sTmp, pInput, offerrem);		/* "�ŵ�ȣ���ܷ�"		*/		
		DATA_MEMCOPY(sTmp, pInput, bidrem);			/* "�ż�ȣ���ܷ�"		*/		
		DATA_MEMCOPY(sTmp, pInput, T_offerrem);		/* "�Ѹŵ�ȣ���ܷ�"		*/		
		DATA_MEMCOPY(sTmp, pInput, T_bidrem);		/* "�Ѹż�ȣ���ܷ�"		*/			
	
		DATA_MEMCOPY(sTmp, pInput, bidvol);			/* "�����ż���"			*/			
		DATA_MEMCOPY(sTmp, pInput, bidstrong);		/* "�ż�����"			*/			
		DATA_MEMCOPY(sTmp, pInput, movolume2);		/* "�����ŷ���2"		*/			
		DATA_MEMCOPY(sTmp, pInput, bidvol2);		/* "�����ż���2"		*/			
		DATA_MEMCOPY(sTmp, pInput, bidstrong2);		/* "�ż�����2"			*/			
		DATA_MEMCOPY(sTmp, pInput, Ebidrem);		/* "�Ѹż�ȣ���ܷ�2"			*/			
	}
};

#endif // AFX_S31_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_

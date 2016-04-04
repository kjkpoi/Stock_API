#if !defined(AFX_MH0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_MH0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


#include "../include/Data_Common.h"

/***** CME ���� ȣ�� (MH0) *****************************************/
/***** SVR : ��ǰ���� ȣ�� *****************************************/
/*******************************************************************/

typedef struct 
{
//	DEFINE_DRDS_LINE0("�����ڵ�",		fuitem,         char,   8)
	
    DEFINE_DRDS_LINE0("�����ڵ�",      jmcode,       char,   8);
	
} DRDS_MH0_KEY;

typedef struct {
    DEFINE_DRDS_LINE0("�����ڵ�",                       jmcode,       char,   8)  
    DEFINE_DRDS_LINE0("����SEQ",                        jmcodeseq,    char,   2)  
    DEFINE_DRDS_LINE0("�ŵ��켱ȣ��[9(4)v9(2)]",        offerho1,     char,   7)  
    DEFINE_DRDS_LINE0("�ż��켱ȣ��[9(4)v9(2)]",        bidho1,       char,   7)  
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
    DEFINE_DRDS_LINE0("ȣ�������ð�",                   hotime,       char,   6)  
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
    DEFINE_DRDS_LINE0("�� �ż� �Ǽ�",                   bidtotcnt,    char,   5)  
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
    DEFINE_DRDS_LINE0("ȣ�����ܷ� ����",                totrem_chg,   char,   7)	
	                                                                                
} DRDS_MH0_DATA;                                                                  

#endif // AFX_MH0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


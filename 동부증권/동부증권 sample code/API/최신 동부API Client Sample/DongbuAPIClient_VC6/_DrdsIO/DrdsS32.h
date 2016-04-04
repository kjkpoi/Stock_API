#if !defined(AFX_S32_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_S32_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_

// #include "../CommonTR/Drds_S31.h"
// �ۼ� : ���ؿ�
// ���� : 2005.11.23(��)

#include "Data_Common.h"

//---- ���簡 (S32) --------------------------------------------------
//     SVR : �켱ȣ��, ü��, �⼼, ����, RECOVERY, ����������
//--------------------------------------------------------------------

typedef struct 
{
	DEFINE_DRDS_LINE0( "�����ڵ�",                       code,         char,   6)	
} DRDS_S32_KEY;

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

    DEFINE_DRDS_LINE0( "�����ż���",					 bidvol,	   char,  10)
    DEFINE_DRDS_LINE0( "�ż�����",						 bidstrong,    char,   9)
    DEFINE_DRDS_LINE0( "�����ŷ���2",					 movolume2,    char,   8)
    DEFINE_DRDS_LINE0( "�����ż���2",					 bidvol2,      char,  10)
    DEFINE_DRDS_LINE0( "�ż�����2",						 bidstrong2,   char,   9)
} DRDS_S32_DATA;

#endif // AFX_S31_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_
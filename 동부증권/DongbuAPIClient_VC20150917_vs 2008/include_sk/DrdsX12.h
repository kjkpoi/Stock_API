#if !defined(AFX_X12_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_X12_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


#include "../include/Data_Common.h"


/****** ȣ���ܷ� (X-2) **********************************************/
/****** SVR : ȣ���ܷ� **********************************************/
/********************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0( "�����ڵ�",                       code,         char,   6)	
} DRDS_X12_KEY;

typedef struct {
	DEFINE_DRDS_LINE0("�����ڵ�",                       code,         char,   6)
    DEFINE_DRDS_LINE0("�ð� (HH:MM:SS)",                time,         char,   6)
    DEFINE_DRDS_LINE0("�ŵ�ȣ��(��)",                   offer,        char,   9)
    DEFINE_DRDS_LINE0("�ż�ȣ��(��)",                   bid,          char,   9)
    DEFINE_DRDS_LINE0("�ŵ�ȣ���ܷ�(��)",               offerrem,     char,  10)
    DEFINE_DRDS_LINE0("�ż�ȣ���ܷ�(��)",               bidrem,       char,  10)
    DEFINE_DRDS_LINE0("���ŵ�ȣ��(��)",                 P_offer,      char,   9)
    DEFINE_DRDS_LINE0("���ż�ȣ��(��)",                 P_bid,        char,   9)
    DEFINE_DRDS_LINE0("���ŵ�ȣ���ܷ�(��)",             P_offerrem,   char,  10)
    DEFINE_DRDS_LINE0("���ż�ȣ���ܷ�(��)",             P_bidrem,     char,  10)
    DEFINE_DRDS_LINE0("�����ŵ�ȣ��(��)",               S_offer,      char,   9)
    DEFINE_DRDS_LINE0("�����ż�ȣ��(��)",               S_bid,        char,   9)
    DEFINE_DRDS_LINE0("�����ŵ�ȣ���ܷ�(��)",           S_offerrem,   char,  10)
    DEFINE_DRDS_LINE0("�����ż�ȣ���ܷ�(��)",           S_bidrem,     char,  10)
    DEFINE_DRDS_LINE0("4���ŵ�ȣ��(��)",                S4_offer,     char,   9)
    DEFINE_DRDS_LINE0("4���ż�ȣ��(��)",                S4_bid,       char,   9)
    DEFINE_DRDS_LINE0("4���ŵ�ȣ���ܷ�(��)",            S4_offerrem,  char,  10)
    DEFINE_DRDS_LINE0("4���ż�ȣ���ܷ�(��)",            S4_bidrem,    char,  10)
    DEFINE_DRDS_LINE0("5���ŵ�ȣ��(��)",                S5_offer,     char,   9)
    DEFINE_DRDS_LINE0("5���ż�ȣ��(��)",                S5_bid,       char,   9)
    DEFINE_DRDS_LINE0("5���ŵ�ȣ���ܷ�(��)",            S5_offerrem,  char,  10)
    DEFINE_DRDS_LINE0("5���ż�ȣ���ܷ�(��)",            S5_bidrem,    char,  10)
    DEFINE_DRDS_LINE0("6���ŵ�ȣ��(��)",                S6_offer,     char,   9)
    DEFINE_DRDS_LINE0("6���ż�ȣ��(��)",                S6_bid,       char,   9)
	DEFINE_DRDS_LINE0("6���ŵ�ȣ���ܷ�(��)",            S6_offerrem,  char,  10)
    DEFINE_DRDS_LINE0("6���ż�ȣ���ܷ�(��)",            S6_bidrem,    char,  10)
    DEFINE_DRDS_LINE0("7���ŵ�ȣ��(��)",                S7_offer,     char,   9)
    DEFINE_DRDS_LINE0("7���ż�ȣ��(��)",                S7_bid,       char,   9)
    DEFINE_DRDS_LINE0("7���ŵ�ȣ���ܷ�(��)",            S7_offerrem,  char,  10)
    DEFINE_DRDS_LINE0("7���ż�ȣ���ܷ�(��)",            S7_bidrem,    char,  10)
    DEFINE_DRDS_LINE0("8���ŵ�ȣ��(��)",                S8_offer,     char,   9)
    DEFINE_DRDS_LINE0("8���ż�ȣ��(��)",                S8_bid,       char,   9)
    DEFINE_DRDS_LINE0("8���ŵ�ȣ���ܷ�(��)",            S8_offerrem,  char,  10)
    DEFINE_DRDS_LINE0("8���ż�ȣ���ܷ�(��)",            S8_bidrem,    char,  10)
    DEFINE_DRDS_LINE0("9���ŵ�ȣ��(��)",                S9_offer,     char,   9)
    DEFINE_DRDS_LINE0("9���ż�ȣ��(��)",                S9_bid,       char,   9)
    DEFINE_DRDS_LINE0("9���ŵ�ȣ���ܷ�(��)",            S9_offerrem,  char,  10)
    DEFINE_DRDS_LINE0("9���ż�ȣ���ܷ�(��)",            S9_bidrem,    char,  10)
    DEFINE_DRDS_LINE0("10���ŵ�ȣ��(��)",               S10_offer,    char,   9)
    DEFINE_DRDS_LINE0("10���ż�ȣ��(��)",               S10_bid,      char,   9)
    DEFINE_DRDS_LINE0("10���ŵ�ȣ���ܷ�(��)",           S10_offerrem, char,  10)
    DEFINE_DRDS_LINE0("10���ż�ȣ���ܷ�(��)",           S10_bidrem,   char,  10)
    DEFINE_DRDS_LINE0("�ŵ�ȣ��     ������(��)",        offerchg,     char,  10)
    DEFINE_DRDS_LINE0("�ż�ȣ��     ������(��)",        bidchg,       char,  10)
    DEFINE_DRDS_LINE0("���ŵ�ȣ��   ������(��)",        P_offerchg,   char,  10)
    DEFINE_DRDS_LINE0("���ż�ȣ��   ������(��)",        P_bidchg,     char,  10)
    DEFINE_DRDS_LINE0("�����ŵ�ȣ�� ������(��)",        S_offerchg,   char,  10)
    DEFINE_DRDS_LINE0("�����ż�ȣ�� ������(��)",        S_bidchg,     char,  10)
	DEFINE_DRDS_LINE0("4���ŵ�ȣ��  ������(��)",        S4_offerchg,  char,  10)
    DEFINE_DRDS_LINE0("4���ż�ȣ��  ������(��)",        S4_bidchg,    char,  10)
    DEFINE_DRDS_LINE0("5���ŵ�ȣ��  ������(��)",        S5_offerchg,  char,  10)
    DEFINE_DRDS_LINE0("5���ż�ȣ��  ������(��)",        S5_bidchg,    char,  10)
    DEFINE_DRDS_LINE0("6���ŵ�ȣ��  ������(��)",        S6_offerchg,  char,  10)
    DEFINE_DRDS_LINE0("6���ż�ȣ��  ������(��)",        S6_bidchg,    char,  10)
    DEFINE_DRDS_LINE0("7���ŵ�ȣ��  ������(��)",        S7_offerchg,  char,  10)
    DEFINE_DRDS_LINE0("7���ż�ȣ��  ������(��)",        S7_bidchg,    char,  10)
    DEFINE_DRDS_LINE0("8���ŵ�ȣ��  ������(��)",        S8_offerchg,  char,  10)
    DEFINE_DRDS_LINE0("8���ż�ȣ��  ������(��)",        S8_bidchg,    char,  10)
    DEFINE_DRDS_LINE0("9���ŵ�ȣ��  ������(��)",        S9_offerchg,  char,  10)
    DEFINE_DRDS_LINE0("9���ż�ȣ��  ������(��)",        S9_bidchg,    char,  10)
    DEFINE_DRDS_LINE0("10���ŵ�ȣ�� ������(��)",        S10_offerchg, char,  10)
    DEFINE_DRDS_LINE0("10���ż�ȣ�� ������(��)",        S10_bidchg,   char,  10)
    DEFINE_DRDS_LINE0("�Ѹŵ�ȣ��������(��)",           T_offerchg,   char,  10)
    DEFINE_DRDS_LINE0("�Ѹż�ȣ��������(��)",           T_bidchg,     char,  10)
    DEFINE_DRDS_LINE0("�Ѹŵ�ȣ���ܷ�(��)",             T_offerrem,   char,  10)
    DEFINE_DRDS_LINE0("�Ѹż�ȣ���ܷ�(��)",             T_bidrem,     char,  10)
    DEFINE_DRDS_LINE0("����ü�ᰡ",                     PredicPrice,  char,   9)
    DEFINE_DRDS_LINE0("����ü�ᷮ",                     PredicVol,    char,  12)
    DEFINE_DRDS_LINE0("���ż��ܷ�",                     Soon_rem,     char,  10)
} DRDS_X12_DATA;

#endif // AFX_X12_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


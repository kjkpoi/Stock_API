#if !defined(AFX_X12_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_X12_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


#include "../include/Data_Common.h"


/****** 호가잔량 (X-2) **********************************************/
/****** SVR : 호가잔량 **********************************************/
/********************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0( "종목코드",                       code,         char,   6)	
} DRDS_X12_KEY;

typedef struct {
	DEFINE_DRDS_LINE0("종목코드",                       code,         char,   6)
    DEFINE_DRDS_LINE0("시간 (HH:MM:SS)",                time,         char,   6)
    DEFINE_DRDS_LINE0("매도호가(원)",                   offer,        char,   9)
    DEFINE_DRDS_LINE0("매수호가(원)",                   bid,          char,   9)
    DEFINE_DRDS_LINE0("매도호가잔량(주)",               offerrem,     char,  10)
    DEFINE_DRDS_LINE0("매수호가잔량(주)",               bidrem,       char,  10)
    DEFINE_DRDS_LINE0("차매도호가(원)",                 P_offer,      char,   9)
    DEFINE_DRDS_LINE0("차매수호가(원)",                 P_bid,        char,   9)
    DEFINE_DRDS_LINE0("차매도호가잔량(주)",             P_offerrem,   char,  10)
    DEFINE_DRDS_LINE0("차매수호가잔량(주)",             P_bidrem,     char,  10)
    DEFINE_DRDS_LINE0("차차매도호가(원)",               S_offer,      char,   9)
    DEFINE_DRDS_LINE0("차차매수호가(원)",               S_bid,        char,   9)
    DEFINE_DRDS_LINE0("차차매도호가잔량(주)",           S_offerrem,   char,  10)
    DEFINE_DRDS_LINE0("차차매수호가잔량(주)",           S_bidrem,     char,  10)
    DEFINE_DRDS_LINE0("4차매도호가(원)",                S4_offer,     char,   9)
    DEFINE_DRDS_LINE0("4차매수호가(원)",                S4_bid,       char,   9)
    DEFINE_DRDS_LINE0("4차매도호가잔량(주)",            S4_offerrem,  char,  10)
    DEFINE_DRDS_LINE0("4차매수호가잔량(주)",            S4_bidrem,    char,  10)
    DEFINE_DRDS_LINE0("5차매도호가(원)",                S5_offer,     char,   9)
    DEFINE_DRDS_LINE0("5차매수호가(원)",                S5_bid,       char,   9)
    DEFINE_DRDS_LINE0("5차매도호가잔량(주)",            S5_offerrem,  char,  10)
    DEFINE_DRDS_LINE0("5차매수호가잔량(주)",            S5_bidrem,    char,  10)
    DEFINE_DRDS_LINE0("6차매도호가(원)",                S6_offer,     char,   9)
    DEFINE_DRDS_LINE0("6차매수호가(원)",                S6_bid,       char,   9)
	DEFINE_DRDS_LINE0("6차매도호가잔량(주)",            S6_offerrem,  char,  10)
    DEFINE_DRDS_LINE0("6차매수호가잔량(주)",            S6_bidrem,    char,  10)
    DEFINE_DRDS_LINE0("7차매도호가(원)",                S7_offer,     char,   9)
    DEFINE_DRDS_LINE0("7차매수호가(원)",                S7_bid,       char,   9)
    DEFINE_DRDS_LINE0("7차매도호가잔량(주)",            S7_offerrem,  char,  10)
    DEFINE_DRDS_LINE0("7차매수호가잔량(주)",            S7_bidrem,    char,  10)
    DEFINE_DRDS_LINE0("8차매도호가(원)",                S8_offer,     char,   9)
    DEFINE_DRDS_LINE0("8차매수호가(원)",                S8_bid,       char,   9)
    DEFINE_DRDS_LINE0("8차매도호가잔량(주)",            S8_offerrem,  char,  10)
    DEFINE_DRDS_LINE0("8차매수호가잔량(주)",            S8_bidrem,    char,  10)
    DEFINE_DRDS_LINE0("9차매도호가(원)",                S9_offer,     char,   9)
    DEFINE_DRDS_LINE0("9차매수호가(원)",                S9_bid,       char,   9)
    DEFINE_DRDS_LINE0("9차매도호가잔량(주)",            S9_offerrem,  char,  10)
    DEFINE_DRDS_LINE0("9차매수호가잔량(주)",            S9_bidrem,    char,  10)
    DEFINE_DRDS_LINE0("10차매도호가(원)",               S10_offer,    char,   9)
    DEFINE_DRDS_LINE0("10차매수호가(원)",               S10_bid,      char,   9)
    DEFINE_DRDS_LINE0("10차매도호가잔량(주)",           S10_offerrem, char,  10)
    DEFINE_DRDS_LINE0("10차매수호가잔량(주)",           S10_bidrem,   char,  10)
    DEFINE_DRDS_LINE0("매도호가     변동량(주)",        offerchg,     char,  10)
    DEFINE_DRDS_LINE0("매수호가     변동량(주)",        bidchg,       char,  10)
    DEFINE_DRDS_LINE0("차매도호가   변동량(주)",        P_offerchg,   char,  10)
    DEFINE_DRDS_LINE0("차매수호가   변동량(주)",        P_bidchg,     char,  10)
    DEFINE_DRDS_LINE0("차차매도호가 변동량(주)",        S_offerchg,   char,  10)
    DEFINE_DRDS_LINE0("차차매수호가 변동량(주)",        S_bidchg,     char,  10)
	DEFINE_DRDS_LINE0("4차매도호가  변동량(주)",        S4_offerchg,  char,  10)
    DEFINE_DRDS_LINE0("4차매수호가  변동량(주)",        S4_bidchg,    char,  10)
    DEFINE_DRDS_LINE0("5차매도호가  변동량(주)",        S5_offerchg,  char,  10)
    DEFINE_DRDS_LINE0("5차매수호가  변동량(주)",        S5_bidchg,    char,  10)
    DEFINE_DRDS_LINE0("6차매도호가  변동량(주)",        S6_offerchg,  char,  10)
    DEFINE_DRDS_LINE0("6차매수호가  변동량(주)",        S6_bidchg,    char,  10)
    DEFINE_DRDS_LINE0("7차매도호가  변동량(주)",        S7_offerchg,  char,  10)
    DEFINE_DRDS_LINE0("7차매수호가  변동량(주)",        S7_bidchg,    char,  10)
    DEFINE_DRDS_LINE0("8차매도호가  변동량(주)",        S8_offerchg,  char,  10)
    DEFINE_DRDS_LINE0("8차매수호가  변동량(주)",        S8_bidchg,    char,  10)
    DEFINE_DRDS_LINE0("9차매도호가  변동량(주)",        S9_offerchg,  char,  10)
    DEFINE_DRDS_LINE0("9차매수호가  변동량(주)",        S9_bidchg,    char,  10)
    DEFINE_DRDS_LINE0("10차매도호가 변동량(주)",        S10_offerchg, char,  10)
    DEFINE_DRDS_LINE0("10차매수호가 변동량(주)",        S10_bidchg,   char,  10)
    DEFINE_DRDS_LINE0("총매도호가변동량(주)",           T_offerchg,   char,  10)
    DEFINE_DRDS_LINE0("총매수호가변동량(주)",           T_bidchg,     char,  10)
    DEFINE_DRDS_LINE0("총매도호가잔량(주)",             T_offerrem,   char,  10)
    DEFINE_DRDS_LINE0("총매수호가잔량(주)",             T_bidrem,     char,  10)
    DEFINE_DRDS_LINE0("예상체결가",                     PredicPrice,  char,   9)
    DEFINE_DRDS_LINE0("예상체결량",                     PredicVol,    char,  12)
    DEFINE_DRDS_LINE0("순매수잔량",                     Soon_rem,     char,  10)
} DRDS_X12_DATA;

#endif // AFX_X12_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


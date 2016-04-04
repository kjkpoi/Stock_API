#if !defined(AFX_MH0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_MH0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


#include "../include/Data_Common.h"

/***** CME 선물 호가 (MH0) *****************************************/
/***** SVR : 상품선물 호가 *****************************************/
/*******************************************************************/

typedef struct 
{
//	DEFINE_DRDS_LINE0("종목코드",		fuitem,         char,   8)
	
    DEFINE_DRDS_LINE0("종목코드",      jmcode,       char,   8);
	
} DRDS_MH0_KEY;

typedef struct {
    DEFINE_DRDS_LINE0("종목코드",                       jmcode,       char,   8)  
    DEFINE_DRDS_LINE0("종목SEQ",                        jmcodeseq,    char,   2)  
    DEFINE_DRDS_LINE0("매도우선호가[9(4)v9(2)]",        offerho1,     char,   7)  
    DEFINE_DRDS_LINE0("매수우선호가[9(4)v9(2)]",        bidho1,       char,   7)  
    DEFINE_DRDS_LINE0("매도잔량",                       offerrem1,    char,   6)  
    DEFINE_DRDS_LINE0("매수잔량",                       bidrem1,      char,   6)  
    DEFINE_DRDS_LINE0("차선매도호가[9(3)v9(2)]",        offerho2,     char,   7)  
    DEFINE_DRDS_LINE0("차선매수호가[9(3)v9(2)]",        bidho2,       char,   7)  
    DEFINE_DRDS_LINE0("차선매도호가잔량",               offerrem2,    char,   6)  
    DEFINE_DRDS_LINE0("차선매수호가잔량",               bidrem2,      char,   6)  
    DEFINE_DRDS_LINE0("차차선매도호가[9(3)v9(2)]",      offerho3,     char,   7)  
    DEFINE_DRDS_LINE0("차차선매수호가[9(3)v9(2)]",      bidho3,       char,   7)  
    DEFINE_DRDS_LINE0("차차선매도호가잔량",             offerrem3,    char,   6)  
    DEFINE_DRDS_LINE0("차차선매수호가잔량",             bidrem3,      char,   6)  
    DEFINE_DRDS_LINE0("총매도호가잔량",                 offertotrem,  char,   6)  
    DEFINE_DRDS_LINE0("총매수호가잔량",                 bidtotrem,    char,   6)  
    DEFINE_DRDS_LINE0("호가접수시간",                   hotime,       char,   6)  
    DEFINE_DRDS_LINE0("4차선매도호가",                  offerho4,     char,   7)  
    DEFINE_DRDS_LINE0("4차선매수호가",                  bidho4,       char,   7)  
    DEFINE_DRDS_LINE0("4차선매도잔량",                  offerrem4,    char,   6)  
    DEFINE_DRDS_LINE0("4차선매수잔량",                  bidrem4,      char,   6)  
    DEFINE_DRDS_LINE0("5차선매도호가",                  offerho5,     char,   7)  
    DEFINE_DRDS_LINE0("5차선매수호가",                  bidho5,       char,   7)  
    DEFINE_DRDS_LINE0("5차선매도잔량",                  offerrem5,    char,   6)  
    DEFINE_DRDS_LINE0("5차선매수잔량",                  bidrem5,      char,   6)  
    DEFINE_DRDS_LINE0("우선매도건수",                   offercnt1,    char,   4)  
    DEFINE_DRDS_LINE0("차선매도건수",                   offercnt2,    char,   4)  
    DEFINE_DRDS_LINE0("차차선매도건수",                 offercnt3,    char,   4)  
    DEFINE_DRDS_LINE0("4차선매도건수",                  offercnt4,    char,   4)  
    DEFINE_DRDS_LINE0("5차선매도건수",                  offercnt5,    char,   4)  
    DEFINE_DRDS_LINE0("총매도건수",                     offertotcnt,  char,   5)  
    DEFINE_DRDS_LINE0("우선매수건수",                   bidcnt1,      char,   4)  
    DEFINE_DRDS_LINE0("차선매수건수",                   bidcnt2,      char,   4)  
    DEFINE_DRDS_LINE0("차차선매수건수",                 bidcnt3,      char,   4)  
    DEFINE_DRDS_LINE0("4차선매수건수",                  bidcnt4,      char,   4)  
    DEFINE_DRDS_LINE0("5차선매수건수",                  bidcnt5,      char,   4)  
    DEFINE_DRDS_LINE0("총 매수 건수",                   bidtotcnt,    char,   5)  
    DEFINE_DRDS_LINE0("매도호가건수대비1",              offcnt1_chg,  char,   4)  
    DEFINE_DRDS_LINE0("매도호가건수대비2",              offcnt2_chg,  char,   4)  
    DEFINE_DRDS_LINE0("매도호가건수대비3",              offcnt3_chg,  char,   4)  
    DEFINE_DRDS_LINE0("매도호가건수대비4",              offcnt4_chg,  char,   4)  
    DEFINE_DRDS_LINE0("매도호가건수대비5",              offcnt5_chg,  char,   4)  
    DEFINE_DRDS_LINE0("매수호가건수대비1",              bidcnt1_chg,  char,   4)  
    DEFINE_DRDS_LINE0("매수호가건수대비2",              bidcnt2_chg,  char,   4)  
    DEFINE_DRDS_LINE0("매수호가건수대비3",              bidcnt3_chg,  char,   4)  
    DEFINE_DRDS_LINE0("매수호가건수대비4",              bidcnt4_chg,  char,   4)  
    DEFINE_DRDS_LINE0("매수호가건수대비5",              bidcnt5_chg,  char,   4)  
    DEFINE_DRDS_LINE0("호가총잔량 차이",                totrem_chg,   char,   7)	
	                                                                                
} DRDS_MH0_DATA;                                                                  

#endif // AFX_MH0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


#if !defined(AFX_SH0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_SH0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_

// #include "../CommonTR/Drds_SH0.h"
#include "../include/Data_Common.h"

// 작성 : 이준옥
// 날자 : 2005.11.23(수)

/***** 선물 호가 (SH0) *********************************************/
/***** SVR : 선물 호가 *********************************************/
/*******************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0( "종목코드",                       code,         char,   6)	
} DRDS_SH0_KEY;

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
} DRDS_SH0_DATA;


// 선물 호가 SH0
typedef struct 
{
    char       fuitem       [8];		// 종목코드
    char       futseq       [2];		// 종목SEQ
    char       offer        [7];		// 매도우선호가[9(3)v9(2)]
    char       bid          [7];		// 매수우선호가[9(3)v9(2)]
    char       offerjan     [6];		// 매도잔량
    char       bidjan       [6];		// 매수잔량

    char       joffer       [7];		// 차선매도호가[9(3)v9(2)]
    char       jbid         [7];		// 차선매수호가[9(3)v9(2)]
    char       jofferjan    [6];		// 차선매도호가잔량
    char       jbidjan      [6];		// 차선매수호가잔량

    char       jjoffer      [7];		// 차차선매도호가[9(3)v9(2)]
    char       jjbid        [7];		// 차차선매수호가[9(3)v9(2)]
    char       jjofferjan   [6];		// 차차선매도호가잔량
    char       jjbidjan     [6];		// 차차선매수호가잔량

    char       tofferjan    [6];		// 총매도호가잔량
    char       tobidjan     [6];		// 총매수호가잔량
	char       hotime       [6];		// 호가접수시간

    char       j4offer      [7];		// 4차선매도호가
    char       j4bid        [7];		// 4차선매수호가
    char       j4offerjan   [6];		// 4차선매도잔량
    char       j4bidjan     [6];		// 4차선매수잔량

    char       j5offer      [7];		// 5차선매도호가
    char       j5bid        [7];		// 5차선매수호가
    char       j5offerjan   [6];		// 5차선매도잔량
    char       j5bidjan     [6];		// 5차선매수잔량

    char       offersu      [4];		// 우선매도건수
    char       joffersu     [4];		// 차선매도건수
    char       jjoffersu    [4];		// 차차선매도건수
    char       j4offersu    [4];		// 4차선매도건수
    char       j5offersu    [4];		// 5차선매도건수

    char       toffersu     [5];		// 총매도건수
    char       bidsu        [4];		// 우선매수건수
    char       jbidsu       [4];		// 차선매수건수
    char       jjbidsu      [4];		// 차차선매수건수
    char       j4bidsu      [4];		// 4차선매수건수
    char       j5bidsu      [4];		// 5차선매수건수
    char       tbidsu       [5];		// 총 매수 건수

	char       offcnt1_chg  [4];			//매도호가건수대비1
    char       offcnt2_chg  [4];			//매도호가건수대비2,
    char       offcnt3_chg  [4];			//매도호가건수대비3,
    char       offcnt4_chg  [4];         //매도호가건수대비4,
    char       offcnt5_chg  [4];			//매도호가건수대비5,	
    char       bidcnt1_chg  [4];			//매도호가건수대비6,
    char       bidcnt2_chg  [4];			//매도호가건수대비7,
    char       bidcnt3_chg  [4];			//매도호가건수대비8,
    char       bidcnt4_chg  [4];			//매도호가건수대비9,
    char       bidcnt5_chg  [4];			//매도호가건수대비10,
    //char       soonmesu     [6];		// 순매수잔량
} st_SH0;
#define st_SH0_Size		sizeof(st_SH0)


#endif // AFX_SH0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


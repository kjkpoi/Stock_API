#if !defined(AFX_SH2_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_SH2_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_

// #include "../CommonTR/DrdsSH2.h"
#include "Data_Common.h"

// 작성 : 오정택
// 날자 : 2006.02.17(금)

/****** 선물 호가 (SH2) *********************************************/
/****** SVR : 관심용 선물 호가 **************************************/
/********************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0("종목코드",		fuitem,         char,   8)
} DRDS_SH2_KEY;

typedef struct {
	DEFINE_DRDS_LINE0("종목코드",		fuitem,         char,   8)
	DEFINE_DRDS_LINE0("호가접수시간(HHMMSS)",		hotime,         char,   6)
	DEFINE_DRDS_LINE0("매도우선호가[9(3)v9(2)]",		offer,          char,   6)
	DEFINE_DRDS_LINE0("매수우선호가[9(3)v9(2)]",		bid,            char,   6)
	DEFINE_DRDS_LINE0("매도잔량",		offerjan,       char,   6)
	DEFINE_DRDS_LINE0("매수잔량",		bidjan,         char,   6)
	DEFINE_DRDS_LINE0("총매도호가잔량",		tofferjan,      char,   6)
	DEFINE_DRDS_LINE0("총매수호가잔량",		tobidjan,       char,   6)
} DRDS_SH2_DATA;

#endif // AFX_SH2_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


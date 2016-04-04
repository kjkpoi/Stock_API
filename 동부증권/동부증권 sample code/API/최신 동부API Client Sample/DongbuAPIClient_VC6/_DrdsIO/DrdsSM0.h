#if !defined(AFX_SM0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_SM0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_

// #include "../CommonTR/Drds_SM0.h"
#include "Data_Common.h"

// 작성 : 이준옥
// 날자 : 2005.11.23(수)

/***** 선물 미결제약정(SM0) ****************************************/
/***** SVR : 선물 미결제약정         *******************************/
/*******************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0("선물코드",                       fucode,       char,   8)	
} DRDS_SM0_KEY;

typedef struct {
    DEFINE_DRDS_LINE0("선물코드",                       fucode,       char,   8)
    DEFINE_DRDS_LINE0("시간",                           time,         char,   6)
    DEFINE_DRDS_LINE0("미결제약정수량",                 qty,          char,   7)
    DEFINE_DRDS_LINE0("미결제약정수량증감",             qty_chg,      char,   6)
} DRDS_SM0_DATA;

#endif // AFX_SM0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


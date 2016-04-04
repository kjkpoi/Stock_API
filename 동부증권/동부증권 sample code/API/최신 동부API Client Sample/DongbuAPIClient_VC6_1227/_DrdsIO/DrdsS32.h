#if !defined(AFX_S32_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_S32_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_

// #include "../CommonTR/Drds_S31.h"
// 작성 : 이준옥
// 날자 : 2005.11.23(수)

#include "Data_Common.h"

//---- 현재가 (S32) --------------------------------------------------
//     SVR : 우선호가, 체결, 기세, 장운용, RECOVERY, 전후장종가
//--------------------------------------------------------------------

typedef struct 
{
	DEFINE_DRDS_LINE0( "종목코드",                       code,         char,   6)	
} DRDS_S32_KEY;

typedef struct {
	DEFINE_DRDS_LINE0( "종목코드",                       code,         char,   6)
    DEFINE_DRDS_LINE0( "시간(HH:MM:SS)",                 time,         char,   6)
    DEFINE_DRDS_LINE0( "등락부호",                       sign,         char,   1)
    DEFINE_DRDS_LINE0( "등락폭",                         change,       char,   9)
    DEFINE_DRDS_LINE0( "현재가",                         price,        char,   9)
    DEFINE_DRDS_LINE0( "등락률",                         chrate,       char,   5)
    DEFINE_DRDS_LINE0( "전장시가",                       openam,       char,   9)
    DEFINE_DRDS_LINE0( "고가",                           high,         char,   9)
    DEFINE_DRDS_LINE0( "저가",                           low,          char,   9)
    DEFINE_DRDS_LINE0( "매도호가",                       offer,        char,   9)
    DEFINE_DRDS_LINE0( "매수호가",                       bid,          char,   9)
    DEFINE_DRDS_LINE0( "누적거래량",                     volume,       char,  12)
    DEFINE_DRDS_LINE0( "변동거래량",                     movolume,     char,   8)
    DEFINE_DRDS_LINE0( "거래대금",                       value,        char,  14)
    DEFINE_DRDS_LINE0( "매매구분",                       maegubun,     char,   1)
    DEFINE_DRDS_LINE0( "장구분",                         janggubun,    char,   1)
    DEFINE_DRDS_LINE0( "CB구분",                         cbgubun,      char,   1)
    DEFINE_DRDS_LINE0( "STOP",                           stop,         char,   1)
    DEFINE_DRDS_LINE0( "시간외거래량",                   over_volume,  char,   9)
    DEFINE_DRDS_LINE0( "시간외대량매매",                 rep_volume,   char,   9)
    DEFINE_DRDS_LINE0( "매도호가잔량",                   offerrem,     char,  10)
    DEFINE_DRDS_LINE0( "매수호가잔량",                   bidrem,       char,  10)
    DEFINE_DRDS_LINE0( "총매도호가잔량",                 T_offerrem,   char,  10)
    DEFINE_DRDS_LINE0( "총매수호가잔량",                 T_bidrem,     char,  10)

    DEFINE_DRDS_LINE0( "누적매수량",					 bidvol,	   char,  10)
    DEFINE_DRDS_LINE0( "매수강도",						 bidstrong,    char,   9)
    DEFINE_DRDS_LINE0( "변동거래량2",					 movolume2,    char,   8)
    DEFINE_DRDS_LINE0( "누적매수량2",					 bidvol2,      char,  10)
    DEFINE_DRDS_LINE0( "매수강도2",						 bidstrong2,   char,   9)
} DRDS_S32_DATA;

#endif // AFX_S31_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_
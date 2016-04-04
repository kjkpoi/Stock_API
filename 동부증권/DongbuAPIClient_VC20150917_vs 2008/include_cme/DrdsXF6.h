#if !defined(AFX_XF6_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_XF6_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_

// #include "../CommonTR/DrdsXF6.h"
// 작성 : 이윤희
// 날자 : 2005.12.22(목)

#include "../include/Data_Common.h"

/****** CME선물 잔고 (XF6) ********************************************/
/****** SVR : CME선물 실시간잔고 Real(HTS)  ********************************/
/***************************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0( "userid",                         userid,       char,  20)
} DRDS_XF6_KEY;

// 20071113 권휘영 [1] >> 추가
typedef struct {
	DEFINE_DRDS_LINE0( "userid",                         userid,       char,   20)                  
	DEFINE_DRDS_LINE0( "계좌번호",                       acctno,       char,   20) //11->20
	DEFINE_DRDS_LINE0( "종목번호",                       itemno,       char,   15) //8->15
	DEFINE_DRDS_LINE0( "보유구분명",                     postpnm,      char,   5)
	DEFINE_DRDS_LINE0( "장부수량",                       bookqty,      char,   15) //9->15
	DEFINE_DRDS_LINE0( "당일변동수량",                   tdchngqty,    char,   15) //9->15
	DEFINE_DRDS_LINE0( "현재가",                         close,        char,   15)  // 6=> 15
	DEFINE_DRDS_LINE0( "매수호가",                       bid,          char,   15)  // 6=> 15
	DEFINE_DRDS_LINE0( "매도호가",                       offer,        char,   15)  // 6=> 15
	DEFINE_DRDS_LINE0( "상한가",                         hilimit,      char,   15)  // 6=> 15
	DEFINE_DRDS_LINE0( "하한가",                         lolimit,      char,   15)  // 6=> 15
	DEFINE_DRDS_LINE0( "시장소속구분",                   mrktblngtp,   char,   1)
	DEFINE_DRDS_LINE0( "매입단가",                       bookprc,      char,   12)
	DEFINE_DRDS_LINE0( "매입금액",                       bookamt,      char,   15)
	DEFINE_DRDS_LINE0( "당일실현손익",                   tdpl,         char,   15)
	DEFINE_DRDS_LINE0( "주문유형체크필드",               checkfld,     char,   3)
	DEFINE_DRDS_LINE0( "거래단위",                       unit,         char,   19)  // 8->19
	DEFINE_DRDS_LINE0( "미체결주문수량",                 nocontqty,    char,   15) //9->15
	DEFINE_DRDS_LINE0( "신규매수금액",                   newbuyamt,    char,   15) //12->15
	DEFINE_DRDS_LINE0( "신규매도금액",                   newsellamt,   char,   15) //12->15
	DEFINE_DRDS_LINE0( "환매수금액",                     rebuyamt,     char,   15) //12->15
	DEFINE_DRDS_LINE0( "전매도금액",                     resellamt,    char,   15) //12->15
	DEFINE_DRDS_LINE0( "예탁현금",                       yetakcash,    char,   15)
	DEFINE_DRDS_LINE0( "예탁대용",                       yetakdae,     char,   15)
	DEFINE_DRDS_LINE0( "주문가능총액",                   jumuntot,     char,   15)
	DEFINE_DRDS_LINE0( "주문가능현금",                   jumuncash,    char,   15)
	DEFINE_DRDS_LINE0( "청산가능수량",                   avqty,        char,   15) //12->15
	DEFINE_DRDS_LINE0( "필러",							 filler,       char,   50)
	
} DRDS_XF6_DATA;
// 20071113 권휘영 << 

class CDRDS_XF6_DATA
{
public: //Variable

	CString m_szuserid;       // userid
	CString m_szacctno;       // 계좌번호
	CString m_szitemno;       // 종목번호
	CString m_szpostpnm;      // 보유구분명
	CString m_szbookqty;      // 장부수량
	CString m_sztdchngqty;    // 당일변동수량
	CString m_szclose;        // 현재가
	CString m_szbid;          // 매수호가
	CString m_szoffer;        // 매도호가
	CString m_szhilimit;      // 상한가
	CString m_szlolimit;      // 하한가
	CString m_szmrktblngtp;   // 시장소속구분
	CString m_szbookprc;      // 매입단가
	CString m_szbookamt;      // 매입금액
	CString m_sztdpl;         // 당일실현손익
	CString m_szcheckfld;     // 주문유형체크필드
	CString m_szunit;         // 거래단위
	CString m_sznocontqty;    // 미체결주문수량
	CString m_sznewbuyamt;    // 신규매수금액
	CString m_sznewsellamt;   // 신규매도금액
	CString m_szrebuyamt;     // 환매수금액
	CString m_szresellamt;    // 전매도금액
	CString m_szyetakcash;    // 예탁현금
	CString m_szyetakdae;     // 예탁대용
	CString m_szjumuntot;     // 주문가능총액
	CString m_szjumuncash;    // 주문가능현금
	CString m_szavqty;        // 청산가능수량

	int			m_nbookqty;		// 장부수량
	int			m_nbookprc;		// 매입단가
	int			m_nclose;		// 현재가
	int			m_nnocontqty;   // 미체결주문수량
	double		m_dtdpl;		// 당일실현손익 (15자리)

public:
	CDRDS_XF6_DATA()
	{
	}

	virtual void  Convert(DRDS_XF6_DATA* pInput)
	{
		CString sTemp1 ;
		char sTmp[30+1];

		DATA_MEMCOPY(sTmp, pInput, userid);				// userid
		DATA_MEMCOPY(sTmp, pInput, acctno);				// 계좌번호
		DATA_MEMCOPY(sTmp, pInput, itemno);				// 종목번호
		DATA_MEMCOPY(sTmp, pInput, postpnm);			// 보유구분명
		DATA_MEMCOPY(sTmp, pInput, bookqty);			// 장부수량
		DATA_MEMCOPY(sTmp, pInput, tdchngqty);			// 당일변동수량
		DATA_MEMCOPY(sTmp, pInput, close);				// 현재가
		DATA_MEMCOPY(sTmp, pInput, bid);				// 매수호가
		DATA_MEMCOPY(sTmp, pInput, offer);				// 매도호가
		DATA_MEMCOPY(sTmp, pInput, hilimit);			// 상한가
		DATA_MEMCOPY(sTmp, pInput, lolimit);			// 하한가
		DATA_MEMCOPY(sTmp, pInput, mrktblngtp);			// 시장소속구분
		DATA_MEMCOPY(sTmp, pInput, bookprc);			// 매입단가
		DATA_MEMCOPY(sTmp, pInput, bookamt);			// 매입금액
		DATA_MEMCOPY(sTmp, pInput, tdpl);				// 당일실현손익
		DATA_MEMCOPY(sTmp, pInput, checkfld);			// 주문유형체크필드
		DATA_MEMCOPY(sTmp, pInput, unit);				// 거래단위
		DATA_MEMCOPY(sTmp, pInput, nocontqty);			// 미체결주문수량
		DATA_MEMCOPY(sTmp, pInput, newbuyamt);			// 신규매수금액
		DATA_MEMCOPY(sTmp, pInput, newsellamt);			// 신규매도금액
		DATA_MEMCOPY(sTmp, pInput, rebuyamt);			// 환매수금액
		DATA_MEMCOPY(sTmp, pInput, resellamt);			// 전매도금액
		DATA_MEMCOPY(sTmp, pInput, yetakcash);			// 예탁현금
		DATA_MEMCOPY(sTmp, pInput, yetakdae);			// 예탁대용
		DATA_MEMCOPY(sTmp, pInput, jumuntot);			// 주문가능총액
		DATA_MEMCOPY(sTmp, pInput, jumuncash);			// 주문가능현금
		DATA_MEMCOPY(sTmp, pInput, avqty);				// 청산가능수량

		DATA_CONVERT_int_0(bookqty);	// 장부수량
		DATA_CONVERT_int_0(bookprc);	// 매입단가
		DATA_CONVERT_int_0(close);		// 현재가
		DATA_CONVERT_int_0(nocontqty);  // 미체결주문수량
		DATA_CONVERT_float_0(tdpl);		// 당일실현손익 15자리
	}
};

#endif // AFX_XF6_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_



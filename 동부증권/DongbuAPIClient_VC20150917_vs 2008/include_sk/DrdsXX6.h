#if !defined(AFX_XX6_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_XX6_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


#include "../include/Data_Common.h"

/****** 실시간 잔고 (XX6) ***************************************/
/****** SVR : 실시간 잔고       *********************************/
/****************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0("userid",                         userid,       char,  20)
} DRDS_XX6_KEY;

typedef struct {
	DEFINE_DRDS_LINE0("userid",                         userid,       char,  20)
	DEFINE_DRDS_LINE0("지점번호",                       jijum,        char,   3)
	DEFINE_DRDS_LINE0("계좌번호",                       geja,         char,  17) //8->17
	DEFINE_DRDS_LINE0("종목코드",                       jgcode,       char,  12) //6->12
	DEFINE_DRDS_LINE0("종목명",                         jgname,       char,  14)
	DEFINE_DRDS_LINE0("금일매수금액",                   buyamt,       char,  15) //12->15
	DEFINE_DRDS_LINE0("금일매도금액",                   sellamt,      char,  15) //12->15
	DEFINE_DRDS_LINE0("금일매도정산금액",               arngamt,      char,  15) //12->15
	DEFINE_DRDS_LINE0("장부수량",                       bookqty,      char,  15) //9->15
	DEFINE_DRDS_LINE0("장부단가",                       bookprc,      char,  15) //7->15
	DEFINE_DRDS_LINE0("평가금액",                       evamt,        char,  15) //12->15
	DEFINE_DRDS_LINE0("평가손익",                       evpl,         char,  15) //12->15
	DEFINE_DRDS_LINE0("당일변동수량",                   tdchngqty,    char,  15) //9->15
	DEFINE_DRDS_LINE0("현재가",                         close,        char,   7)
	DEFINE_DRDS_LINE0("매수호가",                       bid,          char,   7)
	DEFINE_DRDS_LINE0("매도호가",                       offer,        char,   7)
	DEFINE_DRDS_LINE0("상한가",                         hilimit,      char,   7)
	DEFINE_DRDS_LINE0("하한가",                         lolimit,      char,   7)
	DEFINE_DRDS_LINE0("시장소속구분",                   mrktblngtp,   char,   1)
	DEFINE_DRDS_LINE0("당일실현손익",                   tdpl,         char,  15) //12->15
	DEFINE_DRDS_LINE0("제비용",                         tax,          char,   9)
	DEFINE_DRDS_LINE0("수익율",                         suikrate,     char,   7)
	DEFINE_DRDS_LINE0("매도가능수량",                   possqty,      char,   15) //20091110 방현진 <<
} DRDS_XX6_DATA;



class CDRDS_XX6_DATA
{
public: //Variable
	CString m_szuserid;				/*  "userid",			*/ 
	CString m_szjijum;				/*  "지점번호"			*/
	CString m_szgeja;				/*  "계좌번호"			*/
	CString m_szjgcode;				/*  "종목코드"			*/
	CString m_szjgname;				/*  "종목명"			*/
	CString m_szbuyamt;				/*  "금일매수금액"		*/
	CString m_szsellamt;			/*  "금일매도금액"		*/
	CString m_szarngamt;			/*  "금일매도정산금액"	*/
	CString m_szbookqty;			/*  "장부수량"			*/
	CString m_szbookprc;			/*  "장부단가"			*/
	CString m_szevamt;				/*  "평가금액"			*/
	CString m_szevpl;				/*  "평가손익"			*/
	CString m_sztdchngqty;			/*  "당일변동수량"		*/
	CString m_szclose;				/*  "현재가"			*/
	CString m_szbid;				/*  "매수호가"			*/
	CString m_szoffer;				/*  "매도호가"			*/
	CString m_szhilimit;			/*  "상한가"			*/
	CString m_szlolimit;			/*  "하한가"			*/
	CString m_szmrktblngtp;			/*  "시장소속구분"		*/
	CString m_sztdpl;				/*  "당일실현손익"		*/
	CString m_sztax;				/*  "제비용"			*/
	CString m_szsuikrate;			/*  "수익율"			*/
	CString m_szpossqty;			/*	매도가능수량		*/

public:
	CDRDS_XX6_DATA()
	{
	}

	virtual void  Convert(DRDS_XX6_DATA* pInput)
	{
		
		CString sTemp1 ;
		char sTmp[20+1];

		DATA_MEMCOPY(sTmp, pInput, userid);				/*  "userid",			*/
		DATA_MEMCOPY(sTmp, pInput, jijum);				/*  "지점번호"			*/
		DATA_MEMCOPY(sTmp, pInput, geja);				/*  "계좌번호"			*/
		DATA_MEMCOPY(sTmp, pInput, jgcode);				/*  "종목코드"			*/
		DATA_MEMCOPY(sTmp, pInput, jgname);				/*  "종목명"			*/
		DATA_MEMCOPY(sTmp, pInput, buyamt);				/*  "금일매수금액"		*/
		DATA_MEMCOPY(sTmp, pInput, sellamt);			/*  "금일매도금액"		*/
		DATA_MEMCOPY(sTmp, pInput, arngamt);			/*  "금일매도정산금액"	*/
		DATA_MEMCOPY(sTmp, pInput, bookqty);			/*  "장부수량"			*/
		DATA_MEMCOPY(sTmp, pInput, bookprc);			/*  "장부단가"			*/
		DATA_MEMCOPY(sTmp, pInput, evamt);				/*  "평가금액"			*/
		DATA_MEMCOPY(sTmp, pInput, evpl);				/*  "평가손익"			*/
		DATA_MEMCOPY(sTmp, pInput, tdchngqty);			/*  "당일변동수량"		*/
		DATA_MEMCOPY(sTmp, pInput, close);				/*  "현재가"			*/
		DATA_MEMCOPY(sTmp, pInput, bid);				/*  "매수호가"			*/
		DATA_MEMCOPY(sTmp, pInput, offer);				/*  "매도호가"			*/
		DATA_MEMCOPY(sTmp, pInput, hilimit);			/*  "상한가"			*/
		DATA_MEMCOPY(sTmp, pInput, lolimit);			/*  "하한가"			*/
		DATA_MEMCOPY(sTmp, pInput, mrktblngtp);			/*  "시장소속구분"		*/
		DATA_MEMCOPY(sTmp, pInput, tdpl);				/*  "당일실현손익"		*/
		DATA_MEMCOPY(sTmp, pInput, tax);				/*  "제비용"			*/
		DATA_MEMCOPY(sTmp, pInput, suikrate);			/*  "수익율"			*/
		DATA_MEMCOPY(sTmp, pInput, possqty);			/*  "매도가능수량"		*/
	}
};

#endif // AFX_XX6_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_




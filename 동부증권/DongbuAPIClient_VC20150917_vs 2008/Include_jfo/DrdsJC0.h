#if !defined(AFX_JC0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_JC0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_

#include "../include/Data_Common.h"

/***** 주식 선물 현재가 (JC0) *******************************************/
/************************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0( "종목코드",                       jmcode,         char,   8)	
} DRDS_JC0_KEY;

typedef struct {
        DEFINE_DRDS_LINE0("종목코드",                   jmcode,      char,         8)
        DEFINE_DRDS_LINE0("종목 SEQ",                   jmcodeseq,   char,         4)
        DEFINE_DRDS_LINE0("시간 HH:MM:SS",              time,        char,         6)
        DEFINE_DRDS_LINE0("현재가",                     price,       char,         7)
        DEFINE_DRDS_LINE0("시가",                       open,        char,         7)
        DEFINE_DRDS_LINE0("고가",                       high,        char,         7)
        DEFINE_DRDS_LINE0("저가",                       low,         char,         7)
        DEFINE_DRDS_LINE0("누적 체결수량",              volume,      char,         7)
        DEFINE_DRDS_LINE0("누적거래대금(천원)",         value,       char,        11)
        DEFINE_DRDS_LINE0("전일대비 부호",              sign,        char,         1)
        DEFINE_DRDS_LINE0("전일대비",                   change,      char,         7)
        DEFINE_DRDS_LINE0("등락률",                     chgrate,     char,         7)
        DEFINE_DRDS_LINE0("체결수량",                   cvolume,     char,         6)

        DEFINE_DRDS_LINE0("매도우선호가",               offerho1,    char,         7)
        DEFINE_DRDS_LINE0("매수우선호가",               bidho1,      char,         7)
        DEFINE_DRDS_LINE0("매도잔량",                   offerrem1,   char,         6)
        DEFINE_DRDS_LINE0("매수잔량",                   bidrem1,     char,         6)
        DEFINE_DRDS_LINE0("차선 매도호가",              offerho2,    char,         7)
        DEFINE_DRDS_LINE0("차선 매수호가",              bidho2,      char,         7)
        DEFINE_DRDS_LINE0("차선 매도호가 잔량",         offerrem2,   char,         6)
        DEFINE_DRDS_LINE0("차선매수호가 잔량",          bidrem2,     char,         6)
        DEFINE_DRDS_LINE0("차차선   매도호가",          offerho3,    char,         7)
        DEFINE_DRDS_LINE0("차차선   매수호가",          bidho3,      char,         7)
        DEFINE_DRDS_LINE0("차차선   매도호가 잔량",     offerrem3,   char,         6)
        DEFINE_DRDS_LINE0("차차선매수호가   잔량",      bidrem3,     char,         6)
        DEFINE_DRDS_LINE0("4차선    매도 호가",         offerho4,    char,         7)
        DEFINE_DRDS_LINE0("4차선    매수 호가",         bidho4,      char,         7)
        DEFINE_DRDS_LINE0("4차선    매도 잔량",         offerrem4,   char,         6)
        DEFINE_DRDS_LINE0("4차선    매수 잔량",         bidrem4,     char,         6)
        DEFINE_DRDS_LINE0("5차선    매도 호가",         offerho5,    char,         7)
        DEFINE_DRDS_LINE0("5차선    매수 호가",         bidho5,      char,         7)
        DEFINE_DRDS_LINE0("5차선    매도 잔량",         offerrem5,   char,         6)
        DEFINE_DRDS_LINE0("5차선    매수 잔량",         bidrem5,     char,         6)
        DEFINE_DRDS_LINE0("6차선    매도 호가",         offerho6,    char,         7)
        DEFINE_DRDS_LINE0("6차선    매수 호가",         bidho6,      char,         7)
        DEFINE_DRDS_LINE0("6차선    매도 잔량",         offerrem6,   char,         6)
        DEFINE_DRDS_LINE0("6차선    매수 잔량",         bidrem6,     char,         6)
        DEFINE_DRDS_LINE0("7차선    매도 호가",         offerho7,    char,         7)
        DEFINE_DRDS_LINE0("7차선    매수 호가",         bidho7,      char,         7)
        DEFINE_DRDS_LINE0("7차선    매도 잔량",         offerrem7,   char,         6)
        DEFINE_DRDS_LINE0("7차선    매수 잔량",         bidrem7,     char,         6)
        DEFINE_DRDS_LINE0("8차선    매도 호가",         offerho8,    char,         7)
        DEFINE_DRDS_LINE0("8차선    매수 호가",         bidho8,      char,         7)
        DEFINE_DRDS_LINE0("8차선    매도 잔량",         offerrem8,   char,         6)
        DEFINE_DRDS_LINE0("8차선    매수 잔량",         bidrem8,     char,         6)
        DEFINE_DRDS_LINE0("9차선    매도 호가",         offerho9,    char,         7)
        DEFINE_DRDS_LINE0("9차선    매수 호가",         bidho9,      char,         7)
        DEFINE_DRDS_LINE0("9차선    매도 잔량",         offerrem9,   char,         6)
        DEFINE_DRDS_LINE0("9차선    매수 잔량",         bidrem9,     char,         6)
        DEFINE_DRDS_LINE0("10차선   매도 호가",         offerho10,   char,         7)
        DEFINE_DRDS_LINE0("10차선   매수 호가",         bidho10,     char,         7)
        DEFINE_DRDS_LINE0("10차선   매도 잔량",         offerrem10,  char,         6)
        DEFINE_DRDS_LINE0("10차선   매수 잔량",         bidrem10,    char,         6)
        DEFINE_DRDS_LINE0("총매도호가 잔량",            offertotrem, char,         7)
        DEFINE_DRDS_LINE0("총매수 호가 잔량",           bidtotrem,   char,         7)

        DEFINE_DRDS_LINE0("우선 매도 건수",             offercnt1,   char,         4)
        DEFINE_DRDS_LINE0("차선 매도 건수",             offercnt2,   char,         4)
        DEFINE_DRDS_LINE0("차차선 매도  건수",          offercnt3,   char,         4)
        DEFINE_DRDS_LINE0("4차선 매도 건수",            offercnt4,   char,         4)
        DEFINE_DRDS_LINE0("5차선 매도 건수",            offercnt5,   char,         4)
        DEFINE_DRDS_LINE0("6차선 매도 건수",            offercnt6,   char,         4)
        DEFINE_DRDS_LINE0("7차선 매도 건수",            offercnt7,   char,         4)
        DEFINE_DRDS_LINE0("8차선 매도 건수",            offercnt8,   char,         4)
        DEFINE_DRDS_LINE0("9차선 매도 건수",            offercnt9,   char,         4)
        DEFINE_DRDS_LINE0("10차선 매도 건수",           offercnt10,  char,         4)
        DEFINE_DRDS_LINE0("총 매도  건수",              offertotcnt, char,         5)
        DEFINE_DRDS_LINE0("우선 매수 건수",             bidcnt1,     char,         4)
        DEFINE_DRDS_LINE0("차선 매수 건수",             bidcnt2,     char,         4)
        DEFINE_DRDS_LINE0("차차선 매수 건수",           bidcnt3,     char,         4)
        DEFINE_DRDS_LINE0("4차선 매수 건수",            bidcnt4,     char,         4)
       	DEFINE_DRDS_LINE0("5차선 매수 건수",            bidcnt5,     char,         4)
        DEFINE_DRDS_LINE0("6차선 매수 건수",            bidcnt6,     char,         4)
        DEFINE_DRDS_LINE0("7차선 매수 건수",            bidcnt7,     char,         4)
        DEFINE_DRDS_LINE0("8차선 매수 건수",            bidcnt8,     char,         4)
        DEFINE_DRDS_LINE0("9차선 매수 건수",            bidcnt9,     char,         4)
        DEFINE_DRDS_LINE0("10차선 매수 건수",           bidcnt10,    char,         4)
        DEFINE_DRDS_LINE0("총 매수  건수",              bidtotcnt,   char,         5)

        DEFINE_DRDS_LINE0("이론가 9(7)V9(2)",           theoryprice, char,        10)
        DEFINE_DRDS_LINE0("미결제 약정",                openyak,     char,         7)
        DEFINE_DRDS_LINE0("미결제 약정 증감",           openyakchg,  char,         7)
        DEFINE_DRDS_LINE0("거래단위(주문체결 사용)",    tradeunit,   char,         8)
} DRDS_JC0_DATA;


class CDRDS_JC0_DATA
{
public: //Variable
	CString m_szjmcode;			/* "종목코드"			*/          
	CString m_szjmcodeseq;		/* "종목SEQ"		    */    
	CString m_sztime;			/* "시간HH:MM:SS    	*/          
	CString m_szprice;			/* "현재가[9(3)v99]"	*/            
	CString m_szopen;			/* "시가[9(3)v99]"		*/            
	CString m_szhigh;			/* "고가[9(3)v99]"		*/            
	CString m_szlow;			/* "저가[9(3)v99]"		*/          
	CString m_szvolume;			/* "누적체결수량"		*/              	
	CString m_szvalue;			/* "누적거래대금(천원->백만원)"	*/          
	CString m_szsign;			/* "전일대비부호"		*/          
	CString m_szchange;			/* "전일대비[9(3)v99]"	*/        
	CString m_szchgrate;		/* "등락율" 			*/        
	CString m_szcvolume;		/* "체결수량"			*/          
	CString m_szofferho1;		/* "매도우선호가[9(3)v9(2)]"*/          
	CString m_szbidho1;	    	/* "매수우선호가[9(3)v9(2)]"*/            

	   

public:
	CDRDS_JC0_DATA()
	{
	}

	virtual void  Convert(DRDS_JC0_DATA* pInput)
	{
		CString sTemp1 ;
		char sTmp[20+1];

		DATA_MEMCOPY(sTmp, pInput, jmcode);			/* "종목코드"			*/	
		DATA_MEMCOPY(sTmp, pInput, jmcodeseq);		/* "종목SEQ"		*/		
		DATA_MEMCOPY(sTmp, pInput, time);			/* "시간HH:MM:SS "			*/		
		DATA_MEMCOPY(sTmp, pInput, price);			/* "현재가[9(3)v99]"				*/		
		DATA_MEMCOPY(sTmp, pInput, open);			/* "시가[9(3)v99]"				*/		
		DATA_MEMCOPY(sTmp, pInput, high);			/* "고가[9(3)v99]"				*/		
		DATA_MEMCOPY(sTmp, pInput, low);			/* "저가[9(3)v99]"			*/		
		DATA_MEMCOPY(sTmp, pInput, volume);			/* "누적체결수량"				*/				
		DATA_MEMCOPY(sTmp, pInput, value);			/* "누적거래대금(천원->백만원)"			*/		
		DATA_MEMCOPY(sTmp, pInput, sign);			/* "전일대비부호"			*/	
		DATA_MEMCOPY(sTmp, pInput, change);			/* "전일대비[9(3)v99]"			*/		
		DATA_MEMCOPY(sTmp, pInput, chgrate);		/* "등락율"			*/	
		DATA_MEMCOPY(sTmp, pInput, cvolume);		/* "체결수량"			*/		
		DATA_MEMCOPY(sTmp, pInput, offerho1);		/* "매도우선호가[9(3)v9(2)]"			*/		
		DATA_MEMCOPY(sTmp, pInput, bidho1);		    /* "매수우선호가[9(3)v9(2)]"				*/		
	}
};

/***** 선물 현재가 (JH0) *******************************************/
/***** 개별주식 선물 호가 (작성일 : 2008. 04) *********************/
/*******************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0( "종목코드",                       jmcode,         char,   8)	
} DRDS_JH0_KEY;

typedef struct {
				DEFINE_DRDS_LINE0("종목코드",              jmcode,      char,        8)
				DEFINE_DRDS_LINE0("종목 SEQ",              jmcodeseq,   char,        4)
				DEFINE_DRDS_LINE0("호가 접수시간",         time,        char,        6)
				
				DEFINE_DRDS_LINE0("매도우선호가",          offerho1,    char,        7)
				DEFINE_DRDS_LINE0("매수우선호가",          bidho1,      char,        7)
				DEFINE_DRDS_LINE0("매도잔량",              offerrem1,   char,        6)
				DEFINE_DRDS_LINE0("매수잔량",              bidrem1,     char,        6)
				DEFINE_DRDS_LINE0("차선 매도호가",         offerho2,    char,        7)
				DEFINE_DRDS_LINE0("차선 매수호가",         bidho2,      char,        7)
				DEFINE_DRDS_LINE0("차선 매도호가 잔량",    offerrem2,   char,        6)
				DEFINE_DRDS_LINE0("차선매수호가 잔량",     bidrem2,     char,        6)
				DEFINE_DRDS_LINE0("차차선 매도호가",       offerho3,    char,        7)
				DEFINE_DRDS_LINE0("차차선 매수호가",       bidho3,      char,        7)
				DEFINE_DRDS_LINE0("차차선 매도호가 잔량",  offerrem3,   char,        6)
				DEFINE_DRDS_LINE0("차차선매수호가 잔량",   bidrem3,     char,        6)
				DEFINE_DRDS_LINE0("4차선    매도 호가",    offerho4,    char,        7)
				DEFINE_DRDS_LINE0("4차선    매수 호가",    bidho4,      char,        7)
				DEFINE_DRDS_LINE0("4차선    매도 잔량",    offerrem4,   char,        6)
				DEFINE_DRDS_LINE0("4차선    매수 잔량",    bidrem4,     char,        6)
				DEFINE_DRDS_LINE0("5차선    매도 호가",    offerho5,    char,        7)
				DEFINE_DRDS_LINE0("5차선    매수 호가",    bidho5,      char,        7)
				DEFINE_DRDS_LINE0("5차선    매도 잔량",    offerrem5,   char,        6)
				DEFINE_DRDS_LINE0("5차선    매수 잔량",    bidrem5,     char,        6)
				DEFINE_DRDS_LINE0("6차선    매도 호가",    offerho6,    char,        7)
				DEFINE_DRDS_LINE0("6차선    매수 호가",    bidho6,      char,        7)
				DEFINE_DRDS_LINE0("6차선    매도 잔량",    offerrem6,   char,        6)
				DEFINE_DRDS_LINE0("6차선    매수 잔량",    bidrem6,     char,        6)
				DEFINE_DRDS_LINE0("7차선    매도 호가",    offerho7,    char,        7)
				DEFINE_DRDS_LINE0("7차선    매수 호가",    bidho7,      char,        7)
				DEFINE_DRDS_LINE0("7차선    매도 잔량",    offerrem7,   char,        6)
				DEFINE_DRDS_LINE0("7차선    매수 잔량",    bidrem7,     char,        6)
				DEFINE_DRDS_LINE0("8차선    매도 호가",    offerho8,    char,        7)
				DEFINE_DRDS_LINE0("8차선    매수 호가",    bidho8,      char,        7)
				DEFINE_DRDS_LINE0("8차선    매도 잔량",    offerrem8,   char,        6)
				DEFINE_DRDS_LINE0("8차선    매수 잔량",    bidrem8,     char,        6)
				DEFINE_DRDS_LINE0("9차선    매도 호가",    offerho9,    char,        7)
				DEFINE_DRDS_LINE0("9차선    매수 호가",    bidho9,      char,        7)
				DEFINE_DRDS_LINE0("9차선    매도 잔량",    offerrem9,   char,        6)
				DEFINE_DRDS_LINE0("9차선    매수 잔량",    bidrem9,     char,        6)
				DEFINE_DRDS_LINE0("10차선   매도 호가",    offerho10,   char,        7)
				DEFINE_DRDS_LINE0("10차선   매수 호가",    bidho10,     char,        7)
				DEFINE_DRDS_LINE0("10차선   매도 잔량",    offerrem10,  char,        6)
				DEFINE_DRDS_LINE0("10차선   매수 잔량",    bidrem10,    char,        6)
				DEFINE_DRDS_LINE0("총매도호가 잔량",       offertotrem, char,        7)
				DEFINE_DRDS_LINE0("총매수호가 잔량",       bidtotrem,   char,        7)
				
				DEFINE_DRDS_LINE0("우선 매도    건수",     offercnt1,   char,        4)
				DEFINE_DRDS_LINE0("차선 매도    건수",     offercnt2,   char,        4)
				DEFINE_DRDS_LINE0("차차선 매도 건수",      offercnt3,   char,        4)
				DEFINE_DRDS_LINE0("4차선    매도 건수",    offercnt4,   char,        4)
				DEFINE_DRDS_LINE0("5차선    매도 건수",    offercnt5,   char,        4)
				DEFINE_DRDS_LINE0("6차선    매도 건수",    offercnt6,   char,        4)
				DEFINE_DRDS_LINE0("7차선    매도 건수",    offercnt7,   char,        4)
				DEFINE_DRDS_LINE0("8차선    매도 건수",    offercnt8,   char,        4)
				DEFINE_DRDS_LINE0("9차선    매도 건수",    offercnt9,   char,        4)
				DEFINE_DRDS_LINE0("10차선   매도 건수",    offercnt10,  char,        4)
				DEFINE_DRDS_LINE0("총 매도 건수",          offertotcnt, char,        5)
				
				DEFINE_DRDS_LINE0("우선 매수    건수",     bidcnt1,     char,        4)
				DEFINE_DRDS_LINE0("차선 매수    건수",     bidcnt2,     char,        4)
				DEFINE_DRDS_LINE0("차차선 매수 건수",      bidcnt3,     char,        4)
				DEFINE_DRDS_LINE0("4차선    매수 건수",    bidcnt4,     char,        4)
				DEFINE_DRDS_LINE0("5차선    매수 건수",    bidcnt5,     char,        4)
				DEFINE_DRDS_LINE0("6차선    매수 건수",    bidcnt6,     char,        4)
				DEFINE_DRDS_LINE0("7차선    매수 건수",    bidcnt7,     char,        4)
				DEFINE_DRDS_LINE0("8차선    매수 건수",    bidcnt8,     char,        4)
				DEFINE_DRDS_LINE0("9차선    매수 건수",    bidcnt9,     char,        4)
				DEFINE_DRDS_LINE0("10차선   매수 건수",    bidcnt10,    char,        4)
				DEFINE_DRDS_LINE0("총 매수 건수",          bidtotcnt,   char,        5)
} DRDS_JH0_DATA;

typedef struct 
{
	DEFINE_DRDS_LINE0("선물코드",                   jmcode,     char,         8)	
} DRDS_JM0_KEY;

typedef struct {
				DEFINE_DRDS_LINE0("선물코드",                   jmcode,     char,         8)
        DEFINE_DRDS_LINE0("시간",                       time,       char,         6)
        DEFINE_DRDS_LINE0("미결제약정 수량(단위:계약)", openyak,    char,         7)
} DRDS_JM0_DATA;
	
#endif // AFX_JC0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_
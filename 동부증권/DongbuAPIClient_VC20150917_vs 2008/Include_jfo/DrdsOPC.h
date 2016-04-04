#if !defined(AFX_OPC_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_OPC_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_

#include "../include/Data_Common.h"

/***** 옵션 현재가 (OPC) *******************************************/
/***** 개별주식 옵션 체결  (작성일 : 2008. 04)*********************/
/*******************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0( "종목코드",                       jmcode,         char,   8)	
} DRDS_OPC_KEY;

typedef struct {
        DEFINE_DRDS_LINE0("종목코드",                   jmcode,      char,         8)
        DEFINE_DRDS_LINE0("현재가",                     price,       char,         6)
		DEFINE_DRDS_LINE0("전일대비",                   change,      char,         6)
		DEFINE_DRDS_LINE0("전일대비 부호",              sign,        char,         1)
        DEFINE_DRDS_LINE0("등락률",                     chgrate,     char,         6)

        DEFINE_DRDS_LINE0("시가",                       open,        char,         6)
        DEFINE_DRDS_LINE0("고가",                       high,        char,         6)
        DEFINE_DRDS_LINE0("저가",                       low,         char,         6)
        DEFINE_DRDS_LINE0("누적 체결수량",              volume,      char,         7)
        DEFINE_DRDS_LINE0("누적거래대금(천원)",         value,       char,        15)
        
        DEFINE_DRDS_LINE0("종목seq",                    jmcodeseq,	 char,         4)
        DEFINE_DRDS_LINE0("체결수량",                   cvolume,     char,         7)
		DEFINE_DRDS_LINE0("체결시간",                   time,        char,         6)

        DEFINE_DRDS_LINE0("매도최우선호가",             offerho1,    char,         6)
        DEFINE_DRDS_LINE0("매도최우선호가잔량",         offerrem1,   char,         7)
		DEFINE_DRDS_LINE0("매도 최우선호가 건수",       offercnt1,   char,         5)

		DEFINE_DRDS_LINE0("매도 2차선호가",             offerho2,    char,         6)
        DEFINE_DRDS_LINE0("매도 2차선호가잔량",         offerrem2,   char,         7)
		DEFINE_DRDS_LINE0("매도 2차선호가 건수",        offercnt2,   char,         5)

		DEFINE_DRDS_LINE0("매도 3차선호가",             offerho3,    char,         6)
        DEFINE_DRDS_LINE0("매도 3차선호가잔량",         offerrem3,   char,         7)
		DEFINE_DRDS_LINE0("매도 3차선호가 건수",        offercnt3,   char,         5)

		DEFINE_DRDS_LINE0("매도 4차선호가",             offerho4,    char,         6)
        DEFINE_DRDS_LINE0("매도 4차선호가잔량",         offerrem4,   char,         7)
		DEFINE_DRDS_LINE0("매도 4차선호가 건수",        offercnt4,   char,         5)

		DEFINE_DRDS_LINE0("매도 5차선호가",             offerho5,    char,         6)
        DEFINE_DRDS_LINE0("매도 5차선호가잔량",         offerrem5,   char,         7)
		DEFINE_DRDS_LINE0("매도 5차선호가 건수",        offercnt5,   char,         5)

		DEFINE_DRDS_LINE0("매수최우선호가",             bidho1,    char,         6)
        DEFINE_DRDS_LINE0("매수최우선호가잔량",         bidrem1,   char,         7)
		DEFINE_DRDS_LINE0("매수 최우선호가 건수",       bidcnt1,   char,         5)

		DEFINE_DRDS_LINE0("매수 2차선호가",             bidho2,    char,         6)
        DEFINE_DRDS_LINE0("매수 2차선호가잔량",         bidrem2,   char,         7)
		DEFINE_DRDS_LINE0("매수 2차선호가 건수",        bidcnt2,   char,         5)

		DEFINE_DRDS_LINE0("매수 3차선호가",             bidho3,    char,         6)
        DEFINE_DRDS_LINE0("매수 3차선호가잔량",         bidrem3,   char,         7)
		DEFINE_DRDS_LINE0("매수 3차선호가 건수",        bidcnt3,   char,         5)

		DEFINE_DRDS_LINE0("매수 4차선호가",             bidho4,    char,         6)
        DEFINE_DRDS_LINE0("매수 4차선호가잔량",         bidrem4,   char,         7)
		DEFINE_DRDS_LINE0("매수 4차선호가 건수",        bidcnt4,   char,         5)

		DEFINE_DRDS_LINE0("매수 5차선호가",             bidho5,    char,         6)
        DEFINE_DRDS_LINE0("매수 5차선호가잔량",         bidrem5,   char,         7)
		DEFINE_DRDS_LINE0("매수 5차선호가 건수",        bidcnt5,   char,         5)

		DEFINE_DRDS_LINE0("매도 총호가수량",            offertotrem,    char,         7)
        DEFINE_DRDS_LINE0("매수 총호가수량",			bidtotrem,		char,         7)
		DEFINE_DRDS_LINE0("매도 총호가건수",			offertotcnt,    char,         6)		
		DEFINE_DRDS_LINE0("매수 총호가건수",            bidtotcnt,      char,         6)
        DEFINE_DRDS_LINE0("delta S9(3)V9(2)",			delta,			char,         7)
		DEFINE_DRDS_LINE0("gmma S9(3)V9(3)",			gmma,			char,         7)
		DEFINE_DRDS_LINE0("vega S9(3)V9(3)",			vega,			char,         7)
		DEFINE_DRDS_LINE0("theta S9(3)V9(3)",			theta,			char,         7)
		DEFINE_DRDS_LINE0("rho S9(3)V9(3)",				rho,			char,         7)
} DRDS_OPC_DATA;


class CDRDS_OPC_DATA
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
	CDRDS_OPC_DATA()
	{
	}

	virtual void  Convert(DRDS_OPC_DATA* pInput)
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

/***** 옵션 현재가 (OPH) *******************************************/
/***** 개별주식 옵션 호가 (작성일 : 2008. 04) *********************/
/*******************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0( "종목코드",                       jmcode,         char,   8)	
} DRDS_OPH_KEY;

typedef struct {
		DEFINE_DRDS_LINE0("종목코드",					jmcode,      char,        8)
		DEFINE_DRDS_LINE0("종목 SEQ",					jmcodeseq,   char,        4)
		DEFINE_DRDS_LINE0("호가 접수시간",				time,        char,        6)
		
		DEFINE_DRDS_LINE0("매도최우선호가",             offerho1,    char,         6)
        DEFINE_DRDS_LINE0("매도최우선호가잔량",         offerrem1,   char,         7)
		DEFINE_DRDS_LINE0("매도 최우선호가 건수",       offercnt1,   char,         5)

		DEFINE_DRDS_LINE0("매도 2차선호가",             offerho2,    char,         6)
        DEFINE_DRDS_LINE0("매도 2차선호가잔량",         offerrem2,   char,         7)
		DEFINE_DRDS_LINE0("매도 2차선호가 건수",        offercnt2,   char,         5)

		DEFINE_DRDS_LINE0("매도 3차선호가",             offerho3,    char,         6)
        DEFINE_DRDS_LINE0("매도 3차선호가잔량",         offerrem3,   char,         7)
		DEFINE_DRDS_LINE0("매도 3차선호가 건수",        offercnt3,   char,         5)

		DEFINE_DRDS_LINE0("매도 4차선호가",             offerho4,    char,         6)
        DEFINE_DRDS_LINE0("매도 4차선호가잔량",         offerrem4,   char,         7)
		DEFINE_DRDS_LINE0("매도 4차선호가 건수",        offercnt4,   char,         5)

		DEFINE_DRDS_LINE0("매도 5차선호가",             offerho5,    char,         6)
        DEFINE_DRDS_LINE0("매도 5차선호가잔량",         offerrem5,   char,         7)
		DEFINE_DRDS_LINE0("매도 5차선호가 건수",        offercnt5,   char,         5)

		DEFINE_DRDS_LINE0("매수최우선호가",             bidho1,    char,         6)
        DEFINE_DRDS_LINE0("매수최우선호가잔량",         bidrem1,   char,         7)
		DEFINE_DRDS_LINE0("매수 최우선호가 건수",       bidcnt1,   char,         5)

		DEFINE_DRDS_LINE0("매수 2차선호가",             bidho2,    char,         6)
        DEFINE_DRDS_LINE0("매수 2차선호가잔량",         bidrem2,   char,         7)
		DEFINE_DRDS_LINE0("매수 2차선호가 건수",        bidcnt2,   char,         5)

		DEFINE_DRDS_LINE0("매수 3차선호가",             bidho3,    char,         6)
        DEFINE_DRDS_LINE0("매수 3차선호가잔량",         bidrem3,   char,         7)
		DEFINE_DRDS_LINE0("매수 3차선호가 건수",        bidcnt3,   char,         5)

		DEFINE_DRDS_LINE0("매수 4차선호가",             bidho4,    char,         6)
        DEFINE_DRDS_LINE0("매수 4차선호가잔량",         bidrem4,   char,         7)
		DEFINE_DRDS_LINE0("매수 4차선호가 건수",        bidcnt4,   char,         5)

		DEFINE_DRDS_LINE0("매수 5차선호가",             bidho5,    char,         6)
        DEFINE_DRDS_LINE0("매수 5차선호가잔량",         bidrem5,   char,         7)
		DEFINE_DRDS_LINE0("매수 5차선호가 건수",        bidcnt5,   char,         5)

		DEFINE_DRDS_LINE0("매도 총호가수량",            offertotrem,    char,         7)
        DEFINE_DRDS_LINE0("매수 총호가수량",			bidtotrem,		char,         7)
		DEFINE_DRDS_LINE0("매도 총호가건수",			offertotcnt,    char,         6)		
		DEFINE_DRDS_LINE0("매수 총호가건수",            bidtotcnt,      char,         6)
} DRDS_OPH_DATA;

typedef struct 
{
	DEFINE_DRDS_LINE0("옵션코드",                   jmcode,     char,         8)	
} DRDS_OM0_KEY;

typedef struct {
		DEFINE_DRDS_LINE0("옵션코드",					jmcode,			char,         8)
        DEFINE_DRDS_LINE0("시간",                       time,			char,         6)
        DEFINE_DRDS_LINE0("미결제약정 수량(단위:계약)", openyak,		char,         7)
		DEFINE_DRDS_LINE0("미결제약정 증감(단위:계약)", openyak_chg,	char,         6)
} DRDS_OM0_DATA;
	
#endif // AFX_OPC_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_

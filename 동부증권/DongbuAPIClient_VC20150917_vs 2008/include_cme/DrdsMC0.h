#if !defined(AFX_MC0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_MC0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_

#include "../include/Data_Common.h"


/***** CME 선물 현재가 (MC0) *******************************************/
/***** SVR : 선물 체결, 장운용, 기세           *********************/
/*******************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0( "종목코드",                       jmcode,         char,   8)	
} DRDS_MC0_KEY;

typedef struct {
  DEFINE_DRDS_LINE0("종목코드",                       jmcode,       char,  8) 
	DEFINE_DRDS_LINE0("종목SEQ",                        jmcodeseq,    char,  2) 
	DEFINE_DRDS_LINE0("시간HH:MM:SS",                   time,         char,  6) 
	DEFINE_DRDS_LINE0("현재가[9(3)v99]",                price,        char,  7) 
	DEFINE_DRDS_LINE0("시가[9(3)v99]",                  open,         char,  7) 
	DEFINE_DRDS_LINE0("고가[9(3)v99]",                  high,         char,  7) 
	DEFINE_DRDS_LINE0("저가[9(3)v99]",                  low,          char,  7) 
	DEFINE_DRDS_LINE0("누적체결수량",                   volume,       char,  7) 
	DEFINE_DRDS_LINE0("누적매수체결량",                 bidvol,       char,  7) 
	DEFINE_DRDS_LINE0("누적거래대금(천원->백만원)",     value,        char, 11) 
	DEFINE_DRDS_LINE0("전일대비부호",                   sign,         char,  1) 
	DEFINE_DRDS_LINE0("전일대비[9(3)v99]",              change,       char,  7) 
	DEFINE_DRDS_LINE0("등락율",                         chgrate,      char,  7) 
	DEFINE_DRDS_LINE0("체결수량",                       cvolume,      char,  6) 
	DEFINE_DRDS_LINE0("매도우선호가[9(3)v9(2)]",        offerho1,     char,  7) 
	DEFINE_DRDS_LINE0("매수우선호가[9(3)v9(2)]",        bidho1,       char,  7) 
	DEFINE_DRDS_LINE0("매도잔량",                       offerrem1,    char,  6) 
	DEFINE_DRDS_LINE0("매수잔량",                       bidrem1,      char,  6) 
	DEFINE_DRDS_LINE0("차선매도호가[9(3)v9(2)]",        offerho2,     char,  7) 
	DEFINE_DRDS_LINE0("차선매수호가[9(3)v9(2)]",        bidho2,       char,  7) 
	DEFINE_DRDS_LINE0("차선매도호가잔량",               offerrem2,    char,  6) 
	DEFINE_DRDS_LINE0("차선매수호가잔량",               bidrem2,      char,  6) 
	DEFINE_DRDS_LINE0("차차선매도호가9(3)v9(2)",        offerho3,     char,  7) 
	DEFINE_DRDS_LINE0("차차선매수호가9(3)v9(2)",        bidho3,       char,  7) 
	DEFINE_DRDS_LINE0("차차선매도호가잔량",             offerrem3,    char,  6) 
	DEFINE_DRDS_LINE0("차차선매수호가잔량",             bidrem3,      char,  6) 
	DEFINE_DRDS_LINE0("총매도호가잔량",                 offertotrem,  char,  6) 
	DEFINE_DRDS_LINE0("총매수호가잔량",                 bidtotrem,    char,  6) 
	DEFINE_DRDS_LINE0("4차선매도호가",                  offerho4,     char,  7) 
	DEFINE_DRDS_LINE0("4차선매수호가",                  bidho4,       char,  7) 
	DEFINE_DRDS_LINE0("4차선매도잔량",                  offerrem4,    char,  6) 
	DEFINE_DRDS_LINE0("4차선매수잔량",                  bidrem4,      char,  6) 
	DEFINE_DRDS_LINE0("5차선매도호가",                  offerho5,     char,  7) 
	DEFINE_DRDS_LINE0("5차선매수호가",                  bidho5,       char,  7) 
	DEFINE_DRDS_LINE0("5차선매도잔량",                  offerrem5,    char,  6) 
	DEFINE_DRDS_LINE0("5차선매수잔량",                  bidrem5,      char,  6) 
                                                                            
	DEFINE_DRDS_LINE0("우선매도건수",                   offercnt1,    char,  4) 
	DEFINE_DRDS_LINE0("차선매도건수",                   offercnt2,    char,  4) 
	DEFINE_DRDS_LINE0("차차선매도건수",                 offercnt3,    char,  4) 
	DEFINE_DRDS_LINE0("4차선매도건수",                  offercnt4,    char,  4) 
	DEFINE_DRDS_LINE0("5차선매도건수",                  offercnt5,    char,  4) 
	DEFINE_DRDS_LINE0("총매도건수",                     offertotcnt,  char,  5) 
                                                                            
	DEFINE_DRDS_LINE0("우선매수건수",                   bidcnt1,      char,  4) 
	DEFINE_DRDS_LINE0("차선매수건수",                   bidcnt2,      char,  4) 
	DEFINE_DRDS_LINE0("차차선매수건수",                 bidcnt3,      char,  4) 
	DEFINE_DRDS_LINE0("4차선매수건수",                  bidcnt4,      char,  4) 
	DEFINE_DRDS_LINE0("5차선매수건수",                  bidcnt5,      char,  4) 
	DEFINE_DRDS_LINE0("총 매수 건수",                   bidtotcnt,    char,  5) 
                                                                            
	DEFINE_DRDS_LINE0("이론가",                         theoryprice,  char,  7) 
                                                                            
	DEFINE_DRDS_LINE0("미결제약정수량",                 openyak,      char,  7) 
	DEFINE_DRDS_LINE0("미결제약정수량대비",             openyakchg,   char,  6) 
	DEFINE_DRDS_LINE0("괴리율",                         gyurirate,    char,  7) 
	DEFINE_DRDS_LINE0("시장베이시스",                   basis,        char,  7) 
	DEFINE_DRDS_LINE0("시가대비",                       openchg,      char,  7) 
	DEFINE_DRDS_LINE0("고가대비",                       highchg,      char,  7) 
	DEFINE_DRDS_LINE0("저가대비",                       lowchg,       char,  7) 
	DEFINE_DRDS_LINE0("매도호가건수대비1",              offcnt1_chg,  char,  4) 
	DEFINE_DRDS_LINE0("매도호가건수대비2",              offcnt2_chg,  char,  4) 
	DEFINE_DRDS_LINE0("매도호가건수대비3",              offcnt3_chg,  char,  4) 
	DEFINE_DRDS_LINE0("매도호가건수대비4",              offcnt4_chg,  char,  4) 
	DEFINE_DRDS_LINE0("매도호가건수대비5",              offcnt5_chg,  char,  4) 
	DEFINE_DRDS_LINE0("매수호가건수대비1",              bidcnt1_chg,  char,  4) 
	DEFINE_DRDS_LINE0("매수호가건수대비2",              bidcnt2_chg,  char,  4) 
	DEFINE_DRDS_LINE0("매수호가건수대비3",              bidcnt3_chg,  char,  4) 
	DEFINE_DRDS_LINE0("매수호가건수대비4",              bidcnt4_chg,  char,  4) 
	DEFINE_DRDS_LINE0("매수호가건수대비5",              bidcnt5_chg,  char,  4) 
                                                                            
	DEFINE_DRDS_LINE0("기초자산지수",                   opttarclose,  char,  7) 
	DEFINE_DRDS_LINE0("호가총잔량 차이",                totrem_chg,   char,  7) 
	DEFINE_DRDS_LINE0("이론베이시스",                   tbasis,       char,  7) 
	DEFINE_DRDS_LINE0("거래량증감",						          volchange,    char,  9)
	DEFINE_DRDS_LINE0("거래대금증감",                   valchange,    char,  9) 
	DEFINE_DRDS_LINE0("체결순매수",                     soonche,      char,  9) 
} DRDS_MC0_DATA;


class CDRDS_MC0_DATA
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
	CString m_szbidvol;			/* "누적매수체결량"		*/              
	CString m_szvalue;			/* "누적거래대금(천원->백만원)"	*/          
	CString m_szsign;			/* "전일대비부호"		*/          
	CString m_szchange;			/* "전일대비[9(3)v99]"	*/        
	CString m_szchgrate;		/* "등락율" 			*/        
	CString m_szcvolume;		/* "체결수량"			*/          
	CString m_szofferho1;		/* "매도우선호가[9(3)v9(2)]"*/          
	CString m_szbidho1;	    	/* "매수우선호가[9(3)v9(2)]"*/            

	//CString m_szofferrem1;		/* "CB구분"			*/            
	//CString m_szbidrem1;			/* "STOP"			*/              
	//CString m_szofferho2;	/* "시간외거래량"		*/      
	//CString m_szbidho2;		/* "시간외대량매매"		*/    
	//CString m_szofferrem2;		/* "매도호가잔량"	*/      
	//CString m_szbidrem2;			/* "매수호가잔량"	*/      
	//CString m_szofferho3;		/* "총매도호가잔량"		*/    

public:
	CDRDS_MC0_DATA()
	{
	}

	virtual void  Convert(DRDS_MC0_DATA* pInput)
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
		DATA_MEMCOPY(sTmp, pInput, bidvol);			/* "누적매수체결량"				*/
		DATA_MEMCOPY(sTmp, pInput, value);			/* "누적거래대금(천원->백만원)"			*/		
		DATA_MEMCOPY(sTmp, pInput, sign);			/* "전일대비부호"			*/	
		DATA_MEMCOPY(sTmp, pInput, change);			/* "전일대비[9(3)v99]"			*/		
		DATA_MEMCOPY(sTmp, pInput, chgrate);		/* "등락율"			*/	
		DATA_MEMCOPY(sTmp, pInput, cvolume);		/* "체결수량"			*/		
		DATA_MEMCOPY(sTmp, pInput, offerho1);		/* "매도우선호가[9(3)v9(2)]"			*/		
		DATA_MEMCOPY(sTmp, pInput, bidho1);		    /* "매수우선호가[9(3)v9(2)]"				*/		
	}
};

typedef struct
{
	char       fuitem		    [8];		// 종목코드
	char       futitemseq   [2];		// 종목SEQ 
	char       futime		    [6];		// 시간HH:MM:SS
	char       fucurr		    [7];		// 현재가[9(3)v99]      	
	char       fuopen       [7];		// 시가[9(3)v99]  
	char       fuhigh       [7];		// 고가[9(3)v99]
	char       fulow        [7];		// 저가[9(3)v99]
									         
	char       fuvolall     [7];		// 누적체결수량
	char       bidvol       [7];        // 누적매수체결량
	char       fuvalall     [11];		// 누적거래대금(천원->백만원)          
  char       fusign       [1];		// 전일대비부호
	char       fuchange     [7];		// 전일대비[9(3)v99]
	char       furate       [7];		// 등락율[9(7)]        
	char       fuvol        [6];		// 체결수량

	char       offer        [7];		// 매도우선호가[9(3)v9(2)]
	char       bid          [7];		// 매수우선호가[9(3)v9(2)]
	char       offerjan     [6];		// 매도잔량
	char       bidjan       [6];		// 매수잔량
									          
	char       joffer       [7];		// 차선매도호가[9(3)v9(2)]
	char       jbid         [7];		// 차선매수호가[9(3)v9(2)]
	char       jofferjan    [6];		// 차선매도호가잔량
	char       jbidjan      [6];		// 차선매수호가잔량
									          
	char       jjoffer      [7];		// 차차선매도호가9(3)v9(2)
	char       jjbid        [7];		// 차차선매수호가9(3)v9(2)
	char       jjofferjan   [6];		// 차차선매도호가잔량
	char       jjbidjan     [6];		// 차차선매수호가잔량
                            
	char       tofferjan    [6];		// 총매도호가잔량
	char       tobidjan     [6];		// 총매수호가잔량
									          
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
	                          
	char       theoryprice  [7];		// 이론가
	                          
	char       openyak      [7];        //미결제약정수량
  char       openyakchg   [6];        //미결제약정수량대비
  char       gyurirate    [7];        //괴리율
  char       basis        [7];        //시장베이시스
  char       openchg      [7];        //시가대비
  char       highchg      [7];        //고가대비
  char       lowchg       [7];        //저가대비
                           
  char       offcnt1_chg  [4];		//매도호가건수대비1
  char       offcnt2_chg  [4];		//매도호가건수대비2
  char       offcnt3_chg  [4];		//매도호가건수대비3
  char       offcnt4_chg  [4];		//매도호가건수대비4
  char       offcnt5_chg  [4];		//매도호가건수대비5
  char       bidcnt1_chg  [4];		//매수호가건수대비1
  char       bidcnt2_chg  [4];		//매수호가건수대비2
  char       bidcnt3_chg  [4];		//매수호가건수대비3
  char       bidcnt4_chg  [4];	    //매수호가건수대비4
  char       bidcnt5_chg  [4];        //매수호가건수대비5
                           
  char       kospi200     [7];		//kospi200
  char       totrem_chg   [7];		//호가총잔량 차이
  char       tbasis       [7];		//이론베이시스
  char       volchange    [9];		//거래량증감
  char       valchange    [9];		//거래대금증감
  char       soonche      [9];		//체결순매수
} _MC0;  
#define st_MC0_Size		sizeof(st_MC0) 


#endif // AFX_MC0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_
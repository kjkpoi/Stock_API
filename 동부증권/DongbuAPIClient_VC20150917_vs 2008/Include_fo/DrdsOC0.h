#if !defined(AFX_OC0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_OC0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_

// #include "../CommonTR/Drds_OC0.h"
#include "../include/Data_Common.h"

// 작성 : 이준옥
// 날자 : 2005.11.23(수)

/***** 옵션 현재가 (OC0) *******************************************/
/***** SVR : 옵션 체결, 장운용, 기세         ***********************/
/*******************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0( "종목코드",                       jmcode,         char,   8)	
} DRDS_OC0_KEY;

typedef struct {
	DEFINE_DRDS_LINE0("종목코드",                       jmcode,       char,   8)
    DEFINE_DRDS_LINE0("총목SEQ",                        jmcodeseq,    char,   3)
    DEFINE_DRDS_LINE0("체결수량",                       cvolume,      char,   6)
    DEFINE_DRDS_LINE0("시간HH:MM:SS",                   time,         char,   6)

    DEFINE_DRDS_LINE0("매도우선호가[9(3)v9(2)]",        offerho1,     char,   7)
    DEFINE_DRDS_LINE0("매수우선호가[9(3)v9(2)]",        bidho1,       char,   7)
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

    DEFINE_DRDS_LINE0("현재가[9(3)v99]",                price,        char,   7)
    DEFINE_DRDS_LINE0("시가[9(3)v99]",                  open,         char,   7)
    DEFINE_DRDS_LINE0("고가[9(3)v99]",                  high,         char,   7)
    DEFINE_DRDS_LINE0("저가[9(3)v99]",                  low,          char,   7)
    DEFINE_DRDS_LINE0("누적 체결수량",                  volume,       char,   8)
    DEFINE_DRDS_LINE0("누적누적매수체결량",             bidvol,       char,   8)
    DEFINE_DRDS_LINE0("누적거래대금",                   value,        char,  11)
	DEFINE_DRDS_LINE0("전일대비부호",                   sign,         char,   1)
    DEFINE_DRDS_LINE0("전일대비",                       change,       char,   7)
    DEFINE_DRDS_LINE0("등락율",                         chgrate,      char,   7)

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
    DEFINE_DRDS_LINE0("총매수건수",                     bidtotcnt,    char,   5)
    
	DEFINE_DRDS_LINE0("이론가",                         theoryprice,  char,   7)
    DEFINE_DRDS_LINE0("내재변동성",                     impv,         char,   7)
	DEFINE_DRDS_LINE0("델타",                           delta,        char,   7)
    DEFINE_DRDS_LINE0("감마",                           gmma,         char,   7)
    DEFINE_DRDS_LINE0("베가",                           vega,         char,   7)
    DEFINE_DRDS_LINE0("세타",                           theta,        char,   7)
    DEFINE_DRDS_LINE0("로우",                           rho,          char,   7)
    DEFINE_DRDS_LINE0("미결제약정수량",                 openyak,      char,   7)
    DEFINE_DRDS_LINE0("미결제약정수량대비",             openyakchg,   char,   6)

    DEFINE_DRDS_LINE0("시가대비",                       openchg,      char,   7)
    DEFINE_DRDS_LINE0("고가대비",                       highchg,      char,   7)
    DEFINE_DRDS_LINE0("저가대비",                       lowchg,       char,   7)
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
	DEFINE_DRDS_LINE0("KP200",  	 				    kp200jisu,    char,   7)

	DEFINE_DRDS_LINE0("내재가치",  	 				    invalue,      char,   6)
	DEFINE_DRDS_LINE0("시간가치",  	 				    tmvalue,      char,   6)
	DEFINE_DRDS_LINE0("거래량증감",					    volchange,    char,   9)
	DEFINE_DRDS_LINE0("거래대금증감",                   valchange,    char,   9)
	DEFINE_DRDS_LINE0("괴리율",                         gyurirate,    char,   7)
	
	//By KHD : 2006.02.6 선물옵션만기월별 시세 화면에 필요한 Drds 코드값 추가 
    
	DEFINE_DRDS_LINE0("체결순매수",                     soonche,      char,   9)
    DEFINE_DRDS_LINE0("총매도호가잔량(부호)",           offertotrem1, char,   7)
    DEFINE_DRDS_LINE0("총매수호가잔량(부호)",           bidtotrem1,   char,   7)
    DEFINE_DRDS_LINE0("미결제약정수량(부호)",           openyak1,     char,   8)

	// 2006.02.06 : 서버요청으로 데이타 추가
	DEFINE_DRDS_LINE0("잔량차(매수잔량-매도잔량)",      remngap,      char,   7)
	DEFINE_DRDS_LINE0("건수차(매수건수-매도건수)",      countgap,     char,   5)

} DRDS_OC0_DATA;


class CDRDS_OC0_DATA
{
public: //Variable
	CString m_szjmcode;			/* "종목코드"			*/          
	CString m_szjmcodeseq;		/* "종목SEQ"		    */    
	CString m_szcvolume;		/* "체결수량        	*/          
	CString m_szprice;			/* "현재가[9(3)v99]"    */            

public:
	CDRDS_OC0_DATA()
	{
	}

	virtual void  Convert(DRDS_OC0_DATA* pInput)
	{
		CString sTemp1 ;
		char sTmp[20+1];

		DATA_MEMCOPY(sTmp, pInput, jmcode);			/* "종목코드"			*/	
		DATA_MEMCOPY(sTmp, pInput, jmcodeseq);		/* "종목SEQ"		*/		
		DATA_MEMCOPY(sTmp, pInput, cvolume);			/* "시간HH:MM:SS "			*/		
		DATA_MEMCOPY(sTmp, pInput, price);			/* "현재가[9(3)v99]"				*/		
	}
};


// 옵션 현재가 OC0
typedef struct
{
    char       opitem       [8];		// 종목코드
    char       opitemseq    [3];		// 총목SEQ
    char       opvol        [6];		// 체결수량
    char       optime       [6];		// 시간HH:MM:SS
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
    char       opcurr       [7];		// 현재가[9(3)v99]
	char       opopen       [7];		// 시가[9(3)v99]
    char       ophigh       [7];		// 고가[9(3)v99]
    char       oplow        [7];		// 저가[9(3)v99]
	char       opvolall     [8];		// 누적체결수량
	char       bidvol       [8];        // 누적매수체결량
	char       opvalall     [11];		// 누적거래대금

	char       opsign       [1];		// 전일대비부호
    char       opchange     [7];		// 전일대비
    char       oprate       [7];		// 등락율[9(7)]
    
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

    char       tbidsu       [5];		// 총매수건수
    char       theory       [7];		// 이론가
    char       impv         [7];		// 내재변동성
    char       delta        [7];		// 델타
    char       gmma         [7];		// 감마
    char       vega         [7];		// 베가
    char       theta        [7];		// 세타
    char       rho          [7];		// 로우

	char       openyak      [7];   // 미결제약정수량
    char       openyakchg   [6];   // 미결제약정수량대비
    char       openchg      [7];   // 시가대비
    char       highchg      [7];   // 고가대비
    char       lowchg       [7];   // 저가대비

    char       offcnt1_chg  [4];    //매도호가건수대비1
    char       offcnt2_chg  [4];    //매도호가건수대비2
    char       offcnt3_chg  [4];    //매도호가건수대비3
    char       offcnt4_chg  [4];    //매도호가건수대비4
    char       offcnt5_chg  [4];    //매도호가건수대비5
    char       bidcnt1_chg  [4];    //매수호가건수대비1
    char       bidcnt2_chg  [4];    //매수호가건수대비2
    char       bidcnt3_chg  [4];    //매수호가건수대비3
    char       bidcnt4_chg  [4];    //매수호가건수대비4
    char       bidcnt5_chg  [4];    //매수호가건수대비5

    char       kp200jisu    [7];    //KP200
    char       invalue      [6];    //내재가치
    char       tmvalue      [6];    //시간가치
    char       volchange    [9];    //거래량증감
    char       valchange    [9];    //거래대금증감
    char       gyurirate    [7];    //괴리율
    char       soonche      [9];    //체결순매수
 
    char       offertotrem1 [7];    //총매도호가잔량(부호)
    char       bidtotrem1   [7];    //총매수호가잔량(부호)
    char       openyak1     [8];    //미결제약정수량(부호)
	char       remngap      [7];    //잔량차(매수잔량-매도잔량)
	char       countgap     [5];    //건수차(매수건수-매도건수)

    //char       fil          [1];		// Temp
    //char       soonmesu     [6];		// 순매수잔량
} st_OC0;  
#define st_OC0_Size		sizeof(st_OC0) 

#endif // AFX_OC0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


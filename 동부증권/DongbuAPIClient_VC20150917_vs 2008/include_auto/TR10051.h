#if !defined(AFX_TR_10051_HEADER_)
#define AFX_TR_10051_HEADER_

// #include "../CommonTR/Tr10051.h"		// 패킷 : 주식호가 



#define TR_10051	"10051"

//-------------------------------------------------------------------------------//
// 호가클릭주문 - 호가전송         사용TR번호:10051 
//--------------------------------[INPUT ]---------------------------------------//
typedef struct _tr_10051_I 
{
	char shcode[6];             /* 종목코드M */
} tr_10051_I;

//--------------------------------[OUTPUT ]---------------------------------------//
typedef struct _tr_10051_T {
	char hname[20];              /* 종목명(한글)M  */
	char tblcount1[4];           /* 테이블카운트  */
	char tblbojo1[20];           /* 테이블보조  */ 
	char price[9];               /* 현재가9(9),원  */
	char sign[1];                /* 등락부호  */
	char change[9];              /* 등락폭9(6)  */
	char chgrate[10];            /* 대비율999.99  */
	char volume[10];             /* 누적거래량9(9),주  */
	char value[12];				 /* 누적거래대금(12)	*/
	char tblcount2[4];           /* 테이블카운트  */
	char tblbojo2[20];           /* 테이블보조  */
	char htime[6];               /* 호가잔량기준시간HHMMSS  */
	char offerrem10[9];          /* 매도10차선잔량9(8),주  */
	char offerho10[9];           /* 매도10차선호가9(7)  */
	char preprice[9];            /* 전일종가9(10),원M  */
	char offerrem9[9];           /* 매도9차선잔량9(8),주  */
	char offerho9[9];            /* 매도9차선호가9(7)  */
	char prevol[10];             /* 전일거래량9(9),주  */
	char offerrem8[9];           /* 매도8차선잔량9(8),주  */
	char offerho8[9];            /* 매도8차선호가9(7)  */
	// 20080618 박동관 TR변경 >>
	//char listing[10];            /* 상장(Kospi)발행(Kosdaq)주식수9listing  */
	char listing[12];            /* 상장(Kospi)발행(Kosdaq)주식수9listing  */
	// 20080618 박동관 TR변경 <<
	char offerrem7[9];           /* 매도7차선잔량9(8),주  */
	char offerho7[9];            /* 매도7차선호가9(7)  */
	char faceval[9];             /* 액면가9(9),원M  */
	char offerrem6[9];           /* 매도6우선잔량9(8),주  */
	char offerho6[9];            /* 매도6차선호가9(7)  */
	char perfull[9];             /* PER전기9(3).99M  */
	char offerrem5[9];           /* 매도5차선잔량9(8),주  */
	char offerho5[9];            /* 매도5차선호가9(7)  */
	char offerrem4[9];           /* 매도4차선잔량9(8),주  */
	char offerho4[9];            /* 매도4차선호가9(7)  */
	char offerrem3[9];           /* 매도3차선잔량9(8),주  */
	char offerho3[9];            /* 매도3차선호가9(7)  */
	char offerrem2[9];           /* 매도2차선잔량9(8),주  */
	char offerho2[9];            /* 매도2차선호가9(7)  */
	char offerrem1[9];           /* 매도최우선잔량9(8),주  */
	char offerho1[9];            /* 매도최우선호가9(7)  */
	char bidho1[9];              /* 매수최우선호가9(7)  */
	char bidrem1[9];             /* 매수최우선잔량9(8),주  */
	char bidho2[9];              /* 매수2차선호가9(7)  */
	char bidrem2[9];             /* 매수2차선잔량9(8),주  */
	char bidho3[9];              /* 매수3차선호가9(7)  */
	char bidrem3[9];             /* 매수3차선잔량9(8),주  */
	char bidho4[9];              /* 매수4차선호가9(7)  */
	char bidrem4[9];             /* 매수4차선잔량9(8),주  */
	char bidho5[9];              /* 매수5차선호가9(7)  */
	char bidrem5[9];             /* 매수5차선잔량9(8),주  */
	char bidho6[9];              /* 매수6우선호가9(7)  */
	char bidrem6[9];             /* 매수6우선잔량9(8),주  */
	char bidho7[9];              /* 매수7차선호가9(7)  */
	char bidrem7[9];             /* 매수7차선잔량9(8),주  */
	char bidho8[9];              /* 매수8차선호가9(7)  */
	char bidrem8[9];             /* 매수8차선잔량9(8),주  */
	char bidho9[9];              /* 매수9차선호가9(7)  */
	char bidrem9[9];             /* 매수9차선잔량9(8),주  */
	char bidho10[9];             /* 매수10차선호가9(7)  */
	char bidrem10[9];            /* 매수10차선잔량9(8),주  */
	char offertotrem[9];         /* 총매도잔량9(8),주  */
	char bidtotrem[9];           /* 총매수잔량9(8),주  */
	char offerrem_ot[9];         /* 시간외매도잔량9(8),주  */
	char bidrem_ot[9];           /* 시간외매수잔량9(8),주  */
	char tblcount3[4];           /* 테이블카운트  */
	char tblbojo3[20];           /* 테이블보조  */
	char hprice[9];              /* 상한가9(9),원M  */
	char high[9];                /* 고가9(7),원  */
	char open[9];                /* 시가9(7),원  */
	char low[9];                 /* 저가9(7),원  */
	char lprice[9];              /* 하한가9(9),원M  */
} tr_10051_T;

typedef struct _tr_10051_U
{
	char	upcodesnm		[18];		/* 종목의소속업종명(ex:전기전자,증권)*/
	char	upjisu			[8];		/* 업종지수  		*/
	char	upsign			[ 1];		/* 업종등락부호 	*/
	char	upchange		[8];		/* 업종전일비 		*/
	char	uprate			[5];		/* 업종등락룰		*/
	char	mstbit			[12];		/* 업종구분(ex:kospi,kosdaq,..)*/
} tr_10051_U;

typedef struct _tr_10051_O
{
	char	 	shcode		[ 7];		/* 종목코드			*/
	char		under		[10];		/* 관감리			*/
	char		right		[10];		/* 권배신규신주구분	*/
	char		badgb		[10];		/* 불성실공시여부	*/
	char		upcode		[ 4];		/* 업종코드			*/
	char		baseprice	[ 9];		/* 기준가  			*/
	
	tr_10051_T	table;	
	
	char		utbl_bojo	[50];
	tr_10051_U	utbl;					/* 종목의소속업종Table*/	
	
	char	etbl_bojo		[50];
	char	expprice		[ 9];		/*  예상 체결가격 */
	char	expvol			[12];		/*  예상 체결수량 */
} tr_10051_O;

#endif //AFX_TR_10051_HEADER_

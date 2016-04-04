#include "stdafx.h"
#include "StmtHelper.h"

#include "include_auto/globalauto.h"

CStmtHelper::CStmtHelper()
{
}

CStmtHelper::~CStmtHelper()
{
}

CString CStmtHelper::GetBuySellStr(CString strVal)
{
	// 1:매도, 2:매수
	if (strVal == "1")
		return "매도";
	else
		return "매수";
}

CString CStmtHelper::GetPercentWonTick(CString strVal)
{
	// 1: 주, 2: %, 3: Tick
	if (strVal == "1")
		return "주";
	else if (strVal == "2")
		return "%";
	else
		return "Tick";
}

CString CStmtHelper::GetParsedCondText(int nIndexType, CString strArg1, CString strArg2, CString strArg3, CString strArg4, CString strArg5)
{
	CString strRet;

	CString strCommaArg1 = strArg1.Trim();
	CString strCommaArg2 = strArg2.Trim();
	CString strCommaArg3 = strArg3.Trim();
	CString strCommaArg4 = strArg4.Trim();
	CString strCommaArg5 = strArg5.Trim();
	
	switch (nIndexType)
	{
	case 100: // 일반주문
		strRet.Format("일반주문%s, %d%s", GetBuySellStr(strArg1), atol(strArg2), GetPercentWonTick(strArg3));
		break;
	case 101: // 호가분할주문
		strRet.Format("호가분할주문%s, %d%s", GetBuySellStr(strArg1), atol(strArg2), GetPercentWonTick(strArg3));
		break;
	case -101 : /* 손실 제한률     */
		strRet.Format("손실제한률 %.2f%% ", atof(strArg1));
		break;
	case -102 : /* 목표 이익률     */
		strRet.Format("목표이익률 %.2f%% ", atof(strArg1));
		break;
	case -105 : /* 이익 반전허용율 */
		strRet.Format("목표보전 %.2f%% 초과 후 최고가 대비  %.2f%% 하락 또는\n"
			"                                     %.2f%% 목표보전",
			atof(strArg1), atof(strArg2), atof(strArg3));
		break;
	case -107 : /* 손실 반전허용율 */
		/* 조건변경에 의한 comment 수정 - 20110804 jini */
		strRet.Format("손실보전 %.2f%% 도달 후 손실제한가 대비\n"
			"         %.2f%% 상승 또는 %.2f%% 추가하락",
			atof(strArg1), atof(strArg2), atof(strArg3));
		break;
	case -111 : /* 손실 제한틱     */
		strRet.Format("손실제한틱 %dTick ", atol(strArg1));
		break;
	case -112 : /* 목표이익틱     */
		strRet.Format("목표이익틱 %dTick ", atol(strArg1));
		break;
	case -115 : /* 목표보전틱     */
		strRet.Format("목표보전 %dTick 초과 후 최고가 대비 %dTick 하락", 
			atol(strArg1), atol(strArg2));
		break;
	case -117 : /* 손실보전틱     */
		strRet.Format("손실보전 %dTick 도달 후 손실제한가 대비 %dTick 상승 또는 %dTick 하락", 
			atol(strArg1), atol(strArg2),
			atol(strArg3));
		break;
	case -121 : /* 손실제한가     */
		InsertComma(strCommaArg1);
		strRet.Format("손실제한가 %s원",
			strCommaArg1);
		break;
	case -122 : /* 목표이익가     */
		InsertComma(strCommaArg1);
		strRet.Format("목표이익가 %s원",
			strCommaArg1);
		break;
	case -125 : /* 목표보전 원     */
		InsertComma(strCommaArg1);
		InsertComma(strCommaArg2);
		strRet.Format("목표보전 %s원 초과 후 최고가 대비 %s원 하락",
			strCommaArg1, strCommaArg2);
		break;
	case -127 : /* 손실보전 원     */
		InsertComma(strCommaArg1);
		InsertComma(strCommaArg2);
		InsertComma(strCommaArg3);
		strRet.Format("손실보전 %s원 도달 후 손실제한가 대비 %s원 상승 또는 %s원 하락",
			strCommaArg1, strCommaArg2,
			strCommaArg3);
		break;
	case -108 : /* 오버나잇     */
		strRet.Format("당일청산 %02d:%02d:%02d 시각에 청산가능 수량을 시장가로 주문",
			atol(strArg1) / 10000,
			(atol(strArg1) % 10000) / 100,
			atol(strArg1) % 100 );
		break;
	case -201 : /* 종목조건 - 주식 */
		InsertComma(strCommaArg4);
		strRet.Format("주식 %s %s %s %s ",
			strArg1, 
			setStr_price(atol(strArg2)),
			setStr_equal(atol(strArg3)),
			strCommaArg4);
		break;
	case -202 : /* 종목조건 - 업종 */
		InsertComma(strCommaArg4);
		strRet.Format("업종 %s %s %s %s ",
			strArg1,
			setStr_price(atol(strArg2)),
			setStr_equal(atol(strArg3)),
			strCommaArg4);
		break;
	case -203 : /* 종목조건 - 선물 */
		InsertComma(strCommaArg4);
		strRet.Format("선물 %s %s %s %s ",
			strArg1,
			setStr_price(atol(strArg2)),
			setStr_equal(atol(strArg3)),
			strCommaArg4);
		break;
	case -204 : /* 종목조건 - 옵션 */
		InsertComma(strCommaArg4);
		strRet.Format("옵션 %s %s %s %s ",
			strArg1,
			setStr_price(atol(strArg2)),
			setStr_equal(atol(strArg3)),
			strCommaArg4);
		break;
	case -301 : /* 기본조건 - A */
	case -307 : /* 기본조건 - A */
		InsertComma(strCommaArg3);
		strRet.Format("%s %s %s ",
			setStr_price(atol(strArg1)),
			setStr_equal(atol(strArg2)),
			strCommaArg3);
		break;
	case -302 : /* 기본조건 - B */
		strRet.Format("현재가 %s %s ",
			setStr_equal(atol(strArg1)),
			setStr_pre(atol(strArg2)) );
		break;
	case -303 : /* 기본조건 - C */
		strRet.Format("당일거래량 %s %s ",
			setStr_equal(atol(strArg1)),
			setStr_volume(atol(strArg2)) );
		break;
	case -304 : /* 기본조건 - D */
		strRet.Format("%s %s 갱신 ",
			setStr_day4new(atol(strArg1)),
			setStr_new(atol(strArg2)) );
		break;
	case -305 : /* 기본조건 - E */
		strRet.Format("연속 %s %s ",
			setStr_day4updown(atol(strArg1)),
			setStr_updown(atol(strArg2)) );
		break;
	case -106 : /* 기본조건 - F */
		strRet.Format("지정시각 %02d:%02d:%02d ",
			atol(strArg1) / 10000,
			(atol(strArg1) % 10000) / 100,
			atol(strArg1) % 100 );
		break;
	case -401 : /* 지표조건 - 돌파 */
		strRet.Format("%s이평이 %s이평 %s ",
			setStr_1avg4through(atol(strArg1)),
			setStr_2avg4through(atol(strArg2)),
			setStr_through(atol(strArg3)) );
		break;
	case -402 : /* 지표조건 - 배열 */
		strRet.Format("%s, %s, %s %s ",
			setStr_1avg4range(atol(strArg1)),
			setStr_2avg4range(atol(strArg2)),
			setStr_3avg4range(atol(strArg3)),
			setStr_range(atol(strArg4))) ;
		break;
	case -403 : /* 지표조건 - MACD */
		strRet.Format("MACD(%s, %s, %s)가 %s %s ",
			setStr_1var4macd(atol(strArg1)),
			setStr_2var4macd(atol(strArg2)),
			setStr_3var4macd(atol(strArg3)),
			setStr_signal4macd(atol(strArg4)),
			setStr_through(atol(strArg5)));
		break;
	case -404 : /* 지표조건 - STOCHASTIC */
		strRet.Format("Stochastic Slow(%s, %s, %s)가 %s %s ",
			setStr_1var4stoch(atol(strArg1)),
			setStr_2var4stoch(atol(strArg2)),
			setStr_3var4stoch(atol(strArg3)),
			setStr_signal4stoch(atol(strArg4)),
			setStr_through(atol(strArg5)) );
		break;
	default   :
		strRet.Format("알 수 없는 조건 (%d) ", nIndexType); 
		break;
	}
	
	if (strRet.GetLength() > 0)
		strRet = strRet + "\n";

	return strRet;
}


/*--------------------------------------------------------------------------*
 * 현재가/대비/등락율/거래량
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_price( int aiI )
{
   CString strBuf;
   
   switch( aiI )
   {
      case 0 :
             strBuf.Format("현재가");
             break;
      case 1 :
             strBuf.Format("대비");
             break;
      case 2 :
             strBuf.Format("등락률");
             break;
      case 3 :
             strBuf.Format("거래량");
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * >/>=/==/<=/<
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_equal( int aiI )
{
   CString strBuf;

   switch ( aiI )
   {
      case 0 :
             strBuf.Format(">");
             break;
      case 1 :
             strBuf.Format(">=");
             break;
      case 2 :
             strBuf.Format("==");
             break;
      case 3 :
             strBuf.Format("<=");
             break;
      case 4 :
             strBuf.Format("<");
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 전일시가/고가/저가/종가/상한가/하한가
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_pre( int aiI )
{
   CString strBuf;

   switch( aiI )
   {
      case 0 :
             strBuf.Format("전일시가");
             break;
      case 1 :
             strBuf.Format("전일고가");
             break;
      case 2 :
             strBuf.Format("전일저가");
             break;
      case 3 :
             strBuf.Format("전일종가");
             break;
      case 4 :
             strBuf.Format("상한가");
             break;
      case 5 :
             strBuf.Format("하한가");
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 전일거래량/5일 평균거래량/10일 평균거래량/20일 평균거래량
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_volume( int aiI )
{
   CString strBuf;

   switch( aiI )
   {
      case 0 :
             strBuf.Format("전일거래량");
             break;
      case 1 :
             strBuf.Format("5일 평균거래량");
             break;
      case 2 :
             strBuf.Format("10일 평균거래량");
             break;
      case 3 :
             strBuf.Format("20일 평균거래량");
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 3일/5일/10일/20일/40일/60일
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_day4new( int aiI )
{
   CString strBuf;


   switch( aiI )
   {
      case 0 : 
             strBuf.Format("3일");
             break;
      case 1 : 
             strBuf.Format("5일");
             break;
      case 2 : 
             strBuf.Format("10일");
             break;
      case 3 : 
             strBuf.Format("20일");
             break;
      case 4 : 
             strBuf.Format("40일");
             break;
      case 5 : 
             strBuf.Format("60일");
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 신고가/신저가
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_new( int aiI )
{
   CString strBuf;
  

   switch( aiI )
   {
      case 0 :
             strBuf.Format("신고가");
             break;
      case 1 :
             strBuf.Format("신저가");
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}


/*--------------------------------------------------------------------------*
 * 1일/2일/3일/4일/5일
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_day4updown( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 : 
      case 1 : 
      case 2 : 
      case 3 : 
      case 4 : 
             strBuf.Format("%d일", (aiI + 1) );
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 상승/하락/상한/하한/양봉/음봉
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_updown( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("상승");
             break;
      case 1 :
             strBuf.Format("하락");
             break;
      case 2 :
             strBuf.Format("상한");
             break;
      case 3 :
             strBuf.Format("하한");
             break;
      case 4 :
             strBuf.Format("양봉");
             break;
      case 5 :
             strBuf.Format("음봉");
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 1/2/3/4/5/10/15/20/40/60
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_1avg4through( int aiI )
{
   CString strBuf;


   switch( aiI )
   {
      case 0 :
      case 1 :
      case 2 :
      case 3 :
      case 4 :
             strBuf.Format("%d", (aiI + 1));
             break;
      case 5 :
             strBuf.Format("%d", 10);
             break;
      case 6 :
             strBuf.Format("%d", 15);
             break;
      case 7 :
             strBuf.Format("%d", 20);
             break;
      case 8 :
             strBuf.Format("%d", 40);
             break;
      case 9 :
             strBuf.Format("%d", 60);
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 5/10/15/20/40/60/120/150/200
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_2avg4through( int aiI )
{
   CString strBuf;


   switch( aiI )
   {
      case 0 :
             strBuf.Format("%d", 5);
             break;
      case 1 :
             strBuf.Format("%d", 10);
             break;
      case 2 :
             strBuf.Format("%d", 15);
             break;
      case 3 :
             strBuf.Format("%d", 20);
             break;
      case 4 :
             strBuf.Format("%d", 40);
             break;
      case 5 :
             strBuf.Format("%d", 60);
             break;
      case 6 :
             strBuf.Format("%d", 120);
             break;
      case 7 :
             strBuf.Format("%d", 150);
             break;
      case 8 :
             strBuf.Format("%d", 200);
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 상향돌파/하향돌파
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_through( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("상향돌파");
             break;
      case 1 :
             strBuf.Format("하향돌파");
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 1/2/3/4/5/10
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_1avg4range( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
      case 1 :
      case 2 :
      case 3 :
      case 4 :
             strBuf.Format("%d", (aiI + 1));
             break;
      case 5 :
             strBuf.Format("%d", 10);
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 10/15/20
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_2avg4range( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("%d", 10);
             break;
      case 1 :
             strBuf.Format("%d", 15);
             break;
      case 2 :
             strBuf.Format("%d", 20);
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 40/60/120/150/200
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_3avg4range( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("%d", 40);
             break;
      case 1 :
             strBuf.Format("%d", 60);
             break;
      case 2 :
             strBuf.Format("%d", 120);
             break;
      case 3 :
             strBuf.Format("%d", 150);
             break;
      case 4 :
             strBuf.Format("%d", 200);
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 정배열/역배열
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_range( int aiI )
{
   CString strBuf;
   
   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("정배열");
             break;
      case 1 :
             strBuf.Format("역배열");
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 5/10/12
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_1var4macd( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("%d", 5);
             break;
      case 1 :
             strBuf.Format("%d", 10);
             break;
      case 2 :
             strBuf.Format("%d", 12);
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 15/20/26
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_2var4macd( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("%d", 15);
             break;
      case 1 :
             strBuf.Format("%d", 20);
             break;
      case 2 :
             strBuf.Format("%d", 26);
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 3/6/9
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_3var4macd( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("%d", 3);
             break;
      case 1 :
             strBuf.Format("%d", 6);
             break;
      case 2 :
             strBuf.Format("%d", 9);
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * Signal/0
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_signal4macd( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("signal");
             break;
      case 1 :
             strBuf.Format("0");
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;

   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 5/10/15
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_1var4stoch( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("%d", 5);
             break;
      case 1 :
             strBuf.Format("%d", 10);
             break;
      case 2 :
             strBuf.Format("%d", 15);
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 3/5/7
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_2var4stoch( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("%d", 3);
             break;
      case 1 :
             strBuf.Format("%d", 5);
             break;
      case 2 :
             strBuf.Format("%d", 7);
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 3/5/7
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_3var4stoch( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("%d", 3);
             break;
      case 1 :
             strBuf.Format("%d", 5);
             break;
      case 2 :
             strBuf.Format("%d", 7);
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * Signal/20/40/60/80
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_signal4stoch( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("signal");
             break;
      case 1 :
             strBuf.Format("20");
             break;
      case 2 :
             strBuf.Format("40");
             break;
      case 3 :
             strBuf.Format("60");
             break;
      case 4 :
             strBuf.Format("80");
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}
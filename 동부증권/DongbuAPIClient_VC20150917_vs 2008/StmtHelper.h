#ifndef __STMTHELPER_H
#define __STMTHELPER_H

// 20120723 ssj - 서버자동주문 >> 서버와 맞추기 위해 서버측 소스의 함수 그대로 카피함
class CStmtHelper
{
public:
	CStmtHelper();
	~CStmtHelper();

protected:
	CString GetBuySellStr(CString strVal);
	CString GetPercentWonTick(CString strVal);
	CString setStr_pricevalue( char, int, double );
	CString setStr_price( int );
	CString setStr_equal( int );
	CString setStr_pre( int );
	CString setStr_volume( int );
	CString setStr_day4new( int );
	CString setStr_new( int );
	CString setStr_day4updown( int );
	CString setStr_updown( int );
	CString setStr_signal( int );
	CString setStr_1avg4through( int );
	CString setStr_2avg4through( int );
	CString setStr_through( int );
	CString setStr_1avg4range( int );
	CString setStr_2avg4range( int );
	CString setStr_3avg4range( int );
	CString setStr_range( int );
	CString setStr_1var4macd( int );
	CString setStr_2var4macd( int );
	CString setStr_3var4macd( int );
	CString setStr_signal4macd( int );
	CString setStr_1var4stoch( int );
	CString setStr_2var4stoch( int );
	CString setStr_3var4stoch( int );
	CString setStr_signal4stoch( int );

public:
	CString GetParsedCondText(int nIndexType, CString strArg1, CString strArg2, CString strArg3, CString strArg4, CString strArg5);
};
// 20120723 ssj - 서버자동주문 <<
#endif
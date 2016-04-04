#if !defined(AFX_TR_14051_HEADER_)
#define AFX_TR_14051_HEADER_

//{{ 신규주문, 청산가능수량 조회


typedef struct
{
    char    geja		[20];		/* 계좌번호 */ //11->20
    char    passwd		[ 8];       /* 비밀번호 */
	char    jcode		[12];		/* 종목코드 8 + 7space */ //15->32  32--> 12
    char    gb			[ 1];		/* 매매구분  1:매도 2:매수 */
	char    price		[12];		/* 주문가격 */ //9->12
    char    ord_type	[ 2];       /* 주문유형  1:지정가 2:시장가 3:조건부지정가 4:최유리지정가*/ //1->2
	char    zLqdtQtyQryTp [ 1];     /* 청산수량 조회구분 : 동부는 1 */
    char    i6			[16];       /* 클라이언트 IP주소(예:192009101031)				*/
} TR_14051_I;

typedef struct
{
	char    newqty		[15];		/* 신규주문가능 수량 */ //7->15
    char    clearqty	[15];		/* 청산가능 수량 */ //7->15
} TR_14051_O;

typedef struct
{
    char    geja		[11];		/* 계좌번호 */
    char    passwd		[ 8];       /* 비밀번호 */
    char    gb			[ 1];		/* 매매구분  1:매도 2:매수 */
    char    jcode		[15];		/* 종목코드 8 + 7space */
    char    ord_type	[ 1];       /* 주문유형  1:지정가 2:시장가 3:조건부지정가 4:최유리지정가*/	
    char    price		[ 9];		/* 주문가격 */
    char    cvd_tp		[ 6];       /* 전략코드 space */
	char	markettp	[ 2];				
} TR_14051_I_1;

typedef struct
{
	char    newqty		[ 7];		/* 신규주문가능 수량 */
    char    clearqty	[ 7];		/* 청산가능 수량 */
} TR_14051_O_1;

class CTR_14051_O
{
public:
    LONGLONG			newqty;
	LONGLONG			clearqty;

public:
	CTR_14051_O(TR_14051_O* pOut)
	{
		convert(pOut);
	}
	CTR_14051_O()
	{
		newqty = 0;
		clearqty= 0;
	}
	void convert(TR_14051_O* pOut)
	{
		CString strData;
		strData.Format("%*.*s", sizeof(pOut->newqty), sizeof(pOut->newqty), pOut->newqty);
		newqty = _atoi64(strData);
		strData.Format("%*.*s", sizeof(pOut->clearqty), sizeof(pOut->clearqty), pOut->clearqty);
		clearqty = _atoi64(strData);
	}
};
#endif //AFX_TR_14051_HEADER_

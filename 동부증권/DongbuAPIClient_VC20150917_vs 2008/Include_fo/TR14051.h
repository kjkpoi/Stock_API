/**************************************************************/
/*  프로그램기능    : {신규/청산 가능 수량 }       			   *
/**************************************************************/
#ifndef _DEFINEDLL_TR14051_
#define	_DEFINEDLL_TR14051_
//
typedef struct
{
    char    geja		[20];		/* 계좌번호 */ //11->20
    char    passwd		[ 8];       /* 비밀번호 */
	char    jcode		[12];		/* 종목코드 8 + 7space */ //15->32  32--> 12
    char    gb			[ 1];		/* 매매구분  1:매도 2:매수 */
	char    price		[12];		/* 주문가격 */ //9->12
    char    ord_type	[ 2];       /* 주문유형  1:지정가 2:시장가 3:조건부지정가 4:최유리지정가*/ //1->2
	char    zLqdtQtyQryTp [ 1];     /* 청산수량 조회구분 : 동부는 1 */
    char    ip			[16];       /* 클라이언트 IP주소(예:192009101031)*/	
} TR_14051_I;

typedef struct
{
	char    newqty		[15];		/* 신규주문가능 수량 */ //7->15
    char    clearqty	[15];		/* 청산가능 수량 */ //7->15
} TR_14051_O;

#endif
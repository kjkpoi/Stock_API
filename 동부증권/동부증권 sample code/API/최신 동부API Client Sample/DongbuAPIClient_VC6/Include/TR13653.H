/**************************************************************/
/*  프로그램기능    : 수수료 조회  			   *
/**************************************************************/
#ifndef _DEFINEDLL_TR13653_
#define	_DEFINEDLL_TR13653_

typedef struct
{
	char        accno [20];			//계좌번호
	char        pass [18];			//입력비밀번호
	char        date [8];			//주문일
	char        ip_addr [16];		//privateip
} TR_13653_I;

typedef struct
{
	char        data1 [15]; //평가예탁금총액
	char        data2 [16]; //주문가능금액
	char        fee   [16]; //수수료
} TR_13653_O;


#endif
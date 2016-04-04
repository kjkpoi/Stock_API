/**************************************************************/
/* 04. 프로그램기능    : {CME선물 평가현황}       	   */
/**************************************************************/

#ifndef _DEFINEDLL_TR20112_
#define	_DEFINEDLL_TR20112_

typedef struct
{
	char        accno [20];			//계좌번호
	char        pass [8];			//입력비밀번호
	//char        date [8];			//주문일
	
	char        janggubun [1];		//잔고평가구분 #0:기본설정1:이동평균법2:선입선출법 (보통은 '0'을 사용)
	char        futuregubun [1];	//선물가격평가구분  #2:전일종가1:당초가
	char        ip_addr [16];		//privateip
	char		nxtKey [19];		//연속키:0 :O_SETCONTBTNKEY    -> 실제 19바이트
} TR_20112_I;


typedef struct
{
	char        data11 [15]; //예탁금총액
	char        data12 [15]; //예탁현금
	char        data13 [15]; //예탁대용
	
	char        data21 [15]; //위탁증거금총액
	char        data22 [15]; //현금위탁증거금액
	char        data23 [14]; //유지증거금총액
	char        data24 [15]; //현금유지증거금액
	
	char        data31 [14]; //추가증거금총액
	char        data32 [15]; //현금추가증거금액
	char        data33 [14]; //주문가능총금액
	char        data34 [15]; //현금주문가능금액
	
	char        data41 [14]; //인출가능총금액
	char        data42 [15]; //인출가능현금액
	
	char		nxtKey [19];  //연속키:0 :O_SETCONTBTNKEY    -> 실제 19바이트
	
} TR_20112_O;

#endif
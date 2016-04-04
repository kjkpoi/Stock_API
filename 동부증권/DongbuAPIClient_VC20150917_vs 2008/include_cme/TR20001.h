/**************************************************************/
/*  프로그램기능    : {CME선물 주문 }       				  */
/**************************************************************/

#ifndef _DEFINEDLL_TR20001_
#define	_DEFINEDLL_TR20001_

typedef struct
{
    char    incnt    [ 4];       /* 주문 cnt                 */
    char    mapno    [ 5];       /* TR사용하는 Map번호       */
} TR_20001_I;

typedef struct
{
    char    clikey  [ 8];		/* 주문 key                                 */
    char    gb      [ 1];		/* 1:매도, 2:매수,  3:정정, 4:취소          */
    char    geja	[20];		/* 계좌번호                                 */
    char    passwd	[ 8];		/* 비밀번호                                 */
    char    code	[15];		/* 종목코드                                 */
    char    wonno	[ 9];		/* 원주문번호   S9(9)                       */
    char    jutype	[ 2];		/* 선물옵션호가유형코드                */
                                /* 00:지정가 03:시장가 05:조건부지정가      */
                                /* 06:최유리지정가                          */
    char    juprc	[12];		/* 주문가     S9(9).99 ->소수점빼고         */
    char    qty		[15];		/* 주문수량   S9(15)                        */
    char    ip      [16];		/* 클라이언트 IP주소(예: 192009101031)      */
} TR_20001_IS; //106

typedef struct 
{
    char    outcnt   [ 4];       /* 주문번호 cnt              */
} TR_20001_O;

typedef struct
{
    char    clikey   [ 8];       /* 주문 key                  */
    char    lOrdNo   [ 9];       /* 주문번호   S9(9)          */
    char    msgcd    [ 6];       /* 메시지코드                */
    char    msgcm   [100];       /* 처리메시지                */
} TR_20001_OS;

#endif
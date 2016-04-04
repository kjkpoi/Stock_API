/**************************************************************/
/*  프로그램기능    : {옵션 종목별 증거금 }       			   *
/**************************************************************/
#ifndef _DEFINEDLL_TR16260_
#define	_DEFINEDLL_TR16260_

typedef struct
{
	char        itemcode [2];			//상품군코드
	char        baseassetcode [3];		//기초자산코드
	char        month [1];				//최근월물구분
	char        ip_addr[16];			//privateip
	char		nxtKey [19];			//연속키:0 :O_SETCONTBTNKEY    -> 실제 19바이트
} TR_16260_I;

typedef struct
{
	char        exeprice [13]; //행사가

	char        jongmok_C [32];		//C선물옵션개별종목번호
	char        name_C [40];		//C구분명
	char        theoryprice_C [19]; //C이론가
	char        baseprice_C [13];	//C기준가
	char        deposit_C [16];		//C주문증거금
	
	char        jongmok_P [32];		//P선물옵션개별종목번호
	char        name_P [40];		//P구분명
	char        theoryprice_P [19]; //P이론가
	char        baseprice_P [13];	//P기준가
	char        deposit_P [16];		//P주문증거금
	
} TR_16260_G;


//1. 버튼 보조메시지 구조
//   구조: 길이정보[2] + 'EN=' + 버튼Enable/Disable구분[1] + '@DT=' + 연속데이타[18]
//   총길이 : 28Bytes
//   길이정보 : (총길이 - 2Bytes)/256[1] + (총길이 - 2Bytes)%256[1]
//   버튼Enable/Disable구분 : 0(Disable=연속데이타없음), 1(Enable=연속데이타있음)
//   연속데이타 : 원장에서 내려준 연속키 값[18]
//   ※ 향후 연속데이타 길이가 바뀔경우, 길이정보를 참조하지 않으면 작업이 발생할 확률이 생김
//
//2. 그리드 보조메시지 구조
//   구조: 데이타갯수[4] + 길이정보[2] + 'UM=' + 그리드구분[1] + '@'
//   총길이: 12Bytes
//   길이정보 : (총길이 - 6Bytes)/256[1] + (총길이 - 6Bytes)%256[1]
//   그리드갱신/추가구분: E(nEw=기존데이타 삭제하고 데이타 뿌림), A(Append=기존데이타 뒤에 데이타 추가) 


#endif
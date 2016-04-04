/**************************************************************/
// 04. 프로그램기능    : {선옵 잔고(원장)조회}    
/**************************************************************/

#ifndef _DEFINEDLL_TR15812_
#define	_DEFINEDLL_TR15812_

typedef struct _tr15812_i
{
	char        accno [20];			//계좌번호
	char        pass [8];			//입력비밀번호
	char        date [8];			//주문일	
	char        janggubun [1];		//잔고평가구분 #0:기본설정1:이동평균법2:선입선출법 (보통은 '0'을 사용)
	char        futuregubun [1];	//선물가격평가구분  #2:전일종가1:당초가
	char        ip_addr [16];		//privateip
	char		nxtKey [19];		//연속키:0 :O_SETCONTBTNKEY    -> 실제 19바이트	
} TR_15812_I;

typedef struct _tr_15812_s
{
	char  acctname[40];			//계좌명
	char  data01[14]; 	// =평가예탁금총액  
	char  data02[15]; 	// =예탁금총액      
	char  data03[14]; 	// =인출가능총금액  
	char  data04[14]; 	// =주문가능총금액  
	char  data05[15]; 	// =위탁증거금총액  
	char  data06[14]; 	// =유지증거금총액  
	char  data07[14]; 	// =현금평가예탁금액
	char  data08[15]; 	// =예탁현금        
	char  data09[15]; 	// =인출가능현금액  
	char  data10[15]; 	// =현금주문가능금액
	char  data11[15]; 	// =현금위탁증거금액
	char  data12[15]; 	// =현금유지증거금액
	char  data13[15]; 	// =예탁대용        
	char  data14[15]; 	// =인출가능대용금액
	char  data15[16]; 	// =평가금액합계    
	char  data16[14]; 	// =평가손익합계    
	char  data17[15]; 	// =미수연체료      
	char  data18[15]; 	// =미수금액        
	char  data19[14]; 	// =추가증거금총액  
	char  data20[15]; 	// =현금추가증거금액
} TR_15812_S;

typedef struct 
{
	char  jgcode  	 [32] ;			/* 종목코드		*/
	char  joname     [40]; 			/* 종목명		*/
	char  jango_gb   [10];          /* 매매구분     */
	char  qntybooknon[16]; 			/* 미결제수량	*/ 
	char  aveprice   [19]; 			/* 평균가		*/
	char  price      [13]; 			/* 현재가		*/
	char  amotbooknon[16];			/* 평가금액     */
	char  changeprice[13];			/* 대비가		*/
	char  pyungpl    [16]; 			/* 평가손익		*/
	char  suikrate   [12]; 			/* 수익율	    */
} TR_15812_G;


typedef struct _tr_15812_o
{	
	TR_15812_S  sm;	
	//버튼 보조메시지1 (가변)
	//그리드 보조메시지2(가변)
	char  gr_DATA[1];	//데이터	
} TR_15812_O;

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
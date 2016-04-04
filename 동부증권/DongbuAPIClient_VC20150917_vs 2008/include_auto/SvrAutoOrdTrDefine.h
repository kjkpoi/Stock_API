
#define LEN_ACCOUNT		11  //계좌번호 길이
#define LEN_ITEMCODE	8   //종목코드 길이
#define LEN_ITEMNAME	20   //종목명 길이

#define LEN_ACCPASS		8   //계좌 비밀전호 길이
#define LEN_USERID		20  //사용자 ID 길이
#define LEN_ORDPRICE	20  //주문 가격 길이
#define LEN_MAXEXP		80  //조건계산식 Max
#include "StdAfx.h"

#define LEN_MAXCONDCOUNT 20

#define TR_SET_ENV				"77010" // 전체설정 등록
#define TR_SET_COND				"77020"	// 개별조건 등록

#define TR_REQ_COND_LIST		"77030"	// 조건리스트 조회
#define TR_REQ_COND_DETAIL		"77040"	// 개별조건 상세 조회
#define TR_REQ_ENV				"77080" // 전체설정 조회
#define TR_AGREE				"20019" // 사용자동의
#define TR_CHANGE_ALL			"77130" // 전체감시,전체해제,전체삭제,전체설정

#define		TR10112		"10112"			// 주문호가단위
#define		TR12151		"12151"			// 신용계좌여부 조회
#define		TR_14055	"14055"			// 주식선옵 가능수량 조회
#define		TR_14051	"14051"			// 선옵 가능수량 조회


#define REALNUM_HOGA_STOCK 0x30


#define HEIGHT_TAB_ITEM		25
#define HEIGHT_GRID			100

#include "Condition_MngDef.h"

typedef struct _INPUT_TR_CHANGE_ALL
{
	char sJobFlag	             [1];             // I:등록, D:삭제, S:중지 R: 감시
	char sMktGbn	               [1];           // 시장구분 S:주식,ELW, F:지수선옵, 주식선물
	char sAcct 	               [12];            // 계좌번호
	char sExpireDate   	       [8];             // 조건 유효기간(YYYYMMDD)
	char sPswd         	       [40];            // 계좌비밀번호
	char sUserID       	       [20];            // HTS User ID
	char sMassId	               [3];           // HTS, Mobile 구분
	char sMFlag        	       [1];             // 반자동 Flag  '0':자동, '1':반자동
	char sOrdKind      	       [1];             // 주문 종류 '1':일반주문  '2':호가분할주문   '3':시간분할주문
	char sOrdCnt       	       [1];             // 분할횟수 (MAX = 5)  1 : 일반주문 n : 호가/시간분할주문
	char sInterval     	       [2];             // 시간분할 주문시 주문 Interval (5 ~ 60)
	char sOrdGb        	       [1];             // 주문구분  '1':지정가, '2':시장가  '3':최유리지정가, '4':최우선지정가 '5':매수1호가,    '6':매수2호가   '7':매도1호가,    '8':매도2호가 '9':조건부지정가 'A':지정가(IOC) 'B':시장가(IOC) 'C':최유리(IOC) 'D':지정가(FOK) 'E':시장가(FOK) 'F':최유리(FOK)
	char sQtyGb        	       [1];             // 수량 입력구분 (2010.10.01 추가)  '1':수량직접입력, '2':백분률로 입력
	char sOrdBaseQty   	       [10];            // 기준수량
	char sOrdRegQty	           [10][10];    // 주문수량(수량 or 백분율)
	char sOrdRegPrc    	       [20];            // 매도1/2/3호가 매수1/2/3호가 현재가, 상한가 하한가
	char sCondFlag     	       [1];             // 조건구분 '1' : 일반조건(계좌/시세/...) '2' : 사용자조건
	char sTargCnt      	       [2];             // 조건수 (최대 20개)
	char sTargExp      	       [80];            // 조건계산식(표현식)
//	char sCode     	           [(4*9)36];       // 조건 Check시 사용되는종목 (4개까지)  시장구분(1) + 종목코드(8) S(STOCK),E(ELW)
	char szCode1[9];							//시장구분(1) + 종목코드(8)                                                                                                                                                                                                                                       
	char szCode2[9];							//시장구분(1) + 종목코드(8)                                                                                                                                                                                                                                       
	char szCode3[9];							//시장구분(1) + 종목코드(8)                                                                                                                                                                                                                                       
	char szCode4[9];							//시장구분(1) + 종목코드(8)                                                                                                                                                                                                                                       
	char sDestTime     	       [6];             //  지정시간 주문을 위한 시간
	char sDestONTime	           [6];         // 선/옵 오버나잇 방지 지정시간 (HHMMSS)
	char sDivGb        	       [1];             // 분할기준 : 0:정배열,   1:등배열, 2:역배열
	char sDivDir       	       [1];             // 분할방향 : 0:매수방향, 1:매도방향
	char sPcIp  	               [15];        // 사설IP format : 999.999.999.999  (15자리사용)
	char sAvgPrcFlag	           [1];         // 평균매입단가 플래그 : 0:설정안함, 1:설정
	char sAvgPrc	               [15];        // 평균매입단가
	User_Define			stUser_Define[20];      // 조건 (화면 하단에 상세내역 기재) 조건1개Size(81) * 조건수(20)
	char sFiller	               [64];        // filler
} INPUT_TR_CHANGE_ALL;

typedef struct _OUTPUT_TR_CHANGE_ALL
{
	char sJobFlag      [1]; // I:등록, U:수정, D:삭제  
	char sRetVal       [1]; // 'S' : 성공, 'F' : 실패
} OUTPUT_TR_CHANGE_ALL;

typedef struct _TR_ORDER_REGIN                                                                                                                                                                                                                                                              
{                                                                                                                                                                                                                                                                                           
	char cJobFlag      [1];   // I:등록, U:수정, D:삭제, S:중지 R: 감시                                                                                                                                                                                                                       
	char szAccount         [12];  // 계좌번호                                                                                                                                                                                                                                                 
	char szShcode       [8];   // 단축코드                                                                                                                                                                                                                                                    
	char szMMType         [1];   // 매매구분     '1':매도, '2':매수                                                                                                                                                                                                                           
	char szCredit         [1];   // "신용구분     '0':현금, '1':유통융자신규, '2':자기융자신규, '3':유통대주, '4':자기대주신규, '5':유통융자상환, '6':자기융자상환, '7':유통대주상환,  '8':자기대주상환, '9':예탁담보대출상환"                                                                
	char szExpiredate   [8];   // 조건 유효기간(YYYYMMDD)                                                                                                                                                                                                                                     
	char szAccPass         [40];  // 계좌비밀번호                                                                                                                                                                                                                                             
	char szMarketType     [1];   // S(STOCK),E(ELW)                                                                                                                                                                                                                                           
	char szUserID       [20];  // HTS User ID                                                                                                                                                                                                                                                 
	char sMassId       [3];   // HTS, Mobile 구분                                                                                                                                                                                                                                             
	char szAutoFlag        [1];   // 반자동 Flag  '0':자동, '1':반자동                                                                                                                                                                                                                        
	char szOrdType      [1];   // 주문 종류 '1':일반주문  '2':호가분할주문   '3':시간분할주문                                                                                                                                                                                                 
	char szOrdCnt       [1];   // 분할횟수 (MAX = 5)  1 : 일반주문 n : 호가/시간분할주문                                                                                                                                                                                                      
	char szInterval     [2];   // 시간분할 주문시 주문 Interval (5 ~ 60)                                                                                                                                                                                                                      
	char szPriceType        [1];   // 주문구분  '1':지정가, '2':시장가  '3':최유리지정가, '4':최우선지정가 '5':매수1호가,    '6':매수2호가   '7':매도1호가,    '8':매도2호가 '9':조건부지정가 'A':지정가(IOC) 'B':시장가(IOC) 'C':최유리(IOC) 'D':지정가(FOK) 'E':시장가(FOK) 'F':최유리(FOK) 
	char szCrdate       [8];   // 대출일(신용매도시 사용)                                                                                                                                                                                                                                     
	char sQtyGb        [1];   // 수량 입력구분 (2010.10.01 추가)  '1':수량직접입력, '2':백분률로 입력                                                                                                                                                                                         
	char szOrdBaseQty   [10];  // 기준수량                                                                                                                                                                                                                                                    
	//char szOrdReqQty    [100]; // 주문수량(수량 or 백분율)                                                                                                                                                                                                                                    
	char szOrdReqQty    [10][10]; // 주문수량(수량 or 백분율)                                                                                                                                                                                                                                    
	char szOrdReqPrice    [20];  // 매도1/2/3호가 매수1/2/3호가 현재가, 상한가 하한가                                                                                                                                                                                                         
	char szCondFlag     [1];   // 조건구분 '1' : 일반조건(계좌/시세/...) '2' : 사용자조건                                                                                                                                                                                                     
	char szCondCnt      [2];   // 조건수 (최대 20개)                                                                                                                                                                                                                                          
	char szCondExp      [80];  // 조건계산식(표현식)                                                                                                                                                                                                                                          
	//char sCode         [36];  // 조건 Check시 사용되는종목 (4개까지)  시장구분(1) + 종목코드(8) S(STOCK),E(ELW)                                                                                                                                                                             
	char szCode1[9];					//시장구분(1) + 종목코드(8)                                                                                                                                                                                                                                       
	char szCode2[9];					//시장구분(1) + 종목코드(8)                                                                                                                                                                                                                                       
	char szCode3[9];					//시장구분(1) + 종목코드(8)                                                                                                                                                                                                                                       
	char szCode4[9];					//시장구분(1) + 종목코드(8)                                                                                                                                                                                                                                       
	char szDestTime     [6];   // 지정시간 주문을 위한 시간                                                                                                                                                                                                                                   
	char sDestONTime   [6];   // 선/옵 오버나잇 방지 지정시간 (HHMMSS)                                                                                                                                                                                                                        
	char sDivGb        [1];   // 분할기준 : 0:정배열,   1:등배열, 2:역배열                                                                                                                                                                                                                    
	char sDivDir       [1];   // 분할방향 : 0:매수방향, 1:매도방향                                                                                                                                                                                                                            
	char sPcIp         [15];  // 사설IP format : 999.999.999.999  (15자리사용)                                                                                                                                                                                                                
	char sAvgPrcFlag	[1];	//평균매입단가 플래그 : 0:설정안함, 1:설정
	char sAvgPrc		[15];	//평균매입단가

	User_Define			stUser_Define[20];      // 2840 조건 (화면 하단에 상세내역 기재) 조건1개Size(81) * 조건수(20)
	char sFiller       [64];  // filler                                                                                                                                                                                                                                                       
} TR_ORDER_REGIN;      
#define SZ_TR_ORDER_REGIN sizeof(TR_ORDER_REGIN)
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
typedef struct tag_OrdListInput
{
	char szAccount[12];			//계좌번호
	char szItemCode[8];			//종목코드
	char szMMType[1];			//매매구분 '1':매도,  '2':매수
	char szCredit[1];			//신용구분     '0':현금, '1':유통융자&자기융자 '2':담보융자
								//신용구분     '0':현금, '1':유통융자신규, '2':자기융자신규, '3':유통대주, '4':자기대주신규, '5':유통융자상환, '6':자기융자상환, '7':유통대주상환, '8':자기대주상환, '9':예탁담보대출상환"
	char szCrDate[8];			// 대출일        YYYYMMDD                (O)
}TR_ORDER_DETAIL_IN;
#define SZ_TR_ORDER_DETAIL_IN sizeof(TR_ORDER_DETAIL_IN)
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
typedef struct tag_TrSvrOrdRegistOutput
{
	char szJobFlag[1];		//I:등록, U:수정, D:삭제, S:중지, R:감시

	// 20120723 ssj - 서버자동주문 >>
	char sRetVal[1];		// S:성공, F:실패
	// 20120723 ssj - 서버자동주문 <<

	TR_ORDER_DETAIL_IN		stDetail;
}TR_ORDER_REGOUT;
#define SZ_TR_ORDER_REGOUT sizeof(TR_ORDER_REGOUT)
// 20120723 ssj - 서버자동주문 <<


typedef struct tag_OrdListOut
{
	TR_ORDER_REGIN stReg;
}
TR_ORDER_DETAIL_OUT;
#define SZ_TR_ORDER_DETAIL_OUT sizeof(TR_ORDER_DETAIL_OUT)

typedef struct tag_TrSvrOrdDeleteInput
{
	char cJobFlag[1];					//D:삭제
	char szAccount[LEN_ACCOUNT];		//계좌번호
	char szShcode[LEN_ITEMCODE];		//단축코드
	char szMMType[1];					//매매구분 '1':매도,  '2':매수
	char szCredit[1];					//신용구분 '0':현금, '1':신용
	char szExpiredate[8];				//유효기간
	char szAccPass[LEN_ACCPASS];		//계좌비밀번호	
	char szUserID[LEN_USERID];			//HTS User ID
	char szCrdate[8];					//대출일(신용매도시 사용)
}TR_ORDER_DELETEIN;
#define SZ_TR_ORDER_DELETEIN sizeof(TR_ORDER_DELETEIN)

typedef struct tag_TrSvrOrdDeleteOutput
{
	char szJobFlag[1];		//I:등록, U:수정, D:삭제
	char szRetVal[1];		//'S':등록성공, 'F':등록실패
}TR_ORDER_DELETEOUT;
#define SZ_TTR_ORDER_DELETEOUT sizeof(TR_ORDER_DELETEOUT)


typedef struct  _CH550C_3
{
   char tnb_cd              [ 3];   /* I 계좌번호                           */
   char ast_cd              [ 2];   /* I 계좌번호                           */
   char acct_no             [ 6];   /* I 계좌번호                           */
   char trcode              [12];   /* I TR코드(등록요구)                   */
   char reg_aban_gbn        [ 1];   /* I 등록해지구분   1:등록 2:해지       */
   char prop_mthd_gbn       [ 1];   /* I 신청방법구분   4:HTS  5:인터넷     */
   char serv_chos_gbn       [ 1];   /* I 서비스선택구분 1:선택 2:전체       */
} TR_SMS_REG;
#define SZ_TR_SMS_REG  sizeof(TR_SMS_REG)


/*--------------------------------------------------------------------------*
 * << 계좌별 핸드폰번호 및 TRCODE신청여부 (NEW) >>
 * 업무계 TR 번호 : CH550C06,  12자리 TR코드 : TR1501021003
 *--------------------------------------------------------------------------*/
typedef struct  _CH550C_4
{
   char tnb_cd              [ 3];   /* I 계좌번호                           */
   char ast_cd              [ 2];   /* I 계좌번호                           */
   char acct_no             [ 6];   /* I 계좌번호                           */
   char trcode              [12];   /* I TR코드(조회요구)                   */
   char hphn_no             [12];   /* O 핸드폰번호                         */
   char trcode_yn           [ 1];   /* O TR코드신청여부    Y or N           */
} TR_PHONENUM;
#define SZ_TR_PHONENUM  sizeof(TR_PHONENUM)

// 20120723 ssj - 서버자동주문 >>
typedef struct tag_OrdDetailInput
{
	char szUserID[20];		//사용자 ID
	char szAccount[12];		//계좌번호
	char sPswd[40];			//게좌비밀번호 
	char sNextKey[30];		//계좌번호+종목코드+매매구분+신용구분+대출일
}TR_ORDLIST_IN;
#define SZ_TR_ORDLIST_IN sizeof(TR_ORDLIST_IN)
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
// TR_REQ_COND_LIST (77030)
typedef struct tag_OrdInfo
{
	char sNextKey[30];		//계좌번호+종목코드+매매구분+신용구분+대출일+신용On/Off
	char szAccount[12];		//계좌번호
	char sAcctID[15];		//계좌식별ID
	char szItemCode[8];		//종목코드
	char szMMType[1];		//매매구분 '1':매도,  '2':매수
	char szCredit[1];		//"신용구분     '0':현금, '1':유통융자신규, '2':자기융자신규, '3':유통대주, '4':자기대주신규, '5':유통융자상환, '6':자기융자상환, '7':유통대주상환, '8':자기대주상환, '9':예탁담보대출상환"
	char cAutoFlag[1];		//반자동 Flag  '0':자동, '1':반자동
	char szItemName[40];	//종목명
	char szPrice[10];		//현재가
	char szExpiredDate[8];	//유효기간
	char cResult[1];		//처리결과    '1':감시,  '2':휴면(중지)
	char cbCondAcc[1];		//손익조건여부  개수
	char cbCondItem[1];		//BM조건여부 개수
	char cbCondPrice[1];	//시세조건여부 개수
	char cbCondIndex[1];	//지표조건여부 개수
	char cbCondUser[1];		//사용자조건여부 개수
	char szLoanDate[8];                   // 대출일
	char sOrdGb[1];			// 주문구분  2012.03.02 추가
	char sOrdRegPrc[20];	// 주문가격  2012.03.02 추가
	// 20120723 ssj - 서버자동주문 >>
	char sAvgPrcFlag[1];    // 평균단가 설정0:매입가,1설정가
	char sAvgPrc[15];		// 평균매입단가 설정값
	char sMassID[3];		// 매체구분 - HTS 일반: 50(디럭스, 이지, FX,FX+ 포함), HTS 미니: 51, 아이폰/안드로이드 앱: 66, 아이패드 앱: 67
	char sOrdQty[10];		// 총주문수량
	// 20120723 ssj - 서버자동주문 <<
	char szCondStatement[800];	//효력조건
}ST_ORDINFO;
#define SZ_ST_ORDINFO sizeof(ST_ORDINFO)
// 20120723 ssj - 서버자동주문 <<

// TR_REQ_COND_LIST (77030)
typedef struct tag_OrdDetailOutput
{
	char szCount[8];		//등록주문 Count
	ST_ORDINFO* pstOrdInfo;
}TR_ORDLIST_OUT;
#define SZ_TR_ORDLIST_OUT sizeof(TR_ORDLIST_OUT)

// 20120723 ssj - 서버자동주문 >>
typedef struct _TR77010_IN
{
	char sAcnt_no        [12]; // 계좌 번호                                                                                                                         
	char sMass_id        [3]; // 조건등록 매체 (ex)HTS, 모바일, 웹 등                                                                                              
	char sSvr_ip         [15]; // 등록서버IP                                                                                                                     
	char sCond_expr_date [8]; // 조건 만료 일자. (YYYYMMDD)                                                                                                        
	char sNewitem_add    [1]; // 0:처리안함, 1:신규유입처리함                                                                                                      
	char sScrt_no        [40]; // 계좌 비밀 번호 (주문, 잔고 조회시 필요함.)                                                                                        
	char sId             [20]; // Hts login ID                                                                                                                      
	char sSEL_BUY_GBN    [1]; // 1:매도, 2:매수                                                                                                                    
	char sAuto_gbn       [1]; // 1 : 반자동 주문, 0 : 자동주문                                                                                                     
	char sOrd_div_gbn    [1]; // 1 : 일반 주문, 2 : 호가분할 주문, 3 : 시간분할 주문
	char sDIV_GBN        [1]; // '0 ': 정배열, '1':등배열, '2':역배열
	char sDIV_ORD_GBN    [1]; // '0' : 매수방향, '1':매도방향
	char sOrd_cnt        [1]; // 일반주문의 경우 1. 호가분할 및 시간 분할인 경우 분할 횟수
	char sORD_INTERVAL   [2]; // 시간분할 주문시 분할 간격 (최소 1분 ~ 최대 60분.)
	char sOrd_gbn        [1]; // " '1':지정가,       '2':시장가 '3':최유리지정가, '4':최우선지정가 '5':매수1호가,    '6':매수2호가 '7':매도1호가,    '8':매도2호가"
	char sORD_QRY_GBN    [1]; // 1:수량직접입력, 2:백분율로 입력
	char sORD_BASE_QRY   [10]; // 기준수량 (ex: 잔고의 50%) 수량 구분에 따라 수량 혹은 백분율로 입력됨.
	char sOrd_qty1       [10]; // 주문수량1  수량 혹은 백분률( 1 ~ 100%)  로 입력됨.
	char sOrd_qty2       [10]; // 주문수량2  수량 혹은 백분률( 1 ~ 100%)  로 입력됨.
	char sOrd_qty3       [10]; // 주문수량3  수량 혹은 백분률( 1 ~ 100%)  로 입력됨.
	char sOrd_qty4       [10]; // 주문수량4  수량 혹은 백분률( 1 ~ 100%)  로 입력됨.
	char sOrd_qty5       [10]; // 주문수량5  수량 혹은 백분률( 1 ~ 100%)  로 입력됨.
	char sOrd_qty6       [10]; // 주문수량6  수량 혹은 백분률( 1 ~ 100%)  로 입력됨.
	char sOrd_qty7       [10]; // 주문수량7  수량 혹은 백분률( 1 ~ 100%)  로 입력됨.
	char sOrd_qty8       [10]; // 주문수량8  수량 혹은 백분률( 1 ~ 100%)  로 입력됨.
	char sOrd_qty9       [10]; // 주문수량9  수량 혹은 백분률( 1 ~ 100%)  로 입력됨.
	char sOrd_qty10      [10]; // 주문수량10  수량 혹은 백분률( 1 ~ 100%)  로 입력됨
	char sOrd_prc        [10]; // 주문가격 (매수1/2/3호가, 매도 1/2/3 호가) 혹은 지정가로 저장 (ex) D1 :매도1호가, S2 :매수2호가, J12300 : 지정가 12300원)
	char sCond_obs_gbn   [1]; // 1': 손익조건, '2':사용자조건
	char sCond_obs_cnt   [2]; // 최대 20개, USER_DEF 사이즈과 관련
	char sCond_obs_mix   [80]; // "조건검색의 EXPLEN값 사용(80) 게좌조건의 경우는 모두 'OR'로 연결 사용자조건의 경우는 사용자 입력 조합식"
	User_Define sCond_obs_detl  [4]; // "조건검색의 UserDefine 구조체 사용, 배열 4개(입력 가능 조건수는 4개)"
	char sPcIp           [15]; // 고객PcIp
	char sFiller         [49]; // Filler
} TR77010_IN;

typedef struct _TR77010_OUT
{
	char sAcct[12]; // 계좌번호
	char sRetVal[1]; // S' 성공 'F'실패
} TR77010_OUT;
 
typedef struct _TR77080_INPUT
{
	char sId             [20]; // Hts login ID
	char sAcnt_no        [12]; // 계좌 번호
} TR77080_INPUT;

typedef struct _TR77080_OUT
{
	char sAcnt_no        [12 ]; // 계좌 번호
	char sMass_id        [3  ]; // 조건등록 매체 (ex)HTS, 모바일, 웹 등
	char sSvr_ip         [15 ]; // 등록서버IP
	char sCond_expr_date [8  ]; // 조건 만료 일자. (YYYYMMDD)
	char sNewitem_add    [1  ]; // 0:처리안함, 1:신규유입처리함
	char sScrt_no        [40 ]; // 계좌 비밀 번호 (주문, 잔고 조회시 필요함.)
	char sId             [20 ]; // Hts login ID
	char sSEL_BUY_GBN    [1  ]; // 1:매도, 2:매수
	char sAuto_gbn       [1  ]; // 1 : 반자동 주문, 0 : 자동주문
	char sOrd_div_gbn    [1  ]; // 1 : 일반 주문, 2 : 호가분할 주문, 3 : 시간분할 주문
	char sDIV_GBN        [1  ]; // '0 ': 정배열, '1':등배열, '2':역배열
	char sDIV_ORD_GBN    [1  ]; // '0' : 매수방향, '1':매도방향
	char sOrd_cnt        [4  ]; // 일반주문의 경우 1. 호가분할 및 시간 분할인 경우 분할 횟수
	char sORD_INTERVAL   [4  ]; // 시간분할 주문시 분할 간격 (최소 1분 ~ 최대 60분.)
	char sOrd_gbn        [1  ]; // " '1':지정가,       '2':시장가 '3':최유리지정가, '4':최우선지정가 '5':매수1호가,    '6':매수2호가 '7':매도1호가,    '8':매도2호가"
	char sORD_QRY_GBN    [1  ]; // 1:수량직접입력, 2:백분율로 입력
	char sORD_BASE_QRY   [10 ]; // 기준수량 (ex: 잔고의 50%) 수량 구분에 따라 수량 혹은 백분율로 입력됨.
	char sOrd_qty1       [10 ]; // 주문수량1  수량 혹은 백분률( 1 ~ 100%)  로 입력됨.
	char sOrd_qty2       [10 ]; // 주문수량2  수량 혹은 백분률( 1 ~ 100%)  로 입력됨.
	char sOrd_qty3       [10 ]; // 주문수량3  수량 혹은 백분률( 1 ~ 100%)  로 입력됨.
	char sOrd_qty4       [10 ]; // 주문수량4  수량 혹은 백분률( 1 ~ 100%)  로 입력됨.
	char sOrd_qty5       [10 ]; // 주문수량5  수량 혹은 백분률( 1 ~ 100%)  로 입력됨.
	char sOrd_qty6       [10 ]; // 주문수량6  수량 혹은 백분률( 1 ~ 100%)  로 입력됨.
	char sOrd_qty7       [10 ]; // 주문수량7  수량 혹은 백분률( 1 ~ 100%)  로 입력됨.
	char sOrd_qty8       [10 ]; // 주문수량8  수량 혹은 백분률( 1 ~ 100%)  로 입력됨.
	char sOrd_qty9       [10 ]; // 주문수량9  수량 혹은 백분률( 1 ~ 100%)  로 입력됨.
	char sOrd_qty10      [10 ]; // 주문수량10  수량 혹은 백분률( 1 ~ 100%)  로 입력됨.
	char sOrd_prc        [10 ]; // 주문가격 (매수1/2/3호가, 매도 1/2/3 호가) 혹은 지정가로 저장 (ex) D1 :매도1호가, S2 :매수2호가, J12300 : 지정가 12300원)
	char sCond_obs_gbn   [1  ]; // 1': 손익조건, '2':사용자조건
	char sCond_obs_cnt   [4  ]; // 최대 20개, USER_DEF 사이즈과 관련
	char sCond_obs_mix   [80 ]; // "조건검색의 EXPLEN값 사용(80) 게좌조건의 경우는 모두 'OR'로 연결 사용자조건의 경우는 사용자 입력 조합식"
	User_Define sCond_obs_detl  [4]; // "조건검색의 UserDefine 구조체 사용, 배열 4개 (입력 가능 조건수는 4개)"
} TR77080_OUT;
// 20120723 ssj - 서버자동주문 <<

//신용약정 여부 조회
typedef struct _TR12151_IN
{
	char acct[20]; //계좌번호
	char privateip[16]; //999999999999
	char reqreccnt[4]; //"0001"
} TR12151_IN;

typedef struct _TR12151_OUT
{
	char ret[1]; // 0: 미약정 1: 약정(신용계좌)
} TR12151_OUT;


// 서버자동주문 동의서 TR

/****************************************************************************/
/*  TR CODE : tr_20019                                                      */
/****************************************************************************/
typedef struct
{
	char    htsId               [128];   /* 사용자ID     */
	char    tsGubun             [  1];  /* 0:미등록,1:등록,2:조회      */
	char    ipAddress           [ 12];  /* IP ADDRESS                  */
	char    commCode            [  1];   /* 매체구분: P: 서버자동주문 S: 시세알리미     */
} TR_IN_AGREE;

typedef struct
{
	char    tsGubun             [  1];  /* 0:미등록,1:등록             */
	char    result              [  1];  /* 0:실패,1:성공               */
} TR_OUT_AGREE; 
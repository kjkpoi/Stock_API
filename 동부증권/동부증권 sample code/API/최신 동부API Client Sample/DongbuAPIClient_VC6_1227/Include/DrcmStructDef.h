
#define		DRCM_CONNECT			-70			//접속
#define		DRCM_DISCONNECT			-71			//접속 해제
#define		DRCM_SENDDATA			-72			//TR전송
#define		DRCM_ADVICE				-73			//실시간 데이타 등록
#define		DRCM_UNADVICE			-74			//실시간 데이타 등록해제

#define		DRCM_CLIENT_IP			-75			//접속 아이피 
#define		DRCM_F_ACCLIST			-76			//계좌리스트

//20100701 EUNSOOK >>
#define		DRCM_IS_ALIVE			-77			//alive
#define		DRCM_ERR_SOCKET			-78			//소켓오류
//20100701 EUNSOOK <<

//20111130 EUNSOOK >>
#define		DRCM_S_ACCLIST			-79			//주식계좌리스트
#define		DRCM_ALL_ACCLIST		-80			//선옵,주식계좌리스트
//20111130 EUNSOOK <<

#define		DRCM_DRDS_DATA			-700		//실시간 데이타 RECEIVE

#define		DRCM_MSG_LOGINFAIL		  -1		//로그인 실패
#define		DRCM_MSG_SOCKETFAIL		  -2		//서버 접속 실패
#define		DRCM_MSG_RESTART		  -3		//재접속

#define		SIZE_TRCODE				5			//TR CODE 글자 길이
#define		SIZE_RTCODE				3			//실시간 CODE 글자 길이


#define		DRCM_RISK_AGREEMENT		700	   	    //위험고지 동의

#define		TR_20000			"20000"		//주문
#define		TR_RISK_AGREEMENT	"20010"
#define		TR_20030			"20030"		//선물주문
#define		TR_20020			"20020"		//주식주문
#define		TR_13655			"13655"		//잔고조회
#define		TR_13615			"13615"		//체결내역조회
#define		TR_15813			"15813"		//평가현황조회
#define		TR_13653			"13653"		//수수료 및 주문가능금액 조회
#define		TR_16260			"16260"		//옵션종목별매도증거금
#define		TR_14051			"14051"		//신규/청산 가능수량


#define		TR_13118			"13118"  //주식체결
#define		TR_13148			"13148"  //주식잔고
#define		TR_STOCKEVAL		"20051"	 //평가현황조회

//DRCM 에 접속하기 위한 구조체
typedef struct {		
	HWND		hClientWnd;			// 데이터를 받을 헨들	
	char		szUserId[20];		// 로그인 아이디
	char		szPwd[20];			// 로그인 패스워드	
	char		szCertPwd[20];		// 공인인증 패스워드	
	BOOL		bShowLoginDlg ;		// 로그인창을 보여줄것인지
	
} ST_DRCM_USER ;




//------------------------------------------------------------------------------------------
// 주문관련 공통 INPUT HEADER & OUTPUT STRUCTURES
//------------------------------------------------------------------------------------------
typedef struct _TRORDER_I
{
	char    incnt    [ 4];      /* 주문 cnt								*/
	char    mapno    [ 5];      /* TR사용하는 Map번호					*/
} TR_ORDER_I;

typedef struct _TRORDER_O
{
	char    outcnt   [ 4];       /* 주문 cnt                  */
} TR_ORDER_O;

#define SZ_ORDER_O     sizeof(TR_ORDER_O)

typedef struct _TRORDER_OS
{
	char	clikey   [ 8];      /* 주문 key                  */
	char    juno     [ 9];      /* 주문번호                  */
	char    msgcd    [ 6];      /* 메시지코드                */
	char    msgcm   [100];      /* 처리메시지                */
} TR_ORDER_OS;

#define SZ_ORDER_OS     sizeof(TR_ORDER_OS)

/*-----------------------------------------------------------*/
/* 선물옵션 주문				                             */
/*-----------------------------------------------------------*/
typedef struct _TR20030_IS
{
	char	clikey   [ 8];      /* 주문 key								*/
	char	gb       [ 1];      /* 1:매도, 2:매수, 3:정정, 4:취소		*/
	char    geja     [20];      /* 계좌번호								*/
	char    passwd   [ 8];      /* 비밀번호								*/
	char    code     [15];      /* 종목코드								*/
	char    wonno    [ 9];      /* 원주문번호							*/
	char    jutype   [ 2];      /* 호가유형코드							*/
								/* 00:지정,03:시장,05:조건부,06:최유리	*/
	char    juprc    [12];      /* 주문가격 S9(9).99					*/
	char    qty      [15];      /* 주문수량 S9(15)						*/
	char    ip       [16];      /* 클라이언트 IP주소(예: 192009101031)	*/
} TR_20030_IS;

#define SZ_FUTURE_IS     sizeof(TR_20030_IS)

/*-----------------------------------------------------------*/
/* 주식 주문				                             */
/*-----------------------------------------------------------*/
typedef struct _TR20020_IS
{
	char	clikey     [ 8];   /* 주문 key								     */
	char	gb         [ 1];   /* 1:매도, 2:매수, 3:정정, 4:취소		     */
	char    geja       [20];   /* 계좌번호								     */
	char    passwd     [ 8];   /* 비밀번호								     */
	char    code       [15];   /* 종목코드								     */
	char    wonno      [ 9];   /* 원주문번호							     */
	char    jutype     [ 2];   /* 호가유형코드							     */
							   /* 00:지정,03:시장,05:조건부,06:최유리	     */
	char    juprc      [12];   /* 주문가격 S9(9).99					         */
	char    qty        [15];   /* 주문수량 S9(15)						     */
	char    zMgntrnCode[ 3];   /* 신용거래코드                               */
	                           /* 000:보통 001:유통융자신규 003:자기융자신규 */
	                           /* 007:자기대주신규 101:유통융자상환          */
	                           /* 103:자기융자상환 107:자기대주상환          */
	                           /* 180:예탁담보대출상환(신용)                 */
	char    zLoanDt    [ 8];   /* 대출일자                                   */
	char    ip         [16];   /* 클라이언트 IP주소(예: 192009101031)        */
} TR_20020_IS;

#define SZ_STOCK_IS     sizeof(TR_20020_IS)

typedef struct
{
	int  m_nRow ;
	int  m_nTrIndex ;
	int	 m_nOrderNo ;
	int	 m_nOrgOrderNo ;	
}ST_ORDERINFO;


//=======================================================================================
// 잔고조회
//=======================================================================================
#define tr_13655MAX 250

typedef struct 
{
	char  geja     [20];    /* 지점번호(3)+계좌번호(8) ->20 */
} TR_13655_I;


typedef struct 	
{
	char  yakjungtot [17];  /* 총   약정금액                    */
	char  pyungpltot [17];  /* 총   평가손익                    */
	char  jumuntot   [17];  /* 주문가능총액                     */

	char  amotpyngtot[17];  /* 총   평가금액                    */
	char  realpltot  [17];  /* 당일 실현손익                    */
	char  jumuncash  [17];  /* 주문가능현금                     */
	char  suikratetot[ 9];  /* 총   수익율   7->9               */

} TR_13655_S;

typedef struct 
{
	char  jocode     [15];  /* 종목코드                8 -> 15  */
	char  mmgb_attr  [ 3];  /* 매매구분                3 ->  3  */
	char  mmgb       [ 5];  /* 매매구분                5 ->  5  */

	char  avqty      [15];  /* 청산가능                9 -> 15  */
	char  pnonqty    [15];  /* 전일잔고                9 -> 15  */
	char  qtychg     [15];  /* 증감                    9 -> 15  */
	char  tnonqty    [15];  /* 보유수량                9 -> 15  */
	char  tnocontqty [15];  /* 미체결주문수량          9 -> 15  */

	char  tnonprc    [12];  /* 매입단가               12 -> 12  */
	char  price      [ 6];  /* 현재가                  6 ->  6  */
	char  pyungpl    [15];  /* 평가손익               15 -> 15  */
	char  suikrate   [ 9];  /* 수익율                  9 ->  9  */

	char  tnonamt    [15];  /* 약정금액               15 -> 15  */
	char  pyungamt   [15];  /* 평가금액               15 -> 15  */
	char  fee        [12];  /* 수수료                 12 -> 12  */

	char  bid        [ 6];  /* 매수호가                6 ->  6  */
	char  offer      [ 6];  /* 매도호가                6 ->  6  */
	char  hprice     [ 6];  /* 상한가                  6 ->  6  */
	char  lprice     [ 6];  /* 하한가                  6 ->  6  */

	char  gdssect    [ 1];  /* 시장소속구분            1 ->  1  */
	char  resbpl     [15];  /* 당일실현손익           15 -> 15  */
	char  jutp       [ 3];  /* 주문유형                3 ->  3  */
	char  trdunt     [15];  /* 거래단위               15 -> 15  */
	char  tdmemeamt  [15];  /* 당일매수또는매도금액   15 -> 15  */
	char  memeamt    [15];  /* 매매대금합             15 -> 15  */
} TR_13655_G;

typedef struct 	
{
	TR_13655_S		sm;

	char  gridcnt    [  4]; // Grid count
	TR_13655_G  gr[tr_13655MAX];
	
} TR_13655_O;


//=======================================================================================
// 체결 내역 조회
//=======================================================================================
#define tr_13615MAX 300
typedef struct 
{
	char  geja     [20];    /* 지점번호(3)+계좌번호(8) ->20 */
	char  passwd    [8];	/* 4->8 */
	char  sort      [1];    /* 정순(1) 역순(2)         */
	char  userfld [100];    /* 입력그대로 RETURN       */
} TR_13615_I;


typedef struct 
{
	char  juno      [9];    /* 주문번호     5->6->9  */
	char  wonjuno   [9];    /* 원주문번호   5->6->9  */
	char  jgcode    [15];   /* 종목코드     8->15->15 */
	char  jugb_attr [3];    /* 주문구분속성 3->3->3  */
	char  jugb      [12];   /* 주문구분     8->12->12 */
	char  jutype    [12];   /* 주문유형     6->6->12  */
	char  juprc     [12];   /* 주문단가     6->10->12 */
	char  juqty     [15];   /* 주문수량     5->7->15  */
	char  cheprc    [12];   /* 체결가격     6->10->12 */
	char  cheqty    [15];   /* 체결수량     5->7->15  */
	char  nonqty    [15];   /* 미체결       5->7->15  */
	char  denymsg   [40];   /* 세부거부사유       */
} TR_13615_G;

typedef struct 
{
	char        userfld [100];             /* 입력그대로 RETURN    */

	char        gridcnt [4];               /* Grid count           */
	char        gridlen [4];               /* Bojo Length          */
	char        gridmsg [5];               /* Grid Bojo Data       */
	TR_13615_G  grid[tr_13615MAX];
} TR_13615_O;

//체결내역 <<

//=======================================================================================
// 수수료 조회
//=======================================================================================
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



//평가현황 >>
typedef struct
{
	char        accno [20];			//계좌번호
	char        pass [8];			//입력비밀번호
	char        date [8];			//주문일

	char        janggubun [1];		//잔고평가구분 #0:기본설정1:이동평균법2:선입선출법 (보통은 '0'을 사용)
	char        futuregubun [1];	//선물가격평가구분  #2:전일종가1:당초가
	char        ip_addr [16];		//privateip
	char		nxtKey [19];		//연속키:0 :O_SETCONTBTNKEY    -> 실제 19바이트
} TR_15813_I;


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

} TR_15813_O;
//평가현황 <<

//옵션 종목별 증거금
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
	
} TR_16260_OS;

//신규/청산 가능 수량
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


/*-----------------------------------------------------------*/
/* TrNo: 20000 패킷			                                 */
/*-----------------------------------------------------------*/

typedef struct
{
    char    incnt    [ 4];       /* 주문 cnt                 */
    char    mapno    [ 5];       /* TR사용하는 Map번호       */
} TR_20000_I;

typedef struct
{
    char    clikey   [ 8];      /* 주문 key                                 */
    char    gb       [ 1];      /* 1:매도, 2:매수,  3:정정, 4:취소          */
    char    geja  [20];      /* 계좌번호                                 */
    char    passwd [ 8];      /* 비밀번호                                 */
    char    code[15];      /* 종목코드                                 */
    char    wonno[ 9];      /* 원주문번호   S9(9)                       */
    char    jutype [ 2];  /* 선물옵션호가유형코드                */
                                /* 00:지정가 03:시장가 05:조건부지정가      */
                                /* 06:최유리지정가                          */
    char    juprc  [12];      /* 주문가     S9(9).99 ->소수점빼고         */
    char    qty  [15];      /* 주문수량   S9(15)                        */
    char    ip       [16];      /* 클라이언트 IP주소(예: 192009101031)      */
} TR_20000_IS; //106

typedef struct 
{
    char    outcnt   [ 4];       /* 주문번호 cnt              */
} TR_20000_O;

typedef struct
{
    char    clikey   [ 8];       /* 주문 key                  */
    char    lOrdNo   [ 9];       /* 주문번호   S9(9)          */
    char    msgcd    [ 6];       /* 메시지코드                */
    char    msgcm   [100];       /* 처리메시지                */
} TR_20000_OS;






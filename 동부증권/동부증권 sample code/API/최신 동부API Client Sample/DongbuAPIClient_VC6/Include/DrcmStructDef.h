
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

//20120109 EUNSOOK >>
#define		TR_15812			"15812"		//선옵(원장)잔고평가
//20120109 EUNSOOK <<

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


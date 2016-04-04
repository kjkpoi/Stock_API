#ifndef _CLIENTDEINE_H
#define _CLIENTDEINE_H


#define USE_CREDITORD			1

#define MAPTYPE_COND_ACCOUNT -100	//손익조건
#define MAPTYPE_COND_ITEM	 -200	//BM조건
#define MAPTYPE_COND_BASE	 -300	//시세조건
#define MAPTYPE_COND_INDEX	 -400	//지표조건

//시장 구분 
#define SVRORD_MARKETTYPE_STOCK  "S" //주식
#define SVRORD_MARKETTYPE_ELW	"E" //ELW
#define SVRORD_MARKETTYPE_FUT	"F" //선물
#define SVRORD_MARKETTYPE_OPT	"O" //옵션
#define SVRORD_MARKETTYPE_SFUT  "K" // 주식선물
#define SVRORD_MARKETTYPE_UP	"U" //업종

#define SVRORD_JOB_REG			"I"		//등록
#define SVRORD_JOB_UPDATE		"U"		//수정
#define SVRORD_JOB_DELETE		"D"		//삭제
#define SVRORD_JOB_STOP			"S"		//중지
#define SVRORD_JOB_START		"R"		//감시

#define SVRORD_AUTO_YES	0			//자동
#define SVRORD_AUTO_NO	1			//반자동

#define SVRORD_MMTYPE_SELL "1"		//매도
#define SVRORD_MMTYPE_BUY  "2"		//매수

#define SVRORD_PRICETYPE_TARGET 1   //지정가
#define SVRORD_PRICETYPE_MARKET 2   //시장가

#define MASS_ID				"500" // 매체구분값(HTS)

enum
{
	CHANGE_ALL_WATCH,
	CHANGE_ALL_STOP,
	CHANGE_ALL_DELETE,
	CHANGE_ALL_SET,
};

enum
{
	POS_SELL = 1, 
	POS_BUY,
};

enum
{
	CUR_NORMAL = 0,
	CUR_WAIT,
};
enum
{
	SEC_BUY,
	SEC_SELL,
	SEC_BOTH,
};

enum
{
	VOL_CLEAR,
	VOL_NEW,
};

enum
{
	REQ_REG_SETTING,
};

enum
{
	MPRICE_MATCH, // 매입가
	MPRICE_USER, // 수정단가
};

enum {
	FL_NONE,
	FL_QRY_AGREE, // 조회
	FL_REG_AGREE, // 등록
};
// 20120723 ssj - 서버자동주문 <<

enum enORDTYPE
{
	NORMAL_ORDER = 1,	// 일반주문
	HOGADIV_ORDER,		// 호가분할주문
	TIMEDIV_ORDER		// 시간분할주문
};

enum
{
	WND_SELL = 0, // 0: 매도, 1: 매수 -> m_tabSellBuy 의 인덱스와 맞추어야 한다!!
	WND_BUY,
};

enum
{
	ORDTYPEWND_NORMAL,
	ORDTYPEWND_DIV,
};

// 20120723 ssj - 서버자동주문 >>
// EVAL_UNIT_PERCENT: %, EVAL_UNIT_WON: 원, EVAL_UNIT_TICK: tick
enum {
	EVAL_UNIT_PERCENT = 0,
	EVAL_UNIT_WON, 
	EVAL_UNIT_TICK,
};

// BASE_TYPE_MATCH: 매입가, BASE_TYPE_USER: 수정단가
enum {
	BASE_TYPE_MATCH = 0, 
	BASE_TYPE_USER,
};
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
enum
{
	BAL_NONE,
	BAL_SELL,
	BAL_BUY,
};

#define SVRORD_CASH			0	//현금
#define SVRORD_CREDIT		1	//신용 유융
#define SVRORD_CREDIT_YU	3	//자융

#define EXPIREDATE		30
//화면 유형(화면 번호또는 이름으로 구분)
#define  OPENTYPE_STOCK_BUY   1

#define  OPENTYPE_FUTURE_BUY  3

#define  OPENTYPE_STOCK_SELL  5
#define  OPENTYPE_FUTURE_SELL 7


#define  MODE_EQUITIES   9
#define  MODE_DERIVATIVES  11

#define CODEINPUT_PROPERTY_FO_SFO_SHARE	 _T("CC=00011000000000000010000000100001000000000000000000000000000000000:CD=0:CH=1:CT=1:MHC=20:MXL=8:MIL=8:ECP=1;1;0;1;0;0;:UEP=1:CN1=코드:CN2=종목명:GS=코드-선물옵션7;코드A-선물옵션2;코드B-선물옵션2;코드C-선물옵션2;코드-주식선옵7;:LS=코드2;") 

#define	TRADINGTYPE_BID					"매수"
#define	TRADINGTYPE_SELL				"매도"
#define	TRADINGTYPE_REPURCHASE			"환매"
#define	TRADINGTYPE_LIQUIDATAION		"전매"
#define	TRADINGTYPE_CLEARING			"청산"

//그리드
#define CEL_BTN_ONOFF		0
#define ITEMCODE_COL		1 //종목명, 종목코드
#define COL_CREDIT_FOSELLBUY	2 //구분	
#define JANGO_VOL_COL		3 //보유수량
#define UNITPRICE			4 //단가
#define	COL_USER_PRICE		5 // 수정단가
#define CUR_PRICE			6 //현재가  
#define EVALUATE_COL		7 //손익    
#define EVALUATERATE_COL	8 //손익률  
#define COL_LOANDATE		9 //대출일   
#define COL_EXPIRE_DATE		10 //유효기간
#define COL_BUY_COND1_ACC	12 //계좌조건 - 매수
#define ORDINFO_END_COL		19 // 조건 마지막 행
#define COL_MTYPE			20 // 매체구분
#define COL_BTN_X			21 // 삭제버튼
#define COL_COST			22 // 매입금액
#define COL_UNIT			23 // 거래승수

#define		COLOR_BACK_INDEX			0
#define		COLOR_TEXT_INDEX			2		// 기본글꼴색
#define		COLOR_BSKIN_TEXT_INDEX		3		// 블랙스킨 글꼴색
#define		COLOR_GRID_TEXT_INDEX		3

#define		COLOR_UP_INDEX				4		// 상승색
#define		COLOR_DOWN_INDEX			6		// 하락색
#define		COLOR_BSKIN_UP_INDEX		5		// 블랙스킨 상승색
#define		COLOR_BSKIN_DOWN_INDEX		7		// 블랙스킨 하락색

#define		COLOR_BUY_INDEX1			14
#define		COLOR_BUY_INDEX2			15
#define		COLOR_SELL_INDEX1			16
#define		COLOR_SELL_INDEX2			17
#define		COLOR_MODCANCEL_INDEX		18
#define		COLOR_MODCANCEL_INDEX2		19

#define		COLOR_GRID_HEADER_INDEX		20
#define		COLOR_LINE_INDEX			22
#define		COLOR_GRID_BACK_INDEX		23
#define		COLOR_GRID_SELECT_INDEX		29		// 선택칼라

#define		COLOR_CHKBOX_LINE_INDEX		70

#define ID_XP1	101 // 조건변경
#define ID_XP2	102 // 메세지
#define ID_XX9	201 // 주식 실시간 잔고
#define ID_XF3	202 // 선옵 실시간 잔고
#define ID_XF4	203 // 선옵 실시간 잔고

#define ID_S31	301 // 주식 현재가
#define ID_ELC	302 // ELW 현재가
#define ID_SC0	303 // 선물 현재가
#define ID_OC0	304 // 옵션 현재가
#define ID_JC0	305 // 주식선물 현재가
#define ID_OPC	306 // 주식옵션 현재가

#define ID_X11	401 // 주식 호가
#define ID_ELH	402 // ELW 호가
#define ID_SH0	403 // 선물 호가
#define ID_OH0	404 // 옵션 호가
#define ID_JH0	405 // 주식선물 호가
#define ID_OPH	406 // 주식옵션 호가

#define ID_JANGO_S31	501 // 주식 현재가 (잔고용)
#define ID_JANGO_ELC	502 // ELW 현재가 (잔고용)
#define ID_JANGO_SC0	503 // 선물 현재가 (잔고용)
#define ID_JANGO_OC0	504 // 옵션 현재가 (잔고용)
#define ID_JANGO_JC0	505 // 주식선물 현재가 (잔고용)
#define ID_JANGO_OPC	506 // 주식옵션 현재가 (잔고용)

#define  STR_NOINPUTVALUE "9999"

/////////////
//  컨트롤 //
/////////////
//컨트롤 길이 (컨트롤 문자갯수와 X값이 대략 일치       X4 = 4글자들어가는 컨트롤 길이)
#define LEN_CTRL_WIDTHX1  20
#define LEN_CTRL_WIDTHX2  40
#define LEN_CTRL_50		  50
#define LEN_CTRL_WIDTHX4  60
#define LEN_CTRL_70		  70
#define LEN_CTRL_WIDTHX8  90
#define LEN_CTRL_100	 100
#define LEN_CTRL_WIDTHX10  120
#define LEN_CTRL_130  130
#define LEN_CTRL_WIDTHX20  240

#define LEN_SPIN_WIDTH	  17

#define LEN_COMBO_HEIGHT  100;

//컨트롤 높이
#define LEN_CTRL_HEIGHT  20

//컨트롤과 컨트롤 가로 간격
#define LEN_CTRL_HGAPTYPE1  1    //연결되는 컨트롤과의 간격
#define LEN_TEXT_TO_CTRL    6    //Text와 컨트롤 사이
#define LEN_CTRL_TO_TEXT    4    //컨트롤에 들어가는 텍스트

//컨트롤과 컨트롤 세로 간격
#define LEN_CTRL_VGAP		1   //일반간격
#define LEN_CTRL_VGAP5		5
#define LEN_CTRL_VGAP_CHECK	12	//체크박스 사이 간격
#define LEN_CTRL_VGAP_Ex    17  //타그룹과의 간격

#define DEFAULT_COLUMN_COUNT		7
#define PROGRAM_TITLE				"서버자동주문"

#define VOLCHECK		 1 //주문가능수량
#define LQVOLCHECK		 2 //청산가능수량


//>>[KSJ000000026] 신용주문추가, 주문구분추가
#define PRICETYPE_CNT_STOCK  _countof(PRICE_TYPE_STRING_EX)
#define PRICETYPE_CNT_ELW	 _countof(PRICE_TYPE_STRING_ELW_EX)
#define PRICETYPE_CNT_FUTOPT _countof(PRICE_TYPE_STRING_FUTOPT_EX)
#define PRICETYPE_CNT_SFUT		_countof(PRICE_TYPE_STRING_SFUT)

const LPCTSTR PRICE_TYPE_TARGET[] =    {_T("지정가"), _T("조건부지정가"), _T("지정가[IOC]"), _T("지정가[FOK]")};

const LPCTSTR PRICE_TYPE_STRING_EX[] =        {_T("지정가"), _T("시장가"), _T("최유리지정가"), _T("최우선지정가"), _T("조건부지정가"), _T("지정가[IOC]"), _T("시장가[IOC]"), _T("최유리[IOC]"), _T("지정가[FOK]"), _T("시장가[FOK]"), _T("최유리[FOK]")};
const LPCTSTR PRICE_TYPE_VALUE_EX[] =         {_T("1"),      _T("2"),      _T("3"),            _T("4"),            _T("9"),            _T("A"),           _T("B"),           _T("C"),           _T("D"),           _T("E"),           _T("F")};

const LPCTSTR PRICE_TYPE_STRING_ELW_EX[] =    {_T("지정가"), _T("지정가[IOC]"), _T("지정가[FOK]")};
const LPCTSTR PRICE_TYPE_VALUE_ELW_EX[] =     {_T("1"),      _T("A"),           _T("D")};

const LPCTSTR PRICE_TYPE_STRING_FUTOPT_EX[] = {_T("지정가"), _T("시장가"), _T("최유리지정가"), _T("조건부지정가"), _T("지정가[IOC]"), _T("시장가[IOC]"), _T("최유리[IOC]"), _T("지정가[FOK]"), _T("시장가[FOK]"), _T("최유리[FOK]")};
const LPCTSTR PRICE_TYPE_VALUE_FUTOPT_EX[] =  {_T("1"),      _T("2"),      _T("3"),            _T("9"),            _T("A"),           _T("B"),           _T("C"),           _T("D"),           _T("E"),           _T("F")};
const CString FUTOPT_ORDTYPE_KEY_DONGBU[] =   { "00",           "03",         "06",               "05",               "10",              "13",             "16",               "20",              "23",              "26"};

const LPCTSTR PRICE_TYPE_STRING_SFUT[] = {"지정가", "지정가[IOC]", "지정가[FOK]"};
const LPCTSTR PRICE_TYPE_VALUE_SFUT[] =  {"1",      "A",           "D"};
const CString SFUT_ORDTYPE_KEY_DONGBU[] ={"00",	    "10",          "20"}; // 주문 가능수량 조회 위해 사용

const LPCTSTR PRICE_GB_STRING[] = {_T("지정가"), _T("현재가"), _T("매수1호가"), _T("매수2호가"),
_T("매도1호가"), _T("매도2호가"), _T("상한가"), _T("하한가")};

const LPCTSTR CREDIT_BUY_TYPE_STRING[] = { "대주상환" }; // "융자"는 매수에서 제외
const CString CREDIT_BUY_TYPE_VAL[] =	{  "03", "07"};    // 주문 가능수량 조회 위해 사용

const LPCTSTR CREDIT_SELL_TYPE_STRING[] = { "대주", "자기융자상환", "유통융자상환", "담보대출상환" };
const CString CREDIT_SELL_TYPE_VAL[] =	{ "05",  "03", "01", "80"};  // 주문 가능수량 조회 위해 사용

const LPCTSTR PRICE_TYPE_STRING2[] = {_T(""), _T("CP"), _T("S1"), _T("S2"), _T("D1"), _T("D2"), _T("HP"), _T("LP")};//[KSJ000000026] 신용주문추가, 주문구분추가


enum
{
	COND_PL, // 손익조건
	COND_Q, // 시세조건
	COND_BM, // BM조건
	COND_I, // 지표조건
};

const LPCTSTR ORDER_COND_STRING[] = {_T("손익조건"), _T("시세조건"), _T("BM조건"), _T("지표조건")/* , _T("사용자조건")*/};
const int	  ORDER_COND_INT[] =	{    COND_PL,		 COND_Q,         COND_BM,      COND_I/* , _T("사용자조건")*/};


const LPCTSTR ORDER_TYPE_STRING[] = {_T("일반주문"), _T("호가분할")/*, _T("시간분할") */};
const LPCTSTR DIV_STANDARD_STRING[] = {_T("정배열"), _T("등배열"), _T("역배열") };
const LPCTSTR PRICE_STANDARD_STRING[] = {_T("매도7호가"), _T("매도6호가"),_T("매도5호가"), _T("매도4호가"), 
				_T("매도3호가"), _T("매도2호가"), _T("매도1호가"),
				_T("매수1호가"), _T("매수2호가"), _T("매수3호가"), 
				_T("매수4호가"), _T("매수5호가"), _T("매수6호가"), _T("매수7호가")};
#define DIVSTANDARD_INDEX 4	//기준가 콤보박스 시작인덱스

const LPCTSTR PRICE_STANDARD_STRING_CONVERT[] = {_T("D7"), _T("D6"),_T("D5"), _T("D4"), _T("D3"), _T("D2"), _T("D1"), _T("S1"), _T("S2"), _T("S3"), _T("S4"), _T("S5"), _T("S6"), _T("S7")};


const LPCTSTR XML_TYPENAME[] = { _T("CONDI_TYPE"), _T("TARGETBASE_TYPE"), _T("GUBUN"), _T("GUBUN_DEFVAL")
	, _T("NOT_USER"), _T("NOT_DEFVAL"), _T("RESULT_VIEW_ID"), _T("RESULT_VIEW_DEFVAL"),
	_T("CHART_VALSET"), _T("FILE_NAME")};

#define RECOMMEND_ROOTTITLE				"추천조건"
#define USER_ROOTTITLE			  		"사용자조건"
#define LANGUAGE_ROOTTITLE				"랭귀지"
#define BOOKMARK_SUBROOTTITLE			"즐겨찾기"

#define INT2STR_BUF(xStr, nSize, nStr) sprintf_s(xStr, "%#0*.*d", nSize, nSize, nStr)

#define SVR_AUTO_ORDER_STOCK_FILE		_T("SvrAutoOrd_STOCK.xml")
//#define SVR_AUTO_ORDER_ELW_FILE		_T("SvrAutoOrd_ELW.xml")
//#define SVR_AUTO_ORDER_FO_FILE		_T("SvrAutoOrd_FO.xml")

// 20120723 ssj - 서버자동주문 >>
#define STR_CAPTION				"서버자동주문"
#define E_STR_PASSWORD_NEEDED	"비밀번호를 입력하여 주십시오."
#define E_STR_ACNT_NEEDED		"계좌번호를 입력하여 주십시오."
#define E_STR_CODE_NEEDED		"종목을 선택하여 주십시오."
#define E_STR_MP				"HTS/MTS에서 등록/수정된 조건만 수정할 수 있습니다."


#define E_STR_SOPT				"주식옵션은 지원하지 않습니다."


enum
{
	SET_FOCUS_ACNT,
	SET_FOCUS_PASSWORD,
};

#define MCTRL_ADD_ITEM			4
#define MCTRL_SETALL_ITEM		5


#define MAX_CONDCNT_INSCREEN   100

//Resource
#define INDEX_START_CHKBOX			5000
#define INDEX_END_CHKBOX			5200

#define INDEX_START_COMBO			5300
#define INDEX_END_COMBO				5400

//OrdGrid
#define MAX_ROWCOUNT	10
#define STATE_NODATA -1
#define STATE_ERROR  0
#define STATE_WATCH  1
#define STATE_STOP   2
#define STATE_DELETE 3

//리얼ID
#define	REAL_CHEJAN_REG			0x24	// 주문 체결/잔고 실시간등록(티커체결통보 : 36)
#define	REAL_SISE_REG			0x32	// 시세등록					(주식종목시세 : 50 )
#define	REAL_ELWSISE_REG		0x37	//ELW시세등록
#define	REAL_FUTSISE_REG		0x41	//선물시세등록
#define	REAL_OPTSISE_REG		0x43	//옵션시세등록


//주문체결 자동갱신 ID
#define RID_SEMIAUTO_CHEGYUL	0x28

#define COLOR_GRID_HEADER_FACE				    RGB(224, 230, 245)//RGB(227, 231, 237)//RGB(218, 218, 218)


#define COLOR_GRID_SEL_ROW		RGB(226, 236, 251)
#define COLOR_GRID_EVEN_ROW		RGB(255, 255, 255)
#define COLOR_GRID_ODD_ROW		RGB(249, 249, 249)
#define COLOR_GRID_LINE			RGB(189, 189, 189) //RGB(172, 178, 185)

#define COLOR_ORD_HEADER  	 RGB(51, 153, 102)
#define COLOR_ORD_SELL	  	 RGB(52, 117, 205)
#define COLOR_ORD_BUY	  	 RGB(255, 0, 0)


#define COLOR_BORDER	RGB(127,145,170)
#define COLOR_BUY_CANVAS RGB(254, 235, 236)
#define COLOR_SELL_CANVAS RGB(200, 220, 240)

#define COLOR_MAIN_CANVAS RGB(255, 255, 255)
#define COLOR_SMS_CANVAS RGB(217, 217, 217)
#define COLOR_SMS_TEXT  	RGB(64, 64, 64)
#define COLOR_SMS_TEXT_GRAY	RGB(127, 127, 127)




#define GETFONT(logFont, nHeight, nWeight, fontData) \
	logFont.lfHeight = nHeight;                            \
	logFont.lfWidth = 0;                                    \
	logFont.lfEscapement = 0;                               \
	logFont.lfOrientation = 0;                              \
	logFont.lfWeight = nWeight;                             \
	logFont.lfItalic = 0;                                   \
	logFont.lfUnderline	=	0;                                \
	logFont.lfStrikeOut	=	0;                                \
	logFont.lfCharSet	=	129;                                \
	logFont.lfOutPrecision	=	3;                            \
	logFont.lfClipPrecision	=	2;                            \
	logFont.lfQuality	=	1;                                  \
	logFont.lfPitchAndFamily=	49;                           \
	strcpy_s(logFont.lfFaceName, (const char*)_T("굴림체"));  \
	fontData.CreateFontIndirect(&logFont);

#define GETPATH_APP(strAppPath)       \
	char buf[255];                                                        \
	GetModuleFileName(NULL, buf, 255);                                    \
	int lastlocationofbackslash = 0;                                      \
	int nBufCnt = strlen(buf);                                            \
	for (int i = 0; i < nBufCnt; i++)                                     \
{                                                                     \
	if (buf[i] == '\\')                                                 \
	lastlocationofbackslash = i;                                      \
}                                                                     \
	CString strAppPath = _T("");                                          \
	for (int j = 0; j < lastlocationofbackslash; j++)                     \
	strAppPath += buf[j];  

// 20120723 ssj - 서버자동주문 >>
static const char *STR_ON = "ON";
static const char *STR_OFF = "OFF";

#define COLOR_STR_ON		RGB(0, 255, 0)

static const int WATCH_STOP = 0;
static const int WATCH_START = 1;
// 20120723 ssj - 서버자동주문 <<


//배경및 컨트롤 색상 
typedef struct  
{
	int m_nHeaderType;
	COLORREF m_clrTabSel;
	COLORREF m_clrTabUnSel;	
	COLORREF m_clrTabSelText;
	COLORREF m_clrTabUnSelText;
	COLORREF m_clrTabBody;
	COLORREF m_clrTabSelGraUp;
	COLORREF m_clrTabSelGraDown;	
	COLORREF m_clrTabUnSelGraUp;
	COLORREF m_clrTabUnSelGraDown;	
} ST_TABCOLOR;

typedef struct  
{
	COLORREF m_clrGridHeader;
	COLORREF m_clrGridHText;  
	COLORREF m_clrGridHilight;
	COLORREF m_clrGridSBk;
	COLORREF m_clrGridSText;  
	COLORREF m_clrGridUpText;  
	COLORREF m_clrGridDownText;
	COLORREF m_clrGridVolText; 
} ST_GRIDCOLOR;

typedef struct _tagColorProperty
{
	COLORREF	 m_clrBkGnd;
	ST_TABCOLOR  m_stClrTab;
	ST_GRIDCOLOR m_stClrGrid;
}ST_CLIENTCOLOR;




typedef CArray<ConditionGroupInfo, ConditionGroupInfo&>		ArrCondGroupInfo;

// typedef struct tagGroupInfo
// {
// 	int nGroup;
// 	ArrCondGroupInfo arrConGrpInfo;
// } GROUP_INFO;
// 
// typedef CArray<GROUP_INFO*, GROUP_INFO*>					ArrGroups;



typedef struct stStatistic
{
	int		nTotalUp;			//상승
	int		nTotalBalance;		//보합
	int		nTotlaDown;			//하락
	int		nTotalAll;			//전체
	float	fUpRatio;			//상승종목비율
	float	fDeclineRatio;		//평균등락률
	int		nKospiAll;
	int		nKospiUp;
	int		nKospiDown;
	float	fKospiDeclineRatio;
	int		nKosdaqAll;
	int		nKosdaqUp;
	int		nKosdaqDown;
	float	fKosdaqDeclineRatio;

	int		nStrongUp;			// 강상승
	int		nNormalUp;			// 상승
	int		nSoftUp;			// 약상승
	int		nSoftDown;			// 약하락
	int		nNormalDown;		// 하락
	int		nStrongDown;		// 강하락
}STATICSTIC;

typedef struct tagOrdGrid
{
	char	cChk[1];					//체크
	char	cAutoFlag[1];				//자동,반자동
	char	szItemCode[LEN_ITEMCODE];	//종목코드
	char	szItemName[LEN_ITEMNAME];	//종목명
	char	szPrice[10];				//현재가
	char	szCondStatement[100];		//효력조건
	char	cCondType[1];				//주문형태

	char	sQtyGb[1];					//수량구분 1:수량, 2:백분율
	char	szOrdVolume[10];			//주문비중,수량
	char	szExpiredDate[8];			//유효기간
	char	cResult[1];					//처리결과
	char	cMMType[1];					//매도/매수
	char	cCredit[1];					//신용구분          
}StOrdGridData; //자동주문현황리스트
#define SZ_ST_ORDGRIDDATA sizeof(StOrdGridData)


//상단 그리드 데이터(조건항목)
typedef struct tagOrdCond
{
	CString strAccount;
	CString strCode;
	CString strMMType;
	CString strCredit;
	CString strAuto;
	CString strItemName;
	CString strPrice;
	CString strState;
	CString strExpiredData;

	CString strCondAcc;	
	CString strCondItem;	
	CString strCondPrice;
	CString strCondIndex;
	CString strCondUesr;
	CString strCondText;
	CString strLoanDate;
	
	CString strUserPrice;
	CString	strHtsMtsMp;
	
	int		nMarket;

}StOrdCondData; //조건항목
#define SZ_ST_ORDCONDDATA sizeof(StOrdCondData)


typedef struct tagOrdJango
{
	int		nMarketType;
	CString strItemName;
	CString strCode;
	CString strQty;
	CString strUintPrice;
	// 20140722 ssj - 선옵 단가 오류 수정 >> 선옵 실시간 잔고와 통일을 위해 수정
	//LONGLONG	nnOrgUnitPriceForCalc;
	// 20140722 ssj - 선옵 단가 오류 수정 <<
	CString strCurPrice;
	CString strProfitandLoss; // 손익
	CString strROP;
	CString strCreditOrdJango;
//	CString strMMType;		//매도매수구분

	CString strHideContract;	//약정금액

	// 20140709 ssj - 거래승수 저장방식으로 변경 >>
	//int     nBasePrice;		//선물 : 500000, 옵션 : 100000, 주식선물 : 10
	CString	strUnit;
	// 20140709 ssj - 거래승수 저장방식으로 변경 <<

	//>>[KSJ000000026] 신용주문추가, 주문구분추가
	// 20120723 ssj - 서버자동주문 >>
	//CString strCreditName;	//신용명
	// 20120723 ssj - 서버자동주문 <<

	CString strLoanDateOrdJango;	//대출일

	// 20120723 ssj - 서버자동주문 >>
	CString	strFOSellBuy;
	CString strSign;
	// 20120723 ssj - 서버자동주문 <<
}StOrdJango;
#define SZ_ST_ORDJANGO sizeof(StOrdJango)

//종목가격정보
typedef struct tagItemPrice
{
	CString strCode;	//종목코드
	CString strCurPrice;//현재가
	CString strSign;	//등락부호
	
}StItemPrice;
#define SZ_ST_ITEMPRICE sizeof(StItemPrice)

//잔고체결정보
typedef struct tagItemCheJan
{
	int		nMarketType;//시장
	CString strCode;	//종목코드
	CString strName;	//종목코드
	CString strCurPrice;//현재가
	CString strCheVol;  //체결량
	CString strMMType;  //매수매도구분
	CString strCredit;	//신용구분명
	CString strCreditGb;	//신용구분값
	CString strUintPrice;//매입단가
	CString	strMiGyuleAvrPrice; //약정금액(선옵)
	CString strCheUnitPriceAvr; //평균체결단가

}StCheJan;
#define SZ_ST_CHEJAN sizeof(StCheJan)

//BM조건 MapType, TagID, ChkBtnID
typedef struct tagCondKey
{
	CString strMapType;
	CString strTagID;
	int     nChkBtnID;
	int     nComboID;
	int     nLinkCtrlID;
	int     nPoint;
}StCondKey;
#define SZ_ST_CONDKEY sizeof(StCondKey)


typedef struct SEMI_AUTO_ORD_HEAD
{
	char    sKey		 [  1];   //A	
	char    sOrdCnt		 [  4];   /* 분할 주문시 총 주문건수                   */
	char    sOrdSeq      [  4];   /* 분할 주문시 몇번째 주문인지               */
	char    sMarketGb    [  1];   /* 시장구분 (S(STOCK),E(ELW),F(FUT),O(OPT))  */

	char	sCondName	 [ 50];
	char    sPSize       [  4];   /* 주문 packet size                          */
	char    sOrdData     [120];   /*Data                         */
} SEMI_AUTO_ORD_HEAD;
#define  SZ_SEMI_AUTO_ORD_HEAD sizeof(SEMI_AUTO_ORD_HEAD)

//< 주식 / ELW 일때 : 공통 Structure 뒤에 아래의 주식/ELW 주문 Structure가 들어감. >
typedef struct
{
   char  PassWd         [ 8];   /* 비밀번호(8)                              */
   char  OrdDate        [ 8];   /* 주문일(8)                                */
   char  AcctNo         [11];   /* 계좌번호(11)                             */
   char  BondTp         [ 1];   /* 주식채권구분(1) 1:주식 2:채권            */
   char  Code           [12];   /* 표준종목코드(12)                         */
   char  SellBuyTp      [ 1];   /* 매매구분(1)                              */
   char  MarketTp       [ 1];   /* 시장구분(1)                              */
                                /* 1.장내 2.장외(단주) 3.KOSDAQ             */
                                /* 4.OTCBB 5.주식ECN 9.기타                 */
   char  DaeYongTp      [ 1];   /* 대용구분(1)                              */
                                /* 선물옵션대용구분:                        */
                                /* N.현물 Y.선물옵션대용 2:인수/도          */
   char  OrdQty         [10];   /* 주문수량(10)                             */
   char  OrdPrc         [10];   /* 주문가격(10)                             */
   char  PrcModiTp      [ 1];   /* 가격정정구분 1.전부정정 2.일부정정       */
   char  QtyCancTp      [ 1];   /* 수량취소구분 1.전부취소 2.일부취소       */
   char  OrdTp          [ 2];   /* 주문구분(2)                              */
                                /* 11:일반매매(ECN) 12:대량매매(ECN)        */
                                /* 01.지정가 02.희망대량 03.신고대량        */
                                /* 05.시장가 06.조건부시장가 09.자사주      */
                                /* 26.조건부희망대량 71.시간외종가          */
                                /* 72.시간외대량 79.시간외대량자기주식      */
                                /* 12.최유리     13.최우선                  */
   char  BuyDate        [ 8];   /* 매수일(8) (YYYY/MM/DD)                   */
   char  CreditTp       [ 2];   /* 신용구분(2)                              */
                                /* 00.보통 01.유통융자매수 02.자기융자매수  */
                                /* 03.유통대주매도  11.유통융자매도상환     */
                                /* 12.유통융자현금상환 33.자기융자매도상환  */
                                /* 34.자기융자현금상환 55.유통대주매수상환  */
                                /* 56.유통대주현물상환                      */
                                /* 77.자기대주매수상환 78.자기대주현물상환  */
   char  LoanDate       [ 8];   /* 대출일(8) (YYYY/MM/DD)                   */
   char  CondTp         [ 1];   /* 분할거래구분(1) 1.분할 2.전량 3.IOC 4.FOK*/
   char  SmallTp        [ 1];   /* 소액참가구분(1)                          */
   char  AgencySellTp   [ 1];   /* 매도대행사반대매도구분(1)                */
   char  HoldTp         [ 1];   /* 잔고보유구분(1)                          */
                                /* 채권잔고구분 및 미징수기관 체크시 사용   */
   char  OrginNo        [10];   /* 원주문번호(10)                           */
                                /* 단주주문에서는 취소될 대상의 주문번호    */
   char  TxonObjtTp     [ 1];   /* 과세대상구분---채권매매시만 사용         */
   char  SeqNo          [ 2];   /* 주문순번 (복수주문에서 사용)->           */
                                /* HTS에서 온대로 넘겨준다                  */

}TRAN_CH401C00_InRec1;


//< 선물 / 옵션 일때 : 공통 Structure 뒤에 아래의 선물/옵션 주문 Structure가 들어감.>
typedef struct
{
   char  ord_dt         [ 8];    /* 주문일(8)                               */
   char  acnt_no        [11];    /* 계좌번호(11)                            */
   char  scrt_no        [ 8];    /* 비밀번호(8)                             */
   char  item_cd        [ 8];    /* 종목번호(8)                             */
   char  fuop_ord_gbn   [ 1];    /* 주문구분(1)  B.최유리지정가 L.지정가
                                                 M.시장가 C.조건부지정가    */
   char  fuop_ord_dl_gbn[ 1];    /* 주문처리구분(1)
                                                 1:일반주문, 2:정정, 3:취소 */
   char  ord_type_gbn   [ 1];    /* 주문유형구분(1)
                                                 1:일반주문, 2:스프레드주문 */
   char  part_total_gbn [ 1];    /* 일부전부구분(1)  1:전부, 2:일부         */
   char  sel_buy_gbn    [ 1];    /* 매수매도구분(1)  1:매도, 2:매수         */
   char  ord_qty        [10];    /* 주문수량 9(10)(10)                      */
   char  ord_prc        [ 9];    /* 주문가격 S9(7)V99(9)                    */
   char  oord_tnb_cd    [ 3];    /* 원팀점코드(3)                           */
   char  oord_no        [ 6];    /* 원주문번호(6)                           */
   char  rsrv_ord_yn    [ 1];    /* 예약주문여부(1) (Y,N)                   */
   char  ord_seq_no     [ 2];    /* 주문순번(2)                             */
   char  cc_desi_ord_gbn[ 1];    /* CC 지정구분(1)                          */
   char  fuop_ord_cond  [ 1];    /* 주문조건(1) X.없슴 I.IOC F.FOK          */
   char  temp_field1    [ 6];    /* 예비용input-filler(6)                   */
}TRAN_CH430C00_InRec1;


typedef struct
{
	char szAccount[12];

	char szCode[8];
	char cMMType[1];
	char cCredit[1];
	char szExDate[8];
}StOrdKey;


typedef struct _ST_XP1
{
	char   KEYuserid	[20]; // 아이디
	char   MarketGb    [1  ]; //시장구분         1:주식/ELW, 2:선물/옵션                                                                                                                             
	char   Acct        [12 ]; //계좌번호                   
	char   ShCode      [8  ]; //단축종목코드               
	char   Mmgbn       [1  ]; //매매구분         1: 매도, 2: 매수                                                                                                                                    
	char   CrGbn       [1  ]; //신용구분                   
	char   CrDate      [8  ]; //대출일           YYYYMMDD  
	char   ExpireDate  [8  ]; //유효기간         YYYYMMDD  
	char   AutoGbn     [1  ]; //자동주문구분     0:자동, 1:반자동                                                                                                                                    
	char   OrdGbn      [1  ]; //주문구분         고객설정값
	char   OrdRegPrc   [20 ]; //주문가격         고객설정값
	char   OrdQty	   [10 ]; //주문수량         고객설정값
	char   CondAcct    [1  ]; //손익조건선택건수  '0':해당없음                                                                                                                                       
	char   CondItem    [1  ]; //BM조건선택건수  '0':해당없음                                                                                                                                       
	char   CondPrice   [1  ]; //시세조건선택건수  '0':해당없음                                                                                                                                       
	char   CondIndex   [1  ]; //지표조건선택건수  '0':해당없음    
	char   AvgPrcFlag  [1];  // 단가 고객설정 	 '0':매입가, '1' 수정단가
	char   AvgPrc	   [15]; //평균매입단가	평균매입단가.
	char  sMassID		[3];		// 매체구분 - HTS 일반: 50(디럭스, 이지, FX,FX+ 포함), HTS 미니: 51, 아이폰/안드로이드 앱: 66, 아이패드 앱: 67
	char   Act_gbn     [1  ]; //처리결과         
							// (등록)I: Insert, (수정)U: Update, (감시)A: Active, (중지)S: Stoped, (삭제)D: Delete, (완료삭제)F: Finished, E: Expired
	char   CondStmt    [394]; //효력조건문장    
} ST_XP1;

class CPriceInfo
{
public:
	BOOL	m_bELW;

	CString	m_strCode;

	CString m_strCurrent;
	CString m_strDiff;
	CString m_strSign;

	CString m_strPrevClose; // 전일종가(기준가)


	CString	m_strFrontBasePrice; // 주식선물근월물기준가 - SFO 전용("호" 버튼 전용)
	CString	m_strBackBasePrice; // 주식선물선택월물기준가 - SFO 전용("호" 버튼 전용)


	CString m_strOffer[5];
	CString m_strBid[5];

	CString m_strUpiLmit;
	CString m_strDownLimit;
	
	int		m_nQtyUnit;
//	int		m_nPriceUnit;

	CString m_strDrdsType[2]; // ex> S31
	int		m_nDrdsID[2]; // ex> ID_S31

	CPriceInfo()
	{
		
		InitPriceInfo();
	}

	~CPriceInfo()
	{
	}

	BOOL IsValid()
	{
		return (m_strCode.GetLength() > 0) && (m_strCurrent.GetLength() > 0);
	}

	void InitPriceInfo()
	{
		m_bELW = FALSE;

		m_strCode = "";
		m_strCurrent = "";
		m_strDiff = "";
		m_strSign = "";

		m_strPrevClose = "";

		// 20131212 ssj - 주식선물스프레드 에러 수정 >>
		m_strFrontBasePrice = "";
		m_strBackBasePrice = "";
		// 20131212 ssj - 주식선물스프레드 에러 수정 <<

		for (int i = 0; i < 5; i++)
		{
			m_strOffer[i] = "";
			m_strBid[i] = "";
		}

		m_strUpiLmit = "";
		m_strDownLimit = "";

		m_nQtyUnit = 1;
		//		m_nPriceUnit = 1;

		m_strDrdsType[0] = "";
		m_nDrdsID[0] = 0;
		m_strDrdsType[1] = "";
		m_nDrdsID[1] = 0;
	}

	void TrimAll()
	{
		m_strCode.Trim();
		m_strCurrent.Trim();
		m_strDiff.Trim();
		m_strSign.Trim();

		m_strPrevClose.Trim();

		// 20131212 ssj - 주식선물스프레드 에러 수정 >>
		m_strFrontBasePrice.Trim();
		m_strBackBasePrice.Trim();
		// 20131212 ssj - 주식선물스프레드 에러 수정 <<

		for (int i = 0; i < 5; i++)
		{
			m_strOffer[i].Trim();
			m_strBid[i].Trim();
		}

		m_strUpiLmit.Trim();
		m_strDownLimit.Trim();
	}


	void ClearPriceInfo()
	{

		InitPriceInfo();
	}	

};


class CGridKey
{
public:
	CString m_strCode;
	CString m_strSellBuy; // '1':매도, '2':매수
	CString m_strCredit;
	CString m_strLoanDate;
	
	CGridKey(CString strCode, CString strSellBuy, CString strCredit, CString strLoanDate)
	{
		m_strCode = strCode;
		m_strSellBuy = strSellBuy;
		m_strCredit = strCredit;
		m_strLoanDate = strLoanDate;
	}
};

#define		CODEINPUT_PROPERTY_F_NS		_T("CC=00010000000000000010000000000000000000000000000000000000000000000:CD=1:CH=0:CT=1:MHC=20:MXL=8:MIL=8:ECP=1;1;0;1;0;0;:UEP=1::CN1=코드:CN2=종목명:GS=;:LS=코드2;")
#define		CODEINPUT_PROPERTY_O_NS		_T("CC=00001000000000000000000000000000000000000000000000000000000000000:CD=1:CH=0:CT=1:MHC=20:MXL=8:MIL=8:ECP=1;1;0;1;0;0;:UEP=1::CN1=코드:CN2=종목명:GS=;:LS=코드2;")


#endif
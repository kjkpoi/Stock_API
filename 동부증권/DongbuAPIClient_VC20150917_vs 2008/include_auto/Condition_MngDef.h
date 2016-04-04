#pragma once

#ifndef CCONDITION_MNGDEF
#define CCONDITION_MNGDEF

/************************************************************/
/*																													*/
/*		ConditionMng Define => STRUCT / DEFINE / TYPEDEF 정의	*/
/*																													*/
/*					2006. 10.  		Doori														  */
/*						작성자 : 우동우																*/
/************************************************************/

//#include "./EU_p0623.h"

#include <afxtempl.h>   //<= CList
/*#define _countof(array) (sizeof(array)/sizeof(array[0]))*/

#define KEY_USERDIRECTORY _T("USERDIRECTORY")

#define STR_CONVERT(pBuff, cData, nSize, strData)	\
  pBuff = new char[nSize + 1];							\
  memset(pBuff, 0x00, nSize + 1);						\
  memcpy(pBuff, cData, nSize);							\
  strData = (CString)pBuff;									\
  strData.TrimRight();											\
delete [] pBuff;

#define INT_CONVERT(pBuff, cData, nSize, nData)	\
  pBuff = new char[nSize + 1];						\
  memset(pBuff, 0x00, nSize + 1);					\
  memcpy(pBuff, cData, nSize);						\
  nData = atoi(pBuff);										\
delete [] pBuff;

// 솔로몬 TR명
//20100317 김한두 >>
//#define TRNO_CONDITION				"piso0350"		//조건검색
//#define TRNO_WORKDATE				"so035010"		//영업일조회
//#define TRNO_MSTCODE			"sr_d3000"//	"so035020"		//종목리스트 조회
//20100317 김한두 <<
//Samsung TR
//#define TRNO_CONDITION				"hfit_o071001"
//#define TRNO_MSTCODE					"hfit_o071004"
//#define TRNO_WORKDATE					"hfit_o071005"

 #define CODE_LENGTH						6
 #define CODENAME_LENGTH					20

#define		MAX_IDXCNT					18	/* 최대 지표 개수(내부)	*/

#define		REAL_IDXCNT					18	/* 최대 지표 개수(외부)	*/
#define		MAX_PARAM					3		/* param 의 최대 개수 	*/
#define		MAX_CONDI					6		/* condition의 최대 개수*/
#define		EXPLEN						80	/* 조건색의 최대 길이 	*/

#define		RESULT_MAX_OFFSET			1
#define		RESULT_MAX					2500	/* 최대 종목 수         */
//#define		RESULT_MAX					2000	/* 최대 종목 수         */
#define		RESULT_FIELD_MAX			20		/* 결과필드 최대 개수 	*/

#define		LANGUAGE_MAX				180000

/********************************************************************/
/*  조건검색 INPUT DATA                                             */
/********************************************************************/

// 20120723 ssj - 서버자동주문 >> commented
//.typedef struct tagUser_Define
//.{
//.	long    IndexNo; 				/* 지표 index				*/
//.	long    GroupNo; 				/* 소속 그룹번호			*/
//.	long    GroupIdxCnt;			/* 그룹내 지표 개수			*/
//.	long    TargetBase;				/* 0:일간, 1:주간, 2:월간, 3:1분, 4:3분	*/
//.									/* 5:5분,  6:10분, 7:15분, 8:30분, 9:60분*/
//.	long    Type; 					/* 지표의 종류					*/
//.									/* 00XX	: 기술적 지표		*/
//.									/* 10XX	: 캔들분석			*/
//.									/* 20XX	: 시세지표			*/
//.									/* 30XX	: 재무지표			*/
//.									/* 40XX	: 기본적 분석		*/
//.									/* 50XX	: 시그널 지표 		*/
//.									/* 60XX	: 전략				*/
//.									/* 70XX : 패턴 (new)		*/
//.									/* 80XX : 뉴스 (new)		*/
//.	long    Type1; 					/* 조건 형태				*/
//.									/* 0: 기준값 돌파(상향/하향)*/
//.									/* 1: 기준선 돌파(상향/하향)*/
//.									/* 2: 기준값 비교(비교) 	*/
//.									/* 3: 기준선 비교(비교) 	*/
//.									/* 4: 값 비교(비교,<,<=,>,>=,==)*/
//.									/* 5: 범위 비교(c1이상~c2이하)  */
//.									/* 6: 추세(상승/하락)           */
//.									/* 7: 반전(상승/하락)           */
//.									/* 8: 순위검색					*/
//.									/* 9: 배열(정배열/역배열)       */
//.									/* 10: n% 종목 순위검색1	    */
//.									/* 11: n% 종목 순위검색2 	    */
//.									/* 20: 뉴스 체크 (new)          */
//.									/* 30: 패턴 체크 (new)          */
//.									/* 90: 기준값 돌파(상향/하향)	##삭제##*/ 
//.									/* 91: 기준선 돌파(상향/하향)	##삭제##*/
//.									/* 92: 기준값 비교(비교)    	##삭제##*/
//.									/* 93: 기준선 비교(비교)    	##삭제##*/
//.									/* 94: 값비교(비교,<,<=,>,>=,==)##삭제##*/
//.									/* 95: 범위 비교(c1이상~c2이하) ##삭제##*/
//.									/* 96: 추세(상승/하락)          ##삭제##*/
//.									/* 97: 반전(상승/하락)          ##삭제##*/
//.									/* 99:기타1                     ##삭제##*/
//.									/* 98:기타2                     ##삭제##*/
//.	long    Type2; 					/* 상세 형태					*/
//.									/* 0: 상향/이상/상승/정배열/매수*/
//.									/* 1: 하향/이하/하락/역배열/매도*/
//.									/* 2: 전일기준(가격지표)        ##삭제##*/
//.									/* 3: 당일기준(가격지표)        ##삭제##*/
//.									/* 99:기타                      */
//.	long    STerm;					/* n봉전 기준               	*/
//.	long    ETerm;					/* n봉이내                 		*/
//.	long    Rank;					/* 순위검색 종목 수             */
//.	long    Trend;					/* 추세횟수						*/
//.	long	SignalCnt1;				/* 발생회수	(new)	X번에서 X번 만족*/
//.	long	SignalCnt2;				/* 발생회수	(new)					*/
//.	long    ResultViewNum;			/* 결과값보기 필드 갯수(0:사용안함)	*/    
//.
//.	char    IndexType;				/* 검색구분 0:일반 1:순위 2:순차	*/
//.	char    SearchType;				/* 검색형태 0:일반 1:사용자정의	2:뉴스 3:패턴   (new) */
//.
//.	char    Operator;				/* 연산자'0':OR '1':AND '2':NEXT	*/
//.	char    Reverse;				/* 결과제외 '0':A, '1':Not A		*/
//.	char    IdxContiGubun;			/* 지표의 연속발생 구분
//.										'0':단일발생, 1:연속발생지표	*/
//.	char    Element;				/* 조건식 사용문자(A) (new)			*/
//.	char	Code[6];
//.
//.	char    filler1[4];
//.	double  Param[MAX_PARAM];      	/* 지표관련 변수값 (ex.12,26,9)		*/
//.	double  Condition[MAX_CONDI];   /* 기타 설정 변수값					*/
//.} User_Define;
//.#define SZ_User_Define sizeof(User_Define)
// 20120723 ssj - 서버자동주문 <<

// 20120723 ssj - 서버자동주문 >>
typedef struct _CHAR10
{
	char szData[10];
} CHAR10;

typedef struct _CHAR8
{
	char szData[8];
} CHAR8;


typedef struct _User_Define
{
	char giIndexNo          [2];  //	지표 번호
	char giGroupNo          [2];  //	그룹 번호
	char giGroupIdxCnt      [2];  //	그룹내의 지표 개수
	char giTargetBase       [2];  //	 0:일간, 1:주간, 2:월간, 3:1분, 4:3분 5:5분, 6:10분, 7:15분, 8:30분, 9:60분
	char giType             [4];  //	지표의 종류
	char giType1            [2];  //	Type1 조건 형태
	char giType2	          [2];  //	상세 형태  
	char giSTerm	          [4];  //	그룹검색 시작위치
	char giETerm	          [4];  //	그룹검색 끝  위치
	char giRank             [4];  //	순위검색 종목 수
	char giTrend	          [4];  //	추세횟수 
	char giSignalCnt1       [4];  //	신호 발생횟수1 
	char giSignalCnt2	      [4];  //	신호 발생횟수2
	char giResultViewNum	  [2];  //	결과값보기 필드 갯수(0:사용안함)
	char IndexType	      ;  //	검색구분 0:일반 1:순위 2:복합
	char SearchType	      ;  //	검색형태 0:일반 1:Language 
	char Operator         ;  //	연산자'0':OR '1':AND '2':NEXT
	char Reverse	      ;  //	결과제외 '0':A, '1':Not A  
	char IdxContiGubun    ;  //	'0':단일발생, 1:연속발생지표
	char Element	      ;  //	조건식 사용문자
	char Code	          [6];  //	short code     
	char Filler	          [4];  //	
	CHAR8 Param	          [3]; //	지표관련 변수값 
	CHAR10 Condition	  [6]; //	기타 설정 변수값
} User_Define;
#define SZ_User_Define sizeof(User_Define)
// 20120723 ssj - 서버자동주문 <<

/********************************************************************/
/*  Output Packet Struct                                            */
/********************************************************************/
typedef struct tagOutPacket{
	long	lTrIndex;
	long	lTotalJongCnt;				/* 검색된 전제 종목 수      */
	long	lOutFieldCnt;				/* Out Field Count          */
	long	lOutListPacketSize;			/* 결과 List 사이즈(한종목) */
	long	lFindTime;					/* 검색시간					*/
	//char    ResultBit[RESULT_MAX];	/* 결과종목 bit list		*/
} OutPacket;
#define SZ_OutPacket sizeof(OutPacket)

// KB투자증권용	-hidden-
typedef struct tagD1021Out1
{
    char    giCallGubun[4];
    char    giTotalJongCnt[4];
    char    giOutFieldCnt[2];
    char    giOutListPacketSize[4];
    char    giFindTime[8];
} D1021OUT1;
#define  SIZE_D1021OUT1	sizeof(D1021OUT1)

/************************************************************************/
/*  Output List Packet Struct                                           */
/************************************************************************/
typedef struct tagOutListPacket{
	char		chSign;					/* 전일대비 부호  1:상한 2:상승 3:보합 4:하한 5:하락*/
	char		chCode[CODE_LENGTH];	/* 종목 코드	 			*/
	char		chName[CODENAME_LENGTH];/* 종목명		 			*/ 
	char		chMarket;               /* 거래소:'1', 코스닥:'2'	*/
	long		lOrderRank;				/* 순위검색 순위 			*/	
	double		dFieldData[RESULT_FIELD_MAX];
} OutListPacket;
#define SZ_OutListPacket sizeof(OutListPacket)

// KB투자증권용	-hidden-
typedef struct tagD1021Out2
{
	char    gsDaebi[1];
    char    gsCode[6];
    char    gsHname[20];
    char    gsMarket[1];
    char    giOrderRank[4];
    char    gdResultField[20][16];
} D1021OUT2;
#define SIZE_D1021OUT2 sizeof(D1021OUT2)

typedef struct tagMSTCode
{
  char    sMarket[1];
  char    sCode[7];
  char    sName[20];
  char    sSetPos[4];
} MSTCode;


/****************************************************************/
/*                                                              */
/*		  Condition Client =>  STRUCT/DEFINE/TYPEDEF 정의					*/
/*																															*/
/*                   2005. 12.  		Doori												*/
/*                        작성자 : 우동우                       */
/****************************************************************/
const		LPCTSTR		CONDITION_INDEX[] = { "A", "B", "C", "D", "E", "F", "G", "H", "I",
												"J", "K", "L", "M", "N", "O", "P", "Q", "R",
												"S", "T", "U", "V", "W", "X", "Y", "Z",
												"a", "b", "c", "d", "e", "f", "g", "h", "i", 
												"j", "k", "l", "m", "n", "o", "p", "q", "r",
												"s", "t",  "u", "w", "x", "y", "z" };


const		LPCTSTR		TARGETLIST_TYPE1[] = { "일간", "주간", "월간", " 1분", " 3분", " 5분", 
																				 "10분", "15분", "30분", "60분" };
const		int		TARGETINDEX_TYPE1[] = { 0, 1, 2, 3, 4, 5, 
																				 6, 7, 8, 9 };

const		LPCTSTR		TARGETLIST_TYPE2[] = { "일간" };
const		int		TARGETINDEX_TYPE2[] = { 0 };

const		LPCTSTR		TARGETLIST_TYPE3[] = { " 1분", " 3분", " 5분", 
																				 "10분", "15분", "30분", "60분" };
const		int		TARGETINDEX_TYPE3[] = { 3, 4, 5, 
																				 6, 7, 8, 9 };

/*
const		LPCTSTR		TARGETLIST_TYPE1[] = { "일간", "주간", "월간", " 1분", " 3분", " 5분", 
																				 "10분", "15분", "60분" };
const		int		TARGETINDEX_TYPE1[] = { 0, 1, 2, 3, 4, 5, 
																				 6, 7, 9 };

const		LPCTSTR		TARGETLIST_TYPE2[] = { "일간" };
const		int		TARGETINDEX_TYPE2[] = { 0 };

const		LPCTSTR		TARGETLIST_TYPE3[] = { " 1분", " 3분", " 5분", 
																				 "10분", "15분", "60분" };
const		int		TARGETINDEX_TYPE3[] = { 3, 4, 5, 
																				 6, 7, 9 };
*/

#define MAX_FIELD_CNT				17		//# 결과 Grid Column 구성 Max Count


#define GRID_MOVEFIELD_POS_NAME			"[값보기 위치]"
#define GRID_MOVEFIELD_POS_INDEX		-100


#define XML_VERSION_USERFILE	"2.0"

//#define FOLDER_NEWS						"\\Data\\NewsData"

// 20120723 ssj - 서버자동주문 >>
//.#define FOLDER_NEWS						"\\DRData\\NewsData"	//@NH
// 20120723 ssj - 서버자동주문 <<

//#define NEWS_KEYWORD_FILE			"\\txnews_keyword.dat"

// 20120723 ssj - 서버자동주문 >>
/*
#define FOLDER_TABLE					"\\Table"
#define MEMBERCOMP_FILE				"seccd.dat"
*/
// 20120723 ssj - 서버자동주문 <<

#define FOLDER_FINDDATA				"\\FindData"

//20100211 김한두 >> NH 경로가 바뀌어서 바꿈

// 20120723 ssj - 서버자동주문 >>
//.#define FOLDER_DATA						"\\DRData" + FOLDER_FINDDATA
#define FOLDER_DATA						"\\Data" + FOLDER_FINDDATA
// 20120723 ssj - 서버자동주문 <<


/************************************************************/
/*																													*/
/* 서비스 프로그램에서 사용하는 XML File Saveed Insert 정의 */
/*																													*/
/*								2004. 11. 02		Doori(우동우)							*/
/************************************************************/
typedef struct tagElement 
{
	CString   strOperation;
	CString   strNot;
	CString   strElement;
	
	BOOL      bView;
	
	CString   strBracket;
	LONG      lBracketCount;
} OneElementInfo;

typedef struct tagGroupElement
{
	int nGroup;
	OneElementInfo stOneElementInfo;
} GroupElementInfo;

typedef CArray<GroupElementInfo, GroupElementInfo&>		ArrGroupElementInfo;

typedef struct tagGroupElementInfo
{
	int nGroup;
	ArrGroupElementInfo arrGroupElemInfo;
} GROUP_ELEMINFO;

typedef CArray<GROUP_ELEMINFO*, GROUP_ELEMINFO*>		ArrGroupElements;



/*
#define MAX_PORT_GROUP        99
#define MAX_PORT_ITEM         99
typedef struct tagPortGroupInfo
{
	int nNo;
	CString strName;

	int nItemCnt;
	int nMarketType[MAX_PORT_ITEM];		 //# 거래소:'1', 코스닥:'2'
	CString strCode[MAX_PORT_ITEM];
} PortGroupInfo;
*/


#define HEAD_OTHER_CNT      2  //# 추가 필드 개수
typedef struct tagHeadInfoType
{
	long        lHeadID;
	CString     strHeadName;
	int         nUnitNum;
	CString     strUnitText;
	CString     strDataType;
	int         nDataLength;
	int         nColWidth;
	CString     strAlignment;
} HeadInfoType;

typedef struct tagHeadMoveInfo{
	int         nColCnt;    //## Add Col Count
	int			nIndex;			
	CString		strElement; 
	BOOL		bCondition; 
	BOOL		bView;
	HeadInfoType  stHeadType[HEAD_OTHER_CNT];
} HeadMoveInfo;


typedef struct tagHeadFixInfo{
	int           nColNum;        
	HeadInfoType  stHeadType;
	BOOL          bView;
} HeadFixInfo;


const LPCTSTR		MATCHVAL_OPT_LIST[] = { ">", ">=", "=", "<=", "<" };
const LPCTSTR		MATCHVAL_OPT_DATA = ">\n>=\n=\n<=\n<\n";
typedef struct tagMatchInfo
{
	int			nRow;
	BOOL		bUser;
	int			nOptIndex;
	CString		strField;
	CString		strElement;
	int 		nFieldIndex;

	int			nGridSourceRow;			//# Temp
} MatchInfo;


typedef struct tagExplainInfo
{
	int			nType;		//# 0 : Text, 1 :URL
	CString		strName;
	CString		strExplain;
	CString		strURL;
} ExplainInfo;


//# 조건 하나의 저장 정보 #
typedef struct tagOneCondition {
	BOOL bFalg;					//# 조건 포함 : TRUE
	
	int	nNotUserFlag;
	int	nGubunUserFlag;			//# 연속/비연속 

	int	nTargetBaseType;		//# TargetBase Type (일간고정, 그외 ...)

	CString strTag;		  //# Tag  <= Map Create Tag
	CString strMapFile;	//# Map File Name

	int	nNonAlert;
	int	nChartValSet;

	CString strName;	//# 지표명
	CString strText;	//# 지표 완성 구문
	
	User_Define stCondition;

	BOOL bFieldVal;			//# 값보기
	BOOL bFieldState;		//# 값보기 Check Field Have
	BOOL bFieldEnable;	//# 값보기 Enable 상태 
										  //=> TRUE : Field values가 없거나 조건이 Not인 경우
										  //=> FALSE : Field values가 있는 경우 
	
	HeadMoveInfo  stHeadMoveInfo;		//# 값보기 필드 정보
} OneConditionInfo;

typedef struct tagConditionGroupInfo{
	int           nGroup;             //## Group
	CString       strElement;         //## Condition Index
	OneConditionInfo  stOneConditionInfo; //## One Condition Info
} ConditionGroupInfo;

typedef CArray<ConditionGroupInfo, ConditionGroupInfo&>		ArrCondGroupInfo;

typedef struct tagGroupInfo
{
	int nGroup;
	ArrCondGroupInfo arrConGrpInfo;
} GROUP_INFO;

typedef CArray<GROUP_INFO*, GROUP_INFO*>					ArrGroups;

typedef struct tagCandleInfo{
	long    lID;
	CString   strName;
} CandleInfo;

typedef struct tagPatenInfo{
	long    lID;
	CString   strName;
} PatenInfo;

typedef struct tagFileInfo
{
	CString   strFolderPath;

	CString   strFilePath;
	CString   strFileName;
	CString   strRegCheck;
} FileInfo;

//# [Xml Tree] ###############################################################################
#define TREE_SELECT_TYPE_CLASS        1

#define TREE_SELECT_TYPE_ITEM_COMM    10
#define TREE_SELECT_TYPE_ITEM_ORDER   11
#define TREE_SELECT_TYPE_PORTPOLIO    12
#define TREE_SELECT_TYPE_ACCOUNT      13
#define TREE_SELECT_TYPE_LANGUAGE     14
#define TREE_SELECT_TYPE_USERPATTEN   15
#define TREE_SELECT_TYPE_NEWS         16

#define TREE_SELECT_TYPE_USERFILE     20
#define TREE_SELECT_TYPE_SYSFILE      21

#define TAG_TYPE_PORTPOLIO    "PORT"
#define TAG_TYPE_ACCOUNT      "ACCOUNT"
#define TAG_TYPE_LANGUAGE     "LANGUAGE"
#define TAG_TYPE_USERPATTEN   "USER_PATTEN"
#define TAG_TYPE_NEWS         "NEWS"

#define CONVERT_TAGTOTYPE(strItemTag, nItemType)	      \
  if (strItemTag == (CString)TAG_TYPE_PORTPOLIO)        \
    nItemType = (int)TREE_SELECT_TYPE_PORTPOLIO;        \
  else if (strItemTag == (CString)TAG_TYPE_ACCOUNT)     \
    nItemType = (int)TREE_SELECT_TYPE_ACCOUNT;          \
  else if (strItemTag == (CString)TAG_TYPE_LANGUAGE)    \
    nItemType = (int)TREE_SELECT_TYPE_LANGUAGE;         \
  else if (strItemTag == (CString)TAG_TYPE_USERPATTEN)  \
    nItemType = (int)TREE_SELECT_TYPE_USERPATTEN;       \
  else if (strItemTag == (CString)TAG_TYPE_NEWS)        \
    nItemType = (int)TREE_SELECT_TYPE_NEWS;             \
  else                                                  \
    nItemType = -1;
   

#define NEWS_SUBROOTTITLE			  	"뉴스분석"
#define PORTPOLIO_SUBROOTTITLE		"관심그룹"
#define LANGUAGE_SUBROOTTITLE			"랭귀지"
#define PATTEN_ROOTTITLE				  "사용자패턴"
#define ACCOUNT_SUBROOTTITLE			"보유종목그룹"

#define CONVERT_TYPETOTITLE(nItemType, strTitle)	        \
  if (nItemType == (int)TREE_SELECT_TYPE_PORTPOLIO)       \
    strTitle = (CString)PORTPOLIO_SUBROOTTITLE;           \
  else if (nItemType == (int)TREE_SELECT_TYPE_ACCOUNT)    \
    strTitle = (CString)ACCOUNT_SUBROOTTITLE;             \
  else if (nItemType == (int)TREE_SELECT_TYPE_LANGUAGE)   \
    strTitle = (CString)LANGUAGE_SUBROOTTITLE;            \
  else if (nItemType == (int)TREE_SELECT_TYPE_USERPATTEN) \
    strTitle = (CString)PATTEN_ROOTTITLE;                 \
  else if (nItemType == (int)TREE_SELECT_TYPE_NEWS)       \
    strTitle = (CString)NEWS_SUBROOTTITLE;                \
  else                                                    \
    strTitle = ""

#define MAP_OTHER_FILE        "Other"

typedef struct tagNewsInfo
{
	int nIndex;
	int nCode;
	CString strType;
	CString strKeyWord;
} NewsInfo;

typedef struct tagXMLTreeInfo
{
	BOOL bVisible;
	int nItemType;

	CString strName;
	CString strTag;

	int nNonAlert;
	int nCondiType;
	int nTargetBase_Type;

	int nGubun;
	int nGubunDefVal;

	int nNotUser;
	int nNotDefVal;
		
	CString strResultViewID;
	int nResultViewDefVal;

	int nChartValSet;
	CString strMapFile;
} XMLTreeInfo;

inline void COPY_XMLTreeInfo(XMLTreeInfo* xpSrc, XMLTreeInfo* xpTar)
{
	xpTar->bVisible = xpSrc->bVisible;
 	xpTar->nItemType = xpSrc->nItemType;
	xpTar->strName = xpSrc->strName;
	xpTar->strTag = xpSrc->strTag;
	xpTar->nNonAlert = xpSrc->nNonAlert;
	xpTar->nCondiType = xpSrc->nCondiType;
	xpTar->nTargetBase_Type = xpSrc->nTargetBase_Type;
	xpTar->nGubun = xpSrc->nGubun;
	xpTar->nGubunDefVal = xpSrc->nGubunDefVal;
	xpTar->nNotUser = xpSrc->nNotUser;
	xpTar->nNotDefVal 	 = xpSrc->nNotDefVal;		
	xpTar->strResultViewID = xpSrc->strResultViewID;
	xpTar->nResultViewDefVal = xpSrc->nResultViewDefVal;
	xpTar->nChartValSet = xpSrc->nChartValSet;
	xpTar->strMapFile = xpSrc->strMapFile;
}


typedef struct tagXMLTreeInfoFile
{
	CString strType;		//# USER, SYS

	CString strFolderPath;
	CString strFilePath;
	CString strFileName;

	BOOL	bQuickReg;		//# Deawoo [NEW]
	BOOL	bUnitCan;		//# Deawoo [NEW]

	CString strAlertReg;

	CString strExplain;
} XMLTreeInfoFile;

typedef struct tagXMLTreeInfoFolder
{
	BOOL	bLock;
	CString strPath;
	CString strName;

	int nFileCnt;

	CList	<XMLTreeInfoFile, XMLTreeInfoFile&> *plistXMLTreeInfoFile;
} XMLTreeInfoFolder;


typedef struct tagInfoFolder
{
	BOOL		bLock;
	CString strPath;
	CString strName;
	int nFileCnt;
	BOOL bTarget;
} InfoFolder;


//# Language!
typedef struct tagLanguageInfo
{
	int	nType;	// 사용된 언어 0 : TS, 1 : YES, 2 : YES
	LPSTR	lpszName;		  // 파일명은 확장자 .sts만 붙이면 됨
					            // 스크립트 경로는 루트경로/ScriptFiles
} LanguageInfo;


//# Lib Group Data!
typedef struct tagConditionItemInfo
{
  CString strGroupName;

  CStringArray strItemName;
  CStringArray strItemData;   //# Path, Data(Tag, Val...)
} ConditionItemInfo;


//# Filter Info ########################################################
typedef struct tagSubFilterInfo
{
	int nTime;
	int nData;
} SubFilterInfo;


#define CNT_CHANGEVAL		5
#define CNT_DIRECTION		8

typedef struct tagFilterInfo
{
	int nMarketType;			//# 0 : 전체, 1 : 코스피, 2 : 코스닥
	
	int nNowPriceChk;
	int nNowPriceUp, nNowPriceDown;
	
	int nChangRateChk;
	int nChangRateUp, nChangRateDown;
		
	int nChangValChk[CNT_CHANGEVAL];

	int nUsjg;							// 우선주
	int nUnder;							// 관리종목
	int nDishonest;						// 불성실 공시
	int nInvestAttention;				// 투자주의
	int nInvestWarn;					// 투자경고
	int nInvestRiskNotice;				// 투자위험예고
	int nInvestRisk;					// 투자위험
	
	int nDealVolType;		//# 0 : 고정, 1 : Time
	int nDealVol;
	CList <SubFilterInfo, SubFilterInfo&>	*plistDealTimeVol;
		
	int nDealPriceType;		//# 0 : 고정, 1 : Time
	int nDealPrice;
	CList <SubFilterInfo, SubFilterInfo&>	*plistDealTimePrice;
		
	int nDirectionChk[CNT_DIRECTION];

	CStringArray saOutCode;
} FilterInfo;
#define SZ_FILTERINFO	sizeof(FilterInfo)

typedef struct tagSignal_ConditionInfo2
{
	char    sJobFlag;           /* 신규:'N', 재진입:'R', 탈퇴:'O'           */
	/* 조건이상: 'E', 조건 점검:'W'             */
	/* 조건 초기화: 'I', 조건 강제종료: 'K'     */

	char    sCode[6];
	char    sName[20];
	/*Signal_CommonInfo2 stCommon;*/

	char    sManagement;                   // 관리종목 (0:O, 1:X)
	char    sControl;                      // 투자정상(0), 투자주의(1), 투자경고(2), 투자위험예고(3),투자위험(4)
	char    sTradeStop;                    // 거래정지 종목 (0:O, 1:X)
	char    sInvestAttention;              // 투자유의 종목 (0:O, 1:X)
	char    sInsincerityNotice;            // 불성실공시 종목 (0:O, 1:X)
	char    sConfidenceLimit;              // 신용제한 종목 (0:O, 1:X)
	char    sCodeNotice;                   // 종목공시 (0:O, 1:X)
	char    sJungriMeme;                   // 정리매매 종목 (0:O, 1:X)
	
	char	sUsjg;                         // 우선주                       
	char    sInvestWarn;                   // 투자 경고                    
	char    sInvestRiskNotice;             // 투자 위험 예고               
	char    sInvestRisk;                   // 투자 위험  
		
	char    sMarket;                       // 시장구분  (1:Kospi, 2:Kosdaq)
	char    sDepositMoney[3];              // 증거금 비율 (100, 040, 033, 025)
	//# Code Info
	char    sPrice[8];           			// 현재가 (단위:원)
	char    sChgRate[6];         			// 등락율   Type(S999.99)   
	char    sSign;               			// 전일대비부호  
	char    sVolume[9];          			// 거래량 : Unit(1,000)   
	char    sAmount[9];          			// 거래대금 : Unit(100,000,000)
	char    sChage[8];           			// 전일대비    
	char    sVolumeRect[6];    				// 거래량 대비율: Unit(1,000)  
	char	filler[2];

	//# 한화 구조체 변경
	int		nData;							// 신호 발생일자
	int		nTime;							// 신호 발생시간
	int		nTrueCnt;						// 현재만족 종목수(기존 + 신규)
	char	sSysNum[4];						// System Alert 조건번호(사용자는 "0000")
	int		nEntryCnt;						// 진입 횟수
} Signal_ConditionInfo2;
#define SZ_SIGNAL_CONDITIONINFO2   sizeof(Signal_ConditionInfo2)

#define GETPATH_APP(strAppPath)       \
	char buf[255];														\
	GetModuleFileName(NULL, buf, 255);									\
	int lastlocationofbackslash = 0;									\
	int nBufCnt = strlen(buf);											\
	for (int i = 0; i < nBufCnt; i++)									\
{																	\
	if (buf[i] == '\\')													\
	lastlocationofbackslash = i;										\
}                                                                   \
	CString strAppPath = _T("");                                        \
	for (int j = 0; j < lastlocationofbackslash; j++)                   \
	strAppPath += buf[j];  


// ------------------------------------------------------------------------------------
//@유진에서 추가
// ------------------------------------------------------------------------------------
//@Solomon090819-->
// 	#include "../../Contents/inc/UseVector.h"
// 	#define Safe_CheckCopy(xSource, xTarget) if(xTarget.GetLength()) memcpy(xSource, (LPCSTR)xTarget, xTarget.GetLength())
// 	class C0621OutBlock1
// 	{
// 	public:
// 		int  GetDataCount(CHARVECTOR2 &vvRpValueList)
// 		{
// 			CString szTmp;
// 			szTmp	 = vvRpValueList[1][1];	// 검색된 전제 종목 수
// 			if(szTmp.GetLength()==0) return 0;
// 
// 			int nRet = atoi(szTmp);
// 			// 조회된 종목이 없을 경우 (-900)이 리턴된다고 함.
// 			return (nRet<0)? 0: nRet;
// 		}
// 		
// 		void SetData(CHARVECTOR2 &vvRpValueList, OutPacket* pOutData)
// 		{
// 			CString szTmp;
// 			szTmp	 = vvRpValueList[1][0];
// 			pOutData->lTrIndex	= atol(szTmp);			//콜구분
// 
// 			szTmp	 = vvRpValueList[1][1];
// 			pOutData->lTotalJongCnt	= atol(szTmp);		//검색된 전제 종목 수
// 
// 			szTmp	 = vvRpValueList[1][2];
// 			pOutData->lOutFieldCnt	= atol(szTmp);		//Out Field Count
// 
// 			szTmp	 = vvRpValueList[1][3];
// 			pOutData->lOutListPacketSize = atol(szTmp);	// 결과 List 사이즈(한종목)
// 
// 			szTmp	 = vvRpValueList[1][4];
// 			pOutData->lFindTime	= atol(szTmp);			// 검색시간
// 		};
// 	};
// 
// 	class C0621OutBlock2
// 	{
// 	public:
// 		void SetData(CHARVECTOR2 &vvRpValueList, OutListPacket* pListData, int nCnt)
// 		{
// 			if(nCnt<=0) return;
// 
// 			CString schSign,
// 					schCode,
// 					schName,
// 					schMarket,
// 					slOrderRank,
// 					sdFieldData;
// 			CString szTmp;
// 			char aTmp[16+1]={0,};
// 			for(int i=0; i<nCnt; i++)
// 			{
// 				schSign		= vvRpValueList[i+1][ 0];
// 				schCode		= vvRpValueList[i+1][ 1];
// 				schName		= vvRpValueList[i+1][ 2];
// 				schMarket	= vvRpValueList[i+1][ 3];
// 				slOrderRank	= vvRpValueList[i+1][ 4];
// 				sdFieldData = vvRpValueList[i+1][ 5];
// 
// 				pListData[i].chSign = schSign[0];
// 				Safe_CheckCopy(pListData[i].chCode, schCode);
// 				Safe_CheckCopy(pListData[i].chName, schName);
// 				pListData[i].chMarket = schMarket[0];
// 				pListData[i].lOrderRank = atol(slOrderRank);
// 
// 				for(int nFi=0; nFi<RESULT_FIELD_MAX; nFi++)
// 				{
// 					sprintf(aTmp, "%16s", sdFieldData.Mid(nFi*16, 16));
// 					aTmp[16] = 0;
// 					pListData[i].dFieldData[nFi] = atof(aTmp);
// 				}
// 			}
// 		}
// 	};
// 
// 	class C0626OutBlock1
// 	{
// 	public:
// 		int  GetDataCount(CHARVECTOR2 &vvRpValueList)
// 		{
// 			CString szTmp;
// 			szTmp	 = vvRpValueList[1][0];	// 요청갯수
// 			if(szTmp.GetLength()==0) return 0;
// 
// 			int nRet = atoi(szTmp);
// 			return (nRet<0)? 0: nRet;	// CConditionResultWnd::SetSearch_WorkDate()에서 42개 요청.
// 		}
// 	};
// 
// 	class C0626OutBlock2
// 	{
// 	public:
// 		void SetData(CHARVECTOR2 &vvRpValueList, char* pOutData, int nDataCnt)
// 		{
// 			CString szTmp;	// 영업일
// 
// 			for(int i=0; i<nDataCnt; i++)
// 			{
// 				szTmp	 = vvRpValueList[i+1][0];
// 				memcpy(&pOutData[i*8], (LPCSTR)szTmp, 8);
// 			}
// 		};
// 	};
// 
// 	class C0627OutBlock1
// 	{
// 	public:
// 		int  GetDataCount(CHARVECTOR2 &vvRpValueList)
// 		{
// 			CString szTmp;
// 			szTmp	 = vvRpValueList[1][0];	// 검색된 전제 종목 수
// 			if(szTmp.GetLength()==0) return 0;
// 
// 			int nRet = atoi(szTmp);
// 			return (nRet<0)? 0: nRet;
// 		}
// 	};
// 
// 	class C0627OutBlock2
// 	{
// 	public:
// 		void SetData(CHARVECTOR2 &vvRpValueList, char* pDataBuf, int nDataCnt)
// 		{
// 			CString sMarket,		//마켓구분
// 					sCode,		//종목코드
// 					sName,		//종목명
// 					sSetPos;	//인덱스
// 			int nPos = 0;
// 
// 			for(int i=0; i<nDataCnt; i++)
// 			{
// 				MSTCode* pOutData = (MSTCode*)&pDataBuf[nPos];
// 				nPos += sizeof(MSTCode);
// 
// 				ZeroMemory(pOutData, sizeof(MSTCode));
// 
// 				sMarket	 = vvRpValueList[i+1][0];
// 				pOutData->sMarket[0] = sMarket[0];
// 
// 				sCode = vvRpValueList[i+1][1];
// 				Safe_CheckCopy(pOutData->sCode ,sCode);
// 				pOutData->sCode[6] = 0;
// 
// 				sName = vvRpValueList[i+1][2];
// 				sName.TrimRight();
// 				//Safe_CheckCopy(pOutData->sName ,sName);
// 				memcpy(pOutData->sName, (LPCSTR)sName, 20);
// 				pOutData->sName[sName.GetLength()]=0;
// 
// 				sSetPos = vvRpValueList[i+1][3];
// 				Safe_CheckCopy(pOutData->sSetPos ,sSetPos);
// 				//memcpy(pOutData->sSetPos, (LPCSTR)sSetPos, 4);
// 			}
// 		};
// 	};
//@Solomon090819<--
//20100504 김한두 >>
// typedef struct stRealData
// {
// 	BYTE	chCount;
// 	CString	strKeyCode;
// 	int		nSize;
// 	LPSTR	pDataBuf;
// 	int		lRealStruct;
// 	BYTE	chRealType;
// } REALDATA;
//20100504 김한두 <<

// 자동갱신 
// typedef struct REALDATA
// {
// //	char		szKeyCode[20];						// 종목코드(모든시장)
// 	char		szKeyCode[32];						// 종목코드(모든시장)
// 	BYTE		chRealType;							// 자동갱신 타입 
// 	BYTE		chCount;							// 자동갱신 개수 
// 	short       nSize;								// 자동갱신 구조체 사이즈 
// 
// 	char*       pDataBuf;							// 실제 데이터 
// 	long		lRealStruct;						// 자동갱신 구조체 ( 구조체에 대한 Pointer )
// } REALDATA_st, *LPREALDATA;
 #endif // CCONDITION_MNGDEF

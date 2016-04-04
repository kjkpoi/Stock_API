#pragma once

#ifndef CCONDITION_MNGDEF
#define CCONDITION_MNGDEF

/************************************************************/
/*																													*/
/*		ConditionMng Define => STRUCT / DEFINE / TYPEDEF ����	*/
/*																													*/
/*					2006. 10.  		Doori														  */
/*						�ۼ��� : �쵿��																*/
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

// �ַθ� TR��
//20100317 ���ѵ� >>
//#define TRNO_CONDITION				"piso0350"		//���ǰ˻�
//#define TRNO_WORKDATE				"so035010"		//��������ȸ
//#define TRNO_MSTCODE			"sr_d3000"//	"so035020"		//���񸮽�Ʈ ��ȸ
//20100317 ���ѵ� <<
//Samsung TR
//#define TRNO_CONDITION				"hfit_o071001"
//#define TRNO_MSTCODE					"hfit_o071004"
//#define TRNO_WORKDATE					"hfit_o071005"

 #define CODE_LENGTH						6
 #define CODENAME_LENGTH					20

#define		MAX_IDXCNT					18	/* �ִ� ��ǥ ����(����)	*/

#define		REAL_IDXCNT					18	/* �ִ� ��ǥ ����(�ܺ�)	*/
#define		MAX_PARAM					3		/* param �� �ִ� ���� 	*/
#define		MAX_CONDI					6		/* condition�� �ִ� ����*/
#define		EXPLEN						80	/* ���ǻ��� �ִ� ���� 	*/

#define		RESULT_MAX_OFFSET			1
#define		RESULT_MAX					2500	/* �ִ� ���� ��         */
//#define		RESULT_MAX					2000	/* �ִ� ���� ��         */
#define		RESULT_FIELD_MAX			20		/* ����ʵ� �ִ� ���� 	*/

#define		LANGUAGE_MAX				180000

/********************************************************************/
/*  ���ǰ˻� INPUT DATA                                             */
/********************************************************************/

// 20120723 ssj - �����ڵ��ֹ� >> commented
//.typedef struct tagUser_Define
//.{
//.	long    IndexNo; 				/* ��ǥ index				*/
//.	long    GroupNo; 				/* �Ҽ� �׷��ȣ			*/
//.	long    GroupIdxCnt;			/* �׷쳻 ��ǥ ����			*/
//.	long    TargetBase;				/* 0:�ϰ�, 1:�ְ�, 2:����, 3:1��, 4:3��	*/
//.									/* 5:5��,  6:10��, 7:15��, 8:30��, 9:60��*/
//.	long    Type; 					/* ��ǥ�� ����					*/
//.									/* 00XX	: ����� ��ǥ		*/
//.									/* 10XX	: ĵ��м�			*/
//.									/* 20XX	: �ü���ǥ			*/
//.									/* 30XX	: �繫��ǥ			*/
//.									/* 40XX	: �⺻�� �м�		*/
//.									/* 50XX	: �ñ׳� ��ǥ 		*/
//.									/* 60XX	: ����				*/
//.									/* 70XX : ���� (new)		*/
//.									/* 80XX : ���� (new)		*/
//.	long    Type1; 					/* ���� ����				*/
//.									/* 0: ���ذ� ����(����/����)*/
//.									/* 1: ���ؼ� ����(����/����)*/
//.									/* 2: ���ذ� ��(��) 	*/
//.									/* 3: ���ؼ� ��(��) 	*/
//.									/* 4: �� ��(��,<,<=,>,>=,==)*/
//.									/* 5: ���� ��(c1�̻�~c2����)  */
//.									/* 6: �߼�(���/�϶�)           */
//.									/* 7: ����(���/�϶�)           */
//.									/* 8: �����˻�					*/
//.									/* 9: �迭(���迭/���迭)       */
//.									/* 10: n% ���� �����˻�1	    */
//.									/* 11: n% ���� �����˻�2 	    */
//.									/* 20: ���� üũ (new)          */
//.									/* 30: ���� üũ (new)          */
//.									/* 90: ���ذ� ����(����/����)	##����##*/ 
//.									/* 91: ���ؼ� ����(����/����)	##����##*/
//.									/* 92: ���ذ� ��(��)    	##����##*/
//.									/* 93: ���ؼ� ��(��)    	##����##*/
//.									/* 94: ����(��,<,<=,>,>=,==)##����##*/
//.									/* 95: ���� ��(c1�̻�~c2����) ##����##*/
//.									/* 96: �߼�(���/�϶�)          ##����##*/
//.									/* 97: ����(���/�϶�)          ##����##*/
//.									/* 99:��Ÿ1                     ##����##*/
//.									/* 98:��Ÿ2                     ##����##*/
//.	long    Type2; 					/* �� ����					*/
//.									/* 0: ����/�̻�/���/���迭/�ż�*/
//.									/* 1: ����/����/�϶�/���迭/�ŵ�*/
//.									/* 2: ���ϱ���(������ǥ)        ##����##*/
//.									/* 3: ���ϱ���(������ǥ)        ##����##*/
//.									/* 99:��Ÿ                      */
//.	long    STerm;					/* n���� ����               	*/
//.	long    ETerm;					/* n���̳�                 		*/
//.	long    Rank;					/* �����˻� ���� ��             */
//.	long    Trend;					/* �߼�Ƚ��						*/
//.	long	SignalCnt1;				/* �߻�ȸ��	(new)	X������ X�� ����*/
//.	long	SignalCnt2;				/* �߻�ȸ��	(new)					*/
//.	long    ResultViewNum;			/* ��������� �ʵ� ����(0:������)	*/    
//.
//.	char    IndexType;				/* �˻����� 0:�Ϲ� 1:���� 2:����	*/
//.	char    SearchType;				/* �˻����� 0:�Ϲ� 1:���������	2:���� 3:����   (new) */
//.
//.	char    Operator;				/* ������'0':OR '1':AND '2':NEXT	*/
//.	char    Reverse;				/* ������� '0':A, '1':Not A		*/
//.	char    IdxContiGubun;			/* ��ǥ�� ���ӹ߻� ����
//.										'0':���Ϲ߻�, 1:���ӹ߻���ǥ	*/
//.	char    Element;				/* ���ǽ� ��빮��(A) (new)			*/
//.	char	Code[6];
//.
//.	char    filler1[4];
//.	double  Param[MAX_PARAM];      	/* ��ǥ���� ������ (ex.12,26,9)		*/
//.	double  Condition[MAX_CONDI];   /* ��Ÿ ���� ������					*/
//.} User_Define;
//.#define SZ_User_Define sizeof(User_Define)
// 20120723 ssj - �����ڵ��ֹ� <<

// 20120723 ssj - �����ڵ��ֹ� >>
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
	char giIndexNo          [2];  //	��ǥ ��ȣ
	char giGroupNo          [2];  //	�׷� ��ȣ
	char giGroupIdxCnt      [2];  //	�׷쳻�� ��ǥ ����
	char giTargetBase       [2];  //	 0:�ϰ�, 1:�ְ�, 2:����, 3:1��, 4:3�� 5:5��, 6:10��, 7:15��, 8:30��, 9:60��
	char giType             [4];  //	��ǥ�� ����
	char giType1            [2];  //	Type1 ���� ����
	char giType2	          [2];  //	�� ����  
	char giSTerm	          [4];  //	�׷�˻� ������ġ
	char giETerm	          [4];  //	�׷�˻� ��  ��ġ
	char giRank             [4];  //	�����˻� ���� ��
	char giTrend	          [4];  //	�߼�Ƚ�� 
	char giSignalCnt1       [4];  //	��ȣ �߻�Ƚ��1 
	char giSignalCnt2	      [4];  //	��ȣ �߻�Ƚ��2
	char giResultViewNum	  [2];  //	��������� �ʵ� ����(0:������)
	char IndexType	      ;  //	�˻����� 0:�Ϲ� 1:���� 2:����
	char SearchType	      ;  //	�˻����� 0:�Ϲ� 1:Language 
	char Operator         ;  //	������'0':OR '1':AND '2':NEXT
	char Reverse	      ;  //	������� '0':A, '1':Not A  
	char IdxContiGubun    ;  //	'0':���Ϲ߻�, 1:���ӹ߻���ǥ
	char Element	      ;  //	���ǽ� ��빮��
	char Code	          [6];  //	short code     
	char Filler	          [4];  //	
	CHAR8 Param	          [3]; //	��ǥ���� ������ 
	CHAR10 Condition	  [6]; //	��Ÿ ���� ������
} User_Define;
#define SZ_User_Define sizeof(User_Define)
// 20120723 ssj - �����ڵ��ֹ� <<

/********************************************************************/
/*  Output Packet Struct                                            */
/********************************************************************/
typedef struct tagOutPacket{
	long	lTrIndex;
	long	lTotalJongCnt;				/* �˻��� ���� ���� ��      */
	long	lOutFieldCnt;				/* Out Field Count          */
	long	lOutListPacketSize;			/* ��� List ������(������) */
	long	lFindTime;					/* �˻��ð�					*/
	//char    ResultBit[RESULT_MAX];	/* ������� bit list		*/
} OutPacket;
#define SZ_OutPacket sizeof(OutPacket)

// KB�������ǿ�	-hidden-
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
	char		chSign;					/* ���ϴ�� ��ȣ  1:���� 2:��� 3:���� 4:���� 5:�϶�*/
	char		chCode[CODE_LENGTH];	/* ���� �ڵ�	 			*/
	char		chName[CODENAME_LENGTH];/* �����		 			*/ 
	char		chMarket;               /* �ŷ���:'1', �ڽ���:'2'	*/
	long		lOrderRank;				/* �����˻� ���� 			*/	
	double		dFieldData[RESULT_FIELD_MAX];
} OutListPacket;
#define SZ_OutListPacket sizeof(OutListPacket)

// KB�������ǿ�	-hidden-
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
/*		  Condition Client =>  STRUCT/DEFINE/TYPEDEF ����					*/
/*																															*/
/*                   2005. 12.  		Doori												*/
/*                        �ۼ��� : �쵿��                       */
/****************************************************************/
const		LPCTSTR		CONDITION_INDEX[] = { "A", "B", "C", "D", "E", "F", "G", "H", "I",
												"J", "K", "L", "M", "N", "O", "P", "Q", "R",
												"S", "T", "U", "V", "W", "X", "Y", "Z",
												"a", "b", "c", "d", "e", "f", "g", "h", "i", 
												"j", "k", "l", "m", "n", "o", "p", "q", "r",
												"s", "t",  "u", "w", "x", "y", "z" };


const		LPCTSTR		TARGETLIST_TYPE1[] = { "�ϰ�", "�ְ�", "����", " 1��", " 3��", " 5��", 
																				 "10��", "15��", "30��", "60��" };
const		int		TARGETINDEX_TYPE1[] = { 0, 1, 2, 3, 4, 5, 
																				 6, 7, 8, 9 };

const		LPCTSTR		TARGETLIST_TYPE2[] = { "�ϰ�" };
const		int		TARGETINDEX_TYPE2[] = { 0 };

const		LPCTSTR		TARGETLIST_TYPE3[] = { " 1��", " 3��", " 5��", 
																				 "10��", "15��", "30��", "60��" };
const		int		TARGETINDEX_TYPE3[] = { 3, 4, 5, 
																				 6, 7, 8, 9 };

/*
const		LPCTSTR		TARGETLIST_TYPE1[] = { "�ϰ�", "�ְ�", "����", " 1��", " 3��", " 5��", 
																				 "10��", "15��", "60��" };
const		int		TARGETINDEX_TYPE1[] = { 0, 1, 2, 3, 4, 5, 
																				 6, 7, 9 };

const		LPCTSTR		TARGETLIST_TYPE2[] = { "�ϰ�" };
const		int		TARGETINDEX_TYPE2[] = { 0 };

const		LPCTSTR		TARGETLIST_TYPE3[] = { " 1��", " 3��", " 5��", 
																				 "10��", "15��", "60��" };
const		int		TARGETINDEX_TYPE3[] = { 3, 4, 5, 
																				 6, 7, 9 };
*/

#define MAX_FIELD_CNT				17		//# ��� Grid Column ���� Max Count


#define GRID_MOVEFIELD_POS_NAME			"[������ ��ġ]"
#define GRID_MOVEFIELD_POS_INDEX		-100


#define XML_VERSION_USERFILE	"2.0"

//#define FOLDER_NEWS						"\\Data\\NewsData"

// 20120723 ssj - �����ڵ��ֹ� >>
//.#define FOLDER_NEWS						"\\DRData\\NewsData"	//@NH
// 20120723 ssj - �����ڵ��ֹ� <<

//#define NEWS_KEYWORD_FILE			"\\txnews_keyword.dat"

// 20120723 ssj - �����ڵ��ֹ� >>
/*
#define FOLDER_TABLE					"\\Table"
#define MEMBERCOMP_FILE				"seccd.dat"
*/
// 20120723 ssj - �����ڵ��ֹ� <<

#define FOLDER_FINDDATA				"\\FindData"

//20100211 ���ѵ� >> NH ��ΰ� �ٲ� �ٲ�

// 20120723 ssj - �����ڵ��ֹ� >>
//.#define FOLDER_DATA						"\\DRData" + FOLDER_FINDDATA
#define FOLDER_DATA						"\\Data" + FOLDER_FINDDATA
// 20120723 ssj - �����ڵ��ֹ� <<


/************************************************************/
/*																													*/
/* ���� ���α׷����� ����ϴ� XML File Saveed Insert ���� */
/*																													*/
/*								2004. 11. 02		Doori(�쵿��)							*/
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
	int nMarketType[MAX_PORT_ITEM];		 //# �ŷ���:'1', �ڽ���:'2'
	CString strCode[MAX_PORT_ITEM];
} PortGroupInfo;
*/


#define HEAD_OTHER_CNT      2  //# �߰� �ʵ� ����
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


//# ���� �ϳ��� ���� ���� #
typedef struct tagOneCondition {
	BOOL bFalg;					//# ���� ���� : TRUE
	
	int	nNotUserFlag;
	int	nGubunUserFlag;			//# ����/�񿬼� 

	int	nTargetBaseType;		//# TargetBase Type (�ϰ�����, �׿� ...)

	CString strTag;		  //# Tag  <= Map Create Tag
	CString strMapFile;	//# Map File Name

	int	nNonAlert;
	int	nChartValSet;

	CString strName;	//# ��ǥ��
	CString strText;	//# ��ǥ �ϼ� ����
	
	User_Define stCondition;

	BOOL bFieldVal;			//# ������
	BOOL bFieldState;		//# ������ Check Field Have
	BOOL bFieldEnable;	//# ������ Enable ���� 
										  //=> TRUE : Field values�� ���ų� ������ Not�� ���
										  //=> FALSE : Field values�� �ִ� ��� 
	
	HeadMoveInfo  stHeadMoveInfo;		//# ������ �ʵ� ����
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
   

#define NEWS_SUBROOTTITLE			  	"�����м�"
#define PORTPOLIO_SUBROOTTITLE		"���ɱ׷�"
#define LANGUAGE_SUBROOTTITLE			"������"
#define PATTEN_ROOTTITLE				  "���������"
#define ACCOUNT_SUBROOTTITLE			"��������׷�"

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
	int	nType;	// ���� ��� 0 : TS, 1 : YES, 2 : YES
	LPSTR	lpszName;		  // ���ϸ��� Ȯ���� .sts�� ���̸� ��
					            // ��ũ��Ʈ ��δ� ��Ʈ���/ScriptFiles
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
	int nMarketType;			//# 0 : ��ü, 1 : �ڽ���, 2 : �ڽ���
	
	int nNowPriceChk;
	int nNowPriceUp, nNowPriceDown;
	
	int nChangRateChk;
	int nChangRateUp, nChangRateDown;
		
	int nChangValChk[CNT_CHANGEVAL];

	int nUsjg;							// �켱��
	int nUnder;							// ��������
	int nDishonest;						// �Ҽ��� ����
	int nInvestAttention;				// ��������
	int nInvestWarn;					// ���ڰ��
	int nInvestRiskNotice;				// �������迹��
	int nInvestRisk;					// ��������
	
	int nDealVolType;		//# 0 : ����, 1 : Time
	int nDealVol;
	CList <SubFilterInfo, SubFilterInfo&>	*plistDealTimeVol;
		
	int nDealPriceType;		//# 0 : ����, 1 : Time
	int nDealPrice;
	CList <SubFilterInfo, SubFilterInfo&>	*plistDealTimePrice;
		
	int nDirectionChk[CNT_DIRECTION];

	CStringArray saOutCode;
} FilterInfo;
#define SZ_FILTERINFO	sizeof(FilterInfo)

typedef struct tagSignal_ConditionInfo2
{
	char    sJobFlag;           /* �ű�:'N', ������:'R', Ż��:'O'           */
	/* �����̻�: 'E', ���� ����:'W'             */
	/* ���� �ʱ�ȭ: 'I', ���� ��������: 'K'     */

	char    sCode[6];
	char    sName[20];
	/*Signal_CommonInfo2 stCommon;*/

	char    sManagement;                   // �������� (0:O, 1:X)
	char    sControl;                      // ��������(0), ��������(1), ���ڰ��(2), �������迹��(3),��������(4)
	char    sTradeStop;                    // �ŷ����� ���� (0:O, 1:X)
	char    sInvestAttention;              // �������� ���� (0:O, 1:X)
	char    sInsincerityNotice;            // �Ҽ��ǰ��� ���� (0:O, 1:X)
	char    sConfidenceLimit;              // �ſ����� ���� (0:O, 1:X)
	char    sCodeNotice;                   // ������� (0:O, 1:X)
	char    sJungriMeme;                   // �����Ÿ� ���� (0:O, 1:X)
	
	char	sUsjg;                         // �켱��                       
	char    sInvestWarn;                   // ���� ���                    
	char    sInvestRiskNotice;             // ���� ���� ����               
	char    sInvestRisk;                   // ���� ����  
		
	char    sMarket;                       // ���屸��  (1:Kospi, 2:Kosdaq)
	char    sDepositMoney[3];              // ���ű� ���� (100, 040, 033, 025)
	//# Code Info
	char    sPrice[8];           			// ���簡 (����:��)
	char    sChgRate[6];         			// �����   Type(S999.99)   
	char    sSign;               			// ���ϴ���ȣ  
	char    sVolume[9];          			// �ŷ��� : Unit(1,000)   
	char    sAmount[9];          			// �ŷ���� : Unit(100,000,000)
	char    sChage[8];           			// ���ϴ��    
	char    sVolumeRect[6];    				// �ŷ��� �����: Unit(1,000)  
	char	filler[2];

	//# ��ȭ ����ü ����
	int		nData;							// ��ȣ �߻�����
	int		nTime;							// ��ȣ �߻��ð�
	int		nTrueCnt;						// ���縸�� �����(���� + �ű�)
	char	sSysNum[4];						// System Alert ���ǹ�ȣ(����ڴ� "0000")
	int		nEntryCnt;						// ���� Ƚ��
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
//@�������� �߰�
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
// 			szTmp	 = vvRpValueList[1][1];	// �˻��� ���� ���� ��
// 			if(szTmp.GetLength()==0) return 0;
// 
// 			int nRet = atoi(szTmp);
// 			// ��ȸ�� ������ ���� ��� (-900)�� ���ϵȴٰ� ��.
// 			return (nRet<0)? 0: nRet;
// 		}
// 		
// 		void SetData(CHARVECTOR2 &vvRpValueList, OutPacket* pOutData)
// 		{
// 			CString szTmp;
// 			szTmp	 = vvRpValueList[1][0];
// 			pOutData->lTrIndex	= atol(szTmp);			//�ݱ���
// 
// 			szTmp	 = vvRpValueList[1][1];
// 			pOutData->lTotalJongCnt	= atol(szTmp);		//�˻��� ���� ���� ��
// 
// 			szTmp	 = vvRpValueList[1][2];
// 			pOutData->lOutFieldCnt	= atol(szTmp);		//Out Field Count
// 
// 			szTmp	 = vvRpValueList[1][3];
// 			pOutData->lOutListPacketSize = atol(szTmp);	// ��� List ������(������)
// 
// 			szTmp	 = vvRpValueList[1][4];
// 			pOutData->lFindTime	= atol(szTmp);			// �˻��ð�
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
// 			szTmp	 = vvRpValueList[1][0];	// ��û����
// 			if(szTmp.GetLength()==0) return 0;
// 
// 			int nRet = atoi(szTmp);
// 			return (nRet<0)? 0: nRet;	// CConditionResultWnd::SetSearch_WorkDate()���� 42�� ��û.
// 		}
// 	};
// 
// 	class C0626OutBlock2
// 	{
// 	public:
// 		void SetData(CHARVECTOR2 &vvRpValueList, char* pOutData, int nDataCnt)
// 		{
// 			CString szTmp;	// ������
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
// 			szTmp	 = vvRpValueList[1][0];	// �˻��� ���� ���� ��
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
// 			CString sMarket,		//���ϱ���
// 					sCode,		//�����ڵ�
// 					sName,		//�����
// 					sSetPos;	//�ε���
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
//20100504 ���ѵ� >>
// typedef struct stRealData
// {
// 	BYTE	chCount;
// 	CString	strKeyCode;
// 	int		nSize;
// 	LPSTR	pDataBuf;
// 	int		lRealStruct;
// 	BYTE	chRealType;
// } REALDATA;
//20100504 ���ѵ� <<

// �ڵ����� 
// typedef struct REALDATA
// {
// //	char		szKeyCode[20];						// �����ڵ�(������)
// 	char		szKeyCode[32];						// �����ڵ�(������)
// 	BYTE		chRealType;							// �ڵ����� Ÿ�� 
// 	BYTE		chCount;							// �ڵ����� ���� 
// 	short       nSize;								// �ڵ����� ����ü ������ 
// 
// 	char*       pDataBuf;							// ���� ������ 
// 	long		lRealStruct;						// �ڵ����� ����ü ( ����ü�� ���� Pointer )
// } REALDATA_st, *LPREALDATA;
 #endif // CCONDITION_MNGDEF

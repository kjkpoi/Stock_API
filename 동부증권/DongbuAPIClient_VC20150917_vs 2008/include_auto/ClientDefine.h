#ifndef _CLIENTDEINE_H
#define _CLIENTDEINE_H


#define USE_CREDITORD			1

#define MAPTYPE_COND_ACCOUNT -100	//��������
#define MAPTYPE_COND_ITEM	 -200	//BM����
#define MAPTYPE_COND_BASE	 -300	//�ü�����
#define MAPTYPE_COND_INDEX	 -400	//��ǥ����

//���� ���� 
#define SVRORD_MARKETTYPE_STOCK  "S" //�ֽ�
#define SVRORD_MARKETTYPE_ELW	"E" //ELW
#define SVRORD_MARKETTYPE_FUT	"F" //����
#define SVRORD_MARKETTYPE_OPT	"O" //�ɼ�
#define SVRORD_MARKETTYPE_SFUT  "K" // �ֽļ���
#define SVRORD_MARKETTYPE_UP	"U" //����

#define SVRORD_JOB_REG			"I"		//���
#define SVRORD_JOB_UPDATE		"U"		//����
#define SVRORD_JOB_DELETE		"D"		//����
#define SVRORD_JOB_STOP			"S"		//����
#define SVRORD_JOB_START		"R"		//����

#define SVRORD_AUTO_YES	0			//�ڵ�
#define SVRORD_AUTO_NO	1			//���ڵ�

#define SVRORD_MMTYPE_SELL "1"		//�ŵ�
#define SVRORD_MMTYPE_BUY  "2"		//�ż�

#define SVRORD_PRICETYPE_TARGET 1   //������
#define SVRORD_PRICETYPE_MARKET 2   //���尡

#define MASS_ID				"500" // ��ü���а�(HTS)

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
	MPRICE_MATCH, // ���԰�
	MPRICE_USER, // �����ܰ�
};

enum {
	FL_NONE,
	FL_QRY_AGREE, // ��ȸ
	FL_REG_AGREE, // ���
};
// 20120723 ssj - �����ڵ��ֹ� <<

enum enORDTYPE
{
	NORMAL_ORDER = 1,	// �Ϲ��ֹ�
	HOGADIV_ORDER,		// ȣ�������ֹ�
	TIMEDIV_ORDER		// �ð������ֹ�
};

enum
{
	WND_SELL = 0, // 0: �ŵ�, 1: �ż� -> m_tabSellBuy �� �ε����� ���߾�� �Ѵ�!!
	WND_BUY,
};

enum
{
	ORDTYPEWND_NORMAL,
	ORDTYPEWND_DIV,
};

// 20120723 ssj - �����ڵ��ֹ� >>
// EVAL_UNIT_PERCENT: %, EVAL_UNIT_WON: ��, EVAL_UNIT_TICK: tick
enum {
	EVAL_UNIT_PERCENT = 0,
	EVAL_UNIT_WON, 
	EVAL_UNIT_TICK,
};

// BASE_TYPE_MATCH: ���԰�, BASE_TYPE_USER: �����ܰ�
enum {
	BASE_TYPE_MATCH = 0, 
	BASE_TYPE_USER,
};
// 20120723 ssj - �����ڵ��ֹ� <<

// 20120723 ssj - �����ڵ��ֹ� >>
enum
{
	BAL_NONE,
	BAL_SELL,
	BAL_BUY,
};

#define SVRORD_CASH			0	//����
#define SVRORD_CREDIT		1	//�ſ� ����
#define SVRORD_CREDIT_YU	3	//����

#define EXPIREDATE		30
//ȭ�� ����(ȭ�� ��ȣ�Ǵ� �̸����� ����)
#define  OPENTYPE_STOCK_BUY   1

#define  OPENTYPE_FUTURE_BUY  3

#define  OPENTYPE_STOCK_SELL  5
#define  OPENTYPE_FUTURE_SELL 7


#define  MODE_EQUITIES   9
#define  MODE_DERIVATIVES  11

#define CODEINPUT_PROPERTY_FO_SFO_SHARE	 _T("CC=00011000000000000010000000100001000000000000000000000000000000000:CD=0:CH=1:CT=1:MHC=20:MXL=8:MIL=8:ECP=1;1;0;1;0;0;:UEP=1:CN1=�ڵ�:CN2=�����:GS=�ڵ�-�����ɼ�7;�ڵ�A-�����ɼ�2;�ڵ�B-�����ɼ�2;�ڵ�C-�����ɼ�2;�ڵ�-�ֽļ���7;:LS=�ڵ�2;") 

#define	TRADINGTYPE_BID					"�ż�"
#define	TRADINGTYPE_SELL				"�ŵ�"
#define	TRADINGTYPE_REPURCHASE			"ȯ��"
#define	TRADINGTYPE_LIQUIDATAION		"����"
#define	TRADINGTYPE_CLEARING			"û��"

//�׸���
#define CEL_BTN_ONOFF		0
#define ITEMCODE_COL		1 //�����, �����ڵ�
#define COL_CREDIT_FOSELLBUY	2 //����	
#define JANGO_VOL_COL		3 //��������
#define UNITPRICE			4 //�ܰ�
#define	COL_USER_PRICE		5 // �����ܰ�
#define CUR_PRICE			6 //���簡  
#define EVALUATE_COL		7 //����    
#define EVALUATERATE_COL	8 //���ͷ�  
#define COL_LOANDATE		9 //������   
#define COL_EXPIRE_DATE		10 //��ȿ�Ⱓ
#define COL_BUY_COND1_ACC	12 //�������� - �ż�
#define ORDINFO_END_COL		19 // ���� ������ ��
#define COL_MTYPE			20 // ��ü����
#define COL_BTN_X			21 // ������ư
#define COL_COST			22 // ���Աݾ�
#define COL_UNIT			23 // �ŷ��¼�

#define		COLOR_BACK_INDEX			0
#define		COLOR_TEXT_INDEX			2		// �⺻�۲û�
#define		COLOR_BSKIN_TEXT_INDEX		3		// ����Ų �۲û�
#define		COLOR_GRID_TEXT_INDEX		3

#define		COLOR_UP_INDEX				4		// ��»�
#define		COLOR_DOWN_INDEX			6		// �϶���
#define		COLOR_BSKIN_UP_INDEX		5		// ����Ų ��»�
#define		COLOR_BSKIN_DOWN_INDEX		7		// ����Ų �϶���

#define		COLOR_BUY_INDEX1			14
#define		COLOR_BUY_INDEX2			15
#define		COLOR_SELL_INDEX1			16
#define		COLOR_SELL_INDEX2			17
#define		COLOR_MODCANCEL_INDEX		18
#define		COLOR_MODCANCEL_INDEX2		19

#define		COLOR_GRID_HEADER_INDEX		20
#define		COLOR_LINE_INDEX			22
#define		COLOR_GRID_BACK_INDEX		23
#define		COLOR_GRID_SELECT_INDEX		29		// ����Į��

#define		COLOR_CHKBOX_LINE_INDEX		70

#define ID_XP1	101 // ���Ǻ���
#define ID_XP2	102 // �޼���
#define ID_XX9	201 // �ֽ� �ǽð� �ܰ�
#define ID_XF3	202 // ���� �ǽð� �ܰ�
#define ID_XF4	203 // ���� �ǽð� �ܰ�

#define ID_S31	301 // �ֽ� ���簡
#define ID_ELC	302 // ELW ���簡
#define ID_SC0	303 // ���� ���簡
#define ID_OC0	304 // �ɼ� ���簡
#define ID_JC0	305 // �ֽļ��� ���簡
#define ID_OPC	306 // �ֽĿɼ� ���簡

#define ID_X11	401 // �ֽ� ȣ��
#define ID_ELH	402 // ELW ȣ��
#define ID_SH0	403 // ���� ȣ��
#define ID_OH0	404 // �ɼ� ȣ��
#define ID_JH0	405 // �ֽļ��� ȣ��
#define ID_OPH	406 // �ֽĿɼ� ȣ��

#define ID_JANGO_S31	501 // �ֽ� ���簡 (�ܰ��)
#define ID_JANGO_ELC	502 // ELW ���簡 (�ܰ��)
#define ID_JANGO_SC0	503 // ���� ���簡 (�ܰ��)
#define ID_JANGO_OC0	504 // �ɼ� ���簡 (�ܰ��)
#define ID_JANGO_JC0	505 // �ֽļ��� ���簡 (�ܰ��)
#define ID_JANGO_OPC	506 // �ֽĿɼ� ���簡 (�ܰ��)

#define  STR_NOINPUTVALUE "9999"

/////////////
//  ��Ʈ�� //
/////////////
//��Ʈ�� ���� (��Ʈ�� ���ڰ����� X���� �뷫 ��ġ       X4 = 4���ڵ��� ��Ʈ�� ����)
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

//��Ʈ�� ����
#define LEN_CTRL_HEIGHT  20

//��Ʈ�Ѱ� ��Ʈ�� ���� ����
#define LEN_CTRL_HGAPTYPE1  1    //����Ǵ� ��Ʈ�Ѱ��� ����
#define LEN_TEXT_TO_CTRL    6    //Text�� ��Ʈ�� ����
#define LEN_CTRL_TO_TEXT    4    //��Ʈ�ѿ� ���� �ؽ�Ʈ

//��Ʈ�Ѱ� ��Ʈ�� ���� ����
#define LEN_CTRL_VGAP		1   //�Ϲݰ���
#define LEN_CTRL_VGAP5		5
#define LEN_CTRL_VGAP_CHECK	12	//üũ�ڽ� ���� ����
#define LEN_CTRL_VGAP_Ex    17  //Ÿ�׷���� ����

#define DEFAULT_COLUMN_COUNT		7
#define PROGRAM_TITLE				"�����ڵ��ֹ�"

#define VOLCHECK		 1 //�ֹ����ɼ���
#define LQVOLCHECK		 2 //û�갡�ɼ���


//>>[KSJ000000026] �ſ��ֹ��߰�, �ֹ������߰�
#define PRICETYPE_CNT_STOCK  _countof(PRICE_TYPE_STRING_EX)
#define PRICETYPE_CNT_ELW	 _countof(PRICE_TYPE_STRING_ELW_EX)
#define PRICETYPE_CNT_FUTOPT _countof(PRICE_TYPE_STRING_FUTOPT_EX)
#define PRICETYPE_CNT_SFUT		_countof(PRICE_TYPE_STRING_SFUT)

const LPCTSTR PRICE_TYPE_TARGET[] =    {_T("������"), _T("���Ǻ�������"), _T("������[IOC]"), _T("������[FOK]")};

const LPCTSTR PRICE_TYPE_STRING_EX[] =        {_T("������"), _T("���尡"), _T("������������"), _T("�ֿ켱������"), _T("���Ǻ�������"), _T("������[IOC]"), _T("���尡[IOC]"), _T("������[IOC]"), _T("������[FOK]"), _T("���尡[FOK]"), _T("������[FOK]")};
const LPCTSTR PRICE_TYPE_VALUE_EX[] =         {_T("1"),      _T("2"),      _T("3"),            _T("4"),            _T("9"),            _T("A"),           _T("B"),           _T("C"),           _T("D"),           _T("E"),           _T("F")};

const LPCTSTR PRICE_TYPE_STRING_ELW_EX[] =    {_T("������"), _T("������[IOC]"), _T("������[FOK]")};
const LPCTSTR PRICE_TYPE_VALUE_ELW_EX[] =     {_T("1"),      _T("A"),           _T("D")};

const LPCTSTR PRICE_TYPE_STRING_FUTOPT_EX[] = {_T("������"), _T("���尡"), _T("������������"), _T("���Ǻ�������"), _T("������[IOC]"), _T("���尡[IOC]"), _T("������[IOC]"), _T("������[FOK]"), _T("���尡[FOK]"), _T("������[FOK]")};
const LPCTSTR PRICE_TYPE_VALUE_FUTOPT_EX[] =  {_T("1"),      _T("2"),      _T("3"),            _T("9"),            _T("A"),           _T("B"),           _T("C"),           _T("D"),           _T("E"),           _T("F")};
const CString FUTOPT_ORDTYPE_KEY_DONGBU[] =   { "00",           "03",         "06",               "05",               "10",              "13",             "16",               "20",              "23",              "26"};

const LPCTSTR PRICE_TYPE_STRING_SFUT[] = {"������", "������[IOC]", "������[FOK]"};
const LPCTSTR PRICE_TYPE_VALUE_SFUT[] =  {"1",      "A",           "D"};
const CString SFUT_ORDTYPE_KEY_DONGBU[] ={"00",	    "10",          "20"}; // �ֹ� ���ɼ��� ��ȸ ���� ���

const LPCTSTR PRICE_GB_STRING[] = {_T("������"), _T("���簡"), _T("�ż�1ȣ��"), _T("�ż�2ȣ��"),
_T("�ŵ�1ȣ��"), _T("�ŵ�2ȣ��"), _T("���Ѱ�"), _T("���Ѱ�")};

const LPCTSTR CREDIT_BUY_TYPE_STRING[] = { "���ֻ�ȯ" }; // "����"�� �ż����� ����
const CString CREDIT_BUY_TYPE_VAL[] =	{  "03", "07"};    // �ֹ� ���ɼ��� ��ȸ ���� ���

const LPCTSTR CREDIT_SELL_TYPE_STRING[] = { "����", "�ڱ����ڻ�ȯ", "�������ڻ�ȯ", "�㺸�����ȯ" };
const CString CREDIT_SELL_TYPE_VAL[] =	{ "05",  "03", "01", "80"};  // �ֹ� ���ɼ��� ��ȸ ���� ���

const LPCTSTR PRICE_TYPE_STRING2[] = {_T(""), _T("CP"), _T("S1"), _T("S2"), _T("D1"), _T("D2"), _T("HP"), _T("LP")};//[KSJ000000026] �ſ��ֹ��߰�, �ֹ������߰�


enum
{
	COND_PL, // ��������
	COND_Q, // �ü�����
	COND_BM, // BM����
	COND_I, // ��ǥ����
};

const LPCTSTR ORDER_COND_STRING[] = {_T("��������"), _T("�ü�����"), _T("BM����"), _T("��ǥ����")/* , _T("���������")*/};
const int	  ORDER_COND_INT[] =	{    COND_PL,		 COND_Q,         COND_BM,      COND_I/* , _T("���������")*/};


const LPCTSTR ORDER_TYPE_STRING[] = {_T("�Ϲ��ֹ�"), _T("ȣ������")/*, _T("�ð�����") */};
const LPCTSTR DIV_STANDARD_STRING[] = {_T("���迭"), _T("��迭"), _T("���迭") };
const LPCTSTR PRICE_STANDARD_STRING[] = {_T("�ŵ�7ȣ��"), _T("�ŵ�6ȣ��"),_T("�ŵ�5ȣ��"), _T("�ŵ�4ȣ��"), 
				_T("�ŵ�3ȣ��"), _T("�ŵ�2ȣ��"), _T("�ŵ�1ȣ��"),
				_T("�ż�1ȣ��"), _T("�ż�2ȣ��"), _T("�ż�3ȣ��"), 
				_T("�ż�4ȣ��"), _T("�ż�5ȣ��"), _T("�ż�6ȣ��"), _T("�ż�7ȣ��")};
#define DIVSTANDARD_INDEX 4	//���ذ� �޺��ڽ� �����ε���

const LPCTSTR PRICE_STANDARD_STRING_CONVERT[] = {_T("D7"), _T("D6"),_T("D5"), _T("D4"), _T("D3"), _T("D2"), _T("D1"), _T("S1"), _T("S2"), _T("S3"), _T("S4"), _T("S5"), _T("S6"), _T("S7")};


const LPCTSTR XML_TYPENAME[] = { _T("CONDI_TYPE"), _T("TARGETBASE_TYPE"), _T("GUBUN"), _T("GUBUN_DEFVAL")
	, _T("NOT_USER"), _T("NOT_DEFVAL"), _T("RESULT_VIEW_ID"), _T("RESULT_VIEW_DEFVAL"),
	_T("CHART_VALSET"), _T("FILE_NAME")};

#define RECOMMEND_ROOTTITLE				"��õ����"
#define USER_ROOTTITLE			  		"���������"
#define LANGUAGE_ROOTTITLE				"������"
#define BOOKMARK_SUBROOTTITLE			"���ã��"

#define INT2STR_BUF(xStr, nSize, nStr) sprintf_s(xStr, "%#0*.*d", nSize, nSize, nStr)

#define SVR_AUTO_ORDER_STOCK_FILE		_T("SvrAutoOrd_STOCK.xml")
//#define SVR_AUTO_ORDER_ELW_FILE		_T("SvrAutoOrd_ELW.xml")
//#define SVR_AUTO_ORDER_FO_FILE		_T("SvrAutoOrd_FO.xml")

// 20120723 ssj - �����ڵ��ֹ� >>
#define STR_CAPTION				"�����ڵ��ֹ�"
#define E_STR_PASSWORD_NEEDED	"��й�ȣ�� �Է��Ͽ� �ֽʽÿ�."
#define E_STR_ACNT_NEEDED		"���¹�ȣ�� �Է��Ͽ� �ֽʽÿ�."
#define E_STR_CODE_NEEDED		"������ �����Ͽ� �ֽʽÿ�."
#define E_STR_MP				"HTS/MTS���� ���/������ ���Ǹ� ������ �� �ֽ��ϴ�."


#define E_STR_SOPT				"�ֽĿɼ��� �������� �ʽ��ϴ�."


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

//����ID
#define	REAL_CHEJAN_REG			0x24	// �ֹ� ü��/�ܰ� �ǽð����(ƼĿü���뺸 : 36)
#define	REAL_SISE_REG			0x32	// �ü����					(�ֽ�����ü� : 50 )
#define	REAL_ELWSISE_REG		0x37	//ELW�ü����
#define	REAL_FUTSISE_REG		0x41	//�����ü����
#define	REAL_OPTSISE_REG		0x43	//�ɼǽü����


//�ֹ�ü�� �ڵ����� ID
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
	strcpy_s(logFont.lfFaceName, (const char*)_T("����ü"));  \
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

// 20120723 ssj - �����ڵ��ֹ� >>
static const char *STR_ON = "ON";
static const char *STR_OFF = "OFF";

#define COLOR_STR_ON		RGB(0, 255, 0)

static const int WATCH_STOP = 0;
static const int WATCH_START = 1;
// 20120723 ssj - �����ڵ��ֹ� <<


//���� ��Ʈ�� ���� 
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
	int		nTotalUp;			//���
	int		nTotalBalance;		//����
	int		nTotlaDown;			//�϶�
	int		nTotalAll;			//��ü
	float	fUpRatio;			//����������
	float	fDeclineRatio;		//��յ����
	int		nKospiAll;
	int		nKospiUp;
	int		nKospiDown;
	float	fKospiDeclineRatio;
	int		nKosdaqAll;
	int		nKosdaqUp;
	int		nKosdaqDown;
	float	fKosdaqDeclineRatio;

	int		nStrongUp;			// �����
	int		nNormalUp;			// ���
	int		nSoftUp;			// ����
	int		nSoftDown;			// ���϶�
	int		nNormalDown;		// �϶�
	int		nStrongDown;		// ���϶�
}STATICSTIC;

typedef struct tagOrdGrid
{
	char	cChk[1];					//üũ
	char	cAutoFlag[1];				//�ڵ�,���ڵ�
	char	szItemCode[LEN_ITEMCODE];	//�����ڵ�
	char	szItemName[LEN_ITEMNAME];	//�����
	char	szPrice[10];				//���簡
	char	szCondStatement[100];		//ȿ������
	char	cCondType[1];				//�ֹ�����

	char	sQtyGb[1];					//�������� 1:����, 2:�����
	char	szOrdVolume[10];			//�ֹ�����,����
	char	szExpiredDate[8];			//��ȿ�Ⱓ
	char	cResult[1];					//ó�����
	char	cMMType[1];					//�ŵ�/�ż�
	char	cCredit[1];					//�ſ뱸��          
}StOrdGridData; //�ڵ��ֹ���Ȳ����Ʈ
#define SZ_ST_ORDGRIDDATA sizeof(StOrdGridData)


//��� �׸��� ������(�����׸�)
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

}StOrdCondData; //�����׸�
#define SZ_ST_ORDCONDDATA sizeof(StOrdCondData)


typedef struct tagOrdJango
{
	int		nMarketType;
	CString strItemName;
	CString strCode;
	CString strQty;
	CString strUintPrice;
	// 20140722 ssj - ���� �ܰ� ���� ���� >> ���� �ǽð� �ܰ�� ������ ���� ����
	//LONGLONG	nnOrgUnitPriceForCalc;
	// 20140722 ssj - ���� �ܰ� ���� ���� <<
	CString strCurPrice;
	CString strProfitandLoss; // ����
	CString strROP;
	CString strCreditOrdJango;
//	CString strMMType;		//�ŵ��ż�����

	CString strHideContract;	//�����ݾ�

	// 20140709 ssj - �ŷ��¼� ���������� ���� >>
	//int     nBasePrice;		//���� : 500000, �ɼ� : 100000, �ֽļ��� : 10
	CString	strUnit;
	// 20140709 ssj - �ŷ��¼� ���������� ���� <<

	//>>[KSJ000000026] �ſ��ֹ��߰�, �ֹ������߰�
	// 20120723 ssj - �����ڵ��ֹ� >>
	//CString strCreditName;	//�ſ��
	// 20120723 ssj - �����ڵ��ֹ� <<

	CString strLoanDateOrdJango;	//������

	// 20120723 ssj - �����ڵ��ֹ� >>
	CString	strFOSellBuy;
	CString strSign;
	// 20120723 ssj - �����ڵ��ֹ� <<
}StOrdJango;
#define SZ_ST_ORDJANGO sizeof(StOrdJango)

//���񰡰�����
typedef struct tagItemPrice
{
	CString strCode;	//�����ڵ�
	CString strCurPrice;//���簡
	CString strSign;	//�����ȣ
	
}StItemPrice;
#define SZ_ST_ITEMPRICE sizeof(StItemPrice)

//�ܰ�ü������
typedef struct tagItemCheJan
{
	int		nMarketType;//����
	CString strCode;	//�����ڵ�
	CString strName;	//�����ڵ�
	CString strCurPrice;//���簡
	CString strCheVol;  //ü�ᷮ
	CString strMMType;  //�ż��ŵ�����
	CString strCredit;	//�ſ뱸�и�
	CString strCreditGb;	//�ſ뱸�а�
	CString strUintPrice;//���Դܰ�
	CString	strMiGyuleAvrPrice; //�����ݾ�(����)
	CString strCheUnitPriceAvr; //���ü��ܰ�

}StCheJan;
#define SZ_ST_CHEJAN sizeof(StCheJan)

//BM���� MapType, TagID, ChkBtnID
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
	char    sOrdCnt		 [  4];   /* ���� �ֹ��� �� �ֹ��Ǽ�                   */
	char    sOrdSeq      [  4];   /* ���� �ֹ��� ���° �ֹ�����               */
	char    sMarketGb    [  1];   /* ���屸�� (S(STOCK),E(ELW),F(FUT),O(OPT))  */

	char	sCondName	 [ 50];
	char    sPSize       [  4];   /* �ֹ� packet size                          */
	char    sOrdData     [120];   /*Data                         */
} SEMI_AUTO_ORD_HEAD;
#define  SZ_SEMI_AUTO_ORD_HEAD sizeof(SEMI_AUTO_ORD_HEAD)

//< �ֽ� / ELW �϶� : ���� Structure �ڿ� �Ʒ��� �ֽ�/ELW �ֹ� Structure�� ��. >
typedef struct
{
   char  PassWd         [ 8];   /* ��й�ȣ(8)                              */
   char  OrdDate        [ 8];   /* �ֹ���(8)                                */
   char  AcctNo         [11];   /* ���¹�ȣ(11)                             */
   char  BondTp         [ 1];   /* �ֽ�ä�Ǳ���(1) 1:�ֽ� 2:ä��            */
   char  Code           [12];   /* ǥ�������ڵ�(12)                         */
   char  SellBuyTp      [ 1];   /* �Ÿű���(1)                              */
   char  MarketTp       [ 1];   /* ���屸��(1)                              */
                                /* 1.�峻 2.���(����) 3.KOSDAQ             */
                                /* 4.OTCBB 5.�ֽ�ECN 9.��Ÿ                 */
   char  DaeYongTp      [ 1];   /* ��뱸��(1)                              */
                                /* �����ɼǴ�뱸��:                        */
                                /* N.���� Y.�����ɼǴ�� 2:�μ�/��          */
   char  OrdQty         [10];   /* �ֹ�����(10)                             */
   char  OrdPrc         [10];   /* �ֹ�����(10)                             */
   char  PrcModiTp      [ 1];   /* ������������ 1.�������� 2.�Ϻ�����       */
   char  QtyCancTp      [ 1];   /* ������ұ��� 1.������� 2.�Ϻ����       */
   char  OrdTp          [ 2];   /* �ֹ�����(2)                              */
                                /* 11:�ϹݸŸ�(ECN) 12:�뷮�Ÿ�(ECN)        */
                                /* 01.������ 02.����뷮 03.�Ű�뷮        */
                                /* 05.���尡 06.���Ǻν��尡 09.�ڻ���      */
                                /* 26.���Ǻ�����뷮 71.�ð�������          */
                                /* 72.�ð��ܴ뷮 79.�ð��ܴ뷮�ڱ��ֽ�      */
                                /* 12.������     13.�ֿ켱                  */
   char  BuyDate        [ 8];   /* �ż���(8) (YYYY/MM/DD)                   */
   char  CreditTp       [ 2];   /* �ſ뱸��(2)                              */
                                /* 00.���� 01.�������ڸż� 02.�ڱ����ڸż�  */
                                /* 03.������ָŵ�  11.�������ڸŵ���ȯ     */
                                /* 12.�����������ݻ�ȯ 33.�ڱ����ڸŵ���ȯ  */
                                /* 34.�ڱ��������ݻ�ȯ 55.������ָż���ȯ  */
                                /* 56.�������������ȯ                      */
                                /* 77.�ڱ���ָż���ȯ 78.�ڱ����������ȯ  */
   char  LoanDate       [ 8];   /* ������(8) (YYYY/MM/DD)                   */
   char  CondTp         [ 1];   /* ���Ұŷ�����(1) 1.���� 2.���� 3.IOC 4.FOK*/
   char  SmallTp        [ 1];   /* �Ҿ���������(1)                          */
   char  AgencySellTp   [ 1];   /* �ŵ������ݴ�ŵ�����(1)                */
   char  HoldTp         [ 1];   /* �ܰ�������(1)                          */
                                /* ä���ܰ��� �� ��¡����� üũ�� ���   */
   char  OrginNo        [10];   /* ���ֹ���ȣ(10)                           */
                                /* �����ֹ������� ��ҵ� ����� �ֹ���ȣ    */
   char  TxonObjtTp     [ 1];   /* ������󱸺�---ä�ǸŸŽø� ���         */
   char  SeqNo          [ 2];   /* �ֹ����� (�����ֹ����� ���)->           */
                                /* HTS���� �´�� �Ѱ��ش�                  */

}TRAN_CH401C00_InRec1;


//< ���� / �ɼ� �϶� : ���� Structure �ڿ� �Ʒ��� ����/�ɼ� �ֹ� Structure�� ��.>
typedef struct
{
   char  ord_dt         [ 8];    /* �ֹ���(8)                               */
   char  acnt_no        [11];    /* ���¹�ȣ(11)                            */
   char  scrt_no        [ 8];    /* ��й�ȣ(8)                             */
   char  item_cd        [ 8];    /* �����ȣ(8)                             */
   char  fuop_ord_gbn   [ 1];    /* �ֹ�����(1)  B.������������ L.������
                                                 M.���尡 C.���Ǻ�������    */
   char  fuop_ord_dl_gbn[ 1];    /* �ֹ�ó������(1)
                                                 1:�Ϲ��ֹ�, 2:����, 3:��� */
   char  ord_type_gbn   [ 1];    /* �ֹ���������(1)
                                                 1:�Ϲ��ֹ�, 2:���������ֹ� */
   char  part_total_gbn [ 1];    /* �Ϻ����α���(1)  1:����, 2:�Ϻ�         */
   char  sel_buy_gbn    [ 1];    /* �ż��ŵ�����(1)  1:�ŵ�, 2:�ż�         */
   char  ord_qty        [10];    /* �ֹ����� 9(10)(10)                      */
   char  ord_prc        [ 9];    /* �ֹ����� S9(7)V99(9)                    */
   char  oord_tnb_cd    [ 3];    /* �������ڵ�(3)                           */
   char  oord_no        [ 6];    /* ���ֹ���ȣ(6)                           */
   char  rsrv_ord_yn    [ 1];    /* �����ֹ�����(1) (Y,N)                   */
   char  ord_seq_no     [ 2];    /* �ֹ�����(2)                             */
   char  cc_desi_ord_gbn[ 1];    /* CC ��������(1)                          */
   char  fuop_ord_cond  [ 1];    /* �ֹ�����(1) X.���� I.IOC F.FOK          */
   char  temp_field1    [ 6];    /* �����input-filler(6)                   */
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
	char   KEYuserid	[20]; // ���̵�
	char   MarketGb    [1  ]; //���屸��         1:�ֽ�/ELW, 2:����/�ɼ�                                                                                                                             
	char   Acct        [12 ]; //���¹�ȣ                   
	char   ShCode      [8  ]; //���������ڵ�               
	char   Mmgbn       [1  ]; //�Ÿű���         1: �ŵ�, 2: �ż�                                                                                                                                    
	char   CrGbn       [1  ]; //�ſ뱸��                   
	char   CrDate      [8  ]; //������           YYYYMMDD  
	char   ExpireDate  [8  ]; //��ȿ�Ⱓ         YYYYMMDD  
	char   AutoGbn     [1  ]; //�ڵ��ֹ�����     0:�ڵ�, 1:���ڵ�                                                                                                                                    
	char   OrdGbn      [1  ]; //�ֹ�����         ��������
	char   OrdRegPrc   [20 ]; //�ֹ�����         ��������
	char   OrdQty	   [10 ]; //�ֹ�����         ��������
	char   CondAcct    [1  ]; //�������Ǽ��ðǼ�  '0':�ش����                                                                                                                                       
	char   CondItem    [1  ]; //BM���Ǽ��ðǼ�  '0':�ش����                                                                                                                                       
	char   CondPrice   [1  ]; //�ü����Ǽ��ðǼ�  '0':�ش����                                                                                                                                       
	char   CondIndex   [1  ]; //��ǥ���Ǽ��ðǼ�  '0':�ش����    
	char   AvgPrcFlag  [1];  // �ܰ� ������ 	 '0':���԰�, '1' �����ܰ�
	char   AvgPrc	   [15]; //��ո��Դܰ�	��ո��Դܰ�.
	char  sMassID		[3];		// ��ü���� - HTS �Ϲ�: 50(�𷰽�, ����, FX,FX+ ����), HTS �̴�: 51, ������/�ȵ���̵� ��: 66, �����е� ��: 67
	char   Act_gbn     [1  ]; //ó�����         
							// (���)I: Insert, (����)U: Update, (����)A: Active, (����)S: Stoped, (����)D: Delete, (�Ϸ����)F: Finished, E: Expired
	char   CondStmt    [394]; //ȿ�����ǹ���    
} ST_XP1;

class CPriceInfo
{
public:
	BOOL	m_bELW;

	CString	m_strCode;

	CString m_strCurrent;
	CString m_strDiff;
	CString m_strSign;

	CString m_strPrevClose; // ��������(���ذ�)


	CString	m_strFrontBasePrice; // �ֽļ����ٿ������ذ� - SFO ����("ȣ" ��ư ����)
	CString	m_strBackBasePrice; // �ֽļ������ÿ������ذ� - SFO ����("ȣ" ��ư ����)


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

		// 20131212 ssj - �ֽļ����������� ���� ���� >>
		m_strFrontBasePrice = "";
		m_strBackBasePrice = "";
		// 20131212 ssj - �ֽļ����������� ���� ���� <<

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

		// 20131212 ssj - �ֽļ����������� ���� ���� >>
		m_strFrontBasePrice.Trim();
		m_strBackBasePrice.Trim();
		// 20131212 ssj - �ֽļ����������� ���� ���� <<

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
	CString m_strSellBuy; // '1':�ŵ�, '2':�ż�
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

#define		CODEINPUT_PROPERTY_F_NS		_T("CC=00010000000000000010000000000000000000000000000000000000000000000:CD=1:CH=0:CT=1:MHC=20:MXL=8:MIL=8:ECP=1;1;0;1;0;0;:UEP=1::CN1=�ڵ�:CN2=�����:GS=;:LS=�ڵ�2;")
#define		CODEINPUT_PROPERTY_O_NS		_T("CC=00001000000000000000000000000000000000000000000000000000000000000:CD=1:CH=0:CT=1:MHC=20:MXL=8:MIL=8:ECP=1;1;0;1;0;0;:UEP=1::CN1=�ڵ�:CN2=�����:GS=;:LS=�ڵ�2;")


#endif
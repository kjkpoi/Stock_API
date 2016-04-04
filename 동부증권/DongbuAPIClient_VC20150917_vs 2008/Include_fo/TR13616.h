#if !defined(AFX_TR_13616_HEADER_)
#define AFX_TR_13616_HEADER_

#include "../include/Data_Common.h"

#define  TR_13616	"13616"

#define TR_13616_MAX 400 

#define  FUTBID             700   /* 선물/옵션-매수-주문          */
#define  FUTOFF             710   /* 선물/옵션-매도-주문          */
#define  FUTJUN             720   /* 선물/옵션-정정-주문          */
#define  FUTCAN             730   /* 선물/옵션-취소-주문          */
#define  FUTBIDJUNCON       702   /* 선물/옵션-매수-정정확인      */
#define  FUTOFFJUNCON       712   /* 선물/옵션-매도-정정확인      */
#define  FUTBIDCANCON       703   /* 선물/옵션-매수-취소확인      */
#define  FUTOFFCANCON       713   /* 선물/옵션-매도-취소확인      */
#define  FUTBIDCHECON       701   /* 선물/옵션-매수-체결확인      */
#define  FUTOFFCHECON       711   /* 선물/옵션-매도-체결확인      */
#define  FUTBIDRJTCON       709   /* 선물/옵션-매수거부확인       */
#define  FUTOFFRJTCON       719   /* 선물/옵션-매도거부확인       */
#define  FUTJJJRJTCON       729   /* 선물/옵션-정정거부확인       */ d
#define  FUTCANRJTCON       739   /* 선물/옵션-취소거부확인       */
#define  FUTSY1RJTCON       749   /* 선물/옵션-접속거부확인       */
#define  FUTSY2RJTCON       759   /* 선물/옵션-매매거부확인       */

//-------------------------------------------------------------------------------##
// 선물실시간체결         사용TR번호:13616                                     ##
//--------------------------------[INPUT ]---------------------------------------##
// [NOTE] 정렬 구분자 없음 : 기본은 "역순"

typedef struct _tr13616_i
{
	char  geja     [20];    /* 지점번호(3)+계좌번호(8) + space  */
	char  checkgb  [ 1];    /* 조회구분 0:전체, 1:종목          */
	char  jgcode   [ 8];    /* 종목코드                         */

	char  nxtGb    [ 1];    /* 0:처음, 1:다음                   */
	char  nxtKey   [ 9];    /* 다음조회 KEY: 주문번호           */
	char  jugb     [ 1];    /* 0전체 1매수 2매도                */

	char  userfld  [100];   /* 받은 그대로 내려준다             */
} TR_13616_I;

#define  TR_13616_I_SIZE sizeof(TR_13616_I)

//--------------------------------[OUTPUT반복 ]-----------------------------------##

typedef struct _tr_13616_g
{
	char  juno      [ 9];   /* 주문번호       */
	char  jgcode    [15];   /* 종목코드       */
	char  jgname    [40];   /* 종목       */
	char  jugb      [12];   /* 주문구분       */
	char  juprc     [12];   /* 주문단가       */
	char  juqty     [15];   /* 주문수량       */
	char  cheprc    [12];   /* 체결가격       */
	char  cheqty    [15];   /* 체결수량       */
	char  nonqty    [15];   /* 미체결         */
	char  wonjuno   [ 9];   /* 원주문번호     */
	char  jutype    [12];   /* 종류           */
	char  denymsg   [40];   /* 세부거부사유   */
} TR_13616_G;

#define  TR_13616_G_SIZE sizeof(TR_13616_G)


typedef struct _tr_13616_o
{
	char  userfld  [100];
	char  nxtBtnSz   [ 2];  /* 연속값길이   */
	char  nxtKey     [50];  /* 연속키값     */

	char  gridcnt   [ 6];
	char  gridmsg   [ 4];
	TR_13616_G  grid[TR_13616_MAX];
} TR_13616_O;


class CTR_13616_G
{
public: //Variable
//    DEFINE_DRDS_LINE0(
	CString  m_szjuno;     	 /* 주문번호  */
	CString  m_szjgcode;     /* 종목코드  */
	CString  m_szjgname ;
	CString  m_szjugb;   	/* 주문구분	*/
	CString  m_szjuprc;     /* 주문단가 	*/
	CString  m_szjuqty;    	/* 주문수량 	*/
	CString  m_szcheprc;    /* 체결단가 	*/
	CString  m_szcheqty;    /* 체결수량 	*/
	CString  m_sznonqty;    /* 미체결 		*/
	CString  m_szwonjuno;  	/* 원주문번호   */
	CString  m_szjutype;    /* 매매구분 	*/
	CString  m_szdenymsg;	 /* 세부거부사유   */

public:
	CTR_13616_G()
	{
	}

	virtual void  Convert(TR_13616_G* pInput)
	{		
		CString sTemp1;
		char sTmp[40+1];

		DATA_MEMCOPY(sTmp, pInput, juno		);   	/* 주문번호   */
		DATA_MEMCOPY(sTmp, pInput, jgcode	);   	/* 종목코드   */
		DATA_MEMCOPY(sTmp, pInput, jgname	);   	/* 종목   */
		DATA_MEMCOPY(sTmp, pInput, jugb		);   	/* 주문구분	  */
  		DATA_MEMCOPY(sTmp, pInput, juprc	);   	/* 주문단가   */
		DATA_MEMCOPY(sTmp, pInput, juqty	);   	/* 주문수량   */
		DATA_MEMCOPY(sTmp, pInput, cheprc	);   	/* 체결단가   */
		DATA_MEMCOPY(sTmp, pInput, cheqty	);   	/* 체결수량   */
		DATA_MEMCOPY(sTmp, pInput, nonqty	);   	/* 미체결 	  */
		DATA_MEMCOPY(sTmp, pInput, wonjuno  ); 	    /* 원주문번호	*/
		DATA_MEMCOPY(sTmp, pInput, jutype	);   	/* 주문유형 	*/
		DATA_MEMCOPY(sTmp, pInput, denymsg	);   	/* 세부거부사유  	*/		
	}
};

typedef CList<CTR_13616_G*, CTR_13616_G*> LIST_TR_13616_G;


class CTR_13616_O
{
public:
    CString m_szgridcnt;                  /* Grid count           */
  
  	int m_ngridcnt;                  /* Grid count           */


	CString m_sznxtKey ;

	CString m_szNextFlag ;
	CString m_szNextVal ;

	LIST_TR_13616_G m_DataList;

public:
	CTR_13616_O()
	{
		ResetAll();
	}

	~CTR_13616_O()
	{
		ResetAll();
	}

	virtual void  Convert(TR_13616_O* pInput)
	{		
		char sTmp[100+1]={0,};

		//20130814 EUNSOOK >>
		char sTmpNxt[50+1]={0,};
		DATA_MEMCOPY(sTmpNxt, pInput, nxtKey);   	/* Next key   */
		m_szNextFlag = m_sznxtKey.Mid(m_sznxtKey.Find("EN=") + 3, 1) ;				
		m_szNextVal = m_sznxtKey.Mid(m_sznxtKey.Find("DT=") + 3, 9) ;
		//20130814 EUNSOOK <<

    	DATA_MEMCOPY(sTmp, pInput, gridcnt);         /* Grid count           */
		
		DATA_CONVERT_int_0(gridcnt);					/* Grid count           */
		    	
	}

	virtual void  ClearList()
	{
		for(POSITION pos=m_DataList.GetHeadPosition(); pos; )
		{
			CTR_13616_G* pItem = m_DataList.GetNext(pos);
			if(pItem) delete pItem;
		}
		m_DataList.RemoveAll();
	}

	void ResetAll()
	{
	
		m_ngridcnt= 0;

		m_szNextFlag ="";
		m_szNextVal ="";
		m_sznxtKey="" ;

		ClearList();
	}
	
	

};

class CTR_13616_I
{
public:
	CString geja;
	CString	jgcode;
	CString	strTemp;

public:
	CTR_13616_I(TR_13616_I* pIn, LPCTSTR lpstrgeja, LPCTSTR lpstrjgcode, char csgb, char csort)
	{
		// 계좌
		geja	= lpstrgeja;
		geja.Remove('-'); geja.Remove('_'); geja.Remove(' ');
		strTemp.Format("%-*.*s", sizeof(pIn->geja), sizeof(pIn->geja), geja);
		memcpy(pIn->geja, strTemp, sizeof(pIn->geja));
		// 종목	
		jgcode	= lpstrjgcode;
		pIn->checkgb[0] = (jgcode == "")? '1' : '0'; //[ 1] 종목코드 체크구분 : 0:전체, 1:종목
		if(jgcode == "") jgcode = " ";
		else			jgcode.Remove(' ');
		strTemp.Format("%-*.*s", sizeof(pIn->jgcode), sizeof(pIn->jgcode), jgcode);
		memcpy(pIn->jgcode, strTemp, sizeof(pIn->jgcode));
	}
	CTR_13616_I()
	{
		geja	= "";
		jgcode	= "";
	}
};

#endif //AFX_TR_13616_HEADER_

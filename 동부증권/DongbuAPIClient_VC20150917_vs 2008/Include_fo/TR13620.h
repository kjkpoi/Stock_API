#if !defined(AFX_TR_13620_HEADER_)
#define AFX_TR_13620_HEADER_

#include "../include/Data_Common.h"

#define  TR_13620	"13620"

//-------------------------------------------------------------------------------##
// 선물실시간미체결         사용TR번호:13620                                     ##
//--------------------------------[INPUT ]---------------------------------------##
// [NOTE] 정렬 구분자 없음 : 기본은 "역순"

typedef struct _tr13620_i
{
	char  geja     [20];    /* 지점번호(3)+계좌번호(8)      */
	char  checkgb  [ 1];    /* 조회구분 0:전체, 1:종목      */
	char  jgcode   [ 8];    /* 종목코드                     */

    char  nxtGb    [ 1];    /* 0:처음, 1:다음                   */
    char  nxtKey   [ 9];    /* 다음조회 KEY: 주문번호           */
	char  type     [ 1];	/* 3전체 1주가지수선옵 2개별주식선옵 4상품선옵 */	// 20110414 dyh 누락된 필드 추가
} TR_13620_I;

#define  TR_13620_I_SIZE sizeof(TR_13620_I)

//--------------------------------[OUTPUT반복 ]-----------------------------------##

typedef struct _tr_13620_g
{
	char  juno      [9];   /* 주문번호       */
	char  jgcode    [15];   /* 종목코드       */
	char  jugb      [12];				/* 주문구분       */
	char  juprc     [12];	/* 주문단가       */
	char  juqty     [15];	/* 주문수량       */
	char  nonqty    [15];	/* 미체결         */
	char  wonjuno   [ 9];	/* 원주문번호     */
	char  jutype    [ 6];				/* 매매구분       */
} TR_13620_G;

#define  TR_13620_G_SIZE sizeof(TR_13620_G)


typedef struct _tr_13620_o
{
    char  nxtBtnSz  [ 2];    /* 연속값길이   */
    char  nxtKey    [50];    /* 연속키값     */
    char        gr_cnt[4];                  /* Grid count           */
    char        gr_bjlen[2];                /* Grid Bojo Data Length*/
    char        gr_bjdata[5];               /* Grid Bojo Data       */
    char	    gr_DATA[1];		              // 사이즈만큼 알아서..
} TR_13620_O;


class CTR_13620_G
{
public: //Variable
//    DEFINE_DRDS_LINE0(
	CString  m_szjuno;     	 /* 주문번호  */
	CString  m_szjgcode;     /* 종목코드  */
	CString  m_szjugb;   	 /* 주문구분	*/
	CString  m_szjuprc;      /* 주문단가 	*/
	CString  m_szjuqty;    	 /* 주문수량 	*/
	CString  m_sznonqty;     /* 미체결 		*/
	CString  m_szwonjuno;  	 /* 원주문번호*/
	CString  m_szjutype;     /* 매매구분 	*/

public:
	CTR_13620_G()
	{
	}

	virtual void  Convert(TR_13620_G* pInput)
	{		
		CString sTemp1;
		char sTmp[20+1];

		DATA_MEMCOPY(sTmp, pInput, juno		);   	/* 주문번호   */
		DATA_MEMCOPY(sTmp, pInput, jgcode	);   	/* 종목코드   */
		DATA_MEMCOPY(sTmp, pInput, jugb		);   	/* 주문구분	  */
  		DATA_MEMCOPY(sTmp, pInput, juprc	);   	/* 주문단가   */
		DATA_MEMCOPY(sTmp, pInput, juqty	);   	/* 주문수량   */
		DATA_MEMCOPY(sTmp, pInput, nonqty	);   	/* 미체결 	  */
		DATA_MEMCOPY(sTmp, pInput, wonjuno  ); 	    /* 원주문번호	*/
		DATA_MEMCOPY(sTmp, pInput, jutype	);   	/* 주문유형 	*/
	}
};

typedef CList<CTR_13620_G*, CTR_13620_G*> LIST_TR_13620_G;


class CTR_13620_O
{
public:
    CString m_szgr_cnt;                  /* Grid count           */
    CString m_szgr_bjlen;                /* Grid Bojo Data Length*/
    CString m_szgr_bjdata;               /* Grid Bojo Data       */

  	int m_ngr_cnt;                  /* Grid count           */
    int m_ngr_bjlen;                /* Grid Bojo Data Length*/
    int m_ngr_bjdata;               /* Grid Bojo Data       */

	CString m_sznxtKey ;

	CString m_szNextFlag ;
	CString m_szNextVal ;

	LIST_TR_13620_G m_DataList;

public:
	CTR_13620_O()
	{
		ResetAll();
	}

	~CTR_13620_O()
	{
		ResetAll();
	}

	virtual void  Convert(TR_13620_O* pInput)
	{		
		char sTmp[5+1]={0,};

		//20130814 EUNSOOK >>
		char sTmpNxt[50+1]={0,};
		DATA_MEMCOPY(sTmpNxt, pInput, nxtKey);   	/* Next key   */
		m_szNextFlag = m_sznxtKey.Mid(m_sznxtKey.Find("EN=") + 3, 1) ;				
		m_szNextVal = m_sznxtKey.Mid(m_sznxtKey.Find("DT=") + 3, 9) ;
		//20130814 EUNSOOK <<

    	DATA_MEMCOPY(sTmp, pInput, gr_cnt);         /* Grid count           */
    	DATA_MEMCOPY(sTmp, pInput, gr_bjlen);       /* Grid Bojo Data Length*/
    	DATA_MEMCOPY(sTmp, pInput, gr_bjdata);      /* Grid Bojo Data       */

    	DATA_CONVERT_int_0(gr_cnt);					/* Grid count           */
    	DATA_CONVERT_int_0(gr_bjlen);               /* Grid Bojo Data Length*/
    	DATA_CONVERT_int_0(gr_bjdata);              /* Grid Bojo Data       */

		CTR_13620_G *pNewItem=NULL;
		TR_13620_G *pData=NULL;
		CString sTemp1, sTemp2;
		for(int i=0; i < m_ngr_cnt; i++)
		{
			pData = (TR_13620_G*)&pInput->gr_DATA[i*sizeof(TR_13620_G)];
			pNewItem = new CTR_13620_G;
			pNewItem->Convert(pData);
			m_DataList.AddTail(pNewItem);
		}
	}

	virtual void  ClearList()
	{
		for(POSITION pos=m_DataList.GetHeadPosition(); pos; )
		{
			CTR_13620_G* pItem = m_DataList.GetNext(pos);
			if(pItem) delete pItem;
		}
		m_DataList.RemoveAll();
	}

	void ResetAll()
	{
		m_ngr_cnt = 0;
		m_ngr_bjlen = 0;
		m_ngr_bjdata= 0;

		m_szNextFlag ="";
		m_szNextVal ="";

		ClearList();
	}
	
	

};

class CTR_13620_I
{
public:
	CString geja;
	CString	jgcode;
	CString	strTemp;

public:
	CTR_13620_I(TR_13620_I* pIn, LPCTSTR lpstrgeja, LPCTSTR lpstrjgcode, char csgb, char csort)
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
	CTR_13620_I()
	{
		geja	= "";
		jgcode	= "";
	}
};

#endif //AFX_TR_13620_HEADER_

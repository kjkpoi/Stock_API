#if !defined(AFX_XF2_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_XF2_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


#include "../include/Data_Common.h"

/****** 선물옵션주문체결 Real (XF2) *********************************/
/****** SVR : 선물옵션주문체결 Real(HTS)  ***************************/
/********************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0( "userid",                         userid,       char,  20)
} DRDS_XF2_KEY;

typedef struct {
	DEFINE_DRDS_LINE0( "userid",                         userid,       char,  20)
	DEFINE_DRDS_LINE0( "지점번호:KEY",                   jijum,        char,   3)
	DEFINE_DRDS_LINE0( "계좌번호:KEY",                   geja,         char,  17) //8->17
	DEFINE_DRDS_LINE0( "주문번호:KEY",                   juno,         char,   9) //7->9
	DEFINE_DRDS_LINE0( "종목명(미사용)",                 jgname,       char,  20)
	DEFINE_DRDS_LINE0( "원주문번호",                     wonjuno,      char,   9) //7->9
	DEFINE_DRDS_LINE0( "종목코드",                       jgcode,       char,  15)
	DEFINE_DRDS_LINE0( "주문구분",                       jugb,         char,   3)
	DEFINE_DRDS_LINE0( "매매구분",                       mmgb,         char,   2)
	DEFINE_DRDS_LINE0( "호가주문부호(미사용)",           singb,        char,   2)
	DEFINE_DRDS_LINE0( "주문수탁방법",                   comgb,        char,   2)
	DEFINE_DRDS_LINE0( "예약구분(지점:0)",               yegb,         char,   1)
	DEFINE_DRDS_LINE0( "메세지코드(최종 부적격사유)",    msgcode,      char,   4)
	DEFINE_DRDS_LINE0( "주문수량",                       juqty,        char,  15) //7->15
	DEFINE_DRDS_LINE0( "주문단가",                       juprc,        char,  12) //9->12
	DEFINE_DRDS_LINE0( "체결수량",                       cheqty,       char,  15) //7->15
	DEFINE_DRDS_LINE0( "누적체결수량",                   cheqtyall,    char,  15) //7->15
	DEFINE_DRDS_LINE0( "체결단가",                       cheprc,       char,  12) //9->12
	DEFINE_DRDS_LINE0( "최근월물약정가new",              cheprc1,      char,  12) //9->12
	DEFINE_DRDS_LINE0( "차근월물약정가new",              cheprc2,      char,  12) //9->12
	DEFINE_DRDS_LINE0( "미체결수량",                     nonqty,       char,  15) //7->15
	DEFINE_DRDS_LINE0( "체결금액",                       cheamt,       char,  15) 
	DEFINE_DRDS_LINE0( "termid",                         termid,       char,   2)
	DEFINE_DRDS_LINE0( "계좌명(미사용)",                 gejaname,     char,  12)
	DEFINE_DRDS_LINE0( "거부코드",                       denycode,     char,   3)
	DEFINE_DRDS_LINE0( "거부사유",                       denymsg,      char,  40)
} DRDS_XF2_DATA;


class CDRDS_XF2_DATA
{
public: //Variable
	CString m_szuserid;				/* "userid"				*/
	CString m_szjijum;				/* "지점번호:KEY"		*/
	CString m_szgeja;				/* "계좌번호:KEY"		*/
	CString m_szjuno;				/* "주문번호:KEY"		*/
	CString m_szjgname;				/* "종목명(미사용)"		*/
	CString m_szwonjuno;			/* "원주문번호"			*/
	CString m_szjgcode;				/* "종목코드"			*/
	CString m_szjugb;				/* "주문구분"			*/
	CString m_szmmgb;				/* "매매구분"			*/
	CString m_szsingb;				/* "호가주문부호(미사용)"			*/
	CString m_szcomgb;				/* "주문수탁방법"					*/
	CString m_szyegb;				/* "예약구분(지점:0)"				*/
	CString m_szmsgcode;			/* "메세지코드(최종 부적격사유)"	*/
	CString m_szjuqty;				/* "주문수량"			*/
	CString m_szjuprc;				/* "주문단가"			*/
	CString m_szcheqty;				/* "체결수량"			*/
	CString m_szcheqtyall;			/* "누적체결수량"		*/
	CString m_szcheprc;				/* "체결단가"			*/
	CString m_szcheprc1;			/* "최근월물약정가new"	*/
	CString m_szcheprc2;			/* "차근월물약정가new"	*/
	CString m_sznonqty;				/* "미체결수량"			*/
	CString m_szcheamt;				/* "체결금액"			*/
	CString m_sztermid;				/* "termid"				*/
	CString m_szgejaname;			/* "계좌명(미사용)"		*/
	CString m_szdenycode;			/* "거부코드"			*/
	CString m_szdenymsg;			/* "거부사유"			*/

	int		m_njuqty;				/* "주문수량"			*/
	int		m_ncheqty;				/* "체결수량"			*/
	int		m_nnonqty;				/* "미체결수량"			*/
	
public:
	CDRDS_XF2_DATA()
	{
	}

	virtual void  Convert(DRDS_XF2_DATA* pInput)
	{
		CString sTemp1 ;
		char sTmp[40+1];

		DATA_MEMCOPY(sTmp, pInput, userid);				/* "userid"		*/
		DATA_MEMCOPY(sTmp, pInput, jijum);				/* "지점번호:KEY"		*/
		DATA_MEMCOPY(sTmp, pInput, geja);				/* "계좌번호:KEY"		*/
		DATA_MEMCOPY(sTmp, pInput, juno);				/* "주문번호:KEY"		*/
		DATA_MEMCOPY(sTmp, pInput, jgname);				/* "종목명(미사용)"		*/
		DATA_MEMCOPY(sTmp, pInput, wonjuno);			/* "원주문번호"		*/
		DATA_MEMCOPY(sTmp, pInput, jgcode);				/* "종목코드"		*/
		DATA_MEMCOPY(sTmp, pInput, jugb);				/* "주문구분"		*/
		DATA_MEMCOPY(sTmp, pInput, mmgb);				/* "매매구분"		*/
		DATA_MEMCOPY(sTmp, pInput, singb);				/* "호가주문부호(미사용)"		*/
		DATA_MEMCOPY(sTmp, pInput, comgb);				/* "주문수탁방법"		*/
		DATA_MEMCOPY(sTmp, pInput, yegb);				/* "예약구분(지점:0)"		*/
		DATA_MEMCOPY(sTmp, pInput, msgcode);			/* "메세지코드(최종 부적격사유)"		*/
		DATA_MEMCOPY(sTmp, pInput, juqty);				/* "주문수량"		*/
		DATA_MEMCOPY(sTmp, pInput, juprc);				/* "주문단가"		*/
		DATA_MEMCOPY(sTmp, pInput, cheqty);				/* "체결수량"		*/
		DATA_MEMCOPY(sTmp, pInput, cheqtyall);			/* "누적체결수량"		*/
		DATA_MEMCOPY(sTmp, pInput, cheprc);				/* "체결단가"		*/
		DATA_MEMCOPY(sTmp, pInput, cheprc1);			/* "최근월물약정가new"		*/
		DATA_MEMCOPY(sTmp, pInput, cheprc2);			/* "차근월물약정가new"		*/
		DATA_MEMCOPY(sTmp, pInput, nonqty);				/* "미체결수량"		*/
		DATA_MEMCOPY(sTmp, pInput, cheamt);				/* "체결금액"		*/
		DATA_MEMCOPY(sTmp, pInput, termid);				/* "termid"		*/
		DATA_MEMCOPY(sTmp, pInput, gejaname);			/* "계좌명(미사용)"		*/
		DATA_MEMCOPY(sTmp, pInput, denycode);			/* "거부코드"		*/
		DATA_MEMCOPY(sTmp, pInput, denymsg);			/* "거부사유"		*/

		DATA_CONVERT_int_0(juqty);		/* "주문수량"	*/
		DATA_CONVERT_int_0(cheqty);		/* "체결수량"	*/
		DATA_CONVERT_int_0(nonqty);		/* "미체결수량"	*/
	}
};

#endif // AFX_XF2_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


#if !defined(AFX_XX1_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_XX1_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


#include "../include/Data_Common.h"

/****** 주문체결 MASTER (XX1) ***************************************/
/****** SVR : 주문체결 MASTER       *********************************/
/********************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0("userid",                         userid,       char,  20)
} DRDS_XX1_KEY;

// 20071031 권휘영 [1] >> 
typedef struct {
	DEFINE_DRDS_LINE0("userid",                         userid,       char,  20)
	DEFINE_DRDS_LINE0("지점번호",                       jijum,        char,   3)
	DEFINE_DRDS_LINE0("계좌번호",                       geja,         char,  17) //8->17
	DEFINE_DRDS_LINE0("주문번호",                       juno,         char,   9) //5->9
	DEFINE_DRDS_LINE0("종목명",                         jgname,       char,  20)
	DEFINE_DRDS_LINE0("원주문번호",                     wonjuno,      char,   9) //5->9
	DEFINE_DRDS_LINE0("종목코드",                       jgcode,       char,  12)
	DEFINE_DRDS_LINE0("주문구분",                       jugb,         char,   3)
	DEFINE_DRDS_LINE0("매매구분",                       mmgb,         char,   2)
	DEFINE_DRDS_LINE0("신용구분",                       singb,        char,   3)
	DEFINE_DRDS_LINE0("통신구분",                       comgb,        char,   2)
	DEFINE_DRDS_LINE0("예약구분",                       yegb,         char,   1)
	DEFINE_DRDS_LINE0("메세지코드",                     msgcode,      char,   4)
	DEFINE_DRDS_LINE0("주문수량",                       juqty,        char,  15) //9->15
	DEFINE_DRDS_LINE0("주문단가",                       juprc,        char,   9) 
	DEFINE_DRDS_LINE0("체결수량",                       cheqty,       char,  15) //9->15
	DEFINE_DRDS_LINE0("체결단가",                       cheprc,       char,   9) 
	DEFINE_DRDS_LINE0("미체결수량",                     nonqty,       char,  15) //9->15
	DEFINE_DRDS_LINE0("체결금액",                       cheamt,       char,  15) //12->15
	DEFINE_DRDS_LINE0("TermId",                         termid,       char,   3) //2->3
	DEFINE_DRDS_LINE0("계좌명",                         gejaname,     char,  12)
    DEFINE_DRDS_LINE0("체결수량",                       wocheqty,     char,  15) /*추가200712*/
	DEFINE_DRDS_LINE0("체결단가",                       wocheprc,     char,   9) /*추가200712*/
} DRDS_XX1_DATA;



class CDRDS_XX1_DATA
{
public: //Variable
	CString m_szuserid;			/*  "userid",     */
	CString m_szjijum;			/*  "지점번호",   */
	CString m_szgeja;			/*  "계좌번호",   */
	CString m_szjuno;			/*  "주문번호",   */
	CString m_szjgname;			/*  "종목명",     */
	CString m_szwonjuno;		/*  "원주문번호", */
	CString m_szjgcode;			/*  "종목코드",   */
	CString m_szjugb;			/*  "주문구분",   */
	CString m_szmmgb;			/*  "매매구분",   */
	CString m_szsingb;			/*  "신용구분",   */
	CString m_szcomgb;			/*  "통신구분",   */
	CString m_szyegb;			/*  "예약구분",   */
	CString m_szmsgcode;		/*  "메세지코드", */
	CString m_szjuqty;			/*  "주문수량",   */
	CString m_szjuprc;			/*  "주문단가",   */
	CString m_szcheqty;			/*  "체결수량",   */
	CString m_szcheprc;			/*  "체결단가",   */
	CString m_sznonqty;			/*  "미체결수량", */
	CString m_szcheamt;			/*  "체결금액",   */
	CString m_sztermid;			/*  "TermId",     */
	CString m_szgejaname;		/*  "계좌명",     */
	CString m_szwocheqty;		/*  "체결수량",   */
	CString m_szwocheprc;		/*  "체결단가",   */

public:
	CDRDS_XX1_DATA()
	{
	}

	virtual void  Convert(DRDS_XX1_DATA* pInput)
	{
	
		CString sTemp1 ;
		char sTmp[20+1];

		DATA_MEMCOPY(sTmp, pInput, userid);			/*  "userid",     */
		DATA_MEMCOPY(sTmp, pInput, jijum);			/*  "지점번호",   */
		DATA_MEMCOPY(sTmp, pInput, geja);			/*  "계좌번호",   */
		DATA_MEMCOPY(sTmp, pInput, juno);			/*  "주문번호",   */
		DATA_MEMCOPY(sTmp, pInput, jgname);			/*  "종목명",     */
		DATA_MEMCOPY(sTmp, pInput, wonjuno);		/*  "원주문번호", */
		DATA_MEMCOPY(sTmp, pInput, jgcode);			/*  "종목코드",   */
		DATA_MEMCOPY(sTmp, pInput, jugb);			/*  "주문구분",   */
		DATA_MEMCOPY(sTmp, pInput, mmgb);			/*  "매매구분",   */
		DATA_MEMCOPY(sTmp, pInput, singb);			/*  "신용구분",   */
		DATA_MEMCOPY(sTmp, pInput, comgb);			/*  "통신구분",   */
		DATA_MEMCOPY(sTmp, pInput, yegb);			/*  "예약구분",   */
		DATA_MEMCOPY(sTmp, pInput, msgcode);		/*  "메세지코드", */
		DATA_MEMCOPY(sTmp, pInput, juqty);			/*  "주문수량",   */
		DATA_MEMCOPY(sTmp, pInput, juprc);			/*  "주문단가",   */
		DATA_MEMCOPY(sTmp, pInput, cheqty);			/*  "체결수량",   */
		DATA_MEMCOPY(sTmp, pInput, cheprc);			/*  "체결단가",   */
		DATA_MEMCOPY(sTmp, pInput, nonqty);			/*  "미체결수량", */
		DATA_MEMCOPY(sTmp, pInput, cheamt);			/*  "체결금액",   */
		DATA_MEMCOPY(sTmp, pInput, termid);			/*  "TermId",     */
		DATA_MEMCOPY(sTmp, pInput, gejaname);		/*  "계좌명",     */
		DATA_MEMCOPY(sTmp, pInput, wocheqty);		/*  "체결수량",   */
		DATA_MEMCOPY(sTmp, pInput, wocheprc);		/*  "체결단가",   */
	}
};

#endif // AFX_XX1_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_




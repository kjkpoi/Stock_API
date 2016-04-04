#if !defined(AFX_XX9_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_XX9_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


#include "../include/Data_Common.h"

/****** �ǽð� �ܰ� (XX9) ***************************************/
/****** SVR : �ǽð� �ܰ�(�ſ�����)******************************/
/****************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0("userid",                         userid,       char,  20)
} DRDS_XX9_KEY;


typedef struct {
	DEFINE_DRDS_LINE0("userid",                         userid,       char,  20)
	DEFINE_DRDS_LINE0("������ȣ",                       jijum,        char,   3)
	DEFINE_DRDS_LINE0("���¹�ȣ",                       geja,         char,  17) //8->17
	DEFINE_DRDS_LINE0("�����ڵ�",                       jgcode,       char,  12) //6->12
	DEFINE_DRDS_LINE0("�����",                         jgname,       char,  14)
	DEFINE_DRDS_LINE0("���ϸż��ݾ�",                   buyamt,       char,  15) //12->15
	DEFINE_DRDS_LINE0("���ϸŵ��ݾ�",                   sellamt,      char,  15) //12->15
	DEFINE_DRDS_LINE0("���ϸŵ�����ݾ�",               arngamt,      char,  15) //12->15
	DEFINE_DRDS_LINE0("��μ���",                       bookqty,      char,  15) //9->15
	DEFINE_DRDS_LINE0("��δܰ�",                       bookprc,      char,  15) //7->15
	DEFINE_DRDS_LINE0("�򰡱ݾ�",                       evamt,        char,  15) //12->15
	DEFINE_DRDS_LINE0("�򰡼���",                       evpl,         char,  15) //12->15
	DEFINE_DRDS_LINE0("���Ϻ�������",                   tdchngqty,    char,  15) //9->15
	DEFINE_DRDS_LINE0("���簡",                         close,        char,   7)
	DEFINE_DRDS_LINE0("�ż�ȣ��",                       bid,          char,   7)
	DEFINE_DRDS_LINE0("�ŵ�ȣ��",                       offer,        char,   7)
	DEFINE_DRDS_LINE0("���Ѱ�",                         hilimit,      char,   7)
	DEFINE_DRDS_LINE0("���Ѱ�",                         lolimit,      char,   7)
	DEFINE_DRDS_LINE0("����Ҽӱ���",                   mrktblngtp,   char,   1)
	DEFINE_DRDS_LINE0("���Ͻ�������",                   tdpl,         char,  15)
	DEFINE_DRDS_LINE0("�����",                         tax,          char,   9)
	DEFINE_DRDS_LINE0("������",                         suikrate,     char,   7)
	DEFINE_DRDS_LINE0("������",                         daechul,      char,   8)
	DEFINE_DRDS_LINE0("�ſ�ݾ�",                       sinamt,       char,  12)
	DEFINE_DRDS_LINE0("���ű���",                       bocash,       char,   4)
	DEFINE_DRDS_LINE0("������",                         mangiil,      char,   8)
	DEFINE_DRDS_LINE0("�ܰ���",                       jangogb,      char,   3) //2->3
	DEFINE_DRDS_LINE0("�ŵ����ɼ���",                   possqty,      char,  15) 


	DEFINE_DRDS_LINE0("�ֹ�����",                       jugb,	  char,   3)
	DEFINE_DRDS_LINE0("ü�����",                       wocheqty,	  char,   15)
	DEFINE_DRDS_LINE0("ü��ܰ�",                       wocheprc,     char,   9) //2->3
	DEFINE_DRDS_LINE0("��ü����",						comgb,        char,   2) 
	
	DEFINE_DRDS_LINE0("�����ȣ",                       sign,		  char,  1)
	DEFINE_DRDS_LINE0("���ϴ��",                       change,       char,  7)
	DEFINE_DRDS_LINE0("�����",							chgrate,      char,  7)	
	DEFINE_DRDS_LINE0("�����ܰ�",						qntyrest,      char,  15)	
	DEFINE_DRDS_LINE0("filler",							filler,       char,   20)
	

} DRDS_XX9_DATA;


class CDRDS_XX9_DATA
{
public: //Variable

	CString m_szuserid;				/*  "userid",			*/ 
	CString m_szjijum;				/*  "������ȣ"			*/
	CString m_szgeja;				/*  "���¹�ȣ"			*/
	CString m_szjgcode;				/*  "�����ڵ�"			*/
	CString m_szjgname;				/*  "�����"			*/
	CString m_szbuyamt;				/*  "���ϸż��ݾ�"		*/
	CString m_szsellamt;			/*  "���ϸŵ��ݾ�"		*/
	CString m_szarngamt;			/*  "���ϸŵ�����ݾ�"	*/
	CString m_szbookqty;			/*  "��μ���"			*/
	CString m_szbookprc;			/*  "��δܰ�"			*/
	CString m_szevamt;				/*  "�򰡱ݾ�"			*/
	CString m_szevpl;				/*  "�򰡼���"			*/
	CString m_sztdchngqty;			/*  "���Ϻ�������"		*/
	CString m_szclose;				/*  "���簡"			*/
	CString m_szbid;				/*  "�ż�ȣ��"			*/
	CString m_szoffer;				/*  "�ŵ�ȣ��"			*/
	CString m_szhilimit;			/*  "���Ѱ�"			*/
	CString m_szlolimit;			/*  "���Ѱ�"			*/
	CString m_szmrktblngtp;			/*  "����Ҽӱ���"		*/
	CString m_sztdpl;				/*  "���Ͻ�������"		*/
	CString m_sztax;				/*  "�����"			*/
	CString m_szsuikrate;			/*  "������"			*/
	CString	m_szdaechul;			/*  "������"			*/
	CString m_szsinamt;				/*  "�ſ�ݾ�"			*/
	CString m_szbocash;				/*  "���ű���"			*/
	CString m_szmangiil;			/*  "������"			*/
	CString m_szjangogb;			/*  "�ܰ���"          */
	CString m_szpossqty;			/*	�ŵ����ɼ���		*/

    CString m_szjugb;				/*	"�ֹ�����"			*/
	CString m_szwocheqty;			/*	"ü�����"			*/
	CString m_szwocheprc;			/*	"ü��ܰ�"			*/
	CString m_szcomgb;				/*	"��ü����"			*/
	CString m_szsign;				/*	"�����ȣ"			*/
	CString m_szchange;				/*	"���ϴ��"			*/
	CString m_szchgrate;			/*	"�����"			*/	
	CString m_szqntyrest;			/*   �����ܰ�			*/	
	CString m_szfiller;				/*	"filler"			*/

public:
	CDRDS_XX9_DATA()
	{
	}

	virtual void  Convert(DRDS_XX9_DATA* pInput)
	{
		CString sTemp1 ;		
		char sTmp[40+1];		
		DATA_MEMCOPY(sTmp, pInput, userid);				/*  "userid",			*/
		DATA_MEMCOPY(sTmp, pInput, jijum);				/*  "������ȣ"			*/
		DATA_MEMCOPY(sTmp, pInput, geja);				/*  "���¹�ȣ"			*/
		DATA_MEMCOPY(sTmp, pInput, jgcode);				/*  "�����ڵ�"			*/
		DATA_MEMCOPY(sTmp, pInput, jgname);				/*  "�����"			*/
		DATA_MEMCOPY(sTmp, pInput, buyamt);				/*  "���ϸż��ݾ�"		*/
		DATA_MEMCOPY(sTmp, pInput, sellamt);			/*  "���ϸŵ��ݾ�"		*/
		DATA_MEMCOPY(sTmp, pInput, arngamt);			/*  "���ϸŵ�����ݾ�"	*/
		DATA_MEMCOPY(sTmp, pInput, bookqty);			/*  "��μ���"			*/
		DATA_MEMCOPY(sTmp, pInput, bookprc);			/*  "��δܰ�"			*/
		DATA_MEMCOPY(sTmp, pInput, evamt);				/*  "�򰡱ݾ�"			*/
		DATA_MEMCOPY(sTmp, pInput, evpl);				/*  "�򰡼���"			*/
		DATA_MEMCOPY(sTmp, pInput, tdchngqty);			/*  "���Ϻ�������"		*/
		DATA_MEMCOPY(sTmp, pInput, close);				/*  "���簡"			*/
		DATA_MEMCOPY(sTmp, pInput, bid);				/*  "�ż�ȣ��"			*/
		DATA_MEMCOPY(sTmp, pInput, offer);				/*  "�ŵ�ȣ��"			*/
		DATA_MEMCOPY(sTmp, pInput, hilimit);			/*  "���Ѱ�"			*/
		DATA_MEMCOPY(sTmp, pInput, lolimit);			/*  "���Ѱ�"			*/
		DATA_MEMCOPY(sTmp, pInput, mrktblngtp);			/*  "����Ҽӱ���"		*/
		DATA_MEMCOPY(sTmp, pInput, tdpl);				/*  "���Ͻ�������"		*/
		DATA_MEMCOPY(sTmp, pInput, tax);				/*  "�����"			*/
		DATA_MEMCOPY(sTmp, pInput, suikrate);			/*  "������"			*/
		DATA_MEMCOPY(sTmp, pInput, daechul);			/*  "������"			*/
		DATA_MEMCOPY(sTmp, pInput, sinamt);				/*  "�ſ�ݾ�"			*/
		DATA_MEMCOPY(sTmp, pInput, bocash);				/*  "���ű���"			*/
		DATA_MEMCOPY(sTmp, pInput, mangiil);			/*  "������"			*/
		DATA_MEMCOPY(sTmp, pInput, jangogb);			/*  "�ܰ���"			*/
		DATA_MEMCOPY(sTmp, pInput, possqty);			/*  "�ŵ����ɼ���"		*/
		DATA_MEMCOPY(sTmp, pInput, jugb);				/*  "�ֹ�����"			*/
		DATA_MEMCOPY(sTmp, pInput, wocheqty);			/*  "ü�����"			*/
		DATA_MEMCOPY(sTmp, pInput, wocheprc);			/*  "ü��ܰ�"			*/
		DATA_MEMCOPY(sTmp, pInput, comgb);				/*  "��ü����"			*/
		DATA_MEMCOPY(sTmp, pInput, sign);				/*  "�����ȣ"			*/
		DATA_MEMCOPY(sTmp, pInput, change);				/*  "���ϴ��"			*/
		DATA_MEMCOPY(sTmp, pInput, chgrate);			/*  "�����"			*/
		DATA_MEMCOPY(sTmp, pInput, qntyrest);			/*  "�����ܰ�"			*/
		DATA_MEMCOPY(sTmp, pInput, filler);				/*  "filler"			*/
	}
};

#endif // AFX_XX9_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_




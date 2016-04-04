#if !defined(AFX_XX6_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_XX6_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


#include "../include/Data_Common.h"

/****** �ǽð� �ܰ� (XX6) ***************************************/
/****** SVR : �ǽð� �ܰ�       *********************************/
/****************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0("userid",                         userid,       char,  20)
} DRDS_XX6_KEY;

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
	DEFINE_DRDS_LINE0("���Ͻ�������",                   tdpl,         char,  15) //12->15
	DEFINE_DRDS_LINE0("�����",                         tax,          char,   9)
	DEFINE_DRDS_LINE0("������",                         suikrate,     char,   7)
	DEFINE_DRDS_LINE0("�ŵ����ɼ���",                   possqty,      char,   15) //20091110 ������ <<
} DRDS_XX6_DATA;



class CDRDS_XX6_DATA
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
	CString m_szpossqty;			/*	�ŵ����ɼ���		*/

public:
	CDRDS_XX6_DATA()
	{
	}

	virtual void  Convert(DRDS_XX6_DATA* pInput)
	{
		
		CString sTemp1 ;
		char sTmp[20+1];

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
		DATA_MEMCOPY(sTmp, pInput, possqty);			/*  "�ŵ����ɼ���"		*/
	}
};

#endif // AFX_XX6_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_




#if !defined(AFX_XF2_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_XF2_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


#include "../include/Data_Common.h"

/****** �����ɼ��ֹ�ü�� Real (XF2) *********************************/
/****** SVR : �����ɼ��ֹ�ü�� Real(HTS)  ***************************/
/********************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0( "userid",                         userid,       char,  20)
} DRDS_XF2_KEY;

typedef struct {
	DEFINE_DRDS_LINE0( "userid",                         userid,       char,  20)
	DEFINE_DRDS_LINE0( "������ȣ:KEY",                   jijum,        char,   3)
	DEFINE_DRDS_LINE0( "���¹�ȣ:KEY",                   geja,         char,  17) //8->17
	DEFINE_DRDS_LINE0( "�ֹ���ȣ:KEY",                   juno,         char,   9) //7->9
	DEFINE_DRDS_LINE0( "�����(�̻��)",                 jgname,       char,  20)
	DEFINE_DRDS_LINE0( "���ֹ���ȣ",                     wonjuno,      char,   9) //7->9
	DEFINE_DRDS_LINE0( "�����ڵ�",                       jgcode,       char,  15)
	DEFINE_DRDS_LINE0( "�ֹ�����",                       jugb,         char,   3)
	DEFINE_DRDS_LINE0( "�Ÿű���",                       mmgb,         char,   2)
	DEFINE_DRDS_LINE0( "ȣ���ֹ���ȣ(�̻��)",           singb,        char,   2)
	DEFINE_DRDS_LINE0( "�ֹ���Ź���",                   comgb,        char,   2)
	DEFINE_DRDS_LINE0( "���౸��(����:0)",               yegb,         char,   1)
	DEFINE_DRDS_LINE0( "�޼����ڵ�(���� �����ݻ���)",    msgcode,      char,   4)
	DEFINE_DRDS_LINE0( "�ֹ�����",                       juqty,        char,  15) //7->15
	DEFINE_DRDS_LINE0( "�ֹ��ܰ�",                       juprc,        char,  12) //9->12
	DEFINE_DRDS_LINE0( "ü�����",                       cheqty,       char,  15) //7->15
	DEFINE_DRDS_LINE0( "����ü�����",                   cheqtyall,    char,  15) //7->15
	DEFINE_DRDS_LINE0( "ü��ܰ�",                       cheprc,       char,  12) //9->12
	DEFINE_DRDS_LINE0( "�ֱٿ���������new",              cheprc1,      char,  12) //9->12
	DEFINE_DRDS_LINE0( "���ٿ���������new",              cheprc2,      char,  12) //9->12
	DEFINE_DRDS_LINE0( "��ü�����",                     nonqty,       char,  15) //7->15
	DEFINE_DRDS_LINE0( "ü��ݾ�",                       cheamt,       char,  15) 
	DEFINE_DRDS_LINE0( "termid",                         termid,       char,   2)
	DEFINE_DRDS_LINE0( "���¸�(�̻��)",                 gejaname,     char,  12)
	DEFINE_DRDS_LINE0( "�ź��ڵ�",                       denycode,     char,   3)
	DEFINE_DRDS_LINE0( "�źλ���",                       denymsg,      char,  40)
} DRDS_XF2_DATA;


class CDRDS_XF2_DATA
{
public: //Variable
	CString m_szuserid;				/* "userid"				*/
	CString m_szjijum;				/* "������ȣ:KEY"		*/
	CString m_szgeja;				/* "���¹�ȣ:KEY"		*/
	CString m_szjuno;				/* "�ֹ���ȣ:KEY"		*/
	CString m_szjgname;				/* "�����(�̻��)"		*/
	CString m_szwonjuno;			/* "���ֹ���ȣ"			*/
	CString m_szjgcode;				/* "�����ڵ�"			*/
	CString m_szjugb;				/* "�ֹ�����"			*/
	CString m_szmmgb;				/* "�Ÿű���"			*/
	CString m_szsingb;				/* "ȣ���ֹ���ȣ(�̻��)"			*/
	CString m_szcomgb;				/* "�ֹ���Ź���"					*/
	CString m_szyegb;				/* "���౸��(����:0)"				*/
	CString m_szmsgcode;			/* "�޼����ڵ�(���� �����ݻ���)"	*/
	CString m_szjuqty;				/* "�ֹ�����"			*/
	CString m_szjuprc;				/* "�ֹ��ܰ�"			*/
	CString m_szcheqty;				/* "ü�����"			*/
	CString m_szcheqtyall;			/* "����ü�����"		*/
	CString m_szcheprc;				/* "ü��ܰ�"			*/
	CString m_szcheprc1;			/* "�ֱٿ���������new"	*/
	CString m_szcheprc2;			/* "���ٿ���������new"	*/
	CString m_sznonqty;				/* "��ü�����"			*/
	CString m_szcheamt;				/* "ü��ݾ�"			*/
	CString m_sztermid;				/* "termid"				*/
	CString m_szgejaname;			/* "���¸�(�̻��)"		*/
	CString m_szdenycode;			/* "�ź��ڵ�"			*/
	CString m_szdenymsg;			/* "�źλ���"			*/

	int		m_njuqty;				/* "�ֹ�����"			*/
	int		m_ncheqty;				/* "ü�����"			*/
	int		m_nnonqty;				/* "��ü�����"			*/
	
public:
	CDRDS_XF2_DATA()
	{
	}

	virtual void  Convert(DRDS_XF2_DATA* pInput)
	{
		CString sTemp1 ;
		char sTmp[40+1];

		DATA_MEMCOPY(sTmp, pInput, userid);				/* "userid"		*/
		DATA_MEMCOPY(sTmp, pInput, jijum);				/* "������ȣ:KEY"		*/
		DATA_MEMCOPY(sTmp, pInput, geja);				/* "���¹�ȣ:KEY"		*/
		DATA_MEMCOPY(sTmp, pInput, juno);				/* "�ֹ���ȣ:KEY"		*/
		DATA_MEMCOPY(sTmp, pInput, jgname);				/* "�����(�̻��)"		*/
		DATA_MEMCOPY(sTmp, pInput, wonjuno);			/* "���ֹ���ȣ"		*/
		DATA_MEMCOPY(sTmp, pInput, jgcode);				/* "�����ڵ�"		*/
		DATA_MEMCOPY(sTmp, pInput, jugb);				/* "�ֹ�����"		*/
		DATA_MEMCOPY(sTmp, pInput, mmgb);				/* "�Ÿű���"		*/
		DATA_MEMCOPY(sTmp, pInput, singb);				/* "ȣ���ֹ���ȣ(�̻��)"		*/
		DATA_MEMCOPY(sTmp, pInput, comgb);				/* "�ֹ���Ź���"		*/
		DATA_MEMCOPY(sTmp, pInput, yegb);				/* "���౸��(����:0)"		*/
		DATA_MEMCOPY(sTmp, pInput, msgcode);			/* "�޼����ڵ�(���� �����ݻ���)"		*/
		DATA_MEMCOPY(sTmp, pInput, juqty);				/* "�ֹ�����"		*/
		DATA_MEMCOPY(sTmp, pInput, juprc);				/* "�ֹ��ܰ�"		*/
		DATA_MEMCOPY(sTmp, pInput, cheqty);				/* "ü�����"		*/
		DATA_MEMCOPY(sTmp, pInput, cheqtyall);			/* "����ü�����"		*/
		DATA_MEMCOPY(sTmp, pInput, cheprc);				/* "ü��ܰ�"		*/
		DATA_MEMCOPY(sTmp, pInput, cheprc1);			/* "�ֱٿ���������new"		*/
		DATA_MEMCOPY(sTmp, pInput, cheprc2);			/* "���ٿ���������new"		*/
		DATA_MEMCOPY(sTmp, pInput, nonqty);				/* "��ü�����"		*/
		DATA_MEMCOPY(sTmp, pInput, cheamt);				/* "ü��ݾ�"		*/
		DATA_MEMCOPY(sTmp, pInput, termid);				/* "termid"		*/
		DATA_MEMCOPY(sTmp, pInput, gejaname);			/* "���¸�(�̻��)"		*/
		DATA_MEMCOPY(sTmp, pInput, denycode);			/* "�ź��ڵ�"		*/
		DATA_MEMCOPY(sTmp, pInput, denymsg);			/* "�źλ���"		*/

		DATA_CONVERT_int_0(juqty);		/* "�ֹ�����"	*/
		DATA_CONVERT_int_0(cheqty);		/* "ü�����"	*/
		DATA_CONVERT_int_0(nonqty);		/* "��ü�����"	*/
	}
};

#endif // AFX_XF2_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


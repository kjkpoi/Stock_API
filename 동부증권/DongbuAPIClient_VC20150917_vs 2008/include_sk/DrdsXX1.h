#if !defined(AFX_XX1_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_XX1_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


#include "../include/Data_Common.h"

/****** �ֹ�ü�� MASTER (XX1) ***************************************/
/****** SVR : �ֹ�ü�� MASTER       *********************************/
/********************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0("userid",                         userid,       char,  20)
} DRDS_XX1_KEY;

// 20071031 ���ֿ� [1] >> 
typedef struct {
	DEFINE_DRDS_LINE0("userid",                         userid,       char,  20)
	DEFINE_DRDS_LINE0("������ȣ",                       jijum,        char,   3)
	DEFINE_DRDS_LINE0("���¹�ȣ",                       geja,         char,  17) //8->17
	DEFINE_DRDS_LINE0("�ֹ���ȣ",                       juno,         char,   9) //5->9
	DEFINE_DRDS_LINE0("�����",                         jgname,       char,  20)
	DEFINE_DRDS_LINE0("���ֹ���ȣ",                     wonjuno,      char,   9) //5->9
	DEFINE_DRDS_LINE0("�����ڵ�",                       jgcode,       char,  12)
	DEFINE_DRDS_LINE0("�ֹ�����",                       jugb,         char,   3)
	DEFINE_DRDS_LINE0("�Ÿű���",                       mmgb,         char,   2)
	DEFINE_DRDS_LINE0("�ſ뱸��",                       singb,        char,   3)
	DEFINE_DRDS_LINE0("��ű���",                       comgb,        char,   2)
	DEFINE_DRDS_LINE0("���౸��",                       yegb,         char,   1)
	DEFINE_DRDS_LINE0("�޼����ڵ�",                     msgcode,      char,   4)
	DEFINE_DRDS_LINE0("�ֹ�����",                       juqty,        char,  15) //9->15
	DEFINE_DRDS_LINE0("�ֹ��ܰ�",                       juprc,        char,   9) 
	DEFINE_DRDS_LINE0("ü�����",                       cheqty,       char,  15) //9->15
	DEFINE_DRDS_LINE0("ü��ܰ�",                       cheprc,       char,   9) 
	DEFINE_DRDS_LINE0("��ü�����",                     nonqty,       char,  15) //9->15
	DEFINE_DRDS_LINE0("ü��ݾ�",                       cheamt,       char,  15) //12->15
	DEFINE_DRDS_LINE0("TermId",                         termid,       char,   3) //2->3
	DEFINE_DRDS_LINE0("���¸�",                         gejaname,     char,  12)
    DEFINE_DRDS_LINE0("ü�����",                       wocheqty,     char,  15) /*�߰�200712*/
	DEFINE_DRDS_LINE0("ü��ܰ�",                       wocheprc,     char,   9) /*�߰�200712*/
} DRDS_XX1_DATA;



class CDRDS_XX1_DATA
{
public: //Variable
	CString m_szuserid;			/*  "userid",     */
	CString m_szjijum;			/*  "������ȣ",   */
	CString m_szgeja;			/*  "���¹�ȣ",   */
	CString m_szjuno;			/*  "�ֹ���ȣ",   */
	CString m_szjgname;			/*  "�����",     */
	CString m_szwonjuno;		/*  "���ֹ���ȣ", */
	CString m_szjgcode;			/*  "�����ڵ�",   */
	CString m_szjugb;			/*  "�ֹ�����",   */
	CString m_szmmgb;			/*  "�Ÿű���",   */
	CString m_szsingb;			/*  "�ſ뱸��",   */
	CString m_szcomgb;			/*  "��ű���",   */
	CString m_szyegb;			/*  "���౸��",   */
	CString m_szmsgcode;		/*  "�޼����ڵ�", */
	CString m_szjuqty;			/*  "�ֹ�����",   */
	CString m_szjuprc;			/*  "�ֹ��ܰ�",   */
	CString m_szcheqty;			/*  "ü�����",   */
	CString m_szcheprc;			/*  "ü��ܰ�",   */
	CString m_sznonqty;			/*  "��ü�����", */
	CString m_szcheamt;			/*  "ü��ݾ�",   */
	CString m_sztermid;			/*  "TermId",     */
	CString m_szgejaname;		/*  "���¸�",     */
	CString m_szwocheqty;		/*  "ü�����",   */
	CString m_szwocheprc;		/*  "ü��ܰ�",   */

public:
	CDRDS_XX1_DATA()
	{
	}

	virtual void  Convert(DRDS_XX1_DATA* pInput)
	{
	
		CString sTemp1 ;
		char sTmp[20+1];

		DATA_MEMCOPY(sTmp, pInput, userid);			/*  "userid",     */
		DATA_MEMCOPY(sTmp, pInput, jijum);			/*  "������ȣ",   */
		DATA_MEMCOPY(sTmp, pInput, geja);			/*  "���¹�ȣ",   */
		DATA_MEMCOPY(sTmp, pInput, juno);			/*  "�ֹ���ȣ",   */
		DATA_MEMCOPY(sTmp, pInput, jgname);			/*  "�����",     */
		DATA_MEMCOPY(sTmp, pInput, wonjuno);		/*  "���ֹ���ȣ", */
		DATA_MEMCOPY(sTmp, pInput, jgcode);			/*  "�����ڵ�",   */
		DATA_MEMCOPY(sTmp, pInput, jugb);			/*  "�ֹ�����",   */
		DATA_MEMCOPY(sTmp, pInput, mmgb);			/*  "�Ÿű���",   */
		DATA_MEMCOPY(sTmp, pInput, singb);			/*  "�ſ뱸��",   */
		DATA_MEMCOPY(sTmp, pInput, comgb);			/*  "��ű���",   */
		DATA_MEMCOPY(sTmp, pInput, yegb);			/*  "���౸��",   */
		DATA_MEMCOPY(sTmp, pInput, msgcode);		/*  "�޼����ڵ�", */
		DATA_MEMCOPY(sTmp, pInput, juqty);			/*  "�ֹ�����",   */
		DATA_MEMCOPY(sTmp, pInput, juprc);			/*  "�ֹ��ܰ�",   */
		DATA_MEMCOPY(sTmp, pInput, cheqty);			/*  "ü�����",   */
		DATA_MEMCOPY(sTmp, pInput, cheprc);			/*  "ü��ܰ�",   */
		DATA_MEMCOPY(sTmp, pInput, nonqty);			/*  "��ü�����", */
		DATA_MEMCOPY(sTmp, pInput, cheamt);			/*  "ü��ݾ�",   */
		DATA_MEMCOPY(sTmp, pInput, termid);			/*  "TermId",     */
		DATA_MEMCOPY(sTmp, pInput, gejaname);		/*  "���¸�",     */
		DATA_MEMCOPY(sTmp, pInput, wocheqty);		/*  "ü�����",   */
		DATA_MEMCOPY(sTmp, pInput, wocheprc);		/*  "ü��ܰ�",   */
	}
};

#endif // AFX_XX1_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_




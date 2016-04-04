#if !defined(AFX_XF6_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_XF6_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_

// #include "../CommonTR/DrdsXF6.h"
// �ۼ� : ������
// ���� : 2005.12.22(��)

#include "../include/Data_Common.h"

/****** CME���� �ܰ� (XF6) ********************************************/
/****** SVR : CME���� �ǽð��ܰ� Real(HTS)  ********************************/
/***************************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0( "userid",                         userid,       char,  20)
} DRDS_XF6_KEY;

// 20071113 ���ֿ� [1] >> �߰�
typedef struct {
	DEFINE_DRDS_LINE0( "userid",                         userid,       char,   20)                  
	DEFINE_DRDS_LINE0( "���¹�ȣ",                       acctno,       char,   20) //11->20
	DEFINE_DRDS_LINE0( "�����ȣ",                       itemno,       char,   15) //8->15
	DEFINE_DRDS_LINE0( "�������и�",                     postpnm,      char,   5)
	DEFINE_DRDS_LINE0( "��μ���",                       bookqty,      char,   15) //9->15
	DEFINE_DRDS_LINE0( "���Ϻ�������",                   tdchngqty,    char,   15) //9->15
	DEFINE_DRDS_LINE0( "���簡",                         close,        char,   15)  // 6=> 15
	DEFINE_DRDS_LINE0( "�ż�ȣ��",                       bid,          char,   15)  // 6=> 15
	DEFINE_DRDS_LINE0( "�ŵ�ȣ��",                       offer,        char,   15)  // 6=> 15
	DEFINE_DRDS_LINE0( "���Ѱ�",                         hilimit,      char,   15)  // 6=> 15
	DEFINE_DRDS_LINE0( "���Ѱ�",                         lolimit,      char,   15)  // 6=> 15
	DEFINE_DRDS_LINE0( "����Ҽӱ���",                   mrktblngtp,   char,   1)
	DEFINE_DRDS_LINE0( "���Դܰ�",                       bookprc,      char,   12)
	DEFINE_DRDS_LINE0( "���Աݾ�",                       bookamt,      char,   15)
	DEFINE_DRDS_LINE0( "���Ͻ�������",                   tdpl,         char,   15)
	DEFINE_DRDS_LINE0( "�ֹ�����üũ�ʵ�",               checkfld,     char,   3)
	DEFINE_DRDS_LINE0( "�ŷ�����",                       unit,         char,   19)  // 8->19
	DEFINE_DRDS_LINE0( "��ü���ֹ�����",                 nocontqty,    char,   15) //9->15
	DEFINE_DRDS_LINE0( "�űԸż��ݾ�",                   newbuyamt,    char,   15) //12->15
	DEFINE_DRDS_LINE0( "�űԸŵ��ݾ�",                   newsellamt,   char,   15) //12->15
	DEFINE_DRDS_LINE0( "ȯ�ż��ݾ�",                     rebuyamt,     char,   15) //12->15
	DEFINE_DRDS_LINE0( "���ŵ��ݾ�",                     resellamt,    char,   15) //12->15
	DEFINE_DRDS_LINE0( "��Ź����",                       yetakcash,    char,   15)
	DEFINE_DRDS_LINE0( "��Ź���",                       yetakdae,     char,   15)
	DEFINE_DRDS_LINE0( "�ֹ������Ѿ�",                   jumuntot,     char,   15)
	DEFINE_DRDS_LINE0( "�ֹ���������",                   jumuncash,    char,   15)
	DEFINE_DRDS_LINE0( "û�갡�ɼ���",                   avqty,        char,   15) //12->15
	DEFINE_DRDS_LINE0( "�ʷ�",							 filler,       char,   50)
	
} DRDS_XF6_DATA;
// 20071113 ���ֿ� << 

class CDRDS_XF6_DATA
{
public: //Variable

	CString m_szuserid;       // userid
	CString m_szacctno;       // ���¹�ȣ
	CString m_szitemno;       // �����ȣ
	CString m_szpostpnm;      // �������и�
	CString m_szbookqty;      // ��μ���
	CString m_sztdchngqty;    // ���Ϻ�������
	CString m_szclose;        // ���簡
	CString m_szbid;          // �ż�ȣ��
	CString m_szoffer;        // �ŵ�ȣ��
	CString m_szhilimit;      // ���Ѱ�
	CString m_szlolimit;      // ���Ѱ�
	CString m_szmrktblngtp;   // ����Ҽӱ���
	CString m_szbookprc;      // ���Դܰ�
	CString m_szbookamt;      // ���Աݾ�
	CString m_sztdpl;         // ���Ͻ�������
	CString m_szcheckfld;     // �ֹ�����üũ�ʵ�
	CString m_szunit;         // �ŷ�����
	CString m_sznocontqty;    // ��ü���ֹ�����
	CString m_sznewbuyamt;    // �űԸż��ݾ�
	CString m_sznewsellamt;   // �űԸŵ��ݾ�
	CString m_szrebuyamt;     // ȯ�ż��ݾ�
	CString m_szresellamt;    // ���ŵ��ݾ�
	CString m_szyetakcash;    // ��Ź����
	CString m_szyetakdae;     // ��Ź���
	CString m_szjumuntot;     // �ֹ������Ѿ�
	CString m_szjumuncash;    // �ֹ���������
	CString m_szavqty;        // û�갡�ɼ���

	int			m_nbookqty;		// ��μ���
	int			m_nbookprc;		// ���Դܰ�
	int			m_nclose;		// ���簡
	int			m_nnocontqty;   // ��ü���ֹ�����
	double		m_dtdpl;		// ���Ͻ������� (15�ڸ�)

public:
	CDRDS_XF6_DATA()
	{
	}

	virtual void  Convert(DRDS_XF6_DATA* pInput)
	{
		CString sTemp1 ;
		char sTmp[30+1];

		DATA_MEMCOPY(sTmp, pInput, userid);				// userid
		DATA_MEMCOPY(sTmp, pInput, acctno);				// ���¹�ȣ
		DATA_MEMCOPY(sTmp, pInput, itemno);				// �����ȣ
		DATA_MEMCOPY(sTmp, pInput, postpnm);			// �������и�
		DATA_MEMCOPY(sTmp, pInput, bookqty);			// ��μ���
		DATA_MEMCOPY(sTmp, pInput, tdchngqty);			// ���Ϻ�������
		DATA_MEMCOPY(sTmp, pInput, close);				// ���簡
		DATA_MEMCOPY(sTmp, pInput, bid);				// �ż�ȣ��
		DATA_MEMCOPY(sTmp, pInput, offer);				// �ŵ�ȣ��
		DATA_MEMCOPY(sTmp, pInput, hilimit);			// ���Ѱ�
		DATA_MEMCOPY(sTmp, pInput, lolimit);			// ���Ѱ�
		DATA_MEMCOPY(sTmp, pInput, mrktblngtp);			// ����Ҽӱ���
		DATA_MEMCOPY(sTmp, pInput, bookprc);			// ���Դܰ�
		DATA_MEMCOPY(sTmp, pInput, bookamt);			// ���Աݾ�
		DATA_MEMCOPY(sTmp, pInput, tdpl);				// ���Ͻ�������
		DATA_MEMCOPY(sTmp, pInput, checkfld);			// �ֹ�����üũ�ʵ�
		DATA_MEMCOPY(sTmp, pInput, unit);				// �ŷ�����
		DATA_MEMCOPY(sTmp, pInput, nocontqty);			// ��ü���ֹ�����
		DATA_MEMCOPY(sTmp, pInput, newbuyamt);			// �űԸż��ݾ�
		DATA_MEMCOPY(sTmp, pInput, newsellamt);			// �űԸŵ��ݾ�
		DATA_MEMCOPY(sTmp, pInput, rebuyamt);			// ȯ�ż��ݾ�
		DATA_MEMCOPY(sTmp, pInput, resellamt);			// ���ŵ��ݾ�
		DATA_MEMCOPY(sTmp, pInput, yetakcash);			// ��Ź����
		DATA_MEMCOPY(sTmp, pInput, yetakdae);			// ��Ź���
		DATA_MEMCOPY(sTmp, pInput, jumuntot);			// �ֹ������Ѿ�
		DATA_MEMCOPY(sTmp, pInput, jumuncash);			// �ֹ���������
		DATA_MEMCOPY(sTmp, pInput, avqty);				// û�갡�ɼ���

		DATA_CONVERT_int_0(bookqty);	// ��μ���
		DATA_CONVERT_int_0(bookprc);	// ���Դܰ�
		DATA_CONVERT_int_0(close);		// ���簡
		DATA_CONVERT_int_0(nocontqty);  // ��ü���ֹ�����
		DATA_CONVERT_float_0(tdpl);		// ���Ͻ������� 15�ڸ�
	}
};

#endif // AFX_XF6_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_



#if !defined(AFX_OH2_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_OH2_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_

// #include "../CommonTR/DrdsOH2.h"
#include "Data_Common.h"

// �ۼ� : ������
// ���� : 2006.02.17(��)

/****** �ɼ� ȣ�� (OH2) *********************************************/
/****** SVR : ���ɿ� �ɼ� ȣ�� **************************************/
/********************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0("�����ڵ�",		opitem,         char,   8)
} DRDS_OH2_KEY;

typedef struct {
	DEFINE_DRDS_LINE0("�����ڵ�",		opitem,         char,   8)
	DEFINE_DRDS_LINE0("ȣ�������ð�",		hokatime,       char,   6)
	DEFINE_DRDS_LINE0("�ŵ��켱ȣ��[9(3)v9(2)]",		offer,          char,   5)
	DEFINE_DRDS_LINE0("�ż��켱ȣ��[9(3)v9(2)]",		bid,            char,   5)
	DEFINE_DRDS_LINE0("�ŵ��ܷ�",		offerjan,       char,   6)
	DEFINE_DRDS_LINE0("�ż��ܷ�",		bidjan,         char,   6)
	DEFINE_DRDS_LINE0("�Ѹŵ�ȣ���ܷ�",		tofferjan,      char,   6)
	DEFINE_DRDS_LINE0("�Ѹż�ȣ���ܷ�",		tobidjan,       char,   6)
} DRDS_OH2_DATA;

#endif // AFX_OH2_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


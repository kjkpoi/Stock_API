#if !defined(AFX_SM0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_SM0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_

// #include "../CommonTR/Drds_SM0.h"
#include "Data_Common.h"

// �ۼ� : ���ؿ�
// ���� : 2005.11.23(��)

/***** ���� �̰�������(SM0) ****************************************/
/***** SVR : ���� �̰�������         *******************************/
/*******************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0("�����ڵ�",                       fucode,       char,   8)	
} DRDS_SM0_KEY;

typedef struct {
    DEFINE_DRDS_LINE0("�����ڵ�",                       fucode,       char,   8)
    DEFINE_DRDS_LINE0("�ð�",                           time,         char,   6)
    DEFINE_DRDS_LINE0("�̰�����������",                 qty,          char,   7)
    DEFINE_DRDS_LINE0("�̰���������������",             qty_chg,      char,   6)
} DRDS_SM0_DATA;

#endif // AFX_SM0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


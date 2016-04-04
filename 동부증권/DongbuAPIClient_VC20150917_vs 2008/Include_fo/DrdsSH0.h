#if !defined(AFX_SH0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_)
#define AFX_SH0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_

// #include "../CommonTR/Drds_SH0.h"
#include "../include/Data_Common.h"

// �ۼ� : ���ؿ�
// ���� : 2005.11.23(��)

/***** ���� ȣ�� (SH0) *********************************************/
/***** SVR : ���� ȣ�� *********************************************/
/*******************************************************************/

typedef struct 
{
	DEFINE_DRDS_LINE0( "�����ڵ�",                       code,         char,   6)	
} DRDS_SH0_KEY;

typedef struct {
	DEFINE_DRDS_LINE0("�����ڵ�",                       jmcode,       char,   8)
	DEFINE_DRDS_LINE0("����SEQ",                        jmcodeseq,    char,   2)
	DEFINE_DRDS_LINE0("�ŵ��켱ȣ��[9(4)v9(2)]",        offerho1,     char,   7)
	DEFINE_DRDS_LINE0("�ż��켱ȣ��[9(4)v9(2)]",        bidho1,       char,   7)
	DEFINE_DRDS_LINE0("�ŵ��ܷ�",                       offerrem1,    char,   6)
	DEFINE_DRDS_LINE0("�ż��ܷ�",                       bidrem1,      char,   6)
	DEFINE_DRDS_LINE0("�����ŵ�ȣ��[9(3)v9(2)]",        offerho2,     char,   7)
	DEFINE_DRDS_LINE0("�����ż�ȣ��[9(3)v9(2)]",        bidho2,       char,   7)
	DEFINE_DRDS_LINE0("�����ŵ�ȣ���ܷ�",               offerrem2,    char,   6)
	DEFINE_DRDS_LINE0("�����ż�ȣ���ܷ�",               bidrem2,      char,   6)
	DEFINE_DRDS_LINE0("�������ŵ�ȣ��[9(3)v9(2)]",      offerho3,     char,   7)
	DEFINE_DRDS_LINE0("�������ż�ȣ��[9(3)v9(2)]",      bidho3,       char,   7)
	DEFINE_DRDS_LINE0("�������ŵ�ȣ���ܷ�",             offerrem3,    char,   6)
	DEFINE_DRDS_LINE0("�������ż�ȣ���ܷ�",             bidrem3,      char,   6)
	DEFINE_DRDS_LINE0("�Ѹŵ�ȣ���ܷ�",                 offertotrem,  char,   6)
	DEFINE_DRDS_LINE0("�Ѹż�ȣ���ܷ�",                 bidtotrem,    char,   6)
	DEFINE_DRDS_LINE0("ȣ�������ð�",                   hotime,       char,   6)
	
	DEFINE_DRDS_LINE0("4�����ŵ�ȣ��",                  offerho4,     char,   7)
	DEFINE_DRDS_LINE0("4�����ż�ȣ��",                  bidho4,       char,   7)
	DEFINE_DRDS_LINE0("4�����ŵ��ܷ�",                  offerrem4,    char,   6)
	DEFINE_DRDS_LINE0("4�����ż��ܷ�",                  bidrem4,      char,   6)
	DEFINE_DRDS_LINE0("5�����ŵ�ȣ��",                  offerho5,     char,   7)
	DEFINE_DRDS_LINE0("5�����ż�ȣ��",                  bidho5,       char,   7)
	DEFINE_DRDS_LINE0("5�����ŵ��ܷ�",                  offerrem5,    char,   6)
	DEFINE_DRDS_LINE0("5�����ż��ܷ�",                  bidrem5,      char,   6)

	DEFINE_DRDS_LINE0("�켱�ŵ��Ǽ�",                   offercnt1,    char,   4)
	DEFINE_DRDS_LINE0("�����ŵ��Ǽ�",                   offercnt2,    char,   4)
	DEFINE_DRDS_LINE0("�������ŵ��Ǽ�",                 offercnt3,    char,   4)
	DEFINE_DRDS_LINE0("4�����ŵ��Ǽ�",                  offercnt4,    char,   4)
	DEFINE_DRDS_LINE0("5�����ŵ��Ǽ�",                  offercnt5,    char,   4)
	
	DEFINE_DRDS_LINE0("�Ѹŵ��Ǽ�",                     offertotcnt,  char,   5)

	DEFINE_DRDS_LINE0("�켱�ż��Ǽ�",                   bidcnt1,      char,   4)
	DEFINE_DRDS_LINE0("�����ż��Ǽ�",                   bidcnt2,      char,   4)
	DEFINE_DRDS_LINE0("�������ż��Ǽ�",                 bidcnt3,      char,   4)
	DEFINE_DRDS_LINE0("4�����ż��Ǽ�",                  bidcnt4,      char,   4)
	DEFINE_DRDS_LINE0("5�����ż��Ǽ�",                  bidcnt5,      char,   4)
	DEFINE_DRDS_LINE0("�� �ż� �Ǽ�",                   bidtotcnt,    char,   5)

	DEFINE_DRDS_LINE0("�ŵ�ȣ���Ǽ����1",              offcnt1_chg,  char,   4)
	DEFINE_DRDS_LINE0("�ŵ�ȣ���Ǽ����2",              offcnt2_chg,  char,   4)
	DEFINE_DRDS_LINE0("�ŵ�ȣ���Ǽ����3",              offcnt3_chg,  char,   4)
	DEFINE_DRDS_LINE0("�ŵ�ȣ���Ǽ����4",              offcnt4_chg,  char,   4)
	DEFINE_DRDS_LINE0("�ŵ�ȣ���Ǽ����5",              offcnt5_chg,  char,   4)
	DEFINE_DRDS_LINE0("�ż�ȣ���Ǽ����1",              bidcnt1_chg,  char,   4)
	DEFINE_DRDS_LINE0("�ż�ȣ���Ǽ����2",              bidcnt2_chg,  char,   4)
	DEFINE_DRDS_LINE0("�ż�ȣ���Ǽ����3",              bidcnt3_chg,  char,   4)
	DEFINE_DRDS_LINE0("�ż�ȣ���Ǽ����4",              bidcnt4_chg,  char,   4)
	DEFINE_DRDS_LINE0("�ż�ȣ���Ǽ����5",              bidcnt5_chg,  char,   4)

	DEFINE_DRDS_LINE0("ȣ�����ܷ� ����",                totrem_chg,   char,   7)
} DRDS_SH0_DATA;


// ���� ȣ�� SH0
typedef struct 
{
    char       fuitem       [8];		// �����ڵ�
    char       futseq       [2];		// ����SEQ
    char       offer        [7];		// �ŵ��켱ȣ��[9(3)v9(2)]
    char       bid          [7];		// �ż��켱ȣ��[9(3)v9(2)]
    char       offerjan     [6];		// �ŵ��ܷ�
    char       bidjan       [6];		// �ż��ܷ�

    char       joffer       [7];		// �����ŵ�ȣ��[9(3)v9(2)]
    char       jbid         [7];		// �����ż�ȣ��[9(3)v9(2)]
    char       jofferjan    [6];		// �����ŵ�ȣ���ܷ�
    char       jbidjan      [6];		// �����ż�ȣ���ܷ�

    char       jjoffer      [7];		// �������ŵ�ȣ��[9(3)v9(2)]
    char       jjbid        [7];		// �������ż�ȣ��[9(3)v9(2)]
    char       jjofferjan   [6];		// �������ŵ�ȣ���ܷ�
    char       jjbidjan     [6];		// �������ż�ȣ���ܷ�

    char       tofferjan    [6];		// �Ѹŵ�ȣ���ܷ�
    char       tobidjan     [6];		// �Ѹż�ȣ���ܷ�
	char       hotime       [6];		// ȣ�������ð�

    char       j4offer      [7];		// 4�����ŵ�ȣ��
    char       j4bid        [7];		// 4�����ż�ȣ��
    char       j4offerjan   [6];		// 4�����ŵ��ܷ�
    char       j4bidjan     [6];		// 4�����ż��ܷ�

    char       j5offer      [7];		// 5�����ŵ�ȣ��
    char       j5bid        [7];		// 5�����ż�ȣ��
    char       j5offerjan   [6];		// 5�����ŵ��ܷ�
    char       j5bidjan     [6];		// 5�����ż��ܷ�

    char       offersu      [4];		// �켱�ŵ��Ǽ�
    char       joffersu     [4];		// �����ŵ��Ǽ�
    char       jjoffersu    [4];		// �������ŵ��Ǽ�
    char       j4offersu    [4];		// 4�����ŵ��Ǽ�
    char       j5offersu    [4];		// 5�����ŵ��Ǽ�

    char       toffersu     [5];		// �Ѹŵ��Ǽ�
    char       bidsu        [4];		// �켱�ż��Ǽ�
    char       jbidsu       [4];		// �����ż��Ǽ�
    char       jjbidsu      [4];		// �������ż��Ǽ�
    char       j4bidsu      [4];		// 4�����ż��Ǽ�
    char       j5bidsu      [4];		// 5�����ż��Ǽ�
    char       tbidsu       [5];		// �� �ż� �Ǽ�

	char       offcnt1_chg  [4];			//�ŵ�ȣ���Ǽ����1
    char       offcnt2_chg  [4];			//�ŵ�ȣ���Ǽ����2,
    char       offcnt3_chg  [4];			//�ŵ�ȣ���Ǽ����3,
    char       offcnt4_chg  [4];         //�ŵ�ȣ���Ǽ����4,
    char       offcnt5_chg  [4];			//�ŵ�ȣ���Ǽ����5,	
    char       bidcnt1_chg  [4];			//�ŵ�ȣ���Ǽ����6,
    char       bidcnt2_chg  [4];			//�ŵ�ȣ���Ǽ����7,
    char       bidcnt3_chg  [4];			//�ŵ�ȣ���Ǽ����8,
    char       bidcnt4_chg  [4];			//�ŵ�ȣ���Ǽ����9,
    char       bidcnt5_chg  [4];			//�ŵ�ȣ���Ǽ����10,
    //char       soonmesu     [6];		// ���ż��ܷ�
} st_SH0;
#define st_SH0_Size		sizeof(st_SH0)


#endif // AFX_SH0_DRDSPACKET_BY_JUNOK_LEE_98B1A__INCLUDED_


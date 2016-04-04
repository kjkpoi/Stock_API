#if !defined(AFX_TR_10051_HEADER_)
#define AFX_TR_10051_HEADER_

// #include "../CommonTR/Tr10051.h"		// ��Ŷ : �ֽ�ȣ�� 



#define TR_10051	"10051"

//-------------------------------------------------------------------------------//
// ȣ��Ŭ���ֹ� - ȣ������         ���TR��ȣ:10051 
//--------------------------------[INPUT ]---------------------------------------//
typedef struct _tr_10051_I 
{
	char shcode[6];             /* �����ڵ�M */
} tr_10051_I;

//--------------------------------[OUTPUT ]---------------------------------------//
typedef struct _tr_10051_T {
	char hname[20];              /* �����(�ѱ�)M  */
	char tblcount1[4];           /* ���̺�ī��Ʈ  */
	char tblbojo1[20];           /* ���̺���  */ 
	char price[9];               /* ���簡9(9),��  */
	char sign[1];                /* �����ȣ  */
	char change[9];              /* �����9(6)  */
	char chgrate[10];            /* �����999.99  */
	char volume[10];             /* �����ŷ���9(9),��  */
	char value[12];				 /* �����ŷ����(12)	*/
	char tblcount2[4];           /* ���̺�ī��Ʈ  */
	char tblbojo2[20];           /* ���̺���  */
	char htime[6];               /* ȣ���ܷ����ؽð�HHMMSS  */
	char offerrem10[9];          /* �ŵ�10�����ܷ�9(8),��  */
	char offerho10[9];           /* �ŵ�10����ȣ��9(7)  */
	char preprice[9];            /* ��������9(10),��M  */
	char offerrem9[9];           /* �ŵ�9�����ܷ�9(8),��  */
	char offerho9[9];            /* �ŵ�9����ȣ��9(7)  */
	char prevol[10];             /* ���ϰŷ���9(9),��  */
	char offerrem8[9];           /* �ŵ�8�����ܷ�9(8),��  */
	char offerho8[9];            /* �ŵ�8����ȣ��9(7)  */
	// 20080618 �ڵ��� TR���� >>
	//char listing[10];            /* ����(Kospi)����(Kosdaq)�ֽļ�9listing  */
	char listing[12];            /* ����(Kospi)����(Kosdaq)�ֽļ�9listing  */
	// 20080618 �ڵ��� TR���� <<
	char offerrem7[9];           /* �ŵ�7�����ܷ�9(8),��  */
	char offerho7[9];            /* �ŵ�7����ȣ��9(7)  */
	char faceval[9];             /* �׸鰡9(9),��M  */
	char offerrem6[9];           /* �ŵ�6�켱�ܷ�9(8),��  */
	char offerho6[9];            /* �ŵ�6����ȣ��9(7)  */
	char perfull[9];             /* PER����9(3).99M  */
	char offerrem5[9];           /* �ŵ�5�����ܷ�9(8),��  */
	char offerho5[9];            /* �ŵ�5����ȣ��9(7)  */
	char offerrem4[9];           /* �ŵ�4�����ܷ�9(8),��  */
	char offerho4[9];            /* �ŵ�4����ȣ��9(7)  */
	char offerrem3[9];           /* �ŵ�3�����ܷ�9(8),��  */
	char offerho3[9];            /* �ŵ�3����ȣ��9(7)  */
	char offerrem2[9];           /* �ŵ�2�����ܷ�9(8),��  */
	char offerho2[9];            /* �ŵ�2����ȣ��9(7)  */
	char offerrem1[9];           /* �ŵ��ֿ켱�ܷ�9(8),��  */
	char offerho1[9];            /* �ŵ��ֿ켱ȣ��9(7)  */
	char bidho1[9];              /* �ż��ֿ켱ȣ��9(7)  */
	char bidrem1[9];             /* �ż��ֿ켱�ܷ�9(8),��  */
	char bidho2[9];              /* �ż�2����ȣ��9(7)  */
	char bidrem2[9];             /* �ż�2�����ܷ�9(8),��  */
	char bidho3[9];              /* �ż�3����ȣ��9(7)  */
	char bidrem3[9];             /* �ż�3�����ܷ�9(8),��  */
	char bidho4[9];              /* �ż�4����ȣ��9(7)  */
	char bidrem4[9];             /* �ż�4�����ܷ�9(8),��  */
	char bidho5[9];              /* �ż�5����ȣ��9(7)  */
	char bidrem5[9];             /* �ż�5�����ܷ�9(8),��  */
	char bidho6[9];              /* �ż�6�켱ȣ��9(7)  */
	char bidrem6[9];             /* �ż�6�켱�ܷ�9(8),��  */
	char bidho7[9];              /* �ż�7����ȣ��9(7)  */
	char bidrem7[9];             /* �ż�7�����ܷ�9(8),��  */
	char bidho8[9];              /* �ż�8����ȣ��9(7)  */
	char bidrem8[9];             /* �ż�8�����ܷ�9(8),��  */
	char bidho9[9];              /* �ż�9����ȣ��9(7)  */
	char bidrem9[9];             /* �ż�9�����ܷ�9(8),��  */
	char bidho10[9];             /* �ż�10����ȣ��9(7)  */
	char bidrem10[9];            /* �ż�10�����ܷ�9(8),��  */
	char offertotrem[9];         /* �Ѹŵ��ܷ�9(8),��  */
	char bidtotrem[9];           /* �Ѹż��ܷ�9(8),��  */
	char offerrem_ot[9];         /* �ð��ܸŵ��ܷ�9(8),��  */
	char bidrem_ot[9];           /* �ð��ܸż��ܷ�9(8),��  */
	char tblcount3[4];           /* ���̺�ī��Ʈ  */
	char tblbojo3[20];           /* ���̺���  */
	char hprice[9];              /* ���Ѱ�9(9),��M  */
	char high[9];                /* ��9(7),��  */
	char open[9];                /* �ð�9(7),��  */
	char low[9];                 /* ����9(7),��  */
	char lprice[9];              /* ���Ѱ�9(9),��M  */
} tr_10051_T;

typedef struct _tr_10051_U
{
	char	upcodesnm		[18];		/* �����ǼҼӾ�����(ex:��������,����)*/
	char	upjisu			[8];		/* ��������  		*/
	char	upsign			[ 1];		/* ���������ȣ 	*/
	char	upchange		[8];		/* �������Ϻ� 		*/
	char	uprate			[5];		/* ���������		*/
	char	mstbit			[12];		/* ��������(ex:kospi,kosdaq,..)*/
} tr_10051_U;

typedef struct _tr_10051_O
{
	char	 	shcode		[ 7];		/* �����ڵ�			*/
	char		under		[10];		/* ������			*/
	char		right		[10];		/* �ǹ�űԽ��ֱ���	*/
	char		badgb		[10];		/* �Ҽ��ǰ��ÿ���	*/
	char		upcode		[ 4];		/* �����ڵ�			*/
	char		baseprice	[ 9];		/* ���ذ�  			*/
	
	tr_10051_T	table;	
	
	char		utbl_bojo	[50];
	tr_10051_U	utbl;					/* �����ǼҼӾ���Table*/	
	
	char	etbl_bojo		[50];
	char	expprice		[ 9];		/*  ���� ü�ᰡ�� */
	char	expvol			[12];		/*  ���� ü����� */
} tr_10051_O;

#endif //AFX_TR_10051_HEADER_

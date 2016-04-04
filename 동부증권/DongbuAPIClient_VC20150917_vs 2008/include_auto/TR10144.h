// 20091103 ����ȯ >> �ű��߰�
#if !defined(AFX_TR_10144_HEADER_)
#define AFX_TR_10144_HEADER_

#define TR_10144	"10144"
//-------------------------------------------------------------------------------//
// �ſ�ŵ����ɼ�����ȸ         ���TR��ȣ:10144                                    //
//--------------------------------[INPUT ]---------------------------------------//

//--------------------------------[INPUT ]------------------------------------------//
typedef struct _TR10144_I
{
	char		acct	[20];   	/* ������ȣ(3)+���¹�ȣ(17) */
	char		passwd	[8];		/* ��й�ȣ					*/ 
	
	char		trdgb	[1];				/* �Ÿű��� : "1"�ŵ�, "2"�ż� */
	char		sinygb  [2];				/* ����󼼺з��ڵ� "01":��������, "03":�ڱ�����,"07":�ڱ���� */

	char		jcode	[6];		/* �����ڵ� (�����ȣ)			*/
    char		price	[15];			/* �ֹ���                   */
    char		lndate	[8];				/* ������ */
	char		ipaddr  [16];		            /* client ipaddr(199.99.9.90->199099009090) 			*/

} TR_10144_I;

//--------------------------------[OUTPUT ]-----------------------------------------//
typedef struct _TR10144_O
{
	char		price		[13];			/*�ֹ���*/
	char		maxqty	    [16];			/*�ֹ����ɼ���*/
	char		maxprice	[16];			/*�ֹ����ɱݾ�*/
} TR_10144_O; 

class CTR_10144_I
{
public:
	CString		acct;	// ���¹�ȣ
	CString		passwd;	// ��й�ȣ
	CString		trdgb;		// �Ÿű���
	CString		sinygb;		// �ſ뱸��(����󼼺з��ڵ�)

	CString		jcode;	// �����ȣ	
	CString		price;	// �ż������
	CString		lndate;	// ������
	CString     ipaddr; // client ipaddr(199.99.9.90->199099009090) 
public:
	CTR_10144_I()
	{
		acct = passwd = trdgb = sinygb = jcode = price = lndate = ipaddr = "";
	}
	CTR_10144_I(LPCTSTR lpstracct, LPCTSTR lpstrpasswd, LPCTSTR lpstrtrdgb, LPCTSTR lpstrsinygb, LPCTSTR lpstrjcode, LPCTSTR lpstrprice, LPCTSTR lpstrlndate, LPCTSTR lpstripaddr)
	{
		acct	= lpstracct;
		passwd	= lpstrpasswd;
		trdgb	= lpstrtrdgb;
		sinygb	= lpstrsinygb;
		jcode	= lpstrjcode;
		price		= lpstrprice;
		lndate	= lpstrlndate;
		ipaddr	= lpstripaddr;

	}
};
// Output
class CTR_10144_O
{
public:
	CString		price;			/*�ֹ���*/
	CString		maxprice;		/*�ֹ����ɱݾ�*/          		
	CString		maxqty;			/*�ֹ����ɼ���*/
	
public:
	CTR_10144_O()
	{
		price = maxprice = maxqty = "";
	}
	CTR_10144_O(LPVOID pData)
	{
		TR_10144_O* pTR = (TR_10144_O*)pData;
		price.Format("%*.*s"	, sizeof(pTR->price), sizeof(pTR->price), pTR->price);
		maxprice.Format("%*.*s"	, sizeof(pTR->maxprice), sizeof(pTR->maxprice), pTR->maxprice);
		maxqty.Format("%*.*s", sizeof(pTR->maxqty), sizeof(pTR->maxqty), pTR->maxqty);
		
		price.TrimLeft();	price.TrimRight();
		maxprice.TrimLeft();	maxprice.TrimRight();
		maxqty.TrimLeft();	maxqty.TrimRight();
	}
};


#endif //AFX_TR_10144_HEADER_

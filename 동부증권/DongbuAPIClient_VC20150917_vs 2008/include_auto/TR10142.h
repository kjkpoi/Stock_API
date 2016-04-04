// 20071211 ���ֿ� [1] >> �߰�
#if !defined(AFX_TR_10142_HEADER_)
#define AFX_TR_10142_HEADER_

#define TR_10142	"10142"
//-------------------------------------------------------------------------------//
// ���ǵ��ֹ�-��ü��         ���TR��ȣ:10142                                    //
//--------------------------------[INPUT ]---------------------------------------//

//--------------------------------[INPUT ]------------------------------------------//
typedef struct _TR10142_I
{
	char  acct		[20];   	/* ������ȣ(3)+���¹�ȣ(17) */
	char  passwd	[8];		/* ��й�ȣ					*/ 
	char  sinygb    [2];        /* "01":��������, "03":�ڱ�����,"07":�ڱ���� */
	char  jcode     [6];		/* �����ڵ�					*/
    char  price     [13];		/* �ֹ���                   */
    char  ipaddr    [16];		/* client ipaddr(199.99.9.90->199099009090) 			*/
} TR_10142_I;

//--------------------------------[OUTPUT ]-----------------------------------------//
typedef struct _TR10142_O
{
	char  maxprice  [16];					/*�ֹ����ɱݾ�*/
	char  maxqty    [16];					/*�ֹ����ɼ���*/
} TR_10142_O; 

class CTR_10142_I
{
public:
	CString		acct;	// ���¹�ȣ
	CString		passwd;	// ��й�ȣ
	CString		sinygb;		// �ſ뱸��

	CString		jcode;	// �����ȣ	
	CString		price;	// �ż������
	CString     ipaddr; // client ipaddr(199.99.9.90->199099009090) 
public:
	CTR_10142_I()
	{
		acct = passwd = sinygb = jcode = price = ipaddr = "";
	}
	CTR_10142_I(LPCTSTR lpstracct, LPCTSTR lpstrpasswd, LPCTSTR lpstrsinygb, LPCTSTR lpstrjcode, LPCTSTR lpstrprice, LPCTSTR lpstripaddr)
	{
		acct	= lpstracct;
		passwd	= lpstrpasswd;
		sinygb	= lpstrsinygb;
		jcode	= lpstrjcode;
		price   = lpstrprice;
		ipaddr  = lpstripaddr;

	}
};
// Output
class CTR_10142_O
{
public:
	CString		maxprice;		/*�ֹ����ɱݾ�*/          		
	CString		maxqty;	/*�ֹ����ɼ���*/
	
public:
	CTR_10142_O()
	{
		maxprice = maxqty = "";
	}
	CTR_10142_O(LPVOID pData)
	{
		TR_10142_O* pTR = (TR_10142_O*)pData;
		maxprice.Format("%*.*s"	, sizeof(pTR->maxprice), sizeof(pTR->maxprice), pTR->maxprice);
		maxqty.Format("%*.*s", sizeof(pTR->maxqty), sizeof(pTR->maxqty), pTR->maxqty);
		
		maxprice.TrimLeft();	maxprice.TrimRight();
		maxqty.TrimLeft();	maxqty.TrimRight();
	}
};


#endif //AFX_TR_10142_HEADER_

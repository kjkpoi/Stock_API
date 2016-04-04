// 20071211 권휘영 [1] >> 추가
#if !defined(AFX_TR_10142_HEADER_)
#define AFX_TR_10142_HEADER_

#define TR_10142	"10142"
//-------------------------------------------------------------------------------//
// 스피드주문-미체결         사용TR번호:10142                                    //
//--------------------------------[INPUT ]---------------------------------------//

//--------------------------------[INPUT ]------------------------------------------//
typedef struct _TR10142_I
{
	char  acct		[20];   	/* 지점번호(3)+계좌번호(17) */
	char  passwd	[8];		/* 비밀번호					*/ 
	char  sinygb    [2];        /* "01":유통융자, "03":자기융자,"07":자기대주 */
	char  jcode     [6];		/* 종목코드					*/
    char  price     [13];		/* 주문가                   */
    char  ipaddr    [16];		/* client ipaddr(199.99.9.90->199099009090) 			*/
} TR_10142_I;

//--------------------------------[OUTPUT ]-----------------------------------------//
typedef struct _TR10142_O
{
	char  maxprice  [16];					/*주문가능금액*/
	char  maxqty    [16];					/*주문가능수량*/
} TR_10142_O; 

class CTR_10142_I
{
public:
	CString		acct;	// 계좌번호
	CString		passwd;	// 비밀번호
	CString		sinygb;		// 신용구분

	CString		jcode;	// 종목번호	
	CString		price;	// 매수희망가
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
	CString		maxprice;		/*주문가능금액*/          		
	CString		maxqty;	/*주문가능수량*/
	
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

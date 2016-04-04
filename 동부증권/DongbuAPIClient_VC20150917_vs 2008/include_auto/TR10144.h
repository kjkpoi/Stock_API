// 20091103 박진환 >> 신규추가
#if !defined(AFX_TR_10144_HEADER_)
#define AFX_TR_10144_HEADER_

#define TR_10144	"10144"
//-------------------------------------------------------------------------------//
// 신용매도가능수량조회         사용TR번호:10144                                    //
//--------------------------------[INPUT ]---------------------------------------//

//--------------------------------[INPUT ]------------------------------------------//
typedef struct _TR10144_I
{
	char		acct	[20];   	/* 지점번호(3)+계좌번호(17) */
	char		passwd	[8];		/* 비밀번호					*/ 
	
	char		trdgb	[1];				/* 매매구분 : "1"매도, "2"매수 */
	char		sinygb  [2];				/* 대출상세분류코드 "01":유통융자, "03":자기융자,"07":자기대주 */

	char		jcode	[6];		/* 종목코드 (종목번호)			*/
    char		price	[15];			/* 주문가                   */
    char		lndate	[8];				/* 대출일 */
	char		ipaddr  [16];		            /* client ipaddr(199.99.9.90->199099009090) 			*/

} TR_10144_I;

//--------------------------------[OUTPUT ]-----------------------------------------//
typedef struct _TR10144_O
{
	char		price		[13];			/*주문가*/
	char		maxqty	    [16];			/*주문가능수량*/
	char		maxprice	[16];			/*주문가능금액*/
} TR_10144_O; 

class CTR_10144_I
{
public:
	CString		acct;	// 계좌번호
	CString		passwd;	// 비밀번호
	CString		trdgb;		// 매매구분
	CString		sinygb;		// 신용구분(대출상세분류코드)

	CString		jcode;	// 종목번호	
	CString		price;	// 매수희망가
	CString		lndate;	// 대출일
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
	CString		price;			/*주문가*/
	CString		maxprice;		/*주문가능금액*/          		
	CString		maxqty;			/*주문가능수량*/
	
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

#if !defined(AFX_TR_10121_HEADER_)
#define AFX_TR_10121_HEADER_

#define	TR_10121	"10121"

//-------------------------------------------------------------------------------//
// 가능수량 조회        사용TR번호:10121                                         //
//--------------------------------[INPUT ]---------------------------------------//
typedef struct
{
	char	gb		[ 1];		/* 조회구분 : 1:매도,2:매수,3:ECN매도,4:ECN매수	*/
	char 	geja	[ 20];		/* 계좌번호										*/
	char	passwd	[ 8];		/* 비밀번호                                     */
	char 	jcode	[ 6];		/* 종목번호										*/
	char	price	[ 9];		/* 매수희망가                                   */	
    char    ipaddr  [16];       /* client ipaddr(199.99.9.90->199099009090)     */
} TR10121_I;
//--------------------------------[OUTPUT     ]-----------------------------------//
typedef struct
{	
	char    pqty		[15];  	/* 매수적정가능수량            					*/
	char    maxqty		[15];  	/* 매도/매수최대가능수량            			*/
} TR_10121_O;


///////////////////////////////////////////////////////////////////////////////////////////
// Input
class CTR_10121_I
{
public:
	char		gb;		// 조회구문 : 1:매도,2:매수,3:ECN매도,4:ECN매수
	CString		geja;	// 계좌번호
	CString		passwd;	// 비밀번호
	CString		jcode;	// 종목번호	
	CString		price;	// 매수희망가
public:
	CTR_10121_I()
	{
		gb		= ' ';
	}
	// 20110616 주우주 >>
	CTR_10121_I(char gubun, LPCTSTR lpstrGeja, LPCTSTR lpstrPass, LPCTSTR lpstrCode, LPCTSTR lpstrPrice)
	{
		gb		= gubun;
		geja	= lpstrGeja;
		passwd	= lpstrPass;
		jcode	= lpstrCode;
		price	= lpstrPrice;
	}	
};
// Output
class CTR_10121_O
{
public:	
	CString		maxqty;		//	매도/매수최대가능수량       
	CString		pqty;		//	매수적정가능수량            
	
public:
	
	CTR_10121_O(LPVOID pData)
	{
		TR_10121_O* pTR = (TR_10121_O*)pData;
		pqty.Format("%*.*s"	, sizeof(pTR->pqty), sizeof(pTR->pqty), pTR->pqty);
		maxqty.Format("%*.*s", sizeof(pTR->maxqty), sizeof(pTR->maxqty), pTR->maxqty);
		
		pqty.TrimLeft();	pqty.TrimRight();
		maxqty.TrimLeft();	maxqty.TrimRight();
	}
};

#endif //AFX_TR_10121_HEADER_

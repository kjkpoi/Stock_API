#if !defined(AFX_TR_10117_HEADER_)
#define AFX_TR_10117_HEADER_

#define	TR_10117	"10121"
//-------------------------------------------------------------------------------//
// 가능수량 조회        사용TR번호:10117                                         //
//--------------------------------[INPUT ]---------------------------------------//
typedef struct
{
	char	gb		[ 1];		/* 조회구분 : 1:매도,2:매수,3:ECN매도,4:ECN매수	*/	
	char 	geja	[ 20];		/* 계좌번호										*/
	char	passwd	[ 8];		/* 비밀번호                                     */
	char 	code	[ 6];		/* 종목번호										*/
	char	price	[ 9];		/* 매수희망가                                   */
    char    ipaddr  [16];       /* client ipaddr(199.99.9.90->199099009090)     */


} TR_10117_I;
//--------------------------------[OUTPUT     ]-----------------------------------//
typedef struct
{	
	char    pqty		[15];  	/* 매수적정가능수량            					*/
	char    maxqty		[15];  	/* 매도/매수최대가능수량            			*/
	       
} TR_10117_O;

typedef struct
{
	char	gb		[ 1];		/* 조회구분 : 1:매도,2:매수,3:ECN매도,4:ECN매수	*/
	char 	bpno	[ 3];		/* 지점번호										*/
	char	mgb		[ 2];		/* 상품구분                                     */
	char 	geja	[ 6];		/* 계좌번호										*/
	char	passwd	[ 8];		/* 비밀번호                                     */
	char 	code	[12];		/* 종목번호										*/
	char	price	[ 9];		/* 매수희망가                                   */
	char 	type	[ 2];		/* 통신매체구분									*/
} TR_10117_I_1;
//--------------------------------[OUTPUT     ]-----------------------------------//
typedef struct
{
	char    d2yesu		[14];  	/* D+2예수금            						*/
	char    maxqty		[ 9];  	/* 매도/매수최대가능수량            			*/
	char    pqty		[ 9];  	/* 매수적정가능수량            					*/
	char    nmamt		[12];  	/* 미체결매수금액            					*/
	char    jqtyyesu	[14];  	/* 유가잔고수량/예수금            				*/
	char    pqtyamt		[12];  	/* 전일재매매사용가능수량/금액					*/
	char    tqtyamt		[12];  	/* 금일재매매사용가능수량/금액					*/

	char 	d_price		[14];   /* 주문가능현금									*/
	char    ksp_maxamt	[12];   /* KOSPI최대주문가능금액						*/
	char    ksd_maxamt	[12];   /* KOSDAQ최대주문가능금액						*/	
} TR_10117_O_1;

// 20071019 권휘영 <<

///////////////////////////////////////////////////////////////////////////////////////////
// Input
class CTR_10117_I
{
public:
	char		gb;		// 조회구문 : 1:매도,2:매수,3:ECN매도,4:ECN매수
	CString		geja;	// 계좌번호
	CString		passwd;	// 비밀번호
	CString		code;	// 종목번호	
	CString		price;	// 매수희망가
public:
	CTR_10117_I()
	{
		gb		= ' ';
		geja = passwd = code = price = "";
	}
	// 20110616 주우주 >>
	CTR_10117_I(char gubun, LPCTSTR lpstrGeja, LPCTSTR lpstrPass, LPCTSTR lpstrCode, LPCTSTR lpstrPrice)
	{
		gb		= gubun;
		geja	= lpstrGeja;
		passwd	= lpstrPass;
		code	= lpstrCode;
		price	= lpstrPrice;
	}
	// 20110616 주우주 <<
};
// Output
class CTR_10117_O
{
public:
	CString		d2yesu;		//	D+2예수금            		
	CString		maxqty;		//	매도/매수최대가능수량       
	CString		pqty;		//	매수적정가능수량            
	CString		nmamt;		//	미체결매수금액            	
	CString		jqtyyesu;	//	유가잔고수량/예수금         
	CString		pqtyamt;	//	전일재매매사용가능수량/금액	
	CString		tqtyamt;	//	금일재매매사용가능수량/금액	

	CString		d_price;	//	주문가능현금				
	CString		ksp_maxamt;	//	KOSPI 최대주문가능금액		
	CString		ksd_maxamt;	//	KOSDAQ 최대주문가능금액	

public:
	CTR_10117_O()
	{
		d2yesu = maxqty = pqty = nmamt = jqtyyesu = pqtyamt = tqtyamt = d_price = ksp_maxamt = ksd_maxamt = "";
	}
	CTR_10117_O(LPVOID pData)
	{
		TR_10117_O* pTR = (TR_10117_O*)pData;
		
		pqty.Format("%*.*s"	, sizeof(pTR->pqty), sizeof(pTR->pqty), pTR->pqty);
		maxqty.Format("%*.*s", sizeof(pTR->maxqty), sizeof(pTR->maxqty), pTR->maxqty);
		
		pqty.TrimLeft();	pqty.TrimRight();
		maxqty.TrimLeft();	maxqty.TrimRight();
	}
};

#endif //AFX_TR_10117_HEADER_

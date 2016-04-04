#if !defined(AFX_TR_10112_HEADER_)
#define AFX_TR_10112_HEADER_

#define		TR_10112	"10112"
#define		SH_KSIZE	6

//-------------------------------------------------------------------------------//
// 매매단위 조회         사용TR번호:10112                                        //
//--------------------------------[INPUT ]---------------------------------------//
typedef struct
{
    char    jgcode[SH_KSIZE];
} TR_10112_I;
//--------------------------------[OUTPUT ]---------------------------------------//
typedef struct {
    char    prcgb   [6];       /* 주문단위 */
    char    hodanwi [8];       /* 호가단위 */
    char    jgcode  [6];	   /* 종목코드 */
} TR_10112_O;

//--------------------------------[Class ]---------------------------------------//
class CTR10112
{
public:
	
	CString    prcgb;		// 주문단위     
    CString    hodanwi;		// 호가단위                  
    CString    jgcode;		// 종목코드
public:
	CTR10112(TR_10112_O* pOut)
	{
		convert(pOut);
	}
	CTR10112()
	{
		prcgb = "";
		hodanwi= "";
		jgcode = "";
	}
	void convert(TR_10112_O* pOut)
	{
		prcgb.Format("%*.*s", sizeof(pOut->prcgb), sizeof(pOut->prcgb), pOut->prcgb);
		hodanwi.Format("%*.*s", sizeof(pOut->hodanwi), sizeof(pOut->hodanwi), pOut->hodanwi);
		jgcode.Format("%*.*s", sizeof(pOut->jgcode), sizeof(pOut->jgcode), pOut->jgcode);
	}
};

#endif //AFX_TR_10112_HEADER_

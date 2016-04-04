#if !defined(AFX_TR_13118_HEADER_)
#define AFX_TR_13118_HEADER_

#define		tr_13118MAX					250
#define		TR_STOCKCHEGYUL				"13118"

#define DATA_MEMCOPY(xTmp, xStruct, xKey) memcpy(xTmp, xStruct->xKey, sizeof(xStruct->xKey)); \
			xTmp[sizeof(xStruct->xKey)]=0;  m_sz##xKey=xTmp; \
			m_sz##xKey.TrimLeft(); m_sz##xKey.TrimRight();

//-------------------------------------------------------------------------------##
// 실시간체결         사용TR번호:13118                                           ##
//--------------------------------[INPUT ]---------------------------------------##
typedef struct _tr13118_i
{
	char  geja		[20];   	/* 지점번호(3)+계좌번호(8) 	*/
	char  sgb		[ 1];		/* 1:주문/체결 2:미체결		*/
	char  chk		[ 1];		/* 종목코드 체크구분		*/
	char  jcode		[ 6];		/* 종목코드					*/ 
	char  sort	 	[ 1];  		/* 정순(1) 역순(2) 			*/

	char  ngbn		[ 1];		/* 0:처음, 1:다음          */
	char  next		[50];		/* 다음조회 KEY            */
} TR_13118_I;


#define  TR_13118_I_SIZE sizeof(TR_13118_I)

//--------------------------------[OUTPUT반복 ]-----------------------------------##
typedef struct _tr_13118_g
{
    char  juno		[ 9];    	/* 주문번호 	*/ //5->9
	char  jgcode	[12];   	/* 종목코드     */
	char  jgname	[20];  		/* 종목명	 	*/
	char  jugb_attr	[ 3]; 		/* 매매구분속성 */
	char  jugb		[16];   	/* 매매구분		*/ 
	char  juqty		[15];    	/* 주문수량 	*/ //9->15
	char  juprc		[12];    	/* 주문단가 	*/ //9->12
	char  cheqty	[15];   	/* 체결수량 	*/ //9->15
	char  cheprc	[12];   	/* 체결평균		*/ //9->12
	char  nonqty	[15];   	/* 미체결 		*/ //9->15
	char  mmgb		[10];    	/* 주문유형 	*/			
	char  wonjuno	[ 9];  		/* 원주문번호	*/ //5->9
	char  status	[10];		/* 처리구분		*/
	char  cherate	[ 9];		/* 체결률		*/
	char  time  	[ 6];		/* 주문시간		*/
	char  feentax	[ 9];		/* 제비용		*/
	char  fee 		[ 9];		/* 수수료		*/
	char  tax		[ 9];		/* 세금			*/	
	char  singb		[ 3];		/* 신용구분		*/	
} TR_13118_G;

#define  TR_13118_G_SIZE sizeof(TR_13118_G)

typedef struct _tr_13118_o
{
	char		geja[20];   	/* 지점번호(3)+계좌번호(8) 	*/

	char		ngbn[ 1];					/* 다음데이타 구분  */
											/* 0:없음, 1:있음   */
	char		next[50];					/* 다음조회 KEY     */

    char        gr_cnt[4];                  /* Grid count           */
    char        gr_bjlen[2];                /* Grid Bojo Data Length*/
    char        gr_bjdata[4];               /* Grid Bojo Data       */
    // TR_13118_G  grid[tr_13118MAX];
	char		gr_DATA[1];		// 사이즈만큼 알아서..
} TR_13118_O;


class CTR_13118_G
{
public: //Variable
//    DEFINE_DRDS_LINE0(
	CString  m_szjuno		;    	/* 주문번호 	*/
	CString  m_szjgcode		;   	/* 종목코드     */
	CString  m_szjgname		;  		/* 종목명	 	*/
	CString  m_szjugb_attr	; 		/* 매매구분속성 */
	CString  m_szjugb		;   	/* 매매구분		*/
	CString  m_szjuqty		;    	/* 주문수량 	*/	
	CString  m_szjuprc		;    	/* 주문단가 	*/
	CString  m_szcheqty		;   	/* 체결수량 	*/
	CString  m_szcheprc		;   	/* 체결평균		*/
	CString  m_sznonqty		;   	/* 미체결 		*/
	CString  m_szmmgb		;    	/* 주문유형 	*/			
	CString  m_szwonjuno	;  		/* 원주문번호	*/
	CString  m_szstatus		;		/* 처리구분		*/
	CString  m_szcherate	;		/* 체결률		*/
	CString  m_sztime  		;		/* 주문시간		*/
	CString  m_szfeentax	;		/* 제비용		*/
	CString  m_szfee 		;		/* 수수료		*/
	CString  m_sztax		;		/* 세금			*/

public:
	CTR_13118_G()
	{
	}

	virtual void  Convert(TR_13118_G* pInput)
	{
		CString sTemp1 ;
		char sTmp[20+1];

		DATA_MEMCOPY(sTmp, pInput, juno		);    	/* 주문번호 	*/		
		DATA_MEMCOPY(sTmp, pInput, jgcode	);   	/* 종목코드     */
		DATA_MEMCOPY(sTmp, pInput, jgname	);  	/* 종목명	 	*/
		DATA_MEMCOPY(sTmp, pInput, jugb_attr); 		/* 매매구분속성 */
		DATA_MEMCOPY(sTmp, pInput, jugb		);   	/* 매매구분		*/
		DATA_MEMCOPY(sTmp, pInput, juqty	);    	/* 주문수량 	*/
		DATA_MEMCOPY(sTmp, pInput, juprc	);    	/* 주문단가 	*/
		DATA_MEMCOPY(sTmp, pInput, cheqty	);   	/* 체결수량 	*/
		DATA_MEMCOPY(sTmp, pInput, cheprc	);   	/* 체결평균		*/
		DATA_MEMCOPY(sTmp, pInput, nonqty	);   	/* 미체결 		*/
		DATA_MEMCOPY(sTmp, pInput, mmgb		);    	/* 주문유형 	*/
		DATA_MEMCOPY(sTmp, pInput, wonjuno	);  	/* 원주문번호	*/
		DATA_MEMCOPY(sTmp, pInput, status	);		/* 처리구분		*/
		DATA_MEMCOPY(sTmp, pInput, cherate	);		/* 체결률		*/
		DATA_MEMCOPY(sTmp, pInput, time  	);		/* 주문시간		*/
		DATA_MEMCOPY(sTmp, pInput, feentax	);		/* 제비용		*/
		DATA_MEMCOPY(sTmp, pInput, fee 		);		/* 수수료		*/
		DATA_MEMCOPY(sTmp, pInput, tax		);		/* 세금			*/
	}
};

//typedef CList<CTR_13118_G*, CTR_13118_G*> LIST_TR_13118_G;


#endif //AFX_TR_13118_HEADER_

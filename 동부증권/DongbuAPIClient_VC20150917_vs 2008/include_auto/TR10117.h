#if !defined(AFX_TR_10117_HEADER_)
#define AFX_TR_10117_HEADER_

#define	TR_10117	"10121"
//-------------------------------------------------------------------------------//
// ���ɼ��� ��ȸ        ���TR��ȣ:10117                                         //
//--------------------------------[INPUT ]---------------------------------------//
typedef struct
{
	char	gb		[ 1];		/* ��ȸ���� : 1:�ŵ�,2:�ż�,3:ECN�ŵ�,4:ECN�ż�	*/	
	char 	geja	[ 20];		/* ���¹�ȣ										*/
	char	passwd	[ 8];		/* ��й�ȣ                                     */
	char 	code	[ 6];		/* �����ȣ										*/
	char	price	[ 9];		/* �ż������                                   */
    char    ipaddr  [16];       /* client ipaddr(199.99.9.90->199099009090)     */


} TR_10117_I;
//--------------------------------[OUTPUT     ]-----------------------------------//
typedef struct
{	
	char    pqty		[15];  	/* �ż��������ɼ���            					*/
	char    maxqty		[15];  	/* �ŵ�/�ż��ִ밡�ɼ���            			*/
	       
} TR_10117_O;

typedef struct
{
	char	gb		[ 1];		/* ��ȸ���� : 1:�ŵ�,2:�ż�,3:ECN�ŵ�,4:ECN�ż�	*/
	char 	bpno	[ 3];		/* ������ȣ										*/
	char	mgb		[ 2];		/* ��ǰ����                                     */
	char 	geja	[ 6];		/* ���¹�ȣ										*/
	char	passwd	[ 8];		/* ��й�ȣ                                     */
	char 	code	[12];		/* �����ȣ										*/
	char	price	[ 9];		/* �ż������                                   */
	char 	type	[ 2];		/* ��Ÿ�ü����									*/
} TR_10117_I_1;
//--------------------------------[OUTPUT     ]-----------------------------------//
typedef struct
{
	char    d2yesu		[14];  	/* D+2������            						*/
	char    maxqty		[ 9];  	/* �ŵ�/�ż��ִ밡�ɼ���            			*/
	char    pqty		[ 9];  	/* �ż��������ɼ���            					*/
	char    nmamt		[12];  	/* ��ü��ż��ݾ�            					*/
	char    jqtyyesu	[14];  	/* �����ܰ����/������            				*/
	char    pqtyamt		[12];  	/* ������ŸŻ�밡�ɼ���/�ݾ�					*/
	char    tqtyamt		[12];  	/* ������ŸŻ�밡�ɼ���/�ݾ�					*/

	char 	d_price		[14];   /* �ֹ���������									*/
	char    ksp_maxamt	[12];   /* KOSPI�ִ��ֹ����ɱݾ�						*/
	char    ksd_maxamt	[12];   /* KOSDAQ�ִ��ֹ����ɱݾ�						*/	
} TR_10117_O_1;

// 20071019 ���ֿ� <<

///////////////////////////////////////////////////////////////////////////////////////////
// Input
class CTR_10117_I
{
public:
	char		gb;		// ��ȸ���� : 1:�ŵ�,2:�ż�,3:ECN�ŵ�,4:ECN�ż�
	CString		geja;	// ���¹�ȣ
	CString		passwd;	// ��й�ȣ
	CString		code;	// �����ȣ	
	CString		price;	// �ż������
public:
	CTR_10117_I()
	{
		gb		= ' ';
		geja = passwd = code = price = "";
	}
	// 20110616 �ֿ��� >>
	CTR_10117_I(char gubun, LPCTSTR lpstrGeja, LPCTSTR lpstrPass, LPCTSTR lpstrCode, LPCTSTR lpstrPrice)
	{
		gb		= gubun;
		geja	= lpstrGeja;
		passwd	= lpstrPass;
		code	= lpstrCode;
		price	= lpstrPrice;
	}
	// 20110616 �ֿ��� <<
};
// Output
class CTR_10117_O
{
public:
	CString		d2yesu;		//	D+2������            		
	CString		maxqty;		//	�ŵ�/�ż��ִ밡�ɼ���       
	CString		pqty;		//	�ż��������ɼ���            
	CString		nmamt;		//	��ü��ż��ݾ�            	
	CString		jqtyyesu;	//	�����ܰ����/������         
	CString		pqtyamt;	//	������ŸŻ�밡�ɼ���/�ݾ�	
	CString		tqtyamt;	//	������ŸŻ�밡�ɼ���/�ݾ�	

	CString		d_price;	//	�ֹ���������				
	CString		ksp_maxamt;	//	KOSPI �ִ��ֹ����ɱݾ�		
	CString		ksd_maxamt;	//	KOSDAQ �ִ��ֹ����ɱݾ�	

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

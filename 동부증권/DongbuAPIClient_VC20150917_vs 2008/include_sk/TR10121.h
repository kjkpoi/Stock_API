#if !defined(AFX_TR_10121_HEADER_)
#define AFX_TR_10121_HEADER_

#define	TR_10121	"10121"

//-------------------------------------------------------------------------------//
// ���ɼ��� ��ȸ        ���TR��ȣ:10121                                         //
//--------------------------------[INPUT ]---------------------------------------//
typedef struct
{
	char	gb		[ 1];		/* ��ȸ���� : 1:�ŵ�,2:�ż�,3:ECN�ŵ�,4:ECN�ż�	*/
	char 	geja	[ 20];		/* ���¹�ȣ										*/
	char	passwd	[ 8];		/* ��й�ȣ                                     */
	char 	jcode	[ 6];		/* �����ȣ										*/
	char	price	[ 9];		/* �ż������                                   */	
    char    ipaddr  [16];       /* client ipaddr(199.99.9.90->199099009090)     */
} TR10121_I;
//--------------------------------[OUTPUT     ]-----------------------------------//
typedef struct
{	
	char    pqty		[15];  	/* �ż��������ɼ���            					*/
	char    maxqty		[15];  	/* �ŵ�/�ż��ִ밡�ɼ���            			*/
} TR_10121_O;


///////////////////////////////////////////////////////////////////////////////////////////
// Input
class CTR_10121_I
{
public:
	char		gb;		// ��ȸ���� : 1:�ŵ�,2:�ż�,3:ECN�ŵ�,4:ECN�ż�
	CString		geja;	// ���¹�ȣ
	CString		passwd;	// ��й�ȣ
	CString		jcode;	// �����ȣ	
	CString		price;	// �ż������
public:
	CTR_10121_I()
	{
		gb		= ' ';
	}
	// 20110616 �ֿ��� >>
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
	CString		maxqty;		//	�ŵ�/�ż��ִ밡�ɼ���       
	CString		pqty;		//	�ż��������ɼ���            
	
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

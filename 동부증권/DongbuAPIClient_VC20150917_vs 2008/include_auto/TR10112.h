#if !defined(AFX_TR_10112_HEADER_)
#define AFX_TR_10112_HEADER_

#define		TR_10112	"10112"
#define		SH_KSIZE	6

//-------------------------------------------------------------------------------//
// �ŸŴ��� ��ȸ         ���TR��ȣ:10112                                        //
//--------------------------------[INPUT ]---------------------------------------//
typedef struct
{
    char    jgcode[SH_KSIZE];
} TR_10112_I;
//--------------------------------[OUTPUT ]---------------------------------------//
typedef struct {
    char    prcgb   [6];       /* �ֹ����� */
    char    hodanwi [8];       /* ȣ������ */
    char    jgcode  [6];	   /* �����ڵ� */
} TR_10112_O;

//--------------------------------[Class ]---------------------------------------//
class CTR10112
{
public:
	
	CString    prcgb;		// �ֹ�����     
    CString    hodanwi;		// ȣ������                  
    CString    jgcode;		// �����ڵ�
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

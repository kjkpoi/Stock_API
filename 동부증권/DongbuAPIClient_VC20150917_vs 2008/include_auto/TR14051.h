#if !defined(AFX_TR_14051_HEADER_)
#define AFX_TR_14051_HEADER_

//{{ �ű��ֹ�, û�갡�ɼ��� ��ȸ


typedef struct
{
    char    geja		[20];		/* ���¹�ȣ */ //11->20
    char    passwd		[ 8];       /* ��й�ȣ */
	char    jcode		[12];		/* �����ڵ� 8 + 7space */ //15->32  32--> 12
    char    gb			[ 1];		/* �Ÿű���  1:�ŵ� 2:�ż� */
	char    price		[12];		/* �ֹ����� */ //9->12
    char    ord_type	[ 2];       /* �ֹ�����  1:������ 2:���尡 3:���Ǻ������� 4:������������*/ //1->2
	char    zLqdtQtyQryTp [ 1];     /* û����� ��ȸ���� : ���δ� 1 */
    char    i6			[16];       /* Ŭ���̾�Ʈ IP�ּ�(��:192009101031)				*/
} TR_14051_I;

typedef struct
{
	char    newqty		[15];		/* �ű��ֹ����� ���� */ //7->15
    char    clearqty	[15];		/* û�갡�� ���� */ //7->15
} TR_14051_O;

typedef struct
{
    char    geja		[11];		/* ���¹�ȣ */
    char    passwd		[ 8];       /* ��й�ȣ */
    char    gb			[ 1];		/* �Ÿű���  1:�ŵ� 2:�ż� */
    char    jcode		[15];		/* �����ڵ� 8 + 7space */
    char    ord_type	[ 1];       /* �ֹ�����  1:������ 2:���尡 3:���Ǻ������� 4:������������*/	
    char    price		[ 9];		/* �ֹ����� */
    char    cvd_tp		[ 6];       /* �����ڵ� space */
	char	markettp	[ 2];				
} TR_14051_I_1;

typedef struct
{
	char    newqty		[ 7];		/* �ű��ֹ����� ���� */
    char    clearqty	[ 7];		/* û�갡�� ���� */
} TR_14051_O_1;

class CTR_14051_O
{
public:
    LONGLONG			newqty;
	LONGLONG			clearqty;

public:
	CTR_14051_O(TR_14051_O* pOut)
	{
		convert(pOut);
	}
	CTR_14051_O()
	{
		newqty = 0;
		clearqty= 0;
	}
	void convert(TR_14051_O* pOut)
	{
		CString strData;
		strData.Format("%*.*s", sizeof(pOut->newqty), sizeof(pOut->newqty), pOut->newqty);
		newqty = _atoi64(strData);
		strData.Format("%*.*s", sizeof(pOut->clearqty), sizeof(pOut->clearqty), pOut->clearqty);
		clearqty = _atoi64(strData);
	}
};
#endif //AFX_TR_14051_HEADER_

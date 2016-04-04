#if !defined(AFX_TR_14055_HEADER_)
#define AFX_TR_14055_HEADER_

//{{ �ű��ֹ�, û�갡�ɼ��� ��ȸ

typedef struct
{
    char    geja		[20];		/* ���¹�ȣ */ //11->20
    char    passwd		[ 8];       /* ��й�ȣ */
	char    jcode		[32];		/* �����ڵ� 8 + 7space */ //15->32
    char    gb			[ 1];		/* �Ÿű���  1:�ŵ� 2:�ż� */
	char    price		[9];		/* �ֹ����� */ //9->12
    char    ord_type	[ 2];       /* �ֹ�����  1:������ 2:���尡 3:���Ǻ������� 4:������������*/ //1->2
	char    zLqdtQtyQryTp [ 1];     /* û����� ��ȸ���� : ���δ� 1 */
    char    ip			[16];       /* Ŭ���̾�Ʈ IP�ּ�(��:192009101031)				*/
} TR_14055_I;

typedef struct
{
	char    newqty		[15];		/* �ű��ֹ����� ���� */ //7->15
    char    clearqty	[15];		/* û�갡�� ���� */ //7->15
} TR_14055_O;


class CTR_14055_O
{
public:	
    LONGLONG			m_nNewqty;		
	LONGLONG			m_nClearqty;

public:
	CTR_14055_O(TR_14055_O* pOut)
	{
		convert(pOut);
	}
	CTR_14055_O()
	{
		m_nNewqty = 0;
		m_nClearqty= 0;
	}
	void convert(TR_14055_O* pOut)
	{
		CString strData;
		strData.Format("%*.*s", sizeof(pOut->newqty), sizeof(pOut->newqty), pOut->newqty);
		m_nNewqty = _atoi64(strData);

		strData.Format("%*.*s", sizeof(pOut->clearqty), sizeof(pOut->clearqty), pOut->clearqty);
		m_nClearqty = _atoi64(strData);
	}
};
#endif //AFX_TR_14055_HEADER_

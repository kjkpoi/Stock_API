#if !defined(AFX_TR_14055_HEADER_)
#define AFX_TR_14055_HEADER_

//{{ 신규주문, 청산가능수량 조회

typedef struct
{
    char    geja		[20];		/* 계좌번호 */ //11->20
    char    passwd		[ 8];       /* 비밀번호 */
	char    jcode		[32];		/* 종목코드 8 + 7space */ //15->32
    char    gb			[ 1];		/* 매매구분  1:매도 2:매수 */
	char    price		[9];		/* 주문가격 */ //9->12
    char    ord_type	[ 2];       /* 주문유형  1:지정가 2:시장가 3:조건부지정가 4:최유리지정가*/ //1->2
	char    zLqdtQtyQryTp [ 1];     /* 청산수량 조회구분 : 동부는 1 */
    char    ip			[16];       /* 클라이언트 IP주소(예:192009101031)				*/
} TR_14055_I;

typedef struct
{
	char    newqty		[15];		/* 신규주문가능 수량 */ //7->15
    char    clearqty	[15];		/* 청산가능 수량 */ //7->15
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

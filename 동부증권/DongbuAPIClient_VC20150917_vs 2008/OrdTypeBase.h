#pragma once
#include "afx.h"

class COrdTypeBase : public CObject
{
public:
	COrdTypeBase();
	COrdTypeBase(const COrdTypeBase &obj) { *this = obj; };
	virtual ~COrdTypeBase();

	virtual void	Copy(const COrdTypeBase& item);
	virtual COrdTypeBase& operator = (const COrdTypeBase& item);

protected:
	enORDTYPE	m_erOrdType;
	CString		m_strExpiredate;			//유효기간
	CString			m_strPriceType;				//주문구분 '1':지정가, '2':시장가	
											/* '1':지정가,       '2':시장가              */
											/* '3':최유리지정가, '4':최우선지정가        */
											/* '5':매수1호가,    '6':매수2호가           */
											/* '7':매도1호가,    '8':매도2호가           */

	int			m_nQtyGb;   				/* 수량 입력구분                             */ 
											/* '1':수량직접입력, '2':백분률로 입력       */

	CString		 m_strBaseQty;
	CStringArray m_saOrdReqQty;			//주문수량(백분율)
	int			m_nOrdCnt;					//분할횟수 1:일반주문, n:호가/시간분할주문
	int			m_nOrdUnit;					//분할단위
	int			m_nDivStd;					//분할기준 0:정배열,   1:등배열, 2:역배열 */
	int			m_nDivWay;					//분할방향 0:매수방향, 1:매도방향         */
public:
	CStringArray m_saOrdPrice;		//주문가격 매수 1/2/3 호가(D1/D2/D3)
									//		   매도 1/2/3 호가(S1/S2/S3)
									//		   지정가(J123400 - 123400 원)

	CString		GetExpireDate()  {return m_strExpiredate;};
	CString		GetPriceType()	 {return m_strPriceType;}; //[KSJ000000026] 신용주문추가, 주문구분추가
	CStringArray*	GetOrdReqPrice() {return &m_saOrdPrice;};
	CStringArray*	GetOrdReqQty()	 {return &m_saOrdReqQty;};
	int			GetOrdDivCnt()   {return m_nOrdCnt;};
	int			GetQtyGb()   {return m_nQtyGb;};
	int			GetOrdUnit()   {return m_nOrdUnit;};
	int			GetDivStd()	   {return m_nDivStd;};
	int			GetDivWay()	   {return m_nDivWay;};

	void		SetExpireDate(CString strDate)	 {m_strExpiredate = strDate;};
	void		SetPriceType(CString strPriceType)	 {m_strPriceType	  = strPriceType;};
	void		SetOrdType(enORDTYPE nOrdType)		 {m_erOrdType	  = nOrdType;};
	void		SetOrdUnit(int nUnit)			 {m_nOrdUnit = nUnit;};

	enORDTYPE	GetOrdType()  {return m_erOrdType; };

	void		CopyOrdReqPrice(CStringArray saOrdReqPrice)   {m_saOrdPrice.Copy(saOrdReqPrice);};
	void		AddOrdReqPrice(CString strOrdReqPrice)			 {m_saOrdPrice.Add(strOrdReqPrice);};

	void		SetQtyGb(int nQtyGb) {m_nQtyGb = nQtyGb;};
	void		SetOrdReqQty(CStringArray* dOrdReqQty);
	void		AddOrdReqQty(CString strOrdReqQty);
	void		SetOrdDivCnt(int nOrdCn)		 {m_nOrdCnt		  = nOrdCn;};

	void		SetBaseQty(CString strQty) {m_strBaseQty = strQty;};
	CString		GetBaseQty() {return m_strBaseQty;};
	void		SetDivStd(int nDiv)  {m_nDivStd = nDiv;};
	void		SetDivWay(int nWay)  {m_nDivWay = nWay;};
	void		ClearData();
};




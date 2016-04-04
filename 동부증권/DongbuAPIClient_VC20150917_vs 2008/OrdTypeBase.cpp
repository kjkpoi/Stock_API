#include "StdAfx.h"
#include "OrdTypeBase.h"

COrdTypeBase::COrdTypeBase(void)
{
	m_strExpiredate = "";
	m_strPriceType	= "1";	 //[KSJ000000026] 신용주문추가, 주문구분추가
	m_saOrdPrice.RemoveAll();

	m_saOrdReqQty.RemoveAll();
	m_nOrdCnt	    = 0;
	m_nQtyGb		= 2;
	m_nOrdUnit		= 0;
	m_nDivStd		= 1; //등배열
	m_nDivWay		= 0; //매수방향	
}

COrdTypeBase::~COrdTypeBase(void)
{
}

void COrdTypeBase::Copy(const COrdTypeBase& item)
{
	m_strExpiredate = item.m_strExpiredate;			
	m_strPriceType	= item.m_strPriceType;		 //[KSJ000000026] 신용주문추가, 주문구분추가			
	m_saOrdPrice.Copy(item.m_saOrdPrice);		

	m_saOrdReqQty.Copy(item.m_saOrdReqQty);	
					
	m_nOrdCnt		= item.m_nOrdCnt;	
	m_nQtyGb		= item.m_nQtyGb;
	m_nOrdUnit      = item.m_nOrdUnit;
	m_strBaseQty    = item.m_strBaseQty;
	m_nDivStd		= item.m_nDivStd;
	m_nDivWay		= item.m_nDivWay;
}

COrdTypeBase& COrdTypeBase::operator = (const COrdTypeBase& item)
{
	
	Copy(item);

	return* this;
}

void COrdTypeBase::SetOrdReqQty(CStringArray* psaOrdReqQty)
{
	int nIndex;
	CString strData;
	for(nIndex = 0; nIndex < psaOrdReqQty->GetCount(); nIndex++)
	{
		strData = psaOrdReqQty->GetAt(nIndex);
		m_saOrdReqQty.Add(strData);
	}
}

void COrdTypeBase::AddOrdReqQty(CString strOrdReqQty)
{
	m_saOrdReqQty.Add(strOrdReqQty);
}

void COrdTypeBase::ClearData()
{
	m_saOrdPrice.RemoveAll();
	m_saOrdReqQty.RemoveAll();
}









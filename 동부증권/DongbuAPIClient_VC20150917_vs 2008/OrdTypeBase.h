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
	CString		m_strExpiredate;			//��ȿ�Ⱓ
	CString			m_strPriceType;				//�ֹ����� '1':������, '2':���尡	
											/* '1':������,       '2':���尡              */
											/* '3':������������, '4':�ֿ켱������        */
											/* '5':�ż�1ȣ��,    '6':�ż�2ȣ��           */
											/* '7':�ŵ�1ȣ��,    '8':�ŵ�2ȣ��           */

	int			m_nQtyGb;   				/* ���� �Է±���                             */ 
											/* '1':���������Է�, '2':��з��� �Է�       */

	CString		 m_strBaseQty;
	CStringArray m_saOrdReqQty;			//�ֹ�����(�����)
	int			m_nOrdCnt;					//����Ƚ�� 1:�Ϲ��ֹ�, n:ȣ��/�ð������ֹ�
	int			m_nOrdUnit;					//���Ҵ���
	int			m_nDivStd;					//���ұ��� 0:���迭,   1:��迭, 2:���迭 */
	int			m_nDivWay;					//���ҹ��� 0:�ż�����, 1:�ŵ�����         */
public:
	CStringArray m_saOrdPrice;		//�ֹ����� �ż� 1/2/3 ȣ��(D1/D2/D3)
									//		   �ŵ� 1/2/3 ȣ��(S1/S2/S3)
									//		   ������(J123400 - 123400 ��)

	CString		GetExpireDate()  {return m_strExpiredate;};
	CString		GetPriceType()	 {return m_strPriceType;}; //[KSJ000000026] �ſ��ֹ��߰�, �ֹ������߰�
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




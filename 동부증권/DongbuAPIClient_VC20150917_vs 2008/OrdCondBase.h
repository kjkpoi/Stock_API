#pragma once
#include "afx.h"

class COrdCondBase : public CObject
{
public:
	COrdCondBase();
	COrdCondBase(const COrdCondBase &obj) { *this = obj; };
	virtual ~COrdCondBase();

	virtual void	Copy(const COrdCondBase& item);
	virtual COrdCondBase& operator = (const COrdCondBase& item);
	
protected:
	int			m_nCondCnt;					//조건수 (최대 20개)
	int			m_nCondFlag;				//조건구분 '1':일반조건(계좌/시세/...), '2':사용자조건
	CString		m_strCondExp;				//조건계산식(표현식)	

	CString		m_strCode1;				//시장구분(1) + 종목코드(8)
	CString		m_strCode2;
	CString		m_strCode3;
	CString		m_strCode4;

public:
	// 20120723 ssj - 서버자동주문 >>
	int			m_nEvalUnit;		// EVAL_UNIT_PERCENT: %, EVAL_UNIT_WON: 원, EVAL_UNIT_TICK: tick
	int			m_nBasePriceType;	// BASE_TYPE_MATCH: 매입가, BASE_TYPE_USER: 수정단가
	CString		m_strBasePrice;		// 사용자가 입력한 수정단가
	// 20120723 ssj - 서버자동주문 <<

public:
	CList<User_Define, User_Define> m_listUser_Define;
//	User_Define* m_pstUser_Define;			//조건 구조체(조건검색에서 사용하는 구조체)
	


public:
	void		InitValue();
	int			GetCondCount()	 {return m_nCondCnt;};	
	int			GetCondFlag()	{return m_nCondFlag;};	
	CString		GetCondExp()	{return m_strCondExp;};		

	CString		GetCondCode1()	{return m_strCode1;};			
	CString		GetCondCode2()	{return m_strCode2;};	
	CString		GetCondCode3()	{return m_strCode3;};	
	CString		GetCondCode4()	{return m_strCode4;};	


	void		SetCondCode1(CString strCode)	{m_strCode1 = strCode;};			
	void		SetCondCode2(CString strCode)	{m_strCode2 = strCode;};	
	void		SetCondCode3(CString strCode)	{m_strCode3 = strCode;};	
	void		SetCondCode4(CString strCode)	{m_strCode4 = strCode;};

	void		SetCondCount(int nCondCnt)		 { 
		m_nCondCnt	=	nCondCnt;
	};	
	void		SetCondFlag(int nCondFlag)		{ m_nCondFlag	=	nCondFlag;};	
	void		SetCondExp(CString strCondExp)	{ m_strCondExp	=	strCondExp;};	
	void		AddCondExp(CString strCondExp);
	void		SetCondCode(CString strCode1, CString strCode2 = "", CString strCode3 = "", CString strCode4 = "");
	void		SetUserDefine(User_Define stUser_Define);
	void		SetUserDefineList(CList<User_Define, User_Define>* plistUser_Define);
	void		Remove_UserDefine();

	// 20120723 ssj - 서버자동주문 >>
	void		SetPriceType(int nPriceType) {
		m_nEvalUnit = nPriceType;		// EVAL_UNIT_PERCENT: %, EVAL_UNIT_WON: 원, EVAL_UNIT_TICK: tick
	}
	int			GetPriceType() {
		return m_nEvalUnit;
	}

	void		SetBasePriceType(int nBasePriceType) {
		m_nBasePriceType = nBasePriceType;	// BASE_TYPE_MATCH: 매입가, BASE_TYPE_USER: 수정단가
	}
	int			GetBasePriceType() {
		return m_nBasePriceType;
	}	

	void		SetBasePrice(CString strBasePrice, int nMapMode)
	{
		m_strBasePrice = strBasePrice;	// 사용자가 입력한 수정단가
		m_strBasePrice.Trim();
		// 20120723 ssj - 서버자동주문 >>
		if (nMapMode == MODE_EQUITIES)
			m_strBasePrice.Format("%d", atol(m_strBasePrice));
		else
			m_strBasePrice.Format("%.2f", atof(m_strBasePrice));
		// 20120723 ssj - 서버자동주문 <<
	}
	CString		GetBasePrice() {
		return m_strBasePrice;
	}
};

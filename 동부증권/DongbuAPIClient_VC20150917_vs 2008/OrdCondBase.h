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
	int			m_nCondCnt;					//���Ǽ� (�ִ� 20��)
	int			m_nCondFlag;				//���Ǳ��� '1':�Ϲ�����(����/�ü�/...), '2':���������
	CString		m_strCondExp;				//���ǰ���(ǥ����)	

	CString		m_strCode1;				//���屸��(1) + �����ڵ�(8)
	CString		m_strCode2;
	CString		m_strCode3;
	CString		m_strCode4;

public:
	// 20120723 ssj - �����ڵ��ֹ� >>
	int			m_nEvalUnit;		// EVAL_UNIT_PERCENT: %, EVAL_UNIT_WON: ��, EVAL_UNIT_TICK: tick
	int			m_nBasePriceType;	// BASE_TYPE_MATCH: ���԰�, BASE_TYPE_USER: �����ܰ�
	CString		m_strBasePrice;		// ����ڰ� �Է��� �����ܰ�
	// 20120723 ssj - �����ڵ��ֹ� <<

public:
	CList<User_Define, User_Define> m_listUser_Define;
//	User_Define* m_pstUser_Define;			//���� ����ü(���ǰ˻����� ����ϴ� ����ü)
	


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

	// 20120723 ssj - �����ڵ��ֹ� >>
	void		SetPriceType(int nPriceType) {
		m_nEvalUnit = nPriceType;		// EVAL_UNIT_PERCENT: %, EVAL_UNIT_WON: ��, EVAL_UNIT_TICK: tick
	}
	int			GetPriceType() {
		return m_nEvalUnit;
	}

	void		SetBasePriceType(int nBasePriceType) {
		m_nBasePriceType = nBasePriceType;	// BASE_TYPE_MATCH: ���԰�, BASE_TYPE_USER: �����ܰ�
	}
	int			GetBasePriceType() {
		return m_nBasePriceType;
	}	

	void		SetBasePrice(CString strBasePrice, int nMapMode)
	{
		m_strBasePrice = strBasePrice;	// ����ڰ� �Է��� �����ܰ�
		m_strBasePrice.Trim();
		// 20120723 ssj - �����ڵ��ֹ� >>
		if (nMapMode == MODE_EQUITIES)
			m_strBasePrice.Format("%d", atol(m_strBasePrice));
		else
			m_strBasePrice.Format("%.2f", atof(m_strBasePrice));
		// 20120723 ssj - �����ڵ��ֹ� <<
	}
	CString		GetBasePrice() {
		return m_strBasePrice;
	}
};

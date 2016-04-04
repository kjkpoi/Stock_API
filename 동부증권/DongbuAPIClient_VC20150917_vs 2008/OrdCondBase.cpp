#include "StdAfx.h"
#include "OrdCondBase.h"

COrdCondBase::COrdCondBase(void)
{
	m_nCondCnt		= 0;			
	m_nCondFlag		= 0;	
	
	m_strCondExp = "";
	m_strCode1 = "";							
	m_strCode2 = "";			
	m_strCode3 = "";			
	m_strCode4 = "";		

	m_nEvalUnit = EVAL_UNIT_PERCENT;		// EVAL_UNIT_PERCENT: %, EVAL_UNIT_WON: 원, EVAL_UNIT_TICK: tick
	m_nBasePriceType = BASE_TYPE_MATCH;	// BASE_TYPE_MATCH: 매입가, BASE_TYPE_USER: 수정단가	
}

COrdCondBase::~COrdCondBase(void)
{

}

void COrdCondBase::Copy(const COrdCondBase& item)
{
	int nOriginIndex = m_nCondCnt;
	if(nOriginIndex < 0)
		nOriginIndex = 0;

	m_nCondCnt		= item.m_nCondCnt;				
	m_nCondFlag		= item.m_nCondFlag;				
	m_strCondExp	= item.m_strCondExp;			
	m_strCode1		= item.m_strCode1;						
	m_strCode2		= item.m_strCode2;			
	m_strCode3		= item.m_strCode3;			
	m_strCode4		= item.m_strCode4;	

	m_nEvalUnit = item.m_nEvalUnit;
	m_nBasePriceType = item.m_nBasePriceType;
	m_strBasePrice = item.m_strBasePrice;

	m_listUser_Define.RemoveAll();
	POSITION pos = item.m_listUser_Define.GetHeadPosition();
	while(pos)
	{
		User_Define stUser_Define = item.m_listUser_Define.GetNext(pos);
		m_listUser_Define.AddTail(stUser_Define);
	}

}

COrdCondBase& COrdCondBase::operator = (const COrdCondBase& item)
{
	
	Copy(item);
	return* this;
}

void COrdCondBase::SetUserDefine(User_Define stUser_DefineOrigin)
{
	m_listUser_Define.AddTail(stUser_DefineOrigin);

}

void COrdCondBase::SetUserDefineList(CList<User_Define, User_Define>* plistUser_Define)
{
	m_nCondCnt = plistUser_Define->GetCount();	
	POSITION pos = plistUser_Define->GetHeadPosition();
	while(pos)
	{
		User_Define stUser_Define = plistUser_Define->GetNext(pos);
		m_listUser_Define.AddTail(stUser_Define);
	}

}

void COrdCondBase::Remove_UserDefine()
{
	
}

void COrdCondBase::AddCondExp(CString strCondExp)
{
	if(m_strCondExp.Find(strCondExp) == -1)
	{
		if(m_strCondExp == "" && strCondExp != "")
			m_strCondExp = strCondExp;
		else
			m_strCondExp += _T("|") + strCondExp;
	}
}	

void COrdCondBase::InitValue()
{
	m_strCondExp = "";

	m_strCode1 = "";	
	m_strCode2 = "";	
	m_strCode3 = "";	
	m_strCode4 = "";	

	m_nEvalUnit = EVAL_UNIT_PERCENT;		// EVAL_UNIT_PERCENT: %, EVAL_UNIT_WON: 원, EVAL_UNIT_TICK: tick
	m_nBasePriceType = BASE_TYPE_MATCH;	// BASE_TYPE_MATCH: 매입가, BASE_TYPE_USER: 수정단가	
	m_strBasePrice = "";
}







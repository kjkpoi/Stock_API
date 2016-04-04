// OrdBase.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "OrdBase.h"

// COrdBase

COrdBase::COrdBase()
{
}

COrdBase::~COrdBase()
{
}

void COrdBase::Copy(const COrdBase& item)
{

}

COrdBase& COrdBase::operator = (const COrdBase& item)
{
	Copy(item);

	return* this;
}




// COrdBase 멤버 함수

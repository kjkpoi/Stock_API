#include "stdafx.h"
#include "APITest.h"

APITest::APITest()
{ 

}
APITest::~APITest()
{

}

void APITest::Test()
{
	printf("hello test\n");
}

BEGIN_MESSAGE_MAP(APITest, CDialog)
	ON_MESSAGE(WM_MSGTEST, OnMsg)
END_MESSAGE_MAP()

LRESULT APITest::OnMsg(WPARAM wParam, LPARAM lParam)
{
	AfxMessageBox(_T("Recv Msg"));    // 해당 동작 확인을 위해서 MessageBox사용, 원하는 코드 삽입...
	return 0;
}
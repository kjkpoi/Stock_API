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
	AfxMessageBox(_T("Recv Msg"));    // �ش� ���� Ȯ���� ���ؼ� MessageBox���, ���ϴ� �ڵ� ����...
	return 0;
}
#pragma once

class APITest : public CDialog
{

public:
     APITest();
	 virtual ~APITest();

	 void Test();

protected:
	 afx_msg LRESULT OnMsg(WPARAM wParam, LPARAM lParam);
     DECLARE_MESSAGE_MAP()
};
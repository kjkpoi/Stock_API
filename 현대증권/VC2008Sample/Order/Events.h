
#ifndef __EVENTS_H__
#define __EVENTS_H__

#include "ELWOrderDlg.h"

// �� Object�� ����� �̺�Ʈ ����

//��ȸ�̺�Ʈ 
class CYFRequestEvent : public IDispEventImpl<
	0,
	CYFRequestEvent,
	&DIID_IYFRequestDataEvents,
	&LIBID_YFExpertPlus,
	1,
	0>
{
public:
	BEGIN_SINK_MAP(CYFRequestEvent)
		SINK_ENTRY_EX(0, DIID_IYFRequestDataEvents, 204, Status)
		SINK_ENTRY_EX(0, DIID_IYFRequestDataEvents, 205, ReceiveData)
	END_SINK_MAP()

	CELWOrderDlg* m_Parent;
	
	CYFRequestEvent(CELWOrderDlg* Parent)
	{
		m_Parent = Parent;
	}
	
	void __stdcall ReceiveData(BSTR TrCode, BSTR Value, BSTR ValueList, long NextFlag, long SelectCount, BSTR MsgCode, BSTR MsgName)
	{
		m_Parent->Request_ReceiveData(TrCode, Value, ValueList, NextFlag, SelectCount, MsgCode, MsgName);

	}

	void __stdcall Status(long Status, BSTR TrCode, BSTR MsgCode, BSTR MsgName)
	{
		m_Parent->Request_Status(Status, TrCode, MsgCode, MsgName);
	}


};



// �ֹ��̺�Ʈ
class CYFOrderEvent: public IDispEventImpl<
	0,
	CYFOrderEvent,
	&DIID_IYFOrderEvents,
	&LIBID_YFExpertPlus,
	1,
	0>
{
public:

	BEGIN_SINK_MAP(CYFOrderEvent)
		SINK_ENTRY_EX(0, DIID_IYFOrderEvents, 204, Status)
		SINK_ENTRY_EX(0, DIID_IYFOrderEvents, 205, ReceiveData)
	END_SINK_MAP()

	CELWOrderDlg* m_Parent;
	
	CYFOrderEvent(CELWOrderDlg* Parent)
	{
		m_Parent = Parent;
	}

	void __stdcall ReceiveData(BSTR TrCode, BSTR Value, BSTR MsgCode, BSTR MsgName)
	{
		m_Parent->Order_ReceiveData(TrCode, Value, MsgCode, MsgName);
	}

	void __stdcall Status(long Status, BSTR TrCode, BSTR MsgCode, BSTR MsgName)
	{
		m_Parent->Order_Status(Status, TrCode, MsgCode, MsgName);
	}

};

// �ǽð������� �̺�Ʈ��ü
class CYFRealEvent : public IDispEventImpl<
	0,
	CYFRealEvent,
	&DIID_IYFRealEvents,
	&LIBID_YFExpertPlus,
	1,
	0>
{
public:

	BEGIN_SINK_MAP(CYFRealEvent)
		SINK_ENTRY_EX(0, DIID_IYFRealEvents, 204, Status)
		SINK_ENTRY_EX(0, DIID_IYFRealEvents, 205, ReceiveData)
	END_SINK_MAP()

	CELWOrderDlg* m_Parent;
	
	CYFRealEvent(CELWOrderDlg* Parent)
	{
		m_Parent = Parent;
	}
	
	void __stdcall ReceiveData(BSTR TrCode, BSTR Value, BSTR MsgCode, BSTR MsgName)
	{

		m_Parent->Real_ReceiveData(TrCode, Value, MsgCode, MsgName);
	}

	void __stdcall Status(long Status, BSTR TrCode, BSTR MsgCode, BSTR MsgName)
	{

		m_Parent->Real_Status(Status, TrCode, MsgCode, MsgName);
	}

};

// ����Ʈ ������ ó�� �̺�Ʈ
class CYFValueListEvent : public IDispEventImpl<
	0,
	CYFValueListEvent,
	&DIID_IYFValueListEvents,
	&LIBID_YFExpertPlus,
	1,
	0>
{
public:

	BEGIN_SINK_MAP(CYFValueListEvent)
		SINK_ENTRY_EX(0, DIID_IYFValueListEvents, 201, Update)
	END_SINK_MAP()

	CELWOrderDlg* m_Parent;
	
	CYFValueListEvent(CELWOrderDlg* Parent)
	{
		m_Parent = Parent;
	}
	
	void __stdcall Update(long RecNo)
	{
		m_Parent->ValueList_Update(RecNo);
	}


};


#endif __EVENTS_H__
#pragma once

// COrdBase ��� ����Դϴ�.

class COrdMinSet : public CObject
{
public:
	CString		m_strMMType;				//�Ÿű��� '1':�ŵ�,  '2':�ż�
	CString		m_strMarketType;			//S(Stock), E(ELW), F(FUT), O(OPT)
	enORDTYPE	m_enOrdType;				//�ֹ����� '1':�Ϲ��ֹ�, '2':ȣ�������ֹ�, '3':�ð������ֹ�	
};

class COrdBase : public COrdMinSet
{
public:
	COrdBase();
	COrdBase(const COrdBase &obj) { *this = obj; };
	virtual ~COrdBase();

	virtual void	Copy(const COrdBase& item);
	virtual COrdBase& operator = (const COrdBase& item);	

public:
	BOOL		m_bCredit;
	// 20120723 ssj - �����ڵ��ֹ� >>
//	CString		m_strUserID;				//HTS User ID	
//	CString		m_strAccount;				//���¹�ȣ
//	CString		m_strAccPass;				//���º�й�ȣ
	// 20120723 ssj - �����ڵ��ֹ� <<

	int			m_nAutoFlag;				//���ڵ� Flag '0':�ڵ�, '1':���ڵ�
	BOOL		m_bSms;						//SMS�뺸 ����
	CString		m_strItemCode;				//�����ڵ�
	CString		m_strItemName;				//�����
	CString		m_strExpireDate;			//������ //>>[KSJ000000026] �ſ��ֹ��߰�, �ֹ������߰�
	CString		m_strPcIp;

// 	CString		m_strMMType;				//�Ÿű��� '1':�ŵ�,  '2':�ż�
// 	CString		m_strMarketType;			//S(Stock), E(ELW), F(FUT), O(OPT)
// 	enORDTYPE	m_enOrdType;				//�ֹ����� '1':�Ϲ��ֹ�, '2':ȣ�������ֹ�, '3':�ð������ֹ�	
//	User_Define	stUser_Define;				//���� ����ü(���ǰ˻����� ����ϴ� ����ü)

public:
	CString		GetOrdMarketType()   {return m_strMarketType; };
	enORDTYPE	GetCurOrderType()    {return m_enOrdType; };
	CString		GetCurMMType()	     {return m_strMMType; };
	// 20120723 ssj - �����ڵ��ֹ� >>
	//CString		GetUserID()			 {return m_strUserID;};
	//CString		GetAccountNum()		 {return m_strAccount;};
	//CString		GetAccountPass()	 {return m_strAccPass;};
	// 20120723 ssj - �����ڵ��ֹ� <<

	int			GetOrderFlag()		 {return m_nAutoFlag;};
	BOOL		GetIsSmsAvailable()	 {return m_bSms;};
	CString		GetItemCode()		 {return m_strItemCode;};
	CString		GetItemName()		 {return m_strItemName;};
	BOOL		GetCredit()			 {return m_bCredit;};
	CString		GetExpireDate()		 {return m_strExpireDate;};//>>[KSJ000000026] �ſ��ֹ��߰�, �ֹ������߰�
	CString		GetIP()				 {return m_strPcIp; };

	void		SetOrdMarketType(CString strMarket)		 {m_strMarketType   = strMarket; };
	void		SetCurOrderType(enORDTYPE enOrdType)     {m_enOrdType	    = enOrdType; };
	void		SetCurMMType(CString strMMType)			 {m_strMMType       = strMMType; };

	// 20120723 ssj - �����ڵ��ֹ� >>
	//void		SetUserID(CString strUserID)			 {m_strUserID		= strUserID;};
	//void		SetAccountNum(CString strAccount)		 {m_strAccount		= strAccount;};
	//void		SetAccountPass(CString strPass)			 {m_strAccPass		= strPass;};
	// 20120723 ssj - �����ڵ��ֹ� <<
	void		SetOrderFlag(int nAutoFlag)				 {m_nAutoFlag		= nAutoFlag;};
	void		SetIsSmsAvailable(BOOL bSms)			 {m_bSms			= bSms;};
	void		SetItemCode(CString strItemCode)		 {m_strItemCode		= strItemCode;};
	void		SetItemName(CString strItemName)		 {m_strItemName		= strItemName;};
	void		SetCredit(BOOL bCredit)					 {m_bCredit			= bCredit;};
	void		SetExpireDate(CString strDate)			 {m_strExpireDate   = strDate; };//>>[KSJ000000026] �ſ��ֹ��߰�, �ֹ������߰�
	void		SetIP(CString strIP)					 {m_strPcIp		= strIP;};
};









#pragma once

// COrdBase 명령 대상입니다.

class COrdMinSet : public CObject
{
public:
	CString		m_strMMType;				//매매구분 '1':매도,  '2':매수
	CString		m_strMarketType;			//S(Stock), E(ELW), F(FUT), O(OPT)
	enORDTYPE	m_enOrdType;				//주문종류 '1':일반주문, '2':호가분할주문, '3':시간분할주문	
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
	// 20120723 ssj - 서버자동주문 >>
//	CString		m_strUserID;				//HTS User ID	
//	CString		m_strAccount;				//계좌번호
//	CString		m_strAccPass;				//계좌비밀번호
	// 20120723 ssj - 서버자동주문 <<

	int			m_nAutoFlag;				//반자동 Flag '0':자동, '1':반자동
	BOOL		m_bSms;						//SMS통보 여부
	CString		m_strItemCode;				//종목코드
	CString		m_strItemName;				//종목명
	CString		m_strExpireDate;			//대출일 //>>[KSJ000000026] 신용주문추가, 주문구분추가
	CString		m_strPcIp;

// 	CString		m_strMMType;				//매매구분 '1':매도,  '2':매수
// 	CString		m_strMarketType;			//S(Stock), E(ELW), F(FUT), O(OPT)
// 	enORDTYPE	m_enOrdType;				//주문종류 '1':일반주문, '2':호가분할주문, '3':시간분할주문	
//	User_Define	stUser_Define;				//조건 구조체(조건검색에서 사용하는 구조체)

public:
	CString		GetOrdMarketType()   {return m_strMarketType; };
	enORDTYPE	GetCurOrderType()    {return m_enOrdType; };
	CString		GetCurMMType()	     {return m_strMMType; };
	// 20120723 ssj - 서버자동주문 >>
	//CString		GetUserID()			 {return m_strUserID;};
	//CString		GetAccountNum()		 {return m_strAccount;};
	//CString		GetAccountPass()	 {return m_strAccPass;};
	// 20120723 ssj - 서버자동주문 <<

	int			GetOrderFlag()		 {return m_nAutoFlag;};
	BOOL		GetIsSmsAvailable()	 {return m_bSms;};
	CString		GetItemCode()		 {return m_strItemCode;};
	CString		GetItemName()		 {return m_strItemName;};
	BOOL		GetCredit()			 {return m_bCredit;};
	CString		GetExpireDate()		 {return m_strExpireDate;};//>>[KSJ000000026] 신용주문추가, 주문구분추가
	CString		GetIP()				 {return m_strPcIp; };

	void		SetOrdMarketType(CString strMarket)		 {m_strMarketType   = strMarket; };
	void		SetCurOrderType(enORDTYPE enOrdType)     {m_enOrdType	    = enOrdType; };
	void		SetCurMMType(CString strMMType)			 {m_strMMType       = strMMType; };

	// 20120723 ssj - 서버자동주문 >>
	//void		SetUserID(CString strUserID)			 {m_strUserID		= strUserID;};
	//void		SetAccountNum(CString strAccount)		 {m_strAccount		= strAccount;};
	//void		SetAccountPass(CString strPass)			 {m_strAccPass		= strPass;};
	// 20120723 ssj - 서버자동주문 <<
	void		SetOrderFlag(int nAutoFlag)				 {m_nAutoFlag		= nAutoFlag;};
	void		SetIsSmsAvailable(BOOL bSms)			 {m_bSms			= bSms;};
	void		SetItemCode(CString strItemCode)		 {m_strItemCode		= strItemCode;};
	void		SetItemName(CString strItemName)		 {m_strItemName		= strItemName;};
	void		SetCredit(BOOL bCredit)					 {m_bCredit			= bCredit;};
	void		SetExpireDate(CString strDate)			 {m_strExpireDate   = strDate; };//>>[KSJ000000026] 신용주문추가, 주문구분추가
	void		SetIP(CString strIP)					 {m_strPcIp		= strIP;};
};









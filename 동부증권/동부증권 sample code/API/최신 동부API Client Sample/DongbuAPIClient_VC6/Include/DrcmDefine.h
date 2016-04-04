#define		R_S31				"S31"		// 현물현재가
#define		R_S32				"S32"		// 현물현재가
#define		R_X22				"X22"		// 현물호가
#define		R_SC0				"SC0"		// 선물 현재가 
#define		R_SH0				"SH0"		// 선물 호가1
#define		R_SH2				"SH2"		// 선물 호가2
#define		R_OC0				"OC0"		// 옵션 현재가 
#define		R_OH0				"OH0"		// 옵션 호가1
#define		R_OH2				"OH2"		// 옵션 호가
#define		R_ELC				"ELC"		// ELW 현재가
#define		R_ELH				"ELH"		// ELW 호가	
#define		R_JC0				"JC0"		// 주식선물 현재가
#define		R_JH0				"JH0"		// 주식선물 호가
#define		R_OPC				"OPC"		// 주식옵션 현재가	
#define		R_OPH				"OPH"		// 주식옵션 호가

#define		R_XF2				"XF2"		// 체결
#define		R_XF3				"XF3"		// 잔고

enum eDrdsData{eS31, eS32, eX22, 
			   eSC0, eSH2, 
			   eOC0, eOH2, 
			   eELC, eELH, 
			   eJC0, eJH0, 
			   eOPC, eOPH, 
			   eXF2, eXF3,
			   eSH0, eOH0, 
				};

#define MAX_DRDS_PACKET_LEN			4096
typedef struct  
{
	char Name[32];
	char Field[32];
	char Key[32];
	UINT Id;
	int  Len;
	char Data[MAX_DRDS_PACKET_LEN];
} DrdsData;

#define		SIZE_DrdsData		sizeof(DrdsData)


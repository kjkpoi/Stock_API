#define		R_S31				"S31"		// �������簡
#define		R_S32				"S32"		// �������簡
#define		R_X22				"X22"		// ����ȣ��
#define		R_SC0				"SC0"		// ���� ���簡 
#define		R_SH0				"SH0"		// ���� ȣ��1
#define		R_SH2				"SH2"		// ���� ȣ��2
#define		R_OC0				"OC0"		// �ɼ� ���簡 
#define		R_OH0				"OH0"		// �ɼ� ȣ��1
#define		R_OH2				"OH2"		// �ɼ� ȣ��
#define		R_ELC				"ELC"		// ELW ���簡
#define		R_ELH				"ELH"		// ELW ȣ��	
#define		R_JC0				"JC0"		// �ֽļ��� ���簡
#define		R_JH0				"JH0"		// �ֽļ��� ȣ��
#define		R_OPC				"OPC"		// �ֽĿɼ� ���簡	
#define		R_OPH				"OPH"		// �ֽĿɼ� ȣ��

#define		R_XF2				"XF2"		// ü��
#define		R_XF3				"XF3"		// �ܰ�

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


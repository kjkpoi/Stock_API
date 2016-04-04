
#define		R_S31				"S31"		// �������簡
#define		R_S32				"S32"		// �������簡
#define		R_X12				"X12"		// ����ȣ��

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
#define		R_MC0				"MC0"		// CME���� ���簡 
#define		R_MH0				"MH0"		// CME���� ȣ��1

#define		R_XF2				"XF2"		// ����ü��
#define		R_XF3				"XF3"		// �����ܰ�
#define		R_XF5				"XF5"		// CME ü��
#define		R_XF6				"XF6"		// CME �ܰ�

#define		R_XX1				"XX1"		// �ֽ�ü��
#define		R_XX6				"XX6"		// �ֽ��ܰ�
#define		R_XX9				"XX9"		// �ֽ��ܰ�(�ſ�)


#define		ID_PRODUCT_FUT		0		//����
#define		ID_PRODUCT_OPT		1		//�ɼ�
#define		ID_PRODUCT_SFUT		2       //�ֽļ���
#define		ID_PRODUCT_SOPT		3       //�ֽĿɼ�
#define		ID_PRODUCT_CME		4		//CME����

#define		ID_PRODUCT_SK		5       //�ֽ�


#define		ID_PRODUCT_FO		10		//����
#define		ID_PRODUCT_SFO		11		//�ֽļ���



enum eDrdsData{eS31, eS32, eX12, 
			   eSC0, eSH2, 
			   eOC0, eOH2, 
			   eELC, eELH, 
			   eJC0, eJH0, 
			   eOPC, eOPH, 
			   eXF2, eXF3,
			   eSH0, eOH0, 
			   eMC0, eMH0,
			   eXF5, eXF6,
			   eXX1, eXX6, eXX9
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


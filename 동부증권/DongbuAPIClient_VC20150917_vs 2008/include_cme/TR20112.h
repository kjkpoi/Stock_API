/**************************************************************/
/* 04. ���α׷����    : {CME���� ����Ȳ}       	   */
/**************************************************************/

#ifndef _DEFINEDLL_TR20112_
#define	_DEFINEDLL_TR20112_

typedef struct
{
	char        accno [20];			//���¹�ȣ
	char        pass [8];			//�Էº�й�ȣ
	//char        date [8];			//�ֹ���
	
	char        janggubun [1];		//�ܰ��򰡱��� #0:�⺻����1:�̵���չ�2:���Լ���� (������ '0'�� ���)
	char        futuregubun [1];	//���������򰡱���  #2:��������1:���ʰ�
	char        ip_addr [16];		//privateip
	char		nxtKey [19];		//����Ű:0 :O_SETCONTBTNKEY    -> ���� 19����Ʈ
} TR_20112_I;


typedef struct
{
	char        data11 [15]; //��Ź���Ѿ�
	char        data12 [15]; //��Ź����
	char        data13 [15]; //��Ź���
	
	char        data21 [15]; //��Ź���ű��Ѿ�
	char        data22 [15]; //������Ź���űݾ�
	char        data23 [14]; //�������ű��Ѿ�
	char        data24 [15]; //�����������űݾ�
	
	char        data31 [14]; //�߰����ű��Ѿ�
	char        data32 [15]; //�����߰����űݾ�
	char        data33 [14]; //�ֹ������ѱݾ�
	char        data34 [15]; //�����ֹ����ɱݾ�
	
	char        data41 [14]; //���Ⱑ���ѱݾ�
	char        data42 [15]; //���Ⱑ�����ݾ�
	
	char		nxtKey [19];  //����Ű:0 :O_SETCONTBTNKEY    -> ���� 19����Ʈ
	
} TR_20112_O;

#endif
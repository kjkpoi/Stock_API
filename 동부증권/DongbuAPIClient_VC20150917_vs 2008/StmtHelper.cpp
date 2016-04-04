#include "stdafx.h"
#include "StmtHelper.h"

#include "include_auto/globalauto.h"

CStmtHelper::CStmtHelper()
{
}

CStmtHelper::~CStmtHelper()
{
}

CString CStmtHelper::GetBuySellStr(CString strVal)
{
	// 1:�ŵ�, 2:�ż�
	if (strVal == "1")
		return "�ŵ�";
	else
		return "�ż�";
}

CString CStmtHelper::GetPercentWonTick(CString strVal)
{
	// 1: ��, 2: %, 3: Tick
	if (strVal == "1")
		return "��";
	else if (strVal == "2")
		return "%";
	else
		return "Tick";
}

CString CStmtHelper::GetParsedCondText(int nIndexType, CString strArg1, CString strArg2, CString strArg3, CString strArg4, CString strArg5)
{
	CString strRet;

	CString strCommaArg1 = strArg1.Trim();
	CString strCommaArg2 = strArg2.Trim();
	CString strCommaArg3 = strArg3.Trim();
	CString strCommaArg4 = strArg4.Trim();
	CString strCommaArg5 = strArg5.Trim();
	
	switch (nIndexType)
	{
	case 100: // �Ϲ��ֹ�
		strRet.Format("�Ϲ��ֹ�%s, %d%s", GetBuySellStr(strArg1), atol(strArg2), GetPercentWonTick(strArg3));
		break;
	case 101: // ȣ�������ֹ�
		strRet.Format("ȣ�������ֹ�%s, %d%s", GetBuySellStr(strArg1), atol(strArg2), GetPercentWonTick(strArg3));
		break;
	case -101 : /* �ս� ���ѷ�     */
		strRet.Format("�ս����ѷ� %.2f%% ", atof(strArg1));
		break;
	case -102 : /* ��ǥ ���ͷ�     */
		strRet.Format("��ǥ���ͷ� %.2f%% ", atof(strArg1));
		break;
	case -105 : /* ���� ��������� */
		strRet.Format("��ǥ���� %.2f%% �ʰ� �� �ְ� ���  %.2f%% �϶� �Ǵ�\n"
			"                                     %.2f%% ��ǥ����",
			atof(strArg1), atof(strArg2), atof(strArg3));
		break;
	case -107 : /* �ս� ��������� */
		/* ���Ǻ��濡 ���� comment ���� - 20110804 jini */
		strRet.Format("�սǺ��� %.2f%% ���� �� �ս����Ѱ� ���\n"
			"         %.2f%% ��� �Ǵ� %.2f%% �߰��϶�",
			atof(strArg1), atof(strArg2), atof(strArg3));
		break;
	case -111 : /* �ս� ����ƽ     */
		strRet.Format("�ս�����ƽ %dTick ", atol(strArg1));
		break;
	case -112 : /* ��ǥ����ƽ     */
		strRet.Format("��ǥ����ƽ %dTick ", atol(strArg1));
		break;
	case -115 : /* ��ǥ����ƽ     */
		strRet.Format("��ǥ���� %dTick �ʰ� �� �ְ� ��� %dTick �϶�", 
			atol(strArg1), atol(strArg2));
		break;
	case -117 : /* �սǺ���ƽ     */
		strRet.Format("�սǺ��� %dTick ���� �� �ս����Ѱ� ��� %dTick ��� �Ǵ� %dTick �϶�", 
			atol(strArg1), atol(strArg2),
			atol(strArg3));
		break;
	case -121 : /* �ս����Ѱ�     */
		InsertComma(strCommaArg1);
		strRet.Format("�ս����Ѱ� %s��",
			strCommaArg1);
		break;
	case -122 : /* ��ǥ���Ͱ�     */
		InsertComma(strCommaArg1);
		strRet.Format("��ǥ���Ͱ� %s��",
			strCommaArg1);
		break;
	case -125 : /* ��ǥ���� ��     */
		InsertComma(strCommaArg1);
		InsertComma(strCommaArg2);
		strRet.Format("��ǥ���� %s�� �ʰ� �� �ְ� ��� %s�� �϶�",
			strCommaArg1, strCommaArg2);
		break;
	case -127 : /* �սǺ��� ��     */
		InsertComma(strCommaArg1);
		InsertComma(strCommaArg2);
		InsertComma(strCommaArg3);
		strRet.Format("�սǺ��� %s�� ���� �� �ս����Ѱ� ��� %s�� ��� �Ǵ� %s�� �϶�",
			strCommaArg1, strCommaArg2,
			strCommaArg3);
		break;
	case -108 : /* ��������     */
		strRet.Format("����û�� %02d:%02d:%02d �ð��� û�갡�� ������ ���尡�� �ֹ�",
			atol(strArg1) / 10000,
			(atol(strArg1) % 10000) / 100,
			atol(strArg1) % 100 );
		break;
	case -201 : /* �������� - �ֽ� */
		InsertComma(strCommaArg4);
		strRet.Format("�ֽ� %s %s %s %s ",
			strArg1, 
			setStr_price(atol(strArg2)),
			setStr_equal(atol(strArg3)),
			strCommaArg4);
		break;
	case -202 : /* �������� - ���� */
		InsertComma(strCommaArg4);
		strRet.Format("���� %s %s %s %s ",
			strArg1,
			setStr_price(atol(strArg2)),
			setStr_equal(atol(strArg3)),
			strCommaArg4);
		break;
	case -203 : /* �������� - ���� */
		InsertComma(strCommaArg4);
		strRet.Format("���� %s %s %s %s ",
			strArg1,
			setStr_price(atol(strArg2)),
			setStr_equal(atol(strArg3)),
			strCommaArg4);
		break;
	case -204 : /* �������� - �ɼ� */
		InsertComma(strCommaArg4);
		strRet.Format("�ɼ� %s %s %s %s ",
			strArg1,
			setStr_price(atol(strArg2)),
			setStr_equal(atol(strArg3)),
			strCommaArg4);
		break;
	case -301 : /* �⺻���� - A */
	case -307 : /* �⺻���� - A */
		InsertComma(strCommaArg3);
		strRet.Format("%s %s %s ",
			setStr_price(atol(strArg1)),
			setStr_equal(atol(strArg2)),
			strCommaArg3);
		break;
	case -302 : /* �⺻���� - B */
		strRet.Format("���簡 %s %s ",
			setStr_equal(atol(strArg1)),
			setStr_pre(atol(strArg2)) );
		break;
	case -303 : /* �⺻���� - C */
		strRet.Format("���ϰŷ��� %s %s ",
			setStr_equal(atol(strArg1)),
			setStr_volume(atol(strArg2)) );
		break;
	case -304 : /* �⺻���� - D */
		strRet.Format("%s %s ���� ",
			setStr_day4new(atol(strArg1)),
			setStr_new(atol(strArg2)) );
		break;
	case -305 : /* �⺻���� - E */
		strRet.Format("���� %s %s ",
			setStr_day4updown(atol(strArg1)),
			setStr_updown(atol(strArg2)) );
		break;
	case -106 : /* �⺻���� - F */
		strRet.Format("�����ð� %02d:%02d:%02d ",
			atol(strArg1) / 10000,
			(atol(strArg1) % 10000) / 100,
			atol(strArg1) % 100 );
		break;
	case -401 : /* ��ǥ���� - ���� */
		strRet.Format("%s������ %s���� %s ",
			setStr_1avg4through(atol(strArg1)),
			setStr_2avg4through(atol(strArg2)),
			setStr_through(atol(strArg3)) );
		break;
	case -402 : /* ��ǥ���� - �迭 */
		strRet.Format("%s, %s, %s %s ",
			setStr_1avg4range(atol(strArg1)),
			setStr_2avg4range(atol(strArg2)),
			setStr_3avg4range(atol(strArg3)),
			setStr_range(atol(strArg4))) ;
		break;
	case -403 : /* ��ǥ���� - MACD */
		strRet.Format("MACD(%s, %s, %s)�� %s %s ",
			setStr_1var4macd(atol(strArg1)),
			setStr_2var4macd(atol(strArg2)),
			setStr_3var4macd(atol(strArg3)),
			setStr_signal4macd(atol(strArg4)),
			setStr_through(atol(strArg5)));
		break;
	case -404 : /* ��ǥ���� - STOCHASTIC */
		strRet.Format("Stochastic Slow(%s, %s, %s)�� %s %s ",
			setStr_1var4stoch(atol(strArg1)),
			setStr_2var4stoch(atol(strArg2)),
			setStr_3var4stoch(atol(strArg3)),
			setStr_signal4stoch(atol(strArg4)),
			setStr_through(atol(strArg5)) );
		break;
	default   :
		strRet.Format("�� �� ���� ���� (%d) ", nIndexType); 
		break;
	}
	
	if (strRet.GetLength() > 0)
		strRet = strRet + "\n";

	return strRet;
}


/*--------------------------------------------------------------------------*
 * ���簡/���/�����/�ŷ���
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_price( int aiI )
{
   CString strBuf;
   
   switch( aiI )
   {
      case 0 :
             strBuf.Format("���簡");
             break;
      case 1 :
             strBuf.Format("���");
             break;
      case 2 :
             strBuf.Format("�����");
             break;
      case 3 :
             strBuf.Format("�ŷ���");
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * >/>=/==/<=/<
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_equal( int aiI )
{
   CString strBuf;

   switch ( aiI )
   {
      case 0 :
             strBuf.Format(">");
             break;
      case 1 :
             strBuf.Format(">=");
             break;
      case 2 :
             strBuf.Format("==");
             break;
      case 3 :
             strBuf.Format("<=");
             break;
      case 4 :
             strBuf.Format("<");
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * ���Ͻð�/��/����/����/���Ѱ�/���Ѱ�
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_pre( int aiI )
{
   CString strBuf;

   switch( aiI )
   {
      case 0 :
             strBuf.Format("���Ͻð�");
             break;
      case 1 :
             strBuf.Format("���ϰ�");
             break;
      case 2 :
             strBuf.Format("��������");
             break;
      case 3 :
             strBuf.Format("��������");
             break;
      case 4 :
             strBuf.Format("���Ѱ�");
             break;
      case 5 :
             strBuf.Format("���Ѱ�");
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * ���ϰŷ���/5�� ��հŷ���/10�� ��հŷ���/20�� ��հŷ���
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_volume( int aiI )
{
   CString strBuf;

   switch( aiI )
   {
      case 0 :
             strBuf.Format("���ϰŷ���");
             break;
      case 1 :
             strBuf.Format("5�� ��հŷ���");
             break;
      case 2 :
             strBuf.Format("10�� ��հŷ���");
             break;
      case 3 :
             strBuf.Format("20�� ��հŷ���");
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 3��/5��/10��/20��/40��/60��
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_day4new( int aiI )
{
   CString strBuf;


   switch( aiI )
   {
      case 0 : 
             strBuf.Format("3��");
             break;
      case 1 : 
             strBuf.Format("5��");
             break;
      case 2 : 
             strBuf.Format("10��");
             break;
      case 3 : 
             strBuf.Format("20��");
             break;
      case 4 : 
             strBuf.Format("40��");
             break;
      case 5 : 
             strBuf.Format("60��");
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * �Ű�/������
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_new( int aiI )
{
   CString strBuf;
  

   switch( aiI )
   {
      case 0 :
             strBuf.Format("�Ű�");
             break;
      case 1 :
             strBuf.Format("������");
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}


/*--------------------------------------------------------------------------*
 * 1��/2��/3��/4��/5��
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_day4updown( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 : 
      case 1 : 
      case 2 : 
      case 3 : 
      case 4 : 
             strBuf.Format("%d��", (aiI + 1) );
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * ���/�϶�/����/����/���/����
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_updown( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("���");
             break;
      case 1 :
             strBuf.Format("�϶�");
             break;
      case 2 :
             strBuf.Format("����");
             break;
      case 3 :
             strBuf.Format("����");
             break;
      case 4 :
             strBuf.Format("���");
             break;
      case 5 :
             strBuf.Format("����");
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 1/2/3/4/5/10/15/20/40/60
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_1avg4through( int aiI )
{
   CString strBuf;


   switch( aiI )
   {
      case 0 :
      case 1 :
      case 2 :
      case 3 :
      case 4 :
             strBuf.Format("%d", (aiI + 1));
             break;
      case 5 :
             strBuf.Format("%d", 10);
             break;
      case 6 :
             strBuf.Format("%d", 15);
             break;
      case 7 :
             strBuf.Format("%d", 20);
             break;
      case 8 :
             strBuf.Format("%d", 40);
             break;
      case 9 :
             strBuf.Format("%d", 60);
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 5/10/15/20/40/60/120/150/200
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_2avg4through( int aiI )
{
   CString strBuf;


   switch( aiI )
   {
      case 0 :
             strBuf.Format("%d", 5);
             break;
      case 1 :
             strBuf.Format("%d", 10);
             break;
      case 2 :
             strBuf.Format("%d", 15);
             break;
      case 3 :
             strBuf.Format("%d", 20);
             break;
      case 4 :
             strBuf.Format("%d", 40);
             break;
      case 5 :
             strBuf.Format("%d", 60);
             break;
      case 6 :
             strBuf.Format("%d", 120);
             break;
      case 7 :
             strBuf.Format("%d", 150);
             break;
      case 8 :
             strBuf.Format("%d", 200);
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * ���⵹��/���⵹��
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_through( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("���⵹��");
             break;
      case 1 :
             strBuf.Format("���⵹��");
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 1/2/3/4/5/10
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_1avg4range( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
      case 1 :
      case 2 :
      case 3 :
      case 4 :
             strBuf.Format("%d", (aiI + 1));
             break;
      case 5 :
             strBuf.Format("%d", 10);
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 10/15/20
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_2avg4range( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("%d", 10);
             break;
      case 1 :
             strBuf.Format("%d", 15);
             break;
      case 2 :
             strBuf.Format("%d", 20);
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 40/60/120/150/200
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_3avg4range( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("%d", 40);
             break;
      case 1 :
             strBuf.Format("%d", 60);
             break;
      case 2 :
             strBuf.Format("%d", 120);
             break;
      case 3 :
             strBuf.Format("%d", 150);
             break;
      case 4 :
             strBuf.Format("%d", 200);
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * ���迭/���迭
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_range( int aiI )
{
   CString strBuf;
   
   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("���迭");
             break;
      case 1 :
             strBuf.Format("���迭");
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 5/10/12
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_1var4macd( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("%d", 5);
             break;
      case 1 :
             strBuf.Format("%d", 10);
             break;
      case 2 :
             strBuf.Format("%d", 12);
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 15/20/26
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_2var4macd( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("%d", 15);
             break;
      case 1 :
             strBuf.Format("%d", 20);
             break;
      case 2 :
             strBuf.Format("%d", 26);
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 3/6/9
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_3var4macd( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("%d", 3);
             break;
      case 1 :
             strBuf.Format("%d", 6);
             break;
      case 2 :
             strBuf.Format("%d", 9);
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * Signal/0
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_signal4macd( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("signal");
             break;
      case 1 :
             strBuf.Format("0");
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;

   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 5/10/15
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_1var4stoch( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("%d", 5);
             break;
      case 1 :
             strBuf.Format("%d", 10);
             break;
      case 2 :
             strBuf.Format("%d", 15);
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 3/5/7
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_2var4stoch( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("%d", 3);
             break;
      case 1 :
             strBuf.Format("%d", 5);
             break;
      case 2 :
             strBuf.Format("%d", 7);
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * 3/5/7
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_3var4stoch( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("%d", 3);
             break;
      case 1 :
             strBuf.Format("%d", 5);
             break;
      case 2 :
             strBuf.Format("%d", 7);
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}

/*--------------------------------------------------------------------------*
 * Signal/20/40/60/80
 *--------------------------------------------------------------------------*/
CString CStmtHelper::setStr_signal4stoch( int aiI )
{
   CString strBuf;

   //memset(sBuf, 0x00, sizeof(sBuf));

   switch( aiI )
   {
      case 0 :
             strBuf.Format("signal");
             break;
      case 1 :
             strBuf.Format("20");
             break;
      case 2 :
             strBuf.Format("40");
             break;
      case 3 :
             strBuf.Format("60");
             break;
      case 4 :
             strBuf.Format("80");
             break;
      default:
             strBuf.Format("?(%d)", aiI);
             break;
   }

   return strBuf;
}
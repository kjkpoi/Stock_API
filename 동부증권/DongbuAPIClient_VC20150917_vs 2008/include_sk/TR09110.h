#ifndef _DEFINEDLL_TR09110_
#define	_DEFINEDLL_TR09110_

/**************************************************************/
/* 01. ���α׷���      : {tr_09110.h}                         */
/* 04. ���α׷����    : {�ֽ����簡}                         */
/* 05. REMARKS ����    : {}                                   */         
/**************************************************************/


#define TR_09110    "09110"

typedef struct
{
	char code[6]; /* �����ڵ� */
} TR_09110_I;

typedef struct
{
	char price       [9];  /* �� �� ��     */
	char sign        [1];  /* �����ȣ     */
	char change      [9];  /* ���ϴ��     */
	char updyul      [7];  /* �� �� ��     */
	char uplmtprice  [9];  /* �� �� ��     */
	char changerate  [7];  /* ���Ѱ������� */
	char volume      [12]; /* �����ŷ���   */
	char openam      [9];  /* ��    ��     */
	char changerate1 [7];  /* �ð� ������ */
	char offer       [9];  /* �ŵ�ȣ��     */
	char high        [9];  /* ��    ��     */
	char changerate2 [7];  /* �� ������ */
	char bid         [9];  /* �ż�ȣ��     */
	char low         [9];  /* ��    ��     */
	char changerate3 [7];  /* ���� ������ */
	char predicprice[9];   /* ����ü�ᰡ�� */
	char predicvol  [12];  /* ����ü����� */
	char dnlmtprice  [9];  /* �� �� ��     */
	char changerate4 [7];  /* ���Ѱ������� */

} TR_09110_JONG;

typedef struct
{

	char  hname    [20];/* �ѱ۸� */
	char  offertot [9]; /* �Ѹŵ�ȣ���ܷ� */
	char  bidtot   [9]; /* �Ѹż�ȣ���ܷ� */

	/* ���簡 ���̺� */
	char             jonglen[6];
	char             jongmsg[5];
	TR_09110_JONG    jong;

} TR_09110_O;



#endif
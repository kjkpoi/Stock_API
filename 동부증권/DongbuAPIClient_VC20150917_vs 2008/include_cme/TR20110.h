#if !defined(AFX_TR_20110_HEADER_)
#define AFX_TR_20110_HEADER_


/*************************************************************/
/* 04. ���α׷����    : {CME���� �ܰ���ȸ}					 */
/*************************************************************/

#define tr_20110MAX		250

typedef struct _TR_20110_I	
{
	char  geja     [20];    /* ������ȣ(3)+���¹�ȣ(8) ->20 */
} TR_20110_I;

typedef struct _TR_20110_S	
{
	char  yakjungtot [17];  /* ��   �����ݾ�                    */
	char  pyungpltot [17];  /* ��   �򰡼���                    */
	char  jumuntot   [17];  /* �ֹ������Ѿ�                     */

	char  amotpyngtot[17];  /* ��   �򰡱ݾ�                    */
	char  realpltot  [17];  /* ���� ��������                    */
	char  jumuncash  [17];  /* �ֹ���������                     */
	char  suikratetot[ 9];  /* ��   ������   7->9               */

} TR_20110_S;

typedef struct _TR_20110_G	
{
	char  jocode     [15];  /* �����ڵ�                8 -> 15  */	
	char  mmgb       [ 5];  /* �Ÿű���                5 ->  5  */
	char  avqty      [15];  /* û�갡��                9 -> 15  */
	char  pnonqty    [15];  /* �����ܰ�                9 -> 15  */
	char  qtychg     [15];  /* ����                    9 -> 15  */
	char  tnonqty    [15];  /* ��������                9 -> 15  */
	char  tnocontqty [15];  /* ��ü���ֹ�����          9 -> 15  */
	char  tnonprc    [12];  /* ���Դܰ�               12 -> 12  */
	char  price      [ 6];  /* ���簡                  6 ->  6  */
	char  pyungpl    [15];  /* �򰡼���               15 -> 15  */
	char  suikrate   [ 9];  /* ������                  9 ->  9  */
	char  tnonamt    [15];  /* �����ݾ�               15 -> 15  */
	char  pyungamt   [15];  /* �򰡱ݾ�               15 -> 15  */
	char  fee        [12];  /* ������                 12 -> 12  */
	char  bid        [ 6];  /* �ż�ȣ��                6 ->  6  */
	char  offer      [ 6];  /* �ŵ�ȣ��                6 ->  6  */
	char  hprice     [ 6];  /* ���Ѱ�                  6 ->  6  */
	char  lprice     [ 6];  /* ���Ѱ�                  6 ->  6  */
	char  gdssect    [ 1];  /* ����Ҽӱ���            1 ->  1  */
	char  resbpl     [15];  /* ���Ͻ�������           15 -> 15  */
	char  jutp       [ 3];  /* �ֹ�����                3 ->  3  */
	char  trdunt     [15];  /* �ŷ�����               15 -> 15  */
	char  tdmemeamt  [15];  /* ���ϸż��Ǵ¸ŵ��ݾ�   15 -> 15  */
	char  memeamt    [15];  /* �ŸŴ����             15 -> 15  */
} TR_20110_G;

typedef struct _tr_20110_o
{
	TR_20110_S		sm;
	char  gridcnt    [  4]; // Grid count
	TR_20110_G  gr[tr_20110MAX];

} TR_20110_O;

#define  SZ_TR20110_I sizeof(TR_20110_I)
#define  SZ_TR20110_G sizeof(TR_20110_G)

#endif //AFX_TR_20110_HEADER_
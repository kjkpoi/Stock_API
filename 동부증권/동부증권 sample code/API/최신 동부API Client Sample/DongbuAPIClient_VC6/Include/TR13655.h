#if !defined(AFX_TR_13655_HEADER_)
#define AFX_TR_13655_HEADER_


/*************************************************************/
/* 04. ���α׷����    : {���� �ܰ���ȸ}					 */
/*************************************************************/
#define tr_13655MAX		250

typedef struct _TR_13655_I	
{
	char  geja     [20];    /* ������ȣ(3)+���¹�ȣ(8) ->20 */
} TR_13655_I;

typedef struct _TR_13655_S	
{
	char  yakjungtot [17];  /* ��   �����ݾ�                    */
	char  pyungpltot [17];  /* ��   �򰡼���                    */
	char  jumuntot   [17];  /* �ֹ������Ѿ�                     */

	char  amotpyngtot[17];  /* ��   �򰡱ݾ�                    */
	char  realpltot  [17];  /* ���� ��������                    */
	char  jumuncash  [17];  /* �ֹ���������                     */
	char  suikratetot[ 9];  /* ��   ������   7->9               */

} TR_13655_S;

typedef struct _TR_13655_G	
{
	char  jocode     [15];  /* �����ڵ�                8 -> 15  */
	char  mmgb_attr  [ 3];  /* �Ÿű���                3 ->  3  */
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
} TR_13655_G;

typedef struct _tr_13655_o
{
	TR_13655_S		sm;
	char  gridcnt    [  4]; // Grid count
	TR_13655_G  gr[tr_13655MAX];

} TR_13655_O;

#define  SZ_TR13655_I sizeof(TR_13655_I)
#define  SZ_TR13655_G sizeof(TR_13655_G)

#endif //AFX_TR_13655_HEADER_
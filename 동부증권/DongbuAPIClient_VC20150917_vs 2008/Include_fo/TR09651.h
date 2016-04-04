#if !defined (_HEADERFILE_TR_09651_H)
#define _HEADERFILE_TR_09651_H
/******************************************************************************
* ���ϸ�     : TR_09651.h                                                     *
* ����       : ���� ȣ����ü��  - �ɼ�		                                  *
*******************************************************************************/

// TR
#define		TR_09651		_T("09651")		// 

//--------------------------------[INPUT ]---------------------------------------##
typedef struct
{
    char jmcode		 [8] ; 	/* �����ڵ�							  	*/
} TR_09651_I;
#define	SZ_09651_I sizeof(TR_09651_I)

//--------------------------------[OUTPUT�ݺ� ]-----------------------------------##
typedef struct
{
	char hotime	 	 [6] ; /* ȣ���ð� 						  int 9(6) */	

    char offercnt5   [4] ; /* 5���� �ŵ�ȣ���Ǽ�                  9(4) */
    char offerrem5   [7] ; /* 5���� �ŵ�ȣ�� �ܷ�                      */
    char offerho5    [7] ; /* 5���� �ŵ�ȣ��                 9(3)v9(2) */

    char offercnt4   [4] ; /* 4���� �ŵ�ȣ���Ǽ�                  9(4) */
    char offerrem4   [7] ; /* 4���� �ŵ�ȣ�� �ܷ�                      */
    char offerho4    [7] ; /* 4���� �ŵ�ȣ��                 9(3)v9(2) */

    char offercnt3   [4] ; /* 3���� �ŵ�ȣ���Ǽ�                  9(4) */
    char offerrem3   [7] ; /* 3���� �ŵ�ȣ�� �ܷ�                 9(6) */
    char offerho3    [7] ; /* 3���� �ŵ�ȣ��                 9(3)v9(2) */

    char offercnt2   [4] ; /* 2���� �ŵ�ȣ���Ǽ�                  9(4) */
    char offerrem2   [7] ; /* 2���� �ŵ�ȣ�� �ܷ�                 9(6) */
    char offerho2    [7] ; /* 2���� �ŵ�ȣ��                 9(3)v9(2) */

    char offercnt1   [4] ; /* 1�켱 �ŵ�ȣ���Ǽ�                  9(4) */
    char offerrem1   [7] ; /* 1     �ŵ�     �ܷ�                 9(6) */
    char offerho1    [7] ; /* 1     �ŵ�ȣ��                 9(3)v9(2) */

    char bidho1      [7] ; /* 1     �ż�ȣ��                 9(3)v9(2) */
    char bidrem1     [7] ; /* 1     �ż��ܷ�                      9(6) */
    char bidcnt1     [4] ; /* 1�켱 �ż�ȣ���Ǽ�                  9(4) */

    char bidho2      [7] ; /* 2���� �ż�ȣ��                 9(3)v9(2) */
    char bidrem2     [7] ; /* 2���� �ż�ȣ�� �ܷ�                 9(6) */
    char bidcnt2     [4] ; /* 2���� �ż�ȣ���Ǽ�                  9(4) */

    char bidho3      [7] ; /* 3���� �ż�ȣ��                 9(3)v9(2) */
    char bidrem3     [7] ; /* 3���� �ż�ȣ�� �ܷ�                 9(6) */
    char bidcnt3     [4] ; /* 3���� �ż�ȣ���Ǽ�                  9(4) */

    char bidho4      [7] ; /* 4���� �ż�ȣ��                 9(3)v9(2) */
    char bidrem4     [7] ; /* 4���� �ż�ȣ�� �ܷ�                      */
    char bidcnt4     [4] ; /* 4���� �ż�ȣ���Ǽ�                  9(4) */

    char bidho5      [7] ; /* 5���� �ż�ȣ��                 9(3)v9(2) */
    char bidrem5     [7] ; /* 5���� �ż�ȣ�� �ܷ�                      */
    char bidcnt5     [4] ; /* 5���� �ż�ȣ���Ǽ�                  9(4) */

    char offertotcnt [5] ; /* �Ѹŵ�ȣ���Ǽ�                      9(5) */
    char offertotrem [7] ; /* �Ѹŵ�ȣ�� �ܷ�                     9(6) */
    char bidtotrem   [7] ; /* �Ѹż� ȣ�� �ܷ�                    9(6) */
    char bidtotcnt   [5] ; /* �Ѹż�ȣ���Ǽ�                      9(5) */

} TR_09651_OG;
#define	SZ_09651_OG sizeof(TR_09651_OG)

//--------------------------------[OUTPUT ]---------------------------------------##
typedef struct
{
    char sign        [1] ; /* ���ϴ�� ��ȣ                            */
                           /* '1':����, '2':���, '3':����             */
                           /* '4':����, '5':�϶�, '6':�⼼����         */
                           /* '7':�⼼���, '8':�⼼����               */
    char price       [7] ; /* ���簡                         9(3)v9(2) */
    char change      [7] ; /* ���ϴ��                       9(3)v9(2) */
    char updyul      [7] ; /* �����                         9999.99   */

    char hprice      [7] ; /* ���Ѱ�                         9(3)v9(2) */
    char lprice      [7] ; /* ���Ѱ�                         9(3)v9(2) */

	char preprice	 [7] ; /* ��������								   */

    char open        [7] ; /* �ð�                           9(3)v9(2) */
    char high        [7] ; /* ��                           9(3)v9(2) */
    char low         [7] ; /* ����                           9(3)v9(2) */

    char volume      [8] ; /* ���� ü�����   (���)              9(6) */
    char theoryprice [7] ; /* �̷а�                         9(3)v9(2) */
    char CurBasis    [7] ; /* ����basis                                */
    char guri        [7];  /* ������                                   */

    char openyak     [8] ; /* �̰��� ��������                          */
    char openyakchg  [6] ; /* �̰��� �������� ���ϴ�� ���� - ����     */

    char k_price     [7] ; /* Kospi200                       9(3)v9(2) */
    char k_sign      [1] ; /* kospi200 �����ȣ                        */
    char k_change    [7] ; /* kospi200 ���ϴ��                        */

    TR_09651_OG hoga[1] ;	

} TR_09651_O;
#define	SZ_09651_O sizeof(TR_09651_O)

#endif //_HEADERFILE_TR_09651_H
#if !defined (_HEADERFILE_TR_09650_H)
#define _HEADERFILE_TR_09650_H
/******************************************************************************
* 파일명     : TR09650.h                                                     *
* 설명       : 선옵 호가별체결  - 선물		                                  *
*******************************************************************************/

// TR
#define		TR_09650		_T("09650")		// 

//--------------------------------[INPUT ]---------------------------------------##
typedef struct
{
    char jmcode		 [8] ; 	/* 종목코드							  	*/
} TR_09650_I;
#define	SZ_09650_I sizeof(TR_09650_I)

//--------------------------------[OUTPUT ]---------------------------------------##
typedef struct
{
    char sign        [1] ; /* 전일대비 부호                            */
                           /* '1':상한, '2':상승, '3':보합             */
                           /* '4':하한, '5':하락, '6':기세상한         */
                           /* '7':기세상승, '8':기세하한               */
    char price       [7] ; /* 현재가                         9(3)v9(2) */
    char change      [7] ; /* 전일대비                       9(3)v9(2) */
    char updyul      [7] ; /* 등락율                         9999.99   */

    char hprice      [7] ; /* 상한가                         9(3)v9(2) */
    char lprice      [7] ; /* 하한가                         9(3)v9(2) */

    char preprice    [7] ; /* 전일종가                       9(3)v9(2) */

    char open        [7] ; /* 시가                           9(3)v9(2) */
    char high        [7] ; /* 고가                           9(3)v9(2) */
    char low         [7] ; /* 저가                           9(3)v9(2) */

    char volume      [8] ; /* 누적 체결수량   (계약)              9(6) */
    char theoryprice [7] ; /* 이론가                         9(3)v9(2) */
    char CurBasis    [7] ; /* 시장basis                                */
    char guri        [7];  /* 괴리율                                   */

    char openyak     [8] ; /* 미결제 약정수량                          */
    char openyakchg  [6] ; /* 미결제 약정수량 전일대비 금일 - 전일     */

    char k_price     [7] ; /* Kospi200                       9(3)v9(2) */
    char k_sign      [1] ; /* kospi200 등락부호                        */
    char k_change    [7] ; /* kospi200 전일대비                        */
    
		char hotime	 	 [6] ; /* 호가시간 						  int 9(6) */	

    char offercnt5   [4] ; /* 5차선 매도호가건수                  9(4) */
    char offerrem5   [6] ; /* 5차선 매도호가 잔량                      */
    char offerho5    [7] ; /* 5차선 매도호가                 9(3)v9(2) */

    char offercnt4   [4] ; /* 4차선 매도호가건수                  9(4) */
    char offerrem4   [6] ; /* 4차선 매도호가 잔량                      */
    char offerho4    [7] ; /* 4차선 매도호가                 9(3)v9(2) */

    char offercnt3   [4] ; /* 3차차 매도호가건수                  9(4) */
    char offerrem3   [6] ; /* 3차차 매도호가 잔량                 9(6) */
    char offerho3    [7] ; /* 3차차 매도호가                 9(3)v9(2) */

    char offercnt2   [4] ; /* 2차선 매도호가건수                  9(4) */
    char offerrem2   [6] ; /* 2차선 매도호가 잔량                 9(6) */
    char offerho2    [7] ; /* 2차선 매도호가                 9(3)v9(2) */

    char offercnt1   [4] ; /* 1우선 매도호가건수                  9(4) */
    char offerrem1   [6] ; /* 1     매도     잔량                 9(6) */
    char offerho1    [7] ; /* 1     매도호가                 9(3)v9(2) */

    char bidho1      [7] ; /* 1     매수호가                 9(3)v9(2) */
    char bidrem1     [6] ; /* 1     매수잔량                      9(6) */
    char bidcnt1     [4] ; /* 1우선 매수호가건수                  9(4) */

    char bidho2      [7] ; /* 2차선 매수호가                 9(3)v9(2) */
    char bidrem2     [6] ; /* 2차선 매수호가 잔량                 9(6) */
    char bidcnt2     [4] ; /* 2차선 매수호가건수                  9(4) */

    char bidho3      [7] ; /* 3차차 매수호가                 9(3)v9(2) */
    char bidrem3     [6] ; /* 3차차 매수호가 잔량                 9(6) */
    char bidcnt3     [4] ; /* 3차차 매수호가건수                  9(4) */

    char bidho4      [7] ; /* 4차선 매수호가                 9(3)v9(2) */
    char bidrem4     [6] ; /* 4차선 매수호가 잔량                      */
    char bidcnt4     [4] ; /* 4차선 매수호가건수                  9(4) */

    char bidho5      [7] ; /* 5차선 매수호가                 9(3)v9(2) */
    char bidrem5     [6] ; /* 5차선 매수호가 잔량                      */
    char bidcnt5     [4] ; /* 5차선 매수호가건수                  9(4) */

    char offertotcnt [5] ; /* 총매도호가건수                      9(5) */
    char offertotrem [6] ; /* 총매도호가 잔량                     9(6) */
    char bidtotrem   [6] ; /* 총매수 호가 잔량                    9(6) */
    char bidtotcnt   [5] ; /* 총매수호가건수                      9(5) */

} TR_09650_O;
#define	SZ_09650_O sizeof(TR_09650_O)

#endif //_HEADERFILE_TR_09650_H
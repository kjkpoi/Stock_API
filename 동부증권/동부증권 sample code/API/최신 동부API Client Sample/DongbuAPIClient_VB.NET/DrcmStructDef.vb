Imports System.Runtime.InteropServices

Module DrcmStructDef

    Public Const DRCM_CONNECT As Integer = -70          '접속
    Public Const DRCM_DISCONNECT As Integer = -71       '접속 해제
    Public Const DRCM_SENDDATA As Integer = -72         'TR전송
    Public Const DRCM_ADVICE As Integer = -73           '실시간 데이타 등록
    Public Const DRCM_UNADVICE As Integer = -74         '실시간 데이타 등록해제
    Public Const DRCM_CLIENT_IP As Integer = -75        '접속 아이피

    Public Const DRCM_DRDS_DATA As Integer = -700       '실시간 데이타 RECEIVE

    Public Const DRCM_MSG_LOGINFAIL As Integer = -1     '로그인 실패
    Public Const DRCM_MSG_SOCKETFAIL As Integer = -2    '서버 접속 실패

    Public Const SIZE_TRCODE As Integer = 5             'TR CODE 글자 길이
    Public Const SIZE_RTCODE As Integer = 3             '실시간 CODE 글자 길이

    Public Const TR_20000 As String = "20000"           '주문
    Public Const TR_13655 As String = "13655"           '잔고조회
    Public Const TR_13615 As String = "13615"           '체결내역조회
    Public Const TR_15813 As String = "15813"           '평가현황조회
    Public Const TR_13653 As String = "13653"           '수수료 조회


    Public Const R_S31 As String = "S31"           '현물현재가       
    Public Const R_S32 As String = "S32"           '현물현재가       
    Public Const R_X22 As String = "X22"           '현물호가         
    Public Const R_SC0 As String = "SC0"           '선물 현재가      
    Public Const R_SH0 As String = "SH0"           '선물 호가(5호가)        
    Public Const R_SH2 As String = "SH2"           '선물 호가        
    Public Const R_OC0 As String = "OC0"           '옵션 현재가      
    Public Const R_OH0 As String = "OH0"           '옵션 호가(5호가)
    Public Const R_OH2 As String = "OH2"           '옵션 호가        
    Public Const R_ELC As String = "ELC"           'ELW 현재가       
    Public Const R_ELH As String = "ELH"           'ELW 호가	       
    Public Const R_JC0 As String = "JC0"           '주식선물 현재가  
    Public Const R_JH0 As String = "JH0"           '주식선물 호가    
    Public Const R_OPC As String = "OPC"           '주식옵션 현재가	 
    Public Const R_OPH As String = "OPH"           '주식옵션 호가    
    Public Const R_XF2 As String = "XF2"           '체결             
    Public Const R_XF3 As String = "XF3"           '잔고 


    'DRCM 에 접속하기 위한 구조체
    Public Structure ST_DRCM_USER

        Public hClientWnd As IntPtr     ' 데이터를 받을 헨들
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=20)> Dim szUserId As String
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=20)> Dim szPwd As String
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=20)> Dim szCertPwd As String
        Public bShowLoginDlg As Boolean


    End Structure

    'PACKET HEADER
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi, pack:=0)> _
    Public Structure STTRHEADER
        <MarshalAs(UnmanagedType.U4, SizeConst:=4)> Dim WindowID As Int32
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=5)> Dim TRCode() As Char
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=6)> Dim MsgCode() As Char
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=82)> Dim Message() As Char
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=2)> Dim CursorPos() As Char
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=3)> Dim Message2Len() As Char
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=3)> Dim APDataLen() As Char


        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=800)> Dim TRData() As Char

        'Dim TRData As Byte        
        'Dim TRData As IntPtr

    End Structure

    '실시간 데이타
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi, pack:=0)> _
   Public Structure DrdsData
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=5)> Dim Name As String
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=6)> Dim Field As String
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=82)> Dim Key As String
        <MarshalAs(UnmanagedType.U4)> Dim Id As Integer
        <MarshalAs(UnmanagedType.U4)> Dim Len As Integer
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=4096)> Dim Data As String

    End Structure

    '잔고조회 >>
    Public Const tr_13655MAX As Integer = 250

    '잔고조회 Input
    Public Structure TR_13655_I
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=20)> Dim geja As String '/* 지점번호(3)+계좌번호(8) ->20 */
    End Structure

    '잔고조회 Output_Header
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi, pack:=0)> _
    Public Structure TR_13655_S
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=17)> Dim yakjungtot() As Char   '/* 총   약정금액
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=17)> Dim pyungpltot() As Char   '/* 총   평가손익
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=17)> Dim jumuntot() As Char     '/* 주문가능총액
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=17)> Dim amotpyngtot() As Char  '/* 총   평가금액
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=17)> Dim realpltot() As Char    '/* 당일 실현손익
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=17)> Dim jumuncash() As Char    '/* 주문가능현금
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=9)> Dim suikratetot() As Char   '/* 총   수익율   7->9
    End Structure

    '잔고조회 Output _반복구간
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi, pack:=0)> _
    Public Structure TR_13655_G
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim jocode() As Char       '/* 종목코드            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=3)> Dim mmgb_attr() As Char     '/* 매매구분            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=5)> Dim mmgb() As Char          '/* 매매구분            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim avqty() As Char        '/* 청산가능            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim pnonqty() As Char      '/* 전일잔고            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim qtychg() As Char       '/* 증감                
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim stnonqty() As Char     '/* 보유수량                           
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim tnocontqty() As Char   '/* 미체결주문수량      
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=12)> Dim tnonprc() As Char      '/* 매입단가            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=6)> Dim price() As Char         '/* 현재가              
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim pyungpl() As Char      '/* 평가손익            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=9)> Dim suikrate() As Char      '/* 수익율              
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim tnonamt() As Char      '/* 약정금액            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim spyungamt() As Char    '/* 평가금액            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=12)> Dim fee() As Char          '/* 수수료              
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=6)> Dim bid() As Char           '/* 매수호가            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=6)> Dim offer() As Char         '/* 매도호가            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=6)> Dim hprice() As Char        '/* 상한가              
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=6)> Dim lprice() As Char        '/* 하한가              
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=1)> Dim sgdssect() As Char      '/* 시장소속구분        
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim sresbpl() As Char      '/* 당일실현손익        
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=3)> Dim jutp() As Char          '/* 주문유형            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim trdunt() As Char       '/* 거래단위            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim tdmemeamt() As Char    '/* 당일매수또는매도금액
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim memeamt() As Char      '/* 매매대금합   
    End Structure

    '잔고조회 Output
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi, pack:=0)> _
    Public Structure TR_13655_O
        Dim sm As TR_13655_S
        <MarshalAs(UnmanagedType.U1)> Dim gridcnt As Char
        Dim gr() As TR_13655_G

    End Structure

    '평가현황 Input 
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi, pack:=0)> _
    Public Structure TR_15813_I
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=20)> Dim accno As String        '계좌번호
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=8)> Dim pass As String          '비밀번호
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=8)> Dim szdate As String        '주문일
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=1)> Dim janggubun As String     '잔고평가구분 #0:기본설정1:이동평균법2:선입선출법 (보통은 '0'을 사용)
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=1)> Dim futuregubun As String   '선물가격평가구분  #2:전일종가1:당초가
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=16)> Dim ip_addr As String      'privateip
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=19)> Dim nxtKey As String       '연속키:0 :O_SETCONTBTNKEY    -> 실제 19바이트

        Public Overrides Function ToString() As String
            Return String.Format("{0}{1}{2}{3}{4}{5}{6}", accno, pass, szdate, janggubun, futuregubun, ip_addr, nxtKey)
        End Function

    End Structure

    '평가현황 Output 
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi, pack:=0)> _
    Public Structure TR_15813_O
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim data11() As Char   '예탁금총액
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim data12() As Char   '예탁현금
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim data13() As Char   '예탁대용

        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim data21() As Char   '위탁증거금총액
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim data22() As Char   '현금위탁증거금액
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=14)> Dim data23() As Char   '유지증거금총액
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim data24() As Char   '현금유지증거금액

        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=14)> Dim data31() As Char   '추가증거금총액
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim data32() As Char   '현금추가증거금액
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=14)> Dim data33() As Char   '주문가능총금액
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim data34() As Char   '현금주문가능금액

        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=14)> Dim data41() As Char   '인출가능총금액
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim data42() As Char   '인출가능현금액

        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=19)> Dim nxtKey() As Char   '연속키:0 :O_SETCONTBTNKEY    -> 실제 19바이트

    End Structure

    '수수료 조회 Input 
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi, pack:=0)> _
    Public Structure TR_13653_I
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=20)> Dim accno As String        '계좌번호
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=18)> Dim pass As String         '비밀번호
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=8)> Dim szdate As String        '주문일        
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=16)> Dim ip_addr As String      'privateip

        Public Overrides Function ToString() As String
            Return String.Format("{0}{1}{2}{3}", accno, pass, szdate, ip_addr)
        End Function

    End Structure

    '수수료조회 Output 
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi, pack:=0)> _
    Public Structure TR_13653_O
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim data1() As Char   '평가예탁금총액
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=16)> Dim data2() As Char   '주문가능금액
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=16)> Dim fee() As Char     '수수료     
    End Structure

    '체결내역 조회 Input 
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi, pack:=0)> _
    Public Structure TR_13615_I
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=20)> Dim geja As String        '지점번호(3)+계좌번호(8) ->20 */
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=8)> Dim passwd As String       '비밀번호
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=1)> Dim sort As String         '정순(1) 역순(2)        
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=100)> Dim userfld As String    '입력그대로 RETURN 

        Public Overrides Function ToString() As String
            Return String.Format("{0}{1}{2}{3}", geja, passwd, sort, userfld)
        End Function

    End Structure

End Module

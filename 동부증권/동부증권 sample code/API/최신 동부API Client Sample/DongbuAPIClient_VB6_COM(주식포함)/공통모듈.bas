Attribute VB_Name = "공통모듈"
Option Explicit


Public Const ID_CONNECT As Integer = -70        '접속
Public Const ID_DISCONNECT As Integer = -71    '접속 해제
Public Const ID_SENDDATA As Integer = -72       'TR전송
Public Const ID_ADVICE_RT As Integer = -73       '실시간 데이타 등록
Public Const ID_UNADVICE_RT As Integer = -74   '실시간 데이타 등록해제
Public Const ID_CLIENT_IP As Integer = -75        '접속 아이피
Public Const ID_F_ACCLIST As Integer = -76       '선물계좌리스트
Public Const ID_DRDS_DATA As Integer = -700   '실시간 데이타 RECEIVE

Public Const ID_MSG_LOGINFAIL As Integer = -1      '로그인 실패
Public Const ID_MSG_SOCKETFAIL As Integer = -2    '서버 접속 실패

Public Enum ORDER_TYPE
    GB_SELL = 1
    GB_BUY = 2
    GB_MODIFY = 3
    GB_CANCEL = 4
End Enum

Public Const GEJA_SIZE = 32
Public Const LEN_GEJANO = 11

'요청
Public Enum CLIENT_REQ_TYPE
    REQ_FUT_ORDER = 1
    REQ_FUT_JANGO = 2
    REQ_FUT_JANGO2 = 3
    REQ_FUT_CHE = 4
    REQ_FUT_EVAL = 5
    REQ_FUT_FEE = 6
    REQ_FUT_DEP_OPT = 7
    REQ_FUT_ORDER_QTY = 8
    REQ_STK_ORDER = 9
    REQ_STK_JANGO = 10
    REQ_STK_CHE = 11
    REQ_STK_EVAL = 12
    
End Enum

'실시간 데이터 요청 ID
Public Const R_S31 As String = "S31"           '현물현재가
Public Const R_S32 As String = "S32"           '현물현재가
Public Const R_X22 As String = "X22"           '현물호가
Public Const R_SC0 As String = "SC0"           '선물 현재가
Public Const R_SH0 As String = "SH0"           '선물 호가(5호가)
Public Const R_SH2 As String = "SH2"           '선물 호가
Public Const R_OC0 As String = "OC0"           '옵션 현재가
Public Const R_OH0 As String = "OH0"           '옵션 호가(5호가)
Public Const R_OH2 As String = "OH2"           '옵션 호가

Public Const R_XF2 As String = "XF2"           '체결
Public Const R_XF3 As String = "XF3"           '잔고
Public Const R_XX1 As String = "XX1"           '주식체결
Public Const R_XX6 As String = "XX6"           '주식잔고


Public g_hDongbuApi As Long '인증받은 DONGBUAPI Handle
Public g_szID As String '로그인 아이디

Public Const g_InitID As String = ""
Public Const g_InitLoginName As String = "dongbu"
Public Const g_InitPwd As String = ""
Public Const g_InitCertPwd As String = ""
Public Const g_InitAcctNo As String = "" '선물
'Public Const g_InitAcctNo As String = "" '주식
Public Const g_InitAcctPwd As String = ""
   
Public Function MidEx(strData As String, ByRef nPos As Long, nLen As Long)
    MidEx = Mid(strData, nPos, nLen)
    
    nPos = nPos + nLen
End Function

Public Function MidEx한글(strData As String, ByRef nPos As Long, nDataSize As Long) As String
  
    On Error Resume Next

    Dim n실제Len As Long
    
    Dim nSize As Long
    Dim i As Long
        
    For i = nPos To Len(strData)
        If Asc(Mid(strData, i, 1)) < 0 Then
            nSize = nSize + 2
        Else
            nSize = nSize + 1
        End If
        
        n실제Len = n실제Len + 1
        
        If nSize >= nDataSize Then Exit For
    Next
                
    MidEx한글 = Mid(strData, nPos, n실제Len)
    
    nPos = nPos + n실제Len
    
End Function


Public Function MidEx속성(strData As String, ByRef nPos As Long, nDataSize As Long) As String

    On Error Resume Next

    Dim n실제Len As Long
    
    Dim nSize As Long
    Dim i As Long
    
    Dim nTmp As Long
    
    For i = nPos To Len(strData)
    
        nTmp = Asc(Mid(strData, i, 1))
        
        If (nTmp = 235 Or nTmp = 226) Then
            nSize = nSize + 2
        Else
        
            If nTmp < 0 Then
                nSize = nSize + 2
            Else
                nSize = nSize + 1
            End If
        
        End If
        
        n실제Len = n실제Len + 1
        If nSize >= nDataSize Then Exit For
    Next
                
    MidEx속성 = Mid(strData, nPos, n실제Len)
    
    nPos = nPos + n실제Len
    
End Function





Attribute VB_Name = "������"
Option Explicit


Public Const ID_CONNECT As Integer = -70        '����
Public Const ID_DISCONNECT As Integer = -71    '���� ����
Public Const ID_SENDDATA As Integer = -72       'TR����
Public Const ID_ADVICE_RT As Integer = -73       '�ǽð� ����Ÿ ���
Public Const ID_UNADVICE_RT As Integer = -74   '�ǽð� ����Ÿ �������
Public Const ID_CLIENT_IP As Integer = -75        '���� ������
Public Const ID_F_ACCLIST As Integer = -76       '�������¸���Ʈ
Public Const ID_DRDS_DATA As Integer = -700   '�ǽð� ����Ÿ RECEIVE

Public Const ID_MSG_LOGINFAIL As Integer = -1      '�α��� ����
Public Const ID_MSG_SOCKETFAIL As Integer = -2    '���� ���� ����

Public Enum ORDER_TYPE
    GB_SELL = 1
    GB_BUY = 2
    GB_MODIFY = 3
    GB_CANCEL = 4
End Enum

Public Const GEJA_SIZE = 32
Public Const LEN_GEJANO = 11

'��û
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

'�ǽð� ������ ��û ID
Public Const R_S31 As String = "S31"           '�������簡
Public Const R_S32 As String = "S32"           '�������簡
Public Const R_X22 As String = "X22"           '����ȣ��
Public Const R_SC0 As String = "SC0"           '���� ���簡
Public Const R_SH0 As String = "SH0"           '���� ȣ��(5ȣ��)
Public Const R_SH2 As String = "SH2"           '���� ȣ��
Public Const R_OC0 As String = "OC0"           '�ɼ� ���簡
Public Const R_OH0 As String = "OH0"           '�ɼ� ȣ��(5ȣ��)
Public Const R_OH2 As String = "OH2"           '�ɼ� ȣ��

Public Const R_XF2 As String = "XF2"           'ü��
Public Const R_XF3 As String = "XF3"           '�ܰ�
Public Const R_XX1 As String = "XX1"           '�ֽ�ü��
Public Const R_XX6 As String = "XX6"           '�ֽ��ܰ�


Public g_hDongbuApi As Long '�������� DONGBUAPI Handle
Public g_szID As String '�α��� ���̵�

Public Const g_InitID As String = ""
Public Const g_InitLoginName As String = "dongbu"
Public Const g_InitPwd As String = ""
Public Const g_InitCertPwd As String = ""
Public Const g_InitAcctNo As String = "" '����
'Public Const g_InitAcctNo As String = "" '�ֽ�
Public Const g_InitAcctPwd As String = ""
   
Public Function MidEx(strData As String, ByRef nPos As Long, nLen As Long)
    MidEx = Mid(strData, nPos, nLen)
    
    nPos = nPos + nLen
End Function

Public Function MidEx�ѱ�(strData As String, ByRef nPos As Long, nDataSize As Long) As String
  
    On Error Resume Next

    Dim n����Len As Long
    
    Dim nSize As Long
    Dim i As Long
        
    For i = nPos To Len(strData)
        If Asc(Mid(strData, i, 1)) < 0 Then
            nSize = nSize + 2
        Else
            nSize = nSize + 1
        End If
        
        n����Len = n����Len + 1
        
        If nSize >= nDataSize Then Exit For
    Next
                
    MidEx�ѱ� = Mid(strData, nPos, n����Len)
    
    nPos = nPos + n����Len
    
End Function


Public Function MidEx�Ӽ�(strData As String, ByRef nPos As Long, nDataSize As Long) As String

    On Error Resume Next

    Dim n����Len As Long
    
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
        
        n����Len = n����Len + 1
        If nSize >= nDataSize Then Exit For
    Next
                
    MidEx�Ӽ� = Mid(strData, nPos, n����Len)
    
    nPos = nPos + n����Len
    
End Function





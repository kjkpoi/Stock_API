Attribute VB_Name = "Module_Drcm"
Option Explicit

Public Declare Function RegCloseKey Lib "advapi32.dll" (ByVal hKey As Long) As Long
Public Declare Function RegCreateKey Lib "advapi32.dll" Alias "RegCreateKeyA" (ByVal hKey As Long, ByVal lpSubKey As String, phkResult As Long) As Long
Public Declare Function RegOpenKeyEx Lib "advapi32" Alias "RegOpenKeyExA" (ByVal hKey As Long, ByVal lpSubKey As String, ByVal ulOptions As Long, ByVal samDesired As Long, phkResult As Long) As Long
Public Declare Function ShellExecute Lib "shell32.dll" Alias "ShellExecuteA" (ByVal hWnd As Long, ByVal lpOperation As String, ByVal lpFile As String, ByVal lpParameters As String, ByVal lpDirectory As String, ByVal nShowCmd As Long) As Long
Public Declare Function RegOpenKey Lib "advapi32.dll" Alias "RegOpenKeyA" (ByVal hKey As Long, ByVal lpSubKey As String, phkResult As Long) As Long
Public Declare Function RegQueryValueEx Lib "advapi32.dll" Alias "RegQueryValueExA" (ByVal hKey As Long, ByVal lpValueName As String, ByVal lpReserved As Long, lpType As Long, lpData As Any, lpcbData As Long) As Long

Public Declare Function FindWindow Lib "user32" Alias "FindWindowA" (ByVal lpClassName As String, ByVal lpWindowName As String) As Long
Public Declare Function SendMessage Lib "user32" Alias "SendMessageA" (ByVal hWnd As Long, ByVal wMsg As Long, ByVal wParam As Long, lParam As Any) As Long

Public Declare Function CallWindowProc Lib "user32" Alias _
   "CallWindowProcA" (ByVal lpPrevWndFunc As Long, ByVal hWnd As _
   Long, ByVal Msg As Long, ByVal wParam As Long, ByVal lParam As _
   Long) As Long
   
Public Declare Function SetWindowLong Lib "user32" Alias "SetWindowLongA" _
   (ByVal hWnd As Long, ByVal nIndex As Long, ByVal dwNewLong As Long) As Long
       
Public Declare Sub CopyMemory Lib "kernel32" Alias "RtlMoveMemory" _
   (hpvDest As Any, hpvSource As Any, ByVal cbCopy As Long)
   
Public Const SW_HIDE = 0
Public Const SW_SHOW = 5

Public Const HKEY_CURRENT_USER = &H80000001

Public Const DRCM_CONNECT As Integer = -70          '����
Public Const DRCM_DISCONNECT As Integer = -71       '���� ����
Public Const DRCM_SENDDATA As Integer = -72         'TR����
Public Const DRCM_ADVICE As Integer = -73           '�ǽð� ����Ÿ ���
Public Const DRCM_UNADVICE As Integer = -74         '�ǽð� ����Ÿ �������
Public Const DRCM_CLIENT_IP As Integer = -75        '���� ������
Public Const DRCM_F_ACCLIST As Integer = -76        '�������¸���Ʈ

Public Const DRCM_DRDS_DATA As Integer = -700       '�ǽð� ����Ÿ RECEIVE

Public Const DRCM_MSG_LOGINFAIL As Integer = -1     '�α��� ����
Public Const DRCM_MSG_SOCKETFAIL As Integer = -2    '���� ���� ����

Public Const SIZE_TRCODE As Integer = 5             'TR CODE ���� ����
Public Const SIZE_RTCODE As Integer = 3             '�ǽð� CODE ���� ����

Public Const TR_20000 As String = "20000"           '�ֹ�
Public Const TR_13655 As String = "13655"           '�ܰ���ȸ
Public Const TR_13615 As String = "13615"           'ü�᳻����ȸ
Public Const TR_15813 As String = "15813"           '����Ȳ��ȸ
Public Const TR_13653 As String = "13653"           '������ ��ȸ
Public Const TR_16260 As String = "16260"           '�ɼ����񺰸ŵ����ű�
Public Const TR_14051 As String = "14051"          '�ű�/û���ֹ����ɼ���


Public Const R_S31 As String = "S31"           '�������簡
Public Const R_S32 As String = "S32"           '�������簡
Public Const R_X22 As String = "X22"           '����ȣ��
Public Const R_SC0 As String = "SC0"           '���� ���簡
Public Const R_SH0 As String = "SH0"           '���� ȣ��(5ȣ��)
Public Const R_SH2 As String = "SH2"           '���� ȣ��
Public Const R_OC0 As String = "OC0"           '�ɼ� ���簡
Public Const R_OH0 As String = "OH0"           '�ɼ� ȣ��(5ȣ��)
Public Const R_OH2 As String = "OH2"           '�ɼ� ȣ��
Public Const R_ELC As String = "ELC"           'ELW ���簡
Public Const R_ELH As String = "ELH"           'ELW ȣ��
Public Const R_JC0 As String = "JC0"           '�ֽļ��� ���簡
Public Const R_JH0 As String = "JH0"           '�ֽļ��� ȣ��
Public Const R_OPC As String = "OPC"           '�ֽĿɼ� ���簡
Public Const R_OPH As String = "OPH"           '�ֽĿɼ� ȣ��
Public Const R_XF2 As String = "XF2"           'ü��
Public Const R_XF3 As String = "XF3"           '�ܰ�

Public Type COPYDATASTRUCT
        dwData As Long
        cbData As Long
        lpData As Long
End Type

Public Const GWL_WNDPROC = (-4)
Public Const WM_COPYDATA = &H4A
Public Const MAX_COPYBUFF = 1024
Public Const GEJA_SIZE = 32
Public Const LEN_GEJANO = 11


'PACKET HEADER
Public Type STTRHEADER
    WindowID(4) As Byte
    TRCode(5) As Byte
    MsgCode(6) As Byte
    Message(82) As Byte
    CursorPos(2) As Byte
    Message2Len(3) As Byte
    APDataLen(3) As Byte
    TRData(800) As Byte
    
End Type

'DRCM �� �����ϱ� ���� ����ü
Public Type ST_DRCM_USER
    hClientWnd As Long
    szUserId(0 To 19) As Byte
    szPwd(0 To 19) As Byte
    szCertPwd(0 To 19) As Byte
    bShowLoginDlg As Long
End Type

Public m_hDongbuDRCM As Long
Public m_hSocket As Long
Public m_szIP As String
 
Global lpPrevWndProc As Long
Global gHW As Long


Public Function GetRegApi(ByVal pHKEY As Long, ByVal sSection As String, ByVal sFullPath As String) As String

'On Error Resume Next

    Dim lResult As Long:  Dim sReturnValue As String:  Dim sBuffer As String: Dim lNewKey As Long
    Dim lDwType As Long: Dim lSZ As Long: Dim lRclass As Long

    lRclass = pHKEY
    lResult = RegOpenKey(lRclass, sFullPath, lNewKey):   lSZ = 256: sBuffer = String$(lSZ, 0)
    
    If lResult = 0 Then
        lResult = RegQueryValueEx(lNewKey, sSection, 0, lDwType, ByVal sBuffer, lSZ)                 'lDwType = 1 is Normal
    
        If lResult = 0 Then
            sReturnValue = StrConv(LeftB(StrConv(sBuffer, vbFromUnicode), lSZ - 1), vbUnicode)
        Else
            sReturnValue = ""
        End If
        
    End If

    lResult = RegCloseKey(lNewKey)
    GetRegApi = Replace(sReturnValue, Chr$(0), "")

End Function

Public Sub Hook()
    lpPrevWndProc = SetWindowLong(gHW, GWL_WNDPROC, AddressOf WindowProc)
    Debug.Print lpPrevWndProc
End Sub

Public Sub Unhook()
    Dim temp As Long
    temp = SetWindowLong(gHW, GWL_WNDPROC, lpPrevWndProc)
End Sub

Function WindowProc(ByVal hw As Long, ByVal uMsg As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
    If uMsg = WM_COPYDATA Then
        Call Form1.ParseReceivedData(lParam)
    End If
    
    WindowProc = CallWindowProc(lpPrevWndProc, hw, uMsg, wParam, lParam)
End Function


Public Function MidEx(strData As String, ByRef nPos As Long, nLen As Long) As String
    Dim strRet As String
    MidEx = Mid$(strData, nPos, nLen)
    
    nPos = nPos + nLen
    
    'MidEx = strRet
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

Public Function StrPadRight(strData As String, nLen As Long, strFill As String) As String
    
    On Error Resume Next

    Dim nLenData As Integer
    Dim strRet As String
    Dim i As Integer
    
    
    strRet = strData
    nLenData = Len(strData)
    For i = nLenData + 1 To nLen
        strRet = strRet + strFill
    Next i
            
    StrPadRight = strRet
End Function

Public Function StrPadLeft(strData As String, nLen As Long, strFill As String) As String
    
    On Error Resume Next

    Dim nLenData As Integer
    Dim strRet As String
    Dim i As Integer
        
    nLenData = Len(strData)
    For i = 1 To nLen - nLenData
        strRet = strRet + strFill
    Next i
            
    StrPadLeft = strRet + strData
    
    If Not (nLen = Len(strRet + strData)) Then
        MsgBox ("!11")
    End If
    
    
End Function





Module Utilities

    Public Const WM_COPYDATA As Integer = &H4A

    Public Structure COPYDATASTRUCT
        Public dwData As IntPtr
        Public cbData As Integer
        Public lpData As IntPtr
    End Structure

    Public Declare Auto Function SendMessage Lib "user32" _
                                  (ByVal hWnd As IntPtr, ByVal Msg As Integer, _
                                   ByVal wParam As IntPtr, _
                                   ByRef lParam As COPYDATASTRUCT) As Integer

    Public Declare Auto Function FindWindow Lib "USER32.DLL" _
                                  (ByVal lpClassName As String, ByVal lpWindowName As String) As IntPtr

End Module

VERSION 5.00
Begin VB.Form frm�ܰ���Ʈ 
   Caption         =   "�ܰ���Ʈ"
   ClientHeight    =   3885
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8265
   LinkTopic       =   "Form1"
   ScaleHeight     =   3885
   ScaleWidth      =   8265
   StartUpPosition =   3  'Windows �⺻��
   Begin VB.OptionButton opt�ֽ� 
      Caption         =   "�ֽ�"
      Height          =   255
      Left            =   5880
      TabIndex        =   9
      Top             =   120
      Width           =   855
   End
   Begin VB.OptionButton opt���� 
      Caption         =   "����"
      Height          =   255
      Left            =   5040
      TabIndex        =   8
      Top             =   120
      Value           =   -1  'True
      Width           =   855
   End
   Begin VB.CheckBox btnXX6 
      Caption         =   "�ֽ��ܰ�(XX6) �ǽð������� ��û ��� �� ����"
      BeginProperty Font 
         Name            =   "����ü"
         Size            =   9
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   252
      Left            =   240
      TabIndex        =   7
      Top             =   960
      Width           =   4695
   End
   Begin VB.CheckBox btnXF3 
      Caption         =   "�����ܰ�(XF3) �ǽð������� ��û ��� �� ����"
      BeginProperty Font 
         Name            =   "����ü"
         Size            =   9
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   252
      Left            =   240
      TabIndex        =   6
      Top             =   600
      Width           =   4695
   End
   Begin VB.TextBox txtPwd 
      BeginProperty Font 
         Name            =   "����ü"
         Size            =   9
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   288
      Left            =   4080
      TabIndex        =   3
      Top             =   120
      Width           =   735
   End
   Begin VB.TextBox txtAccount 
      Height          =   270
      Left            =   960
      TabIndex        =   2
      Text            =   "Text1"
      Top             =   120
      Width           =   2055
   End
   Begin VB.CommandButton btnJango 
      Caption         =   "��ȸ"
      BeginProperty Font 
         Name            =   "����ü"
         Size            =   9
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   372
      Left            =   6840
      TabIndex        =   1
      Top             =   120
      Width           =   1215
   End
   Begin VB.ListBox ListBox1 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   2400
      Left            =   120
      TabIndex        =   0
      Top             =   1320
      Width           =   7935
   End
   Begin VB.Label Label7 
      Caption         =   "����"
      BeginProperty Font 
         Name            =   "����ü"
         Size            =   9
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   240
      TabIndex        =   5
      Top             =   120
      Width           =   615
   End
   Begin VB.Label Label8 
      Caption         =   "���º��"
      BeginProperty Font 
         Name            =   "����ü"
         Size            =   9
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   3240
      TabIndex        =   4
      Top             =   120
      Width           =   735
   End
End
Attribute VB_Name = "frm�ܰ���Ʈ"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim WithEvents ����API��ü  As DongbuAPI
Attribute ����API��ü.VB_VarHelpID = -1

Dim m_RTDataXF3 As clsDrdsXF3   '�����ܰ�
Dim m_RTDataXX6 As clsDrdsXX6  '�ֽ��ܰ�
Dim m_szNextKey As String

Private Sub Form_Load()
    Dim bRet As Boolean
    
      '�ʱ�ȭ
    Set ����API��ü = New DongbuAPI
    bRet = ����API��ü.InitCtrl(g_hDongbuApi, CLng(Me.hWnd))
    
    txtAccount.Text = g_InitAcctNo
    txtPwd.Text = g_InitAcctPwd
    
    Set m_RTDataXX6 = New clsDrdsXX6
    Set m_RTDataXF3 = New clsDrdsXF3
    
End Sub

Private Sub Form_Unload(Cancel As Integer)
    Dim bRet As Boolean
    '�ǽð���û ����
    If (btnXX6.Value = vbChecked) Then
        bRet = ����API��ü.ReqRealtimeData(ID_UNADVICE_RT, R_XX6, g_szID)
    End If
    
     If (btnXF3.Value = vbChecked) Then
        bRet = ����API��ü.ReqRealtimeData(ID_UNADVICE_RT, R_XF3, g_szID)
    End If
    
    Set ����API��ü = Nothing
    Set m_RTDataXX6 = Nothing
    Set m_RTDataXF3 = Nothing
    
End Sub

Private Sub DisplayMsg(ByVal strMsg As String)

    ListBox1.AddItem strMsg, 0
    
End Sub

Private Sub ����API��ü_ReceiveData(ByVal nReqID As Long, ByVal szMsgCode As String, ByVal szMsg As String, ByVal szData As String)
    Select Case (nReqID)
        Case REQ_FUT_JANGO
            DisplayMsg ("���� �ܰ���ȸ >> " + szMsg)
            Parse_REQ_FUT_JANGO (szData)
            
        Case REQ_STK_JANGO
            DisplayMsg ("�ֽ� �ܰ���ȸ >> " + szMsg)
            Parse_REQ_STK_JANGO (szData)
    End Select
End Sub

Private Sub ����API��ü_ReceiveRTData(ByVal szName As String, ByVal szField As String, ByVal szData As String)
    DisplayMsg ("�ǽð������� ����>>" + szName + ":" + szField)
    DisplayMsg ("DATA>>" + szData)
    
    Select Case szName
    Case R_XF3                      '���� �ܰ�
        Call Parse_XF3(szData)
    Case R_XX6                      '�ֽ� �ܰ�
        Call Parse_XX6(szData)
    End Select

End Sub

Private Sub Parse_XF3(ByVal strData As String)
    m_RTDataXF3.Init (strData)
End Sub

Private Sub Parse_XX6(ByVal strData As String)
    m_RTDataXX6.Init (strData)
End Sub

'�ֽ� �ܰ���ȸ
Private Sub Parse_REQ_STK_JANGO(strData As String)
On Error Resume Next
    'TR_13148
    
    '''''''''''''''''''''''''''''
    Dim sm_bjlen
    Dim sm_bjdata
    '''''''''''''''''''''''''''''sm
    Dim �Ѹ��Աݾ�
    Dim ���򰡼���
    Dim ���ϸŵ��ݾ�
    Dim ���򰡱ݾ�
    Dim �Ѽ�����
    Dim ���Ͻ�������
    Dim Next����
    Dim NextKey
    '''''''''''''''''''''''''''''
    Dim gr_bjlen
    Dim gr_bjdata
    '''''''''''''''''''''''''''''
    Dim ���ڵ尹�� As Long
    
    Dim szItem(100) As String
    Dim i As Long, nPos As Long
    
    nPos = 1
    sm_bjlen = MidEx(strData, nPos, 6)
    sm_bjdata = MidEx(strData, nPos, 5)
    
    �Ѹ��Աݾ� = MidEx(strData, nPos, 15)
    ���򰡼��� = MidEx(strData, nPos, 15)
    ���ϸŵ��ݾ� = MidEx(strData, nPos, 15)
    ���򰡱ݾ� = MidEx(strData, nPos, 15)
    �Ѽ����� = MidEx(strData, nPos, 15)
    ���Ͻ������� = MidEx(strData, nPos, 15)
    Next���� = MidEx(strData, nPos, 1)
    NextKey = MidEx(strData, nPos, 50)
    
    gr_bjlen = MidEx(strData, nPos, 6)
    gr_bjdata = MidEx(strData, nPos, 5)
    
    
    ���ڵ尹�� = CLng(Left(gr_bjlen, 4))
    
    m_szNextKey = Trim(NextKey)
    
    For i = 1 To ���ڵ尹��
        strData = Mid(strData, nPos):       nPos = 1
        
        szItem(1) = MidEx(strData, nPos, 6)  '�����ڵ�
        szItem(2) = MidEx�ѱ�(strData, nPos, 20) '�����
        szItem(3) = MidEx(strData, nPos, 15) '�������
        szItem(4) = MidEx(strData, nPos, 15) '�򰡼���
        szItem(5) = MidEx(strData, nPos, 7)  '������
        
        szItem(6) = MidEx(strData, nPos, 15)  '�ܰ�ݾ�
        szItem(7) = MidEx(strData, nPos, 15) '�򰡱ݾ�
        szItem(8) = MidEx(strData, nPos, 15)  '���Ϻ���
        szItem(9) = MidEx(strData, nPos, 15)  '���Ϻ���
        szItem(10) = MidEx(strData, nPos, 15)  '�����ܰ�
        
        szItem(11) = MidEx(strData, nPos, 9)  '��δܰ�
        szItem(12) = MidEx(strData, nPos, 9) '�����
        szItem(13) = MidEx(strData, nPos, 9)  '�ִ���
        szItem(14) = MidEx(strData, nPos, 9)  '������
        szItem(15) = MidEx(strData, nPos, 9) '����
        
        szItem(16) = MidEx(strData, nPos, 7) '���簡
        szItem(17) = MidEx(strData, nPos, 7)  '���ϴ��
        szItem(18) = MidEx(strData, nPos, 8)  '����������
        szItem(19) = MidEx(strData, nPos, 1)  '�����ȣ
        szItem(20) = MidEx(strData, nPos, 15)  '��������
        szItem(21) = MidEx(strData, nPos, 15)  '���ϸŵ��ݾ�
        
        szItem(22) = MidEx(strData, nPos, 1) '�ܰ���
        szItem(23) = MidEx(strData, nPos, 8) '������
        szItem(24) = MidEx(strData, nPos, 8) '������
        szItem(25) = MidEx(strData, nPos, 15)  '�ſ�ݾ�
        szItem(26) = MidEx(strData, nPos, 9)  '��������
        szItem(27) = MidEx(strData, nPos, 3)  '�������ű���
        
        DisplayMsg "��������>>" + szItem(1) + " : " + szItem(2)
    Next i
    
End Sub

Private Sub Parse_REQ_FUT_JANGO(strData As String) '���� �ܰ���ȸ

On Error Resume Next

    'TR_13655
    Dim �Ѿ����ݾ�
    Dim ���򰡼���
    Dim �ֹ������Ѿ�
    Dim ���򰡱ݾ�
    Dim ���Ͻ�������
    Dim �ֹ���������
    Dim �Ѽ�����
    Dim ���ڵ尹�� As Long
        
    Dim i As Long, nPos As Long
    Dim szItem(100) As String
    
    If Len(strData) = 0 Then
        Return
    End If
    
    nPos = 1
    �Ѿ����ݾ� = MidEx(strData, nPos, 17)
    ���򰡼��� = MidEx(strData, nPos, 17)
    �ֹ������Ѿ� = MidEx(strData, nPos, 17)
    
    ���򰡱ݾ� = MidEx(strData, nPos, 17)
    ���Ͻ������� = MidEx(strData, nPos, 17)
    �ֹ��������� = MidEx(strData, nPos, 17)
    �Ѽ����� = MidEx(strData, nPos, 9)
            
    ���ڵ尹�� = MidEx(strData, nPos, 4)
    
    For i = 1 To ���ڵ尹��
        strData = Mid(strData, nPos):       nPos = 1
        
        szItem(1) = MidEx(strData, nPos, 15)       '�����ڵ�
        szItem(2) = MidEx�Ӽ�(strData, nPos, 3)        '�ŸżӼ�
        szItem(3) = MidEx�ѱ�(strData, nPos, 5) '�Ÿű���
        szItem(4) = MidEx(strData, nPos, 15)     'û�갡��
        szItem(5) = MidEx(strData, nPos, 15)     '�����ܰ�
        szItem(6) = MidEx(strData, nPos, 15)        '����
        szItem(7) = MidEx(strData, nPos, 15)     '��������
        szItem(8) = MidEx(strData, nPos, 15) '��ü���ֹ�����
        szItem(9) = MidEx(strData, nPos, 12)     '���Դܰ�
        szItem(10) = MidEx(strData, nPos, 6)        '���簡
        szItem(11) = MidEx(strData, nPos, 15)     '�򰡼���
        szItem(12) = MidEx(strData, nPos, 9)        '������
        szItem(13) = MidEx(strData, nPos, 15)     '�����ݾ�
        szItem(14) = MidEx(strData, nPos, 15)  '�򰡱ݾ�
        szItem(15) = MidEx(strData, nPos, 12) '������
        szItem(16) = MidEx(strData, nPos, 6) '�ż�ȣ��
        szItem(17) = MidEx(strData, nPos, 6)  '�ŵ�ȣ��
        szItem(18) = MidEx(strData, nPos, 6)  '���Ѱ�
        szItem(19) = MidEx(strData, nPos, 6)  '���Ѱ�
        szItem(20) = MidEx(strData, nPos, 1) '����Ҽӱ���
        szItem(21) = MidEx(strData, nPos, 15) '���Ͻ�������D
        szItem(22) = MidEx(strData, nPos, 3) '�ֹ�����
        szItem(23) = MidEx(strData, nPos, 15) '�ŷ�����
        szItem(24) = MidEx(strData, nPos, 15)   '���ϸż��Ǵ¸ŵ��ݾ�
        szItem(25) = MidEx(strData, nPos, 15)  '�ŸŴ����
        
        DisplayMsg "��������>>" + szItem(1)
                    
    Next i
    
End Sub

'�ܰ���ȸ
Private Sub btnJango_Click()
    Dim szAccount As String
    Dim szData As String
    Dim nRet As Boolean
    
    szAccount = txtAccount.Text
    
    If IsEmpty(szAccount) Then
        Exit Sub
    End If
    
    If (opt����.Value = True) Then
        nRet = ����API��ü.ReqJango(szAccount)
    Else
        nRet = ����API��ü.ReqStockJango(szAccount, m_szNextKey)
    End If
    
    m_szNextKey = ""
    
End Sub

'�����ܰ� �ǽð�
Private Sub btnXF3_Click()

    Dim bRet As Boolean

    If (btnXF3.Value = vbChecked) Then
        bRet = ����API��ü.ReqRealtimeData(ID_ADVICE_RT, R_XF3, g_szID)
    Else
        bRet = ����API��ü.ReqRealtimeData(ID_UNADVICE_RT, R_XF3, g_szID)
    End If

End Sub

'�ֽ��ܰ� �ǽð�
Private Sub btnXX6_Click()

    Dim bRet As Boolean

    If (btnXX6.Value = vbChecked) Then
        bRet = ����API��ü.ReqRealtimeData(ID_ADVICE_RT, R_XX6, g_szID)
    Else
        bRet = ����API��ü.ReqRealtimeData(ID_UNADVICE_RT, R_XX6, g_szID)
    End If

End Sub

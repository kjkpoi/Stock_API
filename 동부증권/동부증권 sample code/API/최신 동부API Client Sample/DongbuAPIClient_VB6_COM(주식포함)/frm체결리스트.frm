VERSION 5.00
Begin VB.Form frmü�Ḯ��Ʈ 
   Caption         =   "ü�᳻����ȸ"
   ClientHeight    =   3900
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8235
   LinkTopic       =   "Form1"
   ScaleHeight     =   3900
   ScaleWidth      =   8235
   StartUpPosition =   3  'Windows �⺻��
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
      TabIndex        =   7
      Top             =   1320
      Width           =   7935
   End
   Begin VB.TextBox txtAccount 
      Height          =   270
      Left            =   960
      TabIndex        =   6
      Text            =   "Text1"
      Top             =   120
      Width           =   2055
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
      TabIndex        =   5
      Top             =   120
      Width           =   735
   End
   Begin VB.CheckBox btnXF2 
      Caption         =   "����ü��(XF2) �ǽð������� ��û ��� �� ����"
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
      TabIndex        =   4
      Top             =   600
      Width           =   4695
   End
   Begin VB.CheckBox btnXX1 
      Caption         =   "�ֽ�ü��(XX1) �ǽð������� ��û ��� �� ����"
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
      TabIndex        =   3
      Top             =   960
      Width           =   4695
   End
   Begin VB.OptionButton opt���� 
      Caption         =   "����"
      Height          =   255
      Left            =   5040
      TabIndex        =   2
      Top             =   120
      Value           =   -1  'True
      Width           =   855
   End
   Begin VB.OptionButton opt�ֽ� 
      Caption         =   "�ֽ�"
      Height          =   255
      Left            =   5880
      TabIndex        =   1
      Top             =   120
      Width           =   855
   End
   Begin VB.CommandButton btnCheguyl 
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
      Left            =   6960
      TabIndex        =   0
      Top             =   120
      Width           =   1095
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
      TabIndex        =   9
      Top             =   120
      Width           =   735
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
      TabIndex        =   8
      Top             =   120
      Width           =   615
   End
End
Attribute VB_Name = "frmü�Ḯ��Ʈ"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim WithEvents ����API��ü  As DongbuAPI
Attribute ����API��ü.VB_VarHelpID = -1

Dim m_RTDataXF2 As clsDrdsXF2   '����ü��
Dim m_RTDataXX1 As clsDrdsXX1  '�ֽ�ü��
Dim m_szNextKey As String

Private Sub Form_Load()

    Dim bRet As Boolean
     '�ʱ�ȭ
    Set ����API��ü = New DongbuAPI
    bRet = ����API��ü.InitCtrl(g_hDongbuApi, CLng(Me.hWnd))
    
    txtAccount.Text = g_InitAcctNo
    txtPwd.Text = g_InitAcctPwd
    
    Set m_RTDataXF2 = New clsDrdsXF2
    Set m_RTDataXX1 = New clsDrdsXX1
End Sub

Private Sub Form_Unload(Cancel As Integer)
    Dim bRet As Boolean
    '�ǽð���û ����
    If (btnXF2.Value = vbChecked) Then
        bRet = ����API��ü.ReqRealtimeData(ID_UNADVICE_RT, R_XF2, g_szID)
    End If
    
     If (btnXX1.Value = vbChecked) Then
        bRet = ����API��ü.ReqRealtimeData(ID_UNADVICE_RT, R_XX1, g_szID)
    End If
    
    Set ����API��ü = Nothing
    Set m_RTDataXF2 = Nothing
    Set m_RTDataXX1 = Nothing
End Sub

Private Sub DisplayMsg(ByVal strMsg As String)

    ListBox1.AddItem strMsg, 0
    
End Sub

Private Sub btnCheguyl_Click()

    Dim szAccount As String
    Dim szPwd As String
    Dim szGB As String
    Dim nRet As Boolean
        
    szAccount = txtAccount.Text
    szPwd = txtPwd.Text
    
    If IsEmpty(szAccount) Then
        Exit Sub
    End If
    
    If (opt����.Value = True) Then
        nRet = ����API��ü.ReqChegyul(szAccount, szPwd, "1")
    Else
        szGB = "1" '1:�ֹ�/ü�� 2:��ü��
        nRet = ����API��ü.ReqStockChegyul(szAccount, szGB, m_szNextKey)
    End If
    
    m_szNextKey = ""
     
End Sub

'�ֽ�ü�� �ǽð�
Private Sub btnXX1_Click()
    Dim szId As String
    Dim nRet As Long
    
    If (btnXX1.Value = vbChecked) Then
        nRet = ����API��ü.ReqRealtimeData(ID_ADVICE_RT, R_XX1, g_szID)
    Else
        nRet = ����API��ü.ReqRealtimeData(ID_UNADVICE_RT, R_XX1, g_szID)
    End If
    
End Sub

'����ü�� �ǽð�
Private Sub btnXF2_Click()
    Dim szId As String
    Dim nRet As Long

    If (btnXF2.Value = vbChecked) Then
        nRet = ����API��ü.ReqRealtimeData(ID_ADVICE_RT, R_XF2, g_szID)
    Else
        nRet = ����API��ü.ReqRealtimeData(ID_UNADVICE_RT, R_XF2, g_szID)
    End If

End Sub

Private Sub Parse_XF2(ByVal strData As String)
    m_RTDataXF2.Init (strData)
End Sub

Private Sub Parse_XX1(ByVal strData As String)
    m_RTDataXX1.Init (strData)
End Sub

Private Sub ����API��ü_ReceiveRTData(ByVal szName As String, ByVal szField As String, ByVal szData As String)

    DisplayMsg ("�ǽð������� ����>>" + szName + ":" + szField)
    DisplayMsg ("DATA>>" + szData)
    
    Select Case szName
    Case R_XF2                      '���� ü��
        Call Parse_XF2(szData)
    Case R_XX1                      '�ֽ� ü��
        Call Parse_XX1(szData)
    End Select

End Sub

Private Sub ����API��ü_ReceiveData(ByVal nReqID As Long, ByVal szMsgCode As String, ByVal szMsg As String, ByVal szData As String)
    Select Case (nReqID)
        Case REQ_STK_CHE
            DisplayMsg ("�ֽ� ü�᳻�� >> " + szMsg)
            Parse_REQ_STK_CHE (szData)
            
        Case REQ_FUT_CHE
            DisplayMsg ("���� ü�᳻�� >> " + szMsg)
            Parse_REQ_FUT_CHE (szData)
    End Select
End Sub

Private Sub Parse_REQ_STK_CHE(strData As String) '�ֽ�ü�Ḯ��Ʈ

    Dim nPos As Long, i As Long
    Dim szItem(100) As String
    Dim geja
    Dim ngbn
    Dim NextKey
    Dim gr_bjlen
    Dim gr_bjdata
    Dim gr_cnt
    
    nPos = 1
    
    geja = MidEx(strData, nPos, 20)
    ngbn = MidEx(strData, nPos, 1)
    NextKey = MidEx(strData, nPos, 50)
    gr_cnt = MidEx(strData, nPos, 4)
    gr_bjlen = MidEx(strData, nPos, 2)
    gr_bjdata = MidEx(strData, nPos, 4)
    
    For i = 1 To gr_cnt
    
        strData = Mid(strData, nPos):       nPos = 1
        
        szItem(1) = MidEx(strData, nPos, 9) ' �ֹ���ȣ
        szItem(2) = MidEx(strData, nPos, 12) ' �����ڵ�
        szItem(3) = MidEx�ѱ�(strData, nPos, 20) ' �����
        szItem(4) = MidEx(strData, nPos, 3)  ' �Ÿű��мӼ�
        szItem(5) = MidEx�ѱ�(strData, nPos, 16)  ' �Ÿű���
        szItem(6) = MidEx(strData, nPos, 15) ' �ֹ�����
        szItem(7) = MidEx(strData, nPos, 12) ' �ֹ��ܰ�
        szItem(8) = MidEx(strData, nPos, 15) ' ü�����
        szItem(9) = MidEx(strData, nPos, 12) ' ü�ᰡ��
        szItem(10) = MidEx(strData, nPos, 15) ' ��ü�����
        szItem(11) = MidEx�ѱ�(strData, nPos, 10) ' �ֹ�����
        szItem(12) = Trim(MidEx�ѱ�(strData, nPos, 9)) ' ���ֹ���ȣ
        szItem(13) = Trim(MidEx�ѱ�(strData, nPos, 10)) ' ó������
        szItem(14) = Trim(MidEx�ѱ�(strData, nPos, 9))  ' ü���
        szItem(15) = Trim(MidEx�ѱ�(strData, nPos, 6))  ' �ֹ��ð�
        szItem(16) = Trim(MidEx�ѱ�(strData, nPos, 9)) ' �����
        szItem(17) = Trim(MidEx�ѱ�(strData, nPos, 9)) ' ������
        szItem(18) = Trim(MidEx�ѱ�(strData, nPos, 9))  ' ����
        szItem(19) = Trim(MidEx�ѱ�(strData, nPos, 3))  ' �ſ뱸��
        
        DisplayMsg strData
    Next i
    
End Sub
Private Sub Parse_REQ_FUT_CHE(strData As String) '����ü�Ḯ��Ʈ

On Error Resume Next

    Dim ���ڵ�Count As Long
    Dim ���ڵ�Len As String
    Dim �׸���Msg As String
    Dim �����ʵ� As String
           
    
    Dim nPos As Long, i As Long
    Dim szItem(100) As String
    
    nPos = 1
    
    �����ʵ� = MidEx(strData, nPos, 100)
    ���ڵ�Count = MidEx(strData, nPos, 4)
    ���ڵ�Len = MidEx(strData, nPos, 4)
    �׸���Msg = MidEx(strData, nPos, 5)
    
    For i = 1 To ���ڵ�Count
    
        strData = Mid(strData, nPos):       nPos = 1
        
        szItem(1) = MidEx(strData, nPos, 9)  ' �ֹ���ȣ
        szItem(2) = MidEx(strData, nPos, 9) ' ���ֹ���ȣ
        szItem(3) = MidEx(strData, nPos, 15)  ' �����ڵ�
        szItem(4) = MidEx(strData, nPos, 3)  ' �ֹ����мӼ�
        szItem(5) = Trim(MidEx�ѱ�(strData, nPos, 12)) ' �ֹ�����
                
        szItem(6) = MidEx�ѱ�(strData, nPos, 12)  ' �ֹ�����
        szItem(7) = MidEx(strData, nPos, 12) ' �ֹ��ܰ�
        szItem(8) = MidEx(strData, nPos, 15) ' �ֹ�����
        szItem(9) = MidEx(strData, nPos, 12)  ' ü�ᰡ��
        szItem(10) = MidEx(strData, nPos, 15)  ' ü�����
        szItem(11) = MidEx(strData, nPos, 15) ' ��ü�����
        szItem(12) = MidEx�ѱ�(strData, nPos, 40)  ' �źθ޼���
        
        DisplayMsg strData
        
    Next i
    
End Sub

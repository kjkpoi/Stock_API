VERSION 5.00
Begin VB.Form frm�ֹ� 
   Caption         =   "�ֹ� ����"
   ClientHeight    =   3675
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8160
   LinkTopic       =   "Form1"
   ScaleHeight     =   3675
   ScaleWidth      =   8160
   StartUpPosition =   3  'Windows �⺻��
   Begin VB.Frame Frame3 
      Caption         =   "�ֹ�"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1695
      Left            =   120
      TabIndex        =   1
      Top             =   120
      Width           =   7935
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
         Left            =   3720
         TabIndex        =   15
         Top             =   360
         Width           =   612
      End
      Begin VB.TextBox txtAccount 
         Height          =   270
         Left            =   720
         TabIndex        =   14
         Text            =   "Text1"
         Top             =   360
         Width           =   1935
      End
      Begin VB.CommandButton btnAbleQty 
         Caption         =   "�ű�/û�� ���ɼ���"
         Height          =   495
         Left            =   5880
         TabIndex        =   10
         Top             =   240
         Width           =   1935
      End
      Begin VB.TextBox edtPrice 
         Height          =   288
         Left            =   2760
         TabIndex        =   9
         Text            =   "0.90"
         Top             =   1080
         Width           =   612
      End
      Begin VB.TextBox edtQty 
         Height          =   288
         Left            =   2760
         TabIndex        =   8
         Text            =   "1"
         Top             =   720
         Width           =   612
      End
      Begin VB.TextBox edtJongCode 
         Height          =   288
         Left            =   720
         TabIndex        =   7
         Text            =   "301G2230"
         Top             =   840
         Width           =   1332
      End
      Begin VB.ComboBox cmbPriceType 
         Height          =   300
         Left            =   720
         TabIndex        =   6
         Text            =   "Combo1"
         Top             =   1200
         Width           =   1335
      End
      Begin VB.OptionButton opt�ŵ� 
         Caption         =   "�ŵ�"
         Height          =   255
         Left            =   3600
         TabIndex        =   5
         Top             =   720
         Width           =   855
      End
      Begin VB.OptionButton opt�ż� 
         Caption         =   "�ż�"
         Height          =   255
         Left            =   3600
         TabIndex        =   4
         Top             =   1080
         Value           =   -1  'True
         Width           =   855
      End
      Begin VB.CommandButton btnOrder 
         Caption         =   "���� �ֹ�"
         Height          =   495
         Left            =   4680
         TabIndex        =   3
         Top             =   240
         Width           =   1095
      End
      Begin VB.CommandButton btnStockOrder 
         Caption         =   "�ֽ� �ֹ�"
         Height          =   495
         Left            =   4680
         TabIndex        =   2
         Top             =   1080
         Width           =   1095
      End
      Begin VB.Line Line2 
         X1              =   4560
         X2              =   7920
         Y1              =   960
         Y2              =   960
      End
      Begin VB.Line Line1 
         X1              =   4560
         X2              =   4560
         Y1              =   240
         Y2              =   1560
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
         TabIndex        =   17
         Top             =   360
         Width           =   375
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
         Left            =   2880
         TabIndex        =   16
         Top             =   360
         Width           =   735
      End
      Begin VB.Label ���� 
         Caption         =   "����"
         Height          =   255
         Left            =   2280
         TabIndex        =   13
         Top             =   1080
         Width           =   375
      End
      Begin VB.Label Label6 
         Caption         =   "����"
         Height          =   255
         Left            =   2280
         TabIndex        =   12
         Top             =   720
         Width           =   375
      End
      Begin VB.Label Label5 
         Caption         =   "����"
         Height          =   255
         Left            =   240
         TabIndex        =   11
         Top             =   840
         Width           =   375
      End
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
      Height          =   1620
      Left            =   120
      TabIndex        =   0
      Top             =   1920
      Width           =   7935
   End
End
Attribute VB_Name = "frm�ֹ�"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim WithEvents ����API��ü  As DongbuAPI
Attribute ����API��ü.VB_VarHelpID = -1

Private Sub Form_Load()

    Dim bRet As Boolean
    
     '�ʱ�ȭ
    Set ����API��ü = New DongbuAPI
    bRet = ����API��ü.InitCtrl(g_hDongbuApi, CLng(Me.hWnd))
    
    txtAccount.Text = g_InitAcctNo
    txtPwd.Text = g_InitAcctPwd
    
    Init�ֹ�
    
End Sub

Private Sub Form_Unload(Cancel As Integer)

    Set ����API��ü = Nothing
    
End Sub


Private Function Init�ֹ�()

    cmbPriceType.AddItem "00:������"
    cmbPriceType.AddItem "03:���尡"
    cmbPriceType.AddItem "05:���Ǻ�������"
    cmbPriceType.AddItem "06:������������"
    
    cmbPriceType.Text = "00:������"

End Function


Private Sub DisplayMsg(ByVal strMsg As String)

    ListBox1.AddItem strMsg, 0
    
End Sub

Private Sub ����API��ü_ReceiveData(ByVal nReqID As Long, ByVal szMsgCode As String, ByVal szMsg As String, ByVal szData As String)
    Select Case (nReqID)
        Case REQ_FUT_ORDER
            DisplayMsg ("�����ֹ� >> " + szMsg)
            ParseREQ_ORDER (szData)
            
        Case REQ_STK_ORDER
            DisplayMsg ("�ֽ��ֹ� >> " + szMsg)
            ParseREQ_ORDER (szData)
            
        Case REQ_FUT_ORDER_QTY
            DisplayMsg ("�ű�/û�갡�ɼ��� ��ȸ  >> " + szMsg)
            Parse_REQ_FUT_ORDER_QTY (szData)
    End Select
    
End Sub

'�ű�/û�� ���� ��ȸ ����
Private Sub Parse_REQ_FUT_ORDER_QTY(strData As String)
    Dim �ű��ֹ����ɼ���
    Dim û���ֹ����ɼ���
    
    Dim nPos As Long
    
    nPos = 1
    �ű��ֹ����ɼ��� = MidEx(strData, nPos, 15)
    û���ֹ����ɼ��� = MidEx(strData, nPos, 15)
    
    DisplayMsg (strData)
    
End Sub

Private Sub ParseREQ_ORDER(strData As String) '�ֹ�����

On Error Resume Next
    Dim �ֹ�Cnt As Long
    Dim nPos As Long
    Dim i As Long
    
    Dim str���ù�ȣ As String
    Dim sr�ֹ���ȣ As String
    Dim str�޽����ڵ� As String
    Dim str�޽��� As String
    
    On Error GoTo OnError
    
    nPos = 1
    �ֹ�Cnt = CLng(MidEx(strData, nPos, 4))
    
    For i = 1 To �ֹ�Cnt
        str���ù�ȣ = MidEx(strData, nPos, 8)
        sr�ֹ���ȣ = MidEx(strData, nPos, 9)
        str�޽����ڵ� = MidEx(strData, nPos, 6)
        
        strData = Mid(strData, nPos)
        nPos = 1
        str�޽��� = MidEx�ѱ�(strData, nPos, 100)
        
        If Mid(str�޽����ڵ�, 2) < 1000 Then
            DisplayMsg ("�ֹ�Ȯ��>> �ֹ���ȣ :" + sr�ֹ���ȣ)
        Else
            DisplayMsg ("�ֹ��ź�>>" + str�޽���)
        End If
    Next i
    
    Exit Sub
OnError:
    MsgBox ("�ֹ����� ó���ÿ���" & Err.Description & strData)
End Sub

Private Sub SendOrder(bFutureOrder As Boolean)
    Dim bRet As Boolean
            
    Dim szAccount As String
    Dim szPwd As String
    Dim szJongmok As String  '/* �����ڵ�
    Dim nOrderPrice As Long  '�ֹ�����
    Dim nOrdSect As Long     '/* 1:�ŵ�, 2:�ż�,  3:����, 4:���
    Dim nPriceType As Long   '/* 00:������ 03:���尡 05:���Ǻ�������  06:������������
    Dim nOrgOrderNo As Long  '/*���ֹ���ȣ
    Dim nQty As Long  '�ֹ�����
        
    szAccount = txtAccount.Text
    szPwd = txtPwd.Text
    szJongmok = edtJongCode.Text
    nPriceType = CLng(Left(cmbPriceType.Text, 2))
    nQty = CLng(edtQty.Text)
    nOrderPrice = CDbl(edtPrice.Text)
    
    If (opt�ż�.Value = True) Then
        nOrdSect = GB_BUY
    Else
        nOrdSect = GB_SELL
    End If
    
    If (bFutureOrder) Then
        nOrderPrice = nOrderPrice * 100
        bRet = ����API��ü.SendFOrder(8888, szAccount, szPwd, nOrdSect, szJongmok, nPriceType, nQty, nOrderPrice, nOrgOrderNo)
    Else
        bRet = ����API��ü.SendSOrder(7777, szAccount, szPwd, nOrdSect, szJongmok, nPriceType, nQty, nOrderPrice, nOrgOrderNo)
    End If
    
    If (bRet = False) Then
        MsgBox "�ֹ����� ����"
    End If
    
End Sub

Private Sub btnOrder_Click()
    '�����ֹ�
    SendOrder (True)
    
End Sub

Private Sub btnStockOrder_Click()
    '�ֽ��ֹ�
    SendOrder (False)
    
End Sub

'�ű�/û�� ���ɼ���
Private Sub btnAbleQty_Click()

    Dim szAccount As String
    Dim szPwd As String
    Dim szJongmok As String
    Dim nOrderType As Integer
    Dim szȣ������ As String
    Dim nPrice As Integer
        
    Dim bRet As Boolean
    
    szAccount = txtAccount.Text
    szPwd = txtPwd.Text
    szJongmok = edtJongCode.Text
    
    If (Not IsEmpty(edtPrice.Text)) Then
        nPrice = CDbl(edtPrice.Text) * 100
    Else
        MsgBox "������ �Է��ϼ���"
        Exit Sub
    End If
        
    '/*�Ÿű���(1) # 1:�ŵ�, 2:�ż�
    If (opt�ż�.Value = True) Then
        nOrderType = GB_BUY
    Else
        nOrderType = GB_SELL
    End If
    
    '/*�����ɼ�ȣ�������ڵ�(2) # 00:������ 03:���尡 05:���Ǻ������� 06:������������
    szȣ������ = Left(cmbPriceType.Text, 2)
                    
    bRet = ����API��ü.ReqAbleQty(szAccount, szPwd, szJongmok, nOrderType, nPrice, szȣ������)

End Sub


VERSION 5.00
Begin VB.Form frm����Ȳ 
   Caption         =   "����Ȳ"
   ClientHeight    =   2385
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   10425
   LinkTopic       =   "Form1"
   ScaleHeight     =   2385
   ScaleWidth      =   10425
   StartUpPosition =   3  'Windows �⺻��
   Begin VB.CommandButton btnFee 
      Caption         =   "�򰡿�Ź�Ѿ�/������ /�ֹ����ɱݾ�"
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
      TabIndex        =   8
      Top             =   120
      Width           =   3135
   End
   Begin VB.TextBox txtDate 
      Height          =   270
      Left            =   4560
      TabIndex        =   3
      Top             =   120
      Width           =   975
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
      TabIndex        =   4
      Top             =   600
      Width           =   10095
   End
   Begin VB.CommandButton btnEval 
      Caption         =   "����Ȳ"
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
      Left            =   5640
      TabIndex        =   2
      Top             =   120
      Width           =   1215
   End
   Begin VB.TextBox txtAccount 
      Height          =   270
      Left            =   960
      TabIndex        =   1
      Top             =   120
      Width           =   1335
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
      Left            =   3360
      TabIndex        =   0
      Top             =   120
      Width           =   612
   End
   Begin VB.Label Label1 
      Caption         =   "��¥"
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
      Left            =   4080
      TabIndex        =   7
      Top             =   120
      Width           =   495
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
      Left            =   2520
      TabIndex        =   6
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
      TabIndex        =   5
      Top             =   120
      Width           =   495
   End
End
Attribute VB_Name = "frm����Ȳ"
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
    
    txtDate.Text = Format(Now, "YYYYMMDD")
End Sub

Private Sub Form_Unload(Cancel As Integer)

    Set ����API��ü = Nothing
    
End Sub

Private Sub DisplayMsg(ByVal strMsg As String)

    ListBox1.AddItem strMsg, 0
    
End Sub

Private Sub ����API��ü_ReceiveData(ByVal nReqID As Long, ByVal szMsgCode As String, ByVal szMsg As String, ByVal szData As String)
    Select Case (nReqID)
        Case REQ_FUT_EVAL
            DisplayMsg ("����Ȳ ��ȸ>> " + szMsg)
            Parse_REQ_FUT_EVAL (szData)
        Case REQ_FUT_FEE
            DisplayMsg ("������/�ֹ����ɱݾ�/�򰡿�Ź�Ѿ� ��ȸ >> " + szMsg)
            Parse_REQ_FUT_FEE (szData)
            
    End Select
End Sub

Private Sub Parse_REQ_FUT_FEE(strData As String) '������
    
    Dim �򰡿�Ź�Ѿ�
    Dim �ֹ����ɱݾ�
    Dim ������

    Dim nPos As Long
    
    nPos = 1
    �򰡿�Ź�Ѿ� = MidEx(strData, nPos, 15)
    �ֹ����ɱݾ� = MidEx(strData, nPos, 16)
    ������ = MidEx(strData, nPos, 16)
    
    DisplayMsg strData
    
End Sub

Private Sub Parse_REQ_FUT_EVAL(strData As String) '��Ź��

On Error Resume Next
    ' TR_15813
    
    Dim �ѱ۾�����
    Dim ��Ź���Ѿ�
    Dim ��Ź����
    Dim ��Ź���
    Dim ��Ź���ű��Ѿ�
    Dim ������Ź���űݾ�
    Dim �������ű��Ѿ�
    Dim �����������űݾ�
    Dim �߰����ű��Ѿ�
    Dim �����߰����űݾ�
    Dim �ֹ������ѱݾ�
    Dim �����ֹ����ɱݾ�
    Dim ���Ⱑ���ѱݾ�
    Dim ���Ⱑ�����ݾ�
    Dim ����Ű

    Dim nPos As Long
    
    nPos = 1
    ��Ź���Ѿ� = MidEx(strData, nPos, 15)
    ��Ź���� = MidEx(strData, nPos, 15)
    ��Ź��� = MidEx(strData, nPos, 15)
    
    ��Ź���ű��Ѿ� = MidEx(strData, nPos, 15)
    ������Ź���űݾ� = MidEx(strData, nPos, 15)
    �������ű��Ѿ� = MidEx(strData, nPos, 14)
    �����������űݾ� = MidEx(strData, nPos, 15)
    
    �߰����ű��Ѿ� = MidEx(strData, nPos, 14)
    �����߰����űݾ� = MidEx(strData, nPos, 15)
    �ֹ������ѱݾ� = MidEx(strData, nPos, 14)
    �����ֹ����ɱݾ� = MidEx(strData, nPos, 15)
    
    ���Ⱑ���ѱݾ� = MidEx(strData, nPos, 14)
    ���Ⱑ�����ݾ� = MidEx(strData, nPos, 15)
    ����Ű = MidEx(strData, nPos, 15)
    
    DisplayMsg strData
    
End Sub

Private Sub btnEval_Click()
    Dim szAccount As String
    Dim szPwd As String
    Dim szDate As String
    Dim bRet As Boolean
            
    szAccount = txtAccount.Text
    szPwd = txtPwd.Text
    szDate = txtDate.Text
    
    bRet = ����API��ü.ReqEval(szAccount, szPwd, szDate)
End Sub

'������/�ֹ����� �ݾ�
Private Sub btnFee_Click()
    
    Dim szAccount As String
    Dim szPwd As String
    Dim szDate As String
    Dim bRet As Boolean
            
    szAccount = txtAccount.Text
    szPwd = txtPwd.Text
    szDate = txtDate.Text
    
    bRet = ����API��ü.ReqFeeNAbleMoney(szAccount, szPwd, szDate)
    
End Sub


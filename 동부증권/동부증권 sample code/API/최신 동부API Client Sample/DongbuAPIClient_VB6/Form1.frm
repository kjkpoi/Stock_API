VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "����API Client Sample(VB6)"
   ClientHeight    =   8250
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   6870
   BeginProperty Font 
      Name            =   "Fixedsys"
      Size            =   12
      Charset         =   129
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   LinkTopic       =   "Form1"
   ScaleHeight     =   8250
   ScaleWidth      =   6870
   StartUpPosition =   3  'Windows �⺻��
   Begin VB.Frame Frame5 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   3375
      Left            =   240
      TabIndex        =   21
      Top             =   2040
      Width           =   6495
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
         Height          =   1215
         Left            =   120
         TabIndex        =   38
         Top             =   2040
         Width           =   6255
         Begin VB.CommandButton btnSell 
            Caption         =   "�ŵ�"
            BeginProperty Font 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   375
            Left            =   4800
            TabIndex        =   44
            Top             =   240
            Width           =   1095
         End
         Begin VB.CommandButton btnBuy 
            Caption         =   "�ż�"
            BeginProperty Font 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   375
            Left            =   3600
            TabIndex        =   43
            Top             =   240
            Width           =   1095
         End
         Begin VB.TextBox edtJongCode 
            BeginProperty Font 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   288
            Left            =   600
            TabIndex        =   42
            Text            =   "201G1247"
            Top             =   360
            Width           =   1332
         End
         Begin VB.TextBox edtQty 
            BeginProperty Font 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   288
            Left            =   2640
            TabIndex        =   41
            Text            =   "1"
            Top             =   240
            Width           =   612
         End
         Begin VB.TextBox edtPrice 
            BeginProperty Font 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   288
            Left            =   2640
            TabIndex        =   40
            Text            =   "1.58"
            Top             =   600
            Width           =   612
         End
         Begin VB.CommandButton btnAbleQty 
            Caption         =   "�ű�/û�� ���ɼ���"
            BeginProperty Font 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   372
            Left            =   3600
            TabIndex        =   39
            Top             =   720
            Width           =   2295
         End
         Begin VB.Label Label5 
            Caption         =   "����"
            BeginProperty Font 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   255
            Left            =   120
            TabIndex        =   47
            Top             =   360
            Width           =   375
         End
         Begin VB.Label Label6 
            Caption         =   "����"
            BeginProperty Font 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   255
            Left            =   2160
            TabIndex        =   46
            Top             =   240
            Width           =   375
         End
         Begin VB.Label ���� 
            Caption         =   "����"
            BeginProperty Font 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   255
            Left            =   2160
            TabIndex        =   45
            Top             =   600
            Width           =   375
         End
      End
      Begin VB.Frame Frame2 
         Caption         =   "��ȸ"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   1215
         Left            =   120
         TabIndex        =   32
         Top             =   720
         Width           =   6255
         Begin VB.CommandButton btnCheguyl 
            Caption         =   "���ɽǽð�ü��"
            BeginProperty Font 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   372
            Left            =   120
            TabIndex        =   37
            Top             =   240
            Width           =   1815
         End
         Begin VB.CommandButton btnEval 
            Caption         =   "����Ȳ��ȸ"
            BeginProperty Font 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   372
            Left            =   3480
            TabIndex        =   35
            Top             =   240
            Width           =   1815
         End
         Begin VB.CommandButton btnFee 
            Caption         =   "�򰡿�Ź�Ѿ�/������ /�ֹ����ɱݾ�"
            BeginProperty Font 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   372
            Left            =   120
            TabIndex        =   34
            Top             =   720
            Width           =   3375
         End
         Begin VB.CommandButton btn�ɼ����񺰸ŵ����ű� 
            Caption         =   "�ɼ����񺰸ŵ����ű�"
            BeginProperty Font 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   372
            Left            =   3600
            TabIndex        =   33
            Top             =   720
            Width           =   2175
         End
         Begin VB.CommandButton btnJango 
            Caption         =   "�����ܰ���ȸ"
            BeginProperty Font 
               Name            =   "MS Sans Serif"
               Size            =   8.25
               Charset         =   0
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   372
            Left            =   1920
            TabIndex        =   36
            Top             =   240
            Width           =   1575
         End
      End
      Begin VB.CommandButton btnAcctList 
         Caption         =   "���ɰ�����ȸ"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   372
         Left            =   4920
         TabIndex        =   7
         Top             =   240
         Width           =   1455
      End
      Begin VB.TextBox txtPwd 
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   288
         Left            =   3960
         TabIndex        =   6
         Top             =   240
         Width           =   612
      End
      Begin VB.ComboBox cmbAcctList 
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   315
         Left            =   960
         TabIndex        =   5
         Top             =   240
         Width           =   2052
      End
      Begin VB.Label Label7 
         Caption         =   "���¹�ȣ"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   120
         TabIndex        =   23
         Top             =   240
         Width           =   735
      End
      Begin VB.Label Label8 
         Caption         =   "���º��"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   3120
         TabIndex        =   22
         Top             =   240
         Width           =   735
      End
   End
   Begin VB.Frame Frame4 
      Caption         =   "DRCM ���� "
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1815
      Left            =   240
      TabIndex        =   16
      Top             =   120
      Width           =   6492
      Begin VB.CheckBox chkMultiConn 
         Caption         =   "��������"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   252
         Left            =   2040
         TabIndex        =   27
         Top             =   1440
         Width           =   1095
      End
      Begin VB.TextBox edtLoginName 
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   264
         Left            =   4320
         TabIndex        =   25
         Text            =   "Text1"
         Top             =   360
         Width           =   1815
      End
      Begin VB.CheckBox chkShowLoginDlg 
         Caption         =   "�α���â ���̱�"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   252
         Left            =   240
         TabIndex        =   24
         Top             =   1440
         Width           =   1695
      End
      Begin VB.TextBox edtID 
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   264
         Left            =   1560
         TabIndex        =   1
         Text            =   "Text1"
         Top             =   360
         Width           =   1452
      End
      Begin VB.TextBox edtPwd 
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   264
         IMEMode         =   3  '��� ����
         Left            =   1560
         PasswordChar    =   "*"
         TabIndex        =   2
         Text            =   "Text2"
         Top             =   720
         Width           =   1452
      End
      Begin VB.TextBox edtCertPwd 
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   264
         IMEMode         =   3  '��� ����
         Left            =   1560
         PasswordChar    =   "*"
         TabIndex        =   3
         Text            =   "Text3"
         Top             =   1080
         Width           =   1452
      End
      Begin VB.CommandButton btnConnect 
         Caption         =   "����"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   975
         Left            =   3360
         TabIndex        =   4
         Top             =   720
         Width           =   1335
      End
      Begin VB.CommandButton btnDisconnect 
         Caption         =   "��������"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   975
         Left            =   4800
         TabIndex        =   17
         Top             =   720
         Width           =   1455
      End
      Begin VB.Label Label4 
         Caption         =   "LogIn Name"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   3360
         TabIndex        =   26
         Top             =   360
         Width           =   975
      End
      Begin VB.Label Label1 
         Caption         =   "�α���ID"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   252
         Left            =   240
         TabIndex        =   20
         Top             =   360
         Width           =   1212
      End
      Begin VB.Label Label2 
         Caption         =   "��й�ȣ"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   252
         Left            =   240
         TabIndex        =   19
         Top             =   720
         Width           =   1212
      End
      Begin VB.Label Label3 
         Caption         =   "�������� ��ȣ"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   240
         TabIndex        =   18
         Top             =   1080
         Width           =   1215
      End
   End
   Begin VB.CommandButton btnClearAll 
      Caption         =   "���� �����"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   372
      Left            =   5280
      TabIndex        =   14
      Top             =   6960
      Width           =   1455
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
      Height          =   840
      Left            =   240
      TabIndex        =   15
      Top             =   7320
      Width           =   6495
   End
   Begin VB.Frame Frame1 
      Caption         =   "�ǽð� ������ ��û ��� �� ���� "
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1335
      Left            =   240
      TabIndex        =   0
      Top             =   5520
      Width           =   6492
      Begin VB.TextBox txtOptCodes 
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   288
         Left            =   1080
         TabIndex        =   30
         Text            =   "201G1242,301G1242"
         Top             =   600
         Width           =   1935
      End
      Begin VB.TextBox txtFutuCodes 
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   288
         Left            =   1080
         TabIndex        =   28
         Text            =   "101G3000,101G6000"
         Top             =   240
         Width           =   1935
      End
      Begin VB.CheckBox btnSC0 
         Caption         =   "�����ü�(SC0)"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   252
         Left            =   3240
         TabIndex        =   8
         Top             =   240
         Width           =   1572
      End
      Begin VB.CheckBox btnOC0 
         Caption         =   "�ɼǽü�(OC0)"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   252
         Left            =   3240
         TabIndex        =   9
         Top             =   600
         Width           =   1572
      End
      Begin VB.CheckBox btnSH0 
         Caption         =   "����ȣ��(SH0)"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   252
         Left            =   4800
         TabIndex        =   10
         Top             =   240
         Width           =   1572
      End
      Begin VB.CheckBox btnOH0 
         Caption         =   "�ɼ�ȣ��(OH0)"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   252
         Left            =   4800
         TabIndex        =   11
         Top             =   600
         Width           =   1572
      End
      Begin VB.CheckBox btnXF2 
         Caption         =   "����ü��(XF2)"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   252
         Left            =   3240
         TabIndex        =   12
         Top             =   960
         Width           =   1572
      End
      Begin VB.CheckBox btnXF3 
         Caption         =   "�����ܰ�(XF3)"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   252
         Left            =   4800
         TabIndex        =   13
         Top             =   960
         Width           =   1572
      End
      Begin VB.Label Label10 
         Caption         =   "�ɼ�����"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   120
         TabIndex        =   31
         Top             =   600
         Width           =   855
      End
      Begin VB.Label Label9 
         Caption         =   "��������"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   120
         TabIndex        =   29
         Top             =   240
         Width           =   855
      End
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Private Declare Function ShellExecute Lib "shell32.dll" Alias "ShellExecuteA" _
   (ByVal hWnd As Long, ByVal lpOperation As String, ByVal lpFile As String, ByVal lpParameters As String, _
    ByVal lpDirectory As String, ByVal nShowCmd As Long) As Long
    
Private Declare Sub Sleep Lib "kernel32" (ByVal dwMilliseconds As Long)


Dim m_RTDataSCO As clsDrdsSC0
Dim m_RTDataSHO As clsDrdsSH0
Dim m_RTDataOCO As clsDrdsOC0
Dim m_RTDataOHO As clsDrdsOH0
   
Private Sub Form_Load()
    edtID.Text = ""
    edtLoginName.Text = "dongbutest"
    edtPwd.Text = ""
    edtCertPwd.Text = ""
    cmbAcctList.Text = ""
    txtPwd.Text = ""
    
    EnableControls (False)
    
    gHW = Me.hWnd
    Hook
        
    Set m_RTDataSCO = New clsDrdsSC0
    Set m_RTDataSHO = New clsDrdsSH0
    Set m_RTDataOCO = New clsDrdsOC0
    Set m_RTDataOHO = New clsDrdsOH0
End Sub

Private Sub Form_Unload(Cancel As Integer)
    Unhook
    DisconnectDRCM
    
    Set m_RTDataSCO = Nothing
    Set m_RTDataSHO = Nothing
    Set m_RTDataOCO = Nothing
    Set m_RTDataOHO = Nothing
End Sub

Private Sub btnClearAll_Click()
    ListBox1.Clear

End Sub

Private Sub btnDisconnect_Click()
    DisconnectDRCM
End Sub

Private Sub btnConnect_Click()
    DisplayMsg ("���� DRCM ���� �õ���...")

    m_hDongbuDRCM = FindDRCM
    

    If m_hDongbuDRCM = 0 Then
        MsgBox ("���� DRCM�� ã�� �� �����ϴ�")
        Exit Sub
    End If

    ConnectDRCM
End Sub

Private Function FindDRCM() As Long

    Dim hDrcmHwnd As Long
    Dim ProcID As Integer
    Dim strRegKey, KeyName As String
    Dim strExePath, strRoot, strExe, strWinName As String
    Dim lNewKey As Long
    Dim sBuffer As String
    Dim szTmpWinName As String
    Dim szMsg As String
    
    strRegKey = "Software\Dongbu Securities\DongbuDRCM\PATH"
    strExe = GetRegApi(HKEY_CURRENT_USER, "Exe", strRegKey)
    If strExe = "" Then
        DisplayMsg ("���� DRCM�� ��ġ�Ǿ� ���� �ʽ��ϴ�!")
        Exit Function
    End If
    
    strRoot = GetRegApi(HKEY_CURRENT_USER, "Root", strRegKey)
    strWinName = GetRegApi(HKEY_CURRENT_USER, "WinName", strRegKey)
    szTmpWinName = strWinName + "[" + Trim(edtLoginName.Text) + "]"
        
    
    '���� �������� drcm�� ã�´�
    hDrcmHwnd = FindWindow(vbNullString, szTmpWinName)

    'drcm�� �����Ų��
    If hDrcmHwnd = 0 Then
        strExePath = strRoot + "\Bin\" + strExe
        ProcID = ShellExecute(Form1.hWnd, "open", strExePath, Trim(edtLoginName.Text), vbNull, SW_HIDE)
        
        Sleep (1000)
        
        If ProcID > 0 Then
            hDrcmHwnd = FindWindow(vbNullString, strWinName)
        End If
    Else
        If (chkMultiConn.Value = vbChecked) Then
            ProcID = ShellExecute(Form1.hWnd, "open", strExePath, Trim(edtLoginName.Text), vbNull, SW_HIDE)
            Sleep (1000)
            If ProcID > 0 Then
                hDrcmHwnd = FindWindow(vbNullString, strWinName)
            End If
        Else
            szMsg = "�̹� ���� ID �� ���� DRCM�� �α׵Ǿ� �ֽ��ϴ�."
            MsgBox (szMsg)
            
            Form_Unload (1)
        End If
    

    End If

    FindDRCM = hDrcmHwnd

End Function


'DRCM�� ���������Ѵٰ� �޽��� ������
Public Sub DisconnectDRCM()

    Dim nRet As Long
    Dim cs As COPYDATASTRUCT
    
    cs.dwData = DRCM_DISCONNECT
    cs.cbData = 0
    
    nRet = SendMessage(m_hDongbuDRCM, WM_COPYDATA, Form1.hWnd, cs)
    
End Sub

Private Function ConnectDRCM() As Long

        Dim nRet As Long
        Dim stUserInfo As ST_DRCM_USER
        Dim cs As COPYDATASTRUCT
        Dim nDataLen As Integer
        Dim szData As String
        Dim szData2 As String
        Dim szData3 As String
        Dim szTmp As String
        Dim nLen As Integer
            
        'get user info
        stUserInfo.hClientWnd = Form1.hWnd
        
                        
        Dim strSpace As String
        strSpace = "                                                     "
                
        If (chkShowLoginDlg.Value = vbChecked) Then
            stUserInfo.bShowLoginDlg = 1
        Else
            stUserInfo.bShowLoginDlg = 0
        End If
                
        nLen = UBound(stUserInfo.szUserId) + 1
        CopyMemory stUserInfo.szUserId(0), ByVal strSpace, nLen
        szTmp = Trim(edtID.Text)
        nLen = Len(szTmp)
        CopyMemory stUserInfo.szUserId(0), ByVal szTmp, nLen
                
        nLen = UBound(stUserInfo.szPwd) + 1
        CopyMemory stUserInfo.szPwd(0), ByVal strSpace, nLen
        szTmp = Trim(edtPwd.Text)
        nLen = Len(szTmp)
        CopyMemory stUserInfo.szPwd(0), ByVal szTmp, nLen
                
        nLen = UBound(stUserInfo.szCertPwd) + 1
        CopyMemory stUserInfo.szCertPwd(0), ByVal strSpace, nLen
        szTmp = Trim(edtCertPwd.Text)
        nLen = Len(szTmp)
        CopyMemory stUserInfo.szCertPwd(0), ByVal szTmp, nLen
                    
        '���ӽõ�
        nDataLen = Len(stUserInfo)
        cs.dwData = DRCM_CONNECT
        cs.cbData = nDataLen
        cs.lpData = VarPtr(stUserInfo)

        nRet = SendMessage(m_hDongbuDRCM, WM_COPYDATA, Form1.hWnd, cs)
         
        Select Case (nRet)
            Case DRCM_MSG_LOGINFAIL
                MsgBox ("�α��� ����")

            Case DRCM_MSG_SOCKETFAIL
                MsgBox ("���� ���� ����")

            Case Else
                m_hSocket = nRet
        End Select

        If m_hSocket <> 0 Then
            GetClientIp
            EnableControls (True)

            DisplayMsg ("�α��� ����")
        Else
            DisplayMsg ("�α��� ����")
        End If

    End Function
    
Private Sub DisplayMsg(ByVal strMsg As String)
    ListBox1.AddItem strMsg, 0
End Sub

'DRCM���� ����Ǿ��ٴ� �޽����� �޾Ƽ� ó��
Public Sub DisconnectedDRCM()

    DisplayMsg ("���� DRCM�� ����Ǿ����ϴ�")
   
    m_hSocket = 0
    m_hDongbuDRCM = 0

    EnableControls (False)

End Sub

    'ȭ�� ��ư�� ó��
Public Sub EnableControls(ByVal bConnected As Boolean)

    Dim bEnabled As Boolean
    bEnabled = bConnected
    
    If bConnected Then
        btnConnect.Enabled = False
    Else
        btnConnect.Enabled = True
    End If

    btnDisconnect.Enabled = bEnabled
    btnSell.Enabled = bEnabled
    btnBuy.Enabled = bEnabled
    btnJango.Enabled = bEnabled
    btnCheguyl.Enabled = bEnabled
    btnEval.Enabled = bEnabled
    btnFee.Enabled = bEnabled
    btnAcctList.Enabled = bEnabled
    
    btn�ɼ����񺰸ŵ����ű�.Enabled = bEnabled
    
    
End Sub

'DRCM�� TR ������ - �ڱ� �ڽ��� Ip ���ϱ� ����
Private Sub GetClientIp()

    Dim nRet As Long
    Dim cs As COPYDATASTRUCT
    cs.dwData = DRCM_CLIENT_IP
    cs.cbData = 0
    nRet = SendMessage(m_hDongbuDRCM, WM_COPYDATA, Form1.hWnd, cs)

End Sub

Private Sub btnAcctList_Click()
    Dim nRet As Long
    Dim cs As COPYDATASTRUCT
    cs.dwData = DRCM_F_ACCLIST
    cs.cbData = 0
    nRet = SendMessage(m_hDongbuDRCM, WM_COPYDATA, Form1.hWnd, cs)
End Sub

'DRCM�� TR ������
Private Function SendToServerEx(ByVal nWorkType As Integer, ByVal szTrCode As String, ByVal szData As String) As Long

    On Error Resume Next

    Dim szSendData As String
    Dim nRet As Long
    Dim buf(1 To MAX_COPYBUFF) As Byte
     
    If IsEmpty(szData) Or IsNull(szData) Then
        SendToServerEx = False
        Exit Function
    End If

    Select Case (nWorkType)
        Case DRCM_SENDDATA
            szSendData = StrPadRight(szTrCode, 5, " ") + szData
        Case DRCM_ADVICE, DRCM_UNADVICE
            szSendData = StrPadRight(szTrCode, 3, " ") + szData
    End Select

    'DRCM�� TR ������
    Dim cs As COPYDATASTRUCT
    Dim nLenSendData As Integer
    
    nLenSendData = Len(szSendData)
    
    cs.dwData = nWorkType
    If nLenSendData = 0 Then
        cs.cbData = 0
        cs.lpData = 0
    Else
        cs.cbData = nLenSendData + 1
        
        Call CopyMemory(buf(1), ByVal szSendData, nLenSendData)
        cs.lpData = VarPtr(buf(1))
    End If
        
    nRet = SendMessage(m_hDongbuDRCM, WM_COPYDATA, Form1.hWnd, cs)

    If nRet <> 1 Then
        MsgBox ("DRCM SERVER�� ��û ����!")
    End If
    
    SendToServerEx = nRet

End Function


Private Sub GetFutureAccList(ByVal strData As String, ByVal nLen As Integer)

    Dim nCount As Long
    Dim nPos As Long
    Dim i As Integer
    
    Dim szAcctInfo As String
    Dim szGubun As String
    Dim szAccNo As String
    Dim szAccName As String
    Dim strTmp As String
        
    If Len(strData) < 3 Then
        Exit Sub
    End If
    
    nPos = 1
    
    strTmp = MidEx(strData, nPos, 3)
    nCount = CLng(strTmp)
            
    cmbAcctList.Clear
    Dim szTmp  As String
           
    For i = 1 To nCount
        
        szGubun = MidEx(strData, nPos, 1)
        szAccNo = MidEx(strData, nPos, LEN_GEJANO)
        szAccName = MidEx�ѱ�(strData, nPos, 20)
        
        szAcctInfo = szAccNo + " " + Trim(szAccName)
        DisplayMsg ("���ɰ��� >> " + Str(i) + " : " + szAcctInfo)
        
        cmbAcctList.AddItem szAcctInfo
        
        If i = nCount Then
            cmbAcctList.Text = szAcctInfo
        End If
    Next i
        
End Sub

Private Sub btnBuy_Click()
    Dim strData As String
    Dim strData2 As String
    Dim nRet As Long
    
    strData = MakeJumun("2", "0")
    nRet = SendToServerEx(DRCM_SENDDATA, TR_20000, strData)
    
End Sub

Private Sub btnSell_Click()

    Dim strData As String
    Dim nRet As Long
    
    strData = MakeJumun("1", "0")
    nRet = SendToServerEx(DRCM_SENDDATA, TR_20000, strData)

End Sub

Private Function MakeJumun(szGubun As String, szOrgOrderNo As String) As String
    
    Dim szCnt As String
    Dim szMapno As String

    Dim szClikey As String
    Dim szAccount As String
    Dim szPwd As String
    Dim szFnoIsuNo As String
    Dim szOrgOrdNo As String
    Dim szFnoOrdprcPtnCode As String
    Dim szOrdPrc As String
    Dim szOrdQty As String
        
    Dim nOrderPrice As Long
    Dim szData As String

    nOrderPrice = CLng(CDbl(edtPrice.Text) * 100)

    szCnt = "0001" '(4)
    szMapno = "88888" '(5)
    szClikey = StrPadRight("", 8, "8")                '/* �ֹ� key(���Ƿ�
    'szGubun              '(1)                          '/* 1:�ŵ�, 2:�ż�,  3:����, 4:���
    szAccount = Left(cmbAcctList.Text, LEN_GEJANO)
    szAccount = StrPadRight(szAccount, 20, " ")     '/* ���¹�ȣ
    szPwd = StrPadRight(txtPwd.Text, 8, " ")        '/* ��й�ȣ
    
    szFnoIsuNo = StrPadRight(edtJongCode.Text, 15, " ")  '/* �����ڵ�(15)
    szOrgOrderNo = StrPadRight(szOrgOrderNo, 9, "0") '/*���ֹ���ȣ(9)
    szFnoOrdprcPtnCode = "00"                        '/* 00:������ 03:���尡 05:���Ǻ�������  06:������������
        
    szOrdPrc = Format(nOrderPrice, "+00000000000") ' '/* �ֹ���(12)
    szOrdQty = StrPadLeft(edtQty.Text, 15, "0")      '/* �ֹ�����(15)

    szData = szCnt + szMapno + szClikey + szGubun + szAccount + szPwd + szFnoIsuNo + szOrgOrderNo + szFnoOrdprcPtnCode + szOrdPrc + szOrdQty + m_szIP
    
    MakeJumun = szData
    
End Function

'�ܰ���ȸ
Private Sub btnJango_Click()
    Dim szAccount As String
    Dim szData As String
    Dim nRet As Long
    
    szAccount = Left(cmbAcctList.Text, LEN_GEJANO)
    
    If IsEmpty(szAccount) Then
        Exit Sub
    End If
        
    szAccount = StrPadRight(szAccount, 20, " ")
    
    szData = szAccount

    nRet = SendToServerEx(DRCM_SENDDATA, TR_13655, szData)
End Sub
'ü�᳻��
Private Sub btnCheguyl_Click()
    Dim szAccount As String
    Dim szPwd As String
    Dim szSort As String
    Dim szUserfld As String
    Dim szData As String
    Dim nRet As Long
        
    szAccount = Left(cmbAcctList.Text, LEN_GEJANO)
    szAccount = StrPadRight(szAccount, 20, " ")
    
    szPwd = StrPadRight(txtPwd.Text, 8, " ")
    szSort = "1"
    szUserfld = StrPadRight("", 100, " ")
        
    szData = szAccount + szPwd + szSort + szUserfld

    nRet = SendToServerEx(DRCM_SENDDATA, TR_13615, szData)
        
End Sub

'����Ȳ ��ȸ
Private Sub btnEval_Click()

    Dim szAccount As String
    Dim szPwd As String
    Dim szDate As String
    Dim szJangGubun As String
    Dim szFutureGubun As String
    Dim szNextKey As String
    Dim szIp As String
    Dim nRet As Long
    Dim szData As String
        
    szAccount = Left(cmbAcctList.Text, LEN_GEJANO)
    szAccount = StrPadRight(szAccount, 20, " ")
    szPwd = StrPadRight(txtPwd.Text, 8, " ")
    szDate = Format(Now, "YYYYMMDD")
    szJangGubun = "2"
    szFutureGubun = "1"
    szIp = StrPadRight(m_szIP, 16, "0")
    szNextKey = StrPadRight("", 19, "0")
    
    szData = szAccount + szPwd + szDate + szJangGubun + szFutureGubun + szIp + szNextKey
    
    nRet = SendToServerEx(DRCM_SENDDATA, TR_15813, szData)
    
End Sub

'�ɼ����񺰸ŵ����ű� 1600
Private Sub btn�ɼ����񺰸ŵ����ű�_Click()
    
    Dim szIp As String
    Dim nRet As Long
    Dim szData As String
    
    Dim sz��ǰ���ڵ� As String    'x(2)
    Dim sz�����ڻ��ڵ� As String  'x(3) ��ü 000
    Dim sz�ֱٿ������� As String  'x(1)
    Dim szNextKey As String       'x(19)
    
           
    sz��ǰ���ڵ� = "00"
    sz�����ڻ��ڵ� = "000"
    sz�ֱٿ������� = "0"
    
    szIp = StrPadRight(m_szIP, 16, "0")
    szNextKey = StrPadRight("", 19, "0")
    
    szData = sz��ǰ���ڵ� + sz�����ڻ��ڵ� + sz�ֱٿ������� + szIp + szNextKey
    nRet = SendToServerEx(DRCM_SENDDATA, TR_16260, szData)
    
End Sub

'�ű�/û�� ���ɼ���
Private Sub btnAbleQty_Click()

    Dim szAccount As String
    Dim szPwd As String
    Dim szJongmok As String
    Dim sz�Ÿű��� As String
    Dim szFnoOrdprcPtnCode As String
    Dim szû�������ȸ���� As String
    Dim sz�ֹ��� As String
    Dim szIp As String
    Dim nRet As Long
    Dim szData As String
    Dim nOrderPrice As Long
    
    If (Not IsEmpty(edtPrice.Text)) Then
        nOrderPrice = CLng(CDbl(edtPrice.Text) * 100)
    End If
        
    szAccount = Left(cmbAcctList.Text, LEN_GEJANO)
    szAccount = StrPadRight(szAccount, 20, " ")
    szPwd = StrPadRight(txtPwd.Text, 8, " ")
    szJongmok = StrPadRight(edtJongCode.Text, 12, " ")  '/*�����ڵ�(12)
    sz�Ÿű��� = "2"                       '            '/*�Ÿű���(1) # 1:�ŵ�, 2:�ż�
    sz�ֹ��� = Format(nOrderPrice, "000000000000") '    '/*�ֹ���(12) # S9(10)99
    szFnoOrdprcPtnCode = "00"                           '/*�����ɼ�ȣ�������ڵ�(2) # 00:������ 03:���尡 05:���Ǻ�������  06:������������
    szû�������ȸ���� = "0"                            '/*û�������ȸ���� # 0:û���Ҽ��ִ¼���,1:���ű������Ǵ��ֹ������ؼ��������ȸ(����)
        
    szIp = StrPadRight(m_szIP, 16, "0")
    
    
    szData = szAccount + szPwd + szJongmok + sz�Ÿű��� + sz�ֹ��� + szFnoOrdprcPtnCode + szû�������ȸ���� + szIp
    nRet = SendToServerEx(DRCM_SENDDATA, TR_14051, szData)

End Sub


Private Sub btnFee_Click()

On Error Resume Next
    Dim szAccount As String
    Dim szPwd As String
    Dim szDate As String
    Dim szNextKey As String
    Dim szIp As String
    Dim nRet As Long
    Dim szData As String
    
    szAccount = Left(cmbAcctList.Text, LEN_GEJANO)
    szAccount = StrPadRight(szAccount, 20, " ")
    szPwd = StrPadRight(txtPwd.Text, 18, " ")
    szDate = Format(Now, "YYYYMMDD")
    szIp = StrPadRight(m_szIP, 16, "0")
    
    szData = szAccount + szPwd + szDate + szIp
    
    nRet = SendToServerEx(DRCM_SENDDATA, TR_13653, szData)

End Sub

Private Sub btnXF2_Click()
    Dim szId As String
    Dim nRet As Long

    szId = Trim(edtID.Text)

    If (btnXF2.Value = vbChecked) Then
        nRet = SendToServerEx(DRCM_ADVICE, R_XF2, szId)
    Else
        nRet = SendToServerEx(DRCM_UNADVICE, R_XF2, szId)
    End If

End Sub

Private Sub btnXF3_Click()
    Dim szId As String
    Dim nRet As Long

    szId = Trim(edtID.Text)

    If (btnXF3.Value = vbChecked) Then
        nRet = SendToServerEx(DRCM_ADVICE, R_XF3, szId)
    Else
        nRet = SendToServerEx(DRCM_UNADVICE, R_XF3, szId)
    End If

End Sub

Private Sub btnOC0_Click()

    Dim szData As String
    Dim nRet As Long

    szData = txtOptCodes.Text

    If (btnOC0.Value = vbChecked) Then
        nRet = SendToServerEx(DRCM_ADVICE, R_OC0, szData)
    Else
        nRet = SendToServerEx(DRCM_UNADVICE, R_OC0, szData)
    End If

End Sub

Private Sub btnOH0_Click()
    Dim szData As String
    Dim nRet As Long

    szData = txtOptCodes.Text

    If (btnOH0.Value = vbChecked) Then
        nRet = SendToServerEx(DRCM_ADVICE, R_OH0, szData)
    Else
        nRet = SendToServerEx(DRCM_UNADVICE, R_OH0, szData)
    End If

End Sub

Private Sub btnSC0_Click()

    Dim szData As String
    Dim nRet As Long

    szData = txtFutuCodes.Text

    If (btnSC0.Value = vbChecked) Then
        nRet = SendToServerEx(DRCM_ADVICE, R_SC0, szData)
    Else
        nRet = SendToServerEx(DRCM_UNADVICE, R_SC0, szData)
    End If

End Sub

Private Sub btnSH0_Click()
    Dim szData As String
    Dim nRet As Long

    szData = txtFutuCodes.Text

    If (btnSH0.Value = vbChecked) Then
        nRet = SendToServerEx(DRCM_ADVICE, R_SH0, szData)
    Else
        nRet = SendToServerEx(DRCM_UNADVICE, R_SH0, szData)
    End If

End Sub

Private Function GetIp(ByVal strData As String)

    Dim strArr() As String
    Dim i As Long
    Dim nCount As Long
    Dim strIp As String
    Dim strTmp As String
    
    strArr = Split(strData, ".")
            
    For i = 0 To 3
        strTmp = Format(strArr(i), "000")
        strIp = strIp + strTmp
    Next i
        
    GetIp = StrPadRight(strIp, 16, "0")
    
End Function

Private Sub OnRealTimeData(ByVal strData As String)
    Dim nType As Long
    Dim nID As Long
    Dim strName As String
    Dim strField As String
    Dim strKey As String
    Dim nLen As Long
    Dim nPos As Long
    
    nPos = 1
    strName = MidEx(strData, nPos, 3)
        
    nPos = 104
    strData = Mid(strData, nPos)
    
    DisplayMsg ("�ǽð������� ����>>" + strName)
    
    Select Case strName
    
    Case R_SC0 '= "SC0"
        Call Parse_SC0(strData)                ' ���� ���簡
    Case R_SH0 '= "SH0"                        ' ���� ȣ��
        Parse_SH0 (strData)
    Case R_OC0 '= "OC0"                        ' �ɼ� ���簡
        Call Parse_OC0(strData)
    Case R_OH0 '= "OH0"                        ' �ɼ� ȣ��
        Call Parse_OH0(strData)
    Case R_XF2 '= "XF2"                        ' ü��
    Case R_XF3 '= "XF3"                        ' �ܰ�
    End Select
End Sub

Private Sub Parse_SC0(ByVal strData As String)
    m_RTDataSCO.Init (strData)
End Sub

Private Sub Parse_SH0(ByVal strData As String)
    m_RTDataSHO.Init (strData)
End Sub

Private Sub Parse_OC0(ByVal strData As String)
    m_RTDataOCO.Init (strData)
End Sub

Private Sub Parse_OH0(ByVal strData As String)
    m_RTDataOHO.Init (strData)
End Sub


Private Sub ParseTR_20000(strData As String) '�ֹ�����

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

Private Sub ParseTR_15813(strData As String) '��Ź��

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
    
End Sub

Private Sub ParseTR_13653(strData As String) '������
    ' TR_13653
    
    Dim �򰡿�Ź�Ѿ�
    Dim �ֹ����ɱݾ�
    Dim ������

    Dim nPos As Long
    
    nPos = 1
    �򰡿�Ź�Ѿ� = MidEx(strData, nPos, 15)
    �ֹ����ɱݾ� = MidEx(strData, nPos, 16)
    ������ = MidEx(strData, nPos, 16)
    
End Sub

Private Sub ParseTR_14051(strData As String) '�ű�/û�� ���� ��ȸ
    ' TR_14051
    
    Dim �ű��ֹ����ɼ���
    Dim û���ֹ����ɼ���
    
    Dim nPos As Long
    
    nPos = 1
    �ű��ֹ����ɼ��� = MidEx(strData, nPos, 15)
    û���ֹ����ɼ��� = MidEx(strData, nPos, 15)
End Sub


Private Sub ParseTR_13655(strData As String) '�ܰ���ȸ

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
    
    Dim �����ڵ�
    Dim �ŸżӼ�
    Dim �Ÿű���
    Dim û�갡��
    Dim �����ܰ�
    Dim ����
    Dim ��������
    Dim ��ü���ֹ�����
    Dim ���Դܰ�
    Dim ���簡
    Dim �򰡼���
    Dim ������
    Dim �����ݾ�
    Dim �򰡱ݾ�
    Dim ������
    Dim �ż�ȣ��
    Dim �ŵ�ȣ��
    Dim ���Ѱ�
    Dim ���Ѱ�
    Dim ����Ҽӱ���
    Dim ���Ͻ�������D
    Dim �ֹ�����
    Dim �ŷ�����
    Dim ���ϸż��Ǵ¸ŵ��ݾ�
    Dim �ŸŴ����
 
    Dim i As Long, nPos As Long
    
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
        
        �����ڵ� = MidEx(strData, nPos, 15)
        
        �ŸżӼ� = MidEx(strData, nPos, 2)
        �Ÿű��� = MidEx�ѱ�(strData, nPos, 5)
        
        û�갡�� = MidEx(strData, nPos, 15)
        �����ܰ� = MidEx(strData, nPos, 15)
        ���� = MidEx(strData, nPos, 15)
        �������� = MidEx(strData, nPos, 15)
        ��ü���ֹ����� = MidEx(strData, nPos, 15)
        ���Դܰ� = MidEx(strData, nPos, 12)
        ���簡 = MidEx(strData, nPos, 6)
        �򰡼��� = MidEx(strData, nPos, 15)
        ������ = MidEx(strData, nPos, 9)
        �����ݾ� = MidEx(strData, nPos, 15)
        �򰡱ݾ� = MidEx(strData, nPos, 15)
        ������ = MidEx(strData, nPos, 12)
        �ż�ȣ�� = MidEx(strData, nPos, 6)
        �ŵ�ȣ�� = MidEx(strData, nPos, 6)
        ���Ѱ� = MidEx(strData, nPos, 6)
        ���Ѱ� = MidEx(strData, nPos, 6)
        ����Ҽӱ��� = MidEx(strData, nPos, 1)
        ���Ͻ�������D = MidEx(strData, nPos, 15)
        �ֹ����� = MidEx(strData, nPos, 3)
        �ŷ����� = MidEx(strData, nPos, 15)
        ���ϸż��Ǵ¸ŵ��ݾ� = MidEx(strData, nPos, 15)
        �ŸŴ���� = MidEx(strData, nPos, 15)
                    
    Next i
    
End Sub

Private Sub ParseTR_13615(strData As String) 'ü�Ḯ��Ʈ

On Error Resume Next
    'TR_13615

    Dim ���ڵ�Count As Long
    Dim ���ڵ�Len As String
    Dim �׸���Msg As String

    Dim �ֹ���ȣ As Long
    Dim �����ʵ� As String
    Dim �����ڵ� As String
    Dim �ֹ����мӼ� As String
    Dim �ֹ����� As String
    
    Dim �ֹ����� As String
    Dim �ֹ��ܰ� As String
    Dim �ֹ����� As String
    Dim ü�ᰡ�� As String
    Dim ü����� As String
    Dim ��ü����� As String
    Dim ���ֹ���ȣ As String
    Dim �Ÿű��� As String
    Dim �źθ޼��� As String
           
    Dim nGridData As String
    Dim nPos As Long, i As Long
    
    nPos = 1
    
    �����ʵ� = MidEx(strData, nPos, 100)
    ���ڵ�Count = MidEx(strData, nPos, 4)
    ���ڵ�Len = MidEx(strData, nPos, 4)
    �׸���Msg = MidEx(strData, nPos, 5)
    
    For i = 1 To ���ڵ�Count
    
        strData = Mid(strData, nPos):       nPos = 1
                        
        �ֹ���ȣ = MidEx(strData, nPos, 9)
        ���ֹ���ȣ = MidEx(strData, nPos, 9)
        �����ڵ� = MidEx(strData, nPos, 15)
        �ֹ����мӼ� = MidEx(strData, nPos, 3)
        �ֹ����� = Trim(MidEx�ѱ�(strData, nPos, 12))
                
        �ֹ����� = MidEx�ѱ�(strData, nPos, 12)
        �ֹ��ܰ� = MidEx(strData, nPos, 12)
        �ֹ����� = MidEx(strData, nPos, 15)
        ü�ᰡ�� = MidEx(strData, nPos, 12)
        ü����� = MidEx(strData, nPos, 15)
        ��ü����� = MidEx(strData, nPos, 15)
        �źθ޼��� = MidEx�ѱ�(strData, nPos, 40)
    Next i
    
End Sub


Private Sub ParseTR_16260(strData As String) '�ɼ����񺰸ŵ����ű�

On Error Resume Next
    'TR_16260
    
    Dim ���ӿ���Ű As String        'x(1)
    Dim ����Ű As String        'x(18)
    Dim ��ȸ�Ǽ� As String      'x(5)
    
    Dim ��簡 As String                    'x(13)
    Dim C�����ɼǰ��������ȣ As String     'x(32)
    Dim C���и� As String                   'x(40) �ѱ�
    Dim C�̷а� As String                   'x(19)
    Dim C���ذ� As String                   'x(13)
    Dim C�ֹ����űݾ� As String             'x(16)
    
    Dim P�����ɼǰ��������ȣ As String     'x(32)
    Dim P���и� As String                   'x(40) �ѱ�
    Dim P�̷а� As String                   'x(19)
    Dim P���ذ� As String                   'x(13)
    Dim P�ֹ����űݾ� As String             'x(16)
    
    
    Dim �����ʵ� As String
    Dim ���ڵ�Count As String
    Dim ���ڵ�Len As String
    Dim �׸���Msg As String
    
    
    Dim nPos As Long, i As Long
    
    nPos = 1
    nPos = InStr(strData, "EN=")
    If (nPos < 1) Then
        Exit Sub
    End If
    
    ���ӿ���Ű = MidEx(strData, nPos + 3, 1)
    nPos = InStr(strData, "DT=")
    nPos = nPos + 3
    ����Ű = MidEx(strData, nPos, 18)
    ��ȸ�Ǽ� = MidEx(strData, nPos, 4)
        
    nPos = 41
    For i = 1 To ��ȸ�Ǽ�
        strData = Mid(strData, nPos): nPos = 1
        
        ��簡 = MidEx(strData, nPos, 13)
        ��簡 = Replace(��簡, "+", "")
                
        C�����ɼǰ��������ȣ = MidEx(strData, nPos, 32)
        C���и� = MidEx�ѱ�(strData, nPos, 40)
        C�̷а� = MidEx(strData, nPos, 19)
        C���ذ� = MidEx(strData, nPos, 13)
        C�ֹ����űݾ� = MidEx(strData, nPos, 16)
        
        P�����ɼǰ��������ȣ = MidEx(strData, nPos, 32)
        P���и� = MidEx�ѱ�(strData, nPos, 40)
        P�̷а� = MidEx(strData, nPos, 19)
        C���ذ� = MidEx(strData, nPos, 13)
        C�ֹ����űݾ� = MidEx(strData, nPos, 16)
    Next i
    
End Sub

Public Sub ParseReceivedData(lParam As Long)

On Error GoTo OnError

    Dim cds As COPYDATASTRUCT
    'Dim buf(1 To MAX_COPYBUFF) As Byte
    Dim buf() As Byte

    Dim strData As String
    Dim i As Integer
    Dim strData2 As String
    Dim strData3 As String
    Dim nDataLen As Long
    
    
    Call CopyMemory(cds, ByVal lParam, Len(cds))
    

    ReDim buf(0 To MAX_COPYBUFF)
    
 
    'unicode�� ��ȯ
    Select Case (cds.dwData)

        Case DRCM_DISCONNECT
            DisconnectedDRCM

        Case DRCM_CLIENT_IP
            Call CopyMemory(buf(0), ByVal cds.lpData, cds.cbData)
            strData = StrConv(buf, vbUnicode)
            strData = Left$(strData, InStr(1, strData, Chr$(0)) - 1)
            m_szIP = GetIp(strData)
                    
        Case DRCM_F_ACCLIST
            Call CopyMemory(buf(0), ByVal cds.lpData, cds.cbData)
            strData = StrConv(buf, vbUnicode)
            strData = Left$(strData, InStr(1, strData, Chr$(0)) - 1)
            GetFutureAccList strData, cds.cbData
            
                        
        Case DRCM_DRDS_DATA
            nDataLen = cds.cbData
            If (nDataLen >= MAX_COPYBUFF) Then
                ReDim buf(nDataLen + 1)
            End If
            
            Call CopyMemory(buf(0), ByVal cds.lpData, cds.cbData)
                        
            strData = Replace(StrConv(buf, vbUnicode), Chr$(0), Chr$(32))
            OnRealTimeData strData

        Case Else
                                                
            nDataLen = cds.cbData
            If (nDataLen >= MAX_COPYBUFF) Then
                ReDim buf(nDataLen + 1)
            End If
            
            Call CopyMemory(buf(1), ByVal cds.lpData, cds.cbData)
            For i = 0 To 4
                buf(i) = 1&
            Next
                     
            strData = Replace$(StrConv(buf, vbUnicode), Chr$(0), Chr$(32))
            
            OnReceiveData strData
            
    End Select
    
    Exit Sub
OnError:
    'MsgBox "Error : ParseReceivedData()"
    
End Sub


'TR ����Ÿ ó��
Private Sub OnReceiveData(ByVal strData As String)

On Error Resume Next

    'packet header ---------
    Dim WindowID As Long
    Dim strTrCode As String
    Dim strMsgCode As String
    Dim strMessage As String
    Dim strCursorPos As String
    Dim strMsg2Len As String
    Dim strAPDataLen As String
    'Dim strTmp As String
    Dim strTRData As String
    '------------------------
    
    Dim nPos As Long
    
    nPos = 6
    
    strTrCode = MidEx(strData, nPos, 5)
    strMsgCode = MidEx(strData, nPos, 6)
    strMessage = MidEx�ѱ�(strData, nPos, 82)
    strCursorPos = MidEx(strData, nPos, 2)
    strMsg2Len = MidEx(strData, nPos, 3)
    strAPDataLen = MidEx(strData, nPos, 3)
    strTRData = Mid(strData, nPos)
                
    If strTrCode = TR_20000 Then '�ֹ�
        DisplayMsg ("�ֹ� >> " + strMessage)
        ParseTR_20000 (strTRData)

    ElseIf strTrCode = TR_13655 Then '�ܰ���ȸ
        DisplayMsg ("�ܰ���ȸ >> " + strMessage)
        ParseTR_13655 (strTRData)
        
    ElseIf strTrCode = TR_13615 Then 'ü�᳻�� ��ȸ
        DisplayMsg ("ü�᳻�� >> " + strMessage)
        ParseTR_13615 (strTRData)

    ElseIf strTrCode = TR_15813 Then '����Ȳ ��ȸ, ��Ź��, �ֹ����ɱݾ�
        DisplayMsg ("����Ȳ >> " + strMessage)
        ParseTR_15813 (strTRData)

    ElseIf strTrCode = TR_13653 Then '������, �ֹ������Ѿ�
        DisplayMsg ("������ ��ȸ �Ϸ� ")
        ParseTR_13653 (strTRData)
        
    ElseIf strTrCode = TR_16260 Then '�ɼ����񺰸ŵ����ű�
        DisplayMsg ("�ɼ����񺰸ŵ����ű� ��ȸ >> " + strMessage)
        ParseTR_16260 (strTRData)
        
    ElseIf strTrCode = TR_14051 Then '�ű�/û�갡�ɼ��� ��ȸ
        DisplayMsg ("�ű�/û�갡�ɼ��� ��ȸ >> " + strMessage)
        ParseTR_14051 (strTRData)
                
    End If

End Sub




VERSION 5.00
Object = "{018DA320-99C5-4BEE-B201-A049156D00C8}#1.0#0"; "DONGBU~1.OCX"
Begin VB.Form frmMain 
   Caption         =   "����API Client Sample(VB6.0)"
   ClientHeight    =   9075
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   8355
   BeginProperty Font 
      Name            =   "����ü"
      Size            =   9
      Charset         =   129
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   LinkTopic       =   "Form1"
   ScaleHeight     =   9075
   ScaleWidth      =   8355
   StartUpPosition =   3  'Windows �⺻��
   Begin DONGBUAPILib.DongbuAPI DongbuAPI1 
      Height          =   255
      Left            =   2160
      TabIndex        =   55
      Top             =   7800
      Visible         =   0   'False
      Width           =   1695
      _Version        =   65536
      _ExtentX        =   2990
      _ExtentY        =   450
      _StockProps     =   0
   End
   Begin VB.PictureBox DongbuDRCM1 
      Height          =   255
      Left            =   4680
      ScaleHeight     =   195
      ScaleWidth      =   1875
      TabIndex        =   49
      Top             =   7440
      Visible         =   0   'False
      Width           =   1935
   End
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
      Height          =   4455
      Left            =   120
      TabIndex        =   21
      Top             =   1800
      Width           =   8055
      Begin VB.CommandButton btnStockAcctList 
         Caption         =   "�ֽİ�����ȸ"
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
         Left            =   6480
         TabIndex        =   45
         Top             =   240
         Width           =   1455
      End
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
         TabIndex        =   33
         Top             =   3000
         Width           =   7815
         Begin VB.CommandButton btnStockOrder 
            Caption         =   "�ֽ� �ֹ�"
            Height          =   375
            Left            =   4320
            TabIndex        =   48
            Top             =   720
            Width           =   1095
         End
         Begin VB.CommandButton btnOrder 
            Caption         =   "���� �ֹ�"
            Height          =   375
            Left            =   4320
            TabIndex        =   44
            Top             =   240
            Width           =   1095
         End
         Begin VB.OptionButton opt�ż� 
            Caption         =   "�ż�"
            Height          =   255
            Left            =   3480
            TabIndex        =   43
            Top             =   600
            Value           =   -1  'True
            Width           =   855
         End
         Begin VB.OptionButton opt�ŵ� 
            Caption         =   "�ŵ�"
            Height          =   255
            Left            =   3480
            TabIndex        =   42
            Top             =   240
            Width           =   855
         End
         Begin VB.ComboBox cmbPriceType 
            Height          =   300
            Left            =   600
            TabIndex        =   41
            Text            =   "Combo1"
            Top             =   720
            Width           =   1335
         End
         Begin VB.TextBox edtJongCode 
            Height          =   288
            Left            =   600
            TabIndex        =   37
            Text            =   "301G1215"
            Top             =   360
            Width           =   1332
         End
         Begin VB.TextBox edtQty 
            Height          =   288
            Left            =   2640
            TabIndex        =   36
            Text            =   "1"
            Top             =   240
            Width           =   612
         End
         Begin VB.TextBox edtPrice 
            Height          =   288
            Left            =   2640
            TabIndex        =   35
            Text            =   "0.88"
            Top             =   600
            Width           =   612
         End
         Begin VB.CommandButton btnAbleQty 
            Caption         =   "�ű�/û�� ���ɼ���"
            Height          =   375
            Left            =   5520
            TabIndex        =   34
            Top             =   240
            Width           =   2175
         End
         Begin VB.Label Label5 
            Caption         =   "����"
            Height          =   255
            Left            =   120
            TabIndex        =   40
            Top             =   360
            Width           =   375
         End
         Begin VB.Label Label6 
            Caption         =   "����"
            Height          =   255
            Left            =   2160
            TabIndex        =   39
            Top             =   240
            Width           =   375
         End
         Begin VB.Label ���� 
            Caption         =   "����"
            Height          =   255
            Left            =   2160
            TabIndex        =   38
            Top             =   600
            Width           =   375
         End
      End
      Begin VB.Frame Frame2 
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
         TabIndex        =   28
         Top             =   720
         Width           =   7815
         Begin VB.CommandButton btn�ɼ����񺰸ŵ����ű� 
            Caption         =   "�ɼ� ���� �ŵ����ű�"
            Height          =   372
            Left            =   120
            TabIndex        =   56
            Top             =   1200
            Width           =   3135
         End
         Begin VB.CommandButton btnStockJango 
            Caption         =   "�ֽ��ܰ���ȸ"
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
            TabIndex        =   47
            Top             =   240
            Width           =   1815
         End
         Begin VB.CommandButton btnStockCheguyl 
            Caption         =   "�ֽĽǽð�ü��"
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
            Left            =   3720
            TabIndex        =   46
            Top             =   240
            Width           =   1815
         End
         Begin VB.CommandButton btnCheguyl 
            Caption         =   "���ɽǽð�ü��"
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
            Left            =   120
            TabIndex        =   32
            Top             =   240
            Width           =   1815
         End
         Begin VB.CommandButton btnJango 
            Caption         =   "�����ܰ���ȸ"
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
            Left            =   2040
            TabIndex        =   31
            Top             =   240
            Width           =   1575
         End
         Begin VB.CommandButton btnEval 
            Caption         =   "����Ȳ��ȸ"
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
            Left            =   4200
            TabIndex        =   30
            Top             =   720
            Width           =   2175
         End
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
            Left            =   120
            TabIndex        =   29
            Top             =   720
            Width           =   3975
         End
      End
      Begin VB.CommandButton btnAcctList 
         Caption         =   "���ɰ�����ȸ"
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
         Left            =   4920
         TabIndex        =   7
         Top             =   240
         Width           =   1455
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
         Left            =   3960
         TabIndex        =   6
         Top             =   240
         Width           =   612
      End
      Begin VB.ComboBox cmbAcctList 
         BeginProperty Font 
            Name            =   "����ü"
            Size            =   9
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   300
         Left            =   960
         TabIndex        =   5
         Top             =   240
         Width           =   2052
      End
      Begin VB.Label Label7 
         Caption         =   "���¹�ȣ"
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
         Left            =   120
         TabIndex        =   23
         Top             =   240
         Width           =   735
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
      Height          =   1575
      Left            =   120
      TabIndex        =   16
      Top             =   120
      Width           =   8055
      Begin VB.CheckBox chkMultiConn 
         Caption         =   "��������"
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
         Left            =   4320
         TabIndex        =   27
         Top             =   1200
         Value           =   1  'Ȯ��
         Width           =   1095
      End
      Begin VB.TextBox edtLoginName 
         BeginProperty Font 
            Name            =   "����ü"
            Size            =   9
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
            Name            =   "����ü"
            Size            =   9
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   252
         Left            =   4320
         TabIndex        =   24
         Top             =   840
         Width           =   1695
      End
      Begin VB.TextBox edtID 
         BeginProperty Font 
            Name            =   "����ü"
            Size            =   9
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
            Name            =   "����ü"
            Size            =   9
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
            Name            =   "����ü"
            Size            =   9
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
            Name            =   "����ü"
            Size            =   9
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   495
         Left            =   6480
         TabIndex        =   4
         Top             =   360
         Width           =   1335
      End
      Begin VB.CommandButton btnDisconnect 
         Caption         =   "��������"
         BeginProperty Font 
            Name            =   "����ü"
            Size            =   9
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   495
         Left            =   6480
         TabIndex        =   17
         Top             =   960
         Width           =   1335
      End
      Begin VB.Label Label4 
         Caption         =   "LogIn Name"
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
         Left            =   3360
         TabIndex        =   26
         Top             =   360
         Width           =   975
      End
      Begin VB.Label Label1 
         Caption         =   "�α���ID"
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
         TabIndex        =   20
         Top             =   360
         Width           =   1212
      End
      Begin VB.Label Label2 
         Caption         =   "��й�ȣ"
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
         TabIndex        =   19
         Top             =   720
         Width           =   1212
      End
      Begin VB.Label Label3 
         Caption         =   "�������� ��ȣ"
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
      Left            =   6720
      TabIndex        =   14
      Top             =   7680
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
      Height          =   1035
      Left            =   120
      TabIndex        =   15
      Top             =   8160
      Width           =   8055
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
      Height          =   1215
      Left            =   120
      TabIndex        =   0
      Top             =   6360
      Width           =   8055
      Begin VB.PictureBox Picture2 
         Appearance      =   0  '���
         BackColor       =   &H80000005&
         ForeColor       =   &H80000008&
         Height          =   855
         Left            =   4080
         ScaleHeight     =   825
         ScaleWidth      =   0
         TabIndex        =   54
         Top             =   240
         Width           =   15
      End
      Begin VB.PictureBox Picture1 
         Appearance      =   0  '���
         BackColor       =   &H80000005&
         ForeColor       =   &H80000008&
         Height          =   855
         Left            =   2040
         ScaleHeight     =   825
         ScaleWidth      =   0
         TabIndex        =   53
         Top             =   240
         Width           =   15
      End
      Begin VB.TextBox txtFutureCodes 
         Height          =   288
         Left            =   2160
         TabIndex        =   52
         Text            =   "101G3000,101G6000"
         Top             =   240
         Width           =   1815
      End
      Begin VB.TextBox txtOptionCodes 
         Height          =   288
         Left            =   120
         TabIndex        =   51
         Text            =   "301G1215,201G1215"
         Top             =   240
         Width           =   1815
      End
      Begin VB.CheckBox btnXX1 
         Caption         =   "�ֽ�ü��(XX1)"
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
         Left            =   6360
         TabIndex        =   50
         Top             =   240
         Width           =   1572
      End
      Begin VB.CheckBox btnSC0 
         Caption         =   "�����ü�(SC0)"
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
         Left            =   120
         TabIndex        =   8
         Top             =   600
         Width           =   1572
      End
      Begin VB.CheckBox btnOC0 
         Caption         =   "�ɼǽü�(OC0)"
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
         Left            =   2160
         TabIndex        =   9
         Top             =   600
         Width           =   1572
      End
      Begin VB.CheckBox btnSH0 
         Caption         =   "����ȣ��(SH0)"
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
         Left            =   120
         TabIndex        =   10
         Top             =   840
         Width           =   1572
      End
      Begin VB.CheckBox btnOH0 
         Caption         =   "�ɼ�ȣ��(OH0)"
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
         Left            =   2160
         TabIndex        =   11
         Top             =   840
         Width           =   1572
      End
      Begin VB.CheckBox btnXF2 
         Caption         =   "����ü��(XF2)"
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
         Left            =   4560
         TabIndex        =   12
         Top             =   240
         Width           =   1572
      End
      Begin VB.CheckBox btnXF3 
         Caption         =   "�����ܰ�(XF3)"
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
         Left            =   4560
         TabIndex        =   13
         Top             =   480
         Width           =   1572
      End
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit


Private Sub DongbuAPI1_DBApiConnected(ByVal hDongbuApi As Long)
    Dim szAcctList As String
    Dim bRet As Boolean
    
    '���¸���Ʈ ���ϱ�
    szAcctList = DongbuAPI1.GetAccountList(1)  '����1, �ֽ� 2
    GetFutureAccList False, szAcctList, Len(szAcctList)
    
    m_hDongbuApi = hDongbuApi
    bRet = DongbuAPI1.Init(m_hDongbuApi)
    
    If (bRet) Then
        EnableControls (True)
        DisplayMsg ("����API ���� ����...")
    End If
    
End Sub

'DRCM���� ����Ǿ��ٴ� �޽����� �޾Ƽ� ó��
Private Sub DongbuAPI1_DBApiDisconnected()
    DisplayMsg ("����API �����")
    EnableControls (False)
End Sub

Private Sub DongbuAPI1_ReceiveData(ByVal nReqID As Long, ByVal szMsgCode As String, ByVal szMsg As String, ByVal szData As String)
    
        Select Case (nReqID)
            'Case REQ_FUT_CHE
            '   DisplayMsg ("���� ü�᳻�� >> " + szMsg)
            '   ParseTR_13615 (szData)
            'Case REQ_FUT_DEP_OPT '�ɼ����񺰸ŵ����ű�
            '    DisplayMsg ("�ɼ����񺰸ŵ����ű� ��ȸ >> " + szMsg)
            '    ParseTR_16260 (szData)
        End Select
    
         
End Sub

Private Sub Form_Unload(Cancel As Integer)
    DongbuAPI1.Logout
End Sub

Private Sub Form_Load()
    edtID.Text = "dsfuture"
    edtLoginName.Text = "ocx test"
    edtPwd.Text = "d3693320"
    edtCertPwd.Text = "dongbusec"
    cmbAcctList.Text = "02060701975"
    txtPwd.Text = "1004"
    
    EnableControls (False)
    
    Init�ֹ�
         
End Sub

'
Private Sub btnAcctList_Click()
    Dim szAcctList As String
    szAcctList = DongbuAPI1.GetAccountList(1)  '����1, �ֽ� 2
    GetFutureAccList False, szAcctList, Len(szAcctList)
End Sub

Private Sub btnStockAcctList_Click()
    Dim szAcctList As String
    szAcctList = DongbuAPI1.GetAccountList(2)  '����1, �ֽ� 2
    GetFutureAccList True, szAcctList, Len(szAcctList)
End Sub

Private Sub GetFutureAccList(ByVal bStock As Boolean, ByVal strData As String, ByVal nLen As Integer)

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
        
        If (bStock) Then
            DisplayMsg ("�ֽİ��� >> " + Str(i) + " : " + szAcctInfo)
        Else
            DisplayMsg ("���ɰ��� >> " + Str(i) + " : " + szAcctInfo)
        End If
        
        cmbAcctList.AddItem szAcctInfo
        
        If i = nCount Then
            cmbAcctList.Text = szAcctInfo
        End If
    Next i
    
    
    txtPwd.Text = ""
        
End Sub

Private Sub DongbuDRCM1_ReceiveRTData(ByVal szDrdsName As String, ByVal szDrdsField As String, ByVal szDrdsData As String)
    
    DisplayMsg ("�ǽð������� ����>>" + szDrdsName)
    Dim szData As String
    szData = szDrdsData
    
    Select Case szDrdsName
    
    Case R_SC0 '= "SC0"                        ' ���� ���簡
        'Call Parse_SC0(szData)
    Case R_SH0 '= "SH0"                        ' ���� ȣ��
        'Parse_SH0 (szData)
    Case R_OC0 '= "OC0"                        ' �ɼ� ���簡
        'Call Parse_OC0(szData)
    Case R_OH0 '= "OH0"                        ' �ɼ� ȣ��
        'Call Parse_OH0(szData)
    Case R_XF2 '= "XF2"                        ' ü��
    Case R_XF3 '= "XF3"                        ' �ܰ�
    End Select
    
End Sub

Private Sub btnClearAll_Click()
    ListBox1.Clear

End Sub

'DRCM�� ���������Ѵٰ� �޽��� ������
Private Sub btnDisconnect_Click()
    DongbuAPI1.Logout
End Sub


Private Sub btnConnect_Click()
    Dim lShowLoginDlg As Long
    Dim lMultiConn As Long
    Dim nReturn As Boolean
    DisplayMsg ("����API ���� �õ���...")
    
    If (chkShowLoginDlg.Value = vbChecked) Then
        lShowLoginDlg = 1
    Else
        lShowLoginDlg = 0
    End If
             
    If (chkMultiConn.Value = vbChecked) Then
        lMultiConn = 1
    Else
        lMultiConn = 0
    End If
    
    'DRCM �α���
    nReturn = DongbuAPI1.Login(edtID.Text, edtLoginName.Text, edtPwd.Text, edtCertPwd.Text, lShowLoginDlg, lMultiConn)
        
    If (nReturn = False) Then
        DisplayMsg ("����API �α��� ����...")
    End If
    
End Sub

Private Sub DisplayMsg(ByVal strMsg As String)
    ListBox1.AddItem strMsg, 0
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
    btnOrder.Enabled = bEnabled
    btnJango.Enabled = bEnabled
    btnCheguyl.Enabled = bEnabled
    btnEval.Enabled = bEnabled
    btnFee.Enabled = bEnabled
    btnAcctList.Enabled = bEnabled
    
    btnStockOrder.Enabled = bEnabled
    btnStockCheguyl.Enabled = bEnabled
    btnStockJango.Enabled = bEnabled
    
    btn�ɼ����񺰸ŵ����ű�.Enabled = bEnabled
    
    btnStockAcctList.Enabled = bEnabled
    btnAbleQty.Enabled = bEnabled
    
    
End Sub


Private Function Init�ֹ�()
    cmbPriceType.AddItem "00:������"
    cmbPriceType.AddItem "03:���尡"
    cmbPriceType.AddItem "05:���Ǻ�������"
    cmbPriceType.AddItem "06:������������"
    
    cmbPriceType.Text = "00:������"

End Function

Private Sub btnOrder_Click()

    SendOrder (True)
    
End Sub

Private Sub btnStockOrder_Click()

    SendOrder (False)
    
End Sub


Private Sub SendOrder(bFutureOrder As Boolean)
    Dim nRet As Long
            
    Dim szAccount As String
    Dim szPwd As String
    Dim szJongmok As String  '/* �����ڵ�
    Dim nOrderPrice As Long  '�ֹ�����
    Dim nOrdSect As Long     '/* 1:�ŵ�, 2:�ż�,  3:����, 4:���
    Dim nPriceType As Long   '/* 00:������ 03:���尡 05:���Ǻ�������  06:������������
    Dim nOrgOrderNo As Long  '/*���ֹ���ȣ
    Dim nQty As Long  '�ֹ�����
    
    
    If (opt�ż�.Value = True) Then
        nOrdSect = 2
    Else
        nOrdSect = 1
    End If
    
    szAccount = Left(cmbAcctList.Text, LEN_GEJANO)
    szPwd = txtPwd.Text
    
    szJongmok = edtJongCode.Text
        
    nPriceType = CLng(Left(cmbPriceType.Text, 2))
    nQty = CLng(edtQty.Text)
    
    
    If (bFutureOrder) Then
        nOrderPrice = CDbl(edtPrice.Text) * 100
        'nRet = DongbuDRCM1.SendFOrder(8888, szAccount, szPwd, nOrdSect, szJongmok, nPriceType, nQty, nOrderPrice, nOrgOrderNo)
    Else
        'nRet = DongbuDRCM1.SendSOrder(7777, szAccount, szPwd, nOrdSect, szJongmok, nPriceType, nQty, nOrderPrice, nOrgOrderNo)
    End If
            
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
    Dim nRet As Boolean
    Dim szData As String
    Dim dOrderPrice As Double
    
    If (Not IsEmpty(edtPrice.Text)) Then
        dOrderPrice = CDbl(edtPrice.Text)
    End If
                
    szAccount = Left(cmbAcctList.Text, LEN_GEJANO)
    szPwd = txtPwd.Text
    szJongmok = edtJongCode.Text                        '/*�����ڵ�(12)
    
    '/*�Ÿű���(1) # 1:�ŵ�, 2:�ż�
    If (opt�ż�.Value = True) Then
        sz�Ÿű��� = "2"                       '
    Else
        sz�Ÿű��� = "1"
    End If
    
    szFnoOrdprcPtnCode = Left(cmbPriceType.Text, 2)     '/*�����ɼ�ȣ�������ڵ�(2) # 00:������ 03:���尡 05:���Ǻ�������  06:������������
                    
    'nRet = DongbuDRCM1.ReqAbleQty(szAccount, szPwd, szJongmok, sz�Ÿű���, dOrderPrice, szFnoOrdprcPtnCode)

End Sub

'�ֽ�ü��
Private Sub btnStockCheguyl_Click()
    Dim szAccount As String
    Dim szNextKey As String
    Dim szGB As String
    Dim nRet As Long
    
    szAccount = Left(cmbAcctList.Text, LEN_GEJANO)
    
    If IsEmpty(szAccount) Then
        Exit Sub
    End If
    
    szGB = "1" '1:�ֹ�/ü�� 2:��ü��
    'nRet = DongbuDRCM1.ReqStockChegyul(szAccount, szGB, szNextKey)


End Sub

'�ֽ��ܰ�
Private Sub btnStockJango_Click()
    Dim szAccount As String
    Dim szNextKey As String
    Dim nRet As Long
    
    szAccount = Left(cmbAcctList.Text, LEN_GEJANO)
    
    If IsEmpty(szAccount) Then
        Exit Sub
    End If
    
    'nRet = DongbuDRCM1.ReqStockJango(szAccount, szNextKey)

End Sub


'�ܰ���ȸ
Private Sub btnJango_Click()
    Dim szAccount As String
    Dim szData As String
    Dim nRet As Long
    
    szAccount = Left(cmbAcctList.Text, LEN_GEJANO)
    
    If IsEmpty(szAccount) Then
        Exit Sub
    End If
    
    'nRet = DongbuDRCM1.ReqJango(szAccount)
End Sub
'ü�᳻��
Private Sub btnCheguyl_Click()
    frmü�Ḯ��Ʈ.Show
            
End Sub

'����Ȳ ��ȸ
Private Sub btnEval_Click()

    Dim szAccount As String
    Dim szPwd As String
    Dim szDate As String
    Dim nRet As Long
            
    szAccount = Left(cmbAcctList.Text, LEN_GEJANO)
    szPwd = txtPwd.Text
    szDate = Format(Now, "YYYYMMDD")
    
    'nRet = DongbuDRCM1.ReqEval(szAccount, szPwd, szDate)
    
End Sub
'������/�ֹ����� �ݾ�
Private Sub btnFee_Click()

    Dim szAccount As String
    Dim szPwd As String
    Dim szDate As String
    Dim nRet As Long
            
    szAccount = Left(cmbAcctList.Text, LEN_GEJANO)
    szPwd = txtPwd.Text
    szDate = Format(Now, "YYYYMMDD")
    
    'nRet = DongbuDRCM1.ReqFeeNAbleMoney(szAccount, szPwd, szDate)
    
End Sub

'�ɼ����񺰸ŵ����ű� 1600
Private Sub btn�ɼ����񺰸ŵ����ű�_Click()
    frm�ɼ����񺰸ŵ����ű�.Show
End Sub


Private Sub btnXX1_Click()
    Dim szId As String
    Dim nRet As Long

    szId = Trim(edtID.Text)

    If (btnXX1.Value = vbChecked) Then
        'nRet = DongbuDRCM1.ReqRealtimeData(DRCM_ADVICE, R_XX1, szId)
    Else
        'nRet = DongbuDRCM1.ReqRealtimeData(DRCM_UNADVICE, R_XX1, szId)
    End If
End Sub

Private Sub btnXF2_Click()
    Dim szId As String
    Dim nRet As Long

    szId = Trim(edtID.Text)

    If (btnXF2.Value = vbChecked) Then
        'nRet = DongbuDRCM1.ReqRealtimeData(DRCM_ADVICE, R_XF2, szId)
    Else
        'nRet = DongbuDRCM1.ReqRealtimeData(DRCM_UNADVICE, R_XF2, szId)
    End If

End Sub

Private Sub btnXF3_Click()
    Dim szId As String
    Dim nRet As Long

    szId = Trim(edtID.Text)

    If (btnXF3.Value = vbChecked) Then
        'nRet = DongbuDRCM1.ReqRealtimeData(DRCM_ADVICE, R_XF3, szId)
    Else
        'nRet = DongbuDRCM1.ReqRealtimeData(DRCM_UNADVICE, R_XF3, szId)
    End If

End Sub

Private Sub btnOC0_Click()

    Dim szData As String
    Dim nRet As Long

    szData = txtOptionCodes.Text

    If (btnOC0.Value = vbChecked) Then
        'nRet = DongbuDRCM1.ReqRealtimeData(DRCM_ADVICE, R_OC0, szData)
    Else
        'nRet = DongbuDRCM1.ReqRealtimeData(DRCM_UNADVICE, R_OC0, szData)
    End If

End Sub

Private Sub btnOH0_Click()
    Dim szData As String
    Dim nRet As Long

    szData = txtOptionCodes.Text

    If (btnOH0.Value = vbChecked) Then
        'nRet = DongbuDRCM1.ReqRealtimeData(DRCM_ADVICE, R_OH0, szData)
    Else
        'nRet = DongbuDRCM1.ReqRealtimeData(DRCM_UNADVICE, R_OH0, szData)
    End If

End Sub

Private Sub btnSC0_Click()

    Dim szData As String
    Dim nRet As Long

    szData = txtFutureCodes.Text

    If (btnSC0.Value = vbChecked) Then
        'nRet = DongbuDRCM1.ReqRealtimeData(DRCM_ADVICE, R_SC0, szData)
    Else
        'nRet = DongbuDRCM1.ReqRealtimeData(DRCM_UNADVICE, R_SC0, szData)
    End If
    

End Sub

Private Sub btnSH0_Click()
    Dim szData As String
    Dim nRet As Long

    szData = txtFutureCodes.Text

    If (btnSH0.Value = vbChecked) Then
        'nRet = DongbuDRCM1.ReqRealtimeData(DRCM_ADVICE, R_SH0, szData)
    Else
        'nRet = DongbuDRCM1.ReqRealtimeData(DRCM_UNADVICE, R_SH0, szData)
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


Private Sub Parse_SC0(ByVal strData As String)
    Dim clsRTData As clsDrdsSC0
    
    clsRTData.Init (strData)
End Sub

Private Sub Parse_SH0(ByVal strData As String)
    Dim clsRTData As clsDrdsSH0
    clsRTData.Init (strData)
End Sub

Private Sub Parse_OC0(ByVal strData As String)
    clsRTData.Init (strData)
End Sub

Private Sub Parse_OH0(ByVal strData As String)
    Dim clsRTData As clsDrdsOH0
    clsRTData.Init (strData)
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


Private Sub ParseTR_13655(strData As String) '���� �ܰ���ȸ

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

Private Sub ParseTR_13148(strData As String) '�ֽ� �ܰ���ȸ

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
    Dim �����ڵ�
    Dim �����
    Dim �������
    Dim �򰡼���
    Dim ������
    Dim �ܰ�ݾ�
    Dim �򰡱ݾ�
    Dim ���Ϻ���
    Dim ���Ϻ���
    Dim �����ܰ�
    Dim ��δܰ�
    Dim �����
    Dim �ִ���
    Dim ������
    Dim ����
    Dim ���簡
    Dim ���ϴ��
    Dim ����������
    Dim �����ȣ
    Dim ��������
    Dim ���ϸŵ��ݾ�
    Dim �ܰ���
    Dim ������
    Dim ������
    Dim �ſ�ݾ�
    Dim ��������
    Dim �������ű���
    Dim ���򰡱ݾױݾ�
    
    Dim ���ڵ尹�� As Long
    
 
    Dim i As Long, nPos As Long
    
    nPos = 1
    
    sm_bjlen = MidEx(strData, nPos, 6)
    sm_bjdata = MidEx(strData, nPos, 5)
    
    �Ѹ��Աݾ� = MidEx(strData, nPos, 15)
    ���򰡼��� = MidEx(strData, nPos, 15)
    ���ϸŵ��ݾ� = MidEx(strData, nPos, 15)
    ���򰡱ݾױݾ� = MidEx(strData, nPos, 15)
    �Ѽ����� = MidEx(strData, nPos, 15)
    ���Ͻ������� = MidEx(strData, nPos, 15)
    Next���� = MidEx(strData, nPos, 1)
    NextKey = MidEx(strData, nPos, 50)
    
    
    gr_bjlen = MidEx(strData, nPos, 6)
    gr_bjdata = MidEx(strData, nPos, 5)
    
    
    ���ڵ尹�� = CLng(gr_bjlen)
    
    For i = 1 To ���ڵ尹��
        strData = Mid(strData, nPos):       nPos = 1
        
        �����ڵ� = MidEx(strData, nPos, 6)
        ����� = MidEx�ѱ�(strData, nPos, 20)
        ������� = MidEx(strData, nPos, 15)
        �򰡼��� = MidEx(strData, nPos, 15)
        ������ = MidEx(strData, nPos, 7)
        
        �ܰ�ݾ� = MidEx(strData, nPos, 15)
        �򰡱ݾ� = MidEx(strData, nPos, 15)
        ���Ϻ��� = MidEx(strData, nPos, 15)
        ���Ϻ��� = MidEx(strData, nPos, 15)
        �����ܰ� = MidEx(strData, nPos, 15)
        
        ��δܰ� = MidEx(strData, nPos, 9)
        ����� = MidEx(strData, nPos, 9)
        �ִ��� = MidEx(strData, nPos, 9)
        ������ = MidEx(strData, nPos, 9)
        ���� = MidEx(strData, nPos, 9)
        
        ���簡 = MidEx(strData, nPos, 7)
        ���ϴ�� = MidEx(strData, nPos, 7)
        ���������� = MidEx(strData, nPos, 8)
        �����ȣ = MidEx(strData, nPos, 1)
        �������� = MidEx(strData, nPos, 15)
        ���ϸŵ��ݾ� = MidEx(strData, nPos, 15)
        
        �ܰ��� = MidEx(strData, nPos, 1)
        ������ = MidEx(strData, nPos, 8)
        ������ = MidEx(strData, nPos, 8)
        �ſ�ݾ� = MidEx(strData, nPos, 15)
        �������� = MidEx(strData, nPos, 9)
        �������ű��� = MidEx(strData, nPos, 3)
        
    Next i
    
End Sub



Private Sub ParseTR_13118(strData As String) '�ֽ�ü�Ḯ��Ʈ

On Error Resume Next
    'TR_1311

    Dim ���ڵ�Count As Long
    Dim ���ڵ�Len As String
    Dim �׸���Msg As String

    Dim �ֹ���ȣ As Long
    Dim �����ڵ� As String
    Dim ����� As String
    Dim �Ÿű��мӼ� As String
    Dim �Ÿű��� As String
    
    Dim �ֹ����� As String
    Dim �ֹ��ܰ� As String
    Dim ü����� As String
    Dim ü�ᰡ�� As String
    
    Dim ��ü����� As String
    Dim �ֹ����� As String
    Dim ���ֹ���ȣ As String
    Dim ó������ As String
    Dim ü��� As String
    
    Dim �ֹ��ð� As String
    Dim ����� As String
    Dim ������ As String
    Dim ���� As String
    Dim �ſ뱸�� As String
           
    Dim nGridData As String
    Dim nPos As Long, i As Long
    
    nPos = 1
    
    Dim geja
    Dim ngbn
    Dim NextKey
    Dim gr_bjlen
    Dim gr_bjdata
    
    geja = MidEx(strData, nPos, 20)
    ngbn = MidEx(strData, nPos, 1)
    NextKey = MidEx(strData, nPos, 50)
    ���ڵ�Count = MidEx(strData, nPos, 4)
    gr_bjlen = MidEx(strData, nPos, 2)
    gr_bjdata = MidEx(strData, nPos, 4)
    
    
    For i = 1 To ���ڵ�Count
    
        strData = Mid(strData, nPos):       nPos = 1
        
        �ֹ���ȣ = MidEx(strData, nPos, 9)
        �����ڵ� = MidEx(strData, nPos, 12)
        ����� = MidEx�ѱ�(strData, nPos, 20)
        �Ÿű��мӼ� = MidEx(strData, nPos, 3)
        �Ÿű��� = MidEx�ѱ�(strData, nPos, 16)
        �ֹ����� = MidEx(strData, nPos, 15)
        �ֹ��ܰ� = MidEx(strData, nPos, 12)
        ü����� = MidEx(strData, nPos, 15)
        ü�ᰡ�� = MidEx(strData, nPos, 12)
        ��ü����� = MidEx(strData, nPos, 15)
        �ֹ����� = MidEx�ѱ�(strData, nPos, 10)
        ���ֹ���ȣ = Trim(MidEx�ѱ�(strData, nPos, 9))
        ó������ = Trim(MidEx�ѱ�(strData, nPos, 10))
        ü��� = Trim(MidEx�ѱ�(strData, nPos, 9))
        �ֹ��ð� = Trim(MidEx�ѱ�(strData, nPos, 6))
        ����� = Trim(MidEx�ѱ�(strData, nPos, 9))
        ������ = Trim(MidEx�ѱ�(strData, nPos, 9))
        ���� = Trim(MidEx�ѱ�(strData, nPos, 9))
        �ſ뱸�� = Trim(MidEx�ѱ�(strData, nPos, 3))
        
    Next i
    
End Sub

VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "동부API Client Sample(VB6)"
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
   StartUpPosition =   3  'Windows 기본값
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
         Caption         =   "주문"
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
            Caption         =   "매도"
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
            Caption         =   "매수"
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
            Caption         =   "신규/청산 가능수량"
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
            Caption         =   "종목"
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
            Caption         =   "수량"
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
         Begin VB.Label 가격 
            Caption         =   "가격"
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
         Caption         =   "조회"
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
            Caption         =   "선옵실시간체결"
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
            Caption         =   "평가현황조회"
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
            Caption         =   "평가예탁총액/수수료 /주문가능금액"
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
         Begin VB.CommandButton btn옵션종목별매도증거금 
            Caption         =   "옵션종목별매도증거금"
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
            Caption         =   "선옵잔고조회"
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
         Caption         =   "선옵계좌조회"
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
         Caption         =   "계좌번호"
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
         Caption         =   "계좌비번"
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
      Caption         =   "DRCM 접속 "
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
         Caption         =   "다중접속"
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
         Caption         =   "로그인창 보이기"
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
         IMEMode         =   3  '사용 못함
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
         IMEMode         =   3  '사용 못함
         Left            =   1560
         PasswordChar    =   "*"
         TabIndex        =   3
         Text            =   "Text3"
         Top             =   1080
         Width           =   1452
      End
      Begin VB.CommandButton btnConnect 
         Caption         =   "접속"
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
         Caption         =   "접속해제"
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
         Caption         =   "로그인ID"
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
         Caption         =   "비밀번호"
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
         Caption         =   "공인인증 암호"
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
      Caption         =   "내역 지우기"
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
      Caption         =   "실시간 데이터 요청 등록 및 해제 "
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
         Caption         =   "선물시세(SC0)"
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
         Caption         =   "옵션시세(OC0)"
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
         Caption         =   "선물호가(SH0)"
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
         Caption         =   "옵션호가(OH0)"
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
         Caption         =   "선옵체결(XF2)"
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
         Caption         =   "선옵잔고(XF3)"
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
         Caption         =   "옵션종목"
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
         Caption         =   "선물종목"
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
    DisplayMsg ("동부 DRCM 접속 시도중...")

    m_hDongbuDRCM = FindDRCM
    

    If m_hDongbuDRCM = 0 Then
        MsgBox ("동부 DRCM을 찾을 수 없습니다")
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
        DisplayMsg ("동부 DRCM이 설치되어 있지 않습니다!")
        Exit Function
    End If
    
    strRoot = GetRegApi(HKEY_CURRENT_USER, "Root", strRegKey)
    strWinName = GetRegApi(HKEY_CURRENT_USER, "WinName", strRegKey)
    szTmpWinName = strWinName + "[" + Trim(edtLoginName.Text) + "]"
        
    
    '현재 실행중인 drcm을 찾는다
    hDrcmHwnd = FindWindow(vbNullString, szTmpWinName)

    'drcm을 실행시킨다
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
            szMsg = "이미 같은 ID 가 동부 DRCM에 로그되어 있습니다."
            MsgBox (szMsg)
            
            Form_Unload (1)
        End If
    

    End If

    FindDRCM = hDrcmHwnd

End Function


'DRCM에 접속해제한다고 메시지 보내기
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
                    
        '접속시도
        nDataLen = Len(stUserInfo)
        cs.dwData = DRCM_CONNECT
        cs.cbData = nDataLen
        cs.lpData = VarPtr(stUserInfo)

        nRet = SendMessage(m_hDongbuDRCM, WM_COPYDATA, Form1.hWnd, cs)
         
        Select Case (nRet)
            Case DRCM_MSG_LOGINFAIL
                MsgBox ("로그인 실패")

            Case DRCM_MSG_SOCKETFAIL
                MsgBox ("서버 접속 실패")

            Case Else
                m_hSocket = nRet
        End Select

        If m_hSocket <> 0 Then
            GetClientIp
            EnableControls (True)

            DisplayMsg ("로그인 성공")
        Else
            DisplayMsg ("로그인 실패")
        End If

    End Function
    
Private Sub DisplayMsg(ByVal strMsg As String)
    ListBox1.AddItem strMsg, 0
End Sub

'DRCM에서 종료되었다는 메시지를 받아서 처리
Public Sub DisconnectedDRCM()

    DisplayMsg ("동부 DRCM이 종료되었습니다")
   
    m_hSocket = 0
    m_hDongbuDRCM = 0

    EnableControls (False)

End Sub

    '화면 버튼들 처리
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
    
    btn옵션종목별매도증거금.Enabled = bEnabled
    
    
End Sub

'DRCM에 TR 보내기 - 자기 자신의 Ip 구하기 위해
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

'DRCM에 TR 보내기
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

    'DRCM에 TR 보내기
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
        MsgBox ("DRCM SERVER에 요청 실패!")
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
        szAccName = MidEx한글(strData, nPos, 20)
        
        szAcctInfo = szAccNo + " " + Trim(szAccName)
        DisplayMsg ("선옵계좌 >> " + Str(i) + " : " + szAcctInfo)
        
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
    szClikey = StrPadRight("", 8, "8")                '/* 주문 key(임의로
    'szGubun              '(1)                          '/* 1:매도, 2:매수,  3:정정, 4:취소
    szAccount = Left(cmbAcctList.Text, LEN_GEJANO)
    szAccount = StrPadRight(szAccount, 20, " ")     '/* 계좌번호
    szPwd = StrPadRight(txtPwd.Text, 8, " ")        '/* 비밀번호
    
    szFnoIsuNo = StrPadRight(edtJongCode.Text, 15, " ")  '/* 종목코드(15)
    szOrgOrderNo = StrPadRight(szOrgOrderNo, 9, "0") '/*원주문번호(9)
    szFnoOrdprcPtnCode = "00"                        '/* 00:지정가 03:시장가 05:조건부지정가  06:최유리지정가
        
    szOrdPrc = Format(nOrderPrice, "+00000000000") ' '/* 주문가(12)
    szOrdQty = StrPadLeft(edtQty.Text, 15, "0")      '/* 주문수량(15)

    szData = szCnt + szMapno + szClikey + szGubun + szAccount + szPwd + szFnoIsuNo + szOrgOrderNo + szFnoOrdprcPtnCode + szOrdPrc + szOrdQty + m_szIP
    
    MakeJumun = szData
    
End Function

'잔고조회
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
'체결내역
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

'평가현황 조회
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

'옵션종목별매도증거금 1600
Private Sub btn옵션종목별매도증거금_Click()
    
    Dim szIp As String
    Dim nRet As Long
    Dim szData As String
    
    Dim sz상품군코드 As String    'x(2)
    Dim sz기초자산코드 As String  'x(3) 전체 000
    Dim sz최근월물구분 As String  'x(1)
    Dim szNextKey As String       'x(19)
    
           
    sz상품군코드 = "00"
    sz기초자산코드 = "000"
    sz최근월물구분 = "0"
    
    szIp = StrPadRight(m_szIP, 16, "0")
    szNextKey = StrPadRight("", 19, "0")
    
    szData = sz상품군코드 + sz기초자산코드 + sz최근월물구분 + szIp + szNextKey
    nRet = SendToServerEx(DRCM_SENDDATA, TR_16260, szData)
    
End Sub

'신규/청산 가능수량
Private Sub btnAbleQty_Click()

    Dim szAccount As String
    Dim szPwd As String
    Dim szJongmok As String
    Dim sz매매구분 As String
    Dim szFnoOrdprcPtnCode As String
    Dim sz청산수량조회구분 As String
    Dim sz주문가 As String
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
    szJongmok = StrPadRight(edtJongCode.Text, 12, " ")  '/*종목코드(12)
    sz매매구분 = "2"                       '            '/*매매구분(1) # 1:매도, 2:매수
    sz주문가 = Format(nOrderPrice, "000000000000") '    '/*주문가(12) # S9(10)99
    szFnoOrdprcPtnCode = "00"                           '/*선물옵션호가유형코드(2) # 00:지정가 03:시장가 05:조건부지정가  06:최유리지정가
    sz청산수량조회구분 = "0"                            '/*청산수량조회구분 # 0:청산할수있는수량,1:증거금증가되는주문에대해서고려해조회(동부)
        
    szIp = StrPadRight(m_szIP, 16, "0")
    
    
    szData = szAccount + szPwd + szJongmok + sz매매구분 + sz주문가 + szFnoOrdprcPtnCode + sz청산수량조회구분 + szIp
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
    
    DisplayMsg ("실시간데이터 수신>>" + strName)
    
    Select Case strName
    
    Case R_SC0 '= "SC0"
        Call Parse_SC0(strData)                ' 선물 현재가
    Case R_SH0 '= "SH0"                        ' 선물 호가
        Parse_SH0 (strData)
    Case R_OC0 '= "OC0"                        ' 옵션 현재가
        Call Parse_OC0(strData)
    Case R_OH0 '= "OH0"                        ' 옵션 호가
        Call Parse_OH0(strData)
    Case R_XF2 '= "XF2"                        ' 체결
    Case R_XF3 '= "XF3"                        ' 잔고
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


Private Sub ParseTR_20000(strData As String) '주문응답

On Error Resume Next
    Dim 주문Cnt As Long
    Dim nPos As Long
    Dim i As Long
    
    Dim str로컬번호 As String
    Dim sr주문번호 As String
    Dim str메시지코드 As String
    Dim str메시지 As String
    
    On Error GoTo OnError
    
    nPos = 1
    주문Cnt = CLng(MidEx(strData, nPos, 4))
    
    For i = 1 To 주문Cnt
        str로컬번호 = MidEx(strData, nPos, 8)
        sr주문번호 = MidEx(strData, nPos, 9)
        str메시지코드 = MidEx(strData, nPos, 6)
        
        strData = Mid(strData, nPos)
        nPos = 1
        str메시지 = MidEx한글(strData, nPos, 100)
        
        If Mid(str메시지코드, 2) < 1000 Then
            DisplayMsg ("주문확인>> 주문번호 :" + sr주문번호)
        Else
            DisplayMsg ("주문거부>>" + str메시지)
        End If
    Next i
    
    Exit Sub
OnError:
    MsgBox ("주문응답 처리시에러" & Err.Description & strData)
End Sub

Private Sub ParseTR_15813(strData As String) '예탁금

On Error Resume Next
    ' TR_15813
    
    Dim 한글아이템
    Dim 예탁금총액
    Dim 예탁현금
    Dim 예탁대용
    Dim 위탁증거금총액
    Dim 현금위탁증거금액
    Dim 유지증거금총액
    Dim 현금유지증거금액
    Dim 추가증거금총액
    Dim 현금추가증거금액
    Dim 주문가능총금액
    Dim 현금주문가능금액
    Dim 인출가능총금액
    Dim 인출가능현금액
    Dim 연속키

    Dim nPos As Long
    
    nPos = 1
    예탁금총액 = MidEx(strData, nPos, 15)
    예탁현금 = MidEx(strData, nPos, 15)
    예탁대용 = MidEx(strData, nPos, 15)
    
    위탁증거금총액 = MidEx(strData, nPos, 15)
    현금위탁증거금액 = MidEx(strData, nPos, 15)
    유지증거금총액 = MidEx(strData, nPos, 14)
    현금유지증거금액 = MidEx(strData, nPos, 15)
    
    추가증거금총액 = MidEx(strData, nPos, 14)
    현금추가증거금액 = MidEx(strData, nPos, 15)
    주문가능총금액 = MidEx(strData, nPos, 14)
    현금주문가능금액 = MidEx(strData, nPos, 15)
    
    인출가능총금액 = MidEx(strData, nPos, 14)
    인출가능현금액 = MidEx(strData, nPos, 15)
    연속키 = MidEx(strData, nPos, 15)
    
End Sub

Private Sub ParseTR_13653(strData As String) '수수료
    ' TR_13653
    
    Dim 평가예탁총액
    Dim 주문가능금액
    Dim 수수료

    Dim nPos As Long
    
    nPos = 1
    평가예탁총액 = MidEx(strData, nPos, 15)
    주문가능금액 = MidEx(strData, nPos, 16)
    수수료 = MidEx(strData, nPos, 16)
    
End Sub

Private Sub ParseTR_14051(strData As String) '신규/청산 수량 조회
    ' TR_14051
    
    Dim 신규주문가능수량
    Dim 청산주문가능수량
    
    Dim nPos As Long
    
    nPos = 1
    신규주문가능수량 = MidEx(strData, nPos, 15)
    청산주문가능수량 = MidEx(strData, nPos, 15)
End Sub


Private Sub ParseTR_13655(strData As String) '잔고조회

On Error Resume Next
    'TR_13655
    Dim 총약정금액
    Dim 총평가손익
    Dim 주문가능총액
    Dim 총평가금액
    Dim 당일실현손익
    Dim 주문가능현금
    Dim 총수익율
    Dim 레코드갯수 As Long
    
    Dim 종목코드
    Dim 매매속성
    Dim 매매구분
    Dim 청산가능
    Dim 전일잔고
    Dim 증감
    Dim 보유수량
    Dim 미체결주문수량
    Dim 매입단가
    Dim 현재가
    Dim 평가손익
    Dim 수익율
    Dim 약정금액
    Dim 평가금액
    Dim 수수료
    Dim 매수호가
    Dim 매도호가
    Dim 상한가
    Dim 하한가
    Dim 시장소속구분
    Dim 당일실현손익D
    Dim 주문유형
    Dim 거래단위
    Dim 당일매수또는매도금액
    Dim 매매대금합
 
    Dim i As Long, nPos As Long
    
    nPos = 1
    총약정금액 = MidEx(strData, nPos, 17)
    총평가손익 = MidEx(strData, nPos, 17)
    주문가능총액 = MidEx(strData, nPos, 17)
    
    총평가금액 = MidEx(strData, nPos, 17)
    당일실현손익 = MidEx(strData, nPos, 17)
    주문가능현금 = MidEx(strData, nPos, 17)
    총수익율 = MidEx(strData, nPos, 9)
    
        
    레코드갯수 = MidEx(strData, nPos, 4)
    
    For i = 1 To 레코드갯수
        strData = Mid(strData, nPos):       nPos = 1
        
        종목코드 = MidEx(strData, nPos, 15)
        
        매매속성 = MidEx(strData, nPos, 2)
        매매구분 = MidEx한글(strData, nPos, 5)
        
        청산가능 = MidEx(strData, nPos, 15)
        전일잔고 = MidEx(strData, nPos, 15)
        증감 = MidEx(strData, nPos, 15)
        보유수량 = MidEx(strData, nPos, 15)
        미체결주문수량 = MidEx(strData, nPos, 15)
        매입단가 = MidEx(strData, nPos, 12)
        현재가 = MidEx(strData, nPos, 6)
        평가손익 = MidEx(strData, nPos, 15)
        수익율 = MidEx(strData, nPos, 9)
        약정금액 = MidEx(strData, nPos, 15)
        평가금액 = MidEx(strData, nPos, 15)
        수수료 = MidEx(strData, nPos, 12)
        매수호가 = MidEx(strData, nPos, 6)
        매도호가 = MidEx(strData, nPos, 6)
        상한가 = MidEx(strData, nPos, 6)
        하한가 = MidEx(strData, nPos, 6)
        시장소속구분 = MidEx(strData, nPos, 1)
        당일실현손익D = MidEx(strData, nPos, 15)
        주문유형 = MidEx(strData, nPos, 3)
        거래단위 = MidEx(strData, nPos, 15)
        당일매수또는매도금액 = MidEx(strData, nPos, 15)
        매매대금합 = MidEx(strData, nPos, 15)
                    
    Next i
    
End Sub

Private Sub ParseTR_13615(strData As String) '체결리스트

On Error Resume Next
    'TR_13615

    Dim 레코드Count As Long
    Dim 레코드Len As String
    Dim 그리드Msg As String

    Dim 주문번호 As Long
    Dim 로컬필드 As String
    Dim 종목코드 As String
    Dim 주문구분속성 As String
    Dim 주문구분 As String
    
    Dim 주문유형 As String
    Dim 주문단가 As String
    Dim 주문수량 As String
    Dim 체결가격 As String
    Dim 체결수량 As String
    Dim 미체결수량 As String
    Dim 원주문번호 As String
    Dim 매매구분 As String
    Dim 거부메세지 As String
           
    Dim nGridData As String
    Dim nPos As Long, i As Long
    
    nPos = 1
    
    로컬필드 = MidEx(strData, nPos, 100)
    레코드Count = MidEx(strData, nPos, 4)
    레코드Len = MidEx(strData, nPos, 4)
    그리드Msg = MidEx(strData, nPos, 5)
    
    For i = 1 To 레코드Count
    
        strData = Mid(strData, nPos):       nPos = 1
                        
        주문번호 = MidEx(strData, nPos, 9)
        원주문번호 = MidEx(strData, nPos, 9)
        종목코드 = MidEx(strData, nPos, 15)
        주문구분속성 = MidEx(strData, nPos, 3)
        주문구분 = Trim(MidEx한글(strData, nPos, 12))
                
        주문유형 = MidEx한글(strData, nPos, 12)
        주문단가 = MidEx(strData, nPos, 12)
        주문수량 = MidEx(strData, nPos, 15)
        체결가격 = MidEx(strData, nPos, 12)
        체결수량 = MidEx(strData, nPos, 15)
        미체결수량 = MidEx(strData, nPos, 15)
        거부메세지 = MidEx한글(strData, nPos, 40)
    Next i
    
End Sub


Private Sub ParseTR_16260(strData As String) '옵션종목별매도증거금

On Error Resume Next
    'TR_16260
    
    Dim 연속여부키 As String        'x(1)
    Dim 연속키 As String        'x(18)
    Dim 조회건수 As String      'x(5)
    
    Dim 행사가 As String                    'x(13)
    Dim C선물옵션개별종목번호 As String     'x(32)
    Dim C구분명 As String                   'x(40) 한글
    Dim C이론가 As String                   'x(19)
    Dim C기준가 As String                   'x(13)
    Dim C주문증거금액 As String             'x(16)
    
    Dim P선물옵션개별종목번호 As String     'x(32)
    Dim P구분명 As String                   'x(40) 한글
    Dim P이론가 As String                   'x(19)
    Dim P기준가 As String                   'x(13)
    Dim P주문증거금액 As String             'x(16)
    
    
    Dim 로컬필드 As String
    Dim 레코드Count As String
    Dim 레코드Len As String
    Dim 그리드Msg As String
    
    
    Dim nPos As Long, i As Long
    
    nPos = 1
    nPos = InStr(strData, "EN=")
    If (nPos < 1) Then
        Exit Sub
    End If
    
    연속여부키 = MidEx(strData, nPos + 3, 1)
    nPos = InStr(strData, "DT=")
    nPos = nPos + 3
    연속키 = MidEx(strData, nPos, 18)
    조회건수 = MidEx(strData, nPos, 4)
        
    nPos = 41
    For i = 1 To 조회건수
        strData = Mid(strData, nPos): nPos = 1
        
        행사가 = MidEx(strData, nPos, 13)
        행사가 = Replace(행사가, "+", "")
                
        C선물옵션개별종목번호 = MidEx(strData, nPos, 32)
        C구분명 = MidEx한글(strData, nPos, 40)
        C이론가 = MidEx(strData, nPos, 19)
        C기준가 = MidEx(strData, nPos, 13)
        C주문증거금액 = MidEx(strData, nPos, 16)
        
        P선물옵션개별종목번호 = MidEx(strData, nPos, 32)
        P구분명 = MidEx한글(strData, nPos, 40)
        P이론가 = MidEx(strData, nPos, 19)
        C기준가 = MidEx(strData, nPos, 13)
        C주문증거금액 = MidEx(strData, nPos, 16)
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
    
 
    'unicode로 변환
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


'TR 데이타 처리
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
    strMessage = MidEx한글(strData, nPos, 82)
    strCursorPos = MidEx(strData, nPos, 2)
    strMsg2Len = MidEx(strData, nPos, 3)
    strAPDataLen = MidEx(strData, nPos, 3)
    strTRData = Mid(strData, nPos)
                
    If strTrCode = TR_20000 Then '주문
        DisplayMsg ("주문 >> " + strMessage)
        ParseTR_20000 (strTRData)

    ElseIf strTrCode = TR_13655 Then '잔고조회
        DisplayMsg ("잔고조회 >> " + strMessage)
        ParseTR_13655 (strTRData)
        
    ElseIf strTrCode = TR_13615 Then '체결내역 조회
        DisplayMsg ("체결내역 >> " + strMessage)
        ParseTR_13615 (strTRData)

    ElseIf strTrCode = TR_15813 Then '평가현황 조회, 예탁금, 주문가능금액
        DisplayMsg ("평가현황 >> " + strMessage)
        ParseTR_15813 (strTRData)

    ElseIf strTrCode = TR_13653 Then '수수료, 주문가능총액
        DisplayMsg ("수수료 조회 완료 ")
        ParseTR_13653 (strTRData)
        
    ElseIf strTrCode = TR_16260 Then '옵션종목별매도증거금
        DisplayMsg ("옵션종목별매도증거금 조회 >> " + strMessage)
        ParseTR_16260 (strTRData)
        
    ElseIf strTrCode = TR_14051 Then '신규/청산가능수량 조회
        DisplayMsg ("신규/청산가능수량 조회 >> " + strMessage)
        ParseTR_14051 (strTRData)
                
    End If

End Sub




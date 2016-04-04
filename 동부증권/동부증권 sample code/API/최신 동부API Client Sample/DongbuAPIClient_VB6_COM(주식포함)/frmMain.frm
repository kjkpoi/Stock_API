VERSION 5.00
Object = "{018DA320-99C5-4BEE-B201-A049156D00C8}#1.0#0"; "DONGBU~1.OCX"
Begin VB.Form frmMain 
   Caption         =   "동부API Client Sample(VB6.0)"
   ClientHeight    =   9075
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   8355
   BeginProperty Font 
      Name            =   "굴림체"
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
   StartUpPosition =   3  'Windows 기본값
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
         Caption         =   "주식계좌조회"
         BeginProperty Font 
            Name            =   "굴림체"
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
         TabIndex        =   33
         Top             =   3000
         Width           =   7815
         Begin VB.CommandButton btnStockOrder 
            Caption         =   "주식 주문"
            Height          =   375
            Left            =   4320
            TabIndex        =   48
            Top             =   720
            Width           =   1095
         End
         Begin VB.CommandButton btnOrder 
            Caption         =   "선옵 주문"
            Height          =   375
            Left            =   4320
            TabIndex        =   44
            Top             =   240
            Width           =   1095
         End
         Begin VB.OptionButton opt매수 
            Caption         =   "매수"
            Height          =   255
            Left            =   3480
            TabIndex        =   43
            Top             =   600
            Value           =   -1  'True
            Width           =   855
         End
         Begin VB.OptionButton opt매도 
            Caption         =   "매도"
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
            Caption         =   "신규/청산 가능수량"
            Height          =   375
            Left            =   5520
            TabIndex        =   34
            Top             =   240
            Width           =   2175
         End
         Begin VB.Label Label5 
            Caption         =   "종목"
            Height          =   255
            Left            =   120
            TabIndex        =   40
            Top             =   360
            Width           =   375
         End
         Begin VB.Label Label6 
            Caption         =   "수량"
            Height          =   255
            Left            =   2160
            TabIndex        =   39
            Top             =   240
            Width           =   375
         End
         Begin VB.Label 가격 
            Caption         =   "가격"
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
         Begin VB.CommandButton btn옵션종목별매도증거금 
            Caption         =   "옵션 종목별 매도증거금"
            Height          =   372
            Left            =   120
            TabIndex        =   56
            Top             =   1200
            Width           =   3135
         End
         Begin VB.CommandButton btnStockJango 
            Caption         =   "주식잔고조회"
            BeginProperty Font 
               Name            =   "굴림체"
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
            Caption         =   "주식실시간체결"
            BeginProperty Font 
               Name            =   "굴림체"
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
            Caption         =   "선옵실시간체결"
            BeginProperty Font 
               Name            =   "굴림체"
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
            Caption         =   "선옵잔고조회"
            BeginProperty Font 
               Name            =   "굴림체"
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
            Caption         =   "평가현황조회"
            BeginProperty Font 
               Name            =   "굴림체"
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
            Caption         =   "평가예탁총액/수수료 /주문가능금액"
            BeginProperty Font 
               Name            =   "굴림체"
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
         Caption         =   "선옵계좌조회"
         BeginProperty Font 
            Name            =   "굴림체"
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
            Name            =   "굴림체"
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
            Name            =   "굴림체"
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
         Caption         =   "계좌번호"
         BeginProperty Font 
            Name            =   "굴림체"
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
         Caption         =   "계좌비번"
         BeginProperty Font 
            Name            =   "굴림체"
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
      Height          =   1575
      Left            =   120
      TabIndex        =   16
      Top             =   120
      Width           =   8055
      Begin VB.CheckBox chkMultiConn 
         Caption         =   "다중접속"
         BeginProperty Font 
            Name            =   "굴림체"
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
         Value           =   1  '확인
         Width           =   1095
      End
      Begin VB.TextBox edtLoginName 
         BeginProperty Font 
            Name            =   "굴림체"
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
         Caption         =   "로그인창 보이기"
         BeginProperty Font 
            Name            =   "굴림체"
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
            Name            =   "굴림체"
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
            Name            =   "굴림체"
            Size            =   9
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
            Name            =   "굴림체"
            Size            =   9
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
            Name            =   "굴림체"
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
         Caption         =   "접속해제"
         BeginProperty Font 
            Name            =   "굴림체"
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
            Name            =   "굴림체"
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
         Caption         =   "로그인ID"
         BeginProperty Font 
            Name            =   "굴림체"
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
         Caption         =   "비밀번호"
         BeginProperty Font 
            Name            =   "굴림체"
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
         Caption         =   "공인인증 암호"
         BeginProperty Font 
            Name            =   "굴림체"
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
      Height          =   1215
      Left            =   120
      TabIndex        =   0
      Top             =   6360
      Width           =   8055
      Begin VB.PictureBox Picture2 
         Appearance      =   0  '평면
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
         Appearance      =   0  '평면
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
         Caption         =   "주식체결(XX1)"
         BeginProperty Font 
            Name            =   "굴림체"
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
         Caption         =   "선물시세(SC0)"
         BeginProperty Font 
            Name            =   "굴림체"
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
         Caption         =   "옵션시세(OC0)"
         BeginProperty Font 
            Name            =   "굴림체"
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
         Caption         =   "선물호가(SH0)"
         BeginProperty Font 
            Name            =   "굴림체"
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
         Caption         =   "옵션호가(OH0)"
         BeginProperty Font 
            Name            =   "굴림체"
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
         Caption         =   "선옵체결(XF2)"
         BeginProperty Font 
            Name            =   "굴림체"
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
         Caption         =   "선옵잔고(XF3)"
         BeginProperty Font 
            Name            =   "굴림체"
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
    
    '계좌리스트 구하기
    szAcctList = DongbuAPI1.GetAccountList(1)  '선물1, 주식 2
    GetFutureAccList False, szAcctList, Len(szAcctList)
    
    m_hDongbuApi = hDongbuApi
    bRet = DongbuAPI1.Init(m_hDongbuApi)
    
    If (bRet) Then
        EnableControls (True)
        DisplayMsg ("동부API 접속 성공...")
    End If
    
End Sub

'DRCM에서 종료되었다는 메시지를 받아서 처리
Private Sub DongbuAPI1_DBApiDisconnected()
    DisplayMsg ("동부API 종료됨")
    EnableControls (False)
End Sub

Private Sub DongbuAPI1_ReceiveData(ByVal nReqID As Long, ByVal szMsgCode As String, ByVal szMsg As String, ByVal szData As String)
    
        Select Case (nReqID)
            'Case REQ_FUT_CHE
            '   DisplayMsg ("선물 체결내역 >> " + szMsg)
            '   ParseTR_13615 (szData)
            'Case REQ_FUT_DEP_OPT '옵션종목별매도증거금
            '    DisplayMsg ("옵션종목별매도증거금 조회 >> " + szMsg)
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
    
    Init주문
         
End Sub

'
Private Sub btnAcctList_Click()
    Dim szAcctList As String
    szAcctList = DongbuAPI1.GetAccountList(1)  '선물1, 주식 2
    GetFutureAccList False, szAcctList, Len(szAcctList)
End Sub

Private Sub btnStockAcctList_Click()
    Dim szAcctList As String
    szAcctList = DongbuAPI1.GetAccountList(2)  '선물1, 주식 2
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
        szAccName = MidEx한글(strData, nPos, 20)
        
        szAcctInfo = szAccNo + " " + Trim(szAccName)
        
        If (bStock) Then
            DisplayMsg ("주식계좌 >> " + Str(i) + " : " + szAcctInfo)
        Else
            DisplayMsg ("선옵계좌 >> " + Str(i) + " : " + szAcctInfo)
        End If
        
        cmbAcctList.AddItem szAcctInfo
        
        If i = nCount Then
            cmbAcctList.Text = szAcctInfo
        End If
    Next i
    
    
    txtPwd.Text = ""
        
End Sub

Private Sub DongbuDRCM1_ReceiveRTData(ByVal szDrdsName As String, ByVal szDrdsField As String, ByVal szDrdsData As String)
    
    DisplayMsg ("실시간데이터 수신>>" + szDrdsName)
    Dim szData As String
    szData = szDrdsData
    
    Select Case szDrdsName
    
    Case R_SC0 '= "SC0"                        ' 선물 현재가
        'Call Parse_SC0(szData)
    Case R_SH0 '= "SH0"                        ' 선물 호가
        'Parse_SH0 (szData)
    Case R_OC0 '= "OC0"                        ' 옵션 현재가
        'Call Parse_OC0(szData)
    Case R_OH0 '= "OH0"                        ' 옵션 호가
        'Call Parse_OH0(szData)
    Case R_XF2 '= "XF2"                        ' 체결
    Case R_XF3 '= "XF3"                        ' 잔고
    End Select
    
End Sub

Private Sub btnClearAll_Click()
    ListBox1.Clear

End Sub

'DRCM에 접속해제한다고 메시지 보내기
Private Sub btnDisconnect_Click()
    DongbuAPI1.Logout
End Sub


Private Sub btnConnect_Click()
    Dim lShowLoginDlg As Long
    Dim lMultiConn As Long
    Dim nReturn As Boolean
    DisplayMsg ("동부API 접속 시도중...")
    
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
    
    'DRCM 로그인
    nReturn = DongbuAPI1.Login(edtID.Text, edtLoginName.Text, edtPwd.Text, edtCertPwd.Text, lShowLoginDlg, lMultiConn)
        
    If (nReturn = False) Then
        DisplayMsg ("동부API 로그인 실패...")
    End If
    
End Sub

Private Sub DisplayMsg(ByVal strMsg As String)
    ListBox1.AddItem strMsg, 0
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
    btnOrder.Enabled = bEnabled
    btnJango.Enabled = bEnabled
    btnCheguyl.Enabled = bEnabled
    btnEval.Enabled = bEnabled
    btnFee.Enabled = bEnabled
    btnAcctList.Enabled = bEnabled
    
    btnStockOrder.Enabled = bEnabled
    btnStockCheguyl.Enabled = bEnabled
    btnStockJango.Enabled = bEnabled
    
    btn옵션종목별매도증거금.Enabled = bEnabled
    
    btnStockAcctList.Enabled = bEnabled
    btnAbleQty.Enabled = bEnabled
    
    
End Sub


Private Function Init주문()
    cmbPriceType.AddItem "00:지정가"
    cmbPriceType.AddItem "03:시장가"
    cmbPriceType.AddItem "05:조건부지정가"
    cmbPriceType.AddItem "06:최유리지정가"
    
    cmbPriceType.Text = "00:지정가"

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
    Dim szJongmok As String  '/* 종목코드
    Dim nOrderPrice As Long  '주문가격
    Dim nOrdSect As Long     '/* 1:매도, 2:매수,  3:정정, 4:취소
    Dim nPriceType As Long   '/* 00:지정가 03:시장가 05:조건부지정가  06:최유리지정가
    Dim nOrgOrderNo As Long  '/*원주문번호
    Dim nQty As Long  '주문수량
    
    
    If (opt매수.Value = True) Then
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
    Dim nRet As Boolean
    Dim szData As String
    Dim dOrderPrice As Double
    
    If (Not IsEmpty(edtPrice.Text)) Then
        dOrderPrice = CDbl(edtPrice.Text)
    End If
                
    szAccount = Left(cmbAcctList.Text, LEN_GEJANO)
    szPwd = txtPwd.Text
    szJongmok = edtJongCode.Text                        '/*종목코드(12)
    
    '/*매매구분(1) # 1:매도, 2:매수
    If (opt매수.Value = True) Then
        sz매매구분 = "2"                       '
    Else
        sz매매구분 = "1"
    End If
    
    szFnoOrdprcPtnCode = Left(cmbPriceType.Text, 2)     '/*선물옵션호가유형코드(2) # 00:지정가 03:시장가 05:조건부지정가  06:최유리지정가
                    
    'nRet = DongbuDRCM1.ReqAbleQty(szAccount, szPwd, szJongmok, sz매매구분, dOrderPrice, szFnoOrdprcPtnCode)

End Sub

'주식체결
Private Sub btnStockCheguyl_Click()
    Dim szAccount As String
    Dim szNextKey As String
    Dim szGB As String
    Dim nRet As Long
    
    szAccount = Left(cmbAcctList.Text, LEN_GEJANO)
    
    If IsEmpty(szAccount) Then
        Exit Sub
    End If
    
    szGB = "1" '1:주문/체결 2:미체결
    'nRet = DongbuDRCM1.ReqStockChegyul(szAccount, szGB, szNextKey)


End Sub

'주식잔고
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


'잔고조회
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
'체결내역
Private Sub btnCheguyl_Click()
    frm체결리스트.Show
            
End Sub

'평가현황 조회
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
'수수료/주문가능 금액
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

'옵션종목별매도증거금 1600
Private Sub btn옵션종목별매도증거금_Click()
    frm옵션종목별매도증거금.Show
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


Private Sub ParseTR_13655(strData As String) '선옵 잔고조회

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

Private Sub ParseTR_13148(strData As String) '주식 잔고조회

On Error Resume Next
    'TR_13148
    
    '''''''''''''''''''''''''''''
    Dim sm_bjlen
    Dim sm_bjdata
    '''''''''''''''''''''''''''''sm
    Dim 총매입금액
    Dim 총평가손익
    Dim 당일매도금액
    Dim 총평가금액
    Dim 총수익율
    Dim 당일실현손익
    Dim Next구분
    Dim NextKey
    '''''''''''''''''''''''''''''
    Dim gr_bjlen
    Dim gr_bjdata
    '''''''''''''''''''''''''''''
    Dim 종목코드
    Dim 종목명
    Dim 가용수량
    Dim 평가손익
    Dim 수익율
    Dim 잔고금액
    Dim 평가금액
    Dim 전일변동
    Dim 금일변동
    Dim 결제잔고
    Dim 장부단가
    Dim 제비용
    Dim 주당비용
    Dim 수수료
    Dim 세금
    Dim 현재가
    Dim 전일대비
    Dim 최종매입일
    Dim 등락부호
    Dim 실현손익
    Dim 금일매도금액
    Dim 잔고구분
    Dim 대출일
    Dim 만기일
    Dim 신용금액
    Dim 대출이자
    Dim 현금증거금율
    Dim 총평가금액금액
    
    Dim 레코드갯수 As Long
    
 
    Dim i As Long, nPos As Long
    
    nPos = 1
    
    sm_bjlen = MidEx(strData, nPos, 6)
    sm_bjdata = MidEx(strData, nPos, 5)
    
    총매입금액 = MidEx(strData, nPos, 15)
    총평가손익 = MidEx(strData, nPos, 15)
    당일매도금액 = MidEx(strData, nPos, 15)
    총평가금액금액 = MidEx(strData, nPos, 15)
    총수익율 = MidEx(strData, nPos, 15)
    당일실현손익 = MidEx(strData, nPos, 15)
    Next구분 = MidEx(strData, nPos, 1)
    NextKey = MidEx(strData, nPos, 50)
    
    
    gr_bjlen = MidEx(strData, nPos, 6)
    gr_bjdata = MidEx(strData, nPos, 5)
    
    
    레코드갯수 = CLng(gr_bjlen)
    
    For i = 1 To 레코드갯수
        strData = Mid(strData, nPos):       nPos = 1
        
        종목코드 = MidEx(strData, nPos, 6)
        종목명 = MidEx한글(strData, nPos, 20)
        가용수량 = MidEx(strData, nPos, 15)
        평가손익 = MidEx(strData, nPos, 15)
        수익율 = MidEx(strData, nPos, 7)
        
        잔고금액 = MidEx(strData, nPos, 15)
        평가금액 = MidEx(strData, nPos, 15)
        전일변동 = MidEx(strData, nPos, 15)
        금일변동 = MidEx(strData, nPos, 15)
        결제잔고 = MidEx(strData, nPos, 15)
        
        장부단가 = MidEx(strData, nPos, 9)
        제비용 = MidEx(strData, nPos, 9)
        주당비용 = MidEx(strData, nPos, 9)
        수수료 = MidEx(strData, nPos, 9)
        세금 = MidEx(strData, nPos, 9)
        
        현재가 = MidEx(strData, nPos, 7)
        전일대비 = MidEx(strData, nPos, 7)
        최종매입일 = MidEx(strData, nPos, 8)
        등락부호 = MidEx(strData, nPos, 1)
        실현손익 = MidEx(strData, nPos, 15)
        금일매도금액 = MidEx(strData, nPos, 15)
        
        잔고구분 = MidEx(strData, nPos, 1)
        대출일 = MidEx(strData, nPos, 8)
        만기일 = MidEx(strData, nPos, 8)
        신용금액 = MidEx(strData, nPos, 15)
        대출이자 = MidEx(strData, nPos, 9)
        현금증거금율 = MidEx(strData, nPos, 3)
        
    Next i
    
End Sub



Private Sub ParseTR_13118(strData As String) '주식체결리스트

On Error Resume Next
    'TR_1311

    Dim 레코드Count As Long
    Dim 레코드Len As String
    Dim 그리드Msg As String

    Dim 주문번호 As Long
    Dim 종목코드 As String
    Dim 종목명 As String
    Dim 매매구분속성 As String
    Dim 매매구분 As String
    
    Dim 주문수량 As String
    Dim 주문단가 As String
    Dim 체결수량 As String
    Dim 체결가격 As String
    
    Dim 미체결수량 As String
    Dim 주문유형 As String
    Dim 원주문번호 As String
    Dim 처리구분 As String
    Dim 체결률 As String
    
    Dim 주문시간 As String
    Dim 제비용 As String
    Dim 수수료 As String
    Dim 세금 As String
    Dim 신용구분 As String
           
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
    레코드Count = MidEx(strData, nPos, 4)
    gr_bjlen = MidEx(strData, nPos, 2)
    gr_bjdata = MidEx(strData, nPos, 4)
    
    
    For i = 1 To 레코드Count
    
        strData = Mid(strData, nPos):       nPos = 1
        
        주문번호 = MidEx(strData, nPos, 9)
        종목코드 = MidEx(strData, nPos, 12)
        종목명 = MidEx한글(strData, nPos, 20)
        매매구분속성 = MidEx(strData, nPos, 3)
        매매구분 = MidEx한글(strData, nPos, 16)
        주문수량 = MidEx(strData, nPos, 15)
        주문단가 = MidEx(strData, nPos, 12)
        체결수량 = MidEx(strData, nPos, 15)
        체결가격 = MidEx(strData, nPos, 12)
        미체결수량 = MidEx(strData, nPos, 15)
        주문유형 = MidEx한글(strData, nPos, 10)
        원주문번호 = Trim(MidEx한글(strData, nPos, 9))
        처리구분 = Trim(MidEx한글(strData, nPos, 10))
        체결률 = Trim(MidEx한글(strData, nPos, 9))
        주문시간 = Trim(MidEx한글(strData, nPos, 6))
        제비용 = Trim(MidEx한글(strData, nPos, 9))
        수수료 = Trim(MidEx한글(strData, nPos, 9))
        세금 = Trim(MidEx한글(strData, nPos, 9))
        신용구분 = Trim(MidEx한글(strData, nPos, 3))
        
    Next i
    
End Sub

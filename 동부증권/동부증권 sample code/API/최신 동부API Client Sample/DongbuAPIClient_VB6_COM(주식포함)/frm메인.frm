VERSION 5.00
Begin VB.Form frm메인 
   Caption         =   "동부API VB6.0 Sample(OCX)"
   ClientHeight    =   7440
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   8280
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
   ScaleHeight     =   7440
   ScaleWidth      =   8280
   StartUpPosition =   3  'Windows 기본값
   Begin VB.Frame Frame3 
      Caption         =   "옵션 실시간 데이터 요청 등록 및 해제  예제"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   120
      TabIndex        =   33
      Top             =   3480
      Width           =   8055
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
         Left            =   5280
         TabIndex        =   36
         Top             =   360
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
         Left            =   3600
         TabIndex        =   35
         Top             =   360
         Width           =   1572
      End
      Begin VB.TextBox txtOptionCodes 
         Height          =   288
         Left            =   1560
         TabIndex        =   34
         Text            =   "301G2230"
         Top             =   360
         Width           =   1815
      End
      Begin VB.Label Label6 
         Caption         =   "종목코드"
         Height          =   255
         Left            =   360
         TabIndex        =   38
         Top             =   360
         Width           =   1095
      End
   End
   Begin VB.Frame Frame2 
      Caption         =   "예제 화면(선옵,주식)"
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
      Left            =   120
      TabIndex        =   26
      Top             =   4320
      Width           =   8055
      Begin VB.CommandButton btnFee 
         Caption         =   "평가현황 / 평가예탁총액,수수료,주문가능금액"
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
         Left            =   240
         TabIndex        =   32
         Top             =   1320
         Width           =   4335
      End
      Begin VB.CommandButton btnJango 
         Caption         =   "잔고내역(선옵,주식)"
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
         Left            =   2880
         TabIndex        =   31
         Top             =   840
         Width           =   2535
      End
      Begin VB.CommandButton btnCheguyl 
         Caption         =   "체결내역(선옵,주식)"
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
         Left            =   240
         TabIndex        =   30
         Top             =   840
         Width           =   2535
      End
      Begin VB.CommandButton btn옵션종목별매도증거금 
         Caption         =   "옵션 종목별 매도증거금"
         Height          =   372
         Left            =   4680
         TabIndex        =   29
         Top             =   1320
         Width           =   2535
      End
      Begin VB.CommandButton btnAbleQty 
         Caption         =   "신규/청산 가능수량(선옵)"
         Height          =   375
         Left            =   2880
         TabIndex        =   28
         Top             =   360
         Width           =   2535
      End
      Begin VB.CommandButton btnOrder 
         Caption         =   "주문(선옵,주식)"
         Height          =   375
         Left            =   240
         TabIndex        =   27
         Top             =   360
         Width           =   2535
      End
   End
   Begin VB.Frame Frame5 
      Caption         =   "계좌조회 예제"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   120
      TabIndex        =   17
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
         TabIndex        =   24
         Top             =   240
         Width           =   1455
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
         TabIndex        =   19
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
         TabIndex        =   18
         Top             =   240
         Width           =   735
      End
   End
   Begin VB.Frame Frame4 
      Caption         =   "동부API 로그인"
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
      TabIndex        =   12
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
         Left            =   3480
         TabIndex        =   23
         Top             =   600
         Width           =   1095
      End
      Begin VB.TextBox edtLoginName 
         Enabled         =   0   'False
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
         TabIndex        =   21
         Text            =   "Text1"
         Top             =   960
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
         Left            =   3480
         TabIndex        =   20
         Top             =   240
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
         Caption         =   "로그인"
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
         Caption         =   "로그아웃"
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
         TabIndex        =   13
         Top             =   960
         Width           =   1335
      End
      Begin VB.Label Label4 
         Caption         =   "Name"
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
         Left            =   3720
         TabIndex        =   22
         Top             =   960
         Width           =   495
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
         TabIndex        =   16
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
         TabIndex        =   15
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
         TabIndex        =   14
         Top             =   1080
         Width           =   1215
      End
   End
   Begin VB.CommandButton btnClearAll 
      Caption         =   "내역삭제"
      BeginProperty Font 
         Name            =   "맑은 고딕"
         Size            =   9
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1095
      Left            =   7080
      TabIndex        =   10
      Top             =   6240
      Width           =   1095
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
      TabIndex        =   11
      Top             =   6240
      Width           =   6855
   End
   Begin VB.Frame Frame1 
      Caption         =   "선물 실시간 데이터 요청 등록 및 해제  예제"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   120
      TabIndex        =   0
      Top             =   2640
      Width           =   8055
      Begin VB.TextBox txtFutureCodes 
         Height          =   288
         Left            =   1560
         TabIndex        =   25
         Text            =   "101G3000,101G6000"
         Top             =   360
         Width           =   1815
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
         Left            =   3600
         TabIndex        =   8
         Top             =   360
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
         Left            =   5280
         TabIndex        =   9
         Top             =   360
         Width           =   1572
      End
      Begin VB.Label Label5 
         Caption         =   "종목코드"
         Height          =   255
         Left            =   360
         TabIndex        =   37
         Top             =   360
         Width           =   1095
      End
   End
End
Attribute VB_Name = "frm메인"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim WithEvents 동부API객체  As DongbuAPI
Attribute 동부API객체.VB_VarHelpID = -1

Dim m_RTDataSC0 As clsDrdsSC0
Dim m_RTDataSH0 As clsDrdsSH0
Dim m_RTDataOC0 As clsDrdsOC0
Dim m_RTDataOH0 As clsDrdsOH0

Dim m_frm옵션종목별매도증거금 As frm옵션종목별매도증거금
Dim m_frm주문 As frm주문
Dim m_frm체결리스트 As frm체결리스트
Dim m_frm잔고리스트 As frm잔고리스트
Dim m_frm평가현황 As frm평가현황

Private Sub 동부API객체_Connected(ByVal hDongbuApi As Long)
    Dim szAcctList As String
    Dim bRet As Boolean
    
    DisplayMsg ("동부API 접속 성공...")
    
    '계좌리스트 구하기
    szAcctList = 동부API객체.GetAccountList(1)  '선물1, 주식 2
    GetFutureAccList False, szAcctList, Len(szAcctList)
    
    g_hDongbuApi = hDongbuApi
    g_szID = Trim(edtID.Text)
    
    
     Set m_frm옵션종목별매도증거금 = New frm옵션종목별매도증거금
     Set m_frm잔고리스트 = New frm잔고리스트
     Set m_frm체결리스트 = New frm체결리스트
     Set m_frm평가현황 = New frm평가현황
     Set m_frm주문 = New frm주문
     
     EnableControls (True)
End Sub

'DRCM에서 종료되었다는 메시지를 받아서 처리
Private Sub 동부API객체_Disconnected()
      g_hDongbuApi = 0
    g_szID = ""
    
    DisplayMsg ("동부API 종료됨")
    EnableControls (False)
    
    Unload m_frm옵션종목별매도증거금
    Unload m_frm잔고리스트
    Unload m_frm체결리스트
    Unload m_frm평가현황
    Unload m_frm주문
End Sub

Private Sub chkMultiConn_Click()
    If (chkMultiConn.Value = vbChecked) Then
        edtLoginName.Enabled = True
    Else
        edtLoginName.Enabled = False
    End If
    
End Sub

Private Sub Form_Load()

    Set 동부API객체 = New DongbuAPI
    
    edtID.Text = g_InitID
    edtLoginName.Text = edtID.Text 'g_InitLoginName
    If edtLoginName.Text = "" Then
        edtLoginName.Text = "dongbu test"
    End If
    
    edtPwd.Text = g_InitPwd
    edtCertPwd.Text = g_InitCertPwd
    cmbAcctList.Text = g_InitAcctNo
    txtPwd.Text = g_InitAcctPwd
    
    Set m_RTDataSC0 = New clsDrdsSC0
    Set m_RTDataSH0 = New clsDrdsSH0
    Set m_RTDataOC0 = New clsDrdsOC0
    Set m_RTDataOH0 = New clsDrdsOH0
    
    EnableControls (False)
     
End Sub

Private Sub Form_Unload(Cancel As Integer)
      
    동부API객체.Logout
    
    Set 동부API객체 = Nothing
    
    Set m_RTDataSC0 = Nothing
    Set m_RTDataSH0 = Nothing
    Set m_RTDataOC0 = Nothing
    Set m_RTDataOH0 = Nothing
    
End Sub


Private Sub 동부API객체_ReceiveData(ByVal nReqID As Long, ByVal szMsgCode As String, ByVal szMsg As String, ByVal szData As String)
        Select Case (nReqID)
        Case REQ_FUT_ORDER
        Case REQ_FUT_JANGO
        Case REQ_FUT_JANGO2
        Case REQ_FUT_CHE
        Case REQ_FUT_EVAL
        Case REQ_FUT_FEE             '수수료/주문가능금액/예탁총액
        Case REQ_FUT_DEP_OPT      '옵션종목별매도증거금
        Case REQ_FUT_ORDER_QTY  '신규/청산 가능수량
        Case REQ_STK_ORDER
        Case REQ_STK_JANGO
        Case REQ_STK_CHE
        Case REQ_STK_EVAL
        End Select
End Sub

Private Sub 동부API객체_ReceiveRTData(ByVal szName As String, ByVal szField As String, ByVal szData As String)

    DisplayMsg ("실시간데이터 수신>>" + szName + ":" + szField)
    DisplayMsg ("DATA>>" + szData)
    
    Select Case szName
    
    Case R_SC0                        ' 선물 현재가
        Call Parse_SC0(szData)
    Case R_SH0                        ' 선물 호가
        Parse_SH0 (szData)
    Case R_OC0                       ' 옵션 현재가
        Call Parse_OC0(szData)
    Case R_OH0                      ' 옵션 호가
        Call Parse_OH0(szData)
    End Select

End Sub

Private Sub Parse_SC0(ByVal strData As String)
    m_RTDataSC0.Init (strData)
End Sub

Private Sub Parse_SH0(ByVal strData As String)
    m_RTDataSH0.Init (strData)
End Sub

Private Sub Parse_OC0(ByVal strData As String)
    m_RTDataOC0.Init (strData)
End Sub

Private Sub Parse_OH0(ByVal strData As String)
    m_RTDataOH0.Init (strData)
End Sub

Private Sub btnAcctList_Click()
    Dim szAcctList As String
    szAcctList = 동부API객체.GetAccountList(1)  '선물1, 주식 2
    GetFutureAccList False, szAcctList, Len(szAcctList)
End Sub

Private Sub btnStockAcctList_Click()
    Dim szAcctList As String
    szAcctList = 동부API객체.GetAccountList(2)  '선물1, 주식 2
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

Private Sub btnClearAll_Click()
    ListBox1.Clear

End Sub

'동부API에 접속해제한다고 메시지 보내기
Private Sub btnDisconnect_Click()
    동부API객체.Logout
End Sub

'접속해지
Private Sub btnConnect_Click()
    Dim lShowLoginDlg As Long
    Dim lMultiConn As Long
    Dim bReturn As Boolean
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
    
    '동부API 컨트롤 생성
    bReturn = 동부API객체.CreateDongbuAPICtrl(edtLoginName.Text, lMultiConn, CLng(Me.hWnd))
    
    '동부API로그인
    If (bReturn) Then
        bReturn = 동부API객체.Login(edtID.Text, edtPwd.Text, edtCertPwd.Text, lShowLoginDlg)
    End If
        
    If (bReturn = False) Then
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
    
    btnFee.Enabled = bEnabled
    btnAcctList.Enabled = bEnabled
    
    
    btn옵션종목별매도증거금.Enabled = bEnabled
    
    btnStockAcctList.Enabled = bEnabled
    btnAbleQty.Enabled = bEnabled
    
    
End Sub

Private Sub btnOC0_Click()

    Dim szData As String
    Dim bRet As Boolean

    szData = txtOptionCodes.Text

    If (btnOC0.Value = vbChecked) Then
        bRet = 동부API객체.ReqRealtimeData(ID_ADVICE_RT, R_OC0, szData)
    Else
        bRet = 동부API객체.ReqRealtimeData(ID_UNADVICE_RT, R_OC0, szData)
    End If

End Sub

Private Sub btnOH0_Click()
    Dim szData As String
    Dim bRet As Boolean

    szData = txtOptionCodes.Text

    If (btnOH0.Value = vbChecked) Then
        bRet = 동부API객체.ReqRealtimeData(ID_ADVICE_RT, R_OH0, szData)
    Else
        bRet = 동부API객체.ReqRealtimeData(ID_UNADVICE_RT, R_OH0, szData)
    End If

End Sub

Private Sub btnSC0_Click()

    Dim szData As String
    Dim bRet As Boolean

    szData = txtFutureCodes.Text

    If (btnSC0.Value = vbChecked) Then
        bRet = 동부API객체.ReqRealtimeData(ID_ADVICE_RT, R_SC0, szData)
    Else
        bRet = 동부API객체.ReqRealtimeData(ID_UNADVICE_RT, R_SC0, szData)
    End If
End Sub

Private Sub btnSH0_Click()
    Dim szData As String
    Dim bRet As Boolean

    szData = txtFutureCodes.Text

    If (btnSH0.Value = vbChecked) Then
        bRet = 동부API객체.ReqRealtimeData(ID_ADVICE_RT, R_SH0, szData)
    Else
        bRet = 동부API객체.ReqRealtimeData(ID_UNADVICE_RT, R_SH0, szData)
    End If

End Sub

'옵션종목별매도증거금 1600
Private Sub btn옵션종목별매도증거금_Click()
        
    m_frm옵션종목별매도증거금.Show
End Sub

'선옵 신규/청산 가능수량
Private Sub btnAbleQty_Click()
    m_frm주문.Show
End Sub

'주문
Private Sub btnOrder_Click()
    m_frm주문.Show
End Sub

'잔고리스트
Private Sub btnJango_Click()
    m_frm잔고리스트.Show
End Sub

'체결내역
Private Sub btnCheguyl_Click()
    m_frm체결리스트.Show
End Sub

'평가현황 조회/수수료/주문가능금액/평가예탁총액
Private Sub btnFee_Click()
    m_frm평가현황.Show
End Sub


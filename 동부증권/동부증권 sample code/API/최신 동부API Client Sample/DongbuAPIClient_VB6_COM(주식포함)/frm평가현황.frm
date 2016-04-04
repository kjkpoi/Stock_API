VERSION 5.00
Begin VB.Form frm평가현황 
   Caption         =   "평가현황"
   ClientHeight    =   2385
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   10425
   LinkTopic       =   "Form1"
   ScaleHeight     =   2385
   ScaleWidth      =   10425
   StartUpPosition =   3  'Windows 기본값
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
      Caption         =   "평가현황"
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
         Name            =   "굴림체"
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
      Caption         =   "날짜"
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
      Left            =   4080
      TabIndex        =   7
      Top             =   120
      Width           =   495
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
      Left            =   2520
      TabIndex        =   6
      Top             =   120
      Width           =   735
   End
   Begin VB.Label Label7 
      Caption         =   "계좌"
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
      TabIndex        =   5
      Top             =   120
      Width           =   495
   End
End
Attribute VB_Name = "frm평가현황"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim WithEvents 동부API객체  As DongbuAPI
Attribute 동부API객체.VB_VarHelpID = -1

Private Sub Form_Load()
    Dim bRet As Boolean
     '초기화
    Set 동부API객체 = New DongbuAPI
    bRet = 동부API객체.InitCtrl(g_hDongbuApi, CLng(Me.hWnd))
    
    txtAccount.Text = g_InitAcctNo
    txtPwd.Text = g_InitAcctPwd
    
    txtDate.Text = Format(Now, "YYYYMMDD")
End Sub

Private Sub Form_Unload(Cancel As Integer)

    Set 동부API객체 = Nothing
    
End Sub

Private Sub DisplayMsg(ByVal strMsg As String)

    ListBox1.AddItem strMsg, 0
    
End Sub

Private Sub 동부API객체_ReceiveData(ByVal nReqID As Long, ByVal szMsgCode As String, ByVal szMsg As String, ByVal szData As String)
    Select Case (nReqID)
        Case REQ_FUT_EVAL
            DisplayMsg ("평가현황 조회>> " + szMsg)
            Parse_REQ_FUT_EVAL (szData)
        Case REQ_FUT_FEE
            DisplayMsg ("수수료/주문가능금액/평가예탁총액 조회 >> " + szMsg)
            Parse_REQ_FUT_FEE (szData)
            
    End Select
End Sub

Private Sub Parse_REQ_FUT_FEE(strData As String) '수수료
    
    Dim 평가예탁총액
    Dim 주문가능금액
    Dim 수수료

    Dim nPos As Long
    
    nPos = 1
    평가예탁총액 = MidEx(strData, nPos, 15)
    주문가능금액 = MidEx(strData, nPos, 16)
    수수료 = MidEx(strData, nPos, 16)
    
    DisplayMsg strData
    
End Sub

Private Sub Parse_REQ_FUT_EVAL(strData As String) '예탁금

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
    
    bRet = 동부API객체.ReqEval(szAccount, szPwd, szDate)
End Sub

'수수료/주문가능 금액
Private Sub btnFee_Click()
    
    Dim szAccount As String
    Dim szPwd As String
    Dim szDate As String
    Dim bRet As Boolean
            
    szAccount = txtAccount.Text
    szPwd = txtPwd.Text
    szDate = txtDate.Text
    
    bRet = 동부API객체.ReqFeeNAbleMoney(szAccount, szPwd, szDate)
    
End Sub


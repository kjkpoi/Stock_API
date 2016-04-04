VERSION 5.00
Begin VB.Form frm주문 
   Caption         =   "주문 관련"
   ClientHeight    =   3675
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8160
   LinkTopic       =   "Form1"
   ScaleHeight     =   3675
   ScaleWidth      =   8160
   StartUpPosition =   3  'Windows 기본값
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
      Height          =   1695
      Left            =   120
      TabIndex        =   1
      Top             =   120
      Width           =   7935
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
         Caption         =   "신규/청산 가능수량"
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
      Begin VB.OptionButton opt매도 
         Caption         =   "매도"
         Height          =   255
         Left            =   3600
         TabIndex        =   5
         Top             =   720
         Width           =   855
      End
      Begin VB.OptionButton opt매수 
         Caption         =   "매수"
         Height          =   255
         Left            =   3600
         TabIndex        =   4
         Top             =   1080
         Value           =   -1  'True
         Width           =   855
      End
      Begin VB.CommandButton btnOrder 
         Caption         =   "선옵 주문"
         Height          =   495
         Left            =   4680
         TabIndex        =   3
         Top             =   240
         Width           =   1095
      End
      Begin VB.CommandButton btnStockOrder 
         Caption         =   "주식 주문"
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
         TabIndex        =   17
         Top             =   360
         Width           =   375
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
         Left            =   2880
         TabIndex        =   16
         Top             =   360
         Width           =   735
      End
      Begin VB.Label 가격 
         Caption         =   "가격"
         Height          =   255
         Left            =   2280
         TabIndex        =   13
         Top             =   1080
         Width           =   375
      End
      Begin VB.Label Label6 
         Caption         =   "수량"
         Height          =   255
         Left            =   2280
         TabIndex        =   12
         Top             =   720
         Width           =   375
      End
      Begin VB.Label Label5 
         Caption         =   "종목"
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
Attribute VB_Name = "frm주문"
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
    
    Init주문
    
End Sub

Private Sub Form_Unload(Cancel As Integer)

    Set 동부API객체 = Nothing
    
End Sub


Private Function Init주문()

    cmbPriceType.AddItem "00:지정가"
    cmbPriceType.AddItem "03:시장가"
    cmbPriceType.AddItem "05:조건부지정가"
    cmbPriceType.AddItem "06:최유리지정가"
    
    cmbPriceType.Text = "00:지정가"

End Function


Private Sub DisplayMsg(ByVal strMsg As String)

    ListBox1.AddItem strMsg, 0
    
End Sub

Private Sub 동부API객체_ReceiveData(ByVal nReqID As Long, ByVal szMsgCode As String, ByVal szMsg As String, ByVal szData As String)
    Select Case (nReqID)
        Case REQ_FUT_ORDER
            DisplayMsg ("선옵주문 >> " + szMsg)
            ParseREQ_ORDER (szData)
            
        Case REQ_STK_ORDER
            DisplayMsg ("주식주문 >> " + szMsg)
            ParseREQ_ORDER (szData)
            
        Case REQ_FUT_ORDER_QTY
            DisplayMsg ("신규/청산가능수량 조회  >> " + szMsg)
            Parse_REQ_FUT_ORDER_QTY (szData)
    End Select
    
End Sub

'신규/청산 수량 조회 응답
Private Sub Parse_REQ_FUT_ORDER_QTY(strData As String)
    Dim 신규주문가능수량
    Dim 청산주문가능수량
    
    Dim nPos As Long
    
    nPos = 1
    신규주문가능수량 = MidEx(strData, nPos, 15)
    청산주문가능수량 = MidEx(strData, nPos, 15)
    
    DisplayMsg (strData)
    
End Sub

Private Sub ParseREQ_ORDER(strData As String) '주문응답

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

Private Sub SendOrder(bFutureOrder As Boolean)
    Dim bRet As Boolean
            
    Dim szAccount As String
    Dim szPwd As String
    Dim szJongmok As String  '/* 종목코드
    Dim nOrderPrice As Long  '주문가격
    Dim nOrdSect As Long     '/* 1:매도, 2:매수,  3:정정, 4:취소
    Dim nPriceType As Long   '/* 00:지정가 03:시장가 05:조건부지정가  06:최유리지정가
    Dim nOrgOrderNo As Long  '/*원주문번호
    Dim nQty As Long  '주문수량
        
    szAccount = txtAccount.Text
    szPwd = txtPwd.Text
    szJongmok = edtJongCode.Text
    nPriceType = CLng(Left(cmbPriceType.Text, 2))
    nQty = CLng(edtQty.Text)
    nOrderPrice = CDbl(edtPrice.Text)
    
    If (opt매수.Value = True) Then
        nOrdSect = GB_BUY
    Else
        nOrdSect = GB_SELL
    End If
    
    If (bFutureOrder) Then
        nOrderPrice = nOrderPrice * 100
        bRet = 동부API객체.SendFOrder(8888, szAccount, szPwd, nOrdSect, szJongmok, nPriceType, nQty, nOrderPrice, nOrgOrderNo)
    Else
        bRet = 동부API객체.SendSOrder(7777, szAccount, szPwd, nOrdSect, szJongmok, nPriceType, nQty, nOrderPrice, nOrgOrderNo)
    End If
    
    If (bRet = False) Then
        MsgBox "주문전송 실패"
    End If
    
End Sub

Private Sub btnOrder_Click()
    '선옵주문
    SendOrder (True)
    
End Sub

Private Sub btnStockOrder_Click()
    '주식주문
    SendOrder (False)
    
End Sub

'신규/청산 가능수량
Private Sub btnAbleQty_Click()

    Dim szAccount As String
    Dim szPwd As String
    Dim szJongmok As String
    Dim nOrderType As Integer
    Dim sz호가유형 As String
    Dim nPrice As Integer
        
    Dim bRet As Boolean
    
    szAccount = txtAccount.Text
    szPwd = txtPwd.Text
    szJongmok = edtJongCode.Text
    
    If (Not IsEmpty(edtPrice.Text)) Then
        nPrice = CDbl(edtPrice.Text) * 100
    Else
        MsgBox "가격을 입력하세요"
        Exit Sub
    End If
        
    '/*매매구분(1) # 1:매도, 2:매수
    If (opt매수.Value = True) Then
        nOrderType = GB_BUY
    Else
        nOrderType = GB_SELL
    End If
    
    '/*선물옵션호가유형코드(2) # 00:지정가 03:시장가 05:조건부지정가 06:최유리지정가
    sz호가유형 = Left(cmbPriceType.Text, 2)
                    
    bRet = 동부API객체.ReqAbleQty(szAccount, szPwd, szJongmok, nOrderType, nPrice, sz호가유형)

End Sub


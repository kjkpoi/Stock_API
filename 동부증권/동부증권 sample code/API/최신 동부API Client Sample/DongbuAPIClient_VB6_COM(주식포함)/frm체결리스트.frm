VERSION 5.00
Begin VB.Form frm체결리스트 
   Caption         =   "체결내역조회"
   ClientHeight    =   3900
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8235
   LinkTopic       =   "Form1"
   ScaleHeight     =   3900
   ScaleWidth      =   8235
   StartUpPosition =   3  'Windows 기본값
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
         Name            =   "굴림체"
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
      Caption         =   "선옵체결(XF2) 실시간데이터 요청 등록 및 해제"
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
      TabIndex        =   4
      Top             =   600
      Width           =   4695
   End
   Begin VB.CheckBox btnXX1 
      Caption         =   "주식체결(XX1) 실시간데이터 요청 등록 및 해제"
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
      TabIndex        =   3
      Top             =   960
      Width           =   4695
   End
   Begin VB.OptionButton opt선옵 
      Caption         =   "선옵"
      Height          =   255
      Left            =   5040
      TabIndex        =   2
      Top             =   120
      Value           =   -1  'True
      Width           =   855
   End
   Begin VB.OptionButton opt주식 
      Caption         =   "주식"
      Height          =   255
      Left            =   5880
      TabIndex        =   1
      Top             =   120
      Width           =   855
   End
   Begin VB.CommandButton btnCheguyl 
      Caption         =   "조회"
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
      TabIndex        =   0
      Top             =   120
      Width           =   1095
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
      Left            =   3240
      TabIndex        =   9
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
      TabIndex        =   8
      Top             =   120
      Width           =   615
   End
End
Attribute VB_Name = "frm체결리스트"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim WithEvents 동부API객체  As DongbuAPI
Attribute 동부API객체.VB_VarHelpID = -1

Dim m_RTDataXF2 As clsDrdsXF2   '선옵체결
Dim m_RTDataXX1 As clsDrdsXX1  '주식체결
Dim m_szNextKey As String

Private Sub Form_Load()

    Dim bRet As Boolean
     '초기화
    Set 동부API객체 = New DongbuAPI
    bRet = 동부API객체.InitCtrl(g_hDongbuApi, CLng(Me.hWnd))
    
    txtAccount.Text = g_InitAcctNo
    txtPwd.Text = g_InitAcctPwd
    
    Set m_RTDataXF2 = New clsDrdsXF2
    Set m_RTDataXX1 = New clsDrdsXX1
End Sub

Private Sub Form_Unload(Cancel As Integer)
    Dim bRet As Boolean
    '실시간요청 해제
    If (btnXF2.Value = vbChecked) Then
        bRet = 동부API객체.ReqRealtimeData(ID_UNADVICE_RT, R_XF2, g_szID)
    End If
    
     If (btnXX1.Value = vbChecked) Then
        bRet = 동부API객체.ReqRealtimeData(ID_UNADVICE_RT, R_XX1, g_szID)
    End If
    
    Set 동부API객체 = Nothing
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
    
    If (opt선옵.Value = True) Then
        nRet = 동부API객체.ReqChegyul(szAccount, szPwd, "1")
    Else
        szGB = "1" '1:주문/체결 2:미체결
        nRet = 동부API객체.ReqStockChegyul(szAccount, szGB, m_szNextKey)
    End If
    
    m_szNextKey = ""
     
End Sub

'주식체결 실시간
Private Sub btnXX1_Click()
    Dim szId As String
    Dim nRet As Long
    
    If (btnXX1.Value = vbChecked) Then
        nRet = 동부API객체.ReqRealtimeData(ID_ADVICE_RT, R_XX1, g_szID)
    Else
        nRet = 동부API객체.ReqRealtimeData(ID_UNADVICE_RT, R_XX1, g_szID)
    End If
    
End Sub

'선옵체결 실시간
Private Sub btnXF2_Click()
    Dim szId As String
    Dim nRet As Long

    If (btnXF2.Value = vbChecked) Then
        nRet = 동부API객체.ReqRealtimeData(ID_ADVICE_RT, R_XF2, g_szID)
    Else
        nRet = 동부API객체.ReqRealtimeData(ID_UNADVICE_RT, R_XF2, g_szID)
    End If

End Sub

Private Sub Parse_XF2(ByVal strData As String)
    m_RTDataXF2.Init (strData)
End Sub

Private Sub Parse_XX1(ByVal strData As String)
    m_RTDataXX1.Init (strData)
End Sub

Private Sub 동부API객체_ReceiveRTData(ByVal szName As String, ByVal szField As String, ByVal szData As String)

    DisplayMsg ("실시간데이터 수신>>" + szName + ":" + szField)
    DisplayMsg ("DATA>>" + szData)
    
    Select Case szName
    Case R_XF2                      '선옵 체결
        Call Parse_XF2(szData)
    Case R_XX1                      '주식 체결
        Call Parse_XX1(szData)
    End Select

End Sub

Private Sub 동부API객체_ReceiveData(ByVal nReqID As Long, ByVal szMsgCode As String, ByVal szMsg As String, ByVal szData As String)
    Select Case (nReqID)
        Case REQ_STK_CHE
            DisplayMsg ("주식 체결내역 >> " + szMsg)
            Parse_REQ_STK_CHE (szData)
            
        Case REQ_FUT_CHE
            DisplayMsg ("선물 체결내역 >> " + szMsg)
            Parse_REQ_FUT_CHE (szData)
    End Select
End Sub

Private Sub Parse_REQ_STK_CHE(strData As String) '주식체결리스트

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
        
        szItem(1) = MidEx(strData, nPos, 9) ' 주문번호
        szItem(2) = MidEx(strData, nPos, 12) ' 종목코드
        szItem(3) = MidEx한글(strData, nPos, 20) ' 종목명
        szItem(4) = MidEx(strData, nPos, 3)  ' 매매구분속성
        szItem(5) = MidEx한글(strData, nPos, 16)  ' 매매구분
        szItem(6) = MidEx(strData, nPos, 15) ' 주문수량
        szItem(7) = MidEx(strData, nPos, 12) ' 주문단가
        szItem(8) = MidEx(strData, nPos, 15) ' 체결수량
        szItem(9) = MidEx(strData, nPos, 12) ' 체결가격
        szItem(10) = MidEx(strData, nPos, 15) ' 미체결수량
        szItem(11) = MidEx한글(strData, nPos, 10) ' 주문유형
        szItem(12) = Trim(MidEx한글(strData, nPos, 9)) ' 원주문번호
        szItem(13) = Trim(MidEx한글(strData, nPos, 10)) ' 처리구분
        szItem(14) = Trim(MidEx한글(strData, nPos, 9))  ' 체결률
        szItem(15) = Trim(MidEx한글(strData, nPos, 6))  ' 주문시간
        szItem(16) = Trim(MidEx한글(strData, nPos, 9)) ' 제비용
        szItem(17) = Trim(MidEx한글(strData, nPos, 9)) ' 수수료
        szItem(18) = Trim(MidEx한글(strData, nPos, 9))  ' 세금
        szItem(19) = Trim(MidEx한글(strData, nPos, 3))  ' 신용구분
        
        DisplayMsg strData
    Next i
    
End Sub
Private Sub Parse_REQ_FUT_CHE(strData As String) '선옵체결리스트

On Error Resume Next

    Dim 레코드Count As Long
    Dim 레코드Len As String
    Dim 그리드Msg As String
    Dim 로컬필드 As String
           
    
    Dim nPos As Long, i As Long
    Dim szItem(100) As String
    
    nPos = 1
    
    로컬필드 = MidEx(strData, nPos, 100)
    레코드Count = MidEx(strData, nPos, 4)
    레코드Len = MidEx(strData, nPos, 4)
    그리드Msg = MidEx(strData, nPos, 5)
    
    For i = 1 To 레코드Count
    
        strData = Mid(strData, nPos):       nPos = 1
        
        szItem(1) = MidEx(strData, nPos, 9)  ' 주문번호
        szItem(2) = MidEx(strData, nPos, 9) ' 원주문번호
        szItem(3) = MidEx(strData, nPos, 15)  ' 종목코드
        szItem(4) = MidEx(strData, nPos, 3)  ' 주문구분속성
        szItem(5) = Trim(MidEx한글(strData, nPos, 12)) ' 주문구분
                
        szItem(6) = MidEx한글(strData, nPos, 12)  ' 주문유형
        szItem(7) = MidEx(strData, nPos, 12) ' 주문단가
        szItem(8) = MidEx(strData, nPos, 15) ' 주문수량
        szItem(9) = MidEx(strData, nPos, 12)  ' 체결가격
        szItem(10) = MidEx(strData, nPos, 15)  ' 체결수량
        szItem(11) = MidEx(strData, nPos, 15) ' 미체결수량
        szItem(12) = MidEx한글(strData, nPos, 40)  ' 거부메세지
        
        DisplayMsg strData
        
    Next i
    
End Sub

VERSION 5.00
Begin VB.Form frm잔고리스트 
   Caption         =   "잔고리스트"
   ClientHeight    =   3885
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8265
   LinkTopic       =   "Form1"
   ScaleHeight     =   3885
   ScaleWidth      =   8265
   StartUpPosition =   3  'Windows 기본값
   Begin VB.OptionButton opt주식 
      Caption         =   "주식"
      Height          =   255
      Left            =   5880
      TabIndex        =   9
      Top             =   120
      Width           =   855
   End
   Begin VB.OptionButton opt선옵 
      Caption         =   "선옵"
      Height          =   255
      Left            =   5040
      TabIndex        =   8
      Top             =   120
      Value           =   -1  'True
      Width           =   855
   End
   Begin VB.CheckBox btnXX6 
      Caption         =   "주식잔고(XX6) 실시간데이터 요청 등록 및 해제"
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
      TabIndex        =   7
      Top             =   960
      Width           =   4695
   End
   Begin VB.CheckBox btnXF3 
      Caption         =   "선옵잔고(XF3) 실시간데이터 요청 등록 및 해제"
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
      TabIndex        =   6
      Top             =   600
      Width           =   4695
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
      TabIndex        =   3
      Top             =   120
      Width           =   735
   End
   Begin VB.TextBox txtAccount 
      Height          =   270
      Left            =   960
      TabIndex        =   2
      Text            =   "Text1"
      Top             =   120
      Width           =   2055
   End
   Begin VB.CommandButton btnJango 
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
      Left            =   6840
      TabIndex        =   1
      Top             =   120
      Width           =   1215
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
      Height          =   2400
      Left            =   120
      TabIndex        =   0
      Top             =   1320
      Width           =   7935
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
      Width           =   615
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
      TabIndex        =   4
      Top             =   120
      Width           =   735
   End
End
Attribute VB_Name = "frm잔고리스트"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim WithEvents 동부API객체  As DongbuAPI
Attribute 동부API객체.VB_VarHelpID = -1

Dim m_RTDataXF3 As clsDrdsXF3   '선옵잔고
Dim m_RTDataXX6 As clsDrdsXX6  '주식잔고
Dim m_szNextKey As String

Private Sub Form_Load()
    Dim bRet As Boolean
    
      '초기화
    Set 동부API객체 = New DongbuAPI
    bRet = 동부API객체.InitCtrl(g_hDongbuApi, CLng(Me.hWnd))
    
    txtAccount.Text = g_InitAcctNo
    txtPwd.Text = g_InitAcctPwd
    
    Set m_RTDataXX6 = New clsDrdsXX6
    Set m_RTDataXF3 = New clsDrdsXF3
    
End Sub

Private Sub Form_Unload(Cancel As Integer)
    Dim bRet As Boolean
    '실시간요청 해제
    If (btnXX6.Value = vbChecked) Then
        bRet = 동부API객체.ReqRealtimeData(ID_UNADVICE_RT, R_XX6, g_szID)
    End If
    
     If (btnXF3.Value = vbChecked) Then
        bRet = 동부API객체.ReqRealtimeData(ID_UNADVICE_RT, R_XF3, g_szID)
    End If
    
    Set 동부API객체 = Nothing
    Set m_RTDataXX6 = Nothing
    Set m_RTDataXF3 = Nothing
    
End Sub

Private Sub DisplayMsg(ByVal strMsg As String)

    ListBox1.AddItem strMsg, 0
    
End Sub

Private Sub 동부API객체_ReceiveData(ByVal nReqID As Long, ByVal szMsgCode As String, ByVal szMsg As String, ByVal szData As String)
    Select Case (nReqID)
        Case REQ_FUT_JANGO
            DisplayMsg ("선옵 잔고조회 >> " + szMsg)
            Parse_REQ_FUT_JANGO (szData)
            
        Case REQ_STK_JANGO
            DisplayMsg ("주식 잔고조회 >> " + szMsg)
            Parse_REQ_STK_JANGO (szData)
    End Select
End Sub

Private Sub 동부API객체_ReceiveRTData(ByVal szName As String, ByVal szField As String, ByVal szData As String)
    DisplayMsg ("실시간데이터 수신>>" + szName + ":" + szField)
    DisplayMsg ("DATA>>" + szData)
    
    Select Case szName
    Case R_XF3                      '선옵 잔고
        Call Parse_XF3(szData)
    Case R_XX6                      '주식 잔고
        Call Parse_XX6(szData)
    End Select

End Sub

Private Sub Parse_XF3(ByVal strData As String)
    m_RTDataXF3.Init (strData)
End Sub

Private Sub Parse_XX6(ByVal strData As String)
    m_RTDataXX6.Init (strData)
End Sub

'주식 잔고조회
Private Sub Parse_REQ_STK_JANGO(strData As String)
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
    Dim 레코드갯수 As Long
    
    Dim szItem(100) As String
    Dim i As Long, nPos As Long
    
    nPos = 1
    sm_bjlen = MidEx(strData, nPos, 6)
    sm_bjdata = MidEx(strData, nPos, 5)
    
    총매입금액 = MidEx(strData, nPos, 15)
    총평가손익 = MidEx(strData, nPos, 15)
    당일매도금액 = MidEx(strData, nPos, 15)
    총평가금액 = MidEx(strData, nPos, 15)
    총수익율 = MidEx(strData, nPos, 15)
    당일실현손익 = MidEx(strData, nPos, 15)
    Next구분 = MidEx(strData, nPos, 1)
    NextKey = MidEx(strData, nPos, 50)
    
    gr_bjlen = MidEx(strData, nPos, 6)
    gr_bjdata = MidEx(strData, nPos, 5)
    
    
    레코드갯수 = CLng(Left(gr_bjlen, 4))
    
    m_szNextKey = Trim(NextKey)
    
    For i = 1 To 레코드갯수
        strData = Mid(strData, nPos):       nPos = 1
        
        szItem(1) = MidEx(strData, nPos, 6)  '종목코드
        szItem(2) = MidEx한글(strData, nPos, 20) '종목명
        szItem(3) = MidEx(strData, nPos, 15) '가용수량
        szItem(4) = MidEx(strData, nPos, 15) '평가손익
        szItem(5) = MidEx(strData, nPos, 7)  '수익율
        
        szItem(6) = MidEx(strData, nPos, 15)  '잔고금액
        szItem(7) = MidEx(strData, nPos, 15) '평가금액
        szItem(8) = MidEx(strData, nPos, 15)  '전일변동
        szItem(9) = MidEx(strData, nPos, 15)  '금일변동
        szItem(10) = MidEx(strData, nPos, 15)  '결제잔고
        
        szItem(11) = MidEx(strData, nPos, 9)  '장부단가
        szItem(12) = MidEx(strData, nPos, 9) '제비용
        szItem(13) = MidEx(strData, nPos, 9)  '주당비용
        szItem(14) = MidEx(strData, nPos, 9)  '수수료
        szItem(15) = MidEx(strData, nPos, 9) '세금
        
        szItem(16) = MidEx(strData, nPos, 7) '현재가
        szItem(17) = MidEx(strData, nPos, 7)  '전일대비
        szItem(18) = MidEx(strData, nPos, 8)  '최종매입일
        szItem(19) = MidEx(strData, nPos, 1)  '등락부호
        szItem(20) = MidEx(strData, nPos, 15)  '실현손익
        szItem(21) = MidEx(strData, nPos, 15)  '금일매도금액
        
        szItem(22) = MidEx(strData, nPos, 1) '잔고구분
        szItem(23) = MidEx(strData, nPos, 8) '대출일
        szItem(24) = MidEx(strData, nPos, 8) '만기일
        szItem(25) = MidEx(strData, nPos, 15)  '신용금액
        szItem(26) = MidEx(strData, nPos, 9)  '대출이자
        szItem(27) = MidEx(strData, nPos, 3)  '현금증거금율
        
        DisplayMsg "보유종목>>" + szItem(1) + " : " + szItem(2)
    Next i
    
End Sub

Private Sub Parse_REQ_FUT_JANGO(strData As String) '선옵 잔고조회

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
        
    Dim i As Long, nPos As Long
    Dim szItem(100) As String
    
    If Len(strData) = 0 Then
        Return
    End If
    
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
        
        szItem(1) = MidEx(strData, nPos, 15)       '종목코드
        szItem(2) = MidEx속성(strData, nPos, 3)        '매매속성
        szItem(3) = MidEx한글(strData, nPos, 5) '매매구분
        szItem(4) = MidEx(strData, nPos, 15)     '청산가능
        szItem(5) = MidEx(strData, nPos, 15)     '전일잔고
        szItem(6) = MidEx(strData, nPos, 15)        '증감
        szItem(7) = MidEx(strData, nPos, 15)     '보유수량
        szItem(8) = MidEx(strData, nPos, 15) '미체결주문수량
        szItem(9) = MidEx(strData, nPos, 12)     '매입단가
        szItem(10) = MidEx(strData, nPos, 6)        '현재가
        szItem(11) = MidEx(strData, nPos, 15)     '평가손익
        szItem(12) = MidEx(strData, nPos, 9)        '수익율
        szItem(13) = MidEx(strData, nPos, 15)     '약정금액
        szItem(14) = MidEx(strData, nPos, 15)  '평가금액
        szItem(15) = MidEx(strData, nPos, 12) '수수료
        szItem(16) = MidEx(strData, nPos, 6) '매수호가
        szItem(17) = MidEx(strData, nPos, 6)  '매도호가
        szItem(18) = MidEx(strData, nPos, 6)  '상한가
        szItem(19) = MidEx(strData, nPos, 6)  '하한가
        szItem(20) = MidEx(strData, nPos, 1) '시장소속구분
        szItem(21) = MidEx(strData, nPos, 15) '당일실현손익D
        szItem(22) = MidEx(strData, nPos, 3) '주문유형
        szItem(23) = MidEx(strData, nPos, 15) '거래단위
        szItem(24) = MidEx(strData, nPos, 15)   '당일매수또는매도금액
        szItem(25) = MidEx(strData, nPos, 15)  '매매대금합
        
        DisplayMsg "보유종목>>" + szItem(1)
                    
    Next i
    
End Sub

'잔고조회
Private Sub btnJango_Click()
    Dim szAccount As String
    Dim szData As String
    Dim nRet As Boolean
    
    szAccount = txtAccount.Text
    
    If IsEmpty(szAccount) Then
        Exit Sub
    End If
    
    If (opt선옵.Value = True) Then
        nRet = 동부API객체.ReqJango(szAccount)
    Else
        nRet = 동부API객체.ReqStockJango(szAccount, m_szNextKey)
    End If
    
    m_szNextKey = ""
    
End Sub

'선옵잔고 실시간
Private Sub btnXF3_Click()

    Dim bRet As Boolean

    If (btnXF3.Value = vbChecked) Then
        bRet = 동부API객체.ReqRealtimeData(ID_ADVICE_RT, R_XF3, g_szID)
    Else
        bRet = 동부API객체.ReqRealtimeData(ID_UNADVICE_RT, R_XF3, g_szID)
    End If

End Sub

'주식잔고 실시간
Private Sub btnXX6_Click()

    Dim bRet As Boolean

    If (btnXX6.Value = vbChecked) Then
        bRet = 동부API객체.ReqRealtimeData(ID_ADVICE_RT, R_XX6, g_szID)
    Else
        bRet = 동부API객체.ReqRealtimeData(ID_UNADVICE_RT, R_XX6, g_szID)
    End If

End Sub

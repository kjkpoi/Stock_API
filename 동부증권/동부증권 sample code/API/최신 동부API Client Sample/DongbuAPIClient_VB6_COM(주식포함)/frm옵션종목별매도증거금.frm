VERSION 5.00
Begin VB.Form frm옵션종목별매도증거금 
   Caption         =   "옵션종목별매도증거금"
   ClientHeight    =   4905
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8280
   LinkTopic       =   "Form2"
   ScaleHeight     =   4905
   ScaleWidth      =   8280
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
      Height          =   3570
      Left            =   120
      TabIndex        =   8
      Top             =   1080
      Width           =   8055
   End
   Begin VB.Frame Frame6 
      Caption         =   "옵션 종목별 매도증거금"
      BeginProperty Font 
         Name            =   "돋움체"
         Size            =   9
         Charset         =   129
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   855
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   8055
      Begin VB.CommandButton btn옵션종목별매도증거금 
         Caption         =   "조회"
         Height          =   372
         Left            =   7200
         TabIndex        =   4
         Top             =   360
         Width           =   615
      End
      Begin VB.ComboBox cmbItem 
         Height          =   300
         Left            =   720
         TabIndex        =   3
         Text            =   "Combo1"
         Top             =   360
         Width           =   1455
      End
      Begin VB.ComboBox cmbBaseAsset 
         Height          =   300
         Left            =   3240
         TabIndex        =   2
         Text            =   "Combo1"
         Top             =   360
         Width           =   1935
      End
      Begin VB.ComboBox cmbMonth 
         Height          =   300
         Left            =   5760
         TabIndex        =   1
         Text            =   "Combo1"
         Top             =   360
         Width           =   1335
      End
      Begin VB.Label Label9 
         Caption         =   "상품군"
         Height          =   255
         Left            =   120
         TabIndex        =   7
         Top             =   360
         Width           =   615
      End
      Begin VB.Label Label10 
         Caption         =   "기초자산"
         Height          =   255
         Left            =   2400
         TabIndex        =   6
         Top             =   360
         Width           =   735
      End
      Begin VB.Label Label11 
         Caption         =   "월물"
         Height          =   255
         Left            =   5280
         TabIndex        =   5
         Top             =   360
         Width           =   375
      End
   End
End
Attribute VB_Name = "frm옵션종목별매도증거금"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim WithEvents 동부API객체  As DongbuAPI
Attribute 동부API객체.VB_VarHelpID = -1
Dim m_szNextKey As String       'x(19)

Private Sub Form_Load()
    Dim bRet As Boolean
     
     '초기화
    Set 동부API객체 = New DongbuAPI
    bRet = 동부API객체.InitCtrl(g_hDongbuApi, CLng(Me.hWnd))
    
    If (bRet) Then
        Init옵션종목별매증거금
    End If
    
End Sub

Private Sub Form_Unload(Cancel As Integer)
    Set 동부API객체 = Nothing
End Sub

Private Sub DisplayMsg(ByVal strMsg As String)

    ListBox1.AddItem strMsg, 0
    
End Sub

Private Sub btn옵션종목별매도증거금_Click()
    
    Dim bRet As Long
    
    Dim sz상품군코드 As String    'x(2)
    Dim sz기초자산코드 As String  'x(3) 전체 000
    Dim sz최근월물구분 As String  'x(1)

    
    sz상품군코드 = Left(cmbItem.Text, 2)
    sz기초자산코드 = Left(cmbBaseAsset.Text, 3)
    sz최근월물구분 = Left(cmbMonth.Text, 1)
    
    bRet = 동부API객체.ReqDepositByOptionItem(sz상품군코드, sz기초자산코드, sz최근월물구분, m_szNextKey)
End Sub

Private Sub 동부API객체_ReceiveData(ByVal nReqID As Long, ByVal szMsgCode As String, ByVal szMsg As String, ByVal szData As String)
    Select Case (nReqID)
        Case REQ_FUT_DEP_OPT '옵션종목별매도증거금
            DisplayMsg ("옵션종목별매도증거금 조회 >> " + szMsg)
            Parse_REQ_FUT_DEP_OPT (szData)
    End Select
End Sub

Private Sub Parse_REQ_FUT_DEP_OPT(strData As String) '옵션종목별매도증거금

On Error Resume Next
    'TR_16260
    
    Dim 연속여부키 As String     'x(1)
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
        
    Dim nPos As Long, i As Long
    
    nPos = 1
    
    연속여부키 = MidEx(strData, nPos, 1)
    연속키 = MidEx(strData, nPos, 18)
    조회건수 = MidEx(strData, nPos, 4)
            
    If (CLng(조회건수) = 0) Then
        Exit Sub
    End If
    
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
        
        DisplayMsg strData
    Next i
    
End Sub


Private Sub cmbItem_Click()
    cmbBaseAsset.Clear
    
    If (cmbItem.Text = "00전체") Then
        cmbBaseAsset.AddItem "000전체"
    ElseIf (cmbItem.Text = "01주가지수") Then
        cmbBaseAsset.AddItem "000전체"
        cmbBaseAsset.AddItem "501KOSPI200"
        cmbBaseAsset.AddItem "503STAR30"
    Else
        cmbBaseAsset.AddItem "000전체"
        cmbBaseAsset.AddItem "510국민은행"
        cmbBaseAsset.AddItem "511삼성전자"
        cmbBaseAsset.AddItem "512SK텔레콤"
        cmbBaseAsset.AddItem "513포항제철"
        cmbBaseAsset.AddItem "514KT"
        cmbBaseAsset.AddItem "515한국전력공사"
        cmbBaseAsset.AddItem "516현대자동차"
        cmbBaseAsset.AddItem "517삼성증권"
        cmbBaseAsset.AddItem "518신한지주"
        cmbBaseAsset.AddItem "519기아차"
        cmbBaseAsset.AddItem "520현대모비스"
        cmbBaseAsset.AddItem "521삼성물산"
        cmbBaseAsset.AddItem "522삼성SDI"
        cmbBaseAsset.AddItem "523삼성전기"
        cmbBaseAsset.AddItem "524LG전자"
        cmbBaseAsset.AddItem "525LG화학"
        cmbBaseAsset.AddItem "526대한항공"
        cmbBaseAsset.AddItem "527한진해운"
        cmbBaseAsset.AddItem "528한국가스"
        cmbBaseAsset.AddItem "529강원랜드"
        cmbBaseAsset.AddItem "530삼성화재"
        cmbBaseAsset.AddItem "531CJ"
        cmbBaseAsset.AddItem "532INI스틸"
        cmbBaseAsset.AddItem "533SK"
        cmbBaseAsset.AddItem "534LG"
        cmbBaseAsset.AddItem "535GS"
        cmbBaseAsset.AddItem "536케이티엔지"
        cmbBaseAsset.AddItem "538한국타이어"
        cmbBaseAsset.AddItem "539현대중공업"
        cmbBaseAsset.AddItem "540하나금융지주"
    End If
    
    cmbBaseAsset.Text = "000전체"
End Sub

Private Sub Init옵션종목별매증거금()
    '상품군
    cmbItem.AddItem "00전체"
    cmbItem.AddItem "01주가지수"
    cmbItem.AddItem "02개별주식"
    cmbItem.AddItem "03가공채권"
    cmbItem.AddItem "04통화"
    cmbItem.AddItem "05상품"
    cmbItem.AddItem "06금리"
    
    cmbItem.Text = "00전체"
    
    '기초자산
    cmbBaseAsset.Text = "000전체"
    
    '조회월물
    cmbMonth.AddItem "0전체    "
    cmbMonth.AddItem "1(1월물) "
    cmbMonth.AddItem "2(2월물) "
    cmbMonth.AddItem "3(3월물) "
    cmbMonth.AddItem "4(4월물) "
    cmbMonth.AddItem "5(5월물) "
    cmbMonth.AddItem "6(6월물) "
    cmbMonth.AddItem "7(7월물) "
    cmbMonth.AddItem "8(8월물) "
    cmbMonth.AddItem "9(9월물) "
    cmbMonth.AddItem "A(10월물)"
    cmbMonth.AddItem "B(11월물)"
    cmbMonth.AddItem "C(12월물)"
    cmbMonth.Text = "0전체"

End Sub


VERSION 5.00
Begin VB.Form frm���� 
   Caption         =   "����API VB6.0 Sample(OCX)"
   ClientHeight    =   7440
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   8280
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
   ScaleHeight     =   7440
   ScaleWidth      =   8280
   StartUpPosition =   3  'Windows �⺻��
   Begin VB.Frame Frame3 
      Caption         =   "�ɼ� �ǽð� ������ ��û ��� �� ����  ����"
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
         Left            =   5280
         TabIndex        =   36
         Top             =   360
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
         Caption         =   "�����ڵ�"
         Height          =   255
         Left            =   360
         TabIndex        =   38
         Top             =   360
         Width           =   1095
      End
   End
   Begin VB.Frame Frame2 
      Caption         =   "���� ȭ��(����,�ֽ�)"
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
         Caption         =   "����Ȳ / �򰡿�Ź�Ѿ�,������,�ֹ����ɱݾ�"
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
         Left            =   240
         TabIndex        =   32
         Top             =   1320
         Width           =   4335
      End
      Begin VB.CommandButton btnJango 
         Caption         =   "�ܰ���(����,�ֽ�)"
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
         Left            =   2880
         TabIndex        =   31
         Top             =   840
         Width           =   2535
      End
      Begin VB.CommandButton btnCheguyl 
         Caption         =   "ü�᳻��(����,�ֽ�)"
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
         Left            =   240
         TabIndex        =   30
         Top             =   840
         Width           =   2535
      End
      Begin VB.CommandButton btn�ɼ����񺰸ŵ����ű� 
         Caption         =   "�ɼ� ���� �ŵ����ű�"
         Height          =   372
         Left            =   4680
         TabIndex        =   29
         Top             =   1320
         Width           =   2535
      End
      Begin VB.CommandButton btnAbleQty 
         Caption         =   "�ű�/û�� ���ɼ���(����)"
         Height          =   375
         Left            =   2880
         TabIndex        =   28
         Top             =   360
         Width           =   2535
      End
      Begin VB.CommandButton btnOrder 
         Caption         =   "�ֹ�(����,�ֽ�)"
         Height          =   375
         Left            =   240
         TabIndex        =   27
         Top             =   360
         Width           =   2535
      End
   End
   Begin VB.Frame Frame5 
      Caption         =   "������ȸ ����"
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
         TabIndex        =   24
         Top             =   240
         Width           =   1455
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
         TabIndex        =   19
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
         TabIndex        =   18
         Top             =   240
         Width           =   735
      End
   End
   Begin VB.Frame Frame4 
      Caption         =   "����API �α���"
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
         Left            =   3480
         TabIndex        =   23
         Top             =   600
         Width           =   1095
      End
      Begin VB.TextBox edtLoginName 
         Enabled         =   0   'False
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
         TabIndex        =   21
         Text            =   "Text1"
         Top             =   960
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
         Left            =   3480
         TabIndex        =   20
         Top             =   240
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
         Caption         =   "�α���"
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
         Caption         =   "�α׾ƿ�"
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
         TabIndex        =   13
         Top             =   960
         Width           =   1335
      End
      Begin VB.Label Label4 
         Caption         =   "Name"
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
         Left            =   3720
         TabIndex        =   22
         Top             =   960
         Width           =   495
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
         TabIndex        =   16
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
         TabIndex        =   15
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
         TabIndex        =   14
         Top             =   1080
         Width           =   1215
      End
   End
   Begin VB.CommandButton btnClearAll 
      Caption         =   "��������"
      BeginProperty Font 
         Name            =   "���� ���"
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
      Caption         =   "���� �ǽð� ������ ��û ��� �� ����  ����"
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
         Left            =   3600
         TabIndex        =   8
         Top             =   360
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
         Left            =   5280
         TabIndex        =   9
         Top             =   360
         Width           =   1572
      End
      Begin VB.Label Label5 
         Caption         =   "�����ڵ�"
         Height          =   255
         Left            =   360
         TabIndex        =   37
         Top             =   360
         Width           =   1095
      End
   End
End
Attribute VB_Name = "frm����"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim WithEvents ����API��ü  As DongbuAPI
Attribute ����API��ü.VB_VarHelpID = -1

Dim m_RTDataSC0 As clsDrdsSC0
Dim m_RTDataSH0 As clsDrdsSH0
Dim m_RTDataOC0 As clsDrdsOC0
Dim m_RTDataOH0 As clsDrdsOH0

Dim m_frm�ɼ����񺰸ŵ����ű� As frm�ɼ����񺰸ŵ����ű�
Dim m_frm�ֹ� As frm�ֹ�
Dim m_frmü�Ḯ��Ʈ As frmü�Ḯ��Ʈ
Dim m_frm�ܰ���Ʈ As frm�ܰ���Ʈ
Dim m_frm����Ȳ As frm����Ȳ

Private Sub ����API��ü_Connected(ByVal hDongbuApi As Long)
    Dim szAcctList As String
    Dim bRet As Boolean
    
    DisplayMsg ("����API ���� ����...")
    
    '���¸���Ʈ ���ϱ�
    szAcctList = ����API��ü.GetAccountList(1)  '����1, �ֽ� 2
    GetFutureAccList False, szAcctList, Len(szAcctList)
    
    g_hDongbuApi = hDongbuApi
    g_szID = Trim(edtID.Text)
    
    
     Set m_frm�ɼ����񺰸ŵ����ű� = New frm�ɼ����񺰸ŵ����ű�
     Set m_frm�ܰ���Ʈ = New frm�ܰ���Ʈ
     Set m_frmü�Ḯ��Ʈ = New frmü�Ḯ��Ʈ
     Set m_frm����Ȳ = New frm����Ȳ
     Set m_frm�ֹ� = New frm�ֹ�
     
     EnableControls (True)
End Sub

'DRCM���� ����Ǿ��ٴ� �޽����� �޾Ƽ� ó��
Private Sub ����API��ü_Disconnected()
      g_hDongbuApi = 0
    g_szID = ""
    
    DisplayMsg ("����API �����")
    EnableControls (False)
    
    Unload m_frm�ɼ����񺰸ŵ����ű�
    Unload m_frm�ܰ���Ʈ
    Unload m_frmü�Ḯ��Ʈ
    Unload m_frm����Ȳ
    Unload m_frm�ֹ�
End Sub

Private Sub chkMultiConn_Click()
    If (chkMultiConn.Value = vbChecked) Then
        edtLoginName.Enabled = True
    Else
        edtLoginName.Enabled = False
    End If
    
End Sub

Private Sub Form_Load()

    Set ����API��ü = New DongbuAPI
    
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
      
    ����API��ü.Logout
    
    Set ����API��ü = Nothing
    
    Set m_RTDataSC0 = Nothing
    Set m_RTDataSH0 = Nothing
    Set m_RTDataOC0 = Nothing
    Set m_RTDataOH0 = Nothing
    
End Sub


Private Sub ����API��ü_ReceiveData(ByVal nReqID As Long, ByVal szMsgCode As String, ByVal szMsg As String, ByVal szData As String)
        Select Case (nReqID)
        Case REQ_FUT_ORDER
        Case REQ_FUT_JANGO
        Case REQ_FUT_JANGO2
        Case REQ_FUT_CHE
        Case REQ_FUT_EVAL
        Case REQ_FUT_FEE             '������/�ֹ����ɱݾ�/��Ź�Ѿ�
        Case REQ_FUT_DEP_OPT      '�ɼ����񺰸ŵ����ű�
        Case REQ_FUT_ORDER_QTY  '�ű�/û�� ���ɼ���
        Case REQ_STK_ORDER
        Case REQ_STK_JANGO
        Case REQ_STK_CHE
        Case REQ_STK_EVAL
        End Select
End Sub

Private Sub ����API��ü_ReceiveRTData(ByVal szName As String, ByVal szField As String, ByVal szData As String)

    DisplayMsg ("�ǽð������� ����>>" + szName + ":" + szField)
    DisplayMsg ("DATA>>" + szData)
    
    Select Case szName
    
    Case R_SC0                        ' ���� ���簡
        Call Parse_SC0(szData)
    Case R_SH0                        ' ���� ȣ��
        Parse_SH0 (szData)
    Case R_OC0                       ' �ɼ� ���簡
        Call Parse_OC0(szData)
    Case R_OH0                      ' �ɼ� ȣ��
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
    szAcctList = ����API��ü.GetAccountList(1)  '����1, �ֽ� 2
    GetFutureAccList False, szAcctList, Len(szAcctList)
End Sub

Private Sub btnStockAcctList_Click()
    Dim szAcctList As String
    szAcctList = ����API��ü.GetAccountList(2)  '����1, �ֽ� 2
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

Private Sub btnClearAll_Click()
    ListBox1.Clear

End Sub

'����API�� ���������Ѵٰ� �޽��� ������
Private Sub btnDisconnect_Click()
    ����API��ü.Logout
End Sub

'��������
Private Sub btnConnect_Click()
    Dim lShowLoginDlg As Long
    Dim lMultiConn As Long
    Dim bReturn As Boolean
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
    
    '����API ��Ʈ�� ����
    bReturn = ����API��ü.CreateDongbuAPICtrl(edtLoginName.Text, lMultiConn, CLng(Me.hWnd))
    
    '����API�α���
    If (bReturn) Then
        bReturn = ����API��ü.Login(edtID.Text, edtPwd.Text, edtCertPwd.Text, lShowLoginDlg)
    End If
        
    If (bReturn = False) Then
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
    
    btnFee.Enabled = bEnabled
    btnAcctList.Enabled = bEnabled
    
    
    btn�ɼ����񺰸ŵ����ű�.Enabled = bEnabled
    
    btnStockAcctList.Enabled = bEnabled
    btnAbleQty.Enabled = bEnabled
    
    
End Sub

Private Sub btnOC0_Click()

    Dim szData As String
    Dim bRet As Boolean

    szData = txtOptionCodes.Text

    If (btnOC0.Value = vbChecked) Then
        bRet = ����API��ü.ReqRealtimeData(ID_ADVICE_RT, R_OC0, szData)
    Else
        bRet = ����API��ü.ReqRealtimeData(ID_UNADVICE_RT, R_OC0, szData)
    End If

End Sub

Private Sub btnOH0_Click()
    Dim szData As String
    Dim bRet As Boolean

    szData = txtOptionCodes.Text

    If (btnOH0.Value = vbChecked) Then
        bRet = ����API��ü.ReqRealtimeData(ID_ADVICE_RT, R_OH0, szData)
    Else
        bRet = ����API��ü.ReqRealtimeData(ID_UNADVICE_RT, R_OH0, szData)
    End If

End Sub

Private Sub btnSC0_Click()

    Dim szData As String
    Dim bRet As Boolean

    szData = txtFutureCodes.Text

    If (btnSC0.Value = vbChecked) Then
        bRet = ����API��ü.ReqRealtimeData(ID_ADVICE_RT, R_SC0, szData)
    Else
        bRet = ����API��ü.ReqRealtimeData(ID_UNADVICE_RT, R_SC0, szData)
    End If
End Sub

Private Sub btnSH0_Click()
    Dim szData As String
    Dim bRet As Boolean

    szData = txtFutureCodes.Text

    If (btnSH0.Value = vbChecked) Then
        bRet = ����API��ü.ReqRealtimeData(ID_ADVICE_RT, R_SH0, szData)
    Else
        bRet = ����API��ü.ReqRealtimeData(ID_UNADVICE_RT, R_SH0, szData)
    End If

End Sub

'�ɼ����񺰸ŵ����ű� 1600
Private Sub btn�ɼ����񺰸ŵ����ű�_Click()
        
    m_frm�ɼ����񺰸ŵ����ű�.Show
End Sub

'���� �ű�/û�� ���ɼ���
Private Sub btnAbleQty_Click()
    m_frm�ֹ�.Show
End Sub

'�ֹ�
Private Sub btnOrder_Click()
    m_frm�ֹ�.Show
End Sub

'�ܰ���Ʈ
Private Sub btnJango_Click()
    m_frm�ܰ���Ʈ.Show
End Sub

'ü�᳻��
Private Sub btnCheguyl_Click()
    m_frmü�Ḯ��Ʈ.Show
End Sub

'����Ȳ ��ȸ/������/�ֹ����ɱݾ�/�򰡿�Ź�Ѿ�
Private Sub btnFee_Click()
    m_frm����Ȳ.Show
End Sub


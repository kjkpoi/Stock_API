VERSION 5.00
Begin VB.Form frm�ɼ����񺰸ŵ����ű� 
   Caption         =   "�ɼ����񺰸ŵ����ű�"
   ClientHeight    =   4905
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8280
   LinkTopic       =   "Form2"
   ScaleHeight     =   4905
   ScaleWidth      =   8280
   StartUpPosition =   3  'Windows �⺻��
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
      Caption         =   "�ɼ� ���� �ŵ����ű�"
      BeginProperty Font 
         Name            =   "����ü"
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
      Begin VB.CommandButton btn�ɼ����񺰸ŵ����ű� 
         Caption         =   "��ȸ"
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
         Caption         =   "��ǰ��"
         Height          =   255
         Left            =   120
         TabIndex        =   7
         Top             =   360
         Width           =   615
      End
      Begin VB.Label Label10 
         Caption         =   "�����ڻ�"
         Height          =   255
         Left            =   2400
         TabIndex        =   6
         Top             =   360
         Width           =   735
      End
      Begin VB.Label Label11 
         Caption         =   "����"
         Height          =   255
         Left            =   5280
         TabIndex        =   5
         Top             =   360
         Width           =   375
      End
   End
End
Attribute VB_Name = "frm�ɼ����񺰸ŵ����ű�"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim WithEvents ����API��ü  As DongbuAPI
Attribute ����API��ü.VB_VarHelpID = -1
Dim m_szNextKey As String       'x(19)

Private Sub Form_Load()
    Dim bRet As Boolean
     
     '�ʱ�ȭ
    Set ����API��ü = New DongbuAPI
    bRet = ����API��ü.InitCtrl(g_hDongbuApi, CLng(Me.hWnd))
    
    If (bRet) Then
        Init�ɼ����񺰸����ű�
    End If
    
End Sub

Private Sub Form_Unload(Cancel As Integer)
    Set ����API��ü = Nothing
End Sub

Private Sub DisplayMsg(ByVal strMsg As String)

    ListBox1.AddItem strMsg, 0
    
End Sub

Private Sub btn�ɼ����񺰸ŵ����ű�_Click()
    
    Dim bRet As Long
    
    Dim sz��ǰ���ڵ� As String    'x(2)
    Dim sz�����ڻ��ڵ� As String  'x(3) ��ü 000
    Dim sz�ֱٿ������� As String  'x(1)

    
    sz��ǰ���ڵ� = Left(cmbItem.Text, 2)
    sz�����ڻ��ڵ� = Left(cmbBaseAsset.Text, 3)
    sz�ֱٿ������� = Left(cmbMonth.Text, 1)
    
    bRet = ����API��ü.ReqDepositByOptionItem(sz��ǰ���ڵ�, sz�����ڻ��ڵ�, sz�ֱٿ�������, m_szNextKey)
End Sub

Private Sub ����API��ü_ReceiveData(ByVal nReqID As Long, ByVal szMsgCode As String, ByVal szMsg As String, ByVal szData As String)
    Select Case (nReqID)
        Case REQ_FUT_DEP_OPT '�ɼ����񺰸ŵ����ű�
            DisplayMsg ("�ɼ����񺰸ŵ����ű� ��ȸ >> " + szMsg)
            Parse_REQ_FUT_DEP_OPT (szData)
    End Select
End Sub

Private Sub Parse_REQ_FUT_DEP_OPT(strData As String) '�ɼ����񺰸ŵ����ű�

On Error Resume Next
    'TR_16260
    
    Dim ���ӿ���Ű As String     'x(1)
    Dim ����Ű As String        'x(18)
    Dim ��ȸ�Ǽ� As String      'x(5)
    
    Dim ��簡 As String                    'x(13)
    Dim C�����ɼǰ��������ȣ As String     'x(32)
    Dim C���и� As String                   'x(40) �ѱ�
    Dim C�̷а� As String                   'x(19)
    Dim C���ذ� As String                   'x(13)
    Dim C�ֹ����űݾ� As String             'x(16)
    
    Dim P�����ɼǰ��������ȣ As String     'x(32)
    Dim P���и� As String                   'x(40) �ѱ�
    Dim P�̷а� As String                   'x(19)
    Dim P���ذ� As String                   'x(13)
    Dim P�ֹ����űݾ� As String             'x(16)
        
    Dim nPos As Long, i As Long
    
    nPos = 1
    
    ���ӿ���Ű = MidEx(strData, nPos, 1)
    ����Ű = MidEx(strData, nPos, 18)
    ��ȸ�Ǽ� = MidEx(strData, nPos, 4)
            
    If (CLng(��ȸ�Ǽ�) = 0) Then
        Exit Sub
    End If
    
    For i = 1 To ��ȸ�Ǽ�
        strData = Mid(strData, nPos): nPos = 1
        
        ��簡 = MidEx(strData, nPos, 13)
        ��簡 = Replace(��簡, "+", "")
        
        C�����ɼǰ��������ȣ = MidEx(strData, nPos, 32)
        C���и� = MidEx�ѱ�(strData, nPos, 40)
        C�̷а� = MidEx(strData, nPos, 19)
        C���ذ� = MidEx(strData, nPos, 13)
        C�ֹ����űݾ� = MidEx(strData, nPos, 16)
        
        P�����ɼǰ��������ȣ = MidEx(strData, nPos, 32)
        P���и� = MidEx�ѱ�(strData, nPos, 40)
        P�̷а� = MidEx(strData, nPos, 19)
        C���ذ� = MidEx(strData, nPos, 13)
        C�ֹ����űݾ� = MidEx(strData, nPos, 16)
        
        DisplayMsg strData
    Next i
    
End Sub


Private Sub cmbItem_Click()
    cmbBaseAsset.Clear
    
    If (cmbItem.Text = "00��ü") Then
        cmbBaseAsset.AddItem "000��ü"
    ElseIf (cmbItem.Text = "01�ְ�����") Then
        cmbBaseAsset.AddItem "000��ü"
        cmbBaseAsset.AddItem "501KOSPI200"
        cmbBaseAsset.AddItem "503STAR30"
    Else
        cmbBaseAsset.AddItem "000��ü"
        cmbBaseAsset.AddItem "510��������"
        cmbBaseAsset.AddItem "511�Ｚ����"
        cmbBaseAsset.AddItem "512SK�ڷ���"
        cmbBaseAsset.AddItem "513������ö"
        cmbBaseAsset.AddItem "514KT"
        cmbBaseAsset.AddItem "515�ѱ����°���"
        cmbBaseAsset.AddItem "516�����ڵ���"
        cmbBaseAsset.AddItem "517�Ｚ����"
        cmbBaseAsset.AddItem "518��������"
        cmbBaseAsset.AddItem "519�����"
        cmbBaseAsset.AddItem "520������"
        cmbBaseAsset.AddItem "521�Ｚ����"
        cmbBaseAsset.AddItem "522�ＺSDI"
        cmbBaseAsset.AddItem "523�Ｚ����"
        cmbBaseAsset.AddItem "524LG����"
        cmbBaseAsset.AddItem "525LGȭ��"
        cmbBaseAsset.AddItem "526�����װ�"
        cmbBaseAsset.AddItem "527�����ؿ�"
        cmbBaseAsset.AddItem "528�ѱ�����"
        cmbBaseAsset.AddItem "529��������"
        cmbBaseAsset.AddItem "530�Ｚȭ��"
        cmbBaseAsset.AddItem "531CJ"
        cmbBaseAsset.AddItem "532INI��ƿ"
        cmbBaseAsset.AddItem "533SK"
        cmbBaseAsset.AddItem "534LG"
        cmbBaseAsset.AddItem "535GS"
        cmbBaseAsset.AddItem "536����Ƽ����"
        cmbBaseAsset.AddItem "538�ѱ�Ÿ�̾�"
        cmbBaseAsset.AddItem "539�����߰���"
        cmbBaseAsset.AddItem "540�ϳ���������"
    End If
    
    cmbBaseAsset.Text = "000��ü"
End Sub

Private Sub Init�ɼ����񺰸����ű�()
    '��ǰ��
    cmbItem.AddItem "00��ü"
    cmbItem.AddItem "01�ְ�����"
    cmbItem.AddItem "02�����ֽ�"
    cmbItem.AddItem "03����ä��"
    cmbItem.AddItem "04��ȭ"
    cmbItem.AddItem "05��ǰ"
    cmbItem.AddItem "06�ݸ�"
    
    cmbItem.Text = "00��ü"
    
    '�����ڻ�
    cmbBaseAsset.Text = "000��ü"
    
    '��ȸ����
    cmbMonth.AddItem "0��ü    "
    cmbMonth.AddItem "1(1����) "
    cmbMonth.AddItem "2(2����) "
    cmbMonth.AddItem "3(3����) "
    cmbMonth.AddItem "4(4����) "
    cmbMonth.AddItem "5(5����) "
    cmbMonth.AddItem "6(6����) "
    cmbMonth.AddItem "7(7����) "
    cmbMonth.AddItem "8(8����) "
    cmbMonth.AddItem "9(9����) "
    cmbMonth.AddItem "A(10����)"
    cmbMonth.AddItem "B(11����)"
    cmbMonth.AddItem "C(12����)"
    cmbMonth.Text = "0��ü"

End Sub


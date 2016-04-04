VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsDrdsXX1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit
'clsDrdsXX1
'***** 주식 주문체결 Real (XX1) *********************************/
'*******************************************************************/

Public userid As String
Public 지점번호 As String
Public 계좌번호 As String
Public 주문번호 As String
Public 종목명 As String
Public 원주문번호 As String
Public 종목코드 As String
Public 주문구분 As String
Public 매매구분 As String
Public 신용구분 As String
Public 통신구분 As String
Public 예약구분 As String
Public 메세지코드 As String
Public 주문수량 As String
Public 주문단가 As String
Public 체결수량 As String
Public 체결단가 As String
Public 미체결수량 As String
Public 체결금액 As String
Public termid As String
Public 계좌명 As String
Public 원주문체결수량 As String
Public 원주문체결단가 As String
Public 대출일 As String


Public Sub Init(strData As String)
    Dim nPos As Long
    nPos = 1
    userid = MidEx(strData, nPos, 20)
    지점번호 = MidEx(strData, nPos, 3)
    계좌번호 = MidEx(strData, nPos, 17)
    주문번호 = MidEx(strData, nPos, 9)
    종목명 = MidEx(strData, nPos, 20)
    원주문번호 = MidEx(strData, nPos, 9)
    종목코드 = MidEx(strData, nPos, 12)
    주문구분 = MidEx(strData, nPos, 3)
    매매구분 = MidEx(strData, nPos, 2)
    
    신용구분 = MidEx(strData, nPos, 3)
    통신구분 = MidEx(strData, nPos, 2)
    예약구분 = MidEx(strData, nPos, 1)
    메세지코드 = MidEx(strData, nPos, 4)
    
    주문수량 = MidEx(strData, nPos, 15)
    주문단가 = MidEx(strData, nPos, 9)
    체결수량 = MidEx(strData, nPos, 15)
    체결단가 = MidEx(strData, nPos, 9)
        
    미체결수량 = MidEx(strData, nPos, 15)
    체결금액 = MidEx(strData, nPos, 15)
    termid = MidEx(strData, nPos, 3)
    계좌명 = MidEx(strData, nPos, 12)
    원주문체결수량 = MidEx(strData, nPos, 15)
    원주문체결단가 = MidEx(strData, nPos, 9)
    대출일 = MidEx(strData, nPos, 8)
End Sub




VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsDrdsXF2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit
'clsDrdsXF2
'***** 선물옵션주문체결 Real (XF2) *********************************/
'***** SVR : 선물옵션주문체결 Real(HTS)  ***************************/
'*******************************************************************/

Public userid As String
Public 지점번호 As String
Public 계좌번호 As String
Public 주문번호 As String
Public 종목명 As String         '(미사용)
Public 원주문번호 As String
Public 종목코드 As String
Public 주문구분 As String
Public 매매구분 As String
Public 호가주문부호 As String         '(미사용)
Public 주문수탁방법 As String
Public 예약구분 As String         '(지점:0)
Public 메세지코드 As String         '(최종부적격사유)
Public 주문수량 As String
Public 주문단가 As String
Public 체결수량 As String
Public 누적체결수량 As String
Public 체결단가 As String
Public 최근월물약정가new As String
Public 차근월물약정가new As String
Public 미체결수량 As String
Public 체결금액 As String
Public termid As String
Public 계좌명 As String         '(미사용)
Public 거부코드 As String
Public 거부사유 As String

Public Sub Init(strData As String)
    Dim nPos As Long

    nPos = 1
    
    userid = MidEx(strData, nPos, 20)
    지점번호 = MidEx(strData, nPos, 3)
    계좌번호 = MidEx(strData, nPos, 17)
    주문번호 = MidEx(strData, nPos, 9)
    종목명 = MidEx(strData, nPos, 20)
    원주문번호 = MidEx(strData, nPos, 9)
    종목코드 = MidEx(strData, nPos, 15)
    주문구분 = MidEx(strData, nPos, 3)
    매매구분 = MidEx(strData, nPos, 2)
    호가주문부호 = MidEx(strData, nPos, 2)
    주문수탁방법 = MidEx(strData, nPos, 2)
    예약구분 = MidEx(strData, nPos, 1)
    메세지코드 = MidEx(strData, nPos, 4)
    주문수량 = MidEx(strData, nPos, 15)
    주문단가 = MidEx(strData, nPos, 12)
    체결수량 = MidEx(strData, nPos, 15)
    누적체결수량 = MidEx(strData, nPos, 15)
    체결단가 = MidEx(strData, nPos, 12)
    최근월물약정가new = MidEx(strData, nPos, 12)
    차근월물약정가new = MidEx(strData, nPos, 12)
    미체결수량 = MidEx(strData, nPos, 15)
    체결금액 = MidEx(strData, nPos, 15)
    termid = MidEx(strData, nPos, 2)
    계좌명 = MidEx(strData, nPos, 12)
    거부코드 = MidEx(strData, nPos, 3)
    거부사유 = Mid(strData, nPos)
End Sub



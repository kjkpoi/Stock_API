VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsDrdsXX2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit
'clsDrdsXX1
'***** 주식 주문잔고 Real (XX6) *********************************/
'*******************************************************************/

Public userid As String
Public 지점번호 As String
Public 계좌번호 As String
Public 종목코드 As String
Public 종목명 As String
Public 금일매수금액 As String
Public 금일매도금액 As String
Public 금일매도정산금액  As String
Public 장부수량 As String
Public 장부단가 As String
Public 평가금액 As String
Public 평가손익 As String
Public 당일변동수량 As String
Public 현재가  As String
Public 매수호가 As String
Public 매도호가 As String
Public 상한가 As String
Public 하한가 As String
Public 시장소속구분  As String
Public 당일실현손익  As String
Public 제비용 As String
Public 수익율 As String
Public 매도가능수량 As String

Public Sub Init(strData As String)
    Dim nPos As Long
    nPos = 1
    userid = MidEx(strData, nPos, 20)
    지점번호 = MidEx(strData, nPos, 3)
    계좌번호 = MidEx(strData, nPos, 17)
    종목코드 = MidEx(strData, nPos, 12)
    종목명 = MidEx(strData, nPos, 14)
    
    금일매수금액 = MidEx(strData, nPos, 15)
    금일매도금액 = MidEx(strData, nPos, 15)
    금일매도정산금액 = MidEx(strData, nPos, 15)
    장부수량 = MidEx(strData, nPos, 15)
    장부단가 = MidEx(strData, nPos, 15)
    평가금액 = MidEx(strData, nPos, 15)
    평가손익 = MidEx(strData, nPos, 15)
    당일변동수량 = MidEx(strData, nPos, 15)
    
    현재가 = MidEx(strData, nPos, 7)
    매수호가 = MidEx(strData, nPos, 7)
    매도호가 = MidEx(strData, nPos, 7)
    상한가 = MidEx(strData, nPos, 7)
    하한가 = MidEx(strData, nPos, 7)
    
    시장소속구분 = MidEx(strData, nPos, 1)
    당일실현손익 = MidEx(strData, nPos, 15)
    제비용 = MidEx(strData, nPos, 9)
    수익율 = MidEx(strData, nPos, 7)
    매도가능수량 = MidEx(strData, nPos, 15)
    
End Sub



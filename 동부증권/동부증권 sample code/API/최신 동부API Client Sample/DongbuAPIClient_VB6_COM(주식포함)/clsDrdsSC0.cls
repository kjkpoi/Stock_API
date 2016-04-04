VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsDrdsSC0"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit
'clsDrdsSC0
'**** 선물 현재가 (SC0) *******************************************/
'**** SVR : 선물 체결, 장운용, 기세           *********************/
'******************************************************************/

Public 종목코드 As String
Public 종목SEQ As String
Public 시간 As String
Public 현재가 As String
Public 시가 As String
Public 고가 As String
Public 저가 As String
Public 누적체결수량 As String
Public 누적매수체결량 As String
Public 누적거래대금 As String         '(천원->백만원)
Public 전일대비부호 As String
Public 전일대비 As String
Public 등락율 As String
Public 체결수량 As String
Public 매도호가1 As String
Public 매수호가1 As String
Public 매도잔량1 As String
Public 매수잔량1 As String
Public 매도호가2 As String
Public 매수호가2 As String
Public 매도잔량2 As String
Public 매수잔량2 As String
Public 매도호가3 As String         '(3)v9(2)
Public 매수호가3 As String         '(3)v9(2)
Public 매도잔량3 As String
Public 매수잔량3 As String
Public 총매도호가잔량 As String
Public 총매수호가잔량 As String
Public 매도호가4 As String
Public 매수호가4 As String
Public 매도잔량4 As String
Public 매수잔량4 As String
Public 매도호가5 As String
Public 매수호가5 As String
Public 매도잔량5 As String
Public 매수잔량5 As String
Public 매도건수1 As String
Public 매도건수2 As String
Public 매도건수3 As String
Public 매도건수4 As String
Public 매도건수5 As String
Public 총매도건수 As String
Public 매수건수1 As String
Public 매수건수2 As String
Public 매수건수3 As String
Public 매수건수4 As String
Public 매수건수5 As String
Public 총매수건수 As String
Public 이론가 As String
Public 미결제약정수량 As String
Public 미결제약정수량대비 As String
Public 괴리율 As String
Public 시장베이시스 As String
Public 시가대비 As String
Public 고가대비 As String
Public 저가대비 As String
Public 매도호가건수대비1 As String
Public 매도호가건수대비2 As String
Public 매도호가건수대비3 As String
Public 매도호가건수대비4 As String
Public 매도호가건수대비5 As String
Public 매수호가건수대비1 As String
Public 매수호가건수대비2 As String
Public 매수호가건수대비3 As String
Public 매수호가건수대비4 As String
Public 매수호가건수대비5 As String
Public kospi200 As String
Public 호가총잔량차이 As String
Public 이론베이시스 As String
Public 거래량증감 As String
Public 거래대금증감 As String

Public Sub Init(strData As String)
    Dim nPos As Long

    nPos = 1

    종목코드 = MidEx(strData, nPos, 8)
    종목SEQ = MidEx(strData, nPos, 2)
    시간 = MidEx(strData, nPos, 6)
    현재가 = MidEx(strData, nPos, 7)
    시가 = MidEx(strData, nPos, 7)
    고가 = MidEx(strData, nPos, 7)
    저가 = MidEx(strData, nPos, 7)
    누적체결수량 = MidEx(strData, nPos, 7)
    누적매수체결량 = MidEx(strData, nPos, 7)
    누적거래대금 = MidEx(strData, nPos, 11)
    전일대비부호 = MidEx(strData, nPos, 1)
    전일대비 = MidEx(strData, nPos, 7)
    등락율 = MidEx(strData, nPos, 7)
    체결수량 = MidEx(strData, nPos, 6)
    매도호가1 = MidEx(strData, nPos, 7)
    매수호가1 = MidEx(strData, nPos, 7)
    매도잔량1 = MidEx(strData, nPos, 6)
    매수잔량1 = MidEx(strData, nPos, 6)
    매도호가2 = MidEx(strData, nPos, 7)
    매수호가2 = MidEx(strData, nPos, 7)
    매도잔량2 = MidEx(strData, nPos, 6)
    매수잔량2 = MidEx(strData, nPos, 6)
    매도호가3 = MidEx(strData, nPos, 7)
    매수호가3 = MidEx(strData, nPos, 7)
    매도잔량3 = MidEx(strData, nPos, 6)
    매수잔량3 = MidEx(strData, nPos, 6)
    총매도호가잔량 = MidEx(strData, nPos, 6)
    총매수호가잔량 = MidEx(strData, nPos, 6)
    매도호가4 = MidEx(strData, nPos, 7)
    매수호가4 = MidEx(strData, nPos, 7)
    매도잔량4 = MidEx(strData, nPos, 6)
    매수잔량4 = MidEx(strData, nPos, 6)
    매도호가5 = MidEx(strData, nPos, 7)
    매수호가5 = MidEx(strData, nPos, 7)
    매도잔량5 = MidEx(strData, nPos, 6)
    매수잔량5 = MidEx(strData, nPos, 6)
    매도건수1 = MidEx(strData, nPos, 4)
    매도건수2 = MidEx(strData, nPos, 4)
    매도건수3 = MidEx(strData, nPos, 4)
    매도건수4 = MidEx(strData, nPos, 4)
    매도건수5 = MidEx(strData, nPos, 4)
    총매도건수 = MidEx(strData, nPos, 5)
    매수건수1 = MidEx(strData, nPos, 4)
    매수건수2 = MidEx(strData, nPos, 4)
    매수건수3 = MidEx(strData, nPos, 4)
    매수건수4 = MidEx(strData, nPos, 4)
    매수건수5 = MidEx(strData, nPos, 4)
    총매수건수 = MidEx(strData, nPos, 5)
    이론가 = MidEx(strData, nPos, 7)
    미결제약정수량 = MidEx(strData, nPos, 7)
    미결제약정수량대비 = MidEx(strData, nPos, 6)
    괴리율 = MidEx(strData, nPos, 7)
    시장베이시스 = MidEx(strData, nPos, 7)
    시가대비 = MidEx(strData, nPos, 7)
    고가대비 = MidEx(strData, nPos, 7)
    저가대비 = MidEx(strData, nPos, 7)
    매도호가건수대비1 = MidEx(strData, nPos, 4)
    매도호가건수대비2 = MidEx(strData, nPos, 4)
    매도호가건수대비3 = MidEx(strData, nPos, 4)
    매도호가건수대비4 = MidEx(strData, nPos, 4)
    매도호가건수대비5 = MidEx(strData, nPos, 4)
    매수호가건수대비1 = MidEx(strData, nPos, 4)
    매수호가건수대비2 = MidEx(strData, nPos, 4)
    매수호가건수대비3 = MidEx(strData, nPos, 4)
    매수호가건수대비4 = MidEx(strData, nPos, 4)
    매수호가건수대비5 = MidEx(strData, nPos, 4)
    kospi200 = MidEx(strData, nPos, 7)
    호가총잔량차이 = MidEx(strData, nPos, 7)
    이론베이시스 = MidEx(strData, nPos, 7)
    거래량증감 = MidEx(strData, nPos, 9)
    거래대금증감 = MidEx(strData, nPos, 9)

End Sub



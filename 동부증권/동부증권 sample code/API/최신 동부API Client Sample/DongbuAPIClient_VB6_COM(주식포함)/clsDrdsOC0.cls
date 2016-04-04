VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsDrdsOC0"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit
'clsDrdsOC0
'**** 옵션 현재가 (OC0) *******************************************/
'**** SVR : 옵션 체결, 장운용, 기세         ***********************/
'******************************************************************/

Public 종목코드 As String
Public 총목SEQ As String
Public 체결수량 As String
Public 시간 As String
Public 매도호가1 As String
Public 매수호가1 As String
Public 매도잔량1 As String
Public 매수잔량1 As String
Public 매도호가2 As String
Public 매수호가2 As String
Public 매도잔량2 As String
Public 매수잔량2 As String
Public 매도호가3 As String
Public 매수호가3 As String
Public 매도잔량3 As String
Public 매수잔량3 As String
Public 총매도호가잔량 As String
Public 총매수호가잔량 As String
Public 현재가 As String
Public 시가 As String
Public 고가 As String
Public 저가 As String
Public 누적체결수량 As String
Public 누적누적매수체결량 As String
Public 누적거래대금 As String
Public 전일대비부호 As String
Public 전일대비 As String
Public 등락율 As String
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
Public 내재변동성 As String
Public 델타 As String
Public 감마 As String
Public 베가 As String
Public 세타 As String
Public 로우 As String
Public 미결제약정수량 As String
Public 미결제약정수량대비 As String
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
Public KP200 As String
Public 내재가치 As String
Public 시간가치 As String
Public 거래량증감 As String
Public 거래대금증감 As String
Public 괴리율 As String
Public 체결순매수 As String
Public 총매도호가잔량_부호 As String
Public 총매수호가잔량_부호 As String
Public 미결제약정수량_부호 As String
Public 잔량차 As String         '(매수잔량-매도잔량)
Public 건수차 As String         '(매수건수-매도건수)

Public Sub Init(strData As String)
    Dim nPos As Long

    nPos = 1

    종목코드 = MidEx(strData, nPos, 8)
    총목SEQ = MidEx(strData, nPos, 3)
    체결수량 = MidEx(strData, nPos, 6)
    시간 = MidEx(strData, nPos, 6)
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
    현재가 = MidEx(strData, nPos, 7)
    시가 = MidEx(strData, nPos, 7)
    고가 = MidEx(strData, nPos, 7)
    저가 = MidEx(strData, nPos, 7)
    누적체결수량 = MidEx(strData, nPos, 8)
    누적누적매수체결량 = MidEx(strData, nPos, 8)
    누적거래대금 = MidEx(strData, nPos, 11)
    전일대비부호 = MidEx(strData, nPos, 1)
    전일대비 = MidEx(strData, nPos, 7)
    등락율 = MidEx(strData, nPos, 7)
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
    내재변동성 = MidEx(strData, nPos, 7)
    델타 = MidEx(strData, nPos, 7)
    감마 = MidEx(strData, nPos, 7)
    베가 = MidEx(strData, nPos, 7)
    세타 = MidEx(strData, nPos, 7)
    로우 = MidEx(strData, nPos, 7)
    미결제약정수량 = MidEx(strData, nPos, 7)
    미결제약정수량대비 = MidEx(strData, nPos, 6)
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
    KP200 = MidEx(strData, nPos, 7)
    내재가치 = MidEx(strData, nPos, 6)
    시간가치 = MidEx(strData, nPos, 6)
    거래량증감 = MidEx(strData, nPos, 9)
    거래대금증감 = MidEx(strData, nPos, 9)
    괴리율 = MidEx(strData, nPos, 7)
    체결순매수 = MidEx(strData, nPos, 9)
    총매도호가잔량_부호 = MidEx(strData, nPos, 7)
    총매수호가잔량_부호 = MidEx(strData, nPos, 7)
    미결제약정수량_부호 = MidEx(strData, nPos, 8)
    잔량차 = MidEx(strData, nPos, 7)
    건수차 = MidEx(strData, nPos, 5)

End Sub



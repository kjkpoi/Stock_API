VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsDrdsSH0"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit
'clsDrdsSH0
'**** 선물 호가 (SH0) *********************************************/
'**** SVR : 선물 호가 *********************************************/
'******************************************************************/

Public 종목코드 As String
Public 종목SEQ As String
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
Public 호가접수시간 As String
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
Public 호가총잔량차이 As String

Public Sub Init(strData As String)
    Dim nPos As Long

    nPos = 1

    종목코드 = MidEx(strData, nPos, 8)
    종목SEQ = MidEx(strData, nPos, 2)
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
    호가접수시간 = MidEx(strData, nPos, 6)
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
    호가총잔량차이 = MidEx(strData, nPos, 7)

End Sub



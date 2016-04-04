VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsDrdsXF3"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit
'clsDrdsXF3
'***** 주식-선물옵션잔고 (XF3) ********************************************/
'***** SVR : 선물옵션실시간잔고 Real(HTS)  ********************************/
'**************************************************************************/

Public userid As String
Public 계좌번호 As String
Public 종목번호 As String
Public 보유구분명 As String
Public 장부수량 As String
Public 당일변동수량 As String
Public 현재가 As String
Public 매수호가 As String
Public 매도호가 As String
Public 상한가 As String
Public 하한가 As String
Public 시장소속구분 As String
Public 매입단가 As String
Public 매입금액 As String
Public 당일실현손익 As String
Public 주문유형체크필드 As String
Public 거래단위 As String
Public 미체결주문수량 As String
Public 신규매수금액 As String
Public 신규매도금액 As String
Public 환매수금액 As String
Public 전매도금액 As String
Public 예탁현금 As String
Public 예탁대용 As String
Public 주문가능총액 As String
Public 주문가능현금 As String
Public 청산가능수량 As String

Public Sub Init(strData As String)
   Dim nPos As Long

   nPos = 1

    userid = Mid(strData, nPos, 20):    nPos = nPos + 20
    계좌번호 = Mid(strData, nPos, 20):    nPos = nPos + 20
    종목번호 = Mid(strData, nPos, 15):    nPos = nPos + 15
    보유구분명 = Mid(strData, nPos, 5):    nPos = nPos + 5
    장부수량 = Mid(strData, nPos, 15):    nPos = nPos + 15
    당일변동수량 = Mid(strData, nPos, 15):    nPos = nPos + 15
    현재가 = Mid(strData, nPos, 6):    nPos = nPos + 6
    매수호가 = Mid(strData, nPos, 6):    nPos = nPos + 6
    매도호가 = Mid(strData, nPos, 6):    nPos = nPos + 6
    상한가 = Mid(strData, nPos, 6):    nPos = nPos + 6
    하한가 = Mid(strData, nPos, 6):    nPos = nPos + 6
    시장소속구분 = Mid(strData, nPos, 1):    nPos = nPos + 1
    매입단가 = Mid(strData, nPos, 12):    nPos = nPos + 12
    매입금액 = Mid(strData, nPos, 15):    nPos = nPos + 15
    당일실현손익 = Mid(strData, nPos, 15):    nPos = nPos + 15
    주문유형체크필드 = Mid(strData, nPos, 3):    nPos = nPos + 3
    거래단위 = Mid(strData, nPos, 8):    nPos = nPos + 8
    미체결주문수량 = Mid(strData, nPos, 15):    nPos = nPos + 15
    신규매수금액 = Mid(strData, nPos, 15):    nPos = nPos + 15
    신규매도금액 = Mid(strData, nPos, 15):    nPos = nPos + 15
    환매수금액 = Mid(strData, nPos, 15):    nPos = nPos + 15
    전매도금액 = Mid(strData, nPos, 15):    nPos = nPos + 15
    예탁현금 = Mid(strData, nPos, 15):    nPos = nPos + 15
    예탁대용 = Mid(strData, nPos, 15):    nPos = nPos + 15
    주문가능총액 = Mid(strData, nPos, 15):    nPos = nPos + 15
    주문가능현금 = Mid(strData, nPos, 15):    nPos = nPos + 15
    청산가능수량 = Mid(strData, nPos, 15):    nPos = nPos + 15

End Sub



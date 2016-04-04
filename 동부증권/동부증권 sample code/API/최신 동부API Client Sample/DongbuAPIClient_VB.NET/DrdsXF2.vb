Module DrdsXF2

    Public Structure DRDS_XF2_DATA

        Dim userid As String        'userid                      20   	
        Dim jijum As String         '지점번호:KEY                 3   
        Dim geja As String          '계좌번호:KEY                17   
        Dim juno As String          '주문번호:KEY                 9   
        Dim jgname As String        '종목명(미사용)              20   
        Dim wonjuno As String       '원주문번호                   9   
        Dim jgcode As String        '종목코드                    15   
        Dim jugb As String          '주문구분                     3   
        Dim mmgb As String          '매매구분                     2   
        Dim singb As String         '호가주문부호(미사용)         2   
        Dim comgb As String         '주문수탁방법                 2   
        Dim yegb As String          '예약구분(지점:0)             1   
        Dim msgcode As String       '메세지코드(최종 부적격사유)  4   
        Dim juqty As String         '주문수량                    15   
        Dim juprc As String         '주문단가                    12   
        Dim cheqty As String        '체결수량                    15   
        Dim cheqtyall As String     '누적체결수량                15   
        Dim cheprc As String        '체결단가                    12   
        Dim cheprc1 As String       '최근월물약정가new           12   
        Dim cheprc2 As String       '차근월물약정가new           12   
        Dim nonqty As String        '미체결수량                  15   
        Dim cheamt As String        '체결금액                    15   
        Dim termid As String        'termid                       2   
        Dim gejaname As String      '계좌명(미사용)              12   
        Dim denycode As String      '거부코드                     3   
        Dim denymsg As String       '거부사유                    40   

        Dim m_szData As String

        Public Function SubStringEx(ByRef nStart As Integer, ByVal nLen As Integer) As String
            Dim strRet As String = m_szData.Substring(nStart, nLen)

            strRet = Trim(strRet)

            nStart = nStart + nLen

            Return strRet

        End Function

        Public Sub SetDrdsData(ByVal szData As String)

            m_szData = szData

            Dim nStart As Integer = 0

            userid = SubStringEx(nStart, 20)
            jijum = SubStringEx(nStart, 3)
            geja = SubStringEx(nStart, 17)
            juno = SubStringEx(nStart, 9)
            jgname = SubStringEx(nStart, 20)
            wonjuno = SubStringEx(nStart, 9)
            jgcode = SubStringEx(nStart, 15)
            jugb = SubStringEx(nStart, 3)
            mmgb = SubStringEx(nStart, 2)
            singb = SubStringEx(nStart, 2)
            comgb = SubStringEx(nStart, 2)
            yegb = SubStringEx(nStart, 1)
            msgcode = SubStringEx(nStart, 4)
            juqty = SubStringEx(nStart, 15)
            juprc = SubStringEx(nStart, 12)
            cheqty = SubStringEx(nStart, 15)
            cheqtyall = SubStringEx(nStart, 15)
            cheprc = SubStringEx(nStart, 12)
            cheprc1 = SubStringEx(nStart, 12)
            cheprc2 = SubStringEx(nStart, 12)
            nonqty = SubStringEx(nStart, 15)
            cheamt = SubStringEx(nStart, 15)
            termid = SubStringEx(nStart, 2)
            gejaname = SubStringEx(nStart, 12)
            denycode = SubStringEx(nStart, 3)
            denymsg = SubStringEx(nStart, 40)

        End Sub

    End Structure


End Module

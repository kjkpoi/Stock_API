Module DrdsXF2

    Public Structure DRDS_XF2_DATA

        Dim userid As String        'userid                      20   	
        Dim jijum As String         '������ȣ:KEY                 3   
        Dim geja As String          '���¹�ȣ:KEY                17   
        Dim juno As String          '�ֹ���ȣ:KEY                 9   
        Dim jgname As String        '�����(�̻��)              20   
        Dim wonjuno As String       '���ֹ���ȣ                   9   
        Dim jgcode As String        '�����ڵ�                    15   
        Dim jugb As String          '�ֹ�����                     3   
        Dim mmgb As String          '�Ÿű���                     2   
        Dim singb As String         'ȣ���ֹ���ȣ(�̻��)         2   
        Dim comgb As String         '�ֹ���Ź���                 2   
        Dim yegb As String          '���౸��(����:0)             1   
        Dim msgcode As String       '�޼����ڵ�(���� �����ݻ���)  4   
        Dim juqty As String         '�ֹ�����                    15   
        Dim juprc As String         '�ֹ��ܰ�                    12   
        Dim cheqty As String        'ü�����                    15   
        Dim cheqtyall As String     '����ü�����                15   
        Dim cheprc As String        'ü��ܰ�                    12   
        Dim cheprc1 As String       '�ֱٿ���������new           12   
        Dim cheprc2 As String       '���ٿ���������new           12   
        Dim nonqty As String        '��ü�����                  15   
        Dim cheamt As String        'ü��ݾ�                    15   
        Dim termid As String        'termid                       2   
        Dim gejaname As String      '���¸�(�̻��)              12   
        Dim denycode As String      '�ź��ڵ�                     3   
        Dim denymsg As String       '�źλ���                    40   

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

Imports System.Runtime.InteropServices

Public Class frmDrcmClient

    Dim m_hDongbuDRCM As IntPtr
    Dim m_hSocket As IntPtr
    Dim m_szIP As String

    Private Sub frmDrcmClient_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load

        edtID.Text = "ddddd"
        edtPwd.Text = "1111"

        EnableControls(False)

    End Sub

    Private Sub frmDrcmClient_FormClosing(ByVal sender As Object, ByVal e As System.Windows.Forms.FormClosingEventArgs) Handles Me.FormClosing

        DisconnectDRCM()

    End Sub

    Private Sub btnDisconnect_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnDisconnect.Click

        DisconnectDRCM()

    End Sub

    Private Sub btnConnect_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnConnect.Click

        DisplayMsg("���� DRCM ���� �õ���...")

        m_hDongbuDRCM = FindDRCM()

        If m_hDongbuDRCM = 0 Then
            MsgBox("���� DRCM�� ã�� �� �����ϴ�")
            Exit Sub
        End If

        ConnectDRCM()

    End Sub

    Private Function FindDRCM() As IntPtr

        Dim hDrcmHwnd As IntPtr
        Dim ProcID As Integer
        Dim strRegKey As String = "Software\Dongbu Securities\DongbuDRCM\PATH"

        Dim strExePath, strRoot, strExe, strWinName As String

        'DRCM ������Ʈ���� ���� �����´�
        Dim reg As Microsoft.Win32.RegistryKey = Microsoft.Win32.Registry.CurrentUser.OpenSubKey(strRegKey, False)
        If reg Is Nothing Then
            DisplayMsg("���� DRCM�� ��ġ�Ǿ� ���� �ʽ��ϴ�!")
            reg.Close()
            Exit Function
        End If

        strRoot = reg.GetValue("Root")
        strExe = reg.GetValue("Exe")
        strWinName = reg.GetValue("WinName")

        reg.Close()

        '���� �������� drcm�� ã�´�
        hDrcmHwnd = FindWindow(vbNullString, strWinName)

        'drcm�� �����Ų��
        If hDrcmHwnd = 0 Then

            strExePath = strRoot + "\" + "Bin\" + strExe

            ProcID = Shell(strExePath, AppWinStyle.NormalFocus)

            If ProcID > 0 Then
                hDrcmHwnd = FindWindow(vbNullString, strWinName)
            End If

        End If

        Return hDrcmHwnd

    End Function

    Private Function ConnectDRCM() As IntPtr

        Dim stUserInfo As ST_DRCM_USER = Nothing
        Dim nSizeData As Integer = Marshal.SizeOf(stUserInfo)

        Dim Send_Buf(nSizeData + 1) As Byte
        Dim pData As IntPtr = Marshal.AllocHGlobal(nSizeData)

        'get user info
        stUserInfo.hClientWnd = Me.Handle
        stUserInfo.szUserId = Trim(edtID.Text)
        stUserInfo.szPwd = Trim(edtPwd.Text)
        stUserInfo.szCertPwd = Trim(edtCertPwd.Text)
        stUserInfo.bShowLoginDlg = True


        Marshal.StructureToPtr(stUserInfo, pData, False)
        'Marshal.Copy(pData, Send_Buf, 0, nSizeData)

        '���ӽõ�
        Dim cs As COPYDATASTRUCT
        cs.dwData = DRCM_CONNECT        
        cs.cbData = Marshal.SizeOf(stUserInfo)
        cs.lpData = pData

        Dim nRet As Integer = SendMessage(m_hDongbuDRCM, WM_COPYDATA, Me.Handle, cs)
        Select Case (nRet)
            Case DRCM_MSG_LOGINFAIL
                MsgBox("�α��� ����")

            Case DRCM_MSG_SOCKETFAIL
                MsgBox("���� ���� ����")

            Case Else
                m_hSocket = nRet
        End Select

        Marshal.FreeHGlobal(pData)

        If m_hSocket <> 0 Then
            GetClientIp()
            EnableControls(True)

            DisplayMsg("�α��� ����")
        Else
            DisplayMsg("�α��� ����")
        End If

    End Function

    Private Sub DisplayMsg(ByVal strMsg As String)
        'ToolStripStatusLabel2.Text = strMsg

        ListBox1.Items.Insert(0, strMsg)
        ListBox1.SetSelected(0, True)
    End Sub

    Protected Overrides Sub WndProc(ByRef m As System.Windows.Forms.Message)

        If m.Msg <> WM_COPYDATA Then
            MyBase.WndProc(m)
            Exit Sub
        End If

        Dim cds As COPYDATASTRUCT = CType(m.GetLParam(GetType(COPYDATASTRUCT)), COPYDATASTRUCT)

        Select Case (cds.dwData)

            Case DRCM_DISCONNECT
                DisconnectedDRCM()

            Case DRCM_CLIENT_IP
                m_szIP = Marshal.PtrToStringAnsi(cds.lpData, cds.cbData)

                ToolStripStatusLabel1.Text = m_szIP

            Case DRCM_DRDS_DATA
                OnRealTimeData(cds.lpData, cds.cbData)

            Case Else
                OnReceiveData(cds.lpData, cds.dwData)

        End Select
        MyBase.WndProc(m)
       
    End Sub

    'DRDS -�ǽð� ����Ÿ ó��
    Private Sub OnRealTimeData(ByVal pData As IntPtr, ByVal nLen As Integer)
        Dim stDrdsData As DrdsData = CType(Marshal.PtrToStructure(pData, GetType(DrdsData)), DrdsData)

        Dim strName As String = stDrdsData.Name

        If stDrdsData.Name = R_XF2 Then
            DisplayMsg("Received XF2")

            '�Ľ� ����
            Dim stXF2 As DRDS_XF2_DATA = Nothing
            stXF2.SetDrdsData(stDrdsData.Data)

        ElseIf strName = R_XF3 Then
            DisplayMsg("Received XF3")

        End If

    End Sub

    Private Function GetStringEx(ByVal pSource() As Char, ByVal nLen As Integer)

        Dim nSizeData As Integer = nLen * Marshal.SystemDefaultCharSize
        Dim pData As IntPtr = Marshal.AllocHGlobal(nSizeData + 1)
        Dim strData As String = Nothing

        Try
            'Marshal.Copy(pSource, 0, pData, nLen)            
            'strData = Marshal.PtrToStringUni(pData, nLen)

            pData = Marshal.StringToBSTR(pSource)
            strData = Marshal.PtrToStringUni(pData)

        Finally
            'Marshal.FreeHGlobal(pData)

        End Try


        Return strData.Trim()

    End Function

    'TR ����Ÿ ó��
    Private Sub OnReceiveData(ByVal szData As IntPtr, ByVal nLen As Integer)

        Dim stHeader As STTRHEADER = CType(Marshal.PtrToStructure(szData, GetType(STTRHEADER)), STTRHEADER)

        Dim strTrCode = GetStringEx(stHeader.TRCode, stHeader.TRCode.Length)
        Dim strMsgCode = GetStringEx(stHeader.MsgCode, stHeader.MsgCode.Length)
        Dim strMessage = GetStringEx(stHeader.Message, 70)
        Dim strMessage2Len = GetStringEx(stHeader.Message2Len, stHeader.Message2Len.Length)
        Dim strAPDataLen = GetStringEx(stHeader.APDataLen, stHeader.APDataLen.Length)

        'Dim strTrCode As String = CType(stHeader.TRCode, String)

        If strTrCode = TR_20000 Then '�ֹ�
            DisplayMsg("�ֹ� >> " + strMessage)

        ElseIf strTrCode = TR_13655 Then '�ܰ���ȸ

            DisplayMsg("�ܰ���ȸ >> " + strMessage)

            Dim st13655 As TR_13655_O = Nothing
            Dim nSize = Marshal.SizeOf(st13655)

            Dim pData As IntPtr = Marshal.AllocHGlobal(nSize + 1)

            Marshal.Copy(stHeader.TRData, 0, pData, nSize)

            Dim strData As String = Marshal.PtrToStringUni(pData)

            MsgBox(strData)

        ElseIf strTrCode = TR_15813 Then '����Ȳ ��ȸ
            DisplayMsg("����Ȳ >> " + strMessage)

        ElseIf strTrCode = TR_13653 Then '������ ��ȸ
            DisplayMsg("������ >> " + strMessage)

        ElseIf strTrCode = TR_13615 Then 'ü�᳻�� ��ȸ
            DisplayMsg("ü�᳻�� >> " + strMessage)

        End If

    End Sub

    'DRCM���� ����Ǿ��ٴ� �޽����� �޾Ƽ� ó��
    Private Sub DisconnectedDRCM()

        DisplayMsg("���� DRCM�� ����Ǿ����ϴ�")

        ToolStripStatusLabel1.Text = ""

        m_hSocket = 0
        m_hDongbuDRCM = 0

        EnableControls(False)

    End Sub

    'ȭ�� ��ư�� ó��
    Private Sub EnableControls(ByVal bConnected As Boolean)

        Dim bEnabled As Boolean = bConnected

        If bConnected Then
            btnConnect.Enabled = False
        Else
            btnConnect.Enabled = True
        End If

        btnDisconnect.Enabled = bEnabled

        btnOrder.Enabled = bEnabled
        btnJango.Enabled = bEnabled
        btnCheguyl.Enabled = bEnabled
        btnEval.Enabled = bEnabled
        btnFee.Enabled = bEnabled

        btnXF2Adv.Enabled = bEnabled
        btnXF2Unadv.Enabled = bEnabled
        btnXF3Adv.Enabled = bEnabled
        btnXF3Unadv.Enabled = bEnabled


    End Sub

    'DRCM�� ���������Ѵٰ� �޽��� ������
    Private Sub DisconnectDRCM()

        Dim cs As COPYDATASTRUCT
        cs.dwData = DRCM_DISCONNECT
        cs.cbData = 0
        SendMessage(m_hDongbuDRCM, WM_COPYDATA, Me.Handle, cs)
    End Sub

    'DRCM�� TR ������ - �ڱ� �ڽ��� Ip ���ϱ� ����
    Private Sub GetClientIp()

        Dim cs As COPYDATASTRUCT
        cs.dwData = DRCM_CLIENT_IP
        cs.cbData = 0
        SendMessage(m_hDongbuDRCM, WM_COPYDATA, Me.Handle, cs)

    End Sub

    'DRCM�� TR ������
    Private Function SendToServerEx(ByVal nWorkType As Integer, ByVal szTrCode As String, ByVal szData As String) As Boolean

        If System.String.IsNullOrEmpty(szData) Then
            Return False
        End If

        Dim szSendData As String = Nothing

        Select Case (nWorkType)
            Case DRCM_SENDDATA
                szSendData = String.Format("{0}{1}", szTrCode.PadRight(5, " "), szData)

            Case DRCM_ADVICE, DRCM_UNADVICE
                szSendData = String.Format("{0}{1}", szTrCode.PadRight(3, " "), szData)
        End Select

        'DRCM�� TR ������
        Dim cs As COPYDATASTRUCT

        Try
            cs.dwData = nWorkType
            cs.cbData = szSendData.Length * Marshal.SystemDefaultCharSize
            cs.lpData = Marshal.StringToHGlobalAnsi(szSendData)

            Dim bRet As Integer = SendMessage(m_hDongbuDRCM, WM_COPYDATA, Me.Handle, cs)

            If bRet <> 1 Then
                MsgBox("DRCM SERVER�� ��û ����!")
            End If

        Catch ex As System.OutOfMemoryException
        Catch e As Exception

        End Try


        Marshal.FreeHGlobal(cs.lpData)

    End Function

    Private Sub btnOrder_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnOrder.Click

        Dim szData As String = "00010000000000015202060701975         0000    101D3000       00000000000+000000138500000000000000011920091040630000"
        SendToServerEx(DRCM_SENDDATA, TR_20000, szData)

    End Sub

    Private Sub btnJango_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnJango.Click

        Dim szAccount As String = "02060701999"
        Dim szData As String = szAccount.PadRight(20, " ")

        SendToServerEx(DRCM_SENDDATA, TR_13655, szData)

    End Sub

    'ü�᳻��
    Private Sub btnCheguyl_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnCheguyl.Click

        Dim szAccount As String = "02060701999"
        Dim szPwd As String = "0000"
        Dim userfld As String = "0"

        Dim stInput As TR_13615_I = Nothing
        stInput.geja = szAccount.PadRight(20, " ")
        stInput.passwd = szPwd.PadRight(8, " ")
        stInput.sort = "1"
        stInput.userfld = userfld.PadRight(100, "0")

        SendToServerEx(DRCM_SENDDATA, TR_13615, stInput.ToString())

    End Sub

    '����Ȳ ��ȸ
    Private Sub btnEval_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnEval.Click

        Dim szAccount As String = "02060701999"
        Dim szPwd As String = "0000"
        Dim szDate As String = "20090305"
        Dim szNextKey As String = "0"

        Dim stInput As TR_15813_I = Nothing
        stInput.accno = szAccount.PadRight(20, " ")
        stInput.pass = szPwd.PadRight(8, " ")
        stInput.szdate = szDate.PadRight(8, " ")
        stInput.janggubun = "2"
        stInput.futuregubun = "1"
        stInput.ip_addr = m_szIP.PadRight(16, " ")
        stInput.nxtKey = szNextKey.PadRight(19, "0")

        SendToServerEx(DRCM_SENDDATA, TR_15813, stInput.ToString())

    End Sub

    '��������ȸ
    Private Sub btnFee_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnFee.Click

        Dim szAccount As String = "02060701999"
        Dim szPwd As String = "0000"
        Dim szDate As String = "20090305"

        Dim stInput As TR_13653_I = Nothing
        stInput.accno = szAccount.PadRight(20, " ")
        stInput.pass = szPwd.PadRight(18, " ")
        stInput.szdate = szDate.PadRight(8, " ")
        stInput.ip_addr = m_szIP.PadRight(16, " ")

        SendToServerEx(DRCM_SENDDATA, TR_13653, stInput.ToString())

    End Sub

    '���� �ǽð�ü�� �ǽð����
    Private Sub btnXF2Adv_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnXF2Adv.Click
        Dim szId As String = Trim(edtID.Text)
        SendToServerEx(DRCM_ADVICE, R_XF2, szId)
    End Sub

    '���� �ǽð�ü�� �ǽð���� ����
    Private Sub btnXF2Unadv_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnXF2Unadv.Click
        Dim szId As String = Trim(edtID.Text)
        SendToServerEx(DRCM_UNADVICE, R_XF2, szId)

    End Sub

    '���� �ǽð��ܰ� �ǽð����
    Private Sub btnXF3Adv_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnXF3Adv.Click
        Dim szId As String = Trim(edtID.Text)
        SendToServerEx(DRCM_ADVICE, R_XF3, szId)

    End Sub

    '���� �ǽð��ܰ� �ǽð���� ����
    Private Sub btnXF3Unadv_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnXF3Unadv.Click
        Dim szId As String = Trim(edtID.Text)
        SendToServerEx(DRCM_UNADVICE, R_XF3, szId)
    End Sub



    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click

        Dim szTmp As String = "����"
        'Dim szTmp2 As String = szTmp.Insert(2, vbNewLine) + szTmp

        ''  Create a managed array.
        'Dim managedArray As Char() = ("abcd").ToCharArray

        '' Initialize unmanged memory to hold the array.
        'Dim size As Integer = Marshal.SizeOf(managedArray(0)) * managedArray.Length
        'Dim pnt As IntPtr = Marshal.AllocHGlobal(szTmp.Length)
        'Marshal.Copy(managedArray, 0, pnt, managedArray.Length)


        Dim nSizeData As Integer = szTmp.Length * Marshal.SystemDefaultCharSize
        Dim pData As IntPtr = Marshal.StringToHGlobalAnsi(szTmp)

        Dim strData As String = Marshal.PtrToStringAnsi(pData)

        MsgBox(strData)

    End Sub

    Private Sub GroupBox2_Enter(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles GroupBox2.Enter

    End Sub
End Class

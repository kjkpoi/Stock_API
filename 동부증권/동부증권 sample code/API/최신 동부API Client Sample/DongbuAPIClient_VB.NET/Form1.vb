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

        DisplayMsg("동부 DRCM 접속 시도중...")

        m_hDongbuDRCM = FindDRCM()

        If m_hDongbuDRCM = 0 Then
            MsgBox("동부 DRCM을 찾을 수 없습니다")
            Exit Sub
        End If

        ConnectDRCM()

    End Sub

    Private Function FindDRCM() As IntPtr

        Dim hDrcmHwnd As IntPtr
        Dim ProcID As Integer
        Dim strRegKey As String = "Software\Dongbu Securities\DongbuDRCM\PATH"

        Dim strExePath, strRoot, strExe, strWinName As String

        'DRCM 레지스트리에 값을 가져온다
        Dim reg As Microsoft.Win32.RegistryKey = Microsoft.Win32.Registry.CurrentUser.OpenSubKey(strRegKey, False)
        If reg Is Nothing Then
            DisplayMsg("동부 DRCM이 설치되어 있지 않습니다!")
            reg.Close()
            Exit Function
        End If

        strRoot = reg.GetValue("Root")
        strExe = reg.GetValue("Exe")
        strWinName = reg.GetValue("WinName")

        reg.Close()

        '현재 실행중인 drcm을 찾는다
        hDrcmHwnd = FindWindow(vbNullString, strWinName)

        'drcm을 실행시킨다
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

        '접속시도
        Dim cs As COPYDATASTRUCT
        cs.dwData = DRCM_CONNECT        
        cs.cbData = Marshal.SizeOf(stUserInfo)
        cs.lpData = pData

        Dim nRet As Integer = SendMessage(m_hDongbuDRCM, WM_COPYDATA, Me.Handle, cs)
        Select Case (nRet)
            Case DRCM_MSG_LOGINFAIL
                MsgBox("로그인 실패")

            Case DRCM_MSG_SOCKETFAIL
                MsgBox("서버 접속 실패")

            Case Else
                m_hSocket = nRet
        End Select

        Marshal.FreeHGlobal(pData)

        If m_hSocket <> 0 Then
            GetClientIp()
            EnableControls(True)

            DisplayMsg("로그인 성공")
        Else
            DisplayMsg("로그인 실패")
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

    'DRDS -실시간 데이타 처리
    Private Sub OnRealTimeData(ByVal pData As IntPtr, ByVal nLen As Integer)
        Dim stDrdsData As DrdsData = CType(Marshal.PtrToStructure(pData, GetType(DrdsData)), DrdsData)

        Dim strName As String = stDrdsData.Name

        If stDrdsData.Name = R_XF2 Then
            DisplayMsg("Received XF2")

            '파싱 예제
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

    'TR 데이타 처리
    Private Sub OnReceiveData(ByVal szData As IntPtr, ByVal nLen As Integer)

        Dim stHeader As STTRHEADER = CType(Marshal.PtrToStructure(szData, GetType(STTRHEADER)), STTRHEADER)

        Dim strTrCode = GetStringEx(stHeader.TRCode, stHeader.TRCode.Length)
        Dim strMsgCode = GetStringEx(stHeader.MsgCode, stHeader.MsgCode.Length)
        Dim strMessage = GetStringEx(stHeader.Message, 70)
        Dim strMessage2Len = GetStringEx(stHeader.Message2Len, stHeader.Message2Len.Length)
        Dim strAPDataLen = GetStringEx(stHeader.APDataLen, stHeader.APDataLen.Length)

        'Dim strTrCode As String = CType(stHeader.TRCode, String)

        If strTrCode = TR_20000 Then '주문
            DisplayMsg("주문 >> " + strMessage)

        ElseIf strTrCode = TR_13655 Then '잔고조회

            DisplayMsg("잔고조회 >> " + strMessage)

            Dim st13655 As TR_13655_O = Nothing
            Dim nSize = Marshal.SizeOf(st13655)

            Dim pData As IntPtr = Marshal.AllocHGlobal(nSize + 1)

            Marshal.Copy(stHeader.TRData, 0, pData, nSize)

            Dim strData As String = Marshal.PtrToStringUni(pData)

            MsgBox(strData)

        ElseIf strTrCode = TR_15813 Then '평가현황 조회
            DisplayMsg("평가현황 >> " + strMessage)

        ElseIf strTrCode = TR_13653 Then '수수료 조회
            DisplayMsg("수수료 >> " + strMessage)

        ElseIf strTrCode = TR_13615 Then '체결내역 조회
            DisplayMsg("체결내역 >> " + strMessage)

        End If

    End Sub

    'DRCM에서 종료되었다는 메시지를 받아서 처리
    Private Sub DisconnectedDRCM()

        DisplayMsg("동부 DRCM이 종료되었습니다")

        ToolStripStatusLabel1.Text = ""

        m_hSocket = 0
        m_hDongbuDRCM = 0

        EnableControls(False)

    End Sub

    '화면 버튼들 처리
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

    'DRCM에 접속해제한다고 메시지 보내기
    Private Sub DisconnectDRCM()

        Dim cs As COPYDATASTRUCT
        cs.dwData = DRCM_DISCONNECT
        cs.cbData = 0
        SendMessage(m_hDongbuDRCM, WM_COPYDATA, Me.Handle, cs)
    End Sub

    'DRCM에 TR 보내기 - 자기 자신의 Ip 구하기 위해
    Private Sub GetClientIp()

        Dim cs As COPYDATASTRUCT
        cs.dwData = DRCM_CLIENT_IP
        cs.cbData = 0
        SendMessage(m_hDongbuDRCM, WM_COPYDATA, Me.Handle, cs)

    End Sub

    'DRCM에 TR 보내기
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

        'DRCM에 TR 보내기
        Dim cs As COPYDATASTRUCT

        Try
            cs.dwData = nWorkType
            cs.cbData = szSendData.Length * Marshal.SystemDefaultCharSize
            cs.lpData = Marshal.StringToHGlobalAnsi(szSendData)

            Dim bRet As Integer = SendMessage(m_hDongbuDRCM, WM_COPYDATA, Me.Handle, cs)

            If bRet <> 1 Then
                MsgBox("DRCM SERVER에 요청 실패!")
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

    '체결내역
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

    '평가현황 조회
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

    '수수료조회
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

    '선옵 실시간체결 실시간등록
    Private Sub btnXF2Adv_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnXF2Adv.Click
        Dim szId As String = Trim(edtID.Text)
        SendToServerEx(DRCM_ADVICE, R_XF2, szId)
    End Sub

    '선옵 실시간체결 실시간등록 해제
    Private Sub btnXF2Unadv_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnXF2Unadv.Click
        Dim szId As String = Trim(edtID.Text)
        SendToServerEx(DRCM_UNADVICE, R_XF2, szId)

    End Sub

    '선옵 실시간잔고 실시간등록
    Private Sub btnXF3Adv_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnXF3Adv.Click
        Dim szId As String = Trim(edtID.Text)
        SendToServerEx(DRCM_ADVICE, R_XF3, szId)

    End Sub

    '선옵 실시간잔고 실시간등록 해제
    Private Sub btnXF3Unadv_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnXF3Unadv.Click
        Dim szId As String = Trim(edtID.Text)
        SendToServerEx(DRCM_UNADVICE, R_XF3, szId)
    End Sub



    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click

        Dim szTmp As String = "가나"
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

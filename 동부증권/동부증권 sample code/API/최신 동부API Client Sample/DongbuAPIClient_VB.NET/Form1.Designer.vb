<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmDrcmClient
    Inherits System.Windows.Forms.Form

    'Form은 Dispose를 재정의하여 구성 요소 목록을 정리합니다.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        If disposing AndAlso components IsNot Nothing Then
            components.Dispose()
        End If
        MyBase.Dispose(disposing)
    End Sub

    'Windows Form 디자이너에 필요합니다.
    Private components As System.ComponentModel.IContainer

    '참고: 다음 프로시저는 Windows Form 디자이너에 필요합니다.
    '수정하려면 Windows Form 디자이너를 사용하십시오.  
    '코드 편집기를 사용하여 수정하지 마십시오.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.btnConnect = New System.Windows.Forms.Button
        Me.btnDisconnect = New System.Windows.Forms.Button
        Me.StatusStrip1 = New System.Windows.Forms.StatusStrip
        Me.ToolStripStatusLabel1 = New System.Windows.Forms.ToolStripStatusLabel
        Me.Label1 = New System.Windows.Forms.Label
        Me.Label2 = New System.Windows.Forms.Label
        Me.Label3 = New System.Windows.Forms.Label
        Me.edtID = New System.Windows.Forms.TextBox
        Me.edtPwd = New System.Windows.Forms.TextBox
        Me.edtCertPwd = New System.Windows.Forms.TextBox
        Me.GroupBox1 = New System.Windows.Forms.GroupBox
        Me.btnFee = New System.Windows.Forms.Button
        Me.btnEval = New System.Windows.Forms.Button
        Me.btnCheguyl = New System.Windows.Forms.Button
        Me.btnJango = New System.Windows.Forms.Button
        Me.btnOrder = New System.Windows.Forms.Button
        Me.GroupBox2 = New System.Windows.Forms.GroupBox
        Me.btnXF3Unadv = New System.Windows.Forms.Button
        Me.btnXF3Adv = New System.Windows.Forms.Button
        Me.btnXF2Unadv = New System.Windows.Forms.Button
        Me.btnXF2Adv = New System.Windows.Forms.Button
        Me.Button1 = New System.Windows.Forms.Button
        Me.ListBox1 = New System.Windows.Forms.ListBox
        Me.Label4 = New System.Windows.Forms.Label
        Me.StatusStrip1.SuspendLayout()
        Me.GroupBox1.SuspendLayout()
        Me.GroupBox2.SuspendLayout()
        Me.SuspendLayout()
        '
        'btnConnect
        '
        Me.btnConnect.Location = New System.Drawing.Point(203, 11)
        Me.btnConnect.Name = "btnConnect"
        Me.btnConnect.Size = New System.Drawing.Size(78, 50)
        Me.btnConnect.TabIndex = 0
        Me.btnConnect.Text = "DRCM 접속"
        Me.btnConnect.UseVisualStyleBackColor = True
        '
        'btnDisconnect
        '
        Me.btnDisconnect.Location = New System.Drawing.Point(283, 11)
        Me.btnDisconnect.Name = "btnDisconnect"
        Me.btnDisconnect.Size = New System.Drawing.Size(103, 50)
        Me.btnDisconnect.TabIndex = 1
        Me.btnDisconnect.Text = "DRCM 접속해제"
        Me.btnDisconnect.UseVisualStyleBackColor = True
        '
        'StatusStrip1
        '
        Me.StatusStrip1.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.ToolStripStatusLabel1})
        Me.StatusStrip1.Location = New System.Drawing.Point(0, 366)
        Me.StatusStrip1.Name = "StatusStrip1"
        Me.StatusStrip1.Size = New System.Drawing.Size(398, 22)
        Me.StatusStrip1.TabIndex = 5
        Me.StatusStrip1.Text = "StatusStrip1"
        '
        'ToolStripStatusLabel1
        '
        Me.ToolStripStatusLabel1.Name = "ToolStripStatusLabel1"
        Me.ToolStripStatusLabel1.Size = New System.Drawing.Size(41, 17)
        Me.ToolStripStatusLabel1.Text = "Ready"
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(47, 14)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(41, 12)
        Me.Label1.TabIndex = 6
        Me.Label1.Text = "아이디"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(59, 38)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(29, 12)
        Me.Label2.TabIndex = 7
        Me.Label2.Text = "암호"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(7, 62)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(81, 12)
        Me.Label3.TabIndex = 8
        Me.Label3.Text = "공인인증 암호"
        '
        'edtID
        '
        Me.edtID.Location = New System.Drawing.Point(94, 11)
        Me.edtID.Name = "edtID"
        Me.edtID.Size = New System.Drawing.Size(94, 21)
        Me.edtID.TabIndex = 9
        '
        'edtPwd
        '
        Me.edtPwd.Location = New System.Drawing.Point(94, 35)
        Me.edtPwd.Name = "edtPwd"
        Me.edtPwd.Size = New System.Drawing.Size(94, 21)
        Me.edtPwd.TabIndex = 10
        Me.edtPwd.UseSystemPasswordChar = True
        '
        'edtCertPwd
        '
        Me.edtCertPwd.Location = New System.Drawing.Point(94, 59)
        Me.edtCertPwd.Name = "edtCertPwd"
        Me.edtCertPwd.Size = New System.Drawing.Size(94, 21)
        Me.edtCertPwd.TabIndex = 11
        Me.edtCertPwd.UseSystemPasswordChar = True
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.btnFee)
        Me.GroupBox1.Controls.Add(Me.btnEval)
        Me.GroupBox1.Controls.Add(Me.btnCheguyl)
        Me.GroupBox1.Controls.Add(Me.btnJango)
        Me.GroupBox1.Controls.Add(Me.btnOrder)
        Me.GroupBox1.Location = New System.Drawing.Point(12, 102)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(375, 58)
        Me.GroupBox1.TabIndex = 12
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "조회 및 주문 전송"
        '
        'btnFee
        '
        Me.btnFee.Location = New System.Drawing.Point(298, 20)
        Me.btnFee.Name = "btnFee"
        Me.btnFee.Size = New System.Drawing.Size(62, 30)
        Me.btnFee.TabIndex = 4
        Me.btnFee.Text = "수수료"
        Me.btnFee.UseVisualStyleBackColor = True
        '
        'btnEval
        '
        Me.btnEval.Location = New System.Drawing.Point(230, 20)
        Me.btnEval.Name = "btnEval"
        Me.btnEval.Size = New System.Drawing.Size(62, 30)
        Me.btnEval.TabIndex = 3
        Me.btnEval.Text = "평가현황"
        Me.btnEval.UseVisualStyleBackColor = True
        '
        'btnCheguyl
        '
        Me.btnCheguyl.Location = New System.Drawing.Point(150, 20)
        Me.btnCheguyl.Name = "btnCheguyl"
        Me.btnCheguyl.Size = New System.Drawing.Size(62, 30)
        Me.btnCheguyl.TabIndex = 2
        Me.btnCheguyl.Text = "체결내역"
        Me.btnCheguyl.UseVisualStyleBackColor = True
        '
        'btnJango
        '
        Me.btnJango.Location = New System.Drawing.Point(82, 20)
        Me.btnJango.Name = "btnJango"
        Me.btnJango.Size = New System.Drawing.Size(62, 30)
        Me.btnJango.TabIndex = 1
        Me.btnJango.Text = "잔고조회"
        Me.btnJango.UseVisualStyleBackColor = True
        '
        'btnOrder
        '
        Me.btnOrder.Location = New System.Drawing.Point(14, 20)
        Me.btnOrder.Name = "btnOrder"
        Me.btnOrder.Size = New System.Drawing.Size(62, 30)
        Me.btnOrder.TabIndex = 0
        Me.btnOrder.Text = "주문전송"
        Me.btnOrder.UseVisualStyleBackColor = True
        '
        'GroupBox2
        '
        Me.GroupBox2.Controls.Add(Me.btnXF3Unadv)
        Me.GroupBox2.Controls.Add(Me.btnXF3Adv)
        Me.GroupBox2.Controls.Add(Me.btnXF2Unadv)
        Me.GroupBox2.Controls.Add(Me.btnXF2Adv)
        Me.GroupBox2.Location = New System.Drawing.Point(12, 166)
        Me.GroupBox2.Name = "GroupBox2"
        Me.GroupBox2.Size = New System.Drawing.Size(375, 73)
        Me.GroupBox2.TabIndex = 13
        Me.GroupBox2.TabStop = False
        Me.GroupBox2.Text = "실시간 등록"
        '
        'btnXF3Unadv
        '
        Me.btnXF3Unadv.Location = New System.Drawing.Point(169, 20)
        Me.btnXF3Unadv.Name = "btnXF3Unadv"
        Me.btnXF3Unadv.Size = New System.Drawing.Size(43, 40)
        Me.btnXF3Unadv.TabIndex = 4
        Me.btnXF3Unadv.Text = "XF3 해지"
        Me.btnXF3Unadv.UseVisualStyleBackColor = True
        '
        'btnXF3Adv
        '
        Me.btnXF3Adv.Location = New System.Drawing.Point(120, 20)
        Me.btnXF3Adv.Name = "btnXF3Adv"
        Me.btnXF3Adv.Size = New System.Drawing.Size(43, 40)
        Me.btnXF3Adv.TabIndex = 3
        Me.btnXF3Adv.Text = "XF3 등록"
        Me.btnXF3Adv.UseVisualStyleBackColor = True
        '
        'btnXF2Unadv
        '
        Me.btnXF2Unadv.Location = New System.Drawing.Point(63, 20)
        Me.btnXF2Unadv.Name = "btnXF2Unadv"
        Me.btnXF2Unadv.Size = New System.Drawing.Size(43, 40)
        Me.btnXF2Unadv.TabIndex = 2
        Me.btnXF2Unadv.Text = "XF2 해지"
        Me.btnXF2Unadv.UseVisualStyleBackColor = True
        '
        'btnXF2Adv
        '
        Me.btnXF2Adv.Location = New System.Drawing.Point(14, 20)
        Me.btnXF2Adv.Name = "btnXF2Adv"
        Me.btnXF2Adv.Size = New System.Drawing.Size(43, 40)
        Me.btnXF2Adv.TabIndex = 1
        Me.btnXF2Adv.Text = "XF2 등록"
        Me.btnXF2Adv.UseVisualStyleBackColor = True
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(242, 67)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(62, 29)
        Me.Button1.TabIndex = 14
        Me.Button1.Text = "test"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'ListBox1
        '
        Me.ListBox1.FormattingEnabled = True
        Me.ListBox1.ItemHeight = 12
        Me.ListBox1.Location = New System.Drawing.Point(12, 272)
        Me.ListBox1.Name = "ListBox1"
        Me.ListBox1.Size = New System.Drawing.Size(375, 88)
        Me.ListBox1.TabIndex = 15
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(12, 252)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(58, 12)
        Me.Label4.TabIndex = 16
        Me.Label4.Text = "Message"
        '
        'frmDrcmClient
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(7.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(398, 388)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.ListBox1)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.GroupBox2)
        Me.Controls.Add(Me.GroupBox1)
        Me.Controls.Add(Me.edtCertPwd)
        Me.Controls.Add(Me.edtPwd)
        Me.Controls.Add(Me.edtID)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.StatusStrip1)
        Me.Controls.Add(Me.btnDisconnect)
        Me.Controls.Add(Me.btnConnect)
        Me.Name = "frmDrcmClient"
        Me.Text = "동부API Client Sample(VB.NET)"
        Me.StatusStrip1.ResumeLayout(False)
        Me.StatusStrip1.PerformLayout()
        Me.GroupBox1.ResumeLayout(False)
        Me.GroupBox2.ResumeLayout(False)
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents btnConnect As System.Windows.Forms.Button
    Friend WithEvents btnDisconnect As System.Windows.Forms.Button
    Friend WithEvents StatusStrip1 As System.Windows.Forms.StatusStrip
    Friend WithEvents ToolStripStatusLabel1 As System.Windows.Forms.ToolStripStatusLabel
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents edtID As System.Windows.Forms.TextBox
    Friend WithEvents edtPwd As System.Windows.Forms.TextBox
    Friend WithEvents edtCertPwd As System.Windows.Forms.TextBox
    Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents btnFee As System.Windows.Forms.Button
    Friend WithEvents btnEval As System.Windows.Forms.Button
    Friend WithEvents btnCheguyl As System.Windows.Forms.Button
    Friend WithEvents btnJango As System.Windows.Forms.Button
    Friend WithEvents btnOrder As System.Windows.Forms.Button
    Friend WithEvents GroupBox2 As System.Windows.Forms.GroupBox
    Friend WithEvents btnXF3Unadv As System.Windows.Forms.Button
    Friend WithEvents btnXF3Adv As System.Windows.Forms.Button
    Friend WithEvents btnXF2Unadv As System.Windows.Forms.Button
    Friend WithEvents btnXF2Adv As System.Windows.Forms.Button
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents ListBox1 As System.Windows.Forms.ListBox
    Friend WithEvents Label4 As System.Windows.Forms.Label

End Class

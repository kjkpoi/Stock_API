Imports System.Runtime.InteropServices

Module DrcmStructDef

    Public Const DRCM_CONNECT As Integer = -70          '����
    Public Const DRCM_DISCONNECT As Integer = -71       '���� ����
    Public Const DRCM_SENDDATA As Integer = -72         'TR����
    Public Const DRCM_ADVICE As Integer = -73           '�ǽð� ����Ÿ ���
    Public Const DRCM_UNADVICE As Integer = -74         '�ǽð� ����Ÿ �������
    Public Const DRCM_CLIENT_IP As Integer = -75        '���� ������

    Public Const DRCM_DRDS_DATA As Integer = -700       '�ǽð� ����Ÿ RECEIVE

    Public Const DRCM_MSG_LOGINFAIL As Integer = -1     '�α��� ����
    Public Const DRCM_MSG_SOCKETFAIL As Integer = -2    '���� ���� ����

    Public Const SIZE_TRCODE As Integer = 5             'TR CODE ���� ����
    Public Const SIZE_RTCODE As Integer = 3             '�ǽð� CODE ���� ����

    Public Const TR_20000 As String = "20000"           '�ֹ�
    Public Const TR_13655 As String = "13655"           '�ܰ���ȸ
    Public Const TR_13615 As String = "13615"           'ü�᳻����ȸ
    Public Const TR_15813 As String = "15813"           '����Ȳ��ȸ
    Public Const TR_13653 As String = "13653"           '������ ��ȸ


    Public Const R_S31 As String = "S31"           '�������簡       
    Public Const R_S32 As String = "S32"           '�������簡       
    Public Const R_X22 As String = "X22"           '����ȣ��         
    Public Const R_SC0 As String = "SC0"           '���� ���簡      
    Public Const R_SH0 As String = "SH0"           '���� ȣ��(5ȣ��)        
    Public Const R_SH2 As String = "SH2"           '���� ȣ��        
    Public Const R_OC0 As String = "OC0"           '�ɼ� ���簡      
    Public Const R_OH0 As String = "OH0"           '�ɼ� ȣ��(5ȣ��)
    Public Const R_OH2 As String = "OH2"           '�ɼ� ȣ��        
    Public Const R_ELC As String = "ELC"           'ELW ���簡       
    Public Const R_ELH As String = "ELH"           'ELW ȣ��	       
    Public Const R_JC0 As String = "JC0"           '�ֽļ��� ���簡  
    Public Const R_JH0 As String = "JH0"           '�ֽļ��� ȣ��    
    Public Const R_OPC As String = "OPC"           '�ֽĿɼ� ���簡	 
    Public Const R_OPH As String = "OPH"           '�ֽĿɼ� ȣ��    
    Public Const R_XF2 As String = "XF2"           'ü��             
    Public Const R_XF3 As String = "XF3"           '�ܰ� 


    'DRCM �� �����ϱ� ���� ����ü
    Public Structure ST_DRCM_USER

        Public hClientWnd As IntPtr     ' �����͸� ���� ���
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=20)> Dim szUserId As String
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=20)> Dim szPwd As String
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=20)> Dim szCertPwd As String
        Public bShowLoginDlg As Boolean


    End Structure

    'PACKET HEADER
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi, pack:=0)> _
    Public Structure STTRHEADER
        <MarshalAs(UnmanagedType.U4, SizeConst:=4)> Dim WindowID As Int32
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=5)> Dim TRCode() As Char
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=6)> Dim MsgCode() As Char
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=82)> Dim Message() As Char
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=2)> Dim CursorPos() As Char
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=3)> Dim Message2Len() As Char
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=3)> Dim APDataLen() As Char


        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=800)> Dim TRData() As Char

        'Dim TRData As Byte        
        'Dim TRData As IntPtr

    End Structure

    '�ǽð� ����Ÿ
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi, pack:=0)> _
   Public Structure DrdsData
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=5)> Dim Name As String
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=6)> Dim Field As String
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=82)> Dim Key As String
        <MarshalAs(UnmanagedType.U4)> Dim Id As Integer
        <MarshalAs(UnmanagedType.U4)> Dim Len As Integer
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=4096)> Dim Data As String

    End Structure

    '�ܰ���ȸ >>
    Public Const tr_13655MAX As Integer = 250

    '�ܰ���ȸ Input
    Public Structure TR_13655_I
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=20)> Dim geja As String '/* ������ȣ(3)+���¹�ȣ(8) ->20 */
    End Structure

    '�ܰ���ȸ Output_Header
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi, pack:=0)> _
    Public Structure TR_13655_S
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=17)> Dim yakjungtot() As Char   '/* ��   �����ݾ�
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=17)> Dim pyungpltot() As Char   '/* ��   �򰡼���
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=17)> Dim jumuntot() As Char     '/* �ֹ������Ѿ�
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=17)> Dim amotpyngtot() As Char  '/* ��   �򰡱ݾ�
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=17)> Dim realpltot() As Char    '/* ���� ��������
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=17)> Dim jumuncash() As Char    '/* �ֹ���������
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=9)> Dim suikratetot() As Char   '/* ��   ������   7->9
    End Structure

    '�ܰ���ȸ Output _�ݺ�����
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi, pack:=0)> _
    Public Structure TR_13655_G
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim jocode() As Char       '/* �����ڵ�            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=3)> Dim mmgb_attr() As Char     '/* �Ÿű���            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=5)> Dim mmgb() As Char          '/* �Ÿű���            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim avqty() As Char        '/* û�갡��            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim pnonqty() As Char      '/* �����ܰ�            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim qtychg() As Char       '/* ����                
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim stnonqty() As Char     '/* ��������                           
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim tnocontqty() As Char   '/* ��ü���ֹ�����      
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=12)> Dim tnonprc() As Char      '/* ���Դܰ�            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=6)> Dim price() As Char         '/* ���簡              
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim pyungpl() As Char      '/* �򰡼���            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=9)> Dim suikrate() As Char      '/* ������              
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim tnonamt() As Char      '/* �����ݾ�            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim spyungamt() As Char    '/* �򰡱ݾ�            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=12)> Dim fee() As Char          '/* ������              
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=6)> Dim bid() As Char           '/* �ż�ȣ��            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=6)> Dim offer() As Char         '/* �ŵ�ȣ��            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=6)> Dim hprice() As Char        '/* ���Ѱ�              
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=6)> Dim lprice() As Char        '/* ���Ѱ�              
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=1)> Dim sgdssect() As Char      '/* ����Ҽӱ���        
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim sresbpl() As Char      '/* ���Ͻ�������        
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=3)> Dim jutp() As Char          '/* �ֹ�����            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim trdunt() As Char       '/* �ŷ�����            
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim tdmemeamt() As Char    '/* ���ϸż��Ǵ¸ŵ��ݾ�
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim memeamt() As Char      '/* �ŸŴ����   
    End Structure

    '�ܰ���ȸ Output
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi, pack:=0)> _
    Public Structure TR_13655_O
        Dim sm As TR_13655_S
        <MarshalAs(UnmanagedType.U1)> Dim gridcnt As Char
        Dim gr() As TR_13655_G

    End Structure

    '����Ȳ Input 
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi, pack:=0)> _
    Public Structure TR_15813_I
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=20)> Dim accno As String        '���¹�ȣ
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=8)> Dim pass As String          '��й�ȣ
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=8)> Dim szdate As String        '�ֹ���
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=1)> Dim janggubun As String     '�ܰ��򰡱��� #0:�⺻����1:�̵���չ�2:���Լ���� (������ '0'�� ���)
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=1)> Dim futuregubun As String   '���������򰡱���  #2:��������1:���ʰ�
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=16)> Dim ip_addr As String      'privateip
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=19)> Dim nxtKey As String       '����Ű:0 :O_SETCONTBTNKEY    -> ���� 19����Ʈ

        Public Overrides Function ToString() As String
            Return String.Format("{0}{1}{2}{3}{4}{5}{6}", accno, pass, szdate, janggubun, futuregubun, ip_addr, nxtKey)
        End Function

    End Structure

    '����Ȳ Output 
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi, pack:=0)> _
    Public Structure TR_15813_O
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim data11() As Char   '��Ź���Ѿ�
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim data12() As Char   '��Ź����
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim data13() As Char   '��Ź���

        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim data21() As Char   '��Ź���ű��Ѿ�
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim data22() As Char   '������Ź���űݾ�
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=14)> Dim data23() As Char   '�������ű��Ѿ�
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim data24() As Char   '�����������űݾ�

        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=14)> Dim data31() As Char   '�߰����ű��Ѿ�
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim data32() As Char   '�����߰����űݾ�
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=14)> Dim data33() As Char   '�ֹ������ѱݾ�
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim data34() As Char   '�����ֹ����ɱݾ�

        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=14)> Dim data41() As Char   '���Ⱑ���ѱݾ�
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim data42() As Char   '���Ⱑ�����ݾ�

        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=19)> Dim nxtKey() As Char   '����Ű:0 :O_SETCONTBTNKEY    -> ���� 19����Ʈ

    End Structure

    '������ ��ȸ Input 
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi, pack:=0)> _
    Public Structure TR_13653_I
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=20)> Dim accno As String        '���¹�ȣ
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=18)> Dim pass As String         '��й�ȣ
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=8)> Dim szdate As String        '�ֹ���        
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=16)> Dim ip_addr As String      'privateip

        Public Overrides Function ToString() As String
            Return String.Format("{0}{1}{2}{3}", accno, pass, szdate, ip_addr)
        End Function

    End Structure

    '��������ȸ Output 
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi, pack:=0)> _
    Public Structure TR_13653_O
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=15)> Dim data1() As Char   '�򰡿�Ź���Ѿ�
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=16)> Dim data2() As Char   '�ֹ����ɱݾ�
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=16)> Dim fee() As Char     '������     
    End Structure

    'ü�᳻�� ��ȸ Input 
    <StructLayout(LayoutKind.Sequential, CharSet:=CharSet.Ansi, pack:=0)> _
    Public Structure TR_13615_I
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=20)> Dim geja As String        '������ȣ(3)+���¹�ȣ(8) ->20 */
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=8)> Dim passwd As String       '��й�ȣ
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=1)> Dim sort As String         '����(1) ����(2)        
        <MarshalAs(UnmanagedType.ByValTStr, SizeConst:=100)> Dim userfld As String    '�Է±״�� RETURN 

        Public Overrides Function ToString() As String
            Return String.Format("{0}{1}{2}{3}", geja, passwd, sort, userfld)
        End Function

    End Structure

End Module

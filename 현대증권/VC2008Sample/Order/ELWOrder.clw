; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CELWOrderDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ELWOrder.h"

ClassCount=4
Class1=CELWOrderApp
Class2=CELWOrderDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_ELWORDER_DIALOG
Class4=CCodeSelDlg
Resource4=IDD_CODEDLG

[CLS:CELWOrderApp]
Type=0
HeaderFile=ELWOrder.h
ImplementationFile=ELWOrder.cpp
Filter=N

[CLS:CELWOrderDlg]
Type=0
HeaderFile=ELWOrderDlg.h
ImplementationFile=ELWOrderDlg.cpp
Filter=D
LastObject=CELWOrderDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ELWOrderDlg.h
ImplementationFile=ELWOrderDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ELWORDER_DIALOG]
Type=1
Class=CELWOrderDlg
ControlCount=22
Control1=IDC_STATIC,static,1342308865
Control2=IDC_COMBO_ACCOUNTNO,combobox,1344340227
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_TAB_ORDER,SysTabControl32,1342177280
Control8=IDC_CODE,edit,1350631552
Control9=IDC_AMOUNT,edit,1350631554
Control10=IDC_ORDER_GUBUN,combobox,1344340226
Control11=IDC_PRICE,edit,1350631554
Control12=IDC_STATIC,static,1342308352
Control13=IDC_ORDER_NO,edit,1350631554
Control14=IDC_BTN_CODE,button,1342279424
Control15=IDC_ORDERBTN,button,1342242816
Control16=IDC_BTN_ELWCur,button,1342246656
Control17=IDC_BTN_ELW2342,button,1342246656
Control18=IDC_GRID_HOGA,{6262D3A0-531B-11CF-91F6-C2863C385E30},1342242816
Control19=IDC_GRID_ELW2514,{6262D3A0-531B-11CF-91F6-C2863C385E30},1342242816
Control20=IDC_GRID_ELW2342,{6262D3A0-531B-11CF-91F6-C2863C385E30},1342242816
Control21=IDC_BTN_ELW2514,button,1342246656
Control22=IDC_STATIC_STATUS,static,1342308352

[DLG:IDD_CODEDLG]
Type=1
Class=CCodeSelDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CCodeSelDlg]
Type=0
HeaderFile=CodeSelDlg.h
ImplementationFile=CodeSelDlg.cpp
BaseClass=CDialog
Filter=D


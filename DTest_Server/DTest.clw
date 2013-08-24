; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDTestDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DTest.h"

ClassCount=5
Class1=CDTestApp
Class2=CDTestDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_DIALOG1
Resource2=IDR_MAINFRAME
Resource3=IDD_DTEST_DIALOG
Class4=CQuestionSet
Resource4=IDD_ABOUTBOX
Class5=CNewQDialog
Resource5=IDD_NEWQ_DIALOG

[CLS:CDTestApp]
Type=0
HeaderFile=DTest.h
ImplementationFile=DTest.cpp
Filter=N

[CLS:CDTestDlg]
Type=0
HeaderFile=DTestDlg.h
ImplementationFile=DTestDlg.cpp
Filter=D
LastObject=CDTestDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=DTestDlg.h
ImplementationFile=DTestDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DTEST_DIALOG]
Type=1
Class=CDTestDlg
ControlCount=11
Control1=IDC_QNO,button,1342177287
Control2=IDC_QTITLE,static,1342177280
Control3=IDC_PRE,button,1342373888
Control4=IDC_NEXT,button,1342242816
Control5=IDC_QUIT,button,1342242816
Control6=IDC_NEW,button,1342242816
Control7=IDC_DEL,button,1342242816
Control8=IDC_AA,static,1342308352
Control9=IDC_AB,static,1342308352
Control10=IDC_AC,static,1342308352
Control11=IDC_AD,static,1342308352

[DLG:IDD_DIALOG1]
Type=1
Class=?
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT2,edit,1350631552

[CLS:CQuestionSet]
Type=0
HeaderFile=QuestionSet.h
ImplementationFile=QuestionSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CQuestionSet]
DB=1
DBType=ODBC
ColumnCount=8
Column1=[QID], 4, 4
Column2=[QTitle], -9, 1024
Column3=[AA], 1, 256
Column4=[AB], 1, 256
Column5=[AC], 1, 256
Column6=[AD], 1, 256
Column7=[RAnswer], 1, 1
Column8=[QCatalog], 1, 10

[DLG:IDD_NEWQ_DIALOG]
Type=1
Class=CNewQDialog
ControlCount=12
Control1=IDC_STATIC,static,1342308352
Control2=IDC_NAA,button,1342308361
Control3=IDC_NAB,button,1342177289
Control4=IDC_NAC,button,1342177289
Control5=IDC_NAD,button,1342177289
Control6=IDC_NQTITLE,edit,1350762628
Control7=IDC_NAAC,edit,1350631556
Control8=IDC_NABC,edit,1350631556
Control9=IDC_NACC,edit,1350631556
Control10=IDC_NADC,edit,1350631556
Control11=IDC_NQ,button,1342242817
Control12=IDCANCEL,button,1342242816

[CLS:CNewQDialog]
Type=0
HeaderFile=NewQDialog.h
ImplementationFile=NewQDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_NQTITLE
VirtualFilter=dWC


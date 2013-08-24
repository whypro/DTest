; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDTestDlg
LastTemplate=CRecordset
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DTest.h"

ClassCount=4
Class1=CDTestApp
Class2=CDTestDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_DTEST_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CQuestionSet
Resource4=IDD_DIALOG1

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
LastObject=IDC_SCORE
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
ControlCount=10
Control1=IDC_QNO,button,1342177287
Control2=IDC_QTITLE,static,1342177280
Control3=IDC_AA,button,1342317577
Control4=IDC_AB,button,1342186505
Control5=IDC_AC,button,1342186505
Control6=IDC_AD,button,1342186505
Control7=IDC_PRE,button,1342373888
Control8=IDC_NEXT,button,1342242816
Control9=IDC_SUMMIT,button,1342242816
Control10=IDC_QUIT,button,1342242816

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


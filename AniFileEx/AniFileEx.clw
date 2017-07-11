; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAniFileExDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "AniFileEx.h"

ClassCount=4
Class1=CAniFileExApp
Class2=CAniFileExDlg
Class3=CAboutDlg

ResourceCount=7
Resource1=IDD_ABOUTBOX (English (U.S.))
Resource2=IDR_MAINFRAME
Resource3=IDD_ANIFILEEX_DIALOG (English (U.S.))
Resource4=IDD_NEWFILE
Resource5=IDD_ABOUTBOX
Resource6=IDD_ANIFILEEX_DIALOG
Class4=EditDlg
Resource7=IDR_MENU_POPUP

[CLS:CAniFileExApp]
Type=0
HeaderFile=AniFileEx.h
ImplementationFile=AniFileEx.cpp
Filter=N

[CLS:CAniFileExDlg]
Type=0
HeaderFile=AniFileExDlg.h
ImplementationFile=AniFileExDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CAniFileExDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=AniFileExDlg.h
ImplementationFile=AniFileExDlg.cpp
Filter=D

[DLG:IDD_ANIFILEEX_DIALOG (English (U.S.))]
Type=1
Class=CAniFileExDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ANIFILEEX_DIALOG]
Type=1
Class=CAniFileExDlg
ControlCount=19
Control1=IDOK,button,1342242817
Control2=IDC_TREE_VIEW,SysTreeView32,1350632111
Control3=IDC_STATIC,button,1342177287
Control4=IDC_BUTTON_NEW,button,1342242816
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_NAME,edit,1350633600
Control9=IDC_EDIT_COUNT,edit,1350633600
Control10=IDC_BUTTON_EDIT,button,1342242816
Control11=IDC_BUTTON_COUNT,button,1342242816
Control12=IDC_BUTTON_DELETE,button,1342242816
Control13=IDC_BUTTON_ABOUT,button,1342283776
Control14=IDC_BUTTON_LOAD,button,1342242816
Control15=IDC_STATIC,button,1342177287
Control16=IDC_EDIT_SEARCH,edit,1350631552
Control17=IDC_BUTTON_SEARCH,button,1342242816
Control18=IDC_LIST_SEARCH,listbox,1352728835
Control19=IDC_STATIC,static,1342177283

[DLG:IDD_ABOUTBOX]
Type=1
Class=?
ControlCount=6
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[DLG:IDD_NEWFILE]
Type=1
Class=EditDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342177283
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT1,edit,1350631552
Control7=IDC_EDIT2,edit,1350631552

[MNU:IDR_MENU_POPUP]
Type=1
Class=?
Command1=ID_MENU_NEW
Command2=ID_MENU_NEWFOLDER
Command3=ID_MENU_EDIT
Command4=ID_MENU_DELETE
CommandCount=4

[CLS:EditDlg]
Type=0
HeaderFile=EditDlg.h
ImplementationFile=EditDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC


# Microsoft Developer Studio Project File - Name="jpglib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=jpglib - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "jpglib.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "jpglib.mak" CFG="jpglib - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "jpglib - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "jpglib - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "jpglib - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "jpglib - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "jpglib - Win32 Release"
# Name "jpglib - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\fGetFileInfo\fGetFileInfo.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jcapimin.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jcapistd.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jccoefct.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jccolor.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jcdctmgr.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jchuff.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jcinit.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jcmainct.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jcmarker.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jcmaster.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jcomapi.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jcparam.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jcphuff.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jcprepct.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jcsample.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jctrans.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jdapimin.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jdapistd.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jdatadst.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jdatasrc.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jdcoefct.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jdcolor.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jddctmgr.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jdhuff.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jdinput.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jdmainct.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jdmarker.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jdmaster.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jdmerge.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jdphuff.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jdpostct.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jdsample.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jdtrans.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jerror.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jfdctflt.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jfdctfst.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jfdctint.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jidctflt.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jidctfst.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jidctint.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jidctred.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jjpglib.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jmemansi.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jmemmgr.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jquant1.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jquant2.c
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jutils.c
# End Source File
# Begin Source File

SOURCE=.\main.c
# End Source File
# Begin Source File

SOURCE=.\saveBmp\saveBmp.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\fGetFileInfo\fGetFileInfo.h
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jchuff.h
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jconfig.h
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jdct.h
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jdhuff.h
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jerror.h
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jinclude.h
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jjpglib.h
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jmemsys.h
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jmorecfg.h
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jpegint.h
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jpeglib.h
# End Source File
# Begin Source File

SOURCE=..\jpgbmpswap\jversion.h
# End Source File
# Begin Source File

SOURCE=.\saveBmp\saveBmp.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project

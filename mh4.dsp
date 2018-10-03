# Microsoft Developer Studio Project File - Name="mh4" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=mh4 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "mh4.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mh4.mak" CFG="mh4 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mh4 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "mh4 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "mh4 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FD /c
# ADD CPP /nologo /MD /W3 /O1 /I "$(QTDIR)\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "QT_DLL" /D "UNICODE" /D "QT_THREAD_SUPPORT" /D "NO_DEBUG" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib imm32.lib winmm.lib wsock32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib imm32.lib winmm.lib wsock32.lib imm32.lib wsock32.lib winmm.lib $(QTDIR)\lib\qt-mt230nc.lib $(QTDIR)\lib\qtmain.lib zlib.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "mh4 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FD /GZ /c
# ADD CPP /nologo /MD /W3 /Gm /ZI /Od /I "$(QTDIR)\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "QT_DLL" /D "UNICODE" /D "QT_THREAD_SUPPORT" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib imm32.lib winmm.lib wsock32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib imm32.lib winmm.lib wsock32.lib imm32.lib wsock32.lib winmm.lib $(QTDIR)\lib\qt-mt230nc.lib $(QTDIR)\lib\qtmain.lib zlib.lib /nologo /subsystem:windows /debug /machine:I386 /nodefaultlib:"libc" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "mh4 - Win32 Release"
# Name "mh4 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# Begin Source File

SOURCE=.\mh4.cpp
# End Source File
# Begin Source File

SOURCE=.\mh4widget.cpp
# End Source File
# Begin Source File

SOURCE=.\mh4window.cpp
# End Source File
# Begin Source File

SOURCE=.\moc_mh4widget.cpp
# End Source File
# Begin Source File

SOURCE=.\moc_mh4window.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\mh4.h
# End Source File
# Begin Source File

SOURCE=.\mh4widget.h

!IF  "$(CFG)" == "mh4 - Win32 Release"

# Begin Custom Build - Moc'ing centralwidget.h...
InputPath=.\mh4widget.h

"moc_mh4widget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc.exe mh4widget.h -o moc_mh4widget.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "mh4 - Win32 Debug"

# Begin Custom Build - Moc'ing centralwidget.h...
InputPath=.\mh4widget.h

"moc_mh4widget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc.exe mh4widget.h -o moc_mh4widget.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\mh4window.h

!IF  "$(CFG)" == "mh4 - Win32 Release"

# Begin Custom Build - Moc'ing mh4window.h...
InputPath=.\mh4window.h

"moc_mh4window.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc.exe mh4window.h -o moc_mh4window.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "mh4 - Win32 Debug"

# Begin Custom Build - Moc'ing mh4window.h...
InputPath=.\mh4window.h

"moc_mh4window.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc.exe mh4window.h -o moc_mh4window.cpp

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Group "Interfaces"

# PROP Default_Filter "ui"
# End Group
# Begin Source File

SOURCE=.\readme.txt
# End Source File
# End Target
# End Project

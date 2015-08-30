Building Qt projects with Visual Studio 2013, Express Edition

For complete info, follow this nice online tutorial (.pdf)
portfolio.delinkx.com/files/Qt.pdf

#1 

Everytime a new Q_OBJECT class is created, the .pro file has to be edited 
and qmake re-ran in order to create the new .vcproj file 
(Alternatively, user can choose to do this "by hand", which is a bit more tedious,
 refer to #2 for more details) 

There is a batch file in the root folder of the project 
(path C:\FluidMechProjects_source\FluidMechProjectsGui\build.bat)
which will essentially run qmake on FluidMechProjectsGui.pro file

.pro file contains all the info about header files + source files to build

In order for your new class to be added to the project correctly, 
.pro file need to be edited by adding source and header file 


#2:  

Set the custom buid type for all the Q_OBJECTS

command line:

setlocal
if errorlevel 1 goto VCEnd
C:\Qt\5.5\msvc2013\bin\moc.exe  -DUNICODE -DWIN32 -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -D_MSC_VER=1800 -D_WIN32 -IC:/Qt/5.5/msvc2013/mkspecs/win32-msvc2013 -IC:/FluidMechProjects_source/FluidMechProjectsGui -IC:/Qt/5.5/msvc2013/include -IC:/Qt/5.5/msvc2013/include/QtWidgets -IC:/Qt/5.5/msvc2013/include/QtGui -IC:/Qt/5.5/msvc2013/include/QtANGLE -IC:/Qt/5.5/msvc2013/include/QtCore mainwindow.h -o debug\moc_mainwindow.cpp
if errorlevel 1 goto VCEnd
endlocal

Description (optional) 
MOC mainwindow.h

OUtputs: (prepend)
debug\moc_mainwindow.cpp;%(Outputs)

Additional dependencies: (prepend)
mainwindow.h;%(AdditionalInputs)


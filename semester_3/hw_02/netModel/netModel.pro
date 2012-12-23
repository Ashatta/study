#-------------------------------------------------
#
# Project created by QtCreator 2012-12-23T16:02:29
#
#-------------------------------------------------

QT += core gui

TARGET = netModel
TEMPLATE = app


SOURCES += main.cpp\
	mainWindow.cpp \
	view.cpp \
	netModel.cpp \
	computers/computer.cpp \
	computers/linuxComputer.cpp \
	computers/macComputer.cpp \
	computers/windowsComputer.cpp

HEADERS  += mainWindow.h \
	view.h \
	netModel.h \
	computers/computer.h \
	computers/linuxComputer.h \
	computers/macComputer.h \
	computers/windowsComputer.h

RESOURCES += netModel.qrc

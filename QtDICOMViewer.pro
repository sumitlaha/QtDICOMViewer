#-------------------------------------------------
#
# Project created by Sumit Laha
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtDICOMViewer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp \
        mainwindow.cpp \
    itkimageiobase.cpp

HEADERS += mainwindow.h

FORMS += mainwindow.ui

QMAKE_CXXFLAGS += -Wno-deprecated

LIBS += -L/usr/local/lib \
-lvtkCommonCore \
-lvtkCommonDataModel \
-lvtkCommonExecutionModel \
-lvtkGUISupportQt \
-lvtkInteractionImage \
-lvtkInteractionStyle \
-lvtkIOImage \
-lvtkRenderingCore \
-lvtkRenderingFreeType \
-lvtkRenderingOpenGL2

INCLUDEPATH += /usr/local/include/vtk-8.0

LIBS += -L/usr/local/lib \
-lITKCommon \
-litkgdcmIOD \
-lITKIOGDCM \
-lITKIOImageBase \
-litksys \
-litkv3p_netlib \
-litkvnl \
-litkvnl_algo \
-lITKVNLInstantiation \
-lITKVTK \
-lITKVtkGlue \
-ldl

INCLUDEPATH += /usr/local/include/ITK-4.12

LIBS += "/usr/lib/x86_64-linux-gnu/*.so.2.6.3"

INCLUDEPATH += /usr/include/gdcm-2.6

RESOURCES += images.qrc

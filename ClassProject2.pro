#-------------------------------------------------
#
# Project created by QtCreator 2019-04-23T16:35:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ClassProject2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    ellipse.cpp \
    fillableshape.cpp \
    line.cpp \
        main.cpp \
        mainwindow.cpp \
    nonfillableshapes.cpp \
    parser.cpp \
    polygon.cpp \
    polyline.cpp \
    shape.cpp \
    admindialog.cpp \
    guestdialog.cpp

HEADERS += \
    ellipse.h \
    fillableshape.h \
    line.h \
        mainwindow.h \
    nonfillableshape.h \
    parser.h \
    polygon.h \
    polyline.h \
    properties.h \
    rectangle.h \
    shape.h \
    text.h \
    vector.h \
    admindialog.h \
    guestdialog.h

FORMS += \
        mainwindow.ui \
    guestdialog.ui \
    admindialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

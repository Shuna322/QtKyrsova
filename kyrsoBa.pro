#-------------------------------------------------
#
# Project created by QtCreator 2017-12-06T15:03:22
#
#-------------------------------------------------

QT       += core gui
QT += sql
QT += core network sql
RC_ICONS = icon.ico

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kyrsoBa
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


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    person.cpp \
    user.cpp \
    widget.cpp \
    student.cpp \
    database.cpp \
    addstudentform.cpp \
    studentinformation.cpp \
    adduserform.cpp \
    studentcontrol.cpp \
    departamentcontol.cpp \
    departamentchange.cpp \
    groupcontrol.cpp \
    groupchange.cpp

HEADERS += \
    mainwindow.h \
    person.h \
    user.h \
    widget.h \
    student.h \
    database.h \
    addstudentform.h \
    studentinformation.h \
    adduserform.h \
    studentcontrol.h \
    departamentcontol.h \
    departamentchange.h \
    groupcontrol.h \
    groupchange.h

FORMS += \
    mainwindow.ui \
    widget.ui \
    addstudentform.ui \
    studentinformation.ui \
    adduserform.ui \
    studentcontrol.ui \
    departamentcontol.ui \
    departamentchange.ui \
    groupcontrol.ui \
    groupchange.ui

DISTFILES +=

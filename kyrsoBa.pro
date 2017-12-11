#-------------------------------------------------
#
# Project created by QtCreator 2017-12-06T15:03:22
#
#-------------------------------------------------

QT       += core gui
QT += sql
QT += core network sql

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
    group.cpp \
    student.cpp \
    database.cpp \
    facuted.cpp \
<<<<<<< HEAD
    addstudentform.cpp
=======
    addstudentform.cpp \
    showtable.cpp
>>>>>>> parent of d3e9696... fixed loginmenu, added group and faculted var to student, changet constructors. Functions add student and show table working. Still need to add some fabulos and masks to addform.

HEADERS += \
    mainwindow.h \
    person.h \
    user.h \
    widget.h \
    group.h \
    student.h \
    database.h \
    facuted.h \
<<<<<<< HEAD
    addstudentform.h
=======
    addstudentform.h \
    showtable.h
>>>>>>> parent of d3e9696... fixed loginmenu, added group and faculted var to student, changet constructors. Functions add student and show table working. Still need to add some fabulos and masks to addform.

FORMS += \
    mainwindow.ui \
    widget.ui \
    addstudentform.ui

#-------------------------------------------------
#
# Project created by QtCreator 2019-04-03T10:19:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt
TEMPLATE = app

SOURCES += mainwindow.cpp \
    dialog1.cpp \
    ../libs/db/database.cpp \
    ../libs/teacher.cpp \
    ../libs/teacher_menu.cpp \
    ../libs/db/sqlite3.c \
    ../libs/main_menu.cpp \
    ../main.cpp \
    qt_main.cpp \
    mainwindow_teach.cpp \
    ../libs/SM.cpp \
    ../libs/func_student.cpp \
    ../libs/db/sha256.cpp \
    dialog2.cpp \
    mainwindow_stud.cpp \
    dialog3.cpp

HEADERS  += mainwindow.h \
    dialog1.h \
    ../headers/database.h \
    ../headers/sqlite3.h \
    ../headers/teacher_menu.h \
    ../headers/tests_main_header.h \
    ../headers/main_menu.h \
    mainwindow_teach.h \
    ../headers/config.h \
    ../headers/student_menu.h \
    ../headers/sha256.h \
    dialog2.h \
    mainwindow_stud.h \
    dialog3.h

FORMS    += mainwindow.ui \
    dialog1.ui \
    mainwindow_teach.ui \
    dialog2.ui \
    mainwindow_stud.ui \
    dialog3.ui

LIBS += -ldl \

DISTFILES += \
    ../Makefile.am \
    ../db/data.sqlite

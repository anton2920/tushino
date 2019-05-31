AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)

$(shell ./scripts/db.sh)

bin_PROGRAMS = ProTest

ProTest_SOURCES = main.cpp

if HAVE_QT
ProTest_CPPFLAGS = $(CXXFLAGS) $(QT_CXXFLAGS) -Wall -Wextra -std=c++11
ProTest_LDADD = libmainmenu.la libqt_cpp.la libdatabse.la libteacher.la libstudent.la
ProTest_LDFLAGS = $(LDFLAGS) $(QT_LIBS)
else
ProTest_CPPFLAGS = $(CXXFLAGS) -Wall -Wextra -std=c++11
ProTest_LDADD = libmainmenu.la libdatabse.la libteacher.la libstudent.la
ProTest_LDFLAGS = $(LDFLAGS)
endif

include_HEADERS = headers/tests_main_header.h headers/database.h headers/main_menu.h headers/sqlite3.h qt/dialog1.h \
qt/mainwindow.h qt/mainwindow_teach.h build-qt-Desktop-Debug/ui_dialog1.h build-qt-Desktop-Debug/ui_mainwindow.h \
build-qt-Desktop-Debug/ui_mainwindow_teach.h build-qt-Desktop-Debug/moc_predefs.h headers/teacher_menu.h \
headers/student_menu.h headers/config.h qt/dialog2.h qt/dialog3.h qt/mainwindow_stud.h headers/sha256.h \
build-qt-Desktop-Debug/ui_dialog2.h build-qt-Desktop-Debug/ui_dialog3.h build-qt-Desktop-Debug/ui_mainwindow_stud.h

if HAVE_QT
lib_LTLIBRARIES = libmainmenu.la libqt_cpp.la libdatabse.la libteacher.la libstudent.la
else 
lib_LTLIBRARIES = libmainmenu.la libdatabse.la libteacher.la libstudent.la
endif

# libmainmenu.la
libmainmenu_la_LDFLAGS = -version-info 0:0:0
libmainmenu_la_SOURCES = libs/main_menu.cpp
libmainmenu_la_CPPFLAGS = $(ProTest_CPPFLAGS)

# libqt_cpp.la
if HAVE_QT
libqt_cpp_la_LDFLAGS = -version-info 0:0:0 $(QT_LIBS)
libqt_cpp_la_SOURCES = qt/dialog1.cpp qt/mainwindow.cpp qt/mainwindow_teach.cpp qt/qt_main.cpp build-qt-Desktop-Debug/moc_dialog1.cpp \
build-qt-Desktop-Debug/moc_mainwindow.cpp build-qt-Desktop-Debug/moc_mainwindow_teach.cpp qt/dialog2.cpp qt/dialog3.cpp \
qt/mainwindow_stud.cpp build-qt-Desktop-Debug/moc_dialog2.cpp build-qt-Desktop-Debug/moc_dialog3.cpp \
build-qt-Desktop-Debug/moc_mainwindow_stud.cpp \
qt/dialog1.ui qt/dialog2.ui qt/dialog3.ui qt/mainwindow.ui qt/mainwindow_teach.ui qt/mainwindow_stud.ui 
libqt_cpp_la_CPPFLAGS = $(ProTest_CPPFLAGS)
endif

# libdatabse.la
libdatabse_la_LDFLAGS = -version-info 0:0:0
libdatabse_la_SOURCES = libs/db/database.cpp libs/db/sqlite3.c libs/db/sha256.cpp
libdatabse_la_CPPFLAGS = $(ProTest_CPPFLAGS)

# libteacher.la
libteacher_la_LDFLAGS = -version-info 0:0:0
libteacher_la_SOURCES = libs/teacher.cpp libs/teacher_menu.cpp
libteacher_la_CPPFLAGS = $(ProTest_CPPFLAGS)

# libstudent.la
libstudent_la_LDFLAGS = -version-info 0:0:0
libstudent_la_SOURCES = libs/SM.cpp libs/func_student.cpp
libstudent_la_CPPFLAGS = $(ProTest_CPPFLAGS)
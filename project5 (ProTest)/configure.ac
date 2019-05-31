# Autoconf requirements

# Initialize, but use more options. Note parameters brackts and whitespace.
AC_INIT([ProTest], [1.0], [anton2920@gmail.com])

# Safety check - list a source file that wouldn't be in other directories:
AC_CONFIG_SRCDIR([src/main.cpp])

# Put configuration results here, so we can easily #include them:
AC_CONFIG_HEADERS([src/headers/config.h])

# Put autotools auxiliary files in a subdir, so they don't clutter top dir:
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

# Enable «automake» to simplify creating makefiles:
AM_INIT_AUTOMAKE
AC_CONFIG_FILES([Makefile src/Makefile doc/Makefile man/Makefile examples/Makefile])

# Look for a C (CXX) compiler:
AC_LANG([C++])
AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX

# Check for: (more) programs, libraries, header files, types,
# structures, compiler characteristics, library functions, system services.
LT_INIT

AC_ENABLE_SHARED
AC_PROG_LIBTOOL

# Check for Qt
AC_ARG_WITH([Qt], [AC_HELP_STRING([--without-Qt], [force build without graphical UI based on Qt5])], [have_qt=no], [t_qt=true])
if test x$t_qt = xtrue; then
	AX_HAVE_QT

	# Define in config.h
	if test "x$have_qt" = xyes; then
		AC_DEFINE([HAVE_QT], [1], [Define if Qt will be used])
	fi
fi

# Qt test for Makefile.am
AM_CONDITIONAL([HAVE_QT], [test "x$have_qt" = xyes])

#AC_CHECK_HEADERS([QApplication QDialog QMessageBox QMainWindow QStyle QDesktopWidget QMessageBox], [], [
#	AC_MSG_WARN([unable to find Qt headers])
#	])

# Check for essential libraries 
AC_SEARCH_LIBS([dlclose], [dl], [], [
	AC_MSG_ERROR([unable to find dl lib])
	])

# AC_SEARCH_LIBS([pthreadMutexAlloc], [pthread], [], [
# 	AC_MSG_ERROR([unable to find pthread lib])
#	])

AC_SEARCH_LIBS([printf], [c], [], [
	AC_MSG_ERROR([unable to find c lib])
	])

AC_CHECK_HEADERS([string cstdio iostream cstring stdlib.h time.h], [], [
	AC_MSG_ERROR([unable to find necessary headers])
	])

 # Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T

# Do final output.
AC_OUTPUT

echo 
echo " ---------------------------------"
echo "| Options used to compile and link:"
echo "| CXX           = $CXX"
echo "| CXXFLAGS      = $CXXFLAGS"
echo "| LDFLAGS       = $LDFLAGS"
echo "| ARFLAGS       = $ARFLAGS"
echo "| With-Qt       = $have_qt"
echo "| QT_CXXFLAGS   = $QT_CXXFLAGS"
echo "| QT_LIBS       = $QT_LIBS"
echo "| QT_MOC        = $QT_MOC"
echo "| QT_UIC        = $QT_UIC"
echo "| QT_LRELEASE   = $QT_LRELEASE"
echo "| QT_LUPDATE    = $QT_LUPDATE"
echo "| QT_DIR        = $QT_DIR"
echo " ---------------------------------"
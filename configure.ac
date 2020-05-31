# -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.64)
AC_INIT(clio-test, 1.0.0, rblankley@woh.rr.com)

AC_CONFIG_AUX_DIR([.])
AM_INIT_AUTOMAKE([subdir-objects])
AM_SILENT_RULES([yes])

AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADER([config.h])

AC_CONFIG_MACRO_DIRS([m4])

# use the C++ compiler for the following checks
AC_LANG([C++])
AX_CXX_COMPILE_STDCXX_17([noext], [optional])

if test $HAVE_CXX17 = 1; then
	AC_MSG_NOTICE([Found c++17 support])
else
	AX_CXX_COMPILE_STDCXX_14([noext], [optional])

	if test $HAVE_CXX14 = 1; then
		AC_MSG_NOTICE([Found c++14 support])
	else
		AX_CXX_COMPILE_STDCXX_11([noext], [mandatory])
	fi
fi

AX_CHECK_COMPILE_FLAG([-pipe], [CXXFLAGS="$CXXFLAGS -pipe"], [])
AX_CHECK_COMPILE_FLAG([-Wall], [CXXFLAGS="$CXXFLAGS -Wall"], [])
AX_CHECK_COMPILE_FLAG([-Wextra], [CXXFLAGS="$CXXFLAGS -Wextra"], [])

AX_PTHREAD(
 [LIBS="$PTHREAD_LIBS $LIBS"
  CFLAGS="$CFLAGS $PTHREAD_CFLAGS"
  CXXFLAGS="$CXXFLAGS $PTHREAD_CFLAGS"],
 [AC_MSG_ERROR([pthread is required to compile this repo])])

# Silence warning: ar: 'u' modifier ignored since 'D' is the default
AC_SUBST(AR_FLAGS, [cr])

# distribute additional compiler and linker flags among Makefiles
# --> set and change these variables instead of CXXFLAGS or LDFLAGS (for user only)
AC_SUBST([AM_CXXFLAGS])
AC_SUBST([AM_LDFLAGS])

# Checks for programs.

# Checks for libraries.
AX_CXX_CHECK_LIB([clio], [clio::logger], [], [AC_MSG_ERROR([Could not find libclio library, check LDFLAGS])])

# Checks for header files.
AC_HEADER_STDC

AC_CHECK_HEADERS([chrono])
AC_CHECK_HEADERS([condition_variable])
AC_CHECK_HEADERS([cstdarg])
AC_CHECK_HEADERS([cstdio])
AC_CHECK_HEADERS([ctime])
AC_CHECK_HEADERS([list])
AC_CHECK_HEADERS([locale])
AC_CHECK_HEADERS([map])
AC_CHECK_HEADERS([memory])
AC_CHECK_HEADERS([mutex])
AC_CHECK_HEADERS([new])
AC_CHECK_HEADERS([iostream])
AC_CHECK_HEADERS([filesystem])
AC_CHECK_HEADERS([shared_mutex])
AC_CHECK_HEADERS([sstream])
AC_CHECK_HEADERS([stack])
AC_CHECK_HEADERS([stdexcept])
AC_CHECK_HEADERS([string])
AC_CHECK_HEADERS([thread])

AC_CHECK_HEADERS([clio.h], [], [AC_MSG_ERROR([Header for libclio is missing or invalid, check CPPFLAGS])])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.

# creating top level and subdirectory Makefiles:
AC_CONFIG_FILES([
	Makefile
	src/Makefile
])

AC_OUTPUT


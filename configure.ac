#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

#! Setup
AC_PREREQ([2.69])
AC_INIT(paxix, 0.0, carl.andrew.walker1@gmail.com)
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR(src)
AC_CONFIG_HEADERS(config.h)


#! Check for programs
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LEX
AC_PROG_YACC


#! Check for libraries
AC_CHECK_LIB(l, yylex)
AC_CHECK_LIB(y, yyparse)


#! Check for header files
AC_CHECK_HEADER(stdint.h)
AC_CHECK_HEADER(stdlib.h)
AC_CHECK_HEADER(string.h)


#! Check for typedefs, structures, and compiler characteristics
AC_CHECK_HEADER_STDBOOL
AC_TYPE_UINT32_T


#! Check for library functions
AC_FUNC_MALLOC
AC_FUNC_REALLOC


#! Produce files
AC_OUTPUT(Makefile
			 src/Makefile)

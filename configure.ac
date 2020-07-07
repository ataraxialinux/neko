AC_PREREQ([2.64])
AC_INIT([neko], [0.998], [ataraxialinux@protonmail.com])
AC_CONFIG_AUX_DIR(aux-dist)
AM_INIT_AUTOMAKE
AM_SANITY_CHECK
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

AC_PROG_MAKE_SET
AC_GNU_SOURCE
AC_STDC_HEADERS
AC_PROG_CC([gcc])
AC_PROG_CXX([g++])
AC_PROG_RANLIB()
AC_LANG(C, C++)

CFLAGS="-fPIC"

AC_CHECK_HEADERS(string.h)

AC_CONFIG_FILES([Makefile
		src/Makefile
		src/libopenbsd/Makefile
		src/libneko/Makefile
		src/libdewey/Makefile
		src/wrappers/Makefile
		src/vercmp/Makefile
		src/xchroot/Makefile
		src/neko/Makefile])

AC_OUTPUT

AC_INIT([rnum], [0.2.2])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([foreign 1.13 subdir-objects dist-zstd no-dist-gzip])
AM_SILENT_RULES([yes])
AC_PREREQ([2.68])
AC_CONFIG_SRCDIR([src/rnum.c])
AC_PROG_CC
AC_CHECK_HEADER([time.h],
		[has_time=1],
		[AC_MSG_ERROR(["math.h is needed"], [exit-status =1])]
	)
AC_ARG_ENABLE([legacy],
	      AS_HELP_STRING([--enable-legacy], [Enable legacy mode ]),
	      [enable_legacy=$enableval],
	      [enable_legacy=no]
      )
AC_ARG_ENABLE([time],
	      AS_HELP_STRING([--enable-time], [Use time instead of getrandom ]),
	      [use_time=$enableval],
	      [use_time=no]
	)
if test "x$enable_legacy" = "xyes"; then
	AC_DEFINE([_ENABLE_LEGACY], [1], [Enable legacy mode])
fi

if test "x$use_time" = "xyes"; then
	AC_DEFINE([_USE_TIME], [1], [Use time instead of getrandom])
fi

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

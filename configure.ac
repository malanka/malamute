################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################

#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
AC_PREREQ(2.61)
#
AC_INIT([malamute],[1.1.0],[zeromq-dev@lists.zeromq.org])

AC_CONFIG_AUX_DIR(config)
AC_CONFIG_MACRO_DIR(config)
AC_CONFIG_HEADERS([src/platform.h])
AM_INIT_AUTOMAKE([subdir-objects tar-ustar dist-zip foreign])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

# This defines PACKAGE_VERSION_... in src/platform.h
PV_MAJOR=`echo $PACKAGE_VERSION | cut -d . -f 1`
PV_MINOR=`echo $PACKAGE_VERSION | cut -d . -f 2`
PV_PATCH=`echo $PACKAGE_VERSION | cut -d . -f 3`
AC_DEFINE_UNQUOTED([PACKAGE_VERSION_MAJOR],[$PV_MAJOR],
    [MLM major version])
AC_DEFINE_UNQUOTED([PACKAGE_VERSION_MINOR],[$PV_MINOR],
    [MLM minor version])
AC_DEFINE_UNQUOTED([PACKAGE_VERSION_PATCH],[$PV_PATCH],
    [MLM patchlevel])
# This lets us use PACKAGE_VERSION in Makefiles
AC_SUBST(PACKAGE_VERSION)

#
# Libtool -version-info (ABI version)
#
# Currently 2.0.1 ("stable"). Don't change this unless you
# know exactly what you're doing and have read and understand
# http://www.gnu.org/software/libtool/manual/html_node/Updating-version-info.html
#
# libmlm -version-info
LTVER="1:1:0"
AC_SUBST(LTVER)

# Capture c flags
MLM_ORIG_CFLAGS="${CFLAGS:-none}"

# Checks for programs
AC_PROG_CC
AC_PROG_CC_C99
AM_PROG_CC_C_O
AC_LIBTOOL_WIN32_DLL
AC_PROG_LIBTOOL
AC_PROG_SED
AC_PROG_AWK
PKG_PROG_PKG_CONFIG

# Code coverage
AC_ARG_WITH(gcov, [AS_HELP_STRING([--with-gcov=yes/no],
                  [With GCC Code Coverage reporting])],
                  [MLM_GCOV="$withval"])

if test "x${MLM_GCOV}" == "xyes"; then
    CFLAGS="-O0 -g -fprofile-arcs -ftest-coverage"

    if test "x${MLM_ORIG_CFLAGS}" != "xnone"; then
        CFLAGS="${CFLAGS} ${MLM_ORIG_CFLAGS}"
    fi
    AM_CONDITIONAL(WITH_GCOV, true)
else
    AM_CONDITIONAL(WITH_GCOV, false)
fi

# Will be used to add flags to pkg-config useful when apps want to statically link
PKGCFG_LIBS_PRIVATE=""

PREVIOUS_CFLAGS="${CFLAGS}"
PREVIOUS_LIBS="${LIBS}"


was_libzmq_check_lib_detected=no

PKG_CHECK_MODULES([libzmq], [libzmq >= 0.0.0],
    [
        PKGCFG_LIBS_PRIVATE="$PKGCFG_LIBS_PRIVATE $libzmq_LIBS"
    ],
    [
        AC_ARG_WITH([libzmq],
            [
                AS_HELP_STRING([--with-libzmq],
                [Specify libzmq prefix])
            ],
            [search_libzmq="yes"],
            [])

        libzmq_synthetic_cflags=""
        libzmq_synthetic_libs="-lzmq"

        if test "x$search_libzmq" = "xyes"; then
            if test -r "${with_libzmq}/include/zmq.h"; then
                libzmq_synthetic_cflags="-I${with_libzmq}/include"
                libzmq_synthetic_libs="-L${with_libzmq}/lib -lzmq"
            else
                AC_MSG_ERROR([${with_libzmq}/include/zmq.h not found. Please check libzmq prefix])
            fi
        fi


        AC_CHECK_LIB([zmq], [zmq_init],
            [
                CFLAGS="${libzmq_synthetic_cflags} ${CFLAGS}"
                LDFLAGS="${libzmq_synthetic_libs} ${LDFLAGS}"
                LIBS="${libzmq_synthetic_libs} ${LIBS}"

                AC_SUBST([libzmq_CFLAGS],[${libzmq_synthetic_cflags}])
                AC_SUBST([libzmq_LIBS],[${libzmq_synthetic_libs}])
                was_libzmq_check_lib_detected=yes
                PKGCFG_LIBS_PRIVATE="$PKGCFG_LIBS_PRIVATE -lzmq"
            ],
            [AC_MSG_ERROR([cannot link with -lzmq, install libzmq])])
    ])

if test "x$was_libzmq_check_lib_detected" = "xno"; then
    CFLAGS="${libzmq_CFLAGS} ${CFLAGS}"
    LIBS="${libzmq_LIBS} ${LIBS}"
fi

was_czmq_check_lib_detected=no

PKG_CHECK_MODULES([czmq], [libczmq >= 0.0.0],
    [
        PKGCFG_LIBS_PRIVATE="$PKGCFG_LIBS_PRIVATE $czmq_LIBS"
    ],
    [
        AC_ARG_WITH([libczmq],
            [
                AS_HELP_STRING([--with-libczmq],
                [Specify libczmq prefix])
            ],
            [search_libczmq="yes"],
            [])

        czmq_synthetic_cflags=""
        czmq_synthetic_libs="-lczmq"

        if test "x$search_libczmq" = "xyes"; then
            if test -r "${with_libczmq}/include/czmq.h"; then
                czmq_synthetic_cflags="-I${with_libczmq}/include"
                czmq_synthetic_libs="-L${with_libczmq}/lib -lczmq"
            else
                AC_MSG_ERROR([${with_libczmq}/include/czmq.h not found. Please check libczmq prefix])
            fi
        fi


        AC_CHECK_LIB([czmq], [zhashx_test],
            [
                CFLAGS="${czmq_synthetic_cflags} ${CFLAGS}"
                LDFLAGS="${czmq_synthetic_libs} ${LDFLAGS}"
                LIBS="${czmq_synthetic_libs} ${LIBS}"

                AC_SUBST([czmq_CFLAGS],[${czmq_synthetic_cflags}])
                AC_SUBST([czmq_LIBS],[${czmq_synthetic_libs}])
                was_czmq_check_lib_detected=yes
                PKGCFG_LIBS_PRIVATE="$PKGCFG_LIBS_PRIVATE -lczmq"
            ],
            [AC_MSG_ERROR([cannot link with -lczmq, install libczmq])])
    ])

if test "x$was_czmq_check_lib_detected" = "xno"; then
    CFLAGS="${czmq_CFLAGS} ${CFLAGS}"
    LIBS="${czmq_LIBS} ${LIBS}"
fi

CFLAGS="${PREVIOUS_CFLAGS}"
LIBS="${PREVIOUS_LIBS}"

AC_SUBST(pkg_config_libs_private, $PKGCFG_LIBS_PRIVATE)

# Platform specific checks
malamute_on_mingw32="no"
malamute_on_cygwin="no"
malamute_on_android="no"
malamute_on_linux="no"
malamute_on_gnu="no"

# Host specific checks
AC_CANONICAL_HOST

# Man pages are built/installed if asciidoc and xmlto are present
#   --with-docs=no overrides this
AC_ARG_WITH([docs],
    AS_HELP_STRING([--with-docs],
        [Build and install man pages [default=yes]]),
    [with_docs=$withval])

if test "x$with_docs" = "xno"; then
    malamute_build_doc="no"
    malamute_install_man="no"
else
    # Determine whether or not documentation should be built and installed.
    malamute_build_doc="yes"
    malamute_install_man="yes"

    # Check for asciidoc and xmlto and don't build the docs if these are not installed.
    AC_CHECK_PROG(malamute_have_asciidoc, asciidoc, yes, no)
    AC_CHECK_PROG(malamute_have_xmlto, xmlto, yes, no)
    if test "x$malamute_have_asciidoc" = "xno" -o "x$malamute_have_xmlto" = "xno"; then
        malamute_build_doc="no"
        # Tarballs built with 'make dist' ship with prebuilt documentation.
        if ! test -f doc/malamute.7; then
            malamute_install_man="no"
            AC_MSG_WARN([You are building an unreleased version of MALAMUTE and asciidoc or xmlto are not installed.])
            AC_MSG_WARN([Documentation will not be built and manual pages will not be installed.])
        fi
    fi
fi
AC_MSG_CHECKING([whether to build documentation])
AC_MSG_RESULT([$malamute_build_doc])
AC_MSG_CHECKING([whether to install manpages])
AC_MSG_RESULT([$malamute_install_man])

# Set some default features required by libmlm code.
CPPFLAGS="-DMLM_INTERNAL_BUILD -D_REENTRANT -D_THREAD_SAFE $CPPFLAGS"

# OS-specific tests
case "${host_os}" in
    *linux*)
        # Define on Linux to enable all library features
        CPPFLAGS="-D_GNU_SOURCE -DLINUX $CPPFLAGS"
        AC_DEFINE(MLM_HAVE_LINUX, 1, [Have Linux OS])
        malamute_on_linux="yes"

        case "${host_os}" in
            *android*)
                AC_DEFINE(MLM_HAVE_ANDROID, 1, [Have Android OS])
                malamute_on_android="yes"
            ;;
        esac
        ;;
    *solaris*)
        # Define on Solaris to enable all library features
        CPPFLAGS="-D_PTHREADS $CPPFLAGS"
        # Allow definitions of common OS-provided functions that are not in old standards
        CPPFLAGS="-D__EXTENSIONS__ $CPPFLAGS"
        AC_DEFINE(MLM_HAVE_SOLARIS, 1, [Have Solaris OS])
        CFLAGS="${CFLAGS} -lsocket -lssp"
        ;;
    *freebsd*)
        # Define on FreeBSD to enable all library features
        CPPFLAGS="-D__BSD_VISIBLE $CPPFLAGS"
        AC_DEFINE(MLM_HAVE_FREEBSD, 1, [Have FreeBSD OS])
        ;;
    *darwin*)
        # Define on Darwin to enable all library features
        CPPFLAGS="-D_DARWIN_C_SOURCE $CPPFLAGS"
        AC_DEFINE(MLM_HAVE_OSX, 1, [Have DarwinOSX OS])
        ;;
    *netbsd*)
        # Define on NetBSD to enable all library features
        CPPFLAGS="-D_NETBSD_SOURCE $CPPFLAGS"
        AC_DEFINE(MLM_HAVE_NETBSD, 1, [Have NetBSD OS])
        ;;
    *openbsd*)
        # Define on OpenBSD to enable all library features
        CPPFLAGS="-D_BSD_SOURCE $CPPFLAGS"
        AC_DEFINE(MLM_HAVE_OPENBSD, 1, [Have OpenBSD OS])
        ;;
    *nto-qnx*)
        AC_DEFINE(MLM_HAVE_QNXNTO, 1, [Have QNX Neutrino OS])
        ;;
    *aix*)
        AC_DEFINE(MLM_HAVE_AIX, 1, [Have AIX OS])
        ;;
    *hpux*)
        # Define on HP-UX to enable all library features
        CPPFLAGS="-D_POSIX_C_SOURCE=200112L"
        AC_DEFINE(MLM_HAVE_HPUX, 1, [Have HPUX OS])
        ;;
    *mingw32*)
        AC_DEFINE(MLM_HAVE_WINDOWS, 1, [Have Windows OS])
        AC_DEFINE(MLM_HAVE_MINGW32, 1, [Have MinGW32])
        AC_CHECK_HEADERS(windows.h)
        malamute_on_mingw32="yes"
        malamute_install_man="no"
        ;;
    *mingw64*)
        # Define on MINGW64 to enable all libeary features
        # Disable format error due to incomplete ANSI C
        CPPFLAGS="-Wno-error=format -D_XOPEN_SOURCE $CPPFLAGS"
        AC_DEFINE(MLM_HAVE_WINDOWS, 1, [Have Windows OS])
        AC_DEFINE(MLM_HAVE_MINGW32, 1, [Have MinGW32])
        AC_CHECK_HEADERS(windows.h)
        malamute_on_mingw32="yes"
        malamute_install_man="no"
        ;;
    *cygwin*)
        # Define on Cygwin to enable all library features
        CPPFLAGS="-D_GNU_SOURCE $CPPFLAGS"
        AC_DEFINE(MLM_HAVE_CYGWIN, 1, [Have Cygwin])
        malamute_on_cygwin="yes"
        ;;
    gnu*)
        # Define on GNU/Hurd to enable all library features
        if test "x$GXX" = "xyes"; then
            CPPFLAGS="-D_GNU_SOURCE $CPPFLAGS"
        fi
        AC_DEFINE(MLM_HAVE_GNU, 1, [Have GNU/Hurd OS])
        malamute_on_gnu="yes"
        ;;
    *)
        AC_MSG_ERROR([unsupported system: ${host_os}])
        ;;
esac

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS(errno.h arpa/inet.h netinet/tcp.h netinet/in.h stddef.h \
                 stdlib.h string.h sys/socket.h sys/time.h unistd.h \
                 limits.h ifaddrs.h)
AC_CHECK_HEADERS([net/if.h net/if_media.h linux/wireless.h], [], [],
[
#ifdef HAVE_SYS_SOCKET_H
# include <sys/socket.h>
#endif
#include <stdint.h>
])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_HEADER_TIME
AC_TYPE_UINT32_T
AC_C_VOLATILE
AC_C_BIGENDIAN

# These options are GNU compiler specific.
if test "x$GCC" = "xyes"; then
    CPPFLAGS="-pedantic -Werror -Wall -Wc++-compat ${CPPFLAGS}"
fi

AM_CONDITIONAL(ENABLE_SHARED, test "x$enable_shared" = "xyes")
AM_CONDITIONAL(ON_MINGW, test "x$malamute_on_mingw32" = "xyes")
AM_CONDITIONAL(ON_CYGWIN, test "x$malamute_on_cygwin" = "xyes")
AM_CONDITIONAL(ON_ANDROID, test "x$malamute_on_android" = "xyes")
AM_CONDITIONAL(ON_LINUX, test "x$malamute_on_linux" = "xyes")
AM_CONDITIONAL(ON_GNU, test "x$malamute_on_gnu" = "xyes")
AM_CONDITIONAL(INSTALL_MAN, test "x$malamute_install_man" = "xyes")
AM_CONDITIONAL(BUILD_DOC, test "x$malamute_build_doc" = "xyes")

# Check for malamute intent
AC_ARG_ENABLE([malamute],
    AS_HELP_STRING([--enable-malamute],
        [Compile and install 'malamute' [default=yes]]),
    [enable_malamute=$enableval],
    [enable_malamute=yes])

AM_CONDITIONAL([ENABLE_MALAMUTE], [test x$enable_malamute != xno])
AM_COND_IF([ENABLE_MALAMUTE], [AC_MSG_NOTICE([ENABLE_MALAMUTE defined])])

# Check for mshell intent
AC_ARG_ENABLE([mshell],
    AS_HELP_STRING([--enable-mshell],
        [Compile and install 'mshell' [default=yes]]),
    [enable_mshell=$enableval],
    [enable_mshell=yes])

AM_CONDITIONAL([ENABLE_MSHELL], [test x$enable_mshell != xno])
AM_COND_IF([ENABLE_MSHELL], [AC_MSG_NOTICE([ENABLE_MSHELL defined])])

# Check for mlm_tutorial intent
AC_ARG_ENABLE([mlm_tutorial],
    AS_HELP_STRING([--enable-mlm_tutorial],
        [Compile and install 'mlm_tutorial' [default=yes]]),
    [enable_mlm_tutorial=$enableval],
    [enable_mlm_tutorial=yes])

AM_CONDITIONAL([ENABLE_MLM_TUTORIAL], [test x$enable_mlm_tutorial != xno])
AM_COND_IF([ENABLE_MLM_TUTORIAL], [AC_MSG_NOTICE([ENABLE_MLM_TUTORIAL defined])])

# Check for mlm_perftest intent
AC_ARG_ENABLE([mlm_perftest],
    AS_HELP_STRING([--enable-mlm_perftest],
        [Compile and install 'mlm_perftest' [default=yes]]),
    [enable_mlm_perftest=$enableval],
    [enable_mlm_perftest=yes])

AM_CONDITIONAL([ENABLE_MLM_PERFTEST], [test x$enable_mlm_perftest != xno])
AM_COND_IF([ENABLE_MLM_PERFTEST], [AC_MSG_NOTICE([ENABLE_MLM_PERFTEST defined])])

# Check for mlm_selftest intent
AC_ARG_ENABLE([mlm_selftest],
    AS_HELP_STRING([--enable-mlm_selftest],
        [Compile 'mlm_selftest' in src [default=yes]]),
    [enable_mlm_selftest=$enableval],
    [enable_mlm_selftest=yes])

AM_CONDITIONAL([ENABLE_MLM_SELFTEST], [test x$enable_mlm_selftest != xno])
AM_COND_IF([ENABLE_MLM_SELFTEST], [AC_MSG_NOTICE([ENABLE_MLM_SELFTEST defined])])

# Checks for library functions.
AC_TYPE_SIGNAL
AC_CHECK_FUNCS(perror gettimeofday memset getifaddrs)

# Set pkgconfigdir
AC_ARG_WITH([pkgconfigdir], AS_HELP_STRING([--with-pkgconfigdir=PATH],
    [Path to the pkgconfig directory [[LIBDIR/pkgconfig]]]),
    [pkgconfigdir="$withval"], [pkgconfigdir='${libdir}/pkgconfig'])
AC_SUBST([pkgconfigdir])


# enable specific system integration features
AC_ARG_WITH([systemd-units],
    AS_HELP_STRING([--with-systemd-units],
    [Build and install with systemd units integration [default=no]]),
    [with_systemd_units=$withval],
    [with_systemd_units=no])

PKG_PROG_PKG_CONFIG
AC_ARG_WITH([systemdsystemunitdir],
     [AS_HELP_STRING([--with-systemdsystemunitdir=DIR], [Directory for systemd service files])],,
     [with_systemdsystemunitdir=auto])
AS_IF([test "x$with_systemdsystemunitdir" = "xyes" -o "x$with_systemdsystemunitdir" = "xauto"], [
     def_systemdsystemunitdir=$($PKG_CONFIG --variable=systemdsystemunitdir systemd)

     AS_IF([test "x$def_systemdsystemunitdir" = "x"],
   [AS_IF([test "x$with_systemdsystemunitdir" = "xyes"],
    [AC_MSG_ERROR([systemd support requested but pkg-config unable to query systemd package])])
    with_systemdsystemunitdir=no],
   [with_systemdsystemunitdir="$def_systemdsystemunitdir"])])
AS_IF([test "x$with_systemdsystemunitdir" != "xno"],
      [AC_SUBST([systemdsystemunitdir], [$with_systemdsystemunitdir])])

AM_CONDITIONAL([WITH_SYSTEMD_UNITS], [test "x$with_systemdsystemunitdir" != "xno" -a x$with_systemd_units != xno])

AM_COND_IF([WITH_SYSTEMD_UNITS],
    [AC_DEFINE(WITH_SYSTEMD_UNITS, 1, [systemd units are going to be installed])
    AC_SUBST(WITH_SYSTEMD_UNITS)],
    [])

#   Project has no stable classes so enable draft API by default
enable_drafts=yes
AM_CONDITIONAL([ENABLE_DRAFTS], [test x$enable_drafts != xno])

if test "x$enable_drafts" = "xyes"; then
    AC_MSG_NOTICE([Building stable and legacy API + draft API])
    AC_DEFINE(MLM_BUILD_DRAFT_API, 1, [Provide draft classes and methods])
    AC_SUBST(pkg_config_defines, "-DMLM_BUILD_DRAFT_API=1")
else
    AC_MSG_NOTICE([Building stable and legacy API (no draft API)])
    AC_SUBST(pkg_config_defines, "")
fi

# Specify output files
AC_CONFIG_FILES([Makefile
                 doc/Makefile
                 src/libmlm.pc
                 src/malamute.cfg
                 ])

AM_COND_IF([WITH_SYSTEMD_UNITS],
    [AC_CONFIG_FILES([
                 src/malamute.service
    ])],
    [])


AC_OUTPUT

# Print configure summary and list make options
AC_DEFUN([AX_SUMMARIZE_ENV],
[
BUILD_USER=${USER}
BUILD_ARCH=${host}
BUILD_HOST=${ac_hostname}
BUILD_DATE=$(date +'%F %H:%M')

AC_DEFINE_UNQUOTED([BUILD_USER],     "${BUILD_USER}",     [The fine user who built the package])
AC_DEFINE_UNQUOTED([BUILD_ARCH],     "${BUILD_ARCH}",     [Architecture of the build host])
AC_DEFINE_UNQUOTED([BUILD_HOST],     "${BUILD_HOST}",     [Build host name])
AC_DEFINE_UNQUOTED([BUILD_DATE],     "${BUILD_DATE}",     [Build date])

AC_SUBST(BUILD_USER)
AC_SUBST(BUILD_ARCH)
AC_SUBST(BUILD_HOST)
AC_SUBST(BUILD_DATE)
AC_SUBST(BUILD_VERSION)
])

AC_DEFUN([AX_SUMMARIZE_CONFIG],
[
echo
echo '##########################################################################'
echo '#                                SUMMARY                                 #'
echo '##########################################################################'
echo
echo Package version............... : $PACKAGE-$VERSION
echo
echo C compiler.................... : $CC
echo C compiler flags.............. : $CFLAGS
echo Configure date................ : $BUILD_DATE
echo Build architecture............ : $BUILD_ARCH
echo Build docs.................... : $malamute_build_doc
echo Build host.................... : $BUILD_HOST
echo Build user.................... : $USER
echo Draft API..................... : $enable_drafts
echo Install dir................... : $prefix
echo Install man pages............. : $malamute_install_man

echo
echo Help:
echo Use the Draft API \(default = yes\):
echo --enable-drafts=\(yes\|no\)
echo
echo Build the docs and install the man pages \(default = yes\):
echo --with-docs=\(yes\|no\)       *requires asciidoc and xmlto

echo
echo '##########################################################################'

echo
echo Configure complete! Now procced with:
echo "    - 'make'               compile the project"
echo "    - 'make check'         run the project's selftest"
echo "    - 'make install'       install the project to $prefix"
echo
echo Further options are:
echo "    - 'make callcheck'     run the project's selftest with valgrind to"
echo "                           check for performance leaks"
echo "    - 'make check-verbose' run the project's selftest in verbose mode"
echo "    - 'make code'          generate code from models in src directory"
echo "                           (requires zproject and zproto)"
echo "    - 'make debug'         run the project's selftest under gdb"
echo "    - 'make memcheck'      run the project's selftest with valgrind to"
echo "                           check for memory leaks"
echo "    - 'make coverage'      generate project's selftest coverage report"
echo "                           expects --with-gcov option for configure"
echo
])

AX_SUMMARIZE_ENV
AX_SUMMARIZE_CONFIG
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################

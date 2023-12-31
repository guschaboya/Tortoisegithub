﻿/*
 * svn_private_config.hw : Template for svn_private_config.h on Win32.
 *
 * ====================================================================
 *    Licensed to the Apache Software Foundation (ASF) under one
 *    or more contributor license agreements.  See the NOTICE file
 *    distributed with this work for additional information
 *    regarding copyright ownership.  The ASF licenses this file
 *    to you under the Apache License, Version 2.0 (the
 *    "License"); you may not use this file except in compliance
 *    with the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing,
 *    software distributed under the License is distributed on an
 *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 *    KIND, either express or implied.  See the License for the
 *    specific language governing permissions and limitations
 *    under the License.
 * ====================================================================
 */

/* ==================================================================== */




#ifndef SVN_PRIVATE_CONFIG_HW
#define SVN_PRIVATE_CONFIG_HW


/* Define to a Windows-specific equivalent of config.guess output */
#define SVN_BUILD_HOST "x86-microsoft-windows"

#if defined(_M_X64)
#define SVN_BUILD_TARGET "x64-microsoft-windows"
#elif defined(_M_IA64)
#define SVN_BUILD_TARGET "ia64-microsoft-windows"
#elif defined( _M_IX86)
#define SVN_BUILD_TARGET "x86-microsoft-windows"
#elif defined(_M_ARM64)
#define SVN_BUILD_TARGET "arm64-microsoft-windows"
#else #error Unsupported build target.
#endif

/* The minimal version of Berkeley DB we want */
#define SVN_FS_WANT_DB_MAJOR    4
#define SVN_FS_WANT_DB_MINOR    0
#define SVN_FS_WANT_DB_PATCH    14


/* Path separator for local filesystem */
#define SVN_PATH_LOCAL_SEPARATOR '\\'

/* Name of system's null device */
#define SVN_NULL_DEVICE_NAME "nul"

/* Link fs fs library into the fs library */
//#define SVN_LIBSVN_FS_LINKS_FS_FS

/* Link local repos access library to client */
//#define SVN_LIBSVN_CLIENT_LINKS_RA_LOCAL

/* Link pipe repos access library to client */
//#define SVN_LIBSVN_CLIENT_LINKS_RA_SVN

/* Defined to be the path to the installed binaries */
#define SVN_BINDIR "/usr/local/bin"



/* The default FS back-end type */
#define DEFAULT_FS_TYPE "fsfs"

/* The default HTTP library to use */
#define DEFAULT_HTTP_LIBRARY "serf"

/* Define to the Python/C API format character suitable for apr_int64_t */
#if defined(_WIN64)
#define SVN_APR_INT64_T_PYCFMT "l"
#elif defined(_WIN32)
#define SVN_APR_INT64_T_PYCFMT "L"
#endif

/* Setup gettext macros */
#define N_(x) x
#define U_(x) x
#define PACKAGE_NAME "subversion"

#ifdef ENABLE_NLS
#define SVN_LOCALE_RELATIVE_PATH "../share/locale"
#include <locale.h>
#include <libintl.h>
#define _(x) dgettext(PACKAGE_NAME, x)
#define Q_(x1, x2, n) dngettext(PACKAGE_NAME, x1, x2, n)
#define HAVE_BIND_TEXTDOMAIN_CODESET
#else
#define _(x) (x)
#define Q_(x1, x2, n) (((n) == 1) ? x1 : x2)
#define gettext(x) (x)
#define dgettext(domain, x) (x)
#endif

#endif /* SVN_PRIVATE_CONFIG_HW */

/* Inclusion of Berkeley DB header */
#ifdef SVN_WANT_BDB
#define APU_WANT_DB
#include <apu_want.h>
#endif

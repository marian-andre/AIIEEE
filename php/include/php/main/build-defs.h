/*                                                                -*- C -*-
   +----------------------------------------------------------------------+
   | PHP Version 5                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2007 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Stig Sæther Bakken <ssb@php.net>                             |
   +----------------------------------------------------------------------+
*/

/* $Id$ */

#define CONFIGURE_COMMAND " './configure'  '--prefix=/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/php' '--enable-fpm' '--with-fpm-user=daemon' '--with-fpm-group=daemon' '--with-apxs2=/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/apache2/bin/apxs' '--with-iconv=/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/common' '--with-libxml-dir=/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/common' '--with-expat-dir=/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/common' '--with-zlib-dir=/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/common' '--enable-mbstring=all' '--enable-soap' '--enable-bcmath' '--enable-ftp' '--with-xmlrpc' '--enable-fastcgi' '--enable-force-cgi-redirect' '--enable-cgi' '--with-imap=/bitnami/mampstack-osx-x64/src/imap-2007f' '--with-imap-ssl=/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/common' '--with-dom=/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/common' '--with-png-dir=/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/common' '--with-gd' '--with-zlib' '--with-curl=/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/common' '--with-jpeg-dir=/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/common' '--enable-exif' '--with-openssl=/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/common' '--with-ldap=/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/common' '--with-freetype-dir=/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/common' '--enable-calendar' '--enable-ctype' '--enable-pcntl' '--enable-session' '--with-regex=php' '--enable-spl' '--enable-zip' '--with-bz2=/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/common' '--enable-sockets' '--with-gmp=/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/common' '--with-xsl=/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/common' '--with-mcrypt=/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/common' '--with-icu-dir=/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/common' '--with-tidy=/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/common' '--with-mysql=mysqlnd' '--with-mysqli=mysqlnd' '--with-pdo-mysql=mysqlnd' '--with-pdo_sqlite=/bitnami/mampstack-osx-x64/output/sqlite' '--with-sqlite3=/bitnami/mampstack-osx-x64/output/sqlite' '--with-gettext=/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/common'"
#define PHP_ADA_INCLUDE		""
#define PHP_ADA_LFLAGS		""
#define PHP_ADA_LIBS		""
#define PHP_APACHE_INCLUDE	""
#define PHP_APACHE_TARGET	""
#define PHP_FHTTPD_INCLUDE      ""
#define PHP_FHTTPD_LIB          ""
#define PHP_FHTTPD_TARGET       ""
#define PHP_CFLAGS		"$(CFLAGS_CLEAN) -prefer-non-pic -static"
#define PHP_DBASE_LIB		""
#define PHP_BUILD_DEBUG		""
#define PHP_GDBM_INCLUDE	""
#define PHP_IBASE_INCLUDE	""
#define PHP_IBASE_LFLAGS	""
#define PHP_IBASE_LIBS		""
#define PHP_IFX_INCLUDE		""
#define PHP_IFX_LFLAGS		""
#define PHP_IFX_LIBS		""
#define PHP_INSTALL_IT		"$(mkinstalldirs) '$(INSTALL_ROOT)/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/apache2/modules' &&                 $(mkinstalldirs) '$(INSTALL_ROOT)/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/apache2/conf' &&                  /Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/apache2/bin/apxs -S LIBEXECDIR='$(INSTALL_ROOT)/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/apache2/modules'                        -S SYSCONFDIR='$(INSTALL_ROOT)/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/apache2/conf'                        -i -a -n php5 libs/libphp5.so"
#define PHP_IODBC_INCLUDE	""
#define PHP_IODBC_LFLAGS	""
#define PHP_IODBC_LIBS		""
#define PHP_MSQL_INCLUDE	""
#define PHP_MSQL_LFLAGS		""
#define PHP_MSQL_LIBS		""
#define PHP_MYSQL_INCLUDE	""
#define PHP_MYSQL_LIBS		""
#define PHP_MYSQL_TYPE		""
#define PHP_ODBC_INCLUDE	""
#define PHP_ODBC_LFLAGS		""
#define PHP_ODBC_LIBS		""
#define PHP_ODBC_TYPE		""
#define PHP_OCI8_SHARED_LIBADD 	""
#define PHP_OCI8_DIR			""
#define PHP_OCI8_ORACLE_VERSION		""
#define PHP_ORACLE_SHARED_LIBADD 	"@ORACLE_SHARED_LIBADD@"
#define PHP_ORACLE_DIR				"@ORACLE_DIR@"
#define PHP_ORACLE_VERSION			"@ORACLE_VERSION@"
#define PHP_PGSQL_INCLUDE	""
#define PHP_PGSQL_LFLAGS	""
#define PHP_PGSQL_LIBS		""
#define PHP_PROG_SENDMAIL	"/usr/bin/sendmail"
#define PHP_SOLID_INCLUDE	""
#define PHP_SOLID_LIBS		""
#define PHP_EMPRESS_INCLUDE	""
#define PHP_EMPRESS_LIBS	""
#define PHP_SYBASE_INCLUDE	""
#define PHP_SYBASE_LFLAGS	""
#define PHP_SYBASE_LIBS		""
#define PHP_DBM_TYPE		""
#define PHP_DBM_LIB		""
#define PHP_LDAP_LFLAGS		""
#define PHP_LDAP_INCLUDE	""
#define PHP_LDAP_LIBS		""
#define PHP_BIRDSTEP_INCLUDE     ""
#define PHP_BIRDSTEP_LIBS        ""
#define PEAR_INSTALLDIR         "/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/php/lib/php"
#define PHP_INCLUDE_PATH	".:/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/php/lib/php"
#define PHP_EXTENSION_DIR       "/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/php/lib/php/extensions"
#define PHP_PREFIX              "/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/php"
#define PHP_BINDIR              "/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/php/bin"
#define PHP_SBINDIR             "/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/php/sbin"
#define PHP_MANDIR              "/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/php/php/man"
#define PHP_LIBDIR              "/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/php/lib/php"
#define PHP_DATADIR             "${prefix}/share"
#define PHP_SYSCONFDIR          "/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/php/etc"
#define PHP_LOCALSTATEDIR       "/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/php/var"
#define PHP_CONFIG_FILE_PATH    "/Volumes/Data/nfs/zfs-student-3/users/2013/mlemort/mamp/php/lib"
#define PHP_CONFIG_FILE_SCAN_DIR    ""
#define PHP_SHLIB_SUFFIX        "so"

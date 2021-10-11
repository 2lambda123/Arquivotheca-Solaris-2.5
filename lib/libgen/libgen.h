/*	Copyright (c) 1988 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*
 * declarations of functions found in libgen
 */

#ifndef _LIBGEN_H
#define	_LIBGEN_H

#pragma ident	"@(#)libgen.h	1.11	93/11/10 SMI"	/* SVr4.0 2.4.2.8 */

#include <sys/types.h>
#include <stdio.h>
#include <time.h>

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef __STDC__
extern char * basename(char *);
#else
extern char * basename();
#endif

#ifdef __STDC__
extern char * bgets(char *, size_t, FILE *, char *);
#else
extern char * bgets();
#endif

#ifdef __STDC__
extern size_t bufsplit(char *, size_t, char **);
#else
extern size_t bufsplit();
#endif

#ifdef __STDC__
extern char * copylist(const char *, off_t *);
#else
extern char * copylist();
#endif

#ifdef __STDC__
extern char * dirname(char *);
#else
extern char * dirname();
#endif

#ifdef __STDC__
extern int eaccess(const char *, int);
#else
extern int eaccess();
#endif

#ifdef __STDC__
extern int gmatch(const char *, const char *);
#else
extern int gmatch();
#endif

#ifdef __STDC__
extern int isencrypt(const char *, size_t);
#else
extern int isencrypt();
#endif

#ifdef __STDC__
extern int mkdirp(const char *, mode_t);
#else
extern int mkdirp();
#endif

#ifdef __STDC__
extern int p2open(const char *, FILE *[2]);
#else
extern int p2open();
#endif

#ifdef __STDC__
extern int p2close(FILE *[2]);
#else
extern int p2close();
#endif

#ifdef __STDC__
extern char * pathfind(const char *, const char *, const char *);
#else
extern char * pathfind();
#endif

#ifdef __STDC__
extern char * regcmp(const char *, ...);
#else
extern char * regcmp();
#endif

#ifdef _REENTRANT
#define	__i_size (*(___i_size()))
#else
extern int __i_size;
#endif

#ifdef __STDC__
extern char * regex(const char *, const char *, ...);
#else
extern char * regex();
#endif

#ifdef _REENTRANT
#define	__loc1 (*(____loc1()))
#else
extern char *__loc1;
#endif

#ifdef __STDC__
extern int rmdirp(char *, char *);
#else
extern int rmdirp();
#endif

#ifdef __STDC__
extern char * strcadd(char *, const char *);
#else
extern char * strcadd();
#endif

#ifdef __STDC__
extern char * strccpy(char *, const char *);
#else
extern char * strccpy();
#endif

#ifdef __STDC__
extern char * streadd(char *, const char *, const char *);
#else
extern char * streadd();
#endif

#ifdef __STDC__
extern char * strecpy(char *, const char *, const char *);
#else
extern char * strecpy();
#endif

#ifdef __STDC__
extern int strfind(const char *, const char *);
#else
extern int strfind();
#endif

#ifdef __STDC__
extern char * strrspn(const char *, const char *);
#else
extern char * strrspn();
#endif

#ifdef __STDC__
extern char * strtrns(const char *, const char *, const char *, char *);
#else
extern char * strtrns();
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* _LIBGEN_H */
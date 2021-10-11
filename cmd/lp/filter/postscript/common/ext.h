/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

#ident	"@(#)ext.h	1.3	90/03/02 SMI"	/* SVr4.0 1.1	*/

/*
 *
 * External varible declarations - many are defined in glob.c.
 *
 */


extern char	**argv;			/* global so everyone can use them */
extern int	argc;

extern int	x_stat;			/* program exit status */
extern int	debug;			/* debug flag */
extern int	ignore;			/* what we do with FATAL errors */

extern long	lineno;			/* line number */
extern long	position;		/* byte position */
extern char	*prog_name;		/* and program name - for errors */
extern char	*temp_file;		/* temporary file - for some programs */


extern char	*optarg;		/* for getopt() */
extern int	optind;

extern char	*malloc();
extern char	*calloc();
extern char	*tempnam();
extern char	*strtok();
extern long	ftell();
extern double	atof();
extern double	sqrt();
extern double	atan2();

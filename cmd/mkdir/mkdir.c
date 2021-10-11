/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T		*/
/*	  All Rights Reserved					*/
/*								*/
/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

#ident	"@(#)mkdir.c	1.17	94/12/06 SMI"	/* SVr4.0 1.7.7.3	*/

/*
** make directory.
** If -m is used with a valid mode, directories will be
** created in that mode.  Otherwise, the default mode will
** be 777 possibly altered by the process's file mode creation
** mask.
** If -p is used, make the directory as well as
** its non-existing parent directories.
*/

#include	<signal.h>
#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<errno.h>
#include	<string.h>
#include	<locale.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<libgen.h>
#include	<stdarg.h>
#include	<wchar.h>

#define	MSGEXISTS	"\"%s\": Exists but is not a directory\n"
#define	MSGUSAGE 	"usage: mkdir [-m mode] [-p] dirname ...\n"
#define	MSGFMT1  	"\"%s\": %s\n"
#define	MSGFAILED	"Failed to make directory \"%s\"; %s\n"

extern int optind,  errno;
extern char *optarg;

static char
*simplify(char *path);

void
errmsg(int severity, int code, char *format, ...);

extern mode_t
newmode(char *ms, mode_t new_mode, mode_t umsk, char *file);

#define	ALLRWX (S_IRWXU | S_IRWXG | S_IRWXO)


void
main(int argc, char *argv[])
{
	int 	pflag, errflg, mflag;
	int 	c, local_errno, tmp_errno;
	mode_t	cur_umask;
	mode_t	intermediate_mode;
	mode_t	mode;
	char 	*d;
	struct stat	buf;

	pflag = mflag = errflg = 0;
	local_errno = 0;

	(void) setlocale(LC_ALL, "");

#if	!defined(TEXT_DOMAIN)	/* Should be defined by cc -D */
#define	TEXT_DOMAIN "SYS_TEST"	/* Use this only if it weren't */
#endif

	(void) textdomain(TEXT_DOMAIN);

	cur_umask = umask(0);

	mode = ALLRWX;
	intermediate_mode = ((~cur_umask) | S_IXUSR | S_IWUSR) & 07777;

	while ((c = getopt(argc, argv, "m:p")) != EOF) {
		switch (c) {
		case 'm':
			mflag++;
			mode = newmode(optarg, ALLRWX, cur_umask, "");
			break;
		case 'p':
			pflag++;
			break;
		case '?':
			errflg++;
			break;
		}
	}

	if (!mflag) {
		mode &= (~cur_umask);
	}

	argc -= optind;
	if (argc < 1 || errflg) {
		errmsg(0, 2, gettext(MSGUSAGE));
	}
	argv = &argv[optind];

	errno = 0;
	while (argc--) {
		if ((d = simplify(*argv++)) == NULL) {
			exit(2);
		}

		/*
		 * When -p is set, invokes mkdirp library routine.
		 * Although successfully invoked, mkdirp sets errno to ENOENT
		 * if one of the directory in the pathname does not exist,
		 * thus creates a confusion on success/failure status
		 * possibly checked by the calling routine or shell.
		 * Therefore, errno is reset only when
		 * mkdirp has executed successfully, otherwise save
		 * in local_errno.
		 */
		if (pflag) {
			/*
			 * POSIX.2 says that it is not an error if
			 * the argument names an existing directory.
			 * We will, however, complain if the argument
			 * exists but is not a directory.
			 */
			if (lstat(d, &buf) != -1) {
				if (S_ISDIR(buf.st_mode)) {
					continue;
				} else {
					local_errno = EEXIST;
					errmsg(0, 0, gettext(MSGEXISTS), d);
					continue;
				}
			}
			errno = 0;

			if (mkdirp(d, intermediate_mode) < 0) {
				tmp_errno = errno;

				if (tmp_errno == EEXIST) {
					if (lstat(d, &buf) != -1) {
						if (! S_ISDIR(buf.st_mode)) {
							local_errno =
							    tmp_errno;
							errmsg(0, 0, gettext(
							    MSGEXISTS), d);
							continue;
						}
						/* S_ISDIR: do nothing */
					} else {
						local_errno = tmp_errno;
						perror("mkdir");
						errmsg(0, 0,
						    gettext(MSGFAILED), d,
						    strerror(local_errno));
						continue;
					}
				} else {
					local_errno = tmp_errno;
					errmsg(0, 0, gettext(MSGFMT1), d,
					    strerror(tmp_errno));
					continue;
				}
			}

			errno = 0;

			if (chmod(d, mode) < 0) {
				tmp_errno = errno;
				local_errno = errno;
				errmsg(0, 0, gettext(MSGFMT1), d,
				    strerror(tmp_errno));
				continue;
			}

			errno = 0;
			continue;
		} else {
			/*
			 * No -p. Make only one directory
			 */

			errno = 0;

			if (mkdir(d, mode) < 0) {
				local_errno = tmp_errno = errno;
				errmsg(0, 0, gettext(MSGFAILED), d,
				    strerror(tmp_errno));
				continue;
			}
		}
	} /* end while */

	/* When pflag is set, the errno is saved in local_errno */

	if (local_errno)
	    errno = local_errno;
	exit(errno ? 2: 0);
}

/*
 *  errmsg - This is an interface required by the code common to mkdir and
 *           chmod.  The severity parameter is ignored here, but is meaningful
 *           to chmod.
 */

void
errmsg(int severity, int code, char *format, ...)
{
	va_list ap;
	va_start(ap, format);

	(void) fprintf(stderr, "mkdir: ");
	(void) vfprintf(stderr, format, ap);

	va_end(ap);

	if (code > 0) {
		exit(code);
	}
}

/*
 *	simplify - given a pathname in a writable buffer, simplify that
 *		   path by removing meaningless occurances of path
 *		   syntax.
 *
 *		   The change happens in place in the argument.  The
 *		   result is neceassarily no longer than the original.
 *
 *		   Return the pointer supplied by the caller on success, or
 *		   NULL on error.
 *
 *		   The caller should handle error reporting based upon the
 *		   returned vlaue.
 */

static char *
simplify(char * mbPath)
{
	int i;
	size_t mbPathlen;	/* length of multi-byte path */
	size_t wcPathlen;	/* length of wide-character path */
	wchar_t *wptr;		/* scratch pointer */
	wchar_t *wcPath;	/* wide-character version of the path */

	/*
	 *  bail out if there is nothing there.
	 */

	if (!mbPath)
	    return (mbPath);

	/*
	 *  convert the multi-byte version of the path to a
	 *  wide-character rendering, for doing our figuring.
	 */

	mbPathlen = strlen(mbPath);

	if ((wcPath = calloc(sizeof (wchar_t), mbPathlen+1)) == NULL) {
		perror("mkdir");
		exit(2);
	}

	if ((wcPathlen = mbstowcs(wcPath, mbPath, mbPathlen)) == -1) {
		free(wcPath);
		return (NULL);
	}

	/*
	 *  remove duplicate slashes first ("//../" -> "/")
	 */

	for (wptr = wcPath, i = 0; i < wcPathlen; i++) {
		*wptr++ = wcPath[i];

		if (wcPath[i] == '/') {
			i++;

			while (wcPath[i] == '/') {
				i++;
			}

			i--;
		}
	}

	*wptr = '\0';

	/*
	 *  next skip initial occurances of "./"
	 */

	for (wcPathlen = wcslen(wcPath), wptr = wcPath, i = 0;
	    i < wcPathlen-2 && wcPath[i] == '.' && wcPath[i+1] == '/';
	    i += 2) {
		/* empty body */
	}

	/*
	 *  now make reductions of various forms.
	 */

	while (i < wcPathlen) {
		if (i < wcPathlen-2 && wcPath[i] == '/' &&
		    wcPath[i+1] == '.' && wcPath[i+2] == '/') {
			/* "/./" -> "/" */
			i += 2;
		} else if (i == wcPathlen-1 && wcPath[i] == '/') {
			/* "/$" -> "" */
			i++;
		} else {
			/* Normal case: copy the character */
			*wptr++ = wcPath[i++];
		}
	}

	*wptr = '\0';

	/*
	 *  now convert back to the multi-byte format.
	 */

	if (wcstombs(mbPath, wcPath, mbPathlen) == -1) {
		free(wcPath);
		return (NULL);
	}

	free(wcPath);
	return (mbPath);
}
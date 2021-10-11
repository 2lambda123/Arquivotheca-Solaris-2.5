/*  Copyright (c) 1988 AT&T */
/*    All Rights Reserved   */

/*  THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T */
/*  The copyright notice above does not evidence any    */
/*  actual or intended publication of such source code. */

#ident  "@(#)mbstowcs.c 1.1 93/05/05 SMI"
 
/*LINTLIBRARY*/

#include <widec.h>
#include "synonyms.h"
#include <stdlib.h>

size_t
_curs_mbstowcs(pwcs, s, n)
wchar_t	*pwcs;
const char *s;
size_t n;
{
	int	i, val;

	for (i = 0; i < n; i++) {
		if ((val = _curs_mbtowc(pwcs++, s, MB_CUR_MAX)) == -1)
			return(val);
		if (val == 0)
			break;
		s += val;
	}
	return(i);
}
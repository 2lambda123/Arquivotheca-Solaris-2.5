/*
 * Copyright (c) 1993 by Sun Microsystems, Inc.
 */

/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef	_AUTOFS_PROT_H_RPCGEN
#define	_AUTOFS_PROT_H_RPCGEN

#pragma ident	"@(#)autofs_prot.h	1.4	94/11/14 SMI"

#include <rpc/rpc.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define	A_MAXNAME 255
#define	A_MAXOPT 255
#define	A_MAXPATH 1024

struct mntrequest {
	char *name;
	char *map;
	char *opts;
	char *path;
};
typedef struct mntrequest mntrequest;

struct mntres {
	int status;
};
typedef struct mntres mntres;

struct umntrequest {
	u_int isdirect;
	u_int devid;
	u_long rdevid;
	struct umntrequest *next;
};
typedef struct umntrequest umntrequest;

struct umntres {
	int status;
};
typedef struct umntres umntres;

#define	AUTOFS_PROG ((u_long)100099)
#define	AUTOFS_VERS ((u_long)1)
#define	AUTOFS_MOUNT ((u_long)1)
#define	AUTOFS_UNMOUNT ((u_long)2)

extern  mntres * autofs_mount_1();
extern  umntres * autofs_unmount_1();

/* the xdr functions */
bool_t xdr_mntrequest();
bool_t xdr_mntres();
bool_t xdr_umntrequest();
bool_t xdr_umntres();

#ifdef	__cplusplus
}
#endif

#endif	/* !_AUTOFS_PROT_H_RPCGEN */
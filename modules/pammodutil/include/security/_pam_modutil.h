#ifndef _PAM_MODUTIL_H
#define _PAM_MODUTIL_H

/*
 * $Id: _pam_modutil.h,v 1.2 2003/01/14 05:43:08 agmorgan Exp $
 *
 * This file is a list of handy libc wrappers that attempt to provide some
 * thread-safe and other convenient functionality to modules in a form that
 * is common, but not dynamically linked with yet another dynamic pam
 * library extension.
 *
 * A number of these functions reserve space in a pam_[sg]et_data item.
 * In all cases, the name of the item is prefixed with "_pammodutil_*".
 *
 * On systems that simply can't support thread safe programming, these
 * functions don't support it either - sorry.
 *
 * Copyright (c) 2001-2002 Andrew Morgan <morgan@kernel.org>
 */

#include <pwd.h>
#include <sys/types.h>

extern struct passwd *_pammodutil_getpwnam(pam_handle_t *pamh,
					   const char *user);

extern struct passwd *_pammodutil_getpwuid(pam_handle_t *pamh,
					   uid_t uid);

extern void _pammodutil_cleanup(pam_handle_t *pamh, void *data,
				int error_status);

extern const char *_pammodutil_getlogin(pam_handle_t *pamh);

#endif /* _PAM_MODUTIL_H */

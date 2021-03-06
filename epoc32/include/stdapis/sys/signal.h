/*-
 * Copyright (c) 1982, 1986, 1989, 1991, 1993
 *	The Regents of the University of California.  All rights reserved.
 * (c) UNIX System Laboratories, Inc.
 * All or some portions of this file are derived from material licensed
 * to the University of California by American Telephone and Telegraph
 * Co. or Unix System Laboratories, Inc. and are reproduced herein with
 * the permission of UNIX System Laboratories, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)signal.h	8.4 (Berkeley) 5/4/95
 * $FreeBSD: src/sys/sys/signal.h,v 1.45 2004/06/11 11:43:46 phk Exp $
 */

#ifndef _SYS_SIGNAL_H_
#define	_SYS_SIGNAL_H_

#include <sys/cdefs.h>
#include <sys/_types.h>
#include <sys/_sigset.h>

#include <stdapis/machine/signal.h>	/* sig_atomic_t; trap codes; sigcontext */

/*
 * System defined signals.
 */
#define	SIGHUP		1	/* hangup */
#define	SIGINT		2	/* interrupt */
#define	SIGQUIT		3	/* quit */
#define	SIGILL		4	/* illegal instr. (not reset when caught) */
#define	SIGTRAP		5	/* trace trap (not reset when caught) */
#define	SIGABRT		6	/* abort() */
#define	SIGIOT		SIGABRT	/* compatibility */
#define	SIGEMT		7	/* EMT instruction */
#define	SIGFPE		8	/* floating point exception */
#define	SIGKILL		9	/* kill (cannot be caught or ignored) */
#define	SIGBUS		10	/* bus error */
#define	SIGSEGV		11	/* segmentation violation */
#define	SIGSYS		12	/* non-existent system call invoked */
#define	SIGPIPE		13	/* write on a pipe with no one to read it */
#define	SIGALRM		14	/* alarm clock */
#define	SIGTERM		15	/* software termination signal from kill */
#define	SIGURG		16	/* urgent condition on IO channel */
#define	SIGSTOP		17	/* sendable stop signal not from tty */
#define	SIGTSTP		18	/* stop signal from tty */
#define	SIGCONT		19	/* continue a stopped process */
#define	SIGCHLD		20	/* to parent on child stop or exit */
#define	SIGTTIN		21	/* to readers pgrp upon background tty read */
#define	SIGTTOU		22	/* like TTIN if (tp->t_local&LTOSTOP) */
#define	SIGIO		23	/* input/output possible signal */
#define	SIGXCPU		24	/* exceeded CPU time limit */
#define	SIGXFSZ		25	/* exceeded file size limit */
#define	SIGVTALRM	26	/* virtual time alarm */
#define	SIGPROF		27	/* profiling time alarm */
#define	SIGWINCH	28	/* window size changes */
#define	SIGINFO		29	/* information request */
#define	SIGUSR1		30	/* user defined signal 1 */
#define	SIGUSR2		31	/* user defined signal 2 */
#define	SIGTHR		32	/* Thread interrupt. */

#define SIGRTMIN	33
#define SIGRTMAX	64
/*
 * XXX missing SIGRTMIN, SIGRTMAX.
 */

#define	SIG_DFL		((__sighandler_t *)0)
#define	SIG_IGN		((__sighandler_t *)1)
#define	SIG_ERR		((__sighandler_t *)-1)
#define	SIG_HOLD	((__sighandler_t *)3)


/*
 * XXX missing SIG_HOLD.
 */

/*-
 * Type of a signal handling function.
 *
 * Language spec sez signal handlers take exactly one arg, even though we
 * actually supply three.  Ugh!
 *
 * We don't try to hide the difference by leaving out the args because
 * that would cause warnings about conformant programs.  Nonconformant
 * programs can avoid the warnings by casting to (__sighandler_t *) or
 * sig_t before calling signal() or assigning to sa_handler or sv_handler.
 *
 * The kernel should reverse the cast before calling the function.  It
 * has no way to do this, but on most machines 1-arg and 3-arg functions
 * have the same calling protocol so there is no problem in practice.
 * A bit in sa_flags could be used to specify the number of args.
 */
typedef	void __sighandler_t(int);

#ifndef _SIGSET_T_DECLARED
#define	_SIGSET_T_DECLARED
typedef	__uint64_t sigset_t;
#endif

#if __POSIX_VISIBLE || __XSI_VISIBLE
struct __siginfo_t;

/*
 * Signal vector "template" used in sigaction call.
 */
struct sigaction {
	union {
		void    (*_sa_handler)(int);
		void    (*_sa_sigaction)(int, struct __siginfo_t*, void *);
	} _sa_u;		/* signal handler */
	int	sa_flags;		/* see signal options below */
	sigset_t sa_mask;		/* signal mask to apply */
};

#define	sa_handler		_sa_u._sa_handler
#define sa_sigaction 	_sa_u._sa_sigaction

#endif

#if __POSIX_VISIBLE || __XSI_VISIBLE
#define	SA_NOCLDSTOP	0x0008	/* do not generate SIGCHLD on child stop */
#endif /* __POSIX_VISIBLE || __XSI_VISIBLE */

#if __XSI_VISIBLE
#define	SA_ONSTACK	0x0001	/* take signal on signal stack */
#define	SA_RESTART	0x0002	/* restart system call on signal return */
#define	SA_RESETHAND	0x0004	/* reset to SIG_DFL when taking signal */
#define	SA_NODEFER	0x0010	/* don't mask the signal we're delivering */
#define	SA_NOCLDWAIT	0x0020	/* don't keep zombies around */
#define	SA_SIGINFO	0x0040	/* signal handler with SA_SIGINFO args */
#endif

#if __BSD_VISIBLE
#define	NSIG		32	/* number of old signals (counting 0) */
#endif

#endif /* !_SYS_SIGNAL_H_ */

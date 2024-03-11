/* Fault handler information.  Linux/PowerPC version when it supports POSIX.
   Copyright (C) 2002, 2009, 2017  Bruno Haible <bruno@clisp.org>

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

#include "fault-posix-ucontext.h"

/* See glibc/sysdeps/unix/sysv/linux/powerpc/sys/ucontext.h
   and the definition of GET_STACK in
   glibc/sysdeps/unix/sysv/linux/powerpc/sigcontextinfo.h.
   Note that the 'mcontext_t' defined in
   glibc/sysdeps/unix/sysv/linux/powerpc/sys/ucontext.h,
   the 'struct sigcontext' defined in <asm/sigcontext.h>,
   and the 'struct pt_regs' defined in <asm/ptrace.h>
   are quite different types.  */

#if defined(__powerpc64__) || defined(_ARCH_PPC64) /* 64-bit */
# define SIGSEGV_FAULT_STACKPOINTER  ((ucontext_t *) ucp)->uc_mcontext.gp_regs[1]
#else /* 32-bit */
/* both should be equivalent */
# if 0
#  define SIGSEGV_FAULT_STACKPOINTER  ((ucontext_t *) ucp)->uc_mcontext.regs->gpr[1]
# else
#  define SIGSEGV_FAULT_STACKPOINTER  ((ucontext_t *) ucp)->uc_mcontext.uc_regs->gregs[1]
# endif
#endif

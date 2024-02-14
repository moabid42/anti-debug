#include "syscalls.h"

// syscall_weak(write,write,__libc_write)

// Pass auf die Syscalls auf :D

.text;
.type __libc_write,@function;
.global __libc_write;
__libc_write:
.ifge __NR_write-256 ;
	mov	$__NR_write,%ax;
	jmp	__unified_syscall_16bit;
.else ;
	mov	$__NR_write,%al;
	jmp	__unified_syscall;
.endif

#include "syscalls.h"

// syscall_weak(write,write,__libc_write)

.extern write_syscall_rand

.text;
.type __libc_write,@function;
.global __libc_write;
__libc_write:
	lea write_syscall_rand(%rip), %rax
	add $4, %rax
	movl (%rax), %eax

	movzx %ax,%eax
	jmp	__unified_syscall_16bit;

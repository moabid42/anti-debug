#pragma once

extern int write_syscall_rand[331];
int write_syscall_rand[331];


// .text;
// .type __libc_write,@function;
// .global __libc_write;
// __libc_write:

// .ifge __NR_write-256 ;
// 	mov	$__NR_write,%ax;
// 	jmp	__unified_syscall_16bit;
// .else ;
// 	mov	$__NR_write,%al;
// 	jmp	__unified_syscall;
// .endif
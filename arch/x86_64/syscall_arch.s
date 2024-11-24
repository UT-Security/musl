.global __syscall_asm
.hidden __syscall_asm
.type __syscall_asm, @function
__syscall:
	movq %r8, %r10
	movq %r9, %r8
	movq %rdi, %rax
	movq %rsi, %rdi
	movq %rdx, %rsi
	movq %rcx, %rdx
	movq 8(%rsp), %r9
	syscall
	ret

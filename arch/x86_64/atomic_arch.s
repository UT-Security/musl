	.text
	.p2align 4
	.globl	a_cas
	.hidden a_cas
	.type	a_cas, @function
a_cas:
.LFB0:
	.cfi_startproc
	movl	%esi, %eax
	lock ; cmpxchg %edx, (%rdi)
	ret
	.cfi_endproc
.LFE0:
	.size	a_cas, .-a_cas
	.p2align 4
	.globl	a_cas_p
	.hidden a_cas_p
	.type	a_cas_p, @function
a_cas_p:
.LFB1:
	.cfi_startproc
	movq %rsi, %rax
	lock ; cmpxchg %rdx, (%rdi)
	ret
	.cfi_endproc
.LFE1:
	.size	a_cas_p, .-a_cas_p
	.p2align 4
	.globl	a_swap
	.hidden a_swap
	.type	a_swap, @function
a_swap:
.LFB2:
	.cfi_startproc
	movl %esi, %eax
	xchg %eax, (%rdi)
	ret
	.cfi_endproc
.LFE2:
	.size	a_swap, .-a_swap
	.p2align 4
	.globl	a_fetch_add
	.hidden a_fetch_add
	.type	a_fetch_add, @function
a_fetch_add:
.LFB3:
	.cfi_startproc
	movl	%esi, %eax
	lock ; xadd %eax, (%rdi)
	ret
	.cfi_endproc
.LFE3:
	.size	a_fetch_add, .-a_fetch_add
	.p2align 4
	.globl	a_and
	.hidden a_and
	.type	a_and, @function
a_and:
.LFB4:
	.cfi_startproc
	lock ; and %esi, (%rdi)
	ret
	.cfi_endproc
.LFE4:
	.size	a_and, .-a_and
	.p2align 4
	.globl	a_or
	.type	a_or, @function
a_or:
.LFB5:
	.cfi_startproc
	lock ; or %esi, (%rdi)
	ret
	.cfi_endproc
.LFE5:
	.size	a_or, .-a_or
	.p2align 4
	.globl	a_and_64
	.hidden a_and_64
	.type	a_and_64, @function
a_and_64:
.LFB6:
	.cfi_startproc
	lock ; and %rsi, (%rdi)
	ret
	.cfi_endproc
.LFE6:
	.size	a_and_64, .-a_and_64
	.p2align 4
	.globl	a_or_64
	.hidden a_or_64
	.type	a_or_64, @function
a_or_64:
.LFB7:
	.cfi_startproc
	lock ; or %rsi, (%rdi)
	ret
	.cfi_endproc
.LFE7:
	.size	a_or_64, .-a_or_64
	.p2align 4
	.globl	a_inc
	.hidden a_inc
	.type	a_inc, @function
a_inc:
.LFB8:
	.cfi_startproc
	lock ; incl (%rdi)
	ret
	.cfi_endproc
.LFE8:
	.size	a_inc, .-a_inc
	.p2align 4
	.globl	a_dec
	.hidden a_dec
	.type	a_dec, @function
a_dec:
.LFB9:
	.cfi_startproc
	lock ; decl (%rdi)
	ret
	.cfi_endproc
.LFE9:
	.size	a_dec, .-a_dec
	.p2align 4
	.globl	a_store
	.hidden a_store
	.type	a_store, @function
a_store:
.LFB10:
	.cfi_startproc
	mov %esi, (%rdi) ; lock ; orl $0,(%rsp)
	ret
	.cfi_endproc
.LFE10:
	.size	a_store, .-a_store
	.p2align 4
	.globl	a_barrier
	.hidden a_barrier
	.type	a_barrier, @function
a_barrier:
.LFB11:
	.cfi_startproc
	ret
	.cfi_endproc
.LFE11:
	.size	a_barrier, .-a_barrier
	.p2align 4
	.globl	a_spin
	.hidden a_spin
	.type	a_spin, @function
a_spin:
.LFB12:
	.cfi_startproc
	pause
	ret
	.cfi_endproc
.LFE12:
	.size	a_spin, .-a_spin
	.p2align 4
	.globl	a_crash
	.hidden a_crash
	.type	a_crash, @function
a_crash:
.LFB13:
	.cfi_startproc
	hlt
	ret
	.cfi_endproc
.LFE13:
	.size	a_crash, .-a_crash
	.p2align 4
	.globl	a_ctz_64
	.hidden a_ctz_64
	.type	a_ctz_64, @function
a_ctz_64:
.LFB14:
	.cfi_startproc
	bsf %rdi,%rax
	ret
	.cfi_endproc
.LFE14:
	.size	a_ctz_64, .-a_ctz_64
	.p2align 4
	.globl	a_clz_64
	.hidden a_clz_64
	.type	a_clz_64, @function
a_clz_64:
.LFB15:
	.cfi_startproc
	bsr %rdi,%rax ; xor $63,%rax
	ret
	.cfi_endproc
.LFE15:
	.size	a_clz_64, .-a_clz_64
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"

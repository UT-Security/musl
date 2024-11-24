	.text
	.globl	__get_tp
	.hidden	__get_tp
	.type	__get_tp, @function
__get_tp:
.LFB0:
	.cfi_startproc
	pushq %rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq %rsp, %rbp
	.cfi_def_cfa_register 6
	mov %fs:0,%rax
	movq %rax, -8(%rbp)
	movq -8(%rbp), %rax
	popq %rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	__get_tp, .-__get_tp
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"

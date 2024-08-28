.text
.global __tlsdesc_static
.hidden __tlsdesc_static
.type __tlsdesc_static,@function
__tlsdesc_static:
	mov 8(%rax),%rax
	ret

.global __tlsdesc_dynamic
.hidden __tlsdesc_dynamic
.type __tlsdesc_dynamic,@function
__tlsdesc_dynamic:
	push %rdx
	mov 8(%rax),%rdx
	mov %fs:0,%rax
	mov 8(%rax), %rax
	push %rcx
	mov (%rdx),%rcx
	mov 8(%rdx),%rdx
	add (%rax,%rcx,8),%rdx
	pop %rcx
	mov %fs:0,%rax
	sub %rax,%rdx
	mov %rdx,%rax
	pop %rdx
	ret

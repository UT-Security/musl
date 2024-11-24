#define CAT(x, y) x##y
#define XCAT(x, y) CAT(x, y)

.text
.global START
START:
	xor %rbp,%rbp
	mov %rsp,%rdi
.weak _DYNAMIC
.hidden _DYNAMIC
	lea _DYNAMIC(%rip),%rsi
	andq $-16,%rsp
	call XCAT(START, _c)

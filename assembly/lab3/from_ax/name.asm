section .text
global _start
	_start:
	mov rax, 0x412E41484D4544;
	push rax
	mov rdx, 0x7
	mov rsi, rsp
	mov rax, 0x1
	mov rdi, 0x1
	syscall
	mov rax, 0x3c
	syscall

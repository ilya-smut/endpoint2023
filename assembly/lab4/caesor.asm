section .data

	string1	db	"AAAABBBB"

section .text
global _start
_start:

	mov rdx,  0xdd
	mov rsi, dword string1
	mov rax, 0x0
	mov rdi, 0x0
	syscall

	mov rbx, dword string1
	mov rcx, [rbx]
	mov r8, 0x0303030303030303
	sub rcx, r8
	mov [rbx], rcx

	mov rdx, 0x8
	mov rsi, dword string1
	mov rax, 0x1
	mov rdi, 0x1
	syscall

	mov rax, 0x3c
	syscall


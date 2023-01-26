section .data
	msg	db	'Hello World', 10

section .text
global _start
	_start:
	mov rdx, 0xd;		Defining 13 bytes for data
	mov rsi, dword msg; 	source index register
	mov rax, 0x1;		Accumulator gets code 1 - write
	mov rdi, 0x1;		Destination index gets code 1 - console
	syscall;
	mov rax, 0x3c;		Accumulator set to stop program
	syscall


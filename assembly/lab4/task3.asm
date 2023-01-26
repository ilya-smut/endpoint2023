section .text
global _start
_start:
mov rcx, 0x31
mov rbx, 0x0a
push rcx
mov  rdx, 0x1
mov rsi, rsp
mov rax, 0x1
mov rdi, 0x1
_loop:
syscall
pop rax
jge _loop
mov rax, 0x3c
syscall

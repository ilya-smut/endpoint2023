section .data
	text1	db	"Hi, My name is Caesor"
	text2	db	"What is your name? "
	hello	db	"Nice to meet you, "
	text3	db	"Now I will encrypt your name"
	newline db	10

section .bss
	name	resb	10

section .text
	global _start
_start:
	call _printText1
	call _newLine
	call _printText2
	call _newLine
	call _getName
	call _printHello
	call _printName
	call _printText3

	mov r8, 0x0303030303030303
	mov rbx, name
	mov r9, [rbx]
	add r9, r8
	mov [rbx], r9

	call _clear

	call _printName

	call _newLine

	mov rax, 60
	mov rdi, 0
	syscall

_clear:
	xor rbx, rbx
	xor r8, r8
	xor r9, r9
	xor rax, rax
	xor rdi, rdi
	xor rsi, rsi
	xor rdx, rdx
	ret

_newLine:
	mov rax, 1
	mov rdi, 1
	mov rsi, newline
	mov rdx, 1
	syscall
	ret

_printText3:
	mov rax, 1
	mov rdi, 1
	mov rsi, text3
	mov rdx, 28
	syscall
	ret

_printHello:
	mov rax, 1
	mov rdi, 1
	mov rsi, hello
	mov rdx, 18
	syscall
	ret

_printName:
	mov rax, 1
	mov rdi, 1
	mov rsi, name
	mov rdx, 8
	syscall
	ret

_printText1:
	mov rax, 1
	mov rdi, 1
	mov rsi, text1
	mov rdx, 21
	syscall
	ret

_printText2:
	mov rax, 1
	mov rdi, 1
	mov rsi, text2
	mov rdx, 19
	syscall
	ret

_getName:
	mov rax, 0
	mov rdi, 0
	mov rsi, name
	mov rdx, 8
	syscall
	ret


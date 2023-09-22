section .data
    hello db "Hello, Holberton",10  ; 10 represents a newline character

section .text
    global _start

_start:
    ; sys_write (1) to stdout (file descriptor)
    mov rax, 1
    mov rdi, 1
    mov rsi, hello
    mov rdx, 15  ; Length of the string
    syscall

    ; sys_exit (60)
    mov rax, 60
    xor rdi, rdi  ; Exit status: 0
    syscall


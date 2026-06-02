
section .text
global _start
extern main
extern exit

_start:
    call main
    mov rdi, 0
    jmp exit

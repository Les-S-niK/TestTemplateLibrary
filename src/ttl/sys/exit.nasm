
section .text
global exit

; rdi -- status code.
exit:
    mov rax, 0x3C
    syscall


; System io calls.

section .text
global putStr
global putStrLn
global putStrN
global putChar

extern strLen

; rdi: fd.
; rsi: String to put into a fd.
; rdx: String length.
putStrN:
    mov rax, 0x01;
    syscall

    ret

; rdi: fd.
; rsi: zero-terminated String to put into a fd.
putStr:
    mov r10, rdi
    mov rdi, rsi
    call strLen

    mov rdx, rax
    mov rdi, r10
    mov rax, 0x01
    syscall

    ret

; rdi: fd
; rsi: zero-terminated String to put into a fd.
putStrLn:
    call putStr
    mov rsi, 0x0A
    call putChar
    ret

; rdi: fd
; rsi: char to put into a fd.
putChar:
    push rbp
    mov rbp, rsp 

    sub rsp, 0x08
    mov qword [rbp - 0x08], rsi
    
    mov rax, 0x01
    lea rsi, [rbp - 0x08]
    mov rdx, 0x01
    syscall

    mov rsp, rbp
    pop rbp

    ret
    


section .text
global getpid
global sendSig

getpid:
    mov rax, 0x14
    syscall

; rdi: PID.
; rsi: signal.
sendSig:
    mov rax, 0x3E
    syscall

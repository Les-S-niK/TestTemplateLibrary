

section .rodata
    STACK_FAIL_ERR_MSG: db  "Stack smashing detected. Exiting programm...", 0x00

section .text
global memset
global __stack_chk_fail

extern putStrLn
extern exit


; rdi: data pointer.
; rsi: value to fill. ( u8 )
; rdx: bytes amount.
memset:
    xor rcx, rcx
memsetLoop:
    cmp rdx, rcx 
    jz memsetExit
    mov byte [rdi + rcx], sil
    inc rcx
    jmp memsetLoop
memsetExit:
    mov rax, rdi
    ret


__stack_chk_fail:
    mov rdi, 0x01
    mov rsi, STACK_FAIL_ERR_MSG
    call putStrLn
    mov rdi, 0x01
    call exit

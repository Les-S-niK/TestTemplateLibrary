
section .text
global strLen

; rdi: zero-terminated string
strLen:
    xor rcx, rcx
strLenLoop:
    cmp byte [rdi + rcx], 0x00 
    jz strLenExit
    inc rcx
    jmp strLenLoop
strLenExit:
    mov rax, rcx
    ret

[bits 16]

enable_mem:
    mov ax, 2403h
    int 15h
    cmp ah, 0
    jne .mem_fail

    mov ax, 2402h
    int 15h
    cmp ah, 0
    jne .mem_fail

    cmp al, 1
    je .done

    mov ax, 2401h
    int 15h
    cmp ah, 0
    jne .mem_fail

    ret

.done:
    ret

.mem_fail:
    mov bx, FAIL_MSG
    call print
    hlt 

FAIL_MSG:
    db 'A20 line failed',0
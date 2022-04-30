load_disk:
    pusha
    push dx

    mov bx, KERNEL_LOCATION

    mov ah, 0x02
    mov al, dh
    mov cl, 0x02
    mov ch, 0x00
    mov dh, [DRIVE]


    int 0x13
    jc .error

    popa
    pop dx
    ret

.error:
    mov bx, ERROR_MSG
    call print
    call nl

    hlt

ERROR_MSG:
    db 'Error!', 0
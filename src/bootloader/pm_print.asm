[bits 32]

VIDEO_MEM: equ 0xb8000
WHITE_ON_BLACK: equ 0x0f

pm_print:
    pusha
    mov edx, VIDEO_MEM

.loop:
    mov al, [ebx]
    mov ah, WHITE_ON_BLACK

    cmp al, 0
    je end

    mov [edx], ax

    add edx, 2
    add ebx, 1

    jmp .loop

end:
    popa
    ret 
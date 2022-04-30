print:
    pusha 

.loop:
    mov al, [bx]
    cmp al, 0
    je done

    mov ah, 0x0e
    int 0x10

    add bx, 1
    jmp .loop

done:
    popa 
    ret

nl:
    mov ah, 0x0e

    mov al, 0x0a
    int 0x10

    mov al, 0x0d
    int 0x10
    
    ret

clear:
    pusha

    mov ax, 0x0700
    mov bh, 0x07
    mov cx, 0x0000
    mov dx, 0x184f
    int 0x10

    popa
    ret
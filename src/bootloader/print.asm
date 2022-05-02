; Logic for the print function: 
; 
; int i = 0; 'i' is the pointer in 'bx' register
; 
; while(string[i] != 0) iterate until we reach the NULL byte
; { 
;    print string[i]; printing with interrupt hex 10
;    i++; increment to next pointer in 'bx' register
; }

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
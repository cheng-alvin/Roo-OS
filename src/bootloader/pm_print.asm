[bits 32]

; Logic for pm_print function:
; 
; const unsigned char *pointer = (unsigned char*) 0xb8000; video memory address
;
; int i = 0; 'i' is the pointer for string in 'bx' register
; while(string[i] != 0) iterate until we reach the NULL byte
; {
;   *pointer = string[i]; printing character at the video memory location
;   *(pointer + 1) = 0x0f; printing the color at the video memory attribute location 
;
;   i ++; increment pointer in 'bx' register
;   pointer += 2; increment pointer in video memory
; }

VIDEO_MEM: equ 0xb8000
WHITE: equ 0x0f

pm_print:
    pusha
    mov edx, VIDEO_MEM

.loop:
    mov al, [ebx]
    mov ah, WHITE

    cmp al, 0
    je end

    mov [edx], ax

    add edx, 2
    add ebx, 1

    jmp .loop

end:
    popa
    ret 
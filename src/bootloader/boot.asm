[org 0x7c00]
[bits 16]

KERNEL_LOCATION equ 0x1000

start:
    mov bp, 0x8000
    mov sp, bp

    mov [DRIVE], dl

    call clear 

    mov bx, LOADING_MSG
    call print
    call nl

    mov dh, 5
    call load_disk

    mov bx, DISK_LOAD_COMPLETE
    call print

    call clear

    mov ah, 00h
    mov al, 03h
    int 0x10

    call pm_enter

jmp $

%include "./print.asm"
%include "./load_disk.asm"
%include "./gdt.asm"
%include "./pm_print.asm"
%include "./pm_enter.asm"

[bits 32]
PM_START:
    mov ebx, DONE_MSG
    call pm_print
    call KERNEL_LOCATION
    jmp $

DONE_MSG db '32 bit protected mode loaded.', 0

LOADING_MSG db 'Loading...', 0

DISK_LOAD_COMPLETE db 'Disk load complete.', 0

DRIVE db 0 

times 510 - ($ - $$) db 0
dw 0xaa55


[bits 16]
pm_enter:
    cli
    lgdt [gdt_descriptor]
    mov eax, cr0
    mov eax, 0x1
    mov cr0, eax
    jmp CODE_SEG:pm_init

[bits 32]
pm_init:
    mov ax, DATA_SEG 
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov ebp, 0x9000
    mov esp, ebp

    jmp PM_START
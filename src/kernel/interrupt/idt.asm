[bits 32]
[extern _idt]

GLOBAL isr1
GLOBAL load_IDT

idt_descriptor:
    dw 4095
    dq _idt

load_IDT:
    lidt[idt_descriptor]
    ret

[extern isr1Handler]
isr1:
    pusha
    call isr1Handler
    popa
    iret
[bits 32]
[extern _start]

%include "./interrupt/idt.asm"

call _start
jmp $
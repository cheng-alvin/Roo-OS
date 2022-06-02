#include "../lib/ctypes.h"
#include "./port.h"

void outb(uint_16 port, uint_8 value){
    asm volatile("outb %1, %0"
                 :
                 : "dN"(port), "a"(value));
}

uint_8 inb(uint_16 port){
    uint_8 value;
    asm volatile("inb %1, %0"
                 : "=a"(value)
                 : "dN"(port));
    return value;
}

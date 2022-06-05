#include "idt.h"
#include "../lib/ctypes.h"
#include "../drivers/port.h"
#include "../drivers/sound.h"

typedef struct IDTDescriptor IDTDescriptor;
struct IDTDescriptor
{
    uint16_t offset_1;
    uint16_t selector;
    uint8_t ist;
    uint8_t type_attributes;
    uint16_t offset_2;
    uint32_t offset_3;
    uint32_t zero;
};

extern IDTDescriptor _idt[256];
extern uint_64 isr1;
extern void load_IDT(void);

void prepareIDT()
{
    for (uint_64 i = 0; i < 256; i++)
    {
        _idt[i].offset_1 = (uint16_t)(((uint_64)&isr1 & 0x000000000000ffff));
        _idt[i].offset_2 = (uint16_t)(((uint_64)&isr1 & 0x00000000ffff0000) >> 16);
        _idt[i].offset_3 = (uint16_t)(((uint_64)&isr1 & 0xffffffff00000000) >> 32);
        _idt[i].ist = 0;
        _idt[i].selector = 0x08;
        _idt[i].type_attributes = 0x8e;
        _idt[i].zero = 0;
    }

    load_IDT();
    outb(0x21, 0xfd);
    outb(0xa1, 0xff);
    asm volatile("sti");
}

extern void isr1Handler()
{
    playSound(1000);
    inb(0x60);
    outb(0x20, 0x20);
    outb(0xa0, 0x20);
}
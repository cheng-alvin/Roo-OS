#include "./drivers/screen.h"
#include "./lib/ctypes.h"
#include "./drivers/sound.h"
#include "./interrupt/idt.h"

void _start()
{
    screenClear(0x00);
    prepareIDT();
    printString("hello", 0x0f, 1, 0);
    asm volatile("hlt");
}
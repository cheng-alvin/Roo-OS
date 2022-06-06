/*
   This is the main file of the Roo-OS kernel.
   This file includes the drivers, libraries, and then it
   does all the kernel stuff.
*/

#include "./drivers/screen.h" // Screen Driver
#include "./lib/ctypes.h"
#include "./drivers/sound.h"
#include "./interrupt/idt.h"

void _start()
{
    screenClear(0x00);          // Clear the screen to hide BIOS messages.
    prepareIDT();
    printString("hello", 0x0f, 1, 0);       // Print 'Hello'.
    asm volatile("hlt");
}

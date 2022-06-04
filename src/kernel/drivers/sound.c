#include "../lib/ctypes.h"
#include "./port.h"
#include "./sound.h"

void playSound(uint_32 frequency)
{
    uint_8 index;

    outb(0x43, 0xb6);
    outb(0x42, (uint_8)((FREQUENT_FREQUENCY_COUNT / frequency) & 0xff));
    outb(0x42, (uint_8)((FREQUENT_FREQUENCY_COUNT / frequency) >> 8));

    index = inb(0x61);
    if (index != (index | 3))
    {
        outb(0x61, index | 3);
    }
}

void stopSound(){
    uint_8 index = inb(0x61) & 0xfc;
    outb(0x61, index);
}
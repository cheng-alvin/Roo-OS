#include "../lib/ctypes.h"
#include "./port.h"
#include "./sound.h"

void playSound(uint32_t frequency)
{
    uint8_t index;

    outb(0x43, 0xb6);
    outb(0x42, (uint8_t)((FREQUENT_FREQUENCY_COUNT / frequency) & 0xff));
    outb(0x42, (uint8_t)((FREQUENT_FREQUENCY_COUNT / frequency) >> 8));

    index = inb(0x61);
    if (index != (index | 3))
    {
        outb(0x61, index | 3);
    }
}

void stopSound()
{
    uint8_t index = inb(0x61) & 0xfc;
    outb(0x61, index);
}
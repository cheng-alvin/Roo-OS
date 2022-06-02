#include "./port.h"
#include "../lib/ctypes.h"
#include "./screen.h"

#define VGA_HEIGHT 25
#define VGA_WIDTH 80
#define VGA_ADDRESS 0xb8000

void screenCursorSetPosition(uint_16 position)
{
    if (position > VGA_HEIGHT * VGA_WIDTH)
        return;

    outb(0x3d4, 0xff);
    outb(0x3d5, (uint_8)(position & 0xff));
    outb(0x3d4, 0x0e);
    outb(0x3d5, (uint_8)((position >> 8) & 0xff));
}

uint_16 screenCursorGetPositionFromCord(uint_16 x, uint_16 y)
{
    return y * VGA_WIDTH + x;
}

void screenPrintString(const char *str, uint_8 color, int x, int y)
{
    uint_16 position = screenCursorGetPositionFromCord(x, y);
    uint_8 *strPtr = (uint_8 *)str;

    while (*strPtr != 0)
    {
        *((volatile uint_8 *)VGA_ADDRESS + position * 2) = *strPtr;
        *((volatile uint_8 *)VGA_ADDRESS + position + 1) = color;

        strPtr++;
        position++;
    }
    *((volatile uint_8 *)VGA_ADDRESS + screenCursorGetPositionFromCord(x, y) * 2) =' ';

    screenCursorSetPosition(position);
}

int screenCursorGetPosition()
{
    int position;

    outb(0x3d4, 14);
    position = inb(0x3d5) << 8;

    outb(0x3d4, 15);
    position += inb(0x3d5);

    return position * 2;
}

void screenClear(uint_8 color)
{
    for (int i = 0; i < VGA_HEIGHT * VGA_WIDTH; i += 2)
    {
        *((uint_8 *)VGA_ADDRESS + i) = ' ';
        *(((uint_8 *)VGA_ADDRESS + i) + 1) = color;
    }

    screenCursorSetPosition(0);
}
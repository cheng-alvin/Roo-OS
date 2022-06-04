#include "./port.h"
#include "../lib/ctypes.h"
#include "./screen.h"

uint_16 getPositionFromCord(uint_16 x, uint_16 y)
{
    return y * VGA_WIDTH + x;
}

void printString(char *str, uint_8 color, int x, int y)
{
    uint_16 position = getPositionFromCord(x, y);
    uint_8 *strPtr = (uint_8 *)str;

    while (*strPtr != 0)
    {
        *((volatile uint_8 *)VGA_ADDRESS + position) = *strPtr;
        *((volatile uint_8 *)VGA_ADDRESS + (position + 1)) = color;

        strPtr++;
        position += 2;
    }

    *((volatile uint_8 *)VGA_ADDRESS + getPositionFromCord(x, y)) = ' ';
    *((volatile uint_8 *)VGA_ADDRESS + (getPositionFromCord(x, y) + 1)) = 0x00;

    setCursorPosition(position / 2);
}

uint_16 getXCordFromPosition(uint_16 position)
{
    return position / (2 * VGA_HEIGHT);
}

uint_16 getYCordFromPosition(uint_16 position)
{
    return (position - getXCordFromPosition(position) * 2 * VGA_HEIGHT) / 2;
}

int getCursorPosition()
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

    setCursorPosition(0);
}

void setCursorPosition(uint_16 position)
{
    if (position > VGA_HEIGHT * VGA_WIDTH)
        return;

    outb(0x3d4, 0x0f);
    outb(0x3d5, (uint_8)(position & 0xff));
    outb(0x3d4, 0x0e);
    outb(0x3d5, (uint_8)((position >> 8) & 0xff));
}
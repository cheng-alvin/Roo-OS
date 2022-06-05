#include "./port.h"
#include "../lib/ctypes.h"
#include "./screen.h"

uint16_t getPositionFromCord(uint16_t x, uint16_t y)
{
    return y * VGA_WIDTH + x;
}

void printString(char *str, uint8_t color, int x, int y)
{
    uint16_t position = getPositionFromCord(x, y);
    uint8_t *strPtr = (uint8_t *)str + 2;

    while (*strPtr != NULL)
    {

        switch (*strPtr)
        {
        case '\n':
            position = getPositionFromCord(1, getYCordFromPosition(position) / 2) - 2;
            break;

        default:
            *((volatile uint8_t *)VGA_ADDRESS + position) = *strPtr;
            *((volatile uint8_t *)VGA_ADDRESS + (position + 1)) = color;
            break;
        }

        strPtr++;
        position += 2;
    }

    setCursorPosition(position / 2);
    strPtr = NULL;
}

uint16_t getXCordFromPosition(uint16_t position)
{
    return position / (2 * VGA_HEIGHT);
}

uint16_t getYCordFromPosition(uint16_t position)
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

void screenClear(uint8_t color)
{
    for (int i = 0; i < VGA_HEIGHT * VGA_WIDTH; i += 2)
    {
        *((uint8_t *)VGA_ADDRESS + i) = ' ';
        *(((uint8_t *)VGA_ADDRESS + i) + 1) = color;
    }

    setCursorPosition(0);
}

void setCursorPosition(uint16_t position)
{
    if (position > VGA_HEIGHT * VGA_WIDTH)
        return;

    outb(0x3d4, 0x0f);
    outb(0x3d5, (uint8_t)(position & 0xff));
    outb(0x3d4, 0x0e);
    outb(0x3d5, (uint8_t)((position >> 8) & 0xff));
}
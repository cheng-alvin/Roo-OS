#include "./drivers/screen.h"
#include "./lib/ctypes.h"
#include "./drivers/sound.h"

void _start()
{
    screenClear(0x00);
    printString("Welcome!", 0x0f, 9, 8);
    printString("Welcome!", 0x0f, 1, 2);
}
#include "./drivers/screen.h"
#include "./lib/ctypes.h"
#include "./drivers/sound.h"

void _start()
{
    screenClear(0x00);
    printString("Hello", 0x0f, 9, 8);
    printString("pp", 0x0f, 9, 10);
    printString("CC", 0x0f, 9, 12);
    printString("Cpp", 0x0f, 9, 14);
}
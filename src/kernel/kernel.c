#include "./drivers/screen.h"
#include "./lib/ctypes.h"

void _start()
{
    screenClear(0x00);
    screenPrintString("Welcome to Roo-Os!", 0x0f, 1, 2);
}
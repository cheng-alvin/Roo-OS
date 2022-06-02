#include "./drivers/screen.h"
#include "./lib/ctypes.h"

void _start()
{
    screenClear(0x00);
    screenCursorSetPosition(screenCursorGetPositionFromCord(21,20));
    screenPrintString("hello", 0x0f, 21, 20);
    return;
}
#pragma once
#include "../lib/ctypes.h"

#define VGA_HEIGHT 25
#define VGA_WIDTH 80
#define VGA_ADDRESS 0xb8000

void screenCursorSetPosition(uint_16 position);
uint_16 screenCursorGetPositionFromCord(uint_16 x, uint_16 y);
void screenPrintString( char *str, uint_8 color, int x, int y);
void screenClear(uint_8 color);
int screenCursorGetPosition();
uint_16 screenGetCursorYFromPosition(uint_16 position);
uint_16 screenGetCursorXFromPosition(uint_16 position);
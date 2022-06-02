#pragma once
#include "../lib/ctypes.h"

void screenCursorSetPosition(uint_16 position);
uint_16 screenCursorGetPositionFromCord(uint_16 x, uint_16 y);
void screenPrintString(const char *str, uint_8 color, int x, int y);
void screenClear(uint_8 color);
int screenCursorGetPosition();
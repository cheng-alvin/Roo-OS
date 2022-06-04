#pragma once
#include "../lib/ctypes.h"

#define VGA_HEIGHT 25
#define VGA_WIDTH 80
#define VGA_ADDRESS 0xb8000

void setCursorPosition(uint_16 position);
uint_16 getPositionFromCord(uint_16 x, uint_16 y);
void printString(char *str, uint_8 color, int x, int y);
void screenClear(uint_8 color);
int getCursorPosition();
uint_16 getYCordFromPosition(uint_16 position);
uint_16 getXCordFromPosition(uint_16 position);
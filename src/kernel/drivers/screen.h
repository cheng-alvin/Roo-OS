#pragma once
#include "../lib/ctypes.h"

#define VGA_HEIGHT 25
#define VGA_WIDTH 80
#define VGA_ADDRESS 0xb8000

void setCursorPosition(uint16_t position);
uint16_t getPositionFromCord(uint16_t x, uint16_t y);
void printString(char *str, uint8_t color, int x, int y);
void screenClear(uint8_t color);
int getCursorPosition();
uint16_t getYCordFromPosition(uint16_t position);
uint16_t getXCordFromPosition(uint16_t position);
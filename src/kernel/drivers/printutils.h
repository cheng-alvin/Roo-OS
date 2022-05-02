#pragma once

#include "./types.h"

#define VIDEO_ADDRESS 0xb8000

#define MAX_ROWS 25
#define MAX_COLS 80
#define SCREEN_AREA MAX_ROWS * MAX_COLS

#define WHITE 0x0f
#define BLACK 0xf0
#define RED 0xf4

int printutils_get_offset(int row, int col);
int printutils_get_offset_row(int offset);
int printutils_get_offset_col(int offset);
void printutils_clear_screen();
void printutils_set_cursor_offset(int offset);
int printutils_get_cursor_offset();
void printutils_print_char(char content, int col, int row, char color);
void printutils_print_string(string content, unsigned char color);
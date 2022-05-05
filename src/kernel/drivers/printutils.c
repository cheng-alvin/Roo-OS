#include "../stdlib/ctypes.h"
#include "./port.h"
#include "./printutils.h"

int printutils_get_offset(int row, int col)
{
    return 2 * (row * MAX_COLS + col);
}

int printutils_get_offset_row(int offset)
{
    return offset / (2 * MAX_COLS);
}

int printutils_get_offset_col(int offset)
{
    return (offset - printutils_get_offset_row(offset) * 2 * MAX_COLS) / 2;
}

void printutils_set_cursor_offset(int offset)
{
    offset /= 2;
    port_byte_out(COMMAND_PORT, HIGH_BYTE);
    port_byte_out(RESULT_PORT, (unsigned char)(offset >> 8));
    port_byte_out(COMMAND_PORT, LOW_BYTE);
    port_byte_out(RESULT_PORT, (unsigned char)(offset & 0xff));
}

int printutils_get_cursor_offset()
{
    port_byte_out(COMMAND_PORT, HIGH_BYTE);
    int offset = port_byte_in(RESULT_PORT) << 8;
    port_byte_out(COMMAND_PORT, LOW_BYTE);
    offset += port_byte_in(RESULT_PORT);
    return offset * 2;
}

void printutils_print_char(char content, int col, int row, char color)
{
    char *screen = (char *)VIDEO_ADDRESS;
    int offset = printutils_get_offset(row, col);

    if (content == '\n')
    {
        row = printutils_get_offset_row(offset);
        offset = printutils_get_offset(row + 1, 0);
    }

    else
    {
        screen += offset;
        *screen = content;
        screen += 1;
        *screen = color;
    }
    printutils_set_cursor_offset(offset);
}


void printutils_clear_screen()
{
    char *screen = (char *)VIDEO_ADDRESS;

    for (int i = 0; i < SCREEN_AREA + 10; i++)
    {
        screen[i * 2] = ' ';
        screen[i * 2 + 1] = WHITE;
    }

    printutils_set_cursor_offset(printutils_get_offset(0, 0));
}

void printutils_print_string(string content, unsigned char color)
{
    int i = 0;
    while (content[i] != '\0')
    {
        printutils_print_char(content[i], printutils_get_offset_col(printutils_get_cursor_offset()) + 1, printutils_get_offset_row(printutils_get_cursor_offset()), color);
        i+= 1;
    }
}


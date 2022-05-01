#include "./drivers/printutils.h"
#include "./drivers/types.h"

void _start()
{
    printutils_clear_screen();
    printutils_print_string("hello", WHITE);
}
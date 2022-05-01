#include "./drivers/printutils.h"
#include "./drivers/types.h"

void _start()
{
    printutils_clear_screen();
    while(true){}
    // printutils_print_string("hello \0", WHITE);
}
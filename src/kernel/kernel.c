#include "./drivers/printutils.h"
#include "./drivers/types.h"
int main();

void _start()
{
    char *ptr = (char *)0xb8000;

    if (main() == 0)
    {
        __asm__("hlt");
    }

    else
    {
        // *ptr = 'E';
    }
}

int main()
{
    printutils_clear_screen();
    printutils_print_char('A', printutils_get_offset_col(printutils_get_cursor_offset()) + 1, printutils_get_offset_row(printutils_get_cursor_offset()), WHITE);
    return 0;
}

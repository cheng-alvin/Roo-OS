#include "./drivers/printutils.h"
#include "./stdlib/ctypes.h"

int main();
void _start();

void _start()
{
    if (main() == 0)
    {
        // __asm__("hlt");
    }
}

int main()
{
    string content = "hello\0";
    printutils_clear_screen();
    // printutils_print_char(content[1], printutils_get_offset_col(printutils_get_cursor_offset()) + 1, printutils_get_offset_row(printutils_get_cursor_offset()), WHITE);
    return 0;
}

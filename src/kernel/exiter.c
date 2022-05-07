#include "./drivers/printutils.h"
#include "./stdlib/ctypes.h"
#include "./exiter.h"

void succsess_exit()
{
    printutils_print_string("OS exited with no errors.\n\0", WHITE);
    stop_system();
}

void error_exit()
{
    printutils_print_string("OS exited with errors.\n\0", WHITE);
    stop_system();
}

void shut_down_exit()
{
    printutils_clear_screen();
    stop_system();
}

void stop_system()
{
    while (true)
    {
        __asm__("hlt");
    }
}
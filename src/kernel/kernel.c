#include "./drivers/printutils.h"
#include "./stdlib/ctypes.h"

int main();
void _start();

void _start()
{
    char *ptr = (char *)VIDEO_ADDRESS;

    if (main() == 0)
    {
        __asm__("hlt");
    }

    else
    {
      
        *ptr = 'E';
        ptr += 1;
        *ptr = YELLOW;
        ptr += 1;
        *ptr = 'R';
        ptr += 1;
        *ptr = YELLOW;
        ptr += 1;
        *ptr = 'R';
        ptr += 1;
        *ptr = YELLOW;
        ptr += 1;
        *ptr = 'O';
        ptr += 1;
        *ptr = YELLOW;
        ptr += 1;
        *ptr = 'R';
        ptr += 1;
        *ptr = YELLOW;
        ptr += 1;
        *ptr = '!';
        ptr += 1;
        *ptr = YELLOW;
        ptr += 1;
    }
}

int main()
{
    printutils_clear_screen();

    return -1;
}

#include "./ctypes.h"

int strlen(string str)
{
    int i = 0;
    while (str[i] != 0)
    {
        i++;
    }

    return i;
}
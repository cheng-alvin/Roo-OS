#include "./ctypes.h"

int strlen(string str)
{
    string p = str;
    for (; *p != '\0'; p++)
        ;

    return p - str;
}
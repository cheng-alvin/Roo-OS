#include "mem.h"
#include "../lib/ctypes.h"

void *memcpy(void *destination, const void *source, size_t size)
{
    char *destinationPtr = destination;
    const char *sourcePtr = source;

    for (; size > 0; size--)
    {
        *destinationPtr++ = *sourcePtr++;
    }

    return destination;
}
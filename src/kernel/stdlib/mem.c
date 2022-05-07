void mem_copy(char *src, char *dest, int bytes)
{
    for (int i = 0; i < bytes; i++)
        *(dest + i) = *(src + i);
}
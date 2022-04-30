void _start()
{
    char *mem = (char *)0xb8000;
    *mem = 'H';
    __asm__("hlt");
}
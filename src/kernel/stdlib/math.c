#include "./ctypes.h"
#include "./math.h"

double square(double x)
{
    return x * x;
}

double pow(double x, double y)
{
    double result = 1;

    for (int i = 0; i < y; i++)
    {
        result *= x;
    }

    return result;
}

double get_square_area(double x, double y)
{
    return x * y;
}

double get_cube_volume(double x, double y, double z)
{
    return x * y * z;
}

double get_circle_area(double r, bool long_pi)
{
    if (long_pi == true)
        return PI_LONG * square(r);

    if (long_pi == false)
        return PI_SHORT * square(r);
}
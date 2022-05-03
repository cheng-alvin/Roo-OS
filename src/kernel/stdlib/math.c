#include "./ctypes.h"
#include "./math.h"

float square(float x)
{
    return x * x;
}

float pow(float x, float y)
{
    float result = 1;

    for (int i = 0; i < y; i++)
    {
        result *= x;
    }

    return result;
}

float get_square_area(float x, float y)
{
    return x * y;
}

float get_cube_volume(float x, float y, float z)
{
    return x * y * z;
}

float get_circle_area(float r, bool long_pi)
{
    if (long_pi == true)
        return PI_LONG * square(r);

    if (long_pi == false)
        return PI_SHORT * square(r);
}
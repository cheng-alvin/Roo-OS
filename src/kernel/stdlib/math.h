#pragma once

#include "./ctypes.h"

#define PI_LONG 3.14159265359
#define PI_SHORT 3.14

#define E_LONG 2.71828182846
#define E_SHORT 2.71

float square(double x);
float pow(double x, double y);
float get_square_area(double x, double y);
float get_cube_volume(double x, double y, double z);
float get_circle_area(double r, bool long_pi);
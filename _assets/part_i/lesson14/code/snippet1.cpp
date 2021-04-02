#include <cstdint>
#include <iostream>

#define PI 3.1416f    /* Can be used to define constants */
#define GPS_ENABLED 1 /* Can be used as a global to enable/disable subroutines */
#define FIRMWARE_V 4  /* Can be used to denote version of hardware  software */
#define DEBUG 0
#define RAD2D(x) x * 180.0 / PI /* A Macro can be function-like, taking & pro-cessing an argument */

void update_gps() {}
void update_gps_2() {}

int main(int argc, char *argv[])
{
    float rad = 0.1;
    float circumference = 2 * PI * rad; /* Useful instead of writing 3.1416 every time */
    if (GPS_ENABLED)
    {
        update_gps();
    }
    if (FIRMWARE_V > 2)
    {
        update_gps_2();
    }
    if (DEBUG)
    {
        std::cout << "Log Message" << std::endl;
    }
    return 0;
}

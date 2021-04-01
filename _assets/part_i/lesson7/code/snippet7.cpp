#include <cstdint>
#include <iostream>

using namespace std; 
int main(int argc, char* argv[]) { 

    uint8_t input_voltage = 130;
    uint8_t output_speed;

    /* Output Speed = (Input Voltage) / 240 * 9 */
    output_speed = input_voltage / 240.0 * 9; /* Dividing by a float implicitly */
    output_speed = (float)input_voltage / 240 * 9; /* Casting to a float, then dividing by an int */

    cout << (uint16_t)output_speed << endl;
    return 0; 
}

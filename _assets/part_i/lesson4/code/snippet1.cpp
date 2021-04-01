#include <cstdint>
#include <iostream>

uint8_t g_c; /* Declaring a global variable, a good practice to use g_ prefix */
using namespace std; /* allows us to call within std namespace directly */

int main(int argc, char* argv[]) { 
    uint8_t a; /* Declaring a local variable */
    int16_t b = 300; /* Declaring AND defining (assigning a value to) a variable*/
    g_c = 4; /* Assigning a value to the global variable */
    a = g_c; /* Assigning the value of the global variable, to the local variable */
    cout << "a = " << (uint16_t)a << endl;
    cout << "b = " << b << "\n";
    return 0; 
}

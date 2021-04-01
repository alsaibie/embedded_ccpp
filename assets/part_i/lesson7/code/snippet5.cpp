#include <cstdint>
#include <iostream>

using namespace std; 

int main(int argc, char* argv[]) { 

    uint8_t a = 3;
    uint8_t b = 4; 
    float bf = 4.0;
    uint16_t c = b / a;  /* integer divide operaton, result: 1 */
    uint16_t d = a / b;  /* integer divide operaton, result: 0 */
    uint16_t e = a / bf; /* float divide operaton,   result: 0, since e is an int */
    float    f = a / bf; /* float divide operation,  result: 0.75 */
    float    g = a / b;  /* integer divide operation, result: 0, even if g is float */
    cout << g << endl;
    return 0; 
}

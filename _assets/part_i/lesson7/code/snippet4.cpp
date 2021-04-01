#include <cstdint>
#include <iostream>

using namespace std; 
int main(int argc, char* argv[]) { 
    uint8_t a = 3; uint8_t b = 4; float c = 3.0; float d = 3.001; 

    bool r1 = (a == 3) && (b == 3); /* Logical Operation, result: 0 (false), as b = 4 */
    bool r2 = (a == 3) || (b == 3); /* Logical Operation, result: 1 (true), as a = 3 */
    bool r3 = a == c; /* Logical Operation, result: 1 (true), as 3 = 3.0 */
    bool r4 = a == d; /* Logical Operation, result: 0 (false), as 3 < 3.001 */
    bool r5 = a == (uint8_t)d; /* Logical Operation, result: 1 (true), as 3 = 3 */
    bool r6 = a >= b; /* Logical Operation, result: 0 (false) */
    bool r7 = !(a >= b); /* Logical Operation, result: 1 (true) */
    return 0; 
}

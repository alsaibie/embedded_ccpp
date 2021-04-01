#include <cstdint>
#include <iostream>

using namespace std; 

int main(int argc, char* argv[]) { 

    uint8_t a = 0b00001000;
    uint8_t b = 0b10001111;
    uint8_t c = 0xF7; /* 11110111 */

    uint8_t r1 = a & b; /* AND operation, result: 00001000 */
    uint8_t r2 = a | c; /* OR operation,  result: 11111111 */
    uint8_t r3 = a ^ b; /* NOR operation, result: 10000111 */
    uint8_t r4 = ~c;    /* NOT operation, result: 00001000 */

    cout << "r1= " << hex << (int)r1 << "\n" ;
    cout << "r2= " << hex << (int)r2 << "\n" ;
    cout << "r3= " << hex << (int)r3 << "\n" ;
    cout << "r4= " << hex << (int)r4 << "\n" ;

    r1 |= b; /* OR operation, result: 10001111 */
    cout << "r1= " << hex << (int)r1 << "\n" ;
    return 0; 
}

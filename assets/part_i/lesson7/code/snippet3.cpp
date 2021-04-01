#include <cstdint>
#include <iostream>
#include <bitset>
using namespace std; 

int main(int argc, char* argv[]) { 

    uint8_t a = 0b00000100;
    uint8_t b = 0b10001111;
    uint8_t c = 0xF7; /* 11110111 */

    uint8_t r1 = a >> 2; /* Shift operation, result: 00000001 */
    uint8_t r2 = b << 4; /* Shift operation, result: 11110000 */
    uint8_t r3 = (a<<1) | c; /* Shift + OR NOR operation, result: 11111111 */
    
    bitset<8> bin(r3);
    cout << hex << bin << endl;
    return 0; 
}

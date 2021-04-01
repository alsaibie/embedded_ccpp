#include <cstdint>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) { 
    uint8_t A = 68;
    uint8_t B = '8';
    uint8_t C[6] = "Hello";
    cout << (int)A << endl; /* Output: 68 */
    cout << A << endl; /* Output: D, ASCII character, uint8_t is treated as char*/
    cout << B << endl; /* Output: 8, ASCII character */
    cout << (int)B << endl; /* Output: 56, the decimal value for the ASCII character '6' */
    cout << C << endl; /* Output: Hello */
    cout << &C << endl; /* Output: Address */
    return 0;
}


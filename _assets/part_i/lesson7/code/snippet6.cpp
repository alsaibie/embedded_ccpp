#include <cstdint>
#include <iostream>

using namespace std; 

int main(int argc, char* argv[]) { 

    uint8_t a = (3 / 4) * 4 ;      /* stored result: 0 */
    uint8_t b = (3 * 4) / 4 ;      /* stored result: 3 */
    uint8_t c = (3/(float)4) * 4 ; /* stored result: 3 */
    cout << (int)c << endl;
    return 0; 
}

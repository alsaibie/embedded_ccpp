#include <cstdint>
#include <iostream>
using namespace std;

extern uint8_t _g_a = 3; /* Variable declared and defined */

int multiplyab(void){
    extern uint8_t _g_b; /* Variable only declared but not defined here */
    return _g_a * _g_b;
}

int main(int argc, char* argv[]) { 
    cout << multiplyab() << endl; /* Output: 15 */
    return 0;
}

uint8_t _g_b = 5; /* At compile time, _g_b is not visible to above functions */

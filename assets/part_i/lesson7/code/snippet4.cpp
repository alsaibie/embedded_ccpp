#include <cstdint>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) { 
    for (int k = 0; k < 2; k++)
    {
        const static uint8_t _a_s = 4; /* Will only be initialized once, can't be altered */
        cout << (int)_a_s << endl;
    }
    return 0;
}

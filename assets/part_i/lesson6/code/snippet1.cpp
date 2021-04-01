#include <cstdint>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) { 
    
    for (int k = 0; k <3; k++){
        uint16_t _a = 3;
        static uint16_t _b = 3; /* Declaring a static variable */
        cout << _a++ << endl; /* Output: 3, 3, 3. Will be reinitialized every loop */
        cout << _b++ << endl; /* Output: 3, 4, 5. Will be initialized only once when declared */
    }
    return 0;
}

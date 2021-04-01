#include <cstdint>
#include <iostream>
using namespace std;
volatile uint8_t _g_a = 20;
uint8_t _g_b = 10;
int main(int argc, char* argv[]) { 
    for (int k = 0; k < 2; k++)
    {
        /* the compiler will not assume the volatile variable doesn't change externally */
        /* _g_a will be retrieved from its address every time its called */
        cout << (int)_g_a << endl; 
        /* The compiler may optimize and set output to 10, assuming it won't change */        
        cout << (int)_g_b << endl; 
    }
    return 0;
}

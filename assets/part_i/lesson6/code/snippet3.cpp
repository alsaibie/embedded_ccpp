#include <cstdint>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) { 
    const uint8_t a = 1;
    a = 2; /* ERROR: Code will not compile, can't assign new value to const */
    return 0;
}

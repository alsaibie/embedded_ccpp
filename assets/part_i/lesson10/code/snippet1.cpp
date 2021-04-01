#include <iostream>

int main(int argc, char *argv[]){
    int a = 3;
    int *ptr = &a; /* initializing a variable with a * (star) prefix, declares it a pointer */
    
    std::cout << a << std::endl; /* Output: 3*/
    std::cout << ptr << std::endl; /* Output: 0x64E24FF7F0 (some random hex value) */
    /* derefrencing the ptr retrieves the value stored in the address pointed to by the pointer */
    std::cout << *ptr << std::endl; /* Output: 3, the * (star) prefix derefrences a pointer */
    return 0;
}

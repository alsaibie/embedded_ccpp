#include <iostream>

int main(int argc, char *argv[]){
    uint16_t a = 3;
    uint32_t b = 3;
    uint16_t *ptr_a = &a; 
    uint32_t *ptr_b = &b;

    std::cout << ptr_a << ", " << (++ptr_a) << std::endl; /* Ptr_a incremented by 2'  */
    std::cout << ptr_b << ", " << (++ptr_b) << std::endl; /* Ptr_b incremented by 4'  */
    return 0;
}

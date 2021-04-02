#include <iostream>
#include <cstdint>

class student {
    uint32_t id; /* By default, class members are private, can only be accessed indirectly */

    public: /* Makes the following declarations (class members) public */
    student(uint32_t set_id); /* A class constructor is a function that has the same name as the class */
    ~student(){};  /* A class deconstructor has the same name as the class with a ~ prefix */
    uint32_t get_id();
};

int main(void){
    student Mona(212121); /* A class object is declared, and given the id */
    std::cout << Mona.get_id() << std::endl; 
    return 0;
}
/* The class constructor has no return element */
student::student(uint32_t set_id){
    id = set_id; /* A class constructor can be used to initialize  */
}
uint32_t student::get_id(void){
    return id;
}

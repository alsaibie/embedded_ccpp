#include <iostream>

class student { /* A class is defined by the “class” keyword */
    uint32_t id; /* By default, class members are private, can only be accessed indirectly */

    public: /* Makes the following declarations (class members) public */
    void set_id(uint32_t set_id);
    uint32_t get_id();
};

int main(void){
    student Mona; /* A class object is declared */
    Mona.set_id(212121); /* Calling a class object function, by the . (dot) character */
    std::cout << Mona.get_id() << std::endl; 
    return 0;
}
/* The class functions need to be defined, note the class_name::function_name syntax*/
void student::set_id(uint32_t set_id){
    id = set_id; /* Takes an id value and stores it in internal class object private variable */
}
uint32_t student::get_id(void){
    return id; /* returns the value of the private variable */
}

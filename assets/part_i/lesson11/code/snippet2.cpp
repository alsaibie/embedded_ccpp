#include <iostream>
#include<cstring>

struct person_t{ /* person_t is a struct type */
    int age;
    char gender;
    char name[10];
};

int main(void){
    person_t Ahmed; /* A new struct object of type person_t is created */
    Ahmed.age    = 18; /* Struct members are accessed by . (dot) character */
    Ahmed.gender = 'M';
    strcpy(Ahmed.name, "Ahmed");

    std::cout << "Name: " << Ahmed.name << ", Age:" << Ahmed.age 
    << ", Gender = " << Ahmed.gender << std::endl;

    return 0;
}


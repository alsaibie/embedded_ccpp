#include <iostream>
struct person_t{
    int age; char gender; char name[10];
}Sara;

void add_age_1(person_t &person, int age){ /* Takes struct by reference */
    person.age = age;
}
person_t add_age_2(person_t person, int age){ /* Takes a copy of struct, returns a struct */
    person.age = age;
    return person;
}

int main(void){
    person_t Ahmed; /* A a struct created here has a local scope */
    add_age_1(Sara, 19); /* Original object is manipulated */
    Ahmed = add_age_2(Ahmed, 24); /* A copy of the original object is passed */
    return 0;
}


#include <iostream>
struct person_t{
    int age; char gender; char name[10];
}Sara, Abdullah; /* Struct objects can be created, they are global */

void add_age(person_t &person, int age){
    person.age = age;
}
void sub_routine(void);

int main(void){
    person_t Ahmed; /* A a struct created here has a local scope */
    add_age(Ahmed, 24);
    sub_routine();
    return 0;
}
void sub_routine(void){
    add_age(Sara, 19); /* Global structs can be accessed here */
    add_age(Abdullah, 21);
}

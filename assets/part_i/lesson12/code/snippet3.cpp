#include <iostream>

class student {
    uint32_t id;

    public: 
    student() { id = 1000; }; /* This constructor takes no argument, perhaps a default value will be set */
    student(uint32_t set_id) { id = set_id; }; /* An alternate constructor that does take an argument */
    ~student(){};  
    uint32_t get_id();
};

int main(void){
    student Ahmed; /* The first constructor: student(), will be used */
    student Mona(121212); /* The second constructor: student(uint32_t set_id), will be used */ 
    return 0;
}

uint32_t student::get_id(void){
    return id;
}

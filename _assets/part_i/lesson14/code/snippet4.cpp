/* Quotes include looks for the header files in the working directory */
#include "my_header.h" 
/* Angle brackets are generally used for system headers */
#include <system_header.h> 

int main(int argc, char *argv[]){
    some_function_from_my_header();
    some_other_function_from_system_header();
    return 0;
}



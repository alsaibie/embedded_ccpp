#include <iostream> 

int main(int argc, char* argv[]) { /* The main function is the starting point of any C++ program */
    int a = 120; /* Variables must be declared, their type must be specificied */
    int b = 250;
    int c = a + b;
    /*In C++ std::cout is a way to print content to the output terminal */
    std::cout << "The sum of " << a <<" and " << b << " is equal to "<< c << std::endl;
    
    return 0; /* main is a function that returns a variable */
}
@def title = "I Fundamentals - Introduction"
@def hascode = true

# Why C/C++?

# C vs C++

\Ccode{sample}{
#include <stdio.h>
int main(){
    printf("Hello Pika\n");
    return 0;
}
}

\CPPexec{example_c_code}{ 
#include <iostream> 

int main(int argc, char* argv[]) { /* The main function is the starting point of any C++ program */
    int a = 120; /* Variables must be declared, their type must be specificied */
    int b = 250;
    int c = a + b;
    /*In C++ std::cout is a way to print content to the output terminal */
    std::cout << "The sum of " << a <<" and " << b << " is equal to "<< c << std::endl;
    
    return 0; /* main is a function that returns a variable */
}
}

```matlab
a = 120;
b = 300;
c = a + b;
disp("The sum of " + a + " and " + b + " is equal to " + c)
```
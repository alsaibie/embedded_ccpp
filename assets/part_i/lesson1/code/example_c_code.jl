# This file was generated, do not modify it. # hide
#hideall
using Markdown

mdC_code = Markdown.htmlesc(raw"""#include <iostream> 

int main(int argc, char* argv[]) { /* The main function is the starting point of any C++ program */
    int a = 120; /* Variables must be declared, their type must be specificied */
    int b = 250;
    int c = a + b;
    /*In C++ std::cout is a way to print content to the output terminal */
    std::cout << "The sum of " << a <<" and " << b << " is equal to "<< c << std::endl;
    
    return 0; /* main is a function that returns a variable */
}""")
mdC_code = raw"""#include <iostream> 

int main(int argc, char* argv[]) { /* The main function is the starting point of any C++ program */
    int a = 120; /* Variables must be declared, their type must be specificied */
    int b = 250;
    int c = a + b;
    /*In C++ std::cout is a way to print content to the output terminal */
    std::cout << "The sum of " << a <<" and " << b << " is equal to "<< c << std::endl;
    
    return 0; /* main is a function that returns a variable */
}"""

mdfile = joinpath(dirname(@OUTPUT), "example_c_code.md")
open(mdfile,"w") do f
    print(f, mdC_code)
end

CPP_code=raw"""
#include <iostream> 

int main(int argc, char* argv[]) { /* The main function is the starting point of any C++ program */
    int a = 120; /* Variables must be declared, their type must be specificied */
    int b = 250;
    int c = a + b;
    /*In C++ std::cout is a way to print content to the output terminal */
    std::cout << "The sum of " << a <<" and " << b << " is equal to "<< c << std::endl;
    
    return 0; /* main is a function that returns a variable */
}
"""

cppfile = joinpath(dirname(@OUTPUT), "example_c_code.cpp")

open(cppfile,"w") do f
    print(f, CPP_code)
end

exefile = tempname()

run(`g++ $cppfile -Wall -O2 -march=native -o $exefile`)

run(`$exefile`)
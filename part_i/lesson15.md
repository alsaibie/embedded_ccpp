@def title = "I Fundamentals - Standard Library"
@def hascode = true

# Standard Library
Recall the cmath or iostream or stdint or bitset headers? These are actually part of what is called the standard library, which contains a number of useful extension functionalities to C/C++.

As you probably have realized. The bare functionalities of C/C++ are quite limited. There aren’t many built in functions. 

When you need additional functions you include the relevant sources. This makes sense, since C/C++ strive to be efficient compiled languages and why include things that are not needed?

There are tons of libraries out there for C/C++, so what is special about the standard library? Well, for one they are standard, they are supported and updated by the languages’ standards committees. This ensures consistency and uniformity in the language application. They can be thought of as part of the language as well. 

It is worth noting that as of this recording, the latest C programming standard is C11 (from 2011) and the latest C++ standard a soon to be release C20 (from 2020). 
C++ implementations that leverage the major changes from 2011 are referred to as modern C++, but that description will drop with time of course. 
## Math Libraries
As engineers we are likely to implement some math functions in our code. The math library contains a set of common functions. Functions such sine cosine power square root, logs and exponentials. And a host of other functions. 

There are several resources online that list all the functionalities of the standard libraries such as cplusplus.com & cppreference.com. 

Note that, if coming from MATLAB, you are probably used to manipulating matrices out of the box. There are no built in matrix library in C/C++. In C++ there are several third party libraries and one commonly used is Eigen

## Vectors
When you want to store / iterate and manipulate a sequence of items, be it variables, including pointers to functions, classes and other elements. 

These are not mathematical vectors. They are similar to arrays in that they store elements in a contiguous storage location, but unlike arrays, they are dynamically sized. 

While the program is running you can shift, iterate, insert, swap, pop from the vector. And these functionalities are built into the vector container. As you would expect, vectors consume more memory compared to arrays.

## Input/Output

The iostream defines the basic input/output interface functions. 

We have seen how cout is used to print characters and numbers to the terminal. We can use cin to read characters IN from the terminal. 

There is also clog which outputs characters for logging and cerr for errors, these can be routed to different locations. The log outputs may be routed to a log file and the error may be formatted in the output with a different color. 

```cpp
#include <cstdint>
#include <iostream>
int main(int argc, char *argv[]){
    uint8_t c;
    std::cin >> c;
    std::cout << c << std::endl; /* Outputs inputted character */
    return 1;
}

```

## Data Types
An essential standard library is the cstdint library. It actually might be indirectly included if you include other standard library headers. This varies and depends on the platform you are working on. 

<cstdint> Defines a set of integral type aliases with specific width requirements, such as:
- uint8_t: unsigned integer of 1 byte size
- int16_t: signed integer of 2 byte size
- intmax_t: signed integer of max size supported on platform 
- uint_least32_t: unsigned of at least 4 bytes
- int_fast8_t: At least as fast as any other type of at least 1 byte size
- Int8_t may not be the faster in math ops than int16_t for instance, as higher bit CPUs need extra steps to work with partial register size data
- For basic embedded applications, it is safe to use standard types, then optimize if needed 



Next: [C/C++ Process Flow](../lesson16/)
@def title = "I Fundamentals - Preprocessor Directives"
@def hascode = true

# Preprocessor Directives

So what are the preprocessor directives?

They are the instructions that begin with the hash sign `#`. When you Build the program, the preprocessor scans through the source files and executes the preprocessor directives. then the code is compiled. The core compiler doesn't see the commands that begin with `#`, they are resolved beforehand. 

There are a handful of preprocessor directives. We will review Macro definitions, conditional inclusions and header file inclusions. 

Preprocessor Directives are lines in the code of the program preceded by a hash sign `#`

They are not part of the compiled program. They are executed during building of the program, in the preprocessor step. They include:
- Macro definitions (#define, #undef)
- Conditional inclusions (`#ifdef`, `#ifndef`, `#if`, `#endif`, `#else` and `#elif`)
- Line control (`#line`)
- Error directive (`#error`)
- Header file inclusion  (`#include`)
- Pragma directive (`#pragma`)

## Macros
Macros are a handy way of creating an alias for a C/C++ piece of instruction. 

\input{cpp}{snippet1.cpp}

To use the macro definitions. We include the `#define` keyword, the macro definition and then what it stands for. 

You will often find macro definitions used in place of some flags, numbers, version number. And then can also be function like where they take and process an argument. 

Note that the preprocessor executes these commands. The compiler will not see the macro definitions. 

For example, PI is macro defined as 3.1416, The preprocessor will look for all instances of the word PI in the code and replace it with 3.1416 BEFORE the code is compiled. 

Here we define a function macro to convert rad to degrees. When used in code, the preprocessor will replace RAD2D(PI/2) for example to 1.5 * 180 / pi. This is not a function, but a command that will be substituted in the code whenever the macro `RAD2D(x)`
```cpp
#define RAD2D(x) x * 180.0 / PI
```

## Conditional Inclusions
The preprocessor can perform a conditional if statement. 

\input{cpp}{snippet2.cpp}
\input{plaintext}{output/snippet2.txt}

The syntax would require a `#if` and a `#endif` at least, with as many `#elif` in between. 

One example use is when you have a code that you want to be backward compatible with previous versions of hardware or firmware. 

You can set a macro somewhere to define the version number of your hardware for example, and then use the conditional inclusions to determine which piece of code to execute, depending on the hardware version. 

Note that only the true statement code will be compiled. Think of it as a way to filter and select between different sets of codes to compile based on some condition. There is no overhead during the code execution, since the condition is fixed at compile time and doesn't change during execution (your drone hardware will not change midflight for instance, or maybe it will for some reason, that would be very creative).

### Ifdef & Ifndef
In this example we define a macro FW_VER and set it to 2. Then we have conditional inclusion. 

\input{cpp}{snippet3.cpp}
\input{plaintext}{output/snippet3.txt}

Note that the second condition is true and the `print_version()` macro is defined as the following. Again, the compile will not see these hash lines, in this example it will see `cout<<"Version 1" <<endl;` here instead of `print_version()`

Another useful macro is the `ifdef` and `ifndef` directives. 
They can be used to check if a specific macro is defined or not defined. 
```cpp
#ifndef FW_VER /* We can check if a macro is undefined */
    #define FW_VER 1 
#endif
```
Assume you have a conditional inclusion statement (if elif) that relies on a certain macro being defined. Perhaps if the header file where it should be defined in is not included. You might want to add a default value to it then, as shown in the example here. Which checks to see if FW_VER is defined, if it is not, then it defines it to some value. Perhaps this is a default value. 

Note that a macro doesn’t have to have an equivalent code. We can simply macro define fw_ver without any associated code or value and the `ifdef` directive would still find it as valid. 
```cpp
#define FW_VER /* This is sufficient to have FW_VER defined */
#ifndef FW_VER 
    #define FW_VER 1 
#endif
```
## Header Inclusion
You have already seen this directive. 

\input{cpp}{snippet4.cpp}
<!-- Output:
\input{plaintext}{output/snippet4.txt} -->

The include directive as the name implies, includes the content of the included file. You can picture the preprocessor taking all the content of the included header and dumping it in place of the include line. 

When using the double quotes to include a header, the preprocessor looks for the header file in the same folder as or with respective to the folder location of the source file.
```cpp
/* Quotes include looks for the header files in the working directory */
#include "my_header.h" 
```
When using angled brackets to include a header file, the preprocessor looks for the header in the system lib include paths. The include paths would be specified to the compiler configuration file (e.g. cmake, make, etc.)
```cpp
/* Angle brackets are generally used for system headers */
#include <system_header.h> 
```

Next: [Standard Library](../lesson15/)
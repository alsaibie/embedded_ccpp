@def title = "I Fundamentals - Variables"
@def hascode = true

# Variable Declarations
~~~
<center><iframe title="vimeo-player" src="https://player.vimeo.com/video/386449962" width="640" height="370" frameborder="0" allowfullscreen></iframe></center>
<br>
~~~

To be able to use the standard library data types, we need to include the **<cstdint>** header. This header has the definition for what **uint16_t** is for example. Which is an unsigned short.

Let's take a look at this example. 

\input{cpp}{snippet1.cpp}
\input{plaintext}{output/snippet1.txt}

*Declaring* a variable is different from *defining* a variable. Declaring a variable is saying I have a variable **a** inside function main that is of **uint8_t** type. Defining a variable is *assigning* a value to it. 

In the above program we have three variables, a global variable **g_c** declared outside of a function and two local variables **a** and **b**. Note that variable **a** is declared and then defined in a different step. We can also declare and define a variable like we did with the variable **b**.  

**_We don’t need to identify the variable type every time we use it. But only when we declare it. And we need to declare it before we use it_**. 

## Variable naming rules

Variable names (also called identifiers) shall always begin with a letter, and they can begin with an underline character (_). Variable names are case-sensitive. On top of what you **can** name the variables, there are usually some common conventions, or practices, for naming variables. These conventions differ from one group of programmers to another. 

Further reading on [variables](https://www.cplusplus.com/doc/tutorial/variables/)

# Variable Scope
A variable scope is where the variable exists. Its borders and visibility. 

```cpp
#include <cstdint>
#include <iostream>

uint8_t g_ui16_a; /* A Global Variable, accessible to all functions in this file, 
and wherever this file is included */
using namespace std; /* allows us to call within std namespace directly */

int main(int argc, char* argv[]) { 
    uint8_t ui8_b; /* A local variable, accessible to any scope inside main() */
    {
        int16_t i16_c; /* Local variable, accessible to inside this scope only */
    }
    cout << "c = " << i16_c << endl; /* ERROR: i16_c is not accessible outside its scope */
    return 1; 
}
```
Variable **g\_ui16\_c** is a global variable. It is global because it is declared outside of any function. It is visible, meaning it can be accessed by any function in the same file and in other files too if said file is included in this other file. A good practice is to name global variables with a g_ prefix. This helps identify that the variable is global. You can go a step further and denote the data type of the variable in its name (ui16: 16 bit unsigned int in this case, and g to indicate global), but that practice is less commonly used. 

The variable **ui8_b** is a local variable in the main function. It is accessible to all instructions within the main function but not to other functions other than main. 

Moreover, we can define a narrower scope within a local scope by using curly braces. The local variable **i16_c** is only accessible to instructions within the curly braces. The program above will fail to compile, because we are attempting to access a variable that is **outside** the scope of the call. 

Higher scope elements are accessible to lower scope areas but not the opposite. 

Next: [Arrays & Characters](../lesson5/)


@def title = "I Fundamentals - Type Qualifiers and Storage Specifiers"
@def hascode = true

# Type Qualifiers and Storage Specifiers
~~~
<center><iframe title="vimeo-player" src="https://player.vimeo.com/video/386450007" width="640" height="370" frameborder="0" allowfullscreen></iframe></center>
<br>
~~~

## static
In addition to specifying the data type when declaring variables, functions or other elements of C/C++, there are type qualifiers and storage specifiers that can be used on declaration.

\input{cpp}{snippet1.cpp}
Output:
\input{plaintext}{output/snippet1.txt}

This is a for-loop where the code within this scope is repeatedly executed three times. We will discuss for-loops separately. 
```cpp
for (int k = 0; k <3; k++){
    uint16_t _a = 3;
    static uint16_t _b = 3; /* Declaring a static variable */
    cout << _a++ << endl; /* Output: 3, 3, 3. Will be reinitialized every loop */
    cout << _b++ << endl; /* Output: 3, 4, 5. Will be initialized only once when declared */
}
```
The static keyword can be used to specify the memory storage characteristics of a variable. A static variable is a variable that is initialized before the code is executed, and it is only declared and initialized once. 

The variable `_a` is a regular local variable. Its memory is still reserved at compile time, but it is not initialized until the code is executed. While the variable `_b` is initialized before the code is executed. 
Notice the difference here between the static and non static variable. Since this part of the code is repeatedly executed. Every time the this line is called the variable `_a` is redeclared and reinitialized to 3.
```cpp
        uint16_t _a = 3; /* lives then dies and gets reinitialized again 2 more times*/
```
While this line is basically executed only the first time. The value in `_b` is retained even after the scope of the variable terminates after the loop ends. 
```cpp
static uint16_t _b = 3; /* Declaring a static variable */
```
This feature is very useful in embedded programming. Say you calculated some sensor error value, you want to retain the value until the next time the code loop runs and then you can update the value, a static variable can help. The other option for keeping a persistent variable is using a global variable.

Global variables are “static” in the sense that they are declared and initialized once. But beware that there is subtle difference between a non-static global variable, a regular global variable, and a static global variable. 

## extern
The storage specifier extern is used to denote that the variable is declared somewhere else. 

\input{cpp}{snippet2.cpp}
Output:
\input{plaintext}{output/snippet2.txt}

This is useful if the variable is declared in a different file. And you are using the same variable across multiple files, you can't declare the variable more than once in every file, but instead you declare it once in one of the files and tell other files about it by using the `extern` keyword.

Here, the extern keyword is of no use since by defining the variable `_g_a` we have specified its value and location.
```cpp
extern uint8_t _g_a = 3; /* Variable declared and defined */
```
It comes in handy when you want to use the variable before it is initialized, you just want the compiler to know that “hey” the variable exists. It will use its initialized value even if its initialized later. And this can be seen with the variable `_g_b` here. Without using `extern` above the code will not compile.
```cpp
uint8_t _g_b = 5; /* At compile time, _g_b is not visible to above functions */
```

Inside the multiplyab function, we just tell the function that there is a global variable named `_g_b` of `uint8_t` type. And note until this point the variable has not been declared. It is declared at the end of the file.

## const
We discussed the two storage specifiers static and extern. There are two **type qualifiers** const and volatile. A *const* variable, as the name suggests, is a constant variable. It’s value cannot be changed. This is very useful when you want to ensure that the value is not changed by mistake. And this can happen, say you have an important variable with a specific value assigned to it. You wouldn’t want the same variable name to be referenced and manipulated somewhere else unintentionally. 

\input{cpp}{snippet3.cpp}
Output:
```
error: assignment of read-only variable 'a'
```

In this example here, we declare const variable a, and then attempt to change it. This code would not compile actually and would give us an error immediately. 

## const static
We can combine a type qualifier and storage specifier. We can declare a variable to be both const and static. This means that the variable will be declared and initialized once before the code is executed and it cannot be changed. 

\input{cpp}{snippet4.cpp}
Output:
\input{plaintext}{output/snippet4.txt}

## volatile
Sometimes a compiler may optimize a code by assuming that, since a variable is not changed anywhere in the code, its initial value remains the same. 

<!-- TODO: Find an example to showcase volatile -->

\input{cpp}{snippet5.cpp}
Output: 
\input{plaintext}{output/snippet5.txt}

Well, what if, and we will see this example clearly in microcontroller programming, what if this variable is manipulated by actions outside of the code itself, through some changes in the hardware. 

In this case, and to ensure that this non-varying-variable assumption does not damage our program, we can declare a variable to be volatile. This tells the compiler: hey listen, don’t assume the value doesn’t change, every time this variable is called, access and read its latest value from its memory location. 

Note that the `uint8_t` variables are type-casted to `int` so the output stream treats them as integers not characters.

Next: [Operations](../lesson7/)
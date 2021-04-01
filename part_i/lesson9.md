@def title = "I Fundamentals - Functions"
@def hascode = true

# Functions
~~~
<center><iframe title="vimeo-player" src="https://player.vimeo.com/video/386948792" width="640" height="370" frameborder="0" allowfullscreen></iframe></center>
<br>
~~~

## Minimal Program
Here is a valid C or C++ program. The minimum code required is the main() function. Think of it as the entry door to the program. 
```cpp
void main(void)
{
    /* A Minimal Program */
}
```
This main function takes no arguments and doesn’t return any argument. You can write the whole program code inside the main function, but it becomes cumbersome and hard to manage and read after a certain point. 

So we use functions to break the code logic into manageable chunks. 

Let’s discuss how functions are declared and used.

## Function Declarations and Definitions
Just like a variable, a function must be declared at least before it is used. 
\input{cpp}{snippet1.cpp}
\input{plaintext}{output/snippet1.txt}

Here, we have the function add which is only declared. Then defined at the bottom. 

Alternatively, we can declare AND define a function like we did with the multiply function.

If a function returns a variable, the variable data type must be specified. Functions cannot return multiple arguments. 

Functions can return structs, which will be covered in later sections. 

Functions can take in more than one argument. Similarly, the type of the argument must be specified. The variable name set in the function argument is the variable to be used within the argument. 

Here, when we call add(5,4), a will be assigned 5 and b will be assigned 4. 

If a function returns an argument, the return keyword must be used. You directly perform an arithmetic operation on the return line. Which is useful for simple functions. 

## Function Arguments
A function can take from void or zero, to infinite arguments, well up to machine memory technically. 

\input{cpp}{snippet2.cpp}
\input{plaintext}{output/snippet2.txt}

We can specify a default argument value, so that if a value is not provided, the default value is used. Default arguments must be put at the end of the function argument list. 

Here we call the same function add, but only pass the first argument. Since we specified a default argument value for second argument, the second argument will be given this default value of 5. 

## Passing Arguments to Functions
A variable name inside the function argument list and within the function, has a scope local to the function only and is not accessible outside the function. 

\input{cpp}{snippet3.cpp}
\input{plaintext}{output/snippet3.txt}

A variable can be passed to a function by value or by reference. 

When passing a variable by value, a copy of the variable value is passed to the function. The function has no control over the original variable. 

here [r1], the add\_3 function takes the address of the variable b, so when manipulating a in here [add\_3], the original variable b is modified. 

But here [r2], the value in b is passed to the function. The function does not modify the variable b, it only processes a copy of the value of b. 

## Function Returns
In C/C++ we often pass a result variable to the function, by reference, and let the function itself store the result of some algorithm into the function directly. Instead of having the variable value returned by the function. 

\input{cpp}{snippet4.cpp}
\input{plaintext}{output/snippet4.txt}

This is especially useful if the function produces multiple results, and since it is not possible to return multiple arguments from a function. 

Here [add], the first argument is passed by references, so the r manipulated inside the function is actually the same r1 variable passed to the function. But variables a and b get passed by value. 


Next: [Pointers and References](../lesson10/)
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

So we use functions to break the code logic into manageable and expressive chunks. Chew your food before you swallow it. 

Let’s discuss how functions are declared and used.

## Function Declarations and Definitions
Just like a variable, a function must be declared before it is used. 
\input{cpp}{snippet1.cpp}
Output:
\input{plaintext}{output/snippet1.txt}

Here, we have the function add which is only **declared**. Then defined at the bottom. In other words, we hereby declared that there is a function **add** that shall take two int arguments and shall return an int. We haven't **defined** what it does *yet*.
```cpp
int add(int a, int b); /* Function Declaration */
```
Alternatively, we can declare AND define a function like we did with the multiply function.
```cpp
int multiply(int a, int b){ /* Function Declaration and Definition */
    return a * b;
}
```
If a function returns a variable, the variable data type must be specified. Functions cannot return multiple arguments. 

Functions can return structs, which will be covered in later sections. 

Functions can take in more than one argument. Similarly, the type of the argument must be specified. The variable name set in the function argument is the variable to be used within the argument. 

Here, when we call add(5,4), `a` will be assigned 5 and `b` will be assigned 4. 
```cpp
    int r1 = add(5,4);
```
```cpp
int add(int a, int b){ /* Function Definition */
    return a + b;
}
```
If a function returns an argument, the `return` keyword must be used. You directly perform an arithmetic operation on the return line. Which is useful for simple functions. 

## Function Arguments
A function can take from void or zero, to infinite arguments, well up to machine memory technically. 

\input{cpp}{snippet2.cpp}
Output:
\input{plaintext}{output/snippet2.txt}

We can specify a default argument value, so that if a value is not provided, the default value is used. Default arguments must be put at the end of the function argument list. 

Here we call the same function add, but only pass the first argument. Since we specified a default argument value for second argument, the second argument will be given this default value of 5. 

## Passing Arguments to Functions
A variable name inside the function argument list and within the function, has a scope local to the function only and is not accessible outside the function. 

\input{cpp}{snippet3.cpp}
Output:
\input{plaintext}{output/snippet3.txt}

A variable can be passed to a function by value or by reference. 

When passing a variable by value, a **copy** of the variable value is passed to the function. The function has no control over the original variable. 

Here, the `add_3` function takes the address of the variable `b`, so when manipulating `a` inside the function `add_3`, the original variable `b` is modified. The variable `a` is treated as the variable `b`.

```cpp
int add_3(int &a){ /* the variable LOCATION REFERENCE will be passed to the function */
    a += 3;
    return a;
} 
```
```cpp
    int r1 = add_3(b); /* r1: 6, b = 6 */
```
But here, the value in `b` is passed to the function. The function does not modify the variable `b`, it only processes a copy of the value of `b`. 
```cpp
    int r2 = add_2(b); /* r2: 8, since b was manipulated (passed by reference) */ 
```
## Function Returns
In C/C++ we can pass a result variable to the function, by reference, and let the function itself store the result of some algorithm into the function directly. Instead of having the variable value returned by the function. 

\input{cpp}{snippet4.cpp}
Output:
\input{plaintext}{output/snippet4.txt}

This is especially useful if the function produces multiple results, and since it is not possible to return multiple arguments from a function. 

Here, the first argument is passed by references, so the r manipulated inside the function is actually the same r1 variable passed to the function. But variables `a` and `b` get passed by value. 
```cpp
void add(int &r, int a, int b){ /* Function Definition */
    /* the function doesn't return any argument,
     * instead changing r changes the r1 inside main()
     */
    r = a + b;
}
```
# Exercise
~~~
<div data-pym-src="https://www.jdoodle.com/embed/v0/39UH?stdin=0&arg=0"></div>
    <script src=
"https://www.jdoodle.com/assets/jdoodle-pym.min.js"
        type="text/javascript">
    </script>
~~~

~~~
<iframe frameborder="0" width="100%" height="700px" src="https://repl.it/@alsaibie/Test?lite=true"></iframe>
~~~
Next: [Pointers and References](../lesson10/)
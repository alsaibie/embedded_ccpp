@def title = "I Fundamentals - Pointers and References"
@def hascode = true

# Pointers and References
~~~
<center><iframe title="vimeo-player" src="https://player.vimeo.com/video/387520687" width="640" height="370" frameborder="0" allowfullscreen></iframe></center>
<br>
~~~
The subject of pointers usually deters students away. It is indeed tricky to grasp at first, but understanding it is essential when working with embedded systems. 

By definition, a pointer can be considered a variable, but instead of storing a value, its purpose is to store an address of something. It **points** to the element location, not value.

A pointer can store the address of a variable, a function, a struct. Basically any element of the C/C++ language. If something has an address, a pointer can be used to **point** to the location of this thing.

We use the ampersand operator `&` to express the address of a variable. 

When declaring a pointer, we use the star symbol to denote that, what we are declaring, is a pointer. 
```cpp
int a = 3;
int * p = &a; /* Declared pointer p and assigned address of a to it */
```
When we want to access the value of the pointer, we access the pointer directly just like a variable. Again, the pointer will give as an address.
```cpp
int a = 3;
int * p = &a;
int * p2 = p; /* Address stored in p (address of variable a) given to a new pointer */
```

If we want to retrieve the value stored in the address, of what the pointer is pointing **to**, then we use the dereference operator `*`. 
```cpp
int a = 3;
int * p = &a;
int b = *p; /* The star here DEREFERENCES the pointer, retrieving the value in that address*/
```

So, heads-up, the star symbol is used in two different situations with pointers, in declaring a pointer and in DE-referencing a pointer.

```cpp
int a = 3;
int * p = &a; /* star symbol for DECLARING a pointer */
int b = *p;  /* star symbol for DEREFERENCING a pointer */
```

## Operation on Pointers
- **Declaration:         e.g. `uint8_t *ptr;`**
  
  To declare a pointer, we specify the data type of the element the pointer will point to (store the address of). Note how we add the star symbol to denote that ptr is a pointer type variable.

- **Assignment:	       e.g. `ptr=&x; ptr=array`**
  
  If x is a regular 8bit unsigned integer, and we want to store the address of x in ptr, we use the ampersand symbol a.k.a the reference operator. Note that the NAME of an array is a pointer to the first element of the array.

- **Dereference:	       e.g. `*ptr`**
  
  To retrieve the value in the address location stored in the pointer. We use the star symbol to DEREFERENCE the pointer. Here / we retrieve the value in X / if ptr stores the address of X.

- **Address of:	       e.g. `&x`**
  
  Again, the ampersand symbol is called the reference operator, it gives us Not the value in x, but the address of x.

- **Increment:		   e.g. `ptr+=3`**
- **Decrement:	       e.g. `ptr--`**
  
  We can increment and decrement pointers just like regular variables. But note that the amount of increment or decrement is multiples of the address size of the pointer data type. 

- **Difference:		   e.g. `ptr1-ptr2`** 
  
  We can subtract addresses

- **Comparison:	       e.g. `ptr1<ptr2`, `ptr1==ptr2`, etc.**
  
  We can compare addresses

Here is an example

\input{cpp}{snippet1.cpp}
Output:
\input{plaintext}{output/snippet1.txt}

Here we create a regular variable.
```cpp
    int a = 3;
```

Then we create a pointer. The star symbol tells the compiler that this is a pointer. We define the ptr by assigning the address of the variable a, by using the reference operator.
```cpp
    int *ptr = &a;
```
When we print out the content of ptr, we will get a long hex number denoting an address in memory. On a PC. This will generally be a different number every time you compile and run the program.
```cpp
std::cout << ptr << std::endl;
```
To print the content in the address inside ptr we use the star symbol to DEREFERENCE the ptr. We will basically get the value stored in the variable `a` 
```cpp
std::cout << *ptr << std::endl;
```
## Pointer is a variable
\input{cpp}{snippet2.cpp}
Output:
\input{plaintext}{output/snippet2.txt}

A pointer is a variable. We can do assignment and we can do math on it.
```cpp
 ptr = &x; /* Grabs the address of the variable x */
```

Here, we assign to `y`, the value stored in `x` by dereferencing the address of `x`.
```cpp
    y = *ptr; /* Grabs the value in the address pointed to by ptr = value in x */
```

Here we store in `x`, the address of `x`. So `x` stores the address of itself. 
```cpp
    x = (int)ptr; /* Grabs address pointed to by ptr and stores it in x */
```

We can also change the value of `x`, by using the pointer. Since the pointer holds the address of `x`, we dereference ptr and assign a value to it. 
```cpp
    *ptr = 4; /* Changes the value stored in the location pointed to by ptr: changes the value of x */
```
## Incrementing Pointers

When incrementing a pointer, it will not necessarily be incremented by one. Instead, it will be incremented by the number of bytes of the data type it points to.
\input{cpp}{snippet3.cpp}
Output (address locations):
\input{plaintext}{output/snippet3.txt}

For example, here we have two pointers: one for a 16bit variable and one for a 32bit.

When we increment the 16bit pointer, we jump two addresses. And when we increment the 32bit pointer, we jump 4 addresses. 8 to C in hex, that???s 4 decimal values.

## Arrays vs. Pointers
Arrays and pointers are closely related. 

\input{cpp}{snippet4.cpp}
Output:
\input{plaintext}{output/snippet4.txt}

You can probably see that an array stores a sequence of values of similar data types; the **array name is actually a pointer**, pointing to the first element of the array.

You can usually treat the array name as a pointer. 

Here we increment the pointer (the name of the array) by two, then dereference it. This wiill retrieve the 3rd array element.
```cpp
    cout << *(sequence + 2) << endl; /*Output: 6, retrieving the 3rd array element */
```
## Passing Pointers
The strength of pointers is seen in one example by the way data can be passed between functions. 

\input{cpp}{snippet5.cpp}
\input{plaintext}{output/snippet5.txt}

When passing a variable to a function the usual way, what is passed is a **copy** of the variable. That???s extra time and memory consumed, especially if you are processing a large array.

Instead of passing a **copy** of the variable, we can pass the **address** of the variable. So the function can manipulate the **original** variable **directly**.

This efficient data handling is shown better when dealing with arrays. Instead of passing a **copy** of all array elements, we can pass a **pointer** to the **array** and let the function manipulate the array directly.

Note that arrays do not carry information regarding their size or length. So, along with the array name (which is a pointer), we have to tell the function the length of the array.

In C++, there are other abstract ways to store sequences of data using standard library templates such as *lists*, *maps* and *vectors*. That carry more information about themselves and embed functionalities to handle their data.

In this example, we have a function that sums array elements. It takes a pointer to the array, the size of the array and a ptr to the result variable.
```cpp
/* A function accepts a ptr, a ptr is just a variable */
void sum_array(uint8_t *arr, size_t arr_s, uint16_t *sum_ptr);
```
Here we create the array, and a result variable. When calling the function, we pass the array name; which is a pointer, the size of the array and the address of the result variable.
```cpp
int main(int argc, char *argv[]){
    uint8_t sequence[4] = {2, 3, 4, 1};
    uint16_t sum = 0; 
    /* When passing an array, need to pass size of array */
    sum_array(sequence,sizeof(sequence), &sum);
    cout << sum << endl;
    return 0;
}
```
Inside the function, we loop through the array elements and continue adding the values to the result variable. Note that `sum_ptr` is a pointer, so to manipulate the result variable we have to dereference it.
```cpp
void sum_array(uint8_t *arr, size_t arr_s, uint16_t *sum_ptr){
    for (int k = 0; k < arr_s; k++){
        *sum_ptr += arr[k]; /* The original variable is manipulated */
    }
}
```




Next: [Structs](../lesson11/)
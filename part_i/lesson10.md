@def title = "I Fundamentals - Pointers and References"
@def hascode = true

# Pointers and References
~~~
<center><iframe title="vimeo-player" src="https://player.vimeo.com/video/387520687" width="640" height="370" frameborder="0" allowfullscreen></iframe></center>
<br>
~~~
The subject of pointers usually deters students away. It is indeed tricky to grasp at first, but understanding it is essential when working with embedded systems. 

By definition, a pointer can be considered a variable, but instead of storing a value, its purpose is to store an address of something.

A pointer can store the address of a variable, a function, a struct. Basically any element of the C/C++ language. If something has an address, a pointer can be used to “POINT” to the location of this thing.

We use the ampersand operator to express the address of a variable. 

When declaring a pointer, we use the star symbol to denote that, what we are declaring, is a pointer. 

When we want to access the value of the pointer, we access the pointer directly just like a variable. Again, the pointer will give as an address.

If we want to retrieve the value stored in the address, of what the pointer is pointing TO, then we use the dereference operator *. 

So, heads-up, the star symbol is used in two different situations with pointers, in declaring a pointer and in DE-referencing a pointer.

## Operation on Pointers
- **Declaration:         e.g. uint8_t *ptr;**
  
  To declare a pointer, we specify the data type of the element the pointer will point to (store the address of). Note how we add the star symbol to denote that ptr is a pointer type variable.

- **Assignment:	       e.g. ptr=&x; ptr=array**
  
  If x is a regular 8bit unsigned integer, and we want to store the address of x in ptr, we use the ampersand symbol a.k.a the reference operator. Note that the NAME of an array is a pointer to the first element of the array.

- **Dereference:	       e.g. *ptr**
  
  To retrieve the value in the address location stored in the pointer. We use the star symbol to DEREFERENCE the pointer. Here / we retrieve the value in X / if ptr stores the address of X.

- **Address of:	       e.g. &x**
  
  Again, the ampersand symbol is called the reference operator, it gives us Not the value in x, but the address of x.

- **Increment:		   e.g. ptr+=3**
- **Decrement:	       e.g. ptr--**
  
  We can increment and decrement pointers just like regular variables. But note that the amount of increment or decrement is multiples of the address size of the pointer data type. 

- **Difference:		   e.g. ptr1-ptr2** 
  
  We can subtract addresses

- **Comparison:	       e.g. ptr1<ptr2, ptr1==ptr2, etc.**
  
  We can compare addresses


\input{cpp}{snippet1.cpp}
\input{plaintext}{output/snippet1.txt}

[L1] Here we create a regular variable;

[L2] Then we create a pointer. The star symbol tells the compiler that this is a pointer. We define the ptr by assigning the address of the variable a, by using the reference operator.

[L3] When we print out the content of ptr, we will get a long hex number denoting an address in memory. On a PC. This will generally be a different number every time you compile and run the program.

[L4] To print the content in the address inside ptr we use the star symbol to DEREFERENCE the ptr. We will basically get the value stored in the variable a 

## Pointer is a variable
\input{cpp}{snippet2.cpp}
\input{plaintext}{output/snippet2.txt}

[L1] A pointer is a variable. We can do assignment and we can do math on it.

[L2] Here, we assign to y, the value stored in x by dereferencing the address of x.

[L3] Here we store in x, the address of x. So X stores the address of itself. 

[L4] We can also change the value of x, by using the pointer. Since the pointer holds the address of x, we dereference ptr and assign a value to it. 

## Incrementing Pointers

When incrementing a pointer, it will not necessarily be incremented by one. Instead, it will be incremented by the number of bytes of the data type it points to.
\input{cpp}{snippet3.cpp}
\input{plaintext}{output/snippet3.txt}

For example, here we have two pointers: one for a 16bit variable and one for a 32bit.

Now assuming we have 8-bit memory mapping, Meaning, every address points to an 8bit memory slot.

When we increment the 16bit pointer, we jump two addresses. And when we increment the 32bit pointer, we jump 4 addresses. 8 to C in hex, that’s 4 decimal values.

## Arrays vs. Pointers
Arrays and pointers are closely related. 

\input{cpp}{snippet4.cpp}
\input{plaintext}{output/snippet4.txt}

You can probably see that an array stores a sequence of values of similar data types; the array name is actually a pointer, pointing to the first element of the array.

You can actually treat the array name as a pointer. 

[Last] Here we increment the pointer (the name of the array) by two, then dereference it. This wiill retrieve the 3rd array element.

## Passing Pointers
The strength of pointers is seen in one example by the way data can be passed between functions. 

\input{cpp}{snippet5.cpp}
\input{plaintext}{output/snippet5.txt}

When passing a variable to a function the usual way, what is passed is a copy of the variable. That’s extra time and memory consumed. 

Instead of passing a COPY of the variable, we can pass the address of the variable. So the function can manipulate the original variable directly.

This efficient data handling is shown better when dealing with arrays. Instead of passing a COPY of all array elements, we can pass a pointer to the array and let the function manipulate the array directly.
 

Note that arrays does not carry information regarding their size or length. So, along with the array name (which is a pointer), we have to tell the function the size of the array.

In C++, there are however other advanced ways to store sequences of data using standard library templates such as lists, maps and vectors. That carry more information about themselves.

[L1] In this example, we have a function that sums array elements. It takes a pointer to the array, the size of the array and a ptr to the result variable.

[L2] Here we create the array, and a result variable. When calling the function, we pass the array name; which is a ptr, the size of the array and the address of the result variable.

[L3] inside the function, we loop through the array elements and continue adding the values to the result variable. Note that sum_ptr is a pointer, so to manipulate the result variable we have to dereference it.





Next: [Structs](../lesson11/)
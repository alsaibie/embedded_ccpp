@def title = "I Fundamentals - Operations"
@def hascode = true

# Arithmetic Operations
~~~
<center><iframe title="vimeo-player" src="https://player.vimeo.com/video/386922824" width="640" height="370" frameborder="0" allowfullscreen></iframe></center>
<br>
~~~
If you have taken any math class in your life this will not look foreign to you. The four basic math operations (add, subtract, multiply and divide) don’t require any additional library and headers in C/C++. 

|     Operator    |     Name                                                 |             Example           |
|-----------------|----------------------------------------------------------|:-----------------------------:|
|     +           |     Addition                                             |           C = A +   B         |
|     +=          |     Addition assignment ( x+=y equiv. to x = x+y)        |             c += b            |
|     -           |     Subtraction                                          |          c = b   – a          |
|     -=          |     Subtraction assignment ( x-=y equiv. to x=x-y)       |             c -= b            |
|     *           |     Multiplication                                       |          j =   count*4        |
|     *=          |     Multiplication assignment ( x*=y equiv. to x=x*y)    |             i *= k            |
|     /           |     Division                                             |           f = r / 13          |
|     /=          |     Division assignment ( x/=y equiv. to x=x/y)          |             f /= 13           |
|     ++          |     Increment by one (++j is equiv. to j = j + 1)        |              i++              |
|     --          |     Decrement   by one (--j is equiv. to j = j – 1)      |               --i             |
|     %           |     Modulus   Operator                                   |     C =   3 % 2 (ans:   1)    |

Moreover, in C/C++ there is what is called an operation assignment. For example, if you wanted to add the value y to the variable x, you can do x = x + y or you can do x+=y. The two are equivalent. This latter is called an addition assignment. 

The same can be done for subtraction, division and multiplication.

We also have increment and decrement operators which are handy way to increase or decrease a variable by 1 integer value, respectively.  

## Arithmetic Assignment
The following two codes are exactly equivalent. Their assembly codes are exactly the same in fact. 
First we declare an int, initialize it to 0. Then increment it by 10, decrement it by 4, divide it by 2 then multiply it by 5 and finally increment it by 1. The final value of a should be 16

```cpp
int main(int argc, char* argv[]) {
    int a = 0;
    a += 10;
    a -= 4;
    a /= 2;
    a *= 5;
    a++;
    return 0;
}
```
```cpp
int main(int argc, char* argv[]) {
    int a = 0;
    a = a + 10;
    a = a - 4;
    a = a / 2;
    a = a * 5;
    a = a + 1;
    return 0;
}
```
## Post vs. Pre Increment
With increment and decrement operators, there is a difference between pre incrementing and post incrementing. To pre increment K we would write ++k and to post increment k we would write k++.
```cpp
#include <iostream>

int main(int argc, char* argv[]) {
    int k = 1;
    std::cout<<"k = "<< k++ <<std::endl;
    /* The output would be: k = 1 */
    return 1;
}
```
```cpp
#include <iostream>

int main(int argc, char* argv[]) {
    int k = 1;
    std::cout<<"k = "<< ++k <<std::endl;
    /* The output would be: k = 2 */
    return 1;
}

```
So what’s the difference you ask. Well, when you pre-increment a variable, what you are requesting is that a variable is first incremented and then read and used in the algorithm. 

In the second example the variable k was initially 1, it was incremented first then used in the cout command, so the output would be 2. But on the left example here, the variable k is first read, used in the cout command and then incremented. So the output of cout is 1.

# Bitwise Operations
~~~
<center><iframe title="vimeo-player" src="https://player.vimeo.com/video/386922845" width="640" height="370" frameborder="0" allowfullscreen></iframe></center>
<br>
~~~
## Expressing Binary and Hexadecimal Values
Before we overview bitwise operations, let’s learn how to express binary and hex values in C/C++. 

To express binary numbers we add the prefix **0b** and to denote hex numbers we add the prefix **0x**.

\input{cpp}{snippet1.cpp}
\input{plaintext}{output/snippet1.txt}

It’s not often required to print out binary or hex values through cout. But if needed, for a binary display you can covert the format as shown here using the bitset template. 

To print a value in hex format through cout, include the keyword hex double angle left angle brackets. 
 
## Bitwise Operators
Manipulating memory and variables on a bit level is essential in embedded programming. The following table summarizes the bitwise operations used. 

|     Operator      |     Name                         | Description                      |
|:-------------------|:----------------------------------|:--------------------------------------|
|     &             |     Bitwise AND                  |     Performs AND operation on each   corresponding bit of two arguments and returns   result           |
|     \|            |     Bitwise   OR                 |     Performs OR operation on each corresponding bit of two arguments and returns   result              |
|     ^             |     Bitwise Exclusive OR         |     Performs Exclusive OR operation on each corresponding bit of two arguments and returns   result    |
|     ~             |     Bitwise NOT                  |     Performs a NOT operation on all the   bits of an argument and returns the result                   |
|     <<   or >>    |     Right shift or Left shift    |     Shift   bits of argument 1 right/left by argument 2 places                                         |

## Logical Bitwise Operations
Let’s look at how we can apply some of the bitwise operations. Here we define three variables. We directly assign binary numbers to a and b, and a hex number to c which has the this binary value. 

The following four operations show how to perform an AND, an OR, a NOR and a NOT operation. 

You can also perform bitwise assignment as well. Numbers can be expressed in binary, hex as well as decimal.

\input{cpp}{snippet2.cpp}
\input{plaintext}{output/snippet2.txt}
  
## Bit-shifting
It is often convenient to manipulate values at the bit level, especially when working with embedded systems. 

\input{cpp}{snippet3.cpp}
\input{plaintext}{output/snippet3.txt}

Shifting, as the name implies, means moving the bits either to the left or the right, by a specified amount. To perform the shift, we use the double angled brackets followed by the number of shifts. 

Bit shifting requires little effort by the CPU, it is actually also useful as a faster arithmetic technique. A right shift can be used to divide by powers of 2 rounded down. But users of this technique for arithmetic operations need to be wary of overflow and loss of precision. 

# Logical Operations
~~~
<center><iframe title="vimeo-player" src="https://player.vimeo.com/video/386922865" width="640" height="370" frameborder="0" allowfullscreen></iframe></center>
<br>
~~~
Logical expressions refer to expressions that can either be true or false. In C++ there is a bool data type, which can take only true or false as a value. The bool type is not built-in the C language, but can be easily defined manually as is often done. However, it is safer to have the bool type built-in. 

|     Operator      |     Name                                        | Description                                                                  |
|:-------------------|:-------------------------------------------------|:----------------------------------------------------------------------------------|
|     &&            |     Logical And                                 |     Returns 1 if inputs are all nonzero, 0 otherwise                             |
|     \|\|          |     Logical Or                                  |     Returns   0 if all inputs are zero, 1 otherwise                              |
|     !             |     Logical NOT                                 |     Return the opposite of the logical   value                                   |
|     <,   >, ==    |     Greater   than, less than, logical equal    |     Returns 1 if argument one is (gt, lt, equal to) argument two, 0 otherwise    |

Numerically, a zero is treated as false and a non-zero value is treated as true. Performing logical operations on logical expressions is done via the following operators. 

Note that here we use a double ampersand for a logical AND, while we use a single ampersand for a bitwise AND operation. 

Comparisons can also be done for numerical values. 

Here are a few examples of how logical operations are used. 
\input{cpp}{snippet4.cpp}

**r1**: Here we compare if a equals 3, which is true, and compare if b equals 3 which is false and then we perform an AND operation between the two, which results in false. 

**r2**: And here we do the same comparisons for a and b but then we perform an OR operation. This time the results is true is at least one of the expressions is true. Not that the logic here is different than with bitwise operations. An AND between multiple expressions is true only when all expressions are true. An OR between multiple expressions is true if at least one of the expressions is true. 

**r3**: We can compare values directly here and the results is true since **a** equals **c**

**r4**: But **a** is not equal to **d** so that’s false.

**r5**: If we convert **d** to an int we drop the decimal and it becomes equal to **a**

**r6**: **a** is smaller than **b** 

**r7**: and since **a** is smaller than **d**, the value in the bracket is false, if we NOT this value we get a true. 

# Float vs Integer Math
~~~
<center><iframe title="vimeo-player" src="https://player.vimeo.com/video/386922884" width="640" height="370" frameborder="0" allowfullscreen></iframe></center>
<br>
~~~
There are a few important points to discuss regarding integer versus floating point math. 

Remember that if you are performing arithmetic operations on integers, any decimal fraction resulting from the operation will be discarded. Should you just save the result into a float variable? Well, close but that’s not the complete picture. 

Let’s see how that works.
\input{cpp}{snippet5.cpp}
\input{plaintext}{output/snippet5.txt}

**c**: both d and a are integers, the division operation is done in integer math, the result is not 1.3 but 1, before the result is saved to the variable c

**d**: The same applies here, a / b is 0.75 but this is integer math so the answer is 0.

**e**: Here we divide the integer a by the float bf, this makes the math carried in float terms so the result is 0.75, but because it is saved into an integer the fraction is dropped and the value stored in e is 0

**f**: The math here is floating point math and now that the value to which the result is stored into is a float, then f would indeed store 0.75. 

**g**: Here, even though the result variable is a float, again the mathematical operation was carried using integer math, because the values involved in the math operation are all integers.  

### Float operation but int variable
Instead of using a float data type, if it is only required that a float operation be a subpart of a division, then, either the order of the operation would have to be adjusted such that multiplication occurs before division, such as with variable **b** below.

\input{cpp}{snippet6.cpp}
\input{plaintext}{output/snippet6.txt}

**c**: or the variable can be temporarily casted to a float in place here (float)

Both would allow for the result to be calculated.  

### Type-Casting floats
If one of the numbers in an arithmetic operation is expressed as a float, like the 240.0 here. Then this is an implicit way to ensure the arithmetic operation is performed in float terms

Alternatively, a variable can be casted in-place to be a float, this basically creates a new temporary value that is a float. It does not change the variable itself to a float. 

\input{cpp}{snippet7.cpp}
\input{plaintext}{output/snippet7.txt}

We can cast variables from one type to another. Again, this doesn’t change the variable type itself, but creates a new temporary variable of a different type in place of the cast+variable operation.

Even if you know the new variable can accept the value coming from an older but different data type variable, it is good practice to explicitly type cast to show intent and awareness that the type of the data has changed. 

When performing floating point math, it is often desired to temporarily cast an int to a float to retain fractional values.

Assigning values between nonmatching datatypes can result in hard track bugs, and worse, engineering disasters. 

Next: [Control Structures](../lesson8/)
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
|     +           |     Addition                                             |           c = a + b         |
|     +=          |     Addition assignment ( x+=y equiv. to x = x+y)        |             c += b            |
|     -           |     Subtraction                                          |          c = b   – a          |
|     -=          |     Subtraction assignment ( x-=y equiv. to x=x-y)       |             c -= b            |
|     *           |     Multiplication                                       |          j =   count*4        |
|     *=          |     Multiplication assignment ( x*=y equiv. to x=x*y)    |             i *= k            |
|     /           |     Division                                             |           f = r / 13          |
|     /=          |     Division assignment ( x/=y equiv. to x=x/y)          |             f /= 13           |
|     ++          |     Increment by one (++j is equiv. to j += 1)        |              i++              |
|     \-\-          |     Decrement   by one (\-\-j is equiv. to j \-= 1)      |               \-\-i             |
|     %           |     Modulus   Operator                                   |     c =   3 % 2 (ans:   1)    |

Moreover, in C/C++ there is what is called an operation assignment. For example, if you wanted to add the value y to the variable x, you can do x = x + y or you can do x+=y. The two are equivalent. This latter one is called an addition assignment. 

The same can be done for subtraction, division and multiplication.

We also have increment and decrement operators which are a handy way to increase or decrease a variable by 1 integer value, respectively.  

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
With increment and decrement operators, there is a difference between pre-incrementing and post-incrementing. To pre-increment K we would write ++k and to post-increment k we would write k++.
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

In the second example the variable k was initially 1, it was incremented first then used in the cout command, so the output would be 2. But with the first example, the variable k is first read, used in the cout command and **then** incremented. So the output of cout is 1.

In other words, with **pre-**: operate on it then use it, and with **post-**: use it then operate on it.

# Bitwise Operations
~~~
<center><iframe title="vimeo-player" src="https://player.vimeo.com/video/386922845" width="640" height="370" frameborder="0" allowfullscreen></iframe></center>
<br>
~~~
## Expressing Binary and Hexadecimal Values
Before we overview bitwise operations, let’s learn how to express binary and hex values in C/C++. 

To express binary numbers we add the prefix **0b** and to denote hex numbers we add the prefix **0x**.

\input{cpp}{snippet1.cpp}
Output:
\input{plaintext}{output/snippet1.txt}

It’s not often required to print out binary or hex values through cout. But if needed, for a binary display you can covert the format as shown here using the bitset template. But you need to bring in the <bitset> header file.

```cpp
bitset<8> binary_var(b); /* Convert format for display only */
```
To print a value in hex format through cout, include the keyword hex double angle left angle brackets. Any variable can be printed in hex for this way. 

```cpp
cout << "hex = " << hex << hex_var << endl; /* use std::hex to format into hex*/
``` 
## Bitwise Operators
Remember that everything in memory is ultimately stored as 1's and 0's. A char or uint8_t variable requires 8-bits of memory (8 1's or 0's).

We can operate on bits directly. Manipulating memory and variables on a bit level is essential in embedded programming. The following table summarizes the bitwise operations used. 

|     Operator      |     Name                         | Description                      |
|:-------------------|:----------------------------------|:--------------------------------------|
|     &             |     Bitwise AND                  |     Performs AND operation on each   corresponding bit of two arguments and returns   result           |
|     \|            |     Bitwise   OR                 |     Performs OR operation on each corresponding bit of two arguments and returns   result              |
|     ^             |     Bitwise Exclusive OR         |     Performs Exclusive OR operation on each corresponding bit of two arguments and returns   result    |
|     ~             |     Bitwise NOT                  |     Performs a NOT operation on all the   bits of an argument and returns the result                   |
|     <<   or >>    |     Right shift or Left shift    |     Shift   bits of argument 1 right/left by argument 2 places                                         |

## Logical Bitwise Operations
Let’s look at how we can apply some of the bitwise operations. Here we define three variables. We directly assign binary numbers to `a` and `b`, and a hex number to `c` which has the this binary value. 

The following four operations show how to perform an AND, an OR, a NOR and a NOT operation. 

You can also perform bitwise assignment as well. Numbers can be expressed in binary, hex as well as decimal.

\input{cpp}{snippet2.cpp}
Output (hex format):
\input{plaintext}{output/snippet2.txt}

### AND 
On a bit level an AND operation is similar to multiplication. If one is zero, the results is zero. 
```cpp
 uint8_t r1 = a & b; /* AND operation, result: 00001000 */
```  
### OR
With OR, if at least one is 1 the result is 1
```cpp
uint8_t r2 = a | c; /* OR operation,  result: 11111111 */
```
### NOR
With a NOR operation, if **only one** is equal to 1, the result is 1.
```cpp
uint8_t r3 = a ^ b; /* NOR operation, result: 10000111 */
```

### NOT
A NOT operation just toggles the value. 
```cpp
 uint8_t r4 = ~c;    /* NOT operation, result: 00001000 */
```

## Bit-shifting
It is often convenient to shift values at the bit level, especially when working with embedded systems. 

Shifting, as the name implies, means moving the bits either to the left or the right, by a specified amount. To perform the shift, we use the double angled brackets followed by the number of shifts. 

\input{cpp}{snippet3.cpp}
Output:
\input{plaintext}{output/snippet3.txt}

Bit shifting requires little effort by the CPU, it is actually also useful as a faster arithmetic technique. A right shift can be used to divide by powers of 2 rounded down. But users of this technique for arithmetic operations need to be wary of overflow and loss of precision. 

### Shifting right
When shifting to the right, the rightmost bits fall into a black hole and disappear, the new ones to the left are zero (no circulation)
```cpp
uint8_t r1 = a >> 2; /* Shift operation, 2 places, result: 00000001 */
```

### Shifting left
Similary, when shifting to the left, the leftmost bits fall into a giant pit and disappear, the new ones to the right are zero. 
```cpp
    uint8_t r2 = b << 4; /* Shift operation, 4 places, result: 11110000 */
```

### Bit numbering
In an 8-bit memory, the first bit to the left is denoted as bit 0 and the last one to the left as bit 7. With Little Endian convention, the lowest bit address (bit 0) is called the Least Significant Bit (LSB) and the bit with the highest address (bit 7 here) is called Most Significant Bit (MSB)
# Logical Operations
~~~
<center><iframe title="vimeo-player" src="https://player.vimeo.com/video/386922865" width="640" height="370" frameborder="0" allowfullscreen></iframe></center>
<br>
~~~
Logical expressions refer to *expressions* that can either be **true** or **false**. In C++ there is a **bool** data type, which can take only **true** or **false** as a value. The **bool** type is not built-in the C language, but can be easily defined manually as is often done. However, it is safer to have the bool type built-in. 

Numerically, a zero is treated as false and a **non-zero** (not just 1) value is treated as true. Performing logical operations on logical expressions is done via the following operators. 

|     Operator      |     Name                                        | Description                                                                  |
|:-------------------|:-------------------------------------------------|:----------------------------------------------------------------------------------|
|     &&            |     Logical AND                                 |     Returns 1 if inputs are all nonzero, 0 otherwise                             |
|     \|\|          |     Logical OR                                  |     Returns   0 if all inputs are zero, 1 otherwise                              |
|     !             |     Logical NOT                                 |     Return the opposite of the logical   value                                   |
|     <,   >, ==    |     Greater   than, less than, logical equal    |     Returns 1 if argument one is (gt, lt, equal to) argument two, 0 otherwise    |

Note that here we use a double ampersand for a logical AND, while we use a single ampersand for a bitwise AND operation. 

Comparisons can also be done for numerical values. 

Here are a few examples of how logical operations are used. 
\input{cpp}{snippet4.cpp}

Here we compare if a equals 3, which is true, and compare if b equals 3 which is false and then we perform an AND operation between the two, which results in false. 
```cpp
bool r1 = (a == 3) && (b == 3); /* Logical Operation, result: 0 (false), as b = 4 */
```
And here we do the same comparisons for a and b but then we perform an OR operation. This time the results is true is at least one of the expressions is true. Not that the logic here is different than with bitwise operations. An AND between multiple expressions is true only when all expressions are true. An OR between multiple expressions is true if at least one of the expressions is true. 
```cpp
bool r2 = (a == 3) || (b == 3); /* Logical Operation, result: 1 (true), as a = 3 */
```

We can compare values directly here and the results is true since `a` equals `c`
```cpp
bool r3 = a == c; /* Logical Operation, result: 1 (true), as 3 = 3.0 */
```

But `a` is not equal to **d** so that’s false.
```cpp
bool r4 = a == d; /* Logical Operation, result: 0 (false), as 3 < 3.001 */
```
If we convert **d** to an int we drop the decimal and it becomes equal to `a`
```cpp
bool r5 = a == (uint8_t)d; /* Logical Operation, result: 1 (true), as 3 = 3 */
```
`a` is smaller than `b` 
```cpp
bool r6 = a >= b; /* Logical Operation, result: 0 (false) */
```
and since `a` is smaller than **d**, the value in the bracket is false, if we NOT this value we get a true. 
```cpp
    bool r7 = !(a >= b); /* Logical Operation, result: 1 (true) */
```
# Float vs Integer Math
~~~
<center><iframe title="vimeo-player" src="https://player.vimeo.com/video/386922884" width="640" height="370" frameborder="0" allowfullscreen></iframe></center>
<br>
~~~
There are a few important points to discuss regarding integer versus floating point math. 

Remember that if you are performing arithmetic operations on integers, any decimal fraction resulting from the operation will be discarded. Should you just save the result into a float variable? Well, close but that’s not the complete picture. 

Let’s see how that works.
\input{cpp}{snippet5.cpp}
Output:
\input{plaintext}{output/snippet5.txt}

Both d and a are integers, the division operation is done in integer math, the result is not 1.3 but 1, before the result is saved to the variable c
```cpp
    uint16_t c = b / a;  /* integer divide operaton, result: 1 */
```
The same applies here, a / b is 0.75 but this is integer math so the answer is 0.
```cpp
    uint16_t d = a / b;  /* integer divide operaton, result: 0 */
```
Here we divide the integer a by the float bf, this makes the math carried in float terms so the result is 0.75, but because it is saved into an integer the fraction is dropped and the value stored in e is 0
```cpp
    uint16_t e = a / bf; /* float divide operaton,   result: 0, since e is an int */
```
The math here is floating point math and now that the value to which the result is stored into is a float, then f would indeed store 0.75. 
```cpp
    float f = a / bf; /* float divide operation,  result: 0.75 */
```
Here, even though the result variable is a float, again the mathematical operation was carried using integer math, because the values involved in the math operation are all integers.
```cpp
    float    g = a / b;  /* integer divide operation, result: 0, even if g is float */
```

### Float operation but int variable
Instead of using a float data type, if it is only required that a float operation be a subpart of a division, then, either the order of the operation would have to be adjusted such that multiplication occurs before division, such as with variable `b` below.

\input{cpp}{snippet6.cpp}
\input{plaintext}{output/snippet6.txt}

Or the variable can be temporarily casted to a float in place here (float)
```cpp
    uint8_t c = (3/(float)4) * 4 ; /* stored result: 3 */
```
Both would allow for the result to be calculated.  

### Type-Casting floats
If one of the numbers in an arithmetic operation is expressed as a float, like the 240.0 here. Then this is an implicit way to ensure the arithmetic operation is performed in float terms.

Alternatively, a variable can be casted in-place to be a float, this basically creates a new temporary value that is a float. It does not change the variable itself to a float. 

\input{cpp}{snippet7.cpp}
Output:
\input{plaintext}{output/snippet7.txt}

We can cast variables from one type to another. Again, this doesn’t change the variable type itself, but creates a new temporary variable of a different type in place of the cast+variable operation.

Even if you know the new variable can accept the value coming from an older but different data type variable, it is good practice to explicitly type cast to show intent and awareness that the type of the data has changed. 

When performing floating point math, it is often desired to temporarily cast an int to a float to retain fractional values.

Assigning values between nonmatching datatypes can result in hard to track bugs, and worse, engineering disasters. 

Next: [Control Structures](../lesson8/)
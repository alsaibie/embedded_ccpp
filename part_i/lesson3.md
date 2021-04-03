@def title = "I Fundamentals - Data Types"
@def hascode = true

# Data Types
~~~
<center><iframe title="vimeo-player" src="https://player.vimeo.com/video/386449945" width="640" height="370" frameborder="0" allowfullscreen></iframe></center>
<br>
~~~

Understanding data types in a compiled language is important. By knowing the data type used, you know the memory required and the range of values it can hold, as well as how to handle the data type in a mathematical operation. 

Here is a table listing the main data types for a 32-bit system. `Void` denotes empty space, it is not a data type per se. It is used to indicate, for example, that a function does not take any variables, or does not return any variables. 

| C Data Type    | C99 keyword  | Precision & Interpretation |           Range           |
|----------------|--------------|----------------------------|:-------------------------:|
| void           | void         | No Memory                  |         Valueless         |
| unsigned char  | uint8_t      | 8-bit (unsigned)           |          0 to 255         |
| signed char    | int8_t       | 8-bit (signed)             |        -128 to 127        |
| unsigned short | uint16_t     | 16-bit (unsigned)          |         0 to 65535        |
| short          | int16_t      | 16-bit (signed)            |      -32768 to 32768      |
| unsigned int   | unsigned int | 32-bit (unsigned)          |      0 to 4294967295      |
| int            | int          | 32-bit (signed)            | -2147483648 to 2147483647 |
| unsigned long  | uint32_t     | 32-bit (unsigned)          |      0 to 4294967295      |
| long           | int32_t      | 32-bit (signed)            | -2147483648 to 2147483647 |
| float          | float        | 32-bit float               |    $+/-10^{-38}$ to $+/-10^{38}$    |
| double         | double       | 64-bit float               |   $+/-10^{-305}$ to $+/-10^{305}$   |

## Standard data type sizes
The bare C data types do not indicate the size of the data, their sizes can actually be different from one CPU architecture to another. 

A char is usually 1 byte, or 8 bit. We can specify if we want a signed or unsigned char by including the unsigned or signed keywords. 

The C99 keyword, or the standard library types are better to use. Since they self identify the data type: its size and whether it is signed or unsigned. The data type name tells it all, no need to remember.

For the ARM architecture, which is the architecture most widely used nowadays in embedded systems. An int is defined as a 32-bit signed data type. 

## Decimal Precision
At the bottom of the list we have `float` and `double`. These are two data types to be used if the variable needs to store non-integer values, whenever you have a fraction or decimal component basically. A double is a 64-bit data type, it’s literally double the size in bits to float. As you can see the precision of the 32-bit float is up to 10^(−38), while the 64-bit double can give a precision of 10^(−305), that’s up to 305 decimal points. 

The number of decimal points is dynamically allocated with floating point numbers. The data bits of a float or double are shared between a sign bit, an exponent or what’s to the left of the decimal point and the fraction or what’s to the right of a decimal point.

<!-- TODO: Add illustration for float -->
Next: [Variables](../lesson4/)



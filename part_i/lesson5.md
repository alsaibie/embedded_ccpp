@def title = "I Fundamentals - Arrays & Characters"
@def hascode = true

# Arrays
~~~
<center><iframe title="vimeo-player" src="https://player.vimeo.com/video/386449984" width="640" height="370" frameborder="0" allowfullscreen></iframe></center>
<br>
~~~

When you need to store a series of numbers or characters of the same data type, you can use arrays. The elements of an array are stored next to each other in memory. Imagine adjacent and similar houses along a neighborhood street. To find the memory size of the array, multiply the array size by the byte size of the data type of the array. An 4 element array of uint16_t (two bytes) would require 2x4=8 bytes of memory in storage. 

Let's take a look at how we can declare, define and access arrays.  

\input{cpp}{snippet1.cpp}
\input{plaintext}{output/snippet1.txt}

To declare an array you need to specify its type, give it a valid name and postfix it with a bracket and a number denoting the size of the array. To create a two-dimensional array you can use two brackets and so on.

There are multiple ways to define an array. Elements of the array can be defined inside curly braces with a comma separator. Array A is a 5 element array and here we declared AND defined the array, giving the following five values to the array: 1,2,3,4,5.

For multi-dimensional arrays we can define inner dimensions subarrays. Here the array B is a 3 by 2 array and we declared and defined the array. Note how we define the 3 – 2 element arrays. 

Array C here is a float type array of size 2. We defined the array by assigning the value 0.0, what happens here is the remaining elements get assigned a value of zero.   

Array D is a three element array, only two elements are defined. The last element is defaulted to zero. 

In C/C++ indexing starts from 0. To access the first element of the array we call the zeroth index. Calling A[2] here would retrieve the value 3, the third element of the array. 

Calling B[2][0] here would retrieve the 1st elements of the third sub-array, which returns 100. 

# ASCII Characters
Arrays can be used to store a series of letters and other characters to form words and sentences. Before we discuss that, we have to first introduce ASCII characters. 

ASCII stands for American Standard Code for Information Interchange. It is a standard for expressing a list of characters mapped to a sequential list of numbers. 

Initially, ASCII characters were based off of 7-bit encoding. So only 127 characters were defined. Then came the extended ASCII characters which have 8-bit encoding, giving us 255 characters. 

When ASCII characters are referenced nowadays, they refer to the 8-bit encoding 255 characters. Recall that a char data type is an 8-bit integer. Which explains the origin of the char keyword.

~~~<center><img src="/assets/part_i/media/ASCII-Table-wide.svg" style="max-width:786px"></center>~~~

**~~~
<center>ASCII Table. <a href="https://en.wikipedia.org/wiki/File:ASCII-Table.svg">Source</a></center>~~~**

# Character Arrays
Let’s look at the different ways we can work with character assignments in C++. 

\input{cpp}{snippet2.cpp}
\input{plaintext}{output/snippet2.txt}

We assign the value **68** to the variable **A**. From the ASCII table, the decimal number **68** maps to the capital letter **D**. 

If we were to print the decimal value of **A** we would get **68**. What we did here is change the type of **A** from an unsigned 8-bit int to an int which is a 32bit signed int. Type casting is discussed separately. 

But note what happens when we print **A** without type casting. Since the type of **A** is **uint8\_t**, which equates to a **char**, it is thus treated as a character and the stream would output the letter D. If we defined A to be **uint16\_t** instead, the output of **A** would be the decimal 68 not the capital D. This is a subtle issue but worth noting. Again the decimal value 68 or the character D are two equal values represented differently. 

To assign an **ASCII** character to a variable we can use single quotes. Here we assign the character 8, not the *number* 8, but the *character* 8 to the variable **B**. 

We can store a string of characters into an array by using *double quotes*. The difference between single and double quotes, is that a double quote includes a **NULL** terminator at the end of the string.  The NULL terminator marks the end of a string. Say you are sending a stream of strings, in order for the receiver to know where each string terminates, it will look for the character **NULL** which has the numeric value of 0 in the ASCII table.

Next: [Type Qualifiers and Storage Specifiers](../lesson6/)
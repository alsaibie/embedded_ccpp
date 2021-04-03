@def title = "I Fundamentals - Control Structures"
@def hascode = true

# Control Structures
~~~
<center><iframe title="vimeo-player" src="https://player.vimeo.com/video/386947527" width="640" height="370" frameborder="0" allowfullscreen></iframe></center>
<br>
~~~
A flow control structure is a block of a program that determines the direction of the code flow given certain conditions. 

In C/C++ we have the selection structures if/else and the switch statement. And we have the loop structures for, while and do while loops.

Let’s look at an example for each.

## If Statement
An **if statement** can contain at least an **if** logical condition and if it is true, a block of code within the curly braces would be executed.
An **if statement** can optionally have multiple **else if** statements, but only one **else** statement. 

\input{cpp}{snippet1.cpp}
Output:
\input{plaintext}{output/snippet1.txt}

Going down the list of if conditions, once the condition is true, the code will be executed and no further logical checks will be performed. That's why the else condition is kept at the end, if none of the above conditions are met, then do the **else** routine.

## Switch Statement
A switch statement is the other selection structure in C/C++. You can arguably perform the same functionality with an **if-statement**. Sometimes a switch statement can be more expressive of the intent. 

\input{cpp}{snippet2.cpp}
Output:
\input{plaintext}{output/snippet2.txt}

The way the switch statement works, is by starting off with the switch keyword and then passing a variable or expression here. 
```cpp
switch (k) {
    /* cases are checked */
}
```
Then, inside a curly braces block, we use the **case** keyword to identify the possible values to check for. Is k equal to 2?
```cpp
    case 2:
        cout << "case 2" << endl;
```
If a case is met, for example here k=3 and so the second case is met. 

But note that case 4 is also executed here. The code after the colons will be executed and **all** the following codes that proceed even in the remaining cases, will also be executed until a **break** keyword is reached or the switch statement is completed.

### Breaking the switch statement
Here, we repeat the example but notice how we add the **break** keyword at the end of every case code. So, when case 3 is met, the program will print out case 3 and then break away from the switch statement.

\input{cpp}{snippet3.cpp}
Output:
\input{plaintext}{output/snippet3.txt}

This subtlety is often missed by beginners. Always include a break statement, unless you want the proceeding routines to be executed as well. 

## For Loop
Probably the most famous loop structure in the world is the for loop. A for loop is intended for repeating a block of code given a start and end condition. 

\input{cpp}{snippet4.cpp}
Output:
\input{plaintext}{output/snippet4.txt}

A for loop in C/C++ is written in the following form, the **for** keyword is used and then **three** elements are defined, the first is an **initializer**, this is executed once, then the **condition**, this is check for trueness and the loop will repeat if it is true, the last is an **operation** that is performed at every loop. This is often used to increment the loop index as shown. Note that you can choose to increment the loop index within the for loop.

Here k is declared and initialized to zero, then the condition for which the loop will continue is that k is less than or equal to 5, and every time the loop is run k is incremented by 1. How many times will this loop code be executed?
```cpp
 for (int k = 0; k <= 5; k++){}
```
Also note that the scope of the loop index variable k is just within the **for loop** structure, it has no definition outside of the for loop here. 

The code will be executed 6 times since we started from 0 and ended at and included 5. 

## While Loop
A while loop keeps executing a code block as long as the condition within the while logical statement is true. 

\input{cpp}{snippet5.cpp}
Output:
\input{plaintext}{output/snippet5.txt}

A while loop and if loop can often be used interchangeably for the same purpose. 

Here we initialized the variable k outside the loop. This time the variable k has a local scope outside the flow structure. 

Then we pre-increment the variable k and check if it is less than 5. If so, execute the code. 

Note that the code was executed only 4 times. That’s because we pre-incremented k, so we started at 1 before the first time we checked the while loop condition, and we only specified the while condition to be true if k is **less** than 5.

### Infinite While Loops
You will often see an infinite loop in embedded systems. 

\input{cpp}{snippet6.cpp}
Output:
\input{plaintext}{output/snippet6.txt}

An infinite loop is a loop that is always, true. It is infinite in the sense that it will repeat itself forever. 

However, you can still break away from an infinite loop if you use the break keyword.
```cpp
    if (k == 6) break; /* This will break the program from the loop */
```
A real world example is when you have a robot waiting for a GPS signal lock before it starts moving, perhaps an infinite while loop is needed to keep checking if the signal is received, once received we can use the break keyword to break from the loop and proceed with the remaining program steps.

## Do While
A do-while loop is similar to a while loop but for one difference. A do-while loop executes the loop the first time regardless if the condition in the while is true or not, then on the second iteration onward the while logic statement is checked. 

\input{cpp}{snippet7.cpp}
Output:
\input{plaintext}{output/snippet7.txt}

Here, this code is only executed once, since `k` is zero at the beginning, then it is incremented. When the while loop checks if `k` is = 0, the statement is false, and so the loop is not executed the second time. 

Next: [Functions](../lesson9/)
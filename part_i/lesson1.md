@def title = "I Fundamentals - Introduction"
@def hascode = true

# Why C/C++?
~~~
<center><iframe title="vimeo-player" src="https://player.vimeo.com/video/386449837" width="640" height="370" frameborder="0" allowfullscreen></iframe></center>
<br>
~~~

## They dominate the embedded world
In the embedded world C and C++ are still the dominant languages. They are here to stay for the foreseeable future. 

You were probably taught to use MATLAB or Python (or hopefully Julia) in your numerical methods classes, and wonder why you can’t just use these languages in robotics, mechatronics or control applications.

You can, and there are sets of tools that attempt to do just that, but at a low micro-controller and embedded level it is not widely practiced in industry. Python and MATLAB are interactive scripting languages, they require a virtual machine, an operating system basically, to run in the background.

Not having to use a "virtual machine", means there is much less overhead. And by overhead we refer to additional resources, that both affect code size and speed of execution (well, code size and speed of execution are closely related). 

Mathworks (MATLAB) has a set of tools to convert their programs into C/C++ for embedded applications. But these tools are not widely adopter in this application space. 

In bigger and integrated systems, you will often see a mixed usage of programming languages, every language has its strength and weaknesses. For example, in a robotic application, you might be employing a Raspberry Pi and using Python to do some machine vision and supervisory level tasks, and in conjunction you may be using a micro-controller for controlling the actuators or processing data from sensors with C/C++ as your programming languages there. This is a very common setup.

## Python-based frameworks
There are, however, increasing efforts to introduce Python-based frameworks for teaching microcontroller programming, such as [Micro-Python](https://micropython.org/) and [Circuit-Python](https://circuitpython.org/) and it is arguable whether it is ready to be used for college-level courses in that space, but they are definitely worth considering for hobbyists and K-12 courses.   

## C/C++ are closer to the metal 
C/C++ are compiled languages. They are low level languages. Think of low-level languages as ones closer to the language the machine speaks in, or “machine language”. C/C++ compilers map code directly to assembly language, which in turn map to machine code. 

Direct mapping to machine language also means that code execution is deterministic, you can judge exactly how long and how much memory a procedure would take, an important thing in safety-critical and high-speed applications.

## Arduino is not a programming language
Just a reminder, there is no such thing as an Arduino **language**. Arduino is a framework written in C/C++. To proficiently use the Arduino ecosystem, a good working knowledge of C/C++ is a must. 



## Machine Code vs. Assembly vs. C/C++
In the early days of computers, they were programmed using machine code. Machine code is composed of 1’s and 0’s, then came a human readable machine code language called Assembly Language. 

Assembly language provides a set of instruction symbols for each of the possible instructions available on a specific machine. An assembly language programmer has to form the code logic using the set of instructions available, which can be different from one CPU architecture and family to another. So, portability of assembly code is not straight forward. And this was an issue.

Assembly was used in microcontroller programming for a long time, and is still used today, but, to a lesser degree. This is primarily due to the increasing capacity of modern computers (memory is cheap, transistors are small). 

With C/C++, the code becomes much more portable, since compilers take off the load of mapping the code to the specific assembly instructions for x86 or ARM or 6086 architectures; the same C code can be compiled for an Intel laptop CPU and an ARM smartphone CPU and each will have different assembly instruction sets. 

The ability to map code to assembly and machine code, makes for a more predictable behavior in safety critical applications. If you are designing a control system for a space rocket, you can’t tolerate any uncertainty in the code behavior (you should not be using a scripting language here for example), the programmer for such a system would work very hard to test the code assuming predictable set of outputs. 

Here is a C/C++ function that takes an integer and returns the square product of that integer. 
```cpp
int square(int num) {
    return num * num;
}
```

And this is the equivalent assembly code (x86-64 gcc compiler). Note that each instruction (push, mov, etc) translates to physically coded machine instruction on the processor for which this code is compiled. You can measure with high confidence how the code will behave, and how much time it takes to execute. If you are designing a controller for a rocket, you need that level of consistency, detail and precision.

```arm
square(int):
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], edi
        mov     eax, DWORD PTR [rbp-4]
        imul    eax, eax
        pop     rbp
        ret
```

And here is the same square() function in assembly code, but compiled for a different target (32-bit ARM gcc compiler). 

```arm
square(int):
        str     fp, [sp, #-4]!
        add     fp, sp, #0
        sub     sp, sp, #12
        str     r0, [fp, #-8]
        ldr     r3, [fp, #-8]
        mov     r2, r3
        mul     r2, r3, r2
        mov     r3, r2
        mov     r0, r3
        add     sp, fp, #0
        ldr     fp, [sp], #4
        bx      lr
```

You can explore how a C/C++ program is compiled to different assembly code based on target, using [Compiler Explorer](https://godbolt.org/)

To compare between two algorithms, and judge whether one is more efficient than another, we usually consult the assembly code produced. It is a decisive measure. You may often find that two algorithms differ in efficiency on one target, but have the same efficiency on another. Studying compilers is a field of its own and outside the scope of this course.

## Need for speed
C/C++ are not only used in safety critical systems. They are widely used in gaming, servers and the low-level or device level of operating systems (device drivers, your mouse, camera, keyboard, harddisk etc.). Basically in any application that can benefit from faster (more efficient) code execution. 

In the last decade, new compiled programming languages have become accepted and used in high profile applications that tend to compete with C/C++, such as [GO](https://golang.org/) (developed by Google), [Rust](https://www.rust-lang.org/) (supported by Mozilla) and [Swift](https://developer.apple.com/swift/) (developed by Apple). 

There is still a long way to go before any of those languages beat C/C++. No one can predict the future, there are many factors and magic market-forces to consider. But it is safe to say that C and C++, are here to stay. 

# C vs C++
~~~
<center><iframe title="vimeo-player" src="https://player.vimeo.com/video/386449877" width="640" height="370" frameborder="0" allowfullscreen></iframe></center>
<br>
~~~

To casual users of the languages C++ seems to be C with classes. This is true on the surface, and is true for much of basic usages. When it comes to professional use they grow apart in many ways, not only in their methods but code architecture as well. For **beginners** in embedded programming, it is safe to state that C++ is C with classes, but don't hold this concept for too long. 

## C still dominates in the micro-controller world, but things are changing
Note that C is still the predominant language used in microcontroller programming. It is the language currently supported by chip manufacturers. In order to use C++ in microcontrollers, third-party frameworks or in-house setup is required (becoming easier). This is changing and chip makers might support C++ out of the box. This would be a strong driving factor in the adoption of a language as you can imagine.

The examples in this course, will be given in a C++ structure. But note that in the embedded world, not all the functionalities of C++ are wise to use, specifically on lower-end microcontrollers. Due, primarily, to the overhead they carry. Such as templates for instance. They are more useful and suitable for larger scale computers, such as desktop or higher end embedded systems. 

## Mixing C and C++
It is very common to find projects that use both C and C++ in the same program. 

By standard convention, C source files have the *\*.c* extension and C headers have the *\*.h* extension. 
Source files for C++ have the *\*.cpp* extension, and *\*.hpp* for the headers. 

As mentioned, a program can have a mixture of C and C++ code. A project may have most of the code base written in C and some specific apps written in C++, and the opposite can occur. Reasons for the mixture can vary. It could be that C++ objects are needed to make a better code architecture for an app working within a C code base. Or it could be that an existing robust C code is ported over to a C++ project. 

## OK, C or C++ for a new project? what's the deal?
Warning. Fierce debate on this issue. 

In short, use C++ if you can setup the compiler environment and are not restricted by an external requirement (industry standard, compatibility, external libraries). You can always strip down additional functionalities in C++ and have it behave as a "C program" if you are limited by resources or have a specific need. 

## Mixing in Assembly
Moreover, it is also possible to implement Assembly Language within a C/C++ project, in a straightforward manner actually. Perhaps a small piece of code is optimized in assembly and needs to be run very fast. 

But sleep tight and know that C/C++ compilers, when setup to optimize the code, can actually produce a very efficient and optimized set of assembly code. Arguably better than what an average assembly programmer can achieve.  

Next: [File and Program Structure](../lesson2/)  
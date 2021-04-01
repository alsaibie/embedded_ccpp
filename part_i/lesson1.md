@def title = "I Fundamentals - Introduction"
@def hascode = true

# Why C/C++?
~~~
<center><iframe title="vimeo-player" src="https://player.vimeo.com/video/386449837" width="640" height="370" frameborder="0" allowfullscreen></iframe></center>
<br>
~~~

## They dominate the embedded world
In the embedded world C and C++ are still the dominant languages. They are here to stay for the foreseeable future. 

And you would ask: we were taught to use MATLAB or Python in our numerical methods classes, can’t we use these languages in robotics, mechatronics or control applications?

Technically we can in some ways. It is not impossible, and there are sets of tools that attempt to do just that, but it is not widely practiced in industry. Python and MATLAB are interactive scripting languages, they require a virtual machine, an operating system basically, to run in the background.

## Python-based frameworks
There are, however, increasing efforts to introduce Python-based frameworks for teaching microcontroller programming, such as [Micro-Python](https://micropython.org/) and [Circuit-Python](https://circuitpython.org/) and it could be arguable whether it is ready to be used for college-level courses, but they are definitely worth considering for hobbyists and K-12 courses.   

## C/C++ are closer to the metal 
C/C++ are compiled languages. They are low level languages. Think of low-level languages as ones closer to the language the machine speaks in, or “machine language”. C/C++ compilers map code directly to assembly language, which in turn map to machine code. 

Just a reminder, there is no such thing as an Arduino language. Arduino is a framework written in C/C++. To proficiently use the Arduino ecosystem, a good working knowledge of C/C++ is a must. 

Not having to use a "virtual machine", means there is much less overhead. And by overhead we refer to additional resources, that both affect code size and speed of execution (well, code size and speed of execution are closely related). 

## Machine Code vs. Assembly vs. C/C++
In the early days of computers, they were programmed using machine code. Machine code is composed of 1’s and 0’s, then came a human readable machine code language called Assembly Language. 

Assembly language provides a set of instruction symbols for each of the possible instructions available on a specific machine. An assembly language programmer has to form the code logic using the set of instructions available, which can be different from one CPU architecture and family to another. So, portability of assembly code is not straight forward. And this was an issue.

Assembly was used in microcontroller programming for a long time, and is still used today, but, to a lesser degree. This is primarily due to the increasing capacity of modern computers (memory is cheap, transistors are small). 

With C/C++, the code becomes much more portable, since compilers take off the load of mapping the code to the specific assembly instructions for x86 or ARM or 6086 architectures; the same C code can be compiled for an Intel laptop CPU and an ARM smartphone CPU and each will have different assembly instruction sets. 

The ability to map code to assembly and machine code, makes for a more predictable behavior in safety critical applications. If you are designing a control system for a space rocket, you can’t tolerate any uncertainty in the code behavior (you should not be using a scripting language here for example), the programmer for such a system would work very hard to test the code assuming predictable set of outputs. 

## Need for speed
C/C++ are not only used in safety critical systems. They are widely used in gaming, servers and the low-level or device level of operating systems. Basically in any application that can benefit from faster (more efficient) code execution. 

In the last decade, new compiled programming languages have become accepted and used in high profile applications that tend to compete with C/C++, such as [GO](https://golang.org/) (developed by Google), [Rust](https://www.rust-lang.org/) (supported by Mozilla) and [Swift](https://developer.apple.com/swift/) (developed by Apple). 

There is still a long way to go before any of those languages beat C/C++. No one can predict the future, there are many factors and magic market-forces to consider. But it is safe to say that C and C++, are here to stay. 

# C vs C++
~~~
<center><iframe title="vimeo-player" src="https://player.vimeo.com/video/386449877" width="640" height="370" frameborder="0" allowfullscreen></iframe></center>
<br>
~~~

Let’s have a look at the differences between C and C++. To many users of the languages C++ seems to be C with classes. This is true on the surface, and is true for much of basic usages. When it comes to professional use they grow apart in many ways. For **beginners** in embedded programming, it is safe to state that C++ is C with classes, but don't hold this concept for too long afterwards. 

## C still dominates in the micro-controller world, but things are changing
Note that C is still the predominant language used in microcontroller programming. It is the language currently supported by chip manufacturers. In order to use C++ in microcontrollers, third-party frameworks or in-house setup is required. This might change soon and chip makers might support C++ out of the box. And this would be a strong driving factor in the adoption of a language as you can imagine.

Much of the examples in this course, will be given in C++. Also note / that in the embedded world, not all the functionalities of C++ are wise to use, specifically on lower-end microcontrollers. Due, primarily, to the overhead they carry. Such as templates for instance. They are more useful and suitable for larger scale computers, such as desktop or higher end embedded systems. 

## Mixing C and C++
It is also common to find projects that use both C and C++ in the same program. 

By standard convention, C source files have the *\*.c* extension and C headers have the *\*.h* extension. 
Source files for C++ have the *\*.cpp* extension, and *\*.hpp* for the headers. 

As mentioned, a program can have a mixture of C and C++ code. A project may have most of the code base written in C and some specific apps written in C++, and the opposite can occur. Reasons for the mixture can vary. It could be that C++ objects are needed to make a better code architecture for an app working within a C code base. Or it could be that an existing robust C code is ported over to a C++ project.

## Mixing in Assembly
Moreover, it is also possible to implement Assembly Language within a C/C++ project, in a straightforward manner actually. Perhaps a small piece of code is optimized in assembly and needs to be run very fast. But sleep tight and know that C/C++ compilers, when setup to optimize the code, can actually produce a very efficient and optimized set of assembly code. Arguably better than what an average assembly programmer can achieve.  

Next: [File and Program Structure](../lesson2/)  
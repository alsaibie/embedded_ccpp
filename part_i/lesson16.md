@def title = "I Fundamentals - C/C++ Process Flow"
@def hascode = true

# C/C++ Process Flow
Now that we’ve review the fundamentals of C/C++ let’s review the compilation workflow. As a beginner, it is useful to have a general understanding of the workflow

~~~
<center><img src="/assets/part_i/media/CCPP_Process_Flow.svg" style="max-width:785px"></center>~~~

As programmers we spend most of our time writing code in source and headers files. 

Once we hit **build**, the preprocessor performs its tasks, carries out all the preprocessor directives and creates a map of the files to be compiled. It goes around the file system and looks for the included headers. 

The compiler then converts the code into machine language. This includes all the source files you included in the project, which would be specified in the compiler configuration. Some compilers such as the gcc compiler first produce an assembly code then machine code. 

The linker connects and maps the compiled files and precompiled object files and library files and produces an executable file.


Next: [Debugging](../lesson17/)

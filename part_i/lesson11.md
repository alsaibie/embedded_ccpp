@def title = "I Fundamentals - Structs"
@def hascode = true
# Structs
~~~
<center><iframe title="vimeo-player" src="https://player.vimeo.com/video/387520821" width="640" height="370" frameborder="0" allowfullscreen></iframe></center>
<br>
~~~

## Struct Structure
Supported in C and C++, structs provide a way to group variables of mixed data types into one element. That element is a struct (meaning structure). 
\input{cpp}{snippet1.cpp}
\input{plaintext}{output/snippet1.txt}
You can define multiple variables within a struct, each with a different data type and name. When accessing the struct, the struct elements can be accessed by name. 

By default, when creating a struct, you are creating the template of the struct. Creating an instance of the struct is an additional step. 

[L1] here, we declare a struct type and include three variables. 

[L2] Here we declare a different struct, and include an array , variables and a struct. Yes, structs can embed other structs. 

[L3] Note, again, that the struct created is only a template. Here we actually create an instance of the struct person_t called Ahmad. Now the struct Ahmed has the members: name , class_year, gender and the test scores struct which then has the midterm and final grades.

## Accessing Struct Members
Once a struct instance is created, we can access its members by the dot operator. 

[Lstring] Here we use the function string copy to copy over the literal string to the name array.

\input{cpp}{snippet2.cpp}
\input{plaintext}{output/snippet2.txt}
## 

\input{cpp}{snippet3.cpp}
\input{plaintext}{output/snippet3.txt}

[L1] We can create multiple instances of the struct after the struct declaration, separated by comma, ending with a semicolon. Note that these struct instances are global. 

[L2] We can pass a struct to a function. Here we pass the struct by reference, so the original struct is access directly, not a copy of it. 

[Llast] And since Sara, and Abdullah are global struct instances, they can be accessed anywhere in the file. 


##
[Lmiddle] A function can actually return a struct. Note that it will return a copy of a struct, perhaps this may not be the most efficient way, especially if the struct is large or this function is called many times. 
 
\input{cpp}{snippet4.cpp}
\input{plaintext}{output/snippet4.txt}

[Llast] Since the add_age_2 function returns a struct, we can copy over the returned struct to Ahmad struct. Again, this might not be the most efficient way to do it.






Next: [Classes](../lesson12/)
@def title = "I Fundamentals - Classes"
@def hascode = true

# Classes
## Here comes the big one
A feature of C++ and not C, and one that differentiates C++ most from C is classes. 

Classes extend the concept of structs, to not only include variables, structs and arrays, **but** it can include **functions**. Think of a struct as a data block, and think of a class as a data block + functions that operate on these data blocks (in addition to inputs/outputs).

\input{cpp}{snippet1.cpp}
Output:
\input{plaintext}{output/snippet1.txt}

An instance of a class is called an **object**, hence the term object-oriented-programming (OOP). 

Structs and classes shared similar features such as inheritance, public/private accessibility, initialization. But these features are generally introduced in the context of classes. 

The programmer can explore later those similarities. For a beginner, it is sufficient to treat structs as a way to store mixed data type elements and then come to treat classes in more detail.

To create a class, we use the `class` keyword. We give a name to the class and then define the class elements. Here we are declaring a class named `student`, remember, just like with structs, this is only a "template" or shape, not an instance. 

Note the `public` keyword. This tells the compiler that the lines below it can be accessed outside the scope of the class, i.e they can be accessed from `main()`. Note here we have two functions `set_id` and `get_id`.
```cpp
class student { /* A class is defined by the “class” keyword */
    uint32_t id; /* By default, class members are private, can only be accessed indirectly */

    public: /* Makes the following declarations (class members) public */
    void set_id(uint32_t set_id);
    uint32_t get_id();
};
```

By default the elements of the class are private: meaning only members of the class can access them, for instance the variable id can only be accessed by the functions `set_id` or `get_id`.

To declare members public, we must explicitly include the public keyword. 

### Creating a class instance
When we create a class object, we are *instantiating* it. Here we create an object of the class `student`, named `Mona`
```cpp
    student Mona; /* A class object is declared */
```

### Defining class functions
Just like any function in C++. Class functions need to be defined. The standard way of doing this is by independently defining each class function, preceded by the class name and a double colon e.g. `student::`. The argument list and the return type must match, but the names of the argument variables don't have to match. You can also define the class functions inside the class definition. 

```cpp
/* The class functions need to be defined, note the class_name::function_name syntax*/
void student::set_id(uint32_t set_id){
    id = set_id; /* Takes an id value and stores it in internal class object private variable */
}
uint32_t student::get_id(void){
    return id; /* returns the value of the private variable */
}
```

>This is a good place to remind you that, in the C/C++ world and programming world in general, there are usually more than one way (many ways) of achieving the same functional result. Different schools of though will recommend different methods and philosophies, and every project will have a different design pattern and architecture.



## Class Constructors (plural)
This is one powerful feature of object-oriented-programming. 

When you instantiate a class object. You can setup and associate certain tasks to happen at the instantiation step.

This is done through the class constructor: as the name suggests, it constructs, as in, sets up the object instance. 

\input{cpp}{snippet2.cpp}
Output:
\input{plaintext}{output/snippet2.txt}

The constructor is a **function** that belongs to the class, it gets called automatically when the object is created. 
- It should have the same name as the class name.
- You don't specify a return type. It will return a pointer to the class instance.
- It can take no arguments or many arguments, just like a regular function.

So, to create a constructor, when you create the class, you create a function that has the same name as the class. The constructor can take from void to any number of arguments. 

In this example we create a very basic class to hold student information. The only information it holds is the student id, which is a private member, meaning it cannot be accessed directly from outside the class, but only a class member function can access and manipulate it.
```cpp
class student {
    uint32_t id; /* By default, class members are private, can only be accessed indirectly */

    public: /* Makes the following declarations (class members) public */
    student(uint32_t set_id); /* A class constructor is a function that has the same name as the class */
    ~student(){};  /* A class deconstructor has the same name as the class with a ~ prefix */
    uint32_t get_id();
};
```

We create the constructor such that it takes the ID value. Looking at the definition of the class constructor, we see that it assigns a value to the id variable inside the class from the passed value to the object name. 
```cpp
/* The class constructor has no return element */
student::student(uint32_t set_id){
    id = set_id; /* A class constructor can be used to initialize  */
}
```

Here, the instance Mona is created and the following number is given to the object name. This in effect calls the constructor of the student class and passes the number to it. 
```cpp
int main(void){
    student Mona(212121); /* A class object is declared, and given the id */
    std::cout << Mona.get_id() << std::endl; 
    return 0;
}
```
And since the id variable is private member, in order to retrieve the value from outside the class we need an access or getter function such as `get_id()`

What if we instantiate a class object without giving it an int, or what if we instantiate it with two arguments?
```cpp
student Dalal(); /* Error, will not compile */
student Bassam(12, 25);  /* Error, will not compile */
```
In both cases above, there are no constructors within the class `student` that match the signature. You need another constructor that takes no arguments, and another that takes two integers. 

## Multiple constructors
A class can have multiple constructors, they all have to have the same name which is the name of the class, but the constructor function can be **overloaded**. 

\input{cpp}{snippet3.cpp}
<!-- Output:
\input{plaintext}{output/snippet3.txt} -->

Overloading is when you have two functions that share the same name but are differentiated based on their argument list. 

Here the student class has two constructors, student with no argument and student with the id argument. 
```cpp
student() { id = 1000; }; 
student(uint32_t set_id) { id = set_id; }; 
```
Notice that the constructors are **defined** within the class. And only `get_id` is defined outside the class.
>Defining class member functions inside or outside the class in general depends on the structure of the project, the size of the functions, and whether you are separating class interface from implementation (header vs source files). 

In this example. Using the same class we instantiate two objects: Ahmad object will use the first constructor with no argument since no argument was given to it, its id will be defaulted to 1000. 

The object Mona will implement the second constructor since an int was given. 
```cpp
int main(void){
    student Ahmed; /* The first constructor: student(), will be used */
    student Mona(121212); /* The second constructor: student(uint32_t set_id), will be used */ 
    return 0;
}
```
This idea can be extended, you can have a third constructor that takes two arguments or three or however many, or you can have a constructor that takes one argument as well but of different data type, like a signed 32bit rather than unsigned, or float rather than int. 

This feature allows for flexibility and modularity in designing classes. And is one of the main strength of OOP.
>Non OOP programming languages have other techniques of compensating for this. For example, in Julia, there are structs but no classes, and the modularity is achieved on creating multiple versions of the function (overloading), called multiple dispatch in Julia, to handle different types of data. 

Next: [Strings](../lesson13/)


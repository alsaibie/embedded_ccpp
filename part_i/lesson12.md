@def title = "I Fundamentals - Classes"
@def hascode = true

# Classes
## 1
A feature of C++ and not C, and one that differentiates C++ most from C is classes.

\input{cpp}{snippet1.cpp}
\input{plaintext}{output/snippet1.txt}

Classes extend the concept of structs, to not only include variables, structs and arrays, but it can include functions. 

An instance of a class is called an OBJECT, hence the term object-oriented-programming. 

Structs and Classes shared similar features such as inheritance, public/private accessibility, initialization. But these features are generally introduced in the context of classes. 

The programmer can explore later those similarities. For a beginner, it is sufficient to treat structs as a way to store mixed data type elements and then come to treat classes in more detail.

To create a class, we use the CLASS keyword. We give a name to the class and then define the class elements. 

By default the elements of the class are private: meaning only members of the class can access them, for instance the variable id can only be accessed by the functions set_id or get_id.

To declare members public, we must explicitly include the public keyword. 


## 2
This is one powerful feature of object-oriented-programming. 

\input{cpp}{snippet2.cpp}
\input{plaintext}{output/snippet2.txt}

When you instantiate a class object. You can setup and associate certain tasks to happen at the instantiation step.

This is done through the class constructor: as the name suggests, it constructs \ as in \ sets up the object instance. 

The constructor is a function that belongs to the class, it gets called automatically when the object is created. It should have the same name as the class name.

So, to create a constructor, when you create the class, you create a function that has the same name as the class. The constructor can take from void to any number of arguments. 

In this example we create a VERY basic class to hold student information. The only information it holds is the student id, which is a private member, meaning it cannot be accessed directly from outside the class.

We create the constructor such that it takes the ID value. Looking at the definition of the class constructor, we see that it assigns a value to the id variable in side the class from the passed value to the object name.

Here, the instance Mona is created and the following number is given to the object name. This in effect calls the constructor of the student class and passes the number to it. 

And since the id variable is private member, in order to retrieve the value from outside the class we need an access or getter function such as get_id()

## 3
A class can have multiple constructors, they all have to have the same name which is the name of the class, but the constructor function can be overloaded. 

\input{cpp}{snippet3.cpp}
\input{plaintext}{output/snippet3.txt}

Overloading is when you have two functions that share the same name but are differentiated based on their argument list. 

Here the student class has two constructors, student with no argument and student with the id argument. 

In this example. Using the same class we instantiate two objects: Ahmad object will use the first constructor with no argument since no argument was given to it, its id will be defaulted to 1000. 

The object Mona will implement the second constructor since an int was given. 

This idea can be extended, you can have a third constructor that takes two arguments or three or however many, or you can have a constructor that takes one argument as well but of different data type, like a signed 32bit rather than unsigned, or float rather than int. 


Next: [Strings](../lesson13/)


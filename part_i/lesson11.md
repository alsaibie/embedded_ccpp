@def title = "I Fundamentals - Structs"
@def hascode = true
# Structs
~~~
<center><iframe title="vimeo-player" src="https://player.vimeo.com/video/387520821" width="640" height="370" frameborder="0" allowfullscreen></iframe></center>
<br>
~~~

## Struct Structure
Supported in C and C++, structs provide a way to group variables of mixed data types into one element. That element is a struct (meaning structure). 

There is an important distinction here as well. When you define a struct, you are defining the **shape** of the struct. You then use this struct (shape) to create a struct **instance**.

\input{cpp}{snippet1.cpp}
<!-- Output: -->
<!-- \input{plaintext}{output/snippet1.txt} -->

You can define multiple variables within a struct, each with a different data type and name. When accessing the struct, the struct elements can be accessed by name. 

By default, when creating a struct, you are creating the shape of the struct. Creating an instance of the struct is an additional step. The struct resembles a composite **data type** in a way.

Here, we declare a struct type (its shape) and include three variables. Now we have `test_scores_t` that defines this new (data type) that has three int elements.
```cpp
struct test_scores_t{
    int midterm_1;
    int midterm_2;
    int final_exam;
};
```

Here we declare a different struct, and include an array , variables and a struct. Yes, structs can embed other structs. 
```cpp
struct person_t{
    /* a struct can accept a mixture of unordered types */
    char name[10];
    int class_year;
    char gender;
    test_scores_t test_scores; /* a struct can be nested within a struct */
};
```

Note, again, that the struct created is only a "template". Here we actually create an **instance** of the struct `person_t` called `Ahmad`. Now the struct instance `Ahmed` has the members: name , class_year, gender and the test scores struct which then has the midterm and final grades.
```cpp
    person_t Ahmed;
```
## Accessing Struct Members
Once a struct instance is created, we can access its members by the dot operator. 
\input{cpp}{snippet2.cpp}
Output:
\input{plaintext}{output/snippet2.txt}

Here we use the function string copy to copy over the literal string to the name array. More on strings later.
```cpp
    strcpy(Ahmed.name, "Ahmed");
```
## Manipulating Structs

\input{cpp}{snippet3.cpp}
Output:
\input{plaintext}{output/snippet3.txt}

```cpp
test
test2
```
We can create multiple instances of the struct after the struct declaration, separated by comma, ending with a semicolon. Note that these struct instances are global. 
```cpp
struct person_t{
    int age; char gender; char name[10];
}Sara, Abdullah; /* Struct objects can be created, they are global */
```
We can pass a struct to a function. Here we pass the struct by reference, so the original struct is access directly, not a copy of it. 
```cpp
void add_age(person_t &person, int age){
    person.age = age;
}
```
```cpp
    add_age(Ahmed, 24);
```

And since Sara, and Abdullah are global struct instances, they can be accessed anywhere in the file. 
```cpp
void sub_routine(void){
    add_age(Sara, 19); /* Global structs can be accessed here */
    add_age(Abdullah, 21);
}
```

## Struct as function return
A function can actually return a struct. Note that it will return a **copy** of a struct here, perhaps this may not be the most efficient way, especially if the struct is large or this function is called many times. 
 
\input{cpp}{snippet4.cpp}
<!-- Output: 
\input{plaintext}{output/snippet4.txt} -->

Since the `add_age_2` function returns a struct, we can copy over the returned struct to Ahmad struct. Again, this might not be the most efficient way to do it.






Next: [Classes](../lesson12/)
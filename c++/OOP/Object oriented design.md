## Object oriented design
-------------------------
Article Name: Object oriented design <br>
Article Link: https://www.geeksforgeeks.org/oops-object-oriented-design/

## Notes
--------
- Structured Programming: Functions and Modules. Function centric code. Examples are C and PASCAL.
- Procedural Programming: Global Data and Functions. Examples are FORTRAN and COBOL.
- Object Oriented Programming: Classes and real time objects. Data centric code.

### Class
---------
An extended concept of the structure used in C. Abstract and User-Defined data type, it may contain any number of variables and functions.
```
class Notes {
    char subject[10];
    int pages;
    char content[INT_MAX];
}
```
The above class is visible to everyone.

### Object
----------
Implementation of class.
```
int main {
    Notes IP;
    IP.subject = "coding";
    IP.pages = 0;
}
```

### Data Abstraction
--------------------
Hiding out some part of the Data.

### Encapsulation
-----------------
Binding together data and functions that manipulate the data.

### Inheritance
---------------
One class inherits properties of another class called the parent class. Helps in achieving code reusability.
1. Child class can directly inherit from parent class.(single parent child)
2. Child class can inherit from two different parent classes.(normal child)
3. Child class can inherit from a another child class which inturn inherited from a parent class.(child with grand parent)
4. Multiple child classes can inherit from single parent. (Children in Orphanage)

### Polymorphism
----------------
Data Processed in multiple forms.(recall SML, there is polymorhic data types like 'a, 'b, which can be of any type)
```
                polymorphism
               /            \
        compile time        run time
        /         \         |
    Function    Operator    Virtual
    Overloading Overloading Function
```
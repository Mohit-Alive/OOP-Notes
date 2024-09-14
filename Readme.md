# OOPS Notes

## Index

1. [Unit–2: Classes and Objects](#initializing-class-objects-with-constructors)
2. [Unit-3: Polymorphism](#unit-3-polymorphism)

<br><br><br>

# Unit–2: Classes and Objects

## Initializing Class Objects with Constructors
* A constructor is a special method that initializes an object when it's created.
* It has the same name as the class and no return type.
* Constructors can set initial values for member variables.
* They are automatically called when an object is created.
* Constructors help in avoiding uninitialized variables.

## Default and Parameterized Constructor
* Default constructor: A constructor with no parameters. It initializes objects with default values.
* If no constructor is provided, C++ automatically creates a default constructor.
* Parameterized constructor: Takes parameters to initialize objects with specific values.
* You can have both default and parameterized constructors in the same class.
* Parameterized constructors provide flexibility for object creation.

``` Cpp
#include <iostream>
using namespace std;

class Circle{
    float radius;
    float PI = 3.14;
    
    public:
        Circle(){
            radius = 0;
        }

        Circle(float r){
            radius = r;
        }
        
        float circleArea(){
            return PI*radius*radius;
        }
};

int main() {
    Circle obj(5);
    cout<<obj.circleArea()<<endl;

    return 0;
}
```

## Destructors
* A destructor is called when an object goes out of scope or is deleted.
* It has the same name as the class but is prefixed with a ~ (tilde).
* It’s used to release resources like memory or file handles.
* Destructors do not take parameters or have a return type.
* Automatically called by the compiler to clean up.

## Constant Variables and Constant Member Functions
* Constant variables: Their values can’t be changed after initialization.
* Declared using the const keyword (e.g., const int x = 10;).
* Constant member functions: Can’t modify any class member variables.
* Declared with const after the function declaration.
* Helps in ensuring immutability for specific parts of a class.

```cpp
// Constant Data Members
const float PI = 3.14;

// Constant Member function
float circleArea() const{
            return PI*radius*radius;
        }
```

## Static Data Member 
* Belongs to the class, not to any specific object: Static Data Member are shared among all instances of the class.
* Can only access static members: They can only access static variables or other static functions, as they don’t have access to instance variables.

```cpp
// Declaration of static member function
public:
    static int count;

// Outside class
int Circle:: count = 1;
```

## Objects as Members of Class
* You can include objects of one class as member variables in another class.
* This allows complex object relationships and composition.
* The constructor of the member object is called before the enclosing class’s constructor.
* It’s a way to implement "has-a" relationships between objects.
* Helps in building modular and reusable code.

```cpp
#include <iostream>
using namespace std;

class Marks
{
    int rno;
    float percentage;

public:
    Marks(int r, float p)
    {
        rno = r;
        percentage = p;
    }
    void printMarks()
    {
        cout << rno << endl;
        cout << percentage << endl;
    }
};

class Student
{
    Marks Mobj;
    string name;

public:
    void setName()
    {
        cin >> name;
    }
    void getResult(Marks obj)
    {
        Mobj = obj;
        cout << name;
        Mobj.printMarks();
    }
};

int main()
{
    Marks mk[5] = {Marks(100, 87), Marks(101, 56), Marks(102, 87), Marks(103, 78), Marks(104, 95)};
    Student st[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the name: ";
        st[i].setName();
    }
    for (int i = 0; i < 5; i++)
    {
        st[i].getResult(mk[i]);
    }
    return 0;
}
```

## Abstract Class
* An abstract class can’t be instantiated directly.
* It contains at least one pure virtual function (declared with = 0).
* Used as a base class to provide a common interface for derived classes.
* Derived classes must implement the pure virtual functions.
* Encourages polymorphism by allowing different classes to share the same interface.

## Friend Function
* A non-member function that can access private and protected members of a class.
* Declared using the friend keyword inside the class.
* Useful when external functions need special access to the class’s internals.
* Doesn’t break encapsulation if used carefully.
* Can be a function or another class.

```cpp
#include<iostream>
using namespace std;

class Shape{
   
    protected:
        int shape_length;
        int shape_width;
       
    public:
         void getLength(int l){
            shape_length = l;
        }

        void getWidth(int w){
            shape_width = w;
        }

        virtual int getPerimeter() = 0;
       
};

class Rectangle : public Shape{
    public:
        int getPerimeter(){
            return (2*(shape_length + shape_width));
        }

};


class square: public Shape{

     public:
        int getPerimeter(){
            return (4*shape_length);
        }
        friend int circlePerimeter (square obj);
       
};

int circlePerimeter(square sq){
    int radius = sq.shape_length;
    return (2* sq.shape_length* 3.14);
}

int main(){
    square sqobj;
    Rectangle rectobj;
    rectobj.getLength(10);
    rectobj.getWidth(5);
    cout<<rectobj.getPerimeter()<<endl;
    sqobj.getLength(10);
    cout<<circlePerimeter(sqobj)<<endl;

    return 0;
}
```

## Dynamic Memory Allocation
* Memory is allocated during runtime using new (for allocating) and delete (for deallocating).
* Allows flexible memory management, especially for arrays and objects.
* Helps in handling large data structures like linked lists, trees, etc.
* Avoids memory wastage by allocating memory only when required.
* Requires careful management to avoid memory leaks.

```cpp
#include <iostream>
using namespace std;

class Book {
    int BookId;
    int Pages;
    int Prices;
    
    public:
        void setBook(int b,int p, int pr ){
            BookId=b;
            Pages=p;
            Prices=pr;
            
        }
        int getBookId(){
            return BookId;
        }
        int getPages(){
            return Pages;
        }
        int getPrices(){
            return Prices;
        }
        
        void showBookDetails(){
            cout<<"Book ID :"<<BookId<<endl;
            cout<<"Pages   :"<<Pages<<endl;
            cout<<"Prices  :"<<Prices<<endl;
            
        }
        
};
int main(){
    Book *book1 = new Book;
    book1->setBook(250,560,950);
    book1->showBookDetails();

    return 0;
}
```

## Proxy Classes
* A design pattern where an object controls access to another object.
* The proxy class provides an interface similar to the real object but adds additional functionality like caching or logging.
* Used for lazy initialization, controlling access to expensive resources.
* Often used in network connections or file access.
* Provides a level of abstraction and control over object creation and access.
<br><br><br>

# Unit-3: Polymorphism

## Concept of Polymorphism

* Polymorphism allows objects of different classes to be treated as objects of a common base class.
* It is primarily achieved through function overriding and inheritance.
* Polymorphism enables a single function or operator to operate in different contexts.
* It can be static (compile-time) or dynamic (runtime) polymorphism.
* Promotes code flexibility and reuse.

## Compile-time and Runtime Overloading
* Compile-time overloading (static polymorphism) happens through function overloading and is determined at compile time, whereas runtime overloading (dynamic polymorphism) uses virtual functions and is determined at runtime.
* Compile-time overloading is faster since the function is resolved during compilation, while runtime overloading provides more flexibility but can have a slight performance overhead due to runtime decision-making.

## Function Overloading

* Function overloading allows multiple functions with the same name but different parameters.
* The compiler differentiates functions by the number or type of arguments.
* It provides readability by using meaningful function names.
* Used to perform similar operations with different input types.
* Helps in implementing polymorphism at compile-time.

```js
//Function Overloading

int area(int side){
}
int area(int length, int width){
}
int area(int length, int width, int height){
}
```

## Constructor Overloading

* Multiple constructors can be defined in a class with different parameter lists.
* Each constructor performs different initialization based on the arguments passed.
* Allows flexibility in creating objects with various initialization setups.
* Reduces code duplication by centralizing object construction logic.
* The constructor called depends on the number and types of arguments provided when creating the object.

``` js
// Constructor Overloading

class Area{
    Area(){
    }
    Area(int side){
    }
    Area(int length, int width){
    }
};
```
## Operator Overloading

* Allows operators (like +, -, *, etc.) to be overloaded to work with user-defined types (e.g., classes).
* Provides the ability to define custom behavior for operators when applied to objects.
* Ensures operators are intuitive for class instances, improving code readability.
* Overloading maintains consistency with built-in types for user-defined types.
* Can be used to overload both unary (e.g., ++) and binary operators (e.g., +).

### Restrictions on Operator Overloading

* Not all operators can be overloaded (e.g., ::, .?, sizeof, typeid).
* Precedence and associativity of operators cannot be changed.
* New operators cannot be created; only existing ones can be overloaded.
* Operators must maintain the expected behavior, especially for built-in types.

### Overloading Operators: <<, >>, Unary Operators, Binary Operators
* << and >>: Overloaded to perform input/output operations on user-defined objects (like cout and cin).
* Unary Operators: These operators (e.g., ++, --, -, !) can be overloaded to work with single objects.
* Binary Operators: Operators like +, -, *, = can be overloaded to perform operations between two objects.

```js
// Syntax of Unary Operator Overloading
class ClassName {
public:
    // Overloading unary operator `++`
    ClassName operator++() {
        // Implementation
        return *this; // return the modified object
    }

    // Overloading unary operator `++` (postfix)
    ClassName operator++(int) {
        // Implementation
        return *this; // return the original object before modification
    }
};
```

```js
// Syntax of Binary Operator Overloading
class ClassName {
public:
    // Overloading binary operator `+`
    ClassName operator+(const ClassName& obj) const {
        // Implementation
        return *this; // return the result of addition
    }

    // Overloading binary operator `-`
    ClassName operator-(const ClassName& obj) const {
        // Implementation
        return *this; // return the result of subtraction
    }

    // Other binary operators can be overloaded similarly
};
```

```js
// Syntax of << >> Operator Overloading
class ClassName {
    int value;
public:
    ClassName(int v) : value(v) {}

    // Friend function for overloading binary operator `<<`
    friend ostream& operator<<(ostream& out, const ClassName& obj) {
        out << obj.value;
        return out;
    }

    // Friend function for overloading binary operator `>>`
    friend istream& operator>>(istream& in, ClassName& obj) {
        in >> obj.value;
        return in;
    }
};
```

``` js
// Example of Unary , Binary and << >> Overloading

#include <iostream>
using namespace std;

class Complex {
    double real, imag;
public:
    // Constructor
    Complex(int r, int i){
        real = r;
        imag = i;
    }

    // Overloading binary operator `+`
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overloading unary operator `-`
    Complex operator-() const {
        return Complex(-real, -imag);
    }

    // Overloading binary operator `<<` for output
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
};

int main() {
    Complex c1(3.0, 2.0);
    Complex c2(1.0, 7.0);
    
    Complex c3 = c1 + c2;    // Uses overloaded `+` operator
    Complex c4 = -c1;        // Uses overloaded `-` operator

    cout << "c1: " << c1 << endl;  // Uses overloaded `<<` operator
    cout << "c2: " << c2 << endl;  // Uses overloaded `<<` operator
    cout << "c3: " << c3 << endl;  // Uses overloaded `<<` operator
    cout << "c4: " << c4 << endl;  // Uses overloaded `<<` operator

    return 0;
}
```
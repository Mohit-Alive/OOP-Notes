# OOPS Notes

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
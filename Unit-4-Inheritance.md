# Unit-4: Inheritance

1. [Introduction to Inheritance, Types of inheritance](#introduction-to-inheritance-types-of-inheritance)
2. [Virtual function, Pure Virtual function](#virtual-function-pure-virtual-function)
3. [Abstract base classes, Pointer to derived class](#abstract-base-classes-pointer-to-derived-class)
4. [Use of Protected and Private Inheritance and Member Functions](#use-of-protected-and-private-inheritance-and-member-functions)
5. [Overriding Base Class Members in a Derived Class](#overriding-base-class-members-in-a-derived-class)
6. [Use of Constructors and Destructors in derived Classes](#use-of-protected-and-private-inheritance-and-member-functions)

## Introduction to Inheritance, Types of Inheritance

- Inheritance allows one class (derived) to inherit the properties and methods of another class (base), creating an "is-a" relationship.

- Single Inheritance: Involves a single base and derived class.
- Multiple Inheritance: A derived class inherits from multiple base classes. This can lead to ambiguity if the same method is present in multiple base classes.
- Multilevel Inheritance: A class inherits from a derived class, forming a chain (A → B → C).
- Hierarchical Inheritance: Multiple derived classes inherit from a single base class.
- Hybrid Inheritance: A combination of multiple and multilevel inheritance.

```cpp
#include <iostream>
using namespace std;

class A {
public:
    void greet() { cout << "Hello from A" << endl; }
};

class B : public A {}; // Single Inheritance
class C : public A {}; // Hierarchical Inheritance
class D : public B {}; // Multilevel Inheritance

int main() {
    D obj;
    obj.greet();       // Output: Hello from A
    return 0;
}
```

## Virtual Function, Pure Virtual Function

- Virtual Function: A function defined in a base class that can be overridden in derived classes for polymorphic behavior.

- Pure Virtual Function: A virtual function with no implementation in the base class, requiring derived classes to implement it.

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; // Pure Virtual Function
};

class Circle : public Shape {
public:
    void draw() override { 
        cout << "Drawing Circle" << endl; 
    }
};

int main() {
    Shape *shape = new Circle();
    shape->draw(); // Output: Drawing Circle
    delete shape;
    return 0;
}
```

## Abstract Base Classes, Pointer to Derived Class

- Abstract Base Class: A class with at least one pure virtual function.

- Pointer to Derived Class: Using base class pointers to point to derived class objects enables polymorphism.

```cpp
#include <iostream>
using namespace std;

class Animal { // Abstract Base Class
public:
    virtual void sound() = 0; // Pure Virtual Function
};

class Cat : public Animal {
public:
    void sound() override { 
        cout << "Meow" << endl; 
    }
};

int main() {
    Animal* a = new Cat(); // Pointer to Derived Class
    a->sound(); // Output: Meow
    delete a;
    return 0;
}
```

## Use of Protected and Private Inheritance and Member Functions
![](https://rndayala.wordpress.com/wp-content/uploads/2019/11/image-205.png)

- Protected Inheritance: Derived class inherits base class members as protected.

- Private Inheritance: Derived class inherits base class members as private.

```cpp
#include <iostream>
using namespace std;

class Base {
protected:
    void display() { cout << "Base Display" << endl; }
};

class Derived : protected Base { // Protected Inheritance
public:
    void show() { display(); } // Accessing protected member
};

int main() {
    Derived d;
    d.show(); // Output: Base Display
    return 0;
}
```

## Overriding Base Class Members in a Derived Class

- When a function in a derived class has the same name and parameters as one in the base class, it overrides the base class function, replacing its implementation. This allows for dynamic polymorphism.

- If a function is marked as virtual in the base class, derived class objects will use the overridden version at runtime.

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() { cout << "Base Display" << endl; }
};

class Derived : public Base {
public:
    void display() override { cout << "Derived Display" << endl; }        // Overridden
};

int main() {
    Base *b = new Derived();
    b->display();  // Output: Derived Display
    delete b;
    return 0;
}

```

## 4.6 Use of Constructors and Destructors in Derived Classes

- When creating derived class objects, the base class constructor is called first, followed by the derived class constructor.

- Similarly, on deletion, the derived class destructor is called first, followed by the base class destructor.

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base Constructor" << endl; }
    ~Base() { cout << "Base Destructor" << endl; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived Constructor" << endl; }
    ~Derived() { cout << "Derived Destructor" << endl; }
};

int main() {
    Derived d;
    // Output:
    // Base Constructor
    // Derived Constructor
    // Derived Destructor
    // Base Destructor
    return 0;
}
```

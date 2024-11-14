# Unit-5: Templates

1. [Function Templates]()
2. [Overloading Function Template]()
3. [Class Template, Class Templates and Non-Type Parameters]()
4. [Templates and Inheritance]()
5. [Templates and Friend classes]()
6. [Templates and Static Member]()

## Templates
- Templates in C++ provide a way to create generic functions and classes that can work with any data type. 

- This avoids code duplication by allowing us to define a single function or class to handle multiple types.

## 5.1 Function Templates
- A function template allows a function to operate with generic types.

- Can accept multiple template parameters using commas: template <typename T, typename U>.

- typename and class can both be used as placeholders, though typename is preferred for clarity.

```cpp
//Syntax

template <typename T>
T functionName(T parameter1, T parameter2) {
    // function body
}

// T is the template argument that acts as a placeholder for a data type.
```

```cpp
#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << "Sum of integers: " << add(3, 5) << endl;       // Output: 8
    cout << "Sum of floats: " << add(2.5, 3.5) << endl;     // Output: 6.0
    return 0;
}
```

## 5.2 Overloading Function Template
- Function Template Overloading refers to defining multiple templates with the same function name but different parameters, allowing the function to work with different types or numbers of arguments.

- Compiler chooses the appropriate function based on the number and type of arguments passed.

- If both function templates and regular functions are defined with the same name, the compiler prioritizes the non-template version when the exact type matches.


```cpp
// Syntax

template <typename T>
T add(T a, T b);

template <typename T>
T add(T a, T b, T c);  // Overloaded with an additional parameter
```

```cpp
#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

template <typename T>
T add(T a, T b, T c) {
    return a + b + c;
}

int main() {
    cout << "Two parameters: " << add(2, 3) << endl;            // Output: 5
    cout << "Three parameters: " << add(2, 3, 4) << endl;       // Output: 9
    return 0;
}
```

## 5.3 Class Template
- A class template allows defining a class with a generic data type.

- Useful for data structures like stacks, queues, and linked lists, which can work with any data type.

- Template classes are defined once and can be instantiated with different types.

```cpp
// Syntax

template <class T>
class ClassName {
    T data;
public:
    ClassName(T val) : data(val) {}
    T getData() { return data; }
};
```

```cpp
#include <iostream>
using namespace std;

template <class T>
class Container {
    T data;
public:
    Container(T val) : data(val) {}
    T getData() { return data; }
};

int main() {
    Container<int> intContainer(5);
    Container<double> doubleContainer(5.5);

    cout << "Integer Container: " << intContainer.getData() << endl;  // Output: 5
    cout << "Double Container: " << doubleContainer.getData() << endl; // Output: 5.5
    return 0;
}
```

### 5.3.1 Class Templates and Non-Type Parameters

- Non-type parameters in templates allow using values (like integers) as template arguments.

- Useful for creating arrays, matrices, or data containers of fixed size.

- Non-type parameters allow flexibility without using dynamic allocation.

```cpp
// Syntax

template <class T, int N>
class Array {
    T arr[N];
public:
    void set(int index, T value) { arr[index] = value; }
    T get(int index) { return arr[index]; }
};
```

```cpp
#include <iostream>
using namespace std;

template <class T, int N>
class Array {
    T arr[N];
public:
    void set(int index, T value) { arr[index] = value; }
    T get(int index) { return arr[index]; }
};

int main() {
    Array<int, 5> intArray;
    intArray.set(0, 10);
    cout << "First element: " << intArray.get(0) << endl;  // Output: 10
    return 0;
}
```

## 5.4 Templates and Inheritance
- Templates can be inherited, allowing derived classes to use template-based base classes.

- Useful when creating a base class with generic behavior that derived classes can extend.

- Allows for combining generic and specific functionality.
Derived classes can be non-template or template-based themselves.

```cpp
#include <iostream>
using namespace std;

template <class T>
class Base {
protected:
    T data;
public:
    Base(T val) : data(val) {}
};

class Derived : public Base<int> {
public:
    Derived(int val) : Base(val) {}
    void show() { cout << "Data: " << data << endl; }  // Output: Data: 5
};

int main() {
    Derived d(5);
    d.show();
    return 0;
}
```

## 5.5 Templates and Friend Classes
- Friend classes can access private members of template classes.

```cpp
#include <iostream>
using namespace std;

template <class T>
class ClassA;

template <class T>
class ClassB {
public:
    void show(ClassA<T>& a);
};

template <class T>
class ClassA {
private:
    T data;
public:
    ClassA(T val) : data(val) {}
    friend class ClassB<T>;
};

template <class T>
void ClassB<T>::show(ClassA<T>& a) {
    cout << "ClassA data: " << a.data << endl;  // Output: ClassA data: 10
}

int main() {
    ClassA<int> a(10);
    ClassB<int> b;
    b.show(a);
    return 0;
}
```

## 5.6 Templates and Static Member
- Static members in template classes are shared across all instances of the same template specialization.

```cpp
#include <iostream>
using namespace std;

template <class T>
class MyClass {
public:
    static int count;
    MyClass() { count++; }
    static void showCount() { cout << "Count: " << count << endl; }
};

template <class T>
int MyClass<T>::count = 0;

int main() {
    MyClass<int> obj1;
    MyClass<int> obj2;
    MyClass<double> obj3;

    MyClass<int>::showCount();    // Output: Count: 2
    MyClass<double>::showCount(); // Output: Count: 1
    return 0;
}
```


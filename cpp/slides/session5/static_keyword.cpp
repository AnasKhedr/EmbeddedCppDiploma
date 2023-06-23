#include <iostream>

// Static makes this variable only seen inside this C++ file(Translation unit -> object .o file)
static int globalVariable = 0;

class ExampleClass {
public:
    int memberVariable = 10;

    // 1. Static member variable that exists without ExampleClass instance (shared between all instances)
    // static int staticVariable;
    inline static int staticVariable;   // only use inline with C++17

    // 2. Static member function, function that can be used without an object\instance of ExampleClass(doesn't need this ptr)
    static void staticFunction() {
        std::cout << "Static function called." << std::endl;
        // memberVariable++; // error, to access member variables you need this pointer(static functions can't access non-static member variable)
    }

    // 3. Static local variable
    void nonStaticFunction() {
        static int staticLocalVariable = 0; // static variable keeps it's value between different invocations of this function
        staticLocalVariable++;
        std::cout << "Static local variable: " << staticLocalVariable << std::endl;
    }
};

// 1. Definition of static member variable (must be done outside the class)
// must do this before C++17
// int ExampleClass::staticVariable = 0;

void myFunction() {
    static int myStaticLocalVariable = 0; // static variable works with functions regardless being part of class or not
    myStaticLocalVariable++;
    std::cout << "My Static local variable: " << myStaticLocalVariable << std::endl;
}

int main() {
    // 1. Accessing static member variable
    ExampleClass::staticVariable = 42;
    std::cout << "Static variable value: " << ExampleClass::staticVariable << std::endl;

    // 2. Calling static member function, without having an instance
    ExampleClass::staticFunction();

    // Creating instances of ExampleClass
    ExampleClass obj1, obj2;

    // 3. Accessing and modifying static local variable
    obj1.nonStaticFunction();  // Static local variable: 1
    obj2.nonStaticFunction();  // Static local variable: 2
    obj1.nonStaticFunction();  // Static local variable: 3

    return 0;
}

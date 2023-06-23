#include <iostream>
#include <memory>

class MyClass {
public:
    ///TASK: your task is to use unique pointer and figure out how to move it
    // std::unique_ptr<int> data;
    int* data;

    // Default constructor
    MyClass() : data(nullptr) {
        std::cout << "Default constructor called." << std::endl;
    }

    // Constructor with data allocation
    MyClass(int _data) : data(new int) {
        *data = _data;
        std::cout << "Constructor called. data: " << *data << "." << std::endl;
    }

    // Copy constructor
    MyClass(const MyClass& other) : data(new int) {
        *data = *(other.data);
        std::cout << "Copy constructor called. Copied value " << *data << "." << std::endl;
    }

    // Move constructor
    MyClass(MyClass&& other) : data(nullptr) {
        data = other.data;
        other.data = nullptr;
        std::cout << "Move constructor called. Moved value " << *data << "." << std::endl;
    }

    // Copy assignment operator
    MyClass& operator=(const MyClass& other) {
        delete data;
        data = new int;
        *data = *(other.data);
        std::cout << "Copy assignment operator called. Copied value " << *data << "." << std::endl;

        return *this;
    }

    // Move assignment operator
    MyClass& operator=(MyClass&& other) {
        delete data;
        data = other.data;
        other.data = nullptr;
        std::cout << "Move assignment operator called. Moved value " << *data << "." << std::endl;

        return *this;
    }

    void printData()
    {
        if(data != NULL)
        {
            std::cout << "Data: " << *data << "\n";
        }
    }

    // Destructor
    ~MyClass() {
        if (data != nullptr) {
            delete data;
            // std::cout << "Destructor called. Deallocated memory." << std::endl;
        }
    }
};

MyClass factory()
{
    std::cout << "calling factory method\n";
    return MyClass(200);
}

MyClass factory2()
{
    std::cout << "calling factory2 method\n";
    MyClass tmp = MyClass(300);
    return tmp;
}

int main() {
    MyClass obj1(5);  // Constructor called. Allocated memory of size 5.
    obj1.printData();

    MyClass obj2;   // Constructor
    obj2 = obj1;  // Copy assignment operator called. Copied value <value from obj1>.
    obj2.printData();

    MyClass obj3;  // Constructor
    obj3 = std::move(obj1);  // Move assignment operator called. Moved value <value from obj1>.
    obj3.printData();

    // object 7 is still being constructed
    MyClass obj4(std::move(obj3)); // move constructor
    // MyClass obj4_ = std::move(obj3); // move constructor, Note you can't move obj3 2 times
    obj4.printData();

    // ---------------------------------------------
    // for you to read
    // ---------------------------------------------

    /*
    // why call move semantics? the factory returns a temporary.
    MyClass obj5(factory());     // the obj5 is not yet created so it doesn't make sense to create obj5 then move the temporary into it. the constructor function returns a temporary so this is the same as just calling the constructor
    // MyClass obj5 = factory();   // returns a temporary
    MyClass obj6 = factory2();  // returns a temporary

    // obj7 is already constructed, so the temporary that is returned by factory will have to replace the original
    MyClass obj7(3);
    obj7 = factory();   // call move because factory returns a temporary
    */

    return 0;
}

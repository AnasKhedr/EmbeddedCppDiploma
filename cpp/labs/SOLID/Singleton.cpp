#include <iostream>

// https://refactoring.guru/design-patterns/singleton

class Singleton {
private:

    // Private constructor to prevent instantiation
    Singleton() {
        std::cout << "Creating a new instance of Singleton class\n";
    }

public:
    // Static method to access the singleton instance
    static Singleton& getInstance() {
        static Singleton c_instance;    // this is created the first time getInstance is called
        return c_instance;
    }

    void showMessage() {
        std::cout << "Hello from Singleton!" << std::endl;
    }
};

int main() {
    // Trying to instantiate the Singleton
    // Singleton s; // This won't work (constructor is private)

    Singleton& s1 = Singleton::getInstance();
    s1.showMessage();

    Singleton& s2 = Singleton::getInstance();
    s2.showMessage();

    // The same instance is referenced
    std::cout << "Are s1 and s2 the same instance? " << (&s1 == &s2 ? "Yes" : "No") << std::endl;

    return 0;
}

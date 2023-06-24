#include <iostream>

// DIP: High-level modules should not depend on low-level modules. Both should depend on abstractions.

// Abstraction (interface) for the IPrinter dependency
class IPrinter {
public:
    virtual void print(const std::string& text) = 0;
};

// Low-level module (concrete implementation)
class ConsolePrinter : public IPrinter {
public:
    void print(const std::string& text) override {
        std::cout << "Printing to console: " << text << std::endl;
    }
};

// High-level module that depends on the IPrinter abstraction
class Document {
private:
    IPrinter& m_printer;

public:
    Document(IPrinter& printer) : m_printer(printer) {}

    void write(const std::string& text) {
        m_printer.print(text);
    }
};

int main() {
    ConsolePrinter consolePrinter;
    Document document(consolePrinter);
    document.write("Hello, World!");

    return 0;
}

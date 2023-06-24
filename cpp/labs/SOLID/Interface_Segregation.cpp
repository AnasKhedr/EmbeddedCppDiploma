#include <iostream>

// ISP: Clients should not be forced to depend on interfaces they do not use.

// Abstract printer interface
class IPrinter {
public:
    virtual void print() const = 0;
    // virtual void scan() const = 0;   // this is bad as printer only print
    // virtual void fax() const = 0;
};

// Scanner interface
class IScanner {
public:
    virtual void scan() const = 0;
};

// Fax interface
class IFax {
public:
    virtual void fax() const = 0;
};

// Super printer implements all interfaces
class SuperPrinter : public IPrinter,
                    public IScanner,
                    public IFax {
public:
    void print() const override {
        std::cout << "Super Printer: Printing..." << std::endl;
    }

    void scan() const override {
        std::cout << "Super Printer: Scanning..." << std::endl;
    }

    void fax() const override {
        std::cout << "Super Printer: Faxing..." << std::endl;
    }
};

// Regular printer implements only the printer interface
class RegularPrinter : public IPrinter {
public:
    void print() const override {
        std::cout << "Regular Printer: Printing..." << std::endl;
    }
};

int main() {
    // Using the Super Printer
    SuperPrinter superPrinter;
    superPrinter.print();
    superPrinter.scan();
    superPrinter.fax();

    // Using the Regular Printer
    RegularPrinter regularPrinter;
    regularPrinter.print();

    return 0;
}

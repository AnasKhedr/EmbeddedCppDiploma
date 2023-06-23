#include <iostream>

// this can accepts both rvalue and lvalue
// this is an rvalue reference but because we used const, C++ can implicitly cast rvalue reference to const lvalue reference
// void processValue(const int& value) {
//     std::cout << "const Lvalue reference: " << value << std::endl;
// }

void processValue(int& value) {
    std::cout << "Lvalue reference: " << value << std::endl;
}

void processValue(int&& value) {
    std::cout << "Rvalue reference: " << value << std::endl;
}

int main() {
    int x = 5;

    processValue(x);        // Calls the lvalue reference overload
    processValue(10);       // Calls the rvalue reference overload

    int&& y = 7;            // rvalue reference to a literal
    processValue(std::move(y));  // Calls the rvalue reference overload
    // processValue(static_cast<int&&>(y));  // this is the what move does, cast to an rvalue

    return 0;
}

#include <iostream>

// LSP: you should be able to use an object of a derived class wherever an object of its base class is expected,
// without causing any issues or unexpected behavior

// check this answer: https://stackoverflow.com/a/584732/6184259

// Rectangle shape
class Rectangle {
protected:
    double width;
    double height;

public:
    Rectangle(double width, double height) : width(width), height(height) {}

    void setWidth(double width) {
        this->width = width;
    }

    void setHeight(double height) {
        this->height = height;
    }

    double getWidth() const {
        return width;
    }

    double getHeight() const {
        return height;
    }

    double area() const {
        return width * height;
    }
};

// Square shape
// inheritance "is a" relation ship and
// mathematically, a square is a rectangle
class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}

    void setWidth(double width) {
        this->width = width;
        this->height = width;
    }

    void setHeight(double height) {
        this->width = height;
        this->height = height;
    }
};

// Function to print the area of a rectangle
void printArea(const Rectangle& rectangle) {
    std::cout << "Area: " << rectangle.area() << std::endl;
}

int main() {
    Rectangle rectangle(4.0, 6.0);
    printArea(rectangle);

    Square square(5.0);
    square.setWidth(10.0);
    printArea(square);

    return 0;
}

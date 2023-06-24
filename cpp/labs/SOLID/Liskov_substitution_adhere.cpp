#include <iostream>

// LSP: you should be able to use an object of a derived class wherever an object of its base class is expected,
// without causing any issues or unexpected behavior

// Base shape class
class Shape {
public:
    virtual double area() const = 0;
    // double area(){ return 0;};   // LSP is talking about inheritance with or without virtual
};

// Rectangle shape
class Rectangle : public Shape {
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

    double area() const override {
        return width * height;
    }
};

// Square shape
class Square : public Shape {
private:
    double side;

public:
    Square(double side) : side(side) {}

    void setSide(double side) {
        this->side = side;
    }

    double getSide() const {
        return side;
    }

    double area() const override {
        return side * side;
    }
};

// Function to print the area of a shape
void printArea(const Shape& shape) {
    std::cout << "Area: " << shape.area() << std::endl;
}

int main() {
    Rectangle rectangle(4.0, 6.0);
    printArea(rectangle);

    Square square(5.0);
    square.setSide(10);
    printArea(square);

    return 0;
}

#include <iostream>
#include <vector>
#include <memory>   // for unique ptr

// OCP: Software entities (classes, modules, functions, etc.) should be open for extension but closed for modification

// Base shape class --> this is called Interface\abstract class because it has a pure virtual function( = 0)
// Interface\abstract class means that you can;t creat a IShape class directly
class IShape {
public:
    virtual double area() const = 0;
    virtual std::string getShapeName() const = 0;
};

// Circle shape
class Circle : public IShape {
private:
    double m_radius;

public:
    Circle(double radius) : m_radius(radius) {}

    double area() const override {
        return (3.14159 * m_radius * m_radius);
    }

    std::string getShapeName() const override{
        return "Circle";
    }
};

// Triangle shape
class Triangle : public IShape {
private:
    double m_base;
    double m_height;

public:
    Triangle(double base, double height) : m_base(base), m_height(height) {}

    double area() const override {
        return (0.5 * m_base * m_height);
    }

    std::string getShapeName() const override{
        return "Triangle";
    }
};

class Square : public IShape {
private:
    double m_base;

public:
    Square(double base) : m_base(base) {}

    double area() const override {
        return (m_base * m_base);
    }

    std::string getShapeName() const override{
        return "Square";
    }
};

// Area calculator
class AreaCalculator {
    int myArea = 0;
public:
    // static double calculateArea(const std::unique_ptr<IShape> shape)  // error why? can you copy unique ptr?
    static double calculateArea(const std::unique_ptr<IShape>& shape)    // static function has no "this" pointer and no access to non static members
    {
        static int x = 0;
        return shape->area();
        x++;
    }

    void incrementArea()
    {
        myArea++;
    }
};


int main() {
    // Create a collection of shapes
    std::vector<std::unique_ptr<IShape>> shapes;
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Triangle>(4.0, 6.0));
    shapes.push_back(std::make_unique<Square>(4.0));

    AreaCalculator obj1;
    AreaCalculator obj2;
    obj1.calculateArea(shapes.at(0));

    obj1.incrementArea();
    // AreaCalculator::incrementArea(&obj2);

    // Calculate and display the total area
    for (auto& oneShape : shapes)
    {
        double area = AreaCalculator::calculateArea(oneShape);
        std::cout << "area of: " << oneShape->getShapeName() << " is: " << area << std::endl;
    }

    return 0;
}

/*
class Square : public IShape {
private:
    double m_base;

public:
    Square(double base) : m_base(base) {}

    double area() const override {
        return (m_base * m_base);
    }
};
*/

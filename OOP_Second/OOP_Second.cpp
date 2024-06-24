#include <iostream>
#include <memory>

class Figure {
protected:
    int sides;
    Figure(int sides) : sides(sides) {}
public:
    virtual ~Figure() = default;
    virtual void print_info() const = 0;
    int getSides() const {
        return sides;
    }
};

class Triangle : public Figure {
protected:
    double a, b, c;
    double A, B, C;
    Triangle(double a, double b, double c, double A, double B, double C) : Figure(3), a(a), b(b), c(c), A(A), B(B), C(C)
    {}

public:
    static std::unique_ptr<Triangle> create(double a, double b, double c, double A, double B, double C)
    {
        return std::unique_ptr<Triangle>(new Triangle(a, b, c, A, B, C));
    }

    void print_info() const override
    {
        std::cout << "Треугольник: a = " << a << ", b = " << b << ", c = " << c
            << "; A = " << A << ", B = " << B << ", C = " << C << std::endl;
    }
};

class RightTriangle : public Triangle
{
    RightTriangle(double a, double b, double c, double A, double B) : Triangle(a, b, c, A, B, 90) {}

public:
    static std::unique_ptr<RightTriangle> create(double a, double b, double c, double A, double B) {
        return std::unique_ptr<RightTriangle>(new RightTriangle(a, b, c, A, B));
    }
};

class IsoscelesTriangle : public Triangle
{
    IsoscelesTriangle(double a, double b, double A, double B) : Triangle(a, b, a, A, B, A) {}

public:
    static std::unique_ptr<IsoscelesTriangle> create(double a, double b, double A, double B)
    {
        return std::unique_ptr<IsoscelesTriangle>(new IsoscelesTriangle(a, b, A, B));
    }
};

class EquilateralTriangle : public Triangle
{
    EquilateralTriangle(double side) : Triangle(side, side, side, 60, 60, 60) {}

public:
    static std::unique_ptr<EquilateralTriangle> create(double side)
    {
        return std::unique_ptr<EquilateralTriangle>(new EquilateralTriangle(side));
    }
};

class Quadrilateral : public Figure
{
protected:
    double a, b, c, d;
    double A, B, C, D;
    Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D) : Figure(4), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

public:
    static std::unique_ptr<Quadrilateral> create(double a, double b, double c, double d, double A, double B, double C, double D)
    {
        return std::unique_ptr<Quadrilateral>(new Quadrilateral(a, b, c, d, A, B, C, D));
    }

    void print_info() const override
    {
        std::cout << "Четырёхугольник: a = " << a << ", b = " << b << ", c = " << c << ", d = " << d
            << "; A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << std::endl;
    }
};

class Rectangle : public Quadrilateral
{
    Rectangle(double a, double b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {}

public:
    static std::unique_ptr<Rectangle> create(double a, double b)
    {
        return std::unique_ptr<Rectangle>(new Rectangle(a, b));
    }
};

class Square : public Quadrilateral
{
    Square(double side) : Quadrilateral(side, side, side, side, 90, 90, 90, 90) {}

public:
    static std::unique_ptr<Square> create(double side)
    {
        return std::unique_ptr<Square>(new Square(side));
    }
};

class Parallelogram : public Quadrilateral
{
    Parallelogram(double a, double b, double A, double B) : Quadrilateral(a, b, a, b, A, B, A, B) {}

public:
    static std::unique_ptr<Parallelogram> create(double a, double b, double A, double B)
    {
        return std::unique_ptr<Parallelogram>(new Parallelogram(a, b, A, B));
    }
};

class Rhombus : public Quadrilateral
{
    Rhombus(double side, double A, double B) : Quadrilateral(side, side, side, side, A, B, A, B) {}

public:
    static std::unique_ptr<Rhombus> create(double side, double A, double B)
    {
        return std::unique_ptr<Rhombus>(new Rhombus(side, A, B));
    }
};

void print_info(const Figure* figure)
{
    figure->print_info();
}

int main()
{
    auto triangle = Triangle::create(3, 4, 5, 30, 60, 90);
    auto rightTriangle = RightTriangle::create(3, 4, 5, 30, 60);
    auto isoscelesTriangle = IsoscelesTriangle::create(5, 6, 50, 80);
    auto equilateralTriangle = EquilateralTriangle::create(6);

    auto quadrilateral = Quadrilateral::create(3, 4, 5, 6, 90, 85, 95, 90);
    auto rectangle = Rectangle::create(4, 6);
    auto square = Square::create(5);
    auto parallelogram = Parallelogram::create(4, 6, 60, 120);
    auto rhombus = Rhombus::create(5, 60, 120);

    std::cout << "Информация о фигурах:" << std::endl;
    print_info(triangle.get());
    print_info(rightTriangle.get());
    print_info(isoscelesTriangle.get());
    print_info(equilateralTriangle.get());
    print_info(quadrilateral.get());
    print_info(rectangle.get());
    print_info(square.get());
    print_info(parallelogram.get());
    print_info(rhombus.get());

    return 0;
}
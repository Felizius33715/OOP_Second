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
public:
    static std::unique_ptr<RightTriangle> create(double a, double b, double c, double A, double B) {
        return std::unique_ptr<RightTriangle>(new RightTriangle(a, b, c, A, B));
    }
};

class IsoscelesTriangle : public Triangle
{
public:
    static std::unique_ptr<IsoscelesTriangle> create(double a, double b, double A, double B)
    {
        return std::unique_ptr<IsoscelesTriangle>(new IsoscelesTriangle(a, b, A, B));
    }
};

class EquilateralTriangle : public Triangle
{
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
public:
    Parallelogram() {}
    Parallelogram(int a, int b, int A, int B)
    {
        name = "Parallelogram";
        this->a = a;
        this->b = b;
        this->A = A;
        this->B = B;
        c = a;
        d = b;
        C = A;
        D = B;
    }
};

class Square : public Quadrilateral
{
public:
    static std::unique_ptr<Square> create(double side)
    {
        return std::unique_ptr<Square>(new Square(side));
    }
};

class Parallelogram : public Quadrilateral
{
public:
    static std::unique_ptr<Parallelogram> create(double a, double b, double A, double B)
    {
        return std::unique_ptr<Parallelogram>(new Parallelogram(a, b, A, B));
    }
};

class Rhombus : public Quadrilateral
{
public:
    static std::unique_ptr<Rhombus> create(double side, double A, double B)
    {
        return std::unique_ptr<Rhombus>(new Rhombus(side, A, B));
    }
};

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

    triangle.print_info(&triangle);
    rightTriangle.print_info(&rightTriangle);
    isoscelesTriangle.print_info(&isoscelesTriangle);
    equilateralTriangle.print_info(&equilateralTriangle);
    quadrangle.print_info(&quadrangle);
    rectangle.print_info(&rectangle);
    square.print_info(&square);
    parallelogram.print_info(&parallelogram);
    rhombus.print_info(&rhombus);
    return 0;
}
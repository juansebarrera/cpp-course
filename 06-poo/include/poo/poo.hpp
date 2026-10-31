#pragma once

#include <memory>
#include <string>
#include <vector>

namespace poo {

class Shape {
public:
    virtual ~Shape() = default;

    virtual double area() const = 0;
    virtual std::string name() const = 0;
};

class Circle final : public Shape {
public:
    explicit Circle(double radius);

    double area() const override;
    std::string name() const override;

private:
    double radius_;
};

class Rectangle final : public Shape {
public:
    Rectangle(double width, double height);

    double area() const override;
    std::string name() const override;

private:
    double width_;
    double height_;
};

double total_area(const std::vector<std::unique_ptr<Shape>>& shapes);

}  // namespace poo

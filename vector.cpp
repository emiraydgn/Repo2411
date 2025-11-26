#include "point.hpp"


struct Vector : Planar {
    Point a;
    Point b;

    Vector(Point aa, Point bb) : a(aa), b(bb) {}

    int x() const override { return b.x() - a.x(); }
    int y() const override { return b.y() - a.y(); }
    int abs_sqr() const override { return x()*x() + y()*y(); }

    ~Vector() override = default;
};
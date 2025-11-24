#ifndef POINT_HPP
#define POINT_HPP
#include "planar.hpp"

struct Point : Planar {
    Point(int xx, int yy);

    int x() const override;
    int y() const override;
    int abs_sqr() const override;

private:
    int data[2];
};

#endif 
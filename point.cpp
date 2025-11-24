#include "point.hpp"

Point::Point(int xx, int yy) {
    data[0] = xx;
    data[1] = yy;
}

int Point::x() const {
    return data[0];
}

int Point::y() const {
    return data[1];
}

int Point::abs_sqr() const {
    return x() * x() + y() * y();
}
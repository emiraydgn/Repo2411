#include <stdexcept>
#include <iostream>
#include "funcs.hpp"
#include "point.hpp"

Planar* make(std::istream& is) {
    std::size_t id;
    if (!(is >> id)) {
        throw std::logic_error("bad input");
    }
    return make(id);
}

Planar* make(std::size_t id) {
    Planar* r = nullptr;
    switch (id) {
    case 0:
        r = new Point(0, 0);
        break;
    default:
        throw std::logic_error("bad id");
    }
    return r;
}

Planar* mostLeft(Planar** pls, std::size_t k) {
    if (k == 0) return nullptr;

    std::size_t best = 0;
    for (std::size_t i = 1; i < k; ++i) {
        if (pls[i]->x() < pls[best]->x()) {
            best = i;
        }
    }
    return pls[best];
}

void draw(Planar* p) {
    if (!p) return;

    std::cout << p->x() << ' '
              << p->y() << ' '
              << p->abs_sqr() << '\n';
}

void free_planars(Planar** pls, std::size_t k) {
    for (std::size_t i = 0; i < k; ++i)
        delete pls[i];
}
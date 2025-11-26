#include <iostream>
#include "funcs.hpp"

int main() {
    Planar* pls[10] = {};
    std::size_t k = 0;

    for (std::size_t i = 0; i < 10; ++i) {
        try {
            pls[k] = make(std::cin);
        } catch (...) {
            free_planars(pls, k);
            return 2;
        }
        ++k;
    }

    draw(mostLeft(pls, k));
    free_planars(pls, k);

    return 0;
}
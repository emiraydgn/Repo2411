#include <istream>
#include "vector.cpp"
#include <iostream>
#include "funcs.hpp"

Planar* make(std::istream& is)
{
    char cmd[2] = { };
    is >> cmd[0] >> cmd[1];

    int data[4] = { };

    if (cmd[0] == 'P' && cmd[1] == 'T') {
        if (is >> data[0] >> data[1]) {
            return new Point(data[0], data[1]);
        }
    }
    else if (cmd[0] == 'V' && cmd[1] == 'T') {
        if (is >> data[0] >> data[1] >> data[2] >> data[3]) {
            return new Vector(Point(data[0], data[1]), Point(data[2], data[3]));
        }
    }
    else {
        throw std::logic_error("bad cmd");
    }
}

int main() {
    size_t s = 0;
    size_t c = 2;

 Planar** pls = new Planar*[c];

 while(std::cin) {
    Planar* p = nullptr;

    try {
        p = make (std::cin);

        if (s == c) {
        Planar** eps = new Planar*[c * 2];

        for (size_t i = 0; i < s; ++i) {

        }
        delete[] pls;
        pls = eps;
        c *=2;
    
        }
        pls[s++] = p;

    }
    catch ( ... ) {

    }
 }

 Planar* mostleft(Planar** pls, size_t k) {
    if (!k) {
        return nullptr;
    }

    Planar* res = *pls;
    while (--k) {
        int next_x  = (++pls)->x();
        int curr_x  = res->x();
        if (next_x < curr_x) {
            res = *pls;
        }
    }
    return res;
}

Planar* ml = mostleft(pls, s);
if (!ml) {
    std::cout << "Not found\n";
    free_planars(pls, s);
    delete[] pls;
    return 0;
}

draw(ml);
std::cout << '\n';
free_planars(pls, s);
delete[] pls;
} 


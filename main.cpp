#include <iostream>
#include <stdexcept>
#include "point.hpp"

using namespace std;

Planar* make(istream& is)
{
    char kind;
    int xx, yy;

    if (!(is >> kind >> xx >> yy)) {
        throw runtime_error("bad input");
    }

    switch (kind) {
    case 'p':
    case 'P':
        return new Point(xx, yy);
    default:
        throw logic_error("bad id");
    }
}

Planar* mostLeft(Planar** pls, size_t k)
{
    if (k == 0) return nullptr;

    size_t best = 0;
    for (size_t i = 1; i < k; ++i) {
        if (pls[i]->x() < pls[best]->x()) {
            best = i;
        }
    }
    return pls[best];
}

void free_planars(Planar** pls, size_t k)
{
    for (size_t i = 0; i < k; ++i) {
        delete pls[i];
    }
}

void draw(Planar* p)
{
    if (!p) return;
    cout << p->x() << ' ' << p->y() << ' ' << p->abs_sqr() << '\n';
}

int main()
{
    Planar* pls[10] = {};
    size_t k = 0;

    for (size_t i = 0; i < 10; ++i) {
        try {
            pls[k] = make(cin);
        }
        catch (const bad_alloc&) {
            free_planars(pls, k);
            return 2;
        }
        catch (...) {
            free_planars(pls, k);
            return 1;
        }
        ++k;
    }

    draw(mostLeft(pls, k));
    free_planars(pls, k);
    return 0;
}
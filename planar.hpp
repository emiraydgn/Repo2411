#ifndef PLANAR_HPP
#define PLANAR_HPP
#include <cstddef>
#include <iosfwd>

struct Planar {
    virtual int x() const = 0;
    virtual int y() const = 0;
    virtual int abs_sqr() const = 0;
    virtual ~Planar() = default;
};

Planar* make(std::istream& is);
Planar* mostLeft(Planar** pls, std::size_t k);
void    draw(Planar* p);
void    free_planars(Planar** pls, std::size_t k);

#endif 
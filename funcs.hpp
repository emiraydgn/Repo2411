#ifndef FUNCS_HPP
#define FUNCS_HPP

#include <istream>
#include "planar.hpp"

Planar* make(std::istream& is);
Planar* make(std::size_t id);
Planar* mostLeft(Planar** pls, std::size_t k);
void draw(Planar* p);
void free_planars(Planar** pls, std::size_t k);

#endif
#include <iostream>

struct Planar {
     virtual int x() const = 0;
     virtual int y() const = 0;
     virtual int abs_sqr() const = 0;
     virtual ~Planar() = default;
};

Planar* make(std::istream& is);
Planar* mostLeft(Planar** pls, size_t k);

int main(){
    Planar* pts[10] = {};
     size_t k = 0;
     pts[k++] = make(std::cin);
}
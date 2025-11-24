#include <iostream>

struct Planar {
    virtual int x() const = 0;
    virtual int y() const = 0;
    virtual int abs_sqr() const = 0;
    virtual ~Planar() = default;
};

struct Point : Planar {
virtual int x() const;
virtual int y() const;
virtual int abs_sqr() const;

Point(int xx, int yy);
virtual ~Point() = default;

private: 
   int data[2];
};

Planar* make(std::istream& is);
Planar* mostLeft(Planar** pls, size_t k);
Planar* make(size_t pl);
void draw(Planar* p);
void free_planars(Planar** pls, size_t k);

int main() {
    Planar* pls[10] = {};
    size_t k = 0;

    for (size_t i = 0; i < 10; ++i) {
        try {
          
            pls[k] = make(std::cin);
        }
        catch (...) {
            free_planars(pls, k);
            return 2;
        }
        ++k;
    }

    draw(mostLeft(pls, k));
    free_planars(pls, k);
}


Planar* make(size_t pl) {
    switch (pl) {
    default:
        throw std::logic_error("bad id");
    }
    return nullptr;   
}


void free_planars(Planar** pls, size_t k) {
    for (size_t i = 0; i < k; ++i) {
        delete pls[i];
    }
}

void draw(Planar* p) {
    std::cout << p->x() << " "
              << p->y() << " "
              << p->abs_sqr() << "\n";
}

Point::Point(int xx, int yy)
: Planar() {
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
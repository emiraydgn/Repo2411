#include <istream>
#include "vector.cpp"

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
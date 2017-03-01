#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "Point.h"

struct Circle
{
    Point center;
    double radius;

    void read();
    void print();

    bool contains(const Point&);
};

#endif // CIRCLE_H_INCLUDED

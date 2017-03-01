#include <iostream>
#include "Point.h"
#include <cmath>

void Point::print()
{
    std::cout<<"("<<x<<","<<y<<")\n";
}

void Point::read()
{
    std::cout<<"x: ";
    std::cin>>x;
    std::cout<<"y: ";
    std::cin>>y;
}

double Point::distance(const Point &p) const
{
    return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
}

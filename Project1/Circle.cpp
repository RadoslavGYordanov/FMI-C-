#include "Circle.h"
#include<iostream>

void Circle::read()
{
    std::cout<<"r: ";
    std::cin>>radius;

    std::cout<<"Center: \n";
    center.read();
}

void Circle::print()
{
    std::cout<<"r= "<<radius<<"\n";
    center.print();
}

bool Circle::contains(const Point &p)
{
    return p.distance(center)<=radius;
}

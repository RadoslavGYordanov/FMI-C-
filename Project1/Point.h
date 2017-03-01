#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

struct Point
{
    double x;
    double y;

    void read();
    void print();

    double distance(const Point &) const;
};


#endif // POINT_H_INCLUDED


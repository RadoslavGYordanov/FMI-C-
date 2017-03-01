#include <iostream>
#include "Point.h"
#include "Circle.h"

int main()
{
    //Point p;
    //p.read();
    //p.print();

    //Circle p;
    //p.read();
    //std::cout<<"\n";
    //p.print();

    int count;
    std::cout<<"Count: ";
    std::cin>>count;

    Point *points=new(std::nothrow) Point[count];
    if(points==NULL)
    {
        std::cout<<"Cannot allocate memory!\n";
        return 1;
    }

    for(int i=0;i<count;i++)
    {
        std::cout<<"Point["<<i<<"]: \n";
        points[i].read();
    }

    double maxDistance=0;
    Point *start=NULL,*end=NULL;
    for(int i=0;i<count-1;i++)
    {
        for(int j=i+1;j<count;j++)
        {
            double currentDistance=points[i].distance(points[j]);
            if(maxDistance<currentDistance)
            {
                maxDistance=currentDistance;
                start=points+i; //&points[i]
                end=points+j;   //&points[j]
            }
        }
    }

    std::cout<<"Max Distance: "<<maxDistance<<"\n";
    if(start && end)
    {
        start->print();
        end->print();
    }

    delete[] points;

    return 0;
}

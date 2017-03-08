#include <iostream>
#include "date.h"

int main()
{
    //Use this when you want an array, but don't have a default constructor
    /*Date* arr[5]={NULL};
    for(int i=0;i<5;i++)
    {
        int d,m,y;
        std::cin>>d>>m>>y;

        arr[i]=new Date(d,m,y);
        arr[i]->print();
    }

    for(int i=0;i<5;i++)
    {
        delete arr[i];
    }
    */

    Date* arr=new Date[3];
    delete[] arr;


    /*
    Date d;
    d.print();

    Date d1(34,3,2017);
    d1.print();
    */
    return 0;
}

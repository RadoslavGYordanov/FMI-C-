#include <iostream>
#include "set.h"


int main()
{
    Set test;
    //test.Remove(5);
    int count=test.GetCount();
    std::cout<<"\ncount: "<<count;
    int* ptr=test.GetSet();
    std::cout<<"\n";
    for(int i=0;i<test.GetCount();i++)
        std::cout<<ptr[i]<<" ";

    return 0;
}

#include <iostream>
#include "../vector.h"


int main()
{
    vector a,b,c;
    std::cout<<"Vector a\n";
    a.set(5);
    std::cout<<"Vector b\n";
    b.set(4);
    a.print();
    std::cout<<std::endl;
    b.print();
    std::cout<<std::endl;
    a+=b;
    a.print();
    std::cout<<std::endl;
    b.print();
    std::cout<<std::endl;

    std::cout<<"Vector c\n";
    c=a+b;
    std::cout<<std::endl;
    c.print();

    return 0;
}

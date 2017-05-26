#include <iostream>
#include "device.h"

using namespace std;

int main()
{
    ElectricDevice test("clock", 50);
    test.print();
    ElectricDevice test1("alarm",100);
    test1.print();

    if(test1==test)
        std::cout<<"\ntest1==test2";
    else
        std::cout<<"\ntest1!=test2";

    test1=test;
    test1.print();

    if(test1==test)
        std::cout<<"\ntest1==test2";
    else
        std::cout<<"\ntest1!=test2";

    return 0;
}

#include"Electric.h"
#include <iostream>

int main()
{
    Electric aircon("Air con",1100,true);
    Electric aircon1("Air con",1100,true);
    Electric aircon2("Air con",1100,true);
    Electric aircon3("Air con",1100,true);
    Electric aircon4("Air con",1100,true);
    Electric aircon5("Air con",1100,true);
    Electric aircon6("Air con",1100,true);


    //aircon.turnOn();
    aircon.print();

    std::cout<<"Appliances on: "<<Electric::getObjectCount()<<"\n";

    aircon.turnOff();
    aircon.print();

    return 0;
}

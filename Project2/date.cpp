#include "date.h"
#include <iostream>
#include<iomanip>

Date::Date() : day(1),month(1),year(1900) //(Initializing list) This is executed before entering the constructor's body.
{
    /*If we have ^ we don't need this.
    this->day=1;
    this->month=1;
    this->year=1900;
    */
}

Date::Date(int d, int m,int y) : day(1),month(1),year(1900) //(Initializing list) This is executed before entering the constructor's body.
{
    if(isValid(d,m,y))
    {
        this->day=d;
        this->month=m;
        this->year=y;
    }
    /*If we have ^ we don't need this.
    else
    {
        this->day=1;
        this->month=1;
        this->year=1900;
    }
    */
}

Date::~Date()
{
    std::cout<<"~Date: ";
    this->print();
}

bool Date::isValid(int d, int m, int y)
{
    if(y<=0) return false;
    if(m<=0 || m>12) return false;
    //leap year
    int maxDays;
    switch(m)
    {
        case 2:maxDays=28;break;
        case 4:
        case 6:
        case 9:
        case 11:maxDays=30;break;
        default:maxDays=31;
    }

    return (d>=0 && d<=maxDays);
}

void Date::print() const
{
    std::cout<<std::setw(2)<<std::setfill('0')<<getDay()<<'.'<<std::setw(2)<<std::setfill('0')<<getMonth()<<'.'<<std::setw(4)<<getYear()<<'\n';
}

void Date::setDay(int newDay)
{
    if(isValid(newDay,this->month,this->year))
        this->day=newDay;
}
void Date::setMonth(int newMonth)
{
    if(isValid(this->day,newMonth,this->year))
        this->month=newMonth;
}
void Date::setYear(int newYear)
{
    if(isValid(this->day,this->month,newYear))
        this->year=newYear;
}



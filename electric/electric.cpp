#include "electric.h"
#include<iostream>
#include<cstring>

const double Electric::VOLTAGE = 220;
const double Electric::MAX_AMPER = 16;

const double Electric::MAX_LOAD=Electric::VOLTAGE * Electric::MAX_AMPER;

int Electric::countObjects = 0;
double Electric::currentLoad= 0;

void Electric::setCategory(const char* category)
{
    if(!category)
    {
        delete[] (this->category);
        (this->category)=NULL;
        return;
    }

    size_t lenght = strlen(category)+1;
    char* buffer=new char[lenght];
    strcpy(buffer,category);

    delete[] this->category;
    this->category=buffer;
}

void Electric::setPower(double power)
{
    if(power<0)
        throw "Negative power!";

    this->power = power;
}

void Electric::turnOn()
{
    if(this->isOn()) return;

    if(this->power + Electric::getCurrentLoad() < Electric::getMaxLoad())
    {
        Electric::currentLoad+=this->power;
        this->state=true;

        ++(Electric::countObjects);
    }
    else
    {
        std::cout<<"The system will be overloaded!";
    }
}

void Electric::turnOff()
{
    if(this->isOn())
    {
        Electric::currentLoad -= (this->power);
        this->state=false;

        --(Electric::countObjects);
    }
}

void Electric::print() const
{
    std::cout<<"Category: "<<this->getCategory()<<"\n";
    std::cout<<"Power: "<<this->getPower()<<"\n";
    std::cout<<"State: "<<std::boolalpha<<this->isOn()<<"\n";

    std::cout<<"Current Load: "<<Electric::getCurrentLoad()<<"\n";
}

Electric::Electric(const char* category, double power, bool state) : category(NULL),state(false)
{
    this->setPower(power);
    this->setCategory(category);
    if(state)
        this->turnOn();
}

Electric::Electric(const Electric& other) : category(NULL), state(false)
{
    this->setPower(other.power);
    this->setCategory(other.category);
    if(other.isOn())
        this->turnOn();
}

Electric& Electric::operator=(const Electric& other)
{
    if(this!=&other)
    {
        this->setPower(other.power);
        this->setCategory(other.category);

        if(other.isOn())
            this->turnOn();
        else
            this->turnOff();
    }

    return *this;
}

Electric::~Electric()
{
    delete[] this->category;
    this->turnOff();
}




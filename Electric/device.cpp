#include "device.h"
#include<iostream>
#include<cstring>


ElectricDevice::ElectricDevice()
{
}

ElectricDevice::ElectricDevice(const char * buffer,int power)
{
    this->type=new char[strlen(buffer)+1];
    std::strcpy(this->type, buffer);
    this->power=power;
}

ElectricDevice::~ElectricDevice()
{
    delete[] this->type;
}

ElectricDevice::ElectricDevice(const ElectricDevice &obj)
{
    this->type=new char[strlen(obj.type)+1];
    std::strcpy(this->type,obj.type);
    this->power=obj.power;
}

ElectricDevice& ElectricDevice::operator=(const ElectricDevice& obj)
{
    if(this!=&obj)
    {
        delete[] this->type;
        this->type=new char[strlen(obj.type)+1];
        std::strcpy(this->type,obj.type);
        this->power=obj.power;
    }

    return *this;
}

bool ElectricDevice::operator==(const ElectricDevice obj) const
{
    if(!strcmp(this->type,obj.type) && this->power==obj.power)
        return true;
    else
        return false;
}

void ElectricDevice::print()
{
    std::cout<<"\nType: "<<this->type;
    std::cout<<"\nPower: "<<this->power;
}



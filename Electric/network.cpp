#include "network.h"
#include<iostream>

ElectricNet::ElectricNet(int power)
{
    this->max_power=power;
}

ElectricNet::~ElectricNet()
{
    delete[] this->current_devices;
}

ElectricNet& ElectricNet::operator+=(const ElectricDevice& obj)
{
    if(this->current_power+obj.getPower() > this->max_power)
    {
        std::cout<<"\nExceeding maximum power!";
    }
    else
    {
        ElectricDevice* temp=new ElectricDevice[this->count_devices+1];
        for(int i=0;i<this->count_devices;i++)
        {
            temp[i]=current_devices[i];
        }
        temp[count_devices+1]=obj;
        delete[] this->current_devices;

        this->current_devices=temp;
        this->count_devices++;
        this->current_power+=obj.getPower();
    }

    return *this;
}

ElectricNet& ElectricNet::operator-=(const ElectricDevice& obj)
{
    for(int i=0;i<this->count_devices;i++)
    {
        if(this->current_devices[i]==obj)
        {

            ElectricDevice* temp=new ElectricDevice[this->count_devices-1];
            for(int i=0,j=0;i<this->count_devices-1;i++,j++)
            {
                if(this->current_devices[i]==obj)
                    j++;
                temp[i]=current_devices[j];
            }
            delete[] this->current_devices;

            this->current_devices=temp;
            this->count_devices--;
            this->current_power-=obj.getPower();

        }
    }
    return *this;
}

bool ElectricNet::operator!()
{
    if(this->count_devices>0)
        return true;
    else
        return false;
}

ElectricNet& ElectricNet::operator++()
{
    this->max_power=this->max_power+this->max_power;

    return *this;
}

ElectricNet& ElectricNet::operator--()
{
    if(this->max_power/2<this->current_power)
        std::cout<<"Exceeding maximum power!";
    else
    {
        this->max_power=this->max_power/2;

    }

    return *this;
}





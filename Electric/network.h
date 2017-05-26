#ifndef NETWORK_H_INCLUDED
#define NETWORK_H_INCLUDED

#include "device.h"

class ElectricNet
{
    int max_power;
    int current_power=0;
    ElectricDevice* current_devices;
    int count_devices=0;
public:
    ElectricNet(int);
    ~ElectricNet();

    //ElectricNet& operator=(const ElectricNet& obj);
    ElectricNet& operator+=(const ElectricDevice& obj);
    const ElectricNet operator+(ElectricDevice obj);
    ElectricNet& operator-=(const ElectricDevice& obj);
    const ElectricNet operator-(ElectricDevice obj);

    ElectricDevice& operator[](char* type);

    bool operator!();
    ElectricNet& operator++();
    ElectricNet& operator--();


};

#endif // NETWORK_H_INCLUDED

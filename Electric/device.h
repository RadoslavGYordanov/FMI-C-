#ifndef DEVICE_H_INCLUDED
#define DEVICE_H_INCLUDED

class ElectricDevice
{
    char* type;
    int power;
public:
    ElectricDevice();
    ElectricDevice(const char *,int);
    ~ElectricDevice();
    ElectricDevice(const ElectricDevice &obj);
    ElectricDevice& operator=(const ElectricDevice& rhs);
    bool operator==(const ElectricDevice obj) const;

    void print();

    int getPower() const
    {
        return this->power;
    }

};

#endif // DEVICE_H_INCLUDED

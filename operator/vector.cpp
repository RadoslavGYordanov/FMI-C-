#include <iostream>
#include "vector.h"

void vector::set(int count)
{
    this->nums=new(std::nothrow) double[count];

    delete[] nums;

    std::cout<<"Input vector: ";
    for(int i=0;i<count;i++)
        std::cin>>nums[i];
    (this->count)=count;
}

void vector::print()
{
    for(int i=0;i<(this->count);i++)
    {
        std::cout<<nums[i];
        if(i!=(count-1))
            std::cout<<',';
    }

}

double vector::operator[](int index) const
{
    return this->nums[index];
}

int vector::getCount() const
{
    return this->count;
}


vector& vector::operator+=(const vector &rhs)
{
    for(int i=0;i<this->count;i++)
    {
        this->nums[i]+=rhs[i];
    }

    return *this;
}

const vector vector::operator+(const vector &other) const
{
    vector result = *this;
    result += other;
    return result;
}

vector& vector::operator=(const vector &rhs)
{
    int newCount=rhs.getCount();
    double *var=new(std::nothrow) double[newCount];
    for(int i=0;i<newCount;i++)
    {
        var[i]=rhs[i];
    }

    this->nums=var;
    this->count=newCount;

    return *this;

}

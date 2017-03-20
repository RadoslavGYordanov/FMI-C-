#include "set.h"
#include<iostream>

bool isIn(int num);
void CopySet(int *old,int *curr,int count);


Set::Set()
{
    int var;
    int realCount;
    std::cout<<"Input how many numbers: ";
    std::cin>>this->count;
    realCount=this->count;

    set=new(std::nothrow) int[count];
    if(set==NULL)
    {
        std::cout<<"Couldn't allocate memory";
        return;
    }
    std::cout<<"\nEnter numbers: ";
    for(int i=0;i<count;i++)
    {
        int j=0;
        std::cin>>var;
        if(!isIn(var))
            this->set[j++]=var;
        else
        {
            realCount--;
        }
    }
    int *ptr=new(std::nothrow) int[realCount];
    if(ptr==NULL)
    {
        std::cout<<"Couldn't allocate memory\n";
        return;
    }
    CopySet(this->set,ptr,realCount);
    this->count=realCount;
    delete[] this->set;
    set=ptr;
}

Set::~Set()
{
    delete[] set;
}

int Set::GetCount() const
{
    return this->count;
}

int* Set::GetSet() const
{
    return this->set;
}


void Set::CopySet(int *old,int *curr,int count)
{
    for(int i=0;i<count;i++)
    {
        curr[i]=old[i];
    }
}

bool Set::isIn(int num)
{
    for(int i=0;i<this->count;i++)
    {
        if(num==this->set[i])
        {
            return 1;
        }
    }
    return 0;
}

void Set::Add(int num)
{
    if(!isIn(num))
    {
        int *ptr=new(std::nothrow) int[(this->count)+1];
        if(ptr==NULL)
        {
            std::cout<<"Couldn't allocate memory\n";
            return;
        }
        CopySet(this->set,ptr,this->count);
        ptr[(this->count)]=num;
        (this->count)++;
        delete[] this->set;
        set=ptr;
    }
}

void Set::Remove(int num)
{
   if(isIn(num))
   {
       std::cout<<"\ntest";
       int *ptr=new(std::nothrow) int[(this->count)-1];
       if(ptr==NULL)
       {
           std::cout<<"Couldn't allocate memory\n";
           return;
       }
       for(int i=0;i<(this->count)-1;i++)
       {
           int j=0;
           if(this->set[i]==num)
                j++;
            ptr[i]=this->set[j++];
       }
        (this->count)--;
        delete[] this->set;
        set=ptr;
   }
}




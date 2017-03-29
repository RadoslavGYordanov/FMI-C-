#ifndef ELECTRIC_H_INCLUDED
#define ELECTRIC_H_INCLUDED

class Electric
{
    static const double VOLTAGE;
    static const double MAX_AMPER;
    static const double MAX_LOAD;

    static int countObjects;
    static double currentLoad;

    char* category;
    double power;
    bool state;

public:
    Electric(const char*,double,bool);
    ~Electric();
    Electric(const Electric&);
    Electric& operator=(const Electric&);

    const char* getCategory() const{return (this->category)?(this->category):"";}
    double getPower() const{return this->power;}
    bool isOn() const{return this->state;}

    static double getVoltage(){return Electric::VOLTAGE;}
    static double getMaxAmper(){return Electric::MAX_AMPER;}
    static double getMaxLoad(){return Electric::MAX_LOAD;}

    static int getObjectCount(){return Electric::countObjects;}
    static double getCurrentLoad(){return Electric::currentLoad;}

    void setCategory(const char*);
    void setPower(double);

    void turnOn();
    void turnOff();

    void print() const;

};

#endif // ELECTRIC_H_INCLUDED

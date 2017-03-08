#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

class Date
{
public:
    Date();
    Date(int d,int m,int y);
    ~Date();

    void print() const;

    int getDay() const{return this->day;}
    int getMonth() const{return this->month;}
    int getYear() const{return this->year;}

    void setDay(int);
    void setMonth(int);
    void setYear(int);

    //FOR HOMEWORK:
    //getWeekday
    //

private:
    int day;
    int month;
    int year;

    bool isValid(int d,int m,int y);
};
#endif // DATE_H_INCLUDED

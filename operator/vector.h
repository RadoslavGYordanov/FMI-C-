#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

class vector
{
    double *nums;
    int count;
public:
    ~vector(){delete[] nums;}

    int getCount() const;
    vector(){nums=NULL; count=0;};
    void set(int count);
    void print();

    double operator[](int index) const;
    vector& operator+=(const vector &rhs);
    const vector operator+(const vector &other) const;
    vector& operator=(const vector &rhs);

};

#endif // VECTOR_H_INCLUDED

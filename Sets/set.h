#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED

class Set
{
    int count;
    int *set;

    void CopySet(int *old,int *curr,int count);
    bool isIn(int num);
public:
    Set();
    ~Set();
    int GetCount() const;
    int* GetSet() const;

    void Add(int);
    void Remove(int);
};

#endif // SET_H_INCLUDED

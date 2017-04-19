#include <iostream>
#include <fstream>
#include <math.h>

struct Point
{
    double x;
    double y;
};

const Point center={0,0};

double distance(const Point& first, const Point& second)
{
    return sqrt((first.x-second.x)*(first.x-second.x) + (first.y-second.y)*(first.y-second.y));
}

bool read(Point& point,std::ifstream& file)
{
    if(!file)
        return false;


    file.get();//removes (
    if(file)
    {
        double x,y;
        file >> x;

        file.get();
        if(file)
        {
            file>>y;
        }
        if(file)
        {
            file.get();//removes )
            if(file)
            {
                point.x=x;
                point.y=y;
            }
            file.ignore();// removes newline
        }
    }
    return file.good();
}

bool print(const Point& point,std::ostream& out)
{
    out<<'('<<point.x<<','<<point.y<<')'<<std::endl;

    return out.good();
}

bool storeInBinary(const Point& point,std::ofstream& out)
{
    out.write((const char*)&point,sizeof(Point));

    return out.good();
}

bool loadFromBinary(Point& point,std::fstream& file)
{
    file.read((char*)&point,sizeof(Point));

    return file && (file.gcount() == sizeof(Point));
}

int findMaxPoint(std::fstream& input)
{
    if(!input)
    {
        return -1;
    }

    int index=0;

    double maxDist=0;
    double currentDist;
    int maxIndex=0;

    Point point;

    while(loadFromBinary(point,input))
    {
        currentDist=distance(point, center);
        if(currentDist>maxDist)
        {
            maxDist=currentDist;
            maxIndex=index;
        }
        index++;
    }

    input.clear();
    return maxIndex;
}

int main()
{
    std::fstream inputBinary("Points.bin",std::ios::in|std::ios::out|std::ios::binary);
    if(!inputBinary)
    {
        std::cout<<"Points.bin can't be opened!"<<std::endl;
        return 1;
    }

    //std::cout<<findMaxPoint(inputBinary)<<std::endl;

    int index=findMaxPoint(inputBinary);

    inputBinary.seekp(index*sizeof(Point),std::ios::beg);
    std::cout<<inputBinary.tellp()<<std::endl;
    if(!inputBinary)
    {
        std::cout<<"error1\n";
    }
    //inputBinary.clear();
    inputBinary.write((const char*)&center,sizeof(Point));
    if(!inputBinary)
    {
        std::cout<<"error2\n";
    }

    inputBinary.clear();
    inputBinary.seekg(0,std::ios::beg);

    Point point;
    while(loadFromBinary(point,inputBinary))
    {
        print(point,std::cout);
    }

    inputBinary.close();


    /*
    std::ifstream textFile("Points.txt");
    if(!textFile)
    {
        std::cout<<"Points.txt can't be opened!"<<std::endl;
        return 1;
    }

    std::ofstream binaryFile("Points.bin",std::ios::binary);
    if(!binaryFile)
    {
        std::cout<<"Points.bin can't be opened!"<<std::endl;
        return 1;
    }

    Point point;
    while(read(point,textFile))
    {
        print(point,std::cout);
        storeInBinary(point,binaryFile);
    }

    textFile.close();
    binaryFile.close();
    */
    return 0;
}


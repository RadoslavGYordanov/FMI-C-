#include <iostream>
#include <fstream>

void printInFile(std::ostream& output,int min,int max,int sum,int count,int row)
{
    if(!output) return;

    if(count)
    {

        output<<"Row "<<row<<"\nAverage: "<<(double)sum/count<<"\nMin: "<<min<<"\nMax: "<<max<<std::endl<<std::endl;
    }
    else
    {
        output<<"Row "<<row<<"\nNo data"<<std::endl<<std::endl;
    }
}

int main(int argc,char* argv[])
{
    if(argc<2)
    {
        std::cout<< "Please enter the filename...";
        return 1;
    }

    std::ofstream output(argv[2],std::ios::out);
    std::ifstream file(argv[1],std::ios::in);
    if(!file)
    {
        std::cout<<argv[1]<<" cannot be opened!"<<std::endl;
        return 1;
    }

    int max,min,sum=0,count=0,row=1;
    int number;

    do
    {
        file>>number;

        if(file)
        {
            if(!count)
            {
                min=max=number;
            }
            else
            {
                min=(min>number)?number:min;
                max=(max<number)?number:max;
            }

            sum+=number;
            count++;
        }
        else if(file.bad())
        {
            std::cout<<"Bad state of the input stream..."<<std::endl;
        }
        else if(!file.eof())
        {
            std::cout<<"Fail state..."<<std::endl;

            file.clear();
            file.ignore();
        }
        else
        {
            std::cout<<"EOF reached!"<<std::endl;
        }


        if(file.peek()=='\n'|| file.eof())
        {
            if(count)
            {
                std::cout<<"Average: "<<(double)sum/count<<"\nMin: "<<min<<"\nMax: "<<max<<std::endl;
            }
            else
            {
                std::cout<<"\nNo data"<<std::endl;
            }

            if(!output)
            {
                std::cout<<argv[2]<<" cannot be opened!"<<std::endl;
                printInFile(std::cout,min,max,sum,count,row);
            }
            else
            {
                printInFile(output,min,max,sum,count,row);
            }

            min=max=sum=count=0;
            row++;
        }

    }while(file);



    file.clear();
    file.close();



    /*
    if(count)
    {
        output<<"Average: "<<(double)sum/count<<"\nMin: "<<min<<"\nMax: "<<max<<std::endl;
    }
    else
    {
        output<<"\nNo data"<<std::endl;
    }
    */

    output.clear();
    output.close();

    return 0;
}

#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    fstream file;
    file.open("number.docx", ios::out);
    for(int i=0;i<100;i++)
    {
        file<<i+1<<" "<<rand()%100000<<endl;
    }
    return 0;
}
#include <iostream>
#include "CopyConstruct.hpp"

using namespace std;

Clock::Clock(int NewH, int NewM, int NewS)
{
    this->Hour = NewH;
    this->Minute = NewM;
    this->Second = NewS;
}

Clock::Clock(Clock &c)
{
    this->Hour = c.Hour;
    this->Minute = c.Minute;
    this->Second = c.Second;
}

void Clock::SetTime(int NewH, int NewM, int NewS)
{
    // �Ӳ���thisָ�붼��һ����
    this->Hour = NewH;
    this->Minute = NewM;
    this->Second = NewS;
}

void Clock::ShowTime()
{
    cout << this->Hour << endl;
    cout << this->Minute << endl;
    cout << this->Second << endl;
}

//��������
Clock::~Clock()
{

}

int main(int argc,int argv[])
{
    Clock c(0,0,0);
    c.SetTime(10,20,30);
    c.ShowTime();
    
}
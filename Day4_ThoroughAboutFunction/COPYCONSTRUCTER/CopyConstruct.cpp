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
    // 加不加this指针都是一样的
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

//析构函数
Clock::~Clock()
{

}

int main(int argc,int argv[])
{
    Clock c(0,0,0);
    c.SetTime(10,20,30);
    c.ShowTime();
    
}
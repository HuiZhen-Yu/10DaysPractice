#include <iostream>

using namespace std;

/* 设计一个计数器counter，用类成员重载自增运算符实现计数器的自增，用友元重载实现计数器的自减 */

class Counter
{
private:
    int n;

public:
    Counter(int i = 0) : n(i){};
    Counter operator++();
    Counter operator++(int);
    friend Counter operator--(Counter &c);
    friend Counter operator--(Counter &c, int);
    void display();
};

Counter Counter::operator++()
{
    ++n;
    return *this;
}

Counter Counter::operator++(int)
{
    n++;
    return *this;
}

Counter operator--(Counter &c)
{
    c.n--;
    return c;
}

Counter operator--(Counter &c, int)
{
    c.n--;
    return c;
}

void Counter::display()
{
    cout << "Counter number = " << n << endl;
}

/* 设计一个time类，能够实现秒钟的自增与自减 */
class Time
{
private:
    int hh = 0, mm = 0, ss = 0;

public:
    Time(int a = 0, int b = 0, int c = 0)
        : hh(a), mm(b), ss(c)
    {
        if (hh >= 24 || mm >= 60 || ss >= 60)
        {
            cout << "请输入正确的时间初始值!" << endl;
        }
    }
    Time operator++();
    friend Time operator--(Time &);
    void display();
};

Time Time::operator++()
{
    ++ss;
    if (ss >= 60)
    {
        ss = 0, ++mm;
        if (mm >= 60)
        {
            mm = 0, ++hh;
            if (hh >= 24)
                hh = 0;
        }
    }
    return *this;
}

Time operator--(Time &t)
{
    --t.ss;
    if (t.ss < 0)
    {
        t.ss = 59, t.mm--;
        if (t.mm < 0)
        {
            t.mm = 59, t.hh--;
            if (t.hh < 0)
            {
                t.hh = 23;
            }
        }
    }
    return t;
}

void Time::display()
{
    cout << hh << ":" << mm << ":" << ss << endl;
}

int main(int argc, char **argv)
{
    Counter a;
    ++a;
    a.display();
    a++;
    a.display();
    --a;
    a.display();
    a--;
    a.display();

    Time t1(23,59,59);
    t1.display();
    ++t1;/* 隐式调用 */
    t1.display();
    t1.operator++(); /* 显式调用 */
    t1.display();
    Time t2(0,0,0);
    t2.display();
    --t2;
    t2.display();

    system("pause");
    return 0;
}
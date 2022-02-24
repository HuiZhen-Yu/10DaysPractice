#include <iostream>

using namespace std;

class Time
{
private:
    int hh, mm, ss;

public:
    Time(int h, int m, int s)
        : hh(h), mm(m), ss(s)
    {
    }
    void operator()(int a, int b, int c)
    {
        hh = a;
        mm = b;
        ss = c;
    }
    void operator++();
    /*     {
            ss < 59 ? ss++ : ss = 0, mm < 59 ? mm++ : mm = 0, hh < 23 ? hh++ : hh = 0;
        } */
    void ShowTime()
    {
        cout << hh << ":" << mm << ":" << ss << endl;
    }
};

void Time::operator++()
{

    ss < 59 ? ss++ : ss = 0, mm < 59 ? mm++ : mm = 0, hh < 23 ? hh++ : hh = 0;
}

int main(int argc, char *argv[])
{
    Time t(12, 13, 14);
    t.ShowTime();
    t(22, 59, 59);
    t.ShowTime();
    ++t;
    t.ShowTime();
    system("pause");
    return 0;
}
#include <iostream>
using namespace std;

class Time
{
private:
    int hh, mm, ss;

public:
    Time(int h = 0, int m = 0, int s = 0)
        : hh(h), mm(m), ss(s)
    {
    }
    void operator()(int a, int b, int c)
    {
        hh = a;
        mm = b;
        ss = c;
    }
    void ShowTime()
    {
        cout << hh << ":" << mm << ":" << ss << endl;
    }
};
int main(int argc, char *argv[])
{

    Time t1(12, 13, 14);
    t1.ShowTime();

    t1.operator()(23, 24, 25);
    t1.ShowTime();

    t1(10, 10, 10);
    t1.ShowTime();
    system("pause");
    return 0;
}
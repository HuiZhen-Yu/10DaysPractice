#include <iostream>

using namespace std;

void display(const double &r);

class A
{
public:
    A(int i, int j)
    {
        x = i;
        y = j;
    }

private:
    int x, y;
};

int main(int argc, char **argv)
{
    double d(9.5);
    display(d);
    A const a(3, 4); // a是常对象不能被更新
    system("pause");
    return 0;
}

// 常引用做形参，再函数中不能更新r所引用的对象。
void display(const double &r)
{
    cout << r << endl;
}
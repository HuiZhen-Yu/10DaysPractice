#include <iostream>

using namespace std;

class A
{
private:
    int x;

public:
    A(int i = 0)
    {
        x = i;
        cout << "A------" << x << endl;
    }
};

class B
{
private:
    int y;

public:
    B(int i)
    {
        y = i;
        cout << "B-------" << y << endl;
    }
};

class C
{
private:
    int z;

public:
    C() = default;
    C(int i)
    {
        z = i;
        cout << "C------" << z << endl;
    }
    int getc()
    {
        return z;
    }
};

class D : public B
{
public:
    C c1, c2;
    A *a1 = new A(10);
    A a0, a4;
    D() : a4(4), c1(1), B(1)
    {
        cout << "D------5" << endl;
    }
};

int main()
{
    D d;
    cout << "d.c2.z = " << d.c2.getc() << endl;
    system("pause");
    return 0;
}
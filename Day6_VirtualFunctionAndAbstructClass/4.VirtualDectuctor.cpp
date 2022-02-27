#include <iostream>
using namespace std;
class A
{
public:
    virtual ~A() { cout << "call A::~A();" << endl; }
};

class B : public A
{
    char *buf;

public:
    B(int i) { buf = new char[i]; }
    ~B()
    {
        delete[] buf;
        cout << "cal; B::~()" << endl;
    }
};

int main()
{
    int i = 0;
    cin >> i;
    if (i)
    {
        A *a = new B(10);
        delete a;
    }
    system("pause");
    return 0;
}

#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "Constructing A" << endl; }
    ~A() { cout << "Destructing A" << endl; }
};

class B : public A
{
public:
    ~B() { cout << "Destructing B" << endl; }
};

int main(int argc, char *argv[])
{
    B b;
    system("pause");
    return 0;
}
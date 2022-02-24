#include <iostream>
using namespace std;

class A
{
public:
/*     void vf()
    {
        cout << "I come from class A" << endl;
    } */
    
    A()
    {
        cout << "I come from class A" << endl;
    }
};

class B : public A
{
};
class c : public A
{
};
class D : public B, public c
{
};

int main()
{
    D d;
    // d.vf(); //程序二义性
    system("pause");
    return 0;
}
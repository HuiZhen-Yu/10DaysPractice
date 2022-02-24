/*
基类中protected的成员
类内部：可以访问
类的使用者：不能访问
类的派生类成员：可以访问
 */
#include <iostream>
using namespace std;

class B
{
private:
    int i;

protected:
    int j;

public:
    int k;
};

class D:public B{
    public: 
    void f()
    {
        // cannot access派生类不可访问基类私有成员 
        //i = 1;
        j=2;//派生类可以访问基类保护乘员
        k = 3;
    }
};

int main()
{
    B b;
    //b.i = 1; //err
    //b.j = 2;//err
    b.k = 3;
    system("pause");
    return 0;
}
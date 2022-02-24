/*
派生方式为protected的继承称为保护继承，在这种继承方式下，基类的public成员在派生类中会变成protected成员，基类的protected和private成员在派生类中保持原来的访问权限
 */

#include <iostream>

using namespace std;

class Base
{
private:
    int x;

protected:
    int getx() { return x; }

public:
    void setx(int n) { x = n; }
    void showx() { cout << x << endl; }
};

class Derived : protected Base
{
private:
    int y;

public:
    void sety(int n) { y = n; }
    void sety() { y = getx(); }
    void showy() { cout << y << endl; };
};

int main()
{
    Derived obj;
    // obj.setx(10); //err
    obj.sety(20);
    // obj.showx(); //err
    obj.showy();
    system("pause");
    return 0;
}
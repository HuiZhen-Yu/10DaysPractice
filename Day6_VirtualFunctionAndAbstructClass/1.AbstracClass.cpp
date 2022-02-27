#include <iostream>

using namespace std;

class Figure
{
protected:
    double x, y;

public:
    void set(double i, double j)
    {
        x = i;
        y = j;
    }
    virtual void area() = 0;
};

class Triangle : public Figure
{
public:
    void area()
    {
        cout << "三角形面积：" << x * y * 0.5 << endl;
    }
};

class Rectangle : public Figure
{
public:
    void area()
    {
        cout << "这是矩形，它的面积是：" << x * y << endl;
    }
};

int main(int argc, char **argv)
{
    //定义抽象类指针 多态的实现
    Figure *pf = NULL;
    // Figure f1;   抽象类不能被实例化
    Rectangle r;
    Triangle t;
    t.set(10, 20);
    pf = &t;
    pf->area();
    r.set(10, 20);
    pf = &r;
    pf->area();
    //定义抽象类引用
    Figure &rF = t;
    rF.set(20, 20);
    rF.area();
    system("pause");
    return 0;
}
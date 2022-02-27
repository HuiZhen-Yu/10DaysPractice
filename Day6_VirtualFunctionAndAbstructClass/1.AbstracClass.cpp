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
        cout << "�����������" << x * y * 0.5 << endl;
    }
};

class Rectangle : public Figure
{
public:
    void area()
    {
        cout << "���Ǿ��Σ���������ǣ�" << x * y << endl;
    }
};

int main(int argc, char **argv)
{
    //���������ָ�� ��̬��ʵ��
    Figure *pf = NULL;
    // Figure f1;   �����಻�ܱ�ʵ����
    Rectangle r;
    Triangle t;
    t.set(10, 20);
    pf = &t;
    pf->area();
    r.set(10, 20);
    pf = &r;
    pf->area();
    //�������������
    Figure &rF = t;
    rF.set(20, 20);
    rF.area();
    system("pause");
    return 0;
}
#include <iostream>
using namespace std;

class A
{
private:
    int a;

public:
    void setA(int x) { a = x; }
    int getA() { return a; }
};

class B : public A
{
private:
    int b;

public:
    void setB(int x) { b = x; }
    int getB() { return b; }
};

void f1(A a, int x)
{
    a.setA(x);
}
void f2(A *pA, int x)
{
    pA->setA(x);
}
void f3(A &rA, int x)
{
    rA.setA(x);
}

int main(int argc, char *argv[])
{
    A a1, *pA;
    B b1, *pB;
    a1.setA(1);
    b1.setA(2);
    cout << a1.getA() << endl;
    cout << b1.getA() << endl;

    //�����������ֵ���������
    a1 = b1;
    cout << a1.getA() << endl;
    cout << b1.getA() << endl;
    a1.setA(10);
    cout << a1.getA() << endl;
    cout << b1.getA() << endl;

    //�����������ĵ�ַ��ֵ������ָ��
    pA = &b1;
    pA->setA(20);
    cout << pA->getA() << endl;
    cout << b1.getA() << endl;

    //������������ʼ��������������
    A &ra = b1;
    ra.setA(30);
    cout << pA->getA() << endl;
    cout << b1.getA() << endl;
    b1.setA(7);
    cout << b1.getA() << endl;
    f1(b1, 100);
    cout << "1111111111" << endl;
    cout << b1.getA() << endl;
    f2(&b1, 200);
    cout << b1.getA() << endl;
    f3(b1, 300);
    cout << b1.getA() << endl;

    system("pause");
    return 0;
}
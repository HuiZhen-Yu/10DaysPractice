/*
������ʽΪprotected�ļ̳г�Ϊ�����̳У������ּ̳з�ʽ�£������public��Ա���������л���protected��Ա�������protected��private��Ա���������б���ԭ���ķ���Ȩ��
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
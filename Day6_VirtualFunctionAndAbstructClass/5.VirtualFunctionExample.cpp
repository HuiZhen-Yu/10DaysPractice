#include <iostream>
#include <string>
using namespace std;

/**
 * 基类指针或引用指向派生类对象时，虚函数与非虚函数的区别：
 * 声明Employee的print为虚函数，则可访问到Manager的print函数，而非虚函数，则只能访问到Employ的print
 */

class Employee
{
public:
    Employee(string name, string id);
    string getName();
    string getId();
    float getSalary();
    virtual void print();

private:
    string Name;
    string Id;
};

Employee::Employee(string name, string id)
    : Name(name), Id(id)
{
}
string Employee::getName()
{
    return Name;
}
string Employee::getId()
{
    return Id;
}
float Employee::getSalary()
{
    return 0.0;
}
void Employee::print()
{
    cout << "姓名：" << Name << "\t"
         << "编号：" << Id << endl;
}

class Manager : public Employee
{
public:
    Manager(string name, string id, float s = 0.0) : Employee(name, id)
    {
        weeklySalary = s;
    }
    /* 设置经理的周薪 */
    void setSalary(float s) { weeklySalary = s; }
    /* 获取经理的周薪 */
    float getSalary() { return weeklySalary; }
    /* 打印经理姓名，身份证，周薪 */
    void print()
    {
        cout << "经理：" << getName() << "\t\t 编号：" << getId() << "\t\t 周工资：" << getSalary() << endl;
    }

private:
    float weeklySalary; //周薪
};

/*
    不论哪种赋值方式，都只能通过基类对象(或基类对象的指针或引用)访问到派生类对象从基类中继承到的成员，不能借此访问派生类定义的成员。而虚函数使得可以通过基类对象的指针或引用访问派生类定义的成员。
 */
int main()
{
    Employee e("小米", "NO0001"), *pM;
    Manager m("小汪", "NO0002", 128);
    m.print();
    pM = &m;
    pM->print();
    Employee &rM = m;
    rM.print();

    system("pause");
    return 0;
}
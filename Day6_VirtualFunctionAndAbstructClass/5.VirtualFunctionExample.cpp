#include <iostream>
#include <string>
using namespace std;

/**
 * ����ָ�������ָ�����������ʱ���麯������麯��������
 * ����Employee��printΪ�麯������ɷ��ʵ�Manager��print�����������麯������ֻ�ܷ��ʵ�Employ��print
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
    cout << "������" << Name << "\t"
         << "��ţ�" << Id << endl;
}

class Manager : public Employee
{
public:
    Manager(string name, string id, float s = 0.0) : Employee(name, id)
    {
        weeklySalary = s;
    }
    /* ���þ������н */
    void setSalary(float s) { weeklySalary = s; }
    /* ��ȡ�������н */
    float getSalary() { return weeklySalary; }
    /* ��ӡ�������������֤����н */
    void print()
    {
        cout << "����" << getName() << "\t\t ��ţ�" << getId() << "\t\t �ܹ��ʣ�" << getSalary() << endl;
    }

private:
    float weeklySalary; //��н
};

/*
    �������ָ�ֵ��ʽ����ֻ��ͨ���������(���������ָ�������)���ʵ����������ӻ����м̳е��ĳ�Ա�����ܽ�˷��������ඨ��ĳ�Ա�����麯��ʹ�ÿ���ͨ����������ָ������÷��������ඨ��ĳ�Ա��
 */
int main()
{
    Employee e("С��", "NO0001"), *pM;
    Manager m("С��", "NO0002", 128);
    m.print();
    pM = &m;
    pM->print();
    Employee &rM = m;
    rM.print();

    system("pause");
    return 0;
}
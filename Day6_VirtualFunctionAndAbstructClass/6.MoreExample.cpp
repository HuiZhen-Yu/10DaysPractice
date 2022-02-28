/**
 * ĳ��˾�о�������Ա��Сʱ���ȶ�����Ա��
 * �����ܼ���н�ꣻ
 * ����Աÿ�µ�н800Ԫ��Ȼ���������ɣ�ÿ����һ����Ʒ��ȡ���������5%��
 * Сʱ����Сʱ����н�ꡣÿ
 * ����Ա�������������֤�ŵ����ݣ�Ϊ�˼����⣬�Ѹ�����Ա�Ĺ�����Ϣ����ɻ���Employee��������Ա��̳и���Ĺ��ܡ�
 */

#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
    Employee(const string name, const string id)
        : Name(Name), Id(id)
    {
    }
    /* �������� */
    string getName() { return Name; }
    /* �������֤�� */
    string getId() { return Id; }
    /* ����нˮ */
    float getSalary() { return 0.0; }
    /* ������������֤�� */
    void print()
    {
        cout << "������" << Name << "\t\t ���: " << Id << endl;
    }

private:
    string Name;
    string Id;
};

class Manager : public Employee
{
public:
    Manager(const string name, const string id, int week)
        : Employee(name, id)
    {
        WeeklySalary = week * 1000;
    }
    float getSalary() { return WeeklySalary; }
    void print()
    {
        cout << "����" << getName() << "\t\t ���: " << getId() << "\t\t �ܹ��ʣ�" << getSalary() << endl;
    }

private:
    float WeeklySalary;
};

class SaleWorker : public Employee
{
public:
    SaleWorker(const string name, const string id, int profit, int x)
        : Employee(name, id)
    {
        WorkerMoney = baseMoney + x * 0.05 * profit;
    }
    float getSalary()
    {
        return WorkerMoney;
    }

private:
    float baseMoney = 800;
    float WorkerMoney;
};

class HourWorker : public Employee
{
public:
    HourWorker(const string name, const string id, int h)
        : Employee(name, id)
    {
        TotalMoney = h * hourMoney;
    }
    float getSalary()
    {
        return TotalMoney;
    }
    void print()
    {
        cout << "Сʱ����" << getName() << "\t\t ��ţ�" << getId() << "\t\t �ܹ��ʣ�" << getSalary() << endl;
    }

private:
    float hourMoney = 100.0;
    float TotalMoney;
};

int main()
{
    cout << "�����빤���ܣ�" << endl;
    int week;
    cin >> week;
    Manager m("С��", "11111111", week);
    m.print();

    cout << "��������������" << endl;
    int profit;
    cin >> profit;
    cout << "���������ۼ�����" << endl;
    int x;
    cin >> x;
    SaleWorker s("С��", "222222", profit, x);
    s.print();

    cout << "�����빮����Сʱ��" << endl;
    int hour;
    cin >> hour;
    HourWorker h("С��", "333333", hour);

    h.print();
    system("pause");
    return 0;
}
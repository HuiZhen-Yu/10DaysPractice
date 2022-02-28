/**
 * 某公司有经理，销售员，小时工等多类人员。
 * 经理按周计算薪酬；
 * 销售员每月底薪800元，然后加销售提成，每销售一件产品提取销售利润的5%；
 * 小时工按小时计算薪酬。每
 * 类人员都有姓名和身份证号等数据，为了简化问题，把各类人员的共有信息抽象成基类Employee，其他人员则继承该类的功能。
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
    /* 返回姓名 */
    string getName() { return Name; }
    /* 返回身份证号 */
    string getId() { return Id; }
    /* 返回薪水 */
    float getSalary() { return 0.0; }
    /* 输出姓名和身份证号 */
    void print()
    {
        cout << "姓名：" << Name << "\t\t 编号: " << Id << endl;
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
        cout << "经理：" << getName() << "\t\t 编号: " << getId() << "\t\t 总工资：" << getSalary() << endl;
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
        cout << "小时工：" << getName() << "\t\t 编号：" << getId() << "\t\t 总工资：" << getSalary() << endl;
    }

private:
    float hourMoney = 100.0;
    float TotalMoney;
};

int main()
{
    cout << "请输入工作周：" << endl;
    int week;
    cin >> week;
    Manager m("小王", "11111111", week);
    m.print();

    cout << "请输入销售利润：" << endl;
    int profit;
    cin >> profit;
    cout << "请输入销售件数：" << endl;
    int x;
    cin >> x;
    SaleWorker s("小李", "222222", profit, x);
    s.print();

    cout << "请输入巩工作小时：" << endl;
    int hour;
    cin >> hour;
    HourWorker h("小何", "333333", hour);

    h.print();
    system("pause");
    return 0;
}
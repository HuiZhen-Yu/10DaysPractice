#include <iostream>
#include <cstring>

using namespace std;

/* operator() */
class Time
{
public:
    Time(int a = 0, int b = 0, int c = 0)
        : h(a), m(b), s(c)
    {
    }
    void operator()(int a, int b, int c)
    {
        h = a;
        m = b;
        s = c;
    }

    void PrintTime()
    {
        cout << h << ":" << m << ":" << s << endl;
    }

private:
    int h, m, s;
};

/* opeartor= */
class X
{
public:
    X &operator=(const X &x)
    {
        cout << "a: ";
        return *this;
    }
};

/* operator[] */
struct Person
{
    double salary;
    char *name;
};

class SalaryManaege
{
    Person *employ;
    int max;
    int n;

public:
    SalaryManaege(int Max = 0)
    {
        max = Max;
        /* �����е�ʵ������ */
        n = 0;
        employ = new Person[max];
    }
    double &operator[](const char *Name)
    {
        Person *p;
        for (p = employ; p < employ + n; p++)
            /* ����������� */
            if (strcmp(p->name, Name) == 0)
                return p->salary;
        /* ������������� */
        p = employ + n++;
        p->name = new char[strlen(Name) + 1];
        strcpy(p->name, Name);
        p->salary = 0;
        return p->salary;
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            cout << employ[i].name << "   " << employ[i].salary << endl;
        }
    }
};

class Y
{
public:
    int operator()(int i = 0)
    {
        cout << "Y::operator(" << i << ")" << endl;
        return i;
    }
    int operator()(int i, int j)
    {
        cout << "Y::operator(" << i << "," << j << ")" << endl;
        return 0;
    }
    int operator[](int i)
    {
        cout << "Y::operator[" << i << "]" << endl;
        return 0;
    }
    int operator[](const char *cp)
    {
        cout<<"X::operator["<<cp<<"]"<<endl;
        return 0;
    }
};

int main()
{
    Time t1(12, 13, 14);
    t1.PrintTime();
    t1.operator()(23, 24, 25);
    t1.PrintTime();
    t1(10, 10, 10);
    t1.PrintTime();

    X obj1, obj2, obj3;
    obj1 = obj2;
    obj1.operator=(obj2);
    obj1 = obj2 = obj3;
    cout<<endl;

    SalaryManaege s(3);
    s["����"] = 2188.0;
    s["����"] = 1230.07;
    s["����"] = 3200.97;

    cout << "����\t" << s["����"] << endl;
    cout << "����\t" << s["����"] << endl;
    cout << "����\t" << s["����"] << endl;

    cout << "-------��Ϊdisplay�����-------\n\n";
    s.display();

    Y obj;
    int i = obj(obj(1), 2);
    int a = obj[i];
    int b = obj["abcd"];
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;

    system("pause");
    return 0;
}
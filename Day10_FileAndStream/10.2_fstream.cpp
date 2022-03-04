#include <iostream>
#include <fstream>

//������һ���ܹ�����������͵Ķ�̬����
#include <vector>
#include <cstring>

using namespace std;

class Person
{
private:
    char name[20];
    char id[18];
    int age;
    char addr[20];

public:
    Person() {}
    Person(char *n, char *pid, int Age, char *Addr)
    {
        strcpy(name, n);
        strcpy(id, pid);
        age = Age;
        strcpy(addr, Addr);
    }
    void display()
    {
        cout << name << "\t" << id << "\t" << age << "\t" << addr << endl;
    }
};
int main(int argc, char const **argv)
{
#if 0
    fstream ioFile;
    ioFile.open("./10DaysPractice/Day10_FileAndStream/a.dat", ios::out);
    ioFile << "����"
           << "  " << 76 << " " << 98 << " " << 67 << endl; // L3
    ioFile << "����"
           << "  " << 89 << " " << 70 << " " << 60 << endl;
    ioFile << "��ʮ"
           << "  " << 91 << " " << 88 << " " << 77 << endl;
    ioFile << "�ƶ�"
           << "  " << 62 << " " << 81 << " " << 75 << endl;
    ioFile << "����"
           << "  " << 90 << " " << 78 << " " << 67 << endl;
    ioFile.close();
    ioFile.open("./10DaysPractice/Day10_FileAndStream/a.dat", ios::in | ios::binary);
    char name[10];
    int chinese, math, computer;
    cout << "����\t"
         << "Ӣ��\t"
         << "��ѧ\t"
         << "�����\t"
         << "�ܷ�" << endl;
    ioFile >> name;
    while (!ioFile.eof())
    {
        ioFile >> chinese >> math >> computer;
        cout << name << "\t" << chinese << "\t" << math << "\t" << computer << "\t" << chinese + math + computer << endl;
        ioFile >> name;
    }
    ioFile.close();
#elif 0
    char ch;
    ofstream out("./10DaysPractice/Day10_FileAndStream/test.dat", ios::out | ios::binary); // L1
    for (int i = 0; i < 90; i++)
    {
        if (i > 0 && (i % 30) == 0)
            out.put('\n');
        out.put(i);
        out.put(' ');
    }
    out.close();
    ifstream in("./10DaysPractice/Day10_FileAndStream/test.dat", ios::in | ios::binary);
    while (in.get(ch))
        cout << ch;
    in.close();
#elif 3

    vector<Person> v;
    vector<Person>::iterator pos; //����һ����������������vector���������ã���������ָ��vector������Ԫ��
    char ch;
    ofstream out("./10DaysPractice/Day10_FileAndStream/persion.txt", ios::out | ios::app | ios::binary);
    char Name[20], ID[18], Addr[20];
    int Age;
    cout << "------������˵���------" << endl
         << endl;
    do
    {
        cout << "name: ";
        cin >> Name;
        cout << "ID number: ";
        cin >> ID;
        cout << "age: ";
        cin >> Age;
        cout << "Address: ";
        cin >> Addr;
        Person per(Name, ID, Age, Addr);
        out.write((char *)&per, sizeof(per));
        cout << "Enter another Person(y/n)?";
        cin >> ch;
    } while (ch == 'y');
    out.close();
    ifstream in("./10DaysPractice/Day10_FileAndStream/persion.txt", ios::in | ios::binary); // L9
    Person s;
    in.read((char *)&s, sizeof(s));
    while (!in.eof())
    {
        v.push_back(s);
        in.read((char *)&s, sizeof(s));
    }
    cout << "\n---------���ļ��ж���������--------" << endl
         << endl; // L15
    pos = v.begin();
    for (pos = v.begin(); pos != v.end(); pos++)
        (*pos).display();
#endif

    system("pause");
    return 0;
}
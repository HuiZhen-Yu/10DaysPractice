#include <iostream>

using namespace std;

void display(const double &r);

class A
{
public:
    A(int i, int j)
    {
        x = i;
        y = j;
    }

private:
    int x, y;
};

int main(int argc, char **argv)
{
    double d(9.5);
    display(d);
    A const a(3, 4); // a�ǳ������ܱ�����
    system("pause");
    return 0;
}

// ���������βΣ��ٺ����в��ܸ���r�����õĶ���
void display(const double &r)
{
    cout << r << endl;
}
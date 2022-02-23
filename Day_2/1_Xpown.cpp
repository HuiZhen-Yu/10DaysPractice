#include <iostream>
using namespace std;

/**
 * ����x��y����
 **/
double power(const double &x, int y)
{
    double value = 1;
    while (y--)
    {
        value *= x;
    }
    return value;
}

int main(int argc, char **argv)
{
    /* ��һ�����ܼ���x��y�η� */
    double base = 0.0;
    int index = 0;
    cout << "���������: " << endl;
    cin >> base;
    cout << "������ָ�� : " << endl;
    cin >> index;
    double result = power(base, index);
    cout << "����ǣ�" << result << endl;

    /* �ڶ������� ����������ת����10������ */
    unsigned int num_binary = 0;
    unsigned int num_decimal = 0;
    cout << "��������������� : " << endl;
    cin >> num_binary;
    for (int i = 0; i < 8; i++)
    {
        unsigned int num_digit = num_binary % 10;
        num_binary /= 10;
        num_decimal += num_digit ? power(2, i) : 0;
    }
    cout << "����ǣ�" << num_decimal << endl;

    system("pause");
    return 0;
}
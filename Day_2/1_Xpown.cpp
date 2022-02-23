#include <iostream>
using namespace std;

/**
 * 计算x的y次幂
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
    /* 第一个功能计算x的y次方 */
    double base = 0.0;
    int index = 0;
    cout << "请输入底数: " << endl;
    cin >> base;
    cout << "请输入指数 : " << endl;
    cin >> index;
    double result = power(base, index);
    cout << "结果是：" << result << endl;

    /* 第二个功能 将二进制数转换成10进制数 */
    unsigned int num_binary = 0;
    unsigned int num_decimal = 0;
    cout << "请输入二进制序列 : " << endl;
    cin >> num_binary;
    for (int i = 0; i < 8; i++)
    {
        unsigned int num_digit = num_binary % 10;
        num_binary /= 10;
        num_decimal += num_digit ? power(2, i) : 0;
    }
    cout << "结果是：" << num_decimal << endl;

    system("pause");
    return 0;
}
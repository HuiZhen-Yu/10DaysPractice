#include <iostream>
using namespace std;

double mypower(double x, double y) {
    
}

double power(double x, int n)
{
    double val = 1.0;
    while (n--)
    {
        val *= x;
    }
    return val;
}

int main(int argc, char const *argv[])
{
    int x;
    cin >> x;   //��Ҫ��������Ƶ���10101100->179
    int wei = 0;
    int sum = 0;
    int each, chu;
    for (int i = 0; i < 8; i++)
    {
        each = x % 10;
        chu = x / 10;
        sum += each * power(2, wei);
        x = chu;
        wei++;
    }
    cout << sum << endl;
    system("pause");
    return 0;
}

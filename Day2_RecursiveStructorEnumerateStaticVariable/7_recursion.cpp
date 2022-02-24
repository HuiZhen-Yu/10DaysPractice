#include <iostream>

using namespace std;

/* 计算阶乘 */

int f(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * f(n - 1);
    }
}

int main(int argc, char const *arg[])
{
    cout << "input x : ";
    int x;
    cin >> x;
    cout << f(x) << endl;
    system("pause");
    return 0;
}
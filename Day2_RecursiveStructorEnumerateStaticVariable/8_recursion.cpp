#include <iostream>

using namespace std;

/* Calculate Feibonacci */
int f(int a)
{
    if (a == 1)
    {
        return 0;
    }
    else if (a == 2)
    {
        return 1;
    }
    else
    {
        return f(a - 1) + f(a - 2);
    }
}

int f2(int n, int k)
{
    if ((n == k) || (k == 0))
    {
        return 1;
    }
    else
    {
        return f2(n - 1, k - 1) + f2(n - 1, k);
    }
}

int main()
{
    cout << "Please input a number: ";
    int a = 0;
    cin >> a;
    int result = f(a);
    cout << "the result is " << result << endl;

    cout << "Please enter two integer number : " << endl;
    int n, k;
    cin >> n >> k;
    cout << f2(n, k) << endl;
    system("pause");
    return 0;
}
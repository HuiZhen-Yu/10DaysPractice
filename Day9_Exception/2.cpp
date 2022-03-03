#include <iostream>

using namespace std;

void handler(int n) throw()
{
    try
    {
        if (n == 1)
            throw n;
        if (n == 2)
            throw 'X';
        if (n == 3)
            throw 1.1;
    }
    catch (...)
    {
        cout << "catch an exception..." << endl;
    }
}

int main(int argc, char **argv)
{
    cout << "Before handler..." << endl;
    try
    {
        handler(1);
    }
    catch (int i)
    {
        cout << "catch an integer..." << endl;
    }
    catch (char c)
    {
        cout << "catch an char..." << endl;
    }
    catch (double d)
    {
        cout << "catch an double..." << endl;
    }
    system("pause");
    return 0;
}
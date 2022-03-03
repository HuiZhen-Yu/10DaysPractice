#include <iostream>

using namespace std;

void temperature(int t)
{
    if (t == 0)
        throw "╫А╠Ыак";
    else if (t == 100)
        throw "╥плзак";
    else
    {
        cout << "temperatore=" << t << endl;
    }
}

int main(int argc, char **argv)
{
    int t = 0;
    cin >> t;
    cout << "1--before try block..." << endl;
    try
    {
        if (t == 10)
            throw "It's at the boiling point.";
        else if (t == 0)
            throw "It's reached the freezing point";
        else
            cout << "the temprature is OK..." << endl;
    }
    catch (int x)
    {
        cout << "temprature = " << x << endl;
    }
    catch (char const *s)
    {
        cout << s << endl;
    }

    try
    {
        cout << "2--inside try block..." << endl;
        throw 10;
        cout << "3--after throw ..." << endl;
    }
    catch (int i)
    {
        cout << "4--In catch block1...exception..errcode is..." << i << endl;
    }
    catch (char *s)
    {
        cout << "5--In catch block2 ... exception..errcode is.." << s << endl;
    }
    catch (double i)
    {
        cout << "7--In catch block double..an double type is.." << i << endl;
    }
    cout << "6--After Catch..." << endl;

    try
    {
        temperature(0);
    }
    catch (char const *s)
    {
        cout << s << endl;
    }

    system("pause");
    return 0;
}
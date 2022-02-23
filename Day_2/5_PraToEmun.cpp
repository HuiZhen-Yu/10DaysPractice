#include <iostream>

using namespace std;

enum weekday
{
    s,
    m,
    t,
    w,
    thu,
    f,
    s1
};
int main(int argc, char **argv)
{
    enum weekday wek = s;

    for (int i = wek; i != f; i++)
    {
        cout << i << endl;
        cout << wek + s << endl;
        cout << "-------Ã¶¾Ù-------" << endl;
    }
    system("pause");
    return 0;
}
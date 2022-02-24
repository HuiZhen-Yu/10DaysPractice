#include <iostream>

using namespace std;

void hannuo(int, char, char, char);
void hannuo1(int, char *, char *, char *);

int main(int argc, char **argv)
{
    int num_flower = 0;
    cout << "Please enter the flower number of HannuoTower " << endl;
    cin >> num_flower;
    hannuo(num_flower, 'A', 'B', 'C');
    cout << "the first way is ok!!" << endl;
    char a = 'A';
    char b = 'B';
    char c = 'C';
    hannuo1(num_flower, &a, &b, &c);
    system("pause");
    return 0;
}

void move(char a, char b)
{
    cout << a << "--->" << b << endl;
}

/* Move n plates from a to c with the help of b */
void hannuo(int n, char a, char b, char c)
{
    if (n == 1)
    {
        move(a, c);
    }
    else
    {
        hannuo(n - 1, a, c, b);
        move(a, c);
        hannuo(n - 1, b, a, c);
    }
}
/* err ??? */
void hannuo1(int n, char *a, char *b, char *c)
{
    if (n == 1)
    {
        move(*a, *c);
    }
    else
    {
        hannuo1(n - 1, a, c, b);
        move(*a, *c);
        char change = *a;
        *a = *b;
        *b = change;
        hannuo1(n - 1, a, b, c);
    }
}
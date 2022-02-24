#include <iostream>
#include <cmath>

using namespace std;

double arctanx(double x)
{
    double e = x;
    double result = x;
    for (unsigned i = 3; abs(e) > 1e-6; i += 2)
    {
        e *= -x * x;
        result += e / i;
    }
    return result;
}

int main(int argc, char **argv)
{
    double pi = 0;
    /* pi=arctan(1/5)-4*arctan(1/239) */
    pi = 16 * arctanx(1.0 / 5) - 4 * arctanx(1.0 / 239.0);
    cout << "PI = " << pi << endl;
    system("pause");
    return 0;
}
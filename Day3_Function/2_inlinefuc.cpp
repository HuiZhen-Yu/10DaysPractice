#include <iostream>

using namespace std;

inline double CalArea(double radius);

int main(int argc, char *arg[])
{
    cout << "Please input the radius: " << endl;
    double r(3.0);
    cin >> r;
    double area;
    area = CalArea(r);
    cout << area << endl;
    system("pause");
    return 0;
}

inline double CalArea(double radius)
{
    return 3.1415936 * radius * radius;
}
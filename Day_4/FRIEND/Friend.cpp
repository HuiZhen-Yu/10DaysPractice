#include <iostream>
#include <cmath>

using namespace std;

class Point
{
public:
    Point(int x = 0, int y = 0) : X(x), Y(y) {}
    int getX() { return X; }
    int getY() { return Y; }
    friend float Distance(Point &a, Point &b);

private:
    int X, Y; //˽�����ݳ�Ա
};

//ͨ����һ��ģ������Ϊ��һ��ģ�����Ԫ��һ��ģ���ܹ����õ���һ��ģ���б��Ǳ����ص���Ϣ��
float Distance(Point &a, Point &b)
{
    double dx = a.X - b.X;
    double dy = a.Y - b.Y;
    return sqrt(dx * dx + dy * dy);
}
int main(int argc, char **argv)
{
    Point p1(3.0, 5.0), p2(4.0, 6.0);
    cout << "����֮��ľ���Ϊ: " << Distance(p1, p2) << endl;
    printf("Distance = %10.8lf\r\n", Distance(p1, p2));
    system("pause");
    return 0;
}
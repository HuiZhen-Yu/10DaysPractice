#include <iostream>
#include <string>

using namespace std;

/* ��ͬ���ڴ��ַ */

union myunions
{
    struct
    {
        int x;
        int y;
        int z;
    } u;
    int k;
} a;

int main(int argc, char *argv[])
{
    a.u.x = 4;
    a.u.y = 5;
    a.u.z = 6;
    a.k = 0; //���ǵ���һ��int�ռ�
    printf("%d %d %d %d", a.u.x, a.u.y, a.u.z, a.k);
    system("pause");
    return 0;
}
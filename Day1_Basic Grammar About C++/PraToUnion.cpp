#include <iostream>
#include <string>

using namespace std;

/* 相同的内存地址 */

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
    a.k = 0; //覆盖掉第一个int空间
    printf("%d %d %d %d", a.u.x, a.u.y, a.u.z, a.k);
    system("pause");
    return 0;
}
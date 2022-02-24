#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char **argv)
{
    cout << "Hello world!" << endl; // c++流输出，通过类的调用实现
    printf("Hello world!!\r\n");    // c格式控制输出，c++兼容
    system("pause");
    return 0;
}
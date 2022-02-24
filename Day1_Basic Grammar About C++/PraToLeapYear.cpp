#include <iostream>

using namespace std;

/**
 *  功能判断一个年份是否是闰年
 **/

int main(int argc, char **argv)
{
    int year = 0;
    bool isLeapYear = false;
    cout << "Enter the year: " << endl;
    cin >> year;
    isLeapYear = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    if (isLeapYear)
    {
        cout << year << " is a leap year" << endl;
    }
    else
    {
        cout << year << " is not a leap year" << endl;
    }

    system("pause");
    return 0;
}

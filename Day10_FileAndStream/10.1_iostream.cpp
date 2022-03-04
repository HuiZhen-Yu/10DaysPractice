#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char **argv)
{
/* cin使用 */
#if 0
    char a[50];
    string b;
    cout << "please input a string: ";
    cin >> a;
    cout << a << endl;
    cin >> b;
    cout << b << endl;

    char stu[5][10];
    int i;
    for (i = 0; i < 5; i++)
        cin.getline(stu[i], 10, ',');
    for (i = 0; i < 5; i++)
        cout << stu[i] << endl;
#elif 2
    char a, b, c, d;
    cin.get(a);
    cin.get(b);
    c = cin.get();
    d = cin.get();
    cout << int(a) << ',' << int(b) << ',' << int(c) << ',' << int(d) << endl;
    /*
用法：a = cin.get() ?或者 ?cin.get(a)
结束条件：输入字符足够后回车
说明：这个是单字符的输入，用途是输入一个字符，把它的ASCALL码存入到a中
处理方法：与cin不同，cin.get()在缓冲区遇到[enter]，[space]，[tab]不会作为舍弃，而是继续留在缓冲区中
*/

    // get()两个参数

    // 1.输入串长<size，输入串长>arraylength，会自动扩张arrayname大小，使能保存所有数据
    //  char a[10];
    //  cin.get(a,20);
    //  cout<<a<<endl;
    //  cout<<sizeof(a)<<endl;
    // 2.输入串长<size，输入串长<arraylength，把串全部输入，后面补‘\0’
    //  char b[10];
    //  cin.get(b,20);
    //  cout<<b<<endl;//12345，此时数组内数据为‘12345'\0’
    //  cout<<sizeof(b)<<endl;
    // 3.输入串长>size，先截取size个字符，若还是大于arraylength，则输入前arraylength-1个字符，最后补充‘\0’
    //  char c[5];
    //  cin.get(c,10);
    //  cout<<c<<endl;
    //  cout<<sizeof(c)<<endl;
    // 4.输入串长>size，先截取size个字符，若小于arraylength，则把截取串放入数组中，最后补充‘\0’
    //  char d[10];
    //  cin.get(d,5);
    //  cout<<d<<endl;
    //  cout<<sizeof(d)<<endl;

    // get()三个参数
    /*
        用法：cin.get(arrayname,size,s) ?把数据输入到arrayname字符数组中，当到达长度size时结束或者遇到字符s时结束
        注释：a必须是字符数组，即char a[]类型，不可为string类型；size为最大的输入长度；s为控制，遇到s则当前输入结束缓存区里的s将被舍弃
    */
    int i;
    char e[10];
    cin.get(e, 8, ',');
    cout << e;

    /*
    char a[10];
    char b;
    cin.get(a,10);
    cin.get(b);
    cout<<a<<endl<<int(b);//输入：12345[enter] 输出：12345 【换行】 10*/
    /*char c[10];
    char d;
    cin.getline(c,10);
    cin.get(d);
    cout<<c<<endl<<int(d);//输入：12345[enter]a[enter] 输出：12345【换行】97*/
    // cin.getline(arrayname,size,s)与cin.gei(arrayname,size,s)的区别
    /*
    cin.getline(arrayname,size,s)当遇到s时会结束输入，并把s从缓冲区中删除
    cin.get（arrayname,size,s）当遇到s时会结束输入，但不会删除缓冲区中的s
    */
    /*
     char e[10];
     char f;
     cin.get(e,10,',');
     cin.get(f);
     cout<<e<<endl<<f;//输入：12345,[enter] 输出：12345【换行】，说明：cin,get不会删除缓冲区的，*/
    char e1[10];
    char f1;
    cin.getline(e1, 10, ',');
    cin.get(f1);
    cout << e1 << endl
         << f1; //输入：asd,wqe 输出：asd【换行】

#endif

/* cout使用 */
#if 0
    char c;
    char a[50] = "this is a string...";
    cout << "use get() input char:";
    while ((c = cin.get()) != '\n')
    {
        cout.put(c);
        cout.put('\n');
        cout.put('t').put('h').put('i').put('s').put('\n');
        cout.write(a, 12).put('\n');
        cout << "look"
             << "\t here!" << endl;
    }
/* 格式控制 */
#elif 0
    char e[30] = "this is string";
    double f = -1234.8976;
    cout << setw(30) << left << setfill('*') << e << "----L1" << endl;
    cout << setw(30) << right << setfill('*') << e << "----L2" << endl;
    // showbase显示数值的基数前缀 base(进制)
    cout << dec << showbase << showpoint << setw(30) << f << "----L3"
         << "\n";
    // showpoint显示小数点
    cout << setw(30) << showpoint << setprecision(10) << f << "----L4"
         << "\n";
    // setbase(8)设置八进制
    cout << setw(30) << setbase(16) << 100 << "----L5"
         << "\n";
#elif 2
    char c[30] = "this is string";
    double d = -1231.232;
    cout.width(30);
    cout.fill('*');
    cout.setf(ios::left);
    cout << c << "----L1" << endl;
    cout.width(30);
    cout.fill('-');
    cout.setf(ios::right);
    cout << c << "----L2" << endl;
    cout.setf(ios::dec | ios::showbase | ios::showpoint);
    cout.width(30);
    cout << d << "----L3"
         << "\n";
    cout.setf(ios::showpoint);
    cout.precision(10);
    cout.width(30);
    cout << d << "----L4"
         << "\n";
    cout.width(30);
    cout.setf(ios::oct, ios::basefield);
    cout << 100 << "----L5"
         << "\n";
#endif
    system("pause");
    return 0;
}
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char **argv)
{
/* cinʹ�� */
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
�÷���a = cin.get() ?���� ?cin.get(a)
���������������ַ��㹻��س�
˵��������ǵ��ַ������룬��;������һ���ַ���������ASCALL����뵽a��
����������cin��ͬ��cin.get()�ڻ���������[enter]��[space]��[tab]������Ϊ���������Ǽ������ڻ�������
*/

    // get()��������

    // 1.���봮��<size�����봮��>arraylength�����Զ�����arrayname��С��ʹ�ܱ�����������
    //  char a[10];
    //  cin.get(a,20);
    //  cout<<a<<endl;
    //  cout<<sizeof(a)<<endl;
    // 2.���봮��<size�����봮��<arraylength���Ѵ�ȫ�����룬���油��\0��
    //  char b[10];
    //  cin.get(b,20);
    //  cout<<b<<endl;//12345����ʱ����������Ϊ��12345'\0��
    //  cout<<sizeof(b)<<endl;
    // 3.���봮��>size���Ƚ�ȡsize���ַ��������Ǵ���arraylength��������ǰarraylength-1���ַ�����󲹳䡮\0��
    //  char c[5];
    //  cin.get(c,10);
    //  cout<<c<<endl;
    //  cout<<sizeof(c)<<endl;
    // 4.���봮��>size���Ƚ�ȡsize���ַ�����С��arraylength����ѽ�ȡ�����������У���󲹳䡮\0��
    //  char d[10];
    //  cin.get(d,5);
    //  cout<<d<<endl;
    //  cout<<sizeof(d)<<endl;

    // get()��������
    /*
        �÷���cin.get(arrayname,size,s) ?���������뵽arrayname�ַ������У������ﳤ��sizeʱ�������������ַ�sʱ����
        ע�ͣ�a�������ַ����飬��char a[]���ͣ�����Ϊstring���ͣ�sizeΪ�������볤�ȣ�sΪ���ƣ�����s��ǰ����������������s��������
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
    cout<<a<<endl<<int(b);//���룺12345[enter] �����12345 �����С� 10*/
    /*char c[10];
    char d;
    cin.getline(c,10);
    cin.get(d);
    cout<<c<<endl<<int(d);//���룺12345[enter]a[enter] �����12345�����С�97*/
    // cin.getline(arrayname,size,s)��cin.gei(arrayname,size,s)������
    /*
    cin.getline(arrayname,size,s)������sʱ��������룬����s�ӻ�������ɾ��
    cin.get��arrayname,size,s��������sʱ��������룬������ɾ���������е�s
    */
    /*
     char e[10];
     char f;
     cin.get(e,10,',');
     cin.get(f);
     cout<<e<<endl<<f;//���룺12345,[enter] �����12345�����С���˵����cin,get����ɾ���������ģ�*/
    char e1[10];
    char f1;
    cin.getline(e1, 10, ',');
    cin.get(f1);
    cout << e1 << endl
         << f1; //���룺asd,wqe �����asd�����С�

#endif

/* coutʹ�� */
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
/* ��ʽ���� */
#elif 0
    char e[30] = "this is string";
    double f = -1234.8976;
    cout << setw(30) << left << setfill('*') << e << "----L1" << endl;
    cout << setw(30) << right << setfill('*') << e << "----L2" << endl;
    // showbase��ʾ��ֵ�Ļ���ǰ׺ base(����)
    cout << dec << showbase << showpoint << setw(30) << f << "----L3"
         << "\n";
    // showpoint��ʾС����
    cout << setw(30) << showpoint << setprecision(10) << f << "----L4"
         << "\n";
    // setbase(8)���ð˽���
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
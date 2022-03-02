#include <iostream>
#include <cstring>

using namespace std;
/**
 * 不要把这里面的class与类里面的class混淆在一起，虽然他们相同的名字组成，但是含义是不同的，
 * 这里的class表示是T的一个参数类型，可以是任何的数据类型，如int、float、char等，或者是用户自定义的struct、enum或class等自定义数据类型
 * 为了区别类与模板参数中的类型关键字class，标准c++提出了用typename作为模板参数的类型关键字，同时也支持使用class
 */

/* 函数模板 */
#if 0
/**
 * 模板实例化发生在调用模板函数时。当编译器遇到程序中对函数模板的调用时，
 * 它才会根据调用语句中实参的具体类型，确定模板参数的数据类型，
 * 并用此类型替换函数模板中的模板参数，生成能够处理该类型的函数代码，即模板函数。
 * 当多次发生类型相同的参数调用时，只在第1次进行实例化。编译器只在第1次调用时生成模板函数，
 * 当之后遇到相同类型的参数调用时，不再生成其他模板函数，它将调用第1次实例化生成的模板函数。
 */
template <class T> /* 实现降序排序 */
void sort(T *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int p = i;
        for (int j = i; j < n; j++)
            if (a[p] < a[j])
                p = j;
        T t = a[i];
        a[i] = a[p];
        a[p] = t;
    }
}

template <typename T>
void display(T &a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t" << endl;
    }
}

/* 模板的特化 TemplateSpecialization */
/* 注意一点，在使用max与min的时候，容易与std命名空间里面的函数进行冲突 */
template <class T>
T myMax(T a, T b)
{
    return a > b ? a : b;
}

template <>
char *myMax(char *a, char *b)
{
    return (strcmp(a, b) >= 0) ? a : b;
}

/* 函数模板作为类模板成员 */
template <class T>
class A
{
public:
    template <class T2>
    void Func(T2 t) { cout << t; } /* 成员函数模板 */
};


int main(int argc, char const *argv[])
{

    A<int> a;
    a.Func('F');
    a.Func("hello");

    int b[] = {1, 41, 2, 5, 8, 21, 23};
    char c[] = {'a', 'x', 'y', 'e', 'q', 'g', 'o', 'u'};
    sort(b, 7);
    sort(c, 8);
    display(b, 7);
    display(c, 8);
    cout << endl;

    float d = 5.1, e = 3.2;
    int f = 2, g = 3;
    cout << "2, 3.2的最大值是：" << myMax(double(2), 2.3) << endl;
    cout << "2,3的最大值是：" << myMax(f, g) << endl;
    cout << "d,e的最大值是：" << myMax(d, e) << endl;
    cout << "xbv和xyce的最大值是" << myMax("xbv", "xyce") << endl;

    system("pause");
    return 0;
}

#endif

/* 类模板 */
#if 1

/* 设计一个堆栈的类模板Stack，在模板中用类型参数T表示栈中存放的数据，用非类型参数MAXSIZE表示栈的大小 */
template <typename T, int MAXSIZE>
class Stack
{
private:
    T elem[MAXSIZE];
    int top;

public:
    Stack() : top(0) {}
    void push(T e);
    T pop();
    bool empty()
    {
        if (top <= -1)
            return 1;
        else
            return 0;
    }
    void setEmpty()
    {
        top = -1;
    }
    bool full()
    {
        if (top >= MAXSIZE - 1)
            return 1;
        else
            return 0;
    }
};
/*
原型：
template <模板参数列表>
返回值类型 类模板名<模板参数名表>：：函数成员名（参数列表）{}
*/
template <class T, int MAXSIZE>
void Stack<T, MAXSIZE>::push(T e)
{
    if (full())
    {
        cout << "栈已经满了，不能再添加元素了!" << endl;
        return;
    }
    elem[++top] = e;
}

template <class T, int MAXSIZE>
T Stack<T, MAXSIZE>::pop()
{
    if (empty())
    {
        cout << "栈已空，不能再弹出元素了！" << endl;
        return 0;
    }
    return elem[top--];
}

/* 类模板特化 */
/* 设计一通用数组类，它能够直接存取数组元素，并能够对数组进行从大到小的排序 */
const int Size = 5;
template <class T>
class Array
{
private:
    T a[Size];

public:
    Array()
    {
        for (int i = 0; i < Size; i++)
        {
            a[i] = 0;
        }
    }
    T &operator[](int i);
    void Sort();
};

template <typename T>
T &Array<T>::operator[](int i)
{
    if (i < 0 || i >= Size)
    {
        cout << "\n数组下标越界！" << endl;
        exit(1);
    }
    return a[i];
}

template <class T>
void Array<T>::Sort()
{
    int p;
    for (int i = 0; i < Size; i++)
    {
        p = i;
        for (int j = i; j < Size; j++)
            if (a[p] < a[j])
                p = j;

        T t = a[p];
        a[p] = a[i];
        a[i] = t;
    }
}
/* 模板特化 */
template <>
void Array<char *>::Sort()
{
    int p;
    for (int i = 0; i < Size - 1; i++)
    {
        p = 1;
        for (int j = i + 1; j < Size; j++)
            if (strcmp(a[p], a[j]) < 0)
                p = j;
        char *t = a[p];
        a[p] = a[i];
        a[i] = t;
    }
}

#endif

int main(int argc, char const *argv[])
{

    /* 类模板实例化 */
    Stack<int, 10> iStack;
    Stack<char, 10> cStack;
    iStack.setEmpty();
    cStack.setEmpty();
    cout << "------intstack------\n";

    int i;
    for (i = 1; i < 11; i++)
        iStack.push(i);
    for (i = 1; i < 11; i++)
        cout << iStack.pop() << "\t";
    cout << "\n\n-------charStack----\n";

    cStack.push('A');
    cStack.push('B');
    cStack.push('C');
    cStack.push('D');
    cStack.push('E');
    for (i = 1; i < 6; i++)
        cout << cStack.pop() << "\t";
    cout << endl;

    Array<int> a1;
    Array<char *> b1;
    a1[0] = 1;
    a1[1] = 23;
    a1[2] = 6;
    a1[3] = 3;
    a1[4] = 9;
    a1.Sort();
    for (int i = 0; i < 5; i++)
        cout << a1[i] << "\t";
    cout << endl;
    b1[0] = "x1";
    b1[1] = "ya";
    b1[2] = "ad";
    b1[3] = "be";
    b1[4] = "bc";
    b1.Sort();
    for (int i = 0; i < 5; i++)
        cout << b1[i] << "\t";
    cout << endl;
    system("pause");
    return 0;
}
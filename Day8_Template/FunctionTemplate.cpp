#include <iostream>
#include <cstring>

using namespace std;
/**
 * ��Ҫ���������class���������class������һ����Ȼ������ͬ��������ɣ����Ǻ����ǲ�ͬ�ģ�
 * �����class��ʾ��T��һ���������ͣ��������κε��������ͣ���int��float��char�ȣ��������û��Զ����struct��enum��class���Զ�����������
 * Ϊ����������ģ������е����͹ؼ���class����׼c++�������typename��Ϊģ����������͹ؼ��֣�ͬʱҲ֧��ʹ��class
 */

/* ����ģ�� */
#if 0
/**
 * ģ��ʵ���������ڵ���ģ�庯��ʱ�������������������жԺ���ģ��ĵ���ʱ��
 * ���Ż���ݵ��������ʵ�εľ������ͣ�ȷ��ģ��������������ͣ�
 * ���ô������滻����ģ���е�ģ������������ܹ���������͵ĺ������룬��ģ�庯����
 * ����η���������ͬ�Ĳ�������ʱ��ֻ�ڵ�1�ν���ʵ������������ֻ�ڵ�1�ε���ʱ����ģ�庯����
 * ��֮��������ͬ���͵Ĳ�������ʱ��������������ģ�庯�����������õ�1��ʵ�������ɵ�ģ�庯����
 */
template <class T> /* ʵ�ֽ������� */
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

/* ģ����ػ� TemplateSpecialization */
/* ע��һ�㣬��ʹ��max��min��ʱ��������std�����ռ�����ĺ������г�ͻ */
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

/* ����ģ����Ϊ��ģ���Ա */
template <class T>
class A
{
public:
    template <class T2>
    void Func(T2 t) { cout << t; } /* ��Ա����ģ�� */
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
    cout << "2, 3.2�����ֵ�ǣ�" << myMax(double(2), 2.3) << endl;
    cout << "2,3�����ֵ�ǣ�" << myMax(f, g) << endl;
    cout << "d,e�����ֵ�ǣ�" << myMax(d, e) << endl;
    cout << "xbv��xyce�����ֵ��" << myMax("xbv", "xyce") << endl;

    system("pause");
    return 0;
}

#endif

/* ��ģ�� */
#if 1

/* ���һ����ջ����ģ��Stack����ģ���������Ͳ���T��ʾջ�д�ŵ����ݣ��÷����Ͳ���MAXSIZE��ʾջ�Ĵ�С */
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
ԭ�ͣ�
template <ģ������б�>
����ֵ���� ��ģ����<ģ���������>����������Ա���������б�{}
*/
template <class T, int MAXSIZE>
void Stack<T, MAXSIZE>::push(T e)
{
    if (full())
    {
        cout << "ջ�Ѿ����ˣ����������Ԫ����!" << endl;
        return;
    }
    elem[++top] = e;
}

template <class T, int MAXSIZE>
T Stack<T, MAXSIZE>::pop()
{
    if (empty())
    {
        cout << "ջ�ѿգ������ٵ���Ԫ���ˣ�" << endl;
        return 0;
    }
    return elem[top--];
}

/* ��ģ���ػ� */
/* ���һͨ�������࣬���ܹ�ֱ�Ӵ�ȡ����Ԫ�أ����ܹ���������дӴ�С������ */
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
        cout << "\n�����±�Խ�磡" << endl;
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
/* ģ���ػ� */
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

    /* ��ģ��ʵ���� */
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
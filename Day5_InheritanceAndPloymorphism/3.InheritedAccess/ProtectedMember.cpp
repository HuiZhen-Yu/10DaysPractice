/*
������protected�ĳ�Ա
���ڲ������Է���
���ʹ���ߣ����ܷ���
����������Ա�����Է���
 */
#include <iostream>
using namespace std;

class B
{
private:
    int i;

protected:
    int j;

public:
    int k;
};

class D:public B{
    public: 
    void f()
    {
        // cannot access�����಻�ɷ��ʻ���˽�г�Ա 
        //i = 1;
        j=2;//��������Է��ʻ��ౣ����Ա
        k = 3;
    }
};

int main()
{
    B b;
    //b.i = 1; //err
    //b.j = 2;//err
    b.k = 3;
    system("pause");
    return 0;
}
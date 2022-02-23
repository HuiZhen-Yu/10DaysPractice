#include <iostream>

using namespace std;
/* 
    使用前向引用申明虽然可以解决一些问题，但是他并不是万能的。需要注意的是，
    尽管使用了前向引用申明，但是在提供一个完整的类申明之前，不能声明该类的对象，
    也不能在内联成员函数中使用该类的对象。
 */
#if 0
// 第一种
class Fred; //前向引用申明
class Barney{
    // Fred x;  //错误：类Fread的声明尚不完整
};

class Fread{
    Barney y;
};
#endif

#if 1
class Fred;
class Barney{
    public:
    void method()
    {
        // x->yabbaDabbaDo();//error
    }
    private:
    Fred *x;//正确，经过前向引用声明，可以声明Fred类的对象指针
};
#endif

int main(int argc,char *arg[])
{

    system("pause");
    return 0;
}
#include <iostream>
using namespace std;

//继承中同名成员处理
class Base
{
    public:
    Base()
    {
        m_a = 100;
    }

    void func()
    {
        cout<<"Base - func函数调用"<<endl;
    }

    void func(int a)
    {
        cout<<"Base - func(int a)函数调用"<<endl;
    }
    int m_a;
};

class Son:public Base
{
    public:

    Son()
    {
        m_a = 200;
    }
    int m_a;

    void func()
    {
        cout<<"Son - func函数调用"<<endl;
    }
};

//同名成员属性处理方式
void test01()
{
    Son s;
    cout<<"Son  下 m_a = "<<s.m_a<<endl;
    cout<<"Base 下 m_a = "<<s.Base::m_a<<endl;
}

//同名成员函数处理
void test02()
{
    Son s;
    s.func();   //直接调用 调用是子类中的同名成员

    //如何调用到父类中的同名成员函数?
    s.Base::func();

    //如果子类中出现和父类同名的成员函数,子类的同名成员会隐藏掉父类中的所有同名成员函数
    //如果想访问到父类中被隐藏的同名成员函数,需要加作用域
    //s.func(100);
    s.Base::func(100);
}
int main()
{
    test01();
    cout<<"----------------------"<<endl;
    test02();

    return 0;
}

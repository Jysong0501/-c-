#include <iostream>
using namespace std;

//继承中同名静态成员处理方式

class Base
{
    public:
    
    static int m_a ;

    static void func()
    {
        cout<<"Base - static void func()"<<endl;
    }

    static void func(int )
    {
        cout<<"Base - static void func(int )"<<endl;
    }
};

int Base::m_a = 100;

class Son:public Base
{
    public:
    
    static int m_a;

    static void func()
    {
        cout<<"Son - static void func()"<<endl;
    }
};
int Son::m_a = 200;


//同名静态成员属性
void test01()
{
    //1.通过对象访问
    cout<<"通过对象访问:"<<endl;
    Son s;
    cout<<"Son  下 m_a = "<<s.m_a<<endl;
    cout<<"Base 下 m_a = "<<s.Base::m_a<<endl;

    //2.通过类名访问
    cout<<"通过类名访问:"<<endl;
    cout<<"Son 下 m_a"<<Son::m_a<<endl;
    //第一个::代表通过类名方式访问  第二个::代表访问父类作用域下
    cout<<"Base 下 m_a"<<Son::Base::m_a<<endl;
    
}

//同名静态成员函数
void test02()
{
    //1.通过对象访问
    cout<<"通过对象访问"<<endl;
    Son s;
    s.func();
    s.Base::func();

    //2.通过类名访问
    cout<<"通过类名访问"<<endl;
    Son::func();
    Son::Base::func();

    //子类出现和父类同名静态成员函数,也会隐藏父类中的所有同名成员函数
    //如果想访问父类中被隐藏同名成员,需要加作用域
    Son::Base::func(100);

}

int main()
{

    test01();
    cout<<"----------------------"<<endl;
    test02();
    return 0;
}
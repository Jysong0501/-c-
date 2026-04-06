#include <iostream>
using namespace std;

//静态成员变量
class Person
{
    public:
    //1.所有对象都共享同一份数据
    //2.编译阶段就分配内存
    //3.类内声明,类外初始化操作
    static int m_a;//类内声明

    //静态成员变量也是有访问权限的
    private:
     static int m_b;
};

int Person::m_a=100;//类外初始化
int Person::m_b=200;
void test01()
{
    Person p;
    cout<<p.m_a<<endl;

    Person p2;
    p2.m_a=200;//p2的改了,其他的都改

    cout<<p.m_a<<endl;//m_a为共享数据,一个类里改了,所有类都改
}

void test02()
{
    //静态成员变量,不属于某个对象上,所有对象都共享同一份数据
    //因此静态成员变量有两种访问方式

    //1.通过对象进行访问
    Person p;
    cout<<p.m_a<<endl;
    //2.通过类名进行访问
    cout<<Person::m_a<<endl;
    //cout<<Person::m_b<<endl;      //类外访问不到类内的私有静态成员变量
}
int main()
{
    cout<<"t1"<<endl;
    test01();
    cout<<endl;
    cout<<"t2"<<endl;
    test02();
    return 0;
}
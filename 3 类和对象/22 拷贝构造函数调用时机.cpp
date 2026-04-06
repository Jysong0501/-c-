#include <iostream>
using namespace std;

//拷贝构造函数调用时机

//!!!
//本节疑似有错误
class Person
{
    public:
    Person()
    {
        cout<<"Person默认构造函数调用"<<endl;
    }

    Person(int age)
    {
        m_age = age;
        cout<<"Person有参构造函数调用"<<endl;
    }

    Person(const Person &p)
    {
        m_age = p.m_age;
        cout<<"Person拷贝构造函数调用"<<endl;
    }

    ~Person ()
    {
        cout<<"Person析构函数调用"<<endl;
    }
    int m_age;
};


//1.使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
    Person p1(20);
    cout<<endl;
    Person p2(p1);
    cout<<endl;
    cout<<"P2的年龄为:"<<p2.m_age<<endl;
}
//2.值传递的方式给函数参数传值

void dowork(Person p)
{

}
void test02()
{
    Person p;
    cout<<endl;
    dowork(p);
    cout<<endl<<endl;
}
//3.值方式返回局部对象


Person dowork2()
{
    Person p1;
    cout<<(int *)&p1<<endl;
    return p1;
}

void test03()
{
    Person p = dowork2();
    cout<<(int*)&p<<endl;

}

int main()
{
    //test01();
    //test02();
    test03();
    cout<<endl<<endl;
}
